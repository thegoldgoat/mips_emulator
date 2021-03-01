#include "Instructions/Arithmetic.hpp"
#include "Instructions/Jump.hpp"
#include "Instructions/Memory.hpp"

int main() {
  VirtualMachine vm = VirtualMachine(2 * 1024 * 1024 * 1024);

  testAdd(vm);
  testSub(vm);
  testMult(vm);
  testDiv(vm);
  testLui(vm);
  testLw(vm);
  testSw(vm);
  testBeq(vm);
  testBne(vm);
}