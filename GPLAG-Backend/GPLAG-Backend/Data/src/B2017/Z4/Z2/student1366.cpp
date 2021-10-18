/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <algorithm>
#include <memory>
#include <vector>
#include <iomanip>

class NepreklapajucaKugla {
    double x,y,z,r;
    static constexpr double PI{4*atan(1.)};
    static bool DaliSuJednaki(double x1, double x2) { return fabs(x1-x2)<=pow(10,-10)*(fabs(x1)+fabs(x2)); }
    static bool DaLiJeCentarUnutar(double x,double y, double z, double x2, double y2, double z2, double r2);
    static bool DaLiJeCentarIzvan(double x, double y, double z, double x2, double y2, double z2, double r2);
    static bool DaLiSePreklapaju(double x, double y, double z, double r, const NepreklapajucaKugla &k2);
    static bool DaLiSeSijeku(double x, double y, double z, double r, const NepreklapajucaKugla &k2);
    static double RastojanjeCentara(double x, double y, double z, const NepreklapajucaKugla &k2);
    static double RastojanjeCentara(double x, double y, double z, double x2, double y2, double z2);
    static void TestPreklapanja(double x, double y, double z, double r);
    static NepreklapajucaKugla* pokNaKraj;
    NepreklapajucaKugla* prethodni;
public:
    explicit NepreklapajucaKugla(double r=0);
    NepreklapajucaKugla(double x, double y, double z, double r=0);
    explicit NepreklapajucaKugla(const std::tuple<double,double,double> &centar, double r=0);
    ~NepreklapajucaKugla();
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    NepreklapajucaKugla(NepreklapajucaKugla &&k);
    NepreklapajucaKugla& operator =(NepreklapajucaKugla &&k);
    NepreklapajucaKugla(const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla& operator =(const NepreklapajucaKugla &k) = delete;
    std::tuple<double,double,double> DajCentar() const { return std::make_tuple(x,y,z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*PI; }
    double DajZapreminu() const { return 4*r*r*r*PI/3; }
    NepreklapajucaKugla &PostaviX(double x) { TestPreklapanja(x,y,z,r); NepreklapajucaKugla::x=x; return *this; }
    NepreklapajucaKugla &PostaviY(double y) { TestPreklapanja(x,y,z,r); NepreklapajucaKugla::y=y; return *this; }
    NepreklapajucaKugla &PostaviZ(double z) { TestPreklapanja(x,y,z,r); NepreklapajucaKugla::z=z; return *this; }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z);
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double,double,double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r);
    void Ispisi() const { std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl; }
    void Transliraj(double delta_x, double delta_y, double delta_z);
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};
NepreklapajucaKugla* NepreklapajucaKugla::pokNaKraj=nullptr;

