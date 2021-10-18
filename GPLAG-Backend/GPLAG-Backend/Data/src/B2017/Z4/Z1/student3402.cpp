/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <algorithm>

const long double PI(4*atan(1));
const double eps(1e-10);

class Kugla
{
    double x,y,z,r;
public:
    explicit Kugla(double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=0; y=0; z=0;
        Kugla::r=r;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple <double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        Kugla::r=r;
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
    std::tuple <double, double, double> DajCentar() const {
        return std::make_tuple(x,y,z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*r*r*PI;
    }
    double DajZapreminu() const {
        return 4./3*PI*r*r*r;
    }
    Kugla &PostaviX(double x) {
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple <double, double, double> &centar) {
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const{
        std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}\n";
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
    if(fabs(k1.x-k2.x)<=eps*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<=eps*(fabs(k1.y)+fabs(k2.y)) && 
        fabs(k1.z-k2.z)<=eps*(fabs(k1.z)+fabs(k2.z)) && fabs(k1.r-k2.r)<=eps*(fabs(k1.r)+fabs(k2.r)))
            return true;
    return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    if(fabs(k1.r-k2.r)<=eps*(fabs(k1.r)+fabs(k2.r))) return true;
    return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    if(fabs(k1.x-k2.x)<=eps*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<=eps*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<=eps*(fabs(k1.z)+fabs(k2.z))) 
        return true;
    return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    if(fabs((k1.r+k2.r)-RastojanjeCentara(k1,k2))<=eps*(fabs(k1.r+k2.r)+fabs(RastojanjeCentara(k1,k2)))) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    if((k1.r<k2.r && fabs(RastojanjeCentara(k1,k2)+k1.r - k2.r)<=eps*(fabs(RastojanjeCentara(k1,k2)+k1.r)+fabs(k2.r))) || 
        (k2.r<k1.r && fabs(RastojanjeCentara(k1,k2)+k2.r - k1.r)<=eps*(fabs(RastojanjeCentara(k1,k2)+k2.r)+fabs(k1.r)))) return true;
    return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    if(RastojanjeCentara(k1,k2)<k1.r+k2.r) return true;
    return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    if(!k1.DaLiSadrzi(k2) && !k2.DaLiSadrzi(k1) && DaLiSePreklapaju(k1,k2) && !DaLiSeDodirujuIzvana(k1,k2) && !DaLiSeDodirujuIznutra(k1,k2)) return true;
    return false;
}

bool Kugla::DaLiSadrzi(const Kugla &k) const{
    if(DaLiSuIdenticne(*this, k) || this->r - (RastojanjeCentara(*this, k)+k.r)>-eps*(fabs(RastojanjeCentara(*this, k)+k.r)+fabs(this->r))) return true;
    return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return std::sqrt(std::pow(k1.x-k2.x,2)+std::pow(k1.y-k2.y,2)+std::pow(k1.z-k2.z,2));
}

int main ()
{
    std::vector<std::shared_ptr<Kugla>> kugle;
    int n;
    std::cout << "Unesite broj kugla: ";
    for(;;){
        std::cin >> n;
        if(n>0 && std::cin && std::cin.peek()=='\n') break;
        std::cin.clear(); std::cin.ignore(10000, '\n');
        std::cout << "Neispravan broj kugli, unesite ponovo!\n";
    }
    for(int i(0); i<n; i++){
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        double x,y,z,r;
        try{
            std::cin >> x >> y >> z;
            if(!std::cin){
                std::cin.clear(); std::cin.ignore(10000, '\n');
                throw std::domain_error("Neispravan centar");
            } 
            std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
            std::cin >> r;
            if(!std::cin){
                std::cin.clear(); std::cin.ignore(10000, '\n');
                throw std::domain_error("Ilegalan poluprecnik");
            }
            kugle.push_back(std::make_shared<Kugla>(x,y,z,r));
        }
        catch(std::domain_error e){
            std::cout << e.what() << std::endl;
            i--;
        }
    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x,delta_y,delta_z;
    for(;;){    
        std::cin >> delta_x >> delta_y >> delta_z;
        if(std::cin) break;
        std::cout << "Neispravni parametri translacije, unesite ponovo!\n";
        std::cin.clear(); std::cin.ignore(10000, '\n');
    }
    std::transform(kugle.begin(), kugle.end(), kugle.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> kugla) -> std::shared_ptr<Kugla> {
        kugla->Transliraj(delta_x, delta_y, delta_z); return kugla;
    });
    std::sort(kugle.begin(), kugle.end(), [](std::shared_ptr<Kugla> kugla1, std::shared_ptr<Kugla> kugla2){
        return kugla1->DajZapreminu()<kugla2->DajZapreminu(); 
    });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:\n";
    std::for_each(kugle.begin(), kugle.end(), [](std::shared_ptr<Kugla> kugla){
        kugla->Ispisi();
    });
    std::cout << "Kugla sa najvecom povrsinom je: ";
    auto temp(*std::max_element(kugle.begin(), kugle.end(), [](std::shared_ptr<Kugla> kugla1, std::shared_ptr<Kugla> kugla2){
        return kugla1->DajPovrsinu()<kugla2->DajPovrsinu(); 
    }));
    temp->Ispisi();
    int brojac(0);
    std::for_each(kugle.begin(), kugle.end(), [&brojac, kugle](std::shared_ptr<Kugla> kugla1){
        auto it(std::find(kugle.begin(), kugle.end(), kugla1));
        it++;
        std::for_each(it, kugle.end(), [kugle, kugla1, &brojac](std::shared_ptr<Kugla> kugla2){
           if(DaLiSeSijeku(*kugla1, *kugla2)){ 
               std::cout << "Presjecaju se kugle: ";
               kugla1->Ispisi(); kugla2->Ispisi();
               brojac++;
           }
        });
    });
    if(brojac==0) std::cout << "Ne postoje kugle koje se presjecaju!";
    return 0;
}
