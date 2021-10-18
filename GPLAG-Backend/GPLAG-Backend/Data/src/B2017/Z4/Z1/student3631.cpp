/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>
bool JesuLiJednaki(double x, double y) {
        double eps(10e-10);
        if(abs(x-y) <= eps*(abs(x) + abs(y))) return true;
        return false;
    }
class Kugla
{
    double X, Y, Z, R;
    static constexpr double PI = 4*atan(1);
    
public:
    explicit Kugla(double r=0) {
        if(r<0) throw std::domain_error("Neispravan poluprecnik");
        R=r;
    }
    Kugla(double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Neispravan poluprecnik");
        X=x;
        Y=y;
        Z=z;
        R=r;
    }
    explicit Kugla(std::tuple<double, double, double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Neispravan poluprecnik");
        X=std::get<0>(centar);
        Y=std::get<1>(centar);
        Z=std::get<2>(centar);
        R=r;
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
        return std::make_tuple(X, Y, Z);
    }
    double DajPoluprecnik() const {
        return R;
    }
    double DajPovrsinu() const {
        return 4*R*R*PI;
    }
    double DajZapreminu() const {
        return R*R*R*PI*4/3;
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
        if(r<0) throw std::domain_error("Neispravan poluprecnik");
        R=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<")," << DajPoluprecnik() << "}"<<std::endl;
        //  std::cout<<"{("<<X<<","<<Y<<","<<Z<<")}";
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
        double udaljenost_centara(RastojanjeCentara(k, *this));
        double veci;
        if(k.R > (*this).R) veci = k.R;
        else veci = (*this).R;
        if(udaljenost_centara < veci && udaljenost_centara < abs(k.R - (*this).R)) return true;
        return false;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    if(JesuLiJednaki(k1.X, k2.X) && JesuLiJednaki(k1.Y, k2.Y) && JesuLiJednaki(k1.Z, k2.Z) && JesuLiJednaki(k1.R, k2.R)) return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if(JesuLiJednaki(k1.R, k2.R)) return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if(JesuLiJednaki(k1.X, k2.X) && JesuLiJednaki(k1.Y, k2.Y) && JesuLiJednaki(k1.Z, k2.Z)) return true;
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    double udaljenost_centara(RastojanjeCentara(k1, k2));
    if(JesuLiJednaki(k1.R + k2.R, udaljenost_centara)) return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    double udaljenost_centara(RastojanjeCentara(k1, k2));
    double veci;
    if(k1.R > k2.R) veci = k1.R;
    else veci = k2.R;
    if(/*veci > udaljenost_centar &&*/ !JesuLiJednaki(veci, udaljenost_centara) && JesuLiJednaki(abs(k1.R - k2.R), udaljenost_centara)) return true;
    return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSeSijeku(k1, k2) || DaLiSeDodirujuIznutra(k1, k2) || k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1) || DaLiSuIdenticne(k1, k2) || DaLiSuKoncentricne(k1, k2)) return true;
    //  if(veci > udaljenost_centara && abs(k1.R - k2.R) > udaljenost_centara) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    long double udaljenost_centara(RastojanjeCentara(k1, k2));
    if(udaljenost_centara < k1.R + k2.R && k2.R + RastojanjeCentara(k1, k2) > k1.R && k1.R + RastojanjeCentara(k1, k2) > k2.R) return true;
  //  if(udaljenost_centara < k1.R + k2.R && !DaLiSeDodirujuIznutra(k1, k2)) return true;
  //  if(udaljenost_centara < k1.R + k2.R && !DaLiSeDodirujuIznutra(k1, k2) /*&& !JesuLiJednaki(k1.R+k2.R, udaljenost_centara)*/) return true;
    return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return sqrt((k1.X - k2.X)*(k1.X - k2.X) + (k1.Y - k2.Y)*(k1.Y - k2.Y) + (k1.Z - k2.Z)*(k1.Z - k2.Z));
}

