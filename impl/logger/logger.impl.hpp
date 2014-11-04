#ifdef TAMANDUA_LOGGER_LOGGER_HPP

namespace tamandua { namespace logger {

template<typename T>
Logger& Logger::operator<<(T data)
{
	output_ << data;
	return *this;
}

} }

#endif
