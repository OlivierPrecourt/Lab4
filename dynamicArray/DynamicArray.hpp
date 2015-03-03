#include "dynamicArray.h"
#include <stdexcept>

using namespace std;

const int TAILLE_PAR_DEFAUT_TABLEAU = 100;
const string ERREUR_HORS_DE_INDEX = "l'element n'existe pas";
const string ERREUR_CAPACITE_INVALIDE = "capacite invalide";

template <class T>
DynamicArray<T>::~DynamicArray(){
	delete[] tabElement;
}

template <class T>
DynamicArray<T>::DynamicArray(){
	tabElement = new T[TAILLE_PAR_DEFAUT_TABLEAU];
	capacite = TAILLE_PAR_DEFAUT_TABLEAU;

	for (int i = 0; i < TAILLE_PAR_DEFAUT_TABLEAU; i++){
		tabElement[i] = T();
	}
}

template <class T>
DynamicArray<T>::DynamicArray(unsigned int _capacite){
	if (_capacite < 1) {
		throw invalid_argument(ERREUR_CAPACITE_INVALIDE);
	}
	else {
		tabElement = new T[_capacite];
		capacite = _capacite;

		for (int i = 0; i < _capacite; i++){
			tabElement[i] = T();
		}
	}
}

template <class T>
void DynamicArray<T>::setElement(unsigned int _index, T _valeur){

	if (_index < 0) {
		throw out_of_range(ERREUR_HORS_DE_INDEX);
	}
	else if (_index >= capacite){
		T *nouveauTableau = new T[_index + 1];

		for (int i = 0; i < capacite; i++){
			nouveauTableau[i] = tabElement[i];
		}

		for (int i = capacite; i < _index + 1; i++){
			nouveauTableau[i] = T();
		}
		delete[] tabElement;
		tabElement = nouveauTableau;
		capacite = _index + 1;
	}

	tabElement[_index] = _valeur;
}

template <class T>
T DynamicArray<T>::getElement(unsigned int _index) const {
	if (_index >= capacite){
		throw  out_of_range(ERREUR_HORS_DE_INDEX);
	}
	else {
		return tabElement[_index];
	}
}

template <class T>
int DynamicArray<T>::getCapacite() const {
	return (int)capacite;
}

template <class T>
void DynamicArray<T>::setCapacite(unsigned int _capacite){
	if (_capacite < 1) {
		throw invalid_argument(ERREUR_CAPACITE_INVALIDE);
	}
	else if (_capacite > capacite){
		T *nouveauTableau = new T[_capacite];

		for (int i = 0; i < capacite; i++){
			nouveauTableau[i] = tabElement[i];
		}

		for (int i = capacite; i < _capacite; i++){
			nouveauTableau[i] = T();
		}

		delete[] tabElement;
		tabElement = nouveauTableau;
		capacite = _capacite;
	}
	else {
		T *nouveauTableau = new T[_capacite];

		for (int i = 0; i < _capacite; i++){
			nouveauTableau[i] = tabElement[i];
		}

		delete[] tabElement;
		tabElement = nouveauTableau;
		capacite = _capacite;
	}
}
