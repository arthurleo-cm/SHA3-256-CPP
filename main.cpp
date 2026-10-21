#include "sha3_256.hpp"
#include <cstdio>
#include <iostream>
#include <string>
void print_state(const Sha3_256& h) {
    for (int x = 0; x < 5; ++x)
        for (int y = 0; y < 5; ++y)
            printf("state[%d][%d] = %016lx\n", x, y, (unsigned long)h.state[x][y]);
}

int main()
{
    std::string mensagem;

    printf("Digite a mensagem para calcular o SHA3-256: ");
    if (!std::getline(std::cin, mensagem)) {
        printf("Erro ao ler a mensagem.\n");
        return 1;
    }
    Sha3_256 hasher;
     uint8_t saida[32];

    hasher.hash(reinterpret_cast<const uint8_t*>(mensagem.data()), mensagem.size(), saida);

    printf("SHA3-256: ");
    for (int i = 0; i < 32; ++i) {
        printf("%02x", (unsigned int)saida[i]);
    }
    printf("\n");

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
    
   
    return 0;
}
