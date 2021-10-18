/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Datum {
    int dan, mjesec, godina;
    static bool Prestupna(int god) {
        return ((god%4==0 and god%100!=0) or god%400==0); 
    }
    static string PretvoriUString(int broj) {
        string s;
        if(broj<0) broj*=(-1);
        do {
            s.insert(s.begin(),broj%10+48);
            broj/=10;
        } while(broj!=0);
        return s;
    }
  public:
  enum Mjeseci{Januar=1,Februar,Mart,April,Maj,Juni,Juli,August,Septembar,Oktobar,Novembar,Decembar};
  enum Dani {Ponedjeljak=1,Utorak,Srijeda,Cetvrtak,Petak,Subota,Nedjelja};
  Datum(int dan, int mjesec, int godina) {
      Postavi(dan,mjesec,godina);
  }
  Datum(int dan, Mjeseci mjesec, int godina) {
      Postavi(dan,(int)mjesec,godina);
  }
  void Postavi(int dan, int mjesec, int godina);
  void Postavi(int dan, Mjeseci mjesec, int godina) {Postavi(dan,int(mjesec),godina);}
  int dajDan() const {return dan;}
  int dajGodinu() const {return godina;}
  Mjeseci dajMjesec() const {return Mjeseci(mjesec);}
  Dani DanUSedmici() const;
  const char *DajImeDanaUSedmici() const;
  const char *DajImeMjeseca() const;
  Datum &operator ++();
  Datum operator ++(int);
  Datum &operator --();
  Datum operator --(int);
  friend Datum operator+(const Datum &d, int koliko);
  friend Datum operator-(const Datum &d, int koliko);
  friend int operator-(const Datum &d1, const Datum &d2);
  Datum &operator+=(int d) {
      *this=*this+d;
      return *this;
  }
  Datum &operator-=(int d) {
      *this=*this-d;
      return *this;
  }
  bool operator==(const Datum &d);
  inline bool operator !=(const Datum &d) {return !(*this==d);}
  bool operator <(const Datum &d);
  bool operator <=(const Datum &d) {return !(*this>d);}
  bool operator >(const Datum &d) {return (*this!=d and !(*this<d));}
  bool operator >=(const Datum &d) {return !(*this<d);}
  friend ostream &operator <<(ostream &tok, const Datum &d);
  friend istream &operator >>(istream &tok, Datum &d);
  operator string() const;
  explicit operator int() const;
};

