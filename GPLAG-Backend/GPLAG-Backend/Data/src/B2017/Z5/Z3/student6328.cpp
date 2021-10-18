/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <cmath>
#include <stdexcept>
class Datum
{
    int dan,mjesec,godina;
    int DajBrojDanaUMjesecu()const; //pomoćne funkcije
    int DajBrojDanaUGodini()const;
    int DajDanUGodini()const;
public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    Datum(int d,int m,int g) {
        this->Postavi(d,m,g);
    }
    Datum(int d, Mjeseci m, int g) {
        this->Postavi(d,m,g);
    }
    void Postavi(int d,int m, int g);
    void Postavi(int d, Mjeseci mjesec, int g);
    int DajDan()const {
        return dan;
    }
    int DajGodinu() const {
        return godina;
    }
    Mjeseci DajMjesec()const;
    const char* DajImeMjeseca()const;
    const char* DajImeDanaUSedmici()const;
    Dani DanUSedmici()const;
    Datum &operator ++();
    Datum &operator ++(int);
    Datum &operator --();
    Datum &operator --(int);
    friend Datum operator+(Datum d,int n);
    friend Datum operator-(Datum d,int n);
    Datum &operator +=(int n) ;
    Datum &operator -=(int n) ;
    friend int operator -(const Datum &d1, const Datum &d2);
    friend bool operator ==(const Datum &d1, const Datum &d2);
    friend bool operator >(const Datum &d1, const Datum &d2);
    friend bool operator <(const Datum &d1, const Datum &d2);
    friend bool operator !=(const Datum &d1, const Datum &d2);
    friend bool operator >=(const Datum &d1, const Datum &d2);
    friend bool operator <=(const Datum &d1, const Datum &d2);
    friend std::ostream &operator <<(std::ostream &tok, const Datum &d) ;
    friend std::istream &operator >>(std::istream &tok, Datum &d);
};
int Datum::DajBrojDanaUGodini()const
{
    int broj(365);
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj++;
    return broj;
}
int Datum::DajBrojDanaUMjesecu()const
{
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || (godina%400==0)) broj_dana[1]++;
    return broj_dana[mjesec-1];
}
int Datum::DajDanUGodini()const
{
    Datum temp(dan,mjesec,godina);
    int suma(0);
    for(int i(0); i!=DajMjesec(); i++) {
        temp.Postavi(1,mjesec-i,godina);
        suma+=temp.DajBrojDanaUMjesecu();
    }
    return suma+dan;
}
void Datum::Postavi(int d,int m,int g)
{
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if((g%4==0 && g%100!=0) || (g%400==0)) broj_dana[1]++;
    if(g<1800 || d<=0 || m<=0 || m>=13 || d>broj_dana[m-1]) throw std::domain_error("Nelegalan datum");
    dan=d;
    mjesec=m;
    godina=g;
}
void Datum::Postavi(int d, Mjeseci mjesec, int g)
{
    try {
        Postavi(d,int(mjesec),g);
    } catch(...) {
        throw;
    }
}
const char* Datum::DajImeMjeseca()const
{
    const char* mjeseci_imena[] {"Januar","Februar","Mart","April","Maj","Juni","Juli","August","Septembar","Oktobar","Novembar","Decembar"};
    return mjeseci_imena[this->DajMjesec()-1];
}

const char* Datum::DajImeDanaUSedmici() const
{
    const char* sedmica_imena[] {"Nedjelja","Ponedjeljak","Utorak","Srijeda","Cetvrtak","Petak","Subota"};
    static int t[]= {0,3,2,5,0,3,5,1,4,6,2,4};
    int temp=godina;
    temp-=mjesec<3;
    return sedmica_imena[(temp+temp/4-temp/100+temp/400+t[mjesec-1]+dan)%7];
}

Datum::Dani Datum::DanUSedmici()const
{
    static int t[]= {0,3,2,5,0,3,5,1,4,6,2,4};
    int temp(godina);
    temp-=mjesec<3;
    int temp2=((temp+temp/4-temp/100+temp/400+t[mjesec-1]+dan)%7);
    if(temp2==0) temp2=7;
    return Dani(temp2);
}

