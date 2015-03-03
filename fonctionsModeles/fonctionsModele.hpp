#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
T TrouverMax(const T tableau[],const int nbElements){
	T max = tableau[0];
	for (unsigned int i = 1; i < nbElements; i++){
		if (tableau[i] > max){
			max = tableau[i];
		}
	}
	return max;
}

template <typename T>
T CalculerSomme(const T tableau[], const int nbElements){
	T somme = tableau[0];
	for (unsigned int i = 1; i < nbElements; i++){
		somme += tableau[i];
	}
	return somme;
}

//template <>
//string CalculerSomme(const string tableau[], const int nbElements){
//	string somme = "";
//	for (unsigned int i = 0; i < nbElements; i++){
//		somme += tableau[i];
//	}
//	return somme;
//}

template <typename T>
unsigned int CompterElement(const T valeur,const T tableau[],const int nbElements){
	unsigned int nbOccurences = 0;
	for (unsigned int i = 0; i < nbElements; i++){
		if (tableau[i] == valeur){
			nbOccurences++;
		}
	}
	return nbOccurences;
}