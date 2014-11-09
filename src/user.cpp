#include "user.hpp"

#include "cryptopp/sha.h"
#include "cryptopp/hex.h"

#include "utility/time.hpp"

namespace tamandua {

User::User(std::string name, std::string password, config::ParticipantId id) :
	Participant(name, id)
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
	return encodeSHA256Hash_(password_hash_);
}

void User::setPassword_(std::string password)
{
	password_hash_ = hashPassword_(password);
}

std::string User::hashPassword_(std::string password)
{
	CryptoPP::SHA256 hash;
	byte digest[CryptoPP::SHA256::DIGESTSIZE];
	hash.CalculateDigest(digest, reinterpret_cast<const byte*>(password.data()), password.length());
	
	return std::string(reinterpret_cast<const char*>(digest), static_cast<size_t>(CryptoPP::SHA256::DIGESTSIZE));
}

std::string User::encodeSHA256Hash_(std::string hash)
{
	CryptoPP::HexEncoder encoder;
	std::string encodedhash;
	encoder.Attach(new CryptoPP::StringSink(encodedhash));
	encoder.Put(reinterpret_cast<const byte*>(hash.data()), hash.size());
	encoder.MessageEnd();
	return encodedhash;
}

}
