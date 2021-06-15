#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()
#include <vector>
#include <array>

#include "test_manager.h"
#include "function.h"


int main ( void )
{
    TestManager tm{ "Test Set" };
    {
        BEGIN_TEST( tm,"Empty array", "[min_max]");
        {
            int A[1] = {0}; //vetor vazio
            size_t n{0};

            auto [ mi, ma ] = min_max( A, n );
            EXPECT_TRUE( mi == -1 );
            EXPECT_TRUE( ma == -1 );
        }
    }

    {
        BEGIN_TEST( tm,"Single Element", "[min_max]");
        {
            int A[]{5};
            size_t n{1};

            auto [ mi, ma ] = min_max( A, n );
            EXPECT_TRUE( mi == 0 );
            EXPECT_TRUE( ma == 0 );
        }
    }

    {

       BEGIN_TEST( tm,"Two elements, (a,b), so that a < b", "[min_max]");
       {  
            int A[]{1,2};
            size_t n{2};

            auto [ mi, ma ] = min_max( A, n );
            EXPECT_TRUE( mi == 0 );
            EXPECT_TRUE( ma == 1 );
       }
    }

    {
        BEGIN_TEST( tm,"Two elements, (a,b), so that a > b", "[min_max]");
        {
            int A[]{2,1};
            size_t n{2};

            auto [ mi, ma ] = min_max( A, n );
            EXPECT_TRUE( mi == 1 );
            EXPECT_TRUE( ma == 0 );
        }
    }
    {
        BEGIN_TEST( tm,"Two elements, (a,b), so that a = b", "[min_max]");
        {
            int A[]{2,2};
            size_t n{2};

            auto [ mi, ma ] = min_max( A, n );
            EXPECT_TRUE( mi == 0 );
            EXPECT_TRUE( ma == 1 );
        }
    }
    {
        BEGIN_TEST( tm,"Unique values in increasing order", "[min_max]");
        {
            int A[]{1,2,3,4,5};
            size_t n{5};

            auto [ mi, ma ] = min_max( A, n );
            EXPECT_TRUE( mi == 0 );
            EXPECT_TRUE( ma == int(n-1) );
        }
    }

    {
        BEGIN_TEST( tm,"Unique values in decreasing order", "[min_max]");
        {
            int A[]{5,4,3,2,1};
            size_t n{5};

            auto [ mi, ma ] = min_max( A, n );
            EXPECT_TRUE( mi == int(n-1) );
            EXPECT_TRUE( ma == 0 );
        }
    }

    {
        BEGIN_TEST( tm,"All equal", "[min_max]");
        {
            int A[]{1,1,1,1,1};
            size_t n{5};

            auto [ mi, ma ] = min_max( A, n );
            EXPECT_TRUE( mi == 0 );
            EXPECT_TRUE( ma == int(n-1) );
        }
    }

    {
        BEGIN_TEST( tm,"Unique values, random order", "[min_max]");
        {
            int A[]{ 2, 3, 5, 4, 1 };
            size_t n{5};

            auto [ mi, ma ] = min_max( A, n );
            EXPECT_TRUE( mi == 4 );
            EXPECT_TRUE( ma == 2 );
        }
    }

    {
        BEGIN_TEST( tm,"Repeated values, random order", "[min_max]");
        {
            int A[]{ 2, 3, 2, 5, 1, 4, 5, 4, 1 };
            size_t n{9};

            auto [ mi, ma ] = min_max( A, n );
            EXPECT_TRUE( mi == 4 );
            EXPECT_TRUE( ma == 6 );
        }
    }

    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
