#include "Instructions/Arithmetic.h"
#include "Instructions/Memory.h"

#include <assert.h>
#include <stdio.h>

int main() {
  VirtualMachine vm = VirtualMachine(2 * 1024 * 1024 * 1024);

  testAdd(vm);
  testSub(vm);
  testMult(vm);
  testDiv(vm);
  testLui(vm);
  testLw(vm);
  testSw(vm);
}