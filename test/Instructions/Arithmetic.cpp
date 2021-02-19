#include "Arithmetic.h"
#include <assert.h>
#include <stdio.h>

bool testAdd(VirtualMachine &vm) {

  // Simple add
  vm.registers.write(1, 100);
  vm.registers.write(2, 200);

  // $3 = $1 + $2
  uint32_t addCode = 0x221820;

  auto instructionCallback = getInstructionCallback(addCode);
  assert(instructionCallback);

  instructionCallback(addCode, vm);

  if (vm.registers.read(3) != 300)
    return false;

  // Overflow add for negatives
  vm.registers.write(1, -2147483648);
  vm.registers.write(2, -1);

  instructionCallback(addCode, vm);

  if (vm.registers.read(3) != 0x7fffffff)
    return false;

  // Overflow add for positives
  vm.registers.write(1, 2147483647);
  vm.registers.write(2, 1);

  instructionCallback(addCode, vm);

  if (vm.registers.read(3) != 0x80000000)
    return false;

  // Just a last one legal no-overflow add
  vm.registers.write(1, 2147483646);
  vm.registers.write(2, 1);

  instructionCallback(addCode, vm);

  if (vm.registers.read(3) != 0x7fffffff)
    return false;

  return true;
}

bool testSub(VirtualMachine &vm) {

  // Simple sub
  vm.registers.write(1, 200);
  vm.registers.write(2, 100);

  // $3 = $1 + $2
  uint32_t subCode = 0x221822;

  auto instructionCallback = getInstructionCallback(subCode);
  assert(instructionCallback);

  instructionCallback(subCode, vm);

  if (vm.registers.read(3) != 100)
    return false;

  // Overflow sub for negatives
  vm.registers.write(1, -2147483648);
  vm.registers.write(2, 1);

  instructionCallback(subCode, vm);

  if (vm.registers.read(3) != 0x7fffffff)
    return false;

  // Overflow sub for positives
  vm.registers.write(1, 2147483647);
  vm.registers.write(2, -1);

  instructionCallback(subCode, vm);

  if (vm.registers.read(3) != 0x80000000)
    return false;

  // Just a last one legal no-overflow sub
  vm.registers.write(1, 2147483646);
  vm.registers.write(2, -1);

  instructionCallback(subCode, vm);

  if (vm.registers.read(3) != 0x7fffffff)
    return false;

  return true;
}
