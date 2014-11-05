#ifndef TAMANDUA_LOGGER_LOG_HPP
#define TAMANDUA_LOGGER_LOG_HPP

#include <sstream>
#include "logger.hpp"

namespace tamandua { namespace logger {

class Log
{
	private:	
		std::stringstream stream_;
		uint8_t policy_;

	public:
		Log(uint8_t);

		template <typename T>
		Log& operator<<(T);

		void append();
		template <typename T, typename... R>
		void append(T, R...);

		std::string toString();
		operator std::string();
		
		uint8_t policy();
};

} }

#include "impl/logger/log.impl.hpp"

#endif
