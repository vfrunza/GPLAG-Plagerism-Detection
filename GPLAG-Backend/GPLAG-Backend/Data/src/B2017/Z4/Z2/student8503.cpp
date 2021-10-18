/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include<tuple>
#include<cmath>
#include<vector>
#include<stdexcept>
#include<memory>
#include<algorithm>
const double epsilon=std::pow(10,-10);
class NepreklapajucaKugla
{
    double x,y,z;
    double r;
public:

    explicit NepreklapajucaKugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=0;
        NepreklapajucaKugla::y=0;
        NepreklapajucaKugla::z=0;
        PostaviPoluprecnik(r);
    }
    NepreklapajucaKugla(double x,double y,double z,double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        PostaviPoluprecnik(r);
    }
    explicit NepreklapajucaKugla(const std::tuple<double,double,double> &centar,double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=std::get<0>(centar);
        NepreklapajucaKugla::y=std::get<1>(centar);
        NepreklapajucaKugla::z=std::get<2>(centar);
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
        centar=std::make_tuple(NepreklapajucaKugla::x,NepreklapajucaKugla::y,NepreklapajucaKugla::z);
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
    NepreklapajucaKugla &PostaviX(double x) {
        NepreklapajucaKugla::x=x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        NepreklapajucaKugla::y=y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x,double y,double z) {
        PostaviX(x);
        PostaviY(y);
        PostaviZ(z);
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double,double,double> &centar) {
        NepreklapajucaKugla::x=std::get<0>(centar);
        NepreklapajucaKugla::y=std::get<1>(centar);
        NepreklapajucaKugla::z=std::get<2>(centar);
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}";
    }
    void Transliraj(double delta_x,double delta_y,double delta_z) {
        NepreklapajucaKugla::x=DajX()+delta_x;
        NepreklapajucaKugla::y=DajY()+delta_y;
        NepreklapajucaKugla::z=DajZ()+delta_z;
    }

    friend double RastojanjeCentara(const NepreklapajucaKugla &k1,const NepreklapajucaKugla &k2);
};
 
int main ()
{
   /* std::cout << "Unesite broj kugla: ";
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
    if(postoji==false) std::cout<<"Ne postoje kugle koje se presjecaju!";*/
    return 0;
}
