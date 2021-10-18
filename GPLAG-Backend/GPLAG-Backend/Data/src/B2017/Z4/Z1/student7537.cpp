/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#define eps 0.0000000001

typedef std::tuple<double, double, double> Tapl;

class Kugla{
    double x, y, z, r;
    public:
    explicit Kugla(double r=0){
       if(r<0) throw std::domain_error("Ilegalan poluprecnik"); 
       x=y=z=0; this->r=r;
    }
    Kugla(double x, double y, double z, double r=0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        this->x=x; this->y=y; this->z=z; this->r=r;  
    }
    explicit Kugla(const Tapl &centar, double r=0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik"); 
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
        this->r=r;
    }
    double DajX() const {return x;}
    double DajY() const {return y;}
    double DajZ() const {return z;}
    Tapl DajCentar() const {return std::make_tuple(x, y, z);}
    double DajPoluprecnik() const {return r;}
    double DajPovrsinu() const {return (4*(4*std::atan(1))*(r*r));}
    double DajZapreminu() const {return ((4/3.)*(r*r*r)*(4*std::atan(1)));}
    Kugla &PostaviX(double x) {this->x=x; return *this;}
    Kugla &PostaviY(double y) {this->y=y; return *this;}
    Kugla &PostaviZ(double z) {this->z=z; return *this;}
    Kugla &PostaviCentar(double x, double y, double z) {this->x=x; this->y=y; this->z=z; return *this;}
    Kugla &PostaviCentar(const Tapl &centar){
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik"); 
        this->r=r; return *this;
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
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
        return (std::sqrt(std::pow(k1.x-k2.x, 2)+std::pow(k1.y-k2.y, 2)
                +std::pow(k1.z-k2.z, 2)));
    }
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    return (std::fabs(k1.x-k2.x)<=eps*(std::fabs(k1.x)+std::fabs(k2.x)) 
           && std::fabs(k1.y-k2.y)<=eps*(std::fabs(k1.y)+std::fabs(k2.y)) 
           && std::fabs(k1.z-k2.z)<=eps*(std::fabs(k1.z)+std::fabs(k2.z)) 
           && std::fabs(k1.r-k2.r)<=eps*(std::fabs(k1.r)+std::fabs(k2.r)));
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    return (std::fabs(k1.r-k2.r)<=eps*(std::fabs(k1.r)+std::fabs(k2.r)));
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    return (std::fabs(k1.x-k2.x)<=eps*(std::fabs(k1.x)+std::fabs(k2.x)) 
           && std::fabs(k1.y-k2.y)<=eps*(std::fabs(k1.y)+std::fabs(k2.y)) 
           && std::fabs(k1.z-k2.z)<=eps*(std::fabs(k1.z)+std::fabs(k2.z)));
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    auto l(RastojanjeCentara(k1, k2));
    return (std::fabs(l-(k1.r+k2.r))<=eps*(l+std::fabs(k1.r+k2.r)));
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    auto l(RastojanjeCentara(k1, k2));
    if(std::fabs(k1.r-k2.r)<=eps*(k1.r+k2.r))
        return false;
    return (std::fabs(l-std::fabs(k1.r-k2.r))<=eps*(l+std::fabs(k1.r-k2.r)));  
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    auto l(RastojanjeCentara(k1, k2));
    if(std::fabs(k1.r-k2.r)>eps*(k1.r+k2.r))
        return (l>std::fabs(k1.r-k2.r) && l<(k1.r+k2.r));
    return (l<(k1.r+k2.r) && l>0);
}

bool Kugla::DaLiSadrzi(const Kugla &k) const{
    auto l(RastojanjeCentara(*this, k));
    if((r<k.r || r>k.r) && l>0)
        return (std::fabs(r-k.r)>=l);
    else if(DaLiSuIdenticne(*this, k)) return true;    
    return false;    
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    if(DaLiSeSijeku(k1, k2))
        return true;
    else if(DaLiSuIdenticne(k1, k2)) return true;    
    else if(k1.r>k2.r)
        return (k1.DaLiSadrzi(k2));
    return (k2.DaLiSadrzi(k1));    
}

int main()
{
    std::cout << "Unesite broj kugla: ";
    int n;
    std::cin >> n;
    while(n<=0 || !std::cin){
        std::cout << "Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> n;
    }
   try{
    std::vector<std::shared_ptr<Kugla>> v(n);
    for(int i=0; i<n; i++){
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        double x, y, z;
        std::cin >> x >> y >> z;
        if(!std::cin){
            std::cout << "Neispravan centar\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            i--;
        }
        else{
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        double r;
        std::cin >> r;
        if(!std::cin || r<0){
            std::cout << "Ilegalan poluprecnik\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            i--;
        }
        else
            v.at(i)=std::make_shared<Kugla>(x, y, z, r);
        }
    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx, dy, dz;
    std::cin >> dx >> dy >> dz;
    while(!std::cin){
        std::cout << "Neispravni parametri translacije, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n'); 
        std::cin >> dx >> dy >> dz;
    }
    std::transform(v.begin(), v.end(), v.begin(), [dx, dy, dz](std::shared_ptr<Kugla> k){
        k->PostaviX(k->DajX()+dx); k->PostaviY(k->DajY()+dy); k->PostaviZ(k->DajZ()+dz);
        return k;
    });
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){
        return k1->DajZapreminu()<k2->DajZapreminu();
    });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> k){
        k->Ispisi(); 
    });
    std::cout << "Kugla sa najvecom povrsinom je: "; 
    (*std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){
        return k1->DajPovrsinu()<k2->DajPovrsinu();
    }))->Ispisi();
    int br(0), i(1);
    std::for_each(v.begin(), v.end(), [v, &br, &i](std::shared_ptr<Kugla> k){
        for(int j=i; j<v.size(); j++){
            if(DaLiSeSijeku(*k, *v.at(j))){
                std::cout << "Presjecaju se kugle: ";
                k->Ispisi(); v.at(j)->Ispisi(); 
                br++;
            }
        }
            i++;
    });
    if(br==0) std::cout << "Ne postoje kugle koje se presjecaju!\n";
    for(int j=0; j<n; j++)
        v.at(j)=nullptr;
    }
    catch(std::domain_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
    catch(...){
        std::cout << "Problemi sa memorijom!\n";
    }
    return 0;
}