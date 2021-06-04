#include "include/catch2/catch.hpp"
#include "../src/function.h"

#include <array>
using std::array;
#include <string>
using std::string;

TEST_CASE("Vetor vazio", "[reverse]")
{
    std::array<string,0> A;

    reverse( A );
    REQUIRE( A.size() == 0 );
}

TEST_CASE("Inverte vetor tamanho ímpar", "[reverse]")
{
    std::array<string,7> A{"7", "6", "5", "4", "3", "2", "1"};
    std::array<string,7> B{"1", "2", "3", "4", "5", "6", "7"};

    reverse( A );
    REQUIRE( A == B );
}

TEST_CASE("Inverte vetor tamanho par", "[reverse]")
{
    std::array<string,6> A{"6", "5", "4", "3", "2", "1"};
    std::array<string,6> B{"1", "2", "3", "4", "5", "6"};

    reverse( A );
    REQUIRE( A == B );
}

TEST_CASE("Vetor com 1 elemento", "[reverse]")
{
    std::array<string,1> A{"3"};
    std::array<string,1> B{"3"};

    reverse( A );
    REQUIRE( A == B );
}
