/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <string>

using std::cout;
using std::cin;
using std::string;

class Datum
{
    int dan, mjesec, godina;
    public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    
    Datum (int dan, Mjeseci mjesec, int godina) { Postavi(dan, mjesec, godina); }
    Datum (int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, Mjeseci mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    
    int DajDan() const { return dan; }
    Mjeseci DajMjesec() const { return Mjeseci(mjesec); }
    int DajGodinu() const { return godina; }
    
    char* DajImeMjeseca()const { }
    Dani DanUSedmici() const;
    char* DajImeDanaUSedmici() const ;
    
    Datum operator ++( int);
    Datum &operator++();
    Datum operator--(int);
    Datum &operator--();
    
    friend Datum operator + (Datum &d, int br);
    friend Datum operator - (Datum &d, int br);
    friend Datum operator - (const Datum &d1,const Datum &d2);
    Datum &operator += (int br);
    Datum &operator -= (int br);
    
    friend bool operator == (const Datum &d1,const Datum &d2);
    friend bool operator != (const Datum &d1,const Datum &d2);
    friend bool operator < (const Datum &d1,const Datum &d2);
    friend bool operator > (const Datum &d1,const Datum &d2);
    friend bool operator <= (const Datum &d1,const Datum &d2);
    friend bool operator >= (const Datum &d1,const Datum &d2);
    
    friend std::ostream &operator << (std::ostream &tok, const Datum &d);
    friend std::istream &operator >> (std::istream &tok, Datum &d);
};

void Datum::Postavi(int dan, Mjeseci mjesec, int godina)
{
    if (godina < 1800)
        throw std::domain_error("Neispravan datum");
    Datum::dan=dan;
    Datum::mjesec=mjesec;
    Datum::godina=godina;
}

void Datum::Postavi(int dan, int mjesec, int godina)
{
    if (godina < 1800)
        throw std::domain_error("Neispravan datum");
    Datum::dan=dan;
    Datum::mjesec=mjesec;
    Datum::godina=godina;
}

bool operator ==(const Datum &d1, const Datum &d2)
{
    return (d1.DajDan() == d2.DajDan() && d1.DajMjesec() == d2.DajMjesec() && d1.DajGodinu() == d2.DajGodinu());
}

bool operator !=(const Datum &d1, const Datum &d2)
{
    return !(d1==d2);
}

bool operator < (const Datum &d1,const Datum &d2)
{
    if (d1.DajGodinu() < d2.DajGodinu())
        return true;
    if (d1.DajGodinu() > d2.DajGodinu())
        return false; 
    if (d1.DajGodinu() == d2.DajGodinu())
    {
        if (d1.DajMjesec() < d2.DajMjesec())
            return true;
        if (d1.DajMjesec() > d2.DajMjesec())
            return false; 
         if (d1.DajMjesec() == d2.DajMjesec())
         {
             if (d1.DajDan() < d2.DajDan())
                    return true;
            if (d1.DajDan() > d2.DajDan())
                    return false;    
         }
    }
    return false;   
}

bool operator > (const Datum &d1,const Datum &d2)
{
    if (d1.DajGodinu() > d2.DajGodinu())
        return true;
    if (d1.DajGodinu() < d2.DajGodinu())
        return false; 
    if (d1.DajGodinu() == d2.DajGodinu())
    {
        if (d1.DajMjesec() > d2.DajMjesec())
            return true;
        if (d1.DajMjesec() < d2.DajMjesec())
            return false; 
         if (d1.DajMjesec() == d2.DajMjesec())
         {
             if (d1.DajDan() > d2.DajDan())
                    return true;
            if (d1.DajDan() < d2.DajDan())
                    return false;    
         }
    }
    return false;   
}
bool operator <= (const Datum &d1,const Datum &d2)
{
    if (d1.DajGodinu() < d2.DajGodinu())
        return true;
    if (d1.DajGodinu() > d2.DajGodinu())
        return false; 
    if (d1.DajGodinu() == d2.DajGodinu())
    {
        if (d1.DajMjesec() < d2.DajMjesec())
            return true;
        if (d1.DajMjesec() > d2.DajMjesec())
            return false; 
         if (d1.DajMjesec() == d2.DajMjesec())
         {
             if (d1.DajDan() < d2.DajDan())
                    return true;
            if (d1.DajDan() > d2.DajDan())
                    return false;    
         }
    }
    return true;   
}

bool operator >= (const Datum &d1,const Datum &d2)
{
    if (d1.DajGodinu() > d2.DajGodinu())
        return true;
    if (d1.DajGodinu() < d2.DajGodinu())
        return false; 
    if (d1.DajGodinu() == d2.DajGodinu())
    {
        if (d1.DajMjesec() > d2.DajMjesec())
            return true;
        if (d1.DajMjesec() < d2.DajMjesec())
            return false; 
         if (d1.DajMjesec() == d2.DajMjesec())
         {
             if (d1.DajDan() > d2.DajDan())
                    return true;
            if (d1.DajDan() < d2.DajDan())
                    return false;    
         }
    }
    return true; 
}
/*
std::ostream &operator << (std::ostream &tok, const Datum &d)
{
   tok << d.DajDan()<<"."<<d.DajImeMjeseca()<<" "<<d.DajGodinu()<<".("<<d.DajImeDanaUSedmici()<<")";
   return tok;
}*/

std::istream &operator >> (std::istream &tok, Datum &d)
{
   tok>>d.dan;
   if (!tok)
        tok.setstate(std::ios::failbit);
    char znak;
    tok>>znak;
    if (znak!='/')
        tok.setstate(std::ios::failbit);
    tok>>d.mjesec;
    if (!tok)
        tok.setstate(std::ios::failbit);
    tok>>znak;
    if (znak!='/')
        tok.setstate(std::ios::failbit);
    tok>>d.godina;   
    return tok;
}

Datum Datum::operator ++ (int)
{
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     if (godina % 4 == 0 && godina % 100 == 0 || godina % 400 == 0)
        broj_dana[1]++;
    Datum pomocni(*this);
    dan++;
     if (dan > broj_dana[mjesec - 1])
    {
        dan=1;
        mjesec++;
        if (mjesec > 12)
        {
            mjesec=1;
            godina++;
        }
    }
    return pomocni;
}

Datum &Datum::operator ++ ()
{
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     if (godina % 4 == 0 && godina % 100 == 0 || godina % 400 == 0)
        broj_dana[1]++;
    dan++;
     if (dan > broj_dana[mjesec - 1])
    {
        dan=1;
        mjesec++;
        if (mjesec > 12)
        {
            mjesec=1;
            godina++;
        }
    }
    return *this;
}

Datum Datum::operator -- ( int )
{
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     if (godina % 4 == 0 && godina % 100 == 0 || godina % 400 == 0)
        broj_dana[1]++;
    Datum pomocni(*this);
    dan--;
    if (dan < 1)
    {
        if (mjesec==1)
        {
            dan=broj_dana[11];
            mjesec=12;
            godina--;
            if (godina < 1800)
                throw std::domain_error("Neispravan datum");
        }
        else
        {
            dan=broj_dana[mjesec-2];
            mjesec--;
        }
    }
    return pomocni;
}

Datum &Datum::operator -- ()
{
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     if (godina % 4 == 0 && godina % 100 == 0 || godina % 400 == 0)
        broj_dana[1]++;
    dan--;
    if (dan < 1)
    {
        if (mjesec==1)
        {
            dan=broj_dana[11];
            mjesec=12;
            godina--;
            if (godina < 1800)
                throw std::domain_error("Neispravan datum");
        }
        else
        {
            dan=broj_dana[mjesec-2];
            mjesec--;
        }
    }
    return *this;
}

Datum &Datum::operator += (int br)
{
    int dan, mjesec, godina, st;
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    dan=this->DajDan();
    mjesec=this->DajMjesec();
    godina=this->DajGodinu();
    
    st=br;
    if (br<0)
        br=br*(-1);
     
    if (st > 0)
    {
        dan+=br;
        while(dan>broj_dana[mjesec-1])
        {
            mjesec++;
        }
    }
    
    else if(st < 0)
    {
        
    }
}

int main ()
{
    cout<<"aaaa";
	return 0;
}
