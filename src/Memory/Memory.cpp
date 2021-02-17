#include "Memory.h"

#include <assert.h>
#include <sys/mman.h>

Memory_t::Memory_t(u_int32_t sizeInByte) {
  memory = (char *)mmap(nullptr, sizeInByte, PROT_READ | PROT_WRITE,
                        MAP_ANON | MAP_PRIVATE, -1, 0);
  assert(memory);

  size = sizeInByte;
}

Memory_t::~Memory_t() { munmap(memory, size); }

unsigned char Memory_t::readByte(u_int32_t offsetInByte) {

#ifdef MEMORY_PROTECTION
  assert(offsetInByte < size);
#endif
  return *(memory + offsetInByte);
}

void Memory_t::writeByte(u_int32_t offsetInByte, unsigned char byte) {
#ifdef MEMORY_PROTECTION
  assert(offsetInByte < size);
#endif
  *(memory + offsetInByte) = byte;
}

u_int32_t Memory_t::readWord(u_int32_t offsetInByte) {

#ifdef MEMORY_PROTECTION
  assert(offsetInByte < size);
#endif
  return *((u_int32_t *)(memory + offsetInByte));
}

void Memory_t::writeWord(u_int32_t offsetInByte, u_int32_t word) {

#ifdef MEMORY_PROTECTION
  assert(offsetInByte < size);
  assert((offsetInByte % 4) == 0);
#endif

  *((u_int32_t *)(memory + offsetInByte)) = word;
}