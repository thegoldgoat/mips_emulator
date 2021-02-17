#pragma once

#include <stdint.h>

class Memory_t {
public:
  uint32_t size;

  Memory_t(u_int32_t);

  ~Memory_t();

private:
  uint32_t *memory = nullptr;
};
