#include"Lista.h"
#include "Nod.h"
#include<iostream>
using namespace std;

Lista::Lista() :start(NULL), size(0){}          //constructorul pentru un obiect de tip Lista fara parametri
Lista::Lista(int x)                             //constructorul pentru un obiect de tipa Lista cu un singur element
{
    start=new Nod(x, NULL,NULL);           //construim nodul start,care nu are vecini,prin urmare,next=NULL & prev=NUL
    size = 1;
}
Lista::Lista(const Lista& l)                    //constructor de copiere
{
    start = NULL;               //initializam obiectul curent drept fiind vid
    size = 0;
    Nod* p = l.start;
    while (p->getNext() != l.start)         //incepem sa copiem element cu element
    {
        inserare(size, p->getInfo());
        p = p->getNext();
    }
    inserare(size,p->getInfo());
}

 int Lista::getSize()
{
    int lungime=1;                      //initializam lungimea cu 1
    Nod* p = start;
    if (start == NULL)                  //lista este vida
        return 0;
    if (start->getNext() == NULL)      //lista are doar un element
        return 1;
    else                              //altfel,daca are mai mult de un element,iteram prin lista pana ajungem la start
    {
        p = p->getNext();               //deoarece am verificat daca lista are mai mult de un element putem sa trecem la urmatorul nod,lungimea fiind deja=1
        while (p != start)
        {
            p = p->getNext();
            lungime++;
        }

        return lungime;
    }

}

