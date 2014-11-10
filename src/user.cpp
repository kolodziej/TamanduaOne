#include "user.hpp"

#include "utility/time.hpp"
#include "utility/crypto.hpp"

namespace tamandua {

User::User(std::string name, std::string password, config::ParticipantId id) :
	Participant(name, id),
	registered_(false),
	created_date_(utility::utcTime()),
	last_visit_date_(utility::utcTime())
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

std::string User::passwordHash()
{
	return utility::encodeSHA256Hash(password_hash_);
}

void User::setPassword_(std::string password)
{
	password_hash_ = hashPassword_(password);
}

std::string User::hashPassword_(std::string password)
{
	return utility::hashSHA256(password);
}

}
