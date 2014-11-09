#include "gtest/gtest.h"
#include "server.hpp"
#include "group.hpp"
#include "participant.hpp"
#include "group_manager.hpp"

#include <vector>
#include <sstream>
#include <memory>

using tamandua::Server;
using tamandua::Group;
using tamandua::Participant;
using tamandua::GroupManager;

class GroupManagerTest : public ::testing::Test
{
	protected:
		virtual void SetUp()
		{
			manager = new GroupManager(server);
			for (int i = 1; i <= 30; ++i)
			{
				std::stringstream name;
				name << "Username" << i;
				pts.push_back(std::make_shared<Participant>(name.str(), i));
			}

			group1 = nullptr;
			group2 = nullptr;
			group3 = nullptr;
		}

		void initGroups()
		{
			group1 = std::make_shared<Group>("NewGroup1");
			group2 = std::make_shared<Group>("NewGroup2");
			group3 = std::make_shared<Group>("NewGroup3");
		}

		virtual void TearDown()
		{
			delete manager;
			pts.clear();
		}

		Server server;
		GroupManager* manager;
		std::shared_ptr<Group> group1;
		std::shared_ptr<Group> group2;
		std::shared_ptr<Group> group3;
		std::vector<std::shared_ptr<Participant>> pts;
};

TEST_F(GroupManagerTest, Basic)
{
	initGroups();
	ASSERT_TRUE(manager->addGroup(group1));
	ASSERT_TRUE(manager->addGroup(group2));
	ASSERT_TRUE(manager->addGroup(group3));

	ASSERT_EQ(group1->id(), 1);
	ASSERT_EQ(group2->id(), 2);
	ASSERT_EQ(group3->id(), 3);
}
