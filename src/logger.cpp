#include "logger.hpp"

#include <stdexcept>
#include <string>

namespace tamandua {

std::map<std::string, Logger*> Logger::loggers_;

Logger::Logger(std::string name, uint8_t policy, std::ostream& output) :
	name_(name),
	logging_policy_(policy),
	output_(output)
{
	auto insertion = loggers_.insert(std::make_pair(name, this));
	if (insertion.second == false)
	{
		throw std::logic_error("logger could not be created");
	}
}

Logger& Logger::getLogger(std::string name)
{
	auto it = loggers_.find(name);
	if (it != loggers_.end())
	{
		return *(it->second);
	} else
	{
		throw std::logic_error("logger does not exists!");
	}
}

}
