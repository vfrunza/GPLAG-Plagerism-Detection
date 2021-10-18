#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <stdexcept>

class Datum {
public:
enum Mjeseci{Januar=1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
enum Dani{Ponedjeljak=1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

private:
int godina, mjesec, dan;
static std::string Izmjena(int broj) {
    std::string s;
    if(broj<0) broj=fabs(broj);
    while(broj!=0) {
        s.insert(s.begin(), broj%10+48);
        broj/=10;
    }
    return s;
}

public:
Datum(int dan, int mjesec, int godina);
Datum(int dan, Mjeseci mjesec, int godina);
void Postavi(int dan, int mjesec, int godina);
void Postavi(int dan, Mjeseci mjesec, int godina);
int DajDan() const {return dan;}
int DajGodinu() const {return godina;}
Mjeseci DajMjesec() const {return Mjeseci(mjesec);}
Dani DanUSedmici() const;
const char* DajImeMjeseca() const;
const char* DajImeDanaUSedmici() const;
Datum& operator++();
Datum  operator++(int);
Datum& operator--();
Datum  operator--(int);
friend int operator-(const Datum& d1, const Datum& d2);
friend Datum operator-(const Datum& d, int broj);
friend Datum operator+(const Datum& d, int broj);
Datum &operator +=(int);
Datum &operator -=(int);
bool operator==(const Datum& d);
bool operator!=(const Datum& d);
bool operator<(const Datum& d);
bool operator>(const Datum& d);
bool operator<=(const Datum& d);
bool operator>=(const Datum& d);
friend std::ostream& operator<<(std::ostream& tok, const Datum& d);
friend std::istream& operator>>(std::istream& tok, Datum& d);
operator std::string() const;
explicit operator int() const;
};

Datum::Datum(int dan=1, int mjesec=1, int godina=1800){Postavi(dan, mjesec, godina);}

Datum::Datum(int dan, Mjeseci mjesec, int godina){Postavi(dan,(int)mjesec, godina);}
void Datum::Postavi(int dan=1, int mjesec=1, int godina=1800){
    if(godina<1800 || mjesec<1 || mjesec>12 || dan<1 || dan>31) throw std::domain_error("Nelegalan datum");
    if((mjesec==1 || mjesec==3 || mjesec==5 || mjesec==7 || mjesec==8 || mjesec==10 || mjesec==12) && dan>31) throw std::domain_error("Nelegalan datum");
    if((mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11) && dan>30) throw std::domain_error("Nelegalan datum");
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) {
        if(mjesec==2 && dan>29) throw std::domain_error("Nelegalan datum");
    } else {
        if(mjesec==2 && dan>28) throw std::domain_error("Nelegalan datum");
    }
    this->dan=dan;
    this->mjesec=mjesec;
    this->godina=godina;
}

void Datum::Postavi(int dan, Mjeseci mjesec, int godina){Postavi(dan, (int)mjesec, godina);}

Datum::Dani Datum::DanUSedmici() const {
    int temp;
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i=1800; i<godina; i++) {
        if(i%4==0 && (i%100!=0 || i%400==0)) temp++;
    }
    temp+=(godina-1800)*365;
    temp+=(dan-1);
    if((godina%4==0 && (godina%100!=0 || godina%400==0)) && mjesec>2) temp++;
    for(int i=0; i<mjesec; i++) {
        temp+=brojdana[i];
    }
    temp+=dan;
    if((temp%7+3)%7==0) return Dani(7);
    return Dani((temp%7+3)%7);
}

const char* Datum::DajImeMjeseca() const {
    const char* temp[]{"Januar","Februar","Mart","April","Maj","Juni","Juli","August","Septembar","Oktobar","Novembar","Decembar"};
    return temp[mjesec-1];
}

const char* Datum::DajImeDanaUSedmici() const {
    //std::cout << DanUSedmici() << std:endl;
    const char *temp[]{"Ponedjeljak","Utorak","Srijeda","Cetvrtak","Petak","Subota","Nedelja"};
    return temp[DanUSedmici()-1];
}

Datum &Datum::operator ++() {
    dan++;
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) brojdana[1]++;
    if(dan>brojdana[mjesec-1]) {
        dan=1;
        mjesec++;
        if(mjesec>12) {
            mjesec=1;
            godina++;
        }
    }
    return *this;
}

