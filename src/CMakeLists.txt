cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

add_executable(mips_emulator main.cpp)

add_library(Decoder STATIC Decoder/Decoder.cpp)
add_library(Istructions STATIC Istructions/callbacks.cpp)

# internal libraries
target_link_libraries(mips_emulator
  Decoder
  Istructions
)

target_compile_features(mips_emulator PUBLIC cxx_std_17)
