cmake_minimum_required(VERSION 3.2)
project ( Negativos5 VERSION 1.0 LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 17)

#=== App target ===
set( APP_NAME "program" )
add_executable( ${APP_NAME} src/main.cpp)
# # Edit this to add any extra source file you may wish to include in this project.
# target_sources( ${APP_NAME} PRIVATE "src/another_file.cpp" )
set_target_properties( ${APP_NAME} PROPERTIES CXX_STANDARD 11 )

add_custom_target(
    verify
    COMMAND python3 ${CMAKE_SOURCE_DIR}/../scripts/verify-inputs.py ./${APP_NAME}
    DEPENDS ${APP_NAME}
)
