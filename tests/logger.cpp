#include "gtest/gtest.h"
#include "logger.hpp"
#include "config/logger.hpp"

#include <iostream>
#include <sstream>
#include <thread>

using tamandua::Logger;

TEST(Logger, Basic)
{
	Logger test_logger("testlogger", Logger::DebugL3, std::cerr);
	test_logger.log(Logger::StandardLog, "Standard log ", "in Tamandua Logger");
	test_logger.log(Logger::Error, "Error log: ", 12.12);
}

TEST(Logger, ThreadSafety)
{
	std::stringstream log;
	Logger test_logger("testlogger2", Logger::BasicLog, log);

	auto lambda_func = [&](const char* str, int num = 500000) {
		for (int i = 0; i < num; ++i)
		{
			test_logger.log(Logger::StandardLog, str, str, str, str, str);
		}
	};
	std::thread threadA(lambda_func, "A");
	std::thread threadB(lambda_func, "B");
	std::thread threadC(lambda_func, "C");
	
	threadA.join();
	threadB.join();
	threadC.join();

	std::string log_line;
	while (std::getline(log, log_line))
	{
		ASSERT_TRUE(log_line == std::string("<STDLOG>: AAAAA") || log_line == std::string("<STDLOG>: BBBBB") || log_line == std::string("<STDLOG>: CCCCC"));
	}
}

TEST(Logger, Macros)
{
	Logger logger("testlogger", Logger::DebugL3, std::cerr);
	Log("testlogger", StandardLog, "StandardLog ", "Log macro");
	StdLog("testlogger", "StandardLog ", "StdLog macro");
	WarningLog("testlogger", "WarningLog ", "WarningLog macro");
	ErrorLog("testlogger", "ErrorLog ", "ErrorLog macro");
	DebugBasicLog("testlogger", "Debug Basic ", "DebugBasicLog macro");
	DebugAdvancedLog("testlogger", "Debug Avanced ", "DebugAdvancedLog macro");
	DebugExpertLog("testlogger", "Debug Expert ", "DebugExpertLog macro");
}
