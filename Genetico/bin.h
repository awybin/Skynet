#include <iostream>
#include<vector>

typedef struct Elemento
{
	unsigned int size;
	unsigned int id;
}elemento;

class bin
{
public:

	bin();

	bin(unsigned int capacity, unsigned int qtdElem);

	~bin();

	unsigned int getCapacity();

	std::vector<unsigned int> getBins();

	std::vector<elemento> getElements();

	void fillBins();

	/*adiciona um elemento ao vetor de elementos*/
	void add(unsigned int elemSize, unsigned int id);

private:
	unsigned int _capacity;
	std::vector<unsigned int> _binPack;
	std::vector<elemento> _elements;
};



