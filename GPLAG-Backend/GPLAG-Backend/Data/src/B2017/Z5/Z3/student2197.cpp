/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
class Datum{
    int dan, mjesec, godina;
public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

Datum(int d, int m, int g){
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && (g%100!=0 || g%400==0)) broj_dana[1]++;
    if(d<1 || g<1 || m<1 || m>12 || d>broj_dana[m-1] || g<1800)  throw std::domain_error("Nelegalan datum");
    dan=d;
    mjesec=m;
    godina=g;
}
    Datum(Mjeseci d, Mjeseci  m, Mjeseci g){
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(int(g)%4==0 && (int(g) % 100!=0 || int(g)%400==0)) broj_dana[1]++;
    if(int(d) <1 || int(g) <1 || int(m)<1 || int(m) >12 || d>broj_dana[m-1] || g<1800)  throw std::domain_error("Nelegalan datum");
    dan=d;
    mjesec=m;
    godina=g;
}

void Postavi(int d, int m, int g){
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && (g%100!=0 || g%400==0)) broj_dana[1]++;
    if(d<1 || g<1 || m<1 || m>12 || d>broj_dana[m-1] || g<1800)  throw std::domain_error("Nelegalan datum");
    dan=d;
    mjesec=m;
    godina=g;
}

int DajDan() const { return dan; }
Datum DajMjesec() const { return Mjeseci; }
int DajGodinu() const { return godina; }
char* DajImeMjeseca(Mjesec m) const { return m; }
int DanUSedmici() const { int d; return d; }

Dani DajImeDanaUSedmici() { Dani(d); return d; }

    

};


int main ()
{
	return 0;
}
