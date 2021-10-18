/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

#define PI (4*std::atan(1))
#define e std::pow(10,-10)
class Kugla {
    double x,y,z,r;
    void TestirajPoluprecnik(double r){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    }
public:
    explicit Kugla(double r = 0){TestirajPoluprecnik(r); x=y=z=r;}
    Kugla(double x, double y, double z, double r = 0){TestirajPoluprecnik(r); this->x=x; this->y=y; this->z=z; this->r=r;}
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
        TestirajPoluprecnik(r);
        std::tie(x,y,z)=centar;
    }
    double DajX() const{return x;}
    double DajY() const{return y;}
    double DajZ() const{return z;}
    std::tuple<double, double, double> DajCentar() const {
        std::tuple<double,double,double> t; t=std::make_tuple(x,y,z); return t;}
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return ((4/3)*r*r*r*PI);}
    double DajZapreminu() const {return ((4*r*r*r*PI)/3);}
    Kugla &PostaviX(double x) {this->x=x; return *this;}
    Kugla &PostaviY(double y) {this->y=y; return *this;}
    Kugla &PostaviZ(double z) {this->z=z; return *this;}
    Kugla &PostaviCentar(double x, double y, double z) { this->x=x; this->y=y; this->z=z; return *this;}
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {std::tie(x,y,z)=centar; return *this;}
    Kugla &PostaviPoluprecnik(double r) {TestirajPoluprecnik(r); this->r=r; return *this;}
    void Ispisi() const {std::cout<<"{("<<x<<","<<y<<","<<z<<"),{"<<r<<"}";}
    void Transliraj(double delta_x, double delta_y, double delta_z){x+=delta_x; y+=delta_y; z+=delta_z;}
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
        return (std::sqrt(((k1.x-k2.x)*(k1.x-k2.x))+((k1.y-k2.y)*(k1.y-k2.y))+((k1.z-k2.z)*(k1.z-k2.z))));
    }
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    
    if(DaLiSuPodudarne(k1,k2) && DaLiSuKoncentricne(k1,k2)) return true;
    return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    if(std::abs(k1.r-k2.r) < (e*(std::abs(k1.r)+std::abs(k2.r)))) return true;
    else return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    bool po_x(std::abs(k1.x-k2.x) < (e*(std::abs(k1.x)+std::abs(k2.x))));
    bool po_y(std::abs(k1.y-k2.y) < (e*(std::abs(k1.y)+std::abs(k2.y))));
    bool po_z(std::abs(k1.z-k2.z) < (e*(std::abs(k1.z)+std::abs(k2.z))));
    if(po_x && po_y && po_z) return true;
    return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    
    //Ako su identicne ili koncetricne onda se dodiruju u beskocano mnogo tacaka a ne samo u jednoj ili se ne dodiruju uopste
    if(DaLiSuIdenticne(k1,k2) || DaLiSuKoncentricne(k1,k2)) return false;
    
    //Ako je udaljenost izmedju centara jednaka zbiru poluprecnika onda se sigurno dodiruju u samo jednoj tacki
    if(std::abs(RastojanjeCentara(k1,k2)-(k1.r+k2.r)) < (e*(std::abs(RastojanjeCentara(k1,k2))+std::abs(k1.r+k2.r)))) return true;
    else return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
        //Ako su identicne ili koncentricne onda se dodiruju u beskonacno mnogo tacaka a ne samo u jednoj ili se nikako ne dodiruju
        if(DaLiSuIdenticne(k1,k2) || DaLiSuKoncentricne(k1,k2)) return false;
        
        //Kugla k2 unutar kugle k1
        if((k2.x<(k1.x+k1.r) || k2.x>(k1.x-k1.r)) && (k2.y<(k1.y+k1.r) || k2.y>(k1.y-k1.r)) && (k2.z<(k2.z+k1.r) || k2.z>(k2.z-k1.r))){
            if(std::abs((k1.r-RastojanjeCentara(k1,k2))-k2.r) < (e*(std::abs(k1.r-RastojanjeCentara(k1,k2))+std::abs(k2.r)))) return true;
        }
        
        //Kugla k1 unutar kugle k2
        if((k1.x<(k2.x+k2.r) || k1.x>(k2.x-k2.r)) && (k1.y<(k2.y+k2.r) || k1.y>(k2.y-k2.r)) && (k1.z<(k2.z+k2.r) || k1.z>(k2.z-k2.r))){
            if(std::abs((k2.r-RastojanjeCentara(k1,k2))-k1.r) < (e*(std::abs(k2.r-RastojanjeCentara(k1,k2))+std::abs(k1.r)))) return true;
        }
        
        return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    return true;

}

int main () {
    
    int n;
    bool dobar_unos;
    std::cout<<"Unesite broj kugla: ";
    do{
        std::cin>>n;
        dobar_unos=false;
        if(!std::cin || n<=0){
            dobar_unos=true;
            std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }
    }
    while(dobar_unos);
    std::vector<std::shared_ptr<Kugla>> v(n);
    for(int i=0;i<n;i++){
        double x,y,z,r;
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        if(!std::cin){
            std::cout<<"Neispravan centar\n";
            i--;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
            
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if(r<0){
            std::cout<<"Ilegalan poluprecnik\n";
            i--;
            continue;
        }
        v[i]=std::make_shared<Kugla> (x,y,z,r);
    }
    int d_x, d_y, d_z;
    while(1){
        std::cout<<"Unesite parametre transformacije (delta_x,delta_y,delta_z): ";
        std::cin>>d_x>>d_y>>d_z;
        if(!std::cin){
            std::cout<<"Niste unijeli broj, pokusajte ponovo\n";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            continue;
        }
        else break;
    }
    
    std::transform(v.begin(),v.end(),v.begin(),[&d_x, &d_y, &d_z](std::shared_ptr<Kugla> p){p->Transliraj(d_x,d_y,d_z); return p;});
    
    std::cout<<"Kugle nakon obavljene transformacije imaju sljedece vrijednosti: \n";
    std::sort(v.begin(),v.end(),[] (std::shared_ptr<Kugla> k1,const std::shared_ptr<Kugla> k2){return (k1->DajZapreminu() < k2->DajZapreminu());});
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Kugla> p){ p->Ispisi(); std::cout<<std::endl;});
    
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    std::shared_ptr<Kugla> p = *(std::max_element(v.begin(),v.end(),[](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){return (k1->DajPovrsinu() < k2->DajPovrsinu());}));
    p->Ispisi();
    std::cout<<std::endl;
    
    return 0;
}
