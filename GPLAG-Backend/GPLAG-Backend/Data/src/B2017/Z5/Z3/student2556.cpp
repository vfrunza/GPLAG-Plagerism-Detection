/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <cmath>
bool Prestupna(int g) {
        if(g % 400 == 0 || (g % 4 == 0 && g % 100 != 0)) return true;
        return false;
    }
static int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char mjeseci[12][10]{"Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar"};
static char dani[7][12]{"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};
class Datum
{
    int dan, mjesec, godina;
    
public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    Datum(int d, int m, int g): dan(d), mjesec(m), godina(g) {
        if(d > broj_dana[m-1] || d < 1 || mjesec > 12 || mjesec < 1 || godina < 1800)
            throw std::domain_error("Nelegalan datum");
    }
    Datum(int d, Mjeseci m, int g): dan(d), mjesec(m), godina(g) {
        if(d > broj_dana[m-1] || d < 1 || mjesec > 12 || mjesec < 1 || godina < 1800)
            throw std::domain_error("Nelegalan datum");
    }
    void Postavi(int d, int m, int g) {
        dan=d, mjesec=m, godina=g;
    }
    void Postavi(int d, Mjeseci m, int g) {
        dan=d, mjesec=m, godina=g;
    }
    int DajDan() const {
        return dan;
    }
    Mjeseci DajMjesec() const {
        return Mjeseci(mjesec);
    }
    int DajGodinu() const {
        return godina;
    }
    char *DajImeMjeseca() const {
        return &mjeseci[mjesec-1][0];
    }
    
    Dani DanUSedmici() const {
        int suma(BrojDanaIzmedju(*this));
        if(suma==0) return static_cast<Dani>(7);
        return static_cast<Dani>(suma%7 + 1);
    }
    char *DajImeDanaUSedmici() const {
        return &dani[DanUSedmici()-1][0];
    }
    
    
    friend Datum &operator ++(Datum &d);
    friend Datum operator ++(Datum &d, int);
    friend Datum &operator --(Datum &d);
    friend Datum operator --(Datum &d, int);
    friend Datum &operator +(Datum &d, int n);
    friend Datum &operator -(Datum &d, int n);
    friend Datum &operator +=(Datum &d, int n);
    friend Datum &operator -=(Datum &d, int n);
    friend long int operator -(Datum &d1, Datum &d2);
    friend bool operator ==(const Datum &d1, const Datum &d2);
    friend bool operator !=(const Datum &d1, const Datum &d2);
    friend bool operator <=(const Datum &d1, const Datum &d2);
    friend bool operator >=(const Datum &d1, const Datum &d2);
    friend bool operator <(const Datum &d1, const Datum &d2);
    friend bool operator >(const Datum &d1, const Datum &d2);
    friend std::ostream &operator<<(std::ostream &tok, const Datum &d);
    friend std::istream &operator>>(std::istream &tok, Datum &d);
    operator std::string() const;
    explicit operator int() const;
    friend long int BrojDanaIzmedju(const Datum &d) ;
};
long int BrojDanaIzmedju(const Datum &d) {
        long int suma(0);
        for(int i=1; i<d.dan; i++) {
            suma++;
        }
        for(int i=1; i<d.mjesec; i++) {
            suma+=broj_dana[i-1];
            if(d.mjesec == 2) {
                if((d.godina % 4 == 0 && d.godina % 100 != 0) || d.godina % 400 == 0) suma++;
            }
        }
        for(int i=1800; i<d.godina; i++) {
            suma+=365;
            if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) suma++;
        }
        return suma;
    }
