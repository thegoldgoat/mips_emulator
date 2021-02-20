#include "callbacks.h"
#include <stdint.h>
#ifdef PRINT_DEBUG
#include <stdio.h>
#endif

#include "../Decoder.h"
#include <assert.h>

#include "../Types/I_Instruction.h"

// Arithmetic and logic operations
void arithmetic(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- arithmetic instruction\n");
#endif

  R_Instruction_t r_instruction = R_Instruction_t(instruction.instruction);

  auto arithmeticInstruction = getArithmeticInstructionCallback(r_instruction);

  // TODO: Launch exception (?)
  assert(arithmeticInstruction);

  arithmeticInstruction(r_instruction, vm);

  if (shouldIncrementPc(r_instruction))
    vm.registers.incrementPC();
}

// ADD immediate
void addi(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- addi\n");
#endif

  I_Instuction_t i_instruction = I_Instuction_t(instruction.instruction);

  int32_t rs = vm.registers.read(i_instruction.rs);

  if (checkIntegerOverflow(rs, i_instruction.immediate)) {
    // TODO: Handle exception
#ifdef PRINT_DEBUG
    fprintf(stderr, "[add]: got overflow adding %x and %x\n", rs,
            i_instruction.immediate);
#endif
  }

  vm.registers.write(i_instruction.rt, rs + i_instruction.immediate);
  vm.registers.incrementPC();
}

// ADD immediate unsigned
void addiu(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- addiu\n");
#endif

  I_Instuction_t i_instruction = I_Instuction_t(instruction.instruction);

  vm.registers.write(i_instruction.rt, vm.registers.read(i_instruction.rs) +
                                           i_instruction.immediate);
  vm.registers.incrementPC();
}

// Set less than immediate
void slti(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- slti\n");
#endif
  I_Instuction_t i_instruction = I_Instuction_t(instruction.instruction);

  vm.registers.write(i_instruction.rt,
                     (int32_t)vm.registers.read(i_instruction.rs) <
                             i_instruction.immediate
                         ? 1
                         : 0);

  vm.registers.incrementPC();
}

// Set less than immediate unsigned
void sltiu(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- sltiu\n");
#endif

  I_Instuction_t i_instruction = I_Instuction_t(instruction.instruction);

  vm.registers.write(i_instruction.rt, vm.registers.read(i_instruction.rs) <
                                               (uint32_t)i_instruction.immediate
                                           ? 1
                                           : 0);

  vm.registers.incrementPC();
}

// And immediate
void andi(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- andi\n");
#endif
  I_Instuction_t i_instruction = I_Instuction_t(instruction.instruction);

  vm.registers.write(i_instruction.rt, vm.registers.read(i_instruction.rs) &
                                           (uint32_t)i_instruction.immediate);

  vm.registers.incrementPC();
}

// Or immediate
void ori(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- ori\n");
#endif
  I_Instuction_t i_instruction = I_Instuction_t(instruction.instruction);

  vm.registers.write(i_instruction.rt, vm.registers.read(i_instruction.rs) |
                                           (uint32_t)i_instruction.immediate);

  vm.registers.incrementPC();
}

// XOR immediate
void xori(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- xori\n");
#endif
  I_Instuction_t i_instruction = I_Instuction_t(instruction.instruction);

  vm.registers.write(i_instruction.rt, vm.registers.read(i_instruction.rs) ^
                                           (uint32_t)i_instruction.immediate);

  vm.registers.incrementPC();
}

// Load Word
void lw(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- Test\n");
#endif

  vm.registers.incrementPC();
}

// Save word
void sw(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- Test\n");
#endif

  vm.registers.incrementPC();
}

// Load undigned byte
void lbu(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- Test\n");
#endif

  vm.registers.incrementPC();
}

// Load byte
void lb(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- Test\n");
#endif

  vm.registers.incrementPC();
}

// Store Byte
void sb(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- Test\n");
#endif

  vm.registers.incrementPC();
}

// Load upper immediate
void lui(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- Test\n");
#endif

  vm.registers.incrementPC();
}

// Branch on equal
void beq(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- Test\n");
#endif
}

// Branch on not equal
void bne(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- Test\n");
#endif
}

// Branch on less than or equal zero
void blez(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- Test\n");
#endif
}

// Branch on greater than zero
void bgtz(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- Test\n");
#endif
}

// Branch on less than zero
void bltz(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- Test\n");
#endif
}

// Jump
void jump(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- Test\n");
#endif
}

// Jump and Link
void jal(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("- Test\n");
#endif
}
