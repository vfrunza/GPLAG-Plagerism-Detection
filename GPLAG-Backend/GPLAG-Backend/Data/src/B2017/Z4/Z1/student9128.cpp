#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>

using std::cout;
using std::cin;

const double PI = 4*atan(1.);
const double EPSILON = 10e-10;

class Kugla {
    double x_coor, y_coor, z_coor, radius;
public:
    explicit Kugla(double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        radius=r;
        x_coor=y_coor=z_coor=0;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x_coor=std::get<0>(centar);
        y_coor=std::get<1>(centar);
        z_coor=std::get<2>(centar);
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x_coor=x; y_coor=y; z_coor=z; radius=r;
    }
    double DajX() const {return x_coor;}
    double DajY() const {return y_coor;}
    double DajZ() const {return z_coor;}
    double DajPoluprecnik() const {return radius;}
    double DajPovrsinu() const {return 4*PI*radius*radius;}
    double DajZapreminu() const {return (4./3)*PI*radius*radius*radius;}
    std::tuple<double, double, double> DajCentar() const {return std::make_tuple(x_coor, y_coor, z_coor);}
    Kugla &PostaviX(double x) {x_coor=x; return *this;}
    Kugla &PostaviY(double y) {y_coor=y; return *this;}
    Kugla &PostaviZ(double z) {z_coor=z; return *this;}
    Kugla &PostaviCentar(double x, double y, double z) {PostaviX(x); PostaviY(y); PostaviZ(z); return *this;}
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {PostaviX(std::get<0>(centar)); PostaviY(std::get<1>(centar)); PostaviZ(std::get<2>(centar)); return *this;}
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        radius=r; return *this;
    }
    void Ispisi() const {cout<<"{("<<x_coor<<","<<y_coor<<","<<z_coor<<"),"<<radius<<"}";}
    void Transliraj(double delta_x, double delta_y, double delta_z);
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
    return sqrt((k2.x_coor-k1.x_coor)*(k2.x_coor-k1.x_coor)+(k2.y_coor-k1.y_coor)*(k2.y_coor-k1.y_coor)+(k2.z_coor-k1.z_coor)*(k2.z_coor-k1.z_coor));
}

void Kugla::Transliraj(double delta_x, double delta_y, double delta_z) {
    x_coor+=delta_x;
    y_coor+=delta_y;
    z_coor+=delta_z;
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    return (fabs(k1.radius-k2.radius)<=EPSILON*(fabs(k1.radius)+fabs(k2.radius)) && fabs(k1.x_coor-k2.x_coor)<=EPSILON*(fabs(k1.x_coor)+fabs(k2.x_coor)) && fabs(k1.y_coor-k2.y_coor)<=EPSILON*(fabs(k1.y_coor)+fabs(k2.y_coor)) && fabs(k1.z_coor-k2.z_coor)<=EPSILON*(fabs(k1.z_coor)+fabs(k2.z_coor)));
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    return fabs(k1.radius-k2.radius)<=EPSILON*(fabs(k1.radius)+fabs(k2.radius));
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    return fabs(k1.x_coor-k2.x_coor)<=EPSILON*(fabs(k1.x_coor)+fabs(k2.x_coor)) && fabs(k1.y_coor-k2.y_coor)<=EPSILON*(fabs(k1.y_coor)+fabs(k2.y_coor)) && fabs(k1.z_coor-k2.z_coor)<=EPSILON*(fabs(k1.z_coor)+fabs(k2.z_coor));
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    double manji_radius, veci_radius;
    if(k1.radius<k2.radius) {
        manji_radius=k1.radius;
        veci_radius=k2.radius;
    }
    else {
        manji_radius=k2.radius;
        veci_radius=k1.radius;
    }
    
    auto udaljenost_centara(RastojanjeCentara(k1, k2));
    
    return fabs(udaljenost_centara+manji_radius-veci_radius)<=EPSILON*(fabs(udaljenost_centara+manji_radius)+fabs(veci_radius));
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    auto udaljenost_centara(RastojanjeCentara(k1, k2));
    return fabs(k1.radius+k2.radius-udaljenost_centara)<=EPSILON*(fabs(k1.radius+k2.radius)+fabs(udaljenost_centara));
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    return RastojanjeCentara(k1, k2)<k1.radius+k2.radius; 
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    
    if(k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1)) return false;
    
    return RastojanjeCentara(k1, k2)<k1.radius+k2.radius;
    
}

bool Kugla::DaLiSadrzi(const Kugla &k) const {
    if(k.radius<radius) return false;
    return radius+RastojanjeCentara(*this, k)<=k.radius;
}

int main ()
{
    int n;
    double r, x, y, z;
    cout<<"Unesite broj kugla: ";
    for(;;) {
        cin>>n;
        if(!cin || n<=0) {
            cout<<"Neispravan broj kugli, unesite ponovo!\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else break;
    }
    std::vector<std::shared_ptr<Kugla>> v(n);
    Kugla pomocna;
    
    for(int i=0; i<n; i++) {
        cout<<"Unesite centar "<<i+1<<". kugle: ";
        cin>>x>>y>>z;
        if(!cin) {
            cout<<"Neispravan centar\n";
            cin.clear();
            cin.ignore(10000, '\n');
            i--;
        } else {
            pomocna.PostaviX(x).PostaviY(y).PostaviZ(z);
            try {
                cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
                cin>>r;
                if(!cin) throw std::domain_error("Ilegalan poluprecnik");
                pomocna.PostaviPoluprecnik(r);
                v[i]= std::make_shared<Kugla>(pomocna);
            } catch(std::domain_error izuzetak) {
                cout<<izuzetak.what()<<"\n";
                i--;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
    }
    
    double delta_x, delta_y, delta_z;
    cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    for(;;) {
        cin>>delta_x>>delta_y>>delta_z;
        if(!cin) { 
            cout<<"Neispravni parametri translacije, unesite ponovo!\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else break;
    }
    
    std::transform(v.begin(), v.end(), v.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> p) {
        p->Transliraj(delta_x, delta_y, delta_z);
        return p;
    });
    
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2){return p1->DajZapreminu()<p2->DajZapreminu();});
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> p){p->Ispisi(); cout<<"\n";});
    
    auto max(std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {return p1->DajPovrsinu()<p2->DajPovrsinu();}));
    cout<<"Kugla sa najvecom povrsinom je: ";
    (*max)->Ispisi();
    cout<<"\n";
    
    int brojac_lam1(0);
    bool bio_ispis=false;
    
    std::for_each(v.begin(), v.end(), [&brojac_lam1, &v, &bio_ispis] (std::shared_ptr<Kugla> p1) {
        std::for_each(v.begin()+brojac_lam1+1, v.end(), [p1, &bio_ispis] (std::shared_ptr<Kugla> p2) {
            if(DaLiSeSijeku(*p1, *p2)) {
                bio_ispis=true;
                cout<<"Presjecaju se kugle: ";
                p1->Ispisi(); cout<<"\n"; p2->Ispisi(); cout<<"\n";
            }
        });
        brojac_lam1++;
    });
    if(!bio_ispis) cout<<"Ne postoje kugle koje se presjecaju!";
    return 0;
}
