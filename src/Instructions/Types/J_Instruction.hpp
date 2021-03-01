#pragma once

#include "Instruction.hpp"
#include <stdint.h>

class J_Instuction_t : public Instruction_t {
public:
  J_Instuction_t(uint32_t instruction);

  int32_t immediate;
};
