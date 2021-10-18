/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include<tuple>
#include<cmath>
#include<vector>
#include<stdexcept>
#include<memory>
#include<algorithm>
const double epsilon=std::pow(10,-10);
class Kugla
{
    double x,y,z;
    double r;
public:

    explicit Kugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=0;
        Kugla::y=0;
        Kugla::z=0;
        PostaviPoluprecnik(r);
    }
    Kugla(double x,double y,double z,double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        PostaviPoluprecnik(r);
    }
    explicit Kugla(const std::tuple<double,double,double> &centar,double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        PostaviPoluprecnik(r);
    }
    double DajX() const {
        return x;
    }
    double DajY() const {
        return y;
    }
    double DajZ() const {
        return z;
    }
    std::tuple<double,double,double> DajCentar() const {
        std::tuple<double,double,double>centar;
        centar=std::make_tuple(Kugla::x,Kugla::y,Kugla::z);
        return centar;
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        double P=4*r*r*std::atan(1)*4;
        return P;
    }
    double DajZapreminu() const {
        double V=4/3*r*r*r*std::atan(1)*4;
        return V;
    }
    Kugla &PostaviX(double x) {
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x,double y,double z) {
        PostaviX(x);
        PostaviY(y);
        PostaviZ(z);
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double,double,double> &centar) {
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}";
    }
    void Transliraj(double delta_x,double delta_y,double delta_z) {
        Kugla::x=DajX()+delta_x;
        Kugla::y=DajY()+delta_y;
        Kugla::z=DajZ()+delta_z;
    }


    friend bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2) ;
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2);

    bool DaLiSadrzi(const Kugla &k) const {
        double d=std::sqrt((DajX()-k.x)*(DajX()-k.x)+(DajY()-k.y)*(DajY()-k.y)+(DajZ()-k.z)*(DajZ()-k.z));
        double manji, veci;
        if(DajPoluprecnik() <= k.DajPoluprecnik()) {
            manji = DajPoluprecnik();
            veci = k.DajPoluprecnik();
        } else {
            veci = DajPoluprecnik();
            manji = k.DajPoluprecnik();
        }
        if(d + manji <= veci || std::fabs((d + manji) - veci) <= epsilon * (std::fabs(veci)+std::fabs(d + manji))) return true;
        return false;
    }

    friend double RastojanjeCentara(const Kugla &k1,const Kugla &k2);
};
   bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2){
        if((std::fabs(k1.x-k2.x))<=(epsilon*(std::fabs(k1.x)+std::fabs(k2.x))) && (std::fabs(k1.y-k2.y))<(epsilon*(std::fabs(k1.y)+std::fabs(k2.y))) && (std::fabs(k1.z-k2.z))<(epsilon*(std::fabs(k1.z)+std::fabs(k2.z))) && (std::fabs(k1.r-k2.r))<(epsilon*(std::fabs(k1.r)+std::fabs(k2.r)))) return true;
        return false;
    }
    bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2){
        if(std::fabs(k1.r-k2.r)<=epsilon*(std::fabs(k1.r)+std::fabs(k2.r))) return true;
        return false;
    }
     bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2) {
        if((std::fabs(k1.x-k2.x))<=(epsilon*(std::fabs(k1.x)+std::fabs(k2.x))) && (std::fabs(k1.y-k2.y))<(epsilon*(std::fabs(k1.y)+std::fabs(k2.y))) && (std::fabs(k1.z-k2.z))<(epsilon*(std::fabs(k1.z)+std::fabs(k2.z)))) return true;
        return false;
    }
    bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2){
        double d=std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
        double zbir_poluprecnika=k1.r+k2.r;
        if(std::fabs(d-zbir_poluprecnika)<=epsilon*(std::fabs(zbir_poluprecnika)+std::fabs(d))) return true;
        return false;
    }
    bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2){
        double d=std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
        double razlika_poluprecnika=std::fabs(k1.r-k2.r);
        if(std::fabs(d-razlika_poluprecnika)<=epsilon*(std::fabs(razlika_poluprecnika)+std::fabs(d))) return true;
        return false;
    }
    bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2){
        RastojanjeCentara(k1,k2);
       // if(k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1) || DaLiSuIdenticne(k1, k2) || DaLiSuKoncentricne(k1, k2) || DaLiSeDodirujuIznutra(k1, k2) || DaLiSeSijeku(k1, k2)) 
      double zbir=k1.r+k2.r;
       if(RastojanjeCentara(k1,k2)>zbir || RastojanjeCentara(k1,k2)<std::fabs(k2.r-k1.r))return true;
        return false;
    } 
    bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2) {
        double d=std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
        double zbir_polu=k1.r+k2.r;
        double razlika_polu=std::fabs(k1.r-k2.r);
        if(d<zbir_polu && d>razlika_polu) 
        
          //  if(!DaLiSuKoncentricne(k1, k2) && !DaLiSeDodirujuIznutra(k1, k2) && !k1.DaLiSadrzi(k2) && !k2.DaLiSadrzi(k1))
            return true;
        
        return false;
    }
    double RastojanjeCentara(const Kugla &k1,const Kugla &k2){
        double d=std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
        return d;
    } 
