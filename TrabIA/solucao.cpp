#define _CRT_SECURE_NO_DEPRECATE
#include "solucao.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

Solucao::Solucao()
{

}

Solucao::Solucao(unsigned int capacity, unsigned int qtdElem)
{
	_capacity = capacity;
	_elements.reserve(qtdElem);
}

Solucao::~Solucao()
{

}

unsigned int Solucao::getCapacity()
{
	return _capacity;
}

std::vector<unsigned int> Solucao::getBins()
{
	return _bins;
}

std::vector<elemento> Solucao::getElements()
{
	return _elements;
}

void Solucao::fillBins()
{
	unsigned int aux = 0, i;
	_bins.clear();

	for (i = 0; i < _elements.size(); i++)
	{
		aux += _elements[i].weight;
		if (aux > _capacity)
		{
			aux = 0;
			_bins.push_back(i);
			aux += _elements[i].weight;
		}
	}
	_bins.push_back(i);
}

void Solucao::add(unsigned int elemSize, unsigned int id) {
	elemento elem;
	elem.weight = elemSize;
	elem.id = id;
	_elements.push_back(elem);
}

void Solucao::setElem(std::vector<elemento> elementos) {
	_elements = elementos;
}

void Solucao::swap(unsigned int seed)
{
    //printf("Swap Seed: %d\n", seed);
    static int x = 0;
    if(x==0)
    {
        srand(seed);
        x=1;
    }
    int idx1 = 0, idx2 = 0;
    while(idx1==idx2)
    {
        idx1 = rand() % _elements.size();
        idx2 = rand() % _elements.size();
    }
    auto aux = _elements[idx1];
    _elements[idx1] = _elements[idx2];
    _elements[idx2] = aux;
    fillBins();
    
}

void Solucao::exibe() {
	int aux = 0, pesTot = 0;

	printf( "%d\n", _bins.size());
	for (int i = 0; i < _elements.size(); i++) {

		if (_bins[aux] == i) {
			printf("Peso: %d\n", pesTot);
			aux++;
			pesTot = 0;
		}
		pesTot += _elements[i].weight;
		printf("%d\t", _elements[i].id);
	}
	printf("Peso: %d\n", pesTot);
}

void Solucao::geraArq(char *path, char *tipo) {
	int aux = 0;
	char path2[201], newPath[218];
	FILE* f;

	int i = 0;
	strcpy(path2, path);
	while (path2[i] != '.') {
		i++;
	}
	path2[i] = '\0';

	strcpy(newPath, path2);
	strcat(newPath, "_");
	strcat(newPath, tipo);
	strcat(newPath, "_Solucao.txt");

	if ((f = fopen(newPath, "wt")) == NULL) {
		printf("erro ao abrir o arquivo\n");
		system("pause");
		exit(1);
	}

	fprintf(f, "%d\n", _bins.size());
	for (int i = 0; i < _elements.size(); i++) {

		if (_bins[aux] == i) {
			fprintf(f, "\n");
			aux++;
		}
		fprintf(f, "%d\t", _elements[i].id);
	}
}