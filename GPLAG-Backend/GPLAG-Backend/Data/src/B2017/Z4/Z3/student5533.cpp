/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>

class Datum
{
    int dan, mjesec, godina;
public:
    Datum (int d, int m, int g) {
        int niz [12]= {31,28,31,30,31,30,31,31,30,31,30,31};
        if (g%4==0 && (g%100!=0 || g%400==0)) {
            niz[1]++;
        }
        if (d<1 || d>niz[m-1] || m<1 || m>12 || g<1) {
            throw std::domain_error ("Neispravan datum");
        }
        Postavi (d,m,g);
    }
    void Postavi (int d, int m, int g);
    std::tuple <int, int, int> Ocitaj () const {
        std::tuple <int, int, int> t(dan,mjesec,godina);
        return t;
    }
    void Ispisi () const {
        std::cout <<dan<<"/"<<mjesec<<"/"<<godina;
    }
};
void Datum::Postavi (int d, int m, int g)
{
    int niz [12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if (g%4==0 && (g%100!=0 || g%400==0)) {
        niz[1]++;
    }
    if (d<1 || d>niz[m-1] || m<1 || m>12 || g<1) {
        throw std::domain_error ("Neispravan datum");
    }
    Datum::dan=d;
    Datum::mjesec=m;
    Datum::godina=g;
}
class Vrijeme {
    Vrijeme (int s, int m) {
        if (s>23 || s<0 || m>59 || m<0) throw std::domain_error ("Neispravno vrijeme");
        sati=s; minute=m;
    }
    void Postavi(int s, int m) {
        if (s>23 || s<0 || m>59 || m<0) throw std::domain_error ("Neispravno vrijeme");
        sati=s; minute=m;
    }
    void Ispisi() const {
        if (sati<10) std::cout<<"0";
        std::cout <<sati<<":";
        if (minute<10) std::cout <<"0";
        std::cout<<minute;
    }
};
class Pregled {
    
};
int main ()
{
    return 0;
}
