/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

using std::vector;
using std::shared_ptr;
using std::get;

const double pi = 4*std::atan(1);

class Kugla {
 private: 
    double x, y, z, r;
    static bool DaLiSuJednaki(double a , double b)  {
        return fabs(a-b)<=10e-10*(fabs(a)+fabs(b));
    }
    static bool DaLiSuJednaki(const std::tuple<double, double, double> &a, const std::tuple<double, double, double> &b)  { // ovdje su a,b centri kugla
        return DaLiSuJednaki(get<0>(a),get<0>(b)) && DaLiSuJednaki(get<1>(a),get<1>(b)) && DaLiSuJednaki(get<2>(a),get<2>(b));
    }
    /*bool DaLiJeUnutra(const Kugla &k) const {
        return RastojanjeCentara(*this, k) + k.DajPoluprecnik() < this->DajPoluprecnik();
    }*/
 public:
    explicit Kugla(double r = 0) { 
        PostaviPoluprecnik(r);  PostaviCentar(0,0,0); 
    }
    Kugla(double x, double y, double z, double r=0) {
        PostaviPoluprecnik(r);  PostaviCentar(x,y,z); 
    }
    explicit Kugla(const std::tuple<double,double,double> &centar, double r=0) {
        PostaviPoluprecnik(r); PostaviCentar(centar);
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(DajX(),DajY(),DajZ()); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*pi; }
    double DajZapreminu() const { return (4/3)*r*r*r*pi; }
    Kugla &PostaviX(double x) { Kugla::x = x; return *this; }
    Kugla &PostaviY(double y) { Kugla::y = y; return *this; }
    Kugla &PostaviZ(double z) { Kugla::z = z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::x = x; Kugla::y = y; Kugla::z = z; return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        std::tie(x,y,z) = centar; return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r = r; return *this;
    }
    void Ispisi() const { std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"; std::cout<<std::endl;}
    void Transliraj(double delta_x, double delta_y, double delta_z) {
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
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) { 
    return Kugla::DaLiSuJednaki(k1.DajCentar(),k2.DajCentar()) && Kugla::DaLiSuJednaki(k1.DajPoluprecnik(),k2.DajPoluprecnik()); 
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) { return Kugla::DaLiSuJednaki(k1.DajPoluprecnik(),k2.DajPoluprecnik()); }

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) { return Kugla::DaLiSuJednaki(k1.DajCentar(),k2.DajCentar()); }

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) { 
    return Kugla::DaLiSuJednaki(k1.DajPoluprecnik()+k2.DajPoluprecnik(),RastojanjeCentara(k1,k2)); 
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) { 
    return (Kugla::DaLiSuJednaki(RastojanjeCentara(k1,k2)+k1.DajPoluprecnik(),k2.DajPoluprecnik()) || Kugla::DaLiSuJednaki(RastojanjeCentara(k1,k2)+k2.DajPoluprecnik(),k1.DajPoluprecnik())); 
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) { return k1.DajPoluprecnik()+k2.DajPoluprecnik()>RastojanjeCentara(k1,k2); }

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) { 
    return k1.DajPoluprecnik()+k2.DajPoluprecnik()>RastojanjeCentara(k1,k2) && !(k1.DaLiSadrzi(k2)) && !(k2.DaLiSadrzi(k1));
}

bool Kugla::DaLiSadrzi(const Kugla &k) const { return RastojanjeCentara(*this,k) + k.DajPoluprecnik() <= this->DajPoluprecnik(); }

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return sqrt(pow(k2.DajX()-k1.DajX(),2)+pow(k2.DajY()-k1.DajY(),2)+pow(k2.DajZ()-k1.DajZ(),2));
}
int main ()
{
    std::cout<<"Unesite broj kugla: ";
    int n;
    std::cin>>n;
    while(!std::cin || n<=0) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
            std::cin>>n;
        }
    vector<shared_ptr<Kugla>> kugle(n);
    
    // Unos kugli
    for(int i=0;i<n;i++) {
        double x,y,z,r;
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        while(!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Neispravan centar\n";
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if(!std::cin || r<0) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Ilegalan poluprecnik\n";
            i--;
            continue;
        }
        kugle.at(i) = std::make_shared<Kugla>(x,y,z,r);
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx,dy,dz; 
    std::cin>>dx>>dy>>dz;
    while(!std::cin) {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
        std::cin>>dx>>dy>>dz;
    }
    std::transform(kugle.begin(), kugle.end(), kugle.begin() , [dx,dy,dz](shared_ptr<Kugla> p_kugla)->shared_ptr<Kugla> {
        p_kugla->Transliraj(dx,dy,dz);
        return p_kugla;
    });
    std::sort(kugle.begin(), kugle.end(), [](shared_ptr<Kugla> k1, shared_ptr<Kugla> k2)->bool {
        return k1->DajZapreminu() < k2->DajZapreminu();
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:\n";
    std::for_each(kugle.begin(), kugle.end(), [](shared_ptr<Kugla> kugla){
        kugla->Ispisi();
        std::cout<<std::endl;
    });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto maxPovrsina = std::max_element(kugle.begin(), kugle.end(), [](shared_ptr<Kugla> k1, shared_ptr<Kugla> k2)->bool {
        return k2->DajPovrsinu() > k1->DajPovrsinu();
    });
    (*maxPovrsina)->Ispisi();
    int offset = 0;
    int postojePresjeci=false;
    std::for_each(kugle.begin(), kugle.end(), [&offset,&postojePresjeci,&kugle](shared_ptr<Kugla> p_kugla)->void {
        offset++;
        std::for_each(kugle.begin()+offset, kugle.end(), [p_kugla, &postojePresjeci](shared_ptr<Kugla> p_kugla2)->void {
            if(DaLiSeSijeku(*p_kugla, *p_kugla2)) {
                std::cout<<"\nPresjecaju se kugle: ";
                p_kugla->Ispisi();
                //std::cout<<"\n";
                p_kugla2->Ispisi();
                postojePresjeci = true;
            }
        });
    });
    if(!postojePresjeci)
        std::cout<<"\nNe postoje kugle koje se presjecaju!";
	return 0;
}
