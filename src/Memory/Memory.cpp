#include "Memory.hpp"

#include <assert.h>
#include <stdexcept>
#include <sys/mman.h>

#ifdef PRINT_DEBUG
#include <stdio.h>
#endif

uint32_t Memory_t::readWord(uint32_t offsetInByte) {
  if (textSegment->containsAddress(offsetInByte)) {
    return textSegment->read(offsetInByte);
  } else if (dataSegment->containsAddress(offsetInByte)) {
    return dataSegment->read(offsetInByte);
  } else {
    throw std::runtime_error("Memory address is not contained within any VMA");
  }
}

void Memory_t::writeWord(uint32_t offsetInByte, uint32_t word) {
  if (textSegment->containsAddress(offsetInByte)) {
    textSegment->write(offsetInByte, word);
  } else if (dataSegment->containsAddress(offsetInByte)) {
    dataSegment->write(offsetInByte, word);
  } else {
    throw std::runtime_error("Memory address is not contained within any VMA");
  }
}

uint32_t Memory_t::readInstruction(uint32_t address) {
  if (textSegment->containsAddress(address)) {
    return textSegment->readExecute(address);
  } else if (dataSegment->containsAddress(address)) {
    return dataSegment->readExecute(address);
  } else {
    throw std::runtime_error("Memory address is not contained within any VMA");
  }
}

void Memory_t::allocateVMAs(uint32_t textBase, uint32_t textSize,
                            uint32_t dataBase, uint32_t dataSize) {
  textSegment.reset(new VMA(textBase, textSize, false, false, true));
  dataSegment.reset(new VMA(dataBase, dataSize, true, true, false));
}

void Memory_t::printDebugInfo() {
  printf(".text: start = %08x; end = %08x\n", textSegment->base,
         textSegment->base + textSegment->size);
  printf(".data: start = %08x; end = %08x\n", dataSegment->base,
         dataSegment->base + dataSegment->size);
}
