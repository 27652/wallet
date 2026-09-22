#include "BIP32.h"
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include <cstring>

HDKey BIP32::fromPrivateKey(const std::vector<unsigned char>& key)
{
    HDKey out;
    memcpy(out.privateKey.data(), key.data(), 32);

    unsigned char zero[32]{};
    memcpy(out.chainCode.data(), zero, 32);
    return out;
}

HDKey BIP32::derive(const HDKey& parent, uint32_t index)
{
    unsigned char data[36];
    memcpy(data, parent.privateKey.data(), 32);
    memcpy(data+32, &index, 4);

    unsigned char result[64];
    unsigned int len = 64;

    HMAC(EVP_sha512(),
         parent.chainCode.data(),
         32,
         data,
         sizeof(data),
         result,
         &len);

    HDKey child;
    memcpy(child.privateKey.data(), result, 32);
    memcpy(child.chainCode.data(), result+32, 32);

    return child;
}