int main ()
{
    std::cout << "Unesite broj kugla: ";
    int n;
    for(;;) {
        std::cin>>n;
        if(!std::cin || n<=0) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            continue;
        }
        break;
    }
    std::vector<std::shared_ptr<Kugla>>kugle(n);
    double x,y,z,r;
    for(int i(0); i<n; i++) {
        for(;;) {
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(100000,'\n');
                std::cout<<"Neispravan centar"<<std::endl;
                continue;
            }
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
            if(!std::cin || r<0) {
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cout<<"Ilegalan poluprecnik"<<std::endl;
                continue;
            }
            break;
        }
        kugle.at(i)=std::make_shared<Kugla>(x,y,z,r);
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double deltax,deltay,deltaz;
    for(;;) {
        std::cin>>deltax>>deltay>>deltaz;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
            continue;
        }
        break;
    }
    std::transform(kugle.begin(),kugle.end(),kugle.begin(),[deltax,deltay,deltaz](std::shared_ptr<Kugla>kugla) {
        kugla->Transliraj(deltax,deltay,deltaz);
        return kugla;
    });
    std::sort(kugle.begin(),kugle.end(),[](std::shared_ptr<Kugla> prvi,std::shared_ptr<Kugla> drugi) {
        if(prvi->DajZapreminu()<drugi->DajZapreminu()) return true;
        return false;
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(kugle.begin(),kugle.end(),[](std::shared_ptr<Kugla>kugla) {
        kugla->Ispisi();
        std::cout<<std::endl;
    });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto pom=*std::max_element(kugle.begin(),kugle.end(),[](std::shared_ptr<Kugla>prva,std::shared_ptr<Kugla> druga) {
        if(prva->DajPovrsinu() < druga->DajPovrsinu()) return true;
        return false;});
    pom->Ispisi();
    std::cout<<std::endl;
    bool postoji=false;
    int indeks=0;
    std::for_each(kugle.begin(),kugle.end(),[&postoji,kugle,&indeks](std::shared_ptr<Kugla>kugla) {
        indeks++;
        std::for_each(kugle.begin()+indeks,kugle.end(),[&postoji,kugla](std::shared_ptr<Kugla>kugla1) {
            if(DaLiSeSijeku(*kugla1,*kugla)) {
                postoji=true;
                std::cout<<"Presjecaju se kugle: ";
                kugla->Ispisi();
                std::cout<<std::endl;
                kugla1->Ispisi();
                std::cout<<std::endl;
            }
        });
    });
    if(postoji==false) std::cout<<"Ne postoje kugle koje se presjecaju!";
    return 0;
}
