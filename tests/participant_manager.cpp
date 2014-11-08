#include "gtest/gtest.h"
#include "server.hpp"
#include "participant_manager.hpp"
#include "participant.hpp"

#include <memory>
#include <sstream>

using tamandua::Server;
using tamandua::ParticipantManager;
using tamandua::Participant;

TEST(ParticipantManager, Basic)
{
	Server svr;
	ParticipantManager manager(svr);
	for (int i = 1; i < 25; ++i)
	{
		std::stringstream name;
		name << "Username " << i;
		auto pt = std::make_shared<Participant>(name.str());
		ASSERT_TRUE(manager.addParticipant(pt));
	}
	int j = 1;
	for (auto it = manager.participants().begin(); it != manager.participants().end(); ++it, ++j)
	{
		std::stringstream name;
		name << "Username " << j;
		ASSERT_EQ(it->first, j);
		ASSERT_EQ(it->second->id(), j);
		ASSERT_EQ(it->second->name(), name.str());
	}

	ASSERT_FALSE(manager.addParticipant(std::make_shared<Participant>("Username 3")));
	ASSERT_FALSE(manager.addParticipant(std::make_shared<Participant>("User", 20)));
}

TEST(ParticipantManager, IdEq0)
{
	Server svr;
	ParticipantManager manager(svr);
	
	manager.addParticipant(std::make_shared<Participant>("UsernameId0", 0));
	ASSERT_NE(manager.participants().begin()->second->id(), 0);
	ASSERT_EQ(manager.participants().begin()->second->id(), 1);
}

TEST(ParticipantManager, RemoveParticipant1)
{
	Server svr;
	ParticipantManager manager(svr);

	auto pt = std::make_shared<Participant>("Username", 20);
	ASSERT_TRUE(manager.addParticipant(pt));
	ASSERT_TRUE(manager.removeParticipant(pt));
	ASSERT_FALSE(manager.removeParticipant(std::shared_ptr<Participant>(nullptr)));
}

TEST(ParticipantManager, RemoveParticipant2)
{
	Server svr;
	ParticipantManager manager(svr);

	auto pt = std::make_shared<Participant>("Username2", 22);
	auto id = pt->id();
	ASSERT_TRUE(manager.addParticipant(pt));
	ASSERT_TRUE(manager.removeParticipant(id));
	ASSERT_FALSE(manager.removeParticipant(id));
	ASSERT_FALSE(manager.removeParticipant(10));
}

TEST(ParticipantManager, RemoveParticipant3)
{
	Server svr;
	ParticipantManager manager(svr);

	auto pt = std::make_shared<Participant>("Username", 20);
	auto name = pt->name();
	ASSERT_TRUE(manager.addParticipant(pt));
	ASSERT_TRUE(manager.removeParticipant(name));
	ASSERT_FALSE(manager.removeParticipant(name));
	ASSERT_FALSE(manager.removeParticipant("OtherUsername"));
}
