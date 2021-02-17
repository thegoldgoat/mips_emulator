#pragma once
#include "Instruction.h"

class R_Instruction_t : public Instruction_t {
public:
  R_Instruction_t(u_int32_t);

  u_int8_t rs;
  u_int8_t rt;
  u_int8_t rd;

  u_int8_t funct_code;
};