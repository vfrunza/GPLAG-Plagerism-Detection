#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>

const long long int MAX(std::numeric_limits<long long int>::max());
const long long int MIN(std::numeric_limits<long long int>::min());

class Razlomak {
    long long int brojnik;
    long long int nazivnik;
    static int Nzd(long long int p = 0, long long int q = 1);
    static long long int Saberi(long long int x, long long int y);
    static long long int Oduzmi(long long int x, long long int y);
    static long long int Mnozi(long long int x, long long int y);
public:
    Razlomak(long long int p, long long int q);
    Razlomak(long double p) { brojnik = p; nazivnik = 1; }
    Razlomak() { brojnik = 0; nazivnik = 1; }
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    operator long double ()const;
    Razlomak operator -(){ if(this->brojnik == MIN) throw std::overflow_error("Nemoguce dobiti tacan rezultat"); return {-(this->brojnik), this->nazivnik}; }
    Razlomak operator +(){ return *this; }
    Razlomak &operator ++(){ return *this+=1; }
    Razlomak operator ++(int){ Razlomak k = *this; *this+=1; return k; }
    Razlomak &operator --(){ return *this-=1; }
    Razlomak operator --(int){ Razlomak k = *this; *this-=1; return k; }
    friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator+=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2);
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator <(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
    friend std::ostream &operator<<(std::ostream &tok, const Razlomak &r);
    friend std::istream &operator>>(std::istream &tok, Razlomak &r);
};
Razlomak::Razlomak(long long int p, long long int q){
    if(q == 0) throw std::logic_error("Nekorektan razlomak");
    long long int djelilac(Nzd(p,q));
    if(p < 0 && q < 0) { p = -p;  q = -q; }
    else if(q < 0) { p = -p; q = -q; }
    brojnik = p/djelilac; nazivnik = q/djelilac;
}
int Razlomak::Nzd(long long int p, long long int q){
    if(p < 0) p = -p; else if(q < 0) q = -q;
    if(p < q){
        long long int temp = p;
        p = q;
        q = temp;
    }
    long long int nzd(1);
    if(q == 0){
        nzd = p;
        return p;
    }
    else return Razlomak::Nzd(q, p % q);
}
long long int Razlomak::Saberi(long long int x, long long int y){
    if(y > 0)
        if(x > MAX-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(y < 0)
        if(x < MIN-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return x + y;
}
long long int Razlomak::Oduzmi(long long int x, long long int y){
    return Razlomak::Saberi(x, -y);
}
long long int Razlomak::Mnozi(long long int x, long long int y){
    if(y > 0)
        if((x < MIN / y) || (x > MAX / y))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(y < 0)
        if((x == -MAX - 1) ||(-x > MAX / (-y)) || (-x < MIN / (-y)))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return x * y;
}
Razlomak operator +(const Razlomak &r1, const Razlomak &r2){
    long long int r = Razlomak::Nzd(r1.nazivnik, r2.nazivnik);
    long long int gornji, donji;
    try{
    gornji = Razlomak::Saberi(Razlomak::Mnozi(r1.brojnik,(r2.nazivnik/r)), Razlomak::Mnozi(r2.brojnik,(r1.nazivnik/r)));
    donji = Razlomak::Mnozi(r1.nazivnik,r2.nazivnik / r);
    }catch(...){
        throw;
    }
    Razlomak r3(gornji, donji);
    return r3;
}
Razlomak operator -(const Razlomak &r1, const Razlomak &r2){
    long long int r(Razlomak::Nzd(r1.nazivnik, r2.nazivnik));
    long long int gornji, donji;
    try{
    gornji = Razlomak::Oduzmi(Razlomak::Mnozi(r1.brojnik, (r2.nazivnik/r)), Razlomak::Mnozi(r2.brojnik, (r1.nazivnik/r)));
    donji = Razlomak::Mnozi(r1.nazivnik, r2.nazivnik / r);
    }catch(...){
        throw;
    }
    Razlomak r3(gornji, donji);
    return r3;
}
Razlomak operator *(const Razlomak &r1, const Razlomak &r2){
    long long int s(Razlomak::Nzd(r1.brojnik, r2.nazivnik));
    long long int t(Razlomak::Nzd(r2.brojnik, r1.nazivnik));
    long long int gornji, donji;
    try{
    gornji = Razlomak::Mnozi((r1.brojnik/s), (r2.brojnik/t));
    donji = Razlomak::Mnozi((r1.nazivnik/t), (r2.nazivnik/s));
    }catch(...){
        throw;
    }
    Razlomak r3(gornji, donji);
    return r3;
}
Razlomak operator /(const Razlomak &r1, const Razlomak &r2){
    long long int u(Razlomak::Nzd(r1.brojnik, r2.brojnik));
    long long int r(Razlomak::Nzd(r1.nazivnik, r2.nazivnik));
    long long int gornji, donji;
    try{
    gornji = Razlomak::Mnozi((r1.brojnik/u), (r2.nazivnik/r));
    donji = Razlomak::Mnozi((r1.nazivnik/r), (r2.brojnik/u));
    }catch(...){
        throw;
    }
    Razlomak r3(gornji, donji);
    return r3;
}
Razlomak &operator *=(Razlomak &r1, const Razlomak &r2){
    return r1 = r1 * r2;
}
Razlomak &operator+=(Razlomak &r1, const Razlomak &r2){
    return r1 = r1 + r2;
}
Razlomak &operator -=(Razlomak &r1, const Razlomak &r2){
    return r1 = r1 - r2;
}
Razlomak &operator /=(Razlomak &r1, const Razlomak &r2){
    return r1 = r1 / r2;
}
bool operator <(const Razlomak &r1, const Razlomak &r2){
    long double p(r1.brojnik / (long double)r1.nazivnik); long double q(r2.brojnik / (long double)r2.nazivnik); return p < q;
}
bool operator >(const Razlomak &r1, const Razlomak &r2){
    long double p(r1.brojnik / (long double)r1.nazivnik); long double q(r2.brojnik / (long double)r2.nazivnik); return p > q;
}
bool operator <=(const Razlomak &r1, const Razlomak &r2){
    if(r1 > r2)return false; return true;
}
bool operator >=(const Razlomak &r1, const Razlomak &r2){
    if(r1 < r2)return false; return true;
}
std::ostream &operator <<(std::ostream &tok, const Razlomak &r){
    if(r.nazivnik == 1){
        tok << r.brojnik;
    }
    else{
        tok << r.brojnik << "/" << r.nazivnik;
    }
    return tok;
}
std::istream &operator >>(std::istream &tok, Razlomak &r){
    tok >> std::ws;
    char znak = tok.peek();
    if(!(znak >= '0' && znak <='9')) tok.setstate(std::ios::failbit);
    else{
    tok >> r.brojnik;
    r.nazivnik = 1;
    znak = tok.peek();
    if(znak == ' ' || znak == tok.eof() ||znak == '\n'){
        return tok;
    }
    else if(znak == '/'){
        tok.get();
        if(tok.peek())
        r.nazivnik = 1;
        tok >> r.nazivnik;
        if(tok.peek() != ' ' && tok.peek() != '\n' && tok.peek() != tok.eof()) tok.setstate(std::ios::failbit);
        }
    }
    r = Razlomak(r.brojnik, r.nazivnik);
    return tok;
}
bool operator ==(const Razlomak &r1, const Razlomak &r2){
    return (r1.brojnik == r2.brojnik && r1.nazivnik == r2.nazivnik);
}
bool operator !=(const Razlomak &r1, const Razlomak &r2){
    return (!(r1 == r2));
}
Razlomak::operator long double() const {
    long double novi;
    novi = (long double)this->brojnik / this->nazivnik;
    return novi;
}
int main ()
{
   try{
       Razlomak c{-1, MIN};
       std::cout << c; 
   }catch(std::logic_error iz){
       std::cout << iz.what();
   }catch(std::overflow_error iz){
       std::cout << iz.what();
   }
	return 0;
}