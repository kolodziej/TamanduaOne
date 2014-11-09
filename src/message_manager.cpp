#include "message_manager.hpp"

#include "server.hpp"
#include "message.hpp"
#include "participant.hpp"
#include "participant_manager.hpp"
#include "utility/time.hpp"

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

void MessageManager::processMessage(std::shared_ptr<Participant> participant, Message& message)
{
	process_queue_lock_.lock();
	process_queue_.push_back(std::make_pair(participant, message));
	process_queue_lock_.unlock();

	process_cv_.notify_one();
}

void MessageManager::sendMessage(std::shared_ptr<Participant> participant, Message& message)
{
	send_queue_lock_.lock();
	send_queue_.push_back(std::make_pair(participant, message));
	send_queue_lock_.unlock();

	send_cv_.notify_one();
}

void MessageManager::processingThread()
{
	std::unique_lock<std::mutex> processing_ulock_(process_queue_lock_);
	while (processing_thread_run_)
	{
		std::shared_ptr<Participant> sender = process_queue_.front().first;
		Message msg = process_queue_.front().second;
		processing_ulock_.lock();
		process_queue_.pop_front();

		fillHeader_(msg);
		// CommandInterpreter: check if command
		// pass event

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
	header.utc_time = utility::utcTime();
}

}
