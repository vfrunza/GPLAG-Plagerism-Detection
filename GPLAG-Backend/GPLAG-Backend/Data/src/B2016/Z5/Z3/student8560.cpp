#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <initializer_list>
bool ProvjeraMnozenja(long long int br1, long long int br2) {
    long long int M(std::numeric_limits<long long int>::max());
    long long int m(std::numeric_limits<long long int>::min());
    if(br2 < 0) {
        if(br1 < m - br2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(br2 > 0) {
        if(br1 > M - br2) throw std::overflow_error ("Nemoguce dobiti rezultat");
    }
    return true;
}
bool ProvjeraSabiranja(long long int br1, long long int br2) {
    long long int M(std::numeric_limits<long long int>::max());
    long long int m(std::numeric_limits<long long int>::min());
    if(br2 < 0) {
        if(br1 == m || br1 *(-1) < m/(br2*(-1)) || br1*(-1) > M/(br2*(-1))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(br2 > 0) {
        if(br1 < m/br2 || br1 > M/br2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    return true;
}
class Razlomak {
    long long int brojnik;
    long long int nazivnik;
    static long long int NZD(long long int br1, long long int br2) {
        if(br2 == 0) return br1;
        long long int nzd = NZD(br2, br1%br2);
           return nzd;
    }
    public: 
    Razlomak(long long int br, long long int naz) {
        if(naz == 0) throw std::logic_error("Nekorektan razlomak");
        int nzd(NZD(br, naz));
        if(br > 0 && naz < 0) { br *= -1; naz *= -1; }
        if(br < 0 && naz < 0) { br *= -1; naz *= -1; }
        brojnik = br/nzd;
        nazivnik = naz/nzd;
    }
    Razlomak(long long int br) {
        brojnik = br;
        nazivnik = 1;
    }
    Razlomak() {
        brojnik = 0;
        nazivnik = 1;
    }
    Razlomak(std::initializer_list<long long int> l) {
        if(l.size() == 0) { brojnik = 0; nazivnik = 1; }
        else {
            auto it = l.begin();
            brojnik = *it;
            if(l.size() == 2) {
                it++;
                nazivnik = *it;
            }
            else nazivnik = 1;
        }
        if(nazivnik < 0) {
            nazivnik *= -1;
            brojnik *= -1;
        }
        long long int nzd = NZD(brojnik, nazivnik);
        brojnik /= nzd;
        nazivnik /= nzd;
    }
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator +(const Razlomak &r);
    friend Razlomak operator -(const Razlomak &r);
    friend Razlomak &operator +=(Razlomak &r1, const Razlomak r2);
    friend Razlomak &operator -=(Razlomak &r1, const Razlomak r2);
    friend Razlomak &operator *=(Razlomak &r1, const Razlomak r2);
    friend Razlomak &operator /=(Razlomak &r1, const Razlomak r2);
    friend std::ostream &operator <<(std::ostream &tok,const Razlomak &r);
    friend std::istream &operator >>(std::istream &tok, Razlomak &r);
    friend bool operator <(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >(const Razlomak &r1, const Razlomak &r2);
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2) {
    return r1.brojnik == r2.brojnik && r1.nazivnik == r2.nazivnik;
    }
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2) {
        return r1.brojnik != r2.brojnik || r1.nazivnik != r2.nazivnik;
    }
    friend inline Razlomak operator++(Razlomak &r, int);
    friend Razlomak &operator++(Razlomak &r) {
        Razlomak r1(1, 1);
        r += r1;
        return r;
    }
    operator long double() const;
};
 std::ostream &operator <<(std::ostream &tok, const Razlomak &r) {
    if(r.nazivnik == 1) tok << r.brojnik;
    else tok << r.brojnik << "/" << r.nazivnik;
    return tok;
}
std::istream &operator >>(std::istream &tok, Razlomak &r) {
      if(tok.peek() < '0' && tok.peek() > '9') {
          tok.setstate(std::ios::failbit); 
          return tok;
      }
      tok >> std::ws >> r.brojnik;
      if(tok.peek() != '/') {
          r.nazivnik = 1;
               }
        else {
          if(tok.peek() != '/') {
              tok.setstate(std::ios::failbit);
              return tok;
              }
              char znak('/');
              tok >> znak;
              if(tok.peek() < '0' && tok.peek() > '9') {
                  tok.setstate(std::ios::failbit);
                  return tok;
              }
              tok >> std::ws;
              tok >> r.nazivnik;
              if(tok.peek() != '\t' && tok.peek() != '\v' && tok.peek()!= '\f' && tok.peek() != '\n' && tok.peek() != ' ' )
              tok.setstate(std::ios::failbit);
      
            r = Razlomak(r.brojnik, r.nazivnik);
        }
            return tok;
       }
Razlomak operator +(const Razlomak &r1, const Razlomak &r2) {
    Razlomak r3(r1.brojnik, r1.nazivnik);
    long long int r = Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    try {
        bool proizvod1 = ProvjeraMnozenja(r1.brojnik, (r2.nazivnik/r));
        bool proizvod2 = ProvjeraMnozenja(r2.brojnik, (r1.nazivnik/r));
        bool zbir1 = ProvjeraSabiranja(proizvod1, proizvod2);
        bool proizvod3 = ProvjeraMnozenja(r1.nazivnik, (r2.nazivnik,r));
    } catch(std::overflow_error) {
        throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    }
    r3.brojnik = (r1.brojnik * (r2.nazivnik/r) + r2.brojnik * (r1.nazivnik/r));
    r3.nazivnik = (r1.nazivnik * (r2.nazivnik/r));
    r3 = Razlomak(r3.brojnik, r3.nazivnik);
    return r3;
}
Razlomak operator -(const Razlomak &r1, const Razlomak &r2) {
    Razlomak r3(r1.brojnik, r1.nazivnik);
    long long int r = Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    try {
        bool proizvod1 = ProvjeraMnozenja(r1.brojnik, (r2.nazivnik/r));
        bool proizvod2 = ProvjeraMnozenja(r2.brojnik, (r1.nazivnik/r));
        bool zbir1 = ProvjeraSabiranja(proizvod1, proizvod2);
        bool proizvod3 = ProvjeraMnozenja(r1.nazivnik, (r2.nazivnik/r));
    } catch(std::overflow_error) {
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    r3.brojnik = (r1.brojnik * (r2.nazivnik/r) - r2.brojnik * (r1.nazivnik/r));
    r3.nazivnik = (r1.nazivnik * (r2.nazivnik/r));
    r3 = Razlomak(r3.brojnik, r3.nazivnik);
    return r3;
}
Razlomak operator *(const Razlomak &r1, const Razlomak &r2) {
    Razlomak r3(r1.brojnik, r1.nazivnik);
    long long int s = Razlomak::NZD(r1.brojnik, r2.nazivnik);
    long long int t = Razlomak::NZD(r2.brojnik, r1.nazivnik);
    try {
        bool proizvod1 = ((r1.brojnik/s) * (r2.brojnik/t));
        bool proizvod2 = ((r1.nazivnik/t) * (r2.nazivnik/s));
    } catch (std::overflow_error) {
        throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    }
    r3.brojnik = (r1.brojnik/s) * (r2.brojnik/t);
    r3.nazivnik = (r1.nazivnik/t) * (r2.nazivnik/s);
    r3 = Razlomak(r3.brojnik, r3.nazivnik);
    return r3;
}
Razlomak operator /(const Razlomak &r1, const Razlomak &r2) {
    Razlomak r3(r1.brojnik, r1.nazivnik);
    long long int r = Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    long long int u = Razlomak::NZD(r1.brojnik, r2.brojnik);
    try {
        bool proizvod1 = ((r1.brojnik/u) * (r2.nazivnik/r));
        bool proizvod2 = ((r1.nazivnik/r) * (r2.brojnik/u));
    } catch (std::overflow_error) {
        throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    }
    r3.brojnik = (r1.brojnik/u) * (r2.nazivnik/r);
    r3.nazivnik = (r1.nazivnik/r) * (r2.brojnik/u);
    r3 = Razlomak(r3.brojnik, r3.nazivnik);
    return r3;
}
Razlomak operator +(const Razlomak &r) {
    return r;
    }
Razlomak operator -(const Razlomak &r) {
    Razlomak r1(r.brojnik, r.nazivnik);
    r1.brojnik *= -1;
    return r1;
}
Razlomak &operator +=(Razlomak &r1, const Razlomak r2) {
  long long int r = Razlomak::NZD(r1.nazivnik, r2.nazivnik);
  try {
      bool proizvod1 = ProvjeraMnozenja(r1.brojnik, (r2.nazivnik/r));
      bool proizvod2 = ProvjeraMnozenja(r2.brojnik, (r1.nazivnik/r));
      bool zbir = ProvjeraSabiranja(proizvod1, proizvod2);
      bool proizvod3 = ProvjeraMnozenja(r1.nazivnik, (r2.nazivnik/r));
      
  } catch(std::overflow_error) {
      throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
  }
  r1.brojnik = (r1.brojnik * (r2.nazivnik/r) + r2.brojnik * (r1.nazivnik/r));
  r1.nazivnik = (r1.nazivnik * (r2.nazivnik/r));
  r1 = Razlomak(r1.brojnik, r1.nazivnik);
   return r1;
}
Razlomak &operator -=(Razlomak &r1, const Razlomak r2) {
    long long int r = Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    try {
        bool proizvod1 = ProvjeraMnozenja(r1.brojnik, (r2.nazivnik/r));
        bool proizvod2 = ProvjeraMnozenja(r2.brojnik, (r1.nazivnik/r));
        bool zbir1 = ProvjeraSabiranja(proizvod1, proizvod2);
        bool proizvod3 = (r1.nazivnik, (r2.nazivnik/r));
    } catch(std::overflow_error) {
        throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    }
    r1.brojnik = (r1.brojnik * (r2.nazivnik/r) - r2.brojnik * (r1.nazivnik/r));
    r1.nazivnik = (r1.nazivnik * (r2.nazivnik/r));
    r1 = Razlomak(r1.brojnik, r1.nazivnik);
        return r1;
}
Razlomak &operator *=(Razlomak &r1, const Razlomak r2) {
    long long int s = Razlomak::NZD(r1.brojnik, r2.nazivnik);
    long long int t = Razlomak::NZD(r2.brojnik, r1.nazivnik);
    try {
        bool proizvod1 = ((r1.brojnik/s) * (r2.brojnik/t));
        bool proizvod2 = ((r1.nazivnik/t) * (r2.nazivnik/s));
    } catch (std::overflow_error) {
        throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    }
    r1.brojnik = (r1.brojnik/s) * (r2.brojnik/t);
    r1.nazivnik = (r1.nazivnik/t) * (r2.nazivnik/s);
    r1 = Razlomak(r1.brojnik, r1.nazivnik);
    return r1;
}
Razlomak &operator /=(Razlomak &r1, const Razlomak r2) {
    long long int r = Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    long long int u = Razlomak::NZD(r1.brojnik, r2.brojnik);
    try {
        bool proizvod1 = ((r1.brojnik/u) * (r2.nazivnik/r));
        bool proizvod2 = ((r1.nazivnik/r) * (r2.brojnik/u));
    } catch(std::overflow_error) {
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    r1.brojnik = (r1.brojnik/u) * (r2.nazivnik/r);
    r1.nazivnik = (r1.nazivnik/r) * (r2.brojnik/u);
    r1 = Razlomak(r1.brojnik, r1.nazivnik);
    return r1;
}
bool operator <(const Razlomak &r1, const Razlomak &r2) {
    long double kolicnik1(r1.brojnik/r1.nazivnik);
    long double kolicnik2(r2.brojnik/r2.nazivnik);
    return kolicnik1 < kolicnik2;
}
bool operator >(const Razlomak &r1, const Razlomak &r2) {
    long double kolicnik1(r1.brojnik/r1.nazivnik);
    long double kolicnik2(r2.brojnik/r2.nazivnik);
    return kolicnik1 > kolicnik2;
}
bool operator <=(const Razlomak &r1, const Razlomak &r2) {
    long double kolicnik1(r1.brojnik/r1.nazivnik);
    long double kolicnik2(r2.brojnik/r2.nazivnik);
    return kolicnik1 <= kolicnik2;
}
bool operator >=(const Razlomak &r1, const Razlomak &r2) {
    long double kolicnik1(r1.brojnik/r1.nazivnik);
    long double kolicnik2(r2.brojnik/r2.nazivnik);
    return kolicnik1 >= kolicnik2;
}
inline Razlomak operator ++(Razlomak &r, int) {
    Razlomak r1(1,1);
    r += r1;
    return r;
}
Razlomak::operator long double() const {
    return (brojnik*(1.))/nazivnik;
}

int main () {
    try {
    Razlomak r1, r2;
        std::cout << "Unesite dva razlomka: ";
    std::cin >> r1 >> r2;
    std::cout << r1 + r2 <<" " << r1 - r2 << std::endl;
    std::cout << r1 * r2 << " " << r1 / r2 << std::endl;
    std::cout << +r1 << " " << -r1 << std::endl;
    std::cout << ++r1 <<" "<< r1++ << " "<< r2++ << " "<< ++r2 << std::endl;
    }catch (std::overflow_error e) {
        std::cout << e.what();
    }
   	return 0;
}