/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <algorithm>

class Kugla{
  double x,y,z,r;
  static bool jednako(double a, double b){
     double eps(0.0000000001);
     return std::fabs(a-b)<eps*(std::fabs(a)+std::fabs(b));
 }
  public:
  explicit Kugla(double r=0) {if(r<0) throw std::domain_error ("Ilegalan poluprecnik"); x=0; y=0; z=0; Kugla::r=r; }
  Kugla(double x, double y, double z, double r=0){if(r<0) throw std::domain_error ("Ilegalan poluprecnik"); Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r; }
  explicit Kugla(std::tuple<double,double,double> &centar, double r=0) {if(r<0) throw std::domain_error ("Ilegalan poluprecnik"); Kugla::r=r; std::tie(x,y,z)=centar;}
  double DajX() const{return x;}
  double DajY() const{return y;}
  double DajZ() const{return z;}
  std::tuple<double,double,double> DajCentar() const{std::tuple<double,double,double> t(std::make_tuple(x,y,z)); return t;}
  double DajPoluprecnik() const{return r;}
  double DajPovrsinu() const{return 4*4*atan(1)*r*r;}
  double DajZapreminu() const{return (4./3)*4*atan(1)*r*r*r;}
  Kugla &PostaviX(double a){x=a; return *this;}
  Kugla &PostaviY(double b){y=b; return *this;}
  Kugla &PostaviCentar(double a, double b, double c){x=a; y=b; z=c; return *this;}
  Kugla &PostaviCentar(const std::tuple<double,double,double> &centar){std::tie(x,y,z)=centar; return *this;}
  Kugla &PostaviPoluprecnik(double r){if(r<0) throw std::domain_error ("Ilegalan poluprecnik"); return *this;}
  void Ispisi() const{std::cout << "{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl; }
  void Transliraj(double delta_x, double delta_y, double delta_z){x+=delta_x; y+=delta_y; z+=delta_z;}
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
  bool DaLiSadrzi(const Kugla &k) const{
      double razlika_poluprecnika(std::fabs(r-k.r));
      return RastojanjeCentara(*this, k)<razlika_poluprecnika;
  }
  friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};
 
  bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
      return Kugla::jednako(k1.x, k2.x) && Kugla::jednako(k1.y, k2.y) && Kugla::jednako(k1.z, k2.z) && Kugla::jednako(k1.r, k2.r);
  }
  bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
      return Kugla::jednako(k1.r, k2.r);
  }
  bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){ 
      return Kugla::jednako(k1.x, k2.x) && Kugla::jednako(k1.y, k2.y) && Kugla::jednako(k1.z, k2.z); 
  }
  bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
      double zbir_poluprecnika(k1.r+k2.r);
      return Kugla::jednako(RastojanjeCentara(k1,k2), zbir_poluprecnika);
  }
  bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
      double razlika_poluprecnika(std::fabs(k1.r-k2.r));
      return Kugla::jednako(RastojanjeCentara(k1,k2), razlika_poluprecnika);
  }
  bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
      double zbir_poluprecnika(k1.r+k2.r);
      return RastojanjeCentara(k1,k2)<zbir_poluprecnika && !Kugla::jednako(RastojanjeCentara(k1,k2),zbir_poluprecnika);
  }
  bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
        double zbir_poluprecnika(k1.r+k2.r);
        double razlika_poluprecnika(std::fabs(k1.r-k2.r));
        return RastojanjeCentara(k1,k2)<zbir_poluprecnika && RastojanjeCentara(k1,k2)>razlika_poluprecnika 
        && !Kugla::jednako(RastojanjeCentara(k1,k2),zbir_poluprecnika)&& !Kugla::jednako(RastojanjeCentara(k1,k2),razlika_poluprecnika);
  }
  double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
      double x(k2.x-k1.x);
      double y(k2.y-k1.y);
      double z(k2.z-k1.z);
      return std::sqrt(x*x+y*y+z*z);
  }
  
int main ()
{ 
    int n;
    std::cout << "Unesite broj kugla: ";
    for(;;){
        int a(0);
        std::cin >> a;
        if(a<=0 || !std::cin) {
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            continue;
        }
            n=a;
            break;
    }
    std::vector<std::shared_ptr<Kugla>>kugle(n);
    
    for(int i=0; i<n; i++){
        std::cout << "Unesite centar "<<i+1<<". kugle: ";
        double a, b, c;
        std::cin >> a >> b >> c;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << "Neispravan centar" << std::endl;
            i--; continue;
        }
        double d;
        std::cout << "Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin >> d;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << "Ilegalan poluprecnik" << std::endl;
            i--; continue;
        }
        try{
        kugle[i]=std::make_shared<Kugla>(a,b,c,d);
        }
        catch(std::domain_error greska){
            std::cout << greska.what() << std::endl;
            kugle[i]=nullptr;
            i--;
        }
    }
    
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x, delta_y, delta_z;
    for(;;){
        double dx, dy, dz;
        std::cin >> dx >> dy >> dz;
        if(!std::cin){
            std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            continue;
        }
        delta_x=dx; delta_y=dy; delta_z=dz;
        break;
    }
    
   std::transform(kugle.begin(), kugle.end(), kugle.begin(), [delta_x,delta_y,delta_z](std::shared_ptr<Kugla> p){(*p).Transliraj(delta_x,delta_y,delta_z); return p;});
    
    std::sort(kugle.begin(), kugle.end(), [](std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2){return (*p1).DajZapreminu()<(*p2).DajZapreminu();});
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(kugle.begin(), kugle.end(),[](std::shared_ptr<Kugla> p){(*p).Ispisi(); });
    
    auto najveca(std::max_element(kugle.begin(), kugle.end(), [](std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2){return (*p1).DajPovrsinu()<(*p2).DajPovrsinu();}));
	std::cout << "Kugla sa najvecom povrsinom je: "; (**najveca).Ispisi();
	
//	std::cout << std::endl;
	int dalje(0);
	bool ima(false);
	std::for_each(kugle.begin(), kugle.end(), 
	[&dalje,kugle, &ima](std::shared_ptr<Kugla> p){dalje++; std::for_each(kugle.begin()+dalje, kugle.end(), 
	[&dalje, p, &ima](std::shared_ptr<Kugla> q){if (DaLiSeSijeku(*p,*q)) {
	    ima=true;
	    std::cout << "Presjecaju se kugle: "; p->Ispisi(); q->Ispisi(); 
	}});
	});
    if(!ima) std::cout << "Ne postoje kugle koje se presjecaju!" << std::endl;
	
	return 0;
}
