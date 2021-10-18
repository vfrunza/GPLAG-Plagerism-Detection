/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double EPS {1e-6};
const double PI {4*std::atan(1)};

class Kugla{
    double x, y, z, r;
    public:
    explicit Kugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=0; y=0; z=0; this->r=r; 
    }
    Kugla(double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        this->x=x; this->y=y; this->z=z; this->r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); this->r=r;
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double>DajCentar() const { return std::tuple<double, double, double> {x, y, z}; }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4 * r * r * PI; }
    double DajZapreminu() const { return  4 * r * r * r * PI / 3; }
    Kugla &PostaviX(double x) { this->x=x; return *this; }
    Kugla &PostaviY(double y) { this->y=y; return *this; }
    Kugla &PostaviZ(double z) { this->z=z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) { this->x=x; this->y=y; this->z=z; return *this; }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) { this->x=std::get<0>(centar); this->y=std::get<1>(centar); this->z=std::get<2>(centar); return *this; }
    Kugla &PostaviPoluprecnik(double r) { if(r<0) throw std::domain_error("Ilegalan poluprecnik"); this->r=r; return *this; }
    void Ispisi() const { std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}" << std::endl; }
    void Transliraj(double delta_x, double delta_y, double delta_z) { x+=delta_x; y+=delta_y; z+=delta_z; }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) { if(std::fabs(k1.r-k2.r)<EPS) return true; return false; }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const { return(r+k.r > std::sqrt((k.x-x)*(k.x-x)+(k.y-y)*(k.y-y)+(k.z-z)*(k.z-z))); }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) { return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)); }
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) { 
    return(std::fabs(k1.x-k2.x)<EPS && std::fabs(k1.y-k2.y)<EPS && std::fabs(k1.z-k2.z)<EPS && std::fabs(k1.r-k2.r)<EPS);
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) { 
    return(std::fabs(k1.x-k2.x)<EPS && std::fabs(k1.y-k2.y)<EPS && std::fabs(k1.z-k2.z)<EPS);
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    return(std::fabs(std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))-(k1.r+k2.r)) < EPS);
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    return(std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)) - std::fabs(k1.r-k2.r) < EPS);
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    return(std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)) < (k1.r+k2.r));
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    return(std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)) < (k1.r+k2.r) && 
         std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)) > std::fabs(k1.r-k2.r));
}

int main () {
    std::cout << "Unesite broj kugla: ";
    int n;
    std::cin >> n;
    while(!std::cin || n<=0) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin >> n;
    }
    std::vector<std::shared_ptr<Kugla>> VekPamPnaK(n);
    for(int i=0; i<n; i++) {
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        double x,y,z;
        std::cin >> x >> y >> z;
        if(!std::cin) {
            std::cout << "Neispravan centar" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            i--;
        }
        else {
            std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
            double r;
            std::cin >> r;
            if(!std::cin || r<0) {
                std::cout << "Ilegalan poluprecnik" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                i--;
            }
            else VekPamPnaK[i]=std::make_shared<Kugla>(x,y,z,r);
        }
    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x, delta_y, delta_z;
    std::cin >> delta_x >> delta_y >> delta_z;
    while(!std::cin) {
        std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin >> delta_x >> delta_y >> delta_z;
    }
    std::transform(VekPamPnaK.begin(),VekPamPnaK.end(),VekPamPnaK.begin(),[delta_x, delta_y, delta_z] (std::shared_ptr<Kugla> k) { (*k).Transliraj(delta_x, delta_y, delta_z); return k; });
    std::sort(VekPamPnaK.begin(), VekPamPnaK.end(), [] (std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2) { return (*k1).DajZapreminu() < (*k2).DajZapreminu(); });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(VekPamPnaK.begin(), VekPamPnaK.end(), [] (std::shared_ptr<Kugla> k) { (*k).Ispisi(); });
    std::cout << "Kugla sa najvecom povrsinom je: ";
    auto ispisi=std::max_element(VekPamPnaK.begin(), VekPamPnaK.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) { return (*k1).DajPovrsinu() < (*k2).DajPovrsinu(); });
    (**ispisi).Ispisi();
    int brojac{0};
    std::for_each(VekPamPnaK.begin(),VekPamPnaK.end(),[VekPamPnaK, &brojac] (std::shared_ptr<Kugla> k) { 
        auto iter(VekPamPnaK.begin());
        while(iter != VekPamPnaK.end() && *iter != k) iter++;
        std::for_each(iter, VekPamPnaK.end(), [k, &brojac](std::shared_ptr<Kugla> k1) { 
            if(DaLiSeSijeku(*k,*k1)) {
                std::cout << "Presjecaju se kugle: "; 
                (*k).Ispisi(); 
                (*k1).Ispisi();
                brojac++;
            } 
        }); 
    } );
    if(brojac == 0) std::cout << "Ne postoje kugle koje se presjecaju!";
	return 0;
}
