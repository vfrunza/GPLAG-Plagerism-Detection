/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
class NepreklapajucaKugla
{
    double r;
    double koordinate[3];
    NepreklapajucaKugla* prethodna;
    static NepreklapajucaKugla* posljednja_kreirana;


public:
    ~NepreklapajucaKugla() {
        if(this==posljednja_kreirana) {
            posljednja_kreirana=this->prethodna;
            this->prethodna=nullptr;
        } else if(this->prethodna==nullptr) {
            NepreklapajucaKugla*pomocna=posljednja_kreirana;
            while(pomocna->prethodna!=this) {
                pomocna=pomocna->prethodna;
            }
            pomocna->prethodna=nullptr;

        } else {
            NepreklapajucaKugla*pomocna=posljednja_kreirana;
            while(pomocna->prethodna!=this) {
                pomocna=pomocna->prethodna;
            }
            pomocna->prethodna=this->prethodna;
        }


    }
    explicit NepreklapajucaKugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik\n");
        NepreklapajucaKugla::r=r;
        koordinate[0]=0;
        koordinate[1]=0;
        koordinate[2]=0;
        if(posljednja_kreirana==nullptr) {
            prethodna=nullptr;
            posljednja_kreirana=this;
        } else {
            NepreklapajucaKugla*pomocna=posljednja_kreirana;
            while(pomocna!=nullptr) {
                if(RastojanjeCentara(*this, *pomocna)<=(*this).r+(*pomocna).r)
                    throw std::logic_error("Nedozvoljeno preklapanje\n");
                pomocna=pomocna->prethodna;
            }
            prethodna=posljednja_kreirana;
            posljednja_kreirana=this;
        }
    }
    NepreklapajucaKugla(double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik\n");
        NepreklapajucaKugla::r=r;
        koordinate[0]=x;
        koordinate[1]=y;
        koordinate[2]=z;
        if(posljednja_kreirana==nullptr) {
            prethodna=nullptr;
            posljednja_kreirana=this;
        } else {
            NepreklapajucaKugla*pomocna=posljednja_kreirana;

            while(pomocna!=nullptr) {
                if(RastojanjeCentara(*this, *pomocna)<=(*this).r+(*pomocna).r)
                    throw std::logic_error("Nedozvoljeno preklapanje\n");
                pomocna=pomocna->prethodna;
            }
            prethodna=posljednja_kreirana;
            posljednja_kreirana=this;
        }
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik\n");
        NepreklapajucaKugla::r=r;
        koordinate[0]=std::get<0>(centar);
        koordinate[1]=std::get<1>(centar);
        koordinate[2]=std::get<2>(centar);
        if(posljednja_kreirana==nullptr) {
            prethodna=nullptr;
            posljednja_kreirana=this;
        } else {
            NepreklapajucaKugla*pomocna=posljednja_kreirana;

            while(pomocna!=nullptr) {
                if(RastojanjeCentara(*this, *pomocna)<=(*this).r+(*pomocna).r)
                    throw std::logic_error("Nedozvoljeno preklapanje\n");
                pomocna=pomocna->prethodna;
            }
            prethodna=posljednja_kreirana;
            posljednja_kreirana=this;
        }
    }
    NepreklapajucaKugla(const NepreklapajucaKugla& n)=delete;
    NepreklapajucaKugla & operator= (const NepreklapajucaKugla& n)=delete;
    double DajX() const {
        return koordinate[0];
    }
    double DajY() const {
        return koordinate[1];
    }
    double DajZ() const {
        return koordinate[2];
    }
    std::tuple<double, double,double> DajCentar() const {
        std::tuple<double, double, double> t {koordinate[0], koordinate[1], koordinate[2]};
        return t;

    }
    double DajPoluprecnik() const {
        return r;

    }
    double DajPovrsinu() const {
        return 4*std::pow(r,2)*4*std::atan(1);
    }
    double DajZapreminu() const {
        return 4./(3)*std::pow(r,3)*4*std::atan(1);
    }
    NepreklapajucaKugla &PostaviX(double x) {

        koordinate[0]=x;
        if(posljednja_kreirana==nullptr) {
            prethodna=nullptr;
            posljednja_kreirana=this;
        } else {
            NepreklapajucaKugla*pomocna=posljednja_kreirana;
            while(pomocna!=nullptr) {
                if(RastojanjeCentara(*this, *pomocna)<=(*this).r+(*pomocna).r)
                    throw std::logic_error("Nedozvoljeno preklapanje\n");
                pomocna=pomocna->prethodna;
            }
            prethodna=posljednja_kreirana;
            posljednja_kreirana=this;
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        koordinate[1]=y;
        if(posljednja_kreirana==nullptr) {
            prethodna=nullptr;
            posljednja_kreirana=this;
        } else {
            NepreklapajucaKugla*pomocna=posljednja_kreirana;
            while(pomocna!=nullptr) {
                if(RastojanjeCentara(*this, *pomocna)<=(*this).r+(*pomocna).r)
                    throw std::logic_error("Nedozvoljeno preklapanje\n");
                pomocna=pomocna->prethodna;
            }
            prethodna=posljednja_kreirana;
            posljednja_kreirana=this;
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        koordinate[2]=z;
        if(posljednja_kreirana==nullptr) {
            prethodna=nullptr;
            posljednja_kreirana=this;
        } else {
            NepreklapajucaKugla*pomocna=posljednja_kreirana;
            while(pomocna!=nullptr) {
                if(RastojanjeCentara(*this, *pomocna)<=(*this).r+(*pomocna).r)
                    throw std::logic_error("Nedozvoljeno preklapanje\n");
                pomocna=pomocna->prethodna;
            }
            prethodna=posljednja_kreirana;
            posljednja_kreirana=this;
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x,double y,double z) {
        koordinate[0]=x;
        koordinate[1]=y;
        koordinate[2]=z;
        if(posljednja_kreirana==nullptr) {
            prethodna=nullptr;
            posljednja_kreirana=this;
        } else {
            NepreklapajucaKugla*pomocna=posljednja_kreirana;
            while(pomocna!=nullptr) {
                if(RastojanjeCentara(*this, *pomocna)<=(*this).r+(*pomocna).r)
                    throw std::logic_error("Nedozvoljeno preklapanje\n");
                pomocna=pomocna->prethodna;
            }
            prethodna=posljednja_kreirana;
            posljednja_kreirana=this;
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double,double,double> &centar) {
        koordinate[0]=std::get<0>(centar);
        koordinate[1]=std::get<1>(centar);
        koordinate[2]=std::get<2>(centar);
        if(posljednja_kreirana==nullptr) {
            prethodna=nullptr;
            posljednja_kreirana=this;
        } else {
            NepreklapajucaKugla*pomocna=posljednja_kreirana;
            while(pomocna!=nullptr) {
                if(RastojanjeCentara(*this, *pomocna)<=(*this).r+(*pomocna).r)
                    throw std::logic_error("Nedozvoljeno preklapanje\n");
                pomocna=pomocna->prethodna;
            }
            prethodna=posljednja_kreirana;
            posljednja_kreirana=this;
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        NepreklapajucaKugla::r=r;
        if(posljednja_kreirana==nullptr) {
            prethodna=nullptr;
            posljednja_kreirana=this;
        } else {
            NepreklapajucaKugla*pomocna=posljednja_kreirana;
            while(pomocna!=nullptr) {
                if(RastojanjeCentara(*this, *pomocna)<=(*this).r+(*pomocna).r)
                    throw std::logic_error("Nedozvoljeno preklapanje\n");
                pomocna=pomocna->prethodna;
            }
            prethodna=posljednja_kreirana;
            posljednja_kreirana=this;
        }
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<koordinate[0]<<","<<koordinate[1]<<","<<koordinate[2]<<"),"<<r<<"}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        koordinate[0]+=delta_x;
        koordinate[1]+=delta_y;
        koordinate[2]+=delta_z;
        if(posljednja_kreirana==nullptr) {
            prethodna=nullptr;
            posljednja_kreirana=this;
        } else {
            NepreklapajucaKugla*pomocna=posljednja_kreirana;
            while(pomocna!=nullptr) {
                if(RastojanjeCentara(*this, *pomocna)<=(*this).r+(*pomocna).r)
                    throw std::logic_error("Nedozvoljeno preklapanje\n");
                pomocna=pomocna->prethodna;
            }
            prethodna=posljednja_kreirana;
            posljednja_kreirana=this;
        }
    }

    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
        double udaljenost(0);
        udaljenost=std::sqrt(std::pow(k1.koordinate[0]-k2.koordinate[0],2)+std::pow(k1.koordinate[1]-k2.koordinate[2],2)+std::pow(k1.koordinate[2]-k2.koordinate[2],2));
        return udaljenost;
    }

};
NepreklapajucaKugla* NepreklapajucaKugla::posljednja_kreirana=nullptr;

int main ()
{

    std::cout<<"Unesite broj kugli: ";
    double n;
    std::cin>>n;
    if(!std::cin || n<=0) {
        do {
            std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
            std::cin>>n;
        } while((!std::cin) || n<=0);
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> niz_pok(n,nullptr);
    double niz[3];
    double poluprecnik(0);
    for(int i=0; i<n; i++) {
        std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
        std::cin>>niz[0]>>niz[1]>>niz[2];
        if(!(std::cin)) {
            do {
                std::cout<<"Neispravan centar, unesite ponovo:\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cin>>niz[0]>>niz[1]>>niz[2];
            } while(!(std::cin));
        }
        std::cout<<"Unesite poluprecnik: ";
        std::cin>>poluprecnik;
        if(!(std::cin) || poluprecnik<0) {
            do {
                std::cout<<"Neispravan poluprecnik, unesite ponovo:\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cin>>poluprecnik;
            } while(!(std::cin) || poluprecnik<0);
        }
        try {
            niz_pok[i]=std::make_shared<NepreklapajucaKugla>(niz[0], niz[1], niz[2], poluprecnik);
        } catch(std::domain_error izuzetak) {
            std::cout<<izuzetak.what();

            i--;
        }

        catch(std::logic_error izuzetak) {
            std::cout<<izuzetak.what();

            i--;

        }


    }
    std::sort(&niz_pok[0], &niz_pok[n], [](std::shared_ptr<NepreklapajucaKugla> pok1, std::shared_ptr<NepreklapajucaKugla> pok2) {
        return pok1->DajPovrsinu()<pok2->DajPovrsinu();
    } );
    std::cout<<"\nKugle nakon obavljenog sortiranja: \n";
    std::for_each(&niz_pok[0], &niz_pok[n],[](std::shared_ptr<NepreklapajucaKugla> pok) {
        (*pok).Ispisi();
        std::cout<<std::endl;
    });

    return 0;
}







/*3
2 3 1
5
10 7 8
2
4 6 3
7
5 8 4
1*/
