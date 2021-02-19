#include "Arithmetic.h"
#include <assert.h>
#include <stdio.h>

void testAdd(VirtualMachine &vm) {

  // Simple add
  vm.registers.write(1, 100);
  vm.registers.write(2, 200);

  // $3 = $1 + $2
  uint32_t addCode = 0x221820;

  auto instructionCallback = getInstructionCallback(addCode);
  assert(instructionCallback);

  instructionCallback(addCode, vm);

  assert(vm.registers.read(3) == 300);

  // Overflow add for negatives
  vm.registers.write(1, -2147483648);
  vm.registers.write(2, -1);

  instructionCallback(addCode, vm);

  assert(vm.registers.read(3) == 0x7fffffff);

  // Overflow add for positives
  vm.registers.write(1, 2147483647);
  vm.registers.write(2, 1);

  instructionCallback(addCode, vm);

  assert(vm.registers.read(3) == 0x80000000);

  // Just a last one legal no-overflow add
  vm.registers.write(1, 2147483646);
  vm.registers.write(2, 1);

  instructionCallback(addCode, vm);

  assert(vm.registers.read(3) == 0x7fffffff);
}

void testSub(VirtualMachine &vm) {

  // Simple sub
  vm.registers.write(1, 200);
  vm.registers.write(2, 100);

  // $3 = $1 - $2
  uint32_t subCode = 0x221822;

  auto instructionCallback = getInstructionCallback(subCode);
  assert(instructionCallback);

  instructionCallback(subCode, vm);

  assert(vm.registers.read(3) == 100);

  // Overflow sub for negatives
  vm.registers.write(1, -2147483648);
  vm.registers.write(2, 1);

  instructionCallback(subCode, vm);

  assert(vm.registers.read(3) == 0x7fffffff);

  // Overflow sub for positives
  vm.registers.write(1, 2147483647);
  vm.registers.write(2, -1);

  instructionCallback(subCode, vm);

  assert(vm.registers.read(3) == 0x80000000);

  // Just a last one legal no-overflow sub
  vm.registers.write(1, 2147483646);
  vm.registers.write(2, -1);

  instructionCallback(subCode, vm);

  assert(vm.registers.read(3) == 0x7fffffff);
}

void testMult(VirtualMachine &vm) {}
