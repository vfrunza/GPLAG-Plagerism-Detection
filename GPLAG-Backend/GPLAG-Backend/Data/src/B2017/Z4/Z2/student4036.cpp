/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <vector>
#include <iomanip>
#include <utility>
#include <memory>
#include <algorithm>

bool JesuLiJednake(double x, double y, double eps=1e-10)
{
    if((x<0 && y>0) || (x>0 && y<0)) return false;
    return std::fabs(x-y) <= eps*(std::fabs(x)+ std::fabs(y));
}
/*bool Preklapanje (NepreklapajucaKugla k1, NepreklapajucaKugla k2){
    if(std::fabs(k1.r-k2.r) < RastojanjeCentara(k1,k2) && RastojanjeCentara(k1,k2) < k1.r+k2.r && !(RastojanjeCentara(k1,k2) > std::fabs(k1.r+k2.r)))
        return true;
    return false;
}*/

//moram imati i fjjuu obrisiii
/*void Obrisi(struct Cvor* p){
    struct Cvor *p=pocetak;
    while (pocetak!= nullptr) {
        p=pocetak;
        pocetak=pocetak->next;
        delete p;
    }
}*/

const double PI(4*atan(1));

class NepreklapajucaKugla
{
    
    static NepreklapajucaKugla *posljednja;
    NepreklapajucaKugla *prethodni();
    double x,y,z,r;
    
public:
    explicit NepreklapajucaKugla(double r = 0) {
        //ovdje treba da baci error ovdje se stvaraju kugle znaci ako se preklapaju baci error unesi ponovo
        while (prethodni != nullptr) {
            if(!(Preklapanje(*posljednja, *prethodni))) throw std::logic_error ("Nedozvoljeno preklapanje");
        }
        x=0;
        y=0;
        z=0;
        prethodni=this;
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0) {
        //if(!(Preklapanje())) throw std::logic_error("Nedozvoljeno preklapanje");
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
        //if(!(Preklapanje())) throw std::logic_error("Nedozvoljeno preklapanje");
        double x1,y1,z1;
        std::tie(x1,y1,z1)=centar;
        x=x1; y=y1; z=z1;
        NepreklapajucaKugla::r=r;
    }
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
        return std::make_tuple(x,y,z);
    }

    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*PI*pow(r,2);
    }
    double DajZapreminu() const {
        return 4*pow(r,3)*PI/3.;
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
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }

   
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const {
        double d(sqrt((std::fabs(pow(x-k.x,2) + pow(y-k.y,2) + pow(z-k.z,2)))));
        if(d<std::fabs(r-k.r)) return true;
        return false;
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);

};
//NepreklapajucaKugla NepreklapajucaKugla::posljednja=nullptr;



double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    double d(sqrt(pow(k1.x-k2.x,2)+pow(k1.y-k2.y,2)+ pow(k1.z-k2.z, 2)));
    return d;
}
int main ()
{
    int n;
    NepreklapajucaKugla kuglica;
    std::cout << "Unesite broj kugli: ";
    std::cin >> n;

    while(n<=0 || !std::cin) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> n;
    }


    std::vector<std::shared_ptr<NepreklapajucaKugla>> vektor(n);

    for(int i=0; i<n; i++) {
        double x,y,z,r;
        try {
            do {
                std::cin.clear();
                std::cin.ignore(1000,'\n');

                std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
                std::cin >> x >> y >> z;

                if(!std::cin) {
                    std::cout << "Neispravan centar" << std::endl;
                    std::cin >> x >> y >> z;
                    continue;
                }
                std::cout << "Unesite poluprecnik: ";
                std::cin >> r;
                if(!std::cin) {
                    std::cout << "Ilegalan poluprecnik" << std::endl;
                }
            } while(!std::cin);
            kuglica.PostaviX(x);
            kuglica.PostaviY(y);
            kuglica.PostaviZ(z);
            kuglica.PostaviPoluprecnik(r);
            vektor[i]=std::make_shared<NepreklapajucaKugla>(kuglica);
        } catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            i--;
        } catch(std::bad_alloc izuzetak) {
            std::cout << "Nema dovoljno memorije!" << std::endl;
            return 0;
        } catch(std::logic_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            i--;
        }
    }

    std::cout << std::endl << "Kugle nakon obavljenog sortiranja: " << std::endl;
   

    std::sort(vektor.begin(), vektor.end(), [](const std::shared_ptr<NepreklapajucaKugla> &p1, const std::shared_ptr<NepreklapajucaKugla> &p2) {
        return p1->DajPovrsinu()<p2->DajPovrsinu();
    });


    for_each(vektor.begin(), vektor.end(), [](const std::shared_ptr<NepreklapajucaKugla> &p) {
        p->Ispisi();
    });
  




    return 0;
}