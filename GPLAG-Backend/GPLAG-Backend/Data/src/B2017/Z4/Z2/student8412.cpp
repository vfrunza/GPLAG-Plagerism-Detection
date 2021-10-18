/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>

#include<tuple>
#include<stdexcept>
#include<cmath>
#include<exception>
#include<memory>
#include<vector>
#include<algorithm>
#define pi (4*atan(1.0))
#define eps (10e-10)

template<typename tip>
bool jednako(tip x,tip y)
{
    if(x<0) x=-x;
    if(y<0) y=-y;
    if(x>y)
    return ((x-y)<eps*((x)+(y)));
    else return ((y-x)<eps*((x)+(y)));
}

class NepreklapajucaKugla
{
    double x,y,z,r;
    static NepreklapajucaKugla*  kraj;
    NepreklapajucaKugla *prethodni=nullptr;
public:
    explicit NepreklapajucaKugla(double pol = 0) {
        if(pol<0) throw std::domain_error("Ilegalan poluprecnik\n");


        x=0;
        y=0;
        z=0;
        r=pol;

        NepreklapajucaKugla* p=kraj;
        while(p!=nullptr) {
            //*p ==*this;TREBA STAVIT USLOV PREKLAPANJA
            if(Preklapanje(*this,*p)) throw std::logic_error("Nedozvoljeno preklapanje\n");
            p=(*p).prethodni;

        }

        prethodni=kraj;
        kraj=this;
    }
    NepreklapajucaKugla(double x1, double y1, double z1, double r1 = 0) {
        if(r1<0) throw std::domain_error("Ilegalan poluprecnik\n");

        x=x1;
        y=y1;
        z=z1;
        r=r1;

        NepreklapajucaKugla* p=kraj;

        while(p!=nullptr) {
            //*p ==*this;TREBA STAVIT USLOV PREKLAPANJA
            if(Preklapanje(*this,*p)) throw std::logic_error("Nedozvoljeno preklapanje\n");
            p=(*p).prethodni;


        }
        prethodni=kraj;
        kraj=this;
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r1 = 0) {

        if(r1<0) throw std::domain_error("Ilegalan poluprecnik\n");


        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        r=r1;

        NepreklapajucaKugla* p=kraj;
        while(p!=nullptr) {
            //*p ==*this;TREBA STAVIT USLOV PREKLAPANJA
            if(Preklapanje(*this,*p)) throw std::logic_error("Nedozvoljeno preklapanje\n");
            p=(*p).prethodni;

        }

        prethodni=kraj;
        kraj=this;
    }
//UBACITI DESTRUKTOR KOJI IZBACUJE SEBE IZ LISTE, UVEZE POKAZIVACE KAKO TREBA
    ~NepreklapajucaKugla() {
        if(this==kraj) {
            kraj=prethodni;
            prethodni=nullptr;
        } else {
            NepreklapajucaKugla* p=kraj;
            while(p!=nullptr) {
                if((*p).prethodni==this) {
                    (*p).prethodni=(*this).prethodni;
                    (*this).prethodni=nullptr;
                    break;
                }
                p=(*p).prethodni;

            }
        }
    }
    NepreklapajucaKugla& operator=(const NepreklapajucaKugla&)=delete;
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
        return (std::make_tuple(x,y,z));

    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*r*r*pi;
    }
    double DajZapreminu() const {
        return (4/3)*r*r*r*pi;
    }
    NepreklapajucaKugla &PostaviX(double x1) {
        x=x1;
        NepreklapajucaKugla* p=kraj;
        if((*this).prethodni!=nullptr) {
            while(p!=nullptr) {
                //*p ==*this;TREBA STAVIT USLOV PREKLAPANJA
                if(Preklapanje(*this,*p) and this!=p) throw std::logic_error("Nedozvoljeno preklapanje\n");
                p=(*p).prethodni;

            }
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y1) {
        y=y1;
        NepreklapajucaKugla* p=kraj;
        if((*this).prethodni!=nullptr) {
            while(p!=nullptr) {
                //*p ==*this;TREBA STAVIT USLOV PREKLAPANJA
                if(Preklapanje(*this,*p) and this!=p) throw std::logic_error("Nedozvoljeno preklapanje\n");
                p=(*p).prethodni;

            }
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z1) {
        z=z1;
        if((*this).prethodni!=nullptr) {
            NepreklapajucaKugla* p=kraj;
            while(p!=nullptr) {
                //*p ==*this;TREBA STAVIT USLOV PREKLAPANJA
                if(Preklapanje(*this,*p) and this!=p) throw std::logic_error("Nedozvoljeno preklapanje\n");
                p=(*p).prethodni;

            }
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x1, double y1, double z1) {
        x=x1;
        y=y1;
        z=z1;
        if((*this).prethodni!=nullptr) {
            NepreklapajucaKugla* p=kraj;
            while(p!=nullptr) {
                //*p ==*this;TREBA STAVIT USLOV PREKLAPANJA
                if(Preklapanje(*this,*p) and this!=p) throw std::logic_error("Nedozvoljeno preklapanje\n");
                p=(*p).prethodni;

            }
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        if((*this).prethodni!=nullptr) {
            NepreklapajucaKugla* p=kraj;
            while(p!=nullptr) {
                //*p ==*this;TREBA STAVIT USLOV PREKLAPANJA
                if(Preklapanje(*this,*p) and this!=p) throw std::logic_error("Nedozvoljeno preklapanje\n");
                p=(*p).prethodni;

            }
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r1) {
        r=r1;
        if((*this).prethodni!=nullptr) {
            NepreklapajucaKugla* p=kraj;
            while(p!=nullptr) {
                //*p ==*this;TREBA STAVIT USLOV PREKLAPANJA
                if(Preklapanje(*this,*p) and this!=p) throw std::logic_error("Nedozvoljeno preklapanje\n");
                p=(*p).prethodni;

            }
        }
        return *this;
    }

    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
        if((*this).prethodni!=nullptr) {
            NepreklapajucaKugla* p=kraj;
            while(p!=nullptr) {

                //*p ==*this;TREBA STAVIT USLOV PREKLAPANJA
                if(Preklapanje(*this,*p) and this!=p) throw std::logic_error("Nedozvoljeno preklapanje\n");
                p=(*p).prethodni;

            }
        }
    }

    bool DaLiSadrzi(const NepreklapajucaKugla &k) const {
        return (r>=k.r+RastojanjeCentara(*this,k));
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);

    friend bool Preklapanje(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};
NepreklapajucaKugla* NepreklapajucaKugla::kraj=nullptr;//STAVLJEN NA NULLPTR

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}
bool Preklapanje(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{

    return ( (jednako(k1.x,k2.x) and jednako(k2.y,k1.y) and  jednako(k2.z,k1.z) ) or (RastojanjeCentara(k1,k2)<(k1.r+k2.r)) or jednako(RastojanjeCentara(k1,k2),(k1.r+k2.r) ));

}



int main()
{
    int k=0;
    int n=0;
    std::cout<<"Unesite broj kugli: ";
    do {

        if(k>0) std::cout<<"Neispravan broj kugli, unesite ponovo!\n";

        std::cin>>n;
        if(n<1) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
        k++;

    } while(n<1);
    std::vector<std::shared_ptr<NepreklapajucaKugla>> v(n);

    int i=0;
    for( i=0; i<n; i++) {
        try {
            std::cout<<"Unesite centar za "<<i+1 <<". kuglu: ";
            int put=0;
            double x,y,z;
            do {

                put++;
                if(put==10) break;
                std::cin>>x>>y>>z;
                if(!(std::cin)) {
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                    std::cout<<"Neispravan centar, unesite ponovo:\n";
                    continue;
                }


                break;


            } while(1);
            std::cout<<"Unesite poluprecnik: ";
            put=0;
            do {
                double r;
                if(put==10) break;
                put++;

                std::cin>>r;
                if(!(std::cin) or r<0) {
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                    std::cout<<"Neispravan poluprecnik, unesite ponovo:\n";
                    continue;
                } else {

                    v[i]=std::make_shared<NepreklapajucaKugla>(x,y,z,r);


                    break;


                }

            } while (1);
        } catch(std::logic_error &e) {

            std::cout<<e.what();
            v[i]=nullptr;
            i--;

        }

    }

    std::sort(v.begin(),v.end(),[](std::shared_ptr<NepreklapajucaKugla> p1,std::shared_ptr<NepreklapajucaKugla> p2) {
        return ((*p1).DajPovrsinu()<(*p2).DajPovrsinu());
    });
    std::cout<<"\nKugle nakon obavljenog sortiranja: \n";
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<NepreklapajucaKugla> p1) {
        (*p1).Ispisi();
    });



    return 0;
}
