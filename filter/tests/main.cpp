#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()
using std::distance;
#include <algorithm>
using std::equal;

#include "include/tm/test_manager.h"
#include "../src/function.h"

int main ( void )
{
    // Creates a test manager for the DAL class.
    TestManager tm{ "Testing Filter function" };

    {
        //=== Test #1
        BEGIN_TEST(tm, "Basic", "Random values." );
        // DISABLE();
        int A[]{ 1, -2, 3, -4, 5, 0, -3, 8, -1 };
        size_t szA { sizeof(A)/sizeof(A[0]) };
        int B[]{ 1, 3, 5, 8 };

        auto endA = filter( &A[0], &A[szA] );
        EXPECT_TRUE( std::equal( std::begin(A), endA, std::begin(B) ) );
        EXPECT_EQ( std::distance( std::begin(A), endA ), 4 );
    }

    {
        //=== Test #2
        BEGIN_TEST(tm, "AllRejected", "All values must be filtered out (all negative or zero)." );
        // DISABLE();
        int A[]{ -1, -2, -3, -4, -5, 0, -3, -8, -1 };
        size_t szA { sizeof(A)/sizeof(A[0]) };

        auto endA = filter( &A[0], &A[szA] );
        EXPECT_EQ( std::distance( std::begin(A), endA ), 0 );
        EXPECT_EQ( std::begin(A), endA );
    }

    {
        //=== Test #3
        BEGIN_TEST(tm, "AllAccepted", "All values must remain (all positives)." );
        // DISABLE();
        int A[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        size_t szA { sizeof(A)/sizeof(A[0]) };
        int B[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        auto endA = filter( &A[0], &A[szA] );
        EXPECT_TRUE( std::equal( std::begin(A), endA, std::begin(B) ) );
        EXPECT_EQ( std::distance( std::begin(A), endA ), (long)szA );
        EXPECT_EQ( std::end(A), endA );
    }

    {
        //=== Test #4
        BEGIN_TEST(tm, "FirstHalfRejected", "The first half of the array must be rejected." );
        // DISABLE();
        int A[]{ -1, -2, -3, -4, -5, 6, 7, 8, 9, 10 };
        size_t szA { sizeof(A)/sizeof(A[0]) };
        int B[]{ 6, 7, 8, 9, 10 };
        size_t szB { sizeof(B)/sizeof(B[0]) };

        auto endA = filter( &A[0], &A[szA] );
        EXPECT_TRUE( std::equal( std::begin(A), endA, std::begin(B) ) );
        EXPECT_EQ( std::distance( std::begin(A), endA ), (long)szB );
    }

    {
        //=== Test #5
        BEGIN_TEST(tm, "LastHalfRejected", "The last half of the array must be rejected." );
        // DISABLE();
        int A[]{ 1, 2, 3, 4, 5, -6, -7, -8, -9, -10 };
        size_t szA { sizeof(A)/sizeof(A[0]) };
        int B[]{ 1, 2, 3, 4, 5 };
        size_t szB { sizeof(B)/sizeof(B[0]) };

        auto endA = filter( &A[0], &A[szA] );
        EXPECT_TRUE( std::equal( std::begin(A), endA, std::begin(B) ) );
        EXPECT_EQ( std::distance( std::begin(A), endA ), (long)szB );
    }

    tm.summary();
    std::cout << std::endl;

    return EXIT_SUCCESS;

}
