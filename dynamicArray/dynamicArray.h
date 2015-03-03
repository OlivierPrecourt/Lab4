#pragma once
#include <iostream>

using namespace std;

template <class T>
class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(unsigned int _capacite);
	~DynamicArray();
	void setElement(unsigned int _index, T _valeur);
	T getElement(unsigned int index) const;
	int getCapacite() const;
	void setCapacite(unsigned int _capacite);
private:
	T* tabElement;
	unsigned int capacite;
	DynamicArray(DynamicArray & _dynamicArray);
	bool operator=(const DynamicArray& _rhs) const;
};

#include "DynamicArray.hpp"