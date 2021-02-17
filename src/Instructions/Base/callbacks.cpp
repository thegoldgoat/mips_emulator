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
  
  arithmeticInstruction(instruction, vm);
}
// ADD immediate
void addi(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// ADD immediate unsignet
void addiu(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// Set less than immediate unsigned
void slti(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// And immediate
void sltiu(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// And immediate
void andi(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// Or immediate
void ori(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// XOR immediate
void xori(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// Load Word
void lw(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// Save word
void sw(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// Load undigned byte
void lbu(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// Load byte
void lb(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// Store Byte
void sb(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// Load upper immediate
void lui(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// Branch on equal
void beq(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// Branch on not equal
void bne(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// Branch on less than or equal zero
void blez(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// Branch on greater than zero
void bgtz(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// Branch on less than zero
void bltz(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// Jump
void jump(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
// Jump and Link
void jal(Instruction_t instruction, VirtualMachine &vm) { printf("Test\n"); }
