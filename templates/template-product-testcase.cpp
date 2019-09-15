#include <catch2/catch.hpp>

#include <vector>
#include <list>

TEMPLATE_PRODUCT_TEST_CASE("Products of type lists", "",
                          (std::vector, std::list),
                          (int, float)) {

    TestType x;
    REQUIRE(x.size() == 0);
    
    x.emplace_back();
    x.emplace_back();
    REQUIRE(x.size() == 2);
}
