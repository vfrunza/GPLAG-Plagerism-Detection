/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <string>

class Datum {
    int dan, mjesec, godina;
public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    Datum(int dan, int mjesec, int godina);
    Datum(int dan, Mjeseci mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    void Postavi(int dan, Mjeseci mjesec, int godina);
    int DajDan() const { return dan; }
    Mjeseci DajMjesec() const { return Mjeseci(mjesec); }
    int DajGodinu() const { return godina; }
    const char *DajImeMjeseca() const;
    Dani DanUSedmici() const { return Dani(dan); }
    const char *DajImeDanaUSedmici() const;
    Datum &operator ++();
    Datum operator ++(int);
    Datum &operator --();
    Datum operator --(int);
    friend Datum operator +(const Datum &d, int broj);
    friend Datum operator -(const Datum &d, int broj);
    Datum &operator +=(int n);
    Datum &operator -=(int n);
    friend int operator -(const Datum &prvi, const Datum &drugi);
    friend bool operator ==(const Datum &prvi, const Datum &drugi);
    friend bool operator !=(const Datum &prvi, const Datum &drugi);
    friend bool operator <(const Datum &prvi, const Datum &drugi);
    friend bool operator >(const Datum &prvi, const Datum &drugi);
    friend bool operator <=(const Datum &prvi, const Datum &drugi);
    friend bool operator >=(const Datum &prvi, const Datum &drugi);
    friend std::ostream &operator <<(std::ostream &tok, const Datum &d);
    friend std::istream &operator >>(std::istream &tok, Datum &d);
    operator std::string() const;
    explicit operator int() const;
};

Datum::Datum(int dan, int mjesec, int godina) {
    Postavi(dan, mjesec, godina);
}

Datum::Datum(int dan, Mjeseci mjesec, int godina) {
    Postavi(dan, mjesec, godina);
}

void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0)) broj_dana[1]++;
    if(godina < 1800 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1]) throw std::domain_error("Nelegalan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec; 
    Datum::godina = godina;    
}

void Datum::Postavi(int dan, Mjeseci mjesec, int godina) {
    Postavi(dan, mjesec, godina);
}

const char *Datum::DajImeMjeseca() const {
    const char *mjeseci[]{"Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar"};
    return mjeseci[mjesec - 1];
}

const char *Datum::DajImeDanaUSedmici() const {
    const char *dani[]{"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};
    int referentniDan = 2;
    int brojDana = *this - Datum(1, 1, 1800);
    brojDana %= 7;
    referentniDan += brojDana;
    referentniDan %= 7;
    return dani[referentniDan];
}

Datum &Datum::operator ++() {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0)) broj_dana[1]++;
    dan++;
    if(dan > broj_dana[mjesec - 1]) {
        dan = 1; 
        mjesec++;
    }
    if(mjesec > 12) {
        mjesec = 1;
        godina++;
    }
    return *this;
}

Datum Datum::operator ++(int) {
    Datum d(*this);
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0)) broj_dana[1]++;
    dan++;
    if(dan > broj_dana[mjesec - 1]) {
        dan = 1; 
        mjesec++;
    }
    if(mjesec > 12) {
        mjesec = 1;
        godina++;
    }    
    return d;
}

Datum &Datum::operator --() {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0)) broj_dana[1]++;
    dan--;
    if(dan < 1) {
        mjesec--;
        if(mjesec < 1) {
            mjesec = 12;
            godina--;
            if(godina < 1800) throw std::domain_error("Nelegalan datum");
        }
        dan = broj_dana[mjesec - 1];
    }
    return *this;
}

Datum Datum::operator --(int) {
    Datum d(*this);
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0)) broj_dana[1]++;
    dan--;
    if(dan < 1) {
        mjesec--;
        if(mjesec < 1) {
            mjesec = 12;
            godina--;
            if(godina < 1800) throw std::domain_error("Nelegalan datum");
        }
        dan = broj_dana[mjesec - 1];
    }
    return d;
}

Datum operator +(const Datum &d, int broj) {
    Datum rezultat(d);
    if(broj > 0) {
        for(int i(0); i < broj; i++) {
            rezultat++;
        }
    }
    else {
        broj *= -1;
        for(int i(0); i < broj; i++) {
            rezultat--;
        }
    }
    return rezultat;
}

Datum operator -(const Datum &d, int broj) {
    Datum rezultat(d);
    if(broj > 0) {
        for(int i(0); i < broj; i++) {
            rezultat--;
        }
    }
    else {
        broj *= -1;
        for(int i(0); i < broj; i++) {
            rezultat++;
        }
    }
    return rezultat;
}

Datum &Datum::operator +=(int n) {
    *this = *this + n;
    return *this;
}

Datum &Datum::operator -=(int n) {
    *this = *this - n;
    return *this;
}

