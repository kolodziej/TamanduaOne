#include "logger.hpp"

#include <stdexcept>

namespace tamandua {

Logger::Logger(std::string name, uint8_t policy, std::ostream& output) :
	name_(name),
	logging_policy_(policy),
	output_(output)
{
	loggers_.insert(std::make_pair(name, this));
}

static Logger& Logger::getLogger(std::string name)
{
	auto it = loggers_.find(name);
	if (it != loggers_.end())
	{
		return *(*it);
	} else
	{
		throw std::logic_error("logger does not exists!");
	}
}

}
