#pragma once

#include <cstring>
#include <glog/logging.h>

#include "core/config/config.h"
#include "core/network/message.h"

namespace xhermes::network {

using Config = xhermes::config::Config;
using Message = xhermes::network::Message

class Receiver {
public:
  Receiver() {}

public:
  virtual void Init(const Config& config) {} 
  virtual bool Recv(Messsage& msg) {}
};

class Sender {  
public:
  Sender() {}

public:
  virtual void Init(const Config& config) {}
  virtual bool Send(const Message& msg) {}
};

/**
 * Stateless Server
 */
class Server : public Receiver, public Sender {
public:
  bool Init(const config::Config& config) {
    CHECK(config.Has("addr"));
    const auto addr = config.Get<std::string>("addr");
    
    CHECK(config.Has("port"));
    const auto port = config.Get<std::string>("port"); 

    LOG(INFO) << "Initializing stateless server";
  } 
}

} // namespace xhermes::network


