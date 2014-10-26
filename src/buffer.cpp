#include "buffer.hpp"

namespace tamandua {

Buffer::Buffer(size_t size)	:	
	buffer_(new char[size], [](char* ptr) { delete[] ptr; }),
	buffer_size_(size)
{}

Buffer::BufferPtr Buffer::buffer()
{
	return buffer_;
}

size_t Buffer::size()
{
	return buffer_size_;
}

} // namespace tamandua
