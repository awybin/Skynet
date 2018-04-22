#pragma once

#include <iostream>
#include<vector>

class bin
{
public:

	bin();

	bin(unsigned int capacity);

	~bin();

	unsigned int getCapacity();

	std::vector<unsigned int> getBins();

	std::vector<unsigned int> getElements();

	void fillBins();

private:
	unsigned int _capacity;
	std::vector<unsigned int> _binPack;
	std::vector<unsigned int> _elements;
};



