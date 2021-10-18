/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath> 
#include <vector>
#include <memory>
#include <algorithm>

class NepreklapajucaKugla {
  double x, y, z, r;
  static constexpr double e=0.0000000001;
  bool DaLiSePreklapaju(double x, double y, double z, double r);
  NepreklapajucaKugla *kraj=nullptr;
  NepreklapajucaKugla *veza=nullptr;
public:
    explicit NepreklapajucaKugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        if(DaLiSePreklapaju(0,0,0,r)) throw std::logic_error("Nedozvoljeno preklapanje");
        veza=kraj;
        kraj=new NepreklapajucaKugla(0,0,0,r);
    }
    NepreklapajucaKugla(double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        if(DaLiSePreklapaju(x,y,z,r)) throw std::logic_error("Nedozvoljeno preklapanje");
        veza=kraj;
        NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z; NepreklapajucaKugla::r=r; 
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); NepreklapajucaKugla::r=r; 
    }
    
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::tie(x,y,z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*4*atan(1); }
    double DajZapreminu() const { return (4*r*r*r*4*atan(1))/3; }
    void Ispisi() const { std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl; }

    NepreklapajucaKugla &PostaviX(double x) { NepreklapajucaKugla::x=x; return *this; }
    NepreklapajucaKugla &PostaviY(double y) { NepreklapajucaKugla::y=y; return *this; }
    NepreklapajucaKugla &PostaviZ(double z) { NepreklapajucaKugla::z=z; return *this; }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) { NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::y=y; return *this; }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) { if(r<0) throw std::domain_error("Ilegalan poluprecnik"); NepreklapajucaKugla::r=r; return *this; }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) { NepreklapajucaKugla::x=std::get<0>(centar); NepreklapajucaKugla::y=std::get<1>(centar); NepreklapajucaKugla::z=std::get<2>(centar); return *this; }

    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    ~NepreklapajucaKugla() {
        if(kraj==this) kraj=this->veza;
        else if(this->veza==nullptr) {
            auto it(kraj);
            while(it->veza!=this) it=it->veza;
            delete this;
            it=nullptr;
        }
        else {
            auto it(kraj);
            while(it->veza!=this) it=it->veza;
            it->veza=this->veza;
            delete this;
        }
    }
};

bool NepreklapajucaKugla::DaLiSePreklapaju(double x, double y, double z, double r) {
    if(!kraj) return false;
    for(auto it=kraj; it!=nullptr; it=it->veza) {
        double rastojanje_centara(std::sqrt((x-it->DajX())*(x-it->DajX())+(y-it->DajY())*(y-it->DajY())+(z-it->DajZ())*(z-it->DajZ())));
        if((rastojanje_centara+it->DajPoluprecnik())<r) return true;
        else if(rastojanje_centara+r<it->DajPoluprecnik()) return true;
    }
    return false;
}


double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return std::sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()));
}

int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    while(!std::cin || n<=0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin>>n;
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> v(n);
    double a, b, c, R;
    for(int i=0; i<n; i++) {
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>a>>b>>c;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Neispravan centar"<<std::endl;
            i--;
            continue;
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>R;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            i--;
            continue;
        }
        try {
            auto pom(std::make_shared<NepreklapajucaKugla>(a,b,c,R));
            v[i]=pom;
        } 
        catch(std::domain_error izz) {
            std::cout<<izz.what()<<std::endl;
            i--;
        }
        catch(std::logic_error izz) {
            std::cout<<izz.what()<<std::endl;
            i--;
        }
    }
    std::sort(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> pok1, std::shared_ptr<NepreklapajucaKugla> pok2) { return pok1->DajPovrsinu()<pok2->DajPovrsinu(); });
    std::cout<<"Kugle nakon obavljenog sortiranja: "<<std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> pok) { pok->Ispisi(); });
    auto najj(std::max_element(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> pok1, std::shared_ptr<NepreklapajucaKugla> pok2) { return pok1->DajPovrsinu()<pok2->DajPovrsinu(); }));
    if(najj==v.end()) std::cout<<"Ne postoji kugla s najvecom povrsinom!"<<std::endl;
    else {
        std::cout<<"Kugla sa najvecom povrsinom je: "; 
        (*najj)->Ispisi(); 
    }
	return 0;
}