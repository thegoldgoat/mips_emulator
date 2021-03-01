#pragma once

#include <stdint.h>

class Memory_t {
public:
  uint32_t size;

  Memory_t(uint32_t);
  ~Memory_t();

  uint32_t readWord(uint32_t offsetInByte);
  void writeWord(uint32_t offsetInByte, uint32_t word);

  unsigned char readByte(uint32_t offsetInByte);
  void writeByte(uint32_t offsetInByte, unsigned char byte);

private:
  char *memory = nullptr;
};
