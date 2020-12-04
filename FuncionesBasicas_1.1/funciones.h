/*
 * funciones.h
 * creado: 26/08/2020
 * autor: Rodrigo Muñoz Guerrero
 *
*/
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#endif // FUNCIONES_H_INCLUDED

using namespace std;

//Clase funciones donde tendremos solo su sonstructor y los tres métodos
class Funciones{
public:
    Funciones(){};
    long sumaDirecta(int n);
    long sumaIterativa(int n);
    long sumaRecursiva(int n);
};

//método de suma Iterativa
long Funciones::sumaIterativa(int n){
  int suma = 0;
  for (int i = 1; i<=n; i++){
    suma = suma + i;
  }
  return suma;
}

//método de suma Recursiva
long Funciones::sumaRecursiva(int n){
 if (n < 1){
   return 0;
 }
 else {
   return n + sumaRecursiva(n-1);
 }
}

//método de suma Directa con fórmula
long Funciones::sumaDirecta(int n){
  return (n*(n+1))/2;
}