void Datum::Postavi(int dan, int mjesec, int godina) {
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(Prestupna(godina)) brojdana[1]++;
    if(godina<1795 or dan<1 or mjesec<1 or mjesec>12 or dan>brojdana[mjesec-1]) throw domain_error("Nelegalan datum!");
    Datum::dan=dan;
    Datum::mjesec=mjesec;
    Datum::godina=godina;
}
Datum::Dani Datum::DanUSedmici() const {
    int brojac=0;
    int brojdana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i=1800;i<godina;i++) 
    if(Prestupna(i)==true) brojac++;
    brojac=brojac+(godina-1800)*365;
    brojac=brojac+dan-1;
    if(Prestupna(godina) and mjesec>=3) brojac++;
    for(int i=1;i<mjesec;i++) {
        brojac+=brojdana[i-1];
    }
    if((brojac%7+3)%7==0) return Dani(7);
    return Dani((brojac%7+3)%7);
}
const char *Datum::DajImeMjeseca() const {
    const char*imena_mjeseci[] {"Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar"};
    return imena_mjeseci[mjesec-1];
}
const char *Datum::DajImeDanaUSedmici() const {
    cout<<DanUSedmici()<<endl;
    const char *imena_dana[]{"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};
    return imena_dana[DanUSedmici()-1];
}
Datum &Datum::operator ++() {
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(Prestupna(godina)) brojdana[1]++;
    dan++;
    if(dan>brojdana[mjesec-1]) {
        dan=1;
        mjesec++;
        if(mjesec>12) {
            mjesec=1;
            godina++;
        }
    }
    return *this;
}
Datum Datum::operator ++(int) {
    Datum tmp(*this);
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(Prestupna(godina)) brojdana[1]++;
    dan++;
    if(dan>brojdana[mjesec-1]) {
        dan=1;
        mjesec++;
        if(mjesec>12) {
            mjesec=1;
            godina++;
        }
    }
    return tmp;
}
Datum &Datum::operator --() {
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(Prestupna(godina)) brojdana[1]++;
    if(dan==1 and mjesec==1 and godina==1800) throw domain_error("Nelegalan datum");
    dan--;
    if(dan<1) {
        mjesec--;
        if(mjesec<1) {
            mjesec=12;
            godina--;
        }
        dan=brojdana[mjesec-1];
    }
    return *this;
}
Datum Datum::operator --(int) {
    Datum tmp(*this);
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(Prestupna(godina)) brojdana[1]++;
    if(dan==1 and mjesec==1 and godina==1800) throw domain_error("Nelegalan datum");
    dan--;
    if(dan<1) {
        mjesec--;
        if(mjesec<1) {
            mjesec=12;
            godina--;
        }
        dan=brojdana[mjesec-1];
    }
    return tmp;
}
Datum operator+(const Datum &d, int koliko) {
    Datum povratni(d);
    for(int i=0;i<koliko;i++) povratni++;
    return povratni;
}
Datum operator-(const Datum &d, int koliko) {
    Datum povratni(d);
    for(int i=0;i<koliko;i++) povratni--;
    return povratni;
}
int operator-(const Datum &d1, const Datum &d2) {
    int brojdanad1=(int)d1;
    int brojdanad2=(int)d2;
    if(brojdanad1>brojdanad2) return  brojdanad1-brojdanad2;
    else return brojdanad2-brojdanad1;
}
bool Datum::operator ==(const Datum &d) {
    if(godina!=d.godina) return false;
    if(mjesec!=d.mjesec) return false;
    if(dan!=d.dan) return false;
    return true;
}
bool Datum::operator <(const Datum &d) {
    if(godina<d.godina) return true;
    else if(godina>d.godina) return false;
    else {
        if(mjesec<d.mjesec) return true;
        else if(mjesec>d.mjesec) return false;
        else return dan<d.dan;
    }
}
ostream &operator<<(ostream &tok, const Datum &d) {
    tok<<d.dan<<"."<<d.DajImeMjeseca()<<" "<<d.godina<<".("<<d.DajImeDanaUSedmici()<<")";
    return tok;
}
istream &operator>>(istream &tok, Datum &d) {
    int dan, mjesec, godina;
    char znak;
    tok>>d.dan;
    tok>>znak;
    if(znak!='/') tok.setstate(ios::failbit);
    tok>>d.mjesec;
    tok>>znak;
    if(znak!='/') tok.setstate(ios::failbit);
    tok>>d.godina;
    if(tok.peek()!=' ' and tok.peek()!='\n') tok.setstate(ios::failbit);
    if(d.godina<1800) tok.setstate(ios::failbit);
    if(d.mjesec<1 or d.mjesec>12) tok.setstate(ios::failbit);
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(Datum::Prestupna(d.godina)==true) brojdana[1]++;
    if(d.dan<1 or d.dan>brojdana[d.mjesec-1]) tok.setstate(ios::failbit);
    return tok;
}
Datum::operator string() const {
    string tok;
    tok+=Datum::PretvoriUString(dan);
    tok+=".";
    tok+=DajImeMjeseca();
    tok+=" ";
    tok+=Datum::PretvoriUString(godina);
    tok+=".(";
    tok+=DajImeDanaUSedmici();
    tok+=")";
    return tok;
}
Datum::operator int() const {
    int brojdanad1=dan-1;
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(Datum::Prestupna(godina)==true) brojdana[1]++;
    for(int i=1;i<mjesec;i++) brojdanad1+=brojdana[i-1];
    for(int i=1800;i<godina;i++) 
    if(Datum::Prestupna(i)==true) brojdanad1++;
    brojdanad1+=(godina-1800)*365;
    return brojdanad1;
}

int main ()
{
    Datum t(23,Datum::Mjeseci::April,2864);
    Datum t2(1,Datum::Mjeseci::Maj,2018);
    t=t-600;
    cout<<t;
	return 0;
}
