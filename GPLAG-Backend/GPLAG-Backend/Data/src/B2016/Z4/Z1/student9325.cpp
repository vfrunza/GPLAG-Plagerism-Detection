#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <memory>

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka t1, t2, t3;
    double testOrijentacije() const {
        return t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second);
    }
    void TestIndeksa(int indeks) const {
    if(indeks < 1 || indeks > 3)
        throw std::range_error("Nekorektan indeks");
    }
    static bool JesuLiJednaki(double x, double y, double Eps = 1e-10) {
        return std::fabs(x - y) <= Eps * (std::fabs(x) + std::fabs(y));
    }

public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        Postavi(t1, t2, t3);
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3) == 0) 
            throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1 = t1; Trougao::t2 = t2; Trougao::t3 = t3; 
    }
    void Postavi(int indeks, const Tacka &t) {
        if(indeks == 1) t1 = t;
        else if(indeks == 2) t2 = t;
        else if(indeks == 3) t3 = t;
        throw std::range_error("Nekorektan indeks");
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double test_orijentacija = t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second);
        if(test_orijentacija > 0) return 1;
        else if(test_orijentacija < 0) return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const {
        if(indeks == 1) return t1;
        else if(indeks == 2) return t2;
        else if(indeks == 3) return t3; 
        throw std::range_error("Nekorektan indeks");
    }
    double DajStranicu(int indeks) const {
        if(indeks == 1) 
            return std::sqrt((t2.first - t3.first)*(t2.first - t3.first) + (t2.second - t3.second)*(t2.second - t3.second));
        else if(indeks == 2) 
            return std::sqrt((t1.first - t3.first)*(t1.first - t3.first) + (t1.second - t3.second)*(t1.second - t3.second));
        else if(indeks == 3) 
            return std::sqrt((t1.first - t2.first)*(t1.first - t2.first) + (t1.second - t2.second)*(t1.second - t2.second));
        throw std::range_error("Nekorektan indeks");
    }
    double DajUgao(int indeks) const {
        if(indeks == 1) {
            return std::acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3) - DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
        }
        else if(indeks == 2) {
            return std::acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3) - DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
        }
        else if(indeks == 3) {
            return std::acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2) - DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(2)*DajStranicu(1)));
        } 
        throw std::range_error("Nekorektan indeks");
    }
    Tacka DajCentar() const {
        return {(t1.first + t2.first + t3.first)/3, (t1.second + t2.second + t3.second)/3};
    }
    double DajObim() const {
        return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
    }
    double DajPovrsinu() const {
        return std::fabs(testOrijentacije());
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(testOrijentacije() > 0) return true;
        else if(testOrijentacije() < 0) return false;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const {
        std::cout << "((" << t1.first << "," << t1.second << "),(" << t2.first << "," 
                  << t2.second << "),(" << t3.first << "," << t3.second << "))";
    }
    void Transliraj(double delta_x, double delta_y) {
        t1.first += delta_x; t2.first += delta_x; t3.first += delta_x;
        t1.second += delta_y; t2.second += delta_y; t3.second += delta_y; 
    }
    void Centriraj(const Tacka &t) {
        double delta_x = std::fabs(t.first - DajCentar().first);
        double delta_y = std::fabs(t.second - DajCentar().second);
        Transliraj(delta_x, delta_y);
    }
    void Rotiraj(const Tacka &t, double ugao) {
        t1.first = t.first + (t1.first - t.first) * std::cos(ugao) - (t1.second - t.second) * std::sin(ugao);
        t1.second = t.second + (t1.first - t.first) * std::sin(ugao) + (t1.second - t.second) * std::cos(ugao);
        t2.first = t.first + (t2.first - t.first) * std::cos(ugao) - (t2.second - t.second) * std::sin(ugao);
        t2.second = t.second + (t2.first - t.first) * std::sin(ugao) + (t2.second - t.second) * std::cos(ugao);
        t3.first = t.first + (t3.first - t.first) * std::cos(ugao) - (t3.second - t.second) * std::sin(ugao);
        t3.second = t.second + (t3.first - t.first) * std::sin(ugao) + (t3.second - t.second) * std::cos(ugao);
    }
    void Skaliraj(const Tacka &t, double faktor) {
        if(JesuLiJednaki(faktor, 0)) 
            throw std::domain_error("Nekorektan faktor skaliranja");
        t1.first = t.first + faktor * (t1.first - t.first);
        t1.second = t.second + faktor * (t1.second - t.second);
        t2.first = t.first + faktor * (t2.first - t.first);
        t2.second = t.second + faktor * (t2.second - t.second);
        t3.first = t.first + faktor * (t3.first - t.first);
        t3.second = t.second + faktor * (t3.second - t.second);
    }
    void Rotiraj(double ugao) {
        Rotiraj(DajCentar(), ugao);
    }
    void Skaliraj(double faktor) {
        Skaliraj(DajCentar(), faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    std::vector<Tacka> v1, v2;
    v1.push_back(t1.t1); v1.push_back(t1.t2); v1.push_back(t1.t3);
    v2.push_back(t2.t1); v2.push_back(t2.t2); v2.push_back(t2.t3);
    std::sort(v1.begin(), v1.end(), [](Tacka a, Tacka b) {
        if(a.first < b.first) 
            return true;
        else if(Trougao::JesuLiJednaki(a.first, b.first)) 
            return a.second <= b.second;
        return false;
    });
    std::sort(v2.begin(), v2.end(), [](Tacka a, Tacka b) {
        if(a.first < b.first) 
            return true;
        else if(Trougao::JesuLiJednaki(a.first, b.first)) 
            return a.second <= b.second;
        return false;
    });
    
    if(v1 == v2) return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    std::vector<double> v1, v2;
    v1.push_back(t1.DajStranicu(1)); v1.push_back(t1.DajStranicu(2)); v1.push_back(t1.DajStranicu(3));
    v2.push_back(t2.DajStranicu(1)); v2.push_back(t2.DajStranicu(2)); v2.push_back(t2.DajStranicu(3));
    std::sort(v1.begin(), v1.end()); std::sort(v2.begin(), v2.end());
    
    if(Trougao::JesuLiJednaki(v1[0], v2[0])) {
        if(Trougao::JesuLiJednaki(v1[1], v2[1])) {
            if(Trougao::JesuLiJednaki(v1[2], v2[2])) {
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    std::vector<double> v1, v2;
    v1.push_back(t1.DajStranicu(1)); v1.push_back(t1.DajStranicu(2)); v1.push_back(t1.DajStranicu(3));
    v2.push_back(t2.DajStranicu(1)); v2.push_back(t2.DajStranicu(2)); v2.push_back(t2.DajStranicu(3));
    std::sort(v1.begin(), v1.end()); std::sort(v2.begin(), v2.end());
    
    double faktor = v1[0]/v2[0];
    
    if(Trougao::JesuLiJednaki(v1[0]/v2[0],faktor)) {
        if(Trougao::JesuLiJednaki(v1[1]/v2[1], faktor)) {
            if(Trougao::JesuLiJednaki(v1[2]/v2[2], faktor)) {
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}

int main() {
    std::cout << "Koliko zelite kreirati trouglova: ";
    int broj_trouglova;
    std::cin >> broj_trouglova;

    std::vector<std::shared_ptr<Trougao>> v;
    
    for(int i = 0; i < broj_trouglova; i++) {
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        double x1, y1, x2, y2, x3, y3;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        try {
            v.push_back(std::make_shared<Trougao> (Trougao({x1, y1}, {x2, y2}, {x3, y3})));
        }
        catch(std::domain_error e) {
            std::cout << e.what() << ", ponovite unos!" << std::endl;
            i--;
        }
    }
    
    std::cout << "Unesite vektor translacije (dx dy): ";
    double dx, dy;
    std::cin >> dx >> dy;
    
    std::transform(v.begin(), v.end(), v.begin(), [dx, dy](std::shared_ptr<Trougao> t) {
        t->Transliraj(dx, dy);
        return t;
    });
    
    std::cout << "Unesite ugao rotacije: ";
    double ugao_rotacije;
    std::cin >> ugao_rotacije;
    
    std::transform(v.begin(), v.end(), v.begin(), [ugao_rotacije](std::shared_ptr<Trougao> t) {
        t->Rotiraj(ugao_rotacije);
        return t;
    });    
    
    std::cout << "Unesite faktor skaliranja: ";
    double faktor_skaliranja;
    std::cin >> faktor_skaliranja;
    
    std::transform(v.begin(), v.end(), v.begin(), [faktor_skaliranja](std::shared_ptr<Trougao> t) {
        t->Skaliraj(t->DajTjeme(1), faktor_skaliranja);
        return t;
    });     
    std::cout << "Trouglovi nakon obavljenih transformacija:\n";
    
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
        return t1->DajPovrsinu() < t2->DajPovrsinu();   
    });
    
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t) {
        t->Ispisi(); std::cout << std::endl;
    });
    
    std::cout << "Trougao sa najmanjim obimom: ";
    auto najmanji_element = min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
       return t1->DajObim() < t2->DajObim(); 
    });
    (*najmanji_element)->Ispisi(); std::cout << std::endl;
    
    bool usao = false;
    for(int i = 0; i < v.size(); i++) {
        for(int j = i+1; j < v.size(); j++) {
            if(DaLiSuIdenticni(*v[i], *v[j])) {
                if(usao == false) {
                    std::cout << "Parovi identicnih trouglova:\n";
                    usao = true;
                }
                v[i]->Ispisi(); std::cout << " i ";
                v[j]->Ispisi(); std::cout << std::endl;
            }
        }
    }
    if(usao == false) {
        std::cout << "Nema identicnih trouglova!\n";
    }
    usao = false;
    for(int i = 0; i < v.size(); i++) {
        for(int j = i+1; j < v.size(); j++) {
            if(DaLiSuPodudarni(*v[i], *v[j])) {
                if(usao == false) {
                    std::cout << "Parovi podudarnih trouglova:\n";
                    usao = true;
                }
                v[i]->Ispisi(); std::cout << " i ";
                v[j]->Ispisi(); std::cout << std::endl;
            }
        }
    }
    if(usao == false) {
        std::cout << "Nema podudarnih trouglova!\n";
    }
    usao = false;
    for(int i = 0; i < v.size(); i++) {
        for(int j = i+1; j < v.size(); j++) {
            if(DaLiSuSlicni(*v[i], *v[j])) {
                if(usao == false) {
                    std::cout << "Parovi slicnih trouglova:\n";
                    usao = true;
                }
                v[i]->Ispisi(); std::cout << " i ";
                v[j]->Ispisi(); std::cout << std::endl;
            }
        }
    }
    if(usao == false) {
        std::cout << "Nema slicnih trouglova!\n";
    }   
    return 0;
}