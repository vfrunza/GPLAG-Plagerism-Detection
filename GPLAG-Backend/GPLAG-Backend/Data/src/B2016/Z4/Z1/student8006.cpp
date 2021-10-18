/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <memory>

#define eps 0.000000001

typedef std::pair<double, double> Tacka;

class Trougao {
Tacka tjemena[3];
static double Izraz(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    return (t1.first) * ((t2.second) - (t3.second)) - (t2.first) * ((t1.second) - (t3.second)) + (t3.first) * ((t1.second) - (t2.second));
}
static int Test(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double test = Izraz(t1, t2, t3);

    if(test > 0) return 1;
    if(test < 0) return -1;
    return 0;
}
void TestirajFaktor(double &faktor) {
    if(std::fabs(faktor - 0.) < eps) throw std::domain_error("Nekorektan faktor skaliranja");
}
void TestirajIndeks(int &indeks) const {
    if(indeks <= 1 && indeks >= 3) throw std::range_error("Nekorektan indeks");
}
double DuzinaStranice(const Tacka &t1, const Tacka &t2) const {
    return sqrt((t1.first - t2.first) * (t1.first - t2.first) - (t1.second - t2.second) * (t1.second - t2.second));
}
double Ugao(double a, double b, double c) const {
    return std::acos((a * a + b * b + c * c) / 2 * a * b);
}
public:
Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    Postavi(t1, t2, t3);
}
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Orijentacija(t1, t2, t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
    
    tjemena[0] = t1;
    tjemena[1] = t2;
    tjemena[2] = t3;
}
void Postavi(int indeks, const Tacka &t) {
    TestirajIndeks(indeks);
    tjemena[indeks] = t;
}
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    return Test(t1, t2, t3);
}
Tacka DajTjeme(int indeks) const {
    TestirajIndeks(indeks);
    return tjemena[indeks];
}
double DajStranicu(int indeks) const {
    TestirajIndeks(indeks);
    if(indeks == 1) return DuzinaStranice(tjemena[1], tjemena[2]);
    if(indeks == 2) return DuzinaStranice(tjemena[0], tjemena[2]);
    return DuzinaStranice(tjemena[0], tjemena[1]);
}
double DajUgao(int indeks) const {
    TestirajIndeks(indeks);
    if(indeks == 0) return Ugao(DajStranicu(1), DajStranicu(2), DajStranicu(0));
    if(indeks == 1) return Ugao(DajStranicu(2), DajStranicu(0), DajStranicu(1));
    return Ugao(DajStranicu(0), DajStranicu(1), DajStranicu(2));
}
Tacka DajCentar() const {
    double x = (tjemena[0].first + tjemena[1].first + tjemena[2].first) / 3;
    double y = (tjemena[0].second + tjemena[1].second + tjemena[2].second) / 3;
    return std::make_pair(x, y);
}
double DajObim() const {
    return DajStranicu(0) + DajStranicu(1) + DajStranicu(2);
}
double DajPovrsinu() const {
    return fabs(Izraz(tjemena[0], tjemena[1], tjemena[2])) / 2;
}
bool DaLiJePozitivnoOrijentiran() const {
    if(Orijentacija(tjemena[0], tjemena[1], tjemena[2]) == 1) return true;
    return false;
}
bool DaLiJeUnutra(const Tacka &t) const {
    int a = Orijentacija(tjemena[0], tjemena[1], tjemena[2]);
    int b = Orijentacija(tjemena[0], tjemena[1], t);
    int c = Orijentacija(tjemena[1], tjemena[2], t);
    int d = Orijentacija(tjemena[2], tjemena[0], t);
    if(a != 0 && b == a && c == a && d == a) return true;
    return false;
}
void Ispisi() const {
    std::cout << "((" << tjemena[0].first << "," << tjemena[0].second << "),(" << tjemena[1].first << "," << tjemena[1].second << "),(" << tjemena[2].first << "," << tjemena[2].second << "))" << std::endl;
}
void Transliraj(double delta_x, double delta_y) {
    for(int i = 0; i < 3; ++i) {
        tjemena[i].first += delta_x;
        tjemena[i].second += delta_y;
    }
}
void Centriraj(const Tacka &t) {
    Transliraj(t.first - DajCentar().first, t.second - DajCentar().second);
}
void Rotiraj(const Tacka &t, double ugao) {
    double x[3], y[3];
    for(int i = 0; i < 3; ++i) {
        x[i] = tjemena[i].first;
        y[i] = tjemena[i].second;
    }
    double xc = t.first;
    double yc = t.second;
    for(int i = 0; i < 3; ++i) {
        tjemena[i].first = xc + (x[i] - xc) * std::cos(ugao) - (y[i] - yc) * std::sin(ugao);
        tjemena[i].second = yc + (x[i] - xc) * std::sin(ugao) + (y[i] - yc) * std::cos(ugao);
    }
}
void Skaliraj(const Tacka &t, double faktor) {
    TestirajFaktor(faktor);
    for(int i = 0; i < 3; ++i) {
        tjemena[i].first = t.first + faktor * (tjemena[i].first - t.first);
        tjemena[i].second = t.second + faktor * (tjemena[i].second - t.second);        
    }
}
void Rotiraj(double ugao) {
    Rotiraj(DajCentar(), ugao);
}
void Skaliraj(double faktor) {
    TestirajFaktor(faktor);
    Skaliraj(DajCentar(), faktor);
}
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    std::vector<Tacka> v1;
    std::vector<Tacka> v2;
    for(int i = 0; i < 3; ++i) {
        v1.push_back(t1.tjemena[i]);
        v2.push_back(t1.tjemena[i]);
    }
    std::sort(v1.begin(), v1.end(), [] (const Tacka &t1, const Tacka &t2) {return t1.first < t2.first;});
    std::sort(v2.begin(), v2.end(), [] (const Tacka &t1, const Tacka &t2) {return t1.first < t2.first;});
    if(v1 == v2) return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
int main () {
    int n;
    std::cout << "Koliko zelite kreirati trouglova: "; std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> Trouglovi{};
    for(int i = 0; i < n; ++i) {
        std::cout << "Unesite podatke za " << i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka t1, t2, t3;
        while(1) {
            std::cin >> t1.first >> t1.second;
            std::cin >> t2.first >> t2.second;
            std::cin >> t3.first >> t3.second;
            try {
                Trougao trougao1(t1, t2, t3);
                break;
            }
            catch(std::domain_error trash) {
                std::cout << trash.what() << ", ponovite unos!" << std::endl;
                std::cout << "Unesite podatke za " << i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            }
        }
        std::shared_ptr<Trougao> T = std::make_shared<Trougao> (t1, t2, t3);
        Trouglovi.push_back(T);
    }
    double delta_x, delta_y;
    double ugao;
    double faktor;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> delta_x >> delta_y;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugao;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> faktor;
    std::cout << "Trouglovi nakon obavljenih transformacija: " << std::endl;
    std::transform(Trouglovi.begin(), Trouglovi.end(), Trouglovi.begin(), [delta_x, delta_y] (std::shared_ptr<Trougao> T1) -> std::shared_ptr<Trougao> {T1 -> Transliraj(delta_x, delta_y); return T1;});
    std::transform(Trouglovi.begin(), Trouglovi.end(), Trouglovi.begin(), [ugao] (std::shared_ptr<Trougao> T1) -> std::shared_ptr<Trougao> {T1 -> Rotiraj(ugao); return T1;});
    std::transform(Trouglovi.begin(), Trouglovi.end(), Trouglovi.begin(), [faktor] (std::shared_ptr<Trougao> T1) -> std::shared_ptr<Trougao> {T1 -> Skaliraj(T1 -> DajTjeme(1), faktor); return T1;});
    std::sort(Trouglovi.begin(), Trouglovi.end(), [] (std::shared_ptr<Trougao> T1, std::shared_ptr<Trougao> T2) -> bool {return T1 -> DajPovrsinu() < T2 -> DajPovrsinu();});
    for_each(Trouglovi.begin(), Trouglovi.end(), [](std::shared_ptr<Trougao> T1) {T1 -> Ispisi(); std::cout << std::endl; });
    auto minimalni = std::min_element(Trouglovi.begin(), Trouglovi.end(), [] (std::shared_ptr<Trougao> T1, std::shared_ptr<Trougao> T2) {return T1 -> DajObim() < T2 -> DajObim();});
    std::cout << "Trougao sa najmanjim obimom: ";
    int i = 0;
    for(auto x = Trouglovi.begin(); x != Trouglovi.end(); ++x) {
        if(*x == *minimalni) {
            Trouglovi[i] -> Ispisi();
            break;
        } 
        i++;
    }
    int br_identicnih = 0, br_slicnih = 0, br_podudarnih = 0;
    
	return 0;
}