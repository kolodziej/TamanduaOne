#ifndef TAMANDUA_SESSION_MANAGER_HPP
#define TAMANDUA_SESSION_MANAGER_HPP

#include "config/tamandua_api.hpp"
#include "config/session.hpp"

#include <boost/asio.hpp>

namespace tamandua {

class Session;

class TAMANDUA_API SessionManager
{
	private:
		Server& server_;
		std::map<config::SessionId, std::shared_ptr<Session>> sessions_;
		boost::asio::ip::tcp::acceptor& acceptor_;
		unsigned int max_session_num_;
		config::SessionId last_session_id_;
		bool accepting_;

	public:
		SessionManager(Server&, boost::asio::ip::tcp::acceptor&, unsigned int = 2000);
		SessionManager(const SessionManager&) = delete;

		bool closeSession(config::SessionId);
		unsigned int maxSessionNum();
		void setMaxSessionNum(unsigned int);
		void startAccepting();
		void stopAccepting();
		bool accepting();

	private:
		config::SessionId nextSessionId_();
};

}

#endif
