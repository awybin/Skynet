#define _CRT_SECURE_NO_DEPRECATE
#include "solucao.h"
#include "criaPop.h"
#include "genetico.h"
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

void geraSeed();

void simulatedAnnealing();

int main(void)
{
	/*int popSize = 500;
	std::vector<Solucao> populacao;

	printf("Arq1===================================\n\n");
	genetico(ARQ1, popSize);
	printf("Arq2===================================\n\n");
	genetico(ARQ2, popSize);
	printf("Arq3===================================\n\n");
	genetico(ARQ3, popSize);
	printf("Arq4===================================\n\n");
	genetico(ARQ4, popSize);
	printf("Arq5===================================\n\n");
	genetico(ARQ5, popSize);

	scanf("%d", &popSize);*/
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