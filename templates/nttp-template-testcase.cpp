#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE_SIG("NTTPs: list of types", "",
                      ((typename T, int V), T, V),
                      (int, 5), (float, 4),
                      ((std::tuple<int, float>), 6)) {

    std::vector<T> v;
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);

    SECTION("resizing bigger changes size and capacity") {
        v.resize(2 * V);

        REQUIRE(v.size() == 2 * V);
        REQUIRE(v.capacity() >= 2 * V);
    }
}

template <typename T, size_t Size>
struct Bar {
    size_t size() const { return Size; }
};

TEMPLATE_PRODUCT_TEST_CASE_SIG("NTTPs: product types", "",
                               ((typename T, size_t S), T, S),
                               (std::array, Bar),
                               ((int, 9), (float, 42))) {
    TestType x;
    REQUIRE(x.size() > 0);
}
