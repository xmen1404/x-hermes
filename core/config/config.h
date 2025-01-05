#pragma once

#include <string>
#include "yaml-cpp/yaml.h"
#include <unordered_map>

namespace xhermes::config {
    class Config {
        public:
            template <typename T>
            T Get(const std::string &key) {
                return node_[key].as<T>();
            }
            bool Has(const std::string &key) {
                if (node_[key]) return true;
                else            return false;
            }
            Config() {}
            Config(const YAML::Node &node) : node_(node) {}
            Config(const std::string &filepath) {
                node_ = YAML::LoadFile(filepath);
            }
            friend struct YAML::convert<xhermes::config::Config>;

        private:
            YAML::Node node_;
    };
} // namespace xhermes::config

namespace YAML {
    template<>
    struct convert<xhermes::config::Config> {
        static Node encode(const xhermes::config::Config& rhs) {
            return rhs.node_;
        }
        
        static bool decode(const Node& node, xhermes::config::Config& rhs) {
            rhs.node_ = node;
            return true;
        }
    };
}

