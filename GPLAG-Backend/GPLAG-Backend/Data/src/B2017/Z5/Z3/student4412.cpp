/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

//prestupna- 366, obicna 365

//napomena za srijedu

class Datum
{
    int dan, mjesec, godina;
    static std::string pretvoriUstring(int broj) {
        std::string rezultat;
        int pomocna(0);
        while(broj>0) {
            pomocna=pomocna*10+broj%10;
            broj/=10;
        }
        while(pomocna>0) {
            rezultat+=pomocna%10+'0';
            pomocna/=10;
        }
        return rezultat;
    }
public:
    enum Mjeseci {Januar=1, Februar, Mart, April, Maj, Juni, Juli, August,
                  Septembar, Oktobar, Novembar, Decembar
                 };
    enum Dani {Ponedjeljak=1, Utorak, Srijeda, Cetvrtak, Petak, Subota,
               Nedjelja
              };

    Datum (int dan, int mjesec, int godina) ;                                   //konstruktor
    Datum (int dan, Mjeseci mjesec, int godina) ;                               //konstruktor

    void Postavi (int dan, int mjesec, int godina) ;
    void Postavi (int dan, Mjeseci mjesec, int godina) ;

    int DajDan () const {                                                       //ocitavanje informacija
        return dan;
    }
    Mjeseci DajMjesec () const {
        return Mjeseci(mjesec);
    }
    int DajGodinu () const {
        return godina;
    }

    const char *DajImeMjeseca () const ;
    Dani DanUSedmici () const;
    const char *DajImeDanaUSedmici () const;
    
    friend Datum &operator ++ (Datum &d);                                       //prefiksna
    friend Datum operator ++(Datum &d, int);                                    //postfiksna
    friend Datum &operator -- (Datum &d);                                       //prefiksna
    friend Datum operator --(Datum &d, int);                                    //postfiksna

    friend Datum operator + (Datum &d, int broj);
    friend Datum operator - (Datum &d, int broj);
    friend Datum &operator += (Datum &d, int broj);
    friend Datum &operator -= (Datum &d, int broj);

    friend int operator - (const Datum &d1, const Datum &d2);

    friend bool operator == (const Datum &d1, const Datum &d2);
    friend bool operator != (const Datum &d1, const Datum &d2);

    friend bool operator < (const Datum &d1, const Datum &d2);
    friend bool operator > (const Datum &d1, const Datum &d2);

    friend bool operator <= (const Datum &d1, const Datum &d2);
    friend bool operator >= (const Datum &d1, const Datum &d2);

    friend std::ostream &operator << (std::ostream &tok, const Datum &d);
    friend std::istream &operator >> (std::istream &tok, Datum &d);

    explicit operator int () const ;
    operator std::string () const;
};

Datum::operator std::string()const
{
    std::string rezultat="";
    rezultat+=pretvoriUstring(DajDan())+".";
    std::string imena_mjeseci[12] {"Januar", "Februar", "Mart", "April",
                                   "Maj", "Juni", "Juli", "August", "Septembar", "Novembar", "Decembar"
                                  };
    std::string dani_u_sedmici[12] {"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak",
                                    "Petak", "Subota", "Nedjelja"
                                   };
    rezultat=rezultat+imena_mjeseci[DajMjesec()-1]+" "+pretvoriUstring(DajGodinu())
             +". ("+dani_u_sedmici[(int)(*this)%7-1]+")";
    return rezultat;
}

Datum::operator int () const
{
    int n_prestupnih(0), n_obicnih(0), rezultat(0);
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i=1800; i<(DajGodinu()); i++)
        if((i%4==0 && i%100!=0) || i%400==0) n_prestupnih++;
        else n_obicnih++;
    for(int i=1; i<DajMjesec(); i++) {
        int godina=this->DajGodinu();
        if(i==2 && ((godina%4==0 && godina%100!=0) || godina%400==0)) rezultat+=29;
        else rezultat+=broj_dana[i-1];
    }
    return (rezultat+n_prestupnih*366+n_obicnih*365+DajDan()-1);
}

const char *Datum::DajImeDanaUSedmici () const
{
    const char*dani_u_sedmici[7] {"Ponedjeljak", "Utorak", "Srijeda",
                                  "Cetvrtak", "Petak", "Subota", "Nedjelja"
                                 };
    return dani_u_sedmici[DanUSedmici()-1];
}

