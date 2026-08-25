# SHA-256-CPP
Primeiro projeto meu que consiste na implementação do algoritmo sha3-256

## Objetivo

Estudar a construção sponge e a permutação Keccak-f[1600], implementando
SHA3-256 sem utilizar bibliotecas criptográficas para o cálculo do hash.
E conseguir criar uma aplicação com criptografia 
## Parâmetros do SHA3-256

- Estado: 1600 bits
- Rate: 1088 bits (136 bytes)
- Capacity: 512 bits
- Saída: 256 bits (32 bytes)
- Permutação: Keccak-f[1600], 24 rodadas

## Aviso

Este é um projeto educacional e não foi auditado para uso em produção.

## Referências

- [FIPS PUB 202 (NIST)](https://doi.org/10.6028/NIST.FIPS.202)
- [Keccak Team](https://keccak.team/keccak.html)
