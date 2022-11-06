cmake_minimum_required(VERSION 3.22)
project(ft_irc)

set(CMAKE_CXX_STANDARD 98)
include_directories(includes)
add_executable(ft_irc src/main.cpp
        src/Server.cpp src/User.cpp includes/User.hpp src/message.cpp includes/message.h)
