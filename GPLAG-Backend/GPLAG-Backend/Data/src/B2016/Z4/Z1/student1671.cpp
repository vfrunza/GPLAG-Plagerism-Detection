/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <cmath>
#include <set>
#include <vector>
#include <memory>
#include <algorithm>

static const double PI(4 * atan(1));
static const double EPS(1e-10);
typedef std::pair<double, double> Tacka;
class Trougao {
    Tacka t1, t2, t3;
    static void PostaviNaNulu(double &x) {
        if (std::fabs(x) < EPS) x = 0;
    };
    static bool DaLiSuJednaki(double x, double y);
    static double F(Tacka t1, Tacka t2, Tacka t3);
    void ProvjeriIndeks(int indeks) const;
    static double Duzina(const Tacka &t1, const Tacka &t2);
    static double Kosinusna(double a, double b, double c);
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);//
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);//
    void Postavi(int indeks, const Tacka &t);//
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);//
    Tacka DajTjeme(int indeks) const;//
    double DajStranicu(int indeks) const;//
    double DajUgao(int indeks) const;//
    Tacka DajCentar() const;//
    double DajObim() const;//
    double DajPovrsinu() const;//
    bool DaLiJePozitivnoOrijentiran() const;//
    bool DaLiJeUnutra(const Tacka &t) const;//
    void Ispisi() const;//
    void Transliraj(double delta_x, double delta_y);//
    void Centriraj(const Tacka &t);//
    void Rotiraj(const Tacka &t, double ugao);//
    void Skaliraj(const Tacka &t, double faktor);//
    void Rotiraj(double ugao);//
    void Skaliraj(double faktor);//
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    std::multiset<double> s1, s2;
    s1.insert(t1.DajUgao(1)); s1.insert(t1.DajUgao(2)); s1.insert(t1.DajUgao(3));
    s2.insert(t2.DajUgao(1)); s2.insert(t2.DajUgao(2)); s2.insert(t2.DajUgao(3));
    auto it_1(s1.begin()), it_2(s2.begin());
    while (it_1 != s1.end()) {
        if (!Trougao::DaLiSuJednaki(*it_1, *it_2)) return false;
        it_1++;
        it_2++;
    }
    std::vector<std::pair<double, Tacka>> v1(3), v2(3);
    for (int i = 0; i < 3; i++) {
        v1[i].first = t1.DajUgao(i+1); v1[i].second = t1.DajTjeme(i+1);
        v2[i].first = t2.DajUgao(i+1); v2[i].second = t2.DajTjeme(i+1);
    }
    std::sort(v1.begin(), v1.end(), [](std::pair<double, Tacka> p1, std::pair<double, Tacka> p2) {
        return p1.first > p2.first;
    });
    std::sort(v2.begin(), v2.end(), [](std::pair<double, Tacka> p1, std::pair<double, Tacka> p2) {
        return p1.first > p2.first;
    });
    if (Trougao::Orijentacija(v1[0].second, v1[1].second, v1[2].second) == Trougao::Orijentacija(v2[0].second, v2[1].second, v2[2].second))
        return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    std::multiset<double> s1, s2;
    s1.insert(t1.DajStranicu(1));
    s1.insert(t1.DajStranicu(2));
    s1.insert(t1.DajStranicu(3));
    s2.insert(t2.DajStranicu(1));
    s2.insert(t2.DajStranicu(2));
    s2.insert(t2.DajStranicu(3));
    auto it_1(s1.begin()), it_2(s2.begin());
    while (it_1 != s1.end()) {
        if (!Trougao::DaLiSuJednaki(*it_1, *it_2)) return false;
        it_1++;
        it_2++;
    }
    std::vector<std::pair<double, Tacka>> v1(3), v2(3);
    for (int i = 0; i < 3; i++) {
        v1[i].first = t1.DajStranicu(i+1); v1[i].second = t1.DajTjeme(i+1);
        v2[i].first = t2.DajStranicu(i+1); v2[i].second = t2.DajTjeme(i+1);
    }
    std::sort(v1.begin(), v1.end(), [](std::pair<double, Tacka> p1, std::pair<double, Tacka> p2) {
       return p1.first > p2.first; 
    });
    std::sort(v2.begin(), v2.end(), [](std::pair<double, Tacka> p1, std::pair<double, Tacka> p2) {
        return p1.first > p2.first;
    });
    if (Trougao::Orijentacija(v1[0].second, v1[1].second, v1[2].second) == Trougao::Orijentacija(v2[0].second, v2[1].second, v2[2].second)) 
        return true;
    return false;
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if ((Trougao::DaLiSuJednaki(t1.DajTjeme(1).first, t2.DajTjeme(1).first) && Trougao::DaLiSuJednaki(t1.DajTjeme(1).second, t2.DajTjeme(1).second)) || (Trougao::DaLiSuJednaki(t1.DajTjeme(1).first, t2.DajTjeme(2).first) && Trougao::DaLiSuJednaki(t1.DajTjeme(1).second, t2.DajTjeme(2).second)) || (Trougao::DaLiSuJednaki(t1.DajTjeme(1).first, t2.DajTjeme(3).first) && Trougao::DaLiSuJednaki(t1.DajTjeme(1).second, t2.DajTjeme(3).second)))
        if ((Trougao::DaLiSuJednaki(t1.DajTjeme(2).first, t2.DajTjeme(1).first) && Trougao::DaLiSuJednaki(t1.DajTjeme(2).second, t2.DajTjeme(1).second)) || (Trougao::DaLiSuJednaki(t1.DajTjeme(2).first, t2.DajTjeme(2).first) && Trougao::DaLiSuJednaki(t1.DajTjeme(2).second, t2.DajTjeme(2).second)) || (Trougao::DaLiSuJednaki(t1.DajTjeme(2).first, t2.DajTjeme(3).first) && Trougao::DaLiSuJednaki(t1.DajTjeme(2).second, t2.DajTjeme(3).second)))
            if ((Trougao::DaLiSuJednaki(t1.DajTjeme(3).first, t2.DajTjeme(1).first) && Trougao::DaLiSuJednaki(t1.DajTjeme(3).second, t2.DajTjeme(1).second)) || (Trougao::DaLiSuJednaki(t1.DajTjeme(3).first, t2.DajTjeme(2).first) && Trougao::DaLiSuJednaki(t1.DajTjeme(3).second, t2.DajTjeme(2).second)) || (Trougao::DaLiSuJednaki(t1.DajTjeme(3).first, t2.DajTjeme(3).first) && Trougao::DaLiSuJednaki(t1.DajTjeme(3).second, t2.DajTjeme(3).second)))
                return true;
    return false;
}
void Trougao::Skaliraj(double faktor) {
    Trougao::Skaliraj(this->DajCentar(), faktor);
}
void Trougao::Rotiraj(double ugao) {
    Trougao::Rotiraj(this->DajCentar(), ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if (Trougao::DaLiSuJednaki(faktor, 0)) throw std::domain_error ("Nekorektan faktor skaliranja");
    auto Xc(t.first), Yc(t.second);
    t1.first = Xc + faktor * (t1.first - Xc);
    t2.first = Xc + faktor * (t2.first - Xc);
    t3.first = Xc + faktor * (t3.first - Xc);
    t1.second = Yc + faktor * (t1.second - Yc);
    t2.second = Yc + faktor * (t2.second - Yc);
    t3.second = Yc + faktor * (t3.second - Yc);
    if (faktor < 0) Trougao::Rotiraj(PI);
}
void Trougao::Rotiraj(const Tacka &t, double ugao) {
    auto x1(t1.first), x2(t2.first), x3(t3.first);
    t1.first = t.first + (t1.first - t.first) * cos(ugao) - (t1.second - t.second) * sin(ugao);
    Trougao::PostaviNaNulu(t1.first);
    t2.first = t.first + (t2.first - t.first) * cos(ugao) - (t2.second - t.second) * sin(ugao);
    Trougao::PostaviNaNulu(t2.first);
    t3.first = t.first + (t3.first - t.first) * cos(ugao) - (t3.second - t.second) * sin(ugao);
    Trougao::PostaviNaNulu(t3.first);
    t1.second = t.second + (x1 - t.first) * sin(ugao) + (t1.second - t.second) * cos(ugao);
    Trougao::PostaviNaNulu(t1.second);
    t2.second = t.second + (x2 - t.first) * sin(ugao) + (t2.second - t.second) * cos(ugao);
    Trougao::PostaviNaNulu(t2.second);
    t3.second = t.second + (x3 - t.first) * sin(ugao) + (t3.second - t.second) * cos(ugao);
    Trougao::PostaviNaNulu(t3.second);
}
void Trougao::Centriraj(const Tacka &t) {
    auto x = t.first - DajCentar().first, y = t.second - DajCentar().second;
    t1.first += x;
    t2.first += x;
    t3.first += x;
    t1.second += y;
    t2.second += y;
    t3.second += y;
}
void Trougao::Transliraj(double delta_x, double delta_y) {
    t1.first += delta_x;
    t2.first += delta_x;
    t3.first += delta_x;
    t1.second += delta_y;
    t2.second += delta_y;
    t3.second += delta_y;
}
void Trougao::Ispisi() const {
    std::cout << "((" << t1.first << "," << t1.second << "),(" << t2.first << "," << t2.second << "),(" << t3.first << "," << t3.second << "))";
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    if (!Orijentacija(t1, t2, t3) || !Orijentacija(t1, t2, t) || !Orijentacija(t2, t3, t) || !Orijentacija(t3, t1, t)) return false;
    if (Orijentacija(t1, t2, t3) == Orijentacija(t1, t2, t) == Orijentacija(t2, t3, t) == Orijentacija(t3, t1, t)) return true;
    return false;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const {
    if (Orijentacija(t1, t2, t3) == 1) return true;
    return false;
}
double Trougao::DajPovrsinu() const {
    return std::fabs(Trougao::F(t1, t2, t3)/2);
}
double Trougao::DajObim() const {
    return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
}
Tacka Trougao::DajCentar() const {
    return std::make_pair((t1.first + t2.first + t3.first)/3, (t1.second + t2.second + t3.second)/3);
}
double Trougao::Kosinusna(double a, double b, double c) {
    return acos((b * b + c * c - a * a)/(2 * b * c));
}
double Trougao::DajUgao(int indeks) const {
    ProvjeriIndeks(indeks);
    if (indeks == 1) return Kosinusna(DajStranicu(1), DajStranicu(2), DajStranicu(3));
    if (indeks == 2) return Kosinusna(DajStranicu(2), DajStranicu(3), DajStranicu(1));
    return Kosinusna(DajStranicu(3), DajStranicu(1), DajStranicu(2));
}
double Trougao::DajStranicu(int indeks) const {
    ProvjeriIndeks(indeks);
    if (indeks == 1) return Trougao::Duzina(t2, t3);
    if (indeks == 2) return Trougao::Duzina(t1, t3);
    return Trougao::Duzina(t1, t2);
}
double Trougao::Duzina(const Tacka &t1, const Tacka &t2) {
    return sqrt((t1.first - t2.first) * (t1.first - t2.first) + (t1.second - t2.second) * (t1.second - t2.second));
}
void Trougao::ProvjeriIndeks(int indeks) const {
    if (indeks < 1 || indeks > 3) throw std::range_error ("Nekorektan indeks");
}
Tacka Trougao::DajTjeme(int indeks) const {
    ProvjeriIndeks(indeks);
    if (indeks == 1) return t1;
    if (indeks == 2) return t2;
    return t3;
}
void Trougao::Postavi(int indeks, const Tacka &t) {
    ProvjeriIndeks(indeks);
    if (indeks == 1) {
        if (Trougao::DaLiSuJednaki(Trougao::F(t, t2, t3), 0)) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::Postavi(t, t2, t3);
    }
    else if (indeks == 2) {
        if (Trougao::DaLiSuJednaki(Trougao::F(t1, t, t3), 0)) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::Postavi(t1, t, t3);
    }
    else if (indeks == 3) {
        if (Trougao::DaLiSuJednaki(Trougao::F(t1, t2, t), 0)) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::Postavi(t1, t2, t);
    }
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (Trougao::DaLiSuJednaki(Trougao::F(t1, t2, t3), 0)) throw std::domain_error ("Nekorektne pozicije tjemena");
    Trougao::t1 = t1;
    Trougao::t2 = t2;
    Trougao::t3 = t3;
}
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (Trougao::DaLiSuJednaki(Trougao::F(t1, t2, t3), 0)) throw std::domain_error ("Nekorektne pozicije tjemena");
    Trougao::t1 = t1;
    Trougao::t2 = t2;
    Trougao::t3 = t3;
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (Trougao::DaLiSuJednaki(Trougao::F(t1, t2, t3), 0)) return 0;
    if (Trougao::F(t1, t2, t3) < 0 && !Trougao::DaLiSuJednaki(Trougao::F(t1, t2, t3), 0)) return -1;
    return 1;
}
bool Trougao::DaLiSuJednaki(double x, double y) {
    return std::fabs(x - y) <= EPS * (std::fabs(x) + std::fabs(y));
}
double Trougao::F(Tacka t1, Tacka t2, Tacka t3) {
    return t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second);
}

