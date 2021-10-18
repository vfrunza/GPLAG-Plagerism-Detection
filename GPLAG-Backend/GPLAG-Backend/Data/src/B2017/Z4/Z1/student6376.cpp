/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>



const double PI (4* std::atan(1));
const double EPS (pow(10,-10));

class Kugla
{
    double x,y,z;
    double r;
    void TestPoluprecnika (double r) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    }
   

public:
    explicit Kugla (double r=0): r(r), x(0),y(0),z(0) {
        TestPoluprecnika(r);
    }
    Kugla (double x,double y,double z,double r=0): r(r), x(x), y(y), z(z) {
        TestPoluprecnika(r);
    }
    explicit Kugla(const std::tuple<double,double,double> &centar, double r=0)  { std::tie(x,y,z)=centar; this->r=r;
        TestPoluprecnika(r);
    }
    double DajX () const {
        return x;
    }
    double DajY () const {
        return y;
    }
    double DajZ () const {
        return z;
    }
    std::tuple <double,double,double> DajCentar () const {
        return std::tie(x,y,z);
    }
    double DajPoluprecnik () const {
        return r;
    }
    double DajPovrsinu () const {
        return 4*r*r*PI;
    }
    double DajZapreminu () const {
        return ((4/3)*r*r*r*PI);
    }
    Kugla &PostaviX (double x) {
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY  (double y) {
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ (double z) {
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar (double x,double y,double z) {
        *this=Kugla(x,y,z);
        return *this;
    }
    Kugla &PostaviCentar (const std::tuple<double,double,double> &centar) {
        std::tie(x,y,z)=centar;
        return *this;
    }
    Kugla &PostaviPoluprecnik (double r) {
        TestPoluprecnika(r);
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
    }
    void Transliraj (double delta_x, double delta_y,double delta_z) {
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }
    friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne (const Kugla &k1,const Kugla &k2);
    friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra (const Kugla &k1,const Kugla &k2);
    friend bool DaLiSePreklapaju (const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeSijeku (const Kugla &k1,const Kugla &k2);
    bool DaLiSadrzi (const Kugla &k) const { 
        return (RastojanjeCentara(*this,k)< this->r);
    }
    friend double RastojanjeCentara (const Kugla &k1,const Kugla &k2);
};

bool DaLiSuIdenticne (const Kugla &k1,const Kugla &k2)
{
    return  (abs(k1.x-k2.x)<EPS*(abs(k1.x)+abs(k2.x)) && abs(k1.y-k2.y)<EPS*(abs(k1.y)+abs(k2.y))  && abs(k1.z-k2.z)<EPS*(abs(k1.z)+abs(k2.z)) && abs(k1.r-k2.r)<EPS*(abs(k1.r)+abs(k2.r)));
}
bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2)
{
    return (abs(k1.r-k2.r)<EPS*(abs(k1.r)+abs(k2.r)));
}
bool DaLiSuKoncentricne (const Kugla &k1,const Kugla &k2)
{
    return (abs(k1.x-k2.x)<EPS*(abs(k1.x)+abs(k2.x)) && abs(k1.y-k2.y)<EPS*(abs(k1.y)+abs(k2.y)) && abs(k1.z-k2.z)<EPS*(abs(k1.z)+abs(k2.z)));
}
bool DaLiSeDodirujuIzvana (const Kugla &k1,const Kugla &k2)
{
    return (abs(RastojanjeCentara(k1,k2)-(k1.r+k2.r))<EPS*(abs(RastojanjeCentara(k1,k2))+abs(k1.r+k2.r)));
}
bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2) {
    return (abs(RastojanjeCentara(k1,k2)-abs(k1.r-k2.r))<EPS*(abs(RastojanjeCentara(k1,k2))+abs(k1.r-k2.r)));
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    return (RastojanjeCentara(k1,k2)<(k1.r+k2.r) && RastojanjeCentara(k1,k2)>abs(k1.r-k2.r) && (DaLiSuIdenticne(k1,k2)==false));
}
bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2) {
    return (DaLiSeSijeku(k1,k2)==true || (RastojanjeCentara(k1,k2)<abs(k1.r-k2.r)));
}

double RastojanjeCentara(const Kugla &k1,const Kugla &k2) {
    double d;
    d=sqrt(pow((k1.x-k2.r),2)+pow((k1.y-k2.y),2)+pow((k1.z-k2.z),2));
    return abs(d);
}


int main ()
{
    int n;
    std::cout<<"Unesite broj kugla:: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Kugla>> v (n);
   for (int i=0;i<n;i++) {
       std::cout<<"Unesite centar "<<i+1<<". kugle: ";
       double a,b,c;
       for (;;) {
       std::cin>>a>>b>>c;
       if (std::cin) break;
       std::cout<<"Neispravan unos, unesite ponovo: ";
       std::cin.clear();
       std::cin.ignore(10000,'\n');
       }
       std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
       double poluprecnik;
       for (;;) {
       std::cin>>poluprecnik;
       if (std::cin && poluprecnik>0) break;
       std::cout<<"Neispravan unos,unesite ponovo: ";
       std::cin.clear();
       std::cin.ignore(10000,'\n');
       }
       v.at(i)= std::make_shared<Kugla> (a,b,c,poluprecnik);
   }
  std::cout<<"Unesite parametre tanslacije (delta_x,delta_y,delta_z): ";
  double dx,dy,dz;
  std::cin>>dx>>dy>>dz;

   
    
    
    
    return 0;
}
