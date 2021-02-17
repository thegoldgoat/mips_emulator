#pragma once

#include "../Istructions/callbacks.h"
#include "../Memory/Memory.h"

void (*getInstructionCallback(Instruction_t))(Instruction_t, Memory_t);