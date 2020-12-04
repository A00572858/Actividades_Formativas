#ifndef DLIST_H_INCLUDED
#define DLIST_H_INCLUDED
#include <string>
#include <sstream>
#include <iostream>

/**
*Programa creado por: Rodrigo Munoz Guerrero
*Matricula: A00572858
*Fecha: 30/09/2020
**/

using namespace std;

template <class T> class DList;

template <class T>
class Link{
public:
    Link();
    Link(T);
    Link(T,Link<T>*);
    T value;
    Link<T> *next;
    Link<T> *pre;
    friend class DList<T>;
};

template <class T>
Link<T>:: Link(): value(0), next(0), pre(0) {}
template <class T>
Link<T>:: Link(T v): value(v), next(0), pre(0) {}

template <class T>
class DList{
private:
    Link<T> *head;
    Link<T> *tail;
public:
    DList();
    DList(const DList<T>&);
    bool empty() const;
    string toStringForward() const;
    string toStringBackward() const;
    void add(int);
    void update(int,int);
    T find(int);
    T remove(int);
    T removef(int);
    T value;
};

template <class T>
DList<T>::DList() : head(0), tail(0) {};

template <class T>
bool DList<T>::empty() const {
	return (head == 0 && tail == 0);
}

template <class T>
string DList<T>::toStringForward() const {
    stringstream aux;
    Link<T> *p;
    p = head;
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->next != 0) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}

template <class T>
string DList<T>::toStringBackward() const {
    stringstream aux;
    Link<T> *p;
    p = tail;
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->pre != 0) {
            aux << ", ";
        }
        p = p->pre;
    }
    aux << "]";
    return aux.str();
}

//CREATE
template <class T>
void DList<T>::add(int a) {
    Link<T> *nl;
    nl = new Link<T>(a);
    if (empty()){
        head = nl;
        tail = nl;
        return;
    }
    else{
    tail->next = nl;
    nl->pre = tail;
    tail = nl;
    }
}

//FIND
template <class T>
T DList<T>::find(int a) {
    Link<T> *p;
    int pos = 0;
    p = head;
    while (p!=0){
        if (p->value == a){
            return pos;
        }
        p = p->next;
        pos++;
    }
    return -1;
}

//UPDATE
template <class T>
void DList<T>::update(int i, int a) {
    Link<T> *p;
    int pos = 0;
    p = head;
    while (p!=0){
        if (pos == i){
            p->value = a;
        }
        p = p->next;
        pos++;
    }
}

template <class T>
T DList<T>::removef(int a) {
    T r;
    Link<T> *p;
    p = head;
    r = p->value;
    if (head==tail){
        head = 0;
        tail = 0;
    }
    else{
        head = p->next;
        p->next->pre = 0;
    }
    delete p;
    return r;
}

//DELETE
template <class T>
T DList<T>::remove(int a) {
    Link<T> *p;
    int pos = 0;
    T r;
    if (a==0){
        return removef(a);
    }
    p = head;
    while (p!=0){
        if (pos==a){
            r = p->value;
            p->pre->next = p->next;
            if (p->next != 0) {
                p->next->pre = p->pre;
            }
            delete p;
            return r;
        }
        p = p-> next;
        pos++;
    }
    return -1;
}


#endif // DLIST_H_INCLUDED
