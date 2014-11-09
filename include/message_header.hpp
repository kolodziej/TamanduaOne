#ifndef TAMANDUA_MESSAGE_HEADER_HPP
#define TAMANDUA_MESSAGE_HEADER_HPP

#include "config/tamandua_api.hpp"
#include "config/message_types.hpp"
#include "config/constants.hpp"

namespace tamandua {

struct TAMANDUA_API MessageHeader
{
	config::MessageId msg_id;
	config::MessageType type;
	config::ErrorCode error_code;
	config::ParticipantId author_id;
	config::GroupId group_id;
	config::UTCTime utc_time;
	config::MessageSize size;
	config::MessageOptions options;
	char author_name[config::participant_name_size];
};

}

#endif
