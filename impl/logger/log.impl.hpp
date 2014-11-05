#ifdef TAMANDUA_LOGGER_LOG_HPP

namespace tamandua { namespace logger {

template <typename T>
Log& Log::operator<<(T data)
{
	stream_ << data;
	return *this;
}

template <typename T, typename... R>
void Log::append(T f, R... rest)
{
	stream << f;
	append(rest...);
}

} }

#endif
