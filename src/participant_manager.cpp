#include "participant_manager.hpp"

#include <sstream>

#include "server.hpp"
#include "participant.hpp"

namespace tamandua {

ParticipantManager::ParticipantManager(Server& server) :
	server_(server),
	last_participant_id_(0)
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
			participant->setParticipantManager_(this);
			return true;
		} else
		{
			participants_.erase(insertion.first);
			return false;
		}
	}
	return false;
}

std::shared_ptr<Participant> ParticipantManager::participant(config::ParticipantId id)
{
	auto it = participants_.find(id);
	if (it == participants_.end())
	{
		return nullptr;
	}

	return it->second;
}

std::shared_ptr<Participant> ParticipantManager::participant(std::string name)
{
	auto id_it = participants_ids_.find(name);
	if (id_it == participants_ids_.end())
	{
		return nullptr;
	}

	return participant(id_it->second);
}

bool ParticipantManager::removeParticipant(std::shared_ptr<Participant> participant)
{
	if (participant == nullptr)
	{
		return false;
	}
	return removeParticipant(participant->id());
}

bool ParticipantManager::removeParticipant(config::ParticipantId id)
{
	auto pt_it = participants_.find(id);
	if (pt_it != participants_.end())
	{
		std::string name = pt_it->second->name();
		participants_.erase(pt_it);
		if (participants_ids_.erase(name))
		{
			pt_it->second->clearParticipantManager_();
			return true;
		} else
		{
			// @todo: proper exception; as above
		}
	}

	return false;
}

bool ParticipantManager::removeParticipant(std::string name)
{
	auto pt_id_it = participants_ids_.find(name);
	if (pt_id_it != participants_ids_.end())
	{
		config::ParticipantId id = pt_id_it->second;
		participants_ids_.erase(pt_id_it);

		auto pt_it = participants_.find(id);
		if (pt_it != participants_.end())
		{
			pt_it->second->clearParticipantManager_();
			participants_.erase(pt_it);
			return true;
		} else
		{
			// @todo: proper exception; as above
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

const std::map<config::ParticipantId, std::shared_ptr<Participant>>& ParticipantManager::participants()
{
	return participants_;
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
	std::stringstream name;
	name << "p#" << participant->id();
	if (participant->name_.empty())
	{
		participant->name_ = name.str();;
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
