cmake_minimum_required(VERSION 3.22)
project(ft_irc)

set(CMAKE_CXX_STANDARD 98)
include_directories(includes)
add_executable(ft_irc src/main.cpp
        src/server.cpp src/Json.cpp includes/Json.hpp)
