#include "Decoder/Decoder.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char **argv) {

  auto instructionCallback = getInstructionCallback(0x0);

  assert(instructionCallback);

  instructionCallback(0x0);
}