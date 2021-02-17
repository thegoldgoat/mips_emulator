#include "Decoder/Decoder.cpp"
#include "Memory/Memory.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char **argv) {

  Memory_t memory = Memory_t((u_int32_t)2 * 1024 * 1024 * 1024);

  auto instructionCallback = getInstructionCallback(0x0);

  assert(instructionCallback);

  instructionCallback(0x0, memory);
}
