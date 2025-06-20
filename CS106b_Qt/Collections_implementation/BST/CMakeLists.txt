cmake_minimum_required(VERSION 3.16)

project(BST LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BST main.cpp
    bst.h bst.cpp)

include(GNUInstallDirs)
install(TARGETS BST
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
