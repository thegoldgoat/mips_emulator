#pragma once

#include <stdint.h>

class VMA {

public:
  VMA(uint32_t base, uint32_t size, bool canRead, bool canWrite,
      bool canExecute);
  ~VMA();

  bool containsAddress(uint32_t address);

  uint32_t read(uint32_t address);
  void write(uint32_t address, uint32_t value);
  uint32_t readExecute(uint32_t address);

  char *getBasePointer();

  // base address
  uint32_t base = 0;
  // Size of the area
  uint32_t size = 0;

private:
  // Base pointer
  char *basePointer = nullptr;

  bool canRead;
  bool canWrite;
  bool canExecute;

  // This value locks the access to basePointer, as it can only be read during
  // the loading phase
  bool pointerLocked = false;
};