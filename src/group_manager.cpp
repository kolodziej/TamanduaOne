#include "group_manager.hpp"

#include "server.hpp"
#include "group.hpp"

namespace tamandua {

GroupManager::GroupManager(Server& server) :
	server_(server),
	last_group_id_(0)
{}

bool GroupManager::addGroup(std::shared_ptr<Group> group)
{
	group->id_ = nextGroupId_();
	auto insertion = groups_.insert(std::make_pair(group->id(), group));
	if (insertion.second == true)
	{
		auto insertion_id = groups_ids_.insert(std::make_pair(group->name(), group->id()));
		if (insertion_id.second == true)
		{
			return true;
		} else
		{
			groups_.erase(insertion.first);
			return false;
		}
	}

	return false;
}

bool GroupManager::removeGroup(std::shared_ptr<Group> group)
{
	return removeGroup(group->id());
}

bool GroupManager::removeGroup(config::GroupId id)
{
	auto gr_it = groups_.find(id);
	if (gr_it != groups_.end())
	{
		std::string name = gr_it->second->name();
		groups_.erase(gr_it);
		if (groups_ids_.erase(name))
		{
			return true;
		} else
		{
			// @todo: proper exception
		}
	}

	return false;
}

bool GroupManager::removeGroup(std::string name)
{
	auto gr_id_it = groups_ids_.find(name);
	if (gr_id_it != groups_ids_.end())
	{
		config::GroupId id = gr_id_it->second;
		groups_ids_.erase(gr_id_it);
		if (groups_.erase(id))
		{
			return true;
		} else
		{
			// @todo: proper exception
		}
	}

	return false;
}

config::GroupId GroupManager::nextGroupId_()
{
	return ++last_group_id_;
}

}
