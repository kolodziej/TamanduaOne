#ifndef TAMANDUA_GROUP_HPP
#define TAMANDUA_GROUP_HPP

#include <map>
#include <string>
#include <memory>

#include "config/tamandua_api.hpp"
#include "config/group.hpp"
#include "config/participant.hpp"

namespace tamandua {

class Participant;
class GroupManager;

class TAMANDUA_API Group :
	public std::enable_shared_from_this<Group>
{
	private:
		config::GroupId id_;
		std::string name_;
		std::map<config::ParticipantId, std::shared_ptr<Participant>> participants_;

	public:
		Group(std::string = std::string());
		config::GroupId id();
		std::string name();
		void setName(std::string);
		bool addParticipant(std::shared_ptr<Participant>);
		bool removeParticipant(std::shared_ptr<Participant>);
		bool removeParticipant(config::ParticipantId);
		const std::map<config::ParticipantId, std::shared_ptr<Participant>>& participants();
		const config::GroupType type()
		{
			return config::Group;
		}

	friend class GroupManager;
};

}

#endif
