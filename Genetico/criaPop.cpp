#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdlib.h>
#include <algorithm> 
#include "criaPop.h"


Solucao leArq(char* path) {
	FILE *f;
	unsigned int qtd, tam, elemSize;
	if ((f = fopen(path, "rt")) == NULL) {
		printf("erro ao abrir o arquivo\n");
		exit(1);
	}

	fscanf(f, "%d%d", &qtd, &tam);

	Solucao pop(tam, qtd);

	for (unsigned int i = 0; i < qtd; i++) {
		fscanf(f, "%d", &elemSize);
		pop.add(elemSize, i);
	}
	fclose(f);
	return pop;
}

Solucao reordena(Solucao pop, unsigned int seed)
{
	std::vector<elemento> temp, vet;
	temp = pop.getElements();
	unsigned int tam = temp.size();

	vet.reserve(tam);
	for (unsigned int i = 0; i < tam; i++) {
		elemento elem;
		elem.weight = -1;
		elem.id = -1;
		vet.push_back(elem);
	}
	srand(seed);

	for (unsigned int i = 0; i < temp.size(); i++) {
		int pos;

		do {
			pos = rand() % temp.size();
		} while (vet[pos].id != -1);

		vet[pos] = temp[i];
	}
	pop.setElem(vet);
	return pop;
}

std::vector<Solucao> criaVecPop(char* path, unsigned int popSize)
{
	int seed;
	std::vector<Solucao> populacao;
	FILE *f;

	populacao.reserve(popSize);

	if ((f = fopen("seed.txt", "rt")) == NULL) {
		printf("erro ao abrir o arquivo\n");
		exit(1);
	}

	for (unsigned int i = 0; i < popSize; i++)
	{
		fscanf(f, "%d", &seed);
		populacao.push_back(leArq(path));
		populacao[i] = reordena(populacao[i], seed);
		populacao[i].fillBins();
	}
	fclose(f);
	return populacao;
}

int fitness(Solucao individuo)
{
	return individuo.getBins().size();
}

