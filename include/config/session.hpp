#ifndef TAMANDUA_CONFIG_SESSION_HPP
#define TAMANDUA_CONFIG_SESSION_HPP
#include <cstdint>

namespace tamandua { namespace config {

typedef uint32_t SessionId;
typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> SslSocketStream;

} }

#endif
