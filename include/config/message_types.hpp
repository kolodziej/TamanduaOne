#ifndef TAMANDUAONE_CONFIG_MESSAGE_TYPES_HPP
#define TAMANDUAONE_CONFIG_MESSAGE_TYPES_HPP
#include <cstdint>

namespace tamanduaone {
namespace config {
	typedef uint32_t MessageId;
	enum MessageType : uint8_t {
		// types
	};
	enum ErrorCode : uint8_t {
		// error codes
	};
	typedef uint32_t AuthorId;
	typedef uint16_t GroupId;
	typedef uint32_t UTCTime;
	typedef uint16_t MessageSize;
	typedef uint16_t MessageOptions;
	typedef uint8_t MessageByte;
}
}

#endif
