/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <sstream>

template <typename T> std::string PretvoriUString(T x)
{
  std::ostringstream s;
  s << x;
  return s.str();
}

class Datum {

  int d, m, g;
  static int BrojDana (int mjesec, int godina) {
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    return broj_dana[mjesec-1];
  }

  static bool DolaziPrije(const Datum &dat1, const Datum &dat2) {
    int dan1(dat1.d), mj1(dat1.m), god1(dat1.g), dan2(dat2.d), mj2(dat2.m), god2(dat2.g);
    return ((god1<god2) || (god1==god2 && mj1<mj2) || (god1==god2 && mj1==mj2 && dan1<dan2));
  }

  static int BrojDanaDoDatuma(int dan, int mj, int god) {
    int dani(0);
    for (int i=1800; i<god; i++) dani+=365+((i%4==0 && i%100!=0) || i%400==0);
    for (int i=1; i<mj; i++) dani+=BrojDana(i, god);
    dani+=dan;
    return dani;
  }

public:

  enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
  enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

  Datum(int dan, int mjesec, int godina) {
    Postavi(dan, mjesec, godina);
  }
  Datum(int dan, Mjeseci mjesec, int godina) {
    Postavi(dan, mjesec, godina);
  }


  Datum &operator =(const Datum &dat) {
    if (&dat!=this) {
      d=dat.d;
      m=dat.m;
      g=dat.g;
    }
    return *this;
  }

  Datum &operator =(Datum &&dat) {
    if (&dat!=this) {
      d=dat.d;
      m=dat.m;
      g=dat.g;
    }
    return *this;
  }

  Datum(const Datum &dat) {
    d=dat.d;
    m=dat.m;
    g=dat.g;
  }
  Datum(Datum &&dat) {
    d=dat.d;
    m=dat.m;
    g=dat.g;
  }


  void Postavi(int dan, int mjesec, int godina) {
    if (godina<1800 || mjesec<1 || mjesec>12) throw std::domain_error("Neispravan datum");
    if (dan<1 || dan>BrojDana(mjesec, godina)) throw std::domain_error("Neispravan datum");
    d=dan;
    m=mjesec;
    g=godina;
  }

  void Postavi(int dan, Mjeseci mjesec, int godina) {
    if (godina<1800 || mjesec<1 || mjesec>12) throw std::domain_error("Neispravan datum");
    if (dan<1 || dan>BrojDana(mjesec, godina)) throw std::domain_error("Neispravan datum");
    d=dan;
    m=mjesec;
    g=godina;
  }

  int DajDan() const {
    return d;
  }
  Mjeseci DajMjesec() const {
    return Mjeseci(m);
  }
  int DajGodinu() const {
    return g;
  }

  const char* DajImeMjeseca() const {
    const char* niz[12] { "Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar"};
    return niz[int(m)-1];
  }

