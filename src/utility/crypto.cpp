#include "utility/crypto.hpp"

#include "cryptopp/sha.h"
#include "cryptopp/hex.h"

namespace tamandua { namespace utility {

std::string hashSHA256(std::string data)
{
	CryptoPP::SHA256 hash;
	byte digest[CryptoPP::SHA256::DIGESTSIZE];
	hash.CalculateDigest(digest, reinterpret_cast<const byte*>(data.data()), data.length());
	return std::string(reinterpret_cast<const char*>(digest), static_cast<size_t>(CryptoPP::SHA256::DIGESTSIZE));
}

std::string encodeSHA256Hash(std::string hash)
{
	CryptoPP::HexEncoder encoder;
	std::string encodedhash;
	encoder.Attach(new CryptoPP::StringSink(encodedhash));
	encoder.Put(reinterpret_cast<const byte*>(hash.data()), hash.size());
	encoder.MessageEnd();
	return encodedhash;
}

} }
