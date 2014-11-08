#ifndef TAMANDUA_GROUP_HPP
#define TAMANDUA_GROUP_HPP

#include "config/group.hpp"
#include "config/participant.hpp"

#include <map>
#include <string>
#include <memory>

namespace tamandua {

class Participant;
class GroupManager;

class Group :
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
