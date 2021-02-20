cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

add_executable(mips_emulator_test test.cpp)

add_library(Test_Arithmetics STATIC Instructions/Arithmetic.cpp)

# Test libraries
target_link_libraries(mips_emulator_test
  Test_Arithmetics
)

# internal libraries
target_link_libraries(mips_emulator_test
  Decoder
  BaseInstructions
  ArithmeticsInstructions
  Instruction
  R_Instruction
  I_Instruction
  Memory
  Registers
)

target_compile_features(mips_emulator_test PUBLIC cxx_std_17)
