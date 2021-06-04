add_library(Catch2 INTERFACE)
target_include_directories(Catch2 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# file( GLOB_RECURSE
      # TEST_FILES 
      # CONFIGURE_DEPENDS
      # "*.cpp"
# )
# add_executable(tests ${TEST_FILES} main.cpp)


# Add the always present main test...
add_executable( ${TEST_NAME} main.cpp )
#... and any other test source that have been created.
target_sources( ${TEST_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/test_01.cpp" )
# We link the library we want to test and the Catch2 library.
target_link_libraries( ${TEST_NAME} PRIVATE ${LIB_NAME} PRIVATE Catch2 )
