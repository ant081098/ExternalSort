cmake_minimum_required(VERSION 3.5)

project(ExternalSort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ExternalSort main.cpp)

install(TARGETS ExternalSort
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
