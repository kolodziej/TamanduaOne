#ifdef TAMANDUA_LOGGER_LOG_HPP

template <typename T>
Log& Log::operator<<(T data)
{
	stream_ << data;
	return *this;
}

#endif
