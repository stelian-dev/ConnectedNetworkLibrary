cmake_minimum_required(VERSION 3.8)

set(LibraryNameTests ${LibraryName}Tests)

set(Sources
    endpoint_tests.cpp)

add_executable(${LibraryNameTests} ${Sources})

target_link_libraries(${LibraryNameTests}
    gtest_main
    ${LibraryName}
)

add_test(
    NAME ${LibraryNameTests}
    COMMAND ${LibraryNameTests}
)