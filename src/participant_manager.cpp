#include "participant_manager.hpp"

#include "server.hpp"
#include "participant.hpp"

namespace tamandua {

ParticipantManager::ParticipantManager(Server& server) :
	server_(server)
{}

bool ParticipantManager::addParticipant(std::shared_ptr<Participant> participant)
{
	if (participant->id() == 0)
	{
		participant->id_ = nextParticipantId_();
	}
	auto insertion = participants_.insert(std::make_pair(participant->id(), participant));
	if (insertion.second == true)
	{
		auto insertion_id = participants_ids_.insert(std::make_pair(participant->name(), participant->id()));
		if (insertion_id.second == true)
		{
			return true;
		} else
		{
			// @todo: proper exception: insertion == true, insertion_id == false
		}
	}
	return false;
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

config::ParticipantId ParticipantManager::nextParticipantId_()
{
	while (participants_.find(++last_participant_id_) != participants_.end())
	{
		// empty body;
	}
	return last_participant_id_;
}

}
