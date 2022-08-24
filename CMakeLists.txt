cmake_minimum_required(VERSION 3.5)

project(ExternalSort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES main.cpp
            sortmanager.cpp
            iface/ioptions.cpp
            iface/isorting.cpp
            iface/ilog.cpp
            commandlinearg.cpp
            externalsort.cpp
            sortfile.cpp
            partfile.cpp
            mergefile.cpp
        )
set(HEADERS sortmanager.h
            iface/ioptions.h
            iface/isorting.h
            iface/ilog.h
            commandlinearg.h
            externalsort.h
            sortfile.h
            partfile.h
            mergefile.h
        )

add_executable(ExternalSort ${SOURCES} ${HEADERS})

install(TARGETS ExternalSort
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
