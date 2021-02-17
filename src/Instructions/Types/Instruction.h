#pragma once
#include <stdint.h>

class Instruction_t {

public:
  uint8_t opCode;

  Instruction_t(u_int32_t);

protected:
  u_int32_t instruction;
};
