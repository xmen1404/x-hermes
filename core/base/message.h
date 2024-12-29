#pragma once

#include <cstdint>
#include <cstring>
#include <ctime>
#include <span>

namespace xhermes::message {

typedef enum MessageType {
    CLIENT_LOGIN,
    CLIENT_LOGOUT,
    CLIENT_SEND_TEXT,
    CLIENT_SEND_MEDIA,
    SERVER_ACKNOWLEDGE,
    CLIENT_ACKNOWLEDGE,
    CLIENT_NOTIFY,
} MessageType;

struct MessageHeader {
    MessageType type;
    uint64_t src;
    uint64_t dst;
    size_t length;
    time_t timestamp;

    void init(MessageType t, uint64_t src, uint64_t dst, size_t length, time_t timestamp) {
        this->type = t;
        this->src = src;
        this->dst = dst;
        this->length = length;
        this->timestamp = timestamp;
    }
};

struct MessageBody {
    char *buff;

    MessageBody() : buff(nullptr) {}
    ~MessageBody() {
        delete[] buff;
    }
    void init(std::span<char> payload) {
        buff = new char[payload.size() + 3];
        std::memcpy(buff, payload.data(), payload.size());
    }
};

struct Message {
    MessageHeader header;
    MessageBody body;

    Message() {}
    Message(MessageType t, uint64_t src, uint64_t dst, std::span<char> payload, time_t timestamp) {
        header.init(t, src, dst, payload.size(), timestamp);
        body.init(payload);
    }

    void serialize(char *buffer, size_t& offset) {
        std::memcpy(buffer+offset, &header, sizeof(MessageHeader));
        offset += sizeof(MessageHeader);

        if (body.buff) {
            std::memcpy(buffer+offset, body.buff, header.length);
            offset += header.length;
        }
    }
    void deserialize(const char *buffer, size_t& offset) {
        std::memcpy(&header, buffer+offset, sizeof(MessageHeader));
        offset += sizeof(MessageHeader);

        if (!body.buff)
            body.buff = new char[header.length+3];
        
        std::memcpy(body.buff, buffer+offset, header.length);
        offset += header.length;
    }
};

} // namespace xhermes
