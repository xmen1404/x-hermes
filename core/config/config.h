#pragma once

#include <string>
#include <unordered_map>

namespace xhermes::config {

class Config {
public: 
  template <typename T>
  T Get(const std::string key) {
    return data_[key];
  }

private:
  std::unordered_map<std::string, std::string> data_;
};

} // namespace xhermes::config

