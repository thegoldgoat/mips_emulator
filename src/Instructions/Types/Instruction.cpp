#include "Instruction.hpp"

Instruction_t::Instruction_t(uint32_t instruction) : instruction(instruction) {
  opCode = instruction >> 26;
}