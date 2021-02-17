#pragma once

#include "Arithmetics/callbacks.h"
#include "Base/callbacks.h"

#include "Instruction.h"

#include "../VirtualMachine/VirtualMachine.h"

void (*getInstructionCallback(Instruction_t))(Instruction_t, VirtualMachine &);

void (*getArithmeticInstructionCallback(Instruction_t instruction))(
    Instruction_t, VirtualMachine &);