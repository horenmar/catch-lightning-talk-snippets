cmake_minimum_required (VERSION 3.8)
project (catch-talk VERSION 0.1 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Catch2 REQUIRED)

enable_testing()

add_executable(simple-generator generators/simple-generator.cpp catch-main.cpp)
target_link_libraries(simple-generator Catch2::Catch2)
add_test(NAME SimpleGen COMMAND simple-generator)

add_executable(chained-generators generators/chained-generators.cpp catch-main.cpp)
target_link_libraries(chained-generators Catch2::Catch2)
add_test(NAME ChainedGen COMMAND chained-generators)

add_executable(nested-generator generators/nested-generator.cpp catch-main.cpp)
target_link_libraries(nested-generator Catch2::Catch2)
add_test(NAME NestedGen COMMAND nested-generator)

add_executable(file-generator generators/file-generator.cpp catch-main.cpp)
target_link_libraries(file-generator Catch2::Catch2)
add_test(NAME FileGen COMMAND file-generator)



add_executable(template-test-case templates/simple-template-testcase.cpp catch-main.cpp)
target_link_libraries(template-test-case Catch2::Catch2)
add_test(NAME TemplateTestCase COMMAND template-test-case)

add_executable(template-product-test-case templates/template-product-testcase.cpp catch-main.cpp)
target_link_libraries(template-product-test-case Catch2::Catch2)
add_test(NAME ProductTestCase COMMAND template-product-test-case)

add_executable(NTTP-test-case templates/nttp-template-testcase.cpp catch-main.cpp)
target_link_libraries(NTTP-test-case Catch2::Catch2)
add_test(NAME NttpTestCase COMMAND NTTP-test-case)



add_executable(simple-benchmark benchmarks/simple-benchmark.cpp catch-main.cpp)
target_compile_definitions(simple-benchmark PRIVATE CATCH_CONFIG_ENABLE_BENCHMARKING)
target_link_libraries(simple-benchmark Catch2::Catch2)
add_test(NAME BasicBench COMMAND simple-benchmark)
