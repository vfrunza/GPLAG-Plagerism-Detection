#include <iostream>
#include <cmath>
#include <utility>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>

typedef std::pair<double, double> Tacka;

class Trougao {
  Tacka tjemena[3];
  static bool FPJednaki(double x, double y);
  static void TestIndeksa(int indeks);
  static double PomocniIzraz(const Tacka &t1, const Tacka &t2, const Tacka &t3);
  static bool IsteTacke(const Tacka &t1, const Tacka &t2);
public:
  Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
  void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
  void Postavi(int indeks, const Tacka &t);
  static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
  Tacka DajTjeme(int indeks) const;
  double DajStranicu(int indeks) const;
  double DajUgao(int indeks) const;
  Tacka DajCentar() const;
  double DajObim() const;
  double DajPovrsinu() const;
  bool DaLiJePozitivnoOrijentiran() const;
  bool DaLiJeUnutra(const Tacka &t) const;
  void Ispisi() const;
  void Transliraj(double delta_x, double delta_y);
  void Centriraj(const Tacka &t);
  void Rotiraj(const Tacka &t, double ugao);
  void Skaliraj(const Tacka &t, double faktor);
  void Rotiraj(double ugao);
  void Skaliraj(double faktor);
  friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool Trougao::FPJednaki(double x, double y) {
  return std::fabs(x - y) < 1e-10;
}

void Trougao::TestIndeksa(int indeks) {
  if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
}

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
  Postavi(t1, t2, t3);
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
  if(Orijentacija(t1, t2, t3) == 0)
    throw std::domain_error("Nekorektne pozicije tjemena");
  tjemena[0] = t1; tjemena[1] = t2; tjemena[2] = t3;
}

// Tricky: i ova varijanta Postavi može baciti "Nekorektne pozicije tjemena!
void Trougao::Postavi(int indeks, const Tacka &t) {
  TestIndeksa(indeks);
  if(Orijentacija(t, tjemena[indeks % 3], tjemena[(indeks + 1) % 3]) == 0)
    throw std::domain_error("Nekorektne pozicije tjemena");
  tjemena[indeks - 1] = t;
}
double Trougao::PomocniIzraz(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
  return t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second)
    + t3.first * (t1.second - t2.second);
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
  double pomocna(PomocniIzraz(t1, t2, t3));
  return pomocna > 0 ? 1 : pomocna < 0 ? -1 : 0;
}

Tacka Trougao::DajTjeme(int indeks) const {
  TestIndeksa(indeks); return tjemena[indeks - 1];
}

double Trougao::DajStranicu(int indeks) const {
  TestIndeksa(indeks);
  Tacka t1(tjemena[indeks % 3]), t2(tjemena[(indeks + 1) % 3]);
  double dx(t2.first - t1.first), dy(t2.second - t1.second);
  return std::sqrt(dx * dx + dy * dy);
}


double Trougao::DajUgao(int indeks) const {
  TestIndeksa(indeks);
  double c(DajStranicu(indeks)), a(DajStranicu(1 + indeks % 3)),
    b(DajStranicu(1 + (indeks + 1) % 3));
  return std::acos((a * a + b * b - c * c) / (2 * a * b));
}

Tacka Trougao::DajCentar() const {
  return {(tjemena[0].first + tjemena[1].first + tjemena[2].first) / 3,
    (tjemena[0].second + tjemena[1].second + tjemena[2].second) / 3};
}

double Trougao::DajObim() const {
  return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
}

double Trougao::DajPovrsinu() const {
  return std::fabs(PomocniIzraz(tjemena[0], tjemena[1], tjemena[2])) / 2;
}