int operator -(const Datum &prvi, const Datum &drugi) {
    int brojDanaPrvi(prvi.DajDan()), brojDanaDrugi(drugi.DajDan());
    for(int i(1800); i < prvi.DajGodinu(); i++) {
        if(i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) brojDanaPrvi += 366;
        else brojDanaPrvi += 365;
    }
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i(0); i < prvi.DajMjesec() - 1; i++) {
        if(prvi.DajGodinu() % 4 == 0 && (prvi.DajGodinu() % 100 != 0 || prvi.DajGodinu() % 400 == 0)) {
            if(i == 1) brojDanaPrvi++;
        }
        brojDanaPrvi += broj_dana[i];
    }
    for(int i(1800); i < drugi.DajGodinu(); i++) {
        if(i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) brojDanaDrugi += 366;
        else brojDanaDrugi += 365;
    }
    for(int i(0); i < drugi.DajMjesec() - 1; i++) {
        if(drugi.DajGodinu() % 4 == 0 && (drugi.DajGodinu() % 100 != 0 || drugi.DajGodinu() % 400 == 0)) {
            if(i == 1) brojDanaDrugi++;
        }
        brojDanaDrugi += broj_dana[i];
    }
    return brojDanaPrvi - brojDanaDrugi;
}

bool operator ==(const Datum &prvi, const Datum &drugi) {
    if(prvi.DajDan() == drugi.DajDan() && prvi.DajMjesec() == drugi.DajMjesec() && prvi.DajGodinu() == drugi.DajGodinu()) return true;
    return false;
}

bool operator !=(const Datum &prvi, const Datum &drugi) {
    if(prvi.DajDan() != drugi.DajDan() || prvi.DajMjesec() != drugi.DajMjesec() || prvi.DajGodinu() != drugi.DajGodinu()) return true;
    return false;
}

bool operator <(const Datum &prvi, const Datum &drugi) {
    if(prvi.DajGodinu() < drugi.DajGodinu()) return true;
    else if(prvi.DajGodinu() == drugi.DajGodinu()) {
        if(prvi.DajMjesec() < drugi.DajMjesec()) return true;
        else if(prvi.DajMjesec() == drugi.DajMjesec()) {
            if(prvi.DajDan() < drugi.DajDan()) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}

bool operator >(const Datum &prvi, const Datum &drugi) {
    if(prvi.DajGodinu() > drugi.DajGodinu()) return true;
    else if(prvi.DajGodinu() == drugi.DajGodinu()) {
        if(prvi.DajMjesec() > drugi.DajMjesec()) return true;
        else if(prvi.DajMjesec() == drugi.DajMjesec()) {
            if(prvi.DajDan() > drugi.DajDan()) return true;
            else return false;
        }
        else return false;
    }
    else return false;    
}

bool operator <=(const Datum &prvi, const Datum &drugi) {
    if(prvi < drugi || prvi == drugi) return true;
    return false;
}

bool operator >=(const Datum &prvi, const Datum &drugi) {
    if(prvi > drugi || prvi == drugi) return true;
    return false;
}

std::ostream &operator <<(std::ostream &tok, const Datum &d) {
    tok << d.DajDan() << "." << d.DajImeMjeseca() << " " << d.DajGodinu() << ".(" << d.DajImeDanaUSedmici() << ")";
    return tok;
}

std::istream &operator >>(std::istream &tok, Datum &d) {
    int dan, mjesec, godina;
    char znak = '/';
    tok >> std::ws;
    tok >> dan;
    if(tok.peek() != '/') tok.setstate(std::ios::failbit);
    tok >> znak;
    if(znak != '/') tok.setstate(std::ios::failbit);
    tok >> mjesec;
    if(tok.peek() != '/') tok.setstate(std::ios::failbit);
    tok >> znak;
    if(znak != '/') tok.setstate(std::ios::failbit);
    tok >> godina;
    if(tok.peek() != '\n') tok.setstate(std::ios::failbit);
    if(tok) {
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0)) broj_dana[1]++;
        if(godina < 1800 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1]) tok.setstate(std::ios::failbit);
    }
    if(tok) d.Postavi(dan, mjesec, godina);
    return tok;
}

Datum::operator std::string() const {
    std::string rezultat;
    int broj = DajDan();
    std::string pomocni;
    while(broj != 0) {
        pomocni.push_back(broj % 10 + '0');
        broj /= 10;
    }
    std::string izvrnuti;
    for(int i(pomocni.length() - 1); i >= 0; i--) {
        izvrnuti.push_back(pomocni.at(i));
    }
    rezultat += izvrnuti;
    pomocni = "";
    izvrnuti = "";
    rezultat += '.';
    auto imeMjeseca = DajImeMjeseca();
    while(*imeMjeseca != '\0') {
        rezultat.push_back(*imeMjeseca);
        imeMjeseca++;
    }
    rezultat += ' ';
    broj = DajGodinu();
    while(broj != 0) {
        pomocni.push_back(broj % 10 + '0');
        broj /= 10;
    }
    for(int i(pomocni.size() - 1); i >= 0; i--) {
        izvrnuti.push_back(pomocni.at(i));
    }
    rezultat += izvrnuti;
    rezultat += ".(";
    auto imeDana = DajImeDanaUSedmici();
    while(*imeDana != '\0') {
        rezultat += *imeDana;
        imeDana++;
    }
    rezultat += ')';
    return rezultat;
}

Datum::operator int() const {
    Datum d(1, 1, 1800);
    return *this - d;
}

int main () {
    Datum dat(23, 4, 2012);
    int i = int(dat);
    std::cout << i;
	return 0;
}
