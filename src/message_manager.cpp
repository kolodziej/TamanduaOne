#include "message_manager.hpp"

#include "server.hpp"
#include "message.hpp"
#include "participant_manager.hpp"

namespace tamandua {

MessageManager::MessageManager(Server& server) :
	server_(server),
	processing_thread_run_(true),
	sending_thread_run_(true)
{}

MessageManager::~MessageManager()
{
	processing_thread_run_ = false;
	sending_thread_run_ = false;
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
	std::unique_lock<std::mutex> processing_ulock_(process_queue_lock_);
	while (processing_thread_run_)
	{
		// procesing messages

		process_cv_.wait(processing_ulock_, [this]()->bool {
			return (process_queue_.empty() == false || processing_thread_run_ == false);
		});
	}
}

void MessageManager::sendingThread()
{
	ParticipantManager &pm = server().participantManager();
	std::unique_lock<std::mutex> sending_ulock_(send_queue_lock_);
	while (sending_thread_run_)
	{
		// sending messages

		send_cv_.wait(sending_ulock_, [this]() {
			return (send_queue_.empty() == false || sending_thread_run_ == false);
		});
	}
}

config::MessageId MessageManager::nextMessageId_()
{
	return ++last_message_id_;
}

void MessageManager::fillHeader_(Message& message)
{
	MessageHeader &header = message.header();
	header.msg_id = nextMessageId_();
	// @todo: header.utc_time =
}

}
