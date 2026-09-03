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
        int esquerda =  (x + 4) % 5;
        int direita  = (x + 1) % 5;
	
	D[x] = C[esquerda] ^ rotl64(C[direita],1);
    
    }

      for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {
            state[x][y] ^= D[x];
        }
    }
	
}
void rho()
    {
        unsigned int desloca[5][5] = {
        { 0, 36,  3, 41, 18},
        { 1, 44, 10, 45,  2},
        {62,  6, 43, 15, 61},
        {28, 55, 25, 21, 56},
        {27, 20, 39,  8, 14}
    };
        for(int x = 0; x < 5;x++)
        {
            for(int y = 0;y < 5;y++)
            {
                state[x][y] = rotl64(state[x][y],desloca[x][y]);
            }
        }
    
    }
void pi()
	{
	  int novoX,novoY;
    uint64_t temp[5][5] = {0};
    for(int x = 0;x<5;x++)
    {
        for(int y = 0;y<5;y++)
        {
            novoX = y;
            novoY = (2 * x + 3 * y) % 5;
            temp[novoX][novoY] = state[x][y];
        }
    }
    for(int x = 0;x<5;x++)
    {
        for(int y = 0;y < 5;y++)
        {
            state[x][y] = temp[x][y];
        }
    }
}
void chi()
{
	uint64_t B[5][5];
	for(int y = 0; y < 5;y++)
	  {
		  for(int x = 0;x < 5;x++)
		  {
			  int proximox1 = (x + 1) % 5;
			  int proximox2 = (x +2) % 5;

			  B[x][y] = state[x][y] xor((~ state[proximox1][y]) & state[proximox2][y]);
		  }
	  }
	for(int y = 0; y < 5;y++)
	  {
		  for(int x = 0;x < 5;x++)
		  {
			  state[x][y] = B[x][y];
		  }
	  }
}
void iota(int numeroRodada)
	{
		const uint64_t RC[24] = {
    0x0000000000000001ULL,
    0x0000000000008082ULL,
    0x800000000000808AULL,
    0x8000000080008000ULL,
    0x000000000000808BULL,
    0x0000000080000001ULL,
    0x8000000080008081ULL,
    0x8000000000008009ULL,
    0x000000000000008AULL,
    0x0000000000000088ULL,
    0x0000000080008009ULL,
    0x000000008000000AULL,
    0x000000008000808BULL,
    0x800000000000008BULL,
    0x8000000000008089ULL,
    0x8000000000008003ULL,
    0x8000000000008002ULL,
    0x8000000000000080ULL,
    0x000000000000800AULL,
    0x800000008000000AULL,
    0x8000000080008081ULL,
    0x8000000000008080ULL,
    0x0000000080000001ULL,
    0x8000000080008008ULL
};

		state[0][0] = state[0][0] ^ RC[numeroRodada];
	
	}


};

