#pragma once
#include "../../Instructions/Types/R_Instruction.h"
#include "../../VirtualMachine/VirtualMachine.h"

void add(R_Instruction_t, VirtualMachine &);
void addu(R_Instruction_t, VirtualMachine &);
void sub(R_Instruction_t, VirtualMachine &);
void subu(R_Instruction_t, VirtualMachine &);
void mult(R_Instruction_t, VirtualMachine &);
void multu(R_Instruction_t, VirtualMachine &);
void div(R_Instruction_t, VirtualMachine &);
void divu(R_Instruction_t, VirtualMachine &);
void slt(R_Instruction_t, VirtualMachine &);
void sltu(R_Instruction_t, VirtualMachine &);
void andCallback(R_Instruction_t, VirtualMachine &);
void orCallback(R_Instruction_t, VirtualMachine &);
void norCallback(R_Instruction_t, VirtualMachine &);
void xorCallback(R_Instruction_t, VirtualMachine &);
void jr(R_Instruction_t, VirtualMachine &);
void jalr(R_Instruction_t, VirtualMachine &);
void nop(R_Instruction_t, VirtualMachine &);
void mfhi(R_Instruction_t, VirtualMachine &);
void mflo(R_Instruction_t, VirtualMachine &);
