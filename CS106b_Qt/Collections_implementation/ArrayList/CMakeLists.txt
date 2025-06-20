cmake_minimum_required(VERSION 3.16)

project(ArrayList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ArrayList main.cpp
    arraylist.h arraylist.cpp)

include(GNUInstallDirs)
install(TARGETS ArrayList
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
