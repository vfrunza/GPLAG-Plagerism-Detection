/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <new>
#include <memory>
#include <algorithm>

const double pi=4*atan(1);
const double epsilon=pow(10,-10);

class Kugla {
    double x,y,z,r;
    
public:
    explicit Kugla(double r = 0) { if (r<0) throw std::domain_error ("Ilegalan poluprecnik"); Kugla::r=r; x=0; y=0; z=0; }
    Kugla(double x, double y, double z, double r = 0){ if (r<0) throw std::domain_error ("Ilegalan poluprecnik"); 
    Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r; }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) { 
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::x=std::get<0>(centar); Kugla::y=std::get<1>(centar); Kugla::z=std::get<2>(centar); Kugla::r=r; }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x,y,z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*pi*r*r; }
    double DajZapreminu() const { return (4/3)*r*r*r*pi; }
    Kugla &PostaviX(double x) { Kugla::x=x; return *this; }
    Kugla &PostaviY(double y) { Kugla::y=y; return *this; }
    Kugla &PostaviZ(double z) { Kugla::z=z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) { Kugla::x=x; Kugla::y=y; Kugla::z=z; return *this; }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) { 
        Kugla::x=std::get<0>(centar); Kugla::y=std::get<1>(centar); Kugla::z=std::get<2>(centar); return *this; }
    Kugla &PostaviPoluprecnik(double r){ 
         if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
         Kugla::r=r; return *this; }
    void Ispisi() const { std::cout << "{(" << x <<"," << y <<","<< z <<")," << r <<"}" << std::endl; }
    void Transliraj(double delta_x, double delta_y, double delta_z){ 
        Kugla::x=x+delta_x; Kugla::y=y+delta_y; Kugla::z=z+delta_z; }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
   // friend bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);

};

bool Jednake (double a, double b){
    return abs(a-b)<=epsilon*(abs(a)+abs(b));
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){                 
    return (Jednake(k1.x,k2.x) && Jednake(k1.y,k2.y) && Jednake(k1.z,k2.z) && Jednake(k1.r,k2.r));
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    return Jednake(k1.r,k2.r);
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    return (Jednake(k1.x,k2.x) && Jednake(k1.y,k2.y) && Jednake(k1.z,k2.z));
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    return Jednake(RastojanjeCentara(k1,k2),k1.r+k2.r);
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    return (RastojanjeCentara(k1,k2)<k1.r+k2.r);
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    double veci;
    if (k1.r>k2.r){ veci=k1.r; }
    else { veci=k2.r; }
    return (k1.r+k2.r+RastojanjeCentara(k1,k2))<2*veci;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    return (RastojanjeCentara(k1,k2)>std::fabs(k1.r-k2.r) && RastojanjeCentara(k1,k2)<k2.r+k1.r);
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return sqrt(pow(k1.x-k2.x,2)+pow(k1.y-k2.y,2)+pow(k1.z-k2.z,2));
    
}

int main ()
{
    int n;
    std::cout << "Unesite broj kugla: ";
    std::cin >> n;
    while (!std::cin || n<=0) {
    std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    std::cin >> n;
    }
    
    
    std::vector<std::shared_ptr<Kugla>> v;
    
    for (int i=1; i<=n; i++){
        Kugla a;
        double x,y,z,r;
        std::cout << "Unesite centar " << i <<". kugle: ";
        std::cin >> x >> y >> z;
        if (!std::cin){ std::cout << "Neispravan centar" << std::endl; i--;  std::cin.clear();
    std::cin.ignore(10000,'\n');   continue; }
        std::cout << "Unesite poluprecnik " << i <<". kugle: ";
        std::cin >> r;
        if (!std::cin || r<0){ std::cout << "Ilegalan poluprecnik" << std::endl; i--;  std::cin.clear();
    std::cin.ignore(10000,'\n');   continue; }
        a.PostaviX(x); a.PostaviY(y); a.PostaviZ(z); a.PostaviPoluprecnik(r);
        v.push_back(std::make_shared<Kugla> (a));
        
    }
    
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double x,y,z;
    while(1){
    std::cin >> x >> y >> z;
    if (!std::cin){ std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl; std::cin.clear();
    std::cin.ignore(10000,'\n'); continue; }
    break;
    }
    std::transform(v.begin(),v.end(),v.begin(), [x, y, z](std::shared_ptr<Kugla> &kugla){
        kugla->Transliraj(x,y,z);
        return kugla;
    });
    std::sort(v.begin(), v.end(), [] (std::shared_ptr<Kugla> kugla1, std::shared_ptr<Kugla> kugla2){
        return kugla1->DajZapreminu()<kugla2->DajZapreminu();
    });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:" << std::endl;
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Kugla> kugla){ kugla->Ispisi();});
    
    //for (int i=0; i<v.size(); i++){
     //v[i]->Ispisi();
    //}
    
    std::cout << "Kugla sa najvecom povrsinom je: " ;
    (*std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> kugla1, std::shared_ptr<Kugla> kugla2){
        return kugla1->DajPovrsinu()<kugla2->DajPovrsinu();
    }))->Ispisi();
    
    bool istina=0;
    int brojac=1;
    
    std::for_each(v.begin(),v.end(),[&v,&brojac,&istina](const std::shared_ptr<Kugla> &kugla1){
        std::for_each(v.begin()+brojac,v.end(), [&kugla1,&istina] (const std::shared_ptr<Kugla> &kugla2){
            if (DaLiSeSijeku(*kugla1,*kugla2)){
                std::cout << "Presjecaju se kugle: ";
                istina=1;
               kugla1->Ispisi(); kugla2->Ispisi(); 
            }});
        brojac++;
    });
    if (istina==0) std::cout << "Ne postoje kugle koje se presjecaju!" << std::endl; 

    
   
	return 0;
}
