#include<vector>
#include "solucao.h"

/*Le o arquivo*/
Solucao leArq(char* path);

/*Reordena o vetor de elementos de um membro da populacao*/
Solucao reordena(Solucao pop, unsigned int seed);

/*Cria o vetor de populacoes*/
std::vector<Solucao> criaVecPop(char* path, unsigned int popSize);

/*Retorna um inteiro baseado no numero de valores dentro do vetor bins*/
int fitness(Solucao individuo);

