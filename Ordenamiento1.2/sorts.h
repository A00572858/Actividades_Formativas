#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>

template <class T>
class Sorts{
private:
	void swap(std::vector<T>&, int, int);
	void carray(std::vector<T>&,std::vector<T>&, int, int);
	void marray(std::vector<T>&,std::vector<T>&, int, int, int);
	void Split(std::vector<T>&,std::vector<T>&, int, int);
public:
    std::vector<T> ordenaSeleccion(std::vector<T>&);
    std::vector<T> ordenaBurbuja(std::vector<T>&);
    std::vector<T> ordenaMerge(std::vector<T>&);
    int busqSecuencial(std::vector<T>&,int);
    int busqBinaria(std::vector<T>&,int);
    std::string arrayToString(const std::vector<T>&);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

template <class T>
std::vector<T> Sorts<T>::ordenaSeleccion(std::vector<T> &v){
    int p;
    for (int i = sizeof(v)-1;i > 0;i--){
        p = 0;
        for (int j=1;j<=i;j++){
            if (v[j] > v[p]){
                p = j;
            }
        }
        if (p != i){
            swap(v,i,p);
        }
    }
    return v;
}

template <class T>
std::string arrayToString(const std::vector<T> &v) {
	std::stringstream aux;

	aux << "[" << v[0];
	for (int i = 1; i < v.size(); i++) {
		aux << ", " << v[i];
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::vector<T> Sorts<T>::ordenaBurbuja(std::vector<T> &v){
    for (int i = sizeof(v) - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}

template <class T>
void Sorts<T>::carray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

template <class T>
void Sorts<T>::marray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (A[i]<A[j]){
			B[k]=A[i];
			i++;
		}
		else{
			B[k]=A[j];
			j++;
		}
		k++;
	}
	if (i>mid){
		for (;j<=high;j++){
			B[k++]=A[j];
		}
	} else {
		for (;i<=mid;i++){
			B[k++]=A[i];
		}
	}
}

template <class T>
void Sorts<T>::Split(std::vector<T> &A, std::vector<T> &B, int low, int high){
	int mid;

	if ((high-low)<1){
		return;
	}
	mid=(high + low)/2;
	Split(A, B, low, mid);
	Split(A, B, mid + 1, high);
	marray(A, B, low, mid, high);
	carray(A, B, low, high);
}

template <class T>
std::vector<T> Sorts<T>::ordenaMerge(std::vector<T> &s){
    std::vector<T> v(s);
    std::vector<T> t(v.size());
	Split(v, t, 0, v.size() - 1);
	return s;
}

template <class T>
int Sorts<T>::busqSecuencial(std::vector<T> &v, int num) {

	for (int i = 0; i < v.size(); i++) {
		if (num == v[i]) {
			return i;
		}
	}
	return -1;
}

template <class T>
int Sorts<T>::busqBinaria(std::vector<T> &v, int num) {

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

#endif // SORTS_H_INCLUDED
