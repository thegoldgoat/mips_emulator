#include "Decoder/Decoder.cpp"
#include "VirtualMachine/VirtualMachine.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char **argv) {

  VirtualMachine vm = VirtualMachine((u_int32_t)2 * 1024 * 1024 * 1024);
  Registers_t registers = Registers_t();

  auto instructionCallback = getInstructionCallback(0x0);

  assert(instructionCallback);

  instructionCallback(0x0, vm);
}
