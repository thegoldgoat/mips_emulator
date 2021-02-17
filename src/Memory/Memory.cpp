#include "Memory.h"

#include <assert.h>
#include <sys/mman.h>

Memory_t::Memory_t(u_int32_t sizeInByte) {
  memory = (u_int32_t *)mmap(nullptr, sizeInByte, PROT_READ | PROT_WRITE,
                             MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
  assert(memory);

  size = sizeInByte;
}

Memory_t::~Memory_t() { munmap(memory, size); }