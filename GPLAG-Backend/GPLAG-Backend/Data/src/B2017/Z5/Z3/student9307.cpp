/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>

// funkcija koja vraca redni broj dana u sedmici za dati datum, a u slucaju da joj je parametar hocu broj dana vraca broj dana izmedju referentnog i unesenog
int KojiJeBioDan (int dan, int mjesec, int godina, bool hocu_broj_dana=false)
{
    int broj_dana [] {31,28,31,30,31,30,31,31,30,31,30,31};
    if ((godina % 4 == 0 && godina % 100 !=0 ) || godina % 400 == 0) broj_dana[1]++;

    int prestupne(0);
    for (int i = 1800; i<=godina; i++) if ((i % 4 == 0 && i % 100 !=0 ) || i % 400 == 0) prestupne++;

    int od_1_do_mjesec(0);
    for (int i = 0; i<mjesec-1; i++) od_1_do_mjesec+=broj_dana[i];
    int ukupno_dana=prestupne+(godina-1800)*365+od_1_do_mjesec+dan-1; // minus jedan jer ne racunam prvi dan npr. izmedju 1.1.1800 i 13.1.1800 ima 12 a ne 13 dana
    if ((godina % 4 == 0 && godina % 100 !=0 ) || godina % 400 == 0) ukupno_dana--; // ako je prestupna godina
    if (hocu_broj_dana)
        return ukupno_dana;
    return  (ukupno_dana+2)%7+1; // +2 zbog srijeda, +1 da fino izbaci dan ako je 1 ponedjeljak
}
class Datum
{
    int dan, mjesec, godina;
    static void Izuzetak(int dan, int mjesec, int godina) {
        int broj_dana [] {31,28,31,30,31,30,31,31,30,31,30,31};
        if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
        if (godina<1800 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw std::domain_error ("Nelegalan datum");
    }

public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

    Datum (int dan, int mjesec, int godina) {
        Izuzetak(dan,mjesec, godina);
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }

    Datum (int dan, Mjeseci mjesec, int godina) {
        Izuzetak(dan,int(mjesec),godina);
        Datum::dan=dan;
        Datum::mjesec=int(mjesec);
        Datum::godina=godina;
    }

    void Postavi (int dan, int mjesec, int godina) {
        Izuzetak(dan, mjesec, godina);
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }

    void Postavi (int dan, Mjeseci mjesec, int godina ) {
        Izuzetak (dan, int(mjesec), godina);
        Datum::dan=dan;
        Datum::mjesec=int(mjesec);
        Datum::godina=godina;
    }

    int DajDan () const {
        return dan;
    }

    Mjeseci DajMjesec() const {
        return Mjeseci(mjesec);
    }

    int DajGodinu () const {
        return godina;
    }

    // da li mora biti const
    const char* DajImeMjeseca () const {
        const char* imena[12] {"Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar" , "Oktobar", "Novembar", "Decembar"};
        return (imena[mjesec-1]);
    }

    Dani DanUSedmici () const {
        return Dani(KojiJeBioDan(dan,mjesec,godina));
    }
    // da li može biti const
    const char* DajImeDanaUSedmici () const {
        const char *imena[7] {"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};
        return imena[int(DanUSedmici())-1];
    }

    Datum& operator ++();

    Datum operator ++(int);

    Datum& operator --();

    Datum operator --(int);

    Datum operator +(int x) const; 

    friend Datum operator +(int x,const Datum& dat);

    Datum operator -(int x) const;

    Datum& operator +=(int x);

    Datum& operator -=(int x);

    friend int operator -(const Datum& dat1,const Datum& dat2) {
        return abs(KojiJeBioDan(dat1.DajDan(),int(dat1.DajMjesec()),dat1.DajGodinu(), true)-
                   KojiJeBioDan(dat2.DajDan(),int(dat2.DajMjesec()),dat2.DajGodinu(), true));
    }

    friend bool operator ==(const Datum& dat1,const Datum& dat2);

    friend bool operator !=(const Datum& dat1,const Datum& dat2);

    friend bool operator <(const Datum& dat1,const Datum& dat2) {
        return (KojiJeBioDan(dat1.DajDan(),int(dat1.DajMjesec()),dat1.DajGodinu(), true)<
                KojiJeBioDan(dat2.DajDan(),int(dat2.DajMjesec()),dat2.DajGodinu(), true));
    }

    friend bool operator >(const Datum& dat1,const Datum& dat2) {
        return !(dat1<dat2);
    }

    friend bool operator <=(const Datum& dat1,const Datum& dat2) {
        return (KojiJeBioDan(dat1.DajDan(),int(dat1.DajMjesec()),dat1.DajGodinu(), true)<=
                KojiJeBioDan(dat2.DajDan(),int(dat2.DajMjesec()),dat2.DajGodinu(), true));
    }

    friend bool operator >=(const Datum& dat1,const Datum& dat2) {
        return (KojiJeBioDan(dat1.DajDan(),int(dat1.DajMjesec()),dat1.DajGodinu(), true)>=
                KojiJeBioDan(dat2.DajDan(),int(dat2.DajMjesec()),dat2.DajGodinu(), true));
    }

    operator std::string () const;

    explicit operator int () const;

};
Datum operator +(int x,const Datum& dat)
{
    return dat+x;
}

Datum& Datum::operator ++()
{
    int broj_dana [] {31,28,31,30,31,30,31,31,30,31,30,31};
    if ((this->godina % 4 == 0 && this->godina % 100 != 0) || this->godina % 400 == 0) broj_dana[1]++;
    if (this->dan == broj_dana[this->mjesec-1]) {
        this->dan=1;
        if (this->mjesec==12) {
            this->mjesec=1;
            this->godina++;
        } else this->mjesec++;
    } else this->dan++;
    return *this;
}

Datum Datum::operator ++(int)
{
    Datum privremeni(*this);
    ++(*this);
    return privremeni;
}

Datum& Datum::operator --()
{
    if (this->dan==1 && this->mjesec==1 && this->godina==1800) throw std::domain_error ("Nelegalan datum");
    int broj_dana [] {31,28,31,30,31,30,31,31,30,31,30,31};
    if ((this->godina % 4 == 0 && this->godina % 100 != 0) || this->godina % 400 == 0) broj_dana[1]++;
    if (this->dan==1) {
        if (this->mjesec==1) {
            this->mjesec=12;
            this->godina--;
        } else this->mjesec--;
        this->dan=broj_dana[mjesec-1];
    } else this->dan--;
    return *this;
}

Datum Datum::operator --(int)
{
    Datum privremeni(*this);
    --(*this);
    return privremeni;
}

Datum Datum::operator +(int x) const
{
    Datum privremeni(*this);
    if (x>0)
        for (int i = 0; i<x; i++) ++(privremeni);
    else for (int i = 0; i<-x; i++) --(privremeni);
    return privremeni;
}

Datum Datum::operator -(int x) const
{
    Datum privremeni(*this);
    return privremeni+(-x);
}

Datum& Datum::operator +=(int x)
{
    *this=*this+x;
    return *this;
}

Datum& Datum::operator -=(int x)
{
    *this=*this-x;
    return *this;
}

bool operator ==(const Datum& dat1,const Datum& dat2)
{
    return (dat1.DajDan()==dat2.DajDan() && dat1.DajMjesec()==dat2.DajMjesec() && dat1.DajGodinu()==dat2.DajGodinu());
}

bool operator !=(const Datum& dat1,const Datum& dat2)
{
    return !(dat1==dat2);
}

std::ostream& operator << (std::ostream &tok, const Datum &dat)
{
    tok<<dat.DajDan()<<"."<<dat.DajImeMjeseca()<<" "<<dat.DajGodinu()<<".("<<dat.DajImeDanaUSedmici()<<")";
    return tok;
}

std::istream& operator >> (std::istream &tok, Datum &dat)
{
    char znak1,znak2;
    int d,m,g;
    tok>>d>>znak1>>m>>znak2>>g;
    if (znak1!='/' || znak2!='/' || std::cin.peek()!='\n') tok.setstate(std::ios::failbit);
    if (tok) dat.Postavi(d,m,g);
    return tok;

}

Datum::operator std::string () const
{
    std::string s;
    s+=std::to_string(this->DajDan());
    s.push_back('.');
    s+=this->DajImeMjeseca();
    s.push_back(' ');
    s+=std::to_string(this->DajGodinu());
    s+=".(";
    s+=this->DajImeDanaUSedmici();
    s.push_back(')');
    return s;
}

Datum::operator int () const
{
    return KojiJeBioDan(dan,mjesec,godina,true);
}


int main ()
{
    try {
        Datum datum (6,6,1944), dat2(15,1,1800);
        std::cout<<datum<<std::endl;
        datum++;
        std::cout<<datum<<std::endl;
        datum+=27036;
        std::cout<<datum<<std::endl;
        datum--;
        std::cout<<datum<<std::endl;
        datum-=70000;
        std::cout<<datum<<std::endl;
        datum=datum+60000;
        datum=10000+datum;
        std::cout<<datum<<std::endl;
        if (datum>dat2) std::cout<<"Datum: "<<datum<<" je veci od "<<dat2<<std::endl;
        std::cout<<"Unesite datum: ";
        std::cin>>dat2;
        std::cout<<"Unijeli ste: "<<dat2<<std::endl;
        dat2-=25703;
        std::cout<<"Oslobodjenje: "<<dat2;
    } catch (std::domain_error i) {
        std::cout<<i.what();
    }
    return 0;
}
