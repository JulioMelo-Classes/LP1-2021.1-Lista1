#ifndef _TEST_MANAGER_
#define _TEST_MANAGER_

/*!
 * @file test_manager.h
 * @brief Definition of the TestManager class.
 * @date November 15th, 2019
 * @author Selan R. dos Santos
 * 
 * Updated on January 27th, 2021: improved macro definition and unified divergent versions.
 */

#include <iostream>   // cout, endl
using std::cout;
using std::endl;
#include <iomanip>    // setw
using std::setw;
#include <algorithm>  // shuffle, copy
using std::shuffle;
using std::copy;
#include <string>
using std::string;

#include <unordered_map>
using std::unordered_map;
#include <vector>
using std::vector;


/// Implements a simple test manager.
class TestManager {
    private:
        /// Defines a single entry in our database.
        struct Entry {
            /// List of possible test results.
            enum class result_t : int { SUCCESS, FAILED, UNDEFINED };
            string m_desc;     //!< The test text description.
            size_t m_seq;      //!< The test sequence number, to help us print the test in the order the client registered them.
            result_t m_result; //!< The test result.
            int m_line;        //!< The test line number.
            bool m_enabled;    //!< Indicates wheter the test is enabled (default) or not.
            /// Default Ctro
            Entry( string d="no_name", size_t s = 0, result_t r=result_t::UNDEFINED, int l=0, bool e=true )
                : m_desc{ d }, m_seq{ s }, m_result{ r }, m_line{ l }, m_enabled{ e }
            { /* empty */ }
        };
        /// Records the tests results. The key is the test name, and the data is an `Entry`.
        std::unordered_map< std::string, Entry > tests_record;
        /// The test suite name.
        std::string test_suite_name;
        /// Number of tests registred.
        size_t n_tests;

    private:
        /// Prints out the overall result of a single test.
        void print_test_result( const std::string &test_name, const Entry &entry ) const
        {
            std::cout << "[ " << "\e[1;34mRUN\e[0m" << "       ] " << test_name << "-> " << entry.m_desc << std::endl;
            if ( entry.m_enabled == false )
            {
                std::cout << "[  " << "\e[1;36mDISABLED\e[0m" << " ]\n";
                return;
            }
            if ( entry.m_result == Entry::result_t::SUCCESS )
                std::cout << "[        " << "\e[1;32mOK\e[0m" << " ]\n";
            else if ( entry.m_result == Entry::result_t::FAILED )
                std::cout << "[      "  << "\e[1;31mFAIL\e[0m" << " ] at line " << entry.m_line << ".\n";
            else if ( entry.m_result == Entry::result_t::UNDEFINED )
                std::cout << "[ "  << "\e[1;35mUNDEFINED\e[0m" << " ] at line " << entry.m_line << ".\n";
        }

        //=== Public interface.
    public:
        /// Default constructor that may take the test suite name.
        explicit TestManager( const std::string suite_name="Default" )
            : test_suite_name{ suite_name }, n_tests{0}
        { /* empty */ }

        /// Registers a test with this suite
        inline void record ( const std::string &key_name, const std::string& msg )
        {
            // Store the entry in the data base.
            tests_record[key_name] = Entry{ msg, n_tests++ };
        }

        inline void enable ( const std::string &key_name, bool value=true )
        {
            // First, let us see if the key is recorded (test has been registered)
            if ( tests_record.count( key_name ) == 0 ) return;

            // Ok, test present. Just set the disabled status accordingly.
            tests_record[ key_name ].m_enabled = value;
        }

        /// Updates the test result.
        void result( const std::string &key, bool value, int line );

        /// Shows the test suite results.
        void summary(void) const;
};

//=== MACRO definitions.
#define BEGIN_TEST(tm, key, msg) std::string _test_id{key}; \
    TestManager &_tm = tm; \
    _tm.record( key, msg )
#endif
//#define RESULT(tm, key, res) tm.result( key, res, __LINE__ )
#define RESULT(key, res) _tm.result( key, res, __LINE__ )
//#define REGISTER(tm, key, msg) tm.record( key, msg )
#define REGISTER(key, msg) _tm.record( key, msg )
#define EXPECT_TRUE( value ) _tm.result( _test_id, value==true, __LINE__ )
#define EXPECT_FALSE( value ) _tm.result( _test_id, value==false, __LINE__ )
#define EXPECT_EQ( value1, value2 ) _tm.result( _test_id, value1==value2, __LINE__ )
#define EXPECT_NE( value1, value2 ) _tm.result( _test_id, value1!=value2, __LINE__ )
#define EXPECT_GT( value1, value2 ) _tm.result( _test_id, value1>value2, __LINE__ )
#define EXPECT_GE( value1, value2 ) _tm.result( _test_id, value1>=value2, __LINE__ )
#define EXPECT_LT( value1, value2 ) _tm.result( _test_id, value1<value2, __LINE__ )
#define EXPECT_LE( value1, value2 ) _tm.result( _test_id, value1<=value2, __LINE__ )
#define DISABLE() _tm.enable( _test_id, false );

