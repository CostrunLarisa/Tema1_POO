#ifndef LISTA_H
#define LISTA_H
#include "Nod.h"
#include<iostream>
using namespace std;
class Lista
{
	Nod* start;
	int size;
public:
	Lista();		//constructor pentru un obiect de tip lista fara parametri
	Lista(int);		//constructor pentru un obiect de tip lista cu parametri
	Lista(const Lista&);		//constructor de copiere
	int getSize();		//determinarea lungimii listei
	void inserare(int,int); //inserarea unui element x pe pozitia i
	void remove(int);		//stergerea unui element x din lista
	void reverse();				//inversarea elementelor din lista
	int suma();		            //suma elementelor din lista
	int elemMinim();            //
	int elemMaxim();
	int cautare(int);			//cauta elementul x si returneaza pozitia pe care il gaseste	//
	Lista& operator=(const Lista&);	//supraincarcarea operatorului =
	int operator[](int);		//supraincararea operatorului []
	Lista operator +(Lista&);		//supraincarcarea operatorului +
	bool operator >(Lista&);
	bool operator <(Lista&);		//supraincarcarea operatorilor <,> pentru compararea a doua liste
	Lista& operator*(const int);                  //supraincarcarea operatorului * pentru inmultirea cu un scalar
	friend istream& operator >>(istream&, Lista&);			//supraincarcarea operatorului de citire
	friend ostream& operator <<(ostream&,const Lista&);			//supraincarcarea operatorului de afisare
	~Lista();	//destructorul
};

#endif
