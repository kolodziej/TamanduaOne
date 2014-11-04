#ifndef TAMANDUA_LOGGER_IMPL_HPP
#define TAMANDUA_LOGGER_IMPL_HPP

namespace tamandua {

template<typename T>
Logger& Logger::operator<<(T data)
{
	output_ << data;
	return *this;
}

}

#endif
