#include "logger/logger.hpp"

#include <stdexcept>
#include <string>

#include "logger/log.hpp"

namespace tamandua { namespace logger {

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

void Logger::log(Log& l)
{
	if (l.policy() & logging_policy_)
	{
		output_ << static_cast<std::string>(l) << "\n";
	}
}

} }
