/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#define eps 0.0000000001

typedef std::tuple<double, double, double> Tapl;

class NepreklapajucaKugla{
    double x, y, z, r;
    NepreklapajucaKugla *prethodna=nullptr;
    static NepreklapajucaKugla *posljednja;
    static bool DaLiSePreklapaju(double x, double y, double z, double r, const NepreklapajucaKugla &k2){
        auto l(std::sqrt(std::pow(x-k2.x, 2)+std::pow(y-k2.y, 2)
                +std::pow(z-k2.z, 2)));
        if(!(l>r+k2.r))
            return true;
        return false;    
    }
    static bool DaLiSuIdenticne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
        return (std::fabs(k1.x-k2.x)<=eps*(std::fabs(k1.x)+std::fabs(k2.x)) 
           && std::fabs(k1.y-k2.y)<=eps*(std::fabs(k1.y)+std::fabs(k2.y)) 
           && std::fabs(k1.z-k2.z)<=eps*(std::fabs(k1.z)+std::fabs(k2.z)) 
           && std::fabs(k1.r-k2.r)<=eps*(std::fabs(k1.r)+std::fabs(k2.r)));
    }
    public:
    explicit NepreklapajucaKugla(double r=0){
       if(r<0) throw std::domain_error("Ilegalan poluprecnik"); 
       if(posljednja!=nullptr){
       auto it(posljednja);
       for(it=posljednja; it->prethodna!=nullptr; it=it->prethodna){
           if(NepreklapajucaKugla::DaLiSePreklapaju(x, y, z, r, *it))
               throw std::logic_error("Nedozvoljeno preklapanje");
       }
       if(NepreklapajucaKugla::DaLiSePreklapaju(x, y, z, r, *it))
               throw std::logic_error("Nedozvoljeno preklapanje");}
       x=0; y=0; z=0; this->r=r; this->prethodna=posljednja; posljednja=this;
    }
    NepreklapajucaKugla(double x, double y, double z, double r=0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        if(posljednja!=nullptr){ 
        auto it(posljednja);
        for(it=posljednja; it->prethodna!=nullptr; it=it->prethodna){
           if(NepreklapajucaKugla::DaLiSePreklapaju(x, y, z, r, *it) )
               throw std::logic_error("Nedozvoljeno preklapanje");
        }
        if(NepreklapajucaKugla::DaLiSePreklapaju(x, y, z, r, *it))
               throw std::logic_error("Nedozvoljeno preklapanje");}
        this->x=x; this->y=y; this->z=z; this->r=r; this->prethodna=posljednja; posljednja=this; 
    }
    explicit NepreklapajucaKugla(const Tapl &centar, double r=0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        if(posljednja!=nullptr){
        auto it(posljednja);
        for(it=posljednja; it->prethodna!=nullptr; it=it->prethodna){
           if(NepreklapajucaKugla::DaLiSePreklapaju(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r, *it))
               throw std::logic_error("Nedozvoljeno preklapanje");
        }
        if(NepreklapajucaKugla::DaLiSePreklapaju(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r, *it))
               throw std::logic_error("Nedozvoljeno preklapanje");}
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
        this->r=r; this->prethodna=posljednja; posljednja=this;
    }
    ~NepreklapajucaKugla(){
        if(posljednja!=nullptr){
        auto tjt(posljednja);
        auto it(posljednja); int br(0);
        for(it=posljednja; it->prethodna!=nullptr; it=it->prethodna){
            if(br>=2)
                tjt=tjt->prethodna;
           if(NepreklapajucaKugla::DaLiSuIdenticne(*this, *it))
               break;
            br++;   
        }
        if(it==posljednja) posljednja=this->prethodna;
        else{
            if(it->prethodna==nullptr && br>1) tjt=tjt->prethodna;
            tjt->prethodna=this->prethodna;
        }}
    }
    NepreklapajucaKugla &operator =(const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla &operator =(NepreklapajucaKugla &&k) = delete;
    double DajX() const {return x;}
    double DajY() const {return y;}
    double DajZ() const {return z;}
    Tapl DajCentar() const {return std::make_tuple(x, y, z);}
    double DajPoluprecnik() const {return r;}
    double DajPovrsinu() const {return (4*(4*std::atan(1))*(r*r));}
    double DajZapreminu() const {return ((4/3.)*(r*r*r)*(4*std::atan(1)));}
    NepreklapajucaKugla &PostaviX(double x) {
        for(auto it=posljednja; it->prethodna!=nullptr; it=it->prethodna){
           if(NepreklapajucaKugla::DaLiSePreklapaju(x, this->y, this->z, this->r, *it))
               throw std::logic_error("Nedozvoljeno preklapanje");
        }
        this->x=x; return *this;}
    NepreklapajucaKugla &PostaviY(double y) {
        for(auto it=posljednja; it->prethodna!=nullptr; it=it->prethodna){
           if(NepreklapajucaKugla::DaLiSePreklapaju(this->x, this->y, this->z, this->r, *it))
               throw std::logic_error("Nedozvoljeno preklapanje");
        }
        this->y=y; return *this;}
    NepreklapajucaKugla &PostaviZ(double z) {
        for(auto it=posljednja; it->prethodna!=nullptr; it=it->prethodna){
           if(NepreklapajucaKugla::DaLiSePreklapaju(this->x, this->y, z, this->r, *it))
               throw std::logic_error("Nedozvoljeno preklapanje");
        }
        this->z=z; return *this;}
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        for(auto it=posljednja; it->prethodna!=nullptr; it=it->prethodna){
           if(NepreklapajucaKugla::DaLiSePreklapaju(x, y, z, this->r, *it))
               throw std::logic_error("Nedozvoljeno preklapanje");
        }
        this->x=x; this->y=y; this->z=z; return *this;}
    NepreklapajucaKugla &PostaviCentar(const Tapl &centar){
        for(auto it=posljednja; it->prethodna!=nullptr; it=it->prethodna){
           if(NepreklapajucaKugla::DaLiSePreklapaju(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), this->r, *it))
               throw std::logic_error("Nedozvoljeno preklapanje");
        }
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r){
        for(auto it=posljednja; it->prethodna!=nullptr; it=it->prethodna){
           if(NepreklapajucaKugla::DaLiSePreklapaju(this->x, this->y, this->z, r, *it))
               throw std::logic_error("Nedozvoljeno preklapanje");
        }
        if(r<0) throw std::domain_error("Ilegalan poluprecnik"); 
        this->r=r; return *this;
    }
    void Ispisi() const{
        std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}\n";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        for(auto it=posljednja; it->prethodna!=nullptr; it=it->prethodna){
           if(NepreklapajucaKugla::DaLiSePreklapaju(x+delta_x, y+delta_y, z+delta_z, this->r, *it))
               throw std::logic_error("Nedozvoljeno preklapanje");
        }
        x+=delta_x; y+=delta_y; z+=delta_z;
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
        return (std::sqrt(std::pow(k1.x-k2.x, 2)+std::pow(k1.y-k2.y, 2)
                +std::pow(k1.z-k2.z, 2)));
    }
};

