#ifndef TAMANDUA_LOGGER_LOGGER_HPP
#define TAMANDUA_LOGGER_LOGGER_HPP

#include <cstdint>
#include <map>
#include <memory>
#include <string>
#include <ostream>

#include "config/tamandua_api.hpp"

namespace tamandua { namespace logger {

class TAMANDUA_API Logger
{
	public:
		enum LoggerPolicy : uint8_t
		{
			Errors = 1 << 0,
			Warnings = 1 << 1,
			Logs = 1 << 2,
			Events = 1 << 3,
			DevelopmentBasic = 1 << 4,
			DevelopmentAdvanced = 1 << 5,
			DevelomentExpert = 1 << 6,
			DevelopmentAll = 1 << 7,
		};

	private:
		static std::map<std::string, Logger*> loggers_;
		std::string name_;
		uint8_t logging_policy_;
		std::ostream& output_;

	public:
		Logger(std::string, uint8_t, std::ostream&);

		template <typename T>
		Logger& operator<<(T data);

		static Logger& getLogger(std::string);
};

} }

#include "impl/logger.impl.hpp"

#endif
