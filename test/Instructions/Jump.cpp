#include "Jump.hpp"

#include <assert.h>

void testBeq(VirtualMachine &vm) {

  uint32_t programCounterBefore = vm.registers.getPc();

  // if $1 == $2 branch 4
  auto beqCode = 0x10220004;
  auto beqInst = Instruction_t(beqCode);

  auto beqCallback = getInstructionCallback(beqCode);

  vm.registers.write(1, 0xabcd);
  vm.registers.write(2, 0xabcd);
  beqCallback(beqInst, vm);

  assert(vm.registers.getPc() == programCounterBefore + 5 * 4);

  programCounterBefore = vm.registers.getPc();
  vm.registers.write(1, 0xabcd);
  vm.registers.write(2, 0xabce);
  beqCallback(beqInst, vm);

  assert(vm.registers.getPc() == programCounterBefore + 4);
}

void testBne(VirtualMachine &vm) {

  uint32_t programCounterBefore = vm.registers.getPc();

  // if $1 != $2 branch 4
  auto beqCode = 0x14220004;
  auto beqInst = Instruction_t(beqCode);

  auto beqCallback = getInstructionCallback(beqCode);

  vm.registers.write(1, 0xabcd);
  vm.registers.write(2, 0xabcd);
  beqCallback(beqInst, vm);

  assert(vm.registers.getPc() == programCounterBefore + 4);

  programCounterBefore = vm.registers.getPc();
  vm.registers.write(1, 0xabcd);
  vm.registers.write(2, 0xabce);
  beqCallback(beqInst, vm);

  assert(vm.registers.getPc() == programCounterBefore + 5 * 4);
}