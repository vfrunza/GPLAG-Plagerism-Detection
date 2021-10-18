/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>

const double PI = 4*atan(1);  // da li je ovo dobro;

class Kugla {
    double x, y, z, r;
    
public:
    explicit Kugla(double r = 0){
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r = r;
        x=0; y=0; z=0; // koordinatni pocetak
    }
    Kugla(double x, double y, double z, double r = 0){
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r = r;
        Kugla::x=x; Kugla::y=y; Kugla::z=z;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r = r;
        
    }
    double DajX() const {
        return x;
    }
    double DajY() const {
        return y;
    }
    double DajZ() const {
        return z;
    }
    std::tuple<double, double,double> DajCentar() const {
        return std::make_tuple(x, y, z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*r*r*PI;
    }
    double DajZapreminu() const{
        return 4*r*r*r*PI/3;
    }
    Kugla &PostaviX(double x){
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY(double y){
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ(double z){
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z){
        Kugla::x=x; Kugla::y=y; Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r){
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        x+=delta_x; y+=delta_y; z+=delta_z;
    }
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

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    if(k1.DajX()!=k2.DajX() || k1.DajY()!=k2.DajY() || k1.DajZ()!=k2.DajZ() || k1.DajPoluprecnik()!=k2.DajPoluprecnik())return false;
    return true;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    if(k1.DajPoluprecnik()!=k2.DajPoluprecnik())return false;
    return true;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    if(k1.DajX()!=k2.DajX() || k1.DajY()!=k2.DajY() || k1.DajZ()!=k2.DajZ())return false;
    return true;
}

/*bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    
}

bool Kugla::DaLiSadrzi(const Kugla &k) const {
    
}*/

double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return std::sqrt(std::pow(2, k1.DajX()-k2.DajX()) + std::pow(2, k1.DajY()-k2.DajY()) + std::pow(2, k1.DajZ()-k2.DajZ()));    
}

int main ()
{
    int n;
    std::cout << "Unesite broj kugla: ";
    std::cin >> n;
    for(int i=0; i<n; i++){
        double pomocna_a, pomocna_b, pomocna_c;
        std::cout << "Unesi centar " << i+1 << ". kugle: ";
        std::cin >> pomocna_a >> pomocna_b >> pomocna_c;
        make tuple ...... dinamicki alociraj klasuu ...
    }
	return 0;
}
