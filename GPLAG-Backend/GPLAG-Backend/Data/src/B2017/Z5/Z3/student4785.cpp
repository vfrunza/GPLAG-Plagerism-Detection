/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <string>
#include <stdexcept>

class Datum
{
    int dan,mjesec,godina;
    void Normaliziraj(int d, int m, int g) {
        int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(g%4==0 && g%100!=0 || g&400==0)broj_dana[1]++;
        while(d>broj_dana[m-1]) {
            d-=broj_dana[m-1];
            m++;
            if(m>12) {
                m=1;
                g++;
                if(g%4==0 && g%100!=0 || g&400==0) broj_dana[1]=29;
                else broj_dana[1]=28;
            }
        }
        while(d<1) {
            m--;
            d+=broj_dana[m-1];
            if(m<1) {
                m=12;
                g--;
                if(g%4==0 && g%100!=0 || g&400==0) broj_dana[1]=29;
                else broj_dana[1]=28;
            }
        }
        if(g<1800) throw std::domain_error("Nelegalan datum");
        dan=d;
        mjesec=m;
        godina=g;
    }
    static int DajRazliku(const Datum &d1, const Datum &d2) {
        int b_d,b_m,b_g,d,m,g;
        if(d1==d2) return 0;
        if(d1<d2) {
            b_d=d1.dan;
            b_m=d1.mjesec;
            b_g=d1.godina;
            d=d2.dan;
            m=d2.mjesec;
            g=d2.godina;
        } else {
            b_d=d2.dan;
            b_m=d2.mjesec;
            b_g=d2.godina;
            d=d1.dan;
            m=d1.mjesec;
            g=d1.godina;
        }
        int razlika(0);
        while(b_g!=g) {
            bool prvi(b_g%4==0);
            bool drugi(b_g%100!=0);
            bool treci(b_g&400==0);
            if(b_g==2000) razlika++;
            else if(prvi&&drugi ||treci) razlika++;
            razlika+=365;
            b_g++;
        }
        while(b_m!=m) {
            int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
            if(b_g==2000 || (b_g%4==0 && b_g%100!=0 || b_g&400==0)) broj_dana[1]++;
            razlika+=broj_dana[b_m-1];
            b_m++;
        }
        while(b_d!=d) {
            razlika++;
            b_d++;
        }
        return razlika;
    }

public:
    enum Mjeseci {Januar=1,Februar,Mart,April,Maj,Juni,Juli,August,Septembar,Oktobar,Novembar,Decembar};
    enum Dani {Ponedjeljak=1,Utorak,Srijeda,Cetvrtak,Petak,Subota,Nedjelja};
    Datum(int d, int m, int g) {
        Postavi(d,m,g);
    }
    Datum(int d, Mjeseci m, int g) {
        Postavi(d,m,g);
    }
    void Postavi(int d, int m, int g);
    void Postavi(int d, Mjeseci mj, int g) {
        Postavi(d,int(mj),g);
    }
    int DajDan() const {
        return dan;
    }
    int DajGodinu() const {
        return godina;
    }
    Mjeseci DajMjesec() const {
        return Mjeseci(Januar+mjesec-1);
    }
    Dani DanUSedmici() const {
        Datum d1(1,1,1800);
        int razlika=DajRazliku(d1,*this);
        razlika=(razlika+Srijeda)%7;
        if(razlika==0) return Srijeda;
        return Dani(razlika);
    }
    char *DajImeMjeseca() const ;
    char *DajImeDanaUSedmici() const ;
    friend Datum& operator++(Datum &d) ;
    friend Datum& operator--(Datum &d) ;
    friend Datum operator++(Datum &d, int) ;
    friend Datum operator--(Datum &d, int) ;
    friend std::istream &operator>>(std::istream &tok, Datum &d);
    friend std::ostream &operator<<(std::ostream &tok, const Datum &d);
    friend Datum &operator+=(Datum &d, int n) ;
    friend Datum &operator-=(Datum &d, int n) ;
    friend Datum operator +(const Datum &d, int n) ;
    friend Datum operator +(int n, const Datum &d) {
        return d+n;
    }
    friend Datum operator-(const Datum &d, int n) ;
    friend bool operator <(const Datum &d1, const Datum &d2) ;
    friend bool operator <=(const Datum &d1, const Datum &d2) {
        if(d1==d2) return true;
        return (d1<d2);
    }
    friend bool operator >(const Datum &d1, const Datum &d2) {
        return (d1!=d2 && !(d1<d2));
    }
    friend bool operator >=(const Datum &d1, const Datum &d2) {
        if(d1==d2) return true;
        return (!(d1<d2));
    }
    friend bool operator ==(const Datum &d1, const Datum &d2) {
        return (d1.godina==d2.godina && d1.mjesec==d2.mjesec && d1.dan==d2.dan);
    }
    friend bool operator !=(const Datum &d1, const Datum &d2) {
        return !(d1==d2);
    }
    friend int operator-(const Datum &d1, const Datum &d2) {
        return DajRazliku(d1,d2);
    }
    operator std::string() const {
        std::string datum;
        datum=std::to_string(dan)+"."+std::to_string(mjesec)+" "+std::to_string(godina)+".("+DajImeDanaUSedmici()+")";
        return datum;
    }
    explicit operator int () const {
        int r;
        Datum d(1,1,1800);
        r=DajRazliku(d,*this);
        return r;
    }
};


