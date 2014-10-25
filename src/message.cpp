#include "message.hpp"

#include "message_header.hpp"
#include "message_composer.hpp"
#include "message_buffer.hpp"

using tamanduaone;

Message::Message()
{}

Message::Message(const MessageComposer& composer) :
	header_(composer.message().header()),
	body_(composer.message().body())
{}

Message::Message(const MessageBuffer& buffer) :
	header_(buffer.message().header()),
	body_(buffer.message().body())
{}

Message::Message(const MessageHeader& header, std::string body) :
	header_(header),
	body_(body)
{}

MessageHeader Message::header()
{
	return header_;
}

std::string Message::body()
{
	return body_;
}

MessageBuffer Message::toBuffer()
{
	return MessageBuffer(*this);
}

void Message::setHeader(MessageHeader header)
{
	header_ = header;
}

void Message::setBody(std::string body)
{
	body_ = body;
}

void Message::fromBuffer(const MessageBuffer& buffer)
{
	header_ = buffer.message().header();
	body_ = buffer.message().body();
}
