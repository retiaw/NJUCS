cmake_minimum_required(VERSION 3.16)

project(LinkedList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LinkedList main.cpp
    linkedlist.h linkedlist.cpp)

include(GNUInstallDirs)
install(TARGETS LinkedList
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
