#include <stdexcept>
#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include<memory>
#include <algorithm>
const double e=pow(10, -10);
const double PI=4*atan(1);
class Kugla{
    private:
    double x,y,z,r;
    public:
    explicit Kugla(double r){
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        r=r; x=0; y=0; z=0;
    }
    Kugla (double xx, double yy, double zz, double rr){
        if (rr<0) throw std::domain_error ("Ilegalan poluprecnik");
        x=xx; y=yy; z=zz; r=rr;
    }
    explicit Kugla (const std::tuple<double,double,double> &centar, double r=0){
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        r=r;
    }
    double DajPoluprecnik() const{ return r;}
    double DajX() const{ return x;}
    double DajY() const { return y;}
    double DajZ() const { return z;}
    std::tuple<double, double, double> DajCentar() const { auto t(std::tie(x,y,z)); 
    return t;}
    double DajPovrsinu() const { return (4*PI*r*r);}
    double DajZapreminu() const { return (PI*r*r*r*(4/3));}
    Kugla &PostaviX (double x){
        x=x;
        return *this;
    }
    Kugla &PostaviY(double y) { 
        y=y;
        return *this; }
    Kugla &PostaviZ (double z){
        z=z;
        return *this;
    }
    Kugla &PostaviCentar (double x, double y, double z){
        x=x; y=y; z=z;
        return *this;
    }
    Kugla &PostaviCentar (std::tuple<double, double, double> &centar){
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik (double r){
        r=r;
        return *this;
    }
    void Ispisi() const{
        std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}";
    }
    void Transliraj (double delta_x, double delta_y, double delta_z){
        x=DajX()+delta_x;
        y=DajY()+delta_y;
        z=DajZ()+ delta_z;
    }
    friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2);
    friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi (const Kugla &k) const {
        double d=sqrt((DajX()+k.DajX())*(DajX()+k.DajX())+(DajY()+k.DajY())*(DajY()+k.DajY())+(DajZ()+k.DajZ())*(DajZ()+k.DajZ()));
        double r=DajPoluprecnik()-k.DajPoluprecnik();
        return (d<r);
    }
};
double RastojanjeCentara (const Kugla &k1, const Kugla &k2){
    return sqrt(pow(k1.DajX()-k2.DajX(),2)+pow(k1.DajY()-k2.DajY(),2)+pow (k1.DajZ()-k2.DajZ(),2));
}
bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2){
    if (fabs(k1.DajX()-k2.DajX())<e && fabs(k1.DajY()-k2.DajY())<e && fabs(k1.DajZ()-k2.DajZ())<e && fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<e)
    return true;
    return false;
}
bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2){
    if (fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<e) return true;
    return false;
}
bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2){
    if (fabs (k1.DajX()-k2.DajX())<e && fabs(k1.DajY()-k2.DajY())<e&& fabs(k1.DajZ()-k2.DajZ())<e)
    return true;
    return false;
}
bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2){
    double d=RastojanjeCentara(k1,k2);
    double r=k1.DajPoluprecnik()+k2.DajPoluprecnik();
    if (fabs(d-r)<e) return true;
    return false;
}
bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2){
    double d=RastojanjeCentara(k1,k2);
    double r=fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik());
    if (fabs(d-r)<e) return true;
    return false;
}
bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2){
    double d=RastojanjeCentara(k1,k2);
    double r=k1.DajPoluprecnik()+k2.DajPoluprecnik();
    if ((d>fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()))&&(r>d)) return true;
    return false;
}
bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2){
    if (DaLiSeSijeku(k1,k2)) return true;
    double d=RastojanjeCentara(k1,k2);
    double r=fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik());
    return d<r;
} typedef std::shared_ptr <Kugla> Tip;
int main ()
{ 
    int n;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    while (n<=0 || !std::cin) {
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        std::cin>>n;
    }
    std::vector<Tip> pok(n), pomocni(n);
    int i=0;
    while (i<n){
        double x,y,z,r;
        label:
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        
        while (!std::cin){ 
            std::cout<<"Neispravan centar\nUnesite centar "<<i+1<<". kugle: ";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
             std::cin>>x>>y>>z;
           
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r; 
        if (!std::cin || r<0){
            std::cout<<"Ilegalan poluprecnik\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            goto label;
        } 
    
        Kugla k=Kugla(x,y,z,r); 
        pok.at(i)=std::make_shared<Kugla> (k);
        
        
      i++;
    }
    
    double delta_x, delta_y, delta_z;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin>>delta_x>>delta_y>>delta_z;
    while (!std::cin){
        std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin>>delta_x>>delta_y>>delta_z;
    }
    std::transform(pok.begin(), pok.end(), pomocni.begin(),[delta_x, delta_y, delta_z](std::shared_ptr<Kugla> &x) { 
       (*x).Transliraj(delta_x,delta_y,delta_z);
       return x;}
        );
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::sort (pomocni.begin(), pomocni.end(), [](std::shared_ptr<Kugla> x, std::shared_ptr<Kugla> y){
        return (*x).DajZapreminu()<(*y).DajZapreminu();
    });
    std::for_each (pomocni.begin(), pomocni.end(), [](std::shared_ptr<Kugla> x){
        (*x).Ispisi(); std::cout<<std::endl;
    });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto max=*std::max_element(pomocni.begin(), pomocni.end(), [](std::shared_ptr<Kugla> x,std::shared_ptr <Kugla> y){
        return (*x).DajPovrsinu()<(*y).DajPovrsinu();
    });
    Kugla k=*max;
    k.Ispisi(); std::cout<<std::endl;
    int f=0,s=1;
    std::for_each(pomocni.begin(), pomocni.end(),[ pomocni, &f,&s](std::shared_ptr<Kugla> x){
        std::for_each(pomocni.begin()+s, pomocni.end(), [& s,x, &f] (std::shared_ptr<Kugla> y){
            if (DaLiSeSijeku((*x),(*y))){
            std::cout<<"Presjecaju se kugle: ";
            (*x).Ispisi(); std::cout<<std::endl;
            (*y).Ispisi(); std::cout<<std::endl;
            f++;} 
            
        }); s++;
    });
    if (f==0) std::cout<<"Ne postoje kugle koje se presjecaju!";

	return 0;
}
