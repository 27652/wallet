#include "Secp256k1.h"
#include <secp256k1.h>

std::vector<unsigned char> privateToPublic(
    const std::array<unsigned char,32>& key)
{
    secp256k1_context* ctx =
        secp256k1_context_create(SECP256K1_CONTEXT_SIGN);

    secp256k1_pubkey pub;

    secp256k1_ec_pubkey_create(
        ctx,
        &pub,
        key.data()
    );

    unsigned char out[65];
    size_t len = 65;

    secp256k1_ec_pubkey_serialize(
        ctx,
        out,
        &len,
        &pub,
        SECP256K1_EC_UNCOMPRESSED
    );

    secp256k1_context_destroy(ctx);

    return std::vector<unsigned char>(out, out+len);
}
