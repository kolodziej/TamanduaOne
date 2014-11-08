#ifndef TAMANDUA_PARTICIPANT_MANAGER_HPP
#define TAMANDUA_PARTICIPANT_MANAGER_HPP

#include <map>
#include <set>
#include <string>
#include <memory>

#include "config/participant.hpp"

namespace tamandua {

class Server;
class Participant;

class ParticipantManager
{
	private:
		Server& server_;
		std::map<config::ParticipantId, std::shared_ptr<Participant>> participants_;
		std::map<std::string, config::ParticipantId> participants_ids_;
		std::set<std::string> locked_names_;
		config::ParticipantId last_participant_id_;

	public:
		ParticipantManager(Server&);
		bool addParticipant(std::shared_ptr<Participant>);
		bool removeParticipant(std::shared_ptr<Participant>);
		bool removeParticipant(config::ParticipantId);
		bool removeParticipant(std::string);

		bool isNameInUse(std::string);
		bool isNameLocked(std::string);
		bool lockName(std::string);
		bool unlockName(std::string);

		const std::map<config::ParticipantId, std::shared_ptr<Participant>>& participants();

	private:
		void setParticipantId_(std::shared_ptr<Participant>);
		void setParticipantName_(std::shared_ptr<Participant>);

		config::ParticipantId nextParticipantId_();

};

}

#endif
