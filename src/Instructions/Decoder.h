#pragma once

#include "Arithmetics/callbacks.h"
#include "Base/callbacks.h"

#include "Types/Instruction.h"

#include "../VirtualMachine/VirtualMachine.h"

void (*getInstructionCallback(Instruction_t))(Instruction_t, VirtualMachine &);

void (*getArithmeticInstructionCallback(R_Instruction_t instruction))(
    R_Instruction_t, VirtualMachine &);