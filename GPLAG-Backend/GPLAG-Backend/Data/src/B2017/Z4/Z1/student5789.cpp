/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <utility>
#define PI 3.14159265
#define EPISLON 0.0000000001
class Kugla{
  double x,y,z,r;
public:
    explicit Kugla(double r=0){
        x=0;
        y=0;
        z=0;
        Kugla::r=r;
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    }
    Kugla(double x,double y, double z,double r=0){
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    }
    explicit Kugla(const std::tuple<double,double,double> &centar,double r=0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        Kugla::r=r;
    }
    double DajX() const{ return x;}
    double DajY() const{ return y;}
    double DajZ() const{ return z;}
    std::tuple<double,double,double> DajCentar() const{ return std::make_tuple(x,y,z);}
    double DajPoluprecnik() const{ return r;}
    double DajPovrsinu() const{ return PI*r*r;}
    double DajZapreminu() const{ return (4./3.)*r*r*r*PI;}
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
    Kugla &PostaviCentar(double x,double y, double z){
        Kugla::x=x;
        Kugla::z=z;
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double,double,double> &centar){
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const{
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
    }
    void Transliraj(double delta_x,double delta_y,double delta_z){
        x=x+delta_x;
        y=y+delta_y;
        z=z+delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiuKoncentricne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const{
        double rez;
        rez=std::sqrt((k.x-x)*(k.x-x)+(k.y-y)*(k.y-y)+(k.z-z)*(k.z-z));
        if(rez<r/2) return true;
        return false;
    }
    friend double RastojanjeCentara(const Kugla &k1,const Kugla &k2);
};

bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2){
    if(std::fabs(k1.x-k2.x)<EPISLON&&std::fabs(k1.y-k2.y)<EPISLON&&std::fabs(k1.z-k2.z)<EPISLON&&std::fabs(k1.r-k2.r)<EPISLON) return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2){
    if(std::fabs(k1.r-k2.r)<EPISLON) return true;
    return false;
}
bool DaLiuKoncentricne(const Kugla &k1,const Kugla &k2){
    if(std::fabs(k1.x-k2.x)<EPISLON&&std::fabs(k1.y-k2.y)<EPISLON&&std::fabs(k1.z-k2.z)<EPISLON) return true;
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2){
    double rez;
    rez=std::sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z));
    if(rez-std::fabs(k1.r+k2.r)<EPISLON) return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2){
    double rez;
    rez=std::sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z));
    if(std::fabs(rez-(std::fabs(k1.r-k2.r)))<EPISLON) return true;
    return false;
}
bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2){
    double rez;
    rez=std::sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z));
    if(rez<(k1.r+k2.r)) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2){
    double rez;
    rez=std::sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z));
    if(rez<(k1.r+k2.r)&&rez>(std::fabs(k1.r-k2.r))) return true;
    return false;
}
double RastojanjeCentara(const Kugla &k1,const Kugla &k2){
    double rez;
    rez=std::sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z));
    return rez;
}
int main ()
{
    std::cout<<"Unesite broj kugla: ";
    int n;
         std::cin>>n;
  
    std::vector<std::shared_ptr<Kugla>> v;
    double x,y,z,r;
    for(int i(0);i<n;i++){
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x;
        std::cin>>y;
        std::cin>>z;
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        try{
        std::cin>>r;
        if(r<0) {
            i--;
            throw std::domain_error("Ilegalan poluprecnik");
        }
        auto p(std::make_shared<Kugla>(x,y,z,r));
        v.push_back(p);
        }
        catch(std::domain_error e){
            
            std::cout<<e.what()<<std::endl;
        }
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x,delta_y,delta_z;
    std::cin>>delta_x;
    std::cin>>delta_y;
    std::cin>>delta_z;
    std::vector<std::shared_ptr<Kugla>> v_novi(n);
    std::transform(v.begin(),v.end(),v_novi.begin(),[delta_x,delta_y,delta_z](std::shared_ptr<Kugla> k ){ (*k).Transliraj(delta_x,delta_y,delta_z); return k;});
    std::sort(v_novi.begin(),v_novi.end(),[](std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2){ return (*k1).DajZapreminu()<(*k2).DajZapreminu();});
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(v_novi.begin(),v_novi.end(),[](std::shared_ptr<Kugla> k){ (*k).Ispisi();});
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto pom=std::max_element(v_novi.begin(),v_novi.end(),[](std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2){return (*k1).DajPovrsinu()<(*k2).DajPovrsinu();});
    (**pom).Ispisi();
    std::vector<std::pair<std::shared_ptr<Kugla>,std::shared_ptr<Kugla>>> par;
    std::for_each(v_novi.begin(),v_novi.end(),[v_novi,&par](std::shared_ptr<Kugla> k){ 
                    for_each(v_novi.begin(),v_novi.end(),[k,&par](std::shared_ptr<Kugla> k2){
                            int br(0),pom_br(0);
                            while(1){
                                if(br==par.size()) break;
                                auto a=par.at(br).first;
                                auto b=par.at(br).second;
                                if((a==k||a==k2)&&(b==k||b==k2)) pom_br++;
                                br++;
                            } 
                            if(pom_br==0){
                            if(DaLiSeSijeku(*k,*k2)) {
                                par.push_back(std::make_pair(k,k2));
                                std::cout<<"Presjecaju se kugle: ";
                                (*k).Ispisi();
                                (*k2).Ispisi();
                            }
                            }
                    });});
    if(par.size()==0) std::cout<<"Ne postoje kugle koje se presjecaju!";
	return 0;
}

