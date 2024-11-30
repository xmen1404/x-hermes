#pragma once

#include <cstring>
#include <glog/logging.h>

#include "config/config.h"

namespace xhermes::network {

using Config = xhermes::config::Config;

struct MessageHeader {
  // TODO: implement me
};

struct MessgeBody {
  // TODO: implement me
};

struct Message {
  MessageHeader header;
  MessageBody body;
};

class Receiver {
public:
  Receiver() {}

public:
  virtual void Init(const xhermes::config::Config& config) {} 
  virtual bool Recv(Messsage& msg) {}
};

class Sender {  
public:
  Sender() {}

public:
  virtual void Init(const xhermes::config::Config& config) {}
  virtual bool Send(const Message& msg) {}

};

/**
 * Bidirectional Socket
 */
class Socket : public Receiver, public Sender {
public:
  void Init(const config::Config& config) {
    LOG(INFO) << "Initializing socket";
  } 
}

} // namespace xhermes::network


