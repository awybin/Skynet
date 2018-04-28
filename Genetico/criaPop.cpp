#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdlib.h>
#include "criaPop.h"


bin leArq(char* path) {
	FILE *f;
	unsigned int qtd, tam, elemSize;
	if ((f = fopen(path, "rt")) == NULL) {
		printf("erro ao abrir o arquivo\n");
		exit(1);
	}

	fscanf(f, "%d%d", &qtd, &tam);

	bin pop(tam, qtd);

	for (unsigned int i = 0; i < qtd; i++) {
		fscanf(f, "%d", &elemSize);
		pop.add(elemSize, i);
	}
	return pop;
}

bin reordena(bin pop, unsigned int seed)
{
	std::vector<elemento> temp, vet;
	temp = pop.getElements();
	int tam = temp.size();

	vet.reserve(tam);
	for (int i = 0; i < tam; i++) {
		elemento elem;
		elem.size = -1; 
		elem.id = -1;
		vet.push_back(elem);
	}
	srand(seed);

	for (int i = 0; i < temp.size(); i++) {
		int pos;

		do {
			pos = rand() % temp.size();
		} while (vet[pos].id != -1);
		
		vet[pos] = temp[i];
	}
	pop.setElem(vet);
	return pop;
}

std::vector<bin> criaVecPop(char* path, unsigned int popSize)
{
	int seed;
	std::vector<bin> populacao;
	FILE *f;

	populacao.reserve(popSize);

	if ((f = fopen("seed.txt", "rt")) == NULL) {
		printf("erro ao abrir o arquivo\n");
		exit(1);
	}

	for (int i = 0; i < popSize; i++)
	{
		fscanf(f, "%d", &seed);
		populacao.push_back(leArq(path));
		populacao[i] = reordena(populacao[i], seed);
		std::vector<elemento> elementos = populacao[i].getElements();
		populacao[i].fillBins();
	}
	return populacao;
}
