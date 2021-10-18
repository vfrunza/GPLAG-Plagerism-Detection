/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>
const double Pi = 4*atan(1);
const double eps = pow(10,-10);
class Kugla{
    double x,y,z,r;
    public:
    explicit Kugla(double r=0):r(r){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    };
    Kugla(double x, double y, double z, double r=0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r;
    }
    explicit Kugla (const std::tuple<double,double,double> &centar, double r=0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        Kugla::r=r;
    }
    double DajX() const {return x;}
    double DajY() const {return y;}
    double DajZ() const {return z;}
    std::tuple<double,double,double> DajCentar() const {return std::make_tuple(x,y,z);}
    double DajPoluprecnik() const {return r;}
    double DajPovrsinu() const {return 4*Pi*r*r;}
    double DajZapreminu() const {return (4./3)*r*r*r*Pi;}
    Kugla &PostaviX (double x) {Kugla::x=x; return *this;}
    Kugla &PostaviY (double y) {Kugla::y=y; return *this;}
    Kugla &PostaviZ (double z) {Kugla::z=z; return *this;}
    Kugla &PostaviCentar(double x, double y, double z){
        Kugla::x=x; Kugla::y=y; Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double,double,double> &centar){
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const{
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        Kugla::x+=delta_x;
        Kugla::y+=delta_y;
        Kugla::z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2){
        int br(0);
        if(fabs(k1.x-k2.x)<eps*(fabs(k1.x)+fabs(k2.x))) br++;
        if(fabs(k1.y-k2.y)<eps*(fabs(k1.y)+fabs(k2.y))) br++;
        if(fabs(k1.z-k2.z)<eps*(fabs(k1.z)+fabs(k2.z))) br++;
        if(fabs(k1.r-k2.r)<eps*(fabs(k1.r)+fabs(k2.r))) br++;
        if(br==4) return true;
        return false;
    }
    //Testira samo da li su kugle podudarne tj da li imaju iste poluprecnike
    friend bool DaLiSuPodudarne(const Kugla k1, const Kugla &k2){
        return (fabs(k1.r-k2.r)<eps*(fabs(k1.r)+fabs(k2.r)));
    }
    //Testira samo da li kugle imaju isti centar, poluprecnik se moze razlikovati
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
        int br(0);
        if(fabs(k1.x-k2.x)<eps*(fabs(k1.x)+fabs(k2.x))) br++;
        if(fabs(k1.y-k2.y)<eps*(fabs(k1.y)+fabs(k2.y))) br++;
        if(fabs(k1.z-k2.z)<eps*(fabs(k1.z)+fabs(k2.z))) br++;
        if(br==3) return true;
        return false;
    }
    
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
        double m(sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2)));
        return (fabs(k1.r+k2.r-m))<eps*(fabs(k1.r+k2.r)+fabs(m));
        //return k1.r+k2.r==m;
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
        double m(sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2)));
        double n(sqrt(pow(k1.r-k2.r,2)));
        return (fabs(n-m))<eps*(fabs(n)+fabs(m));
        //return n==m;
    }
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
       double m(sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2)));
       return m<k1.r+k2.r;
    }
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
        double m(sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2)));
        return (m<k1.r+k2.r && sqrt(pow(k1.r-k2.r,2))<m);  
    }
    bool DaLiSadrzi(const Kugla &k) const{
        return r+k.r>sqrt(pow(k.x-x,2)+pow(k.y-y,2)+pow(k.z-z,2));
    }
    friend double RastojanjeCentra(const Kugla &k1, const Kugla &k2){
        double rastojanje(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)));
        return rastojanje;
    }
};
bool DaLiJeMoguc(double poluprecnik){
    return (poluprecnik>=0);
}
int main ()
{
    int  n;
    std::cout<<"Unesite broj kugla: ";
    for(;;){
        std::cin>>n;
        while(!std::cin || n<=0){
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cin>>n;
        }
        if(n>0) break;
    }
   
    try{
        std::vector<std::shared_ptr<Kugla>> Kugle(n);
        for(int i(0); i<n; i++){
            double x,y,z,r;
            bool ispravan_unos(true);
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
            while(!std::cin){
                std::cout<<"Neispravan centar";
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cout<<"\nUnesite centar "<<i+1<<". kugle: ";
                std::cin>>x>>y>>z;
                if(std::cin) break;
            }
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
            if(DaLiJeMoguc(r))  Kugle[i]=std::make_shared<Kugla>(Kugla(x,y,z,r));
            else {
                ispravan_unos=false;
                std::cout<<"Ilegalan poluprecnik\n";
            }
            while(!ispravan_unos){
                std::cout<<"Unesite centar "<<i+1<<". kugle: ";
                std::cin>>x>>y>>z;
                //std::cin.clear();
                //std::cin.ignore(1000,'\n');
                std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
                std::cin>>r;
                if(r>=0) break;
            }
            Kugle[i]=std::make_shared<Kugla>(Kugla(x,y,z,r));
        }
        std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        double delta_x,delta_y,delta_z;
        std::cin>>delta_x>>delta_y>>delta_z;
        if(!std::cin){
            while(!std::cin){
                std::cout<<"Neispravni parametri translacije unesite ponovo!";
                std::cin.clear();
                std::cin.ignore();
                std::cin>>delta_x>>delta_y>>delta_z;
                if(std::cin) break;
            }
        }
        for(int i(0); i<n; i++) Kugle[i]->Transliraj(delta_x,delta_y,delta_z);
        std::sort(Kugle.begin(), Kugle.end(),[](std::shared_ptr<const Kugla> k1, std::shared_ptr<const Kugla> k2){
                                                return k1->DajZapreminu()<k2->DajZapreminu();
        });
        std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
        std::for_each(Kugle.begin(), Kugle.end(), [](std::shared_ptr<const Kugla> x){ x->Ispisi(); std::cout<<std::endl;});
        //Trazimo kuglu sa najvecom povrsinom 
        auto najveca_p(std::max_element(Kugle.begin(), Kugle.end(),[](std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2)->bool{
            return (*k1).DajPovrsinu() < (*k2).DajPovrsinu();
        }));
        std::cout<<"Kugla sa najvecom povrsinom je: "; (*najveca_p)->Ispisi(); std::cout<<std::endl;
        //Da li se sijeku
        bool sijeku_se(false);
        for(int i(0); i<n; i++){
            for(int j(i+1); j<n; j++){
            if(DaLiSeSijeku(*Kugle[i], *Kugle[j])){
                std::cout<<"\nPresjecaju se kugle: ";
                Kugle[i]->Ispisi();
                std::cout<<std::endl;
                Kugle[j]->Ispisi();
                std::cout<<std::endl;
                sijeku_se=true;
            }}
        }
        if(!sijeku_se) std::cout<<"\nNe postoje kugle koje se presjecaju!"<<std::endl;
    }catch(...){
        std::cout<<"Problemi sa memorijom"<<std::endl;
    }
	return 0;
}
