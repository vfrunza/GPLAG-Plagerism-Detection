/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!

#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>
#include <functional>

typedef std::pair<double, double> Tacka;

class Trougao {
     Tacka tacke[3];
    void ProvjeraIndeksa(int i) const {
        if(i < 1 || i > 3) throw std::range_error("Nekorektan indeks");
    }
    static double Izraz(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second);
    }
    static bool EpsJednakost(double x, double y) {
        const double Eps (1E-10);
        return std::fabs(x-y) <= Eps * (std::fabs(x) + std::fabs(y));
    }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(!Orijentacija(t1, t2, t3)) throw std::domain_error("Nekorektne pozicije tjemena");
        tacke[0] = t1; tacke[1] = t2; tacke[2] = t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(!Orijentacija(t1, t2, t3)) throw std::domain_error("Nekorektne pozicije tjemena");
        tacke[0] = t1; tacke[1] = t2; tacke[2] = t3;  
    }
    void Postavi(int indeks, const Tacka &t) {
        ProvjeraIndeksa(indeks);
        auto tmp(tacke[indeks-1]);
        tacke[indeks-1] = t;
        if(!Orijentacija(tacke[0], tacke[1], tacke[2])) {
            tacke[indeks-1] = tmp;
            throw std::domain_error("Nekorektne pozicije tjemena");
        }
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) { ProvjeraIndeksa(indeks); return tacke[indeks-1]; }
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra (const Tacka &t) const;
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y);
    void Centriraj (const Tacka &t);
    void Rotiraj (const Tacka &t, double ugao);
    void Rotiraj (double ugao);
    void Skaliraj (const Tacka &t, double faktor);
    void Skaliraj (double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
    
};

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    auto a = Izraz(t1, t2, t3);
    if(a < 0) return -1;
    if(a > 0) return 1;
    else return 0;
}

double Trougao::DajStranicu(int indeks) const {
    ProvjeraIndeksa(indeks);
    double d = sqrt(pow(tacke[indeks%3].first - tacke[(indeks+1)%3].first, 2) + pow(tacke[indeks%3].second - tacke[(indeks+1)%3].second, 2));
    //double d = sqrt((tacke[indeks%3].first - tacke[(indeks+1)%3].first))*(tacke[indeks%3].first -
    return d;
}

double Trougao::DajUgao(int indeks) const {
    ProvjeraIndeksa(indeks);
    double a = DajStranicu(indeks%3), b = DajStranicu((indeks+1)%3), c = DajStranicu(indeks-1);
    return std::acos((a*a+b*b-c*c)/(2*a*b));
}

Tacka Trougao::DajCentar() const {
    Tacka t;
    t.first = 0; t.second = 0;
    for(int i = 0; i < 3; i++) {
        t.first += tacke[i].first;
        t.second += tacke[i].second;
    }
    t.first /= 3;
    t.second /= 3;
    return t;
}

double Trougao::DajObim() const {
    double O(0);
    for(int i = 0; i < 3; i++)
        O += DajStranicu(i+1);
    return O;
}

double Trougao::DajPovrsinu() const {
    return 0.5 * std::abs(Izraz(tacke[0], tacke[1], tacke[2]));
}

bool Trougao::DaLiJePozitivnoOrijentiran() const {
    auto a = Orijentacija(tacke[0], tacke[1], tacke[2]);
    return a == 1;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    auto orj(Orijentacija(tacke[0], tacke[1], tacke[2]));
    return Orijentacija(tacke[0], tacke[1], t) == orj && Orijentacija(tacke[1], tacke[2], t) == orj && Orijentacija(tacke[2], tacke[0], t) == orj;
}

void Trougao::Ispisi() const {
    std::cout << "(";
    for(int i = 0; i < 3; i++) {
        std::cout << "(" << tacke[i].first << "," << tacke[i].second << ")";
        if(i != 2) std::cout << ",";
    }
    std::cout << ")";
}

void Trougao::Transliraj (double delta_x, double delta_y) {
    for(int i = 0; i < 3; i++) {
        tacke[i].first += delta_x;
        tacke[i].second += delta_y;   
    }
}

void Trougao::Centriraj (const Tacka &t) {
    Tacka t2 = DajCentar();
    Transliraj(t.first - t2.first, t.second - t2.second);
}

void Trougao::Rotiraj (const Tacka &t, double ugao) {
    for(int i = 0; i < 3; i++) {
        double x = t.first + (tacke[i].first - t.first) * std::cos(ugao) - (tacke[i].second - t.second) * std::sin(ugao);
        double y = t.second + (tacke[i].first - t.first) * std::sin(ugao) + (tacke[i].second - t.second) * std::cos(ugao);
        tacke[i] = {x,y};
    }
}

void Trougao::Rotiraj (double ugao) {
    Rotiraj(DajCentar(), ugao);
}

void Trougao::Skaliraj (const Tacka &t, double faktor) {
    if (!faktor) throw std::domain_error("Nekorektan faktor skaliranja");
    for(int i = 0; i < 3; i++) {
        tacke[i].first = t.first + faktor * (tacke[i].first - t.first);
        tacke[i].second = t.second + faktor * (tacke[i].second - t.second); 
    }
}

void Trougao::Skaliraj (double faktor) {
    Skaliraj(DajCentar(), faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    for(int i = 0; i < 3; i++) {
        int brojac(0);
        for(int j = 0; j < 3; j++)
            if(Trougao::EpsJednakost(t1.tacke[i].first, t2.tacke[j].first) && Trougao::EpsJednakost(t1.tacke[i].second, t2.tacke[j].second))
            //if(t1.tacke[i].first == t2.tacke[j].first && t1.tacke[i].second == t2.tacke[j].second)
                brojac++;
        if(brojac != 1)
            return false;
    }
    return true;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    for(int i = 0; i < 3; i++) {
        int brojac(0);
        for(int j = 0; j < 3; j++)
            if(Trougao::EpsJednakost(t1.DajStranicu(i+1), t2.DajStranicu(j+1)))
            //if(t1.DajStranicu(i+1) == t2.DajStranicu(j+1))
                brojac++;
        if(brojac < 1) return false;
    }
    int br(1);
    for(int i = 1; i < 3; i++)
        if(Trougao::EpsJednakost(t1.DajStranicu(i+1), t1.DajStranicu(1)))
        //if(t1.DajStranicu(i+1) == t1.DajStranicu(1)) br++;
    if(br == 3) return true;
    auto t(t1);
    for(int i = 0; i < 3; i++)
        for(int j = 1; j < 2; j++)
            if(t.DajStranicu(i+1) < t.DajStranicu(j+1))
                std::swap(t.tacke[i], t.tacke[j]);
    auto tp(t2);
    for(int i =  0; i < 3; i++)
        for(int j = 1; j < 2; j++)
            if(tp.DajStranicu(i+1) < tp.DajStranicu(j+1))
                std::swap(tp.tacke[i], tp.tacke[j]);
    if(Trougao::Orijentacija(t.tacke[0], t.tacke[1], t.tacke[2]) == Trougao::Orijentacija(tp.tacke[0], tp.tacke[1], tp.tacke[2]))
        return true;
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    int br1(0), br2(0), br3(0);
    double k1(t1.DajStranicu(1)/t2.DajStranicu(1)), k2(t1.DajStranicu(1)/t2.DajStranicu(2)), k3(t1.DajStranicu(1)/t2.DajStranicu(3));
    for(int i = 0; i < 3; i++) 
        for(int j = 0; j < 3; j++) {
            double x = t1.DajStranicu(i+1) / t2.DajStranicu(j+1);
            if(Trougao::EpsJednakost(x, k1)) br1++;
            if(Trougao::EpsJednakost(x, k2)) br2++;
            if(Trougao::EpsJednakost(x, k3)) br3++;
        }
    if(br1 != 3 && br2 != 3 && br3 != 3) return false;
    if(br1 == 3 && br2 == 3 && br3 == 3) return true;
    auto t(t1);
    for(int i = 0; i < 3; i++)
        for(int j = 1; j <2; j++)
            if(t.DajStranicu(i+1) < t.DajStranicu(j+1))
                std::swap(t.tacke[i], t.tacke[j]);
    auto tp(t2);
    for(int i = 0; i < 3; i++)
        for(int j = 1; j < 2; j++)
            if(tp.DajStranicu(i+1) < tp.DajStranicu(j+1))
                std::swap(tp.tacke[i], tp.tacke[j]);
                
    if(Trougao::Orijentacija(t.tacke[0], t.tacke[1], t.tacke[2]) == Trougao::Orijentacija(tp.tacke[0], tp.tacke[1], tp.tacke[2]))
        return true;
    return false;
}

bool Provjera(const std::vector<std::shared_ptr<Trougao>> &v, std::function<bool(Trougao, Trougao)> f, int x) {
    bool uslov(false);
    for(int i = 0; i < v.size(); i++)
        for(int j = i; j < v.size(); j++) 
            if(i != j && f(*v[i], *v[j])) {
                if(!uslov) {
                    if(x == 0) std::cout << "\nParovi identicnih trouglova:\n";
                    if(x == 1) std::cout << "Parovi podudarnih trouglova:\n";
                    if(x == 2) std::cout << "Parovi slicnih trouglova:\n";
                }
                uslov = true;
                v[i] -> Ispisi();
                std::cout << " i ";
                v[j] -> Ispisi();
                std::cout << std::endl;
            }
    return uslov;
}
int main ()
{  
    try{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    for(int i = 0; i < n; i++) {
        double x1, y1, x2, y2, x3, y3;
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        try {
            v[i] = std::make_shared<Trougao> (Trougao({x1, y1}, {x2, y2}, {x3, y3}));
        }
        catch(std::domain_error e) {
            std::cout << e.what() <<", ponovite unos!" << std::endl;
            i--;
        }
        catch(std::bad_alloc) {
            std::cout <<"Problemi sa memorijom";
        }
    }
    std::cout << "Unesite vektor translacije (dx dy): ";
    double dx, dy;
    std::cin >> dx >> dy;
    std::transform(v.begin(), v.end(), v.begin(),  [dx, dy] (std::shared_ptr<Trougao> t) {t->Transliraj(dx, dy); return t;});
    std::cout << "Unesite ugao rotacije: ";
    double ugao;
    std::cin >> ugao;
    std::transform(v.begin(), v.end(), v.begin(), [ugao] (std::shared_ptr<Trougao> t) {t->Rotiraj(ugao); return t;});
    std::cout << "Unesite faktor skaliranja: ";
    double faktor;
    std::cin >> faktor;
    std::transform(v.begin(), v.end(), v.begin(), [faktor] (std::shared_ptr<Trougao>t) {t->Skaliraj(t->DajTjeme(1), faktor); return t;});
    std::sort(v.begin(), v.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) { return t1->DajPovrsinu() < t2->DajPovrsinu();});
    std::cout << "Trouglovi nakon obavljenih transformacija:\n";
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t) { t->Ispisi(); std::cout << std::endl;});    
    auto min_obim (std::min_element(v.begin(), v.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {return t1->DajObim() < t2->DajObim();}));
    std::cout << "Trougao sa najmanjim obimom: ";
    if(min_obim != v.end()) (*min_obim)->Ispisi();
    if(!(Provjera(v, DaLiSuIdenticni, 0))) std::cout << "\nNema identicnih trouglova!\n";
    if(!(Provjera(v, DaLiSuPodudarni, 1))) std::cout << "Nema podudarnih trouglova!\n";
    if(!(Provjera(v, DaLiSuSlicni, 2))) std::cout << "Nema slicnih trouglova!\n";
    }
    catch(std::bad_alloc) {
        std::cout << "Nema memorije";
    }
    
	return 0;
}