#pragma once
#include "../../VirtualMachine/VirtualMachine.hpp"
#include "../Types/Instruction.hpp"

// Arithmetic and logic operations
void arithmetic(Instruction_t, VirtualMachine &);
// ADD immediate
void addi(Instruction_t, VirtualMachine &);
// ADD immediate unsignet
void addiu(Instruction_t, VirtualMachine &);
// Set less than immediate unsigned
void slti(Instruction_t, VirtualMachine &);
// And immediate
void sltiu(Instruction_t, VirtualMachine &);
// And immediate
void andi(Instruction_t, VirtualMachine &);
// Or immediate
void ori(Instruction_t, VirtualMachine &);
// XOR immediate
void xori(Instruction_t, VirtualMachine &);
// Load Word
void lw(Instruction_t, VirtualMachine &);
// Save word
void sw(Instruction_t, VirtualMachine &);
// Load undigned byte
void lbu(Instruction_t, VirtualMachine &);
// Load byte
void lb(Instruction_t, VirtualMachine &);
// Store Byte
void sb(Instruction_t, VirtualMachine &);
// Load upper immediate
void lui(Instruction_t, VirtualMachine &);
// Branch on equal
void beq(Instruction_t, VirtualMachine &);
// Branch on not equal
void bne(Instruction_t, VirtualMachine &);
// Branch on less than or equal zero
void blez(Instruction_t, VirtualMachine &);
// Branch on greater than zero
void bgtz(Instruction_t, VirtualMachine &);
// Branch on less than zero
void bltz(Instruction_t, VirtualMachine &);
// Jump
void jump(Instruction_t, VirtualMachine &);
// Jump and Link
void jal(Instruction_t, VirtualMachine &);
