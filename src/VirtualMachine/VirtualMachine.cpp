#include "VirtualMachine.hpp"
#include "../Instructions/Decoder.hpp"
#include "../Instructions/Types/Instruction.hpp"

#include <assert.h>
#include <fstream>
#include <iostream>

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
#define STACK_POINTER 29
#define FRAME_POINTER 30

void VirtualMachine::initRegisters() {
  // Program Counter
  registers.jumpPC(entryPointAddress / 4);

  // Global pointer
  registers.write(GLOBAL_POINTER, 0x10008000);

  // Stack pointer & Frame pointer
  registers.write(STACK_POINTER, memory.size - 4);
  registers.write(FRAME_POINTER, memory.size - 4);
}

void VirtualMachine::stopExecution() { continueExecution = false; }

void VirtualMachine::runCPUCycle() {
  uint32_t fetchedInstruction;

  // Fetch Instruction
  fetchedInstruction = memory.readWord(registers.getPc());

  // Decode
  Instruction_t decodedInstruction(fetchedInstruction);
  auto instructionCallback = getInstructionCallback(decodedInstruction);

  assert(instructionCallback);

  // Execute and write results
  instructionCallback(decodedInstruction, *this);
}

void VirtualMachine::runExecutable() {

  // Prepare registers:
  initRegisters();

  // Start loop:
  while (continueExecution) {
    runCPUCycle();
  }
}

void VirtualMachine::debugExecutable() {

  std::string inputBuffer;
  bool continueDebug = true;

  while (continueDebug) {
    std::cout << "> ";
    std::flush(std::cout);
    std::cin >> inputBuffer;

    try {
      if (inputBuffer == "r") {
        initRegisters();
        debug_runUntilBreakpoint();
      } else if (inputBuffer == "e") {
        continueDebug = false;
      } else if (inputBuffer == "b") {
        std::cin >> inputBuffer;

        // TODO: check that std::stoi accepts 32 bit unsigned integer up to 2^32
        // -1
        debug_breakpoints.insert({(uint32_t)std::stoi(inputBuffer), true});
      } else if (inputBuffer == "sb") {
        for (auto &iterator : debug_breakpoints)
          printf("Breakpoint at %08x\n", iterator.first);
      } else if (inputBuffer == "rb") {
        std::cin >> inputBuffer;
        if (debug_breakpoints.erase((uint32_t)std::stoi(inputBuffer)) == 0)
          throw std::runtime_error("Breakpoint not found");
      } else if (inputBuffer == "c") {
        debug_runUntilBreakpoint();
      } else if (inputBuffer == "n") {
        runCPUCycle();
      } else if (inputBuffer == "pr") {
        for (int i = 0; i < REGISTER_FILE_SIZE; i++) {
          uint32_t regValue = registers.read(i);
          printf("[%02d]: hex = %08x; dec = %d\n", i, regValue, regValue);
        }
      } else if (inputBuffer == "wr") {
        throw std::runtime_error("Instruction not implemented");
      } else if (inputBuffer == "pm") {
        throw std::runtime_error("Instruction not implemented");
      } else if (inputBuffer == "wm") {
        throw std::runtime_error("Instruction not implemented");
      } else {
        throw std::runtime_error("Invalid command");
      }
    } catch (std::runtime_error &error) {
      std::cout << error.what() << std::endl;
    } catch (std::invalid_argument &error) {
      std::cout << "Invalid number" << std::endl;
    }
  }
}

void VirtualMachine::debug_runUntilBreakpoint() {
  do {
    auto result = debug_breakpoints.find(registers.getPc());
    if (result == debug_breakpoints.end()) {
      this->runCPUCycle();
    } else
      break;
  } while (continueExecution);
}
