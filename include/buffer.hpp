#ifndef TAMANDUA_BUFFER_HPP
#define TAMANDUA_BUFFER_HPP
#include <memory>
#include "config/tamandua_api.hpp"

namespace tamandua {

class TAMANDUA_API Buffer
{
	public:
		typedef std::shared_ptr<char> BufferPtr;

	private:
		BufferPtr buffer_;
		size_t buffer_size_;

	public:
		Buffer(size_t);
		BufferPtr buffer();
		size_t size();
};

}

#endif
