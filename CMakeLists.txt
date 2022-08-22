cmake_minimum_required(VERSION 3.5)

project(ExternalSort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES main.cpp sortmanager.cpp iface/ioptions.cpp iface/isorting.cpp commandlinearg.cpp externalsort.cpp)
set(HEADERS sortmanager.h iface/ioptions.h iface/isorting.h commandlinearg.h externalsort.h)

add_executable(ExternalSort ${SOURCES} ${HEADERS})

install(TARGETS ExternalSort
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
