#include <catch2/catch_test_macros.hpp>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <span>
#include "message.h"

using namespace xhermes::message;

TEST_CASE("Message Serialize-Deserialized Test") {
    std::string test = "Hello, world!";
    std::span<char> payload(test);

    Message msg(
        CLIENT_SEND_TEXT,
        12345678,
        87654321,
        payload,
        0
    );
    char *buffer = new char[1024];
    size_t offset = 0;
    
    msg.serialize(buffer, offset);      offset = 0;
    msg.deserialize(buffer, offset);    offset = 0;

    REQUIRE(msg.header.type == CLIENT_SEND_TEXT);
    REQUIRE(msg.header.src == 12345678);
    REQUIRE(msg.header.dst == 87654321);
    REQUIRE(msg.header.length == payload.size());
    REQUIRE(msg.header.timestamp == 0);

    REQUIRE(std::strncmp(msg.body.buff, test.data(), test.size()) == 0);
}