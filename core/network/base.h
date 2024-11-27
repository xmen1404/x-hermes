#pragma once

#include <cstring>

#include "config/config.h"

namespace xhermes::network {

class Socket {
public:
  void Init(const config::Config& config) {
    LOG(INFO) << "Initializing socket";
  } 
}

} // namespace xhermes::network


