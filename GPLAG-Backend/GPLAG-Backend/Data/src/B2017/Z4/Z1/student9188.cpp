/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <memory>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <tuple>
#include <utility>

const double PI(4*std::atan(1));
const double EPSILON(pow(10,-10));
class Kugla{
    double x,y,z,r;
    public: 
    explicit Kugla(double r = 0);
    Kugla(double x, double y, double z, double r = 0);
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0);
    double DajX() const{ return x;}
    double DajY() const{ return y;}
    double DajZ() const{ return z;}
    std::tuple<double, double, double> DajCentar() const{ return std::make_tuple(x,y,z); }
    double DajPoluprecnik() const{return r;}
    double DajPovrsinu() const { return 4*r*r*PI;}
    double DajZapreminu() const {return (4*r*r*r*PI)/3. ;}
    Kugla &PostaviX(double x);
    Kugla &PostaviY(double y);
    Kugla &PostaviZ(double z);
    Kugla &PostaviCentar(double x, double y, double z); 
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const{std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;}
    void Transliraj(double delta_x, double delta_y, double delta_z);
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

Kugla::Kugla(double r) : r(r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    x = 0; Kugla::y = 0; Kugla::z = 0;
    
}
Kugla::Kugla(double x, double y, double z, double r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::x = x; Kugla::y = y; Kugla::z = z;
    Kugla::r = r;
}
Kugla::Kugla(const std::tuple<double,double,double> &centar,double r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::x = std::get<0>(centar); Kugla::y = std::get<1>(centar); Kugla::z = std::get<2>(centar);
    Kugla::r = r;
}
Kugla &Kugla::PostaviX(double x){
    this->x = x;
    return *this;
}
Kugla &Kugla::PostaviY(double y){
    this->y = y;
    return *this;
}
Kugla &Kugla::PostaviZ(double z){
    this->z = z;
    return *this;
}
Kugla &Kugla::PostaviCentar(double x, double y, double z){
    this->x = x; this->y = y; this->z = z;
    return  *this;
}
Kugla &Kugla::PostaviCentar(const std::tuple<double,double,double> &centar){
    this->x = std::get<0>(centar); this->y = std::get<1>(centar); this->z=std::get<2>(centar);
    return *this;
}
Kugla &Kugla::PostaviPoluprecnik(double r){
    this->r = r;
    return *this;
}
void Kugla::Transliraj(double delta_x,double delta_y, double delta_z){
    x+=delta_x; 
    y+=delta_y;
    z+=delta_z;
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    if(std::fabs(k1.r-k2.r)<=EPSILON*(std::fabs(k1.r)+std::fabs(k2.r))
    && std::fabs(k1.x-k2.x)<=EPSILON*(std::fabs(k1.x)+std::fabs(k2.x))
    &&std::fabs(k1.y-k2.y)<=EPSILON*(std::fabs(k1.y)+std::fabs(k2.y)) 
    && std::fabs(k1.z-k2.z)<=EPSILON*(std::fabs(k1.z)+std::fabs(k2.z))) return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    if(std::fabs(k1.r-k2.r)<=EPSILON*(std::fabs(k1.r)+std::fabs(k2.r))) return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    if(std::fabs(k1.x-k2.x)<=EPSILON*(std::fabs(k1.x)+std::fabs(k2.x))&&
       std::fabs(k1.y-k2.y)<=EPSILON*(std::fabs(k1.y)+std::fabs(k2.y))&&
       std::fabs(k1.z-k2.z)<=EPSILON*(std::fabs(k1.z)+std::fabs(k2.z))) return true;
    return false;
}
bool DaLiSePreklapaju(const Kugla &k1 ,const Kugla &k2){
    return DaLiSeSijeku(k1,k2);
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    double modul(RastojanjeCentara(k1,k2));
    return (std::fabs(k1.r-k2.r)<modul) && modul<k1.r+k2.r);
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    return (fabs(RastojanjeCentara(k1,k2)-(k1.DajPoluprecnik()+k2.DajPoluprecnik())) <= 
            EPSILON * (fabs(RastojanjeCentara(k1,k2))+fabs(k1.DajPoluprecnik()+k2.DajPoluprecnik())));
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    return (fabs(RastojanjeCentara(k1,k2)+k2.DajPoluprecnik()-k1.DajPoluprecnik())<= 
            EPSILON*(std::fabs(RastojanjeCentara(k1,k2)+k2.DajPoluprecnik())+std::fabs(k1.DajPoluprecnik())));
}
inline double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}
bool Kugla::DaLiSadrzi(const Kugla &k) const{
    return (std::fabs(RastojanjeCentara(*this,k)+k.DajPoluprecnik())<this->DajPoluprecnik());
}
int main ()
{   
    int n;
    std::cout<<"Unesite broj kugla: ";
    for(;;){
        
        std::cin>>n;
        if(!std::cin || n<=0){
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            continue;
        }
        else break;
    }
    std::vector<std::shared_ptr<Kugla>> kugle;
    for(int i=0;i<n;i++){
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        double x,y,z;
        std::cin>>x>>y>>z;
        if(!std::cin){
            std::cout<<"Neispravan centar"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            i--;
            continue;
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        double r; 
        std::cin>>r;
        if(!std::cin || r<0){
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            i--;
            continue;
        }
        kugle.push_back(std::make_shared<Kugla>(std::make_tuple(x,y,z),r));
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    int delta_x,delta_y,delta_z;
    for(;;){
        std::cin>>delta_x>>delta_y>>delta_z;
        if(!std::cin){
            std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            continue;
        }else break;
    }
    std::transform(kugle.begin(),kugle.end(),kugle.begin(),[delta_x,delta_y,delta_z](const std::shared_ptr<Kugla> a){a->Transliraj(delta_x,delta_y,delta_z); return a;});
    std::sort(kugle.begin(),kugle.end(),[](const std::shared_ptr<Kugla> a, const std::shared_ptr<Kugla> b){return a->DajZapreminu() < b->DajZapreminu();});
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(kugle.begin(),kugle.end(),[](const std::shared_ptr<Kugla> a){a->Ispisi();});
    auto x(std::max_element(kugle.begin(),kugle.end(),[](const std::shared_ptr<Kugla> a, const std::shared_ptr<Kugla> b){return a->DajPovrsinu() < b->DajPovrsinu();}));
    std::cout<<"Kugla sa najvecom povrsinom je: "; (*x)->Ispisi();
    std::vector<std::pair<Kugla,Kugla>> kuglice;
    std::for_each(kugle.begin(),kugle.end(),[&kugle,&kuglice](const std::shared_ptr<Kugla> kugla1){
        std::for_each(kugle.begin(),kugle.end(),[kugla1,&kuglice](const std::shared_ptr<Kugla> kugla2){
            
            if(DaLiSeSijeku(*kugla1,*kugla2) && kugla1 != kugla2) {
                std::pair<Kugla,Kugla> kugl(*kugla1,*kugla2);
                kuglice.push_back(kugl);
                int broj_ispisanih = std::count_if(kuglice.begin(),kuglice.end(),[kugl](std::pair<Kugla,Kugla> par){
                    if(DaLiSuIdenticne(std::get<0>(par),std::get<1>(kugl)) 
                    && DaLiSuIdenticne(std::get<1>(par),std::get<0>(kugl))) return true;
                    return false;
                });
                if(broj_ispisanih==0){
                std::cout<<"Presjecaju se kugle: ";
                kugla1->Ispisi();
                kugla2->Ispisi();
                }
            }
        });
    });
    if(kuglice.size()==0) std::cout<<"Ne postoje kugle koje se presjecaju!";
	return 0;
}
