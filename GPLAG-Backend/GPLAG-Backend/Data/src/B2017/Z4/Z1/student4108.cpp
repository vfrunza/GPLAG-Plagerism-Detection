/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <memory>

constexpr double EPS=0.0000000001;
constexpr double PI=4*std::atan(1);


class Kugla{
    double x, y, z, r;
    static bool DaLiJeIsto(double prvi, double drugi);
    public:
    explicit Kugla(double r = 0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
    }
    Kugla(double x, double y, double z, double r = 0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        Kugla::r=r;
    }
    double DajX() const;
    double DajY() const;
    double DajZ() const;
    std::tuple<double, double, double> DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    Kugla &PostaviX(double x);
    Kugla &PostaviY(double y);
    Kugla &PostaviZ(double z);
    Kugla &PostaviCentar(double x, double y, double z);
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
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
bool Kugla::DaLiJeIsto(double prvi, double drugi){
    if(std::fabs(prvi-drugi)<=EPS*(std::fabs(prvi)+std::fabs(drugi))) return true;
    return false;
}/*
//konstruktori
Kugla::Kugla(double r=0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
}
Kugla::Kugla(double x, double y, double z, double r=0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    Kugla::r=r;
}
Kugla::Kugla(const tuple<double, double, double> &centar, double r=0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::x=std::get<0>(centar);
    Kugla::y=std::get<1>(centar);
    Kugla::z=std::get<2>(centar);
    Kugla::r=r;
}*/
//get
double Kugla::DajX() const{
    return x;
}
double Kugla::DajY() const{
    return y;
}
double Kugla::DajZ() const{
    return z;
}
std::tuple<double, double, double> Kugla::DajCentar() const{
    std::tuple<double, double, double> povratni;
    povratni=std::make_tuple(x, y, z);
    return povratni;
}
double Kugla::DajPoluprecnik() const{
    return r;
}
double Kugla::DajPovrsinu() const{
    return 4*r*r*PI;
}
double Kugla::DajZapreminu() const{
    return (4.00/3.00)*r*r*r*PI;
}
//set
Kugla &Kugla::PostaviX(double x){
    Kugla::x=x;
    return *this;
}
Kugla &Kugla::PostaviY(double y){
    Kugla::y=y;
    return *this;
}
Kugla &Kugla::PostaviZ(double z){
    Kugla::z=z;
    return *this;
}
Kugla &Kugla::PostaviCentar(double x, double y, double z){
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    return *this;
}
Kugla &Kugla::PostaviCentar(const std::tuple<double, double, double> &centar){
    Kugla::x=std::get<0>(centar);
    Kugla::y=std::get<1>(centar);
    Kugla::z=std::get<2>(centar);
    return *this;
}
Kugla &Kugla::PostaviPoluprecnik(double r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
    return *this;
}

void Kugla::Ispisi() const{
    std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
}
void Kugla::Transliraj(double delta_x, double delta_y, double delta_z){
    x+=delta_x;
    y+=delta_y;
    z+=delta_z;
}

//prijatelji
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
     if(Kugla::DaLiJeIsto(k1.DajX(), k2.DajX()) && Kugla::DaLiJeIsto(k1.DajY(), k2.DajY()) && Kugla::DaLiJeIsto(k1.DajZ(), k2.DajZ()) && Kugla::DaLiJeIsto(k1.DajPoluprecnik(), k2.DajPoluprecnik())) return true;
     return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    if(Kugla::DaLiJeIsto(k1.DajPoluprecnik(), k2.DajPoluprecnik())) return true;
    return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x) + (k1.y-k2.y)*(k1.y-k2.y) + (k1.z-k2.z)*(k1.z-k2.z));
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    if(Kugla::DaLiJeIsto(k1.DajX(), k2.DajX()) && Kugla::DaLiJeIsto(k1.DajY(), k2.DajY()) && Kugla::DaLiJeIsto(k1.DajZ(), k2.DajZ())) return true;
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    double udaljenost=k1.DajPoluprecnik()+k2.DajPoluprecnik();
    double udaljenostCentar=RastojanjeCentara(k1, k2);
    if(Kugla::DaLiJeIsto(udaljenost, udaljenostCentar)) return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
        double razlikaRadijusa=std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik());
        if(Kugla::DaLiJeIsto(RastojanjeCentara(k1, k2), razlikaRadijusa)) return true;
        return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    double zbirRadijusa=std::fabs(k1.DajPoluprecnik()+k2.DajPoluprecnik());
    double razlikaRadijusa=std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik());
    double rastojanje=RastojanjeCentara(k1,k2);
 
    
    if(!Kugla::DaLiJeIsto(zbirRadijusa, rastojanje) && !Kugla::DaLiJeIsto(razlikaRadijusa, rastojanje) && zbirRadijusa>rastojanje && rastojanje>razlikaRadijusa) return true;
    return false;
}
bool Kugla::DaLiSadrzi(const Kugla &k) const{
    double ras=std::sqrt((x-k.x)*(x-k.x) + (y-k.y)*(y-k.y) + (z-k.z)*(z-k.z));
    if(ras+k.r<r || std::fabs(ras+k.r-r)<=EPS*(std::fabs(ras+k.r)+std::fabs(r))) return true;
    return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    if(DaLiSuIdenticne(k1, k2) || DaLiSeSijeku(k1, k2) || k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1)) return true;
    return false;
}

