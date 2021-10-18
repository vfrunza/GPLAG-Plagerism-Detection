/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <new>
#include <vector>
#include <memory>

const double eps=std::pow(10,-10);
    bool Jednaki(double a, double b){
        return (std::abs(a-b)<eps*(std::abs(b)+std::abs(a)));
    }
    bool Veci(double a,double b){
        return a-b > eps * (std::abs(b)+std::abs(a));
    }


class Kugla{
    double x, y, z,r;

    public:
    explicit Kugla(double r=0);
    Kugla (double x,double y, double z, double r=0);
    explicit Kugla(const std::tuple<double,double,double> &centar,double r=0);
    double DajX () const;
    double DajY () const;
    double DajZ () const;
    std::tuple<double,double,double> DajCentar()const;
    double DajPoluprecnik () const;
    double DajPovrsinu () const;
    double DajZapreminu () const;
    Kugla &PostaviX(double x);
    Kugla &PostaviY(double y);
    Kugla &PostaviZ(double z);
    Kugla &PostaviCentar (double x, double y, double z);
    Kugla &PostaviCentar(std::tuple<double,double,double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Translatiraj (double delta_x, double delta_y, double delta_z);
    friend bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1,const Kugla &k2);
};
 Kugla::Kugla(double r){
    if(r<0)
        throw std::domain_error("Ilegalan poluprecnik");
    this->r=r;
}
Kugla::Kugla(double x,double y, double z, double r){
     if(r<0)
        throw std::domain_error("Ilegalan poluprecnik");
     this->r=r;
     this->x=x;
     this->z=z;
     this->y=y;
}
Kugla::Kugla(const std::tuple<double,double,double> &centar,double r){
    if(r<0)
        throw std::domain_error("Ilegalan poluprecnik");
     this->r=r;
     this->x=std::get<0>(centar);
     this->z=std::get<1>(centar);
     this->y=std::get<2>(centar);
}
double Kugla::DajX () const{
    return x;
}

double Kugla::DajY () const{
    return y;
}

double Kugla::DajZ () const{
    return z;
}

std::tuple<double,double,double> Kugla::DajCentar()const{
    return std::make_tuple(x,y,z);
}

double Kugla::DajPoluprecnik () const{
    return r;
}
    
double Kugla::DajPovrsinu () const{
    return 4*r*r*4*std::atan(1);
}
double Kugla::DajZapreminu () const{
    return (4.)*r*r*r*4*std::atan(1)/3;
}

Kugla& Kugla::PostaviX(double x){
    this->x=x;
    return *this;
    }
    
Kugla& Kugla::PostaviY(double y){
    this->y=y;
    return *this;
}

Kugla& Kugla::PostaviZ(double z){
    this->z=z;
    return *this;
}
Kugla & Kugla::PostaviCentar (double x, double y, double z){
    this->x=x;
    this->y=y;
    this->z=z;
    return *this;
}

Kugla & Kugla::PostaviCentar(std::tuple<double,double,double> &centar){
    this->x=std::get<0>(centar);
     this->y=std::get<1>(centar);
     this->z=std::get<2>(centar);
     return *this;
}

Kugla & Kugla::PostaviPoluprecnik(double r){
    this->r=r;
    return *this;
}

void Kugla::Ispisi() const{
    std::cout << "{("<<x<<","<<y<<","<<z<<"),"<<r<<"}" <<std::endl;
}

void Kugla::Translatiraj (double delta_x, double delta_y, double delta_z){
    x+=delta_x; y+=delta_y; z+=delta_z;
}    

 bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2){
     return Jednaki(k1.r,k2.r);
 }
 
 bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2){
     return (Jednaki(k1.x,k2.x) && Jednaki(k1.y,k2.y) && Jednaki(k1.z,k2.z));
 }
 
  bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2){
     return (DaLiSuKoncentricne(k1,k2)&&DaLiSuPodudarne(k1,k2));
 }
 
 double RastojanjeCentara(const Kugla &k1,const Kugla &k2){
     return std::sqrt((k1.x -k2.x) * (k1.x -k2.x) + (k1.y - k2.y) * (k1.y - k2.y) + (k1.z - k2.z) * (k1.z - k2.z));
 }
 
 bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2){
    return Jednaki(RastojanjeCentara(k1,k2),k1.r+k2.r);
 }
 
bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2){
    if(Jednaki(k1.r,k2.r)) return false;
    return Jednaki(k1.r,RastojanjeCentara(k1,k2)+k2.r) or Jednaki(k2.r,RastojanjeCentara(k1,k2)+k1.r);
 }
 bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2 ){
     return Veci(k1.r+k2.r,RastojanjeCentara(k1,k2));
 }
 
 bool Kugla::DaLiSadrzi(const Kugla &k) const{
        return Veci(k.r,RastojanjeCentara(*this,k)+this->r) or Jednaki(k.r,RastojanjeCentara(*this,k)+this->r);
 }
 
bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2 ){
    return (!(k1.DaLiSadrzi(k2)) && !(k2.DaLiSadrzi(k1)) && !DaLiSeDodirujuIznutra(k1,k2) && DaLiSePreklapaju(k1,k2));
}
 
