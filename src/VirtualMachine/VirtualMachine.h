#pragma once
#include "../Memory/Memory.h"
#include "../Registers/Registers.h"
#include <stdint.h>
#include <string>

struct ExeHeader {
  uint32_t textSegmentSize;
  uint32_t dataSegmentSize;
  uint32_t entryPointOffset;
};

class VirtualMachine {
public:
  Memory_t memory;
  Registers_t registers;

  VirtualMachine(uint32_t memorySize) : memory(Memory_t(memorySize)) {}

  void loadExecutable(std::string path);

  void runExecutable();

private:
  uint32_t entryPointAddress;
};