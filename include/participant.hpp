#ifndef TAMANDUA_PARTICIPANT_HPP
#define TAMANDUA_PARTICIPANT_HPP

#include <string>
#include <memory>

#include "config/tamandua_api.hpp"
#include "config/participant.hpp"

namespace tamandua {

class ParticipantManager;

class TAMANDUA_API Participant :
	public std::enable_shared_from_this<Participant>
{
	private:
		config::ParticipantId id_;
		std::string name_;
		bool online_;
		bool hidden_;

	public:
		Participant(std::string = std::string(), config::ParticipantId = 0);
		Participant(const Participant&) = delete;

		config::ParticipantId id();
		std::string name();
		void setName(std::string);

		bool online();
		void setOnline(bool = true);
		
		bool hidden();
		bool shown();
		void show();
		void hide();

		const config::ParticipantType type()
		{
			return config::Participant;
		}

	friend class ParticipantManager;
};

}

#endif
