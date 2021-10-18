/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <vector>

const double pi=4*atan(1);
const double eps=0.0000000001;

class NepreklapajucaKugla {
    double x, y, z, r;
    
    NepreklapajucaKugla* prethodni;
    static NepreklapajucaKugla* posljednji;
    
    static bool PreklapaSe (double x, double y, double z, double r, NepreklapajucaKugla* pok=nullptr) {
        NepreklapajucaKugla* p(posljednji);
        while (p!=nullptr) {
            if (std::sqrt( (x-(*p).x)*(x-(*p).x)+(y-(*p).y)*(y-(*p).y)+(z-(*p).z)*(z-(*p).z) )-(r+(*p).r)<=eps && p!=pok) return true;
            p=(*p).prethodni;
        }
        return false;
    }
    
    
  public:
  
    explicit NepreklapajucaKugla(double r = 0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        if (PreklapaSe(0, 0, 0, r)) throw std::logic_error("Nedozvoljeno preklapanje");
        prethodni=posljednji;
        x=0; y=0; z=0; NepreklapajucaKugla::r=r;
        posljednji=this;
    }
    
    NepreklapajucaKugla(double x, double y, double z, double r = 0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        if (PreklapaSe(x, y, z, r)) throw std::logic_error("Nedozvoljeno preklapanje");
        prethodni=posljednji;
        NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z; NepreklapajucaKugla::r=r;
        posljednji=this;
    }
    
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        if (PreklapaSe(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r)) throw std::logic_error("Nedozvoljeno preklapanje");
        prethodni=posljednji;
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); NepreklapajucaKugla::r=r; 
        posljednji=this;
    }
    NepreklapajucaKugla (const NepreklapajucaKugla &k)=delete;
    NepreklapajucaKugla &operator= (const NepreklapajucaKugla &k)=delete;
    
    ~NepreklapajucaKugla() {
        if (prethodni==nullptr) {
            if (this==posljednji) posljednji=nullptr;
            else{
                NepreklapajucaKugla* sljedeci(posljednji), *trenutni(posljednji);
                while ((*trenutni).prethodni!=nullptr) { if (trenutni!=posljednji) sljedeci=(*sljedeci).prethodni; trenutni=(*trenutni).prethodni; }
                trenutni=nullptr; (*sljedeci).prethodni=nullptr;
            }
        }
        else if (this==posljednji) { posljednji=prethodni; }
        else {
            NepreklapajucaKugla* sljedeci(posljednji), *trenutni(posljednji);
            while (trenutni!=this) { if (trenutni!=posljednji) sljedeci=(*sljedeci).prethodni; trenutni=(*trenutni).prethodni; }
            (*sljedeci).prethodni=(*trenutni).prethodni;
        }
    }
    
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x, y, z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*pi; }
    double DajZapreminu() const { return 4*r*r*r*pi/3; }
    
    NepreklapajucaKugla &PostaviX(double x) { if (PreklapaSe(x, y, z, r, this)) throw std::logic_error("Nedozvoljeno preklapanje"); NepreklapajucaKugla::x=x;  return *this; }
    NepreklapajucaKugla &PostaviY(double y) { if (PreklapaSe(x, y, z, r, this)) throw std::logic_error("Nedozvoljeno preklapanje"); NepreklapajucaKugla::y=y; return *this; }
    NepreklapajucaKugla &PostaviZ(double z) { if (PreklapaSe(x, y, z, r, this)) throw std::logic_error("Nedozvoljeno preklapanje"); NepreklapajucaKugla::z=z; return *this; }
    
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) { if (PreklapaSe(x, y, z, r, this)) throw std::logic_error("Nedozvoljeno preklapanje"); NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z; return *this; }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) { 
        if (PreklapaSe(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r, this)) throw std::logic_error("Nedozvoljeno preklapanje");
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
        return *this; 
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) { if (r<0) throw std::domain_error("Ilegalan poluprecnik"); if (PreklapaSe(x, y, z, r, this)) throw std::logic_error("Nedozvoljeno preklapanje"); NepreklapajucaKugla::r=r; return *this; }
    
    void Ispisi() const { std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}"; }
    
    void Transliraj(double delta_x, double delta_y, double delta_z) { 
        if (PreklapaSe(x+delta_x, y+delta_y, z+delta_z, r, this)) throw std::logic_error("Nedozvoljeno preklapanje");
        x+=delta_x; y+=delta_y; z+=delta_z;
    }
    
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}

NepreklapajucaKugla* NepreklapajucaKugla::posljednji=nullptr;

int main ()
{
    int n;
    std::cout << "Unesite broj kugli: "; 
    while ( std::cin >> n, !std::cin || n<=0) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear(); std::cin.ignore(10000, '\n');
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> v;
    v.resize(n);
    
    for (int i=0; i<n; i++) {
        std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
        double x, y, z, r;
        while (std::cin >> x >> y >> z, !std::cin) {
            std::cout << "Neispravan centar, unesite ponovo:" << std::endl;
            std::cin.clear(); std::cin.ignore(1000, '\n');
        }
        std::cout << "Unesite poluprecnik: ";
        while (std::cin >> r, !std::cin || r<0) {
            std::cout << "Neispravan poluprecnik, unesite ponovo:" << std::endl;
            std::cin.clear(); std::cin.ignore(1000, '\n');
        }
        try {
            v.at(i)=std::make_shared<NepreklapajucaKugla>(x, y, z, r);
        }
        catch(std::exception &izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            i--;
        }
    }
    std::sort(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> p1, std::shared_ptr<NepreklapajucaKugla> p2) { return (*p1).DajPovrsinu()<(*p2).DajPovrsinu(); } );
    std::cout << std::endl << "Kugle nakon obavljenog sortiranja: " << std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> p) { (*p).Ispisi(); std::cout << std::endl; } );
    
    
    /*NepreklapajucaKugla* p;
    
    try {
        p=new NepreklapajucaKugla(5, 5, 5, 1);
        
        
        try {
            NepreklapajucaKugla k1(5, 5, 5);
        }
        catch(...) { std::cout << "greska"; }
        
    }
    catch(std::exception &iz) {
        std::cout << iz.what();
    }
    delete p;*/
    
	return 0;
}
