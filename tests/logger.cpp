#include "gtest/gtest.h"
#include "logger/logger.hpp"
#include "logger/log.hpp"

#include <iostream>

using tamandua::logger::Logger;
using tamandua::logger::Log;

TEST(Logger, Basic)
{
	Logger test_logger("testlogger", Logger::All, std::cerr);
	Log log1(Logger::DevelopmentAdvanced), log2(Logger::Errors | Logger::Warnings);
	log1 << "Testing log data: " << 1234;
	log2 << "Test log data: " << 12.34;

	test_logger.log(log1);
	test_logger.log(log2);
}

TEST(Logger, Advanced)
{
	Logger test_logger("onlyadv", Logger::DevelopmentBasic | Logger::DevelopmentAdvanced | Logger::DevelopmentExpert, std::cerr);
	Log log_basic(Logger::DevelopmentBasic),
		log_adv(Logger::DevelopmentAdvanced),
		log_exp(Logger::DevelopmentExpert),
		log_other(Logger::Errors);

	log_basic << "Basic log [should be!]";
	log_adv << "Advanced log [should be!]";
	log_exp << "Expert log [should be!]";
	log_other << "Other log [must not be!]";

	test_logger.log(log_basic);
	test_logger.log(log_adv);
	test_logger.log(log_exp);
	test_logger.log(log_other);
}
