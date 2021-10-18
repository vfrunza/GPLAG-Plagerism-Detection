#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <type_traits>

class Datum {
public:
    /// public attributes
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August,
                    Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
  
    /// ctors & mutators
    Datum(int d, int m, int g) { this->Postavi(d, m, g); }
    Datum(int d, Mjeseci m, int g) { this->Postavi(d, m, g); }
    
    void Postavi(int d, int m, int g);
    void Postavi(int d, Datum::Mjeseci m, int g);
    
    /// inspectors
    int DajDan() const                  { return this->dan; }
    Mjeseci DajMjesec() const           { return IntToMjesec(this->mjesec); }
    int DajGodinu() const               { return this->godina; }
    const char* DajImeMjeseca() const   { return imena_mjeseci[this->mjesec - 1]; };
    
    Dani DanUSedmici() const;
    const char* DajImeDanaUSedmici() const { return imena_dani[static_cast<int>(this->DanUSedmici()) - 1]; }
    /// operators
    Datum& operator++();
    Datum operator++(int);
    Datum& operator--();
    Datum operator--(int);
    
    Datum& operator+=(int);
    Datum& operator-=(int);

    friend Datum operator+(Datum, int);
    friend Datum operator+(int, const Datum&);
    friend Datum operator-(Datum, int);
    friend Datum operator-(int, const Datum&);
    friend int operator-(const Datum&, const Datum&);
    
    friend bool operator==(const Datum&, const Datum&);
    friend bool operator!=(const Datum&, const Datum&);
    friend bool operator<(const Datum&, const Datum&);
    friend bool operator>(const Datum&, const Datum&);
    friend bool operator<=(const Datum&, const Datum&);
    friend bool operator>=(const Datum&, const Datum&);

    operator std::string () const;
    explicit operator int() const;
    friend std::ostream &operator <<(std::ostream &tok, const Datum& d);
    friend std::istream &operator <<(std::istream &tok, Datum& d);
    
private:
    int dan, mjesec, godina;
    static const char* imena_mjeseci[12];
    static const char* imena_dani[7];
	static const int broj_dana[12];
	
    void static validDate(int d, int m, int g);
	bool static isLeap(int g) { return ((g % 4 == 0) && (g % 100 != 0)) || (g % 400 == 0); }
	int static const daysInMonth(int m, int g);
	int static MjesecToInt(Mjeseci m);
	int DaniToInt() const;
	Mjeseci static IntToMjesec(int m);
	Dani IzracunajDan();
};
 
/// implementation of private Datum methods
int const Datum::daysInMonth(int m, int g) {
	return Datum::broj_dana[m - 1] + (isLeap(g) && m == 2 ? 1 : 0);
}
void Datum::validDate(int d, int m, int g) {
	if (g < 1800 || d < 1 || m < 1 || m > 12 || d > daysInMonth(m, g)) 
	    throw std::domain_error("Nelegalan datum");
}
int Datum::MjesecToInt(Datum::Mjeseci m) {
    return std::abs((static_cast<int>(m) - static_cast<int>(Mjeseci::Januar)) % 12 + 1);
}
Datum::Mjeseci Datum::IntToMjesec(int m) {
    return static_cast<Datum::Mjeseci>(m % 12 + MjesecToInt(Datum::Januar) - 1);
}
/// implementation of Datum interface
Datum::Dani Datum::DanUSedmici() const {
    int _reminder (int(*this) % 7);
    return _reminder == 0 ? Dani::Nedjelja : static_cast<Datum::Dani>(_reminder + int(Datum::Ponedjeljak) - 1);
}
void Datum::Postavi(int d, int m, int g) { 
    validDate(d, m, g);
    Datum::dan = d; Datum::mjesec = m; Datum::godina = g;
}
void Datum::Postavi(int d, Mjeseci m, int g) {
    this->Postavi(d, MjesecToInt(m), g);
}

Datum& Datum::operator++() {
	if (1 + this->dan > daysInMonth(this->mjesec, this->godina)) {
		this->dan = 1;
		if (this->mjesec == 12) this->mjesec = 0, ++this->godina;
		++this->mjesec;
	} 
	else ++this->dan;
	return *this;
}
Datum Datum::operator++(int) {
	Datum newDate(this->dan, this->mjesec, this->godina);
	++*this;
	return newDate;
}
Datum& Datum::operator--() {	
	if (1 == this->dan) {
		if (this->mjesec == 1) { this->mjesec = 12, --this->godina; }
		else --this->mjesec;
		this->dan = daysInMonth(this->mjesec, this->godina);
	}
	else --this->dan;
	try { validDate(this->dan, this->mjesec, this->godina); }
	catch (...) { 
	    ++*this; 
	    throw;
    }
    return *this;
}
Datum Datum::operator--(int) {
	Datum newDate(this->dan, this->mjesec, this->godina);
	--*this;
	return newDate;
}

Datum operator +(Datum date, int days) {
    if(days > 0) for(; days-- != 0; ++date);
    else for(; days-- != 0; --date);
    return date;
}
Datum operator -(Datum date, int days) {
    if(days > 0) for(; days-- != 0; --date);
    else for(; days-- != 0; ++date);
    return date;
}

inline Datum operator +(int days, const Datum& date) {
    return date + days;
}
inline Datum operator -(int days, const Datum& date) {
    return date - days;
}

Datum& Datum::operator +=(int days) {
	Datum saveDate(this->dan, this->mjesec, this->godina);
	try { *this = *this + days; }
	catch (...) {
	    *this = saveDate;
	    throw;
	}
	return *this;
}
Datum& Datum::operator -=(int days) {
    Datum saveDate(this->dan, this->mjesec, this->godina);
	try { *this = *this - days; }
	catch (...) {
	    *this = saveDate;
	    throw;
	}
	return *this;
}

bool operator==(const Datum& d1, const Datum& d2) { return d1.dan == d2.dan && d1.mjesec == d2.mjesec && d1.godina == d2.godina; }
bool operator!=(const Datum& d1, const Datum& d2) { return !(d1 == d2); }
bool operator<(const Datum& d1, const Datum& d2) {
    return (d1.godina < d2.godina) || (d1.godina == d2.godina && d1.mjesec < d2.mjesec) || 
            (d1.godina == d2.godina && d1.mjesec == d2.mjesec && d1.dan < d2.dan);
}
bool operator>(const Datum& d1, const Datum& d2) { return d2 < d1; }
bool operator<=(const Datum& d1, const Datum& d2) { return d1 == d2 || d1 < d2; }
bool operator>=(const Datum& d1, const Datum& d2) { return d1 == d2 || d2 < d1; }

int operator-(const Datum& d1, const Datum& d2) {
    int distance(0);
    Datum _min (std::min(d1, d2)), _max (std::max(d1, d2));
    for(; _min != _max; ++_min, ++distance);
    return distance;
}
Datum::operator int() const { return *this - Datum(1, 1, 1800); }
Datum::operator std::string () const { 
    return std::to_string(this->DajDan()) + '.' + this->DajImeMjeseca() + ' ' + std::to_string(this->DajGodinu()) + ".(" + this->DajImeDanaUSedmici() + ")";
}

std::ostream &operator <<(std::ostream &tok, const Datum& d) {
    tok << d.DajDan() << '.' << d.DajImeMjeseca() << ' ' << d.DajGodinu() << ".(" << d.DajImeDanaUSedmici() << ")";
    return tok;
}
/// TO CHECK, NOT DONE
std::istream &operator >>(std::istream &tok, Datum& datum) {
    char znak;
    int d, m, y;
    
    tok >> std::ws;
    if(!::isdigit(tok.peek())) tok.setstate(std::ios::failbit);
    else tok >> d >> znak;
    if(znak != '/') tok.setstate(std::ios::failbit);
    
    if(!::isdigit(tok.peek())) tok.setstate(std::ios::failbit);
    else tok >> m >> znak;
    if(znak != '/') tok.setstate(std::ios::failbit);
    
    if(!::isdigit(tok.peek())) tok.setstate(std::ios::failbit);
    else tok >> y;
    
    try { datum.Postavi(d, m, y); }
    catch (...) { tok.setstate(std::ios::failbit); }
    return tok;
}

/// initialise Datum data
const char* Datum::imena_mjeseci[12] = {"Januar","Februar","Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar"};
const char* Datum::imena_dani[7] = {"Ponedjeljak","Utorak","Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};
const int Datum::broj_dana[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 
int main () {
    
	return 0;
}