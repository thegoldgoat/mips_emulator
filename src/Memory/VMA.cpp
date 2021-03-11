#include "VMA.hpp"

#include <assert.h>
#include <stdexcept>
#include <stdio.h>
#include <sys/mman.h>

VMA::VMA(uint32_t base, uint32_t size, std::string name, bool canRead,
         bool canWrite, bool canExecute)
    : base(base), size(size), name(name), canRead(canRead), canWrite(canWrite),
      canExecute(canExecute) {
  basePointer = (char *)mmap(nullptr, size, PROT_READ | PROT_WRITE,
                             MAP_ANON | MAP_PRIVATE, -1, 0);

  assert(basePointer);
}

VMA::~VMA() {
  printf("munmapping VMA: %s\n", name.c_str());
  munmap(basePointer, size);
}

bool VMA::containsAddress(uint32_t address) {
  return address >= base && address <= base + size;
}

uint32_t VMA::read(uint32_t address) {
  if (!canRead)
    throw std::runtime_error(
        "VMA access error: trying to read protected segment " +
        std::to_string(address));

  return *(uint32_t *)(basePointer + (address - base));
}

void VMA::write(uint32_t address, uint32_t value) {
  if (!canWrite)
    throw std::runtime_error(
        "VMA access error: trying to write a protected segment " +
        std::to_string(address));

  *(uint32_t *)(basePointer + (address - base)) = value;
}

uint32_t VMA::readExecute(uint32_t address) {
  if (!canExecute)
    throw std::runtime_error(
        "VMA access error: trying to execute a protected segment " +
        std::to_string(address));
  return *(uint32_t *)(basePointer + (address - base));
}

uint32_t VMA::debug_read(uint32_t address) {
  return *(uint32_t *)(basePointer + (address - base));
}

void VMA::debug_write(uint32_t address, uint32_t value) {
  *(uint32_t *)(basePointer + (address - base)) = value;
}

char *VMA::getBasePointer() {
  if (pointerLocked)
    throw std::runtime_error(
        "VMA: Trying to get a VMA pointer while it was already locked");

  pointerLocked = true;

  return basePointer;
}
