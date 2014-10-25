#ifndef TAMANDUAONE_MESSAGE_COMPOSER_HPP
#define TAMANDUAONE_MESSAGE_COMPOSER_HPP
#include <sstream>

#include "config/message_types.hpp"

namespace tamanduaone {

class Message;
class MessageHeader;
class MessageBuffer;

class MessageComposer
{
	private:
		MessageHeader header_;
		std::stringstream body_stream_;

	public:
		MessageComposer(MessageType, AuthorId = 0, std::string = std::string(), GroupId = 0);
		MessageComposer(MessageType, std::string, AuthorId = 0, std::string = std::string(), GroupId = 0);

		template <typename Data>
		MessageComposer& operator<<(Data data);

		Message message();
		MessageBuffer buffer();
};

}

#include "impl/message_composer.impl.hpp"

#endif
