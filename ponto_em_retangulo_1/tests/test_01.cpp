#include "include/catch2/catch.hpp"
#include "../src/function.h"
#include <iomanip>

#include <iostream>
using std::cout;

TEST_CASE("Regular - pontos nas arestas e cantos", "[retangulo1]")
{
    Ponto R1{ -99, -99 }, R2{ 99, 99};

    for( auto x{R1.x} ; x <= R2.x ; ++x )
    {
        cout << R1.x << " " << R1.y << "  " << R2.x << " " << R2.y << "   " << x << " " << R1.y << " border" << '\n';
        REQUIRE( location_t::BORDER == pt_in_rect( R1, R2, Ponto{x,R1.y} ) );

        cout << R1.x << " " << R1.y << "  " << R2.x << " " << R2.y << "   " << x << " " << R2.y << " border" << '\n';
        REQUIRE( location_t::BORDER == pt_in_rect( R1, R2, Ponto{x,R2.y} ) );
    }
    for( auto y{R1.y} ; y <= R2.y ; ++y )
    {
        cout << R1.x << " " << R1.y << "  " << R2.x << " " << R2.y << "   " << R1.x << " " << y << " border" << '\n';
        REQUIRE( location_t::BORDER == pt_in_rect( R1, R2, Ponto{R1.x,y} ) );

        cout << R1.x << " " << R1.y << "  " << R2.x << " " << R2.y << "   " << R2.x << " " << y << " border" << '\n';
        REQUIRE( location_t::BORDER == pt_in_rect( R1, R2, Ponto{R2.x,y} ) );
    }
}

TEST_CASE("Regular - dentro", "[retangulo1]")
{
    Ponto R1{ -99, -99 }, R2{ 99, 99};

    for( auto x{R1.x+1} ; x < R2.x ; ++x )
        for( auto y{R1.y+1} ; y < R2.y ; ++y )
        {
            cout << R1.x << " " << R1.y << "  " << R2.x << " " << R2.y << "   " << x << " " << y << " inside" << '\n';
            REQUIRE( location_t::INSIDE == pt_in_rect( R1, R2, Ponto{x,y} ) );
        }
}


TEST_CASE("Regular - fora 8 regiões", "[retangulo1]")
{
    Ponto R1{ -4, -5 }, R2{ 4, 5 };
    Ponto P[]{
        { 0,  6 }, // above
        { 0, -6 }, // below
        { 6,  0 }, // right
        { -6, 0 }, // left
        
        {  6,  6 }, // right(+)/above(+)
        {  6, -6 }, // right(+)/below(-)
        { -6,  6 }, // left(-)/above(+)
        { -6, -6 }  // left(-)/below(-)
    };

    for( const auto &p: P )
        REQUIRE( location_t::OUTSIDE == pt_in_rect( R1, R2, p ) );
}

TEST_CASE("Degenerado horizontal - pontos nas arestas e cantos", "[retangulo1]")
{
    Ponto R1{ -30, -22 }, R2{ 50, 35 };

    std::cout << "degenerado_horizontal_fronteiras.txt\n";
    for( auto x{R1.x} ; x <= R2.x ; ++x )
    {
        cout << std::setprecision(3) << R1.x << " " << R1.y << "  " << R2.x << " " << R2.y << "   " << x << " " << R1.y << " border" << '\n';
        REQUIRE( location_t::BORDER == pt_in_rect( R1, R2, Ponto{x,R1.y} ) );
    }
    std::cout << "degenerado_horizontal_fronteiras.txt\n";
}

TEST_CASE("Degenerado vertical - pontos nas arestas e cantos", "[retangulo1]")
{
    Ponto R1{ -30, -22 }, R2{ 50, 35 };

    std::cout << "degenerado_vertical_fronteiras.txt\n";
    for( auto y{R1.y} ; y <= R2.y ; ++y )
    {
        cout << std::setprecision(3) << R1.x << " " << R1.y << "  " << R2.x << " " << R2.y << "   " << R1.x << " " << y << " border" << '\n';
        REQUIRE( location_t::BORDER == pt_in_rect( R1, R2, Ponto{R1.x,y} ) );
    }
    std::cout << "degenerado_vertical_fronteiras.txt\n";
}

TEST_CASE("Degenerado horizontal - fora 6 regiões", "[retangulo1]")
{
    Ponto R1{ -4, 5 }, R2{ 4, 5 };

    // Acima
    for( auto x{R1.x-1} ; x <= R2.x+1 ; ++x )
    {
        cout << R1.x << " " << R1.y << "  " << R2.x << " " << R2.y << "   " << x << " " << R1.y+1 << " outside" << '\n';
        REQUIRE( location_t::OUTSIDE == pt_in_rect( R1, R2, Ponto{x,R1.y+1} ) );
    }
    // Abaixo
    for( auto x{R1.x-1} ; x <= R2.x+1 ; ++x )
    {
        cout << R1.x << " " << R1.y << "  " << R2.x << " " << R2.y << "   " << x << " " << R1.y-1 << " outside" << '\n';
        REQUIRE( location_t::OUTSIDE == pt_in_rect( R1, R2, Ponto{x,R1.y-1} ) );
    }
}

TEST_CASE("Degenerado vertical - fora 6 regiões", "[retangulo1]")
{
    Ponto R1{ 4, -5 }, R2{ 4, 5 };

    // Acima
    for( auto y{R1.y-1} ; y <= R2.y+1 ; ++y )
    {
        cout << R1.x << " " << R1.y << "  " << R2.x << " " << R2.y << "   " << R1.x+1 << " " << y << " outside" << '\n';
        REQUIRE( location_t::OUTSIDE == pt_in_rect( R1, R2, Ponto{R1.x+1, y} ) );
    }
    // Abaixo
    for( auto y{R1.y-1} ; y <= R2.y+1 ; ++y )
    {
        cout << R1.x << " " << R1.y << "  " << R2.x << " " << R2.y << "   " << R1.x-1 << " " << y << " outside" << '\n';
        REQUIRE( location_t::OUTSIDE == pt_in_rect( R1, R2, Ponto{R1.x-1, y} ) );
    }
}

