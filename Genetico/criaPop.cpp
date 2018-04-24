#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "criaPop.h"

bin leArq(char* path) {
	FILE *f;
	unsigned int qtd, tam, elemSize;
	if ((f = fopen(path, "rt")) == NULL) {
		printf("erro ao abrir o arquivo");
		exit(1);
	}

	fscanf(f, "%d%d", &qtd, &tam);

	bin pop(tam, qtd);

	for (unsigned int i = 0; i < qtd; i++) {
		fscanf(f, "%d", &elemSize);
		pop.add(elemSize, i);
	}

	pop.fillBins();

	return pop;
}

bin reordena(bin pop, int seed)
{
	return bin();
}

std::vector<bin> criaVecPop()
{
	return std::vector<bin>();
}

void addVecPop(bin pop)
{
}
