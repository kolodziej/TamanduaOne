#ifndef TAMANDUA_SERVER_HPP
#define TAMANDUA_SERVER_HPP

#include <thread>

#include "server_settings.hpp"
#include "participant_manager.hpp"
#include "group_manager.hpp"
#include "session_manager.hpp"
//#include "module_manager.hpp"
//#include "command_interpreter.hpp"

namespace tamandua {

class Server
{
	private:
		ServerSettings settings_;
		ParticipantManager participant_manager_;
		GroupManager group_manager_;
		SessionManager session_manager_;
		//ModuleManager module_manager_;
		//CommandInterpreter command_interpreter_;

		std::thread io_service_thread_;

	public:
		Server();
		Server(const Server&) = delete;

		ServerSettings settings();
		ParticipantManager& participantManager();
		GroupManager& groupManager();
		SessionManager& sessionManager();
		//ModuleManager& moduleManager();
		//CommandInterpreter& commandInterpreter();

};

} // namespace tamandua

#endif
