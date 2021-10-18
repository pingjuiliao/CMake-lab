cmake_minimum_required(VERSION 3.5)

project(myHello)
configure_file(hello.h.in hello.h)

add_executable(Hello
    hello.cpp)

target_include_directories(Hello PUBLIC
    "${PROJECT_BINARY_DIR}"
    )
