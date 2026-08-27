#include <cstdint>

struct Sha3_256{
  uint64_t state[5][5] = {0};
  uin64_t rorl64(uint64_t x, unsigned int n);
};
