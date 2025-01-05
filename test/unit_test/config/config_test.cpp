#include <catch2/catch_test_macros.hpp>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

// #include "yaml-cpp/yaml.h"
#include "config.h"

using namespace xhermes::config;

TEST_CASE("Config Loading Test") {
    Config config("config_test.yaml");

    REQUIRE((config.Has("doe") && config.Get<std::string>("doe") == "a deer, a female deer"));
    REQUIRE((config.Has("ray") && config.Get<std::string>("ray") == "a drop of golden sun"));
    REQUIRE((config.Has("pi") && config.Get<float>("pi") == 3.14159f));
    REQUIRE((config.Has("xmas") && config.Get<bool>("xmas") == true));
    REQUIRE((config.Has("french-hens") && config.Get<int>("french-hens") == 3));

    // Validate "calling-birds" sequence
    REQUIRE(config.Has("calling-birds"));
    REQUIRE(config.Get<std::vector<std::string>>("calling-birds") == std::vector<std::string>{"huey", "dewey", "louie", "fred"});

    // Validate "xmas-fifth-day" nested structure
    REQUIRE(config.Has("xmas-fifth-day"));
    Config xmasFifthDay = config.Get<Config>("xmas-fifth-day");

    REQUIRE((xmasFifthDay.Has("calling-birds") && xmasFifthDay.Get<std::string>("calling-birds") == "four"));
    REQUIRE((xmasFifthDay.Has("french-hens") && xmasFifthDay.Get<int>("french-hens") == 3));
    REQUIRE((xmasFifthDay.Has("golden-rings") && xmasFifthDay.Get<int>("golden-rings") == 5));
    REQUIRE((xmasFifthDay.Has("turtle-doves") && xmasFifthDay.Get<std::string>("turtle-doves") == "two"));

    REQUIRE(xmasFifthDay.Has("partridges"));
    Config partridges = xmasFifthDay.Get<Config>("partridges");
    
    REQUIRE((partridges.Has("count") && partridges.Get<int>("count") == 1));
    REQUIRE((partridges.Has("location") && partridges.Get<std::string>("location") == "a pear tree"));
}