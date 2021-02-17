#pragma once
#include "../Memory/Memory.h"
#include "../Registers/Registers.h"
#include <stdint.h>

class VirtualMachine {
public:
  Memory_t memory;
  Registers_t registers;

  VirtualMachine(u_int32_t memorySize) : memory(Memory_t(memorySize)) {}
};