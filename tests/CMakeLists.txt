cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

link_directories(
	"../gtest/"
	"../lib/"
)

include_directories(
  "../gtest/include/"
	"../include/"
	"../"
)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(LINK_LIBS gtest gtest_main pthread tamandua_protocol)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/tests/bin")

add_executable(message_composer message_composer.cpp)
target_link_libraries(message_composer "${LINK_LIBS}")

add_executable(logger logger.cpp)
target_link_libraries(logger "${LINK_LIBS}")
