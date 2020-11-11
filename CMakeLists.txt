cmake_minimum_required(VERSION 3.6.0)

# CMake 3.6. supports VS_STARTUP_PROJECT, see https://cmake.org/cmake/help/v3.6/prop_dir/VS_STARTUP_PROJECT.html

project(ValidateMaaJwt)

add_executable(validatejwt main.cpp)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT validatejwt)

