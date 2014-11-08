#ifndef TAMANDUA_GROUP_MANAGER_HPP
#define TAMANDUA_GROUP_MANAGER_HPP

#include <map>
#include <string>
#include <memory>

#include "config/message_types.hpp"

namespace tamandua {

class Server;
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

		bool addGroup(std::shared_ptr<Group>);
		bool removeGroup(std::shared_ptr<Group>);
		bool removeGroup(config::GroupId);
		bool removeGroup(std::string);

	private:
		config::GroupId nextGroupId_();

};

}

#endif
