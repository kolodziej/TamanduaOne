#ifndef TAMANDUA_MESSAGE_COMPOSER_IMPL_HPP
#define TAMANDUA_MESSAGE_COMPOSER_IMPL_HPP

using tamandua;

template<typename Data>
MessageComposer& MessageComposer::operator<<(Data data)
{
	body_stream_ << data;
	return *this;
}

#endif
