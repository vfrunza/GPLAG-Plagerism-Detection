
/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
const double epsilon=(std::pow(10,-10));
class Kugla
{
    double r;
    double koordinate[3];

public:
    explicit Kugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        koordinate[0]=0;
        koordinate[1]=0;
        koordinate[2]=0;
    }
    Kugla(double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        koordinate[0]=x;
        koordinate[1]=y;
        koordinate[2]=z;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        koordinate[0]=std::get<0>(centar);
        koordinate[1]=std::get<1>(centar);
        koordinate[2]=std::get<2>(centar);
    }
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
        return 4*std::pow(r,2)*4*atan(1);
    }
    double DajZapreminu() const {
        return 4./(3)*std::pow(r,3)*4*atan(1);
    }
    Kugla &PostaviX(double x) {
        koordinate[0]=x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        koordinate[1]=y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        koordinate[2]=z;
        return *this;
    }
    Kugla &PostaviCentar(double x,double y,double z) {
        koordinate[0]=x;
        koordinate[1]=y;
        koordinate[2]=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double,double,double> &centar) {
        koordinate[0]=std::get<0>(centar);
        koordinate[1]=std::get<1>(centar);
        koordinate[2]=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<koordinate[0]<<","<<koordinate[1]<<","<<koordinate[2]<<"),"<<r<<"}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        koordinate[0]+=delta_x;
        koordinate[1]+=delta_y;
        koordinate[2]+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
        bool identicne(true);
        if(k1.r!=k2.r || k1.koordinate[0]!=k2.koordinate[0] || k1.koordinate[1]!=k2.koordinate[1] || k1.koordinate[2]!=k2.koordinate[2])
            identicne=false;
        return identicne;
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
        bool podudarne(true);
        if(k1.r!=k2.r) podudarne=false;
        return podudarne;
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
        bool koncentricne(true);
        if(k1.koordinate[0]!=k2.koordinate[0] || k1.koordinate[1]!=k2.koordinate[1] || k1.koordinate[2]!=k2.koordinate[2]) koncentricne=false;
        return koncentricne;
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
        double udaljenost(0);
        udaljenost=std::sqrt(std::pow(k1.koordinate[0]-k2.koordinate[0],2)+std::pow(k1.koordinate[1]-k2.koordinate[1],2)+std::pow(k1.koordinate[2]-k2.koordinate[2],2));
       if((std::fabs(udaljenost-k1.r-k2.r))<epsilon*(std::fabs(udaljenost)+std::fabs(k1.r+k2.r)) && !DaLiSuIdenticne(k1,k2));  return true; // if(udaljenost==k1.r+k2.r)
        return false;
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
        double udaljenost(0);
        udaljenost=std::sqrt(std::pow(k1.koordinate[0]-k2.koordinate[0],2)+std::pow(k1.koordinate[1]-k2.koordinate[1],2)+std::pow(k1.koordinate[2]-k2.koordinate[2],2));

        if((std::fabs(udaljenost+k2.r-k1.r))<epsilon*(std::fabs(udaljenost+k2.r)+std::fabs(k1.r)) && !DaLiSuIdenticne(k1,k2)) return true; //    if(udaljenost+k2.r==k1.r)
        if((std::fabs(udaljenost+k1.r-k2.r))<epsilon*(std::fabs(udaljenost+k1.r)+std::fabs(k2.r)) && !DaLiSuIdenticne(k1,k2)) return true; //if(udaljenost+k1.r==k2.r)
        return false;
    }
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
        double udaljenost(0);
        udaljenost=std::sqrt(std::pow(k1.koordinate[0]-k2.koordinate[0],2)+std::pow(k1.koordinate[1]-k2.koordinate[1],2)+std::pow(k1.koordinate[2]-k2.koordinate[2],2));

        if(udaljenost<k1.r+k2.r)
            return true;
        return false;
    }
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
        double udaljenost(0);
        udaljenost=std::sqrt(std::pow(k1.koordinate[0]-k2.koordinate[0],2)+std::pow(k1.koordinate[1]-k2.koordinate[1],2)+std::pow(k1.koordinate[2]-k2.koordinate[2],2));

        //if(udaljenost==k1.r+k2.r) return true;
        if(udaljenost<k1.r+k2.r && (!k2.DaLiSadrzi(k1)) && (!k1.DaLiSadrzi(k2))) return true; //|| udaljenost+k2.r>k1.r) && !(k1.DaLiSadrzi(k2)
        return false;
    }
    bool DaLiSadrzi(const Kugla &k) const {
        double udaljenost(0);
        udaljenost=std::sqrt(std::pow(k.koordinate[0]-Kugla::koordinate[0],2)+std::pow(k.koordinate[1]-Kugla::koordinate[1],2)+std::pow(k.koordinate[2]-Kugla::koordinate[2],2));
       

        if(udaljenost +k.r<=r) return true;
        return false; 
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
        double udaljenost(0);
        udaljenost=std::sqrt(std::pow(k1.koordinate[0]-k2.koordinate[0],2)+std::pow(k1.koordinate[1]-k2.koordinate[1],2)+std::pow(k1.koordinate[2]-k2.koordinate[2],2));
        return udaljenost;
    }

};

