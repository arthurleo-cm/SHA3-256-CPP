# SHA3-256-CPP
Primeiro projeto meu que consiste na implementação do algoritmo sha3-256

## Objetivo

Conseguir implementar o sha3-256

## Parâmetros do SHA3-256

- Estado: 1600 bits
- Rate: 1088 bits (136 bytes)
- Capacity: 512 bits
- Saída: 256 bits (32 bytes)
- Permutação: Keccak-f[1600], 24 rodadas

## Etapas implementadas
- Theta, Rho, Pi, Chi e Iota: transformações da permutação Keccak-f[1600]
- Keccak-f: executa as 24 rodadas na ordem correta
- Absorção: incorpora blocos de 136 bytes ao estado de 1600 bits
- Padding SHA3: usa o sufixo 0x06 e o bit final 0x80
- Extração: produz os 32 bytes (256 bits) do hash
- Testes: compara resultados com vetores conhecidos
## Exemplo de validação

Para a mensagem abc, o resultado esperado segundo o SHA3-256 é:

3a985da74fe225b2045c172d6bd390bd
855f086e3e9d525b46bfe24511431532
## Aviso

Este é um projeto educacional e não foi auditado para uso em produção.

## Referências


- [FIPS PUB 202 (NIST)](https://doi.org/10.6028/NIST.FIPS.202)
- [Keccak Team](https://keccak.team/keccak.html)
- https://android.googlesource.com/platform/external/openssl/+/52c587d60be67c337364b830dd3fdc15404a2f04/crypto/sha/asm/keccak1600-armv8.pl
- https://www.youtube.com/watch?v=JWskjzgiIa4("Aula 22: A Função Hash SHA-3 por Christof Paar")
