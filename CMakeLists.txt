cmake_minimum_required(VERSION 3.6.0)
project(validatejwt)

if (CMAKE_HOST_WIN32)
    set(WINDOWS 1)
elseif(CMAKE_HOST_UNIX)
    set(LINUX 1)
endif()

add_executable(validatejwt main.cpp)

if(WINDOWS)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT validatejwt)
#elseif(LINUX)
endif()

