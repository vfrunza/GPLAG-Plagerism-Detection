/B2017/2018: Zadaća 4, Zadatak 1

#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <new>
#include <algorithm>

// Pocetni interfejs kopiran iz postavke zadatka.

const double pi=4*atan(1);
const double eps=pow(10, -10);

class Kugla {
    double X, Y, Z, R;
public:
    explicit Kugla(double r = 0) { if(r<0) throw std::domain_error("Ilegalan poluprecnik"); X=0; Y=0; Z=0; R=r;}
    Kugla(double x, double y, double z, double r = 0) { if(r<0) throw std::domain_error("Ilegalan poluprecnik"); X=x; Y=y; Z=z; R=r;}
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) { if(r<0) throw std::domain_error("Ilegalan poluprecnik"); X=std::get<0>(centar); Y=std::get<1>(centar); Z=std::get<2>(centar); R=r;}
    double DajX() const { return X; }
    double DajY() const { return Y; }
    double DajZ() const { return Z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(X, Y, Z); }
    double DajPoluprecnik() const { return R; }
    double DajPovrsinu() const { return 4*pi*R*R; }
    double DajZapreminu() const { return (4/double(3))*pi*R*R*R; }
    Kugla &PostaviX(double x) { X=x; return *this; }
    Kugla &PostaviY(double y) { Y=y; return *this; }
    Kugla &PostaviZ(double z) { Z=z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) { X=x; Y=y; Z=z; return *this; }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) { X=std::get<0>(centar); Y=std::get<1>(centar); Z=std::get<2>(centar); return *this; }
    Kugla &PostaviPoluprecnik(double r) { if(r<0) throw std::domain_error("Ilegalan poluprecnik"); R=r; return *this; }
    void Ispisi() const { std::cout << "{(" << X << "," << Y << "," << Z << ")," << R << "}" << std::endl; }
    void Transliraj(double delta_x, double delta_y, double delta_z) { X+=delta_x; Y+=delta_y; Z+=delta_z; } 
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};


bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    if ((fabs(k1.X-k2.X)<eps*(fabs(k1.X)+fabs(k2.X))) && (fabs(k1.Y-k2.Y)<eps*(fabs(k1.Y)+fabs(k2.Y)))
    && (fabs(k1.Z-k2.Z)<eps*(fabs(k1.Z)+fabs(k2.Z)))  && (fabs(k1.R-k2.R)<eps*(fabs(k1.R)+fabs(k2.R))))
        return true;
    return false;
}


bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    if (fabs(k1.R-k2.R)<eps*(fabs(k1.R)+fabs(k2.R)))
        return true;
    return false;
}


bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    if ((fabs(k1.X-k2.X)<eps*(fabs(k1.X)+fabs(k2.X))) && (fabs(k1.Y-k2.Y)<eps*(fabs(k1.Y)+fabs(k2.Y))) && (fabs(k1.Z-k2.Z)<eps*(fabs(k1.Z)+fabs(k2.Z))))
        return true;
    return false;
}


bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    // d - udaljenost centara    
    double d=sqrt(pow((k2.X-k1.X), 2) + pow((k2.Y-k1.Y), 2) + pow((k2.Z-k1.Z), 2));
    double zp=k1.R+k2.R; // zbir poluprecnika
    if (fabs(d-zp)<eps*(fabs(d)+fabs(zp)))
        return true;
    return false;
}


bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    // d - udaljenost centara
    double d=sqrt(pow((k2.X-k1.X), 2) + pow((k2.Y-k1.Y), 2) + pow((k2.Z-k1.Z), 2));
    double rp=fabs(k1.R-k2.R); // razlika poluprecnika
    if (fabs(d-rp)<eps*(fabs(d)+fabs(rp)))
        return true;
    return false;
}


bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    // d - udaljenost centara
    double d=sqrt(pow((k2.X-k1.X), 2) + pow((k2.Y-k1.Y), 2) + pow((k2.Z-k1.Z), 2));
    double zp=k1.R+k2.R; // zbir poluprecnika
    if (d<zp) return true;
    return false;
}


bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    // d - udaljenost centara
    double d=sqrt(pow((k2.X-k1.X), 2) + pow((k2.Y-k1.Y), 2) + pow((k2.Z-k1.Z), 2));
    double zp=k1.R+k2.R; // zbir poluprecnika
    double rp=fabs(k1.R-k2.R); // razlika poluprecnika
    if (d<zp && d>rp) return true;
    return false;
}

// PROVJERITI
bool Kugla::DaLiSadrzi(const Kugla &k) const {
    // d - udaljenost centara
    double d=sqrt(pow((X-k.X), 2) + pow((Y-k.Y), 2) + pow((Z-k.Z), 2));
    double rp=fabs(R-k.R); // razlika poluprecnika
    if ((d<R || (fabs(d-R)<eps*(fabs(d)+fabs(R)))) && ((d<rp) || (fabs(d-rp)<eps*(fabs(d)+fabs(rp)))))
        return true;
    return false;
}


double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return sqrt(pow((k2.X-k1.X), 2) + pow((k2.Y-k1.Y), 2) + pow((k2.Z-k1.Z), 2));
}


int main ()
{
    int n;
    std::cout << "Unesite broj kugla: ";
    std::cin >> n;
    while (!std::cin || n<1) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> n;
    }
    std::vector<std::shared_ptr<Kugla>> v;
    
    
    for (int i=0; i<n; i++) {
        double x, y, z, r;
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        std::cin >> x >> y >> z;
        if (!std::cin) {
            std::cout << "Neispravan centar" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            i--;
            continue;
        }
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        std::cin >> r;
        if (r<0 || !std::cin) {
            std::cout << "Ilegalan poluprecnik"<< std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            i--;
            continue;
        }
        v.push_back(std::make_shared<Kugla>(x, y, z, r));
    }
    
    double delta_x, delta_y, delta_z;
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin >> delta_x >> delta_y >> delta_z;
    while (!std::cin) {
        std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> delta_x >> delta_y >> delta_z;
    }
    
    std::transform (std::begin(v), std::end(v), std::begin(v), [delta_x, delta_y, delta_z] (std::shared_ptr<Kugla> k) {
        (*k).Transliraj(delta_x, delta_y, delta_z);
        return k;
    });
    
    std::sort (std::begin(v), std::end(v), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) { return (*k1).DajZapreminu() < (*k2).DajZapreminu(); });
    
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    
    std::for_each (std::begin(v), std::end(v), [] (std::shared_ptr<Kugla> k) { (*k).Ispisi(); });
    
    auto najveci = std::max_element(std::begin(v), std::end(v), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) { return (*k1).DajPovrsinu() < (*k2).DajPovrsinu(); } );
    
    std::cout << "Kugla sa najvecom povrsinom je: ";
    
    // najveci: pokazivac na pokazivac
    (**najveci).Ispisi();
    
    int brojac(0), i(0);
    
    std::for_each (std::begin(v), std::end(v), [&brojac, &i, v] (std::shared_ptr<Kugla> k1) {
        i++;
        std::for_each (std::begin(v)+i, std::end(v), [&brojac, k1] (std::shared_ptr<Kugla> k2) {
           if (DaLiSeSijeku(*k1,*k2)) {
               brojac++;
               std::cout << "Presjecaju se kugle: ";
               (*k1).Ispisi();
               (*k2).Ispisi();
           } 
        });
    });
    
    if (brojac==0) std::cout << "Ne postoje kugle koje se presjecaju!";
    
	return 0;
}