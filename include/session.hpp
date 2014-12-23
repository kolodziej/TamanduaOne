#ifndef TAMANDUA_SESSION_HPP
#define TAMANDUA_SESSION_HPP

#include <deque>
#include <memory>

#include "config/tamandua_api.hpp"
#include "config/session.hpp"
#include "message.hpp"

namespace tamandua {

class Server;
class Participant;

class TAMANDUA_API Session
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
