#include <iostream>
#include <stdexcept>
#include <cmath>

class Razlomak {
    long long int brojnik, nazivnik;
    static long long int NZD (long long int p, long long int q) {
        return q == 0 ? p : NZD(q, p%q);
    }
    long double DajAproksimaciju() const {
        return static_cast<long double>(this->DajBrojnik()) / this->DajNazivnik();
    } 
public: 
    Razlomak (long long int brojnik = 0, long long int nazivnik = 1) {
        if (nazivnik == 0) throw std::logic_error("Nekorektan razlomak");
        if ((brojnik >= 0 && nazivnik > 0) || (brojnik < 0 && nazivnik < 0)) {
            brojnik = std::abs(brojnik); nazivnik = std::abs(nazivnik);
            Razlomak::brojnik = brojnik / Razlomak::NZD(brojnik, nazivnik);
            Razlomak::nazivnik = nazivnik / Razlomak::NZD(brojnik, nazivnik);
        } else {
            brojnik = std::abs(brojnik); nazivnik = std::abs(nazivnik);
            Razlomak::brojnik = -brojnik / Razlomak::NZD(brojnik, nazivnik);
            Razlomak::nazivnik = nazivnik / Razlomak::NZD(brojnik, nazivnik);
        }
    }
    long long int DajBrojnik() const {return brojnik;}
    long long int DajNazivnik() const {return nazivnik;}
    
    friend Razlomak operator +(const Razlomak &prvi, const Razlomak &drugi);    //done
    friend Razlomak operator -(const Razlomak &prvi, const Razlomak &drugi);    //done
    friend Razlomak operator *(const Razlomak &prvi, const Razlomak &drugi);    //done
    friend Razlomak operator /(const Razlomak &prvi, const Razlomak &drugi);    //done
    friend Razlomak operator +(const Razlomak &prvi) {return prvi;}             //done
    friend Razlomak operator -(const Razlomak &prvi);                           //done
    friend Razlomak &operator +=(Razlomak &prvi, const Razlomak &drugi);        //done
    friend Razlomak &operator -=(Razlomak &prvi, const Razlomak &drugi);        //done
    friend Razlomak &operator *=(Razlomak &prvi, const Razlomak &drugi);        //done
    friend Razlomak &operator /=(Razlomak &prvi, const Razlomak &drugi);        //done
    
    Razlomak &operator ++() {return *this += 1;}
    Razlomak operator ++(int) {
        Razlomak tmp(*this);
        *this += 1;
        return tmp;
    }
    Razlomak &operator --() {return *this -= 1;}
    Razlomak operator --(int) {
        Razlomak tmp(*this);
        *this -= 1;
        return tmp;
    }
    
    friend bool operator <(const Razlomak &prvi, const Razlomak &drugi);        //done
    friend bool operator >(const Razlomak &prvi, const Razlomak &drugi);        //done
    friend bool operator <=(const Razlomak &prvi, const Razlomak &drugi);       //done
    friend bool operator >=(const Razlomak &prvi, const Razlomak &drugi);       //done
    friend bool operator ==(const Razlomak &prvi, const Razlomak &drugi);       //done
    friend bool operator !=(const Razlomak &prvi, const Razlomak &drugi);       //done
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &prvi);  //done
    friend std::istream &operator >>(std::istream &tok, Razlomak &prvi);        //done
    
    operator long double () const {return this->DajAproksimaciju();}
};

std::istream &operator >>(std::istream &tok, Razlomak &prvi) {
    char znak;
    long long int gore, dole;
    tok >> std::ws;
    tok >> gore;
    if (!tok) tok.setstate(std::ios::failbit);
    znak = tok.peek();
    if (znak == '\n' || znak == '\t' || znak == '\v' || znak == '\f' || znak == ' ' || znak == EOF) {
        dole = 1;
        znak = tok.peek();
        if (!(znak == ' ' || znak == 10 || znak == EOF)) tok.setstate(std::ios::failbit);
        prvi = Razlomak(gore, dole);
    } else if (znak == '/') {
        tok >> znak;
        tok >> dole;
        if (!tok) tok.setstate(std::ios::failbit);
        znak = tok.peek();
        if (!(znak == ' ' || znak == 10 || znak == EOF)) tok.setstate(std::ios::failbit);
        prvi = Razlomak(gore, dole);
    } else tok.setstate(std::ios::failbit);
    return tok;
}

std::ostream &operator <<(std::ostream &tok, const Razlomak &prvi) {
    if (prvi.DajNazivnik() == 1) return tok << prvi.DajBrojnik();
    return tok << prvi.DajBrojnik() << "/" << prvi.DajNazivnik();
}

