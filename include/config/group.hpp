#ifndef TAMANDUA_CONFIG_GROUP_HPP
#define TAMANDUA_CONFIG_GROUP_HPP
#include <cstdint>

namespace tamandua { namespace config {

typedef uint16_t GroupId;

enum class GroupType : uint8_t
{
	Group = 0,
	Room = 1,
	PrivateRoom = 2,
	Conference = 3,
};

} }

#endif
