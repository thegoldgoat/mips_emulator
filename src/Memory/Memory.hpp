#pragma once

#include <stdint.h>

#include "VMA.hpp"

#include <memory>

class Memory_t {
public:
  uint32_t size;

  uint32_t readInstruction(uint32_t address);

  uint32_t readWord(uint32_t offsetInByte);
  void writeWord(uint32_t offsetInByte, uint32_t word);

  void allocateVMAs(uint32_t textBase, uint32_t textSize, uint32_t dataBase,
                    uint32_t dataSize);

  char *getTextSegmentPointer() { return textSegment->getBasePointer(); }
  char *getDataSegmentPointer() { return dataSegment->getBasePointer(); }

private:
  std::unique_ptr<VMA> textSegment;
  std::unique_ptr<VMA> dataSegment;
};