int main ()
{
   
    std::cout<<"Unesite broj kugla: ";
    int n(0);
    while(true){
        std::cin>>n;
        if(n<=0 || std::cin.peek()!='\n'){
            std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else break;
    }
    std::vector<std::shared_ptr<Kugla>> pok(n);
    for(int i=0; i<n; i++){
        double unosX(0), unosY(0), unosZ(0), unosR(0);
        pocetak:
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        
        std::cin>>unosX;
        if(std::cin.peek()!='\n' && std::cin.peek()!=' ') {std::cout<<"Neispravan centar\n"; std::cin.clear(); std::cin.ignore(10000, '\n'); goto pocetak;}
        std::cin>>unosY;
        if(std::cin.peek()!='\n' && std::cin.peek()!=' ') {std::cout<<"Neispravan centar\n"; std::cin.clear(); std::cin.ignore(10000, '\n'); goto pocetak;}
        std::cin>>unosZ;
        if(std::cin.peek()!='\n' && std::cin.peek()!=' ') {std::cout<<"Neispravan centar\n"; std::cin.clear(); std::cin.ignore(10000, '\n'); goto pocetak;}
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>unosR;
        if(std::cin.peek()!='\n' && std::cin.peek()!=' ') {std::cout<<"Ilegalan poluprecnik\n"; std::cin.clear(); std::cin.ignore(10000, '\n'); goto pocetak;}
        if(unosR<0){std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout<<"Ilegalan poluprecnik\n"; goto pocetak;}
        
        pok.at(i)=std::make_shared<Kugla> (unosX, unosY, unosZ, unosR);
        
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x(0), delta_y(0), delta_z(0);
    while(true){
        std::cin>>delta_x>>delta_y>>delta_z;
        if(!std::cin){
            std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else break;
        
    }
    std::transform(pok.begin(), pok.end(), pok.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> a) {std::shared_ptr<Kugla> povratni=std::make_shared<Kugla>(a->DajX()+delta_x, a->DajY()+delta_y, a->DajZ()+delta_z, a->DajPoluprecnik()); return povratni;} );
    
    std::sort(pok.begin(), pok.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        if(!(std::fabs(k1->DajZapreminu()-k2->DajZapreminu())<=EPS*(std::fabs(k1->DajZapreminu()) + std::fabs(k2->DajZapreminu()))) && k1->DajZapreminu()<k2->DajZapreminu()) return true;
        return false;
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(pok.begin(), pok.end(), [](std::shared_ptr<Kugla> k) {
        std::cout<<"{("<<k->DajX()<<","<<k->DajY()<<","<<k->DajZ()<<"),"<<k->DajPoluprecnik()<<"}"<<std::endl;
    });
    
    std::vector<std::shared_ptr<Kugla>>::iterator it=std::max_element(pok.begin(), pok.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        if(!(std::fabs(k1->DajPovrsinu()-k2->DajPovrsinu())<=EPS*(std::fabs(k1->DajPovrsinu()) + std::fabs(k2->DajPovrsinu()))) && k1->DajPovrsinu()<k2->DajPovrsinu()) return true;
        return false;
    });
    
    std::cout<<"Kugla sa najvecom povrsinom je: {("<<(*it)->DajX()<<","<<(*it)->DajY()<<","<<(*it)->DajZ()<<"),"<<(*it)->DajPoluprecnik()<<"}";
    
    int koliko(0);
    std::vector<std::shared_ptr<Kugla>>::iterator pomocni=pok.begin();
    std::vector<std::shared_ptr<Kugla>>::iterator kraj=pok.end();
    
    std::for_each(pok.begin(), pok.end(), [&pomocni, kraj, &koliko](std::shared_ptr<Kugla> a){
        std::for_each(pomocni, kraj, [a, &pomocni, &koliko](std::shared_ptr<Kugla> b){
            if(DaLiSeSijeku(*a, *b)){
                std::cout<<std::endl<<"Presjecaju se kugle: ";
                (*a).Ispisi();
                std::cout<<std::endl;
                (*b).Ispisi();
                koliko++;
            }
            
        });
        pomocni++;
    });  
    
    if(!koliko) std::cout<<std::endl<<"Ne postoje kugle koje se presjecaju!";
    /*Kugla k1(0, 0, 0, 1);
    Kugla k2(0, 0, 2, 1);
    std::cout<<DaLiSePreklapaju(k1, k2);*/
	return 0;
}
