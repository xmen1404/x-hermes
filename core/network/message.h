#pragma once

#include <cstdint>
#include <cstring>
#include <ctime>
#include <span>

namespace xhermes::network {

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

  void Init(MessageType t, uint64_t src, uint64_t dst, size_t length,
            time_t timestamp) {
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
  ~MessageBody() { delete[] buff; }
  void Init(std::span<char> payload) {
    buff = new char[payload.size() + 3];
    std::memcpy(buff, payload.data(), payload.size());
  }
};

struct Message {
  MessageHeader header;
  MessageBody body;

  Message() {}
  Message(MessageType t, uint64_t src, uint64_t dst, std::span<char> payload,
          time_t timestamp) {
    header.Init(t, src, dst, payload.size(), timestamp);
    body.Init(payload);
  }

  size_t Serialize(char *buffer) {
    std::memcpy(buffer, &header, sizeof(MessageHeader));

    if (body.buff)
      std::memcpy(buffer + sizeof(MessageHeader), body.buff, header.length);

    return sizeof(MessageHeader) + header.length;
  }
  size_t Deserialize(const char *buffer) {
    std::memcpy(&header, buffer, sizeof(MessageHeader));

    if (!body.buff)
      body.buff = new char[header.length + 3];

    std::memcpy(body.buff, buffer + sizeof(MessageHeader), header.length);

    return sizeof(MessageHeader) + header.length;
  }
};

} // namespace xhermes::network
