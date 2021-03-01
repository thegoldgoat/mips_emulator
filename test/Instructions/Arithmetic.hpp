#pragma once

#include "../../src/Instructions/Decoder.hpp"
#include "../../src/VirtualMachine/VirtualMachine.hpp"

void testAdd(VirtualMachine &vm);
void testSub(VirtualMachine &vm);
void testMult(VirtualMachine &vm);
void testDiv(VirtualMachine &vm);
void testLui(VirtualMachine &vm);