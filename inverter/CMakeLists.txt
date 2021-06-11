cmake_minimum_required(VERSION 3.0)
project (Inverter VERSION 1.0 LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 17)

#=== Lib target ===
#set( LIB_NAME "func" )
#add_library( ${LIB_NAME} src/function.cpp)
#set_target_properties( ${LIB_NAME} PROPERTIES CXX_STANDARD 11 )

# #=== Test target ===
set ( TEST_NAME "all_tests")
add_subdirectory(tests)

add_custom_target(
    run_tests
    COMMAND ${TEST_NAME}
    # COMMAND ${CMAKE_BINARY_DIR}/tests/tests
    #DEPENDS ${LIB_NAME}
)
