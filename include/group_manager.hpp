#ifndef TAMANDUA_GROUP_MANAGER_HPP
#define TAMANDUA_GROUP_MANAGER_HPP

#include <map>
#include <string>
#include <memory>

#include "config/message_types.hpp"

namespace tamandua {

class Group;

class GroupManager
{
	private:
		Server& server_;
		std::map<config::GroupId, std::shared_ptr<Group>> groups_;
		std::map<std::string, config::GroupId> groups_ids_;
		config::GroupId last_group_id_;

	public:
		GroupManager(Server&);
		GroupManager(const GroupManager&) = delete;

		void addGroup(std::shared_ptr<Group>);
		void closeGroup(config::GroupId);
		void closeGroup(std::string);

	private:
		config::GroupId nextGroupId_();

};

}

#endif
