/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include<stdexcept>
#include<cmath>
#include<climits>

class Razlomak{
    
    long long int brojnik;
    long long int nazivnik;
   static long long int NZD(long long int p,long long int q);
   static bool PrekoracenjePlus(long long int x,long long int y);
   static bool PrekoracenjeMinus(long long int x, long long int y);
   static bool PrekoracenjePuta(long long int x, long long int y);
    
   
   public:
  explicit operator long double() const { return (long double) brojnik/nazivnik;}
   
   Razlomak(long long int brojnik=0,long long int nazivnik=1);
   long long int DajBrojnik()  const  {return brojnik;};
   long long int DajNazivnik() const {return nazivnik;};
   
   friend Razlomak operator +(const Razlomak &r1,const Razlomak &r2);
   friend Razlomak operator -(const Razlomak &r1,const Razlomak &r2);
   friend Razlomak operator *(const Razlomak &r1,const Razlomak &r2);
   friend Razlomak operator /(const Razlomak &r1,const Razlomak &r2);
   
   friend Razlomak operator +(const Razlomak &r) {return r;};
   friend Razlomak operator -( Razlomak &r);
   
   friend Razlomak &operator +=(Razlomak &r1,const Razlomak &r2);
   friend Razlomak &operator -=(Razlomak &r1,const Razlomak &r2);
   friend Razlomak &operator *=(Razlomak &r1,const Razlomak &r2);
   friend Razlomak &operator /=(Razlomak &r1,const Razlomak &r2);
   
   friend bool operator == (const Razlomak &r1,const Razlomak &r2){
       return r1.brojnik==r2.brojnik && r1.nazivnik==r2.nazivnik;
   }
   friend bool operator != (const Razlomak &r1,const Razlomak &r2){
       return !(r1==r2);
   }
   friend bool operator <(const Razlomak &r1,const Razlomak &r2);
   friend bool operator >(const Razlomak &r1,const Razlomak &r2);
   friend bool operator <=(const Razlomak &r1,const Razlomak &r2);
   friend bool operator >=(const Razlomak &r1,const Razlomak &r2);
   
