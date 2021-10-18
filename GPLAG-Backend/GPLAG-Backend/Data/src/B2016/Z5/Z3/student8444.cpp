/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <limits>
#include <stdexcept>
#include <math.h>
#include <algorithm>
#define epslinon 0.0000000001

class Razlomak{
    long long int brojnik;
    long long int nazivnik;
    const static long long int m=std::numeric_limits<long long int>::min();//najmanja vrijednost long long inta
    const static long long int M=std::numeric_limits<long long int>::max();//najveca vrijednost long long inta
    static long long int NZD(long long int p, long long int q){
        if(p<q) std::swap(p, q);
        while(q!=0){
            long long int pomocni1,pomocni2;//ovi pomocni su prelazni koraci
            pomocni1=p;
            pomocni2=q;
            p=pomocni2;
            q=pomocni1%pomocni2;
        }
        return p;
    }
    static void PrekoracenjeZaSabiranje(long long int x, long long int y){
        if(y>0){
            if(x>M-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
        else if(y<0){
            if(x<m-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    static void PrekoracenjeZaOduzimanje(long long int x, long long int y){
        long long int y1=y*(-1);
        PrekoracenjeZaSabiranje(x,y1);
    }
    static void PrekoracenjeZaMnozenje(long long int x, long long int y){
        if(y>0){
            if(x<m/y || x>M/y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
        else if(y<0){
            if(x==m || x*(-1)> M/(y*(-1)) || x*(-1)<m/(y*(-1))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    public:
    Razlomak(long long brojnik=0, long long nazivnik=1){
        if(nazivnik<0 && (brojnik>0 || brojnik<0)) {
            brojnik*=-1;
            nazivnik*=-1;
        }
        if(nazivnik==0) throw std::logic_error("Nekorektan razlomak");
        long long int nzd=NZD(brojnik,nazivnik);
        brojnik/=nzd;
        nazivnik/=nzd;
        this->brojnik=brojnik;
        this->nazivnik=nazivnik;
    }
    
    Razlomak(const Razlomak &r){
        this->brojnik=r.brojnik;
        this->nazivnik=r.nazivnik;
    }
    
    Razlomak &operator= (const Razlomak &r){
        this->brojnik=r.brojnik;
        this->nazivnik=r.nazivnik;
        return *this;
    }
    
    Razlomak &operator= (Razlomak &&r){
        this->brojnik=r.brojnik;
        this->nazivnik=r.nazivnik;
        return *this;
    }
    
    long long int DajBrojnik(){ return brojnik;}
    long long int DajNazivnik(){ return nazivnik;}
    
     
    friend Razlomak operator+(const Razlomak &r1, const Razlomak &r2){
        auto nzd=NZD(r1.nazivnik, r2.nazivnik);
        PrekoracenjeZaMnozenje(r1.brojnik, r2.nazivnik/nzd);
        PrekoracenjeZaMnozenje(r1.nazivnik,r2.nazivnik/nzd);
        PrekoracenjeZaMnozenje(r2.brojnik, r1.nazivnik/nzd);
        PrekoracenjeZaSabiranje(r1.brojnik*(r2.nazivnik/nzd), r2.brojnik*(r1.nazivnik/nzd));
        long long int naziv=r1.nazivnik*(r2.nazivnik/nzd);
        long long int broj=r1.brojnik*(r2.nazivnik/nzd) + r2.brojnik*(r1.nazivnik/nzd);
        Razlomak vrati(broj,naziv);
        return vrati;
    }
    
    
    friend Razlomak operator-(const Razlomak &r1, const Razlomak &r2){
        auto nzd=NZD(r1.nazivnik, r2.nazivnik);
        PrekoracenjeZaMnozenje(r1.brojnik, r2.nazivnik/nzd);
        PrekoracenjeZaMnozenje(r1.nazivnik,r2.nazivnik/nzd);
        PrekoracenjeZaMnozenje(r2.brojnik, r1.nazivnik/nzd);
        PrekoracenjeZaOduzimanje(r1.brojnik*(r2.nazivnik/nzd), r2.brojnik*(r1.nazivnik/nzd));
        long long int naziv=r1.nazivnik*(r2.nazivnik/nzd);
        long long int broj=r1.brojnik*(r2.nazivnik/nzd) - r2.brojnik*(r1.nazivnik/nzd);
        Razlomak vrati(broj,naziv);
        return vrati;
    }
    
    friend Razlomak operator*(const Razlomak &r1, const Razlomak &r2){
        auto nzd1=NZD(r1.brojnik,r2.nazivnik);
        auto nzd=NZD(r2.nazivnik, r1.nazivnik);
        PrekoracenjeZaMnozenje(r1.brojnik/nzd1, r2.brojnik/nzd);
        PrekoracenjeZaMnozenje(r1.nazivnik/nzd,r2.nazivnik/nzd1);
        
        long long int naziv=(r1.nazivnik/nzd)*(r2.nazivnik/nzd1);
        long long int broj=(r1.brojnik/nzd1)*(r2.brojnik/nzd);
        Razlomak vrati(broj,naziv);
        return vrati;
    }
    friend Razlomak operator/(const Razlomak &r1, const Razlomak &r2){
        auto nzd1=NZD(r1.brojnik,r2.nazivnik);
        auto nzd=NZD(r1.nazivnik, r2.nazivnik);
        PrekoracenjeZaMnozenje(r1.brojnik/nzd1, r2.brojnik/nzd);
        PrekoracenjeZaMnozenje(r1.nazivnik/nzd,r2.brojnik/nzd1);
        
        long long int naziv=(r1.nazivnik/nzd)*(r2.brojnik/nzd1);
        long long int broj=(r1.brojnik/nzd1)*(r2.nazivnik/nzd);
        Razlomak vrati(broj,naziv);
        return vrati;
    }
    friend Razlomak operator ++(Razlomak &r1, int){
        auto vrati=r1;
        ++r1;
        return r1;
    }
    friend Razlomak operator --(Razlomak &r1, int){
        auto vrati=r1;
        --r1;
        return r1;
    }
    friend Razlomak &operator ++(Razlomak &r1){
        Razlomak r(1);
        r1+=r;
        return r1;
    }
    friend Razlomak &operator --(Razlomak &r1){
        Razlomak r(1);
        r1-=r;
        return r1;
    }
    
     friend Razlomak operator+=(Razlomak &r1, const Razlomak &r2){
        auto nzd=NZD(r1.nazivnik, r2.nazivnik);
        auto nzd1=NZD(r1.brojnik,r1.nazivnik);
        PrekoracenjeZaMnozenje(r1.brojnik, r2.nazivnik/nzd);
        PrekoracenjeZaMnozenje(r1.nazivnik,r2.nazivnik/nzd);
        PrekoracenjeZaMnozenje(r2.brojnik, r1.nazivnik/nzd);
        PrekoracenjeZaSabiranje(r1.brojnik*(r2.nazivnik/nzd), r2.brojnik*(r1.nazivnik/nzd));
        r1.brojnik=r1.brojnik*(r2.nazivnik/nzd)+r2.brojnik*(r1.nazivnik/nzd);
        r1.nazivnik=r1.nazivnik*(r2.nazivnik/nzd);
        r1.brojnik/=nzd1;
        r1.nazivnik/=nzd1;
        return r1;
        
    }
    
    friend Razlomak operator-=(Razlomak &r1, const Razlomak &r2){
        auto nzd=NZD(r1.nazivnik, r2.nazivnik);
        auto nzd1=NZD(r1.brojnik,r1.nazivnik);
        PrekoracenjeZaMnozenje(r1.brojnik, r2.nazivnik/nzd);
        PrekoracenjeZaMnozenje(r1.nazivnik,r2.nazivnik/nzd);
        PrekoracenjeZaMnozenje(r2.brojnik, r1.nazivnik/nzd);
        PrekoracenjeZaOduzimanje(r1.brojnik*(r2.nazivnik/nzd), r2.brojnik*(r1.nazivnik/nzd));
        r1.brojnik=r1.brojnik*(r2.nazivnik/nzd)+r2.brojnik*(r1.nazivnik/nzd);
        r1.nazivnik=r1.nazivnik*(r2.nazivnik/nzd);
        r1.brojnik/=nzd1;
        r1.nazivnik/=nzd1;
        return r1;
    }
    friend Razlomak operator*=(Razlomak &r1, const Razlomak &r2){
        auto nzd1=NZD(r1.brojnik,r2.nazivnik);
        auto nzd=NZD(r2.nazivnik, r1.nazivnik);
        auto nzd2=NZD(r1.brojnik, r1.nazivnik);
        PrekoracenjeZaMnozenje(r1.brojnik/nzd1, r2.brojnik/nzd);
        PrekoracenjeZaMnozenje(r1.nazivnik/nzd,r2.nazivnik/nzd1);
        r1.brojnik=(r1.brojnik/nzd1)*(r2.brojnik/nzd);
        r1.nazivnik=(r1.nazivnik/nzd)*(r2.nazivnik/nzd1);
        r1.brojnik/=nzd2;
        r1.nazivnik/=nzd2;
        return r1;
        
    }
    friend Razlomak operator/=(Razlomak &r1, const Razlomak &r2){
        auto nzd1=NZD(r1.brojnik,r2.nazivnik);
        auto nzd=NZD(r1.nazivnik, r2.nazivnik);
        auto nzd2=NZD(r1.brojnik, r1.nazivnik);
        PrekoracenjeZaMnozenje(r1.brojnik/nzd1, r2.brojnik/nzd);
        PrekoracenjeZaMnozenje(r1.nazivnik/nzd,r2.brojnik/nzd1);
        r1.brojnik=(r1.brojnik/nzd1)*(r2.brojnik/nzd);
        r1.nazivnik=(r1.nazivnik/nzd)*(r2.nazivnik/nzd1);
        r1.brojnik/=nzd2;
        r1.nazivnik/=nzd2;
        return r1;
    }
    friend bool operator< (const Razlomak &r1, const Razlomak &r2){
        long double razlomak1=r1.brojnik/r1.nazivnik;
        long double razlomak2=r2.brojnik/r2.nazivnik;
        if(razlomak1-razlomak2<epslinon) return true;
        return false;
    }
    friend bool operator >(const Razlomak &r1, const Razlomak &r2){
        long double razlomak1=r1.brojnik/r1.nazivnik;
        long double razlomak2=r2.brojnik/r2.nazivnik;
        if(razlomak1-razlomak2>epslinon) return true;
        return false;
    }
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2){
        long double razlomak1=r1.brojnik/r1.nazivnik;
        long double razlomak2=r2.brojnik/r2.nazivnik;
        if(fabs(razlomak1-razlomak2)<epslinon) return true;
        return false;
    }
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2){
        return (r1<r2 || r1==r2);
    }
     friend bool operator >=(const Razlomak &r1, const Razlomak &r2){
        return (r1>r2 || r1==r2);
    }
    
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2){
        return !(r1==r2);
    }
    
    friend std::ostream &operator<< (std::ostream &tok, const Razlomak &r){
        if(r.nazivnik==1) return tok<<r.brojnik;
        return tok<<r.brojnik<<"/"<<r.nazivnik;
    }
    friend std::istream &operator>>(std::istream &tok, Razlomak &r){
        return tok;
    }
    operator long double() const{
        return brojnik/(long double)nazivnik;
    }
    
    
    
};
int main ()
{
	return 0;
}