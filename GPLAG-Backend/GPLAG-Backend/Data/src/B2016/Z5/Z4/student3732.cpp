#include <iostream>
#include <iomanip>
#include <vector>
#include <initializer_list>
#include <stdexcept>

template <typename TipEl>
  class GMatrica {
    int br_redova, br_kolona;
    TipEl elementi[4][4];
  public:
    GMatrica();
    GMatrica(int brr, int brk, TipEl pvrijednost = TipEl());
    template <typename DrugiTip>
      GMatrica(const GMatrica<DrugiTip> &m);
    template <typename DrugiTip>
      GMatrica(DrugiTip m[4][4]);
    GMatrica(const std::vector<std::vector<TipEl>> v);
    GMatrica(std::initializer_list<std::initializer_list<TipEl>> l);
    int DajBrojRedova() const { return br_redova; }
    int DajBrojKolona() const { return br_kolona; }
    template <typename Tip1, typename Tip2>
      friend auto operator +(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
        -> GMatrica<decltype(m1.elementi[0][0] + m2.elementi[0][0])>;
    template <typename Tip1, typename Tip2>
      friend auto operator -(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
        -> GMatrica<decltype(m1.elementi[0][0] - m2.elementi[0][0])>;
    template <typename Tip1, typename Tip2>
      friend auto operator *(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
        -> GMatrica<decltype(m1.elementi[0][0] * m2.elementi[0][0])>;
    template <typename Tip1, typename Tip2>
      friend auto operator *(const GMatrica<Tip1> &m, Tip2 broj)
        -> GMatrica<decltype(m.elementi[0][0] * broj)>;
    template <typename Tip1, typename Tip2>
      friend auto operator *(Tip1 broj, const GMatrica<Tip2> &m)
        -> GMatrica<decltype(m.elementi[0][0] * broj)>;
    template <typename Tip2>
      GMatrica &operator +=(const GMatrica<Tip2> &m);
    template <typename Tip2>
      GMatrica &operator -=(const GMatrica<Tip2> &m);
    template <typename Tip2>
      GMatrica &operator *=(const GMatrica<Tip2> &m);
    template <typename Tip2>
      GMatrica &operator *=(Tip2 broj);
    template <typename Tip1, typename Tip2>
      friend bool operator ==(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);
    template <typename Tip1, typename Tip2>
      friend bool operator !=(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);
    TipEl *operator[](int i) { return elementi[i]; }
    const TipEl *operator[](int i) const { return elementi[i]; }
    TipEl &operator()(int i, int j);
    TipEl operator()(int i, int j) const;
    template <typename Tip2>
      friend std::istream &operator >>(std::istream &tok, GMatrica<Tip2> &m);
    template <typename Tip2>
      friend std::ostream &operator <<(std::ostream &tok, const GMatrica<Tip2> &m);
    template <typename DrugiTip>
      friend class GMatrica;
  };

template <typename TipEl>
  GMatrica<TipEl>::GMatrica() : br_redova(0), br_kolona(0) {}

template <typename TipEl>
  GMatrica<TipEl>::GMatrica(int brr, int brk, TipEl pvrijednost) :
    br_redova(brr), br_kolona(brk) {
      if(brr < 0 || brr > 4 || brk < 0 || brk > 4)
        throw std::logic_error("Ilegalan format matrice");
      for(int i = 0; i < brr; i++)
        for(int j = 0; j < brk; j++) elementi[i][j] = pvrijednost;
  }

template <typename TipEl>
  template <typename DrugiTip>
    GMatrica<TipEl>::GMatrica(const GMatrica<DrugiTip> &m) :
      br_redova(m.br_redova), br_kolona(m.br_kolona) {
        for(int i = 0; i < br_redova; i++)
          for(int j = 0; j < br_kolona; j++) elementi[i][j] = m.elementi[i][j];
    }

template <typename TipEl>
  template <typename DrugiTip>
    GMatrica<TipEl>::GMatrica(DrugiTip m[4][4]) : br_redova(4), br_kolona(4) {
      for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++) elementi[i][j] = m[i][j];
    }

template <typename TipEl>
  GMatrica<TipEl>::GMatrica(const std::vector<std::vector<TipEl>> v) :
    br_redova(v.size()), br_kolona(0) {
      if(br_redova != 0) br_kolona = v[0].size();
      if(br_redova > 4 || br_kolona > 4)
        throw std::logic_error("Ilegalan format matrice");
      for(int i = 0; i < br_redova; i++) {
        if(v[i].size != br_kolona)
          throw std::logic_error("Ilegalan format matrice");
        for(int j = 0; j < br_kolona; j++) elementi[i][j] = v[i][j];
      }
  }

template <typename TipEl>
  GMatrica<TipEl>::GMatrica(std::initializer_list<std::initializer_list<TipEl>> l) :
    br_redova(l.size()), br_kolona(0) {
      if(br_redova != 0) br_kolona = l.begin()[0].size();
      if(br_redova > 4 || br_kolona > 4)
        throw std::logic_error("Ilegalan format matrice");
      for(int i = 0; i < br_redova; i++) {
        if(l.begin()[i].size() != br_kolona)
          throw std::logic_error("Ilegalan format matrice");
        for(int j = 0; j < br_kolona; j++)
          elementi[i][j] = l.begin()[i].begin()[j];
      }
  }

template <typename Tip1, typename Tip2>
  auto operator +(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
    -> GMatrica<decltype(m1.elementi[0][0] + m2.elementi[0][0])> {
      if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Nedozvoljena operacija");
      GMatrica<decltype(m1.elementi[0][0] + m2.elementi[0][0])>
        m3(m1.br_redova, m1.br_kolona);
      for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
          m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
      return m3;
  }

template <typename Tip1, typename Tip2>
  auto operator -(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
    -> GMatrica<decltype(m1.elementi[0][0] - m2.elementi[0][0])> {
      if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Nedozvoljena operacija");
      GMatrica<decltype(m1.elementi[0][0] + m2.elementi[0][0])>
        m3(m1.br_redova, m1.br_kolona);
      for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
          m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
      return m3;
  }

template <typename Tip1, typename Tip2>
  auto operator *(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
    -> GMatrica<decltype(m1.elementi[0][0] * m2.elementi[0][0])> {
      if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Nedozvoljena operacija");
      GMatrica<decltype(m1.elementi[0][0] + m2.elementi[0][0])>
        m3(m1.br_redova, m2.br_kolona);
      for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m2.br_kolona; j++) {
          m3.elementi[i][j] = 0;
          for(int k = 0; k < m1.br_kolona; k++)
            m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
        }
      return m3;
  }

template <typename Tip1, typename Tip2>
  auto operator *(const GMatrica<Tip1> &m, Tip2 broj)
    -> GMatrica<decltype(m.elementi[0][0] * broj)> {
      GMatrica<decltype(m.elementi[0][0] * broj)> m2(m.br_redova, m.br_kolona);
      for(int i = 0; i < m.br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++)
          m2.elementi[i][j] = m.elementi[i][j] * broj;
      return m2;
  }

template <typename Tip1, typename Tip2>
  auto operator *(Tip1 broj, const GMatrica<Tip2> &m)
    -> GMatrica<decltype(m.elementi[0][0] * broj)> {
      return m * broj;
  }

template <typename TipEl>
  template <typename Tip2>
    GMatrica<TipEl> &GMatrica<TipEl>::operator +=(const GMatrica<Tip2> &m) {
      if(br_redova != m.br_redova || br_kolona != m.br_kolona)
        throw std::domain_error("Nedozvoljena operacija");
      for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
          elementi[i][j] += m.elementi[i][j];
      return *this;
    }

template <typename TipEl>
  template <typename Tip2>
    GMatrica<TipEl> &GMatrica<TipEl>::operator -=(const GMatrica<Tip2> &m) {
      if(br_redova != m.br_redova || br_kolona != m.br_kolona)
        throw std::domain_error("Nedozvoljena operacija");
      for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
          elementi[i][j] -= m.elementi[i][j];
      return *this;
    }

template <typename TipEl>
  template <typename Tip2>
    GMatrica<TipEl> &GMatrica<TipEl>::operator *=(const GMatrica<Tip2> &m) {
      if(br_kolona != m.br_redova)
        throw std::domain_error("Nedozvoljena operacija");
      GMatrica<TipEl> m1(*this);
      for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++) {
          elementi[i][j] = 0;
          for(int k = 0; k < br_kolona; k++)
            elementi[i][j] += m1.elementi[i][k] * m.elementi[k][j];
        }
      return *this;
    }

template <typename TipEl>
  template <typename Tip2>
    GMatrica<TipEl> &GMatrica<TipEl>::operator *=(Tip2 broj) {
      for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
          elementi[i][j] *= broj;
      return *this;
    }

template <typename Tip1, typename Tip2>
  bool operator ==(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
      return false;
    for(int i = 0; i < m1.br_redova; i++)
      for(int j = 0; j < m1.br_kolona; j++)
        if(m1[i][j] != m2[i][j]) return false;
    return true;
  }

template <typename Tip1, typename Tip2>
  bool operator !=(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) {
    return !(m1 == m2);
  }

template <typename TipEl>
  TipEl &GMatrica<TipEl>::operator()(int i, int j) {
    if(i < 1 || i > br_redova || j < 1 || j > br_kolona)
      throw std::range_error("Nedozvoljen indeks");
    return elementi[i - 1][j - 1];
  }

template <typename TipEl>
  TipEl GMatrica<TipEl>::operator()(int i, int j) const {
    if(i < 1 || i > br_redova || j < 1 || j > br_kolona)
      throw std::range_error("Nedozvoljen indeks");
    return elementi[i - 1][j - 1];
  }

template <typename TipEl>
  std::istream &operator >>(std::istream &tok, GMatrica<TipEl> &m) {
    char znak;
    tok >> znak;
    if(znak != '[') tok.setstate(std::ios::failbit);
    for(int i = 0; i < m.br_redova; i++) {
      for(int j = 0; j < m.br_kolona; j++) {
        tok >> m.elementi[i][j];
        if(j != m.br_kolona - 1) {
          tok >> znak;
          if(znak != ',') tok.setstate(std::ios::failbit);
        }
      }
      if(i != m.br_redova - 1) {
        tok >> znak;
        if(znak != ';') tok.setstate(std::ios::failbit);
      }
    }
    tok >> znak;
    if(znak != ']') tok.setstate(std::ios::failbit);
    return tok;
  }

template <typename TipEl>
  std::ostream &operator <<(std::ostream &tok, const GMatrica<TipEl> &m) {
    int sirina_ispisa(tok.width());
    if(sirina_ispisa < 6) sirina_ispisa = 6;
    for(int i = 0; i < m.br_redova; i++) {
      for(int j = 0; j < m.br_kolona; j++)
        std::cout << std::setw(sirina_ispisa) << m.elementi[i][j];
      std::cout << std::endl;
    }
    return tok;
  }

class Fudo {
public:
  operator GMatrica<int>() { return GMatrica<int>{{1, 1}, {1, 1}}; }
};

#define TestirajIzuzetak(izuzetak, tijelo) \
  try tijelo catch(izuzetak e) { std::cout << e.what() << std::endl; }


int main(){
//AT25
  GMatrica<int> a(3,3);
  std::cin >> a;
  std::cout << std::setw(3) << a <<std::endl;
  std::cout << std::setw(12) << a << std::endl;
  
  
 

  
}


int _main() {
{
  GMatrica<int> m1;
  std::cout << m1.DajBrojRedova() << " " << m1.DajBrojKolona() << std::endl;
  GMatrica<int> m2(2, 3);
  std::cout << m2 << std::endl;
  std::cout << m2.DajBrojRedova() << " " << m2.DajBrojKolona() << std::endl;
  GMatrica<int> m3(2, 3, 10);
  std::cout << m3 << std::endl;
  TestirajIzuzetak(std::logic_error, { GMatrica<int> m(1, 5); });
  TestirajIzuzetak(std::logic_error, { GMatrica<int> m(5, 1); });
  TestirajIzuzetak(std::logic_error, { GMatrica<int> m(1, -1); });
  TestirajIzuzetak(std::logic_error, { GMatrica<int> m(-1, 1); });
  
  
  GMatrica<double> m4(m3);
  std::cout << m4 << std::endl;
  m4 = m3;                          // Test radi li dodjela izmedju razlicitih tipova
  std::cout << m4 << std::endl;
  
  
  int cmat[4][4]{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, 1, 2}, {3, 4, 5, 6}};
  GMatrica<int> m5(cmat);
  std::cout << m5 << std::endl;
  GMatrica<double> m6(cmat);
  std::cout << m6 << std::endl;
  GMatrica<int> m7({{1, 2, 3}, {4, 5, 6}});
  std::cout << m7 << std::endl;
  
  
  TestirajIzuzetak(std::logic_error, {
    GMatrica<int> m({{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}});
  });
  TestirajIzuzetak(std::logic_error, {
    GMatrica<int> m({{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}});
  });
  TestirajIzuzetak(std::logic_error, {
    GMatrica<int> m({{1}, {1, 2}});
  });

  
  
  GMatrica<int> m8({});                 // Rubni slucaj: matrica 0x0
  std::cout << m8 << std::endl;
  std::cout << m8.DajBrojRedova() << " " << m8.DajBrojKolona() << std::endl;
  GMatrica<int> m9({{}, {}});           // Rubni slucaj: matrica 2x0
  std::cout << m9 << std::endl;
  std::cout << m9.DajBrojRedova() << " " << m9.DajBrojKolona() << std::endl;
  
  
  GMatrica<int> m10{{1, 2, 3}, {4, 5, 6}};
  std::cout << m10 << std::endl;
  try {                                                    // Zbog nekog razloga, makro TestirajIzuzetak
    GMatrica<int> m{{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};     // ovdje nece da radi...
  }
  catch(std::logic_error e) {
    std::cout << e.what() << std::endl;
  }
  try {
    GMatrica<int> m{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  }
  catch(std::logic_error e) {
    std::cout << e.what() << std::endl;
  }
  try {
    GMatrica<int> m{{1}, {1, 2}};
  }
  catch(std::logic_error e) {
    std::cout << e.what() << std::endl;
  }
  



  GMatrica<int> m11({});               // Rubni slucaj: matrica 0x0
  std::cout << m11 << std::endl;
  std::cout << m11.DajBrojRedova() << " " << m11.DajBrojKolona() << std::endl;
  GMatrica<int> m12{{}, {}};           // Rubni slucaj: matrica 2x0
  std::cout << m12 << std::endl;
  std::cout << m12.DajBrojRedova() << " " << m12.DajBrojKolona() << std::endl;
  m12 = {{1, 2}, {3, 4}};              // I ovo treba da radi...
  std::cout << m12 << std::endl;
}
  // Većina dalje stvari ocekuje da sekvencijski konstruktor radi dobro... da li tako raditi
  // u autotestovima, ili ne, ne znam... Ili se možda osloniti na konstruktor za vektor


  GMatrica<int> a{{1, 2}, {3, 4}}, b{{5, 7}, {8, 6}};
  GMatrica<int> c{{1, 2, 3}, {4, 5, 6}}, d{{1, 2}, {3, 4}, {5, 6}};

  std::cout << a + b << std::endl;
  std::cout << a - b << std::endl;
  std::cout << a * b << std::endl;
  std::cout << b * a << std::endl;
  //std::cout << a * 3 << std::endl;
  //std::cout << 3 * a << std::endl;
  //std::cout << a * 3.5 << std::endl;                // Razliciti tipovi
 // std::cout << 3.5 * a << std::endl;
  std::cout << c * d << std::endl;
  std::cout << d * c << std::endl;
  GMatrica<double> e{{1.2, 3.4}, {5.6, 7.8}};
  std::cout << a + e << std::endl;                  // Razliciti tipovi
  std::cout << a - e << std::endl;
  std::cout << a * e << std::endl;
  std::cout << a * e << std::endl;
  
  
  TestirajIzuzetak(std::domain_error, { a + c; });  // Možda dodati još koju varijantu neslaganja formata
  TestirajIzuzetak(std::domain_error, { a - c; });
  TestirajIzuzetak(std::domain_error, { c * a; });
  
  
  GMatrica<int> a1(a), a2(a), a3(a), a4(a), a5(a), a6(a), a7(a), a8(a);
  GMatrica<double> e1(e), e2(e), e3(e), e4(e);
  a1 += b;
  a2 -= b;
  a3 *= b;
  a4 *= 3;
  std::cout << a1 << std::endl;
  std::cout << a2 << std::endl;
  std::cout << a3 << std::endl;
  std::cout << a4 << std::endl;
  a5 += e;                              // Mora biti sasjeceno na int...
  a6 -= e;
  a7 *= e;
  a8 *= 3.5;
  std::cout << a5 << std::endl;
  std::cout << a6 << std::endl;
  std::cout << a7 << std::endl;
  std::cout << a8 << std::endl;
  e1 += a;                              // Ali ovdje ne...
  e2 -= a;
  e3 *= a;
  e4 *= 3;
  std::cout << e1 << std::endl;
  std::cout << e2 << std::endl;
  std::cout << e3 << std::endl;
  std::cout << e4 << std::endl;
  
  
  TestirajIzuzetak(std::domain_error, { a += c; });  // Možda dodati još koju varijantu neslaganja formata
  TestirajIzuzetak(std::domain_error, { a -= c; });
  TestirajIzuzetak(std::domain_error, { c *= a; });
  std::cout << std::boolalpha;
  std::cout << (a == a) << " " << (a == b) << " " << (a == c) << std::endl;
  std::cout << (a != a) << " " << (a != b) << " " << (a != c) << std::endl;
  std::cout << (a == e) << " " << (a != e) << std::endl;                        // Razliciti tipovi
  GMatrica<double> adouble(a);
  std::cout << (a == adouble) << " " << (a != adouble) << std::endl;            // Razliciti tipovi, jednaki sadrzaji

  // Još malo testova operatora () i [] uključujući test izuzetaka...
  // Obavezno testirati radi li a(1, 1) = ... i a[1][1] = ...
  //   i napraviti jednu const kopiju, tipa const GMatrica<int> aa;
  //   pa vidjeti rade li () i [] sa tom kopijom

}

