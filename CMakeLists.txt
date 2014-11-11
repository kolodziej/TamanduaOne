cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(TamanduaONE)

include_directories(
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}/gtest"
	"${PROJECT_SOURCE_DIR}"
)

add_subdirectory(gtest)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -static -lm")

set(PROTOCOL_SOURCES
	"src/message.cpp"
	"src/message_composer.cpp"
	"src/buffer.cpp"
)

set(LIBRARY_SOURCES
	"src/logger.cpp"
	"src/message_manager.cpp"
	"src/participant.cpp"
	"src/participant_manager.cpp"
	"src/group.cpp"
	"src/server.cpp"
	"src/group_manager.cpp"
	"src/utility/time.cpp"
	"src/utility/crypto.cpp"
	"src/user.cpp"
	"src/command.cpp"
)

set(PROTOCOL_HEADERS
	"include/config/message_types.hpp"
	"include/config/constants.hpp"
	"include/message.hpp"
	"include/message_header.hpp"
	"include/message_composer.hpp"
	"impl/message_composer.impl.hpp"
	"include/buffer.hpp"
)

set(LIBRARY_HEADERS
	"include/config/tamandua_api.hpp"
	"include/config/logger.hpp"
	"include/logger.hpp"
	"impl/logger.impl.hpp"
	"include/message_manager.hpp"
	"include/participant.hpp"
	"include/server.hpp"
	"include/server_settings.hpp"
	"include/participant_manager.hpp"
	"include/group.hpp"
	"include/group_manager.hpp"
	"include/session_manager.hpp"
	"include/utility/time.hpp"
	"include/utility/crypto.hpp"
	"include/user.hpp"
	"include/command.hpp"
)
	add_library(tamandua_protocol STATIC ${PROTOCOL_HEADERS} ${PROTOCOL_SOURCES})
		
if(NOT ONLY_PROTOCOL OR NOT NOMAKE_TESTS)
	find_package(Boost 1.49 COMPONENTS system program_options regex REQUIRED)
	find_package(OpenSSL 1.0.0 REQUIRED)
	find_package(Crypto++ REQUIRED)

	add_library(tamandua STATIC ${PROTOCOL_HEADERS} ${LIBRARY_HEADERS} ${PROTOCOL_SOURCES} ${LIBRARY_SOURCES} ${Crypto++_INCLUDE_DIRS} ${Crypto++_LIBRARIES})

endif(NOT ONLY_PROTOCOL OR NOT NOMAKE_TESTS)

if(NOT NOMAKE_TESTS)
	add_subdirectory(tests)
endif(NOT NOMAKE_TESTS)
