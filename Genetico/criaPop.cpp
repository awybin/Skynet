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
		std::vector<elemento> elementos = populacao[i].getElements();
		populacao[i].fillBins();
	}
	return populacao;
}

int fitness(Solucao individuo)
{
	return individuo.getBins().size();
}

void selecao(std::vector<Solucao> populacao)
{
	 std::sort(populacao.begin(), populacao.end(), melhorSolucao);
}

void crossover(Solucao pai, Solucao mae, std::vector<elemento> filhos[2])
{
	std::vector<elemento> elemPai, elemMae, filho1, filho2;
	elemPai = pai.getElements();
	elemMae = mae.getElements();

	int teste = 1, alternar = 0;

	filho1.reserve(elemPai.size());
	filho2.reserve(elemPai.size());
	for (int i = 0; i < elemPai.size(); i++) {
		elemento elem;
		elem.id = -1;
		elem.weight = -1;
		filho1.push_back(elem);
		filho2.push_back(elem);
	}

	while (teste) {
		/*achar um loop nao feito*/
		int p, m;
		for (p = 0; p < elemPai.size(); p++) {
			if (elemPai[p].id != -1)
				break;
			if (p + 1 == elemPai.size())
				teste = 0;
		}
		if (teste == 0)
			break;
		/*percorrer e copiar um loop*/
		do {

			for (m = 0; m < elemPai.size(); m++) {
				if (elemPai[p].id == elemMae[m].id)
					break;
			}

			if (alternar % 2 == 0) {
				filho1[p] = elemPai[p];
				filho2[m] = elemMae[m];
			}
			else if (alternar % 2 == 1) {
				filho1[m] = elemMae[m];
				filho2[p] = elemPai[p];
			}
			elemPai[p].id = -1;
			elemMae[m].id = -1;
			p = m;
		} while (elemPai[p].id != -1);
		alternar++;
	}
	filhos[0] = filho1;
	filhos[1] = filho2;
}

bool melhorSolucao(Solucao s1, Solucao s2)
{
	if (fitness(s1) >= fitness(s2))
	{
		return true;
	}
	else
		return false;
}

bool mutacao(int seed)
{
	srand(seed);
	int mutRatio = 2;
	if (mutRatio > rand() % 100)
	{
		return true;
	}
	false;
}