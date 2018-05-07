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
	double e = 2.718281828, p, temp; //valores para o calculo da probabilidade de aceitar movimento pior
	unsigned int saSeed, swapSeed; //seeds de geracao de numeros aleatorios
	int qtdIni = 1;
	std::vector<Solucao> solu;
	//segue o controle de qual instancia do problema se trata
	if (strcmp(ARQ1,Path) == 0)
	{
		solu = criaVecPop(Path, qtdIni);
		saSeed = 69322;
		swapSeed = 23353;
	}
	else if (strcmp(ARQ2, Path) == 0)
	{
		solu = criaVecPop(Path, qtdIni);
		saSeed = 194562;
		swapSeed = 13455;
	}
	else if (strcmp(ARQ3, Path) == 0)
	{
		solu = criaVecPop(Path, qtdIni);
		saSeed = 1762;
		swapSeed = 16875;
	}
	else if (strcmp(ARQ4, Path) == 0)
	{
		solu = criaVecPop(Path, qtdIni);
		saSeed = 12;
		swapSeed = 13;
	}
	else if (strcmp(ARQ5, Path) == 0)
	{
		solu = criaVecPop(ARQ5, qtdIni);
		saSeed = 151101;
		swapSeed = 16200;
	}
	else //caso nao seja um arquivo valido
	{
		printf("Instancia nao existe\n");
		exit(1);
	}
	printf("Primeira Solucao: %d\n", solu[0].getBins().size());

	clock_t Ticks[2];
	Ticks[0] = clock(); //guarda o tempo de inicio do algoritimo

	for (int i = 0; i<solu.size(); i++)
	{
		for (temp = 80; temp>0.00008; temp *= 0.90) //controle de temperatura
		{
			for (unsigned int j = 0; j<n; j++) //controle de iteracoes para cada faixa de temperatura
			{
				auto soluNew = solu[i];
				soluNew.swap(swapSeed); //pega um vizinho da solucao corrente
				int delta = fitness(soluNew) - fitness(solu[i]); //determina qual a melhor solucao e por quanto
				if (delta < 0) //movimento de melhora
				{
					solu[i] = soluNew;
				}
				else
				{
					p = pow(e, -((double)delta) / temp);
					if (rand() / (double)RAND_MAX <= p) //possibilidade de piora
						solu[i] = soluNew;
				}
			}
			
		}
		printf("Solucao final: %d\n", solu[i].getBins().size());
		solu[i].geraArq(Path, "Anealing"); //gera o arquivo para a solucao final
	}
	Ticks[1] = clock();
	float Tempo = (Ticks[1] - Ticks[0]) / (float)CLOCKS_PER_SEC; //tempo total de execucao
	printf("Tempo gasto: %.2f s.\n", Tempo);
}
