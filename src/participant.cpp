#include "participant.hpp"

#include "config/constants.hpp"

namespace tamandua {

Participant::Participant(std::string name, ParticipantId id) :
	id_(id),
	name_(name),
	online_(false),
	hidden_(false)
{}

ParticipantId Participant::id()
{
	return id_;
}

std::string Participant::name()
{
	return name_;
}

void Participant::setName(std::string name)
{
	name_ = name.substr(0, config::participant_name_size);
}

bool Participant::online()
{
	return online_;
}

void Participant::setOnline(bool online)
{
	online_ = online;
}

bool Participant::hidden()
{
	return hidden_;
}

bool Participant::shown()
{
	return (hidden_ == false);
}

void Participant::show()
{
	hidden_ = false;
}

void Participant::hide()
{
	hidden_ = true;
}

}
