/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <initializer_list>
#include <limits>

using namespace std;

class Razlomak {
    long long int brojnik,nazivnik;
    static long long int NZD(long long int b,long long int n);
    static bool Prekoracenje(long long int x,long long int y);
    static bool Prekoracenje2(long long int x,long long int y);
    static bool Jednaki(long double x,long double y);
    public:
    Razlomak(long long int b=0,long long int n=1);
    Razlomak(initializer_list<long long int>lista);
    long long int DajBrojnik()const{return brojnik;}
    long long int DajNazivnik()const {return nazivnik;}
    friend Razlomak operator + (const Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator - (const Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator * (const Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator / (const Razlomak &r1,const Razlomak &r2);
    Razlomak &operator +=(const Razlomak &r2);
    Razlomak &operator -=(const Razlomak &r2);
    Razlomak &operator *=(const Razlomak &r2);
    Razlomak &operator /=(const Razlomak &r2);
    friend Razlomak operator +(const Razlomak &r){return r;}
    friend Razlomak operator -(const Razlomak &r);
    friend Razlomak operator <(const Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator >(const Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator <=(const Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator >=(const Razlomak &r1,const Razlomak &r2);
    friend bool operator ==(const Razlomak &r1,const Razlomak &r2);
    friend bool operator !=(const Razlomak &r1,const Razlomak &r2);
    friend ostream &operator <<(ostream &tok, Razlomak r);
    friend istream &operator >>(istream &tok,Razlomak &r);
    operator long double () const;
};
long long int Razlomak:: NZD(long long int b,long long int n){
    if(b==0)return n;
    n=n%b;
    return NZD(n,b);
}
bool Razlomak::Prekoracenje(long long int x,long long int y){
    long long int M=numeric_limits<long long int>::max();
    long long int m=numeric_limits<long long int>::lowest();
    if(y>0){
        if(x>M-y)return true;
    }
    if(y<0){
        if(x<m-y)return true;
    }
    return false;
}
bool Razlomak::Prekoracenje2(long long int x,long long int y){
    long long int M=numeric_limits<long long int>::max();
    long long int m=numeric_limits<long long int>::lowest();
    if(y>0){
        if(x<m/y || x>M/y)return true;
    }
    if(y<0){
        if(x==m || -x>M/(-y) || -x<m/(-y))return true;
    }
    return false;
}
bool Razlomak::Jednaki(long double x,long double y){
    const double eps(1e-10);
    if(fabs(x-y)<=eps*(fabs(x)+fabs(y)))return true;
    return false;
}
Razlomak::Razlomak(long long int b,long long int n){
    if(n==0)throw logic_error("Nekorektan nazivnik");
    long long int vrati(Razlomak::NZD(abs(b),abs(n)));
    if((b>=0 && n>0) || (b<0 && n>0)){brojnik=b/vrati;nazivnik=n/vrati;}
    else {brojnik=(-1)*(b/vrati);nazivnik=(-1)*(n/vrati);}
}
Razlomak::Razlomak(initializer_list<long long int>lista){
    auto it=lista.begin();
    brojnik=*it;
    it++;
    nazivnik=*it;
}
Razlomak operator +(const Razlomak &r1,const Razlomak &r2){
    long long int r(Razlomak::NZD(r1.nazivnik,r2.nazivnik));
    if(Razlomak::Prekoracenje(r1.brojnik*(r2.nazivnik/r),r2.brojnik*(r1.nazivnik/r)))throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::Prekoracenje2(r1.nazivnik,r2.nazivnik/r))throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int privremeni_b=r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r);
    long long int privremeni_n=r1.nazivnik*(r2.nazivnik/r);
    Razlomak vrati(privremeni_b,privremeni_n);
    return vrati;
} 
Razlomak operator -(const Razlomak &r1,const Razlomak &r2){
    long long int r(Razlomak::NZD(r1.nazivnik,r2.nazivnik));
    if(Razlomak::Prekoracenje(r1.brojnik*(r2.nazivnik/r),r2.brojnik*(r1.nazivnik/r)))throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::Prekoracenje2(r1.nazivnik,r2.nazivnik/r))throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int privremeni_b=r1.brojnik*(r2.nazivnik/r)-r2.brojnik*(r1.nazivnik/r);
    long long int privremeni_n=r1.nazivnik*(r2.nazivnik/r);
    Razlomak vrati(privremeni_b,privremeni_n);
    return vrati;
}
Razlomak operator *(const Razlomak &r1,const Razlomak &r2){
    long long int t(Razlomak::NZD(r2.brojnik,r1.nazivnik)),s(Razlomak::NZD(r1.brojnik,r2.nazivnik));
    if(Razlomak::Prekoracenje2(r1.brojnik/s,r2.brojnik/t))throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::Prekoracenje2(r1.nazivnik/t,r2.nazivnik/s))throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int privremeni_b=(r1.brojnik/s)*(r2.brojnik/t);
    long long int privremeni_n=(r1.nazivnik/t)*(r2.nazivnik/s);
    Razlomak vrati(privremeni_b,privremeni_n);
    return vrati;
}
Razlomak operator /(const Razlomak &r1,const Razlomak &r2){
    long long int r(Razlomak::NZD(r1.nazivnik,r2.nazivnik));
    long long int u(Razlomak::NZD(r1.brojnik,r2.brojnik));
    long long int privremeni_b=(r1.brojnik/u)*(r2.nazivnik/r);
    long long int privremeni_n=(r1.nazivnik/r)*(r2.brojnik/u);
    Razlomak vrati(privremeni_b,privremeni_n);
    return vrati;
}
Razlomak &Razlomak::operator +=(const Razlomak &r2){
    long long int r(Razlomak::NZD(nazivnik,r2.nazivnik));
    if(Razlomak::Prekoracenje(brojnik*(r2.nazivnik/r),r2.brojnik*(nazivnik/r)))throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::Prekoracenje2(nazivnik,r2.nazivnik/r))throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int privremeni_b=brojnik*(r2.nazivnik/r)+r2.brojnik*(nazivnik/r);
    long long int privremeni_n=nazivnik*(r2.nazivnik/r);
    Razlomak vrati(privremeni_b,privremeni_n);
    brojnik=vrati.brojnik;nazivnik=vrati.nazivnik;
    return *this;
} 
Razlomak &Razlomak::operator -=(const Razlomak &r2){
    long long int r(Razlomak::NZD(nazivnik,r2.nazivnik));
    if(Razlomak::Prekoracenje(brojnik*(r2.nazivnik/r),r2.brojnik*(nazivnik/r)))throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::Prekoracenje2(nazivnik,r2.nazivnik/r))throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int privremeni_b=brojnik*(r2.nazivnik/r)-r2.brojnik*(nazivnik/r);
    long long int privremeni_n=nazivnik*(r2.nazivnik/r);
    Razlomak vrati(privremeni_b,privremeni_n);
    brojnik=vrati.brojnik;nazivnik=vrati.nazivnik;
    return *this;
}
Razlomak &Razlomak::operator *=(const Razlomak &r2){
    long long int t(Razlomak::NZD(r2.brojnik,nazivnik)),s(Razlomak::NZD(brojnik,r2.nazivnik));
    if(Razlomak::Prekoracenje2(brojnik/s,r2.brojnik/t))throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::Prekoracenje2(nazivnik/t,r2.nazivnik/s))throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int privremeni_b=(brojnik/s)*(r2.brojnik/t);
    long long int privremeni_n=(nazivnik/t)*(r2.nazivnik/s);
    Razlomak vrati(privremeni_b,privremeni_n);
    brojnik=vrati.brojnik;nazivnik=vrati.nazivnik;
    return *this;
}
Razlomak &Razlomak::operator /=(const Razlomak &r2){
    long long int r(Razlomak::NZD(nazivnik,r2.nazivnik));
    long long int u(Razlomak::NZD(brojnik,r2.brojnik));
    long long int privremeni_b=(brojnik/u)*(r2.nazivnik/r);
    long long int privremeni_n=(nazivnik/r)*(r2.brojnik/u);
    Razlomak vrati(privremeni_b,privremeni_n);
    brojnik=vrati.brojnik;nazivnik=vrati.nazivnik;
    return *this;
}
Razlomak operator <(const Razlomak &r1,const Razlomak &r2){
    long double privremeni1=(long double)r1.brojnik/(long double)r1.nazivnik;
    long double privremeni2=(long double)r2.brojnik/(long double)r2.nazivnik;
    if(privremeni1<privremeni2)return r1;
    else return r2;
}
Razlomak operator >(const Razlomak &r1,const Razlomak &r2){
    long double privremeni1=(long double)r1.brojnik/(long double)r1.nazivnik;
    long double privremeni2=(long double)r2.brojnik/(long double)r2.nazivnik;
    if(privremeni1>privremeni2)return r1;
    else return r2;
}
Razlomak operator <=(const Razlomak &r1,const Razlomak &r2){
    long double privremeni1=(long double)r1.brojnik/(long double)r1.nazivnik;
    long double privremeni2=(long double)r2.brojnik/(long double)r2.nazivnik;
    if(privremeni1>privremeni2)return r1;
    else return r2;
}
Razlomak operator >=(const Razlomak &r1,const Razlomak &r2){
    long double privremeni1=(long double)r1.brojnik/(long double)r1.nazivnik;
    long double privremeni2=(long double)r2.brojnik/(long double)r2.nazivnik;
    if(privremeni1>privremeni2)return r1;
    else return r2;
}
bool operator ==(const Razlomak &r1,const Razlomak &r2){
    long double privremeni1=(long double)r1.brojnik/(long double)r1.nazivnik;
    long double privremeni2=(long double)r2.brojnik/(long double)r2.nazivnik;
    if(Razlomak::Jednaki(privremeni1,privremeni2))return true;
    return false;
}
bool operator !=(const Razlomak &r1,const Razlomak &r2){
    long double privremeni1=(long double)r1.brojnik/(long double)r1.nazivnik;
    long double privremeni2=(long double)r2.brojnik/(long double)r2.nazivnik;
    if(!Razlomak::Jednaki(privremeni1,privremeni2))return true;
    return false;
}
ostream &operator <<(ostream &tok, Razlomak r){
    long long int vrati(Razlomak::NZD(abs(r.brojnik),abs(r.nazivnik)));
    if((r.brojnik>=0 && r.nazivnik>0) || (r.brojnik<0 && r.nazivnik>0)){r.brojnik=r.brojnik/vrati;r.nazivnik=r.nazivnik/vrati;}
    else {r.brojnik=(-1)*(r.brojnik/vrati);r.nazivnik=(-1)*(r.nazivnik/vrati);}
    if(r.nazivnik==1)tok<<r.brojnik;
    else {tok<<r.brojnik<<"/"<<r.nazivnik;}
    return tok;
}
istream &operator >>(istream &tok, Razlomak &r){
    char znak;
    tok>>ws;
    tok>>r.brojnik;
    if(tok.peek() != '/'){
        r.nazivnik=1;
    }
    else {
        tok>>znak>>r.nazivnik;
        if(znak!='/')tok.setstate(ios::failbit);
    }
    //if(tok.peek()!=' ' || tok.peek()!='\n' || tok.peek()!='\t' || tok.peek()!='\v' || tok.peek()!='\f')tok.setstate(ios::failbit);
    return tok;
}
Razlomak::operator long double () const{
    return (long double) brojnik/ (long double) nazivnik;
}
int main ()
{
    //Razlomak r(10,-15),r1;
    //cout<<r.DajBrojnik()<<" "<<r.DajNazivnik()<<endl;
    //cout<<r1.DajBrojnik()<<" "<<r1.DajNazivnik();
    //cin>>r1;cout<<r1;
    //Razlomak r(2337, 3740), q (4014, 5225);
    //cout << r << " + " << q << " = " <<r+q;
   //r-=q;cout<<r;
   //Razlomak r{2,3},r1{1,3};
   
  //Razlomak t(r<r1),t2(r>r1);
   //cout<<t<<t2;
   //bool a(t==t2);
   //cout<<a;
	return 0;
}