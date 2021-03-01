#include "R_Instruction.hpp"

R_Instruction_t::R_Instruction_t(uint32_t instruction)
    : Instruction_t(instruction) {

  uint32_t temp = instruction & 0x3e00000;

  temp >>= 21;
  rs = temp;

  temp = instruction & 0x1f0000;
  temp >>= 16;

  rt = temp;

  temp = instruction & 0xf800;
  temp >>= 11;

  rd = temp;

  funct_code = instruction & 0x3f;
}
