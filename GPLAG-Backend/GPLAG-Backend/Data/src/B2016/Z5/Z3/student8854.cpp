/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <limits>
#include <stdexcept>
long long int NZD(long long int a, long long int b)
    {
        if(b==0)
        return a;
        else
        return NZD(b,a%b);
    }
const long long int minimum(std::numeric_limits<long long int>::min());
const long long int maximum(std::numeric_limits<long long int>::max());
class Razlomak{
    long long int brojnik,nazivnik;
    static long long int NadjimiNZD(long long int a, long long int b)
    {
        if(b==0)
        return a;
        else
        return NadjimiNZD(b,a%b);
    }
    
    public:
    Razlomak(long long int brojnik=0, long long int nazivnik=1)
    {
        if(nazivnik==0)
        throw std::logic_error("Nekorektan razlomak");
        Razlomak::brojnik=brojnik/NadjimiNZD(brojnik,nazivnik);
        Razlomak::nazivnik=nazivnik=nazivnik/NadjimiNZD(brojnik,nazivnik);
        
    }
    
    long long int DajBrojnik() const {return brojnik;}
    long long int DajNazivnik() const {return nazivnik;}
    
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &b)
    {
        long long int broj(b.DajBrojnik()),naziv(b.DajNazivnik());
        if(broj==0)
        {
            tok<<0;
            return tok;
        }
        if(naziv==1)
        {
            tok<<broj;
            return tok;
        }
        tok<<broj<<"/"<<naziv;
        
        return tok;
    }
    friend std::istream &operator >>(std::istream &tok, Razlomak &b)
    {
        char znak;
        znak='/';
        long long int aa(b.DajBrojnik()),bb(b.DajNazivnik());
        return tok>>aa>>znak>>bb;
    }
    
    
    
    
    
    
    
};
    Razlomak operator + (const Razlomak &a,const Razlomak &b)
    {
        long long int p1,p2,q1,q2,r;
        p1=a.DajBrojnik();
        q1=a.DajNazivnik();
        p2=b.DajBrojnik();
        q2=b.DajNazivnik();
        r=NZD(q1,q2);
        if((q2/r)>0 && ((p1<minimum/(q2/r)) || (p1>maximum/(q2/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        if((q1/r)>0 && ((p2<minimum/(q1/r)) || (p2>maximum/(q1/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        if((q2/r)>0 && ((q1<minimum/(q2/r)) || (q1>maximum/(q2/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        
        if((p2*(q1/r)>0 && p1*(q2/r)>maximum-p2*(q1/r)) || (p2*(q1/r)<0 && p1*(q2/r)<minimum-p2*(q1/r)))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        
        return Razlomak{p1*(q2/r)+p2*(q1/r),q1*(q2/r)};
        
        
        
        
    }
  
    Razlomak operator - (const Razlomak &a,const Razlomak &b)
    {
        long long int p2,q2;
        
        p2=b.DajBrojnik();
        q2=b.DajNazivnik();
        Razlomak b1(-p2,q2);
        return a+b1;
        
        
        
        
    }
    Razlomak operator * (const Razlomak &a,const Razlomak &b)
    {
        long long int broj1,naziv1,broj2,naziv2,nzd;
        broj1=a.DajBrojnik();
        naziv1=a.DajNazivnik();
        broj2=b.DajBrojnik();
        naziv2=b.DajNazivnik();
        nzd=NZD(naziv1,naziv2);
        
        
        
        
        
        
        
        
    }
    Razlomak operator / (const Razlomak &a,const Razlomak &b)
    {
        return a;
        
        
    }
 /*   std::ostream operator << (std::ostream &a,const Razlomak &b)
    {
        a<<b.DajBrojnik()<<"/"<<b.DajNazivnik();
        
        return a;
    }
   */ 

int main ()
{
	Razlomak a(5,7);
	Razlomak b(2,9);
	Razlomak c=a+b;
	std::cout<<"ekstrica"<<std::endl<<std::endl<<c.DajBrojnik()<<" "<<c.DajNazivnik();
	c=a-b;
	std::cout<<"ekstrica"<<std::endl<<std::endl<<c.DajBrojnik()<<" "<<c.DajNazivnik();
	Razlomak d{2,2};
	return 0;
}