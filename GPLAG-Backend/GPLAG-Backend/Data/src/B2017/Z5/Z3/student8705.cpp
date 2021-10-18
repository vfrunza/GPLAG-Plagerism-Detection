#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <cctype>
#include <cmath>

std::string int_str(int x)
{
    std::ostringstream o; o << x; return o.str();
}
class Datum
{
    int d, m, g;
    static int BrojDana(int, int);
    static bool Validan(int d, int m, int g) { return m >= 1 && m <= 12 && d >= 1 && d <= BrojDana(m, g) && g >= 1800; }
public:
    enum Mjeseci { Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August,
        Septembar, Oktobar, Novembar, Decembar };
    enum Dani { Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja };
    Datum(int d, int m, int g) { Postavi(d, m, g); }
    Datum(int d, Mjeseci m, int g) { Postavi(d, m, g); }
    void Postavi(int dan, int mjesec, int godina);
    void Postavi(int dan, Mjeseci mjesec, int godina) { Postavi(dan, int(mjesec), godina); }
    int DajDan() const { return d; }
    Mjeseci DajMjesec() const { return Mjeseci(m); }
    int DajGodinu() const { return g; }
    const char *DajImeMjeseca() const;
    Dani DanUSedmici() const;
    const char *DajImeDanaUSedmici() const;
    
