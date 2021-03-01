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

void testMult(VirtualMachine &vm) {

  // $1 * $2
  uint32_t multCode = 0x220018;
  // $3 = $hi
  uint32_t mfhiCode = 0x1810;
  // $4 = $lo
  uint32_t mfloCode = 0x2012;

  auto multCallback = getInstructionCallback(multCode);
  assert(multCallback);

  auto mfhiCallback = getInstructionCallback(mfhiCode);
  assert(mfhiCallback);

  auto mfloCallback = getInstructionCallback(mfloCode);
  assert(mfloCallback);

  // * Standard multiplication
  vm.registers.write(1, 10);
  vm.registers.write(2, 20);

  multCallback(Instruction_t(multCode), vm);

  // Read hi and lo
  mfhiCallback(mfhiCode, vm);
  mfloCallback(mfloCode, vm);

  assert(vm.registers.read(3) == 0x0);
  assert(vm.registers.read(4) == 200);

  // * Only in hi multiplication
  vm.registers.write(1, 0x7fffffff);
  vm.registers.write(2, 2);

  multCallback(Instruction_t(multCode), vm);

  // Read hi and lo
  mfhiCallback(mfhiCode, vm);
  mfloCallback(mfloCode, vm);

  assert(vm.registers.read(3) == 0x0);
  assert(vm.registers.read(4) == 0xfffffffe);

  // * Negative multiplication
  vm.registers.write(1, 0x80000000);
  vm.registers.write(2, 4);

  multCallback(Instruction_t(multCode), vm);

  // Read hi and lo
  mfhiCallback(mfhiCode, vm);
  mfloCallback(mfloCode, vm);

  assert(vm.registers.read(3) == 0xfffffffe);
  assert(vm.registers.read(4) == 0x0);

  uint32_t multuCode = 0x220019;
  auto multuCallback = getInstructionCallback(multuCode);

  vm.registers.write(1, 0x80000000);
  vm.registers.write(2, 4);

  multuCallback(Instruction_t(multuCode), vm);

  // Read hi and lo
  mfhiCallback(mfhiCode, vm);
  mfloCallback(mfloCode, vm);

  assert(vm.registers.read(3) == 0x2);
  assert(vm.registers.read(4) == 0x0);
}

void testDiv(VirtualMachine &vm) {
  // $1 / $2
  auto divCode = 2228250;
  auto divInst = Instruction_t(divCode);

  auto divCallback = getInstructionCallback(divCode);

  vm.registers.write(1, 10);
  vm.registers.write(2, 2);

  divCallback(divInst, vm);

  assert(vm.registers.getLo() == 5);
  assert(vm.registers.getHi() == 0);

  vm.registers.write(1, 10);
  vm.registers.write(2, 3);

  divCallback(divInst, vm);

  assert(vm.registers.getLo() == 3);
  assert(vm.registers.getHi() == 1);

  vm.registers.write(1, 0xf0000000);
  vm.registers.write(2, 2);

  divCallback(divInst, vm);

  assert(vm.registers.getLo() == 0xf8000000);
  assert(vm.registers.getHi() == 0);
}

void testLui(VirtualMachine &vm) {
  auto luiCode = 0x3c01f0f0;
  auto luiInst = Instruction_t(luiCode);

  auto luiCallback = getInstructionCallback(luiCode);

  luiCallback(luiInst, vm);

  assert(vm.registers.read(1) == 0xf0f00000);
}