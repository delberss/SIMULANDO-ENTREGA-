cmake_minimum_required(VERSION 3.22)
project(trabalho-pratico-parte-1-dnp)
set(CMAKE_CXX_STANDARD 14)
include_directories(.)

add_executable(funcionamentoHash tests/teste1.cpp src/hash.cpp src/list.cpp src/no.cpp include/hash.h include/list.h include/no.h)
add_executable(test2 tests/teste2.cpp src/hash.cpp src/list.cpp src/no.cpp include/hash.h include/list.h include/no.h)