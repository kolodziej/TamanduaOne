#include "command.hpp"

#include <sstream>

namespace tamandua {

Command::Command(std::string name, int params_min, int params_max) :
	name_(name),
	params_min_(params_min),
	params_max_(params_max)
{
}

Command::Command(std::string name, std::string format, int params_min, int params_max) :
	name_(name),
	format_(format),
	params_min_(params_min),
	params_max_(params_max)
{
}

std::string Command::name()
{
	return name_;
}

std::string Command::format()
{
	std::stringstream stream;
	stream << "/" << name_ << " " << format_;
	return stream.str();
}

int Command::min()
{
	return (params_min_ >= 0) ? params_min_ : 0;
}

int Command::max()
{
	return (params_max_ >= -1) ? params_max_ : -1;
}

}
