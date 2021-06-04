#include "include/catch2/catch.hpp"
#include "../src/function.h"


TEST_CASE("Empty array", "[min_max]")
{
    int A[]{};
    size_t n{0};

    auto [ mi, ma ] = min_max( A, n );
    REQUIRE( mi == -1 );
    REQUIRE( ma == -1 );
}

TEST_CASE("Single Element", "[min_max]")
{
    int A[]{5};
    size_t n{1};

    auto [ mi, ma ] = min_max( A, n );
    REQUIRE( mi == 0 );
    REQUIRE( ma == 0 );
}

TEST_CASE("Two elements, (a,b), so that a < b", "[min_max]")
{
    int A[]{1,2};
    size_t n{2};

    auto [ mi, ma ] = min_max( A, n );
    REQUIRE( mi == 0 );
    REQUIRE( ma == 1 );
}

TEST_CASE("Two elements, (a,b), so that a > b", "[min_max]")
{
    int A[]{2,1};
    size_t n{2};

    auto [ mi, ma ] = min_max( A, n );
    REQUIRE( mi == 1 );
    REQUIRE( ma == 0 );
}

TEST_CASE("Two elements, (a,b), so that a = b", "[min_max]")
{
    int A[]{2,2};
    size_t n{2};

    auto [ mi, ma ] = min_max( A, n );
    REQUIRE( mi == 0 );
    REQUIRE( ma == 1 );
}

TEST_CASE("Unique values in increasing order", "[min_max]")
{
    int A[]{1,2,3,4,5};
    size_t n{5};

    auto [ mi, ma ] = min_max( A, n );
    REQUIRE( mi == 0 );
    REQUIRE( ma == int(n-1) );
}

TEST_CASE("Unique values in decreasing order", "[min_max]")
{
    int A[]{5,4,3,2,1};
    size_t n{5};

    auto [ mi, ma ] = min_max( A, n );
    REQUIRE( mi == int(n-1) );
    REQUIRE( ma == 0 );
}

TEST_CASE("All equal", "[min_max]")
{
    int A[]{1,1,1,1,1};
    size_t n{5};

    auto [ mi, ma ] = min_max( A, n );
    REQUIRE( mi == 0 );
    REQUIRE( ma == int(n-1) );
}

TEST_CASE("Unique values, random order", "[min_max]")
{
    int A[]{ 2, 3, 5, 4, 1 };
    size_t n{5};

    auto [ mi, ma ] = min_max( A, n );
    REQUIRE( mi == 4 );
    REQUIRE( ma == 2 );
}

TEST_CASE("Repeated values, random order", "[min_max]")
{
    int A[]{ 2, 3, 2, 5, 1, 4, 5, 4, 1 };
    size_t n{9};

    auto [ mi, ma ] = min_max( A, n );
    REQUIRE( mi == 4 );
    REQUIRE( ma == 6 );
}
