#pragma once

#include "Arithmetics/callbacks.hpp"
#include "Base/callbacks.hpp"

#include "Types/Instruction.hpp"
#include "Types/R_Instruction.hpp"

#include "../VirtualMachine/VirtualMachine.hpp"

void (*getInstructionCallback(Instruction_t))(Instruction_t, VirtualMachine &);

void (*getArithmeticInstructionCallback(R_Instruction_t instruction))(
    R_Instruction_t, VirtualMachine &);

bool shouldIncrementPc(R_Instruction_t instruction);

bool checkIntegerOverflow(int32_t op1, int32_t op2);