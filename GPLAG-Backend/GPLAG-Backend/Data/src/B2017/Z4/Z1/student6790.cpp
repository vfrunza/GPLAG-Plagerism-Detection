/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

#define PI 3.14159265359
#define epsilon 0.0000000001

bool postoji(false);

class Kugla {
    double x,y,z,r;
    void IspravnostPoluprecnika(double r) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
    }
    
    public:
    explicit Kugla(double r=0) {
        x=0; y=0; z=0; 
        IspravnostPoluprecnika(r);
        Kugla::r=r;
    }
    Kugla(double x,double y,double z,double r=0) {
        Kugla::x=x; Kugla::y=y; Kugla::z=z; 
        IspravnostPoluprecnika(r); Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double,double,double> &centar,double r=0){
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
        IspravnostPoluprecnika(r); Kugla::r=r;
    }
    
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double,double,double> DajCentar() const {
        std::tuple<double,double,double> centar{x,y,z};
        return centar;
    }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*PI*r*r; }
    double DajZapreminu() const { return (4*r*r*r*PI)/3; }
    
    Kugla &PostaviX(double x) { Kugla::x=x; return (*this); }
    Kugla &PostaviY(double y) { Kugla::y=y; return (*this); }
    Kugla &PostaviZ(double z) { Kugla::z=z; return (*this); }
    Kugla &PostaviCentar(double x,double y,double z) { 
        Kugla::x=x; Kugla::y=y; Kugla::z=z; 
        return (*this);
    }
    Kugla &PostaviCentar(const std::tuple<double,double,double> &centar) {
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
        return (*this);
    }
    Kugla &PostaviPoluprecnik(double r) {
        IspravnostPoluprecnika(r); Kugla::r=r;
        return (*this);
    }
    void Ispisi() const{
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
    }
    void Translatiraj(double delta_x,double delta_y,double delta_z){
        x+=delta_x; y+=delta_y; z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2);
    
    //pregledati jos funkciju
    bool DaLiSadrzi(const Kugla &k) const {
        if(x>Kugla::x || y>Kugla::y || z>Kugla::z || 2*r>Kugla::r) 
            return false;
        return true;
    }
    friend double RastojanjeCentara(const Kugla &k1,const Kugla &k2);
    friend double Udaljenost(const Kugla &k1,const Kugla &k2);
};

bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2) {
    if(abs(k1.x-k2.x)>(epsilon*(abs(k1.x)+abs(k2.x))) || 
        abs(k1.y-k2.y)>(epsilon*(abs(k1.y)+abs(k2.y)))|| 
        abs(k1.z-k2.z)>(epsilon*(abs(k1.z)+abs(k2.z)))|| 
        abs(k1.r-k2.r)>(epsilon*(abs(k1.r)+abs(k2.r))) )
            return false;
    return true;
}

double Udaljenost(const Kugla &k1,const Kugla &k2) {
    return (std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)));
}

bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2) {
    if(std::abs(k1.r-k2.r)>(epsilon*(std::abs(k1.r)+std::abs(k2.r)))) 
        return false;
    return true;
}

bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2){
    if(std::abs(k1.x-k2.x)>(epsilon*(std::abs(k1.x)+std::abs(k2.x))) || 
        std::abs(k1.y-k2.y)>(epsilon*(std::abs(k1.y)+std::abs(k2.y)))|| 
        std::abs(k1.z-k2.z)>(epsilon*(std::abs(k1.z)+std::abs(k2.z))))
        return false;
    return true;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2) {
    double d(Udaljenost(k1,k2));
    if (std::abs((k1.r+k2.r)-d)<epsilon*(std::abs(k1.r)+std::abs(k2.r))) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2) {
    double d(Udaljenost(k1,k2));
    return (std::abs((k1.r-k2.r)-d)<epsilon*(std::abs(k1.r)-std::abs(k2.r)));
}


bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2) {
    double d(Udaljenost(k1,k2));
    return (std::abs(k1.r-k2.r)<d);
}


bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2){
    double d(Udaljenost(k1,k2));
    return ((std::abs(k1.r-k2.r)<d)&& std::abs(k1.r+k2.r)>d);
}

double RastojanjeCentara(const Kugla &k1,const Kugla &k2) {
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}



int main (){
    
    int n;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    while(!std::cin || n<1) {
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin>>n;
    }
    
    std::vector<std::shared_ptr<Kugla>> v;
    
    try {
        for(int i(0);i<n;i++) {
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            double x,y,z;
            //std::cin>>x>>y>>z;
            if(!(std::cin>>x>>y>>z)) {
                std::cout<<"Neispravan centar"<<std::endl;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                i--;
                continue;
            }
            
            
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            double r;
            if(!(std::cin>>r) || r<0) {
                std::cout<<"Ilegalan poluprecnik"<<std::endl;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                i--;
                continue;
            }
            try{
                v.push_back(std::make_shared<Kugla>(x,y,z,r));
            }
            catch (std::domain_error izuzetak) {
                std::cout<<izuzetak.what()<<std::endl;;
                i--;
            }
            catch(std::bad_alloc) {
                throw;
            }
        }
    }
    catch(std::bad_alloc) {
        std::cout<<"Problemi s memorijom!";
    }
    
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx,dy,dz;
    while(!(std::cin>>dx>>dy>>dz)|| dx<0 || dy<0 || dz<0) {
                std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
            }
    
    
    std::transform(v.begin(),v.end(),v.begin(),[dx,dy,dz](std::shared_ptr<Kugla> k) { 
        (*k).Translatiraj(dx,dy,dz);
        return k;
    } );
    
    std::sort(v.begin(),v.end(),[](std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2){
        return (*k1).DajZapreminu()<(*k2).DajZapreminu();
    } );
    
    
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Kugla> k) { 
        (*k).Ispisi(); 
        std::cout<<std::endl;
    });
    
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto max_el(std::max_element(v.begin(),v.end(),[](std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2){
        return (*k1).DajPovrsinu()<(*k2).DajPovrsinu();
    }));
    
    (*(*max_el)).Ispisi();
    
    auto pocetak(v.begin());
    auto kraj(v.end());

    std::for_each(pocetak,kraj-1,[pocetak,kraj](std::shared_ptr<Kugla> k1){
        std::for_each(pocetak+1,kraj,[k1,pocetak](std::shared_ptr<Kugla> k2) {;
            if(DaLiSeSijeku(*k1,*k2)) {
                std::cout<<std::endl<<"Presjecaju se kugle: "; (*k1).Ispisi();
                std::cout<<std::endl; (*k2).Ispisi();
                postoji=true;
            }
        });
    });
    
    if(!postoji) std::cout<<std::endl<<"Ne postoje kugle koje se presjecaju!";
    
	return 0;
}
