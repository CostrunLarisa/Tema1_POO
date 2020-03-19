#ifndef NOD_H
#define NOD_H
#include<iostream>
using namespace std;
class Lista;
class Nod {
	int info;       //variabila pentru informatia din nod
	Nod* next;      //adresa urmatorului nod
	Nod* prev;      //adresa nodului precedent
public:
	Nod();
	Nod(int, Nod*,Nod*);
	void setInfo(int);
	void setNext(Nod*);
	void setPrev(Nod*);
	int getInfo();
	Nod* getNext();
	Nod* getPrev();
	friend class Lista;
};


#endif