bool Trougao::DaLiJePozitivnoOrijentiran() const {
  return PomocniIzraz(tjemena[0], tjemena[1], tjemena[2]) > 0;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const {
  int referentna(Orijentacija(tjemena[0], tjemena[1], tjemena[2]));
  for(int i = 0; i < 3; i++)
    if(Orijentacija(tjemena[i], tjemena[(i + 1) % 3], t) != referentna)
      return false;
  return true;
}

void Trougao::Ispisi() const {
  std::cout << "((" << tjemena[0].first << "," << tjemena[0].second
    << "),(" << tjemena[1].first << "," << tjemena[1].second << "),("
    << tjemena[2].first << "," << tjemena[2].second << "))";
}

void Trougao::Transliraj(double delta_x, double delta_y) {
  for(Tacka &tjeme : tjemena) {
    tjeme.first += delta_x; tjeme.second += delta_y;
  }
}

void Trougao::Centriraj(const Tacka &t) {
  Tacka centar(DajCentar());
  Transliraj(t.first - centar.first, t.second - centar.second);
}

void Trougao::Rotiraj(const Tacka &t, double ugao) {
  for(Tacka &tjeme : tjemena) {
    double dx(tjeme.first - t.first), dy(tjeme.second - t.second);
    double pomocna(t.first + dx * std::cos(ugao)- dy * std::sin(ugao));
    tjeme.second = t.second + dx * std::sin(ugao) + dy * std::cos(ugao);
    tjeme.first = pomocna;
  }
}

void Trougao::Skaliraj(const Tacka &t, double faktor) {
  if(faktor == 0)
    throw std::domain_error("Nekorektan faktor skaliranja");
  for(Tacka &tjeme : tjemena) {
    tjeme.first = t.first + faktor * (tjeme.first - t.first);
    tjeme.second = t.second + faktor * (tjeme.second - t.second);
  }
}

void Trougao::Rotiraj(double ugao) {
  Rotiraj(DajCentar(), ugao);
}

void Trougao::Skaliraj(double faktor) {
  Skaliraj(DajCentar(), faktor);
}

bool Trougao::IsteTacke(const Tacka &t1, const Tacka &t2) {
  return FPJednaki(t1.first, t2.first) && FPJednaki(t1.second, t2.second);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
  int perm[6][3]{{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
  for(int i = 0; i < 6; i++) {
    bool test(true);
    for(int j = 0; j < 3; j++)
      if(!Trougao::IsteTacke(t1.tjemena[j], t2.tjemena[perm[i][j]])) test = false;
    if(test) return true;
  }
  return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
  double str1[]{t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)};
  double str2[]{t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
  int perm[6][3]{{0, 1, 2}, {2, 1, 0}, {1, 2, 0}, {0, 2, 1}, {2, 0, 1}, {1, 0, 2}};     // Redoslijed je bitan!
  int start(t1.DaLiJePozitivnoOrijentiran() != t2.DaLiJePozitivnoOrijentiran());
  for(int i = start; i < 6; i += 2) {
    bool test(true);
    for(int j = 0; j < 3; j++)
      if(!Trougao::FPJednaki(str1[j], str2[perm[i][j]])) test = false;
    if(test) return true;
  }
  return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
  double str1[]{t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)};
  double str2[]{t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
  int perm[6][3]{{0, 1, 2}, {2, 1, 0}, {1, 2, 0}, {0, 2, 1}, {2, 0, 1}, {1, 0, 2}};     // Redoslijed je bitan!
  int start(t1.DaLiJePozitivnoOrijentiran() != t2.DaLiJePozitivnoOrijentiran());
  for(int i = start; i < 6; i += 2) {
    double k[3];
    for(int j = 0; j < 3; j++) k[j] = str1[j] / str2[perm[i][j]];
    if(Trougao::FPJednaki(k[0], k[1]) && Trougao::FPJednaki(k[1], k[2])) return true;
  }
  return false;
}

typedef std::shared_ptr<Trougao> TPtr;

// Pomocna funkcija
void TestParova(const std::vector<TPtr> &v,
  bool testfn(const Trougao &, const Trougao &), const char tekst[]) {
    int brojac(0);
    for(int i = 0; i < v.size(); i++)
      for(int j = i + 1; j < v.size(); j++)
        if(testfn(*v[i], *v[j])) {
          brojac++;
          if(brojac == 1) std::cout << "Parovi " << tekst << " trouglova:\n";
          v[i]->Ispisi();
          std::cout << " i ";
          v[j]->Ispisi();
          std::cout << std::endl;
        }
    if(brojac == 0) std::cout << "Nema " << tekst << " trouglova!\n";
}

int main() {
  int n;
  std::cout << "Koliko zelite kreirati trouglova: ";
  std::cin >> n;
  std::vector<TPtr> v(n);
  for(int i = 0; i < n; i++) {
    double x1, y1, x2, y2, x3, y3;
    std::cout << "Unesite podatke za " << i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    try {
      v[i] = std::make_shared<Trougao>(Tacka{x1, y1}, Tacka{x2, y2}, Tacka{x3, y3});
    }
    catch(std::domain_error e) {
      std::cout << e.what() << ", ponovite unos!" << std::endl;
      i--;
    }
  }
  double dx, dy, ugao, faktor;
  std::cout << "Unesite vektor translacije (dx dy): ";
  std::cin >> dx >> dy;
  std::cout << "Unesite ugao rotacije: ";
  std::cin >> ugao;
  std::cout << "Unesite faktor skaliranja: ";
  std::cin >> faktor;
  std::transform(v.begin(), v.end(), v.begin(), [=](TPtr p) {
    p->Transliraj(dx, dy); p->Rotiraj(ugao); p->Skaliraj(p->DajTjeme(1), faktor);
    return p;
  });
  std::sort(v.begin(), v.end(), [](TPtr p1, TPtr p2) {
    return p1->DajPovrsinu() < p2->DajPovrsinu();
  });
  std::cout << "Trouglovi nakon obavljenih transformacija:\n";
  std::for_each(v.begin(), v.end(), [](TPtr p) {
    p->Ispisi(); std::cout << std::endl;
  });
  std::cout << "Trougao sa najmanjim obimom: ";
  (*std::min_element(v.begin(), v.end(), [](TPtr p1, TPtr p2) {
    return p1->DajObim() < p2->DajObim();
  }))->Ispisi();
  std::cout << std::endl;
  TestParova(v, DaLiSuIdenticni, "identicnih");
  TestParova(v, DaLiSuPodudarni, "podudarnih");
  TestParova(v, DaLiSuSlicni, "slicnih");
  return 0;
}

