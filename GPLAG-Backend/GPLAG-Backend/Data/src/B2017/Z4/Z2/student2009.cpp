/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::shared_ptr;
using std::shared_ptr;
using std::endl;
const double eps=0.0000000001;
const double pi=3.141592653589793238462;

class NepreklapajucaKugla
{
    double x,y,z,r;
    NepreklapajucaKugla*prethodni=nullptr;
    static NepreklapajucaKugla* zadnji;
    static bool IstiDouble(const double &x, const double &y) {
        if (fabs(x-y) < eps*(fabs(x)+fabs(y))) return true;
        else if(fabs(x-y)<eps) return true;
        else return false;
    }

    static bool Preklapanje(double x1, double y1, double z1, double r1, NepreklapajucaKugla* p=nullptr) {
        NepreklapajucaKugla* zadnji_temp=zadnji;
        while(zadnji_temp!=nullptr) {
            double d=sqrt((x1-zadnji_temp->x)*(x1-zadnji_temp->x)+(y1-zadnji_temp->y)*(y1-zadnji_temp->y)+(z1-zadnji_temp->z)*(z1-zadnji_temp->z));
            if(zadnji_temp!=p && d-(r1+zadnji_temp->DajPoluprecnik())<=eps) return true;
            zadnji_temp=zadnji_temp->prethodni;
        }
        return false;
    }

public:
    explicit NepreklapajucaKugla(double r1 = 0) {
        if(r1<0) throw std::domain_error("Ilegalan poluprecnik");
        if(Preklapanje(0,0,0,r1)) throw std::logic_error("Nedozvoljeno preklapanje");
        prethodni=zadnji;
        x=y=z=0;
        NepreklapajucaKugla::r=r1;
        zadnji=this;
    };

    NepreklapajucaKugla(double x, double y, double z, double r1 = 0) {
        if(r1<0) throw std::domain_error("Ilegalan poluprecnik");
        if(Preklapanje(x,y,z,r1)) throw std::logic_error("Nedozvoljeno preklapanje");
        prethodni=zadnji;
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r1;
        zadnji=this;
    }

    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, const double r1 = 0) {
        if(r1<0) throw std::domain_error("Ilegalan poluprecnik");
        if(Preklapanje(std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),r1)) throw std::logic_error("Nedozvoljeno preklapanje");
        prethodni=zadnji;
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        NepreklapajucaKugla::r=r1;
        zadnji=this;
    }

    NepreklapajucaKugla (const NepreklapajucaKugla &x) =delete;
    NepreklapajucaKugla &operator =(const NepreklapajucaKugla &k) = delete;

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
        return std::make_tuple(x,y,z);
    }

    double DajPoluprecnik() const {
        return r;
    }

    double DajPovrsinu() const {
        return 4*r*r*pi;
    }

    double DajZapreminu() const {
        return (4./3)*(r*r*r)*pi;
    }

    NepreklapajucaKugla &PostaviX(double x1) {
        if(Preklapanje(x1,y,z,r,this)) throw std::logic_error("Nedozvoljeno preklapanje");
        x=x1;
        return *this;
    }

    NepreklapajucaKugla &PostaviY(double y1) {
        if(Preklapanje(x,y1,z,r,this)) throw std::logic_error("Nedozvoljeno preklapanje");
        y=y1;
        return *this;
    }

    NepreklapajucaKugla &PostaviZ(double z1) {
        if(Preklapanje(x,y,z1,r,this)) throw std::logic_error("Nedozvoljeno preklapanje");
        z=z1;
        return *this;
    }

    NepreklapajucaKugla &PostaviCentar(double x1, double y1, double z1) {
        if(Preklapanje(x1,y1,z1,r,this)) throw std::logic_error("Nedozvoljeno preklapanje");
        x=x1;
        y=y1;
        z=z1;
        return *this;
    }

    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        if(Preklapanje(std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),r,this)) throw std::logic_error("Nedozvoljeno preklapanje");
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        return *this;
    }

    NepreklapajucaKugla &PostaviPoluprecnik(double r1) {
        if(r1<0) throw std::domain_error("Ilegalan poluprecnik");
        if(Preklapanje(x,y,z,r1,this)) throw std::logic_error("Nedozvoljeno preklapanje");
        r=r1;
        return *this;
    }

    void Ispisi() const {
        std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}" << endl;
    }

    void Transliraj(double delta_x, double delta_y, double delta_z) {
        if(Preklapanje(x+delta_x,y+delta_y,z+delta_z,r,this)) throw std::logic_error("Nedozvoljeno preklapanje");
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }

    ~NepreklapajucaKugla() {
        if(this==zadnji) zadnji=prethodni; // ako je zadnji u listi
        else if(prethodni==nullptr) { // ako je prvi
            if(this==zadnji) zadnji=nullptr; // ako je prvi a ujedno i jedini
            else { // ako ih je prvi a ima ih vise od 1
                NepreklapajucaKugla*next(zadnji);
                while(next->prethodni!=nullptr && next->prethodni!=this) next=next->prethodni;
                next->prethodni=nullptr;
            }
        } else { // ako je negdje izmedju
            NepreklapajucaKugla*next(zadnji);
            NepreklapajucaKugla*previous(zadnji);
            while(next->prethodni!=nullptr && next->prethodni!=this)  {
                next=next->prethodni;
                previous=previous->prethodni;
            }
            previous=previous->prethodni->prethodni;
            next->prethodni=previous;
        }
    }

    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);

};

NepreklapajucaKugla*NepreklapajucaKugla::zadnji=nullptr;

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}

int main ()
{
    int n;
    cout << "Unesite broj kugli: ";
    while (std::cin >> n, !cin || n<=0) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    try {
        vector<shared_ptr<NepreklapajucaKugla>> kugle;
        for(int i=0; i<n; i++) {
            std::tuple<double,double,double> centar;
            double r;
            bool preklapanje {false};
            for(;;) {
                preklapanje=false;
                cout << "Unesite centar za " << i+1 << ". kuglu: ";
                for(;;) {
                    cin >> std::get<0>(centar) >> std::get<1>(centar) >> std::get<2>(centar);
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout << "Neispravan centar, unesite ponovo:" <<endl;
                    } else break;
                }
                cout << "Unesite poluprecnik: ";
                for(;;) {
                    cin >> r;
                    if(r<0 || cin.fail()) {
                        if(cin.fail()) {
                            cin.clear();
                            cin.ignore(1000,'\n');
                        }
                        cout << "Neispravan poluprecnik, unesite ponovo: " << endl;
                    } else break;
                }
                try {
                    NepreklapajucaKugla nk(centar,r);
                } catch(std::logic_error& ex) {
                    cout << ex.what() <<endl;
                    preklapanje=true;
                }
                if(!preklapanje) break;
            }
            kugle.push_back(shared_ptr<NepreklapajucaKugla>(new NepreklapajucaKugla(centar,r)));
        }
        cout <<endl;
        std::sort(kugle.begin(),kugle.end(),[kugle](const shared_ptr<NepreklapajucaKugla> &k1,const shared_ptr<NepreklapajucaKugla> &k2) {
            return k1->DajZapreminu()<k2->DajZapreminu();
        });
        cout << "Kugle nakon obavljenog sortiranja: " <<endl;
        std::for_each(kugle.begin(),kugle.end(),[kugle](const shared_ptr<NepreklapajucaKugla> &k) {
            k->Ispisi();
        });

    } catch(std::exception &ex) {
        cout << ex.what();
    }

    return 0;
}
