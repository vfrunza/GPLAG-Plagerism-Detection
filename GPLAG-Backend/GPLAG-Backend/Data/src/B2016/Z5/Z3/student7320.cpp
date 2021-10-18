/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <sstream>

typedef long long int lint;
class Razlomak {
  lint brojnik, nazivnik;
  static lint gcd(lint a, lint b) {
    return b == 0 ? a : gcd(b, a % b);
  }
public:
  Razlomak(lint a = 0, lint b = 1) {
    bool prviManji = a < 0;
    bool drugiManji = b < 0;
    a = std::max(a, -a); b = std::max(b, -b);
    lint zaj = gcd(a, b);
    a /= zaj; b /= zaj;
    if (prviManji && drugiManji) brojnik = a, nazivnik = b;
    if (prviManji && !drugiManji) brojnik = -a, nazivnik = b;
    if (!prviManji && drugiManji) brojnik = -a, nazivnik = b;
    if (!prviManji && !drugiManji) brojnik = a, nazivnik = b;
  }
  lint DajBrojnik() { return brojnik; }
  lint DajNazivnik() { return nazivnik; }
  friend Razlomak operator + (const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator - (const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator * (const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator / (const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator + (const Razlomak &r1);
  friend Razlomak operator - (const Razlomak &r1);
  friend Razlomak operator += (const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator -= (const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator *= (const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator /= (const Razlomak &r1, const Razlomak &r2);
  friend bool operator < (const Razlomak &r1, const Razlomak &r2);
  friend bool operator <= (const Razlomak &r1, const Razlomak &r2);
  friend bool operator > (const Razlomak &r1, const Razlomak &r2);
  friend bool operator >= (const Razlomak &r1, const Razlomak &r2);
  friend bool operator == (const Razlomak &r1, const Razlomak &r2);
  friend std::ostream &operator << (std::ostream &tok, const Razlomak &r1);
  friend std::istream &operator >> (std::istream &tok, Razlomak &r1);
  operator long double() const {
    return (long double) brojnik / nazivnik;
  }
};
Razlomak operator + (const Razlomak &r1, const Razlomak &r2) {
  lint r = Razlomak::gcd(r1.nazivnik, r2.nazivnik);
  lint s = Razlomak::gcd(r1.brojnik, r2.nazivnik);
  lint t = Razlomak:: gcd(r2.brojnik, r1.nazivnik);
  lint u = Razlomak:: gcd(r1.brojnik, r2.brojnik);
  Razlomak ret = Razlomak( r1.brojnik * (r2.nazivnik / r) + r2.brojnik * (r1.nazivnik / r) , r1.nazivnik * (r2.nazivnik / r) );
  return ret;
}
Razlomak operator - (const Razlomak &r1, const Razlomak &r2) {
  lint r = Razlomak::gcd(r1.nazivnik, r2.nazivnik);
  lint s = Razlomak::gcd(r1.brojnik, r2.nazivnik);
  lint t = Razlomak:: gcd(r2.brojnik, r1.nazivnik);
  lint u = Razlomak:: gcd(r1.brojnik, r2.brojnik);
  Razlomak ret = Razlomak( r1.brojnik * (r2.nazivnik / r) - r2.brojnik * (r1.nazivnik / r) , r1.nazivnik * (r2.nazivnik / r) );
  return ret;
}
Razlomak operator * (const Razlomak &r1, const Razlomak &r2) {
  lint r = Razlomak::gcd(r1.nazivnik, r2.nazivnik);
  lint s = Razlomak::gcd(r1.brojnik, r2.nazivnik);
  lint t = Razlomak:: gcd(r2.brojnik, r1.nazivnik);
  lint u = Razlomak:: gcd(r1.brojnik, r2.brojnik);
  Razlomak ret = Razlomak( ((r1.brojnik / s) * (r2.brojnik / t)) , (r1.nazivnik / t) * (r2.nazivnik / s));
  return ret;
}
Razlomak operator / (const Razlomak &r1, const Razlomak &r2) {
  lint r = Razlomak::gcd(r1.nazivnik, r2.nazivnik);
  lint s = Razlomak::gcd(r1.brojnik, r2.nazivnik);
  lint t = Razlomak:: gcd(r2.brojnik, r1.nazivnik);
  lint u = Razlomak:: gcd(r1.brojnik, r2.brojnik);
  Razlomak ret = Razlomak( ((r1.brojnik / u) * (r2.nazivnik / r)) , (r1.nazivnik / r) * (r2.brojnik / u));
  return ret;
}
Razlomak operator + (const Razlomak &r1) { return r1; }
Razlomak operator - (const Razlomak &r1) { return Razlomak (-r1.brojnik, -r1.nazivnik); }
Razlomak operator += (const Razlomak &r1, const Razlomak &r2) { return r1 + r2; }
Razlomak operator -= (const Razlomak &r1, const Razlomak &r2) { return r1 - r2; }
Razlomak operator *= (const Razlomak &r1, const Razlomak &r2) { return r1 * r2; }
Razlomak operator /= (const Razlomak &r1, const Razlomak &r2) { return r1 / r2; }
bool operator < (const Razlomak &r1, const Razlomak &r2) {
  long double x1, y1;
  x1 = (long double) (r1.brojnik) / r1.nazivnik;
  y1 = (long double) (r2.brojnik) / r2.nazivnik;
  return x1 < y1; 
}
bool operator <= (const Razlomak &r1, const Razlomak &r2) {
  long double x1, y1;
  x1 = (long double) (r1.brojnik) / r1.nazivnik;
  y1 = (long double) (r2.brojnik) / r2.nazivnik;
  return x1 <= y1; 
}
bool operator > (const Razlomak &r1, const Razlomak &r2) {
  long double x1, y1;
  x1 = (long double) (r1.brojnik) / r1.nazivnik;
  y1 = (long double) (r2.brojnik) / r2.nazivnik;
  return x1 > y1; 
}
bool operator >= (const Razlomak &r1, const Razlomak &r2) {
  long double x1, y1;
  x1 = (long double) (r1.brojnik) / r1.nazivnik;
  y1 = (long double) (r2.brojnik) / r2.nazivnik;
  return x1 >= y1; 
}
bool operator == (const Razlomak &r1, const Razlomak &r2) {
  long double x1, y1;
  x1 = (long double) (r1.brojnik) / r1.nazivnik;
  y1 = (long double) (r2.brojnik) / r2.nazivnik;
  return x1 == y1; 
}
std::ostream &operator << (std::ostream &tok, const Razlomak &r1) {
  tok << r1.brojnik;
  if (r1.nazivnik != 1) tok << "/" << r1.nazivnik;
  return tok;
}
std::istream &operator >> (std::istream &tok, Razlomak &r1) {
  char c;
  tok >> std::ws;
  c = tok.peek();
  if (!(c >= '0' && c <= '9'))  tok.setstate(std::ios::failbit);
  //tok >> std::ws;
  lint br1; tok >> br1;
  //tok >> std::ws;
  c = tok.peek();
  if (c == '/') tok >> c;
  else {
    r1 = Razlomak(br1);
    return tok;
  }
  c = tok.peek();
  if (!(c >= '0' && c <= '9'))  tok.setstate(std::ios::failbit);
  //tok >> std::ws;
  lint br2; tok >> br2;
  r1 = Razlomak(br1, br2);
  c = tok.peek();
  if (!(c >= '0' && c <= '9') && c != ' ')  tok.setstate(std::ios::failbit);
  r1 = Razlomak(br1, br2);
  return tok;
}
int main() {
  
     Razlomak r, q, t;
     std::istringstream is ("10/20"); //ne mora sa \n zavrsiti
     is >> r;
     std::cout << r << std::endl;

     is.str ("173"); //samo jedan broj, 173/1
     is.clear(); //mora, radi EOF
     is >> r;
     std::cout << r << std::endl;

     is.str ("               173/50"); //ispravno, razmaci prije
     is.clear();
     is >> r;
     std::cout << r << std::endl;

     is.str ("               173/50       "); //ispravno, razmaci prije, poslije
     is.clear();
     is >> r;
     std::cout << r << std::endl;


     is.str ("173/51  ne zanima nas sta je nakon     "); //ispravno
     is.clear();
     is >> r; //sljedece citanje bi bilo neispravno
     std::cout << r << std::endl;

     is.str ("17/33e ali je vazno da nakon razlomka ide BJELINA"); //neispravno
     is.clear();
     is >> r;
     if (is.fail()) std::cout << "OK, neispravno!" << std::endl;
     else std::cout << "Nije OK! Ovo nije ispravan unos!" << std::endl;

     //nije ispravno ni npr. 10b/20, ni 10/ 20 ni a20/5
     //necu sve testirati (barem ne u javnim :troll:)

     is.str ("a17/33"); //neispravno
     is.clear();
     is >> r;
     if (is.fail()) std::cout << "OK, neispravno!" << std::endl;
     else std::cout << "Nije OK! Ovo nije ispravan unos!" << std::endl;
/*
     std::cout << "VEOMA VAZNO: " << std::endl;
     //treba biti MOGUCE unijeti vise razlomaka odjednom! (pazite na std::ws)
     is.str (" 1/3   5/7  4/2    nebitno"); //neispravno
     is.clear();
     is >> r >> q >> t;
     std::cout << "r = " << r << ", q = " << q << ", t = " << t;

     //dosta testova :whew: */  
}