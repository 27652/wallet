#pragma once
#include <array>
#include <vector>
#include <cstdint>

struct HDKey {
    std::array<unsigned char,32> privateKey{};
    std::array<unsigned char,32> chainCode{};
};

class BIP32 {
public:
    static HDKey fromPrivateKey(const std::vector<unsigned char>& key);
    static HDKey derive(const HDKey& parent, uint32_t index);
};
