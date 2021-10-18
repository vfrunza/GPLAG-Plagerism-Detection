/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>
const double E=1e-10;
class Razlomak {
    long long int brojnik, nazivnik;
    static long long int NZD(long long int brojnik, long long int nazivnik) {
        brojnik=fabs(brojnik); nazivnik=fabs(nazivnik);
        while(brojnik!=nazivnik) {
            if(brojnik>nazivnik)
                brojnik-=nazivnik;
            else
                nazivnik-=brojnik;
        } 
        return brojnik;
    }
    static long long int M, m;
    static bool prekpl(long long int x, long long int y) {              //prekoracenje+
        if(y>0) {if(x>M-y) return true; }             //istina za prekoracenje;
        if(y<0) {if(x<m-y) return true; }
        return false;
    }
    static bool prekmi(long long int x, long long int y) {              //prekoracenje-
        if(y<0) {if(x>M+y) return true; }
        if(y>0) {if(x<m+y) return true; }
        return false;
    }
    static bool prekmn(long long int x, long long int y) {              //prekoracenje*
        if(y>0) { if(x<m/y || x>M/y) return true; }
        if(y<0) { if(x==m || -x>M/(-y) || -x<m/(-y)) return true; }
        return false;
    }
    public:
        Razlomak() { brojnik=0; nazivnik=1; }
        Razlomak(long long int brojnik) { Razlomak::brojnik=brojnik; Razlomak::nazivnik=1; }
        Razlomak(long long int brojnik, long long int nazivnik);
        long long int DajBrojnik() const { return brojnik; }
        long long int DajNazivnik() const { return nazivnik; }
        friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator +(Razlomak r1);
        friend Razlomak operator -(Razlomak r1);
        friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2);//vidjet da li ih treba mecat kao fje clanice
        friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2);
        friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2);
        friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2);
        friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
        friend bool operator !=(const Razlomak &r1, const Razlomak &r2);
        friend bool operator <(const Razlomak &r1, const Razlomak &r2);
        friend bool operator >(const Razlomak &r1, const Razlomak &r2);
        friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
        friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak &operator ++(Razlomak &r);
        friend Razlomak &operator --(Razlomak &r);
        friend Razlomak operator ++(Razlomak &r, int);
        friend Razlomak operator --(Razlomak &r, int);
        friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r);
        friend std::istream &operator >>(std::istream &tok, Razlomak &r);
        operator long double () const;
};
long long int Razlomak::M=std::numeric_limits<long long int>::max();
long long int Razlomak::m=std::numeric_limits<long long int>::min();
Razlomak::Razlomak(long long int brojnik, long long int nazivnik) {
    if(fabs(nazivnik-0)<E) throw std::logic_error("Nekorektan razlomak");
    if(brojnik<0 && nazivnik<0) { brojnik=-brojnik; nazivnik=-nazivnik; }
    if(nazivnik<0) { brojnik=-brojnik; nazivnik=-nazivnik; }
    long long int nzd=NZD(brojnik, nazivnik);
    Razlomak::brojnik=brojnik/nzd; Razlomak::nazivnik=nazivnik/nzd;
}
Razlomak operator +(const Razlomak &r1, const Razlomak &r2) {
    long long int brojnik, nazivnik;
    auto r=Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    brojnik=r1.brojnik*(r2.nazivnik/r) + r2.brojnik*(r1.nazivnik/r);
    nazivnik=r1.nazivnik*(r2.nazivnik/r);
    return {brojnik, nazivnik};
}
Razlomak operator -(const Razlomak &r1, const Razlomak &r2) {
    long long int brojnik, nazivnik;
    auto r=Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    brojnik=r1.brojnik*(r2.nazivnik/r) - r2.brojnik*(r1.nazivnik/r);
    nazivnik=r1.nazivnik*(r2.nazivnik/r);
    return {brojnik, nazivnik};
}
Razlomak operator *(const Razlomak &r1, const Razlomak &r2) {
    long long int brojnik, nazivnik;
    auto s=Razlomak::NZD(r1.brojnik, r2.nazivnik);
    auto t=Razlomak::NZD(r2.brojnik, r1.nazivnik);
    brojnik=(r1.brojnik/s)*(r2.brojnik/t);
    nazivnik=(r1.nazivnik/t)*(r2.nazivnik/s);
    return {brojnik, nazivnik};
}
Razlomak operator /(const Razlomak &r1, const Razlomak &r2) {
    long long int brojnik, nazivnik;
    auto u=Razlomak::NZD(r1.brojnik, r2.brojnik);
    auto r=Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    brojnik=(r1.brojnik/u)*(r2.nazivnik/r);
    nazivnik=(r1.nazivnik/r)*(r2.brojnik/u);
    return {brojnik, nazivnik};
}
Razlomak operator +(Razlomak r) {
    return {r.brojnik, r.nazivnik}; 
}
Razlomak operator -(Razlomak r) {
    r.brojnik=-r.brojnik;
    return { r.brojnik, r.nazivnik};
}
Razlomak &operator +=(Razlomak &r1, const Razlomak &r2) {
    auto r=Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    r1.brojnik=r1.brojnik*(r2.nazivnik/r) + r2.brojnik*(r1.nazivnik/r);
    r1.nazivnik=r1.nazivnik*(r2.nazivnik/r);
    auto pomocnibrojnik=r1.brojnik;
    r1.brojnik/=Razlomak::NZD(r1.brojnik, r1.nazivnik);
    r1.nazivnik/=Razlomak::NZD(pomocnibrojnik, r1.nazivnik);
    return r1;
}
Razlomak &operator -=(Razlomak &r1, const Razlomak &r2) {
    auto r=Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    r1.brojnik=r1.brojnik*(r2.nazivnik/r) - r2.brojnik*(r1.nazivnik/r);
    r1.nazivnik=r1.nazivnik*(r2.nazivnik/r);
    auto pomocnibrojnik=r1.brojnik;
    r1.brojnik/=Razlomak::NZD(r1.brojnik, r1.nazivnik);
    r1.nazivnik/=Razlomak::NZD(pomocnibrojnik, r1.nazivnik);
    return r1;
}
Razlomak &operator *=(Razlomak &r1, const Razlomak &r2) {
    auto s=Razlomak::NZD(r1.brojnik, r2.nazivnik);
    auto t=Razlomak::NZD(r2.brojnik, r1.nazivnik);
    r1.brojnik=(r1.brojnik/s)*(r2.brojnik/t);
    r1.nazivnik=(r1.nazivnik/t)*(r2.nazivnik/s);
    auto pomocnibrojnik=r1.brojnik;
    r1.brojnik/=Razlomak::NZD(r1.brojnik, r1.nazivnik);
    r1.nazivnik/=Razlomak::NZD(pomocnibrojnik, r1.nazivnik);
    return r1;
}
Razlomak &operator /=(Razlomak &r1, const Razlomak &r2) {
    auto u=Razlomak::NZD(r1.brojnik, r2.brojnik);
    auto r=Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    r1.brojnik=(r1.brojnik/u)*(r2.nazivnik/r);
    r1.nazivnik=(r1.nazivnik/r)*(r2.brojnik/u);
    auto pomocnibrojnik=r1.brojnik;
    r1.brojnik/=Razlomak::NZD(r1.brojnik, r1.nazivnik);
    r1.nazivnik/=Razlomak::NZD(pomocnibrojnik, r1.nazivnik);
    return r1;
}
bool operator ==(const Razlomak &r1, const Razlomak &r2) {
    return r1.brojnik==r2.brojnik && r1.nazivnik==r2.nazivnik;
}
inline bool operator !=(const Razlomak &r1, const Razlomak &r2) {
    return !(r1==r2);
}
bool operator <(const Razlomak &r1, const Razlomak &r2) {
    long double r1brojnik=r1.brojnik;
    long double r1nazivnik=r1.nazivnik;
    long double r2brojnik=r2.brojnik;
    long double r2nazivnik=r2.nazivnik;
    return r1brojnik/r1nazivnik < r2brojnik/r2nazivnik;
}
bool operator >(const Razlomak &r1, const Razlomak &r2) {
    long double r1brojnik=r1.brojnik;
    long double r1nazivnik=r1.nazivnik;
    long double r2brojnik=r2.brojnik;
    long double r2nazivnik=r2.nazivnik;
    return r1brojnik/r1nazivnik > r2brojnik/r2nazivnik;
}
bool operator <=(const Razlomak &r1, const Razlomak &r2) {
    long double r1brojnik=r1.brojnik;
    long double r1nazivnik=r1.nazivnik;
    long double r2brojnik=r2.brojnik;
    long double r2nazivnik=r2.nazivnik;
    return r1brojnik/r1nazivnik <= r2brojnik/r2nazivnik;
}
bool operator >=(const Razlomak &r1, const Razlomak &r2) {
    long double r1brojnik=r1.brojnik;
    long double r1nazivnik=r1.nazivnik;
    long double r2brojnik=r2.brojnik;
    long double r2nazivnik=r2.nazivnik;
    return r1brojnik/r1nazivnik >= r2brojnik/r2nazivnik;
}
Razlomak &operator ++(Razlomak &r) {
    r.brojnik+=r.nazivnik;
    auto pomocnibrojnik=r.brojnik;
    r.brojnik/=Razlomak::NZD(r.brojnik, r.nazivnik);
    r.nazivnik/=Razlomak::NZD(pomocnibrojnik, r.nazivnik);
    return r;
}
Razlomak &operator --(Razlomak &r) {
    r.brojnik-=r.nazivnik;
    auto pomocnibrojnik=r.brojnik;
    r.brojnik/=Razlomak::NZD(r.brojnik, r.nazivnik);
    r.nazivnik/=Razlomak::NZD(pomocnibrojnik, r.nazivnik);
    return r;
}
Razlomak operator ++(Razlomak &r, int) {
    Razlomak pomocni(r);
    r.brojnik+=r.nazivnik;
    auto pomocnibrojnik=r.brojnik;
    r.brojnik/=Razlomak::NZD(r.brojnik, r.nazivnik);
    r.nazivnik/=Razlomak::NZD(pomocnibrojnik, r.nazivnik);
    return pomocni;
}
Razlomak operator --(Razlomak &r, int) {
    Razlomak pomocni(r);
    r.brojnik-=r.nazivnik;
    auto pomocnibrojnik=r.brojnik;
    r.brojnik/=Razlomak::NZD(r.brojnik, r.nazivnik);
    r.nazivnik/=Razlomak::NZD(pomocnibrojnik, r.nazivnik);
    return pomocni;
}
std::ostream &operator <<(std::ostream &tok, const Razlomak &r) {
    if(fabs(r.brojnik-0)<E) return tok << r.brojnik;
    else if(fabs(r.nazivnik-1)<E) return tok << r.brojnik;
    return tok << r.brojnik << "/" << r.nazivnik;
}
std::istream &operator >>(std::istream &tok, Razlomak &r) {
    char znak;
    tok>>std::ws;
    tok>> r.brojnik;
    if(tok.peek()!='/') {
        r.nazivnik=1;
        return tok;
    }
    else {
        tok >> znak;
        tok>> r.nazivnik;
        if(tok.peek()!=' ' && tok.peek()!='\n' && tok.peek()!='\t' && tok.peek()!='\v' && tok.peek()!='\f' && tok.peek()!='\r') tok.setstate(std::ios::failbit);
        auto pomocnibrojnik=r.brojnik;
        r.brojnik/=Razlomak::NZD(r.brojnik, r.nazivnik);
        r.nazivnik/=Razlomak::NZD(pomocnibrojnik, r.nazivnik);
        return tok;
    }
}
Razlomak::operator long double () const {
    long double rbroj(brojnik);
    long double rnaziv(nazivnik);
    return rbroj/rnaziv;
} 
int main (){
    Razlomak r, r1, r2;
    std::cout << "Unesite razlomak: ";
    std::cin >> r2;
    std::cout << "Unijeli ste razlomak: " << r2;
    std::cout << "\nUnesite dva razlomka na koje zelite primjenit sve aritmeticke operacije :-P: ";
    std::cin >> r >> r1;
    r2=r+r1;
    std::cout << "Za razlomke koje ste unijeli:\nZbir: " << r2;
    r2=r-r1;
    std::cout << "\nRazlika: " << r2;
    r2=r*r1;
    std::cout << "\nProizvod: " << r2;
    r2=r/r1;
    std::cout << "\nKolicnik: " << r2;
	return 0;
}