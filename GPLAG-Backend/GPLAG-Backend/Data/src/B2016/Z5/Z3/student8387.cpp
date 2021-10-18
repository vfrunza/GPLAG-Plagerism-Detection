#include <iostream>
#include <stdexcept>
#include <cmath>
class Razlomak{
    long long int brojnik,nazivnik;
    static long long int NZD(long long int a,long long int b);
    public:
        Razlomak(){brojnik=0;nazivnik=1;}
        Razlomak(long long int b,long long int n=1);
        long long int DajBrojnik() const{return brojnik;}
        long long int DajNazivnik() const{return nazivnik;}
        friend Razlomak operator +(const Razlomak &p1, const Razlomak &p2);
        friend Razlomak operator -(const Razlomak &p1, const Razlomak &p2);
        friend Razlomak operator *(const Razlomak &p1, const Razlomak &p2);
        friend Razlomak operator /(const Razlomak &p1, const Razlomak &p2);
        Razlomak operator+(){return *this;}
        Razlomak operator-(){return Razlomak(-brojnik,nazivnik);}
        Razlomak operator+=(const Razlomak &c);
        Razlomak operator-=(const Razlomak &c);
        Razlomak operator*=(const Razlomak &c);
        inline Razlomak operator/=(const Razlomak &c);
        inline Razlomak operator++(int);
        Razlomak &operator++();
        friend bool operator<(const Razlomak &p1,const Razlomak &p2);
        friend bool operator>(const Razlomak &p1,const Razlomak &p2);
        friend bool operator<=(const Razlomak &p1,const Razlomak &p2);
        friend bool operator>=(const Razlomak &p1,const Razlomak &p2);
        friend bool operator==(const Razlomak &p1,const Razlomak &p2);
        inline friend bool operator!=(const Razlomak &p1,const Razlomak &p2);
        friend std::ostream &operator <<(std::ostream &tok,const Razlomak &a);
        friend std::istream &operator >>(std::istream &tok, Razlomak &a);
        operator long double () const{return (long double)brojnik/nazivnik;}
};
long long int Razlomak::NZD(long long int a,long long int b){
    while(b!=0){
        long long int tmp=a;
        a=b;
        b=tmp%b;
    }
    return a;
}
Razlomak::Razlomak(long long int b,long long int n){
    if(n==0)throw std::logic_error("Nekorektan razlomak");
    long long int m;
    if(b<n)m=b;
    else m=n;
    int tmp=b;
    if(NZD(b,n)<=m){
        b/=NZD(b,n);
        n/=NZD(tmp,n);
    }
    if((b<0&&n>0) || (n<0&&b>=0)){b=-std::abs(b);n=std::abs(n);}
    if(b<0&&n<0){b=std::abs(b);n=std::abs(n);}
    brojnik=b;
    nazivnik=n;
}
Razlomak operator +(const Razlomak &p1, const Razlomak &p2){
    long long int r=Razlomak::NZD(p1.nazivnik,p2.nazivnik);
    long long int b=p1.brojnik*(p2.nazivnik/r)+p2.brojnik*(p1.nazivnik/r);
    long long int n=p1.nazivnik*p2.nazivnik;
    return Razlomak(b,n);
}
Razlomak operator -(const Razlomak &p1, const Razlomak &p2){
    long long int r=Razlomak::NZD(p1.nazivnik,p2.nazivnik);
    long long int b=p1.brojnik*(p2.nazivnik/r)-p2.brojnik*(p1.nazivnik/r);
    long long int n=p1.nazivnik*p2.nazivnik;
    return Razlomak(b,n);
}
Razlomak operator *(const Razlomak &p1, const Razlomak &p2){
    long long int s=Razlomak::NZD(p1.brojnik,p2.nazivnik);
    long long int t=Razlomak::NZD(p2.brojnik,p1.nazivnik);
    long long int b=(p1.brojnik/s)*(p2.brojnik/t);
    long long int n=(p1.nazivnik/t)*(p2.nazivnik/s);
    return Razlomak(b,n);
}
Razlomak operator /(const Razlomak &p1, const Razlomak &p2){
    long long int r=Razlomak::NZD(p1.nazivnik,p2.nazivnik);
    long long int u=Razlomak::NZD(p1.brojnik,p2.brojnik);
    long long int b=(p1.brojnik/u)*(p2.nazivnik/r);
    long long int n=(p1.nazivnik/r)*(p2.brojnik/u);
    return Razlomak(b,n);
}
Razlomak Razlomak::operator+=(const Razlomak &c){
    return (*this)+c;
}
Razlomak Razlomak::operator-=(const Razlomak &c){
    return (*this)-c;
}
Razlomak Razlomak::operator*=(const Razlomak &c){
    return (*this)*c;
}
Razlomak Razlomak::operator/=(const Razlomak &c){
    return (*this)/c;
}
Razlomak Razlomak::operator++(int){
    Razlomak t(nazivnik,nazivnik);
    Razlomak vrati(*this);
    (*this)+=t;
    return vrati;
}
Razlomak &Razlomak::operator++(){
    Razlomak t(nazivnik,nazivnik);
    (*this)+=t;
    return *this;
}
bool operator<(const Razlomak &p1,const Razlomak &p2){
    long long int r=Razlomak::NZD(p1.brojnik,p2.brojnik);
    long long int s=Razlomak::NZD(p1.nazivnik,p2.nazivnik);
    long double a=(p1.brojnik/(long double)r)*(p2.nazivnik/(long double)s);
    long double b=(p2.brojnik/(long double)r)*(p1.nazivnik/(long double)s);
    return a<b;
}
bool operator>(const Razlomak &p1,const Razlomak &p2){
    long long int r=Razlomak::NZD(p1.brojnik,p2.brojnik);
    long long int s=Razlomak::NZD(p1.nazivnik,p2.nazivnik);
    long double a=(p1.brojnik/(long double)r)*(p2.nazivnik/(long double)s);
    long double b=(p2.brojnik/(long double)r)*(p1.nazivnik/(long double)s);
    return a>b;
}
bool operator<=(const Razlomak &p1,const Razlomak &p2){
    long long int r=Razlomak::NZD(p1.brojnik,p2.brojnik);
    long long int s=Razlomak::NZD(p1.nazivnik,p2.nazivnik);
    long double a=(p1.brojnik/(long double)r)*(p2.nazivnik/(long double)s);
    long double b=(p2.brojnik/(long double)r)*(p1.nazivnik/(long double)s);
    return a<=b;
}
bool operator>=(const Razlomak &p1,const Razlomak &p2){
    long long int r=Razlomak::NZD(p1.brojnik,p2.brojnik);
    long long int s=Razlomak::NZD(p1.nazivnik,p2.nazivnik);
    long double a=(p1.brojnik/(long double)r)*(p2.nazivnik/(long double)s);
    long double b=(p2.brojnik/(long double)r)*(p1.nazivnik/(long double)s);
    return a>=b;
}
bool operator==(const Razlomak &p1,const Razlomak &p2){
    long long int r=Razlomak::NZD(p1.brojnik,p2.brojnik);
    long long int s=Razlomak::NZD(p1.nazivnik,p2.nazivnik);
    long double a=(p1.brojnik/(long double)r)*(p2.nazivnik/(long double)s);
    long double b=(p2.brojnik/(long double)r)*(p1.nazivnik/(long double)s);
    return a==b;
}
bool operator!=(const Razlomak &p1,const Razlomak &p2){
    return !(p1==p2);
}
std::ostream &operator <<(std::ostream &tok,const Razlomak &a){
    if(a.nazivnik==1)tok<<a.brojnik;
    else tok<<a.brojnik<<"/"<<a.nazivnik;
    return tok;
}
std::istream &operator>>(std::istream &tok, Razlomak &a){
    char znak;
    tok>>std::ws;
    if(tok.peek() != '/'){
        tok>>a.brojnik;
        a.nazivnik=1;
    }
    else{
        tok>>a.brojnik>>znak;
        if(znak!='/')tok.setstate(std::ios::failbit);
        tok>>a.nazivnik;
    }
    return tok;
}
int main ()
{
    Razlomak r, p, q;
    std::cin >> r; //5/17
    std::cout << r << std::endl;
    std::cin.clear(); std::cin.ignore (100, '\n');
    std::cin >> r >> p >> q; //10 20 30 -> 10/1 20/1 30/1
    std::cout << r << " " << p << " " << q<< std::endl;
	return 0;
}