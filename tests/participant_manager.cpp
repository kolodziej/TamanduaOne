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
	for (int i = 0; i < 100; ++i)
	{
		std::stringstream name;
		name << "Username " << i;
		auto pt = std::make_shared<Participant>(name.str());
		ASSERT_TRUE(manager.addParticipant(pt));
	}

	ASSERT_FALSE(manager.addParticipant(std::make_shared<Participant>("Username 3")));
	ASSERT_FALSE(manager.addParticipant(std::make_shared<Participant>("User", 20)));
}
