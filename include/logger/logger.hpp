#ifndef TAMANDUA_LOGGER_LOGGER_HPP
#define TAMANDUA_LOGGER_LOGGER_HPP

#include <cstdint>
#include <map>
#include <memory>
#include <string>
#include <ostream>
#include <mutex>

#include "config/tamandua_api.hpp"

namespace tamandua { namespace logger {

class Log;

class TAMANDUA_API Logger
{
	public:
		enum Policy : uint8_t
		{
			StandardLog = 1 << 0,
			Warnings = 1 << 1,
			Errors = 1 << 2,
			DebugBasic = 1 << 3,
			DebugAdvanced = 1 << 4,
			DebugExpert = 1 << 5,
		};

		enum PolicySet : uint8_t
		{
			BasicLog = StandardLog | Errors,
			ExtendedLog = StandardLog | Warnings | Errors,
			DebugL1 = StandardLog | Warnings | Errors | DebugBasic,
			DebugL2 = StandardLog | Warnings | Errors | DebugBasic | DebugAdvanced,
			DebugL3 = StandardLog | Warnings | Errors | DebugBasic | DebugAdvanced | DebugExpert,
			OnlyDebug = DebugBasic | DebugAdvanced | DebugExpert,
		};

	private:
		static std::map<std::string, Logger*> loggers_;
		std::string name_;
		uint8_t logging_policy_;
		std::ostream& output_;
		std::mutex logging_lock_;

	public:
		Logger(std::string, uint8_t, std::ostream&);
		static Logger& getLogger(std::string);

		void log(Log&);
};

} }

#endif
