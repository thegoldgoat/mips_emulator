#include "callbacks.h"
#include <stdio.h>

void add(Instruction_t, VirtualMachine &) { printf("test\n"); }
void addu(Instruction_t, VirtualMachine &) { printf("test\n"); }
void sub(Instruction_t, VirtualMachine &) { printf("test\n"); }
void subu(Instruction_t, VirtualMachine &) { printf("test\n"); }
void mult(Instruction_t, VirtualMachine &) { printf("test\n"); }
void multu(Instruction_t, VirtualMachine &) { printf("test\n"); }
void div(Instruction_t, VirtualMachine &) { printf("test\n"); }
void divu(Instruction_t, VirtualMachine &) { printf("test\n"); }
void slt(Instruction_t, VirtualMachine &) { printf("test\n"); }
void sltu(Instruction_t, VirtualMachine &) { printf("test\n"); }
void andCallback(Instruction_t, VirtualMachine &) { printf("test\n"); }
void orCallback(Instruction_t, VirtualMachine &) { printf("test\n"); }
void norCallback(Instruction_t, VirtualMachine &) { printf("test\n"); }
void xorCallback(Instruction_t, VirtualMachine &) { printf("test\n"); }
void jr(Instruction_t, VirtualMachine &) { printf("test\n"); }
void jalr(Instruction_t, VirtualMachine &) { printf("test\n"); }
void nop(Instruction_t, VirtualMachine &) { printf("test\n"); }
void mfhi(Instruction_t, VirtualMachine &) { printf("test\n"); }
void mflo(Instruction_t, VirtualMachine &) { printf("test\n"); }