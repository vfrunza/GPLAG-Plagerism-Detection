/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <algorithm>
#include <memory>
#include <vector>
using namespace std;

class NepreklapajucaKugla
{
    const double PI=4*atan(1);
    double x,y,z;
    double poluprecnik;
    NepreklapajucaKugla *prethodni;
    static NepreklapajucaKugla *zadnji;
    static bool Jednaki(double a, double b,double eps=10e-10) {
        return fabs(a-b)<eps;
    }
    static bool Preklapanje(const NepreklapajucaKugla &k1,const NepreklapajucaKugla &k2) {
        return RastojanjeCentara(k1,k2)<= k1.poluprecnik+k2.poluprecnik;
    }
    void Testiraj() {
        NepreklapajucaKugla *pomocna {zadnji};
        for(;;) {
            if(this!=pomocna && Preklapanje(*this,*pomocna)) {
                this-> ~NepreklapajucaKugla();
                throw logic_error("Nedozvoljeno preklapanje");
            }
            pomocna=pomocna->prethodni;
            if(pomocna==nullptr)
                break;
        }
    }
public:
    explicit NepreklapajucaKugla(double r = 0) {
        if(poluprecnik<0) throw domain_error("Ilegalan poluprecnik");
        poluprecnik=r;
        if(zadnji==nullptr)
            prethodni=nullptr;
        else prethodni=zadnji;
        zadnji=this;
        this->Testiraj();
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0) {
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        poluprecnik=r;
        if(zadnji==nullptr)
            prethodni=nullptr;
        else prethodni=zadnji;
        zadnji=this;
        this->Testiraj();

    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        x=get<0>(centar);
        y=get<1>(centar);
        z=get<2>(centar);
        poluprecnik=r;
        if(zadnji==nullptr)
            prethodni=nullptr;
        else prethodni=zadnji;
        zadnji=this;
        this->Testiraj();
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
    NepreklapajucaKugla &PostaviX(double x) {
        NepreklapajucaKugla::x=x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        NepreklapajucaKugla::y=y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        NepreklapajucaKugla::x=get<0>(centar);
        NepreklapajucaKugla::y=get<1>(centar);
        NepreklapajucaKugla::z=get<2>(centar);
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        poluprecnik=r;
        return *this;
    }

    NepreklapajucaKugla(const NepreklapajucaKugla &k)=delete;
    NepreklapajucaKugla &operator=(const NepreklapajucaKugla &k)=delete;
    NepreklapajucaKugla(NepreklapajucaKugla &&k)=delete;
    NepreklapajucaKugla &operator=(NepreklapajucaKugla &&k)=delete;

    ~NepreklapajucaKugla() {
        if(zadnji==this) {
            zadnji=prethodni;
            prethodni=nullptr;
        } else {
            NepreklapajucaKugla *pomocna {zadnji};
            while(pomocna->prethodni!=this)
                pomocna=pomocna->prethodni;

            pomocna->prethodni=this->prethodni;
            this->prethodni=nullptr;
        }
    }

    void Ispisi() const {
        cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const;
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

bool NepreklapajucaKugla::DaLiSadrzi(const NepreklapajucaKugla &k) const
{
    return NepreklapajucaKugla::Preklapanje(*this,k) && RastojanjeCentara(*this,k)<(this->poluprecnik)-k.poluprecnik;
}

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2));
}

NepreklapajucaKugla *NepreklapajucaKugla::zadnji=nullptr;

int main ()
{
    int n;
    cout<<"Unesite broj kugli: ";
    while((cin>>n),!cin || n<=0) {
        cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;
        cin.clear();
        cin.ignore(20,'\n');
    }
    vector<shared_ptr<NepreklapajucaKugla>>v(n);

    for(int i=0; i<n; i++) {
        double x,y,z,r;
ponovo:
        cout<<"Unesite centar za "<<i+1<<". kuglu: ";
        cin>>x>>y>>z;
        if(!cin) {
            cout<<"Neispravan centar, unesite ponovo: "<<endl;
            cin.clear();
            cin.ignore(200,'\n');
            cin>>x>>y>>z;
        }
        cout<<"Unesite poluprecnik: ";
        while((cin>>r),!cin || r<0) {
            cout<<"Neispravan poluprecnik, unesite ponovo: "<<endl;
            cin.clear();
            cin.ignore(20,'\n');
        }
        try {
            v[i]=make_shared<NepreklapajucaKugla>(x,y,z,r);
        } catch(bad_alloc x) {
            cout<<x.what()<<endl;
        } catch(logic_error x) {
            cout<<x.what()<<endl;
            cin.clear();
            cin.ignore(20,'\n');
            goto ponovo;
        }
    }

    sort(v.begin(),v.end(),[] (const shared_ptr<NepreklapajucaKugla>k1,const shared_ptr<NepreklapajucaKugla>k2) {
        return (*k1).DajPovrsinu()<(*k2).DajPovrsinu();
    });

    cout<<"\nKugle nakon obavljenog sortiranja: "<<endl;
    for_each(v.begin(),v.end(),[] (shared_ptr<NepreklapajucaKugla>k) {
        (*k).Ispisi();
        cout<<endl;
    });
    return 0;
}
