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

/*Altera a ordem do vetor de soluções para que o inicio tenham as soluções com melhor valor de fitness*/
void selecao(std::vector<Solucao> populacao);

void crossover(Solucao pai, Solucao mae);

bool melhorSolucao(Solucao s1, Solucao s2);