#include "bin.h"
#include "criaPop.h"

int main(void)
{
	int popSize = 200;
	int seed = 12; //valor a ser gerado de forma aleatoria
	std::vector<bin> população;
	for (int i = 0; i < popSize; i++)
	{
		população.push_back(leArq(""));
		população[i] = reordena(população[i], seed);
	}


	return 0;
}