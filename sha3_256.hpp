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

//THETA θ (dificil)
void theta() {
    uint64_t C[5] = {0};
    uint64_t D[5] = {0};
    for (int x = 0; x < 5; ++x) {
	for(int y = 0; y < 5; ++y)
	{
		C[x] ^= state[x][y];
	}
    }
  for (int x = 0; x < 5; ++x) {
        int esquerda =  (x - 4) % 5;
        int direita  = (x + 1) % 5;
	
	D[x] = C[esquerda ^ rotl64(C[direita],1);
    
    }

      for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {
            state[x][y] ^= D[x];
        }
    }
}
};

