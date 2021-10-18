add_library(MyLib
    myswap.cxx
    mygcd.cxx)

target_include_directories(MyLib
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
# install rules

install(TARGETS MyLib DESTINATION lib)
install(FILES mylib.h DESTINATION include)
