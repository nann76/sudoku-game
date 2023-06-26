cmake_minimum_required(VERSION 3.0)
project(sudoku)
set(CMAKE_EXE_LINKER_FLAGS -static)
set(CMAKE_CXX_STANDARD 17)

add_executable(sudoku main.cpp assert.h common.h sudoku.h getopt.h sudoku.cpp unittests.cpp)

add_subdirectory(./googletest)
include_directories(./googletest/include)
link_directories(${PROJECT_SOURCE_DIR}/googletest)
target_link_libraries(${PROJECT_NAME} gtest)