#include <iostream>
#include "Lista.h"
#include "Nod.h"
#include<cassert>
using namespace std;
int main()
{
    Lista l(2);
    l.inserare(0,40);
    l.inserare(1,10);
    l.inserare(40,22);
    l.inserare(3,-1);
    assert(l[0]==40);
    assert(l.getSize()==5);
    assert(l.elemMaxim()==40);
    assert(l.elemMinim()==-1);
    assert(l.cautare(22)==4);
    assert(l.suma()==73);
    Lista ob(2);
    assert(l>ob==1);
    assert(ob<l==1);
    l.remove(10);
    assert(l.cautare(10)==1); //apare eroare,ceea ce ne si doream,deoare ce 10 nu se mai afla in lista
    cout<<l;
    //Mai jos sunt cateva teste fara assert
    ob=l;
    ob.inserare(0,88);
    Lista n;
    Lista l2;
    l2=ob+l;
    l2.remove(22);
    Lista pa(12);
    pa.inserare(22,3);
    pa.inserare(77,2);
    pa*3;
    cout<<l<<"\n";
    l.reverse();
    Lista p;
    p.reverse();
    Lista ps(2);
    ps.inserare(0,9);
    ps.remove(2);
    ps.reverse();
    cout<<ps.cautare(2)<<'\n';
    ps.remove(2);
    cout<<ps.suma()<<'\n';
    cout<<ps;
    cout<<ps[2];
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
