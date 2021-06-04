#include "function.h"

#include <iterator>
using std::iter_swap;

/*! 
 * Reverse de order of elements inside the array.
 * @param arr Reference to the array with the values.
 */
template <size_t SIZE>
void reverse( std::array< std::string, SIZE > & arr )
{
    auto first = arr.begin();
    auto last = arr.last();

    while( first != last and first != --last )
        std::iter_swap( first++, last );
}
