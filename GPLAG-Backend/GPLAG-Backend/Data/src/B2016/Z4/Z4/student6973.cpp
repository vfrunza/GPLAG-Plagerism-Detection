/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
using namespace std;
struct Bazna {
virtual void f() { cout << 1; }
void g() { cout << 3; }
};
struct Izvedena : public Bazna {
virtual void f() { cout << 2; }
void g() { cout << 4; }
};
void p(Bazna b) {
b.f(); b.g();
}
void q(Bazna &b) {
b.f(); b.g();
}
int main ()
{
Bazna b;
Izvedena i;
Bazna *pb = new Bazna;
Bazna *pbi = new Izvedena;
Izvedena *pi = new Izvedena;
pb->f(); pb->g(); pbi->f(); pbi->g(); pi->f(); pi->g();
p(b); p(i); q(b); q(i);
return 0;
}