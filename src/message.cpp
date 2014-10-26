#include "message.hpp"

#include <cstring>
#include <string>

#include "message_header.hpp"
#include "message_composer.hpp"
#include "buffer.hpp"

namespace tamandua {

Message::Message()
{}

Message::Message(MessageComposer& composer) :
	header_(composer.message().header()),
	body_(composer.message().body())
{}

Message::Message(const MessageHeader& header, std::string body) :
	header_(header),
	body_(body)
{}

MessageHeader& Message::header()
{
	return header_;
}

std::string Message::body()
{
	return body_;
}

void Message::setHeader(const MessageHeader& header)
{
	header_.msg_id = header.msg_id;
	header_.type = header.type;
	header_.error_code = header.error_code;
	header_.author_id = header.author_id;
	header_.group_id = header.group_id;
	header_.utc_time = header.utc_time;
	header_.size = header.size;
	header_.options = header.options;
	strncpy(header_.author_name, header.author_name, 40);
}

void Message::setBody(std::string body)
{
	body_ = body;
}

void Message::headerFromBuffer(Buffer buf)
{
	memcpy(reinterpret_cast<void*>(&header_), reinterpret_cast<const void*>(buf.buffer().get()), sizeof(header_));
}

void Message::bodyFromBuffer(Buffer buf)
{
	body_ = std::string(buf.buffer().get(), buf.size());
}

Buffer Message::toBuffer()
{
	size_t size = sizeof(header_) + body_.length();
	Buffer buf(size);
	memcpy(reinterpret_cast<void*>(buf.buffer().get()), reinterpret_cast<const void*>(&header_), sizeof(header_));
	memcpy(reinterpret_cast<void*>(buf.buffer().get() + sizeof(header_)), reinterpret_cast<const void*>(body_.data()), body_.size());
	return buf;
}

} // namespace tamandua
