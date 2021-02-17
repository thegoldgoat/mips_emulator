#include "Memory.h"

#include <sys/mman.h>
#include <assert.h>

u_int32_t *initMemory(u_int32_t sizeInByte)
{
    u_int32_t *memory = (u_int32_t*) mmap(nullptr, sizeInByte, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

    assert(memory);

    return memory;
}
