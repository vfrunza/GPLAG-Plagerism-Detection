/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <memory>
#include <new>
#include <vector>
#include <algorithm>
#define eps 0.0000000001


class Kugla
{
    double x,y,z, r;
public:

    explicit Kugla(double r=0) {
        x=0;
        y=0;
        z=0;
        r=r;
    }
    Kugla(double x, double y, double z,double r=0): x(x), y(y), z(z), r(r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        r=r;
    }
    explicit Kugla(const std::tuple<double,double,double> &centar, double r=0): x(std::get<0>(centar)), y(std::get<1>(centar)), z(std::get<2>(centar)) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        r=r;
    }

    double DajX()const {
        return x;
    }
    double DajY()const {
        return y;
    }
    double DajZ()const {
        return z;
    }
    std::tuple<double,double, double> DajCentar()const {
        std::tuple<double,double,double> pomocni;
        std::get<0>(pomocni)=(*this).DajX();
        std::get<1>(pomocni)=(*this).DajY();
        std::get<2>(pomocni)=(*this).DajZ();
        return pomocni;
    }

    double DajPoluprecnik()const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*(*this).DajPoluprecnik()*(*this).DajPoluprecnik()*4*atan(1);
    }
    double DajZapreminu()const {
        return (4*(*this).DajPoluprecnik()*(*this).DajPoluprecnik()*(*this).DajPoluprecnik()*4*atan(1))/3;
    }

    Kugla &PostaviX(double X) {
        x=X;
        return *this;
    }

    Kugla &PostaviY(double Y) {
        y=Y;
        return *this;
    }

    Kugla &PostaviZ(double Z) {
        z=Z;
        return *this;
    }

    Kugla &PostaviCentar(double X, double Y, double Z) {
        x=X;
        y=Y;
        z=Z;
        return *this;
    }

    Kugla &PostaviCentar(const std::tuple<double, double,double> &centar) {
        (*this).PostaviX(std::get<0>(centar));
        (*this).PostaviY(std::get<1>(centar));
        (*this).PostaviZ(std::get<2>(centar));
        return *this;
    }

    Kugla &PostaviPoluprecnik(double R) {
        if(R<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=R;
        return *this;
    }

    void Ispisi() const {
        std::cout<<"{"<<"("<<(*this).DajX()<<","<<(*this).DajY()<<","<<(*this).DajZ()<<"),"<<(*this).DajPoluprecnik()<<"}"<<std::endl;;
    }

    void Transliraj(double delta_x, double delta_y, double delta_z) {
        PostaviCentar((*this).DajX()+delta_x, (*this).DajY()+delta_y, (*this).DajZ()+delta_z);
    }

    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    bool  logicka(true);
    if(std::abs(k1.DajX()-k2.DajX())>eps || std::abs(k1.DajY()-k2.DajY())>eps || std::abs(k1.DajZ()-k2.DajZ())>eps || std::abs(k1.DajPoluprecnik()-k2.DajPoluprecnik())>eps) logicka=false;
    return logicka;
}

bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2)
{
    bool logicka(true);
    if(std::abs(k1.DajPoluprecnik()-k2.DajPoluprecnik())>eps) logicka=false;
    return logicka;
}

bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2)
{
    bool logicka(true);
    if(std::abs(k1.DajX()-k2.DajX())>eps || std::abs(k1.DajY()-k2.DajY())>eps || std::abs(k1.DajZ()-k2.DajZ())>eps) logicka=false;
    return logicka;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    bool logicka(true);
    if(std::abs(RastojanjeCentara(k1, k2)-std::abs(k1.DajPoluprecnik()+k2.DajPoluprecnik()))>eps) logicka=false;
    return logicka;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    bool logicka(true);
    if(std::abs(RastojanjeCentara(k1, k2)-(k1.DajPoluprecnik()-k2.DajPoluprecnik()))>eps) logicka=false;
    return logicka;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    bool logicka(false);
    if((k1.DajPoluprecnik()+k2.DajPoluprecnik())>RastojanjeCentara(k1, k2) && RastojanjeCentara(k1, k2)>std::abs(k1.DajPoluprecnik()-k2.DajPoluprecnik())) logicka=true;
    return logicka;
}

