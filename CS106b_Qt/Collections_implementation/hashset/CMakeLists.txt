cmake_minimum_required(VERSION 3.16)

project(hashset LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hashset main.cpp
    hashset.h hashset.cpp)

include(GNUInstallDirs)
install(TARGETS hashset
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
