cmake_minimum_required(VERSION 3.23)
project(08-Messages)

include(FetchContent) # once in the project to include the module

FetchContent_Declare(libdio
        GIT_REPOSITORY https://github.com/HEIGVD-PRG1-F-2022/libdio.git
        GIT_TAG v0.2.5
        )
FetchContent_MakeAvailable(libdio)

set(CMAKE_CXX_STANDARD 20)

add_executable(messages main.cpp Email.cpp Toot.cpp Tweet.cpp Tools.cpp)

target_link_libraries(messages PRIVATE libdio)
