#include "sha3_256.hpp"
#include <cstdio>

void print_state(const Sha3_256& h) {
    for (int x = 0; x < 5; ++x)
        for (int y = 0; y < 5; ++y)
            printf("state[%d][%d] = %016lx\n", x, y, (unsigned long)h.state[x][y]);
}

int main()
{
    Sha3_256 hasher;

    // valores conhecidos, só para poder ver o efeito de cada etapa
  //  uint64_t v = 1;
  //  for (int x = 0; x < 5; ++x)
   //     for (int y = 0; y < 5; ++y) {
      //      hasher.state[x][y] = v;
       //     v <<= 1;
    //    }

    //printf("Antes do theta:\n");
  // print_state(hasher);
  //  hasher.theta();
   // printf("\nDepois do theta:\n");
  //  print_state(hasher);
    //printf("\nAdicionando o rho\n");
   //hasher.rho();
    //theta + rho no codigo
   // print_state(hasher);
    //theta+ rho + pi no codigo
    //printf("\nAdicionando o pi\n");
    //hasher.pi();
    //print_state(hasher);
    //theta + rho + pi + chi no codigo
   // printf("\nAdicionando o chi\n");
    //hasher.chi();
    //print_state(hasher);
    
    for(int numeroRodadas = 0;numeroRodadas< 24;numeroRodadas++)
    {
        hasher.theta();
        hasher.rho();
        hasher.pi();
        hasher.chi();
        hasher.iota(numeroRodadas);
    }
    print_state(hasher);
    return 0;
}
