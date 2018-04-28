#include "bin.h"

bin::bin()
{

}

bin::bin(unsigned int capacity, unsigned int qtdElem)
{
	_capacity = capacity;
	_elements.reserve(qtdElem);
}

bin::~bin()
{

}

unsigned int bin::getCapacity()
{
	return _capacity;
}

std::vector<unsigned int> bin::getBins()
{
	return _binPack;
}

std::vector<elemento> bin::getElements()
{
	return _elements;
}

void bin::fillBins()
{
	unsigned int aux = 0;
	for (unsigned int i = 0; i < _elements.size(); i++)
	{
		aux += _elements[i].size;
		if (aux > _capacity)
		{
			aux = 0;
			_binPack.push_back(i);
		}
	}
}

void bin::add(unsigned int elemSize, unsigned int id) {
	elemento elem;
	elem.size = elemSize;
	elem.id = id;
	_elements.push_back(elem);
}

void bin::setElem(std::vector<elemento> elementos) {
	_elements = elementos;
}