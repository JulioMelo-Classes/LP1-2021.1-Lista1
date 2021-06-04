/*!
 * @file test_manager.cpp
 * @brief Implementation of the TestManager class.
 * @date November 15th, 2019
 * @author Selan R. dos Santos
 */

#include "test_manager.h"

/*!
 * Updates the test result database.
 * @param key The unique test key, which is the test's name.
 * @param value The result of the test, that might either be `true` or `false`.
 * @param line The line number in the source code, where the teste happened.
 */
void TestManager::result( const std::string &key, bool value, int line )
{
    // Get previous result.
    auto old_entry = tests_record[ key ];
    // We only update if the previous result is TRUE or UNDEFINED.
    // Otherwise, we keep the first failure.
    if ( old_entry.m_result == Entry::result_t::SUCCESS or
         old_entry.m_result == Entry::result_t::UNDEFINED )
    {
        tests_record[key].m_result = value ? Entry::result_t::SUCCESS : Entry::result_t::FAILED ; // Update the result.
        tests_record[key].m_line = line;     // Update the line.
    }
}

void TestManager::summary(void) const
{
    size_t n_successful{0}, n_failed{0}, n_disabled{0}, n_undefined{0};

    // This list helps us to print all the test results in the same order
    // the user specified in his/get client code.
    using hash_item = std::pair< std::string, Entry >;
    std::vector< hash_item > sorted_list;
    // Copy the hash table to a vector, so we can sort the item by sequence.
    std::copy ( tests_record.begin(), tests_record.end(), std::back_inserter( sorted_list ) );
    // Sort the vector
    std::sort( sorted_list.begin(), sorted_list.end(),
            [](const hash_item& h1, const hash_item& h2 )->bool
            { return h1.second.m_seq < h2.second.m_seq; } );

    // Print out the tests result from the sorted list.
    std::cout << "[===========] Running " << n_tests << " from the \""  << test_suite_name << "\" test suite.\n";
    for ( const auto & t : sorted_list )
    {
        print_test_result( t.first, t.second );
        if ( not t.second.m_enabled ) n_disabled++;
        else if ( t.second.m_result == TestManager::Entry::result_t::SUCCESS ) n_successful++;
        else if ( t.second.m_result == TestManager::Entry::result_t::FAILED ) n_failed++;
        else if ( t.second.m_result == TestManager::Entry::result_t::UNDEFINED ) n_undefined++;
    }
    std::cout << "[===========] " << n_tests << " tests from the \"" << test_suite_name << "\" test suite ran.\n";

    // Final summary
    if ( n_successful != 0 ) std::cout << "[ "<< "\e[1;32mPASSED\e[0m"    << "    ] " << n_successful << " tests.\n";
    if ( n_failed != 0 )     std::cout << "[ "<< "\e[1;31mFAILED\e[0m"    << "    ] " << n_failed     << " tests.\n";
    if ( n_disabled != 0 )   std::cout << "[ "<< "\e[1;36mDISABLED\e[0m"  << "  ] "   << n_disabled   << " tests.\n";
    if ( n_undefined != 0 )  std::cout << "[ "<< "\e[1;35mUNDEFINED\e[0m" << " ] "    << n_undefined  << " tests.\n";
}
