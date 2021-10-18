/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <sstream>
class Razlomak {
    long long int brojnik;
    long long int nazivnik;
    static int nzd(long long int p, long long int q) {
        if(q==0) return p;
        p=p%q;
        return nzd(q,p);
    }
    public:
    Razlomak(long long int b, long long int n);
    Razlomak () { brojnik=0; nazivnik=1; }
    Razlomak(long long int x) { brojnik=x; nazivnik=1; }
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    friend std::ostream &operator <<(std::ostream &tok,const Razlomak &r);
    friend std::istream &operator>> (std::istream &tok,Razlomak &r);
    friend Razlomak operator+ (const Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator- (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator* (const Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator/ (const Razlomak &r1,const Razlomak &r2);
    Razlomak operator-() const { return {-brojnik,-nazivnik}; }
    friend Razlomak operator +(const Razlomak &r);
    Razlomak &operator+= (const Razlomak &r);
    Razlomak &operator-= (const Razlomak &r);
    Razlomak &operator*= (const Razlomak &r);
    //friend Razlomak &operator/= (const Razlomak &r);
    friend Razlomak &operator++ (Razlomak &r);
    //Razlomak operator++ (Razlomak &r);
    
};

Razlomak::Razlomak(long long int b, long long int n) {
    if(n==0) {
        throw std::logic_error("Nekorektan razlomak");
    }
    if(n<0) {
        b=b*(-1);
    }
    if(b<0 && n<0) {
        b*=(-1);
        n*=(-1);
    }
    b=b/nzd(b,n);
    n=n/nzd(b,n);
    brojnik=b;
    nazivnik=n;
}
std::ostream &operator <<(std::ostream &tok,const Razlomak &r) {
        if(r.nazivnik==1) {
            tok<<r.brojnik;
            return tok;
        }
        
        tok<<r.brojnik<<"/"<<r.nazivnik;
        return tok;
    }
std::istream &operator >>(std::istream &tok, Razlomak &r) {
    char znak;
    tok>>r.brojnik>>znak>>r.nazivnik;
    if(znak=='\n' || znak=='\r') {
        r.nazivnik=1;
        return tok;
    }
    if(znak!='/' || znak!=' ') {
        tok.setstate(std::ios::failbit);
    }
 int n=Razlomak::nzd(r.brojnik,r.nazivnik);
    r.brojnik/=n;
    r.nazivnik/=n;
 


  return tok;
  
}
Razlomak operator+ (const Razlomak &r1,const Razlomak &r2) {
    Razlomak r3;
    int r=Razlomak::nzd(r1.nazivnik,r2.nazivnik);
    r3.brojnik=r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r);
    r3.nazivnik=r1.nazivnik*(r2.nazivnik/r);
    int n=Razlomak::nzd(r3.brojnik,r3.nazivnik);
    r3.brojnik/=n;
    r3.nazivnik/=n;
    return r3;
}
Razlomak operator- (const Razlomak &r1,const Razlomak &r2) {
    Razlomak r3;
    int r=Razlomak::nzd(r1.nazivnik,r2.nazivnik);
    r3.brojnik=r1.brojnik*(r2.nazivnik/r)-r2.brojnik*(r1.nazivnik/r);
    r3.nazivnik=r1.nazivnik*(r2.nazivnik/r);
    int n=Razlomak::nzd(r3.brojnik,r3.nazivnik);
    r3.brojnik/=n;
    r3.nazivnik/=n;
    return r3;
} 
Razlomak operator* (const Razlomak &r1, const Razlomak &r2) {
    Razlomak r3;
    int s=Razlomak::nzd(r1.brojnik,r2.nazivnik);
    int t=Razlomak::nzd(r2.brojnik,r1.nazivnik);
    r3.brojnik=(r1.brojnik/s)*(r2.brojnik/t);
    r3.nazivnik=(r1.nazivnik/t)*(r2.nazivnik/s);
    int n=Razlomak::nzd(r3.brojnik,r3.nazivnik);
    r3.brojnik/=n;
    r3.nazivnik/=n;
    return r3;
    
}
Razlomak operator/ (const Razlomak &r1, const Razlomak &r2) {
    Razlomak r3;
    int r=Razlomak::nzd(r1.nazivnik,r2.nazivnik);
    int u=Razlomak::nzd(r1.brojnik,r2.brojnik);
    r3.brojnik=(r1.brojnik/u)*(r2.nazivnik/r);
    r3.nazivnik=(r1.nazivnik/r)*(r2.brojnik/u);
    int n=Razlomak::nzd(r3.brojnik,r3.nazivnik);
    r3.brojnik/=n;
    r3.nazivnik/=n;
    return r3;
}
Razlomak operator +(const Razlomak &r)  {
     Razlomak r1(r);
     +r.brojnik; 
     +r.nazivnik;
     return r1;
}
Razlomak &Razlomak::operator+= (const Razlomak &r) {
    brojnik+=r.brojnik;
    nazivnik+=r.nazivnik;
    return *this;
}
Razlomak &Razlomak::operator-= (const Razlomak &r) {
    brojnik-=r.brojnik;
    nazivnik-=r.nazivnik;
    return *this;
}
Razlomak &Razlomak::operator*= (const Razlomak &r) {
    brojnik*=r.brojnik;
    nazivnik*=r.nazivnik;
    return *this;
}
/*Razlomak &Razlomak::operator/= (const Razlomak &r) {
    brojnik/=r.brojnik;
    nazivnik/=r.nazivnik;
    return *this;
}*/
Razlomak &operator++ (Razlomak &r) {  //prefiksni
    r.brojnik++;
    r.nazivnik++;
    return r;
}
/*Razlomak operator++ (Razlomak &r, int) {
    Razlomak pomocni(r);
    r.brojnik++;
    r.nazivnik++;
    return pomocni;
}*/

int main ()
{
      Razlomak r, p, q;
        std::cin >> r; //5/17
        std::cout << r << std::endl;
        std::cin.clear(); std::cin.ignore (100, '\n');
        //tri zaredom
        std::cin >> r >> p >> q; //10 20 30 -> 10/1 20/1 30/1
        std::cout << r << " " << p << " " << q << std::endl;
        std::cin.clear(); std::cin.ignore (100, '\n');
        std::cin >> r;
        std::cout << r;
    
	return 0;
}