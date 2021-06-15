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
        BEGIN_TEST(tm, "Vetor vazio", "[reverse]");
        std::array<string,0> A;

        reverse( A );
        EXPECT_TRUE( A.size() == 0 );
    }

    {

        BEGIN_TEST(tm,"Inverte vetor tamanho ímpar", "[reverse]");
        std::array<string,7> A{"7", "6", "5", "4", "3", "2", "1"};
        std::array<string,7> B{"1", "2", "3", "4", "5", "6", "7"};

        reverse( A );
        EXPECT_TRUE( A == B );

    }

    {

        BEGIN_TEST( tm,"Inverte vetor tamanho par", "[reverse]");
        std::array<string,6> A{"6", "5", "4", "3", "2", "1"};
        std::array<string,6> B{"1", "2", "3", "4", "5", "6"};

        reverse( A );
        EXPECT_TRUE( A == B );
    }

    {
        BEGIN_TEST( tm,"Vetor com 1 elemento", "[reverse]");
        std::array<string,1> A{"3"};
        std::array<string,1> B{"3"};

        reverse( A );
        EXPECT_TRUE( A == B );
    }

    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
