
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#define PI 4*std::atan(1)
#include <algorithm>
#include <memory>

bool JesuLiJednaki (double x, double y, double Eps = 1e-10) {
    return std::fabs(x-y) <= Eps * (std::fabs(x) + std::fabs(y));
}
class Kugla {
double x, y, z, r;
public:
 explicit Kugla(double r = 0) {
     if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
     Kugla::r = r;
 }
Kugla(double x, double y, double z, double r = 0){
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r;
}
explicit Kugla(const std::tuple<double, double, double> & centar, double r = 0){
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    Kugla::x=std::get<0>(centar); Kugla::y=std::get<1>(centar); Kugla::z=std::get<2>(centar); Kugla::r=r;
}
double DajX() const {
 return x;
}
double DajY() const {
    return y;
};
double DajZ() const {
    return z;
};
std::tuple<double, double, double> DajCentar() const {
    return std::make_tuple(x, y, z);
}
double DajPoluprecnik() const {
    return r;
}
double DajPovrsinu() const {
    return 4*PI*r*r;
}
double DajZapreminu() const {
    return 4/3*PI*r*r*r;
}
Kugla &PostaviX(double x) {
    Kugla::x = x;
    return *this;
}
Kugla & PostaviY(double y) {
      Kugla::y = y;
    return *this;
}
Kugla & PostaviZ(double z) {
    Kugla::z = z;
    return *this;
}
Kugla &PostaviCentar(double x, double y, double z) {
    Kugla::x=x; Kugla::y=y; Kugla::z=z;
    return *this;
}
Kugla &PostaviCentar(const std::tuple<double, double, double> & centar){
    Kugla::x = std::get<0> (centar);
    Kugla::y = std::get<1> (centar);
    Kugla::z = std::get<2> (centar);
    return *this;
}
Kugla &PostaviPoluprecnik(double r){
    Kugla::r = r;
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    return *this;
}
void Ispisi() const {
    std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}\n";
}
void Transliraj(double delta_x, double delta_y, double delta_z){
    x+=delta_x; y+=delta_y; z+=delta_z;
}
friend bool DaLiSuIdenticne(const Kugla & k1, const Kugla & k2);
friend bool DaLiSuPodudarne(const Kugla & k1, const Kugla & k2);
friend bool DaLiSuKoncentricne(const Kugla & k1, const Kugla & k2);
friend bool DaLiSeDodirujuIzvana(const Kugla & k1, const Kugla & k2);
friend bool DaLiSeDodirujuIznutra(const Kugla & k1, const Kugla & k2);
friend bool DaLiSePreklapaju(const Kugla & k1, const Kugla & k2);
friend bool DaLiSeSijeku(const Kugla & k1, const Kugla & k2);
bool DaLiSadrzi(const Kugla & k) const;
friend double RastojanjeCentara(const Kugla & k1, const Kugla & k2);
};

bool DaLiSuIdenticne(const Kugla & k1, const Kugla & k2) {
    return (JesuLiJednaki (k1.x, k2.x  ) &&
        JesuLiJednaki (k1.y, k2.y  ) &&
        JesuLiJednaki (  k1.z, k2.z) &&
       JesuLiJednaki (  k1.r, k2.r) ) ;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    return JesuLiJednaki (  k1.r, k2.r);
}
bool DaLiSuKoncentricne(const Kugla & k1, const Kugla & k2){
    return (JesuLiJednaki (  k1.x, k2.x) &&
        JesuLiJednaki (  k1.y, k2.y) &&
        JesuLiJednaki (  k1.z, k2.z) );
}
double RastojanjeCentara (double x1, double y1, double z1,
 double x2, double y2, double z2) {
    return std::sqrt (  (x1-x2)*(x1-x2)+
                    (y1-y2)*(y1-y2)+
                    (z1-z2)*(z1-z2)
        );
}
bool DaLiSeDodirujuIzvana(const Kugla & k1, const Kugla & k2) {
    return  JesuLiJednaki (  RastojanjeCentara(k1.x, k1.y, k1.z, k2.x, k2.y, k2.z), k1.r +k2.r);
}
bool DaLiSeDodirujuIznutra(const Kugla & k1, const Kugla & k2) {
    return  RastojanjeCentara(k1.x, k1.y, k1.z, k2.x, k2.y, k2.z) < (k1.r +k2.r);
}
bool DaLiSePreklapaju(const Kugla & k1, const Kugla & k2) {
    return  RastojanjeCentara(k1.x, k1.y, k1.z, k2.x, k2.y, k2.z) <  (k1.r +k2.r) ;
}
bool DaLiSeSijeku (const Kugla & k1, const Kugla & k2) {
    return DaLiSePreklapaju(k1, k2);
}

