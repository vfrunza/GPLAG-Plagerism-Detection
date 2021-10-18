/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

const double PI (4 * std::atan(1));
const double EPS (0.0000000001);

class Kugla {
    double x, y, z, r;
    bool JeLiIstiCentar (const Kugla &k) const {
        return ((std::fabs(k.x - this->x) <= EPS * (std::fabs(k.x) + std::fabs(this->x))) && (std::fabs(k.y - this->y) <= EPS * (std::fabs(k.y) + std::fabs(this->y))) &&
           (std::fabs(k.z - this->z) <= EPS * (std::fabs(k.z) + std::fabs(this->z))));
    }
    
    bool JeLiIstiPoluprecnik(const Kugla &k) const {
        return (std::fabs(k.r - this->r) <= EPS * (std::fabs(k.r) + std::fabs(this->r)));
    }
    
    bool Udaljenost(const Kugla &k) const {
        double d;
        d = (k.x - this->x) * (k.x - this->x) + (k.y - this->y) * (k.y - this->y) + (k.z - this->z) * (k.z - this->z);
      
        return std::sqrt(d);
    }
    
    bool JesuLiJednakaDvaBroja(double x, double y) {
        return std::fabs(x - y) <= EPS * (std::fabs(x) + std::fabs(y));
    }
    
public: 
    explicit Kugla(double r = 0) {
        if (r < 0)
            throw std::domain_error("Ilegalan poluprecnik");
        x = 0; y = 0; z = 0; Kugla::r = r;
    }
    
    Kugla(double x, double y, double z, double r = 0) {
        if (r < 0)
            throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
        Kugla::r = r;
    }
    
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if (r < 0)
            throw std::domain_error("Ilegalan poluprecnik");
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
        Kugla::r = r;
    }
    
    double DajX() const { return x; }
    
    double DajY() const { return y; }
    
    double DajZ() const { return z; }
    
    std::tuple<double, double, double> DajCentar() const {
        std::tuple<double, double, double> centar;
        centar = std::make_tuple(x, y, z);
        
        return centar;
    }
    
    double DajPoluprecnik() const { return r; }
    
    double DajPovrsinu() const {
        if (std::fabs(r) <= EPS * std::fabs(r)) // if(r == 0)
            return 0;
        return 4 * r * r * PI;
    }
    
    double DajZapreminu() const {
        if (std::fabs(r) <= EPS * std::fabs(r)) 
            return 0;
        return 4 / 3 * PI * r * r * r; 
    }
    
    Kugla &PostaviX(double x) {
        Kugla::x = x;
        return *this;
    }
    
    Kugla &PostaviY(double y) {
        Kugla::y = y;
        return *this;
    }
    
    Kugla &PostaviZ(double z) {
        Kugla::z = z;
        return *this;
    }
    
    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
        
        return *this;
    }
    
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
        
        return *this;
    }
    
    Kugla &PostaviPoluprecnik(double r) {
        if (r < 0)
            throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r = r;
        
        return *this;
    }
    
    void Ispisi() const {
        std::cout << "{(" << Kugla::DajX() << "," << Kugla::DajY() << "," << Kugla::DajZ() << ")," << Kugla::DajPoluprecnik() << "}" << std::endl;
    }
    
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x += delta_x;
        y += delta_y;
        z += delta_z;
    }
    
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const {
        
        return k.Udaljenost(*this) + k.DajPoluprecnik() < this->DajPoluprecnik(); // ILI MANJE ILI JEDNAKO
    }
    
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    if (std::fabs(k1.r) <= EPS * std::fabs(k1.r) && std::fabs(k2.r) >= EPS * std::fabs(k2.r)) // r1 = 0 a r2 != 0
        return false;
    else if (std::fabs(k1.r) >= EPS * std::fabs(k1.r) && std::fabs(k2.r) >= EPS * std::fabs(k2.r)) // r1 != 0 a r2 = 0
        return false;
    else if (std::fabs(k1.r) <= EPS * std::fabs(k1.r) && std::fabs(k2.r) <= EPS * std::fabs(k2.r) && 
        std::fabs(k1.x - k2.x) <= EPS * (std::fabs(k1.x) + std::fabs(k2.x)) &&
        std::fabs(k1.y - k2.y) <= EPS * (std::fabs(k1.y) + std::fabs(k2.y)) &&
        std::fabs(k1.z - k2.z) <= EPS * (std::fabs(k1.z) + std::fabs(k2.z)))
            return true;
    if (k1.JeLiIstiCentar(k2) && k1.JeLiIstiPoluprecnik(k2))
           return true;
    return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    return (k1.JeLiIstiPoluprecnik(k2));

}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    return k1.JeLiIstiCentar(k2);
}