Datum::Mjeseci Datum::DajMjesec() const
{
    Mjeseci m;
    m=Mjeseci(this->mjesec);
    return m;
}
Datum &Datum::operator ++()
{
    dan++;
    if(dan>DajBrojDanaUMjesecu()) {
        mjesec++;
        dan=1;
    }
    if(mjesec>12) {
        godina++;
        mjesec=1;
    }
    Postavi(dan,mjesec,godina);
    return *this;
}

Datum &Datum::operator ++(int)
{
    ++(*this);
    return *this;
}

Datum &Datum::operator --()
{
    dan--;
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || (godina%400==0)) broj_dana[1]++;
    if(dan<1) {
        mjesec--;
        if(mjesec!=0) {
            Postavi(1,mjesec,godina);
            dan=broj_dana[mjesec-1];
        }
    }
    if(mjesec==0) {
        godina--;
        mjesec=12;
        Postavi(1,mjesec,godina);
        dan=broj_dana[mjesec-1];
    }
    Postavi(dan,mjesec,godina);
    return *this;
}

Datum &Datum::operator --(int)
{
    --(*this);
    return *this;
}

Datum operator +(Datum d, int n)
{
    if(n<0) d-n;
    else {
        for(int i=0; i<n; i++) d++;
    }
    return d;
}

Datum operator -(Datum d,int n)
{
    if(n<0) d+n;
    if(n==0) return d;
    for(int i=0; i<n; i++) d--;
    return d;
}

Datum &Datum::operator +=(int n)
{
    for(int i=0; i<n; i++)(*this)++;
    return *this;
}

Datum &Datum::operator -=(int n)
{
    for(int i=0; i<n; i++)(*this)--;
    return *this;
}

int operator -(const Datum &d1, const Datum &d2)
{
    int suma(0);
    Datum temp1(d1);
    Datum temp2(d2);
    if(d1.godina>d2.godina) {
        temp1=d2;
        temp2=d1;
    }
    suma+=temp1.DajBrojDanaUGodini()-temp1.DajDanUGodini();
    temp1.Postavi(1,1,temp1.godina+1);
    while(temp1.godina<temp2.godina) {
        suma+=temp1.DajBrojDanaUGodini();
        temp1.Postavi(1,1,temp1.godina+1);
    }
    suma+=temp2.DajDanUGodini();
    if(d1.godina<d2.godina) suma*=-1;
    return suma;
}

bool operator ==(const Datum &d1, const Datum &d2)
{
    return (d1.godina==d2.godina && d1.mjesec==d2.mjesec && d1.dan==d2.dan);
}

bool operator !=(const Datum &d1, const Datum &d2)
{
    return !(d1==d2);
}
bool operator >(const Datum &d1, const Datum &d2)
{
    if(d1.godina==d2.godina) return d1.DajDanUGodini()>d2.DajDanUGodini();
    else return d1.godina>d2.godina;
}

bool operator <(const Datum &d1, const Datum &d2)
{
    if(d1.godina==d2.godina) return d1.DajDanUGodini()>d2.DajDanUGodini();
    else return d1.godina<d2.godina;
}
bool operator >=(const Datum &d1, const Datum &d2)
{
    return d1.godina==d2.godina || d1.godina>d2.godina;
}

bool operator <=(const Datum &d1, const Datum &d2)
{
    return d1.godina==d2.godina || d1.godina<d2.godina;
}

std::ostream &operator <<(std::ostream &tok, const Datum &d)
{
    tok<<d.DajDan()<<"."<<d.DajImeMjeseca()<<" "<<d.DajGodinu()<<".("<<d.DajImeDanaUSedmici()<<") "<<std::endl;
    return tok;
}

std::istream &operator >>(std::istream &tok, Datum &d)
{
    char znak1,znak2;
    tok>>d.dan>>znak1>>d.mjesec>>znak2>>d.godina;
    if(znak1!='/' || znak2!='/') tok.setstate(std::ios::failbit);
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    if((d.godina%4==0 && d.godina%100!=0) || (d.godina%400==0)) broj_dana[1]++;
    if(d.godina<1800 || d.mjesec<1 || d.mjesec>12 || d.dan<1 || d.dan>broj_dana[d.mjesec-1]) tok.setstate(std::ios::failbit);
    return tok;
}
int main ()
{
    /*try {
        Datum d1(16, 2, 2007);
        Datum d2(26, 8, 1998);
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
        std::cout << "Unesite datum: ";
        Datum d3(1,1,1800);
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
    }*/
    return 0;

}