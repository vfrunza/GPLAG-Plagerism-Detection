/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

class Razlomak
{
    long long int brojnik, nazivnik;
    static int NZD(long long int x, long long int y) {
        long long int nzd=1;
        if(fabs(x)>=fabs(y) && fabs(y)>=2) {
            for(int i=2; i<=y; i++) {
                if(x%i==0 && y%i==0) nzd=i;
            }
        }
        if(fabs(y)>=fabs(x) && fabs(x)>=2) {
            for(int i=2; i<=x; i++) {
                if(x%i==0 && y%i==0) nzd=i;
            }
        }
        return nzd;
    }
public:
    Razlomak(long long int p, long long int q) {
        if(q==0) throw std::logic_error ("Nekorektan razlomak");

        long long int n=NZD(p,q);
        if(n!=1) {
            p/=n;
            q/=n;
        }
        brojnik=p;
        nazivnik=q;
        if(q<0) {
            nazivnik*=-1;
            brojnik*=-1;
        }
    }
    Razlomak(long long int p) {
        brojnik=p;
        nazivnik=1;
    }
    Razlomak() {
        brojnik=0;
        nazivnik=1;
    }
    long long int DajBrojnik()const {
        return brojnik;
    }
    long long int DajNazivnik()const {
        return nazivnik;
    }
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &R);

    friend std::istream &operator >>(std::istream &tok,  Razlomak &R);

    friend Razlomak operator *(Razlomak a, Razlomak b) ;
    friend Razlomak operator +(Razlomak a, Razlomak b) ;

    friend Razlomak operator -(Razlomak a, Razlomak b);

    friend Razlomak operator /(Razlomak a, Razlomak b);
    operator long double()const {

        return (long double)brojnik/nazivnik;
    }

};

int NZD(long long int x, long long int y)
{
    long long int nzd=1;
    if(fabs(x)>=fabs(y) && fabs(y)>=2) {
        for(int i=2; i<=y; i++) {
            if(x%i==0 && y%i==0) nzd=i;
        }
    }
    if(fabs(y)>=fabs(x) && fabs(x)>=2) {
        for(int i=2; i<=x; i++) {
            if(x%i==0 && y%i==0) nzd=i;
        }
    }
    return nzd;
}
Razlomak operator -(Razlomak a, Razlomak b)
{
    Razlomak c;
    c.brojnik=a.DajBrojnik()*(b.DajNazivnik()/NZD(a.DajNazivnik(),b.DajNazivnik()))-b.DajBrojnik()*(a.DajNazivnik()/NZD(a.DajNazivnik(),b.DajNazivnik()));
    c.nazivnik=a.DajNazivnik()*(b.DajNazivnik()/NZD(a.DajNazivnik(),b.DajNazivnik()));
    long long int n=NZD(c.brojnik,c.nazivnik);
    if(n!=1) {
        c.brojnik/=n;
        c.nazivnik/=n;
    }
    if(c.nazivnik<0) {
        c.nazivnik*=-1;
        c.brojnik*=-1;
    }
    return c;
}
Razlomak operator +(Razlomak a, Razlomak b)
{
    Razlomak c;
    c.brojnik=a.DajBrojnik()*(b.DajNazivnik()/NZD(a.DajNazivnik(),b.DajNazivnik()))+b.DajBrojnik()*(a.DajNazivnik()/NZD(a.DajNazivnik(),b.DajNazivnik()));
    c.nazivnik=a.DajNazivnik()*(b.DajNazivnik()/NZD(a.DajNazivnik(),b.DajNazivnik()));
    long long int n=NZD(c.brojnik,c.nazivnik);
    if(n!=1) {
        c.brojnik/=n;
        c.nazivnik/=n;
    }
    if(c.nazivnik<0) {
        c.nazivnik*=-1;
        c.brojnik*=-1;
    }
    return c;
}
Razlomak operator *(Razlomak a, Razlomak b)
{
    Razlomak c;
    c.brojnik=(a.DajBrojnik()/NZD(a.DajBrojnik(), b.DajNazivnik()))*(b.DajBrojnik()/NZD(b.DajBrojnik(), a.DajNazivnik()));
    c.nazivnik=(a.DajNazivnik()/NZD(b.DajBrojnik(), a.DajNazivnik()))*(b.DajNazivnik()/NZD(a.DajBrojnik(), b.DajNazivnik()));
    long long int n=NZD(c.brojnik,c.nazivnik);
    if(n!=1) {
        c.brojnik/=n;
        c.nazivnik/=n;
    }
    if(c.nazivnik<0) {
        c.nazivnik*=-1;
        c.brojnik*=-1;
    }
    return c;

}
std::istream &operator >>(std::istream &tok,  Razlomak &R)
{
    char znak;
    tok>>std::ws;
    tok>> R.brojnik;
    if(tok.peek()!='/') {
        R.nazivnik=1;
    } else {
        tok >> znak>>R.nazivnik;

        if(tok.peek()!=' ') {
            tok.setstate(std::ios::failbit);
        }

        long long int n=NZD(R.brojnik,R.nazivnik);
        if(n!=1) {
            R.brojnik/=n;
            R.nazivnik/=n;
        }
        if(R.nazivnik<0) {
            R.nazivnik*=-1;
            R.brojnik*=-1;
        }
        R=Razlomak(R. brojnik,R.nazivnik);
    }

    return tok;
}
std::ostream &operator <<(std::ostream &tok, const Razlomak &R)
{

    if(R.DajBrojnik()==0)return tok<< R.DajBrojnik();
    if(R.DajBrojnik()!=0 && R.DajNazivnik()==1)return tok<< R.DajBrojnik();
    return tok<< R.DajBrojnik()<<"/"<<R.DajNazivnik();
}
Razlomak operator /(Razlomak a, Razlomak b)
{
    Razlomak c;
    c.brojnik=(a.DajBrojnik()/Razlomak::NZD(a.DajBrojnik(), b.DajBrojnik()))*(b.DajNazivnik()/Razlomak::NZD(a.DajNazivnik(),b.DajNazivnik()));
    c.nazivnik=(a.DajNazivnik()/Razlomak::NZD(a.DajNazivnik(),b.DajNazivnik()))*(b.DajBrojnik()/Razlomak::NZD(a.DajBrojnik(), b.DajBrojnik()));

    long long int n=Razlomak::NZD(c.brojnik,c.nazivnik);
    if(n!=1) {
        c.brojnik/=n;
        c.nazivnik/=n;
    }
    if(c.nazivnik<0) {
        c.nazivnik*=-1;
        c.brojnik*=-1;
    }
    return c;

}
int main ()
{
    return 0;
}