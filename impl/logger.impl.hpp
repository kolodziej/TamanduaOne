#ifndef TAMANDUA_LOGGER_IMPL_HPP
#define TAMANDUA_LOGGER_IMPL_HPP

namespace tamandua {

template<typename... Data>
void Logger::log(Policy policy, Data... data)
{
	if (policy & logging_policy_ == 0)
	{
		return;
	}
	std::lock_guard<std::mutex> lock(write_lock_);
	switch (policy)
	{
		case StandardLog:
			output_ << "<STDLOG>: ";
			break;

		case Warning:
			output_ << "<WARNING>: ";
			break;

		case Error:
			output_ << "<ERROR>: ";
			break;

		case DebugBasic:
		case DebugAdvanced:
		case DebugExpert:
			output_ << "<DEBUG_BASIC>: ";
			break;
		
		default:
			output_ << "<__OTHER__>: ";
			break;
	}

	logData_(data...);
}

}

#endif
