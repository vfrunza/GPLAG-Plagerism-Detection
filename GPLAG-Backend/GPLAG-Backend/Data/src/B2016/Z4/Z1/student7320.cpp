/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>

typedef std::pair<double, double> Tacka;
#define ff first
#define ss second
#define pb push_back

bool Isti(double a, double b, double eps = 1E-10) {
  return fabs(a - b) < eps;
}
class Trougao {
  Tacka x[3]{};
  
  static double DajVrijednost(Tacka x0, Tacka x1, Tacka x2) {
    return x0.ff*(x1.ss - x2.ss) + x1.ff*(x2.ss - x0.ss) + x2.ff*(x0.ss - x1.ss);
  }
public:
  Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    Postavi(t1, t2, t3);
  }
  void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double val = DajVrijednost(t1, t2, t3);
    if (Isti(val, 0.)) throw std::domain_error("Nekorektne pozicije tjemena");
    x[0].ff = t1.ff; x[0].ss = t1.ss;
    x[1].ff = t2.ff; x[1].ss = t2.ss;
    x[2].ff = t3.ff; x[2].ss = t3.ss;
  }
  void Postavi(int indeks, const Tacka &t) {
    if (!(indeks >= 1 && indeks <= 3)) throw std::range_error("Nekorektan indeks");
    x[indeks - 1] = t;
  }
  static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double val = DajVrijednost(t1, t2, t3);
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
  }
  Tacka DajTjeme(int indeks) const { return x[indeks - 1]; }
  double DajStranicu(int indeks) const {
    int i1, i2; i1 = i2 = 0;
    if (indeks == 1) { i1 = 1; i2 = 2; }
    if (indeks == 2) { i1 = 0; i2 = 2; }
    if (indeks == 3) { i1 = 0; i1 = 1; }
    double val1 = x[i1].ss - x[i2].ss;
    double val2 = x[i1].ff - x[i2].ff;
    return sqrt(val1 * val1 + val2 * val2);
  };
  double DajUgao(int indeks) const {
    int i1, i2;
    if (indeks == 1) { i1 = 1; i2 = 2; }
    if (indeks == 2) { i1 = 0; i2 = 2; }
    if (indeks == 3) { i1 = 0; i2 = 1; }
    
    double a, b, c;
    a = DajStranicu(indeks);
    b = DajStranicu(i1 + 1);
    c = DajStranicu(i2 + 1);
    double cosval = (a * a - b * b - c * c) / (-2. * b * c);
    return acos(cosval);
  };
  Tacka DajCentar() const {
    return Tacka((x[0].ff + x[1].ff + x[2].ff) / 3., (x[0].ss + x[1].ss + x[2].ss) / 3.);
  };
  double DajObim() const { 
    double a = DajStranicu(1);
    double b = DajStranicu(2);
    double c = DajStranicu(3);
    return a + b + c;
  }
  double DajPovrsinu() const {
    return 0.5 * fabs( x[0].ff * (x[1].ss - x[2].ss) + x[1].ff * (x[2].ss - x[0].ss) + x[2].ff * (x[0].ss - x[1].ss));
    //return 0.5 * fabs(DajVrijednost(x[0], x[1], x[2]));
  };
  bool DaLiJePozitivnoOrijentiran() const {
    return !!Orijentacija(x[0],x[1],x[2]);
  };
  bool DaLiJeUnutra(const Tacka &t) const { 
    int P1 = Orijentacija(x[0], x[1], x[2]);
    int P2 = Orijentacija(x[0], x[1], t);
    int P3 = Orijentacija(x[0], x[2], t);
    int P4 = Orijentacija(x[1], x[2], t);
    //std::cout << P1 << " " << P2 << " " << P3 << " " << P4 << "\n";
    if (P4 > 0) return (P1 < 0 && P2 < 0 && P3 < 0);
    else return (P1 > 0 && P2 > 0 && P3 > 0);
  };
  void Ispisi() const { std::cout << "((" << x[0].ff << "," << x[0].ss << "),(" << x[1].ff << "," << x[1].ss << "),(" << x[2].ff << "," << x[2].ss << "))"; }
  void Transliraj(double delta_x, double delta_y) {
    x[0].ff += delta_x; x[0].ss += delta_y;
    x[1].ff += delta_x; x[1].ss += delta_y;
    x[2].ff += delta_x; x[2].ss += delta_y;
  }
  void Centriraj(const Tacka &t) {
    double dx, dy;
    dx = 3. * t.ff - ((x[0].ff + x[1].ff + x[2].ff) / 3.);
    dy = 3. * t.ss - ((x[0].ss + x[1].ss + x[2].ss) / 3.);
    for (int i = 0; i < 3; i++) x[i].ff += dx, x[i].ss += dy;
  }
  void Rotiraj(const Tacka &t, double ugao) {
    for (int i = 0; i < 3; i++) {
      //x[i] = Tacka(t.ff + (x[i].ff - t.ff) * cos(ugao) - (x[i].ss - t.ss) * sin(ugao), t.ss + (x[i].ff - t.ff) * sin(ugao) - (x[i].ss - t.ss) * cos(ugao));
      x[i].ff = (t.ff + (x[i].ff - t.ff) * cos(ugao) - (x[i].ss - t.ss) * sin(ugao));
      x[i].ss = (t.ss + (x[i].ff - t.ff) * sin(ugao) + (x[i].ss - t.ss) * cos(ugao));
    }
  }
  void Skaliraj(const Tacka &t, double faktor) {
    if (Isti(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
    for (int i = 0; i < 3; i++) {
      x[i].ff = t.ff + faktor * (x[i].ff - t.ff);
      x[i].ss = t.ss + faktor * (x[i].ss - t.ss);
    }
  }
  void Rotiraj(double ugao) {
    Tacka p = DajCentar();
    Rotiraj(p, ugao);
  }
  void Skaliraj(double faktor) {
    Tacka p = DajCentar();
    Skaliraj(p, faktor);
  }
  friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool cmp1(std::pair<double, double> A, std::pair<double, double> B) {
  if (Isti(A.ff, B.ff)) return A.ss < B.ss;
  return A.ff < B.ff;
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
  std::vector<Tacka> o1, o2; 
  for (int i = 0; i < 3; i++) o1.pb(t1.x[i]), o2.pb(t2.x[i]); 
  std::sort(o1.begin(), o1.end(), cmp1);
  std::sort(o2.begin(), o2.end(), cmp1);
  for (int i = 0; i < 3; i++) 
    if (!Isti(o1[i].ff, o2[i].ff) || !Isti(o1[i].ss, o2[i].ss)) return 0;
  return 1;
}
double UdaljenostTacaka(const Tacka &T1, const Tacka &T2) {
  double dx = T2.ff - T1.ff;
  double dy = T2.ss - T1.ss;
  return sqrt(dx * dx + dy * dy);
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
  Tacka T1, T2, T3;
  T1 = t1.DajTjeme(1); T2 = t1.DajTjeme(2); T3 = t1.DajTjeme(3);
  Tacka Q1, Q2, Q3;
  Q1 = t2.DajTjeme(1); Q2 = t2.DajTjeme(2); Q3 = t2.DajTjeme(3);
  int Or1 = Trougao::Orijentacija(T1, T2, T3);
  int Or2 = Trougao::Orijentacija(Q1, Q2, Q3);
  int Or3 = Trougao::Orijentacija(Q1, Q3, Q2);
  int Or4 = Trougao::Orijentacija(Q2, Q1, Q3);
  int Or5 = Trougao::Orijentacija(Q2, Q3, Q1);
  int Or6 = Trougao::Orijentacija(Q3, Q2, Q1);
  int Or7 = Trougao::Orijentacija(Q3, Q1, Q2);
  bool zaVratiti = 0;
  if (Or1 == Or2) {
    zaVratiti = (Isti(UdaljenostTacaka(T1, T2), UdaljenostTacaka(Q1, Q2)) && Isti(UdaljenostTacaka(T2, T3), UdaljenostTacaka(Q2, Q3)) && Isti(UdaljenostTacaka(T3, T1), UdaljenostTacaka(Q3, Q1)));
    if (zaVratiti) return 1;
  }
  if (Or1 == Or3) {
    zaVratiti = (Isti(UdaljenostTacaka(T1, T2), UdaljenostTacaka(Q1, Q3)) && Isti(UdaljenostTacaka(T2, T3), UdaljenostTacaka(Q3, Q2)) && Isti(UdaljenostTacaka(T3, T1), UdaljenostTacaka(Q2, Q1)));
    if (zaVratiti) return 1;
  }
  if (Or1 == Or4) {
    zaVratiti = (Isti(UdaljenostTacaka(T1, T2), UdaljenostTacaka(Q2, Q1)) && Isti(UdaljenostTacaka(T2, T3), UdaljenostTacaka(Q1, Q3)) && Isti(UdaljenostTacaka(T3, T1), UdaljenostTacaka(Q3, Q2)));
    if (zaVratiti) return 1;
  }
  if (Or1 == Or5) {
    zaVratiti = (Isti(UdaljenostTacaka(T1, T2), UdaljenostTacaka(Q2, Q3)) && Isti(UdaljenostTacaka(T2, T3), UdaljenostTacaka(Q3, Q1)) && Isti(UdaljenostTacaka(T3, T1), UdaljenostTacaka(Q1, Q2)));
    if (zaVratiti) return 1;
  }
  if (Or1 == Or6) {
    zaVratiti = (Isti(UdaljenostTacaka(T1, T2), UdaljenostTacaka(Q3, Q2)) && Isti(UdaljenostTacaka(T2, T3), UdaljenostTacaka(Q2, Q1)) && Isti(UdaljenostTacaka(T3, T1), UdaljenostTacaka(Q1, Q3)));
    if (zaVratiti) return 1;
  }
  if (Or1 == Or7) {
    zaVratiti = (Isti(UdaljenostTacaka(T1, T2), UdaljenostTacaka(Q3, Q1)) && Isti(UdaljenostTacaka(T2, T3), UdaljenostTacaka(Q1, Q2)) && Isti(UdaljenostTacaka(T3, T1), UdaljenostTacaka(Q2, Q3)));
    if (zaVratiti) return 1;
  }
  return zaVratiti;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
  Tacka T1, T2, T3;
  T1 = t1.DajTjeme(1); T2 = t1.DajTjeme(2); T3 = t1.DajTjeme(3);
  Tacka Q1, Q2, Q3;
  Q1 = t2.DajTjeme(1); Q2 = t2.DajTjeme(2); Q3 = t2.DajTjeme(3);
  int Or1 = Trougao::Orijentacija(T1, T2, T3);
  int Or2 = Trougao::Orijentacija(Q1, Q2, Q3);
  int Or3 = Trougao::Orijentacija(Q1, Q3, Q2);
  int Or4 = Trougao::Orijentacija(Q2, Q1, Q3);
  int Or5 = Trougao::Orijentacija(Q2, Q3, Q1);
  int Or6 = Trougao::Orijentacija(Q3, Q2, Q1);
  int Or7 = Trougao::Orijentacija(Q3, Q1, Q2);
  bool zaVratiti = 0;
  if (Or1 == Or2) {
    zaVratiti = (Isti(UdaljenostTacaka(T1, T2) / UdaljenostTacaka(Q1, Q2), UdaljenostTacaka(T2, T3) / UdaljenostTacaka(Q2, Q3)) && Isti(UdaljenostTacaka(T3, T1) / UdaljenostTacaka(Q3, Q1), UdaljenostTacaka(T2, T3) / UdaljenostTacaka(Q2, Q3)));
    if (zaVratiti) return 1;
  }
  if (Or1 == Or3) {
    zaVratiti = (Isti(UdaljenostTacaka(T1, T2) / UdaljenostTacaka(Q1, Q3), UdaljenostTacaka(T2, T3) / UdaljenostTacaka(Q3, Q2)) && Isti(UdaljenostTacaka(T3, T1) / UdaljenostTacaka(Q2, Q1), UdaljenostTacaka(T2, T3) / UdaljenostTacaka(Q3, Q2))); 
    if (zaVratiti) return 1;
  }
  if (Or1 == Or4) {
    zaVratiti = (Isti(UdaljenostTacaka(T1, T2) / UdaljenostTacaka(Q2, Q1), UdaljenostTacaka(T2, T3) / UdaljenostTacaka(Q1, Q3)) && Isti(UdaljenostTacaka(T3, T1) / UdaljenostTacaka(Q3, Q2), UdaljenostTacaka(T2, T3) / UdaljenostTacaka(Q1, Q3))); 
    if (zaVratiti) return 1;
  }
  if (Or1 == Or5) {
    zaVratiti = (Isti(UdaljenostTacaka(T1, T2) / UdaljenostTacaka(Q2, Q3), UdaljenostTacaka(T2, T3) / UdaljenostTacaka(Q3, Q1)) && Isti(UdaljenostTacaka(T3, T1) / UdaljenostTacaka(Q1, Q2), UdaljenostTacaka(T2, T3) / UdaljenostTacaka(Q3, Q1)));
    if (zaVratiti) return 1;
  }
  if (Or1 == Or6) {
    zaVratiti = (Isti(UdaljenostTacaka(T1, T2) / UdaljenostTacaka(Q3, Q2), UdaljenostTacaka(T2, T3) / UdaljenostTacaka(Q2, Q1)) && Isti(UdaljenostTacaka(T3, T1) / UdaljenostTacaka(Q1, Q3), UdaljenostTacaka(T2, T3) / UdaljenostTacaka(Q2, Q1))); 
    if (zaVratiti) return 1;
  }
  if (Or1 == Or7) {
    zaVratiti = (Isti(UdaljenostTacaka(T1, T2) / UdaljenostTacaka(Q3, Q1), UdaljenostTacaka(T2, T3) / UdaljenostTacaka(Q1, Q2)) && Isti(UdaljenostTacaka(T3, T1) / UdaljenostTacaka(Q2, Q3), UdaljenostTacaka(T2, T3) / UdaljenostTacaka(Q1, Q2))); 
    if (zaVratiti) return 1;
  }
  return zaVratiti;
}
int main () {
  int n;
  std::cout << "Koliko zelite kreirati trouglova: "; std::cin >> n;
  std::vector<std::shared_ptr<Trougao> > vect{};
  for (int i = 0; i < n; i++) {
    std::cout << "Unesite podatke za " << i + 1 <<". trougao (x1 y1 x2 y2 x3 y3): ";
    Tacka x0, x1, x2;
    while (1) {
      std::cin >> x0.ff >> x0.ss;
      std::cin >> x1.ff >> x1.ss;
      std::cin >> x2.ff >> x2.ss;
      try {
        Trougao T1 = Trougao(x0, x1, x2);
        break;
      }
      catch (std::domain_error c) {
        std::cout << c.what() << ", ponovite unos!\n";
        std::cout << "Unesite podatke za " << i + 1 <<". trougao (x1 y1 x2 y2 x3 y3): ";
      }
    }
    std::shared_ptr<Trougao> T = std::make_shared<Trougao>(x0, x1, x2);
    vect.push_back(T);
  }
  
  double dx, dy, ugao, faktor;
  std::cout << "Unesite vektor translacije (dx dy): "; std::cin >> dx >> dy;
  std::cout << "Unesite ugao rotacije: "; std::cin >> ugao;
  std::cout << "Unesite faktor skaliranja: "; std::cin >> faktor;
  std::cout << "Trouglovi nakon obavljenih transformacija: \n";
  std::transform(vect.begin(), vect.end(), vect.begin(), [dx, dy](std::shared_ptr<Trougao> A) -> std::shared_ptr<Trougao> {
    A -> Transliraj(dx, dy);
    return A;
  });
  std::transform(vect.begin(), vect.end(), vect.begin(), [ugao](std::shared_ptr<Trougao> A) -> std::shared_ptr<Trougao> {
    A -> Rotiraj(ugao);
    return A;
  });
  std::transform(vect.begin(), vect.end(), vect.begin(), [faktor](std::shared_ptr<Trougao> A) -> std::shared_ptr<Trougao> {
    A -> Skaliraj(A -> DajTjeme(1), faktor);
    return A;
  });
  std::sort(vect.begin(), vect.end(), [](std::shared_ptr<Trougao> A, std::shared_ptr<Trougao> B) -> bool {
    return A -> DajPovrsinu() < B -> DajPovrsinu();
  });
  for_each(vect.begin(), vect.end(), [](std::shared_ptr<Trougao> A) {
    A -> Ispisi(); std::cout << "\n";
  });
  auto mini = std::min_element(vect.begin(), vect.end(), [](std::shared_ptr<Trougao> A, std::shared_ptr<Trougao> B) {
    return A->DajObim() < B->DajObim();
  });
  std::cout << "Trougao sa najmanjim obimom: ";
  int i = 0;
  for (auto x = vect.begin(); x != vect.end(); x++) {
    //std::cout << *x << " " << *mini << "\n";
    if (*x == *mini) {
      vect[i] -> Ispisi();
      break;
    }
    i++;
  }
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;
  
  for (int i = 0; i < vect.size(); i++)
    for (int j = i; j < vect.size(); j++) {
      if (i != j) {
        if (DaLiSuIdenticni(*vect[i], *vect[j])) cnt1++;
        if (DaLiSuPodudarni(*vect[i], *vect[j])) cnt2++;
        if (DaLiSuSlicni(*vect[i], *vect[j])) cnt3++;
      }
    }
  if (cnt1 != 0) {
    std::cout << "\nParovi identicnih trouglova: \n";
    for (int i = 0; i < vect.size(); i++) {
      for (int j = i; j < vect.size(); j++)
        if (i != j && DaLiSuIdenticni(*vect[i], *vect[j])) {
          vect[i] -> Ispisi(); std::cout << " i "; vect[j] -> Ispisi();
          std::cout << "\n";
        }
    }
  } else std::cout << "\nNema identicnih trouglova!\n";
  if (cnt2 != 0) {
    std::cout << "Parovi podudarnih trouglova: \n";
    for (int i = 0; i < vect.size(); i++) {
      for (int j = i; j < vect.size(); j++)
        if (i != j && DaLiSuPodudarni(*vect[i], *vect[j])) {
          vect[i] -> Ispisi(); std::cout << " i "; vect[j] -> Ispisi();
          std::cout << "\n";
        }
    }
  } else std::cout << "Nema podudarnih trouglova!\n";
  if (cnt3 != 0) {
    std::cout << "Parovi slicnih trouglova: \n";
    for (int i = 0; i < vect.size(); i++) {
      for (int j = i; j < vect.size(); j++)
        if (i != j && DaLiSuSlicni(*vect[i], *vect[j])) {
          vect[i] -> Ispisi(); std::cout << " i "; vect[j] -> Ispisi();
          std::cout << "\n";
        }
    }
  } else std::cout << "Nema slicnih trouglova!\n";
	return 0;
}