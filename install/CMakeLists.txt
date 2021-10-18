cmake_minimum_required(VERSION 3.5)

project(PutMath VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

option(USE_MYLIB "Use my library" ON)

configure_file(config.h.in config.h)

if(USE_MYLIB)
    add_subdirectory(MyLib)
    list(APPEND EXTRA_LIBS MyLib)
    # list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MyLib")
endif()


# add executable
add_executable(PrintMath printMath.cxx)
target_link_libraries(PrintMath
    PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path for include files
# so that we will find config.h
target_include_directories(PrintMath
    PUBLIC
    ${PROJECT_BINARY_DIR}
    #${EXTRA_INCLUDES}
)

# add the install targets
install(TARGETS PrintMath DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h"
   DESTINATION include)

