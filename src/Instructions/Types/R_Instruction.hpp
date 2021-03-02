#pragma once
#include "Instruction.hpp"

class R_Instruction_t : public Instruction_t {
public:
  R_Instruction_t(uint32_t);

  uint8_t rs;
  uint8_t rt;
  uint8_t rd;

  uint8_t funct_code;

  uint32_t getShiftAmount();
};