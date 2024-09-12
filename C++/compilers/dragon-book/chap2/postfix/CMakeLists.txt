cmake_minimum_required(VERSION 3.1...3.29)

project(Kexpr VERSION 1.0 
               LANGUAGES CXX)

# main 

include_directories(src)

set(CXX_SRCS 
      src/lexer.hpp             src/lexer.cpp
)

add_executable(kexpr src/main.cpp ${CXX_SRCS})

target_compile_options(kexpr PRIVATE -g -std=c++20)

# unit tests

find_package(Catch2 3 REQUIRED)

set(TEST_SRCS 
   )

add_executable(tests ${TEST_SRCS} ${CXX_SRCS})

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

target_compile_options(tests PRIVATE -g -std=c++20)

#add_custom_command(TARGET tests POST_BUILD COMMAND tests)
