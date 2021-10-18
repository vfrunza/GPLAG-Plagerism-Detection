/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <tuple>
#include <algorithm>
#include <memory>
#include <vector>
#define eps 0.0000000001

class Kugla{
  double X,Y,Z,R;
  bool IsprPolup(double a){
    if(a<0)return false;
    else return true;
}
  
public:
    explicit Kugla(double r=0){                                                             //
        if(IsprPolup(r)){
            R=r;
            X=0;
            Y=0;
            Z=0;
        }
        else throw std::domain_error("Ilegalan poluprecnik");
    };
    Kugla(double x, double y, double z, double r){                                          //    
        if(IsprPolup(r)){
            R=r;
            X=x;
            Y=y;
            Z=z;
        }
        else throw std::domain_error("Ilegalan poluprecnik");
    };
    explicit Kugla(const std::tuple<double, double, double> &centar, double r){             //
        if(IsprPolup(r)){
            R=r;
            X=std::get<0>(centar);
            Y=std::get<1>(centar);
            Z=std::get<2>(centar);
        }
        else throw std::domain_error("Ilegalan poluprecnik");
    };
    double DajX() const{return X;};                                                         //
    double DajY() const{return Y;};                                                         //
    double DajZ() const{return Z;};                                                         //
    std::tuple<double, double, double> DajCentar() const{                                   //
        std::tuple<double,double,double> a;
        a=std::make_tuple(X,Y,Z);
        return a;
    };
    double DajPoluprecnik() const {return 2*R*4*atan(1);};                                  //
    double DajPovrsinu() const {return R*R*4*atan(1);};                                     //
    double DajZapreminu() const {return (4/3)*R*R*R*4*atan(1);};                            //
    
    Kugla &PostaviX(double x){X=x;return *this;};                                           //
    Kugla &PostaviY(double y){Y=y;return *this;};                                           //
    Kugla &PostaviZ(double z){Z=z;return *this;};                                           //
    Kugla &PostaviCentar(double x, double y, double z){                                     //
        X=x;Y=y;Z=z;return *this;
    };
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){                 //
        X=std::get<0>(centar);Y=std::get<1>(centar);Z=std::get<2>(centar);return *this;
    };
    Kugla &PostaviPoluprecnik(double r){                                                    //
        if(IsprPolup(r)){   
            R=r;
            return *this;
        }
        else throw std::domain_error("Ilegalan poluprecnik");
    };
    void Ispisi() const{                                                                    //
        std::cout<<"{("<<X<<","<<Y<<","<<Z<<"),"<<R<<"}"<<std::endl;
    };
    void Transliraj(double delta_x, double delta_y, double delta_z){                        //
        X+=delta_x;
        Y+=delta_y;
        Z+=delta_z;
    };
    
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){                          //
        if((abs(k1.X-k2.X)<eps*(abs(k1.X)+abs(k2.X))) and (abs(k1.Y-k2.Y)<eps*(abs(k1.Y)+abs(k2.Y))) and (abs(k1.Z-k2.Z)<eps*(abs(k1.Z)+abs(k2.Z))) and (abs(k1.R-k2.R)<eps*(abs(k1.R)+abs(k2.R)))) return true;
        else return false;
    };
    
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){                          //
        if((abs(k1.R-k2.R)<eps*(abs(k1.R)+abs(k2.R))))return true;
        else return false;
    };
    
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){                       //
        if((abs(k1.X-k2.X)<eps*(abs(k1.X)+abs(k2.X))) and (abs(k1.Y-k2.Y)<eps*(abs(k1.Y)+abs(k2.Y))) and (abs(k1.Z-k2.Z)<eps*(abs(k1.Z)+abs(k2.Z))))return true;
        else return false;
    };
    
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){                     //
        double a=RastojanjeCentara(k1,k2);
        double b=k1.R+k2.R;
        if((abs(a-b))<eps*(abs(a)+abs(b)))return true;
        else return false;
    };
    
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){                    //
        double a=RastojanjeCentara(k1,k2);
        double b=k1.R-k2.R;
        if((abs(a-b))<eps*(abs(a)+abs(b))) return true;
        else return false;
    };
    
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){                         //
        double a=RastojanjeCentara(k1,k2);
        double b=k1.R+k2.R;
        if(a<b)return true;
        else return false;
    };
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){                             //
        double a=RastojanjeCentara(k1,k2);
        
        if(a<k1.R+k2.R and sqrt(pow(k1.R-k2.R,2))<a)return true;
        else return false;
    };
    bool DaLiSadrzi(const Kugla &k) const{                                                  //
        if(R+k.R>sqrt(pow(k.X-X,2)+pow(k.Y-Y,2)+pow(k.Z-Z,2))) return true;
        else return false;
    };
    
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2){                      //
        double rast;
        rast=sqrt(pow(k1.X-k2.X,2)+pow(k1.Y-k2.Y,2)+pow(k1.Z-k2.Z,2));
        return rast;
    };
};


