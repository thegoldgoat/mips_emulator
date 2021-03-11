#include "VirtualMachine.hpp"
#include "../Instructions/Decoder.hpp"
#include "../Instructions/Types/Instruction.hpp"

#include <assert.h>
#include <fstream>
#include <iostream>
#include <sstream>

#define TEXT_SEGMENT_START 0x00400000
#define DATA_SEGMENT_START 0x10000000

void VirtualMachine::loadExecutable(std::string path) {
  std::ifstream inputFile(path);

  if (!inputFile.is_open()) {
    perror("Couldn't open input file\n");
    throw std::runtime_error("");
  }

  ExeHeader header;
  uint32_t intBuffer;

  inputFile.read((char *)&header, sizeof(header));

  entryPointAddress = header.entryPointOffset + TEXT_SEGMENT_START;

  // Create VMA
  memory.allocateVMAs(
      TEXT_SEGMENT_START, header.textSegmentSize * sizeof(uint32_t),
      DATA_SEGMENT_START, header.dataSegmentSize * sizeof(uint32_t));

  char *segmentBasePointer = memory.getTextSegmentPointer();

  // Load text segment into memory
  for (uint32_t i = 0; i < header.textSegmentSize; i++) {
    inputFile.read((char *)&intBuffer, sizeof(intBuffer));
    *(segmentBasePointer) = intBuffer;
    segmentBasePointer += sizeof(uint32_t);
  }

  segmentBasePointer = memory.getDataSegmentPointer();

  // Load text segment into memory
  for (uint32_t i = 0; i < header.dataSegmentSize; i++) {
    inputFile.read((char *)&intBuffer, sizeof(intBuffer));
    *(segmentBasePointer) = intBuffer;
    segmentBasePointer += sizeof(uint32_t);
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
  fetchedInstruction = memory.readInstruction(registers.getPc());

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

  initRegisters();

  std::string inputBuffer;
  bool continueDebug = true;

  while (continueDebug) {
    std::cout << "> ";
    std::flush(std::cout);
    std::getline(std::cin, inputBuffer);

    std::stringstream lineBuffer(inputBuffer);
    lineBuffer >> inputBuffer;

    try {
      if (inputBuffer == "r") {
        initRegisters();
        debug_runUntilBreakpoint();
      } else if (inputBuffer == "e") {
        continueDebug = false;
      } else if (inputBuffer == "b") {
        lineBuffer >> inputBuffer;

        // TODO: check that std::stoi accepts 32 bit unsigned integer up to 2^32
        // -1
        debug_breakpoints.insert({(uint32_t)std::stoi(inputBuffer), true});
      } else if (inputBuffer == "sb") {
        for (auto &iterator : debug_breakpoints)
          printf("Breakpoint at %08x\n", iterator.first);
      } else if (inputBuffer == "rb") {
        if (!lineBuffer.good())
          throw std::runtime_error("Missing command parameter");

        lineBuffer >> inputBuffer;
        if (debug_breakpoints.erase((uint32_t)std::stoi(inputBuffer)) == 0)
          throw std::runtime_error("Breakpoint not found");
      } else if (inputBuffer == "c") {
        debug_runUntilBreakpoint();
      } else if (inputBuffer == "n") {
        runCPUCycle();
      } else if (inputBuffer == "pr") {

        if (lineBuffer.good()) {
          int32_t registerNumber;
          lineBuffer >> inputBuffer;

          registerNumber = std::stoi(inputBuffer, nullptr, 0);

          if (registerNumber < 0 || registerNumber > 31)
            throw std::runtime_error("Invalid register number");

          uint32_t regValue = registers.read(registerNumber);
          printf("hex = %08x; dec = %d\n", regValue, regValue);

        } else {
          for (int i = 0; i < REGISTER_FILE_SIZE; i++) {
            uint32_t regValue = registers.read(i);
            printf("[%02d]: hex = %08x; dec = %d\n", i, regValue, regValue);
          }
          printf("[PC]: %08x\n[HI]: %08x\n[LO]: %08x\n", registers.getPc(),
                 registers.getHi(), registers.getLo());
        }

      } else if (inputBuffer == "wr") {
        int32_t registerNumber;
        uint32_t registerValue;

        if (!lineBuffer.good())
          throw std::runtime_error("Missing command parameter");
        lineBuffer >> inputBuffer;
        registerNumber = std::stoi(inputBuffer, nullptr, 0);

        if (registerNumber < 0 || registerNumber > 31)
          throw std::runtime_error("Invalid register number");

        if (!lineBuffer.good())
          throw std::runtime_error("Missing command parameter");
        lineBuffer >> inputBuffer;
        registerValue = std::stoi(inputBuffer, nullptr, 0);

        registers.write(registerNumber, registerValue);

      } else if (inputBuffer == "pm") {
        if (!lineBuffer.good())
          throw std::runtime_error("Missing command parameter");
        uint32_t memoryAddress;
        lineBuffer >> inputBuffer;

        memoryAddress = std::stoi(inputBuffer, nullptr, 0);

        if (memoryAddress >= memory.size)
          throw std::runtime_error("Memory address out of range");

        printf("hex = %08x\n", memory.readWord(memoryAddress));
      } else if (inputBuffer == "wm") {
        if (!lineBuffer.good())
          throw std::runtime_error("Missing command parameter");
        uint32_t memoryAddress;
        lineBuffer >> inputBuffer;

        memoryAddress = std::stoi(inputBuffer, nullptr, 0);

        if (memoryAddress >= memory.size)
          throw std::runtime_error("Memory address out of range");

        if (!lineBuffer.good())
          throw std::runtime_error("Missing command parameter");
        uint32_t newValue;
        lineBuffer >> inputBuffer;

        newValue = std::stoi(inputBuffer, nullptr, 0);

        memory.writeWord(memoryAddress, newValue);
      } else if (inputBuffer == "vma") {
        memory.printDebugInfo();
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
      runCPUCycle();
    } else
      break;
  } while (continueExecution);
}