int main ()
{
    std::cout<<"Unesite broj kugla: ";
    double n;
    std::cin>>n;
    if(!(std::cin) || n<=0) {
        do {
            std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin>>n;
        } while((!std::cin)|| n<=0);
    }
    std::vector<std::shared_ptr<Kugla>> niz_pok(n,nullptr);
    double niz[3];
    double poluprecnik(0);
    for(int i=0; i<n; i++) {
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>niz[0]>>niz[1]>>niz[2];
        if(!(std::cin)) {
            do {
                std::cout<<"Neispravan centar\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout<<"Unesite centar "<<i+1<<". kugle: ";
                std::cin>>niz[0]>>niz[1]>>niz[2];
            } while(!(std::cin));
        }
      
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>poluprecnik;
        if(!(std::cin) || poluprecnik<0) {
            do {
                std::cout<<"Ilegalan poluprecnik\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>niz[0]>>niz[1]>>niz[2];
        if(!(std::cin)) {
            do {
                std::cout<<"Neispravan centar\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout<<"Unesite centar "<<i+1<<". kugle: ";
                std::cin>>niz[0]>>niz[1]>>niz[2];
            } while(!(std::cin));
        }
                std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
                std::cin>>poluprecnik;
            } while(!(std::cin) || poluprecnik<0);
        }
        niz_pok[i]=std::make_shared<Kugla>(niz[0], niz[1], niz[2], poluprecnik);
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x(0), delta_y(0),delta_z(0);
    std::cin>>delta_x>>delta_y>>delta_z;
    if((!std::cin)){
        do{
            std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin>>delta_x>>delta_y>>delta_z;
        }while(!(std::cin));
    }
    std::transform(&niz_pok[0], &niz_pok[n], &niz_pok[0], [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> pok) {
        pok->Transliraj(delta_x,delta_y,delta_z);
        return pok;
    });
    std::sort(&niz_pok[0], &niz_pok[n], [](std::shared_ptr<Kugla> pok1, std::shared_ptr<Kugla> pok2) {
        return pok1->DajZapreminu()<pok2->DajZapreminu();
    } );
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each(&niz_pok[0], &niz_pok[n],[](std::shared_ptr<Kugla> pok) {
        pok->Ispisi();
        std::cout<<std::endl;
    });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto pok(std::max_element(&niz_pok[0], &niz_pok[n],[](std::shared_ptr<Kugla> pok1, std::shared_ptr<Kugla> pok2) {
        return pok1->DajPovrsinu()<pok2->DajPovrsinu();
    } ));
    (**pok).Ispisi();
    std::cout<<std::endl;

    int brojac(0);
    int br2(0);
    std::for_each(&niz_pok[0], &niz_pok[n],[&niz_pok,&br2, n, &brojac](std::shared_ptr<Kugla> pok) {
        std::for_each(&niz_pok[br2+1], &niz_pok[n],[&pok,n, &brojac](std::shared_ptr<Kugla> pok2) {
          //  if(RastojanjeCentara(*pok, *pok2)<pok->DajPoluprecnik()+pok2->DajPoluprecnik() && !(pok->DaLiSadrzi(*pok2))) 
           if(DaLiSeSijeku(*pok,*pok2))
            {
                brojac++;
               if(!DaLiSuIdenticne(*pok,*pok2)){
                std::cout<<"Presjecaju se kugle: ";
                (*pok).Ispisi();
                std::cout<<std::endl;
                (*pok2).Ispisi();
                std::cout<<std::endl;
               }
            }
        });
        br2++;
    });
    if(brojac==0)
        std::cout<<"Ne postoje kugle koje se presjecaju!";

    return 0;
}
