#include "Memory.h"

#include <assert.h>
#include <sys/mman.h>

#ifdef PRINT_DEBUG
#include <stdio.h>
#endif

Memory_t::Memory_t(uint32_t sizeInByte) {

#ifdef PRINT_DEBUG
  printf("memory mapping\n");
#endif

  memory = (char *)mmap(nullptr, sizeInByte, PROT_READ | PROT_WRITE,
                        MAP_ANON | MAP_PRIVATE, -1, 0);
  assert(memory);

  size = sizeInByte;
}

Memory_t::~Memory_t() {
#ifdef PRINT_DEBUG
  printf("memory unmapping\n");
#endif
  munmap(memory, size);
}

unsigned char Memory_t::readByte(uint32_t offsetInByte) {

#ifdef MEMORY_PROTECTION
  assert(offsetInByte < size);
#endif
  return *(memory + offsetInByte);
}

void Memory_t::writeByte(uint32_t offsetInByte, unsigned char byte) {
#ifdef MEMORY_PROTECTION
  assert(offsetInByte < size);
#endif
  *(memory + offsetInByte) = byte;
}

uint32_t Memory_t::readWord(uint32_t offsetInByte) {

#ifdef MEMORY_PROTECTION
  assert(offsetInByte < size);
#endif
  return *((uint32_t *)(memory + offsetInByte));
}

void Memory_t::writeWord(uint32_t offsetInByte, uint32_t word) {

#ifdef MEMORY_PROTECTION
  assert(offsetInByte < size);
  assert((offsetInByte % 4) == 0);
#endif

  *((uint32_t *)(memory + offsetInByte)) = word;
}
