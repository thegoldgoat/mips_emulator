#include "Decoder/Decoder.cpp"
#include "Memory/Memory.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char **argv) {

  Memory_t memory = initMemory((u_int32_t)2 * 1024 * 1024 * 1024);

  printf("memory: %p\n", memory);

  auto instructionCallback = getInstructionCallback(0x0);

  assert(instructionCallback);

  instructionCallback(0x0, memory);
}