//Sta ako je poluprecnik nula, kakvo je to dodirivanje haha
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    double d, zbir_r;
    d = k1.Udaljenost(k2);
    zbir_r = k1.r + k2.r;
    // ako je udaljenost od centara jednaka zbiru poluprecnika
    return std::fabs(d - zbir_r) <= EPS * (std::fabs(d) + std::fabs(zbir_r));
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    bool dodiruju_se(false);
    // ako je udaljenost od centara jednaka razlici poluprecnika
    if (k1.r > k2.r) {
        double d, razlika_r;
        d = k1.Udaljenost(k2);
        razlika_r = k1.r - k2.r;
        if(std::fabs(d - razlika_r) <= EPS * (std::fabs(d) + std::fabs(razlika_r)))
            dodiruju_se = true;
    }
    else if (k2.r > k1.r) {
        double d, razlika_r;
        d = k1.Udaljenost(k2);
        razlika_r = k2.r - k1.r;
        if(std::fabs(d - razlika_r) <= EPS * (std::fabs(d) + std::fabs(razlika_r)))
            dodiruju_se = true;
    }
    return dodiruju_se;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    return k1.r + k2.r > k1.Udaljenost(k2);
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    return DaLiSeSijeku(k1, k2) || k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1);
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return k1.Udaljenost(k2);
}

int main ()
{
    std::cout << "Unesite broj kugla: ";
    int n;
    std::cin >> n;
    while (!std::cin || std::cin.peek() != '\n' || n <= 0) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n'); 
        std::cin >> n;
    }
           
    std::vector<std::shared_ptr<Kugla>> vekt;
    double x, y, z, r;
    for (int i = 1 ; i <= n ; i++) {
        std::cout << "Unesite centar " << i << ". kugle: ";
        std::cin >> x >> y >> z;
        while (!std::cin) {
            std::cout << "Neispravan centar" << std::endl << "Unesite centar " << i << ". kugle: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cin >> x >> y >> z;
        }
        std::cout << "Unesite poluprecnik " << i << ". kugle: ";
        std::cin >> r;
        if (!std::cin || r < 0) {
            std::cout << "Ilegalan poluprecnik" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            i--;
        }
        
        else {
            std::shared_ptr<Kugla> pok;
            pok = std::make_shared<Kugla>(x, y, z, r);
            vekt.push_back(pok);
        }
    }
    
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x, delta_y, delta_z;
    std::cin >> delta_x >> delta_y >> delta_z;
    
    std::transform(vekt.begin(), vekt.end(), vekt.begin(), [delta_x, delta_y, delta_z] (std::shared_ptr<Kugla> &pok) {
         pok->Transliraj(delta_x, delta_y, delta_z); 
         return pok; 
    });
    
    std::sort(vekt.begin(), vekt.end(), [](std::shared_ptr<Kugla> kugla1, std::shared_ptr<Kugla> kugla2) {
        return kugla1->DajZapreminu() < kugla2->DajZapreminu();
    });
    
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(vekt.begin(), vekt.end(), [](std::shared_ptr<Kugla> pok) {
        pok->Ispisi();
    });
    
    auto najveca_povrsina = std::max_element(vekt.begin(), vekt.end(), [vekt](std::shared_ptr<Kugla> kugla1, std::shared_ptr<Kugla> kugla2) {
       
        return kugla1->DajPovrsinu() < kugla2->DajPovrsinu();
    });
    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*najveca_povrsina)->Ispisi();
    std::cout << std::endl;
    
    auto pok(vekt.begin());
    int broj(0);
    std::for_each(vekt.begin(), vekt.end(), [&](std::shared_ptr<Kugla> kugla1) {
        pok++;
        std::for_each(pok, vekt.end(), [&](std::shared_ptr<Kugla> kugla2) {
            if (DaLiSeSijeku(*kugla1, *kugla2)) {
                std::cout << "Presjecaju se kugle: ";
                broj++;
                kugla1->Ispisi();
                kugla2->Ispisi();
            }
        });
    });
    
    if (broj == 0)
        std::cout << "Ne postoje kugle koje se presjecaju!" << std::endl;
    
	return 0;
}