    Datum &operator ++();
    Datum &operator --();
    Datum operator ++(int);
    Datum operator --(int);
    Datum &operator +=(int x);
    Datum &operator -=(int x) { return *this += -x; }
    Datum operator +(int x) const { Datum pom(*this); return pom += x; }
    Datum operator -(int x) const { return *this + (-x); }
    int operator -(const Datum &x) const { return int(*this) - int(x); }
    bool operator ==(const Datum &x) const { return d == x.d && m == x.m && g == x.g; }
    bool operator !=(const Datum &x) const { return !(*this == x); }
    bool operator <(const Datum &x) const { return g < x.g || (g == x.g && (m < x.m || (m == x.m && d < x.d))); }
    bool operator >=(const Datum &x) const { return !(*this < x); }
    bool operator <=(const Datum &x) const { return *this < x || *this == x; }
    bool operator >(const Datum &x) const { return !(*this <= x); }
    friend std::ostream &operator <<(std::ostream &o, const Datum &x) { return o << std::string(x); }
    friend std::istream &operator >>(std::istream &i, Datum &x);
    operator std::string() const;
    explicit operator int() const;
};
int Datum::BrojDana(int m, int g)
{
    static int br_dana[12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return br_dana[m-1] + (m == 2 && ((g % 100 != 0 && g % 4 == 0) || g % 400 == 0));
}
void Datum::Postavi(int dan, int mjesec, int godina)
{
    if (!Validan(dan, mjesec, godina)) throw std::domain_error("Nelegalan datum");
    d = dan; m = mjesec; g = godina;
}
const char *Datum::DajImeMjeseca() const
{
    static const char *imena[]{ "Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar" };
    return imena[m-1];
}
//Greska u postavci, pise da je 1.1.1800 nedjelja a treba srijeda
Datum::Dani Datum::DanUSedmici() const
{
    return Dani(1 + (int(*this) + 2) % 7);
}
const char *Datum::DajImeDanaUSedmici() const
{
    static const char *dani[] { "Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja" };
    return dani[int(DanUSedmici()) - 1];
}
Datum &Datum::operator ++()
{
    if (Validan(d+1, m, g)) Postavi(d+1, m, g);
    else if (Validan(1, m+1, g)) Postavi(1, m+1, g);
    else Postavi(1, 1, g+1);
    return *this;
}
Datum &Datum::operator --()
{
    if (Validan(d-1, m, g)) Postavi(d-1, m, g);
    else if (Validan(BrojDana(m-1, g), m-1, g)) Postavi(BrojDana(m-1, g), m-1, g);
    else Postavi(BrojDana(12, g-1), 12, g-1);
    return *this;
}
Datum Datum::operator ++(int)
{
    Datum d(*this);
    ++*this;
    return d;
}
Datum Datum::operator --(int)
{
    Datum d(*this);
    --*this;
    return d;
}
Datum &Datum::operator +=(int x)
{
    Datum dat(*this);
    int br_god(x / 365.2425), br_mj((x - br_god * 365.2425) / 30.44), br_d(x - br_mj * 30.44);
    g = std::max(g + br_god, 1800);
    m = std::min(std::max(m + br_mj, 1), 12);
    d = std::min(std::max(d + br_d, 1), 28);
    while (int razlika = int(*this) - int(dat) - x)
        if (razlika > 0) --*this;
        else ++*this;
    return *this;
}
bool slash(std::istream &cin) { return cin.peek() == '/' && (cin.get() || true); }
//?Da li smije datum pocinjati sa razmakom (tj. znakom koji ne dovodi da cin >> int upadne u neispravno stanje)
//Ako ne smije onda se javlja pitanje da li je dozvoljeno koristiti cin.ignore()
//Jer sta ako je korisnik unosio nesto prije ovog datuma, onda je ostao onaj \n u spremniku
//Sta ako je jos znakova ostalo u spremniku od prethodnog unosa, da li se tok postavlja u neispravno stanje ili?
std::istream &operator >>(std::istream &cin, Datum &x)
{
    int a(0), b(0), c(0);
    if (/*!std::isdigit(cin.peek()) || */!(cin >> a) || !slash(cin) || !std::isdigit(cin.peek())
    || !(cin >> b) || !slash(cin) || !std::isdigit(cin.peek())
    || !(cin >> c) || cin.peek() != '\n' || !Datum::Validan(a, b, c))
        cin.setstate(std::ios::failbit);
    else x.Postavi(a, b, c);
    return cin;
}
Datum::operator std::string() const
{
    return int_str(d) + ". " + DajImeMjeseca() + " " + int_str(g) + ". (" + DajImeDanaUSedmici() + ")";
}
Datum::operator int() const
{
    int br_dana((g - 1800) * 365 + (g - 1797) / 4 - (g - 1701) / 100 + (g - 1601) / 400);
    for (int i(1); i < m; ++i) br_dana += BrojDana(i, g);
    return br_dana + d - 1;
}

int main()
{
    //Test operatora +=, -(Datum, Datum), !=, a ujedno i operatora ++, --
    //Ako ne ispise "BAD", onda su operatori dobri
    for (int i(0); i < 100; ++i)
    {
        Datum izvor(1 + std::rand() % 28, 1 + std::rand() % 12, 1800 + rand() % 999999),
        odrediste(1 + std::rand() % 28, 1 + std::rand() % 12, 1800 + rand() % 999999);
        if ((izvor += (odrediste - izvor)) != odrediste) std::cout << "BAD";
    }
    Datum dat1(18, 6, 2018), dat2(18, Datum::Juni, 2018), dat3(7, 4, 1934);
    std::cout << "Jednaki: " << std::boolalpha << (dat1 == dat2);
    std::cout << '\n' << dat1 << '\n';
    if (dat3 < dat1) std::cout << "Manji\n";
    if (dat3 > dat1) std::cout << "Veci\n";
    if (dat3 != dat1) std::cout << "Razliciti\n";
    if (dat3 <= dat1) std::cout << "Manji ili jednak\n";
    if (dat3 >= dat1) std::cout << "Veci ili jednak\n";
    std::cout << "Unesite datum: ";
    std::cin >> dat1;
    int n;
    std::cout << "Unesite broj dana: ";
    std::cin >> n;
    std::cout << "Datum pomjeren za uneseni broj dana unaprijed je: " << (dat1+n) << " , a unazad: " << (dat1-n);
	return 0;
}