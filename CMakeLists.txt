cmake_minimum_required(VERSION 3.8)

#Project name: CNL - ConnectedNetworkLibrary
set(LibraryName CNL)
project(${LibraryName}, CXX)

#Languages used
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(cnl)
add_subdirectory(googletest)
add_subdirectory(test)
