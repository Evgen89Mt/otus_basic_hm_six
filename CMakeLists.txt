cmake_minimum_required(VERSION 3.20)

project(06_hm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/new_vector.cpp
)

target_include_directories(
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

message("!!! msg <CMAKE_SOURCE_DIR> ${CMAKE_SOURCE_DIR}")
message("!!! msg <CMAKE_BINARY_DIR> ${CMAKE_BINARY_DIR}")
