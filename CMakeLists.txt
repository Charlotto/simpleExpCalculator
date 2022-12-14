cmake_minimum_required(VERSION 3.22)
project(InfixToPostfixExpression)

set(CMAKE_CXX_STANDARD 11)

add_library(expconvert SHARED
    src/expconvert.cpp
)

add_library(valcheck SHARED
        src/expcheck.cpp
)

add_library(expio SHARED
        src/expio.cpp
)

add_library(expcalc SHARED
    src/expcalc.cpp
)

target_include_directories(expconvert
        PUBLIC
            ${PROJECT_SOURCE_DIR}/include
)
target_include_directories(valcheck
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
target_include_directories(expio
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(expcalc
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)


add_executable(expbinary
        src/main.cpp
)

target_link_libraries(expbinary
    PRIVATE
        expconvert
        valcheck
        expio
        expcalc

)
