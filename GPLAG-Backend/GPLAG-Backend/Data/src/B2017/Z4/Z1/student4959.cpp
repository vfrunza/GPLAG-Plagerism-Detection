/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <algorithm>

const double PI = 4*std::atan(1);
const double EPS = 1e-10;

class Kugla{
    double x,y,z,r;
    
    public:
    explicit Kugla(double r = 0){
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        x = 0; y = 0; z = 0; Kugla::r = r; 
    }//done
    Kugla(double x, double y, double z, double r = 0){
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x = x; Kugla::y = y; Kugla::z = z; Kugla::r = r;
    }//done
    explicit Kugla(const std::tuple<double,double,double> &centar, double r = 0){
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        x =std::get<0>(centar); y = std::get<1>(centar);
        z = std::get<2>(centar); Kugla::r = r;
    }//done
    
    double DajX() const { return x; }//done
    double DajY() const { return y; }//done
    double DajZ() const { return z; }//done
    double DajPoluprecnik() const { return r; }//done
    double DajPovrsinu() const;//done
    double DajZapreminu() const;//done
    std::tuple<double,double,double> DajCentar() const;//done
    
    Kugla &PostaviX(double x);//done
    Kugla &PostaviY(double y);//done
    Kugla &PostaviZ(double z);//done¸
    Kugla &PostaviCentar(double x, double y, double z);//done
    Kugla &PostaviCentar(const std::tuple<double,double,double> &centar);//done
    Kugla &PostaviPoluprecnik(double r);//done
    
    void Ispisi() const;//done
    void Tranasliraj(double delta_x, double delta_y, double delta_z);//done
    
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);//done
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);//done
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);//done
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);//done
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);//done
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);//done
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);//done
    bool DaLiSadrzi(const Kugla &k) const;//done
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);//done

};

Kugla &Kugla::PostaviCentar(double x, double y, double z){
    PostaviX(x); PostaviY(y); PostaviZ(z);
    return *this;
}
Kugla &Kugla::PostaviCentar(const std::tuple<double,double,double> &centar){
    PostaviCentar(std::get<0>(centar),std::get<1>(centar),std::get<2>(centar));
    return *this;
}
Kugla &Kugla::PostaviPoluprecnik(double r){
    if(r<0)throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r = r; return *this;
}
Kugla &Kugla::PostaviX(double x){
    Kugla::x = x; return *this;
}
Kugla &Kugla::PostaviY(double y){
    Kugla::y = y; return *this;
}
Kugla &Kugla::PostaviZ(double z){
    Kugla::z = z; return *this;
}
std::tuple<double,double,double> Kugla::DajCentar() const {
    return std::make_tuple(DajX(),DajY(),DajZ());
}
double Kugla::DajPovrsinu() const {
    return 4*DajPoluprecnik()*DajPoluprecnik()*PI;
}
double Kugla::DajZapreminu() const {
    return DajPovrsinu()*DajPoluprecnik()/3; 
}
void Kugla::Ispisi() const {
    // ispis oblika {( , , ), }
    std::cout<<"{("<<DajX()<<","<<DajY()<<","
        <<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl;
}
void Kugla::Tranasliraj(double delta_x, double delta_y, double delta_z){
    x+=delta_x; y+=delta_y; z+=delta_z;
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    // oredjenje preko eps;
    bool tx,ty,tz,tr;
    tx = std::abs(k1.DajX() - k2.DajX()) < EPS;
    ty = std::abs(k1.DajY() - k2.DajY()) < EPS;
    tz = std::abs(k1.DajZ() - k2.DajZ()) < EPS;
    tr = std::abs(k1.DajPoluprecnik() - k2.DajPoluprecnik()) < EPS;
    if( tx && ty && tz && tr)return true;
    return false;    
}
bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2){
    // imaju isti poluprecnik centar ne mora biti
    if(std::abs(k1.DajPoluprecnik() - k2.DajPoluprecnik()) < EPS)return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    // imaju isti centar poluprecnik ne mora biti
    bool tx,ty,tz;
    tx = std::abs(k1.DajX() - k2.DajX()) < EPS;
    ty = std::abs(k1.DajY() - k2.DajY()) < EPS;
    tz = std::abs(k1.DajZ() - k2.DajZ()) < EPS;
    if(tx && ty && tz)return true;
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    // testira da li imaju jednu zajednicku tacku izvana
    double d1 = k1.DajPoluprecnik() + k2.DajPoluprecnik();
    double d = RastojanjeCentara(k1,k2);
    if(std::abs(d-d1) < EPS)return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    // ukoliko je udaljenost centara manja od zbira poluprecnika
    double d1 = k1.DajPoluprecnik() + k2.DajPoluprecnik();
    double d = RastojanjeCentara(k1,k2);
    if(d1 - d > 0 && !DaLiSeDodirujuIznutra(k1,k2))return true;
    return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    // rastojanje centara
    double prvi(k1.DajX() - k2.DajX());
    double drugi(k1.DajY() - k2.DajY());
    double treci(k1.DajZ() - k2.DajZ());
    return std::sqrt( prvi*prvi + drugi*drugi + treci*treci);
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    if(k1.DajPoluprecnik() > k2.DajPoluprecnik()){
        double x(RastojanjeCentara(k1,k2)+k2.DajPoluprecnik());
        double y(k1.DajPoluprecnik());
        return abs(x-y) < EPS*(abs(x)+abs(y));
    }
    else {
        double x(RastojanjeCentara(k1,k2)+k1.DajPoluprecnik());
        double y(k2.DajPoluprecnik());
        return abs(x-y) < EPS*(abs(x)+abs(y));
    }
}
bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2){
    if(k1.DajPoluprecnik() > k2.DajPoluprecnik())
        return (RastojanjeCentara(k1,k2) + k2.DajPoluprecnik() > k1.DajPoluprecnik());
    else
        return (RastojanjeCentara(k1,k2) + k1.DajPoluprecnik() > k2.DajPoluprecnik());
}
bool Kugla::DaLiSadrzi(const Kugla &k) const {
    return RastojanjeCentara(*this,k) + k.DajPoluprecnik() < r;
}

