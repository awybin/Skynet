#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdlib.h>
#include <algorithm> 
#include "criaPop.h"
#include "genetico.h"

std::vector<Solucao> selecao(std::vector<Solucao> populacao)
{
	for (int i = 0; i < populacao.size(); i++) {
		for (int j = 0; j < populacao.size(); j++) {
			if (!melhorSolucao(populacao[i], populacao[j])) {
				Solucao temp = populacao[i];
				populacao[i] = populacao[j];
				populacao[j] = temp;
			}
		}
	}

	return populacao;
}

void crossover(Solucao pai, Solucao mae, Solucao filhos[2])
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
	mutacao(filhos[0]);
	mutacao(filhos[1]);

	filhos[0].setElem(filho1);
	filhos[1].setElem(filho2);

	filhos[0].fillBins();
	filhos[1].fillBins();
}

bool melhorSolucao(const Solucao &s1, const Solucao &s2)
{
	if (fitness(s1) >= fitness(s2))
	{
		return true;
	}
	else
		return false;
}

void mutacao(Solucao filho)
{
	int mutRatio = 3;
	if (mutRatio > rand() % 100)
	{
		for (int i = 0; i < 10; i++)
		{
			filho.swap(3);
		}
	}
}

void genetico(char* path, int popSize) {
	int cont = 0; //Conta as repetições sem melhora
	std::vector<Solucao> populacao;
	populacao = criaVecPop(path, popSize);

	populacao = selecao(populacao);
	Solucao melhor = populacao[0];
	srand(2);

	printf("Inicial %d bins\n\n", melhor.getBins().size());

	while (cont < 200) {
		
		populacao = embaralhaPop(populacao);

		for (int i = 0; i < populacao.size() / 4; i++) {
			crossover(populacao[2*i], populacao[2 * i + 1], &populacao[populacao.size() / 2 + 2*i]);
		}

		//Checa se houve melhora
		populacao = selecao(populacao);
		if (melhorSolucao(melhor, populacao[0])) {
			cont++;
			//printf("%d geracao, nao melhorou\n %d bins\n\n", teste, melhor.getBins().size());
		}
		else {
			melhor = populacao[0];
			cont = 0;
			//printf("%d geracao, melhorou\n %d bins\n\n", teste, melhor.getBins().size());
		}
	}
	printf("Final %d bins\n\n", melhor.getBins().size());
}

std::vector<Solucao> embaralhaPop(std::vector<Solucao> populacao) {
	std::vector<Solucao> novoPop;
	std::vector<int> usados;

	novoPop.reserve(populacao.size());
	usados.reserve(populacao.size()/2);
	
	for (int i = 0; i < populacao.size() / 2; i++) 
		usados.push_back(1);
	
	for (int i = 0; i < populacao.size() / 2; i++) {
		int prox = 1;
		while (usados[prox] == -1) 
			prox = rand() % populacao.size()/2;
		
		novoPop.push_back(populacao[prox]);
		usados[prox] = -1;
	}
	
	for (int i = populacao.size() / 2; i < populacao.size(); i++)
		novoPop.push_back(populacao[0]);

	return novoPop;
}
