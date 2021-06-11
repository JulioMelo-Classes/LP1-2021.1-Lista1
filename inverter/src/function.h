#ifndef FUNCTION_H
#define FUNCTION_H
#include <array>
using std::array;

#include <string>
using std::string;

template <size_t SIZE>
void reverse( std::array<std::string,SIZE> & arr );

#include "function.cpp"
#endif
