#pragma once
#include <array>
#include <vector>

std::vector<unsigned char> privateToPublic(
    const std::array<unsigned char,32>& key
);