NepreklapajucaKugla *NepreklapajucaKugla::posljednja(nullptr);

bool DaLiSePreklapaju(double x, double y, double z, double r, const NepreklapajucaKugla &k2){
    auto l(std::sqrt(std::pow(x-k2.DajX(), 2)+std::pow(y-k2.DajY(), 2)
                +std::pow(z-k2.DajZ(), 2)));
        if(!(l>r+k2.DajPoluprecnik()))
            return true;
        return false;    
}

int main()
{
    std::cout << "Unesite broj kugli: ";
    int n;
    std::cin >> n;
    while(n<=0 || !std::cin){
        std::cout << "Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> n;
    }
    try{
    std::vector<std::shared_ptr<NepreklapajucaKugla>> v(n);
    for(int i=0; i<n; i++){
        std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
        double x, y, z;
        std::cin >> x >> y >> z;
        while(!std::cin){
            std::cout << "Neispravan centar, unesite ponovo:\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> x >> y >> z;
        }
        std::cout << "Unesite poluprecnik: ";
        double r;
        std::cin >> r;
        while(!std::cin || r<0){
            std::cout << "Neispravan poluprecnik, unesite ponovo:\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> r;
        }{
            int pokazatelj(1);
            int j(0);
            for(j=0; j<i; j++){
                if(DaLiSePreklapaju(x, y, z, r, *v.at(j))){
                    i--;
                    std::cout << "Nedozvoljeno preklapanje\n";
                    pokazatelj=0;
                    break;
                }
            }
            
           if(pokazatelj) v.at(i)=std::make_shared<NepreklapajucaKugla>(x, y, z, r);
        }
    }
    std::sort(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2){
        return k1->DajPovrsinu()<k2->DajPovrsinu();
    });
    std::cout << "\nKugle nakon obavljenog sortiranja: \n";
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> k){
        k->Ispisi();
    });
    }
    catch(std::domain_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
    catch(std::logic_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
    catch(...){
        std::cout << "Problemi sa memorijom!\n";
    }
    return 0;
}