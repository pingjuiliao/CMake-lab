cmake_minimum_required(VERSION 3.5)

project(UseLib VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

option(USE_MYLIB "Use tutorial" ON)

configure_file(config.h.in config.h)


if(USE_MYLIB)
    add_subdirectory(MyLibrary)
    list(APPEND EXTRA_LIBS MyLib)
    # list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MyLib")
endif()

# add executable
add_executable(Main main.cxx)

target_link_libraries(Main
    PUBLIC ${EXTRA_LIBS})


target_include_directories(Main
    PUBLIC
    ${PROJECT_BINARY_DIR}
    #${EXTRA_INCLUDES}
)



# testing
enable_testing()

function(test_stdin program arg1 arg2 result)
    add_test(
        NAME test_${arg1}_against_${arg2}
        COMMAND ${program} ${arg1} ${arg2})
    set_tests_properties(
        test_${arg1}_against_${arg2}
        PROPERTIES PASS_REGULAR_EXPRESSION ${result}
        )
endfunction(test_stdin)

test_stdin(Main 4 5 "gcd is 1")
test_stdin(Main 16 4 "gcd is 4")
test_stdin(Main 231 88 "gcd is 11")
test_stdin(Main 1452 501 "gcd is 3")



