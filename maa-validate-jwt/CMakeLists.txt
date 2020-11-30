cmake_minimum_required(VERSION 3.6.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(maa-validate-jwt)

if(CMAKE_HOST_WIN32)
    set(WINDOWS 1)
elseif(CMAKE_HOST_UNIX)
    set(LINUX 1)
endif()

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/options.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/options.h)
add_executable(maa-validate-jwt ${SOURCES} ${HEADERS})
target_include_directories(maa-validate-jwt PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(WINDOWS)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT maa-validate-jwt)
#elseif(LINUX)
endif()

