#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka tacke[3];
    static double Stepen(double baza, int stepen);
    static bool Jednaki (double a, double b);
    static double Povrsina(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    static double Udaljenost(const Tacka &t1, const Tacka &t2);
    static Tacka RotirajTacku(const Tacka &t1, const Tacka &t, double ugao);
    static Tacka ZamTacku(const Tacka &t1, const Tacka &t, double faktor);
    static bool JednakostTacaka(const Tacka &t1, const Tacka &t2);
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

double Trougao::Stepen (double baza, int stepen) {
    double proizvod(1);
    for(int i = 0; i < abs(stepen); i++) proizvod *= baza;
    if(stepen < 0) { proizvod = 1. / proizvod; return proizvod; }
    return proizvod;
}

bool Trougao::Jednaki (double a, double b) {
    return fabs(a - b) < 1E-10;
}

double Trougao::Povrsina(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    return 0.5 * fabs(t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second));
}

double Trougao::Udaljenost(const Tacka &t1, const Tacka &t2) {
    return sqrt(Stepen(t1.first - t2.first, 2) + Stepen(t1.second - t2.second, 2));
}

Tacka Trougao::RotirajTacku(const Tacka &t1, const Tacka &t, double ugao) {
    return {t.first + (t1.first - t.first) * cos(ugao) - (t1.second - t.second) * sin(ugao), t.second + (t1.first - t.first) * sin(ugao) - (t1.second - t.second) * cos(ugao)};
}

Tacka Trougao::ZamTacku(const Tacka &t1, const Tacka &t, double faktor) {
    return {t.first + (t1.first - t.first) * faktor, t.second + (t1.second - t.second) * faktor};
}

bool Trougao::JednakostTacaka(const Tacka &t1, const Tacka &t2) { return Jednaki(t1.first, t2.first) && Jednaki(t1.second, t2.second); }

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3); }

inline void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Orijentacija(t1, t2, t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
    tacke[0] = t1; tacke[1] = t2; tacke[2] = t3;
}

inline void Trougao::Postavi(int indeks, const Tacka &t1) {
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    auto pomocna(tacke[indeks - 1]); tacke[indeks - 1] = t1;
    if(Orijentacija(tacke[0], tacke[1], tacke[2]) == 0) { tacke[indeks - 1] = pomocna; throw std::domain_error("Nekorektne pozicije tjemena"); }
}

inline int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double rez(t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second));
    if(rez > 0) return 1; 
    else if(Trougao::Jednaki(rez, 0)) return 0;
    return -1;
}

inline void Trougao::Ispisi() const {
    std::cout << "((" << tacke[0].first << "," << tacke[0].second << "),(" << tacke[1].first << "," << tacke[1].second << "),(" << tacke[2].first << "," << tacke[2].second << "))";
}

inline Tacka Trougao::DajTjeme(int indeks) const { return tacke[indeks - 1]; }

inline double Trougao::DajStranicu(int indeks) const { 
    if(indeks == 1) return sqrt(Stepen(tacke[2].first - tacke[1].first, 2) + Stepen(tacke[2].second - tacke[1].second, 2));
    else if(indeks == 2) return sqrt(Stepen(tacke[2].first - tacke[0].first, 2) + Stepen(tacke[2].second - tacke[0].second, 2));
    return sqrt(Stepen(tacke[0].first - tacke[1].first, 2) + Stepen(tacke[0].second - tacke[1].second, 2)); 
}

inline double Trougao::DajUgao(int indeks) const {
    if(indeks == 1) return acos((Stepen(DajStranicu(1), 2) - Stepen(DajStranicu(2), 2) - Stepen(DajStranicu(3), 2)) / (-2 * DajStranicu(2) * DajStranicu(3)));
    else if(indeks == 2) return acos((Stepen(DajStranicu(2), 2) - Stepen(DajStranicu(1), 2) - Stepen(DajStranicu(3), 2)) / (-2 * DajStranicu(1) * DajStranicu(3)));
    return acos((Stepen(DajStranicu(3), 2) - Stepen(DajStranicu(1), 2) - Stepen(DajStranicu(2), 2)) / (-2 * DajStranicu(1) * DajStranicu(2)));
}

inline Tacka Trougao::DajCentar() const { return std::make_pair((tacke[0].first + tacke[1].first + tacke[2].first) / 3, (tacke[0].second + tacke[1].second + tacke[2].second) / 3); }

inline double Trougao::DajObim() const { return DajStranicu(1) + DajStranicu(2) + DajStranicu(3); }

inline double Trougao::DajPovrsinu() const { return 0.5 * fabs(tacke[0].first * (tacke[1].second - tacke[2].second) - tacke[1].first * (tacke[0].second - tacke[2].second) + tacke[2].first * (tacke[0].second - tacke[1].second)); }

inline bool Trougao::DaLiJePozitivnoOrijentiran() const { return Orijentacija(tacke[0], tacke[1], tacke[2]) > 0; }

inline bool Trougao::DaLiJeUnutra(const Tacka &t) const { return (Povrsina(tacke[0], tacke[1], t) + Povrsina(tacke[0], t, tacke[2]) + Povrsina(t, tacke[1], tacke[2])) <= (*this).DajPovrsinu(); }

inline void Trougao::Transliraj(double delta_x, double delta_y) { tacke[0].first += delta_x; tacke[0].second += delta_y; tacke[1].first += delta_x; tacke[1].second += delta_y; tacke[2].first += delta_x; tacke[2].second += delta_y;}

inline void Trougao::Centriraj(const Tacka &t) { Transliraj(t.first, t.second); }

inline void Trougao::Rotiraj(const Tacka &t, double ugao) { 
    tacke[0] = RotirajTacku(tacke[0], t, ugao); tacke[1] = RotirajTacku(tacke[1], t, ugao); tacke[2] = RotirajTacku(tacke[2], t, ugao);
}

inline void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(Jednaki(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
    tacke[0] = ZamTacku(tacke[0], t, faktor); tacke[1] = ZamTacku(tacke[1], t, faktor); tacke[2] = ZamTacku(tacke[2], t, faktor);
}

inline void Trougao::Rotiraj(double ugao) { Rotiraj((*this).DajCentar(), ugao); }

inline void Trougao::Skaliraj(double faktor) { 
    try {
        Skaliraj((*this).DajCentar(), faktor);
    } catch(std::domain_error izuzetak) { throw izuzetak; } 
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    int brojac(0);
    
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++)
            if(Trougao::JednakostTacaka(t1.DajTjeme(i), t2.DajTjeme(j))) brojac++;
    }
    
    if(brojac == 3) return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    int brojac1(0), brojac2(0);
    
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            if(Trougao::Jednaki(t1.DajStranicu(i), t2.DajStranicu(j))) brojac1++;
            if(Trougao::Jednaki(t1.DajUgao(i), t2.DajUgao(j))) brojac2++;
        }
    }
    
    if(brojac1 > 2 && brojac2 > 2) return true;
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    int brojac(0);
    
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++)
            if(Trougao::Jednaki(t1.DajUgao(i), t2.DajUgao(j))) brojac++;
    }
    
    if(brojac > 2 && Trougao::Jednaki(t1.DajStranicu(1) / t2.DajStranicu(1), t1.DajStranicu(2) / t2.DajStranicu(2)) && Trougao::Jednaki(t1.DajStranicu(1) / t2.DajStranicu(1), t1.DajStranicu(2) / t2.DajStranicu(2))) return true;
    return false;
}

int main() {
    
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n;
    std::cin >> n;
    
    std::vector<std::shared_ptr<Trougao>> v(n);
    for(int i = 0; i < n; i++) {
        std::cout << "Unesite podatke za  " << i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        double x1, x2, x3, y1, y2, y3;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Tacka t1({x1, y1});
        Tacka t2({x2, y2});
        Tacka t3({x3, y3});
        try {
            v[i] = std::make_shared<Trougao>(t1, t2, t3);
        }
        catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            i--;
        }
    }
    
    std::cout << "Unesite vektor translacije (dx dy): ";
    double d_x, d_y;
    std::cin >> d_x >> d_y;
    
    std::cout << "Unesite ugao rotacije: ";
    double ugao;
    std::cin >> ugao;
    
    std::cout << "Unesite faktor skaliranja: ";
    double faktor;
    std::cin >> faktor;
    
    std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
    std::transform(v.begin(), v.end(), v.begin(), [d_x, d_y, ugao, faktor](const std::shared_ptr<Trougao> t1) {
        (*t1).Transliraj(d_x, d_y);
        (*t1).Rotiraj(ugao);
        (*t1).Skaliraj((*t1).DajTjeme(1), faktor);
        return t1;
    });
    
    std::sort(v.begin(), v.end(), [](const std::shared_ptr<Trougao> t1,const std::shared_ptr<Trougao> t2) {return (*t1).DajObim() < (*t2).DajObim();});
    
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t) {
        (*t).Ispisi(); std::cout << std::endl;
    });
    
    std::cout << "Trougao sa najmanjim obimom: ";
    auto pok(std::min_element(v.begin(), v.end(), [](const std::shared_ptr<Trougao> t1,const std::shared_ptr<Trougao> t2) {return (*t1).DajObim() < (*t2).DajObim();}));
    if(n != 0) { (*pok)->Ispisi(); }
    
    return 0;
}