int main ()
{
    try {
        int n;
        std::cout << "Koliko zelite kreirati trouglova: ";
        std::cin >> n;
        std::vector<std::shared_ptr<Trougao>> v(n);
        for (int i = 0; i < n; i++) {
            bool pogresan_unos(true);
            while (pogresan_unos) {
                std::cout << "Unesite podatke za " << i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
                try {
                    int x1, y1, x2, y2, x3, y3;
                    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
                    v[i] = std::make_shared<Trougao>(Tacka(x1, y1), Tacka(x2, y2), Tacka(x3, y3));
                    pogresan_unos = false;
                }
                catch(std::domain_error izuzetak) {
                    std::cout << izuzetak.what() << ", ponovite unos!" << std::endl;
                }
                catch(std::range_error izuzetak) {
                    std::cout << izuzetak.what() << ", ponovite unos!" << std::endl;
                }
                catch(...) {
                    throw;
                }
            }
        }
        if (true) {
            double dx, dy;
            std::cout << "Unesite vektor translacije (dx dy): ";
            std::cin >> dx >> dy;
            std::transform(v.begin(), v.end(), v.begin(), [dx, dy](std::shared_ptr<Trougao> t) {
            (t->Transliraj(dx, dy));
            return t;
            });
            double ugao;
            std::cout << "Unesite ugao rotacije: ";
            std::cin >> ugao;
            for (int i = 0; i < n; i++) v[i]->Rotiraj(ugao);
            double faktor_skaliranja;
            std::cout << "Unesite faktor skaliranja: ";
            std::cin >> faktor_skaliranja;
            for (int i = 0; i < n; i++) v[i]->Skaliraj(v[i]->DajTjeme(1), faktor_skaliranja);
            std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
                return (t1->DajPovrsinu() < t2->DajPovrsinu());
            });
            std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
            std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t) {
                t->Ispisi();
                std::cout << std::endl;
            });
            std::cout << "Trougao sa najmanjim obimom: ";
            auto najmanji_obim(std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
                return t1->DajObim() < t2->DajObim();
            }));
            if (n) (*najmanji_obim)->Ispisi();
            std::cout << std::endl;
        }
        bool test(false);
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < v.size(); j++) if (DaLiSuIdenticni(*v[i], *v[j])) {
                    if (!test) std::cout << "Parovi identicnih trouglova:" << std::endl, test = true;
                    v[i]->Ispisi();
                    std::cout << " i ";
                    v[j]->Ispisi();
                    std::cout << std::endl;
                }
        }
        if (!test) std::cout << "Nema identicnih trouglova!" << std::endl;
        test = false;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < v.size(); j++) if (DaLiSuPodudarni(*v[i], *v[j])) {
                    if (!test) std::cout << "Parovi podudarnih trouglova:" << std::endl, test = true;
                    v[i]->Ispisi();
                    std::cout << " i ";
                    v[j]->Ispisi();
                    std::cout << std::endl;
                }
        }
        if (!test) std::cout << "Nema podudarnih trouglova!" << std::endl;
        test = false;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < v.size(); j++) if (DaLiSuSlicni(*v[i], *v[j])) {
                    if (!test) std::cout << "Parovi slicnih trouglova:" << std::endl, test = true;
                    v[i]->Ispisi();
                    std::cout << " i ";
                    v[j]->Ispisi();
                    std::cout << std::endl;
                }
        }
        if (!test) std::cout << "Nema slicnih trouglova!" << std::endl;
    }
    catch (std::domain_error tekst) {
        std::cout << tekst.what();
    }
    catch (std::range_error tekst) {
        std::cout << tekst.what();
    }
    catch (...) {
        std::cout << "Nema memorije";
    }

    return 0;
}
