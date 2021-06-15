cmake_minimum_required(VERSION 3.0)
project (Inverter VERSION 1.0 LANGUAGES CXX )

#== find package, v3 version
# find_package(Catch2 REQUIRED)

set( CMAKE_CXX_STANDARD 17)

#=== Lib target ===
set( LIB_NAME "func" )
add_library( ${LIB_NAME} src/function.cpp)
set_target_properties( ${LIB_NAME} PROPERTIES CXX_STANDARD 11 )

# #=== Test target ===
set ( TEST_NAME "all_tests")

### [2] Test engine
# includes do test manager
include_directories( tests/lib/test_manager/include src/)

# Cria um executável com nome "run_tests", adiciona neste executável os arquivos do test manager e o seu main.cpp
add_executable( ${TEST_NAME}
                tests/lib/test_manager/src/test_manager.cpp
                tests/main.cpp )

target_link_libraries( ${TEST_NAME} ${LIB_NAME} )


# #=== Testing ===
# enable_testing()
# add_test( NAME ${TEST_NAME} COMMAND ${TEST_NAME} )
 
# add_custom_target(
    # verify
    # COMMAND python3 ${CMAKE_SOURCE_DIR}/scripts/verify-inputs.py ./${APP_NAME}
    # DEPENDS ${APP_NAME}
# )

add_custom_target(
    run_tests
    COMMAND ${TEST_NAME}
    # COMMAND ${CMAKE_BINARY_DIR}/tests/tests
    DEPENDS ${LIB_NAME}
)