   friend Razlomak &operator ++(Razlomak &r){
       if(PrekoracenjePlus(r.brojnik,r.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
       r.brojnik=r.brojnik+r.nazivnik; return r;}
   friend Razlomak &operator --(Razlomak &r){
       if(PrekoracenjeMinus(r.brojnik,r.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
       r.brojnik=r.brojnik-r.nazivnik;
       return r;
   }
   friend Razlomak operator ++(Razlomak &r,int);
   friend Razlomak operator --(Razlomak &r,int);
   
   
   friend std::ostream &operator <<(std::ostream &tok,const Razlomak &r){
       
       if(r.nazivnik==1){
           
           return tok<<r.brojnik;
       }else{
       return tok<<r.brojnik<<"/"<<r.nazivnik;
       }
   
   }
   
   friend std::istream &operator >> (std::istream &tok,Razlomak &r);
   
};

Razlomak operator -( Razlomak &r){
    
    auto m=LLONG_MIN;
   
    if(-r.brojnik==m) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
   
    r.brojnik=-r.brojnik;
    return r;
}


long long int Razlomak::NZD(long long int p,long long int q){
    
    long long int p1(p),q1(q);
 
        a:
        p=q1;
        q=p1%q1;
        if(q==0) return p;
        else{
            p1=p; q1=q;
            goto a;
        }
  
}

bool Razlomak::PrekoracenjePlus(long long int x,long long int y){
    auto m=LLONG_MIN,M=LLONG_MAX;
    
    if(y>0 && x>M-y) return true;
   else if(y<0 && x<m-y) return true;
    else return false;
    
}
bool Razlomak::PrekoracenjeMinus(long long int x,long long int y){
    auto m=LLONG_MIN,M=LLONG_MAX;
    
    if(y<0 && x>M+y) return true;
   else if(y>0 && x<m+y) return true;
    else return false;
    
}



bool Razlomak::PrekoracenjePuta(long long int x, long long int y){
    auto m=LLONG_MIN,M=LLONG_MAX;
    
    if(y>0 && (x<m/y || x>M/y)) return true;
    else if(y<0 && (x==m || -x>M/(-y) || -x<m/(-y))) return true;
    else return false;
}


Razlomak::Razlomak(long long int brojnik,long long int nazivnik){
    
    if(nazivnik==0) throw std::logic_error("Nekorektan razlomak");
    
    auto nzd(NZD(brojnik,nazivnik));
    
    if( nazivnik<0) {
       
     nazivnik=std::abs(nazivnik);
      if(brojnik>0) brojnik=-brojnik;
      if(brojnik<0) brojnik=std::abs(brojnik);
      
        
    }
    
    Razlomak::brojnik=brojnik/nzd;
    Razlomak::nazivnik=nazivnik/nzd;
    
}
Razlomak operator +(const Razlomak &r1,const Razlomak &r2){
   Razlomak r3(r1);
   return r3+=r2;
}
Razlomak operator -(const Razlomak &r1,const Razlomak &r2){
     
    Razlomak r3(r1);
    return r3-=r2;
}
Razlomak operator *(const Razlomak &r1,const Razlomak &r2){
    
    Razlomak r3(r1);
    return r3*=r2;
}
Razlomak operator /(const Razlomak &r1,const Razlomak &r2){
    Razlomak r3(r1);
    return r3/=r2;
}

Razlomak &operator +=(Razlomak &r1,const Razlomak &r2){
    
     auto r(Razlomak::NZD(r1.nazivnik,r2.nazivnik));
       
      if(Razlomak::PrekoracenjePuta(r1.brojnik,r2.nazivnik/r) || Razlomak::PrekoracenjePuta(r2.brojnik,r1.nazivnik/r) || Razlomak::PrekoracenjePuta(r1.nazivnik,r2.nazivnik/r) 
    || Razlomak::PrekoracenjePlus(r1.brojnik*(r2.nazivnik/r),r2.brojnik*(r1.nazivnik/r))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    
    r1=Razlomak(r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r),r1.nazivnik*(r2.nazivnik/r));
    return r1;
}
Razlomak &operator -=(Razlomak &r1,const Razlomak &r2){
     auto r(Razlomak::NZD(r1.nazivnik,r2.nazivnik));
      if(Razlomak::PrekoracenjePuta(r1.brojnik,r2.nazivnik/r) || Razlomak::PrekoracenjePuta(r2.brojnik,r1.nazivnik/r) || Razlomak::PrekoracenjePuta(r1.nazivnik,r2.nazivnik/r) 
     || Razlomak::PrekoracenjeMinus(r1.brojnik*(r2.nazivnik/r),r2.brojnik*(r1.nazivnik/r))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    r1= Razlomak(r1.brojnik*(r2.nazivnik/r)-r2.brojnik*(r1.nazivnik/r),r1.nazivnik*(r2.nazivnik/r));
    return r1;
}
Razlomak &operator *= (Razlomak &r1,const Razlomak &r2){

    auto s(Razlomak::NZD(r1.brojnik,r2.nazivnik));
    auto t(Razlomak::NZD(r2.brojnik,r1.nazivnik));
     if(Razlomak::PrekoracenjePuta(r1.brojnik/s,r2.nazivnik/t) || Razlomak::PrekoracenjePuta(r1.nazivnik/t,r2.brojnik/s))
    throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    
    r1= Razlomak((r1.brojnik/s)*(r2.brojnik/t),(r1.nazivnik/t)*(r2.nazivnik/s));
    return r1;
    
}
Razlomak &operator /=(Razlomak &r1, const Razlomak &r2){
     auto r(Razlomak::NZD(r1.nazivnik,r2.nazivnik));
    auto u(Razlomak::NZD(r1.brojnik,r2.brojnik));
    r1= Razlomak((r1.brojnik/u)*(r2.nazivnik/r),(r1.nazivnik/r)*(r2.brojnik/u));
    return r1;
}


std::istream &operator >> (std::istream &tok, Razlomak &r){ 
       char znak;
    tok>>std::ws;
    tok>>r.brojnik;
    if(tok.peek()=='/'){
        
        tok>>znak>>r.nazivnik;
        if(tok.peek()!='\n' && tok.peek()!='\r' && tok.peek()!='\f' && tok.peek()!='\v' && tok.peek()!='\t' && tok.peek()!=' ') tok.setstate(std::ios::failbit);
        r=Razlomak(r.brojnik,r.nazivnik);
    }
    else{
       
        if(tok.peek()!='\n' && tok.peek()!='\r' && tok.peek()!='\f' && tok.peek()!='\v' && tok.peek()!='\t' && tok.peek()!=' ') tok.setstate(std::ios::failbit);
         r.nazivnik=1;
    }
    
    return tok;
}

bool operator >(const Razlomak &r1,const Razlomak &r2){
    
    auto r=Razlomak::NZD(r1.brojnik,r2.brojnik);
    auto s=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
    
    return (r1.brojnik/r)*(r2.nazivnik/s)>(r2.brojnik/r)*(r1.nazivnik/s);
}
bool operator <(const Razlomak &r1,const Razlomak &r2){
    
    auto r=Razlomak::NZD(r1.brojnik,r2.brojnik);
    auto s=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
    
    return (r1.brojnik/r)*(r2.nazivnik/s)<(r2.brojnik/r)*(r1.nazivnik/s);
}
bool operator <=(const Razlomak &r1,const Razlomak &r2){
    
      return r1<r2 || r1==r2;
}
bool operator >=(const Razlomak &r1,const Razlomak &r2){
 
    return  r1>r2|| r1==r2;
}
Razlomak operator ++(Razlomak &r,int){
    
    Razlomak p(r);
    if(Razlomak::PrekoracenjePlus(r.brojnik,r.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    r.brojnik=r.brojnik+r.nazivnik;
    return p;
}
 Razlomak operator --(Razlomak &r,int){
     Razlomak p(r);
     if(Razlomak::PrekoracenjeMinus(r.brojnik,r.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
     r.brojnik=r.brojnik-r.nazivnik;
     return p;
 }




int main ()
{
	return 0;
}