#define _CRT_SECURE_NO_DEPRECATE
#include "solucao.h"
#include "criaPop.h"

#include <math.h>
#include<stdio.h>
#include <vector>
#include <time.h>

#define ARQ1 "Falkenauer_t60_00.txt"
#define ARQ2 "Falkenauer_t120_01.txt"
#define ARQ3 "Falkenauer_u120_02.txt"
#define ARQ4 "Falkenauer_u250_04.txt"
#define ARQ5 "Falkenauer_u500_05.txt"

void geraSeed();

void simulatedAnnealing();

int main(void)
{
	int popSize = 200;
	std::vector<Solucao> populacao;
	std::vector<elemento> teste[2];

	populacao = criaVecPop(ARQ1, popSize);
	printf("\n id/size, \n\n");
	for (int i = 0; i < 2; i++) {
		printf("%d Membro da Pop:\n\n", i);
		std::vector<elemento> elementos = populacao[i].getElements();
		for (int j = 0; j < elementos.size(); j++) {
			printf("%d/%d, ", elementos[j].id, elementos[j].weight);
		}
		printf("\n\n");
	}

	crossover(populacao[0], populacao[1], teste);

	printf("Filho 1\n\n");
	for (int j = 0; j < teste[0].size(); j++) {
		printf("%d/%d, ", teste[0][j].id, teste[0][j].weight);
	}
	printf("\n\nFilho 2\n\n");
	for (int j = 0; j < teste[1].size(); j++) {
		printf("%d/%d, ", teste[1][j].id, teste[1][j].weight);
	}
	printf("\n\n");
        
        simulatedAnnealing();

	return 0;
}

void geraSeed() {
	FILE *f;
	unsigned int v[1000];
	if ((f = fopen("seed.txt", "wt")) == NULL) {
		printf("erro ao abrir o arquivo\n");
		exit(1);
	}

	for (int i = 0; i < 1000; i++) {
		v[i] = 0;
	}

	for (int i = 0; i < 1000; i++) {
		int temp, teste;
		do {
			temp = rand();
			for (int j = 0; j < i; j++) {
				if (v[j] == temp) {
					teste = 0;
					printf("Repetida: %d\n", temp);
					break;
				}
			}
			teste = 1;
		} while (teste == 0);
		v[i] = temp;
		fprintf(f, "%d\n", temp);
	}
}

void simulatedAnnealing()
{
    printf("\n===================================================\n");
    double e = 2.718281828, p, temp;
    unsigned int saSeed, swapSeed, arqNum, n;
    int qtdIni = 1;
    printf("Informe qual instancia do problema deve ser resolvida:\n");
    scanf("%d", &arqNum);
    std::vector<Solucao> solu;
    if(arqNum==1)// Resultado: 20 em 0 seg
    {
        solu = criaVecPop(ARQ1, qtdIni);
        saSeed = 15000;
        swapSeed = 16000;
        n = 2700;
    }
    else if(arqNum==2)// Resultado: 41 em 8 seg
    {
        solu = criaVecPop(ARQ2, qtdIni);
        saSeed = 15000;
        swapSeed = 16000;
        n = 21000;
    }
    else if(arqNum==3)// Resultado: 46 em 203 seg
    {
        solu = criaVecPop(ARQ3, qtdIni);
        saSeed = 15000;
        swapSeed = 16000;
        n = 500000;
    }
    else if(arqNum==4)// Resultado: 104 em 291 seg
    {
        solu = criaVecPop(ARQ4, qtdIni);
        saSeed = 15000;
        swapSeed = 16000;
        n = 500000;
    }
    else if(arqNum==5)// Resultado: 213 em 469 seg
    {
        solu = criaVecPop(ARQ5, qtdIni);
        saSeed = 15000;
        swapSeed = 16000;
        n = 500000;
    }
    else
    {
        printf("Instancia nao existe\n");
        exit(1);
    }
    printf("Quantidade de solucoes iniciais:%d\n", (unsigned int)solu.size());
    printf("%d\n", solu[0].getBins().size());
    auto iniTime = time(NULL);
    printf("SA Seed: %d\nSwap Seed: %d\n", saSeed, swapSeed);
    for(int i=0; i<solu.size(); i++)
    {
        for(temp=80; temp>0.00008; temp*=0.9)
        {
            for(unsigned int j=0; j<n; j++)
            {
                auto soluNew = solu[i];
                soluNew.swap(swapSeed);
                int delta = fitness(soluNew)-fitness(solu[i]);
                if(delta<0)
                    solu[i] = soluNew;
                else
                {
                    p = pow(e, -((double)delta)/temp);
                    if(rand() / (double)RAND_MAX <= p)
                        solu[i] = soluNew;
                }
            }
        }
        printf("%d\n", solu[i].getBins().size());
    }
    printf("Tempo de execucao: %f\n", (double)(time(NULL)-iniTime));
}
