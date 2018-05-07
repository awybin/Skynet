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

int main(void)
{		
	int tipoalgoritmo;
	printf("Informe qual o numero do algoritmo desejado:\n1 - Genetico\n2 - Simulated Anealing\n");
	scanf("%d", &tipoalgoritmo);
	if (tipoalgoritmo == 1)
	{
		int popSize = 100;
		printf("\nARQUIVO 1");
		printf("\n===================================================\n");
		genetico(ARQ1, popSize);
		printf("\nARQUIVO 2");
		printf("\n===================================================\n");
		genetico(ARQ2, popSize);
		printf("\nARQUIVO 3");
		printf("\n===================================================\n");
		genetico(ARQ3, popSize);
		printf("\nARQUIVO 4");
		printf("\n===================================================\n");
		genetico(ARQ4, popSize);
		printf("\nARQUIVO 5");
		printf("\n===================================================\n");
		genetico(ARQ5, popSize);
	}
	else if (tipoalgoritmo == 2)
	{
		int n = 5000; /*Numero de iteracoes*/
		printf("ARQUIVO 1");
		simulatedAnnealing(ARQ1, n);
		printf("\n\n");
		printf("ARQUIVO 2");
		simulatedAnnealing(ARQ2, n);
		printf("\n\n");
		printf("ARQUIVO 3");
		simulatedAnnealing(ARQ3, n);
		printf("\n\n");
		printf("ARQUIVO 4");
		simulatedAnnealing(ARQ4, n);
		printf("\n\n");
		printf("ARQUIVO 5");
		simulatedAnnealing(ARQ5, n);

	}
	else
		printf("Numero do algoritmo incorreto\n");

	system("pause");
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
	fclose(f);
}