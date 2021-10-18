#include <iostream>
#include <stdexcept>
#include <exception>
#include <string>
#include <sstream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Datum
{
    int dan,mjesec,godina;
    int dansedmica;
    static bool DaLiJeIspravno(int m, int g) {
        return (m>=1 && m<=12 && g>=1800);
    }
    static int BrojDana (int mjesec, int godina) {
        int BrojDana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((godina%4==0 && godina%100!=0) || godina%400==0) BrojDana[1]++;
        return BrojDana[mjesec-1];
    }
    static int Prestupne(const Datum &d) {
        int godine=d.godina;
        if (d.mjesec <= 2)
            godine--;
        return godine/4 - godine/100 + godine/400;
    }

    static int KojiJeDan(int dan, int mjesec, int godina) {
        static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        godina -= mjesec < 3;
        int x = (godina + godina/4 - godina/100 + godina/400 + t[mjesec-1] + dan) % 7;
        if(x==0) x=7;
        return x;
    }

    const char * mjechr[12]= {"Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August",
                              "Septembar", "Oktobar", "Novembar", "Decembar"
                             };
    const char * dachr[7]= {"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};
public:

    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August,
                  Septembar, Oktobar, Novembar, Decembar
                 };
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

    Datum() {}
    Datum(int d, int m, int g) {
        if(!DaLiJeIspravno(m,g) || d<1 || d>BrojDana(m,g)) throw std::domain_error("Nelegalan datum");
        dan=d;
        mjesec=m;
        godina=g;
        dansedmica=KojiJeDan(dan,mjesec,godina);
    }

    Datum(int d, Mjeseci m, int g) {
        if(!DaLiJeIspravno(m,g) || d<1 || d>BrojDana(m,g)) throw std::domain_error("Nelegalan datum");
        dan=d;
        mjesec=m;
        godina=g;
        dansedmica=KojiJeDan(dan,mjesec,godina);
    }

    void Postavi(int dan, int mjesec, int godina) {
        if(!DaLiJeIspravno(mjesec,godina) || dan<1 || dan>BrojDana(mjesec,godina)) throw std::domain_error("Nelegalan datum");
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
        dansedmica=KojiJeDan(Datum::dan,Datum::mjesec,Datum::godina);
    }

    void Postavi(int dan, Mjeseci mjesec, int godina) {
        if(!DaLiJeIspravno(mjesec,godina) || dan<1 || dan>BrojDana(mjesec,godina)) throw std::domain_error("Nelegalan datum");
        Datum::dan = dan;
        Datum::mjesec = static_cast<int>(mjesec);
        Datum::godina = godina;
        dansedmica=KojiJeDan(Datum::dan,Datum::mjesec,Datum::godina);
    }

    int DajDan() const {
        return dan;
    }

    int DajGodinu() const {
        return godina;
    }

    Mjeseci DajMjesec() const {
        return static_cast<Mjeseci>(mjesec);
    }

    const char * DajImeMjeseca() const {
        return mjechr[mjesec-1];
    }

    Dani DanUSedmici() const {
        return static_cast<Dani>(dansedmica);
    }

    const char * DajImeDanaUSedmici() const {
        return dachr[dansedmica-1];
    }

    Datum & operator ++() {
        int dan1(dan), mjesec1(mjesec), godina1(godina);
        dan1++;
        if(dan1>Datum::BrojDana(mjesec1,godina1)) {
            dan1=1;
            mjesec1++;
        }
        if (mjesec1>12) {
            mjesec1=1;
            godina1++;
        }
        this->Postavi(dan1, mjesec1, godina1);
        return *this;
    }

    Datum operator ++(int) {
        Datum temp(*this);
        ++(*this);
        return temp;
    }

    Datum &operator --() {
        int dan1(dan), mjesec1(mjesec), godina1(godina);
        dan1--;
        if (dan1<1) {
            mjesec1--;
            if (mjesec1>0) dan1=Datum::BrojDana(mjesec1, godina1);
        }
        if(mjesec1<1) {
            mjesec1=12;
            godina1--;
            if(godina1<1800) throw std::domain_error("Nelegalan datum");
            dan1=Datum::BrojDana(mjesec1,godina1);
        }
        this->Postavi(dan1, mjesec1, godina1);
        return *this;
    }

    Datum operator --(int) {
        Datum temp(*this);
        --(*this);
        return temp;
    }

    Datum &operator +=(int n) {
        while(n!=0) {
            ++(*this);
            n--;
        }
        return *this;
    }

    Datum &operator -=(int n) {
        while(n!=0) {
            --(*this);
            n--;
        }
        return *this;
    }

    operator std::string() const {
        string s(std::to_string(dan) + "." + mjechr[mjesec-1] + " " + std::to_string(godina) + ".(" + dachr[dansedmica-1] + ")");
        return s;
    }

    explicit operator int() const {
        Datum ref(1,1,1800);
        return *this-ref;
    }

    friend std::ostream & operator << (std::ostream &tok, const Datum &d);
    friend std::istream & operator >> (std::istream &utok, Datum &d);
    friend Datum operator +(Datum d, int n);
    friend Datum operator -(Datum d, int n);
    friend int operator -(const Datum &d1, const Datum &d2);
    friend bool operator ==(const Datum &d1, const Datum &d2);
    friend bool operator !=(const Datum &d1, const Datum &d2);
    friend bool operator <(const Datum &d1, const Datum &d2);
    friend bool operator >(const Datum &d1, const Datum &d2);
    friend bool operator <=(const Datum &d1, const Datum &d2);
    friend bool operator >=(const Datum &d1, const Datum &d2);

};

