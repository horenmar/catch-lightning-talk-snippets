#include <catch2/catch.hpp>

TEST_CASE("Chaining generators 1") {
    auto val = GENERATE(take(10, random(0., 10.)));

    REQUIRE(0. <= val);
    REQUIRE(val < 10.);
}

TEST_CASE("Chaining generators 2") {
    auto val = GENERATE(take(10,
                        filter([] (int val) { return val % 5 == 0; },
                        random(0, 100))));
}
