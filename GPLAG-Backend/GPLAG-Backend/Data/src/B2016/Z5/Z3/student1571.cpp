#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
#include <limits>

class Razlomak {
  long long int brojnik, nazivnik;
  static int NZD (long long int brojnik, long long int nazivnik) {
      if (nazivnik == 0) return brojnik;
      return NZD (nazivnik, (brojnik % nazivnik));
  }
  static bool DaLiSuIsti (long double a, long double b) {
    double eps (1e-10);
    return std::fabs (a - b) <= eps * (std::fabs(a) + std::fabs(b));
  }
  static bool OverflowZaSabiranje (long long int x, long long int y) {
    long long int m = std::numeric_limits<long long int>::min();
    long long int M = std::numeric_limits<long long int>::max();
    bool uslov(false);
    if (y > 0) {
      if (x > M - y) uslov = true;
    }
    else if (y < 0) {
      if (x < m - y) uslov = true;
    }
    return uslov;
  }
  static bool OverflowZaOduzimanje (long long int x, long long int y) {
    long long int m = std::numeric_limits<long long int>::min();
    long long int M = std::numeric_limits<long long int>::max();
    bool uslov = false;
    if (y < 0) {
      if (x < m - y) uslov = true;
    }
    else if (y > 0) {
      if (x > M - y) uslov =  true;
    }
    return uslov;
  }
  static bool OverflowZaMnozenje (long long int x, long long int y) {
    long long int m = std::numeric_limits<long long int>::min();
    long long int M = std::numeric_limits<long long int>::max();
    bool uslov(false);
    if (y > 0) {
      if ((x < m / y) || (x > M / y)) uslov = true;
    }
    else if (y < 0) {
      if ((x == m) || (-x > M / (-y)) || -x < m / (-y)) uslov = true;
    }
    return uslov;
  }
  public:
  Razlomak (long long int brojnik = 0, long long int nazivnik = 1);
  long long int DajBrojnik() const { return brojnik; }
  long long int DajNazivnik() const { return nazivnik; }
  operator long double();
  friend Razlomak operator+ (const Razlomak &r1, const Razlomak &r2);
  friend Razlomak &operator+= (Razlomak &r1, const Razlomak &r2);
  friend Razlomak &operator-= (Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator- (const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator* (const Razlomak &r1, const Razlomak &r2);
  friend Razlomak &operator*= (Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator/ (const Razlomak &r1, const Razlomak &r2);
  friend Razlomak &operator/= (Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator+ (const Razlomak &r1) { return r1; }
  friend Razlomak &operator- (Razlomak &r1); 
  friend Razlomak &operator-- (Razlomak &r1) { return r1-=1; }
  friend Razlomak &operator++ (Razlomak &r1) { return r1+=1; }
  friend Razlomak operator--  (Razlomak &r1, int n);
  friend Razlomak operator++  (Razlomak &r1, int n);
  friend bool operator<  (const Razlomak &r1, const Razlomak &r2);
  friend bool operator>  (const Razlomak &r1, const Razlomak &r2);
  friend bool operator== (const Razlomak &r1, const Razlomak &r2);
  friend bool operator!= (const Razlomak &r1, const Razlomak &r2) { return !(r1 == r2); }
  friend bool operator<= (const Razlomak &r1, const Razlomak &r2);
  friend bool operator>= (const Razlomak &r1, const Razlomak &r2); 
  //friend std::ostream &operator << (std::ostream &tok, Razlomak &r);
  friend std::istream &operator >> (std::istream &tok, Razlomak &r);
};
Razlomak::Razlomak (long long int brojnik, long long int nazivnik) {
    if (brojnik < 0 && nazivnik < 0) {
      brojnik *= -1;
      nazivnik *= -1;
      Razlomak::brojnik = brojnik;
      Razlomak::nazivnik = nazivnik;
    }
    else if (brojnik < 0) {
      Razlomak::brojnik = brojnik;
      Razlomak::nazivnik = nazivnik;
    }
    else if (nazivnik < 0) {
      brojnik *= -1;
      nazivnik *= -1;
      Razlomak::brojnik = brojnik;
      Razlomak::nazivnik = nazivnik;
    }
    else if (nazivnik == 0) throw std::logic_error ("Nekorektan razlomak");
    
    if (NZD(brojnik, nazivnik) == 1) {
        Razlomak::brojnik = brojnik;
        Razlomak::nazivnik = nazivnik;
    }
    else {
        Razlomak::brojnik = brojnik / (std::abs(NZD (brojnik, nazivnik)));
        Razlomak::nazivnik = nazivnik /(std::abs(NZD (brojnik, nazivnik)));
    }
}
Razlomak operator+ (const Razlomak &r1, const Razlomak &r2) {
  if (Razlomak::OverflowZaSabiranje(r1.DajBrojnik(), r1.DajNazivnik()) || Razlomak::OverflowZaSabiranje(r2.DajBrojnik(), r2.DajNazivnik())) 
    throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
  int r(Razlomak::NZD(r1.DajNazivnik(), r2.DajNazivnik()));
  return {r1.DajBrojnik() * (r2.DajNazivnik() / r) + r2.DajBrojnik() * (r1.DajNazivnik() / r), r1.DajNazivnik() * (r2.DajNazivnik() / r)};
}
Razlomak &operator+= (Razlomak &r1, const Razlomak &r2) {
  if (Razlomak::OverflowZaSabiranje(r1.DajBrojnik(), r1.DajNazivnik()) || Razlomak::OverflowZaSabiranje(r2.DajBrojnik(), r2.DajNazivnik()))
    throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
  int r(Razlomak::NZD (r1.DajNazivnik(), r2.DajNazivnik()));
  r1.brojnik = r1.DajBrojnik() * (r2.DajNazivnik() / r) + r2.DajBrojnik() * (r1.DajNazivnik() / r);
  r1.nazivnik =r1.DajNazivnik() * (r2.DajNazivnik() / r);
  long long int a(r1.brojnik), b(r1.nazivnik);
  Razlomak pomocni(a, b);
  r1 = pomocni;
  return r1;
}
Razlomak operator- (const Razlomak &r1, const Razlomak &r2) {
 if (Razlomak::OverflowZaOduzimanje(r1.DajBrojnik(), r1.DajNazivnik()) || Razlomak::OverflowZaOduzimanje(r2.DajBrojnik(), r2.DajNazivnik()))
   throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
  int r(Razlomak::NZD (r1.DajNazivnik(), r2.DajNazivnik()));
  return {r1.DajBrojnik() * (r2.DajNazivnik() / r) - r2.DajBrojnik() * (r1.DajNazivnik() / r), r1.DajNazivnik() *  (r2.DajNazivnik() / r)};
}
Razlomak &operator-= (Razlomak &r1, const Razlomak &r2) {
  if (Razlomak::OverflowZaOduzimanje(r1.DajBrojnik(), r1.DajNazivnik()) || Razlomak::OverflowZaOduzimanje(r2.DajBrojnik(), r2.DajNazivnik()))
     throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
  int r(Razlomak::NZD (r1.DajNazivnik(), r2.DajNazivnik()));
  r1.brojnik = r1.DajBrojnik() * (r2.DajNazivnik() / r) - r2.DajBrojnik() * (r1.DajNazivnik() / r);
  r1.nazivnik = r1.DajNazivnik() * (r2.DajNazivnik() / r);
  Razlomak pomocni (r1.brojnik, r1.nazivnik);
  r1 = pomocni;
  return r1;
}
Razlomak operator* (const Razlomak &r1, const Razlomak &r2) {
  if (Razlomak::OverflowZaMnozenje(r1.DajBrojnik(), r1.DajNazivnik()) || Razlomak::OverflowZaMnozenje(r2.DajBrojnik(), r2.DajNazivnik()))
    throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
  int s (Razlomak::NZD (r1.DajBrojnik(), r2.DajNazivnik())), t (Razlomak::NZD (r2.DajBrojnik(), r1.DajNazivnik()));
  return {((r1.DajBrojnik() / s) * (r2.DajBrojnik() / t)), ((r1.DajNazivnik() / t) * (r2.DajNazivnik() /s))};
}
Razlomak &operator*= (Razlomak &r1, const Razlomak &r2) {
  if (Razlomak::OverflowZaMnozenje(r1.DajBrojnik(), r1.DajNazivnik()) || Razlomak::OverflowZaMnozenje(r2.DajBrojnik(), r2.DajNazivnik()))
    throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
  int s(Razlomak::NZD (r1.DajBrojnik(), r2.DajNazivnik())), t(Razlomak::NZD (r2.DajBrojnik(), r1.DajNazivnik()));
  r1.brojnik = (r1.DajBrojnik() / s) * (r2.DajBrojnik() / t);
  r1.nazivnik = (r1.DajNazivnik() / t) * (r2.DajNazivnik() / s);
  Razlomak pomocni (r1.brojnik, r1.nazivnik);
  r1 = pomocni;
  return r1;
}
Razlomak operator/ (const Razlomak &r1, const Razlomak &r2) {
  int u (Razlomak::NZD(r1.DajBrojnik(), r2.DajBrojnik())), r(Razlomak::NZD (r1.DajNazivnik(), r2.DajNazivnik()));
  return {((r1.DajBrojnik() / u) * (r2.DajNazivnik() / r)), ((r1.DajNazivnik() /r) * (r2.DajBrojnik() / u))};
}
Razlomak &operator/= (Razlomak &r1, const Razlomak &r2) {
  int u(Razlomak::NZD (r1.DajBrojnik(), r2.DajBrojnik())), r(Razlomak::NZD (r1.DajNazivnik(), r2.DajNazivnik()));
  r1.brojnik = (r1.DajBrojnik() / u) * (r2.DajNazivnik() / r);
  r1.nazivnik = (r1.DajNazivnik() / r) * (r2.DajBrojnik() / u);
  Razlomak pomocni (r1.brojnik, r1.nazivnik);
  r1 = pomocni;
  return r1;
}
Razlomak &operator- (Razlomak &r1) {
  Razlomak pom (-r1.DajBrojnik(), r1.DajNazivnik());
  r1 = pom;
  return r1;
}
std::ostream  &operator <<(std::ostream &tok, const Razlomak &r) {
  if (r.DajNazivnik() == 1) std::cout << r.DajBrojnik();
  else std::cout <<r.DajBrojnik() << "/" << r.DajNazivnik();
  return tok;
}
std::istream &operator >> (std::istream &tok, Razlomak &r) {
  char znak;
  long long int a, b;
  tok >> std::ws;
  tok >> a;
  if (tok.peek() != '/') {
    r.brojnik = a;
    r.nazivnik = 1;
    return tok;
  }
  tok >> znak;
  if (znak != '/') tok.setstate (std::ios::failbit);
  tok >> b;
  if (tok.peek() != '\n' && tok.peek() != '\t' && tok.peek() != '\v' && tok.peek() != ' ' && tok.peek() != '\f') tok.setstate (std::ios::failbit);
  if (Razlomak::NZD(a, b) == 1) {
    r.brojnik = a;
    r.nazivnik = b;
    return tok;
  }
  else {
    r.brojnik = a / (Razlomak::NZD (a, b));
    r.nazivnik = b / (Razlomak::NZD (a, b));
    return tok;
  }
}
Razlomak::operator long double() {
  long double rezultat = (static_cast<long double> (brojnik)) / nazivnik;
  return rezultat;
}
Razlomak operator++ (Razlomak &r1, int n) {
  Razlomak pomocni (r1);
  ++r1;
  return pomocni;
}
Razlomak operator-- (Razlomak &r1, int n) {
  Razlomak pomocni (r1);
  --r1;
  return pomocni;
}
bool operator< (const Razlomak &r1, const Razlomak &r2) {
  long double vr1 = (static_cast<long double> (r1.brojnik)) / r1.nazivnik;
  long double vr2 = (static_cast<long double> (r2.brojnik)) / r2.nazivnik;
  return vr1 < vr2;
}
bool operator > (const Razlomak &r1, const Razlomak &r2) {
  long double vr1 = (static_cast<long double> (r1.brojnik)) / r1.nazivnik;
  long double vr2 = (static_cast<long double> (r2.brojnik)) / r2.nazivnik;
  return vr1 > vr2;
}
bool operator== (const Razlomak &r1, const Razlomak &r2) {
  long double vr1 = (static_cast<long double> (r1.brojnik)) / r1.nazivnik;
  long double vr2 = (static_cast<long double> (r2.brojnik)) / r2.nazivnik;
  return Razlomak::DaLiSuIsti(vr1, vr2);
}
bool operator<= (const Razlomak &r1, const Razlomak &r2) {
  long double vr1 = (static_cast<long double> (r1.brojnik)) / r1.nazivnik;
  long double vr2 = (static_cast<long double> (r2.brojnik)) / r2.nazivnik;
  return vr1 <= vr2;
}
bool operator >= (const Razlomak &r1, const Razlomak &r2) {
  long double vr1 = (static_cast<long double> (r1.brojnik)) / r1.nazivnik;
  long double vr2 = (static_cast<long double> (r2.brojnik)) / r2.nazivnik;
  return vr1 >= vr2;
}
int main ()
{
    try {
      Razlomak r(1,-2),p{1,2}; // konstruktori
      std::cout << r + p; // operator+s
      std::cout << std::endl << r - p; // operator-
      std::cout << std::endl << r * p << std::endl; // operator*
      std::cout << r/p << std::endl; // operator/
      if (r < p) std::cout << "Manji je!"; // operator <
      else std::cout << "Nije manji!"; 
      if (p > r) std::cout << std::endl << "Veci je!"; // operator >
      else std::cout << std::endl<< "Nije veci!";
      std::cout << std::endl << --r; // operator-- prefiksni
      std::cout << std::endl << ++r; // operator++ prefiksni
      r += p; // operator +=
      std::cout << std::endl << r;
      r -= p; // operator -=
      std::cout << std::endl << r;
      r *= p; // operator *=
      std::cout << std::endl << r;
      r /= p; // operator /=
      std::cout << std::endl << r << std::endl;
      Razlomak a;
      std::cin >> a;
      std::cout << a;
      -r;
      std::cout << r;
  }
  catch (std::overflow_error por) {
    std::cout << por.what();
  }
  catch (std::logic_error por) {
    std::cout << por.what();
  }
	return 0;
}