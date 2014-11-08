#include "group.hpp"

#include "config/constants.hpp"
#include "participant.hpp"

namespace tamandua {

Group::Group(std::string name) :
	name_(name)
{}

config::GroupId Group::id()
{
	return id_;
}

std::string Group::name()
{
	return name_;
}

void Group::setName(std::string name)
{
	name_ = name.substr(0, config::group_name_size);
}

bool Group::addParticipant(std::shared_ptr<Participant> participant)
{
	auto insertion = participants_.insert(std::make_pair(participant->id(), participant));
	// @todo: inform participant about new group
	return insertion.second;
}

bool Group::removeParticipant(std::shared_ptr<Participant> participant)
{
	return removeParticipant(participant->id());
}

bool Group::removeParticipant(config::ParticipantId id)
{
	return static_cast<bool>(participants_.erase(id));
}

const std::map<config::ParticipantId, std::shared_ptr<Participant>>& Group::participants()
{
	return participants_;
}

}
