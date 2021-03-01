#include "VirtualMachine.h"

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