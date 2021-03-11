#pragma once

#include <stdint.h>

#include "VMA.hpp"

#include <memory>
#include <string>
#include <vector>

class Memory_t {
public:
  Memory_t(bool allowDebug) : allowDebug(allowDebug) {}

  uint32_t readInstruction(uint32_t address);
  uint32_t readWord(uint32_t offsetInByte);
  void writeWord(uint32_t offsetInByte, uint32_t word);

  uint32_t debug_read(uint32_t address);
  void debug_write(uint32_t offsetInByte, uint32_t word);

  void allocateVMAs(std::shared_ptr<VMA> &newVMA);
  void printDebugInfo();

private:
  std::vector<std::shared_ptr<VMA>> vmaSegments;

  bool allowDebug;

  VMA *getVMAForAddress(uint32_t address);
};