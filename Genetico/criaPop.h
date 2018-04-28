#include<vector>
#include "bin.h"

/*Le o arquivo*/
bin leArq(char* path);

/*Reordena o vetor de elementos de um membro da populacao*/
bin reordena(bin pop, unsigned int seed);

/*Cria o vetor de populacoes*/
std::vector<bin> criaVecPop(char* path, unsigned int popSize);