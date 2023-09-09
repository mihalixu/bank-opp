cmake_minimum_required(VERSION 3.18)
project(opp VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include(CTest)

set(CPP_SRCS  # all non-main, non-GUI source files
    account.cpp
    childaccount.cpp
    transferaccount.cpp
)

add_library(catch2 catch_amalgamated.cpp)
add_executable(account_test ${CPP_SRCS}  account_test.cpp)
target_link_libraries(account_test catch2)
add_test(NAME account_test COMMAND account_test)



