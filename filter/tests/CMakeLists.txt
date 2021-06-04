# Using TestManager Library
# Compile the TestManagere first into a lib.
set( TEST_API "TM")
add_library(${TEST_API} STATIC ${CMAKE_CURRENT_SOURCE_DIR}/include/tm/test_manager.cpp)
target_include_directories( ${TEST_API} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties( ${TEST_API} PROPERTIES CXX_STANDARD 11 )

# Add the always present main test...
add_executable( ${TEST_NAME} main.cpp )
target_include_directories( ${TEST_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
#... and any other test source that have been created.
# target_sources( ${TEST_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/test_01.cpp" )
# We link the library we want to test and the Catch2 library.
target_link_libraries( ${TEST_NAME} PRIVATE ${LIB_NAME} PRIVATE ${TEST_API} )
