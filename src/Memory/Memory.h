#pragma once

#include <stdint.h>

class Memory_t {
public:
  uint32_t size;

  Memory_t(u_int32_t);
  ~Memory_t();

  u_int32_t readWord(u_int32_t offsetInByte);
  void writeWord(u_int32_t offsetInByte, u_int32_t word);

  unsigned char readByte(u_int32_t offsetInByte);
  void writeByte(u_int32_t offsetInByte, unsigned char byte);

private:
  char *memory = nullptr;
};
