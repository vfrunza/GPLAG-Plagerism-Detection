/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <vector>

const double pi=4*atan(1);
const double eps=0.0000000001;

class Kugla {
    double x, y, z, r;
    
  public:
  
    explicit Kugla(double r = 0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=0; y=0; z=0; Kugla::r=r;
    }
    
    Kugla(double x, double y, double z, double r = 0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r;
    }
    
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); Kugla::r=r; 
        
    }
    
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x, y, z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*pi; }
    double DajZapreminu() const { return 4*r*r*r*pi/3; }
    
    Kugla &PostaviX(double x) { Kugla::x=x; return *this; }
    Kugla &PostaviY(double y) { Kugla::y=y; return *this; }
    Kugla &PostaviZ(double z) { Kugla::z=z; return *this; }
    
    Kugla &PostaviCentar(double x, double y, double z) { Kugla::x=x; Kugla::y=y; Kugla::z=z; return *this; }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) { x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); return *this; }
    Kugla &PostaviPoluprecnik(double r) { if (r<0) throw std::domain_error("Ilegalan poluprecnik"); Kugla::r=r; return *this; }
    
    void Ispisi() const { std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl; }
    
    void Transliraj(double delta_x, double delta_y, double delta_z) { x+=delta_x; y+=delta_y; z+=delta_z; }
    
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    
    bool DaLiSadrzi(const Kugla &k) const { 
        if (DaLiSuIdenticne(*this, k)) return true;
        return (RastojanjeCentara(*this, k)<r-k.DajPoluprecnik() || std::fabs(RastojanjeCentara(*this, k)-(r-k.DajPoluprecnik()) ) <= eps* (std::fabs(RastojanjeCentara(*this, k))+std::fabs(r-k.DajPoluprecnik())) );
    }
    
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};


bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) { return (std::fabs(k1.x-k2.x)<=eps*(std::fabs(k1.x)+std::fabs(k2.x)) && std::fabs(k1.y-k2.y)<=eps*(std::fabs(k1.y)+std::fabs(k2.y)) && std::fabs(k1.z-k2.z)<=eps*(std::fabs(k1.z)+std::fabs(k2.z)) && std::fabs(k1.r-k2.r)<=eps*(std::fabs(k1.r)+std::fabs(k2.r))); }
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) { return std::fabs(k1.r-k2.r)<=eps*(std::fabs(k1.r)+std::fabs(k2.r)); }
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) { return (RastojanjeCentara(k1, k2)<eps); }

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    double x(RastojanjeCentara(k1, k2));
    double zbir(k1.DajPoluprecnik()+k2.DajPoluprecnik());
    return (std::fabs(x-zbir)<=eps*(std::fabs(x)+std::fabs(zbir)));
}
    
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    if (DaLiSuIdenticne(k1, k2)) return false;
    double x(RastojanjeCentara(k1, k2));
    double razlika(std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
    return (std::fabs(x-razlika)<=eps*(std::fabs(x)+std::fabs(razlika)));
}
    
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) { return ( RastojanjeCentara(k1, k2)<k1.DajPoluprecnik()+k2.DajPoluprecnik() ); }
    
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    if (DaLiSuIdenticne(k1, k2)) return true; //hm
    return (RastojanjeCentara(k1, k2)<k1.DajPoluprecnik()+k2.DajPoluprecnik() &&  RastojanjeCentara(k1, k2)>std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}

int main ()
{
    int n;
    std::cout << "Unesite broj kugla: ";
    while (std::cin >> n, !std::cin || n<=0) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear(); std::cin.ignore(1000, '\n');
    }
    
    std::vector<std::shared_ptr<Kugla>> v;
    v.resize(n);
    
    for (int i=0; i<n; i++) {
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        double x, y, z, r;
        std::cin >> x >> y >> z;
        if (!std::cin) { std::cout << "Neispravan centar" << std::endl; std::cin.clear(); std::cin.ignore(1000, '\n'); i--; continue; }
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        std::cin >> r;
        if (!std::cin) { std::cout << "Ilegalan poluprecnik" << std::endl; std::cin.clear(); std::cin.ignore(1000, '\n'); i--; continue; }
        try {
            v.at(i)=std::make_shared<Kugla>(x, y, z, r);
        }
        catch(std::exception &izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            i--;
        }
    }
    double d_x, d_y, d_z;
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    while ( std::cin >> d_x >> d_y >> d_z, !std::cin) {
        std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
        std::cin.clear(); std::cin.ignore(10000, '\n');
    }
    std::transform(v.begin(), v.end(), v.begin(), [d_x, d_y, d_z] (std::shared_ptr<Kugla> p1) { (*p1).Transliraj(d_x, d_y, d_z); return p1; } );
    std::sort (v.begin(), v.end(), [](std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) { return (*p1).DajZapreminu()<(*p2).DajZapreminu(); });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each (v.begin(), v.end(), [](std::shared_ptr<Kugla> p) { (*p).Ispisi(); });
    
    
    auto it(std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) { return (*p1).DajPovrsinu()<(*p2).DajPovrsinu(); }) );
	std::cout << "Kugla sa najvecom povrsinom je: "; if (it!=v.end()) (*it)->Ispisi();
	
	
	int i(0);
	bool ima_nekih_koje_se_presjecaju(false);
	std::for_each( v.begin(), v.end(), [v, &i, &ima_nekih_koje_se_presjecaju] (std::shared_ptr<Kugla> p1) { i++;
	    std::for_each ( v.begin()+i, v.end(), [p1, &ima_nekih_koje_se_presjecaju] (std::shared_ptr<Kugla> p2) { 
	        if (DaLiSeSijeku(*p1, *p2)) { ima_nekih_koje_se_presjecaju=true; std::cout << "Presjecaju se kugle: "; (*p1).Ispisi(); (*p2).Ispisi(); std::cout << std::endl; } } ); } );
	
	if (!ima_nekih_koje_se_presjecaju) std::cout << "Ne postoje kugle koje se presjecaju!";
	
	
	
	
	/*Kugla k1(1, 0, 0, 2);
	Kugla k2(1, 0, 0, 2);
	
	if (DaLiSuKoncentricne(k1, k2)) std::cout << "koncentricne" << std::endl;
	if (DaLiSuIdenticne(k1, k2)) std::cout << "identicne" << std::endl;
	if (DaLiSeDodirujuIznutra(k1, k2)) std::cout << "dodiruju se iznutra" << std::endl;
	if (DaLiSeDodirujuIzvana(k1, k2)) std::cout << "dodiruju se izvana" << std::endl;
	if (DaLiSePreklapaju(k1, k2)) std::cout << "preklapaju se" << std::endl;
	if (DaLiSeSijeku(k1, k2)) std::cout << "sijeku se" << std::endl;
	if (DaLiSuPodudarne(k1, k2)) std::cout << "podudarne" << std::endl;
	if (k1.DaLiSadrzi(k2)) std::cout << "sadrzi";
	*/
	
	
	return 0;
}
