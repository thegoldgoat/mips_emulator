#pragma once
#include "../Memory/Memory.hpp"
#include "../Registers/Registers.hpp"
#include <map>
#include <stdint.h>
#include <string>

struct ExeHeader {
  uint32_t textSegmentSize;
  uint32_t dataSegmentSize;
  uint32_t entryPointOffset;
};

class VirtualMachine {
public:
  Memory_t memory;
  Registers_t registers;

  void loadExecutable(std::string path);

  void runExecutable();
  void debugExecutable();

  void stopExecution();

private:
  bool continueExecution = true;

  uint32_t entryPointAddress;

  void initRegisters();
  void runCPUCycle();

  void debug_runUntilBreakpoint();

  std::map<uint32_t, bool> debug_breakpoints;
};