#include "session_manager.hpp"

#include "server.hpp"

namespace tamandua {

SessionManager::SessionManager(Server& server, boost::asio::ip::tcp::acceptor& acceptor, unsigned int max_session_num) :
	server_(server),
	acceptor_(acceptor),
	max_session_num_(max_session_num),
	last_session_id_(0),
	accepting_(false)
{}

bool SessionManager::closeSession(config::SessionId id)
{
	auto it = sessions_.find(id);
	if (it != sessions_.end())
	{
		return it->second->close();
	}
	return false;
}

unsigned int SessionManager::maxSessionNum()
{
	return max_session_num_;
}

void SessionManager::setMaxSessionNum(unsigned int max_session_num)
{
	max_session_num_ = max_session_num;
}

void SessionManager::startAccepting()
{
	accepting_ = true;
	// start accepting in acceptor
}

void SessionManager::stopAccepting()
{
	accepting_ = false;
	// stop accepting in acceptor
}

bool SessionManager::accepting()
{
	return accepting_;
}

config::SessionId SessionManager::nextSessionId_()
{
	return ++last_session_id_;
}

}
