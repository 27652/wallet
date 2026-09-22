#include "BIP32.h"
#include "Secp256k1.h"
#include "Address.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<unsigned char> readKey()
{
    std::ifstream f("root.key");
    std::string s;
    f >> s;

    std::vector<unsigned char> out;

    for(size_t i=0;i<s.size();i+=2)
        out.push_back(
            std::stoul(s.substr(i,2),nullptr,16)
        );

    return out;
}

int main()
{
    auto root = readKey();

    auto master =
        BIP32::fromPrivateKey(root);

    // m/44'/60'/0'/0/0
    auto eth =
        BIP32::derive(master,44|0x80000000);

    eth =
        BIP32::derive(eth,60|0x80000000);

    eth =
        BIP32::derive(eth,0|0x80000000);

    eth =
        BIP32::derive(eth,0);

    eth =
        BIP32::derive(eth,0);


    auto pub =
        privateToPublic(eth.privateKey);


    std::cout
        << "ETH Address: "
        << ethAddress(pub)
        << std::endl;

    return 0;
}
