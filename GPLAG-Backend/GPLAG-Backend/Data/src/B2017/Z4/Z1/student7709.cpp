/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include<cmath>
#include<vector>
#include <tuple>
#include <memory>
#include <algorithm>

class Kugla
{
    double X,Y,Z,R;

public:
    explicit Kugla(double r = 0) {
        PostaviPoluprecnik(r);
        X=0;
        Y=0;
        Z=0;
    }
    Kugla(double x, double y, double z, double r = 0) {

        PostaviX(x);
        PostaviY(y);
        PostaviZ(z);
        PostaviPoluprecnik(r);

    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        PostaviCentar(centar);
        PostaviPoluprecnik(r);
    }

    double DajX() const {
        return X;
    }
    double DajY() const {
        return Y;
    }
    double DajZ() const {
        return Z;
    }

    std::tuple<double, double, double> DajCentar() const {
        auto a=std::make_tuple(X,Y,Z);
        return a;
    }
    double DajPoluprecnik() const {
        return R;
    }
    double DajPovrsinu() const {
        return (4*R*R*4*atan(1));
    }
    double DajZapreminu() const {
        return (4*R*R*R*4*(atan(1))/3);
    }

    Kugla &PostaviX(double x) {
        X=x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        Y=y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        Z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z) {
        X=x;
        Y=y;
        Z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        X=std::get<0>(centar);
        Y=std::get<1>(centar);
        Z=std::get<2>(centar);

        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        R=r;
        return *this;
    }

    void Ispisi() const {
        std::cout<<"{("<<X<<","<<Y<<","<<Z<<"),"<<R<<"}"<<std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        X+=delta_x;
        Y+=delta_y;
        Z+=delta_z;
    }

    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const {
        if((sqrt(pow((X-k.X),2)+pow((Y-k.Y),2)+pow((Z-k.Z),2)))<(R+k.R) && R>k.R)
            return true;
        return false;

    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);

};

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return (sqrt(pow((k2.X-k1.X),2)+pow((k2.Y-k1.Y),2)+pow((k2.Z-k1.Z),2)));

}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    if((abs(k1.R-k2.R)<pow(10,-10)*(abs(k1.R)+abs(k2.R))) && (abs(k1.X-k2.X)<pow(10,-10)*(abs(k1.X)+abs(k2.X))) && (abs(k1.Y-k2.Y)<pow(10,-10)*(abs(k1.Y)+abs(k2.Y))) && (abs(k1.Z-k2.Z)<pow(10,-10)*(abs(k1.Z)+abs(k2.Z))))
        return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if(abs(k1.R-k2.R)<pow(10,-10)*(abs(k1.R)+abs(k2.R)))
        return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if((abs(k1.X-k2.X)<pow(10,-10)*(abs(k1.X)+abs(k2.X))) && (abs(k1.Y-k2.Y)<pow(10,-10)*(abs(k1.Y)+abs(k2.Y))) && (abs(k1.Z-k2.Z)<pow(10,-10)*(abs(k1.Z)+abs(k2.Z))))
        return true;
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    double RC=RastojanjeCentara(k1,k2);
    double zbirPoluprecnika=k1.R+k2.R;
    if((abs(RC-zbirPoluprecnika)<pow(10,-10)*(abs(RC)+abs(zbirPoluprecnika))))
        return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    double RC=RastojanjeCentara(k1,k2);
    double razlika=abs(k2.R-k1.R);
    double zbir1=RC+k2.R; double zbir2=RC+k1.R;
    if( (abs(RC-razlika)<pow(10,-10)*(abs(RC)+abs(razlika))) && ((abs(zbir1-k2.R)<pow(10,-10)*(abs(zbir1)+abs(k2.R))) || (abs(zbir2-k1.R)<pow(10,-10)*(abs(zbir2)+abs(k1.R)))));
        return true;
    return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{double RC=RastojanjeCentara(k1,k2);
    if((abs(RC-0)<pow(10,-10)*(abs(RC)+0)) && (abs(k1.R-k2.R)<pow(10,-10)*(abs(k1.R)+abs(k2.R))));
    return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{   double RC=RastojanjeCentara(k1,k2);
    if(RC<(k2.R+k1.R)   && RC>abs(k1.R-k2.R))
        return true;
    return false;

}

int main ()
{
    int brKugla;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>brKugla;
    while(!brKugla || brKugla<=0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout<<"Neispravan broj kugli, unesite ponovo!\n";

        std::cin>>brKugla;

    }

    std::vector<std::shared_ptr<Kugla>> p;

    for(int i(0); i<brKugla; i++) {
        int pomoc=0;
        double x,y,z,r;
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Neispravan centar"<<std::endl;
            pomoc=1;
            i--;
            continue;
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if(!std::cin || r<0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            if(pomoc==0)
                i--;
            pomoc=1;
        }
        if(pomoc==0) {
            auto k(std::make_shared<Kugla>(x,y,z,r));
            p.push_back(k);
        }
    }

    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x,delta_y,delta_z;
    std::cin>>delta_x>>delta_y>>delta_z;
    if(!std::cin) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
        std::cin>>delta_x>>delta_y>>delta_z;
    }
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: ";
    std::transform(p.begin(),p.end(),p.begin(),[delta_x,delta_y,delta_z](std::shared_ptr<Kugla> K1) {
        (*K1).Transliraj(delta_x,delta_y,delta_z);
        return K1;
    });


    std::sort(p.begin(),p.end(),[](std::shared_ptr<Kugla>K1, std::shared_ptr<Kugla>K2) {
        return (*K2).DajZapreminu()>(*K1).DajZapreminu();
    });
    std::cout<<std::endl;
    std::for_each(p.begin(),p.end(),[](std::shared_ptr<Kugla>K) {
        (*K).Ispisi();
    });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (*(*max_element(p.begin(),p.end(),[](std::shared_ptr<Kugla>K1, std::shared_ptr<Kugla>K2) {
        return (*K2).DajPovrsinu()>(*K1).DajPovrsinu();
    }))).Ispisi();


    int pomoc;
    pomoc=0;
    std::for_each(p.begin(),p.end(),[p,&pomoc](std::shared_ptr<Kugla>K1) {

        auto pom=std::find(p.begin(),p.end(),K1);
        int br=pom-p.begin();

        std::for_each(p.begin()+br+1,p.end(),[K1,&pomoc](std::shared_ptr<Kugla> K2) {
        
            if(DaLiSeSijeku(*K1,*K2)) {
                pomoc++;
                
                std::cout<<"Presjecaju se kugle: ";
                (*K1).Ispisi();
                (*K2).Ispisi();
            }
        });
    });
    if(pomoc==0)
        std::cout<<"Ne postoje kugle koje se presjecaju!"<<std::endl;;

    return 0;
}
