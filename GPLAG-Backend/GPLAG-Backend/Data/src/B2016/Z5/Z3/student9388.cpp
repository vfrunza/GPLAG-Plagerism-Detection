#include <iostream>
#include <stdexcept>
#include <cmath>
long long int m{-2147483648};
long long int M{2147483647};
class Razlomak{
  long long int brojnik, nazivnik;
  static bool JesuLiJednaki(double x, double y, double Eps=1e-10){
    return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));  
  }
   public:
  Razlomak(long long int brojnik, long long int nazivnik);
  Razlomak(long long int brojnik);
  Razlomak();
  long long int DajBrojnik() const{ return brojnik;}
  long long int DajNazivnik() const{ return nazivnik;}
  friend std::ostream &operator<<(std::ostream &tok, const Razlomak &r);
  friend Razlomak operator +(const Razlomak &r1){return r1;}
  friend Razlomak operator -(Razlomak &r1){r1.brojnik=r1.brojnik*(-1); return r1;}
  friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2);
  friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2);
  friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2);
  friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2);
  friend Razlomak &operator ++(Razlomak &r1);
  friend Razlomak &operator --(Razlomak &r1);
  friend Razlomak operator ++(Razlomak &r1,  int);
  friend Razlomak operator --(Razlomak &r1,  int);
  friend bool operator <(const Razlomak &r1, const Razlomak &r2);
  friend bool operator >(const Razlomak &r1, const Razlomak &r2);
  friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
  friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
  friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
  friend std::istream &operator >>(std::istream &tok, Razlomak &r);
  operator long double() const;
};
Razlomak::Razlomak(long long int brojnik, long long int nazivnik){
    int predznak{0};
    long long int a, b, ostatak{1}, nzd{1}, kolicnik{0}, pomoc{0}, ostatak1{1};
    if(nazivnik==0) throw std::logic_error("Nekorektan razlomak");
    if(brojnik<0 && nazivnik<0){brojnik*=-1; nazivnik*=-1;}
    else if(nazivnik<0){predznak=1; nazivnik=nazivnik*(-1);}
     else if(brojnik<0){predznak=1; brojnik=brojnik*(-1);}
    a=brojnik; b=nazivnik;
    if(a==b || b==0){nzd=1;}
    else{
    pomoc=a/b;
    ostatak1=a-b*pomoc;
    if(ostatak1==0){nzd=nazivnik;}
    else while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
         nzd=ostatak;
         a=b;
         b=ostatak;
    }
    }
    brojnik=brojnik/nzd;
    nazivnik=nazivnik/nzd;
    if(predznak==1) brojnik=brojnik*(-1);
    Razlomak::brojnik=brojnik;
    Razlomak::nazivnik=nazivnik;
}
Razlomak::Razlomak(long long int brojnik){
    Razlomak::brojnik=brojnik;
    Razlomak::nazivnik=1;
}
Razlomak::Razlomak(){
    Razlomak::brojnik=0;
    Razlomak::nazivnik=1;
}
Razlomak operator +(const Razlomak &r1, const Razlomak &r2){
    long long int r{1}, a, b, ostatak{1}, kolicnik{0}, brojnik, nazivnik;
    long double kolicnik1{0}, kolicnik2{0};
    kolicnik1=(double)r1.brojnik/r1.nazivnik;
    kolicnik2=(double)r2.brojnik/r2.nazivnik;
    if(kolicnik2>0 && kolicnik1>M-kolicnik2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(kolicnik2<0 && kolicnik1<m-kolicnik2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
   // if(r1.nazivnik>=r2.nazivnik){a=r1.nazivnik; b=r2.nazivnik;}
   // else{a=r2.nazivnik; b=r1.nazivnik;}
   a=r1.nazivnik; b=r2.nazivnik;
    if(a==b){r=1;}
    else{
    while(ostatak!=0){
     kolicnik=a/b;
     ostatak=a-b*kolicnik;
     if(ostatak==0) break;
      r=ostatak;
      a=b;
      b=ostatak;
    }
    }
    brojnik=r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r);
    nazivnik=r1.nazivnik*(r2.nazivnik/r);
    Razlomak r3(brojnik,nazivnik);
    return r3;
}
Razlomak operator -(const Razlomak &r1, const Razlomak &r2){
    long long int r{1}, a, b, ostatak{1}, kolicnik{0}, brojnik, nazivnik;
    long double kolicnik1{0}, kolicnik2{0};
    kolicnik1=(double)r1.brojnik/r1.nazivnik;
    kolicnik2=(double)r2.brojnik/r2.nazivnik;
    if(kolicnik2<0 && kolicnik1>M-kolicnik2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(kolicnik2>0 && kolicnik1<m-kolicnik2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
   // if(r1.nazivnik>=r2.nazivnik){a=r1.nazivnik; b=r2.nazivnik;}
   // else{a=r2.nazivnik; b=r1.nazivnik;}
   a=r1.nazivnik; b=r2.nazivnik;
    if(a==b){r=1;}
    else{
    while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
        r=ostatak;
        a=b;
        b=ostatak;
    }
    }
    brojnik=r1.brojnik*(r2.nazivnik/r)-r2.brojnik*(r1.nazivnik/r);
    nazivnik=r1.nazivnik*(r2.nazivnik/r);
    Razlomak r3(brojnik,nazivnik);
    return r3;
}
Razlomak operator *(const Razlomak &r1, const Razlomak &r2){
    long long int t{1}, s{1}, a, b, ostatak{1}, kolicnik{0}, brojnik, nazivnik;
    long double kolicnik1{0}, kolicnik2{0};
    kolicnik1=(double)r1.brojnik/r1.nazivnik;
    kolicnik2=(double)r2.brojnik/r2.nazivnik;
    if(kolicnik2>0 && (kolicnik1<(double)m/kolicnik2 || kolicnik1>(double)M/kolicnik2)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(kolicnik2<0 && (Razlomak::JesuLiJednaki(kolicnik1,m) || (-kolicnik1)<(double)M/(-kolicnik2) || (-kolicnik1)>(double)m/(-kolicnik2))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
   // if(r1.brojnik>=r2.nazivnik){a=r1.brojnik; b=r2.nazivnik;}
   // else{a=r2.nazivnik; b=r1.brojnik;}
   a=r1.brojnik; b=r2.nazivnik;
    if(a==b){s=1;}
    else{
    while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
        s=ostatak;
        a=b;
        b=ostatak;
    }
    }
    ostatak=1;
   // if(r2.brojnik>=r1.nazivnik){a=r2.brojnik; b=r1.nazivnik;}
    //else{a=r1.nazivnik; b=r2.brojnik;}
    a=r2.brojnik; b=r1.nazivnik;
    if(a==b){t=1;}
    else{
    while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
        t=ostatak;
        a=b;
        b=ostatak;
    }
    }
    brojnik=((double)r1.brojnik/s)*((double)r2.brojnik/t);
    nazivnik=((double)r1.nazivnik/t)*((double)r2.nazivnik/s);
    Razlomak r3(brojnik, nazivnik);
    return r3;
}
Razlomak operator /(const Razlomak &r1, const Razlomak &r2){
    long long int u{1}, r{1}, a, b, ostatak{1}, kolicnik{0}, brojnik, nazivnik;
    if(r2.brojnik==0) throw std::logic_error("Nekorektan razlomak");
   // if(r1.nazivnik>=r2.nazivnik){a=r1.nazivnik; b=r2.nazivnik;}
   // else{a=r2.nazivnik; b=r1.nazivnik;}
   a=r1.nazivnik; b=r2.nazivnik;
    if(a==b){r=1;}
    else{
    while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
        r=ostatak;
        a=b;
        b=ostatak;
    }
    }
    ostatak=1;
   // if(r1.brojnik>=r2.brojnik){a=r1.brojnik; b=r2.brojnik;}
   // else{a=r2.brojnik; b=r1.brojnik;}
   a=r1.brojnik; b=r2.brojnik;
    if(a==b){u=1;}
    else{
    while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
        u=ostatak;
        a=b;
        b=ostatak;
    }
    }
    brojnik=((double)r1.brojnik/u)*((double)r2.nazivnik/r);
    nazivnik=((double)r1.nazivnik/r)*((double)r2.brojnik/u);
    Razlomak r3(brojnik, nazivnik);
    return r3;
}
Razlomak &operator +=(Razlomak &r1, const Razlomak &r2){
    int predznak{0};
    long long int r{1},a,b,ostatak{1}, kolicnik{0}, nzd{1};
    long double kolicnik1{0}, kolicnik2{0};
    kolicnik1=(double)r1.brojnik/r1.nazivnik;
    kolicnik2=(double)r2.brojnik/r2.nazivnik;
    if(kolicnik2>0 && kolicnik1>M-kolicnik2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(kolicnik2<0 && kolicnik1<m-kolicnik2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
   // if(r1.nazivnik>=r2.nazivnik){a=r1.nazivnik; b=r2.nazivnik;}
   // else{a=r2.nazivnik; b=r1.nazivnik;}
   a=r1.nazivnik; b=r2.nazivnik;
    if(a==b){r=1;}
    else{
    while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
        r=ostatak;
        a=b;
        b=ostatak;
    }
    }
    r1.brojnik=r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r);
    r1.nazivnik=r1.nazivnik*(r2.nazivnik/r);
    ostatak=1;
    if(r1.brojnik<0 && r1.nazivnik<0){r1.brojnik*=(-1); r1.nazivnik*=(-1);}
    else if(r1.nazivnik<0){predznak=1; r1.nazivnik=r1.nazivnik*(-1);}
    else if(r1.brojnik<0){predznak=1; r1.brojnik=r1.brojnik*(-1);}
   // if(r1.brojnik>=r1.nazivnik){a=r1.brojnik; b=r1.nazivnik;}
  //  else{a=r1.nazivnik; b=r1.brojnik;}
    a=r1.brojnik; b=r1.nazivnik;
    if(a==b){nzd=1;}
    else{
    while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
        nzd=ostatak;
        a=b;
        b=ostatak;
    }
    }
    r1.brojnik=r1.brojnik/nzd;
    r1.nazivnik=r1.nazivnik/nzd;
    if(predznak==1) r1.brojnik=r1.brojnik*(-1);
    return r1;
}
Razlomak &operator -=(Razlomak &r1, const Razlomak &r2){
    int predznak{0};
    long long int r{1},a,b,ostatak{1}, kolicnik{0}, nzd{1};
    long double kolicnik1{0}, kolicnik2{0};
    kolicnik1=(double)r1.brojnik/r1.nazivnik;
    kolicnik2=(double)r2.brojnik/r2.nazivnik;
    if(kolicnik2<0 && kolicnik1>M-kolicnik2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(kolicnik2>0 && kolicnik1<m-kolicnik2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
  //  if(r1.nazivnik>=r2.nazivnik){a=r1.nazivnik; b=r2.nazivnik;}
  //  else{a=r2.nazivnik; b=r1.nazivnik;}
  a=r1.nazivnik; b=r2.nazivnik;
    if(a==b){r=1;}
    else{
    while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
        r=ostatak;
        a=b;
        b=ostatak;
    }
    }
    r1.brojnik=r1.brojnik*((double)r2.nazivnik/r)-r2.brojnik*((double)r1.nazivnik/r);
    r1.nazivnik=r1.nazivnik*(r2.nazivnik/r);
    ostatak=1;
    if(r1.brojnik<0 && r1.nazivnik<0){r1.brojnik*=(-1); r1.nazivnik*=(-1);}
    else if(r1.nazivnik<0){predznak=1; r1.nazivnik=r1.nazivnik*(-1);}
    else if(r1.brojnik<0){predznak=1; r1.brojnik=r1.brojnik*(-1);}
   // if(r1.brojnik>=r1.nazivnik){a=r1.brojnik; b=r1.nazivnik;}
   // else{a=r1.nazivnik; b=r1.brojnik;}
   a=r1.brojnik; b=r1.nazivnik;
    if(a==b){nzd=1;}
    else{
    while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
        nzd=ostatak;
        a=b;
        b=ostatak;
    }
    }
    r1.brojnik=r1.brojnik/nzd;
    r1.nazivnik=r1.nazivnik/nzd;
    if(predznak==1) r1.brojnik=r1.brojnik*(-1);
    return r1;
}
Razlomak &operator *=(Razlomak &r1, const Razlomak &r2){
    int predznak{0};
    long long int t{1}, s{1}, a,b,ostatak{1}, kolicnik{0},nzd{1};
    long double kolicnik1{0}, kolicnik2{0};
    kolicnik1=(double)r1.brojnik/r1.nazivnik;
    kolicnik2=(double)r2.brojnik/r2.nazivnik;
    if(kolicnik2>0 && (kolicnik1<(double)m/kolicnik2 || kolicnik1>(double)M/kolicnik2)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(kolicnik2<0 && (Razlomak::JesuLiJednaki(kolicnik1,m) || (-kolicnik1)<(double)M/(-kolicnik2) || (-kolicnik1)>(double)m/(-kolicnik2))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
   // if(r1.brojnik>=r2.nazivnik){a=r1.brojnik; b=r2.nazivnik;}
  //  else{a=r2.nazivnik; b=r1.brojnik;}
  a=r1.brojnik; b=r2.nazivnik;
    if(a==b){s=1;}
    else{
    while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
        s=ostatak;
        a=b;
        b=ostatak;
    }
    }
    ostatak=1;
   // if(r2.brojnik>=r1.nazivnik){a=r2.brojnik; b=r1.nazivnik;}
   // else{a=r1.nazivnik; b=r2.brojnik;}
   a=r2.brojnik; b=r1.nazivnik;
    if(a==b){t=1;}
    else{
    while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
        t=ostatak;
        a=b;
        b=ostatak;
    }
    }
    r1.brojnik=((double)r1.brojnik/s)*((double)r2.brojnik/t);
    r1.nazivnik=((double)r1.nazivnik/t)*((double)r2.nazivnik/s);
    ostatak=1;
    if(r1.brojnik<0 && r1.nazivnik<0){r1.brojnik*=(-1); r1.nazivnik*=(-1);}
    else if(r1.nazivnik<0){predznak=1; r1.nazivnik=r1.nazivnik*(-1);}
    else if(r1.brojnik<0){predznak=1; r1.brojnik=r1.brojnik*(-1);}
   // if(r1.brojnik>=r1.nazivnik){a=r1.brojnik; b=r1.nazivnik;}
   // else{a=r1.nazivnik; b=r1.brojnik;}
   a=r1.brojnik; b=r1.nazivnik;
    if(a==b){nzd=1;}
    else{
    while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
        nzd=ostatak;
        a=b;
        b=ostatak;
    }
    }
    r1.brojnik=r1.brojnik/nzd;
    r1.nazivnik=r1.nazivnik/nzd;
    if(predznak==1) r1.brojnik=r1.brojnik*(-1);
    return r1;
}
Razlomak &operator /=(Razlomak &r1, const Razlomak &r2){
    int predznak{0};
    long long int u{1}, r{1}, a,b,ostatak{1},kolicnik{0},nzd{1};
   // if(r1.nazivnik>=r2.nazivnik){a=r1.nazivnik; b=r2.nazivnik;}
//    else{a=r2.nazivnik; b=r1.nazivnik;}
    a=r1.nazivnik; b=r2.nazivnik;
    if(a==b){r=1;}
    else{
    while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
        r=ostatak;
        a=b;
        b=ostatak;
    }
    }
    ostatak=1;
   // if(r1.brojnik>=r2.brojnik){a=r1.brojnik; b=r2.brojnik;}
    //else{a=r2.brojnik; b=r1.brojnik;}
    a=r1.brojnik; b=r2.brojnik;
    if(a==b){u=1;}
    else{
    while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
        u=ostatak;
        a=b;
        b=ostatak;
    }
    }
    r1.brojnik=((double)r1.brojnik/u)*((double)r2.nazivnik/r);
    r1.nazivnik=((double)r1.nazivnik/r)*((double)r2.brojnik/u);
    ostatak=1;
    if(r1.brojnik<0 && r1.nazivnik<0){r1.brojnik*=(-1); r1.nazivnik*=(-1);}
    else if(r1.nazivnik<0){predznak=1; r1.nazivnik=r1.nazivnik*(-1);}
    else if(r1.brojnik<0){predznak=1; r1.brojnik=r1.brojnik*(-1);}
   // if(r1.brojnik>=r1.nazivnik){a=r1.brojnik; b=r1.nazivnik;}
   // else{a=r1.nazivnik; b=r1.brojnik;}
   a=r1.brojnik; b=r1.nazivnik;
    if(a==b){nzd=1;}
    else{
    while(ostatak!=0){
        kolicnik=a/b;
        ostatak=a-b*kolicnik;
        if(ostatak==0) break;
        nzd=ostatak;
        a=b;
        b=ostatak;
    }
    }
    r1.brojnik=r1.brojnik/nzd;
    r1.nazivnik=r1.nazivnik/nzd;
    if(predznak==1) r1.brojnik=r1.brojnik*(-1);
    return r1;
}
Razlomak &operator ++(Razlomak &r1){
    r1.brojnik=r1.brojnik+r1.nazivnik;
    return r1;
}
Razlomak &operator --(Razlomak &r1){
    r1.brojnik=r1.brojnik-r1.nazivnik;
    return r1;
}
Razlomak operator ++(Razlomak &r1, int){
    Razlomak pomocni(r1);
    r1.brojnik=r1.brojnik+r1.nazivnik;
    return pomocni;
}
Razlomak operator --(Razlomak &r1, int){
    Razlomak pomocni(r1);
    r1.brojnik=r1.brojnik-r1.nazivnik;
    return pomocni;
}
bool operator <(const Razlomak &r1, const Razlomak &r2){
 long double kolicnik1{0}, kolicnik2{0};
 kolicnik1=(long double)r1.brojnik/r1.nazivnik;
 kolicnik2=(long double)r2.brojnik/r2.nazivnik;
 return kolicnik1<kolicnik2;
}
bool operator >(const Razlomak &r1, const Razlomak &r2){
    long double kolicnik1{0}, kolicnik2{0};
    kolicnik1=(long double)r1.brojnik/r1.nazivnik;
    kolicnik2=(long double)r2.brojnik/r2.nazivnik;
    return kolicnik1>kolicnik2;
}
bool operator <=(const Razlomak &r1, const Razlomak &r2){
    long double kolicnik1{0}, kolicnik2{0};
    kolicnik1=(long double)r1.brojnik/r1.nazivnik;
    kolicnik2=(long double)r2.brojnik/r2.nazivnik;
    return kolicnik1<=kolicnik2;
}
bool operator >=(const Razlomak &r1, const Razlomak &r2){
    long double kolicnik1{0}, kolicnik2{0};
    kolicnik1=(long double)r1.brojnik/r1.nazivnik;
    kolicnik2=(long double)r2.brojnik/r2.nazivnik;
    return kolicnik1>=kolicnik2;
}
bool operator ==(const Razlomak &r1, const Razlomak &r2){
    long double kolicnik1{0}, kolicnik2{0};
    kolicnik1=(long double)r1.brojnik/r1.nazivnik;
    kolicnik2=(long double)r2.brojnik/r2.nazivnik;
    return Razlomak::JesuLiJednaki(kolicnik1,kolicnik2);
}
Razlomak::operator long double() const{
    long double iznos;
    iznos=(long double)this->brojnik/this->nazivnik;
    return iznos;
}
std::ostream &operator <<(std::ostream &tok, const Razlomak &r){
    if(r.nazivnik==1) tok<<r.brojnik;
    else tok <<r.brojnik<<"/"<<r.nazivnik;
    return tok;
}
std::istream &operator >>(std::istream &tok, Razlomak &r){
    int znak{0};
    tok >>std::ws;
    if(tok.peek()!='/'){
     tok >>r.brojnik;    
     r.nazivnik=1;
    }
    else{
        tok>>r.brojnik>>znak;
        if(znak!='/') tok.setstate(std::ios::failbit);
        tok>>r.nazivnik;
    }
    return tok;
}
int main ()
{
    try{
       // Razlomak r;
       Razlomak r1(124,4),r2(11,77);
       r1=r1-r2;
       std::cout <<r1;
      //  std::cout <<"Unesite razlomke: ";
      /*  Razlomak r, p, q;
        std::cin >>r;*/
  //      std::cout <<r<<" "<<p<<" "<<q;
        //std::cin >>brojnik>>nazivnik;
      //  std::cin.clear(); std::cin.ignore(100,'\n');
   /*  Razlomak r1(2337,3740);
     Razlomak r2(4014,5225);*/
  //   Razlomak r3(1);
   //  std::cout <<r1+r2<<std::endl;
//    std::cout <<r1-r2<<std::endl;
  //  std::cout <<r1*r2<<std::endl;
  //  std::cout <<r1/r2<<std::endl;
   //  operator-(r1);
    // std::cout <<r1<<std::endl;
    // operator+(r1);
    // std::cout <<r1<<std::endl;
     //r1+=r2;
   //  r1=r1+r2;
 //    std::cout <<r1<<std::endl;
    //r1-=r2;
   // r1=r2-r1;
   // r1=r1*r2;
   // r1/=r2;
   // r1+=r3;
  // r1-=1;
  //  std::cout <<r1++<<std::endl;
   //   std::cout <<--r1<<std::endl;
  //  if(r1>r2) std::cout<<"Prvi razlomak je veci od drugog";
 //    else std::cout <<"Prvi razlomak je manji od drugog";
  //  if(r1==r2) std::cout <<"Jednaki razlomci";
//    else std::cout <<"Razliciti razlomci";
    }
    catch(std::logic_error izuzetak1){
       std::cout<<izuzetak1.what(); 
    }
    catch(std::overflow_error izuzetak2){
        std::cout <<izuzetak2.what();
    }
	return 0;
}