  Dani DanUSedmici() const {

    int niz[] {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

    int god(g), mj(m), dan(d);

    god-=mj<3;

    if ((god + god/4 - god/100 + god/400 + niz[mj-1] + dan) % 7==0) return Dani(7);
    return Dani((god + god/4 - god/100 + god/400 + niz[mj-1] + dan) % 7);
  }

  const char* DajImeDanaUSedmici() const {
    const char* niz[7] { "Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};
    return niz[int(DanUSedmici())-1];
  }

  friend Datum &operator ++(Datum &dat);

  friend Datum operator ++(Datum &dat, int);

  friend Datum &operator --(Datum &dat);

  friend Datum operator --(Datum &dat, int);

  friend Datum operator +(const Datum &dat, int n);

  friend Datum operator -(const Datum &dat, int n);

  friend Datum &operator +=(Datum &dat, int n);

  friend Datum &operator -=(Datum &dat, int n) {
    dat+=(-n);
    return dat;
  }

  friend int operator -(const Datum &dat1, const Datum &dat2);

  friend bool operator ==(const Datum &dat1, const Datum &dat2) {
    return dat1.d == dat2.d && dat1.m == dat2.m && dat1.g==dat2.g;
  }

  friend bool operator !=(const Datum &dat1, const Datum &dat2) {
    return !(dat1 == dat2);
  }

  friend bool operator <(const Datum &dat1, const Datum &dat2) {
    return DolaziPrije(dat1, dat2);
  }

  friend bool operator >(const Datum &dat1, const Datum &dat2) {
    return !(dat1<dat2) && dat1!=dat2;
  }

  friend bool operator <=(const Datum &dat1, const Datum &dat2) {
    return dat1<dat2 || dat1==dat2;
  }

  friend bool operator >=(const Datum &dat1, const Datum &dat2) {
    return dat1>dat2 || dat1==dat2;
  }

  friend std::ostream &operator <<(std::ostream &tok, const Datum &dat) {
    tok  << std::string(dat) << std::endl;
    return tok;
  }

  friend std::istream &operator >>(std::istream &tok, Datum &dat);

  operator std::string() const {
    std::string s(PretvoriUString(d));

    s=s+".";
    s=s+DajImeMjeseca();
    s=s+" ";
    s=s+PretvoriUString(g);
    s=s+".(";
    s=s+DajImeDanaUSedmici();
    s=s+")";

    return s;
  }

  explicit operator int() const {
    return BrojDanaDoDatuma(d, m, g);
  }

};

Datum &operator ++(Datum &dat)
{
  dat.d++;
  if (dat.d>Datum::BrojDana(dat.m, dat.g)) {
    dat.d=1;
    dat.m++;
  }
  if (dat.m>12) {
    dat.m=1;
    dat.g++;
  }
  return dat;
}

Datum operator ++(Datum &dat, int)
{
  Datum pomocna(dat.d, dat.m, dat.g);
  ++dat;
  return pomocna;
}

Datum &operator --(Datum &dat)
{
  int dan(dat.d), mj(dat.m), god(dat.g);
  dan--;
  if (dan<1) {
    mj--;
    if (mj>0) dan=Datum::BrojDana(mj, god);
  }
  if (mj<1) {
    mj=12;
    god--;
    if (god<1800) throw std::domain_error("Nelegalan datum");
    dan=31;
  }

  dat.d=dan;
  dat.m=mj;
  dat.g=god;
  return dat;
}

Datum operator --(Datum &dat, int)
{
  Datum pomocna(dat);
  --dat;
  return pomocna;
}


Datum operator +(const Datum &dat, int n)
{
  Datum pomocna(dat.d, dat.m, dat.g);
  pomocna+=n;
  return pomocna;
}

Datum operator -(const Datum &dat, int n)
{
  Datum pomocna(dat.d, dat.m, dat.g);
  pomocna-=n;
  return pomocna;
}

Datum &operator +=(Datum &dat, int n)
{
  if (n>0) for (int i=0; i<n; i++) dat++;
  else {
    Datum pomocna(dat);
    for (int i=n; i<0; i++) pomocna--;
    dat=pomocna;
  }
  return dat;
}


int operator -(const Datum &dat1, const Datum &dat2)
{
  int n1(Datum::BrojDanaDoDatuma(dat1.d, dat1.m, dat1.g)), n2(Datum::BrojDanaDoDatuma(dat2.d, dat2.m, dat2.g));
  return std::abs(n1-n2);
}

std::istream &operator >>(std::istream &tok, Datum &dat)
{
  char znak;
  int dan, mj, god;
  try {
    tok >> dan;
    if (tok.peek()!='/') throw "";
    tok >> znak >> mj;
    if (tok.peek()!='/') throw "";
    tok >> znak >> god;
    if (tok.peek()!='\n') throw "";
  } catch(...) {
    tok.setstate(std::ios::failbit);
    return tok;
  }
  dat.Postavi(dan, mj, god);
  return tok;
}




int main ()
{

  try {
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


    std::cout << d2 << std::endl;
    d2-=44;
    std::cout << d2 << std::endl;
    --d2;
    std::cout << d2 << std::endl;

    d1+=8;
    std::cout << d1 << std::endl;

  } catch(std::exception &iz) {
    std::cout << iz.what();
  }


  return 0;
}
