#include "Instructions/Decoder.hpp"
#include "VirtualMachine/VirtualMachine.hpp"
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define PRINT_USAGE

int main(int argc, char **argv) {

  if (argc < 2 || argc > 3 || (argc == 3 && strcmp(argv[2], "--debug") != 0)) {
    printf("Usage: %s <input_file> [--debug]\n", argv[0]);
    return -1;
  }

  VirtualMachine vm = VirtualMachine((uint32_t)2 * 1024 * 1024 * 1024);

  vm.loadExecutable(argv[1]);

  if (argc == 3)
    vm.debugExecutable();
  else
    vm.runExecutable();
}
