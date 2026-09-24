#pragma once
#include <array>
#include <vector>
#include <cstdint>

struct HDKey {
    std::array<unsigned char, 32> privateKey{};
    std::array<unsigned char, 32> chainCode{};
};

class BIP32 {
public:
    // BIP32 master key generation:
    // I = HMAC-SHA512(Key = "Bitcoin seed", Data = seed)
    static HDKey fromSeed(const std::vector<unsigned char>& seed);

    // Private child derivation.
    // index >= 0x80000000 -> hardened
    // index <  0x80000000 -> non-hardened
    static HDKey derive(const HDKey& parent, uint32_t index);
};
