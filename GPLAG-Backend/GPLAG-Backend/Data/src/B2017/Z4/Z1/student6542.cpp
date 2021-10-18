/B2017/2018: Zad}aća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <memory>
#include <algorithm>

const double epsilon=pow(10,-10);
class Kugla {
    double x;
    double y;
    double z;
    double r;
public:
    explicit Kugla(double r=0){
        if(r<0) throw std::domain_error("Ilegalan Poluprecnik");
        x=y=z=0;
        
    }
    
    Kugla(double x, double y, double z,double r=0){
        if(r<0) throw std::domain_error("Ilegalan Poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
    }
    
    explicit Kugla (const std::tuple<double,double,double> &centar, double r=0){
        if(r<0) throw std::domain_error("Ilegalan Poluprecnik");
        x=std::get<0> (centar);
        y=std::get<1> (centar);
        z=std::get<2> (centar);
    }
    double DajX() const { return x;}
    double DajY() const {return y;}
    double DajZ() const {return z;}
   
   std::tuple<double,double,double> DajCentar() const {
        return std::tuple<int,int,int> (x,y,z);    
    }
    
    double DajPoluprecnik() const {return r;}
    double DajPovrsinu() const {return 4*r*r*4*atan(1); }
    double DajZapreminu() const{return ((4/3)*(r*r*r))/(4*atan(1));}
    Kugla &PostaviX(double x){
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY(double y){
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ(double z){
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z){
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }
   Kugla &PostaviCentar(const std::tuple<double,double,double> &centar){
        x=std::get<0> (centar);
        y=std::get<1> (centar);
        z=std::get<2> (centar);
        return *this;    
    }
    Kugla &PostaviPoluprecnik(double r){
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const{
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
    }
    void Transliraj(double delta_x,double delta_y,double delta_z){
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
        if(abs(k1.x-k2.x)<epsilon*(abs(k1.x)+abs(k2.x)) && 
        abs(k1.y-k2.y)<epsilon*(abs(k1.y)+abs(k2.y)) &&
        abs(k1.z-k2.z)<epsilon*(abs(k1.z)+abs(k2.z)) &&
        abs(k1.r-k2.r)<epsilon*(abs(k1.r)+abs(k2.r))) return true;
        else return false;
    }
    
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
        if(abs(k1.r-k2.r)<epsilon*(abs(k1.r)+abs(k2.r))) return true;
        return false;
    }
    
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
        if(abs(k1.x-k2.x)<epsilon*(abs(k1.x)+abs(k2.x)) &&
        abs(k1.y-k2.y)<epsilon*(abs(k1.y)+abs(k2.y)) &&
        abs(k1.z-k2.z)<epsilon*(abs(k1.z)+abs(k2.z))) return true;
        else return false;
    }
    
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
        double d=sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z));
        if(abs(d-(k2.r+k1.r))<epsilon*(abs(d)+abs(k1.r+k2.r))) return true;
        else return false;
    }
    
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
        double d=sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z));
        if(abs(d-(k2.r+k1.r))<epsilon*(abs(d)+abs(k1.r+k2.r))) return true;
        else return false;
    }
    
    double Udaljenost(double x1,double x2,double y1,double y2, double z1,double z2){
        return sqrt ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
    }
   /*
   friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
       if (Udaljenost(k1.DajX(),k2.DajX(),k1.DajY(),k2.DajY(),k1.DajZ(),k2.DajZ())<k1.DajPoluprecnik()+k2.DajPoluprecnik()) return true;
       else return k1.DaLiSadrzi(k2);
   }
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
        if (Udaljenost(k1.DajX(),k2.DajX(),k1.DajY(),k2.DajY(),k1.DajZ(),k2.DajZ())<k1.DajPoluprecnik()+k2.DajPoluprecnik() &&
        Udaljenost(k1.DajX(),k2.DajX(),k1.DajY(),k2.DajY(),k1.DajZ(),k2.DajZ())>fabs (k1.DajPoluprecnik()+k2.DajPoluprecnik()));
    }

    bool DaLiSadrzi(const Kugla k) const{
        return Udaljenost(DajX(),k.DajX(),DajY(),k.DajY(),DajZ(),k.DajZ())<=fabs(DajPoluprecnik()-k.DajPoluprecnik());
    }
    */
};



int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    do{
        std::cin>>n;
        if(!std::cin || n<1){
             std::cout<<" ";
             std::cin.clear();
             std::cin.ignore(1000,'\n');
        }
    }while(!std::cin || n<1);    
    std::vector<std::shared_ptr<Kugla>> vektor;
    double x,y,z,r;
    
    for(int i=0;i<=n;i++){
        try{
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
             std::cin>>x>>y>>z;
            if(!std::cin) throw std::domain_error("Neispravan centar");
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
             std::cin>>r;
            if(!std::cin) throw std::domain_error("Ilegalan poluprecnik");
            vektor.push_back(std::make_shared<Kugla> (x,y,z,r));
        
        }
        catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what()<<std::endl;
             std::cin.clear();
             std::cin.ignore(1000,'\n');
             i--;
        }
    }
    double delta_x,delta_y,delta_z;
    std::cout<<"Unesite elemente translacije (delta_x,delta_y,delta_z): ";
    do{
        std::cin>>delta_x>>delta_y>>delta_z;
        if(!std::cin){
            std::cout<<" ";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }else break;
    } while(!std::cin);
    std::transform(vektor.begin(),vektor.end(),vektor.begin(),[delta_x,delta_y,delta_z](std::shared_ptr<Kugla> pokazivac){
        pokazivac->Transliraj(delta_x,delta_y,delta_z);
        return pokazivac;
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednost:\n";
	std::sort(vektor.begin(), vektor.end(), [](std::shared_ptr<Kugla> p1,std::shared_ptr<Kugla> p2){
	    if(p1->DajZapreminu()<p2->DajZapreminu()) return true;
	    return false;
	});
	std::for_each(vektor.begin(),vektor.end(), [](std::shared_ptr<Kugla> pokazivac){
	    pokazivac->Ispisi(); std::cout<<"\n";
	});
	std::cout<<"Kugla sa najvecom povrsinom je: ";
	(**std::max_element(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla>p1,std::shared_ptr<Kugla> p2){
	    if(p1->DajPovrsinu()<p2->DajPovrsinu()) return true;
	    return false;
	})).Ispisi();
	
	
	return 0;
}
 