#pragma once

#include <string>
#include <unordered_map>

namespace xhermes::config {

class Config {
public:
  bool Init() {
  }

  template <typename T>
  T Get(const std::string& key) {
  }

  bool Has(const std::string& key) {
  }
};

} // namespace xhermes::config

