/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <vector>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <memory>
#include <algorithm>
const double pi=4*atan(1);

class Kugla {
    double x,y,z;
    double poluprecnik;
    public:
    explicit Kugla(double r=0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik\n");
        poluprecnik=r;
        x=0; y=0; z=0;
    }
    Kugla(double x1, double y1, double z1, double r=0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik\n");
        else {
            x=x1;
            y=y1;
            z=z1;
            poluprecnik=r;
        }
    }
    explicit Kugla(const std::tuple<double,double,double> &centar, double r=0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik\n");
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        poluprecnik=r;
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double,double,double> DajCentar() const {
        return std::make_tuple(x,y,z); }
    double DajPoluprecnik() const { return poluprecnik; }
    double DajPovrsnu() const { return 4*pi*poluprecnik*poluprecnik; }
    double DajZapreminu() const { return (4/3.)*pi*poluprecnik*poluprecnik*poluprecnik; }
    Kugla &PostaviX(double X) {
        x=X;
        return *this;
    }
    Kugla &PostaviY(double Y) {
        y=Y;
        return *this;
    }
    Kugla &PostaviZ(double Z) {
        z=Z;
        return *this;
    }
    Kugla &PostaviCentar(double X, double Y, double Z) {
        x=X; y=Y; z=Z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple <double, double, double> &centar) {
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik\n");
        poluprecnik=r;
        return *this;
    }
    void Ispisi() const{
        std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl;
    }
    void Transliraj(double delta_x,double delta_y, double delta_z) {
        x=x+delta_x; y=y+delta_y; z=z+delta_z;
    }
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

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return sqrt((k1.DajX()-k2.DajX()) * (k1.DajX()-k2.DajX()) + (k1.DajY()-k2.DajY()) * (k1.DajY()-k2.DajY()) + (k1.DajZ()-k2.DajZ()) * (k1.DajZ()-k2.DajZ()));
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    if(std::abs(k1.DajX()-k2.DajX())<pow(10,-10)*(abs(k1.DajX()) + abs(k2.DajX())) && std::abs(k1.DajY()-k2.DajY())<pow(10,-10)*(abs(k1.DajY()) + abs(k2.DajY())) && std::abs(k1.DajZ()-k2.DajZ())<pow(10,-10)*(abs(k1.DajZ()) + abs(k2.DajZ())) && std::abs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<pow(10,-10)*(abs(k1.DajPoluprecnik()) + abs(k2.DajPoluprecnik())))
    return true;
    else return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    if(std::abs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<pow(10,-10)*(abs(k1.DajPoluprecnik()) + abs(k2.DajPoluprecnik())) );
    else return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    if((k1.DajX()-k2.DajX())<pow(10,-10)*(abs(k1.DajX()) + abs(k2.DajX())) && std::abs(k1.DajY()-k2.DajY())<pow(10,-10)*(abs(k1.DajY()) + abs(k2.DajY())) && std::abs(k1.DajZ()-k2.DajZ())<pow(10,-10)*(abs(k1.DajZ()) + abs(k2.DajZ())))
    return true;
    else return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    if( std::abs((k1.DajPoluprecnik() + k2.DajPoluprecnik()) - RastojanjeCentara(k1,k2)) < pow(10,-10)*(abs(RastojanjeCentara(k1,k2)) + abs ((k1.DajPoluprecnik() + k2.DajPoluprecnik()) ) ) )
    return true;
    else return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    double max_poluprecnik (0), min_poluprecnik(0);
    if( k1.DajPoluprecnik() >= k2.DajPoluprecnik() ) { max_poluprecnik=k1.DajPoluprecnik(); min_poluprecnik=k2.DajPoluprecnik(); }
    else { max_poluprecnik=k2.DajPoluprecnik(); min_poluprecnik=k1.DajPoluprecnik(); }
    double a;
    a=RastojanjeCentara(k1,k2) + min_poluprecnik;
    if(std::abs(a-max_poluprecnik) <= pow(10,-10)*(std::abs(a-max_poluprecnik) + std::abs(0) ))
    return true; else return false;
}
bool Kugla::DaLiSadrzi(const Kugla &k2) const {
    double rastojanje;
    rastojanje=sqrt((x-k2.DajX()) * (x-k2.DajX()) + (y-k2.DajY()) * (y-k2.DajY()) + (z-k2.DajZ()) * (z-k2.DajZ()));
    if(poluprecnik>k2.DajPoluprecnik() && rastojanje+k2.DajPoluprecnik()<poluprecnik ) return true;
    else return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
double rastojanje;
rastojanje=std::sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX()) + (k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY()) + (k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()));
   if(rastojanje <k1.DajPoluprecnik() +k2.DajPoluprecnik() && rastojanje> std::abs(k1.DajPoluprecnik()-k2.DajPoluprecnik() ) )
   return true;
   else return false;
}


bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    if(k1.DaLiSadrzi(k2)==true || k2.DaLiSadrzi(k1) || DaLiSeSijeku(k1,k2)==true)
    return true;
    else return false;
}

int main ()
{ 
    int n;
    double x,y,z,r;
    std::cout<<"Unesite broj kugla: ";
    while(true) {
    std::cin>>n;
    if(n<=0 || !std::cin)  {std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    
    }else break;
    }
    
    std::vector<std::shared_ptr<Kugla>> V(n);
    for(int i=0;i<n;i++) {
            while(true) {
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        
        std::cin>>x>>y>>z;
            
        if( !std::cin)  {std::cout<<"Neispravan centar\n";
    std::cin.clear();
    std::cin.ignore(10000,'\n');
        } else break;
    
            }
        
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if(r<0 || !std::cin) {std::cout<<"Ilegalan poluprecnik\n"; {
            std::cin.clear();
    std::cin.ignore(10000,'\n');
         i-- ; continue; }
        }
        
        
        
    
        try{
            V.at(i)=std::shared_ptr<Kugla>(new Kugla(x,y,z,r));
        } catch (std::domain_error izuzetak) {
            std::cout<<izuzetak.what();
            i--;
        }
    }
    int delta_x,delta_y,delta_z;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    while(true) {
    std::cin>>delta_x>>delta_y>>delta_z;
    if(!std::cin)  {std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    
    }else break;
    }
   transform(V.begin(),V.end(),V.begin() ,[delta_x,delta_y,delta_z] (std::shared_ptr<Kugla> p) {
    p->Transliraj(delta_x,delta_y,delta_z);
    return p;} );
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    sort(V.begin(),V.end(),[] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {
        return p1->DajZapreminu()<p2->DajZapreminu();
   } );
    std::for_each(V.begin(),V.end(), [] (std::shared_ptr<Kugla> p) {
        p->Ispisi();
    } );
    std::cout<<"Kugla sa najvecom povrsinom je: ";
auto A=max_element(V.begin(), V.end(), [V] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {
    return p1->DajPovrsnu()<p2->DajPovrsnu();
} );
(**A).Ispisi();
int i=1;
std::vector<Kugla> V1;
bool DaLiJeIspunjen(false);
for_each(V.begin(),V.end(), [V,&i,&DaLiJeIspunjen](std::shared_ptr<Kugla> p) {
    for_each(V.begin()+i,V.end(), [p,&DaLiJeIspunjen] (std::shared_ptr<Kugla> p1) {
        
        if(DaLiSeSijeku(*p,*p1)==true)  { std::cout<<"Presjecaju se kugle: "; DaLiJeIspunjen=true; (*p).Ispisi(); (*p1).Ispisi(); }
    });
    i++;
});
if(DaLiJeIspunjen==false) std::cout<<"Ne postoje kugle koje se presjecaju!"; 


return 0;
}
