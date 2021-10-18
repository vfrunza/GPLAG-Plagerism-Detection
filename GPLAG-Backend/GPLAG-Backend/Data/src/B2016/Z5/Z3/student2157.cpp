/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljcivo* osobi koja ih pise
#include <iostream>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <limits>
const long long Mm=std::numeric_limits<long long int>::max();
const long long mm=std::numeric_limits<long long int>::min();
class Razlomak{
    long long int brojnik;
    long long int nazivnik;
    static long long int NZD(long long int &aa, long long int &bb);
    public:
    Razlomak():brojnik(0),nazivnik(1){};
    Razlomak(long long int x):brojnik(x),nazivnik(1){};
    long long int DajBrojnik()const{return brojnik;}
    long long int DajNazivnik()const{return nazivnik;}
    Razlomak(long long int x,long long int y);
    explicit operator long double()const{return double(brojnik)/nazivnik;}
    friend Razlomak operator* (const Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator/ (const Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator+ (const Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator- (const Razlomak &r1,const Razlomak &r2);
    friend Razlomak &operator +=(Razlomak &r1,const Razlomak &r2);
    friend Razlomak &operator -=(Razlomak &r1,const Razlomak &r2);
    friend Razlomak &operator *=(Razlomak &r1,const Razlomak &r2);
    friend Razlomak &operator /=(Razlomak &r1,const Razlomak &r2);
    friend Razlomak &operator ++(Razlomak &r1);
    friend Razlomak operator ++(Razlomak &r,int);
    friend Razlomak &operator --(Razlomak &r1);
    friend Razlomak operator --(Razlomak &r,int);
    friend Razlomak operator+(const Razlomak &r1){return Razlomak(r1.brojnik,r1.nazivnik);}
    friend Razlomak operator-(const Razlomak &r1);
    friend bool operator<(const Razlomak &r1,const Razlomak &r2);
    friend bool operator>(const Razlomak &r1,const Razlomak &r2);
    friend bool operator<=(const Razlomak &r1,const Razlomak &r2);
    friend bool operator>=(const Razlomak &r1,const Razlomak &r2);
    friend bool operator==(const Razlomak &r1,const Razlomak &r2);
    friend bool operator!=(const Razlomak &r1,const Razlomak &r2);
    friend std::ostream &operator<<(std::ostream &izlaz,const Razlomak &r);
    friend std::istream &operator>>(std::istream &ulaz,Razlomak &r);
    friend bool Limit(long long int x,long long int y,int slucaj);
};
bool Limit(long long int x,long long int y,int slucaj){
    if(slucaj==1){//sabiranje
        if(y>0 && x>Mm-y)return false;
        else if(y<0 && x<mm-y)return false;
        return true;
    }
    if(slucaj==2){//oduzimanje
        if(y<0 && x>Mm-y)return false;
        else if(y>0 && x<mm+y )return false;
        return true;
    }
    if(slucaj==3){//mnozenje
        if(y>0){
        if(x>Mm/y || x<mm*y)return false;}
        if(y<0){
        if(x==mm || -x>Mm/(-y) || -x<mm/(-y))return false;}
        return true;
    }
    return true;
}
Razlomak::Razlomak(long long int x,long long y){
    brojnik=x;nazivnik=y;
    if(y==0)throw std::logic_error("Nekorektan razlomak");
    if(x>0 && y<0){brojnik=x*(-1);nazivnik=fabs(y);}
    if(x<0 && y<0){brojnik=fabs(x);nazivnik=fabs(y);}
    NZD(brojnik,nazivnik);
}
long long int Razlomak::NZD(long long int &aa,long long int &bb){
    auto a=aa;
    auto b=bb;
    while(b!=0){
        auto t=b;
        b=a%b;
        a=t;
    }
    aa=aa/abs(a);bb=bb/abs(a);
    return a;
}
Razlomak operator* (const Razlomak &p1,const Razlomak &p2){
    auto r1=p1;auto r2=p2;
    Razlomak vrati;
    auto s=Razlomak::NZD(r1.brojnik,r2.nazivnik);
    auto t=Razlomak::NZD(r2.brojnik,r1.nazivnik);
    if(Limit((p1.brojnik/s),(p2.brojnik/t),3)==false)throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    if(Limit((p1.nazivnik/t),(p2.nazivnik/s),3)==false)throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    vrati.brojnik=(p1.brojnik/s)*(p2.brojnik/t);
    vrati.nazivnik=(p1.nazivnik/t)*(p2.nazivnik/s);
    return vrati;
}
Razlomak operator/ (const Razlomak &p1,const Razlomak &p2){
    auto r1=p1;auto r2=p2;
    Razlomak vrati;
    auto u=Razlomak::NZD(r1.brojnik,r2.brojnik);
    auto r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
    if(Limit((p1.brojnik/u),(p2.nazivnik/r),3)==false)throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    if(Limit((p1.nazivnik/r),(p2.brojnik/u),3)==false)throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    vrati.brojnik=(p1.brojnik/u)*(p2.nazivnik/r);
    vrati.nazivnik=(p1.nazivnik/r)*(p2.brojnik/u);
    return vrati;
}
Razlomak operator+ (const Razlomak &p1,const Razlomak &p2){
    auto r1=p1;auto r2=p2;
    Razlomak vrati;
    auto r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
    auto b1=p1.brojnik*(p2.nazivnik/r);auto b2=p2.brojnik*(p1.nazivnik/r);
    if(Limit(b1,b2,1)==false)throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    if(Limit(p1.nazivnik,p2.nazivnik/r,3)==false)throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    vrati.brojnik=p1.brojnik*(p2.nazivnik/r)+p2.brojnik*(p1.nazivnik/r);
    vrati.nazivnik=p1.nazivnik*(p2.nazivnik/r);
    Razlomak::NZD(vrati.brojnik,vrati.nazivnik);
    return vrati;
}
Razlomak operator- (const Razlomak &p1,const Razlomak &p2){
    auto r1=p1;auto r2=p2;
    Razlomak vrati;
    auto r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
    if(Limit(p1.brojnik*(p2.nazivnik/r),p2.brojnik*(p1.nazivnik/r),2)==false)throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    if(Limit(p1.nazivnik,(p2.nazivnik/r),3)==false)throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    vrati.nazivnik=p1.nazivnik*(p2.nazivnik/r);
    vrati.brojnik=p1.brojnik*(p2.nazivnik/r)-p2.brojnik*(p1.nazivnik/r);
    Razlomak::NZD(vrati.brojnik,vrati.nazivnik);
    return vrati;
}
Razlomak &operator+=(Razlomak &r1,const Razlomak &r2){
    try{
        r1=r1+r2;
    }
    catch(std::overflow_error x){throw x;}
    return r1;
}
Razlomak &operator -=(Razlomak &r1,const Razlomak &r2){
    try{r1=r1-r2;}
    catch(std::overflow_error x){throw x;}
    return r1;
}
Razlomak &operator *=(Razlomak &r1,const Razlomak &r2){
    try{
        r1=r1*r2;
    }
    catch(std::overflow_error x){throw x;}
    return r1;
}
Razlomak &operator /=(Razlomak &r1,const Razlomak &r2){    
    try{
        r1=r1/r2;
    }
    catch(std::overflow_error x){throw x;}
    return r1;
}
Razlomak operator -(const Razlomak &r1){
    if(r1.brojnik==mm)throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    return Razlomak(-r1.brojnik,r1.nazivnik);
}
Razlomak &operator ++(Razlomak &r1){
    try{r1=r1+Razlomak(1,1);}
    catch(std::overflow_error x){throw x;}
    return r1;
}
Razlomak operator ++(Razlomak &r1,int){
    auto vrati=r1;
    try{r1=r1+Razlomak(1,1);}
    catch(std::overflow_error x){throw x;}
    return vrati;
}
Razlomak &operator --(Razlomak &r1){
    try{r1=r1+Razlomak(-1,1);}
    catch(std::overflow_error x){throw x;}
    return r1;
}
Razlomak operator --(Razlomak &r1,int){
    auto vrati=r1;
    try{r1=r1+Razlomak(-1,1);}
    catch(std::overflow_error x){throw x;}
    return vrati;
}
bool operator<(const Razlomak &r1,const Razlomak &r2){
    return static_cast<long double>(r1) < static_cast<long double>(r2);
}
bool operator>(const Razlomak &r1,const Razlomak &r2){
    return static_cast<long double>(r1) > static_cast<long double>(r2);
}
bool operator<=(const Razlomak &r1,const Razlomak &r2){
    if(r1.brojnik==r2.brojnik && r1.nazivnik==r2.nazivnik)return true;
    return static_cast<long double>(r1) < static_cast<long double>(r2);
}
bool operator>=(const Razlomak &r1,const Razlomak &r2){
    if(r1.brojnik==r2.brojnik && r1.nazivnik==r2.nazivnik)return true;
    return static_cast<long double>(r1) > static_cast<long double>(r2);
}
bool operator==(const Razlomak &r1,const Razlomak &r2){
    if(r1.brojnik==r2.brojnik && r1.nazivnik==r2.nazivnik)return true;
    return false;
}
bool operator!=(const Razlomak &r1,const Razlomak &r2){
    if(r1.brojnik==r2.brojnik && r1.nazivnik==r2.nazivnik)return false;
    return true;
}
std::ostream &operator<<(std::ostream &izlaz,const Razlomak &r){
        if(r.nazivnik==1){
            izlaz<<r.brojnik;
        }
        else{
            izlaz<<r.brojnik<<"/"<<r.nazivnik;
        }
        return izlaz;
    }
std::istream &operator>>(std::istream &ulaz,Razlomak &r){
long long int x,y(1);
try{
    bool slucaj=false;
    ulaz>>std::ws;
    ulaz>>x;
    char z=ulaz.peek();
    if(z!='\n'){z=ulaz.get();}
    if(z=='\n' || z==' ' || z=='\t' || z=='\v' || z=='\f' || z=='\377'){
        slucaj=true;
    }
    else if(z=='/'){
        ulaz>>y;
        char z=ulaz.peek();
        slucaj=true;
        if(z=='\n' || z==' ' || z=='\t' || z=='\v' || z=='\f' || z=='\377'){
            slucaj=true;
        }
        else (ulaz.setstate(std::ios::failbit));
    }
    else ulaz.setstate(std::ios::failbit);
    if(slucaj){
        r.brojnik=x;
        r.nazivnik=y;
        Razlomak proba(x,y);
        Razlomak::NZD(r.brojnik,r.nazivnik);
    }
}
catch(std::logic_error x){
    throw x;
}
    return ulaz;
}
int main(){
    //provjera operatora
    Razlomak a(17,8);
    Razlomak b(17,89);
    Razlomak g;
    Razlomak a1{3,8};
    Razlomak b1(13,5);
    Razlomak c=a;
    auto r=a*b+a1/b1;
    //provjera operacija i ispisa
    std::cout<<a<<" * "<<b<<" + "<<g<<" + "<<a1<<" / "<<b1<<" = "<<r<<"\n";
    std::cout<<"Pretvorba razlomka u long double: "<<static_cast<long double>(r)<<std::endl;
    //provjera logickih operatora
    if(a>b)std::cout<<" a > b\n";
    if(b<a)std::cout<<" b < a\n";
    if(b!=a)std::cout<<" b != a\n";
    if(a==c)std::cout<<" a == c\n";
    try{
        //testiranje izuzetaka
        Razlomak test(mm);
        --test;
    }catch(std::overflow_error x){std::cout<<"Izuzetak: "<<x.what()<<"\n";}
    std::cout<<"Testiranje unosa razlomka: ";
    Razlomak unos1,unos2;
    std::cin>>unos1>>unos2;
    std::cout<<"Uneseni razlomci su: "<<unos1<<" "<<unos2<<"\n";
    unos1+=unos2;
    std::cout<<"R1+=R2 testiranje: "<< unos1 <<"\n";
    unos1-=unos2;
    std::cout<<"R1-=R2 testiranje: "<<unos1<<"\n";
    unos1*=unos2;
    std::cout<<"R1*=R2 testiranje: "<<unos1<<"\n";
    unos1/=unos2;
    std::cout<<"R1/=R2 testiranje: "<<unos1<<"\n";
    return 0;
}