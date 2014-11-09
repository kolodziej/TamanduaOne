#include "gtest/gtest.h"
#include "participant.hpp"
#include "user.hpp"

#include <iostream>

using tamandua::User;

TEST(User, Password)
{
	User user("User1", "MyPassword");
	ASSERT_TRUE(user.verifyPassword("MyPassword"));
	ASSERT_FALSE(user.verifyPassword("MojeHaslo"));
	ASSERT_TRUE(user.changePassword("MyPassword", "MyPassword2"));
	ASSERT_FALSE(user.changePassword("MyPassword", "MyPassword3"));
	ASSERT_TRUE(user.verifyPassword("MyPassword2"));
	ASSERT_FALSE(user.verifyPassword("MyPassword"));
}
