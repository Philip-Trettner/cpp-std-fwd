cmake_minimum_required(VERSION 3.8)
project(cpp-std-fwd)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "tests/*.*" "include/*")

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC "include/")

if(MSVC)
    target_compile_options(${PROJECT_NAME} PUBLIC
        /MP
        /FC
    )
else()
    target_compile_options(${PROJECT_NAME} PUBLIC
        -Wall
    )

    # Clang filesystem
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        target_link_libraries(${PROJECT_NAME} PUBLIC stdc++fs)
    endif()
endif()