std::ostream & operator << (std::ostream &tok, const Datum &d)
{
    tok << string(d) << endl;
    return tok;
}

std::istream & operator >> (std::istream &utok, Datum &d1)
{
    int d,m,g;
    char znak;
    utok >> d;
    if(!utok.fail() && utok.peek()=='/') {
        utok >> znak >> m;
        if(!utok.fail() && utok.peek()=='/') utok >> znak>> g;
        else utok.setstate(std::ios::failbit);
    } else utok.setstate(std::ios::failbit);

    d1.Postavi(d,m,g);
    return utok;
}

Datum operator +(Datum d, int n)
{
    while(n!=0) {
        ++d;
        n--;
    }
    return d;
}

Datum operator -(Datum d, int n)
{
    while(n!=0) {
        --d;
        n--;
    }
    return d;
}


int operator -(const Datum &d1, const Datum &d2)
{
    long int x = d1.godina*365+d1.dan;
    for(int i=1; i<d1.mjesec; i++) x+=Datum::BrojDana(i,d1.godina);
    x+=Datum::Prestupne(d1);

    long int y = d2.godina*365+d2.dan;
    for(int i=1; i<d2.mjesec; i++) y+=Datum::BrojDana(i,d2.godina);
    y+=Datum::Prestupne(d2);

    return abs(x-y);
}

bool operator ==(const Datum &d1, const Datum &d2)
{
    return (d1.dan==d2.dan && d1.mjesec==d2.mjesec && d1.godina==d2.godina);
}

bool operator !=(const Datum &d1, const Datum &d2)
{
    return !(d1.dan==d2.dan && d1.mjesec==d2.mjesec && d1.godina==d2.godina);
}

bool operator <(const Datum &d1, const Datum &d2)
{
    return (d1.godina<d2.godina || (d1.godina==d2.godina && d1.mjesec<d2.mjesec) || (d1.godina==d2.godina && d1.mjesec==d2.mjesec && d1.dan<d2.dan));
}

bool operator >(const Datum &d1, const Datum &d2)
{
    return (d1!=d2 && !(d1<d2));
}
bool operator <=(const Datum &d1, const Datum &d2)
{
    return (d1==d2 || d1<d2);
}

bool operator >=(const Datum &d1, const Datum &d2)
{
    return (d1==d2 || d1>d2);
}


int main ()
{
    try {
        Datum d1(31, 12, 1998);
        Datum d2(22, 12, 1998);
        d2.Postavi(22, 11, 1998);
        std::cout << d1.DajDan() << std::endl;
        std::cout << d1.DajMjesec() << std::endl;
        std::cout << d1.DajGodinu() << std::endl;
        std::cout << d1.DajImeMjeseca() << std::endl;
        std::cout << d1.DajImeDanaUSedmici() << std::endl;
        std::cout << d1.DanUSedmici() << std::endl;
        d1++;
        ++d1;
        std::cout << d1 << std::endl;
        d1--;
        --d1;
        std::cout << d1 << std::endl;
        Datum d3;
        std::cout << "Unesite datum: ";
        std::cin >> d3;
        if (!std::cin) std::cout << "Greska pri unosu" << std::endl;
       std::cout << d3;
        if (d1==d2) std::cout << "Jednaki su"  << std::endl;
        if (d1!=d2) std::cout << "Nisu jednaki"  << std::endl;
        if (d1<d2) std::cout << "d1 je manji od d2"  << std::endl;
        if (d1<=d2) std::cout << "d1 je manji ili jednak d2"  << std::endl;
        if (d1>d2) std::cout << "d1 je veci od d2"  << std::endl;
        if (d1>=d2) std::cout << "d1 je veci ili jednak d2"  << std::endl;
        std::cout << "Proslo je " << d1-d2 << " dana između " << d1 << " i " << d2 << std::endl;
        std::cout << d2;
        d2-=44;
        std::cout << d2;
        --d2;
        std::cout << d2;
        d1+=8;
        std::cout << d1;

    } catch(std::exception &iz) {
        std::cout << iz.what();
    }
    return 0;
}