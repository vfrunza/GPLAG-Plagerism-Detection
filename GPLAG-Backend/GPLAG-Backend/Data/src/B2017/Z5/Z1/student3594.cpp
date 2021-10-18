/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
struct Kalamuta {
virtual int foo() const { return 5;}
long int bar () { return 4;}
virtual int baz() const { return 3;}
virtual ~Kalamuta() {}
};
struct Cincozna : public Kalamuta {
int foo() const { return 6;}
long bar () { return 8;}
virtual int baz() { return 12;}
};
int main() {
Kalamuta *pk = new Kalamuta, *ck = new Cincozna;
Cincozna *cc = new Cincozna;
std::cout << pk->foo() << " " << pk->bar() << " " << pk->baz() << std::endl;
std::cout << ck->foo() << " " << ck->bar() << " " << ck->baz() << std::endl;
std::cout << cc->foo() << " " << cc->bar() << " " << cc->baz() << std::endl;
delete pk; delete cc; delete ck;
return 0;
}