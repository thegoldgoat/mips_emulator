#include "J_Instruction.hpp"
#include "Instruction.hpp"
#include <stdint.h>

J_Instuction_t::J_Instuction_t(uint32_t instruction) : Instruction_t(instruction) {
  immediate = instruction & 0x3fffffff;
}
