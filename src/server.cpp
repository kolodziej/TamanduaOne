#include "server.hpp"

namespace tamandua {

Server::Server() :
	participant_manager_(*this),
	group_manager_(*this)
{
}

ServerSettings Server::settings()
{
	return settings_;
}

ParticipantManager& Server::participantManager()
{
	return participant_manager_;
}

GroupManager& Server::groupManager()
{
	return group_manager_;
}

SessionManager& Server::sessionManager()
{
	return session_manager_;
}

/*ModuleManager& Server::moduleManager()
{
	return module_manager_;
}

CommandInterpreter& Server::commandInterpreter()
{
	return command_interpreter_;
}*/

}
