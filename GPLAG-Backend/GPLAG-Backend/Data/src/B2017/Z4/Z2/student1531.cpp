/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <vector>
#include <memory>
#include <algorithm>


class NepreklapajucaKugla
{
    double x, y, z;
    double r;
    NepreklapajucaKugla *p;   //pokazuje na prethodno kreiranu kuglu
    static NepreklapajucaKugla *posljednji; //pokazuje na posljednju kreiranu kuglu
    static constexpr double PI {4.*(std::atan(1))};

    static bool JesuLiJednaki(double x, double y, double Eps = 1e-10) {
        return ( std::fabs(x-y) <= Eps*(std::fabs(x)+std::fabs(y)) );
    }
    bool DaLiSePreklapaju(NepreklapajucaKugla *nova, NepreklapajucaKugla *k, NepreklapajucaKugla *kraj) {
        for(NepreklapajucaKugla *temp = k; temp!=kraj; temp = temp->p) {
            if( (temp->r + nova->r) >= RastojanjeCentara(*temp, *nova) ) return true;
        }
        return false;
    }

public:
    explicit NepreklapajucaKugla(double r = 0) : x(0), y(0), z(0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r = r;
        if(!DaLiSePreklapaju(this, posljednji, nullptr)) { //ispitaj preklapanje do kraja
            p = posljednji;
            posljednji = this;
        } else {
            p = nullptr;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0) : x(x), y(y), z(z) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r = r;
        if(!DaLiSePreklapaju(this, posljednji, nullptr)) {
            p = posljednji;
            posljednji = this;
        } else {
            p = nullptr;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
        NepreklapajucaKugla::r = r;
        if(!DaLiSePreklapaju(this, posljednji, nullptr)) {
            p = posljednji;
            posljednji = this;
        } else {
            p = nullptr;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
    }
    NepreklapajucaKugla (const NepreklapajucaKugla &k) = delete;
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
        std::tuple<double, double, double> t {x, y, z};
        return t;
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4.*r*r*PI;
    }
    double DajZapreminu() const {
        return (4*PI*r*r*r)/3.;
    }
    NepreklapajucaKugla &PostaviX(double x) {   //OVDJE
        NepreklapajucaKugla::x = x;
        if(DaLiSePreklapaju(this, this->p, nullptr)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        if(DaLiSePreklapaju(this, posljednji, this)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        NepreklapajucaKugla::y = y;
        if(DaLiSePreklapaju(this, this->p, nullptr)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        if(DaLiSePreklapaju(this, posljednji, this)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        NepreklapajucaKugla::z = z;
        if(DaLiSePreklapaju(this, this->p, nullptr)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        if(DaLiSePreklapaju(this, posljednji, this)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        NepreklapajucaKugla::x = x;
        NepreklapajucaKugla::y = y;
        NepreklapajucaKugla::z = z;
        if(DaLiSePreklapaju(this, this->p, nullptr)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        if(DaLiSePreklapaju(this, posljednji, this)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
        if(DaLiSePreklapaju(this, this->p, nullptr)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        if(DaLiSePreklapaju(this, posljednji, this)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r = r;
        if(DaLiSePreklapaju(this, this->p, nullptr)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        if(DaLiSePreklapaju(this, posljednji, this)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    ~NepreklapajucaKugla() {
        for(NepreklapajucaKugla *temp = posljednji; temp!=nullptr; temp = temp->p) {
            if(temp == posljednji && temp==this) {
                posljednji = this->p;
                this->p = nullptr;
                break;
            }
            if(temp->p == this) {
                temp->p = this->p;
                this->p = nullptr;
                break;
            }
        }
    }
};

NepreklapajucaKugla* NepreklapajucaKugla::posljednji(nullptr);

void NepreklapajucaKugla::Ispisi() const
{
    std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
}
void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    x += delta_x;
    y += delta_y;
    z += delta_z;
    if(DaLiSePreklapaju(this, this->p, nullptr)) {
        throw std::logic_error("Nedozvoljeno preklapanje");
    }
    if(DaLiSePreklapaju(this, posljednji, this)) {
        throw std::logic_error("Nedozvoljeno preklapanje");
    }
}


double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return std::sqrt( std::pow((k1.x-k2.x), 2) + std::pow((k1.y-k2.y), 2) + std::pow((k1.z-k2.z), 2) );
}

int main ()
{
    try {
        std::cout<<"Unesite broj kugli: ";
        int n;
        for(;;) {
            std::cin>>n;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
            } else if(n<=0) {
                std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
            } else break;
        }
        std::vector<std::shared_ptr<NepreklapajucaKugla>> vektor(n);
        for(int i=0; i<n; i++) {
            std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
            for(;;) {
                double a, b, c, d;
                std::cin>>a>>b>>c;
                if(std::cin) {
                    std::cout<<"Unesite poluprecnik: ";
                    for(;;) {

                        std::cin>>d;
                        if(std::cin && d>=0) {
                            try {
                                vektor.at(i) = std::make_shared<NepreklapajucaKugla>(a, b, c, d);
                            } catch(std::logic_error izuzetak) {
                                std::cout<<izuzetak.what()<<std::endl;
                                i--;
                            }
                            break;
                        } else if(d<0) {
                            std::cout<<"Neispravan poluprecnik, unesite ponovo:\n";

                        } else {
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');
                            std::cout<<"Neispravan poluprecnik, unesite ponovo:\n";

                        }
                    }
                    break;
                } else {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout<<"Neispravan centar, unesite ponovo:\n";

                }
            }
        }
        std::cout<<"\nKugle nakon obavljenog sortiranja: \n";
        std::sort(vektor.begin(), vektor.end(), [](std::shared_ptr<NepreklapajucaKugla> pnk1, std::shared_ptr<NepreklapajucaKugla> pnk2) {
            return (*pnk1).DajPovrsinu() < (*pnk2).DajPovrsinu();
        });
        std::for_each(vektor.begin(), vektor.end(), [](std::shared_ptr<NepreklapajucaKugla> pnk) {
            pnk->Ispisi();
        });
        /*
        vektor.at(0)->PostaviX(1);
        vektor.at(0)->PostaviY(1);
        vektor.at(0)->PostaviZ(1);
        vektor.at(0)->Ispisi();
        */
    } catch(std::domain_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    } catch(std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    } catch(...) {
        std::cout<<"Doslo je do greske!"<<std::endl;
    }

    return 0;
}
