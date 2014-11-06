#include "participant_manager.hpp"

#include "server.hpp"

namespace tamandua {

ParticipantManager::ParticipantManager(Server& server) :
	server_(server)
{}

void ParticipantManager::addParticipant(std::shared_ptr<Participant> participant)
{
	if (p.id_ == 0)
	{
		
	}
}

bool ParticipantManager::isNameInUse(std::string name)
{
	auto it = participants_ids_.find(name);
	if (it == participants_ids_.end())
	{
		return false;
	}

	return true;
}

bool ParticipantManager::isNameLocked(std::string name)
{
	auto it = locked_names_.find(name);
	if (it == locked_names_.end())
	{
		return false;
	}

	return true;
}

bool ParticipantManager::lockName(std::string name)
{
	auto insertion = locked_names_.insert(name);
	return insertion.second;
}

bool ParticipantManager::unlockName(std::string name)
{
	return static_cast<bool>(locked_names_.erase(name));
}

void ParticipantManager::setParticipantId_(std::shared_ptr<Participant> participant)
{
	if (participant->id_ == 0)
	{
		participant->id_ = nextParticipantId_();
	} else
	{
		auto it = participants_.find(participant->id_);
		if (it != participants_.end())
		{
			participant->id_ = nextParticipantId_();
		}
	}
}

void ParticipantManager::setParticipantName_(std::shared_ptr<Participant> participant)
{
	// get default name from server settings
	if (participant->name_.empty())
	{
		participant->name_ = "Guest";
	} else
	{
		auto it = participants_ids_.find(participant->name_);
		if (it != participants_ids_.end())
		{
			participant->name_ = "Guest";
		}
	}
}

ParticipantId ParticipantManager::nextParticipantId_()
{
	while (participants_.find(++last_participant_id_) != participants_.end())
	{
		// empty body;
	}
}

}
