/B2017/2018: Zadaća 4, Zadatak 2


//Napomena: kopiran kod sa zadatka 1


#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>

const double PI=4*std::atan (1);
const double Eps(1e-10);

class NepreklapajucaKugla
{
    double X, Y, Z, R;

public:

    explicit NepreklapajucaKugla (double r=0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        X=0;
        Y=0;
        Z=0;
        R=r;
    }

    NepreklapajucaKugla (double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        X=x;
        Y=y;
        Z=z;
        R=r;
    }

    explicit NepreklapajucaKugla (const std::tuple<double, double, double> &centar, double r=0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        X=std::get<0>(centar);
        X=std::get<1>(centar);
        Z=std::get<2>(centar);
        R=r;
    }

    double DajX () const {
        return X;
    }

    double DajY () const {
        return Y;
    }

    double DajZ () const {
        return Z;
    }

    std::tuple<double, double,double> DajCentar () const {
        std::tuple<double, double, double> t (std::make_tuple(X, Y, Z));
        return t;
    }

    double DajPoluprecnik () const {
        return R;
    }

    double DajPovrsinu () const {
        return 4*R*R*PI;
    }

    double DajZapreminu () const {
        return 4*R*R*R*PI/3.;
    }

    NepreklapajucaKugla &PostaviX (double x) {
        X=x;
        return *this;
    }

    NepreklapajucaKugla &PostaviY (double y) {
        Y=y;
        return *this;
    }

    NepreklapajucaKugla &PostaviZ (double z) {
        Z=z;
        return *this;
    }

    NepreklapajucaKugla &PostaviCentar (double x, double y, double z) {
        X=x;
        Y=y;
        Z=z;
        return *this;
    }

    NepreklapajucaKugla &PostaviCentar (const std::tuple<double, double, double> &centar) {
        X=std::get<0>(centar);
        Y=std::get<1>(centar);
        Z=std::get<2>(centar);
        return *this;
    }

    NepreklapajucaKugla &PostaviPoluprecnik (double r) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        R=r;
        return *this;
    }

    void Ispisi () const {
        std::cout<<"{("<<X<<","<<Y<<","<<Z<<"),"<<R<<"}\n";
    }

    void Transliraj (double delta_x, double delta_y, double delta_z) {
        X+=delta_x;
        Y+=delta_y;
        Z+=delta_z;
    }

    friend double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
        return std::sqrt(pow(k2.X-k1.X,2)+pow(k2.Y-k1.Y,2)+pow(k2.Z-k1.Z,2));
    }
};

int main ()
{
    int n;
    std::cout<<"Unesite broj kugli: ";
    for(;;) {
        bool pom(true);
        std::cin>>n;
        if(!std::cin || n<=0)
            pom=false;
        if(pom) break;
        std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    std::vector<std::shared_ptr<NepreklapajucaKugla>> v;

    for(int i=0; i<n; i++) {
        double x,y,z,r;
        std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
        for(;;) {
            bool pom_x(true), pom_y(true), pom_z(true);
            std::cin>>x;
            if(!std::cin) pom_x=false;
            std::cin>>y;
            if(!std::cin) pom_y=false;
            std::cin>>z;
            if(!std::cin) pom_z=false;
            if(pom_x && pom_y && pom_z) break;
            else {
                std::cout<<"Neispravan centar, unesite ponovo:\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        }
        std::cout<<"Unesite poluprecnik: ";
        for(;;) {
            std::cin>>r;
            if(!std::cin || r<0) {
                std::cout<<"Neispravan poluprecnik, unesite ponovo: \n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            } else break;
        }

        try {
            auto pok=new NepreklapajucaKugla(x,y,z,r);
            v.push_back(std::shared_ptr<NepreklapajucaKugla>(pok));
        } catch (std::bad_alloc) {
            std::cout<<"Problem sa memorijom!";
        } catch (std::domain_error izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;
        } catch(...) {}
    }

    std::sort (v.begin(), v.end(), [] (const std::shared_ptr<NepreklapajucaKugla> &k1, const std::shared_ptr<NepreklapajucaKugla> &k2) {
        return k1->DajPovrsinu()<k2->DajPovrsinu();
    });

    std::cout<<"\nKugle nakon obavljenog sortiranja: \n";

    for_each(v.begin(), v.end(), [] (const std::shared_ptr<NepreklapajucaKugla> &k)->void {k->Ispisi();});

    return 0;
}
