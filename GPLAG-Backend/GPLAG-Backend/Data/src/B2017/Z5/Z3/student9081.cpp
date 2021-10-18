/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <string>

class Datum
{
    int dan,mjesec,godina;
    static int BrojDana (int m, int g);
    int UkupnoDana () const;
    static bool Prestupna (int g) {return g%4==0 && (g%100!=0 || g%400==0);}
public:
    enum Mjeseci {Januar=1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak=1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    Datum (int d, int m, int g) {Postavi (d,m,g);}
    Datum (int d, Mjeseci m, int g) {Postavi (d,int(m),g);}
    void Postavi (int d, int m, int g);
    void Postavi (int d, Mjeseci m, int g) {Postavi(d,int(m),g);}
    int DajDan () const {return dan;}
    Mjeseci DajMjesec () const {return Mjeseci(mjesec);}
    int DajGodinu () const {return godina;}
    const char *DajImeMjeseca () const;
    Dani DanUSedmici () const {int temp(0); const char *ime[]{"Ponedjeljak","Utorak","Srijeda","Cetvrtak","Petak","Subota","Nedjelja"}; 
    for (int i=0;i<7;i++) {if (DajImeDanaUSedmici()==ime[i]) {temp=i; break;}} return Dani(temp+1);}
    const char *DajImeDanaUSedmici () const;
    Datum &operator++();
    Datum operator++(int);
    Datum &operator--();
    Datum operator--(int);
    Datum &operator+=(int n);
    inline Datum operator + (int n) {Datum d(*this); d+=n; return d;}
    inline Datum &operator-= (int n) {return *this+=-n;}
    inline Datum operator - (int n) {Datum d(*this); d-=n; return d;}
    friend int operator - (const Datum &d1, const Datum &d2);
    friend bool operator == (const Datum &d1, const Datum &d2);
    friend bool operator != (const Datum &d1, const Datum &d2);
    friend bool operator < (const Datum &d1, const Datum &d2);
    friend bool operator > (const Datum &d1, const Datum &d2);
    friend bool operator <= (const Datum &d1, const Datum &d2);
    friend bool operator >= (const Datum &d1, const Datum &d2);
    friend std::ostream &operator << (std::ostream &tok, const Datum &d);
    friend std::istream &operator >> (std::istream &tok, Datum &d);
    operator std::string () const {return std::to_string(dan)+"."+DajImeMjeseca()+" "+std::to_string(godina)+".("+DajImeDanaUSedmici()+")";}
    explicit operator int () const {return this->UkupnoDana();}
};

std::istream &operator>> (std::istream &tok, Datum &d)
{
    char znak;
    tok>>d.dan>>znak;
    if (znak!='/') tok.setstate(std::ios::failbit);
    tok>>d.mjesec>>znak;
    if (znak!='/') tok.setstate(std::ios::failbit);
    tok>>d.godina;
    if (d.dan<1 || d.mjesec<1 || d.godina<1800 || d.mjesec>12 || d.dan>Datum::BrojDana(d.mjesec,d.godina)) tok.setstate(std::ios::failbit);
    return tok;
}

std::ostream &operator << (std::ostream &tok, const Datum &d)
{
    return tok<<d.dan<<"."<<d.DajImeMjeseca()<<" "<<d.godina<<".("<<d.DajImeDanaUSedmici()<<")";
}

inline bool operator >= (const Datum &d1, const Datum &d2)
{
    return d1>d2 || d1==d2;
}

inline bool operator <= (const Datum &d1, const Datum &d2)
{
    return d1<d2 || d1==d2;
}

bool operator > (const Datum &d1, const Datum &d2)
{
    if (d1.godina==d2.godina)
    {
        if (d1.mjesec==d2.mjesec)
        {
            return d1.dan>d2.dan;
        }
        return d1.mjesec>d2.mjesec;
    }
    return d1.godina>d2.godina;
}

bool operator < (const Datum &d1, const Datum &d2)
{
    if (d1.godina==d2.godina)
    {
        if (d1.mjesec==d2.mjesec)
        {
            return d1.dan<d2.dan;
        }
        return d1.mjesec<d2.mjesec;
    }
    return d1.godina<d2.godina;
}

bool operator == (const Datum &d1, const Datum &d2)
{
    return d1.dan==d2.dan && d1.mjesec==d2.mjesec && d1.godina==d2.godina;
}

inline bool operator != (const Datum &d1, const Datum &d2)
{
    return !(d1==d2);
}

int operator - (const Datum &d1, const Datum &d2)
{
    return d1.UkupnoDana()-d2.UkupnoDana();
}

Datum &Datum::operator+= (int n)
{
    Datum temp(*this);
    try
    {
        if (n>=0)
        {
            for (int i=0;i<n;i++)
            ++(*this);
        }
        else
        {
            for (int i=0;i<-n;i++)
            --(*this);
        }
    }
    catch (std::domain_error)
    {
        *this=temp;
        throw;
    }
    return *this;
}

Datum Datum::operator-- (int)
{
    Datum temp(*this);
    --(*this);
    return temp;
}

Datum &Datum::operator-- ()
{
    Datum temp(*this);
    dan--;
    if (dan==0)
    {
        mjesec--;
        if (mjesec==0)
        {
            mjesec=12;
            godina--;
        }
        dan=BrojDana(mjesec,godina);
    }
    if (godina<1800)
    {
        *this=temp;
        throw std::domain_error ("Nelegalan datum");
    }
    return *this;
}

Datum &Datum::operator++ ()
{
    dan++;
    if (dan>BrojDana(mjesec,godina)) dan=1,mjesec++;
    if (mjesec>12) mjesec=1,godina++;
    return *this;
}

Datum Datum::operator++ (int)
{
    Datum temp(*this);
    ++(*this);
    return temp;
}

const char *Datum::DajImeDanaUSedmici () const
{
    const char *ime[]{"Srijeda","Cetvrtak","Petak","Subota","Nedjelja","Ponedjeljak","Utorak"};
    return ime[UkupnoDana()%7];
}

int Datum::UkupnoDana() const
{
    int ukupno(0);
    for (int i=1800;i<godina;i++)
        ukupno+=365+int(Prestupna(i));
    for (int i=1;i<mjesec;i++)
        ukupno+=BrojDana(i,godina);
    for (int i=1;i<dan;i++)
        ++ukupno;
    return ukupno;
}

const char *Datum::DajImeMjeseca() const
{
    const char *ime[]{"Januar","Februar","Mart","April","Maj","Juni","Juli","August","Septembar","Oktobar","Novembar","Decembar"};
    return ime[mjesec-1];
}

int Datum::BrojDana (int m, int g)
{
    int bd[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if (Datum::Prestupna(g)) bd[1]++;
    return bd[m-1];
}

void Datum::Postavi(int d, int m, int g)
{
    if (g<1800 || d<1 || m<1 || m>12 || d>BrojDana(m,g)) throw std::domain_error ("Nelegalan datum");
    dan=d; mjesec=m; godina=g;
}

int main ()
{
    try 
    {
        Datum d(14,2,1998);
        for (;;)
        {
            int n;
            std::cout<<"Odaberite opciju:\n1 - Pomjeri unaprijed\n2 - Pomjeri unazad\n3 - Koji je danas dan?\n4 - Pretvori u string\n5 - Daj broj dana od 1.1.1800.\n";
            std::cout<<"6 - Ime mjeseca\n7 - Ispisi datum\n8 - Kraj\n";
            std::cin>>n;
            if (n==1)
            {
                int p;
                std::cout<<"Unesite pomak: "; std::cin>>p;
                try {d+=p;}
                catch (std::domain_error e)
                { std::cout<<e.what()<<"\n";}
            }
            else if (n==2)
            {
                int p;
                std::cout<<"Unesite pomak: "; std::cin>>p;
                try{d-=p;}
                catch(std::domain_error e)
                {std::cout<<e.what()<<"\n";}
            }
            else if (n==3) std::cout<<"Danas je "<<d.DajImeDanaUSedmici()<<std::endl;
            else if (n==4) std::cout<<std::string(d)<<std::endl;
            else if (n==5) std::cout<<"Broj proteklih dana od 1.1.1800. je "<<int(d)<<std::endl;
            else if (n==6) std::cout<<"Ime mjeseca je "<<d.DajImeMjeseca()<<std::endl;
            else if (n==7) std::cout<<d<<std::endl;
            else if (n==8) break;
        }
    }
    catch (std::domain_error e)
    {
        std::cout<<e.what()<<"\n";
    }
	return 0;
}
