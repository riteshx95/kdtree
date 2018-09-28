cmake_minimum_required(VERSION 3.7)
project(kdtest)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_library(libkdtree ${SOURCES} ${HEADERS})

add_executable(kdtest "src/test.cpp")

target_link_libraries(kdtest libkdtree stdc++fs)
