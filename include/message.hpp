#ifndef TAMANDUA_MESSAGE_HPP
#define TAMANDUA_MESSAGE_HPP
#include <string>
#include "config/tamandua_api.hpp"

namespace tamandua {

struct MessageHeader;
class MessageComposer;
class MessageBuffer;

class TAMANDUA_API Message
{
	private:
		MessageHeader header_;
		std::string body_;

	public:
		Message();
		Message(const MessageComposer &);
		Message(const MessageBuffer &);
		Message(const MessageHeader&, std::string);

		MessageHeader header();
		std::string body();
		MessageBuffer toBuffer();
		void setHeader(MessageHeader);
		void setBody(std::string);
		void fromBuffer(const MessageBuffer&);
};

}

#endif
