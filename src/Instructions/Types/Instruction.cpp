#include "Instruction.h"

Instruction_t::Instruction_t(u_int32_t instruction) : instruction(instruction) {
  opCode = instruction >> 26;
}