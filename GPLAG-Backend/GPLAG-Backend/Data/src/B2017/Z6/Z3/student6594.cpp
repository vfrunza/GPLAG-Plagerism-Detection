/* 
   B16/17 (Tutorijal 12, Zadatak 6)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <fstream>
#include <vector>

template <typename TipEl> class Matrica {
  int br_redova = 0, br_kolona = 0;
  TipEl** elementi = nullptr;
  char ime_matrice;
  static TipEl** AlocirajMemoriju(int br_redova, int br_kolona);
  static void DealocirajMemoriju(TipEl** elementi, int br_redova);
  void KopirajElemente(TipEl** elementi);

public:
  
  Matrica(const char* dat, bool t)
  {
    if (t)
      ObnoviIzBinarneDatoteke(dat);
    else
      ObnoviIzTekstualneDatoteke(dat);
  }
  
  Matrica(int br_redova, int br_kolona, char ime = 0);
  Matrica(const Matrica& m);
  Matrica& operator=(const Matrica& m);
  Matrica(Matrica&& m);
  Matrica& operator=(Matrica&& m);

  ~Matrica() { DealocirajMemoriju(elementi, br_redova); }

  TipEl* operator[](int i) { return elementi[i]; }

  const TipEl* operator[](int i) const { return elementi[i]; }

  TipEl& operator()(int r, int k)
  {
    if (r < 1 || r > br_redova || k < 1 || k > br_kolona)
      throw std::range_error("Neispravan indeks");
    return elementi[r - 1][k - 1];
  }

  TipEl operator()(int r, int k) const
  {
    if (r < 1 || r > br_redova || k < 1 || k > br_kolona)
      throw std::range_error("Neispravan indeks");
    return elementi[r - 1][k - 1];
  }
  template <typename _Ty1, typename _Ty2>
  friend auto operator*=(Matrica<_Ty1>& g, const Matrica<_Ty2>& m)
      -> Matrica<decltype(g[0][0] * m[0][0])>;

  template <typename _Ty1, typename _Ty2>
  friend auto operator+=(Matrica<_Ty1>& g, const Matrica<_Ty2>& m)
      -> Matrica<decltype(g[0][0] + m[0][0])>;

  template <typename _Ty1, typename _Ty2>
  friend auto operator*=(Matrica<_Ty1>& g, const _Ty2& m)
      -> Matrica<decltype(g[0][0] * m)>;

  template <typename _Ty1, typename _Ty2>
  friend auto operator-=(Matrica<_Ty1>& g, const Matrica<_Ty2>& m)
      -> Matrica<decltype(g[0][0] - m[0][0])>;

  template <typename _Ty>
  friend std::ostream& operator<<(std::ostream& os, const Matrica<_Ty>& m);

  template <typename _Ty1, typename _Ty2>
  friend auto operator-=(Matrica<_Ty1>& g, const Matrica<_Ty2>& m)
      -> Matrica<decltype(g[0][0] - m[0][0])>;

  template <typename _Ty>
  friend std::istream& operator>>(std::istream& is, Matrica<_Ty>& m1);

  operator std::string() const;

  void SacuvajUTekstualnuDatoteku(const char* dat) const;
  void ObnoviIzTekstualneDatoteke(const char* dat);

  void SacuvajUBinarnuDatoteku(const char* dat) const;
  void ObnoviIzBinarneDatoteke(const char* dat);

};


template <typename TipEl>
void Matrica<TipEl>::ObnoviIzBinarneDatoteke(const char* dat)
{
  std::ifstream tok(dat, std::ios::binary | std::ios::in);
  if (!tok)
    throw std::logic_error("Trazena datoteka ne postoji");
  auto p = 0U;
  int bk, br;
  tok.read(reinterpret_cast<char*>(&br), sizeof(int));
  if (!tok.good())
    throw std::logic_error("Datoteka sadrzi besmislene podatke");
  p += sizeof(int);
  tok.seekg(p);
  tok.read(reinterpret_cast<char*>(&bk), sizeof(int));
  if (!tok.good())
    throw std::logic_error("Datoteka sadrzi besmislene podatke");
  p += sizeof(int);
  auto vel_el = sizeof(TipEl);
  Matrica<TipEl> m(br, bk);
  for (int i = 0; i < br; i++)
    for (int j = 0; j < bk; ++j) {
      tok.read(reinterpret_cast<char*>(&m[i][j]), sizeof(TipEl));
      if (!tok.good())
        throw std::logic_error("Datoteka sadrzi besmislene podatke");
      p += vel_el;
      tok.seekg(p);
    }
  *this = std::move(m);
}

template <typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(const char* dat) const
{
  std::ofstream tok(dat, std::ios::binary | std::ios::out);
  if (!tok)
    throw std::logic_error("Trazena datoteka ne postoji");
  auto p = 0U;
  tok.write(reinterpret_cast<const char*>(&br_redova), sizeof(int));
  if (!tok.good())
    throw std::logic_error("Datoteka sadrzi besmislene podatke");
  p += sizeof(int);
  tok.seekp(p);
  tok.write(reinterpret_cast<const char*>(&br_kolona), sizeof(int));
  if (!tok.good())
    throw std::logic_error("Datoteka sadrzi besmislene podatke");
  p += sizeof(int);
  auto vel_el = sizeof(TipEl);
  for (int i = 0; i < br_redova; i++)
    for (int j = 0; j < br_kolona; ++j) {
      tok.write(reinterpret_cast<char*>(&elementi[i][j]), sizeof(TipEl));
      if (!tok.good())
        throw std::logic_error("Datoteka sadrzi besmislene podatke");
      p += vel_el;
      tok.seekp(p);
    }
}

template <typename TipEl>
void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(const char* dat)
{
  std::ifstream tok(dat);
  if (!tok)
    throw std::logic_error("Trazena datoteka ne postoji");
  std::vector<std::vector<TipEl>> m;
  std::vector<TipEl> v;
  while (15) {
    double x;
    tok >> x;
    v.push_back(x);
    if (tok.peek() == ',')
      tok.ignore();
    else if (tok.peek() == '\n') {
      m.push_back(v);
      v.resize(0);
    } else if (tok.eof()) {
      m.push_back(v);
      v.resize(0);
      break;
    }

    if (!tok.good())
      throw std::logic_error("Datoteka sadrzi besmislene podatke");
  }
  if (m.size() == 0)
    return;
  DealocirajMemoriju(elementi, br_redova);
  elementi = AlocirajMemoriju(m.size(), m[0].size());
  br_kolona = m[0].size();
  br_redova = m.size();
  for (int i = 0; i < m.size(); i++)
    for (int j = 0; j < m[0].size(); ++j)
      elementi[i][j] = m[i][j];
}

template <typename TipEl>
void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(const char* dat) const
{
  std::ofstream tok(dat);
  if (!tok)
    throw std::logic_error("Trazena datoteka ne postoji");
  for (int i(0); i < br_redova; i++) {
    for (int j(0); j < br_kolona; j++) {
      tok << elementi[i][j];
      if (j != br_kolona - 1)
        tok << ",";
      if (!tok.good())
        throw std::logic_error("Problemi sa upisom u datoteku");
    }
    if (i != br_redova - 1)
      tok << "\n";
    if (!tok.good())
      throw std::logic_error("Problemi sa upisom u datoteku");
  }
}


template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl** elementi, int br_redova)
{
  if (elementi == nullptr || br_redova == 0)
    return;
  for (int i = 0; i < br_redova; i++)
    delete[] elementi[i];
  delete[] elementi;
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime)
    : br_redova(br_redova), br_kolona(br_kolona),
      elementi(AlocirajMemoriju(br_redova, br_kolona)), ime_matrice(ime)
{
}

template <typename TipEl> void Matrica<TipEl>::KopirajElemente(TipEl** elementi)
{
  for (int i = 0; i < br_redova; i++)
    for (int j = 0; j < br_kolona; j++)
      Matrica::elementi[i][j] = elementi[i][j];
}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl>& m)
    : br_redova(m.br_redova), br_kolona(m.br_kolona),
      elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)),
      ime_matrice(m.ime_matrice)
{
  KopirajElemente(m.elementi);
}
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl>&& m)
    : br_redova(m.br_redova), br_kolona(m.br_kolona), elementi(m.elementi),
      ime_matrice(m.ime_matrice)
{
  m.br_redova = 0;
  m.elementi = nullptr;
}

template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator=(const Matrica<TipEl>& m)
{
  if (br_redova < m.br_redova || br_kolona < m.br_kolona) {
    TipEl** novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
    DealocirajMemoriju(elementi, br_redova);
    elementi = novi_prostor;
  } else if (br_redova > m.br_redova)
    for (int i = m.br_redova; i < br_redova; i++)
      delete elementi[i];
  br_redova = m.br_redova;
  br_kolona = m.br_kolona;
  ime_matrice = m.ime_matrice;
  KopirajElemente(m.elementi);
  return *this;
}
template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator=(Matrica<TipEl>&& m)
{
  std::swap(br_redova, m.br_redova);
  std::swap(br_kolona, m.br_kolona);
  std::swap(ime_matrice, m.ime_matrice);
  std::swap(elementi, m.elementi);
  return *this;
}

template <typename TipEl>
TipEl** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
  TipEl** elementi(new TipEl* [br_redova] {});
  try {
    for (int i = 0; i < br_redova; i++)
      elementi[i] = new TipEl[br_kolona];
  } catch (...) {
    DealocirajMemoriju(elementi, br_redova);
    throw;
  }
  return elementi;
}

template <typename _Ty1, typename _Ty2>
auto operator+=(Matrica<_Ty1>& g, const Matrica<_Ty2>& m)
    -> Matrica<decltype(g[0][0] + m[0][0])>
{
  if (g.br_kolona != m.br_kolona || g.br_redova != m.br_redova)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
  for (int i = 0; i < g.br_redova; ++i)
    for (int j = 0; j < g.br_kolona; ++j)
      g[i][j] += m[i][j];
  return g;
}

template <typename _Ty1, typename _Ty2>
auto operator-=(Matrica<_Ty1>& g, const Matrica<_Ty2>& m)
    -> Matrica<decltype(g[0][0] - m[0][0])>
{
  if (g.br_kolona != m.br_kolona || g.br_redova != m.br_redova)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
  for (int i = 0; i < g.br_redova; ++i)
    for (int j = 0; j < g.br_kolona; ++j)
      g[i][j] -= m[i][j];
  return g;
}

template <typename _Ty1, typename _Ty2>
auto operator+(const Matrica<_Ty1>& g, const Matrica<_Ty2>& m)
    -> Matrica<decltype(g[0][0] + m[0][0])>
{
  auto p = g;
  p += m;
  return p;
}

template <typename _Ty1, typename _Ty2>
auto operator-(const Matrica<_Ty1>& g, const Matrica<_Ty2>& m)
    -> Matrica<decltype(g[0][0] - m[0][0])>
{
  auto p = g;
  p -= m;
  return p;
}

template <typename _Ty>
std::istream& operator>>(std::istream& is, Matrica<_Ty>& m1)
{
  for (int i = 0; i < m1.br_redova; ++i)
    for (int j = 0; j < m1.br_kolona; ++j) {
      std::cout << m1.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
      is >> m1[i][j];
    }
  return is;
}

template <typename _Ty>
std::ostream& operator<<(std::ostream& os, const Matrica<_Ty>& m)
{
  auto sirina = os.width();

  for (int i(0); i < m.br_redova; i++) {
    for (int j(0); j < m.br_kolona; j++)
      os << std::setw(sirina) << m[i][j];
    os << "\n";
  }
  return os;
}

template <typename _Ty1, typename _Ty2>
auto operator*=(Matrica<_Ty1>& g, const Matrica<_Ty2>& m)
    -> Matrica<decltype(g[0][0] * m[0][0])>
{
  if (g.br_kolona != m.br_redova)
    throw std::domain_error("Matrice nisu saglasne za mnozenje");
  auto p = g;
  g.br_kolona = m.br_kolona;
  for (int i = 0; i < p.br_redova; ++i) {
    for (int j = 0; j < m.br_kolona; ++j) {
      _Ty1 s{};
      for (int k = 0; k < p.br_kolona; ++k)
        s += p[i][k] * m[k][j];
      g[i][j] = s;
    }
  }
  return g;
}

template <typename _Ty1, typename _Ty2>
auto operator*=(Matrica<_Ty1>& g, const _Ty2& m)
    -> Matrica<decltype(g[0][0] * m)>
{
  for (int i = 0; i < g.br_redova; ++i)
    for (int j = 0; j < g.br_kolona; ++j)
      g[i][j] *= m;
  return g;
}

template <typename _Ty1, typename _Ty2>
auto operator*(const Matrica<_Ty1>& g, const Matrica<_Ty2>& m)
    -> Matrica<decltype(g[0][0] * m[0][0])>
{
  auto p = g;
  p *= m;
  return p;
}

template <typename _Ty1, typename _Ty2>
auto operator*(const Matrica<_Ty1>& g, const _Ty2& m)
    -> Matrica<decltype(g[0][0] * m)>
{
  auto p = g;
  p *= m;
  return p;
}

template <typename _Ty1, typename _Ty2>
auto operator*(const _Ty2& m, const Matrica<_Ty1>& g)
    -> Matrica<decltype(m * g[0][0])>
{
  auto p = g;
  p *= m;
  return p;
}

template <typename _Ty1> Matrica<_Ty1>::operator std::string() const
{
  std::string s = "{";
  for (int i(0); i < br_redova; i++) {
    s += "{";
    for (int j(0); j < br_kolona; j++) {
      if (elementi[i][j] - int(elementi[i][j]) == 0)
        s += std::to_string(int(elementi[i][j]));
      else
        s += std::to_string(elementi[i][j]);
      if (j != br_kolona - 1)
        s += ",";
    }
    s += "}";
    if (i != br_redova - 1)
      s += ",";
  }
  s += "}";
  return s;
}
int main(){
  
}
// Rad sa datotekama je testiran javnim AT-ovima da se ja ne peglam
     int m,n;
  std::cout << "Unesi broj redova i kolona za matrice:\n";
  std::cin >> m >> n;
  try {
    Matrica<double> a(m, n, 'A'), b(m, n, 'B');
    std::cout << "Unesi matricu A:\n";
    std::cin >> a;
    std::cout << "Unesi matricu B:\n";
    std::cin >> b;
	a*=b;
	std::cout << a <<"\n";
	a+=b;
	std::cout << a <<"\n";
	a-=b;
	std::cout << a <<"\n";
	std::cout <<  b + a <<"\n";
b*=10;
std::cout <<  b - a <<"\n";

std::cout << b * b << "\n";

std::cout << std::string(b*4) << "\n";

std::cout << std::string(4*b) << "\n";

for(int i = 0; i < 2; i++){
      for(int j = 0; j < 2; j++)
      std::cout << a[i][j] << " ";
      std::cout << std::endl;
}

for(int i = 0; i < 2; i++){
      for(int j = 0; j < 2; j++)
      std::cout << b[i][j] << " ";
      std::cout << std::endl;
}
}
catch(std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!\n";
  }
    catch(std::domain_error e) {
    std::cout << e.what();
  }
    catch(std::range_error e) {
    std::cout << e.what();
  }
  
	return 0;
}