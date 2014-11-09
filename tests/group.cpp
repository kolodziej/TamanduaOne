#include "gtest/gtest.h"
#include "group.hpp"
#include "participant.hpp"

#include <vector>
#include <sstream>
#include <memory>

using tamandua::Group;
using tamandua::Participant;

class GroupTest : public ::testing::Test
{
	protected:
		virtual void SetUp()
		{
			group = new Group("New group");
			for (int i = 0; i < 10; ++i)
			{
				std::stringstream name;
				name << "Username " << i+1;
				pts.push_back(std::make_shared<Participant>(name.str(), i+1));
			}
		}

		virtual void TearDown()
		{
			pts.clear();
			delete group;
		}

		virtual void addAllPts()
		{
			for (auto pt : pts)
			{
				group->addParticipant(pt);
			}
		}

		Group* group;
		std::vector<std::shared_ptr<Participant>> pts;
};

TEST_F(GroupTest, Basic)
{
	ASSERT_EQ(group->id(), 0);
	ASSERT_EQ(group->name(), "New group");
	for (auto pt : pts)
	{
		ASSERT_TRUE(group->addParticipant(pt));
	}

	ASSERT_FALSE(group->addParticipant(pts[2]));
}

TEST_F(GroupTest, RemoveParticipants1)
{
	addAllPts();
	for (auto pt : pts)
	{
		ASSERT_TRUE(group->removeParticipant(pt));
	}
	ASSERT_FALSE(group->removeParticipant(pts[2]));
	ASSERT_TRUE(group->participants().empty());
}

TEST_F(GroupTest, RemoveParticipants2)
{
	addAllPts();
	for (auto pt : pts)
	{
		ASSERT_TRUE(group->removeParticipant(pt->id()));
	}
	ASSERT_FALSE(group->removeParticipant(pts[2]->id()));
	ASSERT_TRUE(group->participants().empty());
}

TEST_F(GroupTest, RemoveParticipants3)
{
	addAllPts();
	for (auto pt : pts)
	{
		ASSERT_TRUE(group->removeParticipant(pt->id()));
	}
	ASSERT_FALSE(group->removeParticipant(pts[2]->id()));
	ASSERT_TRUE(group->participants().empty());
}
