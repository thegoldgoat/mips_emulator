#include "I_Instruction.h"
#include "Instruction.h"
#include <stdint.h>

I_Instuction_t::I_Instuction_t(uint32_t instruction)
    : Instruction_t(instruction) {

  uint32_t temp = instruction & 0x3e00000;

  temp >>= 21;
  rs = temp;

  temp = instruction & 0x1f0000;
  temp >>= 16;

  rt = temp;

  immediate = (int32_t)instruction & 0x0000ffff;
}
