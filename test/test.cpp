#define CATCH_CONFIG_MAIN

#include <algorithm>
#include "../src/cs-iv-algorithm.h"
#include "../src/catch.hpp"

TEST_CASE("Construction of object - default", "[Default Constructor]") {
    sortT testBox;
    REQUIRE(testBox.getUpLim() == 3);
    REQUIRE(testBox.list.size() == 0);
    testBox.testWith(std::sort);
    REQUIRE(testBox.list.size() == 3);
}

TEST_CASE("Construction of object - param", "[Param Constructor]") {
    sortT testBox(6);
    REQUIRE(testBox.getUpLim() == 6);
    REQUIRE(testBox.list.size() == 0);
    testBox.testWith(std::sort);
    REQUIRE(testBox.list.size() == 6);
}

TEST_CASE("Construction of object - param & 0 UpLimit",
          "[UpLimit 0 Param Constructor]") {
    sortT testBox(0);
    REQUIRE(testBox.getUpLim() == 3);
    REQUIRE(testBox.list.size() == 0);
    testBox.testWith(std::sort);
    REQUIRE(testBox.list.size() == 3);
}

TEST_CASE("Construction of object - param & 100 UpLimit",
          "[UpLimit overflow Param Constructor]") {
    sortT testBox(100);
    long long sentinel = std::numeric_limits<long long>::max();
    sentinel = sentinel - (sentinel % 10);
    unsigned int k = 0;
    while (sentinel != 0) {
        sentinel /= 10;
        ++k;
    }

    REQUIRE(testBox.getUpLim() == 3);
    REQUIRE(testBox.list.size() == 0);
    testBox.testWith(std::sort);
    REQUIRE(testBox.list.size() == 3);
}