Datum Datum::operator ++(int) {
    Datum temp(*this);
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) brojdana[1]++;
    dan++;
    if(dan>brojdana[mjesec-1]) {
        dan=1;
        mjesec++;
        if(mjesec>12) {
            mjesec=1;
            godina++;
        }
    }
    return temp;
}

Datum &Datum::operator --() {
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) brojdana[1]++;
    if(dan==1 && mjesec==1 && godina==1800) throw std::domain_error("Nelegalan datum");
    dan--;
    if(dan<1) {
        mjesec--;
        if(mjesec<1) {
            mjesec=12;
            godina--;
        }
    }
    dan=brojdana[mjesec-1];
    return *this;
}

Datum Datum::operator --(int) {
    Datum temp(*this);
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) brojdana[1]++;
    if(dan==1 && mjesec==1 && godina==1800) throw std::domain_error("Nelegalan datum");
    dan--;
    if(dan<1) {
        mjesec--;
        if(mjesec<1) {
            mjesec=12;
            godina--;
        }
    }
    dan=brojdana[mjesec-1];
    return temp;
}

Datum operator +(const Datum& d, int broj) {
    Datum temp(d);
    for(int i=0; i<broj; i++) temp++;
    return temp;
}

Datum operator -(const Datum& d, int broj) {
    Datum temp(d);
    for(int i=0; i<broj; i++) temp--;
    return temp;
}

int operator -(const Datum& d1, const Datum& d2) {
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int temp1=brojdana[d1.mjesec-1];
    int temp2=brojdana[d2.mjesec-1];
    if(temp1>temp2) return temp1-temp2;
    else return temp2-temp1;
}

Datum& Datum::operator +=(int broj) {
    *this=*this+broj;
    return *this;
}

Datum& Datum::operator -=(int broj) {
    *this=*this-broj;
    return *this;
}

bool Datum::operator ==(const Datum& d) {
    if(d.Datum::DajGodinu()!=godina) return false;
    if(d.Datum::DajDan()!=dan) return false;
    if(d.Datum::DajMjesec()!=mjesec) return false;
    return true;
}

bool Datum::operator !=(const Datum& d) {
    return !(*this==d);
}

bool Datum::operator <(const Datum& d) {
    if(godina<d.godina) return true;
    else if(godina>d.godina) return false;
    else if(mjesec<d.mjesec) return true;
    else if(mjesec>d.mjesec) return false;
    else if(dan<d.dan) return true;
    else return false;
}

bool Datum::operator <=(const Datum& d) {
    if(dan>d.dan) return false;
    else if(mjesec>d.mjesec) return false;
    else if(godina>d.godina) return false;
    else return true;
}

bool Datum::operator >(const Datum& d) {
    if(godina<d.godina) return false;
    else if(godina>d.godina) return true;
    else if(mjesec<d.mjesec) return false;
    else if(mjesec>d.mjesec) return true;
    else if(dan>d.dan) return true;
    else return false;
}

bool Datum::operator >=(const Datum& d) {
    if(dan<d.dan) return false;
    else if(mjesec<d.mjesec) return false;
    else if(godina<d.godina) return false;
    else return true;
}

std::ostream &operator<<(std::ostream &tok, const Datum &d) {
    tok << d.dan << "." << d.DajImeMjeseca() << " " << d.godina << ".(" << d.DajImeDanaUSedmici() << ")";
    return tok;
}

std::istream &operator>>(std::istream &tok, Datum &d) {
    char temp;
    tok >> d.dan >> temp;
    if(temp!='/') tok.setstate(std::ios::failbit);
    tok >> d.mjesec >> temp;
    if(temp!='/') tok.setstate(std::ios::failbit);
    tok >> d.godina;
    if(tok.peek()!='\n' && tok.peek()!=' ') tok.setstate(std::ios::failbit);
    if(d.godina<1800 || d.mjesec<1 || d.mjesec>12 || d.dan<1 || d.dan>31) tok.setstate(std::ios::failbit);
    if((d.mjesec==1 || d.mjesec==3 || d.mjesec==5 || d.mjesec==7 || d.mjesec==8 || d.mjesec==10 || d.mjesec==12) && d.dan>31) tok.setstate(std::ios::failbit);
    if((d.mjesec==4 || d.mjesec==6 || d.mjesec==9 || d.mjesec==11) && d.dan>30) tok.setstate(std::ios::failbit);
    if(d.godina%4==0 && (d.godina%100!=0 || d.godina%400==0)) {
        if(d.mjesec==2 && d.dan>29) tok.setstate(std::ios::failbit);
    } else {
        if(d.mjesec==2 && d.dan>28) tok.setstate(std::ios::failbit);
    }
    return tok;
}

