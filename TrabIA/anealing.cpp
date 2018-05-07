#define _CRT_SECURE_NO_DEPRECATE
#include "solucao.h"
#include "criaPop.h"
#include "anealing.h"

#include <math.h>
#include<stdio.h>
#include <vector>
#include <time.h>

#define ARQ1 "Falkenauer_t60_00.txt"
#define ARQ2 "Falkenauer_t120_01.txt"
#define ARQ3 "Falkenauer_u120_02.txt"
#define ARQ4 "Falkenauer_u250_04.txt"
#define ARQ5 "Falkenauer_u500_05.txt"

void simulatedAnnealing(char* Path, int n)
{
	printf("\n===================================================\n");
	double e = 2.718281828, p, temp;
	unsigned int saSeed, swapSeed;
	int qtdIni = 1;
	std::vector<Solucao> solu;
	if (strcmp(ARQ1,Path) == 0)// Resultado: 20 em 0 seg
	{
		solu = criaVecPop(Path, qtdIni);
		saSeed = 69322;
		swapSeed = 23353;
	}
	else if (strcmp(ARQ2, Path) == 0)// Resultado: 41 em 4 seg
	{
		solu = criaVecPop(Path, qtdIni);
		saSeed = 194562;
		swapSeed = 13455;
	}
	else if (strcmp(ARQ3, Path) == 0)// Resultado: 46 em 87 seg
	{
		solu = criaVecPop(Path, qtdIni);
		saSeed = 1762;
		swapSeed = 16875;
	}
	else if (strcmp(ARQ4, Path) == 0)// Resultado: 104 em 106 seg
	{
		solu = criaVecPop(Path, qtdIni);
		saSeed = 12;
		swapSeed = 13;
	}
	else if (strcmp(ARQ5, Path) == 0)// Resultado: 213 em 137 seg
	{
		solu = criaVecPop(ARQ5, qtdIni);
		saSeed = 151101;
		swapSeed = 16200;
	}
	else
	{
		printf("Instancia nao existe\n");
		exit(1);
	}
	printf("Primeira Solucao: %d\n", solu[0].getBins().size());
	auto iniTime = time(NULL);
	for (int i = 0; i<solu.size(); i++)
	{
		for (temp = 80; temp>0.00008; temp *= 0.90)
		{
			for (unsigned int j = 0; j<n; j++)
			{
				auto soluNew = solu[i];
				soluNew.swap(swapSeed);
				int delta = fitness(soluNew) - fitness(solu[i]);
				if (delta < 0)
				{
					solu[i] = soluNew;
				}
				else
				{
					p = pow(e, -((double)delta) / temp);
					if (rand() / (double)RAND_MAX <= p)
						solu[i] = soluNew;
				}
			}
			
		}
		printf("Solucao final: %d\n", solu[i].getBins().size());
		solu[i].geraArq(Path, "Anealing");
	}
	printf("Tempo de execucao: %f\n", (double)(time(NULL) - iniTime));
}