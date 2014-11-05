#ifndef TAMANDUA_LOGGER_LOG_BASIC_HPP
#define TAMANDUA_LOGGER_LOG_BASIC_HPP

#include "logger/logger.hpp"
#include "logger/log.hpp"

namespace tamandua { namespace logger {

class LogBasic : public Log
{
	public:
		LogBasic() :
			Log(Logger::Logs | Logger::Errors | Logger::Events)
		{}
};

} }

#endif
