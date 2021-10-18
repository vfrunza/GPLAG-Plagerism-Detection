/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <algorithm>
#include <vector>

using namespace std;

double PI(4*atan(1.));
double e(pow(10,-10));
bool netacno(true);
class Kugla {
    double x,y,z;
    double r;
    public:
    explicit Kugla(double r = 0) {
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        x=0;
        y=0;
        z=0;
        this->r=r; //moze i Kugla::r=r;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        this->x=x;
        this->y=y;
        this->z=z;
        this->r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        x=get<0>(centar);
        y=get<1>(centar);
        z=get<2>(centar);
        this->r=r;
    }
    double DajX() const {
        return x;
    }
    double DajY() const {
        return y;
    }
    double DajZ() const {
        return z;
    }
    std::tuple<double, double, double> DajCentar() const {
        auto centar(tie(x,y,z));
        return centar;
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        double p(4*r*r*PI);
        return p;
    }
    double DajZapreminu() const {
        double v=(4./3)*r*r*r*PI;
        return v;
    }
    Kugla &PostaviX(double x) {
        this->x=x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        this->y=y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        this->z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z) {
        this->x=x;
        this->y=y;
        this->z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        x=get<0>(centar);
        y=get<1>(centar);
        z=get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        this->r=r;
        return *this;
    }
    void Ispisi() const {
        cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const {
        if(RastojanjeCentara(*this,k)+k.DajPoluprecnik()<r) return true;
        return false;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    if(fabs(k1.x-k2.x)<e*(fabs(k1.x)+fabs(k2.x)) 
    or fabs(k1.y-k2.y)<e*(fabs(k1.y)+fabs(k2.y)) 
    or fabs(k1.z-k2.z)<e*(fabs(k1.z)+fabs(k2.z))
    or fabs(k1.r-k2.r)<e*(fabs(k1.r)+fabs(k2.r))) return false;
    return true;
} 
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    if(fabs(k1.r-k2.r)<e*(fabs(k1.r)+fabs(k2.r))) return false;
    return true;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    if(fabs(k1.x-k2.x)<e*(fabs(k1.x)+fabs(k2.x)) 
    or fabs(k1.y-k2.y)<e*(fabs(k1.y)+fabs(k2.y)) 
    or fabs(k1.z-k2.z)<e*(fabs(k1.z)+fabs(k2.z))) return false;
    return true;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    double udaljenost1(RastojanjeCentara(k1,k2));
    double udaljenost2(k1.r+k2.r);
    if(fabs(udaljenost1-udaljenost2)<e*(fabs(udaljenost1)+fabs(udaljenost2))) return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    double udaljenost1(RastojanjeCentara(k1,k2));
    double udaljenost2(k1.r+k2.r);
    if(fabs(udaljenost1-udaljenost2)<e*(fabs(udaljenost1)+fabs(udaljenost2))) return false;
    if(udaljenost1<udaljenost2 and (k1.r==(k2.r-udaljenost1) or k2.r==(k1.r-udaljenost1))) return true;
    return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    double udaljenost1(RastojanjeCentara(k1,k2));
    double udaljenost2(k1.r+k2.r);
    if(udaljenost1<udaljenost2) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    double udaljenost1(RastojanjeCentara(k1,k2));
    double udaljenost2(k1.r+k2.r);
    if(udaljenost1<udaljenost2 and (k1.r>k2.r-udaljenost1 or k2.r>k1.r+udaljenost1) and k1.DajCentar()!=k2.DajCentar()) return true;
    return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return (sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)));
}

int main ()
{
    try {
         double n;
         cout<<"Unesite broj kugla: ";
         cin>>n;
         while(!cin or n<=0) {
             cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;
             cin.clear();
             cin.ignore(10000,'\n');
             cin>>n;
         }
         std::vector<shared_ptr<Kugla>> v(n);
         double x,y,z,r;
         for(int i(0);i<n;i++) {
             cout<<"Unesite centar "<<i+1<<". kugle: ";
             cin>>x>>y>>z;
             if(!cin) {
                 cout<<"Neispravan centar"<<endl;
                 cin.clear();
                 cin.ignore(1000,'\n');
                 i--;
                 continue;
             }
             cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
             cin>>r;
             if(r<0 or !cin) {
                 cout<<"Ilegalan poluprecnik"<<endl;
                 cin.clear();
                 cin.ignore(1000,'\n');
                 i--;
                 continue;
             }
             else v[i]=make_shared<Kugla>(Kugla(x,y,z,r));
         }
         double delta_x,delta_y,delta_z;
         cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
         cin>>delta_x>>delta_y>>delta_z;
         while(!cin) {
             cout<<"Neispravni parametri translacije, unesite ponovo!"<<endl;
             cin.clear();
             cin.ignore(10000,'\n');
             cin>>delta_x>>delta_y>>delta_z;
         }
         transform(v.begin(),v.end(),v.begin(),[delta_x,delta_y,delta_z](shared_ptr<Kugla> k) {
             (*k).Transliraj(delta_x,delta_y,delta_z);
             return k;
         });
         sort(v.begin(),v.end(),[](shared_ptr<Kugla> k1, shared_ptr<Kugla> k2) {
             return (*k1).DajZapreminu()<(*k2).DajZapreminu();
         });
         cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<endl;
         for_each(v.begin(),v.end(),[](shared_ptr<Kugla> k) {
             (*k).Ispisi();
         });
         auto it=max_element(v.begin(),v.end(),[](shared_ptr<Kugla> k1, shared_ptr<Kugla> k2) {
             return (*k1).DajPovrsinu()<(*k2).DajPovrsinu();
         });
         cout<<"Kugla sa najvecom povrsinom je: ";
         (*it)->Ispisi();
         auto it1(v.begin());
         auto it2(v.end());
         for_each(it1,it2-1,[it1,it2](shared_ptr<Kugla> k1) {
             for_each(it1+1,it2,[it1,it2,k1](shared_ptr<Kugla> k2) {
                 if(DaLiSeSijeku(*k1,*k2) and it1!=it2) {
                     netacno=false;
                     cout<<"Presjecaju se kugle: ";
                     (*k1).Ispisi();
                     (*k2).Ispisi();
                     cout<<endl;
                 }
             });
         });
         if(netacno==true) cout<<"Ne postoje kugle koje se presjecaju!";
    }
    catch(domain_error a) {
        cout<<a.what()<<endl;
    }
	return 0;
}
