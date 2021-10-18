#include <iostream>
#include <stdexcept>
#include <string>

class Datum {
    int dan, mjesec, godina;
    static bool Prestupna(int g) {return g % 400 == 0 || (g % 100 != 0 && g % 4 == 0);}
    static int PretvoriUDane(const Datum &dat) {
        int g(dat.godina - 1800-1), n((dat.godina-1800)*365);
        n += g/4 + (g+200)/400 - g/100;
        int d_u_m[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (Datum::Prestupna(dat.godina)) d_u_m[1]++;
        for (int i = 0; i < dat.mjesec-1; i++) n += d_u_m[i];
        n += dat.dan;
        return n;
    }
    static Datum PretvoriUDatum(int n);
public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August,
        Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, 
        Subota, Nedjelja};
    Datum(int d, int m, int g) { Postavi(d,m,g); }
    Datum(int d, Mjeseci m, int g) { Postavi(d,m,g); }
    Datum &Postavi(int d, int m, int g); 
    Datum &Postavi(int d, Mjeseci m, int g) { return Postavi(d, int(m), g); }
    int DajDan() const { return dan; }
    Mjeseci DajMjesec() const { return Mjeseci(mjesec); }
    int DajGodinu() const { return godina; }
    Dani DanUSedmici() const {
        int n((Datum::PretvoriUDane(*this)-1)%7);
        n -= 1; if (n < 0) n+= 7;
        return Dani(n);
    }
    const char *DajImeMjeseca() const;
    const char *DajImeDanaUSedmici() const;
    friend std::ostream &operator << (std::ostream &tok, const Datum &dat) {
        return tok << std::string(dat) << std::endl;    
    }
    friend std::istream &operator >> (std::istream &tok, Datum &dat);
    friend Datum &operator += (Datum &dat, int n);
    friend Datum &operator -= (Datum &dat, int n);
    friend Datum operator ++ (Datum &dat, int) {
        Datum novi(dat); dat+=1;
        return novi;
    }
    friend Datum &operator ++ (Datum &dat) {
        return dat += 1;
    }
    friend Datum operator -- (Datum &dat, int) {
        Datum novi(dat); dat-=1;
        return novi;
    }
    friend Datum &operator -- (Datum &dat) {
        return dat-=1;
    }
    friend Datum operator + (const Datum &dat, int n) {
        Datum novi(dat); return novi+=n;
    }
    friend Datum operator + (int n, const Datum &dat) {
        Datum novi(dat); return novi += n;
    }
    friend Datum operator - (const Datum &dat, int n) {
        Datum novi(dat); return novi-=n;
    }
    friend Datum operator - (int n, const Datum &dat) {
        Datum novi(dat); return novi -= n;
    }
    friend int operator - (const Datum &dat1, const Datum &dat2) {
        return abs(Datum::PretvoriUDane(dat1) - Datum::PretvoriUDane(dat2));
    }
    friend bool operator == (const Datum &dat1, const Datum &dat2) {
        return dat1.dan == dat2.dan && dat1.mjesec == dat2.mjesec
            && dat1.godina == dat2.godina;
    }
    friend bool operator != (const Datum &dat1, const Datum &dat2) {
        return !(dat1 == dat2);
    }
    friend bool operator < (const Datum &dat1, const Datum &dat2) {
        return dat1.dan < dat2.dan && dat1.mjesec <= dat2.mjesec
            && dat1.godina <= dat2.godina;
    }
    friend bool operator <= (const Datum &dat1, const Datum &dat2) {
        return dat1.dan <= dat2.dan && dat1.mjesec <= dat2.mjesec
            && dat1.godina <= dat2.godina;
    }
    friend bool operator > (const Datum &dat1, const Datum &dat2) {
        return dat1.dan > dat2.dan && dat1.mjesec >= dat2.mjesec
            && dat1.godina >= dat2.godina;
    }
    friend bool operator >= (const Datum &dat1, const Datum &dat2) {
        return dat1.dan >= dat2.dan && dat1.mjesec >= dat2.mjesec
            && dat1.godina >= dat2.godina;
    }
    operator std::string() const {
        return std::to_string(DajDan()) + ". " + std::string(DajImeMjeseca()) 
            + " " + std::to_string(DajGodinu()) + ".(" 
            + std::string(DajImeDanaUSedmici()) + ")";  
    }
    explicit operator int() const {
        return Datum::PretvoriUDane(*this) - 1;
    }
};

Datum &Datum::Postavi(int d, int m, int g) {
    int d_u_m[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (Datum::Prestupna(g)) d_u_m[1]++;
    if (d < 1 || d > d_u_m[m-1] || m < 1 || m > 12 || g < 1800)
        throw std::domain_error("Nelegalan datum");
    dan = d; mjesec = m; godina = g;
    return *this;
}

Datum Datum::PretvoriUDatum(int n) {
    Datum dat(1,1,1800);
    int god(n/365);
    n -= god/4 + (god+200)/400 - god/100 + 1;
    dat.godina += n/365; n %= 365;
    int d_u_m[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (Datum::Prestupna(dat.godina)) d_u_m[1]++;
    for (int i = 0; i < 12; i++) {
        if (n < d_u_m[i]) break;
        n -= d_u_m[i]; dat.mjesec++;
    }
    dat.dan += n;
    return dat;
}
        
const char* Datum::DajImeMjeseca() const {
    const char *ime_mjeseca[12]{"Januar", "Februar", "Mart", "April", "Maj",
        "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar"};
    return ime_mjeseca[mjesec-1];
}

const char* Datum::DajImeDanaUSedmici() const {
    const char *ime_dana[7] {"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak",
        "Petak", "Subota", "Nedjelja"};
    return ime_dana[int(DanUSedmici())];
}

std::istream &operator >> (std::istream &tok, Datum &dat) {
    char c;
    int d, m, g;
    if (tok >> d >> c && c == '/' && tok >> m >> c && c == '/' && tok >> g)
        dat.Postavi(d,m,g);
    else tok.setstate(std::ios::failbit);
    return tok;
}


Datum &operator += (Datum &dat, int n) {
    int dani1(Datum::PretvoriUDane(dat));
    dat = Datum::PretvoriUDatum(dani1+n);
    if (dat.DajDan() < 1) throw std::domain_error("Nelegalan datum");
    return dat;
}

Datum &operator -= (Datum &dat, int n) {
    int dani1(Datum::PretvoriUDane(dat));
    dat = Datum::PretvoriUDatum(dani1-n);
    if (dat.DajDan() < 1) throw std::domain_error("Nelegalan datum");
    return dat;
}

enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August,
    Septembar, Oktobar, Novembar, Decembar};
enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, 
    Subota, Nedjelja};

int main ()
{
    Datum dan(1,Januar,1800);
    std::cin >> dan;
    std::string s(dan);
    std::cout << s << std::endl;
    int x(dan);
    Datum novi(1+dan);
    std::cout << novi << x;
	return 0;
}
