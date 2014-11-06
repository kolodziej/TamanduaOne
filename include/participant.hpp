#ifndef TAMANDUA_PARTICIPANT_HPP
#define TAMANDUA_PARTICIPANT_HPP

#include "config/message_types.hpp"

#include <string>

namespace tamandua {

typedef config::AuthorId ParticipantId;

class Participant
{
	private:
		ParticipantId id_;
		std::string name_;
		bool online_;
		bool hidden_;

	public:
		Participant(std::string = std::string(), ParticipantId = 0);

		ParticipantId id();
		std::string name();
		void setName(std::string);

		bool online();
		void setOnline(bool = true);
		
		bool hidden();
		bool shown();
		void show();
		void hide();
};

}

#endif
