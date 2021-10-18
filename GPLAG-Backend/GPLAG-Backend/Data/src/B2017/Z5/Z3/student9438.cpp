#include <iostream>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <utility>
#include <iomanip>

class Datum
{
  int dan, mjesec, godina;
  public:
  enum Mjeseci {Januar=1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
  enum Dani {Ponedjeljak=1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
  Mjeseci m;
  Datum(Dani d, Mjeseci m, int g) {
    Postavi(d,m,g);
  }
  Datum(int d, int m, int g) {
    Postavi(d,m,g);
  }
  
  void Postavi(Dani d, Mjeseci m, int godina) {
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina %4 == 0 && godina % 100 !=0 || godina % 400 == 0)
      broj_dana[1]++;
    if(godina<1800 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1])
      throw std::domain_error("Nelegalan datum");
    dan=d;
    mjesec=m;
    Datum::godina= godina;
  }
  
  void Postavi(int d, int m, int g) {
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g % 4 == 0 && g % 100 != 0 || g%400 == 0)
      broj_dana[1]++;
    if(g<1800 || m < 1 || m > 12 || d <1 || d > broj_dana[mjesec-1])
      throw std::domain_error("Nelegalan datum");
    dan=d;
    mjesec=m;
    godina=g;
  }

  int DajDan() const {
    return dan;
  }
  
  Mjeseci DajMjesec() const {
    return m;
  }
  
  int DajGodinu() const {
    return godina;
  }


  friend Datum &operator ++(Datum &d) {
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dan(d.dan), mjesec(d.mjesec), godina(d.godina);

    if(godina %4 == 0 && godina % 100 !=0 || godina % 400 == 0)
      broj_dana[1]++;
    dan++;
    if(dan > broj_dana[mjesec-1]) dan=1, mjesec++;
    if(mjesec > 12) mjesec=1, godina++;
    d.dan=dan;
    d.mjesec=mjesec;
    d.godina=godina;
  }
  
  friend Datum operator ++(Datum &d, int) {
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dan(d.dan), mjesec(d.mjesec), godina(d.godina);
    Datum pomocni(d);
    if(godina %4 == 0 && godina % 100 !=0 || godina % 400 == 0)
      broj_dana[1]++;
    ++dan;
    if(dan > broj_dana[mjesec-1]) dan=1, mjesec++;
    if(mjesec > 12) mjesec=1, godina++;
    pomocni.dan=dan;
    pomocni.mjesec=mjesec;
    pomocni.godina=godina;
  }
  
  friend Datum &operator --(Datum &d) {
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dan(d.dan), mjesec(d.mjesec), godina(d.godina);

    if(godina %4 == 0 && godina % 100 !=0 || godina % 400 == 0)
      broj_dana[1]++;
    dan--;
    if(dan < 1) dan=broj_dana[mjesec-1], mjesec--;
    if(mjesec < 1) mjesec=12, godina--;
    if(godina < 1800) throw std::domain_error("Nelegalan datum");
    d.dan=dan;
    d.mjesec=mjesec;
    d.godina=godina;
  }

  friend Datum operator --(Datum &d, int) {
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dan(d.dan), mjesec(d.mjesec), godina(d.godina);
    Datum pomocni(d);
    if(godina %4 == 0 && godina % 100 !=0 || godina % 400 == 0)
      broj_dana[1]++;
    --dan;
    if(dan < 1) dan=broj_dana[mjesec-1], mjesec--;
    if(mjesec < 1) mjesec=12, godina--;
    if(godina < 1800) throw std::domain_error("Nelegalan datum");
    pomocni.dan=dan;
    pomocni.mjesec=mjesec;
    pomocni.godina=godina;
  }

  friend Datum operator +(Datum &d, int n) {
    if(n>0) {
      int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      int dan(d.dan), mjesec(d.mjesec), godina(d.godina);
      if(godina %4 == 0 && godina % 100 !=0 || godina % 400 == 0)
        broj_dana[1]++;
      dan = dan + n;
      if(dan > broj_dana[mjesec-1]) {
        dan= dan - broj_dana[mjesec-1];
        mjesec++;
      }
      if (mjesec > 12) {
        mjesec=1;
        godina++;
      }
      if(godina < 1800) throw std::domain_error("Nelegalan datum");
      d.dan=dan;
      d.mjesec=mjesec;
      d.godina=godina;
    }
  }
  
    friend Datum operator -(Datum &d, int n) {
   
      int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      int dan(d.dan), mjesec(d.mjesec), godina(d.godina);
      if(godina %4 == 0 && godina % 100 !=0 || godina % 400 == 0)
        broj_dana[1]++;
      dan = dan - n;
      if(dan < 1) {
        dan= dan + broj_dana[mjesec-1];
        mjesec--;
      }
      if (mjesec < 1) {
        mjesec=12;
        godina--;
      }
      if(godina < 1800) throw std::domain_error("Nelegalan datum");
      d.dan=dan;
      d.mjesec=mjesec;
      d.godina=godina;
    }
    friend Datum &operator +=(Datum &d, int n){
      d=d+n;
      return d;
    }
    friend Datum &operator -=(Datum &d, int n){
      d=d-n;
      return d;
    }
    
    friend int operator -(const Datum &d1, const Datum &d2){
        int g(std::abs(d1.godina-d2.godina));
        int m(std::abs(d1.mjesec-d2.mjesec));
        int d(std::abs(d1.dan-d2.dan));
        return d+m*30+g*365;
      
    }
};

int main ()
{
  return 0;
}
