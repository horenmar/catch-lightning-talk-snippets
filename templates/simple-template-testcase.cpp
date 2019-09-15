#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE("You can have a test across multiple types", "",
                   int, float) {

    std::vector<TestType> vec;
    REQUIRE(vec.size() == 0);
    REQUIRE(vec.capacity() == 0);

    vec.reserve(5);
    REQUIRE(vec.size() == 0);
    REQUIRE(vec.capacity() >= 5);
}

using MyTypes = std::tuple<int, float>;

TEMPLATE_LIST_TEST_CASE("You can use existing type lists", "",
                        MyTypes) {

    std::vector<TestType> vec;
    REQUIRE(vec.size() == 0);
    REQUIRE(vec.capacity() == 0);

    vec.reserve(5);

    REQUIRE(vec.size() == 0);
    REQUIRE(vec.capacity() >= 5);
}
