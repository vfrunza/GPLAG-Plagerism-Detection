/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector> 
#include <climits>

using std::cin;
using std::cout;
using std::endl;
typedef std::tuple<double, double, double, double> Parametri;

const double PI=4*atan(1);
bool Jednakost(double x, double y) { if ((fabs(x-y))<10e-10*(fabs(x)+fabs(y))) return true; return false;}

class Kugla {
    double x, y, z, r;
    bool Jednake(double x, double y) { if ((fabs(x-y))<10e-10*(fabs(x)+fabs(y))) return true; return false;}
public:
    explicit Kugla (double r=0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=0; y=0; z=0; Kugla::r=r;
    }
    Kugla (double x, double y, double z, double r=0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r;
    }
    explicit Kugla (const std::tuple<double, double, double> &centar, double r=0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=std::get<0>(centar); Kugla::y=std::get<1>(centar); Kugla::z=std::get<2>(centar); Kugla::r = r;
    }
    double DajX() const {return x;}
    double DajY() const {return y;}
    double DajZ() const {return z;}
    std::tuple<double, double, double> DajCentar () const { return std::make_tuple(x, y, z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*PI; }
    double DajZapreminu() const { return (4/3)*r*r*r*PI; }
    Kugla &PostaviX (double x){ Kugla::x=x; return *this;}
    Kugla &PostaviY (double y){ Kugla::y=y; return *this;}
    Kugla &PostaviZ (double z){ Kugla::z=z; return *this;}
    Kugla &PostaviCentar (double x, double y, double z) { Kugla::x=x; Kugla::y=y; Kugla::z=z; return *this;}
    Kugla &PostaviCentar (const std::tuple<double, double, double> &centar) {
        Kugla::x=std::get<0>(centar); Kugla::y=std::get<1>(centar); Kugla::z=std::get<2>(centar); return *this;
    }
    Kugla &PostaviPoluprecnik (double r) {if(r<0) throw std::domain_error("Ilegalan poluprecnik"); Kugla::r=r; return *this;}
    void Ispisi() const {std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl;}
    bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2) {
            if (Jednake(k1.x, k2.x) && Jednake(k1.y, k2.y) && Jednake(k1.z, k2.z) && Jednake(k1.r, k2.r)) return true;
            return false;
    }
    bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2) { if(Jednake(k1.r, k2.r)) return true; return false; }
    bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2) { if(Jednake(k1.x, k2.x) && Jednake(k1.y, k2.y) && Jednake(k1.z, k2.z)) return true; return false;}
    void Transliraj (double delta_x, double delta_y, double delta_z) { x+=delta_x; y+=delta_y; z+=delta_z; }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const {return RastojanjeCentara(*this, k)<this->r+k.r;}
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {return Jednakost(RastojanjeCentara(k1, k2), k1.r+k2.r);}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {return Jednakost(RastojanjeCentara(k1, k2), fabs(k2.r-k1.r));}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {return RastojanjeCentara(k1, k2)<k2.r+k1.r;}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {return DaLiSePreklapaju(k1, k2) && (RastojanjeCentara(k1, k2)>fabs(k2.r-k1.r));}  
double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {return sqrt(pow(k2.x-k1.x, 2)+pow(k2.y-k1.y, 2)+pow(k2.z-k1.z, 2));}

Parametri UnosKugle (double &x, double &y, double &z, double &r, int &brojac) {
    
    do {
        cout << "Unesite centar " << brojac+1 << ". kugle: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> x >> y >> z;
        if(!cin) {
            cout << "Neispravan centar" << endl;
            continue;
        }
        cout << "Unesite poluprecnik " << brojac+1 << ". kugle: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> r;
        if (!cin || r<0) {
            cout << "Ilegalan poluprecnik" << endl;
            continue;
        }
    } while (!cin || r<0);
    
    return std::make_tuple(x, y, z, r);
}

typedef std::vector<std::shared_ptr<Kugla>> VK;

int main()
{
    cout << "Unesite broj kugla: ";
    int n;
    cin >> n;
    if(n<=0 || !cin) {
        cout << "Neispravan broj kugli, unesite ponovo!" << endl;
        do {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> n;
            if (!cin || n<=0) cout << "Neispravan broj kugli, unesite ponovo!" << endl;
        } while (n<=0 || !cin);
    }
    VK Kugle;
    for (int i(0); i<n; i++) {
        double x, y, z, r;
        Parametri pom = UnosKugle(x, y, z, r, i);
        Kugle.push_back(std::make_shared<Kugla>(std::get<0>(pom), std::get<1>(pom), std::get<2>(pom), std::get<3>(pom)));
    }
    cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx, dy, dz;
    cin >> dx >> dy >> dz;
    if(!cin) {
        cout << "Neispravni parametri translacije, unesite ponovo!" << endl;
        do {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> dx >> dy >> dz;
            if(!cin) cout << "Neispravni parametri translacije, unesite ponovo!" << endl;
        } while (!cin);
    }
    std::transform(Kugle.begin(), Kugle.end(), Kugle.begin(), [dx, dy, dz](std::shared_ptr<Kugla> k) {k->Transliraj(dx, dy, dz); return k; });
    cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << endl;
    std::sort(Kugle.begin(), Kugle.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2)->bool {return k1->DajZapreminu()<k2->DajZapreminu();});
    std::for_each(Kugle.begin(), Kugle.end(), [](const std::shared_ptr<Kugla> &k)->void {k->Ispisi();});
    auto max(std::max_element(Kugle.begin(), Kugle.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){return k1->DajPovrsinu()<k2->DajPovrsinu();}));
    cout << "Kugla sa najvecom povrsinom je: ";
    (**max).Ispisi();
    int brojac1(0);
    std::for_each(Kugle.begin(), Kugle.end(), [&brojac1, Kugle](std::shared_ptr<Kugla> k1) { 
        std::for_each(Kugle.begin()+brojac1, Kugle.end(), [&brojac1, k1, Kugle](std::shared_ptr<Kugla> k2) {
            if(DaLiSeSijeku(*k1, *k2)) {
                cout << "Presjecaju se kugle: "; 
                k1->Ispisi(); k2->Ispisi(); brojac1++;
        }});
    });
    
    if(brojac1==0) cout << "Ne postoje kugle koje se presjecaju!";
    
    return 0;
}
