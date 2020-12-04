#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>

using namespace std;

template <class T>
class Link{
public:
    Link();
    Link(T);
    Link(T,Link<T>*);
    T value;
    Link<T> *next;
//    friend class List<T>;
};

template <class T>
Link<T>:: Link(): value(0), next(0){}
template <class T>
Link<T>:: Link(T v): value(v), next(0){}
template <class T>
Link<T>:: Link(T v, Link* n): value(v), next(n){}

template<class T>
class List{
private:
    Link<T> *head;
public:
    string toString() const;
    List();
    void add(int);
    int find(int);
    void update(int,int);
    int remove(int);
};

template <class T>
List<T>::List() : head(0) {};

template <class T>
void List<T>::add(int a) {
    Link<T> *newlink, *p;
    newlink = new Link<T>(a);
    if(head == 0){
        newlink->next = head;
        head = newlink;
        return;
    }
    p = head;
    while (p->next!=0){
        p = p->next;
    }
    newlink->next = 0;
    p->next = newlink;
}

template <class T>
string List<T>::toString() const{
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
int List<T>::find(int a){
    int cont = 0;
    Link<T> *p;
    p = head;
    if (head == 0){
        return -1;
    }
    while (p!=0){
        if (p->value==a){
            return cont;
        }
        p = p->next;
        cont++;
    }
    return -1;
}

template <class T>
void List<T>::update(int i,int a) {
    Link<T>* p;
    int cont;
    if(head == 0){
        return;
    }
    p = head;
    while (p!=0){
        if(cont == i){
            p->value = a;
            return;
        }
        p = p->next;
        cont++;
    }

}

template <class T>
int List<T>::remove(int a) {
    Link<T> *p, *q;
    int b,c = 0;
    if (a==0){
        p = head;
        head = p->next;
        b = p->value;
        delete p;
    }
    p = head;
    while (p!=0){
        if (c == a){
            b = q->value;
            q->next = p->next;
            delete p;
            return b;
        }
        q = p;
        p = p->next;
        c++;
    }
}

#endif // LIST_H_INCLUDED
