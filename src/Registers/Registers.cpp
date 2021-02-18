#include "Registers.h"

#include <assert.h>

void Registers_t::write(u_int8_t offset, u_int32_t value) {

#ifdef REGISTERS_PROTECTION
  assert(offset < REGISTER_FILE_SIZE);
  assert(offset != 0);
#endif

  if (offset == 0)
    return;

  registerFile[offset] = value;
}

u_int32_t Registers_t::read(u_int8_t offset) {

#ifdef REGISTERS_PROTECTION
  assert(offset < REGISTER_FILE_SIZE);
#endif

  return registerFile[offset];
}

void Registers_t::incrementPC() { programCounter += 4; }

void Registers_t::jumpPC(u_int32_t instruction) {
  // PC <-- [PC31..28] || [I25..0] || 00

  u_int32_t newValue = 0x0;

  // Remove op-code from instruction
  instruction &= 0x03ffffff;

  // Re-align bits
  instruction = instruction << 2;

  newValue |= instruction;

  // Remove all bits except 4 rightmost
  programCounter &= 0xf0000000;

  newValue |= programCounter;

  programCounter = newValue;
}

void Registers_t::branchJump(int16_t jumpOffset) {
  // PC <-- [PC] + 4 + ([I15]14 || [I15..0] || 02)
  programCounter += 4 + 4 * jumpOffset;
}
