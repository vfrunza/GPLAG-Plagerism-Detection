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
    bool Jednaki(long double a, long double b){
        return (std::abs(a-b)<eps*(std::abs(b)+std::abs(a)));
    }
    bool Veci( long double a, long double b){
        return a-b > eps * (std::abs(b)+std::abs(a));
    }


class NepreklapajucaKugla{
    double x, y, z,r;
    bool DaliSeSijeku(const NepreklapajucaKugla& k1){
        return Veci(r+k1.r,RastojanjeCentara(*this,k1));
    }
    NepreklapajucaKugla * prethodni;
    static NepreklapajucaKugla * pocetak;
    public:
    explicit NepreklapajucaKugla(double r=0);
    NepreklapajucaKugla (double x,double y, double z, double r=0);
    explicit NepreklapajucaKugla(const std::tuple<double,double,double> &centar,double r=0);
    double DajX () const;
    double DajY () const;
    double DajZ () const;
    NepreklapajucaKugla(NepreklapajucaKugla k1)=delete;
    NepreklapajucaKugla& operator=(NepreklapajucaKugla k1)=delete;
    std::tuple<double,double,double> DajCentar()const;
    double DajPoluprecnik () const;
    double DajPovrsinu () const;
    double DajZapreminu () const;
    NepreklapajucaKugla &PostaviX(double x);
    NepreklapajucaKugla &PostaviY(double y);
    NepreklapajucaKugla &PostaviZ(double z);
    NepreklapajucaKugla &PostaviCentar (double x, double y, double z);
    NepreklapajucaKugla &PostaviCentar(std::tuple<double,double,double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Translatiraj (double delta_x, double delta_y, double delta_z);
     bool DaLiSadrzi(const NepreklapajucaKugla &k) const;
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1,const NepreklapajucaKugla &k2);
};
 NepreklapajucaKugla * NepreklapajucaKugla:: pocetak=nullptr;
 NepreklapajucaKugla::NepreklapajucaKugla(double r){
    if(r<0)
        throw std::domain_error("Ilegalan poluprecnik");
    auto p=pocetak;
    while (p!=nullptr) {
        if(Veci( r+p->r,std::sqrt((0 -p->x) * (0 -p->x) + (0 -p->y) * (0 -p->y) + (0 -p->z) * (0 -p->z)) )){
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        p=p->prethodni;
    }
        prethodni=pocetak;
        int NepreklapajucaKugla* NepreklapajucaKugla::pocetak=this;
        this->r=r;
     this->x=0;
     this->z=0;
     this->y=0;
}
NepreklapajucaKugla::NepreklapajucaKugla(double x,double y, double z, double r){
     if(r<0)
        throw std::domain_error("Ilegalan poluprecnik");
     auto p=pocetak;
    while (p!=nullptr) {
        if(Veci( r+p->r,std::sqrt((x -p->x) * (x -p->x) + (y -p->y) * (y -p->y) + (z -p->z) * (z -p->z)) )){
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        p=p->prethodni;
    }
    prethodni=pocetak;
NepreklapajucaKugla* NepreklapajucaKugla::pocetak=this;
     this->r=r;
     this->x=x;
     this->z=z;
     this->y=y;
}
NepreklapajucaKugla::NepreklapajucaKugla(const std::tuple<double,double,double> &centar,double r){
    if(r<0)
        throw std::domain_error("Ilegalan poluprecnik");
    int r1,x1,y1,z1;
     r1=r;
     x1=std::get<0>(centar);
     y1=std::get<1>(centar);
     z1=std::get<2>(centar);
       auto p=pocetak;
    while (p!=nullptr) {
        if(Veci( r+p->r,std::sqrt((x1 -p->x) * (x1 -p->x) + (y1 -p->y) * (y1 -p->y) + (z1 -p->z) * (z1 -p->z)) )){
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        p=p->prethodni;
    }
    prethodni=pocetak;
    int NepreklapajucaKugla* NepreklapajucaKugla::pocetak=this;
     this->r=r;
     this->x=x;
     this->z=z;
     this->y=y;
}
double NepreklapajucaKugla::DajX () const{
    return x;
}

double NepreklapajucaKugla::DajY () const{
    return y;
}

double NepreklapajucaKugla::DajZ () const{
    return z;
}

std::tuple<double,double,double> NepreklapajucaKugla::DajCentar()const{
    return std::make_tuple(x,y,z);
}

double NepreklapajucaKugla::DajPoluprecnik () const{
    return r;
}
    
double NepreklapajucaKugla::DajPovrsinu () const{
    return 4*r*r*4*std::atan(1);
}
double NepreklapajucaKugla::DajZapreminu () const{
    return (4.)*r*r*r*4*std::atan(1)/3;
}

NepreklapajucaKugla& NepreklapajucaKugla::PostaviX(double x){
     auto p=pocetak;
    while (p!=nullptr) {
        if( p!=this && Veci( r+p->r,std::sqrt((x -p->x) * (x -p->x) + (y -p->y) * (y -p->y) + (z -p->z) * (z -p->z)) )){
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        p=p->prethodni;
        }
        this->x=x;
        return *this;
        }
    
NepreklapajucaKugla& NepreklapajucaKugla::PostaviY(double y){
     auto p=pocetak;
    while (p!=nullptr) {
        if( p!=this && Veci( r+p->r,std::sqrt((x -p->x) * (x -p->x) + (y -p->y) * (y -p->y) + (z -p->z) * (z -p->z)) )){
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        p=p->prethodni;
        }
    this->y=y;
    return *this;
}

NepreklapajucaKugla& NepreklapajucaKugla::PostaviZ(double z){
    this->z=z;
    return *this;
}
NepreklapajucaKugla & NepreklapajucaKugla::PostaviCentar (double x, double y, double z){
    this->x=x;
    this->y=y;
    this->z=z;
    return *this;
}

NepreklapajucaKugla & NepreklapajucaKugla::PostaviCentar(std::tuple<double,double,double> &centar){
    this->x=std::get<0>(centar);
     this->z=std::get<1>(centar);
     this->y=std::get<2>(centar);
     return *this;
}

NepreklapajucaKugla & NepreklapajucaKugla::PostaviPoluprecnik(double r){
    this->r=r;
    return *this;
}

void NepreklapajucaKugla::Ispisi() const{
    std::cout << "{("<<x<<","<<y<<","<<z<<"),"<<r<<"}" <<std::endl;
}

void NepreklapajucaKugla::Translatiraj (double delta_x, double delta_y, double delta_z){
    x+=delta_x; y+=delta_y; z+=delta_z;
}    

 bool NepreklapajucaKugla::DaLiSadrzi(const NepreklapajucaKugla &k) const{
        return Veci(k.r,RastojanjeCentara(*this,k)+this->r) or Jednaki(k.r,RastojanjeCentara(*this,k)+this->r);
 }
 
  double RastojanjeCentara(const Kugla &k1,const Kugla &k2){
     return std::sqrt((k1.x -k2.x) * (k1.x -k2.x) + (k1.y - k2.y) * (k1.y - k2.y) + (k1.z - k2.z) * (k1.z - k2.z));
 }
 
int main ()
{
    int n;
        std::cout << "Unesite broj NepreklapajucaKugla: ";
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
    
    std::vector<std::shared_ptr<NepreklapajucaKugla>> Kuglee(n,nullptr);
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
            Kuglee.at(i)=std::make_shared<NepreklapajucaKugla>(x,y,z,r);
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
    
    std::transform(Kuglee.begin(),Kuglee.end(),Kuglee.begin(),[dx,dy,dz](std::shared_ptr<NepreklapajucaKugla> k)->std::shared_ptr<NepreklapajucaKugla>{
     k->Translatiraj(dx,dy,dz);
     return k;
    });
    
    std::sort(Kuglee.begin(),Kuglee.end(),[](std::shared_ptr<NepreklapajucaKugla> k1,std::shared_ptr<NepreklapajucaKugla> k2){
        return (!Veci(k1->DajZapreminu(),k2->DajZapreminu())&& !Jednaki(k1->DajZapreminu(),k2->DajZapreminu()));
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(Kuglee.begin(),Kuglee.end(),[](std::shared_ptr<NepreklapajucaKugla> k){
     k->Ispisi();
    });
    std::cout << "NepreklapajucaKugla sa najvecom povrsinom je: ";
    (*(std::max_element(Kuglee.begin(),Kuglee.end(),[](std::shared_ptr<NepreklapajucaKugla> k1,std::shared_ptr<NepreklapajucaKugla> k2){
        return(!Veci(k1->DajPovrsinu(),k2->DajPovrsinu())&& !Jednaki(k1->DajPovrsinu(),k2->DajPovrsinu()));
    })))->Ispisi();
    std::cout<<std::endl;
    int brojac1(0),brojac2(0);
    std::for_each(Kuglee.begin(),Kuglee.end(),[&brojac1,&brojac2,Kuglee](std::shared_ptr<NepreklapajucaKugla> k1)->void{
        brojac2++;
        std::for_each(Kuglee.begin()+brojac2,Kuglee.end(),[k1,&brojac1](std::shared_ptr<NepreklapajucaKugla> k2)->void{
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















