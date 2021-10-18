/B2017/2018: Zadaća 4, Zadatak 2
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

class NepreklapajucaKugla {
    double x, y, z, r;
    NepreklapajucaKugla* prethodni;
    static NepreklapajucaKugla* posljedni;
    bool Jednakost(double x, double y) { if ((fabs(x-y))<10e-10*(fabs(x)+fabs(y))) return true; return false;}
    double RastojanjeCentara(double x, double y, double z, const NepreklapajucaKugla &k1) {
        return sqrt(pow(x-k1.x, 2)+pow(y-k1.y, 2)+pow(z-k1.z, 2));
    }
    bool PreklapaLiSe (double x, double y, double z, double r, const NepreklapajucaKugla &k1) {
        if(k1.r+r>=RastojanjeCentara(x, y, z, k1)) return true;
        return false;
    }
    void PreklapanjeSaOstalima (double x, double y, double z, double r) {
       for(auto klizeci(NepreklapajucaKugla::posljedni); klizeci!=nullptr; klizeci=klizeci->prethodni)
            if(PreklapaLiSe(x, y, z, r, *klizeci)) throw std::logic_error("Nedozvoljeno preklapanje");
    }
public:
    explicit NepreklapajucaKugla (double r=0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        PreklapanjeSaOstalima(0, 0, 0, r);
        if(posljedni==nullptr) { posljedni=this; prethodni=nullptr;}
        else {prethodni=posljedni; posljedni=this;}
        x=0; y=0; z=0; NepreklapajucaKugla::r=r;
    }
    NepreklapajucaKugla (double x, double y, double z, double r=0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        PreklapanjeSaOstalima(x, y, z, r);
        if(posljedni==nullptr) {posljedni=this;prethodni=nullptr;}
        else { prethodni=posljedni; posljedni=this;}
        NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z; NepreklapajucaKugla::r=r;
    }
    explicit NepreklapajucaKugla (const std::tuple<double, double, double> &centar, double r=0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        PreklapanjeSaOstalima(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r);
        if(posljedni==nullptr) { posljedni=this; prethodni=nullptr; }
        else { prethodni=posljedni; posljedni=this;}
        NepreklapajucaKugla::x=std::get<0>(centar); NepreklapajucaKugla::y=std::get<1>(centar); NepreklapajucaKugla::z=std::get<2>(centar); NepreklapajucaKugla::r = r;
    }
    double DajX() const {return x;}
    double DajY() const {return y;}
    double DajZ() const {return z;}
    std::tuple<double, double, double> DajCentar () const { return std::make_tuple(x, y, z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*PI; }
    double DajZapreminu() const { return (4/3)*r*r*r*PI; }
    NepreklapajucaKugla &PostaviX (double x){PreklapanjeSaOstalima(x, y, z, r); NepreklapajucaKugla::x=x; return *this;}
    NepreklapajucaKugla &PostaviY (double y){PreklapanjeSaOstalima(x, y, z, r); NepreklapajucaKugla::y=y; return *this;}
    NepreklapajucaKugla &PostaviZ (double z){PreklapanjeSaOstalima(x, y, z, r); NepreklapajucaKugla::z=z; return *this;}
    NepreklapajucaKugla &PostaviCentar (double x, double y, double z) {
        PreklapanjeSaOstalima(x, y, z, r);
        NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z; 
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar (const std::tuple<double, double, double> &centar) {
        PreklapanjeSaOstalima(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r);
        NepreklapajucaKugla::x=std::get<0>(centar); NepreklapajucaKugla::y=std::get<1>(centar); NepreklapajucaKugla::z=std::get<2>(centar); 
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik (double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        PreklapanjeSaOstalima(x, y, z, r);
        NepreklapajucaKugla::r=r; 
        return *this;
    }
    ~NepreklapajucaKugla() {
        if(this!=posljedni) {
            NepreklapajucaKugla *temp;
            for(temp=posljedni; temp->prethodni!=this; temp=temp->prethodni);
            temp->prethodni = this->prethodni;
        }
        else 
            posljedni=this->prethodni;
    }
    NepreklapajucaKugla& operator =(NepreklapajucaKugla &&k1);
    NepreklapajucaKugla (NepreklapajucaKugla &&k1);
    void Ispisi() const {std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl;}
    void Transliraj (double delta_x, double delta_y, double delta_z) { x+=delta_x; y+=delta_y; z+=delta_z; }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};
NepreklapajucaKugla* NepreklapajucaKugla::posljedni=nullptr;
double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {return sqrt(pow(k2.x-k1.x, 2)+pow(k2.y-k1.y, 2)+pow(k2.z-k1.z, 2));}
NepreklapajucaKugla& NepreklapajucaKugla::operator =(NepreklapajucaKugla &&k1) {
    PreklapanjeSaOstalima(k1.x, k1.y, k1.z, k1.r);
    *this = std::move(k1);
    return *this;
}
NepreklapajucaKugla::NepreklapajucaKugla(NepreklapajucaKugla &&k1) {PreklapanjeSaOstalima(k1.x, k1.y, k1.z, k1.r); *this = std::move(k1);}
Parametri UnosKugle (double &x, double &y, double &z, double &r, int &brojac) {
    cout << "Unesite centar za " << brojac+1 << ". kuglu: ";
    do {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        cin >> x >> y >> z;
        if(!cin) {
            cout << "Neispravan centar, unesite ponovo: " << endl;
            continue;
        }
        cout << "Unesite poluprecnik: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> r;
        if (!cin || r<0) {
            do {
                cout << "Neispravan poluprecnik, unesite ponovo: " << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                cin >> r;
            } while (!cin || r<0);
        }
    } while (!cin);
    return std::make_tuple(x, y, z, r);
}

typedef std::vector<std::shared_ptr<NepreklapajucaKugla>> VK;
int main()
{
    cout << "Unesite broj kugli: ";
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
        try {
            Kugle.push_back(std::make_shared<NepreklapajucaKugla>(std::get<0>(pom), std::get<1>(pom), std::get<2>(pom), std::get<3>(pom)));
        } catch (std::logic_error &poruka) {
            cout << poruka.what() << endl;
            i--;
            continue;
        }
    }          
    cout << endl << "Kugle nakon obavljenog sortiranja: " << endl;
    std::sort(Kugle.begin(), Kugle.end(), [](std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2)->bool {return k1->DajPovrsinu()<k2->DajPovrsinu();});
    std::for_each(Kugle.begin(), Kugle.end(), [](const std::shared_ptr<NepreklapajucaKugla> &k)->void {k->Ispisi();});
    return 0;
}
         