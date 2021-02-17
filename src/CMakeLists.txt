cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

add_executable(mips_emulator main.cpp)

add_library(Decoder STATIC Instructions/Decoder.cpp)
add_library(BaseInstructions STATIC Instructions/Base/callbacks.cpp)
add_library(ArithmeticsInstructions STATIC Instructions/Arithmetics/callbacks.cpp)

add_library(Memory STATIC Memory/Memory.cpp)
add_library(Registers STATIC Registers/Registers.cpp)

# internal libraries
target_link_libraries(mips_emulator
  Decoder
  BaseInstructions
  ArithmeticsInstructions
  Memory
  Registers
)

target_compile_features(mips_emulator PUBLIC cxx_std_17)
