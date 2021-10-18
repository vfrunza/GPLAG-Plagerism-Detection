#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double pi(4*atan(1));
const double eps=pow(10,-10);

class NepreklapajucaKugla
{
    double x,y,z;
    double poluprecnik;
    NepreklapajucaKugla *prethodni=nullptr;
    static NepreklapajucaKugla *posljednji;
    static bool Jednako (double k1,double k2) {
        if (abs(k1-k2)<=eps*(abs(k1)+abs(k2))) return true;
        return false;
    }
    static bool Preklapanje (const NepreklapajucaKugla &k2, const double &x, const double &y, const double &z, const double &r) {
        double udaljenost=sqrt((k2.DajX()-x)*(k2.DajX()-x)+(k2.DajY()-y)*(k2.DajY()-y)+(k2.DajZ()-z)*(k2.DajZ()-z));
        double duzina=r+k2.DajPoluprecnik();
        if (udaljenost<=duzina) return true;
        return false;
    }
public:
    explicit NepreklapajucaKugla (double r = 0) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        if (posljednji!=nullptr) {
            auto it (posljednji);
            for (it=posljednji; it!=nullptr; it=it->prethodni) {
                if (Preklapanje(*it,x,y,z,r)==true) throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        x=y=z=0;
        poluprecnik=r;
        this->prethodni=posljednji;
        posljednji=this;
    }
    NepreklapajucaKugla (double x, double y, double z, double r=0) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        if (posljednji!=nullptr) {
            auto it (posljednji);
            for (it=posljednji; it!=nullptr; it=it->prethodni) {
                if (Preklapanje(*it,x,y,z,r)==true) throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        poluprecnik=r;
        this->prethodni=posljednji;
        posljednji=this;
    }
    explicit NepreklapajucaKugla (const std::tuple<double, double, double> &centar, double r=0) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        if (posljednji!=nullptr) {
            auto it (posljednji);
            for (it=posljednji; it!=nullptr; it=it->prethodni) {
                if (Preklapanje(*it,std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),r)==true) throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        poluprecnik=r;
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        this->prethodni=posljednji;
        posljednji=this;
    }
    NepreklapajucaKugla (const NepreklapajucaKugla &k)=delete;
    NepreklapajucaKugla &operator =(const NepreklapajucaKugla &k)=delete;
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
        auto pom(std::make_tuple(x,y,z));
        return pom;
    }
    double DajPoluprecnik() const {
        return poluprecnik;
    }
    double DajPovrsinu() const {
        return 4*pi*poluprecnik*poluprecnik;
    }
    double DajZapreminu() const {
        return (4/3)*pi*poluprecnik*poluprecnik*poluprecnik;
    }
    NepreklapajucaKugla &PostaviX(double x) {
        if (posljednji!=nullptr) {
            auto it (posljednji);
            for (it=posljednji; it!=nullptr; it=it->prethodni) {
                if (Preklapanje(*it,x,y,z,poluprecnik)==true) throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        NepreklapajucaKugla::x=x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        if (posljednji!=nullptr) {
            auto it (posljednji);
            for (it=posljednji; it!=nullptr; it=it->prethodni) {
                if (Preklapanje(*it,x,y,z,poluprecnik)==true) throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        NepreklapajucaKugla::y=y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        if (posljednji!=nullptr) {
            auto it (posljednji);
            for (it=posljednji; it!=nullptr; it=it->prethodni) {
                if (Preklapanje(*it,x,y,z,poluprecnik)==true) throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        if (posljednji!=nullptr) {
            auto it (posljednji);
            for (it=posljednji; it!=nullptr; it=it->prethodni) {
                if (Preklapanje(*it,x,y,z,poluprecnik)==true) throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        if (posljednji!=nullptr) {
            auto it (posljednji);
            for (it=posljednji; it!=nullptr; it=it->prethodni) {
                if (Preklapanje(*it,std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),poluprecnik)==true) throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        NepreklapajucaKugla::x=std::get<0>(centar);
        NepreklapajucaKugla::y=std::get<1>(centar);
        NepreklapajucaKugla::z=std::get<2>(centar);
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        if (posljednji!=nullptr) {
            auto it (posljednji);
            for (it=posljednji; it!=nullptr; it=it->prethodni) {
                if (Preklapanje(*it,x,y,z,r)==true) throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        poluprecnik=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<poluprecnik<<"}"<<std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        if (posljednji!=nullptr) {
            auto it (posljednji);
            for (it=posljednji; it!=nullptr; it=it->prethodni) {
                if (Preklapanje(*it,x+delta_x,y+delta_y,z+delta_z,poluprecnik)==true) throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        NepreklapajucaKugla::x+=delta_x;
        NepreklapajucaKugla::y+=delta_y;
        NepreklapajucaKugla::z+=delta_z;
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
        double udaljenost=sqrt((k2.DajX()-k1.DajX())*(k2.DajX()-k1.DajX())+(k2.DajY()-k1.DajY())*(k2.DajY()-k1.DajY())+(k2.DajZ()-k1.DajZ())*(k2.DajZ()-k1.DajZ()));
        return udaljenost;
    }
};

NepreklapajucaKugla *NepreklapajucaKugla::posljednji=nullptr;

int main ()
{
    try {
        std::cout<<"Unesite broj kugli: ";
        int n;
        for (;;) {
            std::cin>>n;
            if (n<=0 || !std::cin) {
                std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                continue;
            } else break;
        }
        std::vector<std::shared_ptr<NepreklapajucaKugla>> vektor;
        for (int i=1; i<=n; i++) {
            try {
                std::cout<<"Unesite centar za "<<i<<". kuglu: ";
                double x,y,z;
                for (;;) {
                    std::cin>>x>>y>>z;
                    if (!std::cin) {
                        std::cout<<"Neispravan centar, unesite ponovo:"<<std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        continue;
                    }
                    break;
                }
                std::cout<<"Unesite poluprecnik: ";
                double r;
                for (;;) {
                    std::cin>>r;
                    if (!std::cin || r<0) {
                        std::cout<<"Neispravan poluprecnik, unesite ponovo:"<<std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        continue;
                    }
                    break;
                }
                auto pom (std::make_shared<NepreklapajucaKugla>(x,y,z,r));
                vektor.push_back(pom);
            } catch (std::logic_error l) {
                std::cout<<l.what()<<std::endl;
                i--;
            }
        }
        std::cout<<std::endl<<"Kugle nakon obavljenog sortiranja: "<<std::endl;
        std::sort (vektor.begin(),vektor.end(),[] (std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2) {
            return k1->DajPovrsinu()<k2->DajPovrsinu();
        });
        std::for_each (vektor.begin(),vektor.end(),[] (std::shared_ptr<NepreklapajucaKugla> k) {
            k->Ispisi();
        });
    } catch (std::logic_error l) {
        std::cout<<l.what()<<std::endl;
    }
    return 0;
}
