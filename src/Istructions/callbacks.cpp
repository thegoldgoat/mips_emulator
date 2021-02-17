#include "callbacks.h"
#include <iostream>

// Arithmetic and logic operations
void arithmetic(Instruction_t) { std::cout << "arithmetic\n"; }
// ADD immediate
void addi(Instruction_t) { std::cout << "Test\n"; }
// ADD immediate unsignet
void addiu(Instruction_t) { std::cout << "Test\n"; }
// Set less than immediate unsigned
void slti(Instruction_t) { std::cout << "Test\n"; }
// And immediate
void sltiu(Instruction_t) { std::cout << "Test\n"; }
// And immediate
void andi(Instruction_t) { std::cout << "Test\n"; }
// Or immediate
void ori(Instruction_t) { std::cout << "Test\n"; }
// XOR immediate
void xori(Instruction_t) { std::cout << "Test\n"; }
// Load Word
void lw(Instruction_t) { std::cout << "Test\n"; }
// Save word
void sw(Instruction_t) { std::cout << "Test\n"; }
// Load undigned byte
void lbu(Instruction_t) { std::cout << "Test\n"; }
// Load byte
void lb(Instruction_t) { std::cout << "Test\n"; }
// Store Byte
void sb(Instruction_t) { std::cout << "Test\n"; }
// Load upper immediate
void lui(Instruction_t) { std::cout << "Test\n"; }
// Branch on equal
void beq(Instruction_t) { std::cout << "Test\n"; }
// Branch on not equal
void bne(Instruction_t) { std::cout << "Test\n"; }
// Branch on less than or equal zero
void blez(Instruction_t) { std::cout << "Test\n"; }
// Branch on greater than zero
void bgtz(Instruction_t) { std::cout << "Test\n"; }
// Branch on less than zero
void bltz(Instruction_t) { std::cout << "Test\n"; }
// Jump
void jump(Instruction_t) { std::cout << "Test\n"; }
// Jump and Link
void jal(Instruction_t) { std::cout << "Test\n"; }
