#ifndef TAMANDUA_CONFIG_MESSAGE_TYPES_HPP
#define TAMANDUA_CONFIG_MESSAGE_TYPES_HPP
#include <cstdint>

namespace tamandua {
namespace config {

typedef uint32_t MessageId;
enum class MessageType : uint8_t {
	InitMessage = 0,
	StandardMessage = 1,
	StatusMessage = 2,
	GroupEnterMessage = 3,
	GroupLeaveMessage = 4,
	ExitMessage = 255
};
enum class ErrorCode : uint8_t {
	Ok = 0, // no errors
};
typedef uint32_t UTCTime;
typedef uint16_t MessageSize;
typedef uint16_t MessageOptions;

}
}

#include "config/group.hpp"
#include "config/participant.hpp"

#endif
