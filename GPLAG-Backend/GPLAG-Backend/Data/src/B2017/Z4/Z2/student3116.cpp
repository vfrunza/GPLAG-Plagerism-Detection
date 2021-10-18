#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

// ??? da li se preklapaju i da li sadrzi
static constexpr double PI=4*atan(1.); 

//logic error iz konstruktora
//izuzetak iz svih mutatora
//test na preklapanje kao privatna fja

bool IsteTacke (const double &a, const double &b)
{
    double eps(std::pow(10 , -10));
    return std::fabs(a-b)<eps*(std::fabs(a)+std::fabs(b));
}

class NepreklapajucaKugla
{
    double x, y, z, r;
    static Kugla *
    bool TestNaPreklapanje;
public:
    explicit NepreklapajucaKugla (double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=0;
        y=0;
        z=0;
    };
    NepreklapajucaKugla (double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
    };
    explicit NepreklapajucaKugla (const std::tuple<double, double, double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        double a, b, c;
        std::tie(a,b,c)=centar;
        NepreklapajucaKugla::x=a;
        NepreklapajucaKugla::y=b;
        NepreklapajucaKugla::z=c;
        NepreklapajucaKugla::r=r;
    };
    double DajX() const {
        return x;
    };
    double DajY() const {
        return y;
    };
    double DajZ() const {
        return z;
    };
    std::tuple<double, double, double> DajCentar() const { 
        double a(x), b(y), c(z);
        return std::tie<double, double, double>(a, b, c);
    };
    double DajPoluprecnik() const {
        return r;
    };
    double DajPovrsinu() const {
        return 2*PI*r*r;
    };
    double DajZapremninu() const {
        return 4/3*r*r*r*PI;
    };
    NepreklapajucaKugla &PostaviX(double x) {
        NepreklapajucaKugla::x=x;
        return *this;
    };
    NepreklapajucaKugla &PostaviY(double y) {
        NepreklapajucaKugla::y=y;
        return *this;
    };
    NepreklapajucaKugla &PostaviZ(double z) {
        NepreklapajucaKugla::z=z;
        return *this;
    };
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        return *this;
    };
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
        return *this;
    };
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
    };
    void Transliraj (double delta_x, double delta_y, double delta_z) {          
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    };
    bool DaLiSadrzi (const NepreklapajucaKugla &k) const;
    friend double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

/*bool NepreklapajucaKugla::DaLiSadrzi (const NepreklapajucaKugla &k) const
{
    //da li kugla nad kojoj je pozvana metoda sadrzi kuglu k
    double veci(0), manji(0);
    if(r>k.r) {veci=r; manji=k.r; }
    else {veci=k.r; manji=r;}
    return RastojanjeCentara(*this, k)<std::sqrt((veci-manji)*(veci-manji)) || 
        DaLiSuIdenticne(*this, k); // || DaLiSeDodirujuIznutra(*this,k);
}*/

NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{
    double a, b, c;
    std::tie(a,b,c)=centar;
    NepreklapajucaKugla::x=a;
    NepreklapajucaKugla::y=b;
    NepreklapajucaKugla::z=c;
    return *this;
}

double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)                     
{
    return std::sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)
                     +(k2.z-k1.z)*(k2.z-k1.z));
}

int main () 
{
    /*Kugla k1(1,1,1,2), k2(1,0, 1, 3);
    std::cout<<std::boolalpha<<k2.DaLiSadrzi(k1);*/
    int n;
    std::cout<<"Unesite broj kugli: ";
    for(;;) {
        std::cin>>n;
        if(!std::cin || n<=0 || n!=int(n))
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl; //peek
        else break;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> kugle;
    double a,b,c,r;
    for(int i=0; i<n; i++) {
        for(;;) {
            std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
            std::cin>>a>>b>>c;
            if(!std::cin) {
                std::cout<<"Neispravan centar"<<std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Unesite poluprecnik: ";
            std::cin>>r;
            if(!std::cin || r<0)
                std::cout<<"Ilegalan poluprecnik"<<std::endl;
            else break;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        try {
            std::shared_ptr<NepreklapajucaKugla> pom(std::make_shared<NepreklapajucaKugla> (NepreklapajucaKugla(a,b,c,r)));
            kugle.push_back(pom);
        } catch (std::domain_error izuzetak) {                                 
            std::cout<<izuzetak.what()<<std::endl;
            i--;
        }
    }
    
    std::cout<<std::endl<<"Kugle nakon obavljanog sortiranja: "<<std::endl;
    std::sort(kugle.begin(), kugle.end(),
        [] (std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2) {
        return k1->DajPovrsinu()<k2->DajPovrsinu();
    });

    std::for_each(kugle.begin(), kugle.end(), [] (std::shared_ptr<NepreklapajucaKugla> k) {
        k->Ispisi();
    });
    

    //bool  sijeku_se(false);
    
    /*for(int i=0; i<n-1; i++) {
        for(int j=1; j<n; j++) {
            if(DaLiSeSjeku(*kugle[i], *kugle[j])) {
                std::cout<<"Presjecaju se kugle: ";
                kugle[i]->Ispisi();
                kugle[j]->Ispisi();
                sijeku_se=true;
            }
        }
    }
    if(sijeku_se==false) std::cout<<"Ne postoje kugle koje se presjecaju!";*/
    return 0;
}
