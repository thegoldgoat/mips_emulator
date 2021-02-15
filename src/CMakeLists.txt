cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

add_executable(mips_emulator main.cpp)

target_compile_features(mips_emulator PUBLIC cxx_std_17)
