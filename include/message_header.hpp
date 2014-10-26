#ifndef TAMANDUA_MESSAGE_HEADER_HPP
#define TAMANDUA_MESSAGE_HEADER_HPP

#include "config/message_types.hpp"
#include "config/tamandua_api.hpp"

namespace tamandua {

const size_t author_name_size = 40;

struct TAMANDUA_API MessageHeader
{
	config::MessageId msg_id;
	config::MessageType type;
	config::ErrorCode error_code;
	config::AuthorId author_id;
	config::GroupId group_id;
	config::UTCTime utc_time;
	config::MessageSize size;
	config::MessageOptions options;
	char author_name[author_name_size];
};

}

#endif
