#pragma once

#include <cstdint>
#include <cstring>
#include <ctime>

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

    MessageHeader(MessageType t, uint64_t src, uint64_t dst, size_t length, time_t timestamp) {
        this->type = t;
        this->src = src;
        this->dst = dst;
        this->length = length;
        this->timestamp = timestamp;
    }
};

struct MessageBody {
    char *buff;

    MessageBody(const std::string &msg) {
        buff = new char[msg.size()+3];
        std::memcpy(buff, msg.data(), msg.size());
    }
    ~MessageBody() {
        delete[] buff;
    }
};

struct Message {
    MessageHeader *header;
    MessageBody *body;

    Message(MessageType t, uint64_t src, uint64_t dst, const std::string &payload, time_t timestamp) {
        header = new MessageHeader(t, src, dst, payload.size(), timestamp);
        body = new MessageBody(payload);
    }
    ~Message() {
        delete header;
        delete body;
    }

    void serialize(char *buffer, size_t& offset) {
        std::memcpy(buffer+offset, header, sizeof(MessageHeader));
        std::memcpy(buffer+offset+sizeof(MessageHeader), body->buff, header->length);
    }
    void deserialize(const char *buffer, size_t& offset) {
        std::memcpy(header, buffer + offset, sizeof(MessageHeader));
        std::memcpy(body->buff, buffer + offset + sizeof(MessageHeader), header->length);
    }
};

} // namespace xhermes
