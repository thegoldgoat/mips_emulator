#include "Instructions/Arithmetic.h"

#include <assert.h>
#include <stdio.h>

int main() {
  VirtualMachine vm = VirtualMachine(2 * 1024 * 1024 * 1024);

  assert(testAdd(vm));

  assert(testSub(vm));
}