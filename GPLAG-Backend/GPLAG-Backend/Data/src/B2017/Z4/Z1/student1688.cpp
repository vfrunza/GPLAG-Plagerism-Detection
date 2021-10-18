/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include<stdexcept>
#include<cmath>
#include<tuple>
#include<vector>
#include<memory>
#include<algorithm>
#define pi 4*atan(1.)
#define eps pow(10,-10)
class Kugla{
     
    double x,y,z,r;
public:
explicit Kugla(double r = 0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::x = 0;
    Kugla::y = 0;
    Kugla::z = 0;
    Kugla::r = r;
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
  x=std::get<0>(centar);
  y=std::get<1>(centar);
  z=std::get<2>(centar);
  Kugla::r=r;
}
double DajX() const{ return x;}
double DajY() const{ return y;}
double DajZ() const{return z;}
std::tuple<double, double, double> DajCentar() const{
    std::tuple<double,double,double> t;
    t=std::make_tuple(x, y, z);
    return t;
}
double DajPoluprecnik() const{ return r;}
double DajPovrsinu() const{return (4*r*r*pi);}
double DajZapreminu() const{return ((4.)/3*r*r*r*pi);}
Kugla &PostaviX(double x) {Kugla::x=x; return *this;}
Kugla &PostaviY(double y){Kugla::y=y; return *this;}
Kugla &PostaviZ(double z){Kugla::z=z; return *this;}
Kugla &PostaviCentar(double x, double y, double z){Kugla::x=x; Kugla::y=y; Kugla::z=z; return *this;}
Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
    x = std::get<0>(centar);
    y = std::get<1>(centar);
    z = std::get<2>(centar);
    return *this;
}
Kugla &PostaviPoluprecnik(double r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
    return *this;
    }
void Ispisi() const{std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;}

void Transliraj(double delta_x, double delta_y, double delta_z){ x+=delta_x; y+=delta_y; z+=delta_z;}
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

bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2){
    if((std::fabs(k1.r -k2.r) <= eps*(std::fabs(k1.r)+std::fabs(k2.r))) && (std::fabs(k1.x -k2.x) <= eps*(std::fabs(k1.x)+std::fabs(k2.x))) && (std::fabs(k1.y -k2.y) <= eps*(std::fabs(k1.y)+std::fabs(k2.y))) && (std::fabs(k1.z -k2.z) <= eps*(std::fabs(k1.z)+std::fabs(k2.z)))) return true;
    return false;
}

bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2){
    if((std::fabs(k1.r-k2.r)<=eps*(std::fabs(k1.r)+std::fabs(k2.r)))) return true;
    return false;
}

bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2){
    if((std::fabs(k1.x-k2.x)<=eps*(std::fabs(k1.x)+std::fabs(k2.x))) && (std::fabs(k1.y-k2.y)<=eps*(std::fabs(k1.y)+std::fabs(k2.y))) && (std::fabs(k1.z-k2.z)<=eps*(std::fabs(k1.z)+std::fabs(k2.z)))) return true;
    return false;  
}

bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2){
    double d = RastojanjeCentara(k1, k2);
    double rad = k1.r + k2.r;
    if(std::fabs(d - rad) <= eps * (std::fabs(rad) + std::fabs(d))) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2){
    double d = RastojanjeCentara(k1, k2);
    double rad = std::fabs(k1.r - k2.r);
    if(std::fabs(d - rad) <= eps * (std::fabs(rad) + std::fabs(d))) return true;    
    return false;
}

bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2){
    if(k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1) || DaLiSuIdenticne(k1, k2) || DaLiSuKoncentricne(k1, k2) || DaLiSeDodirujuIznutra(k1, k2) || DaLiSeSijeku(k1, k2)) return true;
    return false;
}

bool Kugla::DaLiSadrzi(const Kugla &k) const {
    if(r < k.r) return false;
    double d = RastojanjeCentara(*this, k);
    double zbir = d + k.r;
    if(DaLiSuKoncentricne(*this, k) || DaLiSuIdenticne(*this, k) || (zbir < this->r || std::fabs(zbir - this->r) <= eps * (std::fabs(zbir) + std::fabs(this->r)))) return true;
    return false;    
}

bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2){
    double d = RastojanjeCentara(k1, k2);
    double zbir = k1.r + k2.r;
    double razlika = std::fabs(k1.r - k2.r);
    if(d > razlika && d < zbir) {
        if(!DaLiSuKoncentricne(k1, k2)) return true;
        return false;
    }
    return false;
}

double RastojanjeCentara(const Kugla &k1,const Kugla &k2){
    double d=std::sqrt((k2.x-k1.x)*(k2.x-k1.x) +(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z));
    return d;
}

int main() {
    std::cout<<"Unesite broj kugla: ";
    int n;
    for(;;) {
        std::cin>>n;
        if(!std::cin || n <= 0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
            continue;
        }
        break;
    }
    std::vector<std::shared_ptr<Kugla>>pok(n,nullptr);
    for(int i(0);i<n;i++){
        double a,b,c,r;
        for(;;) {
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>a>>b>>c;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Neispravan centar" << std::endl;
                continue;
            }
            std::cout<<"Unesite poluprecnik " <<i+1<<". kugle: ";
            std::cin>>r;
            if(!std::cin || r < 0) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ilegalan poluprecnik" << std::endl;
                continue;
            }
            break;
        }
        try{
            pok[i]=std::make_shared<Kugla>(a, b, c, r);
        }
        catch(std::domain_error e){
            i--;
        }
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double x,y,z;
    for(;;) {
        std::cin>>x>>y>>z;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
            continue;
        }
        break;
    }
    std::transform(pok.begin(),pok.end(),pok.begin(),[x, y, z](std::shared_ptr<Kugla> k){
        k->Transliraj(x, y, z);
        return k;
    });
    std::sort(pok.begin(), pok.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajZapreminu() < k2->DajZapreminu();
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(pok.begin(), pok.end(), [] (std::shared_ptr<Kugla> k) {
        k->Ispisi();
    });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (**std::max_element(pok.begin(), pok.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    })).Ispisi();
    int presjek(0), indeks(0);
    std::for_each(pok.begin(), pok.end(), [pok, &presjek, &indeks] (std::shared_ptr<Kugla> k) {
        indeks++;
        std::for_each(pok.begin() + indeks, pok.end(), [&presjek, k] (std::shared_ptr<Kugla> k2) {
            if(DaLiSeSijeku(*k, *k2)) {
                std::cout << "Presjecaju se kugle: ";
                k->Ispisi();
                k2->Ispisi();
                presjek++;
            }
        });
    });
    if(presjek == 0) std::cout << "Ne postoje kugle koje se presjecaju!";
	return 0;
}
