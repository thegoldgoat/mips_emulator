#include "R_Instruction.h"

R_Instruction_t::R_Instruction_t(u_int32_t instruction)
    : Instruction_t(instruction) {

  rs = instruction & 0x3e00000;
  rs = rs >> 21;

  rt = instruction & 0x1f0000;
  rt = rt >> 16;

  rd = instruction & 0xf800;
  rd = rd >> 11;

  funct_code = instruction & 0x3f;
}