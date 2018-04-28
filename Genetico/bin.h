#ifndef BIN_H
#define BIN_H

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

	/*Retorna o valor equivalente a quanto cabe em um bin*/
	unsigned int getCapacity();

	/*Retorna o vetor de bins*/
	std::vector<unsigned int> getBins();

	/*Retorna o vetor de elementos*/
	std::vector<elemento> getElements();

	/*Preenche o vetor de bins com a quantidade de cada elemento*/
	void fillBins();

	/*Adiciona um elemento ao vetor de elementos*/
	void add(unsigned int elemSize, unsigned int id);

	/*Muda o vetor de elementos pelo recebido como argumento*/
	void setElem(std::vector<elemento> elementos);

private:
	/*Capacidade maxima de um bin*/
	unsigned int _capacity;

	/*Vetor que representa os bins, cada posição é um bin e o numero armazenado é equivalente ao numero de elementos*/
	std::vector<unsigned int> _binPack;

	/*Vetor com os elementos*/
	std::vector<elemento> _elements;
};

#endif

