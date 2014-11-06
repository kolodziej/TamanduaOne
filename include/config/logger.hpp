#ifndef TAMANDUA_CONFIG_LOGGER_HPP
#define TAMANDUA_CONFIG_LOGGER_HPP

#include "logger/logger.hpp"
#define Log(name, type, ...) tamandua::Logger::getLogger(name).log(type, __VA_ARGS__)
#define StdLog(name, ...) tamandua::Logger::getLogger(name).log(tamandua::Logger::StandardLog, __VA_ARGS__)
#define WarningLog(name, ...) tamandua::Logger::getLogger(name).log(tamandua::Logger::Warning, __VA_ARGS__)
#define ErrorLog(name, ...) tamandua::Logger::getLogger(name).log(tamandua::Logger::Error, __VA_ARGS__)
#define DebugBasicLog(name, ...) tamandua::Logger::getLogger(name).log(tamandua::Logger::DebugBasic, __VA_ARGS__)
#define DebugAdvancedLog(name, ...) tamandua::Logger::getLogger(name).log(tamandua::Logger::DebugAdvanced, __VA_ARGS__)
#define DebugExpertLog(name, ...) tamandua::Logger::getLogger(name).log(tamandua::Logger::DebugExpert, __VA_ARGS__)

#endif
