/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
 
class Datum
{
    int dan,mjesec,godina;
    char mjeseci[12][10]{"Januar","Februar","Mart","April","Maj","Juni","Juli","August","Septembar","Oktobar","Novembar","Decembar"};
    char dani[7][12]{"Ponedjeljak","Utorak","Srijeda","Cetvrtak","Petak","Subota","Nedjelja"};
public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    Datum(int d, int m, int g);
    Datum(int d, Mjeseci mj, int g);
    void Postavi(int d, int m, int g);
    void Postavi(int d, Mjeseci mj, int g);
    int DajDan() const { return dan; }
    Mjeseci DajMjesec() const { return Mjeseci(mjesec); }
    int DajGodinu() const { return godina; }
    char *DajImeMjeseca() const { return (char *)(mjeseci[mjesec-1]); }
    Dani DanUSedmici() const
    {
        int ukupnodana=0;
        for(int i=1800;i<godina;i++)
        {
            int broj_dana=365;
            if((i%4==0 && i%100!=0) || i%400==0) broj_dana++;
            ukupnodana+=broj_dana;
        }
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina % 4 == 0 && godina % 100 != 0 ) || godina % 400 == 0) broj_dana[1]++;
        for(int i=1;i<mjesec;i++) ukupnodana+=broj_dana[i-1];
        for(int i=1;i<dan;i++) ukupnodana++;
        return Dani((ukupnodana+2)%7+1);
    }
    char *DajImeDanaUSedmici() const { return (char *)(dani[DanUSedmici()-1]); }
    friend Datum& operator++(Datum &d);
    friend Datum operator++(Datum &d, int);
    friend Datum& operator--(Datum &d);
    friend Datum operator--(Datum &d, int);
    friend Datum& operator+(Datum &d1, int broj);
    friend Datum& operator-(Datum &d1, int broj);
    friend Datum& operator+=(Datum &d1, int broj);
    friend Datum& operator-=(Datum &d1, int broj);
    friend int operator-(Datum d1, Datum d2);
    friend bool operator<(const Datum &d1, const Datum &d2);
    friend bool operator>(const Datum &d1, const Datum &d2);
    friend bool operator<=(const Datum &d1, const Datum &d2);
    friend bool operator>=(const Datum &d1, const Datum &d2);
    friend bool operator==(const Datum &d1, const Datum &d2);
    friend bool operator!=(const Datum &d1, const Datum &d2);
    friend std::ostream &operator<<(std::ostream &tok, const Datum &d);
    friend std::istream &operator>>(std::istream &tok, Datum &d);
    operator std::string() { return std::to_string(DajDan())+". "+std::string(DajImeMjeseca())+" "+std::to_string(DajGodinu())+". ("+std::string(DajImeDanaUSedmici())+")"; }
    explicit operator int();
};
Datum::operator int()
{
    int ukupnodana=0;
    for(int i=1800;i<godina;i++)
    {
        int broj_dana=365;
        if((i%4==0 && i%100!=0) || i%400==0) broj_dana++;
        ukupnodana+=broj_dana;
    }
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0 ) || godina % 400 == 0) broj_dana[1]++;
    for(int i=1;i<mjesec;i++) ukupnodana+=broj_dana[i-1];
    for(int i=1;i<dan;i++) ukupnodana++;
    return ukupnodana;
}
Datum::Datum(int d, int m, int g)
{
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0 ) || g % 400 == 0) broj_dana[1]++;
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1] || g < 1800) throw std::domain_error("Nelegalan datum");
    dan = d; mjesec = m; godina = g;
}
Datum::Datum(int d, Mjeseci mj, int g)
{
    int m;
    m=int(mj);
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++;
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1] || g < 1800) throw std::domain_error("Nelegalan datum");
    dan = d; mjesec = m; godina = g;
}
void Datum::Postavi(int d, int m, int g)
{
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0 ) || g % 400 == 0) broj_dana[1]++;
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1] || g < 1800) throw std::domain_error("Nelegalan datum");
    dan = d; mjesec = m; godina = g;
}
void Datum::Postavi(int d, Mjeseci mj, int g)
{
    int m;
    m=int(mj);
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++;
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1] || g < 1800) throw std::domain_error("Nelegalan datum");
    dan = d; mjesec = m; godina = g;
}
std::ostream& operator<<(std::ostream &tok, const Datum &d)
{
    tok<<d.DajDan()<<". "<<d.DajImeMjeseca()<<" "<<d.DajGodinu()<<". ("<<d.DajImeDanaUSedmici()<<")"<<std::endl;
    return tok;
}
std::istream &operator>>(std::istream &tok, Datum &d)
{
    int dan,mjesec,godina;
    char znak;
    std::cin>>dan;
    if(!std::cin) { tok.setstate(std::ios::failbit); return tok; }
    std::cin>>znak;
    if(znak!='/' || !std::cin) { tok.setstate(std::ios::failbit); return tok; }
    std::cin>>mjesec;
    if(!std::cin) { tok.setstate(std::ios::failbit); return tok; }
    std::cin>>znak;
    if(!std::cin) { tok.setstate(std::ios::failbit); return tok; }
    std::cin>>godina;
    if(!std::cin) { tok.setstate(std::ios::failbit); return tok; }
    try
    {
        d=Datum(dan,mjesec,godina);
    }
    catch(...)
    {
        tok.setstate(std::ios::failbit);
    }
    return tok;
}
bool operator!=(const Datum &d1, const Datum &d2)
{
    return !(d1.dan==d2.dan && d1.mjesec==d2.mjesec && d1.godina==d2.godina);
}
bool operator==(const Datum &d1, const Datum &d2)
{
    return d1.dan==d2.dan && d1.mjesec==d2.mjesec && d1.godina==d2.godina;
}
bool operator<(const Datum &d1, const Datum &d2)
{
    if(d1.godina!=d2.godina) return d1.godina<d2.godina;
    if(d1.mjesec!=d2.mjesec) return d1.mjesec<d2.mjesec;
    return d1.dan<d2.dan;
}
bool operator>(const Datum &d1, const Datum &d2)
{
    if(d1.godina!=d2.godina) return d1.godina>d2.godina;
    if(d1.mjesec!=d2.mjesec) return d1.mjesec>d2.mjesec;
    return d1.dan>d2.dan;
}
bool operator<=(const Datum &d1, const Datum &d2)
{
    if(d1.godina!=d2.godina) return d1.godina<d2.godina;
    if(d1.mjesec!=d2.mjesec) return d1.mjesec<d2.mjesec;
    return d1.dan<=d2.dan;
}
bool operator>=(const Datum &d1, const Datum &d2)
{
    if(d1.godina!=d2.godina) return d1.godina>d2.godina;
    if(d1.mjesec!=d2.mjesec) return d1.mjesec>d2.mjesec;
    return d1.dan>=d2.dan;
}
int operator-(Datum d1, Datum d2)
{
    if(d2<d1)
    {
        Datum pomocni(d2);
        d2=d1;
        d1=pomocni;
    }
    int broj(0);
    while(d1.dan!=d2.dan || d1.mjesec!=d2.mjesec || d1.godina!=d2.godina) {broj++;d1++;}
    return broj;
}
inline Datum& operator+(Datum &d1, int broj)
{
    return d1+=broj;
}
inline Datum& operator-(Datum &d1, int broj)
{
    return d1-=broj;
}
Datum &operator+=(Datum &d1, int broj)
{
    if(broj<0) return d1-=(-1)*broj;
    else
    {
        for(int i=0;i<broj;i++) d1++;
        return d1;
    }
}
Datum &operator-=(Datum &d1, int broj)
{
    if(broj<0) return d1+=(-1)*broj;
    else
    {
        for(int i=0;i<broj;i++) d1--;
        return d1;
    }
}
Datum &operator++(Datum &d)
{
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((d.godina % 4 == 0 && d.godina % 100 != 0 ) || d.godina % 400 == 0) broj_dana[1]++;
    if(broj_dana[d.mjesec-1]==d.dan)
    {
        if(d.mjesec==12) { d.dan=1; d.mjesec=1; d.godina++; }
        else { d.dan=1; d.mjesec++; }
    }
    else d.dan++;
    return d;
}
Datum operator++(Datum &d, int)
{
    Datum pomocni(d);
    ++d;
    return pomocni;
}
Datum &operator--(Datum &d)
{
    if(d.dan==1 && d.mjesec==1 && d.godina==1800) throw std::domain_error("Nelegalan datum");
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((d.godina % 4 == 0 && d.godina % 100 != 0 ) || d.godina % 400 == 0) broj_dana[1]++;
    if(d.dan==1)
    {
        if(d.mjesec==1) { d.dan=31; d.mjesec=12; d.godina--; }
        else { d.mjesec--; d.dan=broj_dana[d.mjesec-1]; }
    }
    else d.dan--;
    return d;
}
Datum operator--(Datum &d, int)
{
    if(d.dan==1 && d.mjesec==1 && d.godina==1800) throw std::domain_error("Nelegalan datum");
    Datum pomocni(d);
    --d;
    return pomocni;
}
 
 
int main ()
{
    Datum datum1(9,6,2018);
    Datum datum2(8,5,2019);
    std::cout<<datum1-datum2;
    //std::cout<<datum.DajDan()<<" "<<datum.DajMjesec()<<" "<<datum.DajGodinu()<<std::endl;
    return 0;
}