#include "utility/time.hpp"

#include <ctime>
#include <chrono>

namespace tamandua { namespace utility {

uint32_t utcTime()
{
	return static_cast<uint32_t>(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
}

} }
