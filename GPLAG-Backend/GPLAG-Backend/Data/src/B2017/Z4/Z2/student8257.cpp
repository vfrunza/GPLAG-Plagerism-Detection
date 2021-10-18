/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

using std::vector;
using std::shared_ptr;
using std::get;

const double pi = 4*std::atan(1);

class NepreklapajucaKugla {
 private: 
    double x, y, z, r;
    static NepreklapajucaKugla* posljednja;
    NepreklapajucaKugla* prethodna;
    
    static bool DaLiSuJednaki(double a , double b)  {
        return fabs(a-b)<=10e-10*(fabs(a)+fabs(b));
    }
    static bool DaLiSuJednaki(const std::tuple<double, double, double> &a, const std::tuple<double, double, double> &b)  { // ovdje su a,b centri kugla
        return DaLiSuJednaki(get<0>(a),get<0>(b)) && DaLiSuJednaki(get<1>(a),get<1>(b)) && DaLiSuJednaki(get<2>(a),get<2>(b));
    }
    static void DaLiSePreklapa(const NepreklapajucaKugla &k);
    
 public:
    // Konstruktori
    explicit NepreklapajucaKugla(double r = 0) : x(0), y(0), z(0), r(r) { 
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        DaLiSePreklapa(*this);   // Finalni test prije stvaranja objekta (naravno ne testiramo prvi objekat)
        prethodna = posljednja;
        posljednja = this;
    }
    NepreklapajucaKugla(double x, double y, double z, double r=0) : x(x), y(y), z(z), r(r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        DaLiSePreklapa(*this);
        prethodna = posljednja;
        posljednja = this;
    }
    explicit NepreklapajucaKugla(const std::tuple<double,double,double> &centar, double r=0) : r(r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        std::tie(x,y,z) = centar;
        prethodna = posljednja;
        posljednja = this;
        DaLiSePreklapa(*this);
    }
    NepreklapajucaKugla(const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla& operator = (const NepreklapajucaKugla &k) = delete;
    
    //Destruktor
    ~NepreklapajucaKugla() {
        NepreklapajucaKugla* p = posljednja;
        NepreklapajucaKugla* izaIzbacene = p;
        while(p!=this) {                // Sve dok ne nadjemo kuglu koja se izbacuje...
            p = p->prethodna;
            if(p==this) break;
            izaIzbacene = p;
        }
        if (this == posljednja)             // Ako izbacujem posljednju kuglu
            posljednja = prethodna;
        else
            izaIzbacene->prethodna = this->prethodna;     // Kuglu iza izbačene spoji sa onom ispred u listi , tako da se lanac ne prekine
        
    }
    
    // Inspektori
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(DajX(),DajY(),DajZ()); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*pi; }
    double DajZapreminu() const { return (4/3)*r*r*r*pi; }
    void Ispisi() const { std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"; }
    
    // Mutatori
    NepreklapajucaKugla &PostaviX(double x) { NepreklapajucaKugla kugla(x,DajY(),DajZ(),DajPoluprecnik()); DaLiSePreklapa(kugla); NepreklapajucaKugla::x = x; return *this; }
    NepreklapajucaKugla &PostaviY(double y) { NepreklapajucaKugla kugla(DajX(),y,DajZ(),DajPoluprecnik()); DaLiSePreklapa(kugla); NepreklapajucaKugla::y = y; return *this; }
    NepreklapajucaKugla &PostaviZ(double z) { NepreklapajucaKugla kugla(DajX(),DajY(),z,DajPoluprecnik()); DaLiSePreklapa(kugla); NepreklapajucaKugla::z = z; return *this; }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        NepreklapajucaKugla kugla(x,y,z,DajPoluprecnik());
        DaLiSePreklapa(kugla);
        NepreklapajucaKugla::x = x; NepreklapajucaKugla::y = y; NepreklapajucaKugla::z = z; return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        NepreklapajucaKugla kugla(centar,DajPoluprecnik());
        DaLiSePreklapa(kugla);
        std::tie(x,y,z) = centar; return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla kugla(DajX(), DajY(), DajZ(), r);
        DaLiSePreklapa(kugla);
        NepreklapajucaKugla::r = r; return *this;
    }
    
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        NepreklapajucaKugla kugla(DajX()+delta_x, DajY()+delta_y , DajZ()+delta_z ,DajPoluprecnik());
        DaLiSePreklapa(kugla);
        x+=delta_x; y+=delta_y; z+=delta_z;
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1,const NepreklapajucaKugla &k2);
};

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return sqrt(pow(k2.DajX()-k1.DajX(),2)+pow(k2.DajY()-k1.DajY(),2)+pow(k2.DajZ()-k1.DajZ(),2));
}
void NepreklapajucaKugla::DaLiSePreklapa(const NepreklapajucaKugla &k) {
    
    auto p_kugla = posljednja;      // p_kugla pokazuje na trenutnu kuglu u listi
    while(p_kugla!=nullptr) {
        if(p_kugla->DajPoluprecnik() + k.DajPoluprecnik() > RastojanjeCentara(*p_kugla,k) || 
            DaLiSuJednaki(p_kugla->DajPoluprecnik() + k.DajPoluprecnik(),RastojanjeCentara(*p_kugla,k))) 
            throw std::logic_error("Nedozvoljeno preklapanje");
        p_kugla=p_kugla->prethodna;
    }
}

NepreklapajucaKugla* NepreklapajucaKugla::posljednja = nullptr;

int main ()
{
    
    std::cout<<"Unesite broj kugli: ";
    int n;
    std::cin>>n;
    while(!std::cin || n<=0) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
            std::cin>>n;
        }
    vector<shared_ptr<NepreklapajucaKugla>> kugle(n);
    
    // Unos kugli
    for(int i=0;i<n;i++) {
        double x,y,z,r;
        std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
        std::cin>>x>>y>>z;
        while(!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Neispravan centar, unesite ponovo:\n";
            std::cin>>x>>y>>z;
        }
        std::cout<<"Unesite poluprecnik: ";
        std::cin>>r;
        while(!std::cin || r<0) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Neispravan poluprecnik, unesite ponovo:\n";
            std::cin>>r;
        }
        try {
            kugle.at(i) = std::make_shared<NepreklapajucaKugla>(x,y,z,r);
        }
        catch(std::domain_error e) {
            std::cout<<e.what()<<"\n";
            i--;
            continue;
        }
        catch(std::logic_error e) {
            std::cout<<e.what()<<"\n";
            i--;
            continue;
        }
    }
    
    std::cout<<"\nKugle nakon obavljenog sortiranja:\n";
    std::sort(kugle.begin(), kugle.end(), [](shared_ptr<NepreklapajucaKugla> k1, shared_ptr<NepreklapajucaKugla> k2)->bool {
       return k1->DajPovrsinu() < k2->DajPovrsinu(); 
    });
    std::for_each(kugle.begin(), kugle.end(), [](const shared_ptr<NepreklapajucaKugla> &k)->void {
        k->Ispisi();
        std::cout<<std::endl;
    });
    
	return 0;
}
