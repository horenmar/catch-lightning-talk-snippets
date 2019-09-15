#include <catch2/catch.hpp>

TEST_CASE("nested generators", "[generators]") {
    auto i = GENERATE(2, 3, 5, 7);
    auto j = GENERATE_COPY(filter([i](int n) {return n % i == 0;} , range(0, 100)));
    REQUIRE(j % i == 0);
}