void Lista::inserare(int i,int x)
{    if (size == 0)             //in cazul in care lista este vida
    {
        start = new Nod(x, NULL, NULL);
        size = 1;
    }
    else if(size==1 && i!=0)            //in cazul in care lista are un element si nis e cere o pozitie mai mare sau mai mica de 0
    {

        Nod* q = new Nod(x,start,start);
        start->setPrev(q);
        start->setNext(q);
        size++;

    }
    else if(i==0 && size==1)        //daca trebuie sa inseram pe prima pozitie si avem un element
    {   Nod* p=start;
        Nod* q = new Nod(x,p,p);
        p->setPrev(q);
        p->setNext(q);
        start=q;
        size++;
    }
    else if (i == 0 && size>1)      //daca trebuie sa inseram pe prima pozitie,insa avem mai multe elemente
    {
        Nod* p = start;
        Nod* m = start->getPrev();
        Nod* q = new Nod;
        q->setInfo(x);
        q->setNext(start);
        q->setPrev(m);
        p->setPrev(q);
        m->setNext(q);
        start = q;
        size++;
    }
    else if (i == size || i >=size )
    {
        Nod* q = new Nod(x, start, start->getPrev());       //cream un nou nod care pointeaza catre urmatorul element(start),retine intregul x si are ca vecin prev pe vecinul prev al lui start
        size++;   //inseram un element,marim dimensiunea listei
        Nod* m = start->getPrev();
        m->setNext(q);      //ultimul element nu va mai pointa catre start,ci catre nodul q,care va fi acum ultimul element
        start->setPrev(q);
    }

    else
    {
        int j = 1;
        Nod* p = start;
        while (j != i)
        {
            j++;
            p = p->getNext();
        }
        Nod* m = p->getNext();
        Nod* q = new Nod(x, m, p);
        size++;
        p->setNext(q);
        m->setPrev(q);
    }
}
int Lista::operator[](int i)
{
    int contor = 0;                   //ne luam un contor care porneste de la 0(indexarea incepe de la 0 in lista) si parcurgem lista pana cand contor==i.Cand am ajuns la pozitia ceruta returnam valoarea din nodul in care am ajuns
    Nod* p = start;
    if (contor == i)                    //daca ni se cere chiar elementul de pe pozitia 0 sau daca ni se cere o pozitie negativa atunci vorm returna primul element din lista
    {
        int valoare = start->getInfo();
        return valoare;
    }
    if (i >= size || contor > i)        //daca pozitia dorita este mai mare decat lungimea listei sau daca este un nr.negativ vom returna -1
            return -1;
    else                                     //in caz contrar mergem prin lista pana cand contor=i
        {
            while (contor != i)
            {
                contor++;
                p = p->getNext();
            }
            int a = p->getInfo();
            return a;
       }

}
int Lista::cautare(int x)           //functia returneaza prima pozitie pe care a fost gasit elementul x
{  Nod* p=start;

    if(p!=NULL)
        {
            for (int i = 0; i < getSize(); i++)
            {   if(p->getInfo()==x)
                    return i;                   //in cazul in care nr. se afla in lista returnam pozitia
                p=p->getNext();
            }
          return -1;                //in cazul in care nu gasim elementul;
        }
    return p->getInfo();            //Lista este vida,dorim sa generam o eroare,deoarece nu putem cauta un element intr-o lista goala
}
void Lista::remove(int x)
{
    int i=cautare(x);

    if (i!=-1)              //realizam stergerea atata timp cat elementul exista inlista
    {
        if(size==1)         //daca este singurul element atuncilista devine vida
        {
            Nod *p=start;
            delete p;
            start=NULL;
            size=0;
        }
        else if(i==0)           //caz particular daca avem de sters primul element
        {
            Nod* p=start;
            Nod* q=p->getNext();
            Nod* m=p->getPrev();
            q->setPrev(start->getPrev());
            m->setNext(q);
            delete p;
            start=q;
            size--;
        }
        else if(i==size-1)              //caz particular,stergerea ultimului element
        {
            Nod* ob=start->getPrev();
            Nod* q=ob->getPrev();
            q->setNext(start);
            start->setPrev(q);
            delete ob;
            size--;

        }
        else{
             Nod *p=start;
            int j=0;
            while(j!=i)
            {
                p=p->getNext();
                j++;
            }
            Nod* ob=p;
            Nod* q=ob->getNext();
            Nod* m=ob->getPrev();
            q->setPrev(start->getPrev());
            m->setNext(q);
            delete ob;
            size--;
         }

    }
}
int Lista::elemMaxim()
{   int maxim;
   if (size==0)
        return start->getInfo();
    if (size == 1)
        return start->getInfo();
    else if (size > 1)
    {
        Nod* p=start;
        maxim=p->getInfo();
        p=p->getNext();
        for(int i=1;i<size;i++)
        {
            if(p->getInfo()>maxim)
                maxim=p->getInfo();
            p=p->getNext();
        }
    }
    return maxim;
}
int Lista::elemMinim()
{   int minim;
    if (size==0)
        return start->getInfo();        //daca lista este vida simulam o eroare
    if (size == 1)
        return start->getInfo();           //daca lista are un element atunci el este si minim si maxim
    else if (size > 1)
    {
        Nod* p=start;
        minim=p->getInfo();
        p=p->getNext();
        for(int i=1;i<size;i++)     //in caz contrar iteram pentru a gasi minimul
        {
            if(p->getInfo()<minim)
                minim=p->getInfo();
            p=p->getNext();
        }
    }
    return minim;
}
istream& operator >>(istream& in,Lista& l)
{
    int n;
    int x;
    in >>n ;
    for (int i = 0; i <n; i++)
    {
        in >> x;
        l.inserare(i, x);
    }
    return in;
}
ostream& operator <<(ostream& out,const Lista& l)
{
    Nod* p=l.start;
    if (p==NULL)
    {
        out<<"Lista este vida";
    }

    else if( p!=NULL)
     {
         out<<p->getInfo()<<" ";
        p=p->getNext();
          while(p!=l.start && p!=NULL)
        {
            out<<p->getInfo()<<" ";
            p=p->getNext();
        }
     }
 return out;
}
int Lista::suma()
{
    int suma = 0;
    Nod* p=start;
    if(p!=NULL)                     //daca lista nu este vida calculam suma
     {
         for (int i = 0; i < getSize(); i++)
            {
                    suma+=p->getInfo();
                    p=p->getNext();
            }
        return suma;
    }
    return -1;   //in caz contrar returnam -1
}
bool Lista ::operator >(Lista& l)
{
    if(suma()>l.suma())
        return 1;
    return 0;
}
bool Lista::operator <(Lista&l)
{
    if(suma()<l.suma())
        return 1;
    return 0;
}
Lista& Lista::operator=(const Lista& l)
{
    if(this!= &l)                           //daca obiectele noastre sunt diferite(nu au aceeasi adresa,i.e incercam sa evitam cazul ob=ob)
    {   this->~Lista();                     //stergem ce este in obiectul curent
       Nod* aux=l.start;
        int iterator=0;
        while(iterator<l.size)              //copiem toata informatia din obiectul l in obiectul curent
        {
            inserare(iterator,aux->info);
            aux=aux->getNext();
            iterator++;
        }
        size=l.size;
    }
    return *this;
}
Lista Lista::operator+(Lista& l)
{

    if((l.size==0 && size==0) || (l.size>0 && size==0))   //in cazul in care obiectul de tip lista l si ob sunt liste vide sau doar ob este vida,returnam l
        return l;
    if(l.size==0 && size>0)          //daca l nu are elemente,dar celalalt are,returnam direct obiectul cu elemente fara a mai face vreo reuniune
        return *this;
    Lista rezultat(l);
    Nod* p=this->start;
    for(int i=0;i<size;i++)
        {
            rezultat.inserare(rezultat.size+1,p->getInfo());
            p=p->next;
        }

    return rezultat;
}
Lista& Lista::operator*(const int x)
{   if(size==0)
        return *this;               //daca lista este vida returnam obiectul
    if(size==1)                      //daca lista are un singur element,atunci vom efectua o singura inmultirea,cea a informatiei din nodul start cu scalarul
     {
         int i=start->getInfo();
         start->setInfo(i*x);
         return *this;
     }
    Nod *p=start->getNext();        //in cazul in care lungimea listei>1,atunci valoarea din fiecare nod av fi inmultita cu scalarul
    int i=start->getInfo();
    start->setInfo(i*x);
    for(int i=1;i<size;i++)
    {
            int i=p->getInfo();     //preluam informatia curenta din fiecare nod
            p->setInfo(i*x);        //setam noua informatie,i.e :valoare veche * scalarul
            p=p->getNext();
    }
    return *this;                   //returnam obiectul modificat
}
void Lista::reverse()
{   if(size>1)                          //facem modificari obiectului atata timp cat are mai mult de un element
    {
        Nod* p=start;
        Nod* q=start->getPrev();
        int val1=start->getInfo();          //iterschimbam valorile dintre primul nod si ultimul nod
        int val2=q->getInfo();
        start->setInfo(val2);
        q->setInfo(val1);
        p=p->getNext();                     //iteram cu un nod de la inceput si cu unul de la final
        q=q->getPrev();
        for(int i=1;i<size/2;i++)           //pentru optimizare parcurgem lista pana la jumatate
        {
                int val1=p->getInfo();
                int val2=q->getInfo();
                p->setInfo(val2);
                q->setInfo(val1);
                p=p->getNext();
                q=q->getPrev();
        }
    }


}
Lista::~Lista() {                   //destructorul

    if(start==NULL)         //daca lista este vida nu mai apelam destructorul
        return;
    Nod* p = start->getNext();
    if (p == NULL)     //daca aveam doar un element
    {
        Nod* q = p;
        delete q;
        start = NULL;
        size = 0;

    }
    while ( p!= start) {
        Nod* q = p;
        p = p->getNext();
        delete q;
    }
    Nod* q = p;
    delete q;
    start = NULL;
    size = 0;
}
