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
using std::endl;
const double pi=4*atan(1);
const double eps(0.0000000001);
class Kugla
{
    double x,y,z;
    double r;
    static constexpr double pi=3.141592653589793238462;
    static bool IstiDouble(const double &x, const double &y) {
        if (fabs(x-y) < eps*(fabs(x)+fabs(y))) return true;
        else if(fabs(x-y)<eps) return true;
        else return false;
    }

public:
    explicit Kugla(double r1 = 0) {
        if(r1<0) throw std::domain_error("Ilegalan poluprecnik");
        x=y=z=0;
        Kugla::r=r1;
    };

    Kugla(double x, double y, double z, double r1 = 0) {
        if(r1<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r1;
    }

    explicit Kugla(const std::tuple<double, double, double> &centar, const double r1 = 0) {
        if(r1<0) throw std::domain_error("Ilegalan poluprecnik");
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        Kugla::r=r1;
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
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        return *this;
    }

    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }

    void Ispisi() const {
        std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}" << endl;
    }

    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }

    bool DaLiSadrzi(const Kugla &k) const;
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);

    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);

};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return (Kugla::IstiDouble(k1.DajX(),k2.DajX()) && Kugla::IstiDouble(k1.DajY(),k2.DajY()) &&
            Kugla::IstiDouble(k1.DajZ(),k2.DajZ()) && Kugla::IstiDouble(k1.DajPoluprecnik(),k2.DajPoluprecnik()));
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return Kugla::IstiDouble(k1.DajPoluprecnik(),k2.DajPoluprecnik());
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return (RastojanjeCentara(k1,k2)<eps);
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}

bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    return (k.DajPoluprecnik()<=this->DajPoluprecnik() && RastojanjeCentara(*this,k)<=fabs(this->DajPoluprecnik()-k.DajPoluprecnik()));
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    double d(RastojanjeCentara(k1,k2));
    return (d<(k1.DajPoluprecnik()+k2.DajPoluprecnik()) && d>(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())));

}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    if(Kugla::IstiDouble(0,k1.r) && Kugla::IstiDouble(k2.r,0) && DaLiSuIdenticne(k1,k2)) return true;
    if(DaLiSuIdenticne(k1,k2) || DaLiSeSijeku(k1,k2)) return false;
    double d=RastojanjeCentara(k1,k2);
    if(Kugla::IstiDouble(d,k1.DajPoluprecnik()+k2.DajPoluprecnik())) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    if(Kugla::IstiDouble(k1.r,0) && Kugla::IstiDouble(k2.r,0) && DaLiSuIdenticne(k1,k2)) return true; 
    if(DaLiSuIdenticne(k1,k2) || DaLiSeSijeku(k1,k2)) return false;
    double d=RastojanjeCentara(k1,k2);
    if(Kugla::IstiDouble(d,fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()))) return true;
    return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    double d(RastojanjeCentara(k1,k2));
    return (d<(k1.DajPoluprecnik()+k2.DajPoluprecnik()));
}

int main (){
   int n;
    cout << "Unesite broj kugla: ";
     while (std::cin >> n, !cin || n<=0) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear(); std::cin.ignore(1000, '\n');
    }
    try {
        vector<shared_ptr<Kugla>> kugle(n);
        for(int i=0;i<n;i++) {
            std::tuple<double,double,double> centar;
            double r; 
            for(;;) {
                 for(;;){
                    cout << "Unesite centar " << i+1 << ". kugle: ";
                    cin >> std::get<0>(centar) >> std::get<1>(centar) >> std::get<2>(centar);
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout << "Neispravan centar" <<endl;
                    } else break;
                }
                cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
                cin >> r;
                if(r<0 || cin.fail()) {
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(1000,'\n');
                    }
                    cout << "Ilegalan poluprecnik" << endl;
                } else break;
            }
            kugle.at(i)=std::make_shared<Kugla>(Kugla(centar,r));
        }
        std::tuple<double,double,double> delta;
        cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        while( cin >> std::get<0>(delta) >> std::get<1>(delta) >> std::get<2>(delta), cin.fail()) {
            cout << "Neispravni parametri translacije, unesite ponovo!" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
        cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << endl;
        std::transform(kugle.begin(),kugle.end(),kugle.begin(),
        [delta](shared_ptr<Kugla> &k) {
            k->Transliraj(std::get<0>(delta),std::get<1>(delta),std::get<2>(delta));
            return k;
        });
        std::sort(kugle.begin(),kugle.end(),[](const shared_ptr<Kugla> &k1,const shared_ptr<Kugla> &k2) {
            return k1->DajZapreminu()<k2->DajZapreminu();
        });
        std::for_each(kugle.begin(),kugle.end(),[](const shared_ptr<Kugla> &k) {
            k->Ispisi();
        });
        cout << "Kugla sa najvecom povrsinom je: ";
        auto a=std::max_element(kugle.begin(),kugle.end(),[](const shared_ptr<Kugla> &k1,const shared_ptr<Kugla> &k2) {
            return k1->DajPovrsinu()<k2->DajPovrsinu();
        }); if(a!=kugle.end()) (*a)->Ispisi();
        int brojac {}, j {};
        std::for_each(kugle.begin(),kugle.end(),[&brojac,&kugle,&j](shared_ptr<Kugla> &k) {
            std::for_each(kugle.begin()+j+1,kugle.end(),[&k,&brojac](const shared_ptr<Kugla> &k1) {
                if(DaLiSeSijeku(*k,*k1)) {
                    cout <<"Presjecaju se kugle: ";
                    k->Ispisi();
                    cout << endl;
                    k1->Ispisi();
                    brojac++;
                    cout << endl;
                }
            } );
            j++;
        } );
        if(brojac==0) cout << "Ne postoje kugle koje se presjecaju!" << endl;
    } catch(std::exception &ex) {
        cout << ex.what();
    }
    return 0;
}
