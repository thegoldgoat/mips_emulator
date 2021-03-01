#include "Instructions/Decoder.hpp"
#include "VirtualMachine/VirtualMachine.hpp"
#include <assert.h>
#include <stdio.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    printf("Usage: %s <input_file>\n", argv[0]);
    return -1;
  }

  VirtualMachine vm = VirtualMachine((uint32_t)2 * 1024 * 1024 * 1024);

  vm.loadExecutable(argv[1]);

  vm.runExecutable();
}
