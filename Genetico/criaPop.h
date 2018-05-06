#include<vector>
#include "solucao.h"

/*Le o arquivo e retorna uma solucao*/
Solucao leArq(char* path);

/*Reordena o vetor de elementos de um membro da populacao*/
Solucao reordena(Solucao pop, unsigned int seed);

/*Cria o vetor de populacoes*/
std::vector<Solucao> criaVecPop(char* path, unsigned int popSize);

/*Retorna um inteiro baseado no numero de bins de uma solucao*/
int fitness(Solucao individuo);