int main ()
{
    try{
        int n;
        std::cout<<"Unesite broj kugla: ";
        
        while(true){
            std::cin>>n;
            if(std::cin && n>0) break;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        }
        std::vector<std::shared_ptr<Kugla>> pok(n);
        for(int i=0;i<n;i++){
            double x,y,z,r;
            
            while(true){
                std::cout<<"Unesite centar "<<i+1<<". kugle: ";
                std::cin>>x>>y>>z;
                if(!std::cin){
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cout<<"Neispravan centar"<<std::endl;
                }
                else{
                std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
                std::cin>>r;
                if(std::cin && r>=0){
                    break;
                }
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cout<<"Ilegalan poluprecnik "<<std::endl;
                }
            }
           Kugla tmp;
           tmp.PostaviCentar(x,y,z);
           tmp.PostaviPoluprecnik(r);
           pok[i]=std::make_shared<Kugla>(tmp);
        }
        
        double transx,transy,transz;
        std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        while(true){
            
            std::cin>>transx>>transy>>transz;
            if(std::cin)break;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        }
        
        std::transform(pok.begin(),pok.end(),pok.begin(),[transx,transy,transz] (std::shared_ptr<Kugla> p) {p->Kugla::Transliraj(transx,transy,transz);return p;});
        std::sort(pok.begin(),pok.end(),[](std::shared_ptr<Kugla> p1,std::shared_ptr<Kugla> p2){return p1->Kugla::DajZapreminu()<p2->Kugla::DajZapreminu();} ); 
        std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: ";
        std::cout<<std::endl;
        std::for_each(pok.begin(),pok.end(),[] (std::shared_ptr<Kugla> p)->void{p->Kugla::Ispisi();}) ;
        
        auto najveci=std::max_element(pok.begin(),pok.end(),[](std::shared_ptr<Kugla> p1,std::shared_ptr<Kugla> p2){return p1->Kugla::DajPovrsinu()<p2->Kugla::DajPovrsinu();});
        std::cout<<"Kugla sa najvecom povrsinom je: ";
        (*najveci)->Kugla::Ispisi();
        
        
        bool ima=false;
        auto it=pok.begin();
        std::for_each(pok.begin(),pok.end(),[&ima,&pok,&it](std::shared_ptr<Kugla> prva){
           std::for_each(it,pok.end(),[prva,&ima,&pok](std::shared_ptr<Kugla> druga){                             
               if(DaLiSeSijeku(*prva,*druga)&& !DaLiSuIdenticne(*prva,*druga)){
                   std::cout<<"Presjecaju se kugle: ";
                   prva->Kugla::Ispisi();
                   druga->Kugla::Ispisi();
                   ima=true;
                   
               }
               
              
           });
           it++;
        });
        if(ima==false){
            std::cout<<"Ne postoje kugle koje se presjecaju!"<<std::endl;
        }
        
        
    }
    catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
	return 0;
}
