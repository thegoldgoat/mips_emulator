#include "Memory.hpp"

#include <assert.h>
#include <stdexcept>
#include <sys/mman.h>

#ifdef PRINT_DEBUG
#include <stdio.h>
#endif

uint32_t Memory_t::readWord(uint32_t offsetInByte) {
  return getVMAForAddress(offsetInByte)->read(offsetInByte);
}

void Memory_t::writeWord(uint32_t offsetInByte, uint32_t word) {
  getVMAForAddress(offsetInByte)->write(offsetInByte, word);
}

uint32_t Memory_t::readInstruction(uint32_t address) {
  return getVMAForAddress(address)->readExecute(address);
}

void Memory_t::allocateVMAs(std::shared_ptr<VMA> &newVMA) {
  vmaSegments.push_back(newVMA);
}

#define ASSERT_DEBUG_ALLOWED                                                   \
  if (!allowDebug)                                                             \
  throw std::runtime_error(                                                    \
      "Trying to print debug values while debug was disabled")

void Memory_t::printDebugInfo() {
  ASSERT_DEBUG_ALLOWED;

  for (auto &iterator : vmaSegments)
    printf("%s: start = %08x; end = %08x\n", iterator->name.c_str(),
           iterator->base, iterator->base + iterator->size);
}

uint32_t Memory_t::debug_read(uint32_t address) {
  ASSERT_DEBUG_ALLOWED;

  return getVMAForAddress(address)->debug_read(address);
}

void Memory_t::debug_write(uint32_t offsetInByte, uint32_t word) {
  ASSERT_DEBUG_ALLOWED;

  getVMAForAddress(offsetInByte)->debug_write(offsetInByte, word);
}

VMA *Memory_t::getVMAForAddress(uint32_t address) {
  for (auto &iterator : vmaSegments)
    if (iterator->containsAddress(address))
      return &(*iterator);

  throw std::runtime_error("Memory address is not contained within any VMA");
}