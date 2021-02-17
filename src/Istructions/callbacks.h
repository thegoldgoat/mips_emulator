#pragma once
#include "../Memory/Memory.h"
#include <stdint.h>

typedef uint32_t Instruction_t;

// Arithmetic and logic operations
void arithmetic(Instruction_t, Memory_t);
// ADD immediate
void addi(Instruction_t, Memory_t);
// ADD immediate unsignet
void addiu(Instruction_t, Memory_t);
// Set less than immediate unsigned
void slti(Instruction_t, Memory_t);
// And immediate
void sltiu(Instruction_t, Memory_t);
// And immediate
void andi(Instruction_t, Memory_t);
// Or immediate
void ori(Instruction_t, Memory_t);
// XOR immediate
void xori(Instruction_t, Memory_t);
// Load Word
void lw(Instruction_t, Memory_t);
// Save word
void sw(Instruction_t, Memory_t);
// Load undigned byte
void lbu(Instruction_t, Memory_t);
// Load byte
void lb(Instruction_t, Memory_t);
// Store Byte
void sb(Instruction_t, Memory_t);
// Load upper immediate
void lui(Instruction_t, Memory_t);
// Branch on equal
void beq(Instruction_t, Memory_t);
// Branch on not equal
void bne(Instruction_t, Memory_t);
// Branch on less than or equal zero
void blez(Instruction_t, Memory_t);
// Branch on greater than zero
void bgtz(Instruction_t, Memory_t);
// Branch on less than zero
void bltz(Instruction_t, Memory_t);
// Jump
void jump(Instruction_t, Memory_t);
// Jump and Link
void jal(Instruction_t, Memory_t);
