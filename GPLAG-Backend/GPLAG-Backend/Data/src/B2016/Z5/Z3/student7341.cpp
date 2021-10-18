/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>

class Razlomak {
    long long int br;
    long long int naz;
    static long long int NZD(long long int p; long long int q){
        while(q!=0) {
            p=q; q=p%q;
        }
        return abs(p);
    }
    void PrekoracenjeZbir (long long int x, long long int y){ 
        if((y>0 && x>M-y) ||  (y<0 && x<m-y)) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    }
    void PrekoracenjeProizvod( long long int x, long long int y) {
        if( (y>0 &&( x<m/y  || x>M/y) )  || ( y<0 && ( x=m || x*(-1)>M/(y*(-1)) || x*(-1)<m/(y*(-1))) ) ) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    }
    
    public:
    Razlomak (long long int b=0, long long int n=1) {
        if(n==0) throw std::logic_error ("Nekorektan razlomak");
        long long int manji;
        auto nzd=NZD(b,n);
        b=b/nzd;
        n=n/nzd;
        if (b<0 && n<0) {br=abs(b) ; naz=abs(n);}
        if(n<0) {br=b*(-1); naz=abs(n);}
    }
    long long int DajBrojnik() {return br;}
    long long int DajNazivnik() {return naz;}
    // OPERATORI    
    
    Razlomak operator + (const Razlomak &r1, const Razlomak &r2){
        long long int r(NZD(r1.DajNazivnik(), r2.DajNazivnik()));
        PrekoracenjeProizvod(r1.DajBrojnik(),(r2.DajNazivnik())/r );
        PrekoracenjeZbir(r1.DajBrojnik()*((r2.DajNazivnik())/r), r2.DajBrojnik()*((r1.DajNazivnik())/r) );
       
        long long int brojnik=r1.DajBrojnik()*((r2.DajNazivnik())/r)  +   r2.DajBrojnik()*((r1.DajNazivnik())/r);
        
        PrekoracenjeProizvod(r1.DajNazivnik(), (r2.DajNazivnik()/r) );
        long long int nazivnik=r1.DajNazivnik()*(r2.DajNazivnik()/r);
        return {brojnik,nazivnik};
    }
    
    Razlomak operator -(const Razlomak &r1, const Razlomak &r2){
        long long int r(NZD(r1.DajNazivnik(), r2.DajNazivnik()));
        PrekoracenjeProizvod(r1.DajBrojnik(),((r2.DajNazivnik())/r) );
        
        PrekoracenjeZbir (r1.DajBrojnik()*((r2.DajNazivnik())/r), ( (-1)* r2.DajBrojnik()*((r1.DajNazivnik())/r)) );
        long long int brojnik=r1.DajBrojnik()*((r2.DajNazivnik())/r)  -   r2.DajBrojnik()*((r1.DajNazivnik())/r);
       
        PrekoracenjeProizvod(r1.DajNazivnik(),(r2.DajNazivnik()/r));
        long long int nazivnik=r1.DajNazivnik()*(r2.DajNazivnik()/r);
        
        return {brojnik,nazivnik};
    }
    
    Razlomak operator * (const Razlomak &r1, const Razlomak &r2){
        long long int s(  NZD ( r1.DajBrojnik(), r2.DajNazivnik() ));
        long long int t(  NZD ( r2.DajBrojnik(),  r1.DajNazivnik()  ));
        PrekoracenjeProizvod( (r1.DajBrojnik()/s), (r2.DajBrojnik()/t)  );
        long long int brojnik( (r1.DajBrojnik()/s) * (r2.DajBrojnik()/t) );
        PrekoracenjeProizvod( (r1.DajNazivnik()/t), (r2.DajNazivnik()/s) );
        long long int nazivnik( (r1.DajNazivnik()/t) * (r2.DajNazivnik()/s) );
        return {brojnik,nazivnik};
    }
    Razlomak operator / (const Razlomak &r1, const Razlomak &r2){
        long long int u(  NZD ( r1.DajBrojnik(), r2.DajBrojnik() ));
        long long int r(  NZD ( r1.DajNazivnik(), r2.DajNazivnik() ));
        PrekoracenjeProizvod( (r1.DajBrojnik()/u), (r2.DajNazivnik()/r));
        long long int brojnik ( (r1.DajBrojnik()/u) * (r2.DajNazivnik()/r) );
        
        PrekoracenjeProizvod( (r1.DajNazivnik()/r), (r2.DajBrojnik()/u))
        long long int nazivnik( (r1.DajNazivnik()/r) * (r2.DajBrojnik()/u) );
        return {brojnik, nazivnik};
    }
    
    Razlomak operator - () const { 
        PrekoracenjeProizvod(br, -1); PrekoracenjeProizvod(naz, -1);
        return {br*(-1), naz*(-1)}; }
    }
    Razlomak operator + () const {
        return {br,naz};
    }
    Razlomak & Razlomak operator += (const Razlomak &r1) {
        
    }
    
}
int main ()
{
	return 0;
}