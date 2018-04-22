#include "bin.h"

bin::bin()
{

}

bin::bin( unsigned int capacity)
{
	_capacity = capacity;
	_elements.reserve(capacity);
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

std::vector<unsigned int> bin::getElements()
{
	return _elements;
}

void bin::fillBins()
{
	unsigned int aux = 0;
	for (unsigned int i = 0; i < _elements.size(); i++)
	{
		aux += _elements[i];
		if (aux > _capacity)
		{
			aux = 0;
			_binPack.push_back(i);
		}			
	}
}
