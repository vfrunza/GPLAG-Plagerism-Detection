/B2017/2018: Zadaća 5, Zadatak 3
#include <cmath>
#include <string>
#include <iostream>
#include <stdexcept>
using std::domain_error;
using std::to_string;
using std::ostream;
using std::istream;
using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::ios; //std::ios::failbit

class Datum {
    int dan, mjesec, godina;
    static bool Prestupna(int g){
        if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) return true;
        return false;
    }
    static int BrojDanaOdReferentnogDatuma(const Datum &dat2);
    static int BrojDanaUGodiniDoTogDatuma(const Datum &dat);
  public:
    enum Mjeseci {
        Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar
};
    enum Dani {
        Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja
};
     Datum(int d, int m, int g) { Postavi(d, m, g); }
     Datum(int d, Mjeseci m, int g) { Postavi(d, int(m), g); }
    void Postavi(int d, int m, int g);
    void Postavi(int d, Mjeseci m, int g) { Postavi(d, int(m), g); }
    int DajDan() const { return dan; }
    Mjeseci DajMjesec() const { return Mjeseci(mjesec); }
    int DajGodinu() const { return godina; }
    const char* DajImeMjeseca() const;
    const char* DajImeDanaUSedmici() const;
    Dani DanUSedmici() const { return Dani(dan); }
    Datum& operator ++();
    Datum& operator --();
    Datum& operator +=(int n);
    Datum& operator -=(int n) { return *this += -n; }
    Datum operator +(int n) const;
    Datum operator -(int n) const;
    Datum operator ++(int);
    Datum operator --(int);
    int operator -(const Datum &d) const;
    bool operator ==(const Datum &d) const {
        return dan == d.dan && mjesec == d.mjesec && godina == d.godina;
    }
    bool operator !=(const Datum &d) const {
        return dan != d.dan || mjesec != d.mjesec || godina != d.godina;
    }
    bool operator <(const Datum &d) const;
    bool operator >(const Datum &d) const;
    bool operator <=(const Datum &d) const {
        return *this < d || *this == d;
    }
    bool operator >=(const Datum &d) const {
        return *this > d || *this == d;
    }
    friend ostream& operator <<(ostream &tok, const Datum &d);
    friend istream& operator >>(istream &tok, Datum &d);
    operator string() const;
    explicit operator int() const;
};
int Datum::BrojDanaUGodiniDoTogDatuma(const Datum &dat){
    int suma(dat.dan - 1); // jer taj dan ne treba da uracunamo u sumu
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(Prestupna(dat.godina)) broj_dana[1]++;
    for(int i=1; i<dat.mjesec; i++) suma += broj_dana[i-1];
    return suma;
}
int Datum::BrojDanaOdReferentnogDatuma(const Datum &dat2){
    Datum dat1(1,1,1800); // referentni datum
    int suma(0), pom_godina(dat1.godina);
    while(pom_godina < dat2.godina){
        suma += 365 + int(Prestupna(pom_godina));
        pom_godina++;
    }
    suma += BrojDanaUGodiniDoTogDatuma(dat2);
    return suma;
}
void Datum::Postavi(int d, int m, int g){
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(Prestupna(g)) broj_dana[1]++;
    if(g<1800 || d<1 || m<1 || m>12 || d>broj_dana[m-1]) throw domain_error("Nelegalan datum");
    dan = d;
    mjesec = m;
    godina = g;
}
const char* Datum::DajImeMjeseca() const {
    const char* imena[13]{"" ,"Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar"};
    return imena[int(mjesec)];
}
const char* Datum::DajImeDanaUSedmici() const {
    const char* imena[7]{"Nedjelja", "Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota"}; 
    //const char* imena[7]{"Sri", "Cet", "Pet", "Sub", "Ned", "Pon", "Uto"}; // *****
    int x(*this - Datum(1,1,1800));
    return imena[x % 7];
}
Datum& Datum::operator ++() { 
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(Prestupna(godina)) broj_dana[1]++;
    dan++;
    if(dan > broj_dana[mjesec-1]) dan = 1, mjesec++;
    if(mjesec > 12) mjesec = 1, godina++;
    return *this;
}
Datum& Datum::operator --() { 
    dan--;
    if(dan == 0) mjesec--;
    if(mjesec == 0) mjesec = 12, godina--;
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(dan == 0){
        if(Prestupna(godina)) broj_dana[1]++;
        dan = broj_dana[mjesec-1];
    }
    if(godina < 1800) throw domain_error("Nelegalan datum");
    return *this;
}
Datum& Datum::operator +=(int n) {
    for(; n<0; n++) --(*this);
    for(; n>0; n--) ++(*this);
    return *this;
}
Datum Datum::operator +(int n) const {
    Datum pom(*this);
    return pom += n;
}
Datum Datum::operator -(int n) const {
    Datum pom(*this);
    return pom -= n;
}
Datum Datum::operator ++(int) {
    Datum pom(*this); 
    *this += 1; // no no (*this)++
    return pom;
}
Datum Datum::operator --(int) {
    Datum pom(*this);
    *this -= 1; // no no (*this)--;
    return pom;
}
int Datum::operator -(const Datum &d) const {
    return std::abs(BrojDanaOdReferentnogDatuma(*this) - BrojDanaOdReferentnogDatuma(d));  // abs ?? ** ** ??
}
bool Datum::operator <(const Datum &d) const {
    if(godina < d.godina) return true;
    if(godina > d.godina) return false;
    if(mjesec < d.mjesec) return true;
    if(mjesec > d.mjesec) return false;
    if(dan < d.dan) return true;
    if(dan > d.dan) return false;
    return false;
}
bool Datum::operator >(const Datum &d) const {
    if(godina > d.godina) return true;
    if(godina < d.godina) return false;
    if(mjesec > d.mjesec) return true;
    if(mjesec < d.mjesec) return false;
    if(dan > d.dan) return true;
    if(dan < d.dan) return false;
    return false;
}
ostream& operator <<(ostream &tok, const Datum &d) {
    return tok << d.dan << "." << d.DajImeMjeseca() << " " << d.godina << ".(" << d.DajImeDanaUSedmici() << ")";
}
istream& operator >>(istream &tok, Datum &d) {
    int dan, mjesec, godina;
    char kosa1, kosa2;
    tok >> dan >> kosa1 >> mjesec >> kosa2 >> godina;
    if(!tok || kosa1 != '/' || kosa2 != '/') tok.setstate(ios::failbit);
    try{
        d = Datum(dan, mjesec, godina);
    }
    catch(...){
        tok.setstate(ios::failbit);
    }
    return tok;
}
Datum::operator int() const {
    return BrojDanaOdReferentnogDatuma(*this);
}
Datum::operator string() const {
    string s(to_string(dan) + ".");
    const char* pok(DajImeMjeseca());
    while(*pok != '\0') {
        s.push_back(*pok);
        pok++;
    }
    s += " " + to_string(godina) + ".(";
    pok = DajImeDanaUSedmici();
    while(*pok != '\0') {
        s.push_back(*pok);
        pok++;
    }
    s += ")";
    return s;
}


