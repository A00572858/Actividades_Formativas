/*
 * sorts.h
 * Rodrigo Muñoz Guerrero
 * A01705674
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <iostream>
#include <vector>

using namespace std;

//Creación de clase tipo template que contiene los diferentes ordenamientos
template <class T>
class Sorts {
private:
	void swap(vector<T>&, int, int);
	void copiarArreglo(vector<T>&, vector<T>&, int, int);
	void mergeArray(vector<T>&, vector<T>&, int, int, int);
	void mergeSplit(vector<T>&, vector<T>&, int, int);
public:
 	vector<T> ordenaSeleccion(vector<T>&);
	vector<T> ordenaBurbuja(vector<T>&);
	vector<T> ordenaMerge(vector<T>&);
 	int busqSecuencial(vector<T>&, int);
 	int busqBinaria(vector<T>&, int);
};

//Funcion que intercambia los valores de dos indices dados dentro de un vector
template <class T>
void Sorts<T>::swap(vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

//Función que ordena un vector con el método de "burbuja"
template <class T>
vector<T> Sorts<T>::ordenaBurbuja(vector<T> &v) {
	for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}

//Función de ordenamiento que utiliza el método de Selección
template <class T>
vector<T> Sorts<T>::ordenaSeleccion(vector<T> &v) {
	int posicion;
	for (int i=0; i < v.size(); i++) {
		posicion = i;
		for (int j = i; j < v.size(); j++) {
			if (v[j] <= v[posicion]) {
				posicion = j;
			}
		}
		if (posicion != i) {
			swap(v, i, posicion);
		}
	}
	return v;
}

//Función de ordenamiento que utiliza el método "Merge"
template <class T>
vector<T> Sorts<T>::ordenaMerge(vector<T> &v) {
    vector<T> temp(v.size());
	mergeSplit(v, temp, 0, v.size() - 1);
	return v;
}

//Función de apoyo a la función ordenaMerge()
template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high) {
	int mid;
	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copiarArreglo(A, B, low, high);
}

//Función auxiliar de ordenaMerge()
template <class T>
void Sorts<T>::copiarArreglo(vector<T> &A, vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

//Función auxiliar de ordenaMerge
template <class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high) {
	int i, j, k;
	i = low;
	j = mid + 1;
	k = low;
	while (i <= mid &&j <= high) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}

//Función de búsqueda de un número dado dentro de un vector o arrgelo de forma secuencial o iterativa
template <class T>
int Sorts<T>::busqSecuencial(vector<T> &v, int num) {
	for (int i = 0; i < v.size(); i++) {
		if (num == v[i]) {
			return i;
		}
	}
	return -1;
}

//Funcipon de búsqueda de un número dentro de un arreglo utilizando el método de arbol binario
template <class T>
int Sorts<T>::busqBinaria(vector<T> &v, int num) {
	int mid;
	int bot = 0;
	int top = v.size() - 1;
	while (bot < top) {
		mid = (top + bot) / 2;
		if (num == v[mid]) {
			return mid;
		} else if (num < v[mid]) {
			top = mid - 1;
		} else if (num > v[mid]) {
			bot = mid + 1;
		}
	}
	return bot;
}

#endif
