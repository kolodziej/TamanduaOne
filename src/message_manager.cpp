#include "message_manager.hpp"

#include "server.hpp"
#include "message.hpp"

namespace tamandua {

MessageManager::MessageManager() :
	processing_thread_(true),
	sending_thread_(true)
{}

MessageManager::~MessageManager()
{
	processing_thread_ = false;
	sending_thread_ = false;
	
}

Server& MessageManager::server()
{
	return server_;
}

void MessageManager::processMessage(Message& message)
{
	process_queue_lock_.lock();
	process_queue_.push_back(message);
	process_queue_lock_.unlock();

	process_cv_.notify_one();
}

void MessageManager::sendMessage(Message& message)
{
	send_queue_lock_.lock();
	send_queue_.push_back(message);
	send_queue_lock_.unlock();

	send_cv_.notify_one();
}

void MessageManager::processingThread()
{
	while (processing_thread_run_)
	{
		// procesing messages

		process_cv_.wait(process_queue_lock_, [this]() {
			return (process_queue_.empty() == false || processing_thread_run_ == false);
		});
	}
}

void MessageManager::sendingThread()
{
	ParticipantManager &pm = server().participantManager();
	while (sending_thread_run_)
	{
		// sending messages

		send_cv_.wait(send_queue_lock_, [this]() {
			return (send_queue_.empty() == false || sending_thread_run_ == false);
		});
	}
}

config::MessageId MessageManager::getNextMessageId_()
{
	return ++last_message_id_;
}

void MessageManager::fillHeader_(Message& message)
{
	MessageHeader &header = message.header();
	header.msg_id = getNextMessageId_();
	// @todo: header.utc_time =
}

}
