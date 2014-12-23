#ifndef TAMANDUA_CONFIG_PARTICIPANT_HPP
#define TAMANDUA_CONFIG_PARTICIPANT_HPP
#include <cstdint>

namespace tamandua { namespace config {

typedef uint32_t ParticipantId;

enum class ParticipantType : uint8_t
{
	Participant = 0,
	HiddenParticipant = 1,
	User = 2,
	Bot = 3,
	Guest = 4,
};

} }

#endif
