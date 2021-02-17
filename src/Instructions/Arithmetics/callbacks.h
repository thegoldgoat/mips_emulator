#pragma once
#include "../../Instructions/Instruction.h"
#include "../../VirtualMachine/VirtualMachine.h"

void add(Instruction_t, VirtualMachine &);
void addu(Instruction_t, VirtualMachine &);
void sub(Instruction_t, VirtualMachine &);
void subu(Instruction_t, VirtualMachine &);
void mult(Instruction_t, VirtualMachine &);
void multu(Instruction_t, VirtualMachine &);
void div(Instruction_t, VirtualMachine &);
void divu(Instruction_t, VirtualMachine &);
void slt(Instruction_t, VirtualMachine &);
void sltu(Instruction_t, VirtualMachine &);
void andCallback(Instruction_t, VirtualMachine &);
void orCallback(Instruction_t, VirtualMachine &);
void norCallback(Instruction_t, VirtualMachine &);
void xorCallback(Instruction_t, VirtualMachine &);
void jr(Instruction_t, VirtualMachine &);
void jalr(Instruction_t, VirtualMachine &);
void nop(Instruction_t, VirtualMachine &);
void mfhi(Instruction_t, VirtualMachine &);
void mflo(Instruction_t, VirtualMachine &);
