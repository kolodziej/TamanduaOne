cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(TamanduaONE)

include_directories(
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}/gtest"
	"${PROJECT_SOURCE_DIR}"
)

add_subdirectory(gtest)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -static -lm")

set(PROTOCOL_SOURCES
	"src/message.cpp"
	"src/message_composer.cpp"
	"src/buffer.cpp"
	"src/logger/logger.cpp"
	"src/logger/log.cpp"
)

set(PROTOCOL_HEADERS
	"include/config/message_types.hpp"
	"include/config/tamandua_api.hpp"
	"include/message.hpp"
	"include/message_header.hpp"
	"include/message_composer.hpp"
	"impl/message_composer.impl.hpp"
	"include/buffer.hpp"
	"include/logger/logger.hpp"
	"include/logger/log.hpp"
	"impl/logger/log.impl.hpp"
)

if(ONLY_PROTOCOL)
	add_library(tamandua_protocol STATIC ${PROTOCOL_HEADERS} ${PROTOCOL_SOURCES})
		
else(ONLY_PROTOCOL)
	find_package(Boost 1.49 COMPONENTS system program_options regex REQUIRED)
	find_package(OpenSSL 1.0.0 REQUIRED)

endif(ONLY_PROTOCOL)

if(MAKE_TESTS)
	add_subdirectory(tests)
endif(MAKE_TESTS)
