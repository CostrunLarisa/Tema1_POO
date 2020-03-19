#include "Nod.h"
#include <iostream>
using namespace std;
Nod::Nod():info(0),next(NULL),prev(NULL){}
Nod::Nod(int i, Nod* n,Nod*q) : info(i), next(n),prev(q) {}
void Nod::setInfo(int i) { info = i; }
void Nod::setNext(Nod* n) { next = n; }
void Nod::setPrev(Nod* n) { prev=n; }
int Nod::getInfo() {
	return info;
}
Nod* Nod::getNext() {
	return next;
}
Nod* Nod::getPrev() {
	return prev;
}
