cmake_minimum_required(VERSION 3.5)

project(ExternalSort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES main.cpp
            sortmanager.cpp
            commandlinearg.cpp
            externalsort.cpp
            iface/ioptions.cpp
            iface/isorting.cpp
            iface/ilog.cpp

            pfile/splitfile.cpp
            pfile/sortfile.cpp
            pfile/mergefile.cpp
            pfile/exceptfile.cpp
        )

set(HEADERS sortmanager.h
            commandlinearg.h
            externalsort.h
            iface/ioptions.h
            iface/isorting.h
            iface/ilog.h

            pfile/splitfile.h
            pfile/sortfile.h
            pfile/mergefile.h
            pfile/exceptfile.h
        )

add_executable(ExternalSort ${SOURCES} ${HEADERS})

install(TARGETS ExternalSort
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