const char *Datum::DajImeMjeseca () const
{
    const char *imena_mjeseci[12] {"Januar", "Februar", "Mart", "April",
                                   "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar",
                                   "Novembar", "Decembar"
                                  };
    return imena_mjeseci[mjesec-1];
}

bool operator <= (const Datum &d1, const Datum &d2)
{
    if(d1==d2) return true;
    else return d1<d2;
}

bool operator >= (const Datum &d1, const Datum &d2)
{
    if(d1==d2) return true;
    else return d1>d2;
}

bool operator != (const Datum &d1, const Datum &d2)
{
    return !(d1==d2);
}

bool operator == (const Datum &d1, const Datum &d2)
{
    return d1.dan==d2.dan && d1.mjesec==d2.mjesec && d1.godina==d2.godina;
}

Datum::Dani Datum::DanUSedmici () const
{
    int n_prestupnih(0), n_obicnih(0), rezultat(0);
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i=1800; i<(DajGodinu()); i++)
        if((i%4==0 && i%100!=0) || i%400==0) n_prestupnih++;
        else n_obicnih++;
    for(int i=1; i<DajMjesec(); i++) {
        int godina=this->DajGodinu();
        if(i==2 && ((godina%4==0 && godina%100!=0) || godina%400==0)) rezultat+=29;
        else rezultat+=broj_dana[i-1];
    }
    rezultat=(rezultat+n_prestupnih*366+n_obicnih*365+DajDan()+2)%7;
    if(rezultat==0)return Dani(7);
    return Dani(rezultat) ;
}

bool operator > (const Datum &d1, const Datum &d2)
{
    if(d1.godina>d2.godina) return true;
    else if(d1.godina<d2.godina) return false;
    else if(d1.godina==d2.godina && d1.mjesec>d2.mjesec) return true;
    else if(d1.godina==d2.godina && d1.mjesec<d2.mjesec) return false;
    else if(d1.godina==d2.godina && d1.mjesec==d2.mjesec && d1.dan>d2.dan) return true;
    else return false;
}

bool operator < (const Datum &d1, const Datum &d2)
{
    if(d1.godina<d2.godina) return true;
    else if(d1.godina>d2.godina) return false;
    else if(d1.godina==d2.godina && d1.mjesec<d2.mjesec) return true;
    else if(d1.godina==d2.godina && d1.mjesec>d2.mjesec) return false;
    else if(d1.godina==d2.godina && d1.mjesec==d2.mjesec && d1.dan<d2.dan) return true;
    else return false;
}

int operator - (const Datum &d1, const Datum &d2)
{
    return (int)d1-(int)d2;
}

Datum &operator += (Datum &d, int broj)
{
    if(broj>0)
        for(int i=0; i<broj; i++)
            ++d;
    else {
        broj*=(-1);
        for(int i=0; i<broj; i++) {
            --d;
            if(d.godina<1800) throw std::domain_error("Nelegalan datum");
        }
    }
    return d;
}

Datum operator -(Datum &d, int broj)
{
    Datum pomocna(d);
    if(broj>0)
        for(int i=0; i<broj; i++) {
            --pomocna;
            if(pomocna.godina<1800) throw std::domain_error("Nelegalan datum");
        }
    else {
        broj*=(-1);
        for(int i=0; i<broj; i++)
            ++d;
    }
    return pomocna;
}


Datum &operator -=(Datum &d, int broj)
{
    if(broj>0)
        for(int i=0; i<broj; i++) {
            --d;
            if(d.godina<1800) throw std::domain_error("Nelegalan datum");
        }
    else {
        broj*=(-1);
        for(int i=0; i<broj; i++)
            ++d;
    }
    return d;
}

Datum operator + (Datum &d, int broj)
{
    Datum pomocna(d);
    if(broj>0)
        for(int i=0; i<broj; i++)
            ++pomocna;
    else {
        broj*=(-1);
        for(int i=0; i<broj; i++) {
            --pomocna;
            if(pomocna.godina<1800) throw std::domain_error("Nelegalan datum");
        }
    }
    return pomocna;
}

