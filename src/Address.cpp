#include "Address.h"
#include <openssl/evp.h>
#include <sstream>

std::string ethAddress(const std::vector<unsigned char>& pub)
{
    // Demo placeholder.
    // Replace with Keccak-256 implementation for production.
    std::stringstream ss;
    ss << "0x";
    for(size_t i=1;i<21 && i<pub.size();i++)
        ss << std::hex << (int)pub[i];

    return ss.str();
}
