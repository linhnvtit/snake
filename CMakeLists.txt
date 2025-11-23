cmake_minimum_required(VERSION 3.10)
project(snake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 REQUIRED)
find_package(pybind11 REQUIRED)

# Recursively include all .cpp files in project (exclude build folder)
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# run version
add_executable(snake main.cpp ${SRC_FILES})
target_link_libraries(snake PRIVATE SDL2::SDL2)
target_include_directories(snake PRIVATE ${SDL2_INCLUDE_DIRS})

# python binding version
pybind11_add_module(pySnake PyBinding.cpp ${SRC_FILES})
target_link_libraries(pySnake PRIVATE SDL2::SDL2)
target_include_directories(pySnake PRIVATE ${SDL2_INCLUDE_DIRS})
set_target_properties(pySnake PROPERTIES LIBRARY_OUTPUT_DIRECTORY '${CMAKE_SOURCE_DIR}/py_game')