/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double EPS {1e-6};
const double PI {4*std::atan(1)};

class NepreklapajucaKugla{
    double x, y, z, r;
    static NepreklapajucaKugla *PokNaZadnju;
    NepreklapajucaKugla *Prijasnja;
    void PROVJERI(double x, double y, double z, double r) {
        NepreklapajucaKugla *pok{PokNaZadnju};
        while(pok != nullptr) {
            if(std::sqrt((x-(*pok).x)*(x-(*pok).x)+(y-(*pok).y)*(y-(*pok).y)+(z-(*pok).z)*(z-(*pok).z)) <= (r+(*pok).r)) {
                throw std::logic_error("Nedozvoljeno preklapanje");
            }
            pok=(*pok).Prijasnja;
        }
    }
    mutable bool JelBiloKogaPrije{false};
    public:
    ~NepreklapajucaKugla() {}
    explicit NepreklapajucaKugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        PROVJERI(0,0,0,r);
        if(!JelBiloKogaPrije) PokNaZadnju=nullptr;
        x=0; y=0; z=0; this->r=r; 
        Prijasnja=PokNaZadnju;
        PokNaZadnju=this;
        JelBiloKogaPrije=true;
    }
    NepreklapajucaKugla(double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        PROVJERI(x,y,z,r);
        if(!JelBiloKogaPrije) PokNaZadnju=nullptr;
        this->x=x; this->y=y; this->z=z; this->r=r;
        Prijasnja=PokNaZadnju;
        PokNaZadnju=this;
        JelBiloKogaPrije=true;
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        PROVJERI(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r);
        if(!JelBiloKogaPrije) PokNaZadnju=nullptr;
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); this->r=r;
        Prijasnja=PokNaZadnju;
        PokNaZadnju=this;
        JelBiloKogaPrije=true;
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double>DajCentar() const { return std::tuple<double, double, double> {x, y, z}; }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4 * r * r * PI; }
    double DajZapreminu() const { return  4 * r * r * r * PI / 3; }
    NepreklapajucaKugla &PostaviX(double x) { PROVJERI(x,y,z,r); this->x=x; return *this; }
    NepreklapajucaKugla &PostaviY(double y) { PROVJERI(x,y,z,r); this->y=y; return *this; }
    NepreklapajucaKugla &PostaviZ(double z) { PROVJERI(x,y,z,r); this->z=z; return *this; }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) { PROVJERI(x,y,z,r); this->x=x; this->y=y; this->z=z; return *this; }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) { 
        PROVJERI(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r); 
        this->x=std::get<0>(centar); this->y=std::get<1>(centar); this->z=std::get<2>(centar); return *this; 
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) { PROVJERI(x,y,z,r); if(r<0) throw std::domain_error("Ilegalan poluprecnik"); this->r=r; return *this; }
    void Ispisi() const { std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}" << std::endl; }
    void Transliraj(double delta_x, double delta_y, double delta_z) { PROVJERI(x+delta_x,y+delta_y,z+delta_z,r); x+=delta_x; y+=delta_y; z+=delta_z; }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) { return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)); }
};

NepreklapajucaKugla* NepreklapajucaKugla::PokNaZadnju(nullptr);

int main () {
    std::cout << "Unesite broj kugli: ";
    int n;
    std::cin >> n;
    while(!std::cin || n<=0) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin >> n;
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> VekPamPnaK(n);
    for(int i=0; i<n; i++) {
        std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
        double x,y,z;
        std::cin >> x >> y >> z;
        while(!std::cin) {
            std::cout << "Neispravan centar, unesite ponovo:" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cin >> x >> y >> z;
        }
            std::cout << "Unesite poluprecnik: ";
            double r;
            std::cin >> r;
            while(!std::cin || r<0) {
                std::cout << "Neispravan poluprecnik, unesite ponovo:" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cin >> r;
            }
            try{
                VekPamPnaK[i]=std::make_shared<NepreklapajucaKugla>(x,y,z,r);
            }
            catch(std::logic_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
                i--;
            }
    }
    std::sort(VekPamPnaK.begin(), VekPamPnaK.end(), [] (std::shared_ptr<NepreklapajucaKugla> k1,std::shared_ptr<NepreklapajucaKugla> k2) { return (*k1).DajPovrsinu() < (*k2).DajPovrsinu(); });
    std::cout << std::endl << "Kugle nakon obavljenog sortiranja: " << std::endl;
    std::for_each(VekPamPnaK.begin(), VekPamPnaK.end(), [] (std::shared_ptr<NepreklapajucaKugla> k) { (*k).Ispisi(); });
	return 0;
}