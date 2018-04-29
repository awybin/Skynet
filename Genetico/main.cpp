#define _CRT_SECURE_NO_DEPRECATE
#include "solucao.h"
#include "criaPop.h"

#define ARQ1 "Falkenauer_t60_00.txt"
#define ARQ2 "Falkenauer_t120_01.txt"
#define ARQ3 "Falkenauer_u120_02.txt"
#define ARQ4 "Falkenauer_u250_04.txt"
#define ARQ5 "Falkenauer_u500_05.txt"

int fitness(Solucao individuo);
void selecao(std::vector<Solucao> populacao);
void crossover(Solucao pai, Solucao mae);
void geraSeed();

int main(void)
{
	int popSize = 200;
	std::vector<Solucao> populacao;

	populacao = criaVecPop(ARQ1, popSize);
	printf("\n id/size, \n\n");
	for (int i = 0; i < 10; i++) {
		printf("%d Membro da Pop:\n\n", i);
		std::vector<elemento> elementos = populacao[i].getElements();
		for (int j = 0; j < elementos.size(); j++) {
			printf("%d/%d, ", elementos[j].id, elementos[j].weight);
		}
		printf("\n\n");
	}



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

int fitness(Solucao individuo)
{
	return individuo.getBins().size();
}

void selecao(std::vector<Solucao> populacao)
{
	std::vector<std::pair<Solucao, int>> popFit;
	for (int i = 0; i < populacao.size(); i++)
	{
		popFit.emplace_back(populacao[i], fitness(populacao[i]));
	}

	


	for (int i = 0; i < populacao.size(); i++)
	{
		populacao[i] = popFit[i].first;
	}
}

void crossover(Solucao pai, Solucao mae)
{

}