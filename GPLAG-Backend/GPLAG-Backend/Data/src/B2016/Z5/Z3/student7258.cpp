/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <limits>

const long long int M(std::numeric_limits<int>::max());
const long long int m(std::numeric_limits<int>::min());

class Razlomak {
    long long int brojnik, nazivnik;
    static long long int NZD(long long int p, long long int q) {
        if(q==0) return p;
        p%=q;
        return NZD(q,p);
    }
    public:
    Razlomak (long long int brojnik=0, long long int nazivnik=1) {
        long long int nzd(NZD(brojnik,nazivnik));
        brojnik/=nzd;
        nazivnik/=nzd;
        if(nazivnik<0) { brojnik=-brojnik; nazivnik=abs(nazivnik); }
        else Razlomak::brojnik=brojnik; Razlomak::nazivnik=nazivnik;
    }
    long long int DajBrojnik() { return brojnik; }
    long long int DajNazivnik() { return nazivnik; }
    friend Razlomak operator + (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator - (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator * (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator / (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator - (const Razlomak &r1);
    friend Razlomak operator + (const Razlomak &r1);
    friend Razlomak operator += (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator -= (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator *= (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator /= (const Razlomak &r1, const Razlomak &r2);
    friend bool operator < (const Razlomak &r1, const Razlomak &r2);
    friend bool operator > (const Razlomak &r1, const Razlomak &r2);
    friend bool operator <= (const Razlomak &r1, const Razlomak &r2);
    friend bool operator >= (const Razlomak &r1, const Razlomak &r2);
    friend bool operator == (const Razlomak &r1, const Razlomak &r2);
    friend bool operator != (const Razlomak &r1, const Razlomak &r2);
    operator long double () const;
    friend std::ostream &operator << (std::ostream &tok, const Razlomak &r1);
    friend std::istream &operator >> (std::istream &tok, Razlomak &r1);
};

std::ostream &operator << (std::ostream &tok, const Razlomak &r1) {
        if(r1.nazivnik==1) return tok << r1.brojnik;
        else return tok << r1.brojnik << "/" << r1.nazivnik; 
    }

Razlomak::operator long double () const {
    return (long double) brojnik/nazivnik;
}

Razlomak operator + (const Razlomak &r1, const Razlomak &r2) {
    long long int r(r1.NZD(r1.nazivnik,r2.nazivnik));
    long long int p1(r1.brojnik), p2(r2.brojnik), q1(r1.nazivnik), q2(r2.nazivnik);
    long long int b=(p1*(q2/r)+p2*(q1/r));
    long long int n=q1*(q2/r);
    return Razlomak(b,n);
}
Razlomak operator - (const Razlomak &r1, const Razlomak &r2) {
    long long int r(r1.NZD(r1.nazivnik,r2.nazivnik));
    long long int p1(r1.brojnik), p2(r2.brojnik), q1(r1.nazivnik), q2(r2.nazivnik);
    long long int b=(p1*(q2/r)-p2*(q1/r));
    long long int n=q1*(q2/r);
    return Razlomak(b,n);
}
Razlomak operator * (const Razlomak &r1, const Razlomak &r2) {
    long long int s(r1.NZD(r1.brojnik,r2.nazivnik)),t(r1.NZD(r2.brojnik,r1.nazivnik));
    long long int p1(r1.brojnik), p2(r2.brojnik), q1(r1.nazivnik), q2(r2.nazivnik);
    long long int b=(p1/s)*(p2/t);
    long long int n=(q1/t)*(q2/s);
    return Razlomak(b,n);
}
Razlomak operator / (const Razlomak &r1, const Razlomak &r2) {
    long long int r(r1.NZD(r1.nazivnik,r2.nazivnik)),u(r1.NZD(r1.brojnik,r2.brojnik));
    long long int p1(r1.brojnik), p2(r2.brojnik), q1(r1.nazivnik), q2(r2.nazivnik);
    long long int b=(p1/u)*(q2/r);
    long long int n=(q1/r)*(p2/u);
    return Razlomak(b,n);
}
Razlomak operator - (const Razlomak &r1) {
    long long int pom(r1.brojnik);
    pom=-pom;
    return Razlomak(pom,r1.nazivnik);
}
Razlomak operator + (const Razlomak &r1) {
    return r1;
}
Razlomak operator += (Razlomak &r1, const Razlomak &r2) {
    r1=r1+r2;
    return r1;
}
Razlomak &operator -= (Razlomak &r1, const Razlomak &r2) {
    r1=r1-r2;
    return r1;
}
Razlomak &operator *= (Razlomak &r1, const Razlomak &r2) {
    r1=r1*r2;
    return r1;
}
Razlomak &operator /= (Razlomak &r1, const Razlomak &r2) {
    r1=r1/r2;
    return r1;
}
bool operator < (const Razlomak &r1, const Razlomak &r2) {
    return ((long double)r1.brojnik/r1.nazivnik)<((long double)r2.brojnik/r2.nazivnik);
}
bool operator > (const Razlomak &r1, const Razlomak &r2) {
    return ((long double)r1.brojnik/r1.nazivnik)>((long double)r2.brojnik/r2.nazivnik);
}
bool operator <= (const Razlomak &r1, const Razlomak &r2) {
    return ((long double)r1.brojnik/r1.nazivnik)<=((long double)r2.brojnik/r2.nazivnik);
}
bool operator >= (const Razlomak &r1, const Razlomak &r2) {
    return ((long double)r1.brojnik/r1.nazivnik)>=((long double)r2.brojnik/r2.nazivnik);
}
bool operator == (const Razlomak &r1, const Razlomak &r2) {
    return ((long double)r1.brojnik/r1.nazivnik)==((long double)r2.brojnik/r2.nazivnik);
}
bool operator != (const Razlomak &r1, const Razlomak &r2) {
    return !((long double)r1.brojnik/r1.nazivnik)==((long double)r2.brojnik/r2.nazivnik);
}
std::istream &operator >> (std::istream &tok, Razlomak &r1) {
    char znak;
    tok >> r1.brojnik;
    if(!tok) tok.setstate(std::ios::failbit);
    if(tok.peek()!='/') {
        return tok;
    }
    else {
        tok >> znak >> r1.nazivnik;
        if(!tok) tok.setstate(std::ios::failbit);
    }
    return tok;
}





int main ()
{
    Razlomak r,s;
    std::cout << "Unesite prvi razlomak: ";
    std::cin >> r;
    if(!(std::cin)) {
        std::cout << "Neispravno stanje" << std::endl;
        return 0;
    }
    std::cout << "Unesite drugi razlomak: ";
    std::cin >> s;
    if(!(std::cin)) { 
        std::cout << "Neispravno stanje" << std::endl;
        return 0;
    }
    std::cout << "Razlomak 1: " << r << std::endl;
    std::cout << "Razlomak 2: " << s << std::endl;
    std::cout << "Zbir razlomaka je " << r+s << ", a njihova razlika je " << r-s << "." << std::endl;
    std::cout << "Proizvod razlomaka je " << r*s << ", a njihov kolicnik je " << r/s << "." << std::endl;
    if(r<s) std::cout << "Prvi razlomak je manji od drugog!" << std::endl;
    else if(r>s) std::cout << "Prvi razlomak je veci od drugog!" << std::endl;
    else if(r==s) std::cout << "Razlomci su jednaki!" << std::endl;
	return 0;
}