bool Kugla::DaLiSadrzi(const Kugla &k)const
{
    bool logicka(false);
    if(std::sqrt((k.DajX()-(*this).DajX())*(k.DajX()-(*this).DajX())+(k.DajY()-(*this).DajY())*(k.DajY()-(*this).DajY())+(k.DajZ()-(*this).DajZ())*
                 (k.DajZ()-(*this).DajZ()))<(*this).DajPoluprecnik() && (k.DajPoluprecnik()<(*this).DajPoluprecnik())) logicka=true;
    return logicka;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    bool logicka(false);
    bool l1(DaLiSeSijeku(k1, k2));
    bool l2(k1.DaLiSadrzi(k2));
    bool l3(k2.DaLiSadrzi(k1));
    if(l1==true || l2==true || l3==true) logicka=true;
    return logicka;
}
double RastojanjeCentara(const Kugla &k1,const Kugla &k2)
{
    double rastojanje(std::sqrt((k2.DajX()-k1.DajX())*(k2.DajX()-k1.DajX())+(k2.DajY()-k1.DajY())*(k2.DajY()-k1.DajY())+(k2.DajZ()-k1.DajZ())*(k2.DajZ()-k1.DajZ())));
    return rastojanje;
}

int main ()
{
    int n;
    char a;
 
    std::cout<<"Unesite broj kugla: ";
   do{
    
     std::cin>>n; 
     if(n>0) break;
     bool logicka=false;
     if(!std::cin){
         std::cin.clear();
         std::cin.ignore(1000, '\n');
          std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
          logicka=true;
     }
     if(logicka) continue;
     if(n<=0) std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
     
    } while(true);
   
    std::vector<std::shared_ptr<Kugla>> v;
    double x, y, z, r;
    char c;
    for(int i=0; i<n; i++) {
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
          
            std::cin>>x>>y>>z;
            c=std::cin.peek();
            if(c!='\n' && c!=' ') {
                std::cout<<"Neispravan centar"<<std::endl;
                std::cin.clear(); 
                std::cin.ignore(1000, '\n');
                i--;
                continue;
            }
            char b;
                std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
                std::cin>>r;
                b=std::cin.peek();
                if(b!='\n' && b!=' ' || r<0) {
                    std::cout<<"Ilegalan poluprecnik"<<std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    i--;
                    continue;
                } 
       try{  
        v.push_back(std::make_shared<Kugla>(x,y,z,r));
    } 
    catch(...){
        std::cout<<"Ilegalan poluprecnik"<<std::endl;
    }}
    double delta_x, delta_y, delta_z;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    for(;;) {
        std::cin>>delta_x>>delta_y>>delta_z;
        if(std::cin) break;
        else {
             std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
           
        }
    }
    std::transform(v.begin(), v.end(), v.begin(),  [delta_x, delta_y, delta_z] (std::shared_ptr<Kugla> p){
          p->Kugla::Transliraj(delta_x, delta_y, delta_z);
        return p;
    });

    std::sort(v.begin(), v.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajZapreminu() < k2->DajZapreminu();
    });
std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> p){p->Kugla::Ispisi();});
 auto pok=(std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2){return p1->DajPovrsinu() < p2->DajPovrsinu(); }));
std::cout<<"Kugla sa najvecom povrsinom je: "; (*pok)->Kugla::Ispisi();
int br(0);
std::for_each(v.begin(), v.end(), [&br, &v](std::shared_ptr<Kugla> p1){

    
    std::for_each(v.begin()+br, v.end(),[&br, p1](std::shared_ptr<Kugla> p2)
    {
        if(DaLiSeSijeku(*p1, *p2)){
            std::cout<<"Presjecaju se kugle: ";
            p1->Ispisi();
            p2->Ispisi();
        }
        }
    );

}
if(br==0) std::cout<<"Ne postoje kugle koje se presjecaju!");
    return 0;
}
