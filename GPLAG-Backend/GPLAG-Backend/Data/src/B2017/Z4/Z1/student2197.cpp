/B2017/2018: ===TITLE===
#include <iostream>
#include <stdexcept>
#include <cmath>
#define epsilon 0.00000000001
#include <memory>
class Kugla{
    double x,y,z,poluprecnik;
public:
    explicit Kugla(double r = 0) : x(0), y(0),z(0) {};
    Kugla (double x, double y, double z, double r=0) {
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        poluprecnik=r;
    }
    
    explicit Kugla(const std::tuple<double,double,double> &centar,double r = 0){};
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double,double, double> DajCentar() const;
    double DajPoluprecnik() const { return poluprecnik; }
    double DajPovrsinu() const { return 4*poluprecnik*poluprecnik*4*atan(1); }
    double DajZapreminu() const { return (4/3) * pow(poluprecnik,3)*4*atan(1); }
    Kugla &PostaviX(double x) { Kugla::x=x; }
    Kugla &PostaviY(double y) { Kugla::y=y; }
    Kugla &PostaviZ(double z) { Kugla::z=z; }
    Kugla &PostaviCentar(double x, double y, double z);
    Kugla &PostaviCentar( std::tuple<double,double, double> &centar);
    Kugla &PostaviPoluprecnik(double r) { poluprecnik=r; }
    void Ispisi() const { std::cout<<"{ ("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"})";  }
    void Transliraj(double delta_x, double delta_y, double delta_z){ x+=delta_x; y+=delta_y; z+=delta_z; }
  
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k)const ;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
    
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    if(k1.DajX()==k2.DajX() && k1.DajY()==k2.DajY() && k1.DajZ()==k2.DajZ() && k1.poluprecnik==k2.poluprecnik)
    return true;
return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
     if(k1.DajX()!=k2.DajX() && k1.DajY()!=k2.DajY() && k1.DajZ()!=k2.DajZ() && k1.poluprecnik==k2.poluprecnik)
    return true;
return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    if(k1.DajX()==k2.DajX() && k1.DajY()==k2.DajY() && k1.DajZ()==k2.DajZ() && k1.poluprecnik!=k2.poluprecnik)
    return true;
return false;
}
  bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
   if(sqrt((k2.DajX()-k1.DajX()) * (k2.DajX()-k1.DajX())  +  (k2.DajY()-k1.DajY()) * (k2.DajY()-k1.DajY()) +
   (k2.DajY()-k1.DajY()) * (k2.DajZ()-k1.DajZ()))- k1.DajPoluprecnik()+ k2.DajPoluprecnik()<epsilon)
   return true;
   return false;
  }
 
 /*
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k)const ;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);*/

int main ()
{
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Kugla>> v(n);
    for(int i=0; i<n; i++){
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
    }
    double delta_x,delta_y,delta_z;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z):";
    std::cin>>delta_x>>delta_y>>delta_z;
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: ";
    
	return 0;
}
