int main ()
{
    int n;
    
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    while(n<=0 || !std::cin){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin>>n;
}
    std::vector<std::shared_ptr<Kugla>> kugle(n);

    double x,y,z;
    double r;
    for(int i=0; i<n; i++) {
        while(1) {
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
            if(!std::cin) {
            //    if(!std::cin || std::cin.peek() != '\n') {
                std::cout<<"Neispravan centar"<<std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
            if(!std::cin || r < 0) {
              //  if(!std::cin || std::cin.peek() != '\n' || r<0) {
                std::cout<<"Ilegalan poluprecnik"<<std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            break;
        }
        std::shared_ptr<Kugla> p(std::make_shared<Kugla>(x, y, z, r));
        kugle.at(i) = p;
    }
    // std::for_each(kugle.begin(), kugle.end(), [&kugle] (std::shared_ptr<Kugla> pocetak) {(*pocetak).Ispisi();});
    // std::for_each(kugle.begin(), kugle.end(), [&kugle]() {(*(*kugle.begin())).Ispisi();});
    
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x, delta_y, delta_z;
    std::cin >> delta_x >> delta_y >> delta_z;
    while(!std::cin) {
        std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin >> delta_x >> delta_y >> delta_z;
    }
    std::transform(kugle.begin(), kugle.end(), kugle.begin(), [delta_x, delta_y, delta_z] (std::shared_ptr<Kugla> kugla) {
        (*kugla).Transliraj(delta_x, delta_y, delta_z);
        return kugla;
    });
    //  std::for_each(kugle.begin(), kugle.end(), [&kugle] (std::shared_ptr<Kugla> pocetak) {(*pocetak).Ispisi();});
    std::sort(kugle.begin(), kugle.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        double zapremina1(k1->DajZapreminu());
        double zapremina2(k2->DajZapreminu());
        return zapremina1 < zapremina2;
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(kugle.begin(), kugle.end(), [&kugle] (std::shared_ptr<Kugla> pocetak) {
        (*pocetak).Ispisi();
    });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    std::shared_ptr<Kugla> max_povrsina(*std::max_element(kugle.begin(), kugle.end(), [] (std::shared_ptr<Kugla> kugla1, std::shared_ptr<Kugla> kugla2) {
        double povrsina1(kugla1->DajPovrsinu());
        double povrsina2(kugla2->DajPovrsinu());
        return povrsina1 < povrsina2;
    }));
    max_povrsina->Ispisi();
    std::vector<std::pair<std::shared_ptr<Kugla>, std::shared_ptr<Kugla>>> parovi;
    bool ispisane(false);
    std::for_each(kugle.begin(), kugle.end(), [&kugle, &ispisane, &parovi](std::shared_ptr<Kugla> k1) {
        std::for_each(kugle.begin()+1, kugle.end(), [&k1, &ispisane, &parovi, &kugle](std::shared_ptr<Kugla> k2) {
            if(DaLiSeSijeku(*k1, *k2) && !DaLiSuIdenticne(*k1, *k2)) {
                bool ne_ispisuj(false);
                for(int i=0; i<parovi.size(); i++) {
                    std::shared_ptr<Kugla> prva(parovi[i].first), druga(parovi[i].second);
                   /* std::cout<<"PAROVI: ";
                    k1->Ispisi();
                    prva->Ispisi();
                    k2->Ispisi();
                    druga->Ispisi();*/
                    if((DaLiSuIdenticne(*k1, *prva) && DaLiSuIdenticne(*k2, *druga)) ||
                            (DaLiSuIdenticne(*k2, *prva) && DaLiSuIdenticne(*k1, *druga))) {
                        ne_ispisuj = true;
                       // break;
                    }
                }
                if(!ne_ispisuj) {
                    std::cout<<"Presjecaju se kugle: ";
                    k1->Ispisi();
                    k2->Ispisi();
                    ispisane=true;
                    parovi.push_back(std::make_pair(k1, k2));
                }
            }
        });
    });
    if(!ispisane) std::cout<<"Ne postoje kugle koje se presjecaju!";

    return 0;
}
