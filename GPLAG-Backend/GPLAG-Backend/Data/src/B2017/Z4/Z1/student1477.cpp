/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <math.h>
#include <vector>
#include <memory>
#include <algorithm>
#define PI 4*atan(1)
#define EPSILON std::pow (10, -10)


class Kugla {
    double x, y, z, r;
public:
    explicit Kugla (double r = 0) {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r = r;
        x = y = z = 0;
    }
    Kugla (double x, double y, double z, double r = 0) {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::x = x; Kugla::y = y; Kugla::z = z; Kugla::r = r;
    }
    explicit Kugla (const std::tuple<double, double, double> &centar, double r = 0) {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        x = std::get<0>(centar); y = std::get<1>(centar); z = std::get<2>(centar);
        Kugla::r = r;
    }
    double DajX () const {return x;}
    double DajY () const {return y;}
    double DajZ () const {return z;}
    std::tuple<double, double, double> DajCentar () const;
    double DajPoluprecnik () const {return r;}
    double DajPovrsinu () const {return 4*PI*DajPoluprecnik()*DajPoluprecnik();}
    double DajZapreminu () const {return (4/3)*(PI*DajPoluprecnik()*DajPoluprecnik()*DajPoluprecnik());}
    Kugla &PostaviX (double x);
    Kugla &PostaviY (double y);
    Kugla &PostaviZ (double z);
    Kugla &PostaviCentar (double x, double y, double z);
    Kugla &PostaviCentar (const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik (double r);
    void Ispisi () const;
    void Transliraj (double delta_x, double delta_y, double delta_z);
    friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi (const Kugla &k) const;
    friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2);
};
std::tuple<double, double, double> Kugla::DajCentar () const {
    std::tuple<double, double, double> centar {x, y, z};
    return centar;
}
Kugla &Kugla::PostaviX (double x) {
    Kugla::x = x;
    return *this;
}
Kugla &Kugla::PostaviY (double y) {
    Kugla::y = y;
    return *this;
}
Kugla &Kugla::PostaviZ (double z) {
    Kugla::z = z;
    return *this;
}
Kugla &Kugla::PostaviCentar (double x, double y, double z) {
    Kugla::x = x;
    Kugla::y = y;
    Kugla::z = z;
    return *this;
}
Kugla &Kugla::PostaviCentar (const std::tuple<double, double, double> &centar) {
    Kugla::x = std::get<0>(centar);
    Kugla::y = std::get<1>(centar);
    Kugla::z = std::get<2>(centar);
    return *this;
}
Kugla &Kugla::PostaviPoluprecnik (double r) {
    if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
    Kugla::r = r;
    return *this;
}
void Kugla::Ispisi () const {
    std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}";
}
void Kugla::Transliraj (double delta_x, double delta_y, double delta_z) {
    x += delta_x; y += delta_y; z += delta_z;
}
bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2) {
    return DaLiSuPodudarne(k1, k2) && DaLiSuKoncentricne(k1, k2);
}
bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2) {
    return abs(k1.r - k2.r) < (abs(k1.r) + abs(k2.r))*EPSILON;
}
bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2) {
    return ((abs(k1.x - k2.x) < (abs(k1.x) + abs(k2.x))*EPSILON) && (abs(k1.y - k2.y) < (abs(k1.y) + abs(k2.y))*EPSILON) && (abs(k1.z - k2.z) < (abs(k1.z) + abs(k2.z))*EPSILON));
}
bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2) {
    return abs(RastojanjeCentara(k1, k2) - (k1.r + k2.r)) < (abs(RastojanjeCentara(k1, k2)) + abs(k1.r + k2.r))*EPSILON;
}
bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2) {
    double razlika;
    if(k1.r > k2. r) razlika = k1.r - k2.r;
    else razlika = k2.r - k1.r;
    return abs(RastojanjeCentara(k1, k2) - razlika) < (abs(RastojanjeCentara(k1, k2)) + abs(razlika))*EPSILON;
}
bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2) { //ako im je udaljenost izmedju centara manja od veceg r
    if (DaLiSeSijeku(k1, k2)) return true;
    return RastojanjeCentara(k1, k2) < k1.r + k2.r;
}
bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2) {
     return RastojanjeCentara(k1, k2) < k1.r + k2.r && RastojanjeCentara(k1, k2) > abs(k1.r - k2.r);
}
bool Kugla::DaLiSadrzi (const Kugla &k) const {
    if (k.r > r) return false;
    return RastojanjeCentara(k, *this) < r;
}
double RastojanjeCentara (const Kugla &k1, const Kugla &k2) {
    return sqrt(pow (k1.x - k2.x, 2) + pow (k1.y - k2.y, 2) + pow(k1.z - k2.z, 2));
}
int main ()
{
    std::cout << "Unesite broj kugla: ";
    int n;
    std::cin >>n;
    std::vector<std::shared_ptr<Kugla>> v (n);
    double x, y, z, r;
    for (int i = 0; i < n; i++) {
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        std::cin >> x >> y >> z;
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        std::cin >> r;
        if (!std::cin || r < 0) {
            std::cout << "Besmisleni podaci" << std::endl;
            i--;
        } else {
            v[i] = std::make_shared<Kugla>(x, y, z, r);
        }
    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double deltax, deltay, deltaz;
    std::cin >> deltax >> deltay >> deltaz;
    
    std::transform (v.begin(), v.end(), v.begin(), [deltax, deltay, deltaz] (std::shared_ptr<Kugla> k) {
         k->Transliraj(deltax, deltay, deltaz);
         return k;
    });
    
    std::sort (v.begin(), v.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajZapreminu() < k2->DajZapreminu();
    });
    
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each (v.begin(), v.end(), [] (std::shared_ptr<Kugla> k) {
        k->Ispisi();
        std::cout << std::endl;
    });
    auto najveci = std::max_element (v.begin(), v.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    });
    auto najveca_povrsina = *najveci;
    std::cout << "Kugla sa najvecom povrsinom je: " ;
    najveca_povrsina->Ispisi();
    std::cout << std::endl;
    bool sijeku_se (false);
    std::for_each (v.begin(), v.end(), [&sijeku_se, v] (std::shared_ptr<Kugla> k1) {
        std::for_each (v.begin(), v.end(), [&sijeku_se, k1] (std::shared_ptr<Kugla> k2) {
            if (k2 > k1) {
                if (DaLiSeSijeku (*k1, *k2)) {
                    sijeku_se = true;
                    std::cout << "Presjecaju se kugle: ";
                    k1->Ispisi();
                    std::cout << std::endl;
                    k2->Ispisi();
                    std::cout << std::endl;
                }
            }
        });
        
    });
    if (!sijeku_se) std::cout << "Ne postoje kugle koje se presjecaju!";
	return 0;
}
