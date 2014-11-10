#ifndef TAMANDUA_UTILITY_CRYPTO_HPP
#define TAMANDUA_UTILITY_CRYPTO_HPP

#include <string>

namespace tamandua { namespace utility {

std::string hashSHA256(std::string);
std::string encodeSHA256Hash(std::string);

} }

#endif
