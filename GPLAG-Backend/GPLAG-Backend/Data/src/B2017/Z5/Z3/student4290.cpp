/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
class Datum
{
    enum Mjeseci {Januar=1,Februar,Mart,April,Maj,Juni,Juli,August,Septembar,Oktobar,Novembar,Decembar};
    enum Dani {Ponedjeljak=1,Utorak,Srijeda,Cetvrtak,Petak,Subota,Nedjelja};
    int dan,mjesec,godina;
public:
    Datum(int d,int m,int g) {
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(g%4==0 && g%100!=0 || g%400==0) broj_dana[1]++;
        if(g<1800||m<1||m>12||d<1||d>broj_dana[m-1])
            throw std::domain_error("Nelegalan datum");
        dan=d,mjesec=m,godina=g;
    }
    bool Da_Li_Je_Prestupna(int g) const {
        if(g%4==0 && g%100!=0 || g%400==0) return true;
        return false;
    }
     int Razmak(Datum &d) const {
         int broj_dana(0);
        for(int i(1800); i<d.godina; i++) {
            if(Da_Li_Je_Prestupna(i)) broj_dana+=366;
            else broj_dana+=365;
        }
        int dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(Da_Li_Je_Prestupna(d.godina)) dana[1]++;
        for(int i(0); i<d.mjesec-1; i++) broj_dana+=dana[i];
        broj_dana+=d.dan;
        return --broj_dana;
    }
    Datum(int d,Mjeseci m,int g) {
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if((g%4==0 && g%100!=0) || g%400==0) broj_dana[1]++;
        if(g<1800||m<1||m>12||d<1||d>broj_dana[m-1])
            throw std::domain_error("Nelegalan datum");
        dan=d,mjesec=m,godina=g;
    }
    void Postavi(int d,int m,int g) {
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if((g%4==0 && g%100!=0) || g%400==0) broj_dana[1]++;
        if(g<1800||m<1||m>12||d<1||d>broj_dana[m-1])
            throw std::domain_error("Nelegalan datum");
        dan=d,mjesec=m,godina=g;
    }
    void Postavi(int d,Mjeseci m,int g) {
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if((g%4==0 && g%100!=0) || g%400==0) broj_dana[1]++;
        if(g<1800||m<1||m>12||d<1||d>broj_dana[m-1])
            throw std::domain_error("Nelegalan datum");
        dan=d,mjesec=m,godina=g;
    }
    int DajDan() const {
        return dan;
    }
    int DajGodinu() const {
        return godina;
    }
    Mjeseci DajMjesec() const {
        return Mjeseci(mjesec);
    }
    const char* DajImeMjeseca() const{
        const char *imena_mjeseci[12] {"Januar","Februar","Mart","April","Maj","Juni","Juli","August","Septembar","Oktobar","Novembar","Decembar"};
        return imena_mjeseci[mjesec-1];
    }
    Dani DanUSedmici() const {
        Datum d(dan,mjesec,godina);
        long long int broj_dana(Razmak(d));
        int dan(broj_dana%7);
        return Dani(dan);
    }
    const char* DajImeDanaUSedmici() const {
        const char *imena_dana[7] {"Nedjelja","Ponedjeljak","Utorak","Srijeda","Cetvrtak","Petak","Subota"};
        Datum d(dan,mjesec,godina);
        long long int dani(Razmak(d));
        int dan(dani%7);
        return imena_dana[dan];
    }
    friend std::ostream &operator << (std::ostream &tok,const Datum &d) {
        tok <<d.dan<<"."<<d.DajImeMjeseca()<<" "<<d.godina <<".("<<d.DajImeDanaUSedmici()<<")"<<std::endl;
        return tok;
    }
    Datum operator ++() {
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(Da_Li_Je_Prestupna(godina)) broj_dana[1]++;
        dan++;
        if(dan>broj_dana[mjesec-1]) {
            dan=1;
            mjesec++;
            if(mjesec>12) {
                mjesec=1;
                godina++;
            }
        }
        return *this;
    }
    Datum operator ++(int) {
        Datum temp(*this);
        ++(*this);
        return temp;
    }
    Datum operator --() {
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(Da_Li_Je_Prestupna(godina)) broj_dana[1]++;
        dan--;
        if(dan<1) {
            if(mjesec>1) {
                dan=broj_dana[mjesec-2];
                mjesec--;
            } else {
                dan=31;
                mjesec=12;
                godina--;
            }
        }
        return *this;
    }
    Datum operator --(int) {
        Datum temp(*this);
        --(*this);
        return temp;
    }
    Datum operator +(int x) {
        Datum dat(*this);
        if(x<0&&Razmak(*this)<x) throw std::domain_error("Nelegalan datum");

    }
    Datum operator -(int x) {
        Datum dat(*this);
        if(x<0&&Razmak(*this)<x) throw std::domain_error("Nelegalan datum");

    }
    friend int operator - (Datum d1,Datum d2)  {
        long long int r1(d1.Razmak(d1));
        long long int r2(d2.Razmak(d2));
        return (r1-r2);
    }
    friend bool operator ==(Datum d1,Datum d2)  {
        if(d1.Razmak(d1)==d2.Razmak(d2)) return true;
        return false;
    }
    friend bool operator !=(Datum d1,Datum d2) {
        if(d1==d2) return false;
        return true;
    }
    friend bool operator < (Datum d1,Datum d2) {
        if(d1!=d2) {
            if(d1.Razmak(d1)<d2.Razmak(d2)) return true;
        }
        return false;
    }
    friend bool operator >(Datum d1,Datum d2) {
        if(d1<d2) return false;
        return true;
    }
    friend bool operator <=(Datum d1, Datum d2) {
        if(d1==d2||d1<d2) return true;
        return false;
    }
    friend bool operator >=(Datum d1,Datum d2) {
        if(d1==d2||d1>d2) return true;
        return false;
    }
    friend std::istream &operator >>(std::istream &tok, Datum &d) {
        char znak;
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(d.Da_Li_Je_Prestupna(d.godina)) broj_dana[1]++;
        tok>>std::ws;
        tok>>d.dan>>znak;
        if(znak!='/') tok.setstate(std::ios::failbit); 
        if(d.dan<1||d.dan>broj_dana[d.mjesec-1])  tok.setstate(std::ios::failbit); 
        tok>>d.mjesec>>znak;
        if(znak!='/') tok.setstate(std::ios::failbit);
        if(d.mjesec<1||d.mjesec>12) tok.setstate(std::ios::failbit); 
        tok>>d.godina;
        if(d.godina<1800) tok.setstate(std::ios::failbit); 
        return tok;
    }
    operator std::string() {
        std::string s;
        s+=std::to_string(dan);
        s.push_back('.');
        s+=this->DajImeMjeseca();
        s.push_back(' ');
        s+=std::to_string(godina);
        s.push_back('.'); s.push_back('(');
        s+=this->DajImeDanaUSedmici();
        s.push_back(')');
        return s;
    }
    explicit operator int () {
        return this->Razmak(*this);
    }

};
int main ()
{
    std::string s;
    int d;
    Datum d1(14,6,2018);
    Datum d2(1,1,1800);
    std::cout << d1.Razmak(d1) << std::endl;
    std::cout << d1;
    std::cout << d2 << std::endl;
    return 0;
}
