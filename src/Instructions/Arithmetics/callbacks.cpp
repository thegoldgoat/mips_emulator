#include "callbacks.hpp"
#include "../Decoder.hpp"
#include <assert.h>
#include <stdexcept>
#include <stdint.h>

#ifdef PRINT_DEBUG
#include <stdio.h>
#endif

void add(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("add\n");
#endif

  int32_t rs = vm.registers.read(instruction.rs);
  int32_t rt = vm.registers.read(instruction.rt);

  if (checkIntegerOverflow(rs, rt)) {
    // TODO: Handle exception
#ifdef PRINT_DEBUG
    fprintf(stderr, "[add]: got overflow adding %x and %x\n", rs, rt);
#endif
  }

  vm.registers.write(instruction.rd, rs + rt);
}

void addu(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("addu\n");
#endif

  vm.registers.write(instruction.rd, vm.registers.read(instruction.rs) +
                                         vm.registers.read(instruction.rt));
}

void sub(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("sub\n");
#endif

  int32_t rs = vm.registers.read(instruction.rs);
  int32_t rt = -vm.registers.read(instruction.rt);

  if (checkIntegerOverflow(rs, rt)) {
    // TODO: Handle exception
#ifdef PRINT_DEBUG
    fprintf(stderr, "[sub]: got overflow adding %x and %x\n", rs, rt);
#endif
  }

  vm.registers.write(instruction.rd, rs + rt);
}

void subu(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("subu\n");
#endif

  vm.registers.write(instruction.rd, vm.registers.read(instruction.rs) -
                                         vm.registers.read(instruction.rt));
}

void mult(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("mult\n");
#endif

  int32_t rs = vm.registers.read(instruction.rs);
  int32_t rt = vm.registers.read(instruction.rt);

  int64_t result = (int64_t)rs * rt;

  vm.registers.writeProduct(result);
}
void multu(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("multu\n");
#endif

  uint32_t rs = vm.registers.read(instruction.rs);
  uint32_t rt = vm.registers.read(instruction.rt);

  uint64_t result = (uint64_t)rs * rt;

  vm.registers.writeProduct(result);
}
void div(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("div\n");
#endif

  int32_t rs = vm.registers.read(instruction.rs);
  int32_t rt = vm.registers.read(instruction.rt);

  if (rt == 0) {
// TODO: Handle exception
#ifdef PRINT_DEBUG
    fprintf(stderr, "Dividing by zero!!\n");
#endif
    return;
  }

  vm.registers.writeDivision(rs / rt, rs % rt);
}
void divu(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("divu\n");
#endif

  uint32_t rs = vm.registers.read(instruction.rs);
  uint32_t rt = vm.registers.read(instruction.rt);

  if (rt == 0) {
// TODO: Handle exception
#ifdef PRINT_DEBUG
    fprintf(stderr, "Dividing by zero!!\n");
#endif
    return;
  }

  vm.registers.writeDivision(rs / rt, rs % rt);
}
void slt(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("slt\n");
#endif

  // Need to cast the values into signed integers
  int32_t first = (int32_t)vm.registers.read(instruction.rs);
  int32_t second = (int32_t)vm.registers.read(instruction.rt);

  vm.registers.write(instruction.rd, (first < second) ? 1 : 0);
}
void sltu(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("sltu\n");
#endif

  uint32_t first = vm.registers.read(instruction.rs);
  uint32_t second = vm.registers.read(instruction.rt);

  vm.registers.write(instruction.rd, (first < second) ? 1 : 0);
}
void andCallback(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("and\n");
#endif

  vm.registers.write(instruction.rd, vm.registers.read(instruction.rs) &
                                         vm.registers.read(instruction.rt));
}
void orCallback(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("or\n");
#endif

  vm.registers.write(instruction.rd, vm.registers.read(instruction.rs) |
                                         vm.registers.read(instruction.rt));
}
void norCallback(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("nor\n");
#endif

  vm.registers.write(
      instruction.rd,

      ~(vm.registers.read(instruction.rs) | vm.registers.read(instruction.rt)));
}
void xorCallback(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("xor\n");
#endif

  vm.registers.write(instruction.rd, vm.registers.read(instruction.rs) ^
                                         vm.registers.read(instruction.rt));
}
void jr(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("jr\n");
#endif

  vm.registers.jumpRegister(instruction.rs);
}
void jalr(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("jalr\n");
#endif

  vm.registers.write(instruction.rd, vm.registers.getPc() + 4);

  vm.registers.jumpRegister(instruction.rs);
}

void sll(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("sll\n");
#endif

  vm.registers.write(instruction.rd, vm.registers.read(instruction.rt)
                                         << instruction.getShiftAmount());

  vm.registers.incrementPC();
}

void srl(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("srl\n");
#endif

  vm.registers.write(instruction.rd, vm.registers.read(instruction.rt) >>
                                         instruction.getShiftAmount());

  vm.registers.incrementPC();
}

void mfhi(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("mfhi\n");
#endif

  vm.registers.write(instruction.rd, vm.registers.getHi());

  vm.registers.incrementPC();
}

void mflo(R_Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("mflo\n");
#endif

  vm.registers.write(instruction.rd, vm.registers.getLo());

  vm.registers.incrementPC();
}

#define SYSCALL_NUMBER_REGISTER 2

void syscall(R_Instruction_t, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("syscall\n");
#endif

  uint32_t syscallNumber = vm.registers.read(SYSCALL_NUMBER_REGISTER);

  switch (syscallNumber) {
  case 10:
    vm.stopExecution();
    break;
  default:
    throw std::runtime_error("Unimplemented syscall number: " +
                             std::to_string(syscallNumber));
  }

  vm.registers.incrementPC();
}
