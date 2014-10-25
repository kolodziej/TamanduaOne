#ifndef TAMANDUAONE_MESSAGE_COMPOSER_IMPL_HPP
#define TAMANDUAONE_MESSAGE_COMPOSER_IMPL_HPP

using tamanduaone;

template<typename Data>
MessageComposer& MessageComposer::operator<<(Data data)
{
	body_stream_ << data;
	return *this;
}

#endif
