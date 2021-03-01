#include "Memory.hpp"
#include <assert.h>
#include <stdint.h>

#define TEST_LW_FLAG 0x1234
#define TEST_LW_OFFSET 0x1c

void testLw(VirtualMachine &vm) {
  // Load into $1 the value of memory at TEST_LW_OFFSET + [$0]

  vm.memory.writeWord(TEST_LW_OFFSET, TEST_LW_FLAG);

  Instruction_t lwInstruction = Instruction_t(0x8C010016);

  auto lwCallback = getInstructionCallback(lwInstruction);

  assert(lwCallback);

  lwCallback(lwInstruction, vm);

  assert(vm.memory.readWord(TEST_LW_OFFSET) == TEST_LW_FLAG);
}

#define TEST_SW_FLAG 0x5678
#define TEST_SW_OFFSET 0x20

void testSw(VirtualMachine &vm) {
  // Store into TEST_SW_OFFSET TEST_SW_FLAG

  vm.registers.write(1, TEST_SW_FLAG);

  Instruction_t swInstruction = Instruction_t(0xAC010020);

  auto swCallback = getInstructionCallback(swInstruction);

  assert(swCallback);

  swCallback(swInstruction, vm);

  assert(vm.memory.readWord(TEST_SW_OFFSET) == TEST_SW_FLAG);
}