int main()
{
    std::cout<<"Unesite broj kugli: ";
    int brojkugla;
    std::cin>>brojkugla;
    if (!std::cin || brojkugla<=0) {
        do {
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cin>>brojkugla;
        }while(brojkugla<=0 || !std::cin); 
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> VektorKugli(brojkugla);
    for (int i=0;i<brojkugla;i++) {
        std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
        double x,y,z;
        std::cin>>x>>y>>z;
        if (!std::cin) {
            do {
                std::cout<<"Neispravan centar, unesite ponovo: "<<std::endl;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cin>>x>>y>>z;
            } while (!std::cin);
        }
        std::cout<<"Unesite poluprecnik: ";
        double r;
        std::cin>>r;
        if (r<0 || !std::cin) {
            do {
            std::cout<<"Neispravan poluprecnik, unesite ponovo: "<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cin>>r;
            }while(!std::cin || r<0);
        }
        try {
        VektorKugli.at(i)=std::make_shared<NepreklapajucaKugla>(x,y,z,r);
        }
        catch(std::logic_error err) {
            std::cout<<err.what()<<std::endl; i--;
        }
    }
    std::sort(VektorKugli.begin(),VektorKugli.end(),[](std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2) { return k1->DajPovrsinu()<k2->DajPovrsinu();});
    std::cout<<std::endl<<"Kugle nakon obavljenog sortiranja: "<<std::endl;
    std::for_each(VektorKugli.begin(), VektorKugli.end(),[](std::shared_ptr<NepreklapajucaKugla> k1){ k1->Ispisi(); });
	return 0;
}

//IMPLEMENTACIJA
NepreklapajucaKugla::NepreklapajucaKugla(double r) {
    if (r<0) throw std::domain_error("Ilegalan poluprecnik");
    TestPreklapanja(0,0,0,r);
    if (!pokNaKraj) { pokNaKraj=this; prethodni=nullptr; }
    else { prethodni=pokNaKraj; pokNaKraj=this; }
    x=0;y=0;z=0;NepreklapajucaKugla::r=r;
}
NepreklapajucaKugla::NepreklapajucaKugla(double x, double y, double z, double r) {
    if (r<0) throw std::domain_error("Ilegalan poluprecnik");
    TestPreklapanja(x,y,z,r);
    if (!pokNaKraj) { pokNaKraj=this; prethodni=nullptr; }
    else { prethodni=pokNaKraj; pokNaKraj=this; }
    NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z; NepreklapajucaKugla::r=r;
}
NepreklapajucaKugla::NepreklapajucaKugla(const std::tuple<double,double,double> &centar, double r) {
    if (r<0) throw std::domain_error("Ilegalan poluprecnik");
    TestPreklapanja(std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),r);
    if (!pokNaKraj) { pokNaKraj=this; prethodni=nullptr; }
    else { prethodni=pokNaKraj; pokNaKraj=this; }
    x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); NepreklapajucaKugla::r=r;
} 
NepreklapajucaKugla& NepreklapajucaKugla::PostaviCentar(double x, double y, double z) {
    TestPreklapanja(x,y,z,r);
    NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z; return *this;
}
NepreklapajucaKugla& NepreklapajucaKugla::PostaviCentar(const std::tuple<double,double,double> &centar) {
    TestPreklapanja(std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),r);
    x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); return *this; 
}
NepreklapajucaKugla& NepreklapajucaKugla::PostaviPoluprecnik(double r) { 
    if (r<0) throw std::domain_error("Ilegalan poluprecnik");
    TestPreklapanja(x,y,z,r);
    NepreklapajucaKugla::r=r; return *this; 
}
void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z) {
    TestPreklapanja(x+delta_x,y+delta_y,z+delta_z,r);
    x+=delta_x; y+=delta_y; z+=delta_z;
}
bool NepreklapajucaKugla::DaLiJeCentarUnutar(double x,double y, double z, double x2, double y2, double z2, double r2) {
    return (RastojanjeCentara(x,y,z,x2,y2,z2)<r2 || DaliSuJednaki(RastojanjeCentara(x,y,z,x2,y2,z2),r2));
}
bool NepreklapajucaKugla::DaLiJeCentarIzvan(double x, double y, double z, double x2, double y2, double z2, double r2) {
    return ((x>=x2+r2 || x<=x2-r2) || (y>=y2+r2 || y<=y2-r2) || (z>=z2+r2 || z<=z2-r2));
}
double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2));
}
bool NepreklapajucaKugla::DaLiSePreklapaju(double x, double y, double z, double r, const NepreklapajucaKugla &k2) {
    return (NepreklapajucaKugla::DaLiJeCentarUnutar(x,y,z,k2.x,k2.y,k2.z,k2.r) || NepreklapajucaKugla::DaLiJeCentarUnutar(k2.x,k2.y,k2.z,x,y,z,r) || DaLiSeSijeku(x,y,z,r,k2));
}
bool NepreklapajucaKugla::DaLiSeSijeku(double x, double y, double z, double r, const NepreklapajucaKugla &k2) {
    bool logicka(false);
    if (NepreklapajucaKugla::DaLiJeCentarUnutar(x,y,z,k2.x,k2.y,k2.z,k2.r)) {
        logicka=(r+RastojanjeCentara(x,y,z,k2)>k2.r || DaliSuJednaki(r+RastojanjeCentara(x,y,z,k2),k2.r));
    }
    else if (NepreklapajucaKugla::DaLiJeCentarUnutar(k2.x,k2.y,k2.z,x,y,z,r)) {
        logicka=(k2.r+RastojanjeCentara(x,y,z,k2)>r || DaliSuJednaki(k2.r+RastojanjeCentara(x,y,z,k2),r));
    }
    else 
        logicka=(RastojanjeCentara(x,y,z,k2)<r+k2.r || DaliSuJednaki(RastojanjeCentara(x,y,z,k2),r+k2.r));
    return logicka;
}
void NepreklapajucaKugla::TestPreklapanja(double x, double y, double z, double r) {
    for (auto pok=NepreklapajucaKugla::pokNaKraj;pok!=nullptr;pok=pok->prethodni) {
        if (DaLiSePreklapaju(x,y,z,r,*pok)) throw std::logic_error("Nedozvoljeno preklapanje");
    }
}
double NepreklapajucaKugla::RastojanjeCentara(double x, double y, double z, const NepreklapajucaKugla &k2) {
    return sqrt(pow(k2.x-x,2)+pow(k2.y-y,2)+pow(k2.z-z,2));
}
NepreklapajucaKugla::~NepreklapajucaKugla() {
    if (pokNaKraj==this) pokNaKraj=this->prethodni;
    else {
        NepreklapajucaKugla* pok;
        for (pok=pokNaKraj;pok->prethodni!=this;pok=pok->prethodni);
        pok->prethodni=this->prethodni;
    }
}
double NepreklapajucaKugla::RastojanjeCentara(double x, double y, double z, double x2, double y2, double z2) {
    return sqrt(pow(x2-x,2)+pow(y2-y,2)+pow(z2-z,2));
}
NepreklapajucaKugla::NepreklapajucaKugla(NepreklapajucaKugla &&k) {
    TestPreklapanja(k.DajX(),k.DajY(),k.DajZ(),k.DajPoluprecnik());
    *this=std::move(k);
}
NepreklapajucaKugla& NepreklapajucaKugla::operator =(NepreklapajucaKugla &&k) {
    TestPreklapanja(k.DajX(),k.DajY(),k.DajZ(),k.DajPoluprecnik());
    *this=std::move(k);
    return *this;
}