#include "bin.h"
#include "criaPop.h"

int main(void)
{
	int popSize = 200;
	int seed = 12; //valor a ser gerado de forma aleatoria
	std::vector<bin> popula��o;
	for (int i = 0; i < popSize; i++)
	{
		popula��o.push_back(leArq(""));
		popula��o[i] = reordena(popula��o[i], seed);
	}


	return 0;
}