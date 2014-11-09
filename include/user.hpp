#ifndef TAMANDUA_USER_HPP
#define TAMANDUA_USER_HPP

#include "config/tamandua_api.hpp"
#include "participant.hpp"

namespace tamandua {

class TAMANDUA_API User :
	public Participant
{
	private:
		uint32_t created_date_;
		uint32_t last_visit_date_;
		std::string password_hash_;

	public:
		User(std::string);
		bool changePassword(std::string, std::string);
		bool verifyPassword(std::string);
		void updateLastVisit();

	private:
		void setPassword_(std::string);
		std::string hashPassword_(std::string);
};

}

#endif
