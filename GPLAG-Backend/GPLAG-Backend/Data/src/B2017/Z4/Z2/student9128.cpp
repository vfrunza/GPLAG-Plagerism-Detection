#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>

using std::cout;
using std::cin;

const double PI = 4*atan(1.);
const double EPSILON = 10e-10;

class NepreklapajucaKugla {
    double x_coor, y_coor, z_coor, radius;
    NepreklapajucaKugla *prethodna=nullptr;
    static NepreklapajucaKugla *posljednja;
    static double UdaljenostDvijeTacke (const std::tuple<double, double, double> &tacka1, const std::tuple<double, double, double> &tacka2);
    bool VecJeUListi() const;
    bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const;
public:
    explicit NepreklapajucaKugla(double r = 0);
    NepreklapajucaKugla(const NepreklapajucaKugla &k) = delete;
    ~NepreklapajucaKugla();
    NepreklapajucaKugla &operator =(const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla(double x, double y, double z, double r = 0);
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0);
    double DajX() const {return x_coor;}
    double DajY() const {return y_coor;}
    double DajZ() const {return z_coor;}
    std::tuple<double, double, double> DajCentar() const {return std::make_tuple(x_coor, y_coor, z_coor);}
    double DajPoluprecnik() const {return radius;}
    double DajPovrsinu() const {return 4*PI*radius*radius;}
    double DajZapreminu() const {return (4./3)*PI*radius*radius*radius;}
    NepreklapajucaKugla &PostaviX(double x) {
        auto pomocna(x_coor);
        x_coor=x;
        if(this->VecJeUListi()) {
            x_coor=pomocna;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        auto pomocna(y_coor);
        y_coor=y;
        if(this->VecJeUListi()) {
            y_coor=pomocna;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        auto pomocna(z_coor);
        z_coor=z;
        if(this->VecJeUListi()) {
            z_coor=pomocna;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        double ypom(y_coor), xpom(x_coor), zpom(z_coor);
        x_coor=x; y_coor=y; z_coor=z;
        if(this->VecJeUListi()) {
            z_coor=zpom, y_coor=ypom, x_coor=xpom;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        double ypom(y_coor), xpom(x_coor), zpom(z_coor);
        x_coor=std::get<0>(centar); y_coor=std::get<1>(centar); z_coor=std::get<2>(centar);
        if(this->VecJeUListi()) {
            z_coor=zpom, y_coor=ypom, x_coor=xpom;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        auto pomocna(radius);
        radius=r;
        if(this->VecJeUListi()) {
            radius=pomocna;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    void Ispisi() const {cout<<"{("<<x_coor<<","<<y_coor<<","<<z_coor<<"),"<<radius<<"}";}
    void Transliraj(double delta_x, double delta_y, double delta_z);
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const;
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

NepreklapajucaKugla::NepreklapajucaKugla(double r) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    radius=r;
    x_coor=y_coor=z_coor=0; 
    if(!posljednja) {
        posljednja=this;
        radius=r; 
        x_coor=y_coor=z_coor=0;
    } else {
        prethodna=posljednja;
        if(!this->VecJeUListi()) {
            posljednja=this;
        } else {
            prethodna=nullptr;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
    }
}

NepreklapajucaKugla::NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    
    x_coor=std::get<0>(centar);
    y_coor=std::get<1>(centar);
    z_coor=std::get<2>(centar);
    if(!posljednja) {
        posljednja=this;
        radius=r;
    } else {
        prethodna=posljednja;
        if(!this->VecJeUListi()) {
            posljednja=this;
        } else {
            prethodna=nullptr;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
    }
}

NepreklapajucaKugla* NepreklapajucaKugla::posljednja = nullptr;

NepreklapajucaKugla::~NepreklapajucaKugla() {
    if(posljednja==this) {
        posljednja=prethodna;
    } else if(this->prethodna==nullptr) {
        posljednja=nullptr;
    } else {
        auto pomocni(posljednja);
        for(;;) {
            if(pomocni==nullptr) break;
            if(pomocni->prethodna==this) {
                auto pomocni2(this->prethodna);
                pomocni->prethodna=pomocni2;
            }
            pomocni=pomocni->prethodna;
        }
    }
}

bool NepreklapajucaKugla::DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const {
    return RastojanjeCentara(k1, k2)<=k1.radius+k2.radius; 
}

NepreklapajucaKugla::NepreklapajucaKugla(double x, double y, double z, double r) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    x_coor=x; y_coor=y; z_coor=z; radius=r;
    if(!posljednja) {
        posljednja=this;
    } else {
        prethodna=posljednja;
        if(!this->VecJeUListi()) {
            posljednja=this;
        } else {
            prethodna=nullptr;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
    }
}

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return sqrt((k2.x_coor-k1.x_coor)*(k2.x_coor-k1.x_coor)+(k2.y_coor-k1.y_coor)*(k2.y_coor-k1.y_coor)+(k2.z_coor-k1.z_coor)*(k2.z_coor-k1.z_coor));
}

void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z) {
    x_coor+=delta_x;
    y_coor+=delta_y;
    z_coor+=delta_z;
}

bool NepreklapajucaKugla::VecJeUListi() const {
    auto pomocni(this);
    
    for(;;) {
        if(!pomocni->prethodna) {
            break;
        }
        auto drugi_pomocni(pomocni->prethodna);;
        if(DaLiSePreklapaju(*pomocni, *drugi_pomocni)) return true;
        pomocni=pomocni->prethodna;
    }
    return false;
}

int main ()
{
    int n;
    double r, x, y, z;
    cout<<"Unesite broj kugli: ";
    for(;;) {
        cin>>n;
        if(!cin || n<=0) {
            cout<<"Neispravan broj kugli, unesite ponovo!\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else break;
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> v(n);
    
    for(int i=0; i<n; i++) {
        cout<<"Unesite centar za "<<i+1<<". kuglu: ";
        for(;;) {
            cin>>x>>y>>z;
            if(!cin) {
                cout<<"Neispravan centar, unesite ponovo:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            } else break;
        }
        try {
            cout<<"Unesite poluprecnik: ";
            for(;;) {
                cin>>r;
                if(!cin || r<0) {
                    cout<<"Neispravan poluprecnik, unesite ponovo:\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                } else break;
            }
            v[i]= std::make_shared<NepreklapajucaKugla>(x,y,z,r);
        } catch(std::domain_error izuzetak) {
            cout<<izuzetak.what()<<"\n";
            i--;
            cin.clear();
            cin.ignore(10000, '\n');
        } catch(std::logic_error izuzetak) {
                cout<<izuzetak.what()<<"\n";
                i--;
                cin.clear();
                cin.ignore(10000, '\n');
        }
    }
    
    std::sort(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> p1, std::shared_ptr<NepreklapajucaKugla> p2) {return p1->DajPovrsinu()<p2->DajPovrsinu();});
    cout<<"\nKugle nakon obavljenog sortiranja: \n";
    for(int i=0; i<v.size(); i++) {
        v[i]->Ispisi();
        cout<<"\n";
    }
    
    return 0;
}
