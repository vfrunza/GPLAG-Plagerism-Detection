/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <tuple>
#include <algorithm>
#define eps 0.0000000001


class NepreklapajucaKugla{
    double X,Y,Z,R;
  bool IsprPolup(double a){
    if(a<0)return false;
    else return true;
}
  
    public:
    explicit NepreklapajucaKugla(double r=0){                                                         
        if(IsprPolup(r)){
            R=r;
            X=0;
            Y=0;
            Z=0;
        }
        else throw std::domain_error("Ilegalan poluprecnik");
    };
    NepreklapajucaKugla(double x, double y, double z, double r){                                      
        if(IsprPolup(r)){
            R=r;
            X=x;
            Y=y;
            Z=z;
        }
        else throw std::domain_error("Ilegalan poluprecnik");
    };
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r){             
        if(IsprPolup(r)){
            R=r;
            X=std::get<0>(centar);
            Y=std::get<1>(centar);
            Z=std::get<2>(centar);
        }
        else throw std::domain_error("Ilegalan poluprecnik");
    };
    double DajX() const{return X;};                                                         
    double DajY() const{return Y;};                                                         
    double DajZ() const{return Z;};                                                         
    std::tuple<double, double, double> DajCentar() const{                                   
        std::tuple<double,double,double> a;
        a=std::make_tuple(X,Y,Z);
        return a;
    };
    double DajPoluprecnik() const {return 2*R*4*atan(1);};                                  
    double DajPovrsinu() const {return R*R*4*atan(1);};                                     
    double DajZapreminu() const {return (4/3)*R*R*R*4*atan(1);};                            
    
    NepreklapajucaKugla &PostaviX(double x){X=x;return *this;};                                           
    NepreklapajucaKugla &PostaviY(double y){Y=y;return *this;};                                           
    NepreklapajucaKugla &PostaviZ(double z){Z=z;return *this;};                                           
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z){                                     
        X=x;Y=y;Z=z;return *this;
    };
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar){                 
        X=std::get<0>(centar);Y=std::get<1>(centar);Z=std::get<2>(centar);return *this;
    };
    NepreklapajucaKugla &PostaviPoluprecnik(double r){                                                    
        if(IsprPolup(r)){   
            R=r;
            return *this;
        }
        else throw std::domain_error("Ilegalan poluprecnik");
    };
    void Ispisi() const{                                                                    
        std::cout<<"{("<<X<<","<<Y<<","<<Z<<"),"<<R<<"}"<<std::endl;
    };
    void Transliraj(double delta_x, double delta_y, double delta_z){                        
        X+=delta_x;Y+=delta_y;Z+=delta_z;
    };
    
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){                      
        double rast;
        rast=sqrt(pow(k1.X-k2.X,2)+pow(k1.Y-k2.Y,2)+pow(k1.Z-k2.Z,2));
        return rast;
    };
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const{                                                  //
        if(R+k.R>sqrt(pow(k.X-X,2)+pow(k.Y-Y,2)+pow(k.Z-Z,2))) return true;
        else return false;
    };
};
int main ()
{
	return 0;
}
