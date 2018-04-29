#include "solucao.h"

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
	unsigned int aux = 0;
	_bins.clear();

	for (unsigned int i = 0; i < _elements.size(); i++)
	{
		aux += _elements[i].weight;
		if (aux > _capacity)
		{
			aux = 0;
			_bins.push_back(i);
			aux += _elements[i].weight;
		}
	}
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