void Datum::Postavi(int d, int m, int g)
{
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && g%100!=0 || g&400==0)broj_dana[1]++;
    if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1] || g<1800) throw std::domain_error("Nelegalan datum");
    dan=d;
    mjesec=m;
    godina=g;
}
char *Datum::DajImeMjeseca() const
{
    char *mjeseci[12] {"Januar","Februar","Mart","April","Maj","Juni","Juli","August","Septembar","Oktobar","Novembar","Decembar"};
    return mjeseci[mjesec-1];
}
char *Datum::DajImeDanaUSedmici() const
{
    char *dani[7] {"Ponedjeljak","Utorak","Srijeda","Cetvrtak","Petak","Subota","Nedjelja"};
    return dani[DanUSedmici()-1];
}
Datum &operator++(Datum &d)
{
    d.dan++;
    d.Normaliziraj(d.dan,d.mjesec,d.godina);
    return d;
}
Datum& operator--(Datum &d)
{
    d.dan--;
    d.Normaliziraj(d.dan,d.mjesec,d.godina);
    return d;
}
Datum operator++(Datum &d, int)
{
    Datum pomocni(d);
    ++d;
    return pomocni;
}
Datum operator--(Datum &d, int)
{
    Datum pomocni(d);
    --d;
    return pomocni;
}

std::istream &operator>>(std::istream &tok, Datum &d)
{
    char znak;
    double a,b,c;
    int ok(true);
    tok>>std::ws;
    tok>>a;
    if(!tok || int(a)!=a) {
        ok=false;
        tok.setstate(std::ios::failbit);
    }
    tok>>znak;
    if(znak!='/') {
        ok=false;
        tok.setstate(std::ios::failbit);
    }
    tok>>b;
    if(!tok || int(b)!=b) {
        ok=false;
        tok.setstate(std::ios::failbit);
    }
    tok>>znak;
    if(znak!='/') {
        ok=false;
        tok.setstate(std::ios::failbit);
    }
    tok>>c;
    if(!tok || int(c)!=c) {
        ok=false;
        tok.setstate(std::ios::failbit);
    }
    if(ok) d.Postavi(a,b,c);
    return tok;
}
std::ostream &operator<<(std::ostream &tok, const Datum &d)
{
    tok<<d.DajDan()<<"."<<d.DajImeMjeseca()<<" "<<d.DajGodinu()<<".("<<d.DajImeDanaUSedmici()<<")"<<std::endl;
    return tok;
}
Datum &operator+=(Datum &d, int n)
{
    d.Normaliziraj(d.dan+n,d.mjesec,d.godina);
    return d;
}
Datum &operator-=(Datum &d, int n)
{
    d.Normaliziraj(d.dan+n,d.mjesec,d.godina);
    return d;
}
Datum operator +(const Datum &d, int n)
{
    Datum d2(d);
    d2+=n;
    return d2;
}
Datum operator-(const Datum &d, int n)
{
    Datum d2(d);
    d2-=n;
    return d2;
}
bool operator <(const Datum &d1, const Datum &d2)
{
    if(d1==d2) return false;
    if(d1.godina<d2.godina) return true;
    else if(d1.godina>d2.godina) return false;
    else if(d1.mjesec<d2.mjesec) return true;
    else if(d1.mjesec>d2.mjesec) return false;
    else if(d1.dan<d2.dan) return true;
    else return false;
}

int main ()
{
    return 0;
}
