/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
#include <stdexcept>

using namespace std;

class NepreklapajucaKugla
{
    double r;
    double x,y,z;
    static NepreklapajucaKugla* zadnji ;
    NepreklapajucaKugla*prethodni;
    static bool DaLiSuJednaki(double a, double b, double eps=1e-10) {
        return fabs(a-b) < eps*(fabs(a)+fabs(b));
    }
    static bool DaLiSePreklapaju(const NepreklapajucaKugla&k1, const NepreklapajucaKugla&k2) {
        double d = RastojanjeCentara(k1,k2);
        return d<=k1.r+k2.r;
    }

    static bool DaLiJeLegalan(const NepreklapajucaKugla& k) {
        for(auto p = NepreklapajucaKugla::zadnji; p!=nullptr; p=p->prethodni) {
            if(DaLiSePreklapaju(k,*p)) {
                return false;
            }
        }
        return true;
    }

public:

    ~NepreklapajucaKugla() {
        if(NepreklapajucaKugla::zadnji==this) {
            NepreklapajucaKugla::zadnji = this->prethodni;
        } else {
            for(auto p = NepreklapajucaKugla::zadnji; p!=nullptr; p=p->prethodni) {
                if(p->prethodni == this) {
                    p->prethodni = this->prethodni;
                }
            }
        }
    }
    explicit NepreklapajucaKugla(double r = 0) {
        if(r<0)throw domain_error("Ilegalan poluprecnik");
        x=0;
        y=0;
        z=0;
        this->r=r;

        if(DaLiJeLegalan(*this)) {
            prethodni = zadnji;
            zadnji = this;
        } else {
            throw logic_error("Nedozvoljeno preklapanje");
        }

    }

    NepreklapajucaKugla(double x, double y, double z, double r = 0) {
        if(r<0)throw domain_error("Ilegalan poluprecnik");
        this->x=x;
        this->y=y;
        this->z=z;
        this->r=r;
        if(DaLiJeLegalan(*this)) {
            prethodni = zadnji;
            zadnji = this;
        } else {
            throw logic_error("Nedozvoljeno preklapanje");
        }

    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
        this->r = r;
        x = get<0>(centar);
        y = get<1>(centar);
        z = get<2>(centar);
        if(DaLiJeLegalan(*this)) {
            prethodni = zadnji;
            zadnji = this;
        } else {
            throw logic_error("Nedozvoljeno preklapanje");
        }

    }


    NepreklapajucaKugla(const NepreklapajucaKugla &n) = delete;
    NepreklapajucaKugla& operator = (const NepreklapajucaKugla& n)=delete;

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
        return tuple<double,double,double>(x,y,z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*r*r*atan(1)*4;
    }
    double DajZapreminu() const {
        return (4./3)*r*r*r*atan(1)*4;
    }
    NepreklapajucaKugla &PostaviX(double x) {
        double stari_x = this->x;
        this->x=x;
        if(!DaLiJeLegalan(*this)) {
            this->x=stari_x;
            throw logic_error("Nedozvoljeno preklapanje");
        }


        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        double stari_y = this->y;

        this->y=y;
        if(!DaLiJeLegalan(*this)) {
            this->y=stari_y;
            throw logic_error("Nedozvoljeno preklapanje");
        }

        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        double stari_z = this->z;

        this->z=z;
        if(!DaLiJeLegalan(*this)) {
            this->z=stari_z;
            throw logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        double stari_x = this->x;
        double stari_y = this->y;
        double stari_z = this->z;
        this->x=x;
        this->y=y;
        this->z=z;
        if(!DaLiJeLegalan(*this)) {
            this->x=stari_x;
            this->y=stari_y;
            this->z=stari_z;
            throw logic_error("Nedozvoljeno preklapanje");
        }

        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {

        double stari_x = this->x;
        double stari_y = this->y;
        double stari_z = this->z;
        x = DajX();
        y = DajY();
        z = DajZ();
        if(!DaLiJeLegalan(*this)) {
            this->x=stari_x;
            this->y=stari_y;
            this->z=stari_z;
            throw logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if(r<0)throw domain_error("Ilegalan poluprecnik");
        double stari_r = this->r;
        this->r = r;
        if(!DaLiJeLegalan(*this)) {
            this->r=stari_r;
            throw logic_error("Nedozvoljeno preklapanje");
        }
    }
    void Ispisi() const {
        cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        double stari_x = this->x;
        double stari_y = this->y;
        double stari_z = this->z;
        this->x = DajX()+delta_x;
        this->y = DajY()+delta_y;
        this->z = DajZ()+delta_z;
        if(!DaLiJeLegalan(*this)) {
            this->x=stari_x;
            this->y=stari_y;
            this->z=stari_z;
            throw logic_error("Nedozvoljeno preklapanje");
        }
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
        return sqrt((k1.x-k2.x)*(k1.x-k2.x) +(k1.y-k2.y)*(k1.y-k2.y) +(k1.z-k2.z)*(k1.z-k2.z));
    }
};


NepreklapajucaKugla* NepreklapajucaKugla::zadnji(nullptr);
int main ()
{



    int n;

    cout<<"Unesite broj kugli: ";
    while(true) {
        cin>>n;
        if(!cin || n<=0) {
            cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
        } else {
            break;
        }
    }
    vector<shared_ptr<NepreklapajucaKugla> > kugle;

    for (int i = 0; i < n; i++) {
        try {
            double x,y,z,r;
            cout<<"Unesite centar za "<<i+1<<". kuglu: ";
            cin>>x>>y>>z;
            while(!cin) {
                cout<<"Neispravan centar, unesite ponovo:"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
                cin>>x>>y>>z;
            }



            cout<<"Unesite poluprecnik: ";
            cin>>r;
            while(true) {
                if(r<0) {
                    cout<<"Neispravan poluprecnik, unesite ponovo:"<<endl;
                }
                else if(!cin) {
                    cout<<"Neispravan poluprecnik, unesite ponovo:"<<endl;
                    cin.clear();
                    cin.ignore(1000,'\n');

                }
                else{
                    break;
                }
                cin>>r;
            }

            auto k = make_shared<NepreklapajucaKugla>(x,y,z,r);
            kugle.push_back(k);

        } catch(domain_error e) {
            cout<<e.what()<<endl;
            i--;
        } catch(logic_error e) {
            cout<<e.what()<<endl;
            i--;
        }
    }


    cout<<"\nKugle nakon obavljenog sortiranja: \n";

    sort(kugle.begin(),kugle.end(),[](shared_ptr<NepreklapajucaKugla>k1, shared_ptr<NepreklapajucaKugla>k2) {
        return k1->DajPovrsinu()<k2->DajPovrsinu();
    });

    for_each(kugle.begin(),kugle.end(),[](shared_ptr<NepreklapajucaKugla>k) {
        k->Ispisi();
    });


    return 0;
}
