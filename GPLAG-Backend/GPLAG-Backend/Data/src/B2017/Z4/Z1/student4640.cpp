#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>


const double PI (4*atan(1));
const double EPS (1e-10);

class Kugla {
    double x,y,z,r;
//    bool MoguFormiratiTrougao (const Kugla &k1, const Kugla &k2);
//      bool DaLiSeNalaziUVektoru (std::vector<std::pair<Kugla,Kugla>>kugle, std::pair<Kugla,Kugla>par);
    
    public:
    
    explicit Kugla (double r=0) {
        x=0;
        y=0;
        z=0;
        Kugla::r=r;
    }
    
    Kugla (double x, double y, double z, double r=0) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    
    explicit Kugla (const std::tuple<double,double,double> &centar, double r=0) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2> (centar);
        Kugla::r=r;
    }
    
    double DajX () const { return x; }
    double DajY () const { return y; }
    double DajZ () const { return z; }
    
    std::tuple<double, double, double> DajCentar () const {
        std::tuple<double, double, double> novi;
        std::get<0>(novi) = x;
        std::get<1>(novi) = y;
        std::get<2>(novi) = z;
        return novi;
    }
    
    double DajPoluprecnik () const { return r; }
    
    double DajPovrsinu () const { return 4*PI*r*r; }
    
    double DajZapreminu () const { return 4/3.*r*r*r*PI; }
    
    Kugla &PostaviX (double x) { 
        Kugla::x = x;
        return *this; 
    }
    
    Kugla &PostaviY (double y)  {
        Kugla::y = y;
        return *this;
    }
    
    Kugla &PostaviZ (double z) {
        Kugla::z = z;
        return *this;
    }
    
    Kugla &PostaviCentar (double x, double y, double z) {
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
        return *this;
    }
    
    Kugla &PostaviCentar (std::tuple<double,double,double> &centar) {
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2> (centar);
        return *this;
    }
    
    Kugla &PostaviPoluprecnik (double r) {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    
    void Ispisi () const { std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"; }
    
    void Transliraj (double delta_x, double delta_y, double delta_z) {
        x += delta_x;
        y += delta_y;
        z += delta_z;
    }
    
    friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi (const Kugla &k) const;
    friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2);
        
};

bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2) {
    return (std::fabs(k1.x-k2.x)<EPS*(std::fabs(k1.x)+std::fabs(k1.y)) && std::fabs(k1.y-k2.y)<EPS*(std::fabs(k1.y)+std::fabs(k2.y)) && 
    std::fabs(k1.z-k2.z)<EPS*(std::fabs(k1.z)+std::fabs(k2.z)) && std::fabs(k1.r-k2.r)<EPS*(std::fabs(k1.r)+std::fabs(k2.r)));
}

bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2) {
    return std::fabs(k1.r-k2.r)<EPS*(std::fabs(k1.r)+std::fabs(k2.r));
}

bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2) {
    return (std::fabs(k1.x-k2.x)<EPS*(std::fabs(k1.x)+std::fabs(k2.x)) && std::fabs(k1.y-k2.y)<EPS*(std::fabs(k1.y)+std::fabs(k2.y)) && 
    std::fabs(k1.z-k2.z)<EPS*(std::fabs(k1.z)+std::fabs(k2.z)));
}

double RastojanjeCentara (const Kugla &k1, const Kugla &k2) {
     return ((std::sqrt(std::pow(k2.x-k1.x, 2) + std::pow(k2.y-k1.y, 2) + std::pow(k2.z-k1.z, 2))) - k1.r - k2.r);
}

bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2) {
    return (std::fabs(k2.r + k1.r - RastojanjeCentara(k1,k2)) < EPS* (std::fabs(k2.r+k1.r) + std::fabs(RastojanjeCentara(k1,k2))));
}

bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2) {
    return std::fabs(k2.r-k1.r-RastojanjeCentara(k1,k2) < EPS* (std::fabs(k2.r-k1.r) + std::fabs(RastojanjeCentara(k1,k2))));
}

/*bool Kugla::MoguFormiratiTrougao (const Kugla &k1, const Kugla &k2) {
    return ((k1.r + k2.r > RastojanjeCentara(k1,k2)) && (k1.r + RastojanjeCentara(k1,k2) > k2.r) && (k2.r + RastojanjeCentara(k1,k2) > k1.r));
}*/

bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2) {
//    return ((k1.r + k2.r > RastojanjeCentara(k1,k2)) && (k1.r + RastojanjeCentara(k1,k2) > k2.r) && (k2.r + RastojanjeCentara(k1,k2) > k1.r));
    return (((std::fabs(k1.x-k2.x)<EPS*(std::fabs(k1.x)+std::fabs(k2.x))) && (std::fabs(k1.y-k2.y)<EPS*(std::fabs(k1.y)+std::fabs(k2.y))) && 
    (std::fabs(k1.z-k2.z)<EPS*(std::fabs(k1.z)+std::fabs(k2.z))) && (std::fabs(k1.r-k2.r)<EPS*(std::fabs(k1.r)+std::fabs(k2.r)))) ||
    (k1.r+k2.r>RastojanjeCentara(k1,k2) && RastojanjeCentara(k1,k2)>std::fabs(k1.r-k2.r)));
}

bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2) {
    return (DaLiSeSijeku(k1,k2));
}

bool Kugla::DaLiSadrzi (const Kugla &k) const {
    return (k.x < x && k.y < y && k.z < z && k.DajZapreminu() < DajZapreminu());
}

bool DaLiSeNalaziUVektoru (std::vector<std::pair<Kugla,Kugla>>kugle, std::pair<Kugla,Kugla>par) {
    for (int i=0; i<kugle.size(); i++) {
        if ((DaLiSuIdenticne(kugle[i].first, par.first) && DaLiSuIdenticne(kugle[i].second, par.second)) || (DaLiSuIdenticne(kugle[i].first, par.second) && 
        DaLiSuIdenticne(kugle[i].second, par.first))) return true;
    }
    return false;
}

int main () {

    double a(0),b(0),c(0),r(0);
    int n(0),broj(0);
    
    std::cout<<"Unesite broj kugla: ";
    do {
        std::cin>>broj;
        if (broj<=0 || !std::cin) {
            std::cout<<"Neispravan broj kugli, unesite ponovo!";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"\n";
        }
        else n=broj;
    }
    while (broj<=0 || !std::cin);
   
    
    std::vector<std::shared_ptr<Kugla>>v;
    
    for (int i=0; i<n; i++) {
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>a>>b>>c;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Neispravan centar\n";
            --i;
            continue;
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if (!std::cin || r<0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Ilegalan poluprecnik\n";
            --i;
            continue;
        }
        std::shared_ptr<Kugla> pok(std::make_shared<Kugla>(a,b,c,r));
        v.push_back(pok);
    }
    
    double dx,dy,dz;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin>>dx>>dy>>dz;
    while(!std::cin){
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
        std::cin>>dx>>dy>>dz;
    }
    
    std::vector<std::shared_ptr<Kugla>>v2(n);
    std::transform (v.begin(), v.end(), v2.begin(), [dx,dy,dz] (std::shared_ptr<Kugla>v) {v->Transliraj(dx,dy,dz); return v;} );
    std::sort(v2.begin(), v2.end(), [] (std::shared_ptr<Kugla>k1, std::shared_ptr<Kugla>k2) {return k1->DajZapreminu() < k2->DajZapreminu(); });
    
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each (v2.begin(), v2.end(), [] (std::shared_ptr<Kugla>k) {k->Ispisi(); std::cout<<std::endl;});
    
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (*std::max_element(v2.begin(), v2.end(), [] (std::shared_ptr<Kugla>k1, std::shared_ptr<Kugla>k2) {
        return k1->DajPovrsinu() < k2->DajPovrsinu();}))->Ispisi();
   
    
    std::vector<std::pair<Kugla,Kugla>> presjek;
       for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i!=j) {
                if (DaLiSuIdenticne(*v2[i], *v2[j])) {
                    if (!DaLiSeNalaziUVektoru(presjek, std::make_pair(*v2[i], *v2[j])))
                    presjek.push_back(std::make_pair(*v2[j], *v2[i]));
                }
            }
        }
    }
    
    if (presjek.size() == 0) std::cout<<"\nNe postoje kugle koje se presjecaju!";
    else {
            std::cout<<"Presjecaju se kugle: ";
            std::for_each(presjek.begin(), presjek.end(), [] (std::pair<Kugla,Kugla>p) {
                p.first.Ispisi();
                std::cout<<"\n";
                p.second.Ispisi();
                std::cout<<"\n";
            });
        }
        
        
        
        
        return 0;
}
    