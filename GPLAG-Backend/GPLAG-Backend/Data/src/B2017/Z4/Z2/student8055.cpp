
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#define PI 4*std::atan(1)
#include <algorithm>
#include <memory>
#include <vector>

bool JesuLiJednaki (double x, double y, double Eps = 1e-10) {
    return std::fabs(x-y) <= Eps * (std::fabs(x) + std::fabs(y));
}

class NepreklapajucaKugla {
    double x, y, z, r;
    void testNaPreklapanje();
    std::shared_ptr<NepreklapajucaKugla> posljednja;
    static std::shared_ptr<NepreklapajucaKugla> posljednjaKreirana;

public:
    NepreklapajucaKugla (const NepreklapajucaKugla &k)= delete; //Zabrana kopiranja
    NepreklapajucaKugla &operator  = (const NepreklapajucaKugla &k)= delete; //Zabrana dodjele
    ~NepreklapajucaKugla ();
    explicit NepreklapajucaKugla(double r = 0) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        NepreklapajucaKugla::r = r;
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0){
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        posljednja = posljednjaKreirana;
        posljednjaKreirana = std::shared_ptr<NepreklapajucaKugla> (this);
        NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z; NepreklapajucaKugla::r=r;
        testNaPreklapanje();
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> & centar, double r = 0){
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=std::get<0>(centar); NepreklapajucaKugla::y=std::get<1>(centar); NepreklapajucaKugla::z=std::get<2>(centar); NepreklapajucaKugla::r=r;
    }
    double DajX() const {
        return x;
    }
    double DajY() const {
        return y;
    };
    double DajZ() const {
        return z;
    };
    std::tuple<double, double, double> DajCentar() const {
        return std::make_tuple(x, y, z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*PI*r*r;
    }
    double DajZapreminu() const {
        return 4/3*PI*r*r*r;
    }
    NepreklapajucaKugla &PostaviX(double x) {
        NepreklapajucaKugla::x = x;
        testNaPreklapanje();
        return *this;
    }
    NepreklapajucaKugla & PostaviY(double y) {
        NepreklapajucaKugla::y = y;
        testNaPreklapanje();
        return *this;
    }
    NepreklapajucaKugla & PostaviZ(double z) {
        NepreklapajucaKugla::z = z;
        testNaPreklapanje();
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z;
        testNaPreklapanje();
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> & centar){
        NepreklapajucaKugla::x = std::get<0> (centar);
        NepreklapajucaKugla::y = std::get<1> (centar);
        NepreklapajucaKugla::z = std::get<2> (centar);
        testNaPreklapanje();
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r){
        NepreklapajucaKugla::r = r;
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        testNaPreklapanje();
        return *this;
    }
    int dajBrojElemenata () const ;
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}\n";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        x+=delta_x; y+=delta_y; z+=delta_z;
        testNaPreklapanje();
    }

    friend double RastojanjeCentara(const NepreklapajucaKugla & k1, const NepreklapajucaKugla & k2);
};
std::shared_ptr<NepreklapajucaKugla> NepreklapajucaKugla::posljednjaKreirana(nullptr);
double RastojanjeCentara (double x1, double y1, double z1,
                          double x2, double y2, double z2) {
    return std::sqrt (  (x1-x2)*(x1-x2)+
                        (y1-y2)*(y1-y2)+
                        (z1-z2)*(z1-z2)
    );
}



void NepreklapajucaKugla::testNaPreklapanje()
{
    for (auto it=posljednjaKreirana->posljednja; it!=nullptr; it=it->posljednja){
        //if (posljednja == nullptr) break; 
        if (RastojanjeCentara(it->x, it->y, it->z, posljednjaKreirana->x, posljednjaKreirana->y, posljednjaKreirana->z) <  (it->r +posljednjaKreirana->r)
                ) {
            posljednjaKreirana=posljednjaKreirana->posljednja;
            posljednja=nullptr;
            throw std::logic_error ("Nedozvoljeno preklapanje");
        }
    }
}
int NepreklapajucaKugla::dajBrojElemenata() const {

    int i(0);
    for (auto it=posljednjaKreirana; it!=nullptr; it=it->posljednja){
        i++;
    }
    return i;
}

NepreklapajucaKugla::~NepreklapajucaKugla() {
    std::cout<<"keno";
    // posljednjaKreirana = nullptr;
/*if (dajBrojElemenata()==0) return;
auto it1 (posljednjaKreirana);
int j(0);
for (int i=0; i<dajBrojElemenata(); i++) {
    if (it1 == posljednja ) {j = i-1; break; }
}
if (j==0){
if (dajBrojElemenata()==1) posljednjaKreirana = nullptr;
else {posljednjaKreirana = posljednjaKreirana->posljednja;
}
}
else if (posljednja == nullptr) {
auto it ( posljednjaKreirana);
for (int i=0; i<dajBrojElemenata()-2; i++)
    {it = it->posljednja;}
it->posljednja = nullptr;
}
else   {
auto it2 (posljednjaKreirana);
for (int i=0; i<j-1; i++)
    {it2 = it2-> posljednja; }
it2->posljednja = it1;
}
*/
}
typedef std::shared_ptr<NepreklapajucaKugla> pametni;
int main ()
{
    int n;
    std::cout<<"Unesite broj kugli: ";
    std::cin>>n;
    std::vector<pametni> vektor;
    double x,y,z,r;
    for (int i=1; i<=n; i++){
        try {
            std::cout<<"Unesite centar za "<<i<<". kuglu: ";
            std::cin>>x;
            if (!std::cin) throw std::domain_error("Ilegalan unos!");
            std::cin>>y;
            if (!std::cin) throw std::domain_error("Ilegalan unos!");
            std::cin>>z;
            if (!std::cin) throw std::domain_error("Ilegalan unos!");
            std::cout<<"Unesite poluprecnik: ";
            std::cin>>r;
            if (!std::cin) throw std::domain_error("Ilegalan unos!");
            //auto p (std::make_shared<NepreklapajucaKugla> (NepreklapajucaKugla(x,y,z,r)));
            std::shared_ptr<NepreklapajucaKugla> p (new NepreklapajucaKugla(x,y,z,r)) ;
            vektor.push_back( p) ;
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<"\n";
            i--;
            std::cin.ignore (10000, '\n');
        }
        catch (std::logic_error e) {
            std::cout<<e.what()<<"\n";
            i--;
            std::cin.ignore (10000, '\n');
        }
    }

/*    std::sort (std::begin(vektor), std::end(vektor), [](pametni k1, pametni k2) { return  (k1->DajPovrsinu() ) < (k2->DajPovrsinu() ); } );
     std::cout<<"Kugle nakon obavljenog sortiranja: ";
     std::for_each (std::begin(vektor), std::end(vektor), [](pametni &k) {k->Ispisi();} );*/
    return 0;
}