bool operator !=(const Razlomak &prvi, const Razlomak &drugi) {
    if (!(prvi == drugi)) return true;
    return false;
}

bool operator ==(const Razlomak &prvi, const Razlomak &drugi) {
    if (prvi.DajBrojnik() == drugi.DajBrojnik() && prvi.DajNazivnik() == drugi.DajNazivnik()) return true;
    return false;
}

bool operator >=(const Razlomak &prvi, const Razlomak &drugi) {
    if (prvi.DajAproksimaciju() / drugi.DajAproksimaciju() >= 1) return true;
    return false;
}

bool operator <=(const Razlomak &prvi, const Razlomak &drugi) {
    if (prvi.DajAproksimaciju() / drugi.DajAproksimaciju() <= 1) return true;
    return false;
}

bool operator >(const Razlomak &prvi, const Razlomak &drugi) {
    if (prvi.DajAproksimaciju() / drugi.DajAproksimaciju() > 1) return true;
    return false;
}

bool operator <(const Razlomak &prvi, const Razlomak &drugi) {
    if (prvi.DajAproksimaciju() / drugi.DajAproksimaciju() < 1) return true;
    return false;
}

inline Razlomak &operator /=(Razlomak &prvi, const Razlomak &drugi) {
    prvi = prvi / drugi;
    return prvi;
}

inline Razlomak &operator *=(Razlomak &prvi, const Razlomak &drugi) {
    prvi = prvi * drugi;
    return prvi;
}

inline Razlomak &operator -=(Razlomak &prvi, const Razlomak &drugi) {
    prvi = prvi - drugi;
    return prvi;
}

inline Razlomak &operator +=(Razlomak &prvi, const Razlomak &drugi) {
    prvi = prvi + drugi;
    return prvi;
}

Razlomak operator -(const Razlomak &prvi) {
    //dodati overflow check
    Razlomak r(prvi);
    r.brojnik = - r.brojnik;
    return r;
}

Razlomak operator /(const Razlomak &prvi, const Razlomak &drugi) {
    //dodati overflow check
    long long int u = Razlomak::NZD(prvi.DajBrojnik(), drugi.DajBrojnik());
    long long int r = Razlomak::NZD(prvi.DajNazivnik(), drugi.DajNazivnik());
    long long int gore = (prvi.DajBrojnik() / u) * (drugi.DajNazivnik() / r);
    long long int dole = (prvi.DajNazivnik() / r) * (drugi.DajBrojnik() / u);
    Razlomak r1(gore, dole);
    return r1;
}

Razlomak operator *(const Razlomak &prvi, const Razlomak &drugi) {
    //dodati overflow check
    long long int s = Razlomak::NZD(prvi.DajBrojnik(), drugi.DajNazivnik());
    long long int t = Razlomak::NZD(drugi.DajBrojnik(), prvi.DajNazivnik());
    long long int gore = (prvi.DajBrojnik() / s) * (drugi.DajBrojnik() / t);
    long long int dole = (prvi.DajNazivnik() / t) * (drugi.DajNazivnik() / s);
    Razlomak r(gore, dole);
    return r;  
}

Razlomak operator -(const Razlomak &prvi, const Razlomak &drugi) {
    //dodati overflow check
    long long int gore = prvi.DajBrojnik() * (drugi.DajNazivnik() / Razlomak::NZD(prvi.DajNazivnik(), drugi.DajNazivnik())) - drugi.DajBrojnik() * (prvi.DajNazivnik() / Razlomak::NZD(prvi.DajNazivnik(), drugi.DajNazivnik()));
    long long int dole = prvi.DajNazivnik() * (drugi.DajNazivnik() / Razlomak::NZD(prvi.DajNazivnik(), drugi.DajNazivnik()));
    Razlomak r(gore, dole);
    return r;
}

Razlomak operator +(const Razlomak &prvi, const Razlomak &drugi) {
    //dodati overflow check
    long long int gore = prvi.DajBrojnik() * (drugi.DajNazivnik() / Razlomak::NZD(prvi.DajNazivnik(), drugi.DajNazivnik())) + drugi.DajBrojnik() * (prvi.DajNazivnik() / Razlomak::NZD(prvi.DajNazivnik(), drugi.DajNazivnik()));
    long long int dole = prvi.DajNazivnik() * (drugi.DajNazivnik() / Razlomak::NZD(prvi.DajNazivnik(), drugi.DajNazivnik()));
    Razlomak r(gore, dole);
    return r;
}

int main() {
    return 0;
}