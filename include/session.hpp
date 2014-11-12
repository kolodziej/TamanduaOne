#ifndef TAMANDUA_SESSION_HPP
#define TAMANDUA_SESSION_HPP

#include <deque>
#include <memory>

#include "message.hpp"

namespace tamandua {

class Server;
class Participant;

class Session
{
	private:
		Server& server_;
		config::SslSocketStream socket_;
		std::deque<Message> received_messages_;
		std::deque<Message> messages_to_send_;
		std::shared_ptr<Participant> participant_;

	public:
		Session();
		Session(const Session&) = delete;
		
		Server& server();
		config::SslSocketStream& socket();


};

}

#endif
