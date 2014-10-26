#ifndef TAMANDUA_MESSAGE_HPP
#define TAMANDUA_MESSAGE_HPP
#include <string>
#include "message_header.hpp"
#include "config/tamandua_api.hpp"

namespace tamandua {

class MessageComposer;
class Buffer;

class TAMANDUA_API Message
{
	private:
		MessageHeader header_;
		std::string body_;

	public:
		Message();
		Message(MessageComposer &);
		Message(const MessageHeader&, std::string);

		MessageHeader& header();
		std::string body();
		void setHeader(const MessageHeader&);
		void setBody(std::string);
		void headerFromBuffer(Buffer);
		void bodyFromBuffer(Buffer);
		Buffer toBuffer();
};

}

#endif
