#include "gtest.h"
#include "message.hpp"
#include "message_composer.hpp"
#include "config/message_types.hpp"

#include <string>
#include <sstream>

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

	msgc << msgappend;
	ASSERT_EQ(msgc.message().body(), msgbody + msgappend);
}

TEST(MessageComposer, stream_operator)
{
	std::string one("One "), two("Two "), three("Three ");
	int num1 = 123432, num2 = 32123;
	double num3 = 3123.21312;
	tamandua::MessageComposer msgc(tamandua::config::StandardMessage);
	msgc << one << two << num1 << three << num2 << one << num3;
	std::stringstream stream;
	stream << one << two << num1 << three << num2 << one << num3;

	ASSERT_EQ(stream.str(), msgc.message().body());
}
