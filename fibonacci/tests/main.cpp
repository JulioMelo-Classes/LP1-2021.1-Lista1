#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()
#include <vector>

#include "test_manager.h"
#include "function.h"


int main ( void )
{
    TestManager tm{ "Test Set" };
    {
        BEGIN_TEST( tm,"Fibonacci(1) ", "[fib_below_n]");
        // There is no number below 1 in FIbobacci series.
        auto result = fib_below_n(1);
        EXPECT_TRUE( result.empty() );
    }

    {
        BEGIN_TEST( tm,"Fibonacc(2)", "[fib_below_n]");
        std::vector<unsigned int> expected {1,1}; // There is no number below 1 in FIbobacci series.
        EXPECT_TRUE(fib_below_n(2) == expected);
    }

    {
        BEGIN_TEST( tm,"Fibonacci (8) ", "[fib_below_n]");
        std::vector<unsigned int> expected {1,1,2,3,5}; // There is no number below 1 in FIbobacci series.
        EXPECT_TRUE( fib_below_n(8) == expected );
    }

    {
        BEGIN_TEST(tm, "Fibonacci from 9 to 13 ", "[fib_below_n]");
        std::vector<unsigned int> expected {1,1,2,3,5,8}; // There is no number below 1 in FIbobacci series.
        EXPECT_TRUE(fib_below_n(9) == expected);
        EXPECT_TRUE(fib_below_n(10) == expected);
        EXPECT_TRUE(fib_below_n(11) == expected);
        EXPECT_TRUE(fib_below_n(12) == expected);
        EXPECT_TRUE(fib_below_n(13) == expected);
    }

    {
        
        BEGIN_TEST(tm, "Fibonacci from 14 to 21", "[fib_below_n]");
        std::vector<unsigned int> expected {1,1,2,3,5,8,13}; // There is no number below 1 in FIbobacci series.
        for ( auto i{14} ; i < 22 ; ++i )
            EXPECT_TRUE(fib_below_n(i) == expected);
    }

    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
