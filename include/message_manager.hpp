#ifndef TAMANDUA_MESSAGE_MANAGER_HPP
#define TAMANDUA_MESSAGE_MANAGER_HPP

#include <deque>

namespace tamandua {
	
class Server;
class Message;

class MessageManager
{
	private:
		Server& server_;
		std::deque<Message> received_messages_;
		std::deque<Message> messages_to_send_;

	public:
		MessageManager();
		MessageManager(const MessageManager&) = delete;

		Server& server();
};

} // namespace tamandua

#endif
