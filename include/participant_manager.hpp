#ifndef TAMANDUA_PARTICIPANT_MANAGER_HPP
#define TAMANDUA_PARTICIPANT_MANAGER_HPP

#include <map>
#include <set>
#include <string>
#include <memory>

namespace tamandua {

class Server;
class Participant;

class ParticipantManager
{
	private:
		Server& server_;
		std::map<ParticipantId, std::shared_ptr<Participant>> participants_;
		std::map<std::string, ParticipantId> participants_ids_;
		std::set<std::string> locked_names_;
		ParticipantId last_participant_id_;

	public:
		ParticipantManager(Server&);
		void addParticipant(std::shared_ptr<Participant>);
		bool isNameInUse(std::string);
		bool isNameLocked(std::string);
		bool lockName(std::string);
		bool unlockName(std::string);

	private:
		void setParticipantId_(std::shared_ptr<Participant>);
		void setParticipantName_(std::shared_ptr<Participant>);

		ParticipantId nextParticipantId_();

};

}

#endif
