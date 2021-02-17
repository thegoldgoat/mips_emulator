#pragma once

#include "../Istructions/callbacks.h"
#include "../VirtualMachine/VirtualMachine.h"

void (*getInstructionCallback(Instruction_t))(Instruction_t, VirtualMachine &);