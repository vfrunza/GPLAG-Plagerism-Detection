#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>

bool Jednaki(double x, double y, double Eps = 1e-10) {
    return fabs(x - y) <= Eps * (fabs(x) + fabs(y));
} 

class NepreklapajucaKugla {
    double x, y, z, r;
    NepreklapajucaKugla *prethodna;
    static NepreklapajucaKugla *posljednja;
    static bool DaLiSePresjecaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
        return RastojanjeCentara(k1,k2) < k1.DajPoluprecnik() + k2.DajPoluprecnik() 
            || Jednaki(RastojanjeCentara(k1,k2), k1.DajPoluprecnik() + k2.DajPoluprecnik());
                
    }
    void TestPresjeka() const {
        auto kugla = posljednja;
        while (kugla != nullptr) {
            if(DaLiSePresjecaju(*this, *kugla))
                throw std::logic_error("Nedozvoljeno preklapanje");
            kugla = kugla->prethodna;
        }
    }
    
public:
    explicit NepreklapajucaKugla(double r = 0) { 
        this->x=0; this->y=0; this->z=0; this->r=r;
        PostaviCentar(0,0,0); PostaviPoluprecnik(r); 
        prethodna = posljednja; posljednja = this; 
    }   
    NepreklapajucaKugla(double x, double y, double z, double r = 0) {
        this->x=x; this->y=y; this->z=z; this->r=r;
        PostaviPoluprecnik(r); PostaviCentar(x,y,z); 
        prethodna = posljednja; posljednja = this; 
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
       this->x=std::get<0>(centar);
       this->y=std::get<1>(centar);
       this->z=std::get<2>(centar);
       this->r=r;
       PostaviPoluprecnik(r); PostaviCentar(centar);
       prethodna = posljednja; posljednja = this; 
    }
    NepreklapajucaKugla(const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla operator = (const NepreklapajucaKugla &k) = delete;
    ~NepreklapajucaKugla() { 
        if (this == posljednja) {
            posljednja = this->prethodna;
        }
        else {
            auto kugla(posljednja);
            while (kugla->prethodna != this) kugla = kugla->prethodna;
            kugla->prethodna = this->prethodna;
        }
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const {
        return std::make_tuple(x, y, z);
    }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*4*atan(1); }
    double DajZapreminu() const { return 4./3*r*r*r*4*atan(1); }
    NepreklapajucaKugla &PostaviX(double x) { NepreklapajucaKugla::x = x; TestPresjeka(); return *this; }
    NepreklapajucaKugla &PostaviY(double y) { NepreklapajucaKugla::y = y; TestPresjeka(); return *this; }
    NepreklapajucaKugla &PostaviZ(double z) { NepreklapajucaKugla::z = z; TestPresjeka(); return *this; }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        PostaviX(x); PostaviY(y); PostaviZ(z);
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        PostaviX(std::get<0>(centar)); 
        PostaviY(std::get<1>(centar)); 
        PostaviZ(std::get<2>(centar));
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double &r) {
        if (r < 0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r = r; 
        TestPresjeka();
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ()
                  << ")," << DajPoluprecnik() << "}" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x += delta_x; y += delta_y; z += delta_z;
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);  
    friend bool Jednaki(double x, double y, double Eps);
};

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return sqrt(pow(k2.x-k1.x,2) + pow(k2.y-k1.y,2) + pow(k2.z-k1.z,2));
}

typedef std::shared_ptr<NepreklapajucaKugla> PK;

NepreklapajucaKugla* NepreklapajucaKugla::posljednja(nullptr);

int main ()
{
    int n;
    std::cout << "Unesite broj kugli: ";
    for (;;) {
        std::cin >> n;
        if (!std::cin || n <= 0) {
            std::cin.clear(); std::cin.ignore(1000, '\n');
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        }
        else break;
    }
    try {
        std::vector<PK> kugle(n);
        for (int i = 0; i < n; i++) {
            double x, y, z, r;
            std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
            for (;;) {
                std::cin >> x >> y >> z;
                if (!std::cin) {
                    std::cin.clear(); std::cin.ignore(1000, '\n');
                    std::cout << "Neispravan centar, unesite ponovo:" << std::endl;
                }
                else break;
            }
            std::cout << "Unesite poluprecnik: ";
            for (;;) {
                std::cin >> r;
                if (!std::cin || r < 0) {
                    std::cin.clear(); std::cin.ignore(1000, '\n');
                    std::cout << "Neispravan poluprecnik, unesite ponovo:" << std::endl;
                }
                else break;
            }
            try {
                kugle[i] = std::make_shared<NepreklapajucaKugla>(x,y,z,r);
            }
            catch (std::logic_error e) {
                std::cout << e.what() << std::endl;
                i--;
            }
        }
        std::cout << std::endl;
        std::sort(kugle.begin(), kugle.end(), [](PK k1, PK k2) {
            return k1->DajPovrsinu() < k2->DajPovrsinu();
        });
        std::cout << "Kugle nakon obavljenog sortiranja: " << std::endl;
        std::for_each(kugle.begin(), kugle.end(), [](PK k1) { k1->Ispisi(); });

    }
    catch (...) {
        std::cout << "Problemi sa memorijom";
    }
	return 0;
}
