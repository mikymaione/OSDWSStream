cmake_minimum_required(VERSION 3.17)
project(src)

set(CMAKE_CXX_STANDARD 17)

add_executable(src main.cpp TCPServer.cpp TCPServer.hpp)