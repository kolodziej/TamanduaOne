#ifndef TAMANDUA_LOGGER_HPP
#define TAMANDUA_LOGGER_HPP

#include <cstdint>
#include <map>
#include <memory>
#include <string>
#include <ostream>
#include <mutex>

#include "config/tamandua_api.hpp"

namespace tamandua {

class Log;

class TAMANDUA_API Logger
{
	public:
		enum Policy : uint8_t
		{
			StandardLog = 1 << 0,
			Warning = 1 << 1,
			Error = 1 << 2,
			DebugBasic = 1 << 3,
			DebugAdvanced = 1 << 4,
			DebugExpert = 1 << 5,
		};

		enum PolicySet : uint8_t
		{
			BasicLog = StandardLog | Error,
			ExtendedLog = StandardLog | Warning | Error,
			DebugL1 = StandardLog | Warning | Error | DebugBasic,
			DebugL2 = StandardLog | Warning | Error | DebugBasic | DebugAdvanced,
			DebugL3 = StandardLog | Warning | Error | DebugBasic | DebugAdvanced | DebugExpert,
			OnlyDebug = DebugBasic | DebugAdvanced | DebugExpert,
		};

	private:
		static std::map<std::string, Logger*> loggers_;
		std::string name_;
		uint8_t logging_policy_;
		std::ostream& output_;
		std::mutex write_lock_;

	public:
		Logger(std::string, uint8_t, std::ostream&);
		static Logger& getLogger(std::string);
	
		template <typename... Data>
		void log(Policy, Data...);

	private:
		inline void logData_()
		{
			output_ << "\n";
		}

		template <typename First, typename... Rest>
		inline void logData_(First f, Rest... r)
		{
			output_ << f;
			logData_(r...);
		}
};

}

#include "impl/logger.impl.hpp"

#endif
