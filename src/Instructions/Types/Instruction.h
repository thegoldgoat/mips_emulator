#pragma once
#include <stdint.h>

class Instruction_t {

public:
  uint8_t opCode;

  Instruction_t(uint32_t);

  uint32_t instruction;
};
