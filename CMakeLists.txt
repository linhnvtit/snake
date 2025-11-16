cmake_minimum_required(VERSION 3.10)
project(snake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 REQUIRED)

# Recursively include all .cpp files in project (exclude build folder)
file(GLOB_RECURSE SRC_FILES
        src/*.cpp
        src/looper/*.cpp
        src/map_controller/*.cpp
        src/map_controller/obj/*.cpp
)
add_executable(snake main.cpp ${SRC_FILES})

target_link_libraries(snake PRIVATE SDL2::SDL2)
target_include_directories(snake PRIVATE ${SDL2_INCLUDE_DIRS})
