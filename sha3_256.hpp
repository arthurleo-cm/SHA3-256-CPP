#include <cstdint>

struct Sha3_256{
  uint64_t state[5][5] = {0};
  uint64_t rotl64(uint64_t x, unsigned int n)
{
    unsigned int entre = n & 63;
    
    if (entre == 0)
    {
        return x;
    }
  uint64_t parte_esq = x << entre;

  uint64_t parte_dir = x >> (64 - entre);


return parte_esq | parte_dir;
}

};

