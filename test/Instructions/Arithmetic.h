#pragma once

#include "../../src/Instructions/Decoder.h"
#include "../../src/VirtualMachine/VirtualMachine.h"

void testAdd(VirtualMachine &vm);
void testSub(VirtualMachine &vm);
void testMult(VirtualMachine &vm);
void testDiv(VirtualMachine &vm);
void testLui(VirtualMachine &vm);