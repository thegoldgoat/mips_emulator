#pragma once

#include "Instruction.h"
#include <stdint.h>

class I_Instuction_t : public Instruction_t {
public:
  I_Instuction_t(uint32_t instruction);

  int32_t immediate;
  int8_t rs;
  int8_t rt;
};