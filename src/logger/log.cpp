#include "logger/log.hpp"

#include <cstdint>
#include <string>

namespace tamandua { namespace logger {

Log::Log(uint8_t policy) :
	policy_(policy)
{}

std::string Log::toString()
{
	return stream_.str();
}

Log::operator std::string()
{
	return toString();
}

void Log::append()
{
	
}

uint8_t Log::policy()
{
	return policy_;
}

} }
