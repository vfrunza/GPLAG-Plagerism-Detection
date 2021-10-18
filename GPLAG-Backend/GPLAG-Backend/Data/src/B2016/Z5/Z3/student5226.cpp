/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
class Razlomak{
    long long int brojnik, nazivnik;
    static  int NZD(long long int p,long long int q){
        int nzd;
        if(p==0) {
            nzd=0;
            return nzd;
        }
        else{
           return  nzd=q/(p%q);}
    }
    
    public:
    Razlomak (long long int br,long long int naz){
        if(naz<0 && br>0) {
            naz=naz*(-1);
            br=br*(-1);
        }
        else if(naz<0 && br<0){
            naz=naz*(-1);
            br=br*(-1);
        }
        else if(naz==0) throw std::logic_error("Nekorektna razlomak");
        int broj;
        broj=NZD(br,naz);
        if(broj!=0 && br%broj==0 && naz%broj==0){
            br=br/broj;
            naz=naz/broj;
        }
        brojnik=br;
        nazivnik=naz;
    }
    
    
    
    Razlomak(long long int br){
        brojnik=br;
        nazivnik=1;
    }
    Razlomak(){
        brojnik=0;
        nazivnik=1;
    }
   long long int DajBrojnik() const { return brojnik;}
    long long int DajNazivnik() const { return nazivnik; }
    
    friend Razlomak operator+(const Razlomak &r1,const Razlomak &r2){
        int r=NZD(r1.nazivnik,r2.nazivnik);
        Razlomak r3;
        r3.brojnik=r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r);
        r3.nazivnik=r1.nazivnik*r2.nazivnik/r;
        return r3;
    }
    friend Razlomak operator-(const Razlomak &r1, const Razlomak &r2){
        int r=NZD(r1.nazivnik,r2.nazivnik);
        Razlomak r3;
        r3.brojnik=r1.brojnik*(r2.nazivnik/r)-r2.brojnik*(r1.nazivnik/r);
        r3.nazivnik=r1.nazivnik*r2.nazivnik/r;
        return r3;
    }
    
    friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2){
        int s=NZD(r1.brojnik,r2.nazivnik);
        int t=NZD(r1.nazivnik,r2.brojnik);
        Razlomak r3;
        r3.brojnik=r1.brojnik/s * r2.brojnik/t;
        r3.nazivnik=r1.nazivnik/t * r2.nazivnik/s;
        return r3;
    }
    
    friend Razlomak operator/(const Razlomak &r1, const Razlomak &r2){
        int r=NZD(r1.nazivnik,r2.nazivnik);
        int u=NZD(r1.brojnik,r2.brojnik);
        Razlomak r3;
        r3.brojnik=r1.brojnik/u * r2.brojnik/u;
        r3.nazivnik=r1.nazivnik/r * r2.nazivnik/r;
        return r3;
    }
    //uvesti prekoracenja u operatorima gore
    
    friend Razlomak operator -(const Razlomak &r1){
        return { -r1.brojnik/r1.nazivnik };
    }
    
    friend Razlomak operator + (const Razlomak &r1){
        return { r1.brojnik / r1.nazivnik };
    }
    
    friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2){
        int r=NZD(r1.nazivnik,r2.nazivnik);
        r1=(r1.brojnik * r2.nazivnik/r + r2.brojnik *r1.nazivnik/r) / (r1.nazivnik*r2.nazivnik/r);
        return r1;
    }
    friend Razlomak &operator-=(Razlomak &r1, const Razlomak &r2){
        int r=NZD(r1.nazivnik,r2.nazivnik);
        r1=(r1.brojnik *r2.nazivnik/r -r2.brojnik *r1.nazivnik/r) / (r1.nazivnik*r2.nazivnik/r);
        return r1;
    }
    
    friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2){
        int s=NZD(r1.brojnik,r2.nazivnik);
        int t=NZD(r1.nazivnik,r2.brojnik);
        r1=(r1.brojnik/s) * (r2.brojnik/t) / (r1.nazivnik/t) * (r2.brojnik/s);
        return r1;
    }
    friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2){
        int u=NZD(r1.brojnik,r2.brojnik);
        int r=NZD(r1.nazivnik,r2.nazivnik);
        r1= (r1.brojnik/u) *(r2.nazivnik/r) / (r1.nazivnik/r) *(r2.brojnik/u);
        return r1;
    }
    
    friend Razlomak operator++(Razlomak &r,int) {
        Razlomak pomocni(r);
        r=r.brojnik+r.nazivnik / r.nazivnik;
        return pomocni;
    }
    
    friend Razlomak &operator++(Razlomak &r){
        r=r.brojnik+r.nazivnik / r.nazivnik;
        return r;
    }
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2){
        if(r1.brojnik%r2.brojnik==0 && r1.nazivnik%r2.nazivnik==0)
        return r1.brojnik==r2.brojnik && r1.nazivnik==r2.nazivnik;
    }
    friend bool operator!=(const Razlomak &r1, const Razlomak &r2){
        return !(r1==r2);
    }
    friend bool operator <(const Razlomak &r1, const Razlomak &r2){
        long double razlomak1, razlomak2;
        razlomak1=r1.brojnik/r2.nazivnik;
        razlomak2=r2.brojnik/r2.nazivnik;
        if(razlomak1<razlomak2) return true;
        else return false;
    }
    friend bool operator>(const Razlomak &r1, const Razlomak &r2){
        long double razlomak1,razlomak2;
        razlomak1=r1.brojnik/r1.nazivnik;
        razlomak2=r2.brojnik/r2.nazivnik;
        if(razlomak1>razlomak2) return true;
        else return false;
    }
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2){
        long double razlomak1,razlomak2;
        razlomak1=r1.brojnik/r1.nazivnik;
        razlomak2=r2.brojnik/r2.nazivnik;
        if(razlomak1<razlomak2 || razlomak1==razlomak2) return true;
        else return false;
        
    }
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2){
        long double razlomak1,razlomak2;
        razlomak1=r1.brojnik/r1.nazivnik;
        razlomak2=r2.brojnik/r2.nazivnik;
        if(razlomak1>razlomak2 || razlomak1==razlomak2) return true;
        else return false;
    }
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r1){
       
        if(r1.nazivnik!=1)
        tok<<r1.brojnik<<"/"<<r1.nazivnik;
        else 
        tok<<r1.brojnik;
        return tok;
    }
    
    friend std::istream &operator >> (std::istream &tok, Razlomak &r1){
        char znak;
        tok>>std::ws;
        tok>>r1.brojnik;
        if(tok.peek()!='/') r1.nazivnik=1;
        else {
            tok>>znak;
            if(znak!='/') tok.setstate(std::ios::failbit);
            tok>>r1.nazivnik;
        }
        return tok;
    }
};
int main ()
{
    Razlomak r1(17,8),r2(4),r3,r4=10/20;
    std::cout<<"r1= "<<r1<<" r2= "<<r2<<" r3= "<<r3<<"r4= "<<r4;
    std::cout<<r3+r4;
	return 0;
}