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
set(LINK_LIBS gtest gtest_main pthread tamandua cryptopp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/tests/bin")

add_executable(message_composer message_composer.cpp)
target_link_libraries(message_composer "${LINK_LIBS}")

add_executable(logger logger.cpp)
target_link_libraries(logger "${LINK_LIBS}")

add_executable(participant participant.cpp)
target_link_libraries(participant "${LINK_LIBS}")

add_executable(participant_manager participant_manager.cpp)
target_link_libraries(participant_manager "${LINK_LIBS}")

add_executable(group group.cpp)
target_link_libraries(group "${LINK_LIBS}")

add_executable(group_manager group_manager.cpp)
target_link_libraries(group_manager "${LINK_LIBS}")

add_executable(user user.cpp)
target_link_libraries(user "${LINK_LIBS}")
