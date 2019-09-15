#include <catch2/catch.hpp>

bool is_success_status(int value) {
    return value >= 200 && value < 300;
}

TEST_CASE("Simple generator") {
    auto [input, expected] = GENERATE(table<int, bool>({
        {101, false},
        {200, true},
        {201, true},
        {202, true},
        {226, true},
        {301, false},
        {403, false},
        {500, false},
    }));

    REQUIRE(is_success_status(input) == expected);
}