int main (){
   /* ;
    cout << Datum (6,6,1944); */
    
    // *Brisi** ne rade dobro test 10 i 11 **
    
    
    
    
   /* Datum d(11,6,2018);
    cout << d << endl;
    d.Postavi(13,6,2018);
    cout << d << endl;
    
    cout << "Unesi datum (d/m/g): ";
    cin >> d;
    cout << "Datum je " << d << endl;
    
    Datum dat(1,1,1800);
    cout << "Novi datum d je " << dat << endl;
    dat.Postavi(2,2,1999);
    cout << "Lejlin datum je " << dat << endl;
    cout << "to je mjesec " << int(dat.DajMjesec()) << ". a godina " << dat.DajGodinu() << endl;
    cout << "naziv tog mjeseca je " << dat.DajImeMjeseca() << " a ime dana u sedmici je " << dat.DajImeDanaUSedmici() << endl;
    cout << "to je " << int(dat.DanUSedmici()) << ". dan u sedmici" << endl;
    
    cout << "Datum je " << dat++ << " a sljedeci datum je " << dat << endl;
    cout << "Datum prethodni je " << dat-2 << endl;
    --dat;
    dat += 2;
    cout << "datum povecan za 2 je " << dat << endl;
    dat--;
    cout << "datum umanjen za 1 je " << dat << endl;
    dat -= 5;
    cout << "datum umanjen za 5 je " << dat << endl;
    cout << "datum + 3 je " << dat + 3 << endl;
    cout << "prefiksni operator ++ daje datum " <<  ++dat << " a prefiksni -- daje datum" << --dat << endl;
    
    
    cout << dat - Datum(1,3, 1800) << endl;
    cout << dat << endl;
    cout << bool(dat == Datum(1,1,1800)) << endl;
    cout << bool(dat != Datum(1,1,1800)) << endl;
    dat = {5,1,1800};
    cout << dat.DajImeDanaUSedmici() << endl;
    
    Datum dd(10,5,2018);
    cout << (string)(dd);
    cout << (int)(dd);
    cout << "\ntrue/false: " << endl;
    Datum tt(3,3,2003);
    cout << bool(dd < tt) << bool(dd > tt) << bool(dd <= tt) << bool(dd >= tt);
*/	return 0;

}