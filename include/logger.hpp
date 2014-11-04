#ifndef TAMANDUA_LOGGER_HPP
#define TAMANDUA_LOGGER_HPP

#include <cstdint>
#include <map>
#include <memory>
#include <string>
#include <ostream>

#include "config/tamandua_api.hpp"

namespace tamandua {

class TAMANDUA_API Logger
{
	public:
		enum LoggerPolicy : uint8_t
		{
		};

	private:
		static std::map<std::string, Logger*> loggers_;
		std::string name_;
		LoggingPolicy logging_policy_;
		std::ostream& output_;

	public:
		Logger(std::string, uint8_t, std::ostream&);

		template <typename T>
		Logger& operator<<(T data);

		static Logger& getLogger(std::string);
};

}

#include "impl/logger.impl.hpp"

#endif
