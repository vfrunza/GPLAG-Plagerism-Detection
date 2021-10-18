#include <iostream>
#include <stdexcept>
#include <cstdlib>

class Razlomak {
    long long int brojnik, nazivnik;
    
    static int pomocna (long long int b, long long int n){
        int broj=0;
         if(abs(n)>abs(b)){
            for(int i=n;i>=1;i--){
                if(n%i==0 && b%i==0) {broj=i; break;}
            }
        }
      
        else if(abs(n)<abs(b)){
            for(int i=b;i>=1;i--){
                if(n%i==0 && b%i==0) {broj=i; break;}
            }
          }
          
          return broj;
    }
    
    public:
    Razlomak (long long int b, long long int n=1);
    long long int DajBrojnik () {return brojnik;}
    long long int DajNazivnik () {return nazivnik;}
    friend Razlomak operator + (const Razlomak &a, const Razlomak &b);
    friend Razlomak operator - (const Razlomak &a, const Razlomak &b);
    friend Razlomak operator * (const Razlomak &a, const Razlomak &b);
    friend Razlomak operator / (const Razlomak &a, const Razlomak &b);
    friend Razlomak operator + (const Razlomak &a) ;
    friend Razlomak operator - (const Razlomak &a) ;
    friend Razlomak &operator += (Razlomak &a, const Razlomak &b);
    friend Razlomak &operator -= (Razlomak &a, const Razlomak &b);
    friend Razlomak &operator *= (Razlomak &a, const Razlomak &b);
    friend Razlomak &operator /= (Razlomak &a, const Razlomak &b);
    friend Razlomak operator ++ (Razlomak &a, int); //postfiksni
    friend Razlomak operator -- (Razlomak &a, int);
    friend Razlomak operator ++ (Razlomak &a);//prefiksni
    friend Razlomak operator -- (Razlomak &a);
    friend bool operator < (const Razlomak &a, const Razlomak &b);
    friend bool operator > (const Razlomak &a, const Razlomak &b);
    friend bool operator <= (const Razlomak &a, const Razlomak &b); //nisam njih
    friend bool operator >= (const Razlomak &a, const Razlomak &b); //nisam njih
    friend bool operator == (const Razlomak &a, const Razlomak &b);
    friend bool operator != (const Razlomak &a, const Razlomak &b);
    friend std::ostream &operator << (std::ostream &tok, const Razlomak &a);
    friend std::istream &operator >> (std::ostream &tok, const Razlomak &a);
};

    Razlomak::Razlomak (long long int b, long long int n){
        if (n==0) throw std::logic_error ("Nekorektan razlomak");
        int broj=Razlomak::pomocna(b,n);
        if(n<0 && b>0) { brojnik=-b/broj;  nazivnik=-n/broj; }
        else if (n<0 && b<0) { brojnik=-b/broj; nazivnik=-n/broj;}
        else { brojnik=b/broj; nazivnik=n/broj;}
  }
   
    Razlomak operator + (const Razlomak &a, const Razlomak &b){
        int r=Razlomak::pomocna(a.nazivnik,b.nazivnik);
        return {(a.brojnik*(b.nazivnik/r) + b.brojnik*(a.nazivnik/r)) , (a.nazivnik*(b.nazivnik/r) ) };
    }
  
    Razlomak operator * (const Razlomak &a, const Razlomak &b){
        int s=Razlomak::pomocna(a.brojnik,b.nazivnik);
        int t=Razlomak::pomocna(b.brojnik,a.nazivnik);
        return {( (a.brojnik*s)*(b.brojnik/t) ) , ( (a.nazivnik/t)* (b.nazivnik/s) ) };
    }
  
   Razlomak operator - (const Razlomak &a, const Razlomak &b){
        int r=Razlomak::pomocna(a.nazivnik,b.nazivnik);
        return {(a.brojnik*(b.nazivnik/r) - b.brojnik*(a.nazivnik/r)) , (a.nazivnik*(b.nazivnik/r) ) };
   }
   
   Razlomak operator / (const Razlomak &a, const Razlomak &b){
       int u=Razlomak::pomocna(a.brojnik,b.brojnik);
       int r=Razlomak::pomocna(a.nazivnik,b.nazivnik);
       return { ( (a.brojnik/u)*(b.nazivnik/r) ) ,  ( (a.nazivnik/r)* (b.brojnik/u) ) } ;
   }
   
   Razlomak operator + (const Razlomak &a) {return a;}
   Razlomak operator - (const Razlomak &a) { return {-a.brojnik, a.nazivnik}; }
  
   Razlomak &operator += (Razlomak &a, const Razlomak &b){
       int r=Razlomak::pomocna(a.nazivnik,b.nazivnik);
       a.brojnik=a.brojnik*(b.nazivnik/r) + b.brojnik*(a.nazivnik/r) ;
       a.nazivnik=a.nazivnik*(b.nazivnik/r);
       return a;
   }
   
   Razlomak &operator -= (Razlomak &a, const Razlomak &b){
       int r=Razlomak::pomocna(a.nazivnik,b.nazivnik);
       a.brojnik = a.brojnik*(b.nazivnik/r) - b.brojnik*(a.nazivnik/r) ;
       a.nazivnik = a.nazivnik*(b.nazivnik/r);
       return a;
   }
   
   Razlomak &operator /= (Razlomak &a, const Razlomak &b){
       int u=Razlomak::pomocna(a.brojnik,b.brojnik);
       int r=Razlomak::pomocna(a.nazivnik,b.nazivnik);
       a.brojnik = (a.brojnik/u)*(b.nazivnik/r);
       a.nazivnik =  (a.nazivnik/r)* (b.brojnik/u);
       return a;
   }
   
    Razlomak &operator *= (Razlomak &a, const Razlomak &b){
        int s=Razlomak::pomocna(a.brojnik,b.nazivnik);
        int t=Razlomak::pomocna(b.brojnik,a.nazivnik);
        a.brojnik=(a.brojnik*s)*(b.brojnik/t);
        a.nazivnik=(a.nazivnik/t)* (b.nazivnik/s);
        return a;
    }
    
    Razlomak operator ++ (Razlomak &a, int){
        Razlomak pomocni(a);
        Razlomak broj(a.nazivnik,a.nazivnik); // treba da napravi broj nazivnik/nazivnik
        a+=broj;
        return pomocni;
    }
    
    Razlomak operator -- (Razlomak &a, int){
        Razlomak pomocni(a);
        Razlomak broj(a.nazivnik,a.nazivnik); // treba da napravi broj nazivnik/nazivnik
        a-=broj;
        return pomocni;
    }
    
    Razlomak operator ++ (Razlomak &a){
        Razlomak broj(a.nazivnik,a.nazivnik); // treba da napravi broj nazivnik/nazivnik
        a+=broj;
        return a;
    }
    
     Razlomak operator -- (Razlomak &a){
        Razlomak broj(a.nazivnik,a.nazivnik); // treba da napravi broj nazivnik/nazivnik
        a-=broj;
        return a;
    }
    
    bool operator < (const Razlomak &a, const Razlomak &b){
        long double br1=a.brojnik/a.nazivnik;
        long double br2=b.brojnik/b.nazivnik;
        return br1 < br2;
    }
    
    bool operator > (const Razlomak &a, const Razlomak &b){
        long double br1=a.brojnik/a.nazivnik;
        long double br2=b.brojnik/b.nazivnik;
        return br1 > br2;
    }
    
    bool operator == (const Razlomak &a, const Razlomak &b){
        return a.brojnik==b.brojnik && a.nazivnik==b.nazivnik;
    }
    
     bool operator != (const Razlomak &a, const Razlomak &b){
        long long int a1=a.brojnik*b.nazivnik;
        long long int b1=a.nazivnik*b.brojnik;
        return a1!=b1;
    }
    
    std::istream & operator >> (std::istream tok, Razlomak &a){
        char znak;
        tok>>std::ws;
        tok>>a.brojnik;
        if(tok.peek()!='/') a.nazivnik=1;
        else {
            tok>>znak;
            if(znak!='/')  tok.setstate(std::ios::failbit);
            tok>>a.nazivnik;
        }
        return tok;
    }
    
    
    
int main ()
{
	return 0;
}