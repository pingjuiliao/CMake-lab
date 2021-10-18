add_library(MyLib
    myswap.cxx
    mygcd.cxx)

target_include_directories(MyLib
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


include(CheckSymbolExists)
# include(CheckCXXSymbolExists) # c++ use this
check_symbol_exists(puts "stdio.h" HAVE_PUTS)
if(NOT HAVE_PUTS)
    unset(HAVE_PUTS CACHE)
    set(CMAKE_REQUIRED_LIBRARIES "m")
    check_symbol_exists(puts "stdio.h" HAVE_PUTS)
    if ( HAVE_PUTS )
        target_link_libraries(MyLib PRIVATE m)
    endif()
endif()

# add compile definitions
if (HAVE_PUTS)
    target_compile_definitions(MyLib
                                PRIVATE "HAVE_PUTS")
endif()

