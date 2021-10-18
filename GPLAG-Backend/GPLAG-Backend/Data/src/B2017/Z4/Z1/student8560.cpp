/B2017/2018: Zadaća 4, Zadatak 1
#include<iostream>
#include<stdexcept>
#include<tuple>
#include<cmath>
#include<vector>
#include<algorithm>
#include<memory>
#include<iterator>
class Kugla {
    double x,y,z;
    double r;
    static bool DaLiSuJednaki(double a, double b);
    public:
    explicit Kugla(double r=0) {if(r<0) throw std::domain_error("Ilegalan poluprecnik"); Kugla::r=r;}
    Kugla(double x, double y, double z, double r=0) { if(r<0) throw std::domain_error("Ilegalan poluprecnik"); Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r;}
    explicit Kugla(const std::tuple<double,double,double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        Kugla::r=r;
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double,double,double> DajCentar() const { return std::make_tuple(x,y,z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 16*r*r*atan(1); }
    double DajZapreminu() const { return (16*r*r*r*atan(1))/3; }
    Kugla &PostaviX(double x) { Kugla::x=x; return *this; }
    Kugla &PostaviY(double y) { Kugla::y=y; return *this; }
    Kugla &PostaviZ(double z) { Kugla::z=z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z);
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const { std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl; }
    void Transliraj(double delta_x, double delta_y, double delta_z) { x+=delta_x; y+=delta_y; z+=delta_z; }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};
bool DaLiSuJednaki(double a, double b) {
    if(std::fabs(a-b)<=((1e-10)*(std::fabs(a)+std::fabs(b)))) return true;
    return false;
}
Kugla &Kugla::PostaviCentar(double x, double y, double z) {
    this->PostaviX(x);
    this->PostaviY(y);
    this->PostaviZ(z);
    return *this;
}
Kugla &Kugla::PostaviCentar(const std::tuple<double,double,double> &centar) {
    this->PostaviX(std::get<0>(centar));
    this->PostaviY(std::get<1>(centar));
    this->PostaviZ(std::get<2>(centar));
    return *this;
}
Kugla &Kugla::PostaviPoluprecnik(double r) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
    return *this;
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    if(DaLiSuJednaki(k1.DajX(),k2.DajX()) && DaLiSuJednaki(k1.DajY(),k2.DajY()) && DaLiSuJednaki(k1.DajZ(),k2.DajZ()) && DaLiSuJednaki(k1.DajPoluprecnik(),k2.DajPoluprecnik())) return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    if(DaLiSuJednaki(k1.DajPoluprecnik(),k2.DajPoluprecnik())) return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    if(DaLiSuJednaki(k1.DajX(),k2.DajX()) && DaLiSuJednaki(k1.DajY(),k2.DajY()) && DaLiSuJednaki(k1.DajZ(),k2.DajZ())) return true;
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    if(DaLiSuJednaki(RastojanjeCentara(k1,k2),k1.DajPoluprecnik()+k2.DajPoluprecnik()) && !DaLiSuIdenticne(k1,k2)) return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    if(DaLiSuJednaki(RastojanjeCentara(k1,k2),std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())) && !DaLiSuIdenticne(k1,k2)) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    if(RastojanjeCentara(k1,k2)<(k1.DajPoluprecnik()+k2.DajPoluprecnik()) && RastojanjeCentara(k1,k2)>std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())) return true;
    return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    if(DaLiSeSijeku(k1,k2) || DaLiSuKoncentricne(k1,k2) || k1.DaLiSadrzi(k2) || DaLiSuIdenticne(k1,k2)) return true;
    return false;
}
bool Kugla::DaLiSadrzi(const Kugla &k) const {
    if(RastojanjeCentara(*this,k)<std::fabs(this->DajPoluprecnik()-k.DajPoluprecnik())) return true;
    return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return std::sqrt((k2.DajX()-k1.DajX())*(k2.DajX()-k1.DajX())+(k2.DajY()-k1.DajY())*(k2.DajY()-k1.DajY())+(k2.DajZ()-k1.DajZ())*(k2.DajZ()-k1.DajZ()));
}
int main () {
    int broj;
    std::cout<<"Unesite broj kugla: ";
    for (;;) {
        std::cin>>broj;
        if(broj<=0 || !std::cin) {
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }
        else break;
    }
    std::vector<std::shared_ptr<Kugla>> v(broj);
    for(int i=0; i<broj; i++) {
        double x,y,z,r;
        for(;;) {
            int ispravno(1);
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
            if(!std::cin) {
                std::cout<<"Neispravan centar"<<std::endl;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                ispravno=0;
            }
            else {
                for(;;) {
                    std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
                    std::cin>>r;
                    if(!std::cin ) {
                        std::cout<<"Ilegalan poluprecnik"<<std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        ispravno=0;
                        break;
                    }
                    else break;
                }
            }
            if(ispravno) break;
        }
        try {
            v[i]=std::make_shared<Kugla>(Kugla(x,y,z,r));
        } catch(std::domain_error izuz) {
            std::cout<<izuz.what()<<std::endl;
            i--;
        }
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx,dy,dz;
    for(;;) {
        std::cin>>dx>>dy>>dz;
        if(!std::cin) {
            std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }
        else break; 
    }
    std::transform(v.begin(),v.end(),v.begin(),[dx,dy,dz](std::shared_ptr<Kugla> k) {
        k->Transliraj(dx,dy,dz);
        return k;
    });
    std::sort(v.begin(),v.end(),[](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajZapreminu()<k2->DajZapreminu();
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Kugla> k) {
        k->Ispisi();
    });
    auto najvecapovrsina(std::max_element(v.begin(),v.end(),[](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajPovrsinu()<k2->DajPovrsinu();
    }));
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (*najvecapovrsina)->Ispisi();
    int ima(0);
    std::vector<std::shared_ptr<Kugla>> pomocni(v);
    std::for_each(v.begin(),v.end(), [&pomocni,&ima](std::shared_ptr<Kugla> k) {
        pomocni.erase(pomocni.begin()+0);
        if(pomocni.size()!=0) {
            std::for_each(pomocni.begin(),pomocni.end(),[k,&ima] (std::shared_ptr<Kugla> k1) {
                if(!DaLiSuIdenticne(*k,*k1) && DaLiSeSijeku(*k,*k1)) {
                    ima=1;
                    std::cout<<"Presjecaju se kugle: ";
                    k->Ispisi();
                    k1->Ispisi();
                    //std::cout<<RastojanjeCentara(*k,*k1)<<" "<<k->DajPoluprecnik()+k1->DajPoluprecnik()<<std::endl;
                }
            });
        }
    });
    if(!ima) std::cout<<"Ne postoje kugle koje se presjecaju!";
    return 0;
}