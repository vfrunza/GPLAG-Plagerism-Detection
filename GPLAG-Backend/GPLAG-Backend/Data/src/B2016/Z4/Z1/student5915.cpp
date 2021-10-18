/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>
#include <utility>

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka t1, t2, t3;
    static double Formula(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3); };
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

inline double Trougao::Formula(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    return t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second);
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Orijentacija(t1, t2, t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
    this->t1 = t1;
    this->t2 = t2;
    this->t3 = t3;
}

void Trougao::Postavi(int indeks, const Tacka &t) {
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    if(indeks == 1) t1 = t;
    else if(indeks == 2) t2 = t;
    else t3 = t;
    if(Orijentacija(t1, t2, t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Formula(t1, t2, t3) > 0) return 1;
    else if(Formula(t1, t2, t3) < 0) return - 1;
    else return 0;
}

Tacka Trougao::DajTjeme(int indeks) const {
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    if(indeks == 1) return t1;
    else if(indeks == 2) return t2;
    else return t3;
}

double Trougao::DajStranicu(int indeks) const {
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    if(indeks == 1) return std::sqrt(std::pow(std::abs(t2.first - t3.first), 2) + std::pow(std::abs(t2.second - t3.second), 2));
    else if(indeks == 2) return std::sqrt(std::pow(std::abs(t1.first - t3.first), 2) + std::pow(std::abs(t1.second - t3.second), 2));
    else return std::sqrt(std::pow(std::abs(t2.first - t1.first), 2) + std::pow(std::abs(t2.second - t1.second), 2));
}

double Trougao::DajUgao(int indeks) const {
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    double a(DajStranicu(1)), b(DajStranicu(2)), c(DajStranicu(3));
    if(indeks == 1) return std::acos((b * b + c * c - a * a) / (2 * b * c));
    else if(indeks == 2) return std::acos((a * a + c * c - b * b) / (2 * a * c));
    else return std::acos((b * b + a * a - c * c) / (2 * b * a));
}

inline Tacka Trougao::DajCentar() const {
    return Tacka((t1.first + t2.first + t3.first) / 3, (t1.second + t2.second + t3.second) / 3);
}

inline double Trougao::DajObim() const {
    return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
}

inline double Trougao::DajPovrsinu() const{
    return std::abs(Formula(this->t1, this->t2, this->t3)) / 2;
}

inline bool Trougao::DaLiJePozitivnoOrijentiran() const {
    if(Formula(this->t1, this->t2, this->t3) > 0) return true;
    else return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    if(Orijentacija(this->t1, this->t2, t) == 0 || Orijentacija(this->t2, this->t3, t) == 0 || Orijentacija(this->t1, this->t3, t) == 0)
        return false;
    if(Orijentacija(this->t1, this->t2, this->t3) == Orijentacija(this->t1, this->t2, t) == Orijentacija(this->t2, this->t3, t) == Orijentacija(this->t3, this->t1, t))
        return true;
    else return false;
}

inline void Trougao::Ispisi() const {
    std::cout << "((" << t1.first << "," << t1.second << "),(" << t2.first << "," << t2.second << "),(" << t3.first << "," << t3.second << "))";
}

void Trougao::Transliraj(double delta_x, double delta_y) {
    t1.first += delta_x;
    t2.first += delta_x;
    t3.first += delta_x;
    t1.second += delta_y;
    t2.second += delta_y;
    t3.second += delta_y;
}

void Trougao::Centriraj(const Tacka &t) {
    double delta_x(t.first - DajCentar().first), delta_y(t.second - DajCentar().second);
    Transliraj(delta_x, delta_y);
}

void Trougao::Rotiraj(const Tacka &t, double ugao) {
    t1.first -= t.first;
    t1.second -= t.second;
    double novi_x = t1.first * std::cos(ugao) - t1.second * std::sin(ugao);
    double novi_y = t1.first * std::sin(ugao) + t1.second * std::cos(ugao);
    t1.first = novi_x + t.first;
    t1.second = novi_y + t.second;
    t2.first -= t.first;
    t2.second -= t.second;
    novi_x = t2.first * std::cos(ugao) - t2.second * std::sin(ugao);
    novi_y = t2.first * std::sin(ugao) + t2.second * std::cos(ugao);
    t2.first = novi_x + t.first;
    t2.second = novi_y + t.second;
    t3.first -= t.first;
    t3.second -= t.second;
    novi_x = t3.first * std::cos(ugao) - t3.second * std::sin(ugao);
    novi_y = t3.first * std::sin(ugao) + t3.second * std::cos(ugao);
    t3.first = novi_x + t.first;
    t3.second = novi_y + t.second;
}

void Trougao::Skaliraj(const Tacka &t, double faktor) {
    const double Eps(1e-10);
    if(std::abs(faktor) < Eps) throw std::domain_error("Nekorektan faktor skaliranja");
    t1.first = t.first + faktor * (t1.first - t.first);
    t1.second = t.second + faktor * (t1.second - t.second);
    t2.first = t.first + faktor * (t2.first - t.first);
    t2.second = t.second + faktor * (t2.second - t.second);
    t3.first = t.first + faktor * (t3.first - t.first);
    t3.second = t.second + faktor * (t3.second - t.second);
}

void Trougao::Rotiraj(double ugao) {
    Tacka t(DajCentar());
    Rotiraj(t, ugao);
}

void Trougao::Skaliraj(double faktor) {
    Tacka t(DajCentar());
    Skaliraj(t, faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    std::vector<double> x1, x2, y1, y2;
    x1.push_back(t1.t1.first);
    x1.push_back(t1.t2.first);
    x1.push_back(t1.t3.first);
    y1.push_back(t1.t1.second);
    y1.push_back(t1.t2.second);
    y1.push_back(t1.t3.second);
    x2.push_back(t2.t1.first);
    x2.push_back(t2.t2.first);
    x2.push_back(t2.t3.first);
    y2.push_back(t2.t1.second);
    y2.push_back(t2.t2.second);
    y2.push_back(t2.t3.second);
    std::sort(x1.begin(), x1.end());
    std::sort(x2.begin(), x2.end());
    std::sort(y1.begin(), y1.end());
    std::sort(y2.begin(), y2.end());
    const double Eps(1e-10);
    if(std::abs(x1[0] - x2[0]) < Eps && std::abs(x1[1] - x2[1]) < Eps && std::abs(x1[2] - x2[2]) < Eps &&
    std::abs(y1[0] - y2[0]) < Eps && std::abs(y1[1] - y2[1]) < Eps && std::abs(y1[2] - y2[2]) < Eps) return true;
    else return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    std::vector<double> uglovi1, uglovi2, stranice1, stranice2;
    uglovi1.push_back(t1.DajUgao(1));
    uglovi1.push_back(t1.DajUgao(2));
    uglovi1.push_back(t1.DajUgao(3));
    uglovi2.push_back(t2.DajUgao(1));
    uglovi2.push_back(t2.DajUgao(2));
    uglovi2.push_back(t2.DajUgao(3));
    stranice1.push_back(t1.DajStranicu(1));
    stranice1.push_back(t1.DajStranicu(2));
    stranice1.push_back(t1.DajStranicu(3));
    stranice2.push_back(t2.DajStranicu(1));
    stranice2.push_back(t2.DajStranicu(2));
    stranice2.push_back(t2.DajStranicu(3));
   
    const double Eps(1e-10);
    
    std::vector<double>::iterator najveci1(std::max_element(uglovi1.begin(), uglovi1.end()));
    std::vector<double>::iterator najveci2(std::max_element(uglovi2.begin(), uglovi2.end()));
    if(std::abs(*najveci1 - *najveci2) > Eps) return false;
    else {
        std::vector<double>::iterator desni1(najveci1);
        std::vector<double>::iterator desni2(najveci2);
        std::vector<double>::iterator lijevi1(najveci1);
        std::vector<double>::iterator lijevi2(najveci2);
        desni1++;
        if(desni1 == uglovi1.end()) desni1 = uglovi1.begin();
        desni2++;
        if(desni2 == uglovi2.end()) desni2 = uglovi2.begin();
        lijevi1--;
        if(lijevi1 < uglovi1.begin()) {
            lijevi1 = uglovi1.end();
            lijevi1--;
        }
        lijevi2--;
        if(lijevi2 < uglovi2.begin()) {
            lijevi2 = uglovi2.end();
            lijevi2--;
        }
        if(Trougao::Orijentacija(t1.t1, t1.t2, t1.t3) == Trougao::Orijentacija(t2.t1, t2.t2, t2.t3)) {
            if(std::abs(*desni1 - *desni2) > Eps) return false;
        }
        else {
            if(std::abs(*desni1 - *lijevi2) > Eps) return false;
        }
    }
    
    std::sort(uglovi1.begin(), uglovi1.end());
    std::sort(uglovi2.begin(), uglovi2.end());
    std::sort(stranice1.begin(), stranice1.end());
    std::sort(stranice2.begin(), stranice2.end());
    if(std::abs(uglovi1[0] - uglovi2[0]) < Eps && std::abs(uglovi1[1] - uglovi2[1]) < Eps && std::abs(uglovi1[2] - uglovi2[2]) < Eps &&
    std::abs(stranice1[0] - stranice2[0]) < Eps && std::abs(stranice1[1] - stranice2[1]) < Eps && std::abs(stranice1[2] - stranice2[2]) < Eps &&
    std::abs(t1.DajPovrsinu() - t2.DajPovrsinu()) < Eps)
        return true;
    else return false;
    
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    std::vector<double> uglovi1, uglovi2, stranice1, stranice2;
    uglovi1.push_back(t1.DajUgao(1));
    uglovi1.push_back(t1.DajUgao(2));
    uglovi1.push_back(t1.DajUgao(3));
    uglovi2.push_back(t2.DajUgao(1));
    uglovi2.push_back(t2.DajUgao(2));
    uglovi2.push_back(t2.DajUgao(3));
    stranice1.push_back(t1.DajStranicu(1));
    stranice1.push_back(t1.DajStranicu(2));
    stranice1.push_back(t1.DajStranicu(3));
    stranice2.push_back(t2.DajStranicu(1));
    stranice2.push_back(t2.DajStranicu(2));
    stranice2.push_back(t2.DajStranicu(3));
    
    const double Eps(1e-10);
    
    std::vector<double>::iterator najveci1(std::max_element(uglovi1.begin(), uglovi1.end()));
    std::vector<double>::iterator najveci2(std::max_element(uglovi2.begin(), uglovi2.end()));
    if(std::abs(*najveci1 - *najveci2) > Eps) return false;
    else {
        std::vector<double>::iterator desni1(najveci1);
        std::vector<double>::iterator desni2(najveci2);
        std::vector<double>::iterator lijevi1(najveci1);
        std::vector<double>::iterator lijevi2(najveci2);
        desni1++;
        if(desni1 == uglovi1.end()) desni1 = uglovi1.begin();
        desni2++;
        if(desni2 == uglovi2.end()) desni2 = uglovi2.begin();
        lijevi1--;
        if(lijevi1 < uglovi1.begin()) {
            lijevi1 = uglovi1.end();
            lijevi1--;
        }
        lijevi2--;
        if(lijevi2 < uglovi2.begin()) {
            lijevi2 = uglovi2.end();
            lijevi2--;
        }
        if(Trougao::Orijentacija(t1.t1, t1.t2, t1.t3) == Trougao::Orijentacija(t2.t1, t2.t2, t2.t3)) {
            if(std::abs(*desni1 - *desni2) > Eps) return false;
        }
        else {
            if(std::abs(*desni1 - *lijevi2) > Eps) return false;
        }
    }
    
    std::sort(uglovi1.begin(), uglovi1.end());
    std::sort(uglovi2.begin(), uglovi2.end());
    std::sort(stranice1.begin(), stranice1.end());
    std::sort(stranice2.begin(), stranice2.end());
    if(std::abs(uglovi1[0] - uglovi2[0]) < Eps && std::abs(uglovi1[1] - uglovi2[1]) < Eps && std::abs(uglovi1[2] - uglovi2[2]) < Eps &&
    (std::abs((stranice1[0] / stranice2[0]) -  (stranice1[1] / stranice2[1])) < Eps) &&
    (std::abs((stranice1[0] / stranice2[0]) - (stranice1[2] / stranice2[2])) < Eps))
        return true;
    else return false;
}

int main ()
{
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n;
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v;
    for(unsigned int i(0); i < n; i++) {
        pocetak:
        std::cout << "Unesite podatke za " << i + 1 <<  ". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka t1;
        Tacka t2;
        Tacka t3;
        std::cin >> t1.first >> t1.second >> t2.first >> t2.second >> t3.first >> t3.second;
        try {
            std::shared_ptr<Trougao> p(new Trougao(t1, t2, t3));
            v.push_back(p);
        }
        catch(std::bad_alloc izuzetak1) {
            std::cout << "Nema dovoljno memorije";
        }
        catch(std::domain_error e) {
            std::cout << e.what() << ", ponovite unos!" << std::endl;
            goto pocetak;
        }
    }
    
    std::cout << "Unesite vektor translacije (dx dy): ";
    double delta_x(0), delta_y(0);
    std::cin >> delta_x >> delta_y;
    std::cout << "Unesite ugao rotacije: ";
    double ugao(0);
    std::cin >> ugao;
    std::cout << "Unesite faktor skaliranja: ";
    double faktor(0);
    std::cin >> faktor;
    
    std::transform(v.begin(), v.end(), v.begin(), [delta_x, delta_y, ugao, faktor](std::shared_ptr<Trougao> p) {
        p->Transliraj(delta_x, delta_y);
        p->Rotiraj(ugao);
        p->Skaliraj(p->DajTjeme(1), faktor);
        return p; });
        
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) {
        return p1->DajPovrsinu() < p2->DajPovrsinu(); } );
        
    std::cout << "Trouglovi nakon obavljenih transformacija:\n";
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> p) { p->Ispisi(); std::cout << std::endl; });
    
    std::vector<std::shared_ptr<Trougao>>::iterator it = std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) {
        return p1->DajObim() < p2->DajObim();
    });
    std::cout << "Trougao sa najmanjim obimom: ";
    (*it)->Ispisi();
    std::cout << std::endl;
    
    int brojac(0);
    for(unsigned int i(0); i < n; i++) {
        for(unsigned int j(i + 1); j < n; j++)
            if(DaLiSuIdenticni(*v[i], *v[j])) {
                brojac++;
                if(brojac == 1) std::cout << "Parovi identicnih trouglova:\n";
                v[i]->Ispisi();
                std::cout << " i ";
                v[j]->Ispisi();
                std::cout << std::endl;
            }
    }
    if(brojac == 0) std::cout << "Nema identicnih trouglova!\n";
    
    brojac = 0;
    for(unsigned int i(0); i < n; i++) {
        for(unsigned int j(i + 1); j < n; j++)
            if(DaLiSuPodudarni(*v[i], *v[j])) {
                brojac++;
                if(brojac == 1) std::cout << "Parovi podudarnih trouglova:\n";
                v[i]->Ispisi();
                std::cout << " i ";
                v[j]->Ispisi();
                std::cout << std::endl;
            }
    }
    if(brojac == 0) std::cout << "Nema podudarnih trouglova!\n";
    
    brojac = 0;
    for(unsigned int i(0); i < n; i++) {
        for(unsigned int j(i + 1); j < n; j++)
            if(DaLiSuSlicni(*v[i], *v[j])) {
                brojac++;
                if(brojac == 1) std::cout << "Parovi slicnih trouglova:\n";
                v[i]->Ispisi();
                std::cout << " i ";
                v[j]->Ispisi();
                std::cout << std::endl;
            }
    }
    if(brojac == 0) std::cout << "Nema slicnih trouglova!\n";
	return 0;
}