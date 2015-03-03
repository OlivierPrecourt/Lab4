#pragma once
#include <iostream>
#include <string>

#include "fonctionsModele.hpp"

using namespace std;

class fonctionsModele
{

public:
	template <typename T>
	T TrouverMax(const T tableau[],const int nbElements);

	template <typename T>
	T CalculerSomme(const T tableau[],const int nbElements);

	//template <>
	//string CalculerSomme(const string tableau[], const int nbElements);

	template <typename T>
	unsigned int CompterElement(const T valeur,const T tableau[],const int nbElements);

private:

};