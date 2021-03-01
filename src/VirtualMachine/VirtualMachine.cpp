#include "VirtualMachine.h"
#include "../Instructions/Decoder.h"
#include "../Instructions/Types/Instruction.h"

#include <assert.h>
#include <fstream>

#define TEXT_SEGMENT_START 0x00400000
#define DATA_SEGMENT_START 0x10000000

void VirtualMachine::loadExecutable(std::string path) {
  std::ifstream inputFile(path);

  if (!inputFile.is_open()) {
    perror("Couldn't open input file\n");
    throw std::runtime_error("");
  }

  ExeHeader header;
  uint32_t intBuffer, currentAddress;

  inputFile.read((char *)&header, sizeof(header));

  entryPointAddress = header.entryPointOffset + TEXT_SEGMENT_START;

  // Load text segment into memory
  currentAddress = TEXT_SEGMENT_START;
  for (uint32_t i = 0; i < header.textSegmentSize; i++) {
    inputFile.read((char *)&intBuffer, sizeof(intBuffer));
    memory.writeWord(currentAddress, intBuffer);
    currentAddress += 4;
  }

  // Load text segment into memory
  currentAddress = DATA_SEGMENT_START;
  for (uint32_t i = 0; i < header.dataSegmentSize; i++) {
    inputFile.read((char *)&intBuffer, sizeof(intBuffer));
    memory.writeWord(currentAddress, intBuffer);
    currentAddress += 4;
  }
}

#define GLOBAL_POINTER 28

void VirtualMachine::runExecutable() {

  // Prepare registers:

  // Program Counter
  registers.jumpPC(entryPointAddress / 4);

  // Global pointer
  registers.write(GLOBAL_POINTER, 0x10008000);

  // TODO: Setup stack pointer and frame pointer

  // Start loop:
  uint32_t fetchedInstruction;
  while (true) {
    // Fetch Instruction
    fetchedInstruction = memory.readWord(registers.getPc());

    // Decode
    Instruction_t decodedInstruction(fetchedInstruction);
    auto instructionCallback = getInstructionCallback(decodedInstruction);

    assert(instructionCallback);

    // Execute and write results
    instructionCallback(decodedInstruction, *this);
  }
}
