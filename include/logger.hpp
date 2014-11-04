#ifndef TAMANDUA_LOGGER_HPP
#define TAMANDUA_LOGGER_HPP

#include <cstdint>
#include <vector>
#include <memory>
#include <string>
#include <ostream>

#include "config/tamandua_api.hpp"

namespace tamandua {

class TAMANDUA_API Logger
{
	private:
		static std::vector<std::shared_ptr<Logger>> loggers_;
		uint32_t logging_policy_;
		std::ostream& output_;

	public:
		Logger(std::string, uint32_t);

		template <typename T>
		Logger& operator<<(T data);

		static Logger& getLogger(std::string);
};

}

#include "impl/logger.impl.hpp"

#endif
