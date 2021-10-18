/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <cmath>
#include <sstream>

class Razlomak {
    long long int brojnik;
    long long int nazivnik;
    static long long int NZD(long long int p, long long int q);
public:
    Razlomak();
    Razlomak(long long int br);
    Razlomak(long long int br, long long int naz);
    long long int DajBrojnik() const;
    long long int DajNazivnik() const;
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r);
    friend std::istream &operator >>(std::istream &tok, Razlomak &r);
    friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);   
    friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
    //static long long int NZD(long long int p, long long int q);
};

std::ostream &operator <<(std::ostream &tok, const Razlomak &r) {
if (r.DajNazivnik()==1)
    tok << r.DajBrojnik();
else tok << r.DajBrojnik() << "/" << r.DajNazivnik();
return tok;
}

std::istream &operator >>(std::istream &tok, Razlomak &r) {
    char znak='\0';
    long long int s;
    tok >> std::ws;
    //if (tok.peek()==' ')
    
    //||(tok.peek()=='\r')||(tok.peek()=='\n')||(tok.peek()=='\t')||(tok.peek()=='\f')||(tok.peek()=='\v')) {
        tok >> r.brojnik >> znak;
        //std::cout<<znak;
        if (znak!='/') {
            //if ((znak<='9')&&(znak>='0')) 
            r.nazivnik=1;
            //else tok.setstate(std::ios::failbit);
            
        }
        else {
            tok>>r.nazivnik;
                s=Razlomak::NZD(r.brojnik,r.nazivnik);
                r.brojnik=r.brojnik/s;
                r.nazivnik=r.nazivnik/s;
            //if ((znak<'0')&&(znak>'9')) tok.setstate(std::ios::failbit);
            
        }


    return tok;
}

Razlomak operator +(const Razlomak &r1, const Razlomak &r2) {
long long int s1, s2, r;
    r=Razlomak::NZD(r1.DajNazivnik(),r2.DajNazivnik());
    s1=r1.DajBrojnik()*(r2.DajNazivnik()/r)+r2.DajBrojnik()*(r1.DajNazivnik()/r);
    s2=r1.DajNazivnik()*(r2.DajNazivnik()/r);
return Razlomak(s1,s2);
}

Razlomak operator -(const Razlomak &r1, const Razlomak &r2) {
long long int s1, s2, r;
    r=Razlomak::NZD(r1.DajNazivnik(),r2.DajNazivnik());
    s1=r1.DajBrojnik()*(r2.DajNazivnik()/r)-r2.DajBrojnik()*(r1.DajNazivnik()/r);
    s2=r1.DajNazivnik()*(r2.DajNazivnik()/r);
return Razlomak(s1,s2);
}

Razlomak operator *(const Razlomak &r1, const Razlomak &r2) {
long long int s1, s2, s,t;
    s=Razlomak::NZD(r1.DajBrojnik(),r2.DajNazivnik());
    t=Razlomak::NZD(r2.DajBrojnik(),r1.DajNazivnik());
    s1=(r1.DajBrojnik()/s)*(r2.DajBrojnik()/t);
    s2=(r1.DajNazivnik()/t)*(r2.DajNazivnik()/s);
return Razlomak(s1,s2);
}

Razlomak operator /(const Razlomak &r1, const Razlomak &r2) {
long long int s1, s2, r,u;
    r=Razlomak::NZD(r1.DajNazivnik(),r2.DajNazivnik());
    u=Razlomak::NZD(r1.DajBrojnik(),r2.DajBrojnik());
    s1=(r1.DajBrojnik()/u)*(r2.DajNazivnik()/r);
    s2=(r1.DajNazivnik()/r)*(r2.DajBrojnik()/u);
return Razlomak(s1,s2);
}



long long int Razlomak::NZD(long long int p, long long int q) {
    
    if(q == 0) return p;
    return NZD(q, p % q);
}
    
Razlomak::Razlomak() {
        brojnik=0;
        nazivnik=1;
    }

Razlomak::Razlomak(long long int br) {
        brojnik=br;
        nazivnik=1;
    }

Razlomak::Razlomak(long long int br, long long int naz) {
    
        long long int s;
        s=NZD(br,naz);
        br=br/s;
        naz=naz/s;
        
        if (((br>=0)&&(naz>0))||((br<0)&&(naz<0))) {
            brojnik=std::abs(br);
            nazivnik=std::abs(naz); 
        }
        if (((br<0)&&(naz>0))||((br>0)&&(naz<0))) {
            brojnik=-std::abs(br);
            nazivnik=std::abs(naz); 
        }
        if (naz==0) {
            throw std::logic_error("Nekorektan razlomak"); 
        }

        
        else {
        brojnik=std::abs(br);
        nazivnik=std::abs(naz); }
    }

long long int Razlomak::DajBrojnik() const
{
    return brojnik;
}

long long int Razlomak::DajNazivnik() const
{
    return nazivnik;
}

int main ()
{
	Razlomak r(173,50);
	

	std::cout<<"Brojnik"<<r.DajBrojnik()<<"Nazivnik"<<r.DajNazivnik();
	//std::cout<<"NZD"<<r.DajBrojnik()<<","<<r.DajNazivnik()<<" je"<<Razlomak::NZD(2,6);
	
	return 0;
}