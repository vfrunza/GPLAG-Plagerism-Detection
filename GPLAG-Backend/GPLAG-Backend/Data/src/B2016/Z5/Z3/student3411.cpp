/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits> 
#include <string> 
class Razlomak{
    long long int nazivnik,brojnik;
    static long long int NZD(long long int x, long long int y);
    public:
    Razlomak(long long int brojn=0, long long int nazivn=1);
    long long int DajNazivnik() const{return nazivnik;}
    long long int DajBrojnik() const {return brojnik;}
    operator long double() const;
    friend Razlomak operator+(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator-(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator*(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator/(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator+=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator-=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator*=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator/=(Razlomak &r1, const Razlomak &r2);
    friend std::ostream &operator<<(std::ostream &tok, const Razlomak &r);
    friend std::istream &operator>>(std::istream &tok, Razlomak &r);
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator <(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >(const Razlomak &r1, const Razlomak &r2);
};
long long int NZD(long long int x, long long int y){
    if(x==0) return y;
    return NZD(y%x, x);
}
bool TestPrekoracenjaMnozenje(long long int x, long long int y){
    if(y>0 && ( (x<(std::numeric_limits<long long int>::min()/y)) || (x>std::numeric_limits<long long int>::max()/y))) return false;
    if(y<0 && (x==std::numeric_limits<long long int>::min() || (-x>std::numeric_limits<long long int>::max()/(-y)) || (-x<(std::numeric_limits<long long int>::min())/(-y)))) return false;
    return true;
}
bool TestPrekoracenjaOduzimanje(long long int x, long long int y){
    if(y<0 && x>std::numeric_limits<long long int>::max()+y) {return false;}
    if(y>0 && x<std::numeric_limits<long long int>::min()+y) {return false;}
    return true;
}
bool TestPrekoracenjaSabiranje(long long int x, long long int y){
     auto m=std::numeric_limits<long long int>::min();
     auto M=std::numeric_limits<long long int>::max();
     if(y>0 && x>M-y) return false;
     if(y<0 && x<m-y) return false;
     return true;
}
Razlomak operator+(const Razlomak &r1, const Razlomak &r2){
    long long int p1(r1.brojnik), q1(r1.nazivnik), q2(r2.nazivnik), p2(r2.brojnik);
    long long int r(NZD(q1,q2)), s(NZD(p1,q2)), t(NZD(p2,q1)), u(NZD(p1,p2));
    if(!TestPrekoracenjaMnozenje(p1,(q2/r))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(!TestPrekoracenjaMnozenje(p2,(q1/r))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(!TestPrekoracenjaMnozenje(q1,(q2/r))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    p1=p1*(q2/r);
    p2=p2*(q1/r);
    if(!TestPrekoracenjaSabiranje(p1,p2)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    Razlomak razlomak(p1+p2, q1*(q2/r));
    return razlomak;
}
Razlomak operator+=(Razlomak &r1, const Razlomak &r2){
    return r1=r1+r2;
}
Razlomak operator -(const Razlomak &r1, const Razlomak &r2){
    long long int p1(r1.brojnik), q1(r1.nazivnik), q2(r2.nazivnik), p2(r2.brojnik);
    long long int r(NZD(q1,q2));
    std::string s("Nemoguce dobiti tacan rezultat");
    if(!TestPrekoracenjaMnozenje(p1,(q2/r))) throw std::overflow_error(s);
    if(!TestPrekoracenjaMnozenje(p2,(q1/r))) throw std::overflow_error(s);
    if(!TestPrekoracenjaMnozenje(q1,(q2/r))) throw std::overflow_error(s);
    p1=p1*(q2/r);
    p2=p2*(q1/r);
    if(!TestPrekoracenjaOduzimanje(p1,p2)) {throw std::overflow_error(s);}
    Razlomak razlomak(p1-p2, q1*(q2/r));
    return razlomak;
}
Razlomak operator-=(Razlomak &r1, const Razlomak &r2){
    return r1=r1-r2;
}
Razlomak operator*(const Razlomak &r1, const Razlomak &r2){
    long long int p1(r1.brojnik), q1(r1.nazivnik), q2(r2.nazivnik), p2(r2.brojnik);
    long long int s(NZD(p1,q2)), t(NZD(p2,q1));
    p1=p1/s;
    q2=q2/s;
    p2=p2/t;
    q1=q1/t;
    std::string st("Nemoguce dobiti tacan rezultat");
    if(!TestPrekoracenjaMnozenje(p1,p2)) throw std::overflow_error(st);
    if(!TestPrekoracenjaMnozenje(q1,q2)) throw std::overflow_error(st);
    Razlomak razlomak(p1*p2,q1*q2);
    return razlomak;
}
Razlomak operator*=(Razlomak &r1, const Razlomak &r2){
    return r1=r1*r2;
}
Razlomak operator/(const Razlomak &r1, const Razlomak &r2){
    long long int p1(r1.brojnik), q1(r1.nazivnik), q2(r2.nazivnik), p2(r2.brojnik);
    long long int r(NZD(q1,q2)), u(NZD(p1,p2));
    p1=p1/u;
    p2=p2/u;
    q1=q1/r;
    q2=q2/r;
    std::string st("Nemoguce dobiti tacan rezultat");
    if(!TestPrekoracenjaMnozenje(p1,q2)) throw std::overflow_error(st);
    if(!TestPrekoracenjaMnozenje(q1,p2)) throw std::overflow_error(st);
    Razlomak razlomak(p1*q2,p2*q1);
    return razlomak;
}
Razlomak operator/=(Razlomak &r1, const Razlomak &r2){
    return r1=r1/r2;
}
std::ostream &operator<<(std::ostream &tok, const Razlomak &r){
    if(r.nazivnik==1){
        tok<<r.brojnik;
    }
    else{
        tok<<r.brojnik<<"/"<<r.nazivnik;
    }
    return tok;
}
std::istream &operator>>(std::istream &tok, Razlomak &r){
    char znak;
    //long long int brojn,nazivn;
    tok>>r.brojnik>>znak;
    if(znak!='/') tok.setstate(std::ios::failbit);
    tok>>r.nazivnik;
    return tok;
}
Razlomak::operator long double() const{
    long double x1(static_cast<long double>(brojnik)/static_cast<long double>(nazivnik));
    return x1;
}
bool operator ==(const Razlomak &r1, const Razlomak &r2){
    long double x1(static_cast<long double>(r1.brojnik)/static_cast<long double>(r1.nazivnik)), x2(static_cast<long double>(r2.brojnik)/static_cast<long double>(r2.nazivnik));
    return x1==x2;
}
bool operator <=(const Razlomak &r1, const Razlomak &r2){
    long double x1(static_cast<long double>(r1.brojnik)/static_cast<long double>(r1.nazivnik)), x2(static_cast<long double>(r2.brojnik)/static_cast<long double>(r2.nazivnik));
    return x1<=x2;
}
bool operator <(const Razlomak &r1, const Razlomak &r2){
    long double x1(static_cast<long double>(r1.brojnik)/static_cast<long double>(r1.nazivnik)), x2(static_cast<long double>(r2.brojnik)/static_cast<long double>(r2.nazivnik));
    return x1<x2;
}
bool operator >=(const Razlomak &r1, const Razlomak &r2){
    long double x1(static_cast<long double>(r1.brojnik)/static_cast<long double>(r1.nazivnik)), x2(static_cast<long double>(r2.brojnik)/static_cast<long double>(r2.nazivnik));
    return x1>=x2;
}
bool operator >(const Razlomak &r1, const Razlomak &r2){
    long double x1(static_cast<long double>(r1.brojnik)/static_cast<long double>(r1.nazivnik)), x2(static_cast<long double>(r2.brojnik)/static_cast<long double>(r2.nazivnik));
    return x1>x2;
}
long long int Razlomak::NZD(long long int x, long long int y){
    if(x==0) return y;
    return NZD(y%x, x);
}
Razlomak::Razlomak(long long int brojn, long long int nazivn){
    if(nazivn==0) throw std::logic_error("Nekorektan razlomak");
    auto nzd(NZD(brojn, nazivn));
    if(nzd<0) nzd*=-1;
    brojn/=nzd;
    nazivn/=nzd;
    if(nazivn<0 && brojn>=0){
        nazivn*=-1;
        brojn*=-1;
    }
    else if(nazivn<0 && brojn<=0){
        nazivn*=-1;
        brojn*=-1;
    }
    nazivnik=nazivn;
    brojnik=brojn;
}
int main ()
{
	return 0;
}