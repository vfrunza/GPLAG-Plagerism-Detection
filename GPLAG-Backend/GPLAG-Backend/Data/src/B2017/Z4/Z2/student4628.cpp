/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double pi(4*atan(1));
const double eps(1e-10);

class NepreklapajucaKugla {
    double x,y,z,r;
    NepreklapajucaKugla* prethodni{};
    static NepreklapajucaKugla* posljednji;
    bool DaLiSePoklapa(const NepreklapajucaKugla &k);
    void Obrisi(NepreklapajucaKugla &k);
    public:
    explicit NepreklapajucaKugla(double r = 0) {
        x=0; y=0; z=0;
        r=0;
        if(DaLiSePoklapa(*this)) {
            Obrisi(*this);
            throw std::logic_error("Nedozvoljeno preklapanje");
            
        }
        else {
            prethodni=posljednji;
            posljednji=this;
        }    
    }
    
    NepreklapajucaKugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik\n");
        NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
        prethodni=posljednji;
            posljednji=this;
        if(DaLiSePoklapa(*this)) {
            Obrisi(*this);    
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        else  {
            
        }
    }
    
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik\n");
        double a,b,c;
        std::tie(a,b,c)=centar;
        x=a; y=b; z=c; 
        NepreklapajucaKugla::r=r;
        if(DaLiSePoklapa(*this)){ 
            Obrisi(*this);
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        else { prethodni=posljednji;
        posljednji=this;}
        }
    ~NepreklapajucaKugla()=default;
    NepreklapajucaKugla(const NepreklapajucaKugla &k)=delete;
    NepreklapajucaKugla &operator =(const NepreklapajucaKugla &k)=delete;
    double DajX() const;
    double DajY() const;
    double DajZ() const;
    std::tuple<double, double, double> DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    NepreklapajucaKugla &PostaviX(double x);
    NepreklapajucaKugla &PostaviY(double y);
    NepreklapajucaKugla &PostaviZ(double z);
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z);
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

NepreklapajucaKugla* NepreklapajucaKugla::posljednji(nullptr);

double NepreklapajucaKugla::DajX() const { return x; }

double NepreklapajucaKugla::DajY() const { return y; }

double NepreklapajucaKugla::DajZ() const { return z; }

std::tuple<double, double, double> NepreklapajucaKugla::DajCentar() const {
    return std::make_tuple(x,y,z);
}

double NepreklapajucaKugla::DajPoluprecnik() const { return r; }

double NepreklapajucaKugla::DajPovrsinu() const { return 4*pi*r*r; }

double NepreklapajucaKugla::DajZapreminu() const {
    return (4/3.*std::pow(r,3)*pi);
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviX(double x) {
    NepreklapajucaKugla::x=x;
    if(DaLiSePoklapa(*this)){ 
        Obrisi(*this);
        throw std::logic_error("Nedozvoljeno preklapanje");
        
    }
    else { prethodni=posljednji; posljednji=this; };
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviY(double y) {
    NepreklapajucaKugla::y=y;
    if(DaLiSePoklapa(*this)){ 
        Obrisi(*this);
        throw std::logic_error("Nedozvoljeno preklapanje");
       
    }
    else { prethodni=posljednji; posljednji=this; };
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviZ(double z) {
    NepreklapajucaKugla::z=z;
    if(DaLiSePoklapa(*this)){ 
        Obrisi(*this);
        throw std::logic_error("Nedozvoljeno preklapanje");
        
    }
    else { prethodni=posljednji; posljednji=this; };
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(double x, double y, double z) {
    NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z;
    if(DaLiSePoklapa(*this)){
        Obrisi(*this);
        throw std::logic_error("Nedozvoljeno preklapanje");
        
    }
    else { prethodni=posljednji; posljednji=this;  };
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(const std::tuple<double, double, double> &centar) {
    double a,b,c;
    std::tie(a,b,c)=centar;
    PostaviCentar(a,b,c);
    if(DaLiSePoklapa(*this)){ 
         Obrisi(*this);
        throw std::logic_error("Nedozvoljeno preklapanje");
       
    }
    else { prethodni=posljednji; posljednji=this; };
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviPoluprecnik(double r) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik\n");
    NepreklapajucaKugla::r=r;
    if(DaLiSePoklapa(*this)){ 
        Obrisi(*this);
        throw std::logic_error("Nedozvoljeno preklapanje");
      
    }
    else { prethodni=posljednji; posljednji=this; };
    return *this;
}

void NepreklapajucaKugla::Ispisi() const {
    std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl;
}

void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z) {
    x+=delta_x; y+=delta_y; z+=delta_z;
}

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return std::sqrt(std::pow(k1.x-k2.x,2)+std::pow(k1.y-k2.y,2)+std::pow(k1.z-k2.z,2));
}

bool NepreklapajucaKugla::DaLiSePoklapa(const NepreklapajucaKugla &k) {
    if(posljednji==nullptr) return 0;
    if(prethodni==nullptr) return 0;
  
    for(auto p=prethodni; p!=nullptr; p=p->prethodni) {
       if(RastojanjeCentara(*p, k)-k.r<=p->DajPoluprecnik()) return 1;
    }
    return 0;
}



void NepreklapajucaKugla::Obrisi( NepreklapajucaKugla &k) {
    posljednji=prethodni;
    if(prethodni==nullptr) prethodni=nullptr;
   else { prethodni=prethodni->prethodni; }
}


int main() {
    std::cout<<"Unesite broj kugli: ";
    int n;
    std::cin>>n;while(n<=0 || !std::cin || int(n)!=n) {
        std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin>>n;
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> kugle;
   double unos[4];
    for(int i=0; i<n; i++) {
        std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
            for(int j=0; j<3; j++) {
                std::cin>>unos[j];
                if(!std::cin) {
                    std::cout<<"Neispravan centar, unesite ponovo:\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    j=-1;
                }
                }
       
        std::cout<<"Unesite poluprecnik: ";
        std::cin>>unos[3];
        while(!std::cin || unos[3]<0) {
            std::cout << "Neispravan poluprecnik, unesite ponovo:" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin>>unos[3];
        }
        
    try {
        auto pok(std::make_shared<NepreklapajucaKugla>(unos[0], unos[1], unos[2], unos[3]));
        kugle.push_back(pok);
    }
    catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
        
    }
    catch(std::bad_alloc ) {
        std::cout<<"Nedovoljno memorije";
    }
    catch(std::logic_error izuzetak2) {
        std::cout<<izuzetak2.what()<<std::endl;
        i--;
    }
    }
    
    
    std::sort(kugle.begin(), kugle.end(), [] (std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2) {
        return k1->DajPovrsinu()<k2->DajPovrsinu();
    });
    
    std::cout<<"\nKugle nakon obavljenog sortiranja: "<<std::endl;
    std::for_each(kugle.begin(), kugle.end(), [] (std::shared_ptr<NepreklapajucaKugla> k) {
        k->Ispisi();
    });
 

    return 0;
}


