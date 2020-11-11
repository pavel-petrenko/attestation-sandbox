cmake_minimum_required(VERSION 3.6.0)
project(maavalidatejwt)

if (CMAKE_HOST_WIN32)
    set(WINDOWS 1)
elseif(CMAKE_HOST_UNIX)
    set(LINUX 1)
endif()

add_executable(maavalidatejwt main.cpp)

if(WINDOWS)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT maavalidatejwt)
#elseif(LINUX)
endif()

