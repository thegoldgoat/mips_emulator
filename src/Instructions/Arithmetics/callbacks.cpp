#include "callbacks.h"

#ifdef PRINT_DEBUG
#include <stdio.h>
#endif

void add(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("nop\n");
#endif
}

void addu(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}

void sub(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}
void subu(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}
void mult(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}
void multu(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}
void div(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}
void divu(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}
void slt(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}
void sltu(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}
void andCallback(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}
void orCallback(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}
void norCallback(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}
void xorCallback(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}
void jr(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}
void jalr(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}

void nop(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("nop\n");
#endif
}

void mfhi(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}

void mflo(R_Instruction_t, VirtualMachine &) {
#ifdef PRINT_DEBUG
  printf("test\n");
#endif
}
