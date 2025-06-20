cmake_minimum_required(VERSION 3.16)

project(ArrayStack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ArrayStack main.cpp
    arraystack.h arraystack.cpp)

include(GNUInstallDirs)
install(TARGETS ArrayStack
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
