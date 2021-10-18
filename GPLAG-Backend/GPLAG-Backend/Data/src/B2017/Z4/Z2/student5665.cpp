/B2017/2018: Zadaća 4, Zadatak 2

#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <new>
#include <algorithm>

// KOPIRAN PRETHODNI ZADATAK! zatim izmijenjen



const double pi=4*atan(1);
const double eps=pow(10, -10);

class NepreklapajucaKugla {
    double X, Y, Z, R;
    NepreklapajucaKugla *prije;
    static NepreklapajucaKugla *posljednja;
    bool Preklapanje(const NepreklapajucaKugla &k1, double x, double y, double z, double r);
public:
    explicit NepreklapajucaKugla(double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        
        for (NepreklapajucaKugla *p=posljednja; p!=nullptr; p=p->prije)
            if (Preklapanje(*p, 0, 0, 0, r)==true) throw std::logic_error("Nedozvoljeno preklapanje");
        
        X=0; Y=0; Z=0; R=r;
        
        if(posljednja==nullptr) prije=nullptr;
        else prije=posljednja;
        posljednja=this;
    }
    
    NepreklapajucaKugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        
        for (NepreklapajucaKugla *p=posljednja; p!=nullptr; p=p->prije)
            if (Preklapanje(*p, x, y, z, r)==true) throw std::logic_error("Nedozvoljeno preklapanje");
        
        X=x; Y=y; Z=z; R=r;
        
        if(posljednja==nullptr) prije=nullptr;
        else prije=posljednja;
        posljednja=this;
    }
    
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        
        for (NepreklapajucaKugla *p=posljednja; p!=nullptr; p=p->prije)
            if (Preklapanje(*p, std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r)==true) throw std::logic_error("Nedozvoljeno preklapanje");
        
        X=std::get<0>(centar); Y=std::get<1>(centar); Z=std::get<2>(centar); R=r;
        
        if(posljednja==nullptr) prije=nullptr;
        else prije=posljednja;
        posljednja=this;
    }
    
    ~NepreklapajucaKugla() {
        if (posljednja!=nullptr && posljednja->prije!=nullptr && this->prije!=nullptr) {
            if (this==posljednja) posljednja=this->prije;
            if (this->prije==nullptr) {
                NepreklapajucaKugla *prethodni=posljednja;
                for (NepreklapajucaKugla *p=posljednja->prije; p!=nullptr; p=p->prije) {
                    if (p==this) prethodni->prije=p->prije;
                    prethodni=p;
                }
            }   
        }
    }
    
    NepreklapajucaKugla (const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla & operator=(const NepreklapajucaKugla &k) = delete;
    double DajX() const { return X; }
    double DajY() const { return Y; }
    double DajZ() const { return Z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(X, Y, Z); }
    double DajPoluprecnik() const { return R; }
    double DajPovrsinu() const { return 4*pi*R*R; }
    double DajZapreminu() const { return (4/double(3))*pi*R*R*R; }
    NepreklapajucaKugla &PostaviX(double x) { X=x; return *this; }
    NepreklapajucaKugla &PostaviY(double y) { Y=y; return *this; }
    NepreklapajucaKugla &PostaviZ(double z) { Z=z; return *this; }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) { X=x; Y=y; Z=z; return *this; }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) { X=std::get<0>(centar); Y=std::get<1>(centar); Z=std::get<2>(centar); return *this; }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) { if(r<0) throw std::domain_error("Ilegalan poluprecnik"); R=r; return *this; }
    void Ispisi() const { std::cout << "{(" << X << "," << Y << "," << Z << ")," << R << "}" << std::endl; }
    void Transliraj(double delta_x, double delta_y, double delta_z) { X+=delta_x; Y+=delta_y; Z+=delta_z; } 
    
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const;
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2); 
};

NepreklapajucaKugla *NepreklapajucaKugla::posljednja(nullptr);



// provjeriti za svaki slucaj
bool NepreklapajucaKugla::DaLiSadrzi(const NepreklapajucaKugla &k) const {
    // d - udaljenost centara
    double d=sqrt(pow((X-k.X), 2) + pow((Y-k.Y), 2) + pow((Z-k.Z), 2));
    double rp=fabs(R-k.R); // razlika poluprecnika
    if ((d<R || (fabs(d-R)<eps*(fabs(d)+fabs(R)))) && ((d<rp) || (fabs(d-rp)<eps*(fabs(d)+fabs(rp)))))
        return true;
    return false;
}


double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return sqrt(pow((k2.X-k1.X), 2) + pow((k2.Y-k1.Y), 2) + pow((k2.Z-k1.Z), 2));
}


bool NepreklapajucaKugla::Preklapanje(const NepreklapajucaKugla &k1, double x, double y, double z, double r) {
    // d - udaljenost centara
    double d=sqrt(pow((x-k1.X), 2) + pow((y-k1.Y), 2) + pow((z-k1.Z), 2));
    double zp=k1.R+r; // zbir poluprecnika
    if (d<zp || (fabs(d-zp)<eps*(fabs(d)+fabs(zp)))) return true;
    return false;
}



int main ()
{   
    int n;
    std::cout << "Unesite broj kugli: ";
    std::cin >> n;
    while (!std::cin || n<1) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> n;
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> v;
    
    
    for (int i=0; i<n; i++) {
        double x, y, z, r;
        std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
        std::cin >> x >> y >> z;
        while (!std::cin) {
            std::cout << "Neispravan centar, unesite ponovo:" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> x >> y >> z;
        }
        std::cout << "Unesite poluprecnik: ";
        std::cin >> r;
        while (r<0 || !std::cin) {
            std::cout << "Neispravan poluprecnik, unesite ponovo:"<< std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> r;
        }
        
        try {
            v.push_back(std::make_shared<NepreklapajucaKugla>(x, y, z, r));
        }
        catch (std::logic_error e) {
            std::cout << e.what() << std::endl;
            i--;
        }
    }
    
    std::sort (std::begin(v), std::end(v), [] (std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2) { return (*k1).DajPovrsinu() < (*k2).DajPovrsinu(); });
    
    std::cout << std::endl << "Kugle nakon obavljenog sortiranja: " << std::endl;
    
    std::for_each (std::begin(v), std::end(v), [] (std::shared_ptr<NepreklapajucaKugla> k) { (*k).Ispisi(); });
    
	return 0;
}