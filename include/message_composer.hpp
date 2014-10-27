#ifndef TAMANDUA_MESSAGE_COMPOSER_HPP
#define TAMANDUA_MESSAGE_COMPOSER_HPP
#include <sstream>


#include "config/message_types.hpp"
#include "message_header.hpp"

namespace tamandua {

class Message;

class TAMANDUA_API MessageComposer
{
	private:
		MessageHeader header_;
		std::stringstream body_stream_;

	public:
		MessageComposer(config::MessageType, config::AuthorId = 0, std::string = std::string(), config::GroupId = 0);
		MessageComposer(config::MessageType, std::string, config::AuthorId = 0, std::string = std::string(), config::GroupId = 0);

		template <typename Data>
		MessageComposer& operator<<(Data data);

		Message message();
};

}

#include "impl/message_composer.impl.hpp"

#endif
