#include <iostream>
#include <tuple>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <iterator>
#define eps 0.0000000001
constexpr double PI(4*atan(1)); 

class Kugla{
 double x,y,z,r;
    public:
    explicit Kugla(double r=0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
    }
    Kugla(double x, double y, double z, double r=0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r=0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=std::get<0>(centar); Kugla::y=std::get<1>(centar); Kugla::z=std::get<2>(centar); Kugla::r=r;
    }
    
    double DajX() const{ return x; }
    double DajY() const{ return y; }
    double DajZ() const{ return z; }
    std::tuple<double, double, double> DajCentar() const{
        std::tuple<double, double, double>c;
        std::get<0>(c)=x; std::get<1>(c)=y; std::get<2>(c)=z;
        return c;
    }
    double DajPoluprecnik() const{ return r; }
    double DajPovrsinu() const{ return 4*r*r*PI; }
    double DajZapreminu() const{ return 4*r*r*r*PI/3; }
    
    Kugla &PostaviX(double x){ Kugla::x=x; return *this; }
    Kugla &PostaviY(double y){ Kugla::y=y; return *this; }
    Kugla &PostaviZ(double z){ Kugla::z=z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z){ Kugla::x=x; Kugla::y=y; Kugla::z=z; return *this; }
    Kugla &PostaviCentar(std::tuple<double, double, double> &centar){
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); return *this; 
    }
    Kugla &PostaviPoluprecnik(double r){ if(r<0) throw std::domain_error("Ilegalan poluprecnik"); Kugla::r=r; return *this; }
    
    void Ispisi() const{ std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"; }
    void Transliraj(double delta_x, double delta_y, double delta_z){ x+=delta_x; y+=delta_y; z+=delta_z; }
    
 friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2); 
 friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
 friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
 friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
 friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
 friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2); 
 friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k);
 friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    return (fabs(k1.x-k2.x)<eps && fabs(k1.y-k2.y)<eps && fabs(k1.z-k2.z)<eps && fabs(k1.r-k2.r)<eps);
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    return fabs(k1.r-k2.r)<eps;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    return (fabs(k1.x-k2.x)<eps && fabs(k1.y-k2.y)<eps && fabs(k1.z-k2.z)<eps);
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    double d(RastojanjeCentara(k1,k2));
    return(d<(k1.r+k2.r) && d>fabs(k1.r-k2.r));
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    double d(RastojanjeCentara(k1,k2));
    return (fabs(d-k1.r-k2.r)<eps);
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    double d(RastojanjeCentara(k1,k2)), dr(fabs(k1.r-k2.r));
    return (fabs(d-dr)<eps);
}

bool Kugla::DaLiSadrzi(const Kugla &k){
    double d(RastojanjeCentara(*this,k)), dr(fabs(this->r-k.r));
    return d<dr;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    double d(RastojanjeCentara(k1,k2)), dr(fabs(k1.r-k2.r));
    return d<dr;
}

int main ()
{
    Kugla k(0,0,0);
    int n(0);
    std::cout<<"Unesite broj kugla: ";
    do{
    std::cin>>n;
    if(!std::cin || n<=0){
        std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    }while(n<=0 || !std::cin);
    std::vector<std::shared_ptr<Kugla>>vp;
    vp.resize(n);
    int i(0);
        double x(0),y(0),z(0),r(0);
        do{
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        while(!std::cin){
        std::cout<<"Neispravan centar\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        }
        try{
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
            k.PostaviX(x).PostaviY(y).PostaviZ(z);
            
                k.PostaviPoluprecnik(r);
                vp[i]=std::make_shared<Kugla>(k);
                i++;
            }catch(std::domain_error izuzetak){
                std::cout<<izuzetak.what()<<std::endl;
            }
        }while(i<n || r<0 || !std::cin);
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double a(0),b(0),c(0);
    std::cin>>a>>b>>c;
    std::transform(std::begin(vp), std::end(vp), std::begin(vp), [a,b,c](std::shared_ptr<Kugla> k){ k->Transliraj(a,b,c); return k; });
    std::sort(std::begin(vp), std::end(vp), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){ return k1->DajZapreminu()<k2->DajZapreminu();});
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    for(int i=0; i<n; i++){
        (*vp[i]).Ispisi();
        std::cout<<std::endl;
    }
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto km(std::max_element(std::begin(vp), std::end(vp), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){ return k1->DajPovrsinu()<k2->DajPovrsinu(); }));
    (**km).Ispisi();
    auto it=vp;
    if(std::distance(std::begin(vp),std::end(vp))==1) std::cout<<"\nNe postoje kugle koje se presjecaju!";
std::for_each(std::begin(vp), std::end(vp), [it](std::shared_ptr<Kugla> k){ 
    int brojac(std::distance(std::begin(it),std::find(std::begin(it),std::end(it),k))+1);
    return std::for_each(std::begin(it)+(brojac++), std::end(it),[k,brojac,it](std::shared_ptr<Kugla> k1){ if(DaLiSeSijeku(*k1, *k)){ std::cout<<"\nPresjecaju se kugle: "; k->Ispisi(); std::cout<<std::endl; k1->Ispisi();}
    else if(DaLiSeSijeku(*k,*k1)==0 && DaLiSuIdenticne(*k,*k1)==0 && brojac==std::distance(std::begin(it),std::end(it))-1) std::cout<<"\nNe postoje kugle koje se presjecaju!"; }); });
	return 0;
}
