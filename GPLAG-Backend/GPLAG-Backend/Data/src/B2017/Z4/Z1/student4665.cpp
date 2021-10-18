/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <memory>
#include <vector>
const double Eps(1e-10);

bool JesuLiJednaki(double x, double y) {
 return std::fabs(x - y) <= Eps * (std::fabs(x) + std::fabs(y));
}

constexpr double pi() { return std::atan(1)*4; }

class Kugla {
    double x,y,z,r;
     void PostaviPrecnik(double precnik) {
        if(precnik < 0) throw std::domain_error("Ilegalan poluprecnik");
        r = precnik;
    }
    double distanceBetween (const Kugla& a) const {
        return sqrt( pow( a.DajX() - this->DajX(), 2 ) + pow( a.DajY() - this->DajY(), 2 ) + pow( a.DajZ() - this->DajZ(), 2 ));
    }
public:
    explicit Kugla(double r = 0) { x = 0; y = 0; z = 0; PostaviPrecnik(r); }
    Kugla(double x, double y, double z, double r = 0) { this->x = x; this->y = y; this->z = z; PostaviPrecnik(r); }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        x = std::get<0>(centar); 
        y = std::get<1>(centar); 
        z = std::get<2>(centar);
        PostaviPrecnik(r);
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x,y,z);}
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4 * r * r * pi();}
    double DajZapreminu() const { return (4 * r * r * r * pi())/3;}
    Kugla &PostaviX(double x) { this->x = x; return *this; }
    Kugla &PostaviY(double y) { this->y = y; return *this; }
    Kugla &PostaviZ(double z) { this->z = z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) { this->x = x; this->z = z; this->y = y; return *this; }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        x = std::get<0>(centar); 
        y = std::get<1>(centar); 
        z = std::get<2>(centar);
        return *this; 
    }
    Kugla &PostaviPoluPrecnik(double r) { PostaviPrecnik(r); return *this; }
    void Ispisi() const { std::cout << "{(" << x <<"," << y << "," << z << ")," << r << "}" << std::endl; }
    void Transliraj(double delta_x, double delta_y, double delta_z) { this->x += delta_x ; this->y += delta_y; this->z += delta_z;}
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const {
        return this->distanceBetween(k) <= this->r && this->distanceBetween(k) + k.DajPoluprecnik() <= this->r;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return k1.distanceBetween(k2);
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    if(!JesuLiJednaki(k1.DajX(),k2.DajX())) return false;
    else
    if(!JesuLiJednaki(k1.DajY(),k2.DajY())) return false;
    else
    if(!JesuLiJednaki(k1.DajZ(),k2.DajZ())) return false;
    else 
    return JesuLiJednaki(k1.DajPoluprecnik(),k2.DajPoluprecnik());
} 

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    return JesuLiJednaki(k1.DajPoluprecnik(),k2.DajPoluprecnik());
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    if(!JesuLiJednaki(k1.DajX(),k2.DajX())) return false;
    else
    if(!JesuLiJednaki(k1.DajY(),k2.DajY())) return false;
    else
    return JesuLiJednaki(k1.DajZ(),k2.DajZ());
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    return JesuLiJednaki(k1.distanceBetween(k2), k1.DajPoluprecnik() + k2.DajPoluprecnik()) && !k1.DaLiSadrzi(k2) && !k2.DaLiSadrzi(k1);
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    return k1.distanceBetween(k2) - (k1.DajPoluprecnik() + k2.DajPoluprecnik()) <= 0;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    if(DaLiSeSijeku(k1,k2)) return true;
    if(k1.DaLiSadrzi(k2)) return true;
    return k2.DaLiSadrzi(k1);
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    return k1.distanceBetween(k2) < (k1.DajPoluprecnik() + k2.DajPoluprecnik()) && !k1.DaLiSadrzi(k2) && !k2.DaLiSadrzi(k1);
}
int main ()
{
    int n;
    std::cout << "Unesite broj kugla: ";
    std::cin >> n;
    while(n <= 0 || std::cin.fail()) {
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(256,'\n');
        }
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin >> n;
    }
    std::vector<std::shared_ptr<Kugla>> niz;
    try {
        for(int i = 1; i <= n; i++) {
            std::cout << "Unesite centar " << i <<". kugle: ";
            double x,y,z;
            std::cin >> x >> y >> z;
            bool nemojNastaviti = false;
            if(std::cin.fail()) {
                if(std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(256,'\n');
                }
                std::cout << "Neispravan centar" << std::endl;
                i--;
                nemojNastaviti= true;
            }
            if(!nemojNastaviti) {
                std::cout << "Unesite poluprecnik " << i <<". kugle: ";
                double r;
                std::cin >> r;
                if(std::cin.fail()) {
                    if(std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(256,'\n');
                    }
                    r = -1;
                }
                std::shared_ptr<Kugla> p(nullptr);
                try {
                    p = std::make_shared<Kugla>(x,y,z,r);
                    niz.push_back(p);
                } catch(std::domain_error e) {
                    std::cout << e.what() << std::endl;
                    i--;
                }
            }
        }
        std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        double delta_x, delta_y, delta_z;
        std::cin >> delta_x >> delta_y >> delta_z;
        while(std::cin.fail()) {
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(256,'\n');
            }
            std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
            std::cin >> delta_x >> delta_y >> delta_z;
        }
        std::transform(std::begin(niz), std::end(niz), std::begin(niz), [delta_x,delta_y, delta_z] (std::shared_ptr<Kugla> p) { p->Transliraj(delta_x, delta_y, delta_z); return p;});
        std::sort(std::begin(niz), std::end(niz), [] (std::shared_ptr<Kugla> p, std::shared_ptr<Kugla> p1) { return p->DajZapreminu() < p1->DajZapreminu();});
        std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
        std::for_each(std::begin(niz), std::end(niz), [](std::shared_ptr<Kugla> p) { p->Ispisi();});
        std::cout << "Kugla sa najvecom povrsinom je: ";
        std::max_element(std::begin(niz), std::end(niz),[] (std::shared_ptr<Kugla> p, std::shared_ptr<Kugla> p1) { return p->DajPovrsinu() < p1->DajPovrsinu();})[0] -> Ispisi();
        bool presjecaju = false;
        int n = 0;
        std::for_each(std::begin(niz), std::end(niz), [&presjecaju,niz, &n](std::shared_ptr<Kugla> p) {n++; std::for_each(std::begin(niz) + n, std::end(niz), [&presjecaju,p](std::shared_ptr<Kugla> p1) {if(DaLiSeSijeku(*p, *p1)) { std::cout << "Presjecaju se kugle: "; p->Ispisi(); p1->Ispisi();presjecaju = true;}}); });
        if(!presjecaju) std::cout << "Ne postoje kugle koje se presjecaju!";
    } catch(std::domain_error e) {
    }
	return 0;
}
