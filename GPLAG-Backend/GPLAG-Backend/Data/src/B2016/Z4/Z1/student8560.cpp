#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>
#include <iomanip>
#include <string>
typedef std::pair<double, double> Tacka;
const double PI(4. * std::atan(1));
const double eps(1e-10);
class Trougao {
    Tacka tacka1, tacka2, tacka3;
    static bool IstaTacka(const Tacka &t1, const Tacka &t2);
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3) == 0) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::tacka1 = t1;
        Trougao::tacka2 = t2;
        Trougao::tacka3 = t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        Trougao::tacka1 = t1;
        Trougao::tacka2 = t2;
        Trougao::tacka3 = t3;
    }
    void Postavi(int indeks, const Tacka &t) {
        if(indeks < 1 || indeks > 3) throw std::range_error ("Nekorektan indeks");
        if(indeks == 1 && (Orijentacija(t, tacka2, tacka3)) == 0)
            throw std::domain_error ("Nekorektne pozicije tjemena");
        if(indeks == 2 && (Orijentacija(tacka1, t, tacka3) == 0))
            throw std::domain_error ("Nekorektne pozicije tjemena");
        if(indeks == 3 && Orijentacija(tacka1, tacka2, t) == 0)
            throw std::domain_error ("Nekorektne pozicije tjemena");
        if(indeks == 1) tacka1 = t;
        if(indeks == 2) tacka2 = t;
        if(indeks == 3) tacka3 = t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        auto pom(t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second));
        if (std::fabs(pom) > 0 && pom > 0) return 1;
        if(std::fabs(pom) > 0 && pom < 0) return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const {
        if(indeks < 1 || indeks > 3) throw std::range_error ("Nekorektan indeks");
        if(indeks == 1) return tacka1;
        if(indeks == 2) return tacka2;
        if(indeks == 3) return tacka3;
    }
    double DajStranicu(int indeks) const {
        if(indeks < 1 || indeks > 3) throw std::range_error ("Nekorektan indeks");
        if(indeks == 1) return sqrt((tacka2.first - tacka3.first) * (tacka2.first - tacka3.first) + (tacka2.second - tacka3.second) * (tacka2.second - tacka3.second));
        if(indeks == 2) return sqrt((tacka1.first - tacka3.first) * (tacka1.first - tacka3.first) + (tacka1.second - tacka3.second) * (tacka1.second - tacka3.second));
        if(indeks == 3) return sqrt((tacka1.first - tacka2.first) * (tacka1.first - tacka2.first) + (tacka1.second - tacka2.second) * (tacka1.second - tacka2.second));
    }
    double DajUgao(int indeks) const {
        if(indeks < 1 || indeks > 3) throw std::range_error ("Nekorektan indeks");
        double a, b, c;
        a = DajStranicu(1);
        b = DajStranicu(2);
        c = DajStranicu(3);
        if(indeks == 1) return ((4 * std::atan(1))*(std::acos((b * b + c * c - a * a)/(2 * b * c))));
        if(indeks == 2) return ((4 * std::atan(1))*(std::acos((a * a + c * c - b * b)/(2 * a * c))));
        if(indeks == 3) return ((4 * std::atan(1))*(std::acos((a * a + b * b - c * c)/(2 * a * b))));
    }
    Tacka DajCentar() const {
        Tacka teziste;
        teziste.first = (tacka1.first + tacka2.first + tacka3.first)/3.;
        teziste.second = (tacka1.second + tacka2.second + tacka3.second)/3.;
        return teziste;
    }
    double DajObim() const {
        double obim;
        double a = DajStranicu(1);
        double b = DajStranicu(2);
        double c = DajStranicu(3);
        obim = a + b + c;
        return obim;
    }
    double DajPovrsinu() const {
        double povrsina;
        povrsina = (0.5*(std::fabs(tacka1.first*(tacka2.second - tacka3.second) - tacka2.first*(tacka1.second - tacka3.second) + tacka3.first*(tacka1.second - tacka2.second))));
        return povrsina;
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(tacka1, tacka2, tacka3) == 1) return true;
        else return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        if(Orijentacija(tacka1, tacka2, tacka3) == Orijentacija(tacka1, tacka2, t) ==  Orijentacija(tacka2, tacka3, t) == Orijentacija(tacka3, tacka1, t)) return true;
        else return false;
    }
    void Ispisi() const {
        std::cout << "(("<<tacka1.first<<","<<tacka1.second<<"),("<<tacka2.first<<","<<tacka2.second<<"),("<<tacka3.first<<","<<tacka3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y) {
        tacka1.first += delta_x; tacka1.second += delta_y;
        tacka2.first += delta_x; tacka2.second += delta_y;
        tacka3.first += delta_x; tacka3.second += delta_y;
    }
    void Centriraj(const Tacka &t) {
        Tacka teziste;
        teziste.first = (tacka1.first + tacka2.first + tacka3.first)/3.;
        teziste.second = (tacka1.second + tacka2.second + tacka3.second)/3.;
        double deltax = std::fabs(t.first - teziste.first);
        double deltay = std::fabs(t.second - teziste.second);
        tacka1.first += deltax; tacka1.second += deltay;
        tacka2.first += deltax; tacka2.second += deltay;
        tacka3.first += deltax; tacka3.second += deltay;
        teziste.first = t.first;
        teziste.second = t.second;
    }
    void Rotiraj(const Tacka &t, double ugao) {
        auto x1(tacka1.first), x2(tacka2.first), x3(tacka3.first);
        tacka1.first = (t.first + (tacka1.first - t.first) * std::cos(ugao) - (tacka1.second - t.second)* std::sin(ugao));
        tacka1.second = (t.second + (x1 - t.first) * std::sin(ugao) + (tacka1.second - t.second) * std::cos(ugao));
        tacka2.first = (t.first + (tacka2.first - t.first) * std::cos(ugao) - (tacka2.second - t.second) * std::sin(ugao));
        tacka2.second = (t.second + (x2 - t.first) * std::sin(ugao) + (tacka2.second - t.second) * std::cos(ugao));
        tacka3.first = (t.first + (tacka3.first - t.first) * std::cos(ugao) - (tacka3.second - t.second) * std::sin(ugao));
        tacka3.second = (t.second + (x3 - t.first) * std::sin(ugao) + (tacka3.second - t.second) * std::cos(ugao));
    }
    void Skaliraj(const Tacka &t, double faktor) {
        if(std::fabs(faktor) < eps) throw std::domain_error ("Nekorektan faktor skaliranja");
            tacka1.first = (t.first + faktor * (tacka1.first - t.first));
            tacka1.second = (t.second + faktor * (tacka1.second - t.second));
            tacka2.first = (t.first + faktor * (tacka2.first - t.first));
            tacka2.second = (t.second + faktor * (tacka2.second - t.second));
            tacka3.first = (t.first + faktor * (tacka3.first - t.first));
            tacka3.second = (t.second + faktor * (tacka3.second - t.second));
        if(faktor < 0 && std::fabs(faktor) > 0) {
            Rotiraj(PI);
        }
    }
    void Rotiraj(double ugao) {
        auto x1(tacka1.first), x2(tacka2.first), x3(tacka3.first);
        Tacka t;
        t.first = (tacka1.first + tacka2.first + tacka3.first)/3.;
        t.second = (tacka1.second + tacka2.second + tacka3.second)/3.;
        tacka1.first = (t.first + (tacka1.first - t.first) * std::cos(ugao) - (tacka1.second - t.second) * std::sin(ugao));
        tacka1.second = (t.second + (x1 - t.first) * std::sin(ugao) + (tacka1.second - t.second) * std::cos(ugao));
        tacka2.first = (t.first + (tacka2.first - t.first) * std::cos(ugao) - (tacka2.second - t.second) * std::sin(ugao));
        tacka2.second = (t.second + (x2 - t.first) * std::sin(ugao) + (tacka2.second - t.second) * std::cos(ugao));
        tacka3.first = (t.first + (tacka3.first - t.first) * std::cos(ugao) - (tacka3.second - t.second) * std::sin(ugao));
        tacka3.second = (t.second + (x3 - t.first) * std::sin(ugao) + (tacka3.second - t.second) * std::cos(ugao));
        }
    void Skaliraj(double faktor) {
        if(std::fabs(faktor) < eps) throw std::domain_error ("Nekorektan faktor skaliranja");
        Tacka t;
        t.first = (tacka1.first + tacka2.first + tacka3.first)/3.;
        t.second = (tacka1.second + tacka2.second + tacka3.second)/3.;
        tacka1.first = (t.first + faktor * (tacka1.first - t.first));
        tacka1.second = (t.second + faktor * (tacka1.second - t.second));
        tacka2.first = (t.first + faktor * (tacka2.first - t.first));
        tacka2.second = (t.second + faktor * (tacka2.second - t.second));
        tacka3.first = (t.first + faktor * (tacka3.first - t.first));
        tacka3.second = (t.second + faktor * (tacka3.second - t.second));
        if (faktor < 0) Rotiraj(PI);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool Trougao::IstaTacka(const Tacka &t1, const Tacka &t2) {
    if (std::fabs(t1.first - t2.first) < eps && std::fabs(t1.second - t2.second) < eps) return true;
    return false;
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if ((Trougao::IstaTacka(t1.tacka1, t2.tacka1) || Trougao::IstaTacka(t1.tacka1, t2.tacka2) || Trougao::IstaTacka(t1.tacka1, t2.tacka3)) && (Trougao::IstaTacka(t1.tacka2, t2.tacka1) 
    || Trougao::IstaTacka(t1.tacka2, t2.tacka2) || Trougao::IstaTacka(t1.tacka2, t2.tacka3)) && (Trougao::IstaTacka(t1.tacka3, t2.tacka1) || Trougao::IstaTacka(t1.tacka3, t2.tacka2)
    || Trougao::IstaTacka(t1.tacka3, t2.tacka3))) return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    if (!((std::fabs(t1.DajStranicu(1) - t2.DajStranicu(1)) < eps || std::fabs(t1.DajStranicu(1) - t2.DajStranicu(2)) < eps || std::fabs(t1.DajStranicu(1) - t2.DajStranicu(3)) < eps) &&
    (std::fabs(t1.DajStranicu(2) - t2.DajStranicu(1)) < eps || std::fabs(t1.DajStranicu(2) - t2.DajStranicu(2)) < eps || std::fabs(t1.DajStranicu(2) - t2.DajStranicu(3)) < eps) &&
    (std::fabs(t1.DajStranicu(3) - t2.DajStranicu(1)) < eps || std::fabs(t1.DajStranicu(3) - t2.DajStranicu(2)) < eps || std::fabs(t1.DajStranicu(3) - t2.DajStranicu(3)) < eps))) return false;
    std::vector<std::pair<double, Tacka>> v1, v2;
    v1.push_back(std::make_pair(t1.DajStranicu(1), t1.DajTjeme(1)));
    v1.push_back(std::make_pair(t1.DajStranicu(2), t1.DajTjeme(2)));
    v1.push_back(std::make_pair(t1.DajStranicu(3), t1.DajTjeme(3)));
    v2.push_back(std::make_pair(t2.DajStranicu(1), t2.DajTjeme(1)));
    v2.push_back(std::make_pair(t2.DajStranicu(2), t2.DajTjeme(2)));
    v2.push_back(std::make_pair(t2.DajStranicu(3), t2.DajTjeme(3)));
    std::sort(v1.begin(), v1.end(), [](std::pair<double, Tacka> a, std::pair<double, Tacka> b) {
        return a.first < b.first;
    });
    std::sort(v2.begin(), v2.end(), [](std::pair<double, Tacka> a, std::pair<double, Tacka> b) {
        return a.first < b.first;
    });
    int or_1(Trougao::Orijentacija(v1[0].second, v1[1].second, v1[2].second));
    int or_2(Trougao::Orijentacija(v2[0].second, v2[1].second, v2[2].second));
    if (or_1 == or_2) return true;
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    double a1, b1, c1, a2, b2, c2;
    a1 = t1.DajUgao(1);
    a2 = t2.DajUgao(1);
    b1 = t1.DajUgao(2);
    b2 = t2.DajUgao(2);
    c1 = t1.DajUgao(3);
    c2 = t2.DajUgao(3);
    if (!((std::fabs(a1 - a2) < eps || std::fabs(a1 - b2) < eps || std::fabs(a1 - c2) < eps) && (std::fabs(b1 - a2) < eps || std::fabs(b1 - b2) < eps || std::fabs(b1 - c2) < eps) && 
    (std::fabs(c1 - a2) < eps || std::fabs(c1 - b2) < eps || std::fabs(c1 - c2) < eps))) return false; 
    std::vector<std::pair<double, Tacka>> v1, v2;
    v1.push_back(std::make_pair(t1.DajUgao(1), t1.DajTjeme(1)));
    v1.push_back(std::make_pair(t1.DajUgao(2), t1.DajTjeme(2)));
    v1.push_back(std::make_pair(t1.DajUgao(3), t1.DajTjeme(3)));
    v2.push_back(std::make_pair(t2.DajUgao(1), t2.DajTjeme(1)));
    v2.push_back(std::make_pair(t2.DajUgao(2), t2.DajTjeme(2)));
    v2.push_back(std::make_pair(t2.DajUgao(3), t2.DajTjeme(3)));
    std::sort(v1.begin(), v1.end(), [](std::pair<double, Tacka> a, std::pair<double, Tacka> b) {
        return a.first < b.first;
    });
    std::sort(v2.begin(), v2.end(), [](std::pair<double, Tacka> a, std::pair<double, Tacka> b) {
        return a.first < b.first;
    });
    int or_1(Trougao::Orijentacija(v1[0].second, v1[1].second, v1[2].second));
    int or_2(Trougao::Orijentacija(v2[0].second, v2[1].second, v2[2].second));
    return or_1 == or_2;
}
int main () {
  int n;
    try {    
        std::cout << "Koliko zelite kreirati trouglova: ";
        std::cin >> n;
        std::vector<std::shared_ptr<Trougao>> vektor(n);
        for(int i(0); i < n; i++) {
            std::cout << "Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            std::vector<double> tjeme;
            for(int j(0); j < 3; j++) {
                double x, y;
                std::cin >> x >> y;
                tjeme.push_back(x);
                tjeme.push_back(y);
            }
            Tacka tacka1, tacka2, tacka3;
            tacka1.first = tjeme[0]; tacka1.second = tjeme[1];
            tacka2.first = tjeme[2]; tacka2.second = tjeme[3];
            tacka3.first = tjeme[4]; tacka3.second = tjeme[5];
            try {
                auto pom = std::make_shared<Trougao>(tacka1, tacka2, tacka3);
                vektor[i] = pom;
            } 
            catch(std::domain_error e) {
                //std::cout << "evo: " << tacka1.first << " " << tacka1.second << " " << tacka2.first << " " << tacka2.second << " " << tacka3.first << " " << tacka3.second << std::endl;
                std::cout << e.what() << ", ponovite unos!" << std::endl;
                i--;
            }
            catch(...) {
                throw;
            }
        }
        std::cout << "Unesite vektor translacije (dx dy): ";
        double deltax, deltay;
        std::cin >> deltax >> deltay;
        std::cout << "Unesite ugao rotacije: ";
        double ugao;
        std::cin >> ugao;
        std::cout << "Unesite faktor skaliranja: ";
        double faktor;
        std::cin >> faktor;
        std::cout << "Trouglovi nakon obavljenih transformacija: " << std::endl;
        std::transform(vektor.begin(), vektor.end(),vektor.begin(), [=] (std::shared_ptr<Trougao> t) {
        t->Transliraj(deltax, deltay);
        t->Rotiraj(ugao);
        t->Skaliraj(t->DajTjeme(1), faktor);
        return t;
    });
        std::sort(vektor.begin(), vektor.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
            return (t1->DajPovrsinu()<t2->DajPovrsinu());
        });
    auto najmanji = (std::min_element(vektor.begin(), vektor.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
        return t1->DajObim()<t2->DajObim();
    }));
    std::for_each(vektor.begin(), vektor.end(), [](std::shared_ptr<Trougao> t) {
        t->Ispisi(); std::cout << std::endl;
    });
    std::cout << "Trougao sa najmanjim obimom: ";
    (*najmanji)->Ispisi();
    std::cout << std::endl;
    int tacno(0);
    for(int i(0); i < vektor.size() - 1; i++) {
        for(int j(i+1); j < vektor.size(); j++) if(DaLiSuIdenticni(*vektor[i], *vektor[j])) {
                if(tacno == 0) std::cout << "Parovi identicnih trouglova:" << std::endl, tacno = 1;
                vektor[i]->Ispisi();
                std::cout << " i ";
                vektor[j]->Ispisi(); std::cout << std::endl;
                }
            }
            if(tacno == 0) std::cout << "Nema identicnih trouglova!" << std::endl;
            tacno = 0;
            for(int i(0); i < vektor.size()-1; i++) {
                for(int j(i+1); j < vektor.size(); j++) if(DaLiSuPodudarni(*vektor[i], *vektor[j])) {
                        if(tacno == 0) std::cout << "Parovi podudarnih trouglova:" << std::endl; 
                        tacno = 1;
                        vektor[i] ->Ispisi();
                        std::cout << " i ";
                        vektor[j]->Ispisi();
                        std::cout << std::endl;
                    }
                }
                if(tacno==0) std::cout << "Nema podudarnih trouglova!" << std::endl;
                tacno = 0;
                for(int i(0); i < vektor.size()-1; i++) {
                    for(int j(i+1); j < vektor.size(); j++) if(DaLiSuSlicni(*vektor[i], *vektor[j])) {
                        if(tacno == 0) std::cout << "Parovi slicnih trouglova:" << std::endl;
                        tacno = 1;
                        vektor[i]->Ispisi();
                        std::cout << " i ";
                        vektor[j]->Ispisi();
                        std::cout << std::endl;
                    }
                    }
                    if(tacno == 0) std::cout << "Nema slicnih trouglova!" << std::endl;
                } catch(std::domain_error e) {
                    std::cout << e.what() << std::endl;
                } catch(std::range_error e) {
                    std::cout << e.what() << std::endl;
                } catch(...) {
                    std::cout << "Nema memorije";
                }
                
    return 0;
}