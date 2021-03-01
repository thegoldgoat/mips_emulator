#pragma once
#include <bits/stdint-uintn.h>
#include <stdint.h>

#define REGISTER_FILE_SIZE 32

class Registers_t {
public:
  void write(uint8_t offset, uint32_t value);
  uint32_t read(uint8_t offset);

  void incrementPC();
  void jumpPC(uint32_t instruction);
  void branchJump(int16_t jumpOffset);
  void jumpRegister(uint8_t regNumber);
  void writeProduct(uint64_t result);
  void writeDivision(uint32_t result, uint32_t remainder);

  uint32_t getHi();
  uint32_t getLo();
  uint32_t getPc();

private:
  uint32_t registerFile[REGISTER_FILE_SIZE] = {0};

  uint32_t programCounter = 0x0;

  // Multiplication/Divisions results
  uint32_t hi;
  uint32_t lo;
};