/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>

class Razlomak{
    long long int brojnik, nazivnik;
    static long long int NadjiNajmanjiZajednicki(long long int br, long long int naz){
        if(naz==0) return naz;
        br%=naz;
        return NadjiNajmanjiZajednicki(naz, br);
    }
     
public:

    Razlomak(long long int BROJNIK, long long int NAZIVNIK){
        if(NAZIVNIK==0) throw std::logic_error("Nekorektan razlomak");
        NadjiNajmanjiZajednicki(BROJNIK, NAZIVNIK);
        if(BROJNIK>0 && NAZIVNIK<0) {
            Razlomak::brojnik=-BROJNIK; Razlomak::nazivnik=std::abs(NAZIVNIK);
        }
        if(BROJNIK<0 && NAZIVNIK<0){
            Razlomak::brojnik=std::abs(BROJNIK); Razlomak::nazivnik=std::abs(NAZIVNIK);
        }
        else{
            Razlomak::brojnik=BROJNIK; Razlomak::nazivnik=NAZIVNIK;
        }
    }
    Razlomak(long long int BR){ Razlomak::brojnik=BR; Razlomak::nazivnik=1; }
    Razlomak(){ Razlomak::brojnik=0; Razlomak::nazivnik=1; }
    
    long long int DajBrojnik() const{ return brojnik; }
    long long int DajNazivnik() const{ return nazivnik; }
    operator long double() const;
   
    friend Razlomak operator +(const Razlomak &p, const Razlomak &q);
    friend Razlomak operator -(const Razlomak &p, const Razlomak &q);
    friend Razlomak operator *(const Razlomak &p, const Razlomak &q);
    friend Razlomak operator /(const Razlomak &p, const Razlomak &q);

    friend Razlomak &operator +(Razlomak &p){ return p; }
    friend Razlomak &operator -(Razlomak &p){ return -p; }
    friend Razlomak &operator +=(Razlomak &p, const Razlomak &q);
    friend Razlomak &operator -=(Razlomak &p, const Razlomak &q);
    friend Razlomak &operator *=(Razlomak &p, const Razlomak &q);
    friend Razlomak &operator /=(Razlomak &p, const Razlomak &q);
    
    friend Razlomak &operator ++(Razlomak &p){
        p+=1;
        return p;
    }
    friend Razlomak operator ++(Razlomak &p, int){
        Razlomak pom(p);
        pom+=1;
        return pom;
    }
    friend Razlomak &operator --(Razlomak &p){
        p-=1;
        return p;
    }
    friend Razlomak operator --(Razlomak &p, int){
        Razlomak pom(p);
        pom-=1;
        return pom;
    }
    
    friend bool operator ==(const Razlomak &p, const Razlomak &q);
    friend bool operator !=(const Razlomak &p, const Razlomak &q);
    friend bool operator <(const Razlomak &p, const Razlomak &q);
    friend bool operator >(const Razlomak &p, const Razlomak &q);
    friend bool operator <=(const Razlomak &p, const Razlomak &q);
    friend bool operator >=(const Razlomak &p, const Razlomak &q);
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &p);
    friend std::istream &operator >>(std::istream &tok, Razlomak &p);
    
};
    Razlomak operator /(const Razlomak &p, const Razlomak &q){
        auto r(Razlomak::NadjiNajmanjiZajednicki(p.nazivnik, q.nazivnik));
        auto u(Razlomak::NadjiNajmanjiZajednicki(p.brojnik, q.brojnik));
        return ((p.brojnik/u)*(q.nazivnik/r))/((p.nazivnik/r)*(q.brojnik/u));
    }
    
    Razlomak operator *(const Razlomak &p, const Razlomak &q){
        auto s(Razlomak::NadjiNajmanjiZajednicki(p.brojnik, q.nazivnik));
        auto t(Razlomak::NadjiNajmanjiZajednicki(q.brojnik, p.nazivnik)); 
        
        return ((p.brojnik/s)*(q.brojnik/t))/((p.nazivnik/t)*(q.nazivnik/s));
    } 
    
    Razlomak operator -(const Razlomak &p1, const Razlomak &p2){
        auto r(Razlomak::NadjiNajmanjiZajednicki(p1.nazivnik, p2.nazivnik));
        long long int br(p1.brojnik*int(p2.nazivnik/r) - p2.brojnik*int(p1.nazivnik/r)), naz(p1.nazivnik*int(p2.nazivnik/r));
        Razlomak PomRazlomak(br, naz);
        return  PomRazlomak;
    }
    
    Razlomak operator +(const Razlomak &p1, const Razlomak &p2){
        auto r(Razlomak::NadjiNajmanjiZajednicki(p1.nazivnik, p2.nazivnik));
        long long int br(p1.brojnik*int(p2.nazivnik/r) + p2.brojnik*int(p1.nazivnik/r)), naz(p1.nazivnik*int(p2.nazivnik/r));
        Razlomak PomRazlomak(br, naz);
        return  PomRazlomak;
    }

    Razlomak &operator +=(Razlomak &p, const Razlomak &q){ p=p+q; return p; }
    Razlomak &operator -=(Razlomak &p, const Razlomak &q){ p=p-q; return p; }
    Razlomak &operator *=(Razlomak &p, const Razlomak &q){ p=p*q; return p; }
    Razlomak &operator /=(Razlomak &p, const Razlomak &q){ p=p*q; return p; }
    
    
    bool operator == (const Razlomak &p, const Razlomak &q){
        return (long double) p.brojnik/p.nazivnik == (long double) q.brojnik/q.nazivnik;
    }
    
    bool operator !=(const Razlomak &p, const Razlomak &q){
        return !(p==q);
    }
    
    bool operator <(const Razlomak &p, const Razlomak &q){
        return (long double) p.brojnik/p.nazivnik < (long double) q.brojnik/q.nazivnik;        
    }
    
    bool operator >(const Razlomak &p, const Razlomak &q){
         return (long double) p.brojnik/p.nazivnik > (long double) q.brojnik/q.nazivnik;       
    }
    
    bool operator <=(const Razlomak &p, const Razlomak &q){
         return (long double) p.brojnik/p.nazivnik <= (long double) q.brojnik/q.nazivnik;       
    }
    
    bool operator >=(const Razlomak &p, const Razlomak &q){
         return (long double) p.brojnik/p.nazivnik >= (long double) q.brojnik/q.nazivnik;       
    }   
    
    std::ostream &operator <<(std::ostream &tok, const Razlomak &p){
        if(p.nazivnik==1) return tok<<p.brojnik;
        return tok<<p.brojnik<<"/"<<p.nazivnik;
    }
    
    std::istream &operator >>(std::istream &tok, Razlomak &p){
        char znak;
        tok>>p.brojnik;
        if(tok.peek()!= '/'){
            p.nazivnik=1;
        }
        else{
            tok>>znak>>p.nazivnik;
            if(!p.brojnik || !p.nazivnik) tok.setstate(std::ios::failbit);
        }
    }
    
    Razlomak::operator long double() const{ return (long double) brojnik/nazivnik; }
    
int main ()
{
    Razlomak r(2337, 3740), q (4014, 5225);
    std::cout << r << " + " << q << " = " << r + q;
	
	return 0;
}