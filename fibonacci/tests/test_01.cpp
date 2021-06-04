#include "include/catch2/catch.hpp"
#include "../src/function.h"

#include <vector>
using std::vector;

TEST_CASE("Fibonacci(1) ", "[fib_below_n]")
{
    // There is no number below 1 in FIbobacci series.
    auto result = fib_below_n(1);
    REQUIRE(result.empty() == true);
}

TEST_CASE("Fibonacc(2)", "[fib_below_n]")
{
    std::vector<unsigned int> expected {1,1}; // There is no number below 1 in FIbobacci series.
    REQUIRE(fib_below_n(2) == expected);
}

TEST_CASE("Fibonacci (8) ", "[fib_below_n]")
{
    std::vector<unsigned int> expected {1,1,2,3,5}; // There is no number below 1 in FIbobacci series.
    REQUIRE(fib_below_n(8) == expected);
}

TEST_CASE("Fibonacci from 9 to 13 ", "[fib_below_n]")
{
    std::vector<unsigned int> expected {1,1,2,3,5,8}; // There is no number below 1 in FIbobacci series.
    REQUIRE(fib_below_n(9) == expected);
    REQUIRE(fib_below_n(10) == expected);
    REQUIRE(fib_below_n(11) == expected);
    REQUIRE(fib_below_n(12) == expected);
    REQUIRE(fib_below_n(13) == expected);
}

TEST_CASE("Fibonacci from 14 to 21", "[fib_below_n]")
{
    std::vector<unsigned int> expected {1,1,2,3,5,8,13}; // There is no number below 1 in FIbobacci series.
    for ( auto i{14} ; i < 22 ; ++i )
        REQUIRE(fib_below_n(i) == expected);
}