Datum &operator -- (Datum &d)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    d.dan-=1;
    if(d.dan<1 && d.mjesec>1) {
        d.dan=broj_dana[d.mjesec-2];
        d.mjesec--;
    } else if(d.dan<1 && d.mjesec==1) {
        d.dan=broj_dana[11];
        d.mjesec=12;
        d.godina-=1;
    }
    if(d.godina<1800) throw std::domain_error("Nelegalan datum");
    return d;
}

Datum operator --(Datum &d, int)
{
    Datum pomocna(d);
    --d;
    return pomocna;
}

Datum &operator ++ (Datum &d)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    d.dan+=1;
    if(d.dan>broj_dana[d.mjesec-1]) {
        d.dan-=broj_dana[d.mjesec-1];
        d.mjesec++;
    }
    if(d.mjesec>12) {
        d.mjesec-=12;
        d.godina++;
    }
    return d;
}

Datum operator ++ (Datum &d, int)
{
    Datum pomocna(d);
    ++d;
    return pomocna;
}

std::istream &operator >> (std::istream &tok, Datum &d)
{
    int dan, mjesec, godina;
    char znak;
    std::cin>>dan>>znak;
    if(!tok || znak!='/') tok.setstate(std::ios::failbit);
    std::cin>>mjesec>>znak;
    if(!tok || znak!='/') tok.setstate(std::ios::failbit);
    std::cin>>godina;
    if(!tok || std::cin.peek()!='\n') tok.setstate(std::ios::failbit);
    d.Postavi(dan, mjesec, godina);
    return tok;
}

std::ostream &operator << (std::ostream &tok, const Datum &d)
{
    tok<<d.DajDan()<<"."<<d.DajImeMjeseca()
       <<" "<<d.DajGodinu()<<".("
       <<d.DajImeDanaUSedmici()<<")"<<std::endl;
    return tok;
}


Datum::Datum (int dan, int mjesec, int godina)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
    if(godina<1800 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana[mjesec-1])
        throw std::domain_error("Nelegalan datum");
    this->dan=dan;
    this->mjesec=mjesec;
    this->godina=godina;
}

void Datum::Postavi (int dan, int mjesec, int godina)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
    if(godina<1800 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana[mjesec-1])
        throw std::domain_error("Nelegalan datum");
    this->dan=dan;
    this->mjesec=mjesec;
    this->godina=godina;
}

Datum::Datum (int dan, Mjeseci mjesec, int godina)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
    if(godina<1800 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana[mjesec-1])
        throw std::domain_error("Nelegalan datum");
    this->dan=dan;
    this->mjesec=mjesec;
    this->godina=godina;
}

void Datum::Postavi (int dan, Mjeseci mjesec, int godina)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4)==0 && (godina%100)!=0 || (godina%400)==0) broj_dana[1]++;
    if(godina<1800 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana[mjesec-1])
        throw std::domain_error("Nelegalan datum");
    this->dan=dan;
    this->mjesec=mjesec;
    this->godina=godina;
}

int main ()
{
    Datum d1(1, 1, 1800), d2(1,1,1800);                                         //postavljeno na referentni datum
    std::cout<<"Unesite prvi datum u formatu dan/mjesec/godina: ";
    std::cin>>d1; 
    std::cout<<"Unesen je datum: ";
    std::cout<<d1;
    std::cout<<"Unesite drugi datum u formatu dan/mjesec/godina: ";
    std::cin>>d2;
    std::cout<<"Unesen je datum: ";
    std::cout<<d2.DajDan()<<"."<<d2.DajImeMjeseca()<<" "<<d2.DajGodinu()<<".("
        <<d2.DajImeDanaUSedmici()<<")"<<std::endl;
    d1++;
    /*std::cout<<"Prvi datum pomjeren za jedan dan unaprijed: ";
    std::cout<<d1;
    --d2;
    std::cout<<"Drugi datum pomjeren za jedan dan unazad: ";
    std::cout<<d2;
    std::cout<<"Za koliko dana zelite pomjeriti prvi datum? ";
    int n;
    std::cin>>n;
    d1=d1+n;
    std::cout<<"Novi datum: ";
    std::cout<<d1;
    if(d1<d2) std::cout<<"Prvi datum je hronoloski ispred drugog datuma.";
    else std::cout<<"Drugi datum je hronoloski ispred prvog datuma"*/
    std::cout<<d2-d1;
    return 0;
}
