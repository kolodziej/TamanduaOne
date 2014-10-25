#ifndef TAMANDUAONE_MESSAGE_HPP
#define TAMANDUAONE_MESSAGE_HPP
#include <string>

namespace tamanduaone {

struct MessageHeader;
class MessageComposer;
class MessageBuffer;

class Message
{
	private:
		MessageHeader header_;
		std::string body_;

	public:
		Message() = delete;
		Message(const MessageComposer &);
		Message(const MessageBuffer &);
		Message(const Message &) = delete;
		Message(const MessageHeader&, std::string);
};

}

#endif
