#include "gtest/gtest.h"
#include "participant.hpp"

using tamandua::Participant;

TEST(Participant, BasicTest)
{
	Participant participant("Kacper Kołodziej");
	ASSERT_EQ(participant.id(), 0);
	ASSERT_EQ(participant.name(), "Kacper Kołodziej");
	ASSERT_FALSE(participant.online());
	ASSERT_FALSE(participant.hidden());
	ASSERT_TRUE(participant.shown());
	participant.setOnline();
	ASSERT_TRUE(participant.online());
	participant.hide();
	ASSERT_TRUE(participant.hidden());
	ASSERT_FALSE(participant.shown());
	participant.show();
	ASSERT_FALSE(participant.hidden());
	ASSERT_TRUE(participant.shown());
}
