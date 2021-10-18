/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
typedef std::pair<double, double> Tacka;
const double eps(1E-10);

class Trougao {
    Tacka T1, T2, T3;
   
    static bool Provjera(int index) {
        if(index < 1 || index > 3) 
            return false;
        return true;
    } 
    
    bool DaLiJeIstoOrjenisano(const Tacka &t1, const Tacka &t2, const Tacka &t3) const{
        if(Orijentacija(t1, t2, t3) == 1) return true;
        return false;
    }
    
    static bool IsteStranice(const Trougao &t1, const Trougao &t2) {
        int iste_stranice(0);
        for(int i = 1; i <= 3; i++) {
            for(int j = 1; j <= 3; j++) 
                if(std::fabs(t1.DajStranicu(i) - t2.DajStranicu(j)) <= eps * std::fabs(t1.DajStranicu(i) + std::fabs(t2.DajStranicu(j)))) {
                    iste_stranice++;
                    break;
                }
        }
        if(iste_stranice == 3) return true;
        return false;
    }

public:

    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3); }
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1, t2, t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
        T1 = t1; T2 = t2; T3 = t3;
    }
    
    void Postavi(int indeks, const Tacka &t) {
        if(Provjera(indeks) == false) throw std::range_error("Nekorektan indeks");
        if(indeks == 1) T1 = t;
        if(indeks == 2) T2 = t;
        if(indeks == 3) T3 = t;
        if(Orijentacija(T1, T2, T3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
    }
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double o(t1.first*(t2.second - t3.second) + t2.first*(t3.second - t1.second) + t3.first*(t1.second - t2.second));
        if(o > 0) return 1;
        else if(o < 0) return -1;
        else return 0;
    }
    
    Tacka DajTjeme(int indeks) const {
        if(Provjera(indeks) == false) throw std::range_error("Nekorektan indeks");
        if(indeks == 1) return T1;
        else if(indeks == 2) return T2;
        else return T3;
    }
    
    double DajStranicu(int indeks) const {
        if(Provjera(indeks) == false) throw std::range_error("Nekorektan indeks");
        if(indeks == 1) return sqrt((T2.first - T3.first)*(T2.first - T3.first) + (T2.second - T3.second)*(T2.second - T3.second));
        else if(indeks == 2) return sqrt((T1.first - T3.first)*(T1.first - T3.first) + (T1.second - T3.second)*(T1.second - T3.second));
        else return sqrt((T2.first - T1.first)*(T2.first - T1.first) + (T2.second - T1.second)*(T2.second - T1.second));
    }
    
    double DajUgao(int indeks) const {
        if(Provjera(indeks) == false) throw std::range_error("Nekorektan indeks");
        double a, b, c;
        a = double(DajStranicu(2)*DajStranicu(2) + DajStranicu(3)*DajStranicu(3) - DajStranicu(1)*DajStranicu(1)) / (2*DajStranicu(2)*DajStranicu(3));
        b = double(DajStranicu(1)*DajStranicu(1) + DajStranicu(3)*DajStranicu(3) - DajStranicu(2)*DajStranicu(2)) / (2*DajStranicu(1)*DajStranicu(3));
        c = double(DajStranicu(1)*DajStranicu(1) + DajStranicu(2)*DajStranicu(2) - DajStranicu(3)*DajStranicu(3)) / (2*DajStranicu(1)*DajStranicu(2));
        if(indeks == 1) return acos(a);
        else if(indeks == 2) return acos(b);
        else return acos(c);
    }
    
    Tacka DajCentar() const {
        Tacka t;
        t.first = (T1.first + T2.first + T3.first)/3.;
        t.second = (T1.second + T2.second + T3.second)/3.;
        return t;
    }
    
    double DajObim() const {
        return (DajStranicu(1) + DajStranicu(2) + DajStranicu(3));
    }
    double DajPovrsinu() const {
        double P = 1./2 * abs(T1.first * (T2.second - T3.second) + T2.first * (T3.second - T1.second) + T3.first * (T1.second - T2.second));  
        return P;
    }
    
    bool DaLiJePozitivnoOrijentiran() const {
        if (Orijentacija(T1, T2, T3) == 1) return true;
        return false;
    }
    
    bool DaLiJeUnutra(const Tacka &t) const {
        if(DaLiJeIstoOrjenisano(T1, T2, T3) == DaLiJeIstoOrjenisano(T1, T2, t) == DaLiJeIstoOrjenisano(T2, T3, t) == DaLiJeIstoOrjenisano(T3, T1, t)) 
            return true;
        return false;
    }
    
    void Ispisi() const {
        std::cout << "((" << T1.first << "," << T1.second <<"),(" << T2.first <<"," << T2.second <<"),(" << T3.first <<"," << T3.second <<"))";
    }
    
    void Transliraj(double delta_x, double delta_y) {
        T1.first += delta_x; T2.first += delta_x; T3.first += delta_x;
        T1.second += delta_y; T2.second += delta_y; T3.second += delta_y;
    }
    
    void Centriraj(const Tacka &t) {
        double delta_x = (t.first * 3 - (T1.first + T2.first + T3.first))/3.;
        double delta_y = (t.second * 3 - (T1.second + T2.second + T3.second))/3.;
        T1.first += delta_x; T2.first += delta_x; T3.first += delta_x;
        T1.second += delta_y; T2.second += delta_y; T3.second += delta_y;
    }
    
    void Rotiraj(const Tacka &t, double ugao) {
        T1.first = t.first + (T1.first - t.first)*cos(ugao) - (T1.second - t.second)*sin(ugao);
        T1.second = t.second + (T1.first - t.first)*sin(ugao) + (T1.second - t.second)*cos(ugao);
        T2.first = t.first + (T2.first - t.first)*cos(ugao) - (T2.second - t.second)*sin(ugao);
        T2.second = t.second + (T2.first - t.first)*sin(ugao) + (T2.second - t.second)*cos(ugao);
        T3.first = t.first + (T3.first - t.first)*cos(ugao) - (T3.second - t.second)*sin(ugao);
        T3.second = t.second + (T3.first - t.first)*sin(ugao) + (T3.second - t.second)*cos(ugao);
    }
    
    void Skaliraj(const Tacka &t, double faktor) {
        if(faktor - 0 < eps) throw std::domain_error("Nekorektan faktor skaliranja");
        T1.first = t.first + faktor*(T1.first - t.first);
        T1.second = t.second + faktor*(T1.second - t.second);
        T2.first = t.first + faktor*(T2.first - t.first);
        T2.second = t.second + faktor*(T2.second - t.second);
        T3.first = t.first + faktor*(T3.first - t.first);
        T3.second = t.second + faktor*(T3.second - t.second);
    }
    
    void Rotiraj(double ugao) {
        Tacka t = DajCentar();
        T1.first = t.first + (T1.first - t.first)*cos(ugao) - (T1.second - t.second)*sin(ugao);
        T1.second = t.second + (T1.first - t.first)*sin(ugao) + (T1.second - t.second)*cos(ugao);
        T2.first = t.first + (T2.first - t.first)*cos(ugao) - (T2.second - t.second)*sin(ugao);
        T2.second = t.second + (T2.first - t.first)*sin(ugao) + (T2.second - t.second)*cos(ugao);
        T3.first = t.first + (T3.first - t.first)*cos(ugao) - (T3.second - t.second)*sin(ugao);
        T3.second = t.second + (T3.first - t.first)*sin(ugao) + (T3.second - t.second)*cos(ugao);
    }
    
    void Skaliraj(double faktor) {
        if(faktor - 0 < eps) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka t = DajCentar();
        T1.first = t.first + faktor*(T1.first - t.first);
        T1.second = t.second + faktor*(T1.second - t.first);
        T2.first = t.first + faktor*(T2.first - t.first);
        T2.second = t.second + faktor*(T2.second - t.first);
        T3.first = t.first + faktor*(T3.first - t.first);
        T3.second = t.second + faktor*(T3.second - t.first);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    std::vector<Tacka> trougao1 {t1.T1, t1.T2, t1.T3};
    std::vector<Tacka> trougao2 {t2.T1, t2.T2, t2.T3};
    int iste_tacke(0);
    for(auto x: trougao1) {
        for(auto y: trougao2)
            if(std::fabs(x.first - y.first) <= eps * (std::fabs(x.first) + std::fabs(y.first)) && std::fabs(x.second - y.second) <= eps * (std::fabs(x.second) + std::fabs(y.second))) { 
                iste_tacke++;
                break;
            }
    }
    if(iste_tacke == 3) return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    if(Trougao::Orijentacija(t1.T1, t1.T2, t1.T3) != Trougao::Orijentacija(t2.T1, t2.T2, t2.T3))
        if(Trougao::IsteStranice(t1, t2)) return true;
    return false;
}

int main ()
{
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n;
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v;
    for(int i = 0; i < n; i++) {
        Tacka t1, t2, t3;
        for(;;){
            std::cout << "Unesite podatke za "<< i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin >> t1.first >> t1.second;
            std::cin >> t2.first >> t2.second;
            std::cin >> t3.first >> t3.second;
            try{
                Trougao T(t1, t2, t3);
                break;
            } catch(std::domain_error e){
                std::cout << e.what() << ", ponovite unos!" << std::endl;
            }
        }
        std::shared_ptr<Trougao> pok = std::make_shared<Trougao> (t1, t2, t3);
        v.push_back(pok);
    }
try {
    std::cout << "Unesite vektor translacije (dx dy): ";
    double delta_x, delta_y;
    std::cin >> delta_x >> delta_y;
    std::cout << "Unesite ugao rotacije: ";
    double ugao;
    std::cin >> ugao;
    std::cout << "Unesite faktor skaliranja: ";
    double faktor;
    std::cin >> faktor;
    
    std::cout << "Trouglovi nakon obavljenih transformacija: ";
    std::transform(v.begin(), v.end(), v.begin(), [delta_x, delta_y](std::shared_ptr<Trougao> s) -> std::shared_ptr<Trougao> {
        s -> Transliraj(delta_x, delta_y); 
        return s;
    });
    std::transform(v.begin(), v.end(), v.begin(), [ugao] (std::shared_ptr<Trougao> s) -> std::shared_ptr<Trougao> {
        s -> Rotiraj(ugao);
        return s;
    });
    std::transform(v.begin(), v.end(), v.begin(), [faktor] (std::shared_ptr<Trougao> s) -> std::shared_ptr<Trougao> {
        s -> Skaliraj(s -> DajTjeme(1), faktor);
        return s;
    });

    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) {
        return p1 -> DajPovrsinu() < p2 -> DajPovrsinu(); });
        
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> p) { std::cout << std::endl;
        return p -> Ispisi(); });
    
    std::cout << "\nTrougao sa najmanjim obimom: ";
    auto trg = *std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) {
        return p1 -> DajObim() < p2 -> DajObim(); });
    for(int i = 0; i < v.size(); i++){
        if(v[i] == trg) v[i] -> Ispisi();
    }
    bool identicni(false), podudarni(false);
    int br1(0), br2(0);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(DaLiSuIdenticni(*v[i], *v[j])) {
                identicni = true;
                if(br1 == 0) std::cout << "\nParovi identicnih trouglova: \n";
                v[i] -> Ispisi(); std::cout << " i "; v[j] -> Ispisi();
                std::cout << std::endl;
                br1++;
            }
        }
    } 
    if(identicni == false) std::cout << "\nNema identicnih trouglova!";
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(DaLiSuPodudarni(*v[i], *v[j])) {
                podudarni = true;
                if(br2 == 0) std::cout << "Parovi podudarnih trouglova: \n";
                v[i] -> Ispisi(); std::cout << " i "; v[j] -> Ispisi();
                std::cout << std::endl;
                br2++;
            }
        }
    }
    
    if(podudarni == false) std::cout << "\nNema podudarnih trouglova!";
    
/*    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(DaLiSuSlicni(*v[i], *v[j])) {
                slicni = true;
                if(br3 == 0) std::cout << "Parovi slicnih trouglova: \n";
                v[i] -> Ispisi(); std::cout << " i "; v[j] -> Ispisi();
                std::cout << std::endl;
                br3++;
            }
        }
    }
    if(slicni == false) std::cout << "\nNema slicnih trouglova!";
*/    
} catch(std::domain_error e) {
    std::cout << e.what() << std::endl;
} catch(std::range_error e) {
    std::cout << e.what() << std::endl;
}
	return 0;
}