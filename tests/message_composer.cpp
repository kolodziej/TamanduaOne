#include "gtest/gtest.h"
#include "message.hpp"
#include "message_composer.hpp"
#include "config/message_types.hpp"

#include <string>

TEST(MessageComposer, StandardMessage)
{
	std::string username("UserName"), msgbody("MsgBody"), msgappend("MsgAppend");
	tamandua::MessageComposer msgc(tamandua::config::StandardMessage, 1, username, 1);
	msgc << msgbody;
	tamandua::Message msg = msgc.message();
	tamandua::MessageHeader header = msg.header();

	ASSERT_EQ(msg.body(), msgbody);
	ASSERT_EQ(header.type, tamandua::config::StandardMessage);
	ASSERT_EQ(header.author_id, 1);
	ASSERT_EQ(header.group_id, 1);
	ASSERT_STREQ(header.author_name, username.data());
}
