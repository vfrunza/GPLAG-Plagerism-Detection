/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

class NepreklapajucaKugla
{
    double x,y,z,r;
    NepreklapajucaKugla* prethodna=nullptr;
    static NepreklapajucaKugla* posljednja;
    static double DajUdaljenost(double x1, double y1, double z1, double x2, double y2, double z2) {
        return sqrt(pow((x2-x1),2)+pow((y2-y1),2)+pow((z2-z1),2));
    }
    static bool Jednako(double x, double y) {
        return fabs(x-y)<1e-10*(fabs(x)+fabs(y));
    }
    bool PreklapanjeSvih(NepreklapajucaKugla *pocetak,double x, double y, double z, double r) {
        for(auto p=pocetak; p!=nullptr; p=p->prethodna) {
            if(PreklapajuSe(*p,x,y,z,r)) return true;
        }
        return false;
    }
    static bool PreklapajuSe(const NepreklapajucaKugla &k1,double x, double y, double z, double r) {
        return (DajUdaljenost(k1.DajX(),k1.DajY(),k1.DajZ(),x,y,z)<=k1.DajPoluprecnik()+r);
        
    }
public:
    explicit NepreklapajucaKugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        if(PreklapanjeSvih(posljednja,0,0,0,r)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        x=y=z=0;
        NepreklapajucaKugla::r=r;
        prethodna=posljednja;
        posljednja=this;
    }
    NepreklapajucaKugla(double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        if(PreklapanjeSvih(posljednja,x,y,z,r)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
        prethodna=posljednja;
        posljednja=this;

    }
    NepreklapajucaKugla(const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla &operator=(const NepreklapajucaKugla &k) = delete;

    ~NepreklapajucaKugla() {
        if(posljednja==nullptr) return;
        if(posljednja==this && prethodna==nullptr){
            posljednja=nullptr;
        }
        else if(posljednja==this){
            posljednja=prethodna;
        }
        else{
            auto p=posljednja;
            for(p=posljednja;p->prethodna!=nullptr;p=p->prethodna) if(p->prethodna==this) break;
            p->prethodna=this->prethodna;
        }
    }
    explicit NepreklapajucaKugla(const std::tuple<double,double,double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        if(PreklapanjeSvih(posljednja,std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),r)) throw std::logic_error("Nedozvoljeno preklapanje");
        std::tie(x,y,z)=centar;
        NepreklapajucaKugla::r=r;
        prethodna=posljednja;
        posljednja=this;
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
    std::tuple<double, double, double> DajCentar() const {
        return std::make_tuple(x,y,z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*DajPoluprecnik()*DajPoluprecnik()*4*atan(1);
    }
    double DajZapreminu() const {
        return (4*DajPoluprecnik()*DajPoluprecnik()*DajPoluprecnik()*4*atan(1))/3.;
    }
    NepreklapajucaKugla &PostaviX(double x) {
        if(prethodna!=nullptr) {
            if(PreklapanjeSvih(prethodna,x,y,z,r)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
        NepreklapajucaKugla::x=x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        if(prethodna!=nullptr) {
            if(PreklapanjeSvih(prethodna,x,y,z,r)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
        NepreklapajucaKugla::y=y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        if(prethodna!=nullptr) {
            if(PreklapanjeSvih(prethodna,x,y,z,r)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        if(prethodna!=nullptr) {
            if(PreklapanjeSvih(prethodna,x,y,z,r)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double,double,double> &centar) {
        if(prethodna!=nullptr) {
            if(PreklapanjeSvih(prethodna,std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),r)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
        std::tie(x,y,z)=centar;
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        if(prethodna!=nullptr) {
            if(PreklapanjeSvih(prethodna,x,y,z,r)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
        NepreklapajucaKugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        if(prethodna!=nullptr) {
            if(PreklapanjeSvih(prethodna,x+delta_x,y+delta_y,z+delta_z,r)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const {
        return DajUdaljenost(DajX(),DajY(),DajZ(),k.DajX(),k.DajY(),k.DajZ())<=fabs(DajPoluprecnik()-k.DajPoluprecnik());
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
        return DajUdaljenost(k1.DajX(),k1.DajY(),k1.DajZ(),k2.DajX(),k2.DajY(),k2.DajZ());
    }
};

NepreklapajucaKugla *NepreklapajucaKugla::posljednja(nullptr);

int main ()
{
    int n;
    std::cout<<"Unesite broj kugli: ";
    for(;;) {
        std::cin>>n;
        if(!std::cin || n<1) {
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        } else break;
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>>v;
    for(int i=0; i<n; i++) {
        try {
            double x,y,z,r;
            std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
            for(;;) {
                if(!(std::cin>>x) || !(std::cin>>y) || !(std::cin>>z)) {
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                    std::cout<<"Neispravan centar, unesite ponovo:"<<std::endl;
                } else break;
            }
            std::cout<<"Unesite poluprecnik: ";
            for(;;) {
                if(!(std::cin>>r) || r<0) {
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                    std::cout<<"Neispravan poluprecnik, unesite ponovo:"<<std::endl;
                } else break;
            }
            v.push_back(std::make_shared<NepreklapajucaKugla>(x,y,z,r));
        } catch(std::domain_error e) {
            std::cout<<e.what()<<std::endl;
            i--;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        } catch(std::logic_error e) {
            std::cout<<e.what()<<std::endl;
            i--;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
    }
    std::sort(v.begin(),v.end(),[](std::shared_ptr<NepreklapajucaKugla> p1,std::shared_ptr<NepreklapajucaKugla> p2) {
        return p1->DajPovrsinu()<p2->DajPovrsinu();
    });
    std::cout<<std::endl<<"Kugle nakon obavljenog sortiranja: "<<std::endl;
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<NepreklapajucaKugla> p) {
        p->Ispisi();
    });
    return 0;
}
