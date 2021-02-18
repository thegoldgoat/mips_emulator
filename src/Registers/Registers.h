#pragma once
#include <stdint.h>

#define REGISTER_FILE_SIZE 32

class Registers_t {
public:
  void write(u_int8_t offset, u_int32_t value);
  u_int32_t read(u_int8_t offset);

  void incrementPC();
  void jumpPC(u_int32_t instruction);
  void branchJump(int16_t jumpOffset);
  void writeProduct(u_int64_t result);

private:
  u_int32_t registerFile[REGISTER_FILE_SIZE] = {0};

  u_int32_t programCounter = 0x0;

  // Multiplication/Divisions results
  u_int32_t hi;
  u_int32_t lo;
};