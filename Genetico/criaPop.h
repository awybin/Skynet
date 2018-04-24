#include<vector>
#include "bin.h"

/*Le o arquivo*/
bin leArq(char* path);

/*Reordena o vetor de elementos de um membro da populacao*/
bin reordena(bin pop, int seed);

/*Cria o vetor de populacoes*/
std::vector <bin> criaVecPop();

/*Adiciona um membro ao vetor de populacoes*/
void addVecPop(bin pop);