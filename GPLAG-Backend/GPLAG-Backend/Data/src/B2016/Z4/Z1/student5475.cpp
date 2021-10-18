#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include <map>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>

typedef std::pair<double, double> Tacka;

bool Isti(double a, double b) {
    const double eps(1e-10);
    return std::fabs(a - b) <= eps * (std::fabs(a) + std::fabs(b));
}
class Trougao {
    Tacka tjeme[3];
    static void TestIndeksa(int indeks) {
        if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    }
    static double F(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second);
    }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3); }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const { TestIndeksa(indeks); return tjeme[indeks-1]; }
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const {
        return {(tjeme[0].first + tjeme[1].first + tjeme[2].first)/3, (tjeme[0].second + tjeme[1].second + tjeme[2].second)/3};
    }
    double DajObim() const { return DajStranicu(1) + DajStranicu(2) + DajStranicu(3); }
    double DajPovrsinu() const { return 1./2 * std::fabs(F(tjeme[0], tjeme[1], tjeme[2])); }
    bool DaLiJePozitivnoOrijentiran() const { return Orijentacija(tjeme[0], tjeme[1], tjeme[2]); }
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const {
        std::cout << "((" << tjeme[0].first << "," << tjeme[0].second << "),(" << tjeme[1].first << "," 
        << tjeme[1].second << "),(" << tjeme[2].first << "," << tjeme[2].second << "))";
    }
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao) { Rotiraj(DajCentar(), ugao); }
    void Skaliraj(double faktor) { Skaliraj(DajCentar(), faktor); }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Orijentacija(t1, t2, t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
    tjeme[0] = t1; tjeme[1] = t2; tjeme[2] = t3;
}
void Trougao::Postavi(int indeks, const Tacka &t) {
    int o;
    if(indeks == 1) o = Orijentacija(t, tjeme[1], tjeme[2]); 
    else if(indeks == 2) o = Orijentacija(tjeme[0], t, tjeme[2]);
    else o = Orijentacija(tjeme[0], tjeme[1], t);
    if(o == 0) throw std::domain_error("Nekorektne pozicije tjemena");
    TestIndeksa(indeks);
    tjeme[indeks-1] = t;
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double temp = F(t1, t2, t3);
    if(temp > 0) return 1;
    if(temp < 0) return -1;
    return 0;
}
double Trougao::DajStranicu(int indeks) const {
    TestIndeksa(indeks);
    double x1, y1, x2, y2;
    if(indeks != 3) {
        x1 = tjeme[3-indeks-1].first; y1 = tjeme[3-indeks-1].second;
        x2 = tjeme[2].first; y2 = tjeme[2].second;
    }
    else {
        x1 = tjeme[0].first; y1 = tjeme[0].second;
        x2 = tjeme[1].first; y2 = tjeme[1].second;
    }
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
double Trougao::DajUgao(int indeks) const {
    TestIndeksa(indeks);
    double a(DajStranicu(indeks)), b, c;
    if(indeks != 3) {
        b = DajStranicu(3-indeks);
        c = DajStranicu(3);
    }
    else {
        b = DajStranicu(1);
        c = DajStranicu(2);
    }
    return acos((b*b + c*c - a*a)/(2*b*c));
}
/**/bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    int o1(Orijentacija(tjeme[0], tjeme[1], tjeme[2])), o2(Orijentacija(tjeme[0], tjeme[1], t)),
    o3(Orijentacija(tjeme[1], tjeme[2], t)), o4(Orijentacija(tjeme[2], tjeme[0], t));
    return o1 == o2 + o3 + o4;
}
void Trougao::Transliraj(double delta_x, double delta_y) {
    for(int i=0; i<3; i++) {
        tjeme[i].first += delta_x;
        tjeme[i].second += delta_y;
    }
}
void Trougao::Centriraj(const Tacka &t) {
    Tacka c(DajCentar());
    double delta_x = std::sqrt((c.first - t.first)*(c.first - t.first)), delta_y = std::sqrt((c.second - t.second)*(c.second - t.second));
    Transliraj(delta_x, delta_y);
}
void Trougao::Rotiraj(const Tacka &t, double ugao) {
    if(Isti(ugao, 0)) return;
    double xc(t.first), yc(t.second);
    for(int i=0; i<3; i++) {
        double x(tjeme[i].first), y(tjeme[i].second);
        Postavi(i+1, std::make_pair(xc + (x - xc)*cos(ugao) - (y - yc)*sin(ugao),
        yc + (x - xc)*sin(ugao) + (y - yc)*cos(ugao)));
    }
}
void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(Isti(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
    bool treba(false);
    if(faktor < 0) {
        faktor *= -1;
        treba = true;
    }
    double xc(t.first), yc(t.second);
    for(int i=0; i<3; i++) {
        double x(tjeme[i].first), y(tjeme[i].second);
        //if(!(Isti(xc, tjeme[i].first)) && !(Isti(yc, tjeme[i].second)))
            Postavi(i+1, std::make_pair(xc + faktor*(x - xc), yc + faktor*(y - yc)));
    }
    if(treba) Rotiraj(atan(1)*4);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    int br(0);
    for(int i=0; i<3; i++) {
       double x1(t1.tjeme[i].first), y1(t1.tjeme[i].second);
        for(int j=0; j<3; j++) {
            double x2(t2.tjeme[j].first), y2(t2.tjeme[j].second);
            if(Isti(x1, x2) && Isti(y1, y2)) br++;
        }
    }
    return br == 3;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    /*Trougao b(t2.tjeme[0], t2.tjeme[1], t2.tjeme[2]);
    b.Centriraj(t1.DajCentar());
    Tacka A(std::make_pair(t1.tjeme[0].first, t1.tjeme[0].second)), B(std::make_pair(t1.tjeme[1].first, t1.tjeme[1].second));
    Tacka sredina(std::make_pair((A.first + B.first)/2., (A.second + B.second)/2.));
        if(DaLiSuIdenticni(t1, b)) return true;
    for(int i=0; i<3; i++) {
        if(Trougao::Orijentacija(A, sredina, t2.tjeme[i]) != 0) {
            Trougao temp(A, sredina, t2.tjeme[i]);
            b.Rotiraj(temp.DajUgao(2));
        if(DaLiSuIdenticni(t1, b)) return true;
        }
    }
    return false;*/
   bool o(Trougao::Orijentacija(t1.tjeme[0], t1.tjeme[1], t1.tjeme[2]) == Trougao::Orijentacija(t2.tjeme[0], t2.tjeme[1], t2.tjeme[2]));
   int str(0), ug(0);
    for(int i=0; i<3; i++) {
        double a(t1.DajStranicu(i+1)), ugao(t1.DajUgao(i+1));
        for(int j=0; j<3; j++) {
            if(Isti(a, t2.DajStranicu(j+1))) str++;
            if(Isti(ugao, t2.DajUgao(j+1))) ug++;
        }
    }
    return ug + str >= 6 && o;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    //ne radi
    Trougao a(t1.tjeme[0], t1.tjeme[1], t1.tjeme[2]), b(t2.tjeme[0], t2.tjeme[1], t2.tjeme[2]);
    double faktor(t1.tjeme[0].first - t2.tjeme[0].first);
    a.Centriraj(b.DajCentar());
    a.Skaliraj(faktor);
    for(int i=0; i<3; i++) {
        if(DaLiSuIdenticni(a, b)) return true;
        a.Rotiraj(1);
    }
    return false;
}
template <typename FunTip>
void IspisiParove(const std::vector<std::shared_ptr<Trougao>> &v, FunTip f, std::string tip) {
    bool nema(true), prvi(true);
    for(int i=0; i<v.size(); i++) {
        Trougao a(v[i]->DajTjeme(1), v[i]->DajTjeme(2), v[i]->DajTjeme(3));
        for(int j=i+1; j<v.size(); j++) {
            Trougao b(v[j]->DajTjeme(1), v[j]->DajTjeme(2), v[j]->DajTjeme(3));
            if(f(a, b)) {
                if(prvi) { std::cout << "Parovi " << tip << " trouglova: " << std::endl; prvi = false; }
                a.Ispisi(); std::cout << " i "; b.Ispisi();
                nema = false;
                std::cout << std::endl;
                }
            }
        }
    if(nema) std::cout << "Nema "<< tip << " trouglova!" << std::endl;
}
int main () {
    typedef std::shared_ptr<Trougao> dijeljeni;
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    try {
        std::cin >> n;
        std::vector<std::shared_ptr<Trougao>> v;
        for(int i=0; i<n; i++) {
        try {
            Tacka t[3];
            std::cout << "Unesite podatke za "<< i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            for(int j=0; j<3; j++) std::cin >> t[j].first >> t[j].second;
            v.push_back(std::make_shared<Trougao>(t[0], t[1], t[2]));
            }
        catch(std::domain_error e) {
            std::cout << e.what() << ", ponovite unos!" << std::endl;
            i--;
        }
        }
    try {
        double dx, dy, teta, faktor;
        std::cout << "Unesite vektor translacije (dx dy): ";
        std::cin >> dx >> dy;
        std::transform(v.begin(), v.end(), v.begin(), [dx, dy](std::shared_ptr<Trougao> t1) { t1->Transliraj(dx, dy); return t1; });
        std::cout << "Unesite ugao rotacije: ";
        std::cin >> teta;
        std::transform(v.begin(), v.end(), v.begin(), [teta](std::shared_ptr<Trougao> t1) { t1->Rotiraj(teta); return t1; });
        std::cout << "Unesite faktor skaliranja: ";
        std::cin >> faktor;
        std::transform(v.begin(), v.end(), v.begin(), [faktor](std::shared_ptr<Trougao> t1) { t1->Skaliraj(t1->DajTjeme(1), faktor); return t1; });
        std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) { return t1->DajPovrsinu() < t2->DajPovrsinu(); }); 
        std::cout << "Trouglovi nakon obavljenih transformacija: " << std::endl;
        for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t) { t->Ispisi(); std::cout << std::endl; } );
        std::cout << "Trougao sa najmanjim obimom: ";
        auto p = std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) { 
            return t1->DajObim() < t2->DajObim(); }); 
        (*p)->Ispisi();
        std::cout << std::endl;
        IspisiParove(v, DaLiSuIdenticni, "identicnih");;
        IspisiParove(v, DaLiSuPodudarni, "podudarnih");
        IspisiParove(v, DaLiSuSlicni, "slicnih");
}
    catch(std::domain_error e) { std::cout << e.what() << std::endl; }
    }catch(...) {}
    return 0;
}