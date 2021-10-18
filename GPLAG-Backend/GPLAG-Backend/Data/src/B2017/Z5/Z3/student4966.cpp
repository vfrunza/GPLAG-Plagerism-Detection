/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>

class Datum {
	int dan, mjesec, godina;
	static char* mjeseci[12];
	static char* dani[7];
	void DaLiJeDatumLegalan(int day, int month, int year);
	void PomjeriUnaprijed();
	void PomjeriUnazad();
public:
	enum Mjeseci { Januar = 1, Februar, Mart, April, Maj, Juni,Juli,August,Septembar,Oktobar,Novembar,Decembar };
	enum Dani {Ponedjeljak=1,Utorak,Srijeda,Cetvrtak,Petak,Subota,Nedjelja};
	Datum(int day, int month, int year);
	Datum(int day, Mjeseci month, int year);
	Datum& Postavi(int day, int month, int year);
	Datum& Postavi(int day, Mjeseci month, int year);
	int DajDan() const { return dan; }
	Mjeseci DajMjesec() const { return static_cast<Mjeseci>(mjesec); }
	int DajGodinu() const { return godina; }
	char* DajImeMjeseca() const{ return mjeseci[mjesec - 1]; }
	Dani DanUSedmici() const;
	char* DajImeDanaUSedmici() const { return dani[int(DanUSedmici()) - 1]; }
	Datum &operator ++();
	Datum operator ++(int);
	Datum &operator --();
	Datum operator --(int);
	friend Datum operator +(const Datum &d,int n);
	friend Datum operator -(const Datum &d,int n);
	friend Datum operator +(int n, const Datum &d);
	Datum& operator +=(int n);
	Datum& operator -=(int n);
	friend int operator -(const Datum &d1,const Datum &d2);
	bool operator ==(const Datum &d) const;
	bool operator !=(const Datum &d) const;
	bool operator <(const Datum &d) const;
	bool operator >(const Datum &d) const;
	bool operator <=(const Datum &d) const;
	bool operator >=(const Datum &d) const;
	friend std::ostream& operator <<(std::ostream &tok, const Datum &d);
	friend std::istream& operator >>(std::istream &tok, Datum &d);
	operator std::string() const;
	explicit operator int() const;
};
char* Datum::mjeseci[12]= { "Januar","Februar","Mart","April","Maj","Juni","Juli","August","Septembar","Oktobar","Novembar","Decembar"};
char* Datum::dani[7]{ "Ponedjeljak","Utorak","Srijeda","Cetvrtak","Petak","Subota","Nedjelja" };
int main()
{
	try {
		Datum dat(28,12,1998);
		std::cin >> dat;
		std::cout << dat;
		dat+=7000;
		std::cout << dat;
	}
	catch (std::domain_error &e) {
		std::cout << e.what();
	}
	std::cin.get();
    return 0;
}

//IMPLEMENTACIJA
	//Datum::private
void Datum::DaLiJeDatumLegalan(int day, int month, int year) {
	int broj_dana[12]{
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) broj_dana[1]++;
	if (year < 1800 || day < 1 || month < 1 || month > 12 || day > broj_dana[month - 1])
		throw std::domain_error("Nelegalan datum");
}
void Datum::PomjeriUnaprijed() {
	static int broj_dana[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	bool logicka = false;
	if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) {
		broj_dana[1]++; logicka = true;
	}
	dan++;
	if (dan>broj_dana[mjesec - 1]) { dan = 1; mjesec++; }
	if (mjesec>12) { mjesec = 1; godina++; }
	if (logicka) broj_dana[1]--;
}
void Datum::PomjeriUnazad() {
	static int broj_dana[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	bool logicka = false;
	if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) {
		broj_dana[1]++; logicka = true;
	}
	dan--;
	if (dan<1) {
		if (mjesec == 1) { dan = broj_dana[11]; mjesec = 12; godina--; }
		else { dan = broj_dana[mjesec - 2]; mjesec--; }
	}
	if (logicka) broj_dana[1]--;
}

	//Datum::public
Datum& Datum::Postavi(int day, int month, int year) {
	DaLiJeDatumLegalan(day, month, year);
	dan = day; mjesec = month; godina = year;
	return *this;
}
Datum& Datum::Postavi(int day, Mjeseci month, int year) {
	DaLiJeDatumLegalan(day, int(month), year);
	dan = day; mjesec = int(month); godina = year;
	return *this;
}
Datum::Datum(int day, int month, int year) {
	Postavi(day, month, year);
}
Datum::Datum(int day, Mjeseci month, int year) {
	Postavi(day, month, year);
}
Datum::Dani Datum::DanUSedmici() const {
	int razlika = (*this - Datum(1, 1, 1800))%7;
	if (razlika == 0) razlika = 7;
	return static_cast<Dani>(razlika);
}
Datum& Datum::operator ++() {
	PomjeriUnaprijed();
	return *this;
}
Datum Datum::operator ++(int) {
	Datum pomocni(*this);
	PomjeriUnaprijed();
	return pomocni;
}
Datum& Datum::operator --() {
	Datum pomocni(*this);
	PomjeriUnazad();
	try {
		DaLiJeDatumLegalan(dan, mjesec, godina);
	}
	catch (...) {
		*this = pomocni;
		throw;
	}
	return *this;
}
Datum Datum::operator --(int) {
	Datum pomocni(*this);
	PomjeriUnazad();
	try {
		DaLiJeDatumLegalan(dan, mjesec, godina);
	}
	catch (...) {
		*this = pomocni;
		throw;
	}
	return pomocni;
}
Datum operator +(const Datum &d, int n) {
	Datum pomocni(d);
	bool logicka = false;
	if (n < 0) { logicka = true; n *= -1; }
	for (int i = 0; i < n; i++) {
		if (logicka) pomocni--;
		else pomocni++;
	}
	return pomocni;
}
Datum operator -(const Datum &d, int n) {
	Datum pomocni(d);
	bool logicka = false;
	if (n < 0) { logicka = true; n *= -1; }
	for (int i = 0; i < n; i++) {
		if (logicka) pomocni++;
		else pomocni--;
	}
	return pomocni;
}
Datum operator +(int n, const Datum &d) {
	return d + n;
}
int operator -(const Datum &d1, const Datum &d2) {
	int broj_dana[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	int godine, i;
	long brojdana1, brojdana2, razlikadana;
	brojdana1 = (d1.godina-1800)* 365 + d1.dan;
	for (i = 0; i<d1.mjesec-1; i++)
		brojdana1 += broj_dana[i];
	godine = d1.godina;
	if (d1.mjesec <= 2)
		godine--;
	brojdana1 += godine / 4 - godine / 100 + godine / 400;

	brojdana2 = (d2.godina-1800)*365 + d2.dan;
	for (i = 0; i<d2.mjesec - 1; i++)
		brojdana2 += broj_dana[i];
	godine = d2.godina;
	if (d2.mjesec <= 2)
		godine--;
	brojdana2 += godine / 4 - godine / 100 + godine / 400;
	razlikadana = brojdana1 - brojdana2;

	return razlikadana;
}
Datum& Datum::operator +=(int n) {
	return *this = *this + n;
}
Datum& Datum::operator -=(int n){
	return *this = *this - n;
}
bool Datum::operator ==(const Datum &d) const{
	return (dan == d.dan && mjesec == d.mjesec && godina == d.godina);
}
bool Datum::operator !=(const Datum &d) const  {
	return !(*this == d);
}
bool Datum::operator <(const Datum &d) const {
	if (godina < d.godina) {
		return true;
		if (godina == d.godina) {
			if (mjesec < d.mjesec) {
				return true;
				if (mjesec == d.mjesec) {
					if (dan < d.dan) return true;
				}
			}
		}
	}
	return false;
}
bool Datum::operator >(const Datum &d) const {
	if (godina > d.godina) {
		return true;
		if (godina == d.godina) {
			if (mjesec > d.mjesec) {
				return true;
				if (mjesec == d.mjesec) {
					if (dan > d.dan) return true;
				}
			}
		}
	}
	return false;
}
bool Datum::operator <=(const Datum &d) const {
	return !(*this > d);
}
bool Datum::operator >=(const Datum &d) const {
	return !(*this < d);
}
std::ostream& operator <<(std::ostream &tok, const Datum &d) {
	tok << d.dan << "." << d.DajImeMjeseca() << " " << d.godina << ". (" << d.DajImeDanaUSedmici() << ")";
	return tok;
}
std::istream& operator >>(std::istream &tok, Datum &d) {
	char znak;
	tok >> d.dan >> znak;
	if (znak!='/') tok.setstate(std::ios::failbit);
	tok >> d.mjesec >> znak;
	if (znak != '/') tok.setstate(std::ios::failbit);
	tok >> d.godina;
	return tok;
}
Datum::operator std::string() const {
	std::string s;
	s += std::to_string(dan) + "." + DajImeMjeseca() + " " + std::to_string(godina) + ". (" + DajImeDanaUSedmici() + ")";
	return s;
}
Datum::operator int() const {
	return *this - Datum(1, 1, 1800);
}
