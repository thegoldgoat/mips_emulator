#include "Instructions/Decoder.h"
#include "VirtualMachine/VirtualMachine.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char **argv) {

  VirtualMachine vm = VirtualMachine((uint32_t)2 * 1024 * 1024 * 1024);

  // Add these 2 registers in register 3
  auto instructionCallback = getInstructionCallback(0x221820);

  assert(instructionCallback);

  instructionCallback(0x221820, vm);
}