int main ()
{
    int n;
        std::cout << "Unesite broj kugla: ";
        while (1) {
            std::cin>>n;
        if(std::cin){
            
            if(n<=0){
                std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
            }else break;
        }
        else{
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        }
        }
    
    std::vector<std::shared_ptr<Kugla>> Kuglee(n,nullptr);
    try{
        for (int i = 0; i < n; i++) {
            double x,y,z,r;
            
            while (1){
                std::cout << "Unesite centar " << i+1<<". kugle: ";
                std::cin >> x>>y>>z;
                if(std::cin )
                    break;
                std::cout << "Neispravan centar" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
            
            }
            std::cout << "Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin >> r;
                if(std::cin){
                    if(r<0)
                        {
                        std::cout << "Ilegalan poluprecnik"<<std::endl;
                        std::cin.ignore(1000,'\n');
                        i--;
                        continue;
                    }
                }else{
                    std::cout << "Ilegalan poluprecnik"<<std::endl ;
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    i--;
                    continue;
                }
            Kuglee.at(i)=std::make_shared<Kugla>(x,y,z,r);
        }
    double dx,dy,dz;
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): " ;
    while (1) {
        
    std::cin >> dx>>dy>>dz;
    if(std::cin )
        break;
    std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
    
}
    
    std::transform(Kuglee.begin(),Kuglee.end(),Kuglee.begin(),[dx,dy,dz](std::shared_ptr<Kugla> k)->std::shared_ptr<Kugla>{
     k->Translatiraj(dx,dy,dz);
     return k;
    });
    
    std::sort(Kuglee.begin(),Kuglee.end(),[](std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2){
        return (!Veci(k1->DajZapreminu(),k2->DajZapreminu())&& !Jednaki(k1->DajZapreminu(),k2->DajZapreminu()));
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(Kuglee.begin(),Kuglee.end(),[](std::shared_ptr<Kugla> k){
     k->Ispisi();
    });
    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*(std::max_element(Kuglee.begin(),Kuglee.end(),[](std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2){
        return(!Veci(k1->DajPovrsinu(),k2->DajPovrsinu())&& !Jednaki(k1->DajPovrsinu(),k2->DajPovrsinu()));
    })))->Ispisi();
    std::cout<<std::endl;
    int brojac1(0),brojac2(0);
    std::for_each(Kuglee.begin(),Kuglee.end(),[&brojac1,&brojac2,Kuglee](std::shared_ptr<Kugla> k1)->void{
        brojac2++;
        std::for_each(Kuglee.begin()+brojac2,Kuglee.end(),[k1,&brojac1](std::shared_ptr<Kugla> k2)->void{
            if(DaLiSeSijeku(*k1,*k2)){
                std::cout << "Presjecaju se kugle: " ;
                k1->Ispisi();
                std::cout  << std::endl;
                k2->Ispisi();
                brojac1++;
                std::cout<<std::endl;
            }
        });
    });
        if(!brojac1)
            std::cout << "Ne postoje kugle koje se presjecaju!" ;
   
    }
    catch(...){
        std::cout << "Problemi sa memorijom!" << std::endl;
    }
    
	return 0;
}















/*
/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>


class Kugla{
    double x, y, z, r;
    public:
    explicit Kugla(double r=0);
    Kugla (double x,double y, double z, double r=0);
    explicit Kugla(const std::tuple<double,double,double> &centar,double r=0);
    double DajX () const;
    double DajY () const;
    double DajZ () const;
    std::tuple<double,double,double> DajCentar()const;
    double DajPoluprecnik () const;
    double DajPovrsinu () const;
    double DajZapreminu () const;
    Kugla &PostaviX(double x);
    Kugla &PostaviY(double y);
    Kugla &PostaviZ(double z);
    Kugla &PostaviCentar (double x, double y, double z);
    Kugla &PostaviCentar(std::tuple<double,double,double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Translatiraj (double delta_x, double delta_y, double delta_z);
    friend bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k);
    friend double RastojanjeCentara(const Kugla &k1,const Kugla &k2);
};
 Kugla::Kugla(double r){
    if(r<0)
        throw std::domain_error("Ilegalan poluprecnik");
    this->r=r;
}
Kugla::Kugla(double x,double y, double z, double r){
     if(r<0)
        throw std::domain_error("Ilegalan poluprecnik");
     this->r=r;
     this->x=x;
     this->z=z;
     this->y=y;
}
Kugla(const std::tuple<double,double,double> &centar,double r){
    if(r<0)
        throw std::domain_error("Ilegalan poluprecnik");
     this->r=r;
     this->x=std::get(centar)<0>;
     this->z=std::get(centar)<1>;
     this->y=std::get(centar)<2>;
}



    

int main ()
{
	return 0;
}
/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>


class Kugla{
    double x, y, z, r;
    public:
    explicit Kugla(double r=0);
    Kugla (double x,double y, double z, double r=0);
    explicit Kugla(const std::tuple<double,double,double> &centar,double r=0);
    double DajX () const;
    double DajY () const;
    double DajZ () const;
    std::tuple<double,double,double> DajCentar()const;
    double DajPoluprecnik () const;
    double DajPovrsinu () const;
    double DajZapreminu () const;
    Kugla &PostaviX(double x);
    Kugla &PostaviY(double y);
    Kugla &PostaviZ(double z);
    Kugla &PostaviCentar (double x, double y, double z);
    Kugla &PostaviCentar(std::tuple<double,double,double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Translatiraj (double delta_x, double delta_y, double delta_z);
    friend bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k);
    friend double RastojanjeCentara(const Kugla &k1,const Kugla &k2);
};
 Kugla::Kugla(double r){
    if(r<0)
        throw std::domain_error("Ilegalan poluprecnik");
    this->r=r;
}
Kugla::Kugla(double x,double y, double z, double r){
     if(r<0)
        throw std::domain_error("Ilegalan poluprecnik");
     this->r=r;
     this->x=x;
     this->z=z;
     this->y=y;
}
Kugla(const std::tuple<double,double,double> &centar,double r){
    if(r<0)
        throw std::domain_error("Ilegalan poluprecnik");
     this->r=r;
     this->x=std::get(centar)<0>;
     this->z=std::get(centar)<1>;
     this->y=std::get(centar)<2>;
}



    

int main ()
{
	return 0;
}
*/