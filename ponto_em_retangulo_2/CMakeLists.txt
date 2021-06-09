cmake_minimum_required(VERSION 3.0)
project ( Retangulo2 VERSION 1.0 LANGUAGES CXX )

#=== App target ===
set( APP_NAME "program" )
add_executable( ${APP_NAME} src/main.cpp src/function.cpp )
set_target_properties( ${APP_NAME} PROPERTIES CXX_STANDARD 17 )

#=== Testing by comparing OUTPUTs
if (MSVC)
    add_custom_target(
        verify
        COMMAND python3 ${CMAKE_SOURCE_DIR}/../scripts/verify-inputs.py ./DEBUG/${APP_NAME}
        DEPENDS ${APP_NAME}
    )
else()
    add_custom_target(
        verify
        COMMAND python3 ${CMAKE_SOURCE_DIR}/../scripts/verify-inputs.py ./${APP_NAME}
        DEPENDS ${APP_NAME}
    )
endif (MSVC)