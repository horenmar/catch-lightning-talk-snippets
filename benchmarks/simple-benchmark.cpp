#include <catch2/catch.hpp>

uint64_t fib(uint64_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

TEST_CASE("Test and benchmark") {
    REQUIRE(fib(20) == 6765);

    BENCHMARK("fib 20") {
        return fib(20);
    };

    CHECK(fib(0) == 0);
}
