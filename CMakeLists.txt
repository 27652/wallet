cmake_minimum_required(VERSION 3.16)
project(HDWallet)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)

add_executable(wallet
    main.cpp
    src/BIP32.cpp
    src/Secp256k1.cpp
    src/Address.cpp
)

target_include_directories(wallet PRIVATE include)

target_link_libraries(wallet
    OpenSSL::Crypto
    secp256k1
)
