#include "callbacks.h"
#ifdef PRINT_DEBUG
#include <stdio.h>
#endif

#include "../Decoder.h"
#include <assert.h>

// Arithmetic and logic operations
void arithmetic(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("arithmetic instruction\n");
#endif

  auto arithmeticInstruction = getArithmeticInstructionCallback(instruction);

  // TODO: Launch exception (?)
  assert(arithmeticInstruction);

  arithmeticInstruction(R_Instruction_t(instruction.opCode), vm);
}

// ADD immediate
void addi(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// ADD immediate unsignet
void addiu(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// Set less than immediate unsigned
void slti(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// And immediate
void sltiu(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// And immediate
void andi(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// Or immediate
void ori(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// XOR immediate
void xori(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// Load Word
void lw(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// Save word
void sw(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// Load undigned byte
void lbu(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// Load byte
void lb(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// Store Byte
void sb(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// Load upper immediate
void lui(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// Branch on equal
void beq(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// Branch on not equal
void bne(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// Branch on less than or equal zero
void blez(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// Branch on greater than zero
void bgtz(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// Branch on less than zero
void bltz(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// Jump
void jump(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}

// Jump and Link
void jal(Instruction_t instruction, VirtualMachine &vm) {
#ifdef PRINT_DEBUG
  printf("Test\n");
#endif
}