int main ()
{
    std::cout<<"Unesite broj kugla: ";
    int n;
    while(std::cin){
    std::cin>>n;
        if(!std::cin || n<=0){
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            n=0;
        }else break;
    }
    std::vector<std::shared_ptr<Kugla>> kugle;
    for(int i(0);i<n;i++){
        double x,y,z,r;
        while(std::cin){
            while(std::cin){
                std::cout<<"Unesite centar "<<i+1<<". kugle: ";
                std::cin>>x>>y>>z;
                if(!std::cin){
                    std::cout<<"Neispravan centar"<<std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                }else break;
            }
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
            if(!std::cin || r<0){
                std::cout<<"Ilegalan poluprecnik"<<std::endl;
                std::cin.clear();
                std::cin.ignore(10000,'\n');                
                
            }else break;
        }
        
        auto a = std::make_shared<Kugla>(Kugla(x,y,z,r));
        kugle.push_back(a);
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double a,s,d;
    while (std::cin) {
        std::cin>>a>>s>>d;
        if(!std::cin){
            std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }else break;
    }

    std::transform(kugle.begin(),kugle.end(),kugle.begin(),
        [a,s,d](std::shared_ptr<Kugla> p){ p->Tranasliraj(a,s,d);  return p; });
        
    std::sort(kugle.begin(),kugle.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){
        return k1->DajZapreminu() < k2->DajZapreminu();
    });
    
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(kugle.begin(),kugle.end(),[](std::shared_ptr<Kugla>k){ k->Ispisi(); });
    
    auto maks = std::max_element(kugle.begin(),kugle.end(),
    [](std::shared_ptr<Kugla>k1,std::shared_ptr<Kugla>k2){
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    });
    
    std::cout<<"Kugla sa najvecom povrsinom je: "; (*maks)->Ispisi();
    
    // presjek kugle
    int kaunter(0),i(0);
    std::for_each(&kugle[0],&kugle[0]+kugle.size(),
        [kugle,&kaunter,&i]( std::shared_ptr<Kugla>k){
            std::for_each(&kugle[i],&kugle[0]+kugle.size(),
                [k,&kaunter](std::shared_ptr<Kugla> k1){
                    if(DaLiSeSijeku(*k,*k1)){
                        kaunter++;
                        std::cout<<"Presjecaju se kugle: ";
                        k->Ispisi();
                        k1->Ispisi();
                    }
                }
            );
            i++;
        }
        
    );
    if(kaunter == 0) std::cout<<"Ne postoje kugle koje se presjecaju!";
	return 0;
}