Datum::operator std::string() const {
    std::string tok;
    tok=tok + Datum::Izmjena(dan) + "." + DajImeMjeseca() + " " + Datum::Izmjena(godina) + ".(" + DajImeDanaUSedmici() + ")";
    return tok;
}

Datum::operator int() const {
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int temp=dan-1;
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) brojdana[1]++;
    for(int i=0; i<mjesec; i++) temp+=brojdana[i];
    for(int i=1800; i<godina; i++) {
        if(i%4==0 && (i%100!=0 || i%400==0)) temp++;
    }
    temp+=(godina-1800)*365;
    return temp;
}


int main () {
    Datum d1(11, Datum::Mjeseci::Juni, 2008);
    Datum d2(18, Datum::Mjeseci::Decembar, 2010);
    Datum d3(23, Datum::Mjeseci::Mart, 1800);
    d1-=10;
    d2-=17;
    d2+=33;
    d3++;
    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
    std::cout << d3 << std::endl;
    return 0;
}

/*
class Datum {
public:
struct BadDatum;
enum Mjeseci {Januar=1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
enum Dani {Ponedjeljak=1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

private:
static char* ImenaMjeseci[12];
static bool defaultSet;
static Datum defaultDatum;
int dan, mjesec, godina;
bool leapYear(const int) const;
void fillDatum(int dan, enum Mjeseci mjesec, int godina);
void checkIllFormed();
bool isIllFormed() const;
void setVal(int&, const int, const int);

public:
//static void showDefault(std::ostream& os);
//static const std::string monthNameByNumber(const int);

Datum(int dan = (Datum::defaultSet)?Datum::defaultDatum.dan():1, Mjeseci mjesec = (Datum::defaultSet)?Datum::defaultDatum.Mjeseci():Mjeseci(1), int godina = (Datum::defaultSet)?Datum::defaultDatum.godina():1800);
Datum(int dan, int mjesec, int godina);
~Datum();
void Postavi(int dan, int mjesec, int godina);
void Postavi(const int dan=1, Mjeseci = Mjeseci(1),const int godina=1800);
int DajDan() const;
Mjeseci DajMjesec() const;
int DajGodinu() const;
const char* DajImeMjeseca() const;
Dani DanUSedmici() const;
Dani DajImeDanaUSedmici() const;
const Datum& operator++();
const Datum  operator++(int);
const Datum& operator--();
const Datum  operator--(int);
const Datum& operator+=(int);
const Datum& operator-=(int);
friend Datum operator-(const Datum& d1, const Datum& d2);
friend Datum operator==(const Datum& d1, const Datum& d2);
friend Datum operator!=(const Datum& d1, const Datum& d2);
friend Datum operator<(const Datum& d1, const Datum& d2);
friend Datum operator>(const Datum& d1, const Datum& d2);
friend Datum operator<=(const Datum& d1, const Datum& d2);
friend Datum operator>=(const Datum& d1, const Datum& d2);

void setDay(const int d) {setVal(dan, d, dan());}
void setMonth(const int);
void setYear(const int);
};

struct Datum::BadDatum {
    int dan, mjesec, godina;
    BadDatum(int dan, int mjesec, int godina);
};

std::ostream& operator<<(std::ostream&, const Datum&);
std::ostream& operator<<(std::ostream&, const Datum::BadDatum&);


Datum::BadDatum::BadDatum(int dan, int mjesec, int godina) : dan(dan), mjesec(mjesec), godina(godina) {}
char* Datum::ImenaMjeseci[12] = {
    "J", "F", "M",
    "A", "M", "J",
    "J", "A", "S",
    "O", "N", "D" 
};
bool Datum::defaultSet = true;
Datum Datum::defaultDatum = Datum(1, 1, 1800);

void Datum::Postavi(const int dan, Mjeseci mjesec, const int godina) {
    Datum::defaultDatum.setDay(dan);
    Datum::defaultDatum.setMonth(mjesec);
    Datum::defaultDatum.setYear(godina);
    Datum::defaultSet = true;
}
void Datum::showDefault(std::ostream& os) {
    os << Datum::defaultDatum;
}
const char* Datum::DajImeMjeseca() const{
    return Datum::ImenaMjeseci[mjesec-1];
}

Datum::Datum(int dan, Mjeseci mjesec, int godina) : dan(dan), mjesec(mjesec), godina(godina) {
    checkIllFormed();
}
Datum::Datum(int dan, int mjesec, int godina) : dan(dan), mjesec(Mjeseci(mjesec)), godina(godina) {
    checkIllFormed();
}
Datum::Datum(const Datum& that) : dan(that.day()), mjesec(that.Mjeseci()), godina(that.year()) {
    checkIllFormed();
}
void Datum::checkIllFormed() {
    if(isIllFormed()) {
        BadDatum bd = BadDatum(day(), Mjeseci(), year());
        *this = Datum::defaultDatum;
        throw bd;
    }
}
Datum& Datum::operator=(const Datum& that) {
    fillDatum(that.day(), that.Mjeseci(), that.year());
    return *this;
}
Datum::~Datum(void) {

}

int Datum::day() const {
    return dan;
}
Datum::Mjeseci Datum::Mjeseci() const {
    return Mjeseci(mjesec);
}
int Datum::year() const {
    return godina;
}

const std::string Datum::getMjeseciName() const {
    return Datum::MjeseciNameByNumber(Mjeseci());
}

void Datum::setDay(const int d) {
    setVal(dan, d, day());
}
void Datum::setMjeseci(const int m) {
    setVal(mjesec, m, Mjeseci());
}
void Datum::setYear(const int y) {
    setVal(godina, y, year());
}
void Datum::setVal(int& val, const int newVal, const int prevVal) {
    val = newVal;
    if(isIllFormed()) {
        BadDatum bd = BadDatum(day(), Mjeseci(), year());
        val = prevVal;
        throw bd;
    }
}

const Datum& Datum::operator++() {
    setDay(day() + 1);
    return *this;
}
const Datum Datum::operator++(int) {
    setDay(day() + 1);
    return *this;
}
const Datum& Datum::operator--() {
    setDay(day() - 1);
    return *this;
}
const Datum Datum::operator--(int) {
    setDay(day() - 1);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Datum& d) {
    os << d.day() << "." << d.getMjeseciName() << "." << d.year();
    return os;
}
std::ostream& operator<<(std::ostream& os, const Datum::BadDatum& bd) {
    os << bd.dan << "." << Datum::MjeseciNameByNumber(bd.mjesec) << "." << bd.godina;
    return os;
}

bool Datum::leapYear(const int y) const {
    
    1.If the year is evenly divisible by 4, go to step 2. Otherwise, go to step 5.
    2.If the year is evenly divisible by 100, go to step 3. Otherwise, go to step 4.
    3.If the year is evenly divisible by 400, go to step 4. Otherwise, go to step 5.
    4.The year is a leap year (it has 366 days).
    5.The year is not a leap year (it has 365 days).
    
    if(y%4) {
        return false;
    }
    if(y%100) {
        return true;
    }
    if(y%400) {
        return false;
    }
    return true;
}
void Datum::fillDatum(int d, enum Mjeseci m, int y) {
    setDay(d);
    setMjeseci(m);
    setYear(y);
}

bool Datum::isIllFormed() const {
    const int d(day()), m(Mjeseci()), y(year());

    //check year
    if(y < 0) {
        return true;
    }

    //check Mjeseci
    if(m < 1 || 12 < m) {
        return true;
    }

    //check day
    int maxDay((7<m)?31-m%2:30+m%2);
    if(m == 2) {
        if(leapYear(y)) {
            maxDay = 29;
        } else {
            maxDay = 28;
        }
    }
    if(d<1 || maxDay<d) {
        return true;
    }

    return false;
}

int main() {
    
    return 0;
}*/