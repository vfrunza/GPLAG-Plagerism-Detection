/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
typedef std::pair<double, double> Tacka;

class Trougao {
private:
    Tacka tjeme[3];
    bool DaLiJeTrougaoMoguc(const Tacka & t1, const Tacka & t2, const Tacka & t3);
    bool DaLiJeTrougaoMoguc(int indeks, const Tacka & t);
    double DuzinaStranica(const Tacka & t1, const Tacka & t2) const;
    static std::pair<int, int> OstaliIndeksi(int index);
    static double Hannah(const Tacka & t1, const Tacka & t2, const Tacka & t3);
    static void IspisiTacku(Tacka t) {
        std::cout << "(" << t.first << "," << t.second << ")";
    }
    static const double EPSILON;
    static bool fpJednako(double f1, double f2) {
        return std::fabs(f1 - f2) < EPSILON;
    }
    bool DaLiJeTackaTjeme(const Tacka & t) const;
public:
    Trougao(const Tacka & t1, const Tacka & t2, const Tacka & t3) {
        Postavi(t1, t2, t3);
    }
    void Postavi(const Tacka & t1, const Tacka & t2, const Tacka & t3);
    void Postavi(int indeks, const Tacka & t);
    static int Orijentacija(const Tacka & t1, const Tacka & t2, const Tacka & t3);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const {
        return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
    }
    double DajPovrsinu() const {
        return std::fabs(Hannah(tjeme[0], tjeme[1], tjeme[2])) / 2;
    }
    bool DaLiJePozitivnoOrijentiran() const {
        return Orijentacija(tjeme[0], tjeme[1], tjeme[2]) == 1;
    }
    bool DaLiJeUnutra(const Tacka & t) const;
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka & t);
    void Rotiraj(const Tacka & t, double ugao);
    void Skaliraj(const Tacka & t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao & t1, const Trougao & t2);
    friend bool DaLiSuPodudarni(const Trougao & t1, const Trougao & t2);
    friend bool DaLiSuSlicni(const Trougao & t1, const Trougao & t2);
};

void Trougao::Postavi(const Tacka & t1, const Tacka & t2, const Tacka & t3) {
    if(!DaLiJeTrougaoMoguc(t1, t2, t3)) throw std::domain_error("Nekorektne pozicije tjemena");
    tjeme[0] = t1;
    tjeme[1] = t2;
    tjeme[2] = t3;
}
void Trougao::Postavi(int indeks, const Tacka & t) {
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    if(!DaLiJeTrougaoMoguc(indeks, t)) throw std::domain_error("Nekorektne pozicije tjemena");
    tjeme[indeks - 1] = t;
}
int Trougao::Orijentacija(const Tacka & t1, const Tacka & t2, const Tacka & t3) {
    //
    //-1 u smjeru kazaljke na satu
    // 1 u smjeru suprotnom od kazaljke na satu
    // 0 ukoliko su na istom pravcu
    //
    double orijen(Hannah(t1, t2, t3));
    if(orijen < 0) {
        return -1;
    } else if(orijen > 0) {
        return 1;
    }
    return 0;
}
bool Trougao::DaLiJeTrougaoMoguc(const Tacka & t1, const Tacka & t2, const Tacka & t3) {
    return (Orijentacija(t1, t2, t3) != 0);
}
bool Trougao::DaLiJeTrougaoMoguc(int indeks, const Tacka & t) {
    std::pair<int, int> indexi (OstaliIndeksi(indeks));
    return DaLiJeTrougaoMoguc(tjeme[indexi.first], tjeme[indexi.second], t);
}
Tacka Trougao::DajTjeme(int indeks) const {
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    return tjeme[indeks - 1];
}
double Trougao::DajStranicu(int indeks) const {
    std::pair<int, int> indexi (OstaliIndeksi(indeks));
    return DuzinaStranica(tjeme[indexi.first], tjeme[indexi.second]);
}
double Trougao::DuzinaStranica(const Tacka & t1, const Tacka & t2) const {
    return std::fabs(std::sqrt((t1.first - t2.first) * (t1.first - t2.first) + (t1.second - t2.second) * (t1.second - t2.second)));
}
double Trougao::DajUgao(int indeks) const {
    std::pair<int, int> indexi (OstaliIndeksi(indeks));
    return std::acos((DajStranicu(indexi.first)*DajStranicu(indexi.first) + DajStranicu(indexi.second)*DajStranicu(indexi.second) - DajStranicu(indeks)*DajStranicu(indeks)) / 2*DajStranicu(indexi.first)*DajStranicu(indexi.second));
}
std::pair<int, int> Trougao::OstaliIndeksi(int index) {
    switch(index) {
    case 1:
        return {1, 2};
    case 2:
        return {0, 2};
    case 3:
        return {0, 1};
    default:
        throw std::range_error("Nekorektan indeks");
    }

}
Tacka Trougao::DajCentar() const {
    Tacka teziste {0, 0};
    for(int i = 0; i < 3; i++) {
        teziste.first += tjeme[i].first;
        teziste.second += tjeme[i].second;
    }
    teziste.first /= 3;
    teziste.second /= 3;
    return teziste;
}
double Trougao::Hannah(const Tacka & t1, const Tacka & t2, const Tacka & t3) {
    return t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second);
}
bool Trougao::DaLiJeUnutra(const Tacka & t) const {
    bool b1, b2, b3;
    b1 = Orijentacija(t, tjeme[0], tjeme[1]) < 0.0f;
    b2 = Orijentacija(t, tjeme[1], tjeme[2]) < 0.0f;
    b3 = Orijentacija(t, tjeme[2], tjeme[0]) < 0.0f;
    return ((b1 == b2) && (b2 == b3));
}
void Trougao::Ispisi() const {
    std::cout << "(";
    IspisiTacku(tjeme[0]);
    std::cout << ",";
    IspisiTacku(tjeme[1]);
    std::cout << ",";
    IspisiTacku(tjeme[2]);
    std::cout << ")";
}
void Trougao::Transliraj(double delta_x, double delta_y) {
    for(int i = 0; i < 3; i++) {
        tjeme[i].first += delta_x;
        tjeme[i].second += delta_y;
    }
}
void Trougao::Centriraj(const Tacka & t) {
    Tacka centar(DajCentar());
    Transliraj(t.first - centar.first, t.second - centar.second);
}
void Trougao::Rotiraj(const Tacka & t, double ugao) {
    for(int i = 0; i < 3; i++) {
        tjeme[i].first = t.first + (tjeme[i].first - t.first) * std::cos(ugao) - (t.second - tjeme[i].second) * std::sin(ugao);
        tjeme[i].second = t.second + (tjeme[i].first - t.first) * std::sin(ugao) + (t.second - tjeme[i].second) * std::cos(ugao);
    }
}
void Trougao::Rotiraj(double ugao) {
    Rotiraj(DajCentar(), ugao);
}
void Trougao::Skaliraj(const Tacka & t, double faktor) {
    if(fpJednako(faktor, 0.0)) throw std::domain_error("Nekorektan faktor skaliranja");
    for(int i = 0; i < 3; i++) {
        tjeme[i].first = t.first + faktor * (tjeme[i].first - t.first);
        tjeme[i].second = t.second + faktor * (tjeme[i]. second - t.second);
    }
}
void Trougao::Skaliraj(double faktor) {
    Skaliraj(DajCentar(), faktor);
}
const double Trougao::EPSILON = 0.00001;
bool DaLiSuIdenticni(const Trougao & t1, const Trougao & t2) {
    for(int i = 0; i < 3; i++){
        if(!t1.DaLiJeTackaTjeme(t2.tjeme[i])) return false;
    }
    return true;
}
bool Trougao::DaLiJeTackaTjeme(const Tacka & t) const {
    for(int i = 0; i < 3; i++) {
        if(fpJednako(tjeme[i].first, t.first) && fpJednako(tjeme[i].second, t.second)) return true;
    }
    return false;
}







int main () {
    std::cout << Trougao::Orijentacija({1,1}, {3,3}, {2,2});
    return 0;
}
