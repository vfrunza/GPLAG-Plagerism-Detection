/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <algorithm>
#include <memory>
#include <vector>
using namespace std;

class Kugla
{
    const double PI=4*atan(1);
    double x,y,z;
    double poluprecnik;
    static bool Jednaki(double a, double b,double eps=10e-10) {
        return fabs(a-b)<eps;
    }
public:
    explicit Kugla(double r = 0) {
        if(poluprecnik<0) throw domain_error("Ilegalan poluprecnik");
        poluprecnik=r;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        poluprecnik=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        x=get<0>(centar);
        y=get<1>(centar);
        z=get<2>(centar);
        poluprecnik=r;
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
    tuple<double, double, double> DajCentar() const {
        return tie(x,y,z);
    }
    double DajPoluprecnik() const {
        return poluprecnik;
    }
    double DajPovrsinu() const {
        return 4*poluprecnik*poluprecnik*PI;
    }
    double DajZapreminu() const {
        return (4/3.)*pow(poluprecnik,3)*PI;
    }
    Kugla &PostaviX(double x) {
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        Kugla::x=get<0>(centar);
        Kugla::y=get<1>(centar);
        Kugla::z=get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        poluprecnik=r;
        return *this;
    }
    void Ispisi() const {
        cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}";
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
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    int br(0);
    if(Kugla::Jednaki(k1.x,k2.x)==true) br++;
    if(Kugla::Jednaki(k1.y,k2.y)==true) br++;
    if(Kugla::Jednaki(k1.z,k2.z)==true) br++;
    if(Kugla::Jednaki(k1.poluprecnik,k2.poluprecnik)==true) br++;
    if(br==4) return true;
    return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return Kugla::Jednaki(k1.poluprecnik,k2.poluprecnik);
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    int br(0);
    if(Kugla::Jednaki(k1.x,k2.x)==true) br++;
    if(Kugla::Jednaki(k1.y,k2.y)==true) br++;
    if(Kugla::Jednaki(k1.z,k2.z)==true) br++;
    if(br==3) return true;
    return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    return Kugla::Jednaki(k1.poluprecnik+k2.poluprecnik,RastojanjeCentara(k1,k2));
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    return Kugla::Jednaki(abs(k1.poluprecnik-k2.poluprecnik),RastojanjeCentara(k1,k2));
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    return RastojanjeCentara(k1,k2)<k1.poluprecnik+k2.poluprecnik;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    return DaLiSePreklapaju(k1,k2) && RastojanjeCentara(k1,k2)>abs(k1.poluprecnik-k2.poluprecnik);
}

bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    return DaLiSePreklapaju(*this,k) && RastojanjeCentara(*this,k)<(this->poluprecnik)-k.poluprecnik;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2));
}

int main ()
{
    int n;
    cout<<"Unesite broj kugla: ";
    while((cin>>n),!cin || n<=0) {
        cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;
        cin.clear();
        cin.ignore(20,'\n');
    }
    vector<shared_ptr<Kugla>>v(n);

    for(int i=0; i<n; i++) {
        double x,y,z,r;
ponovo:
        cout<<"Unesite centar "<<i+1<<". kugle: ";
        cin>>x>>y>>z;
        while(!cin) {
            cout<<"Neispravan centar"<<endl;
            cin.clear();
            cin.ignore(200,'\n');
            goto ponovo;
        }
        cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        cin>>r;
        try {
            if(!cin || r<0) {
                throw domain_error("Ilegalan poluprecnik");
            }
        } catch(domain_error x) {
            cout<<x.what()<<endl;
            cin.clear();
            cin.ignore(200,'\n');
            goto ponovo;
        }
        try {
            v[i]=make_shared<Kugla>(x,y,z,r);
        } catch(bad_alloc x) {
            cout<<x.what()<<endl;
        }
    }


    cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x,delta_y,delta_z;
opet:
    cin>>delta_x>>delta_y>>delta_z;
    if(!cin) {
        cout<<"Neispravni parametri translacije, unesite ponovo!"<<endl;
        cin.clear();
        cin.ignore(200,'\n');
        goto opet;
    }
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<endl;
    transform(v.begin(),v.end(),v.begin(),[delta_x,delta_y,delta_z] (const shared_ptr<Kugla>k1) {
        (*k1).Transliraj(delta_x,delta_y,delta_z);
        return k1;
    });

    sort(v.begin(),v.end(),[] (const shared_ptr<Kugla>k1,const shared_ptr<Kugla>k2) {
        return (*k1).DajZapreminu()<(*k2).DajZapreminu();
    });

    for_each(v.begin(),v.end(),[] (shared_ptr<Kugla>k) {
        (*k).Ispisi();
        cout<<endl;
    });

    cout<<"Kugla sa najvecom povrsinom je: ";
    auto pok(max_element(v.begin(),v.end(),[] (const shared_ptr<Kugla>k1,const shared_ptr<Kugla>k2) {
        return (*k1).DajPovrsinu() < (*k2).DajPovrsinu();
    }));
    if(n!=0) {
        (*pok)->Ispisi();
    }


    int br(0),i(0);
    for_each(v.begin(),v.end(),[v,&br,&i] (shared_ptr<Kugla>k1) ->void {
        for_each(v.begin()+(++i),v.end(),[&](shared_ptr<Kugla>k2) ->void {
            if(DaLiSeSijeku(*k1,*k2) && k1!=k2) {
                cout<<"\nPresjecaju se kugle: ";
                k1->Ispisi();
                cout<<endl;
                k2->Ispisi();
                br++;
            }
        });
    });

    if(!br) {
        cout<<"\nNe postoje kugle koje se presjecaju!";
    }
    return 0;
}
