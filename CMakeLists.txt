cmake_minimum_required(VERSION 3.5)

project(FastRTTI VERSION 1.0.0)

file(GLOB_RECURSE SRC "*.cpp" "*.h")

add_subdirectory(RTTI)
add_subdirectory(Tests)