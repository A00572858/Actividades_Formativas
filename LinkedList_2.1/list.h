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
    void add(T);
    T find(T);
    T remove_first();
    void update(T,T);
    T remove(T);
};

template <class T>
List<T>::List() : head(0) {};

template <class T>
void List<T>::add(T a) {
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
T List<T>::find(T a){
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
void List<T>::update(T pos,T val){
	int i = 0;
	Link<T> *p;
	
	p = head;
	while (p != 0){
		if (i == pos){
			p->value = val;
		}
		p = p->next;
		i++;
	}
}

template <class T>
T List<T>::remove_first(){
	T val;
	Link<T> *p, *q;
	
	p = head;
	q = p;
	p = p->next;
	val = q->value;
	head = p;
	
	delete q;
	
	return val;
}

template <class T>
T List<T>::remove(T pos){
	int index;
	T val;
	Link<T> *p, *q;
	
	if (pos == 0){
		return remove_first();
	}
	
	q = 0;
	p = head;
	index = 0;
	while (index != pos){
		q = p;
		p = p->next;
		index++;
	}
	
	val = p->value;
	q->next = p->next;
	
	delete p;
	
	return val;
}

#endif // LIST_H_INCLUDED
