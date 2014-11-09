#include "user.hpp"

#include "utility/time.hpp"

namespace tamandua {

User::User(std::string password)
{
	setPassword_(password);
}

bool User::changePassword(std::string current, std::string newpass)
{
	if (verifyPassword(current))
	{
		setPassword_(newpass);
		return true;
	}

	return false;
}

bool User::verifyPassword(std::string password)
{
	return (password_hash_ == hashPassword_(password));
}

void User::updateLastVisit()
{
	last_visit_date_ = utility::utcTime();
}

void User::setPassword_(std::string password)
{
	password_hash_ = hashPassword_(password);
}

std::string User::hashPassword_(std::string password)
{
	std::string password_hash(password); // @todo: introduce hashing function
	return password_hash;
}

}