Datum &operator ++(Datum &d)
{
    d.dan+=1;
    if(d.dan > broj_dana[d.mjesec-1]) {
        d.dan=1;
        d.mjesec++;
    }
    if(d.mjesec > 12) {
        d.mjesec=1;
        d.godina++;
    }
    return d;
}
Datum operator ++(Datum &d, int)
{
    Datum pomocni(d);
    ++d;
    return pomocni;
}
Datum &operator --(Datum &d)
{
    d.dan-=1;
    if(d.dan < broj_dana[d.mjesec-1]) {
        d.mjesec--;
        d.dan = broj_dana[d.mjesec-1];
    }
    if(d.mjesec <= 0) {
        d.godina--;
        if(d.godina < 1800) throw std::domain_error("Nelegalan datum");
        d.mjesec = 12;
    }
    return d;
}
Datum operator --(Datum &d, int)
{
    Datum pomocni(d);
    --d;
    return pomocni;
}
Datum &operator +(Datum &d, int n)
{
    d.dan += n;
    if(n > 0) {
        while(d.dan > broj_dana[d.mjesec - 1]) {
            d.dan -= broj_dana[d.mjesec - 1];
            d.mjesec++;
            if(d.mjesec > 12) {
                d.godina++;
                d.mjesec=1;
            }
            if(d.mjesec == 2 && Prestupna(d.godina)) d.dan--;
        }
    } else if(n < 0) d = d - abs(n);
    if(d.godina < 1800) throw std::domain_error("Nelegalan datum");
    return d;
}
Datum &operator -(Datum &d, int n)
{
    d.dan -= n;
    if(n > 0) {
        while(d.dan < 1) {
            d.mjesec--;
            if(d.mjesec < 1) {
                d.godina--;
                d.mjesec = 12;
            }
            d.dan += broj_dana[d.mjesec - 1];
            if(d.mjesec == 2 && Prestupna(d.godina)) d.dan++;
        }
    } else if(n < 0) d = d + n;
    if(d.godina < 1800) throw std::domain_error("Nelegalan datum");
    return d;
}
Datum &operator+=(Datum &d, int n) {
    d = d + n;
    return d;   
}
Datum &operator-=(Datum &d, int n) {
    d = d - n;
    return d;
}
long int operator-(Datum &d1, Datum &d2) {
    return abs(BrojDanaIzmedju(d1) - BrojDanaIzmedju(d2));
}
bool operator!=(const Datum &d1, const Datum &d2) {
    if(d1.godina != d2.godina || d1.dan != d2.dan || d1.mjesec != d2.mjesec) return true;
    return false;
}
bool operator==(const Datum &d1, const Datum &d2) {
    if(d1.godina == d2.godina && d1.mjesec == d2.mjesec && d1.dan == d2.mjesec) return true;
    return false;
}
bool operator>=(const Datum &d1, const Datum &d2) {
    if(d1.godina > d2.godina) return true;
    else if(d1.godina == d2.godina) {
        if(d1.mjesec > d2.mjesec) return true;
        else if(d1.mjesec == d2.mjesec) {
            if(d1.dan >= d2.dan) return true;
            return false;
        }
        return false;
    }
    return false;
}
bool operator<=(const Datum &d1, const Datum &d2) {
    if(d1.godina < d2.godina) return true;
    else if(d1.godina == d2.godina) {
        if(d1.mjesec < d2.mjesec) return true;
        else if(d1.mjesec == d2.mjesec) {
            if(d1.dan <= d2.dan) return true;
            return false;
        }
        return false;
    }
    return false;
}
bool operator>(const Datum &d1, const Datum &d2) {
    if(d1.godina > d2.godina) return true;
    else if(d1.godina == d2.godina) {
        if(d1.mjesec > d2.mjesec) return true;
        else if(d1.mjesec == d2.mjesec) {
            if(d1.dan > d2.dan) return true;
            return false;
        }
        return false;
    }
    return false;
}
bool operator<(const Datum &d1, const Datum &d2) {
    if(d1.godina < d2.godina) return true;
    else if(d1.godina == d2.godina) {
        if(d1.mjesec < d2.mjesec) return true;
        else if(d1.mjesec == d2.mjesec) {
            if(d1.dan < d2.dan) return true;
            return false;
        }
        return false;
    }
    return false;
}
std::ostream &operator<<(std::ostream &tok, const Datum &d) {
    tok<<d.DajDan()<<"."<<d.DajImeMjeseca()<<" "<<d.DajGodinu()<<".("<<d.DajImeDanaUSedmici()<<")"<<std::endl;
    return tok;
}
std::istream &operator>>(std::istream &tok, Datum &dat) {
    char znak1, znak2;
    int d, m, g;
    tok>>d>>znak1>>m>>znak2>>g;
    if(std::cin.peek() != '\n' || !std::cin || znak1 != '/' || znak2 != '/') tok.setstate(std::ios::failbit);
    else dat.dan = d, dat.mjesec = m, dat.godina = g;
    return tok;
}
Datum::operator std::string() const {
    std::string s;
    Datum d(*this);
    s+=std::to_string(this->DajDan());
    s.push_back('.');
    s += std::to_string(*(d.DajImeMjeseca()));
    s.push_back(' ');
    s+=std::to_string(this->DajGodinu());
    s.push_back('.');
    s.push_back('(');
    s += std::to_string(*(d.DajImeDanaUSedmici()));
    s.push_back(')');
    return s;
}
Datum::operator int() const {
    return BrojDanaIzmedju(*this);
}
int main ()
{
    try{
    Datum d1(11, 6, 2019), d2(1, 7, 2019);
    std::string s=d1;
    std::cout<<s;
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
    return 0;
}
