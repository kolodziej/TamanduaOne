#ifndef TAMANDUA_USER_HPP
#define TAMANDUA_USER_HPP

#include "config/tamandua_api.hpp"
#include "config/participant.hpp"
#include "participant.hpp"

namespace tamandua {

class TAMANDUA_API User :
	public Participant
{
	private:
		bool registered_;
		uint32_t created_date_;
		uint32_t last_visit_date_;
		std::string password_hash_;

	public:
		User(std::string, std::string, config::ParticipantId = 0);
		bool changePassword(std::string, std::string);
		bool verifyPassword(std::string);
		void updateLastVisit();
		std::string passwordHash();

	private:
		void setPassword_(std::string);
		std::string hashPassword_(std::string);
};

}

#endif
