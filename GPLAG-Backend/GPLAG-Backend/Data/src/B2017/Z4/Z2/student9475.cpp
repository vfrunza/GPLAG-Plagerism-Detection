/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double epsilon=pow(10,-10);

class NepreklapajucaKugla
{
    double x, y, z, r;
    bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
public:
    explicit NepreklapajucaKugla(double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
        NepreklapajucaKugla::x=0;
        NepreklapajucaKugla::y=0;
        NepreklapajucaKugla::z=0;
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
        NepreklapajucaKugla::x=std::get<0>(centar);
        NepreklapajucaKugla::y=std::get<1>(centar);
        NepreklapajucaKugla::z=std::get<2>(centar);
    }
    NepreklapajucaKugla(const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla &operator = (const NepreklapajucaKugla &k) = delete;
    double DajX() const {
        return x;
    }
    double DajY() const {
        return y;
    }
    double DajZ() const {
        return z;
    }
    std::tuple<double, double, double> DajCentar() const {      
        return std::tie(x,y,z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 16*r*r*atan(1);
    }
    double DajZapreminu() const {
        return (16*r*r*r*atan(1))/3;
    }
    NepreklapajucaKugla &PostaviX(double x) {
        NepreklapajucaKugla::x=x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        NepreklapajucaKugla::y=y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        NepreklapajucaKugla::x=std::get<0>(centar);
        NepreklapajucaKugla::y=std::get<1>(centar);
        NepreklapajucaKugla::z=std::get<2>(centar);
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout << "{" << "(" << x << "," << y << "," << z << ")," << r << "}" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        NepreklapajucaKugla::x+=delta_x;
        NepreklapajucaKugla::y+=delta_y;
        NepreklapajucaKugla::z+=delta_z;
    }

    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return sqrt((k1.x-k2.x)*(k1.x-k2.x) + (k1.y-k2.y)*(k1.y-k2.y) + (k1.z-k2.z)*(k1.z-k2.z));
}

int main ()
{

    int n;
    std::cout << "Unesite broj kugli: ";
    while(true) {
        try {
            std::cin >> n;
            if(!std::cin || n<=0) {
                std::cin.clear();
                std::cin.ignore(100000,'\n');
                throw std::domain_error("Neispravan broj kugli, unesite ponovo!");
            }
            break;
        } catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
    }


    double x, y, z, r;
    std::vector<std::shared_ptr<NepreklapajucaKugla>> kugle(n);
    for(int i=0; i<n; i++) {
        try {
            std::cout << "Unesite centar za "  << i+1 << ". kuglu: ";
            std::cin >> x;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(100000,'\n');
                throw std::domain_error("Neispravan centar");
            }
            std::cin >> y;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(100000,'\n');
                throw std::domain_error("Neispravan centar");
            }
            std::cin >> z;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(100000,'\n');
                throw std::domain_error("Neispravan centar");
            }
            std::cout << "Unesite poluprecnik: ";
            std::cin >> r;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(100000,'\n');
                throw std::domain_error("Ilegalan poluprecnik");
            }
            kugle[i]=std::make_shared<NepreklapajucaKugla>(x,y,z,r);
        } catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            i--;
        }
    }
    
    std::sort(kugle.begin(), kugle.end(), [](std::shared_ptr<NepreklapajucaKugla> a, std::shared_ptr<NepreklapajucaKugla> b) {
        return a->DajPovrsinu()<b->DajPovrsinu();
    });
    
    std::cout << "Kugle nakon obavljenog sortiranja: " << std::endl;
    for(int i=0; i<kugle.size(); i++) {
        kugle[i]->Ispisi();
    }

    return 0;
}