bool Kugla::DaLiSadrzi(const Kugla & k) const {
    if (Kugla::r - k.r < 0 ) return false;
    return !(RastojanjeCentara(k.x, k.y, k.z, Kugla::x, Kugla::y, Kugla::z) > (Kugla::r - k.r) ) ;
}

typedef std::shared_ptr<Kugla> pametni;
int main ()
{

    int n;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
   std::vector<pametni> vektor;
   double x,y,z,r;
    for (int i=1; i<=n; i++){
        try {
        std::cout<<"Unesite centar "<<i<<". kugle: ";
        std::cin>>x;
        if (!std::cin) throw std::domain_error("Ilegalan unos!");
        std::cin>>y;
        if (!std::cin) throw std::domain_error("Ilegalan unos!");
        std::cin>>z;
        if (!std::cin) throw std::domain_error("Ilegalan unos!");
        std::cout<<"Unesite poluprecnik "<<i<<". kugle: ";
        std::cin>>r;
        if (!std::cin) throw std::domain_error("Ilegalan unos!");
        auto p (std::make_shared<Kugla> (Kugla(x,y,z,r)));
        vektor.push_back(p);
        }
        catch(std::domain_error e){
            std::cout<<e.what();
            i--;
        }
    }   
  std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x, delta_y, delta_z;
    std::cin>> delta_x>> delta_y>>delta_z;
    std::transform (std::begin(vektor), std::end(vektor), std::begin(vektor), [&delta_x, &delta_y, &delta_z] (pametni &k) { k->Transliraj(delta_x, delta_y, delta_z); return k; }  );
    std::sort (std::begin(vektor), std::end(vektor), [](pametni k1, pametni k2) { return  (k1->DajZapreminu() ) < (k2->DajZapreminu() ); } );
    std::for_each (std::begin(vektor), std::end(vektor), [](pametni &k) {k->Ispisi();} );
    auto q ( std::max_element (std::begin (vektor), std::end(vektor), [] (pametni &k1, pametni &k2){return k1->DajPovrsinu()<k2->DajPovrsinu();  }   ) );
    std::cout<<"Kugla sa najvecom povrsinom je: "; (*q)->Ispisi();
    int ima (0);
    int i(1);
    std::for_each (std::begin(vektor), std::end(vektor), [&vektor, &ima, &i](pametni &k1) {
    std::for_each (std::begin (vektor)+i, std::end(vektor), [&k1, &ima](pametni &k2) {
   // std::cout<<!DaLiSuIdenticne(  (*k1), (*k2) ) << DaLiSeSijeku(  (*k1), (*k2) ) <<"\n" ;
        if (!DaLiSuIdenticne(  (*k1), (*k2) )  && DaLiSeSijeku(  (*k1), (*k2) )) {
            ima = 1;
            std::cout<<"Presjecaju se kugle: "; k1->Ispisi(); std::cout<< "\n"; k2->Ispisi();
        }
     } );
    i++;
    });
    if (!ima) std::cout<<"Ne postoje kugle koje se presjecaju!";

    return 0;
}

