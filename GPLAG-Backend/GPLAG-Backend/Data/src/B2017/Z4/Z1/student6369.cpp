/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <vector>
#include <algorithm>
#include <memory>

constexpr double PI=atan(1)*4;
constexpr double eps=0.000000001;
class Kugla
{
    double x,y,z,poluprecnik;

public:


    explicit Kugla(double r = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        poluprecnik=r;
        x = 0;
        y = 0;
        z = 0;
    }
    Kugla(double x, double y, double z, double r = 0) {
        PostaviPoluprecnik(r);
        PostaviX(x);
        PostaviY(y);
        PostaviZ(z);

    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        PostaviPoluprecnik(r);
        PostaviX(std::get<0>(centar));
        PostaviY(std::get<1>(centar));
        PostaviZ(std::get<2>(centar));

    }
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
        return std::make_tuple(x,y,z);
    }
    double DajPoluprecnik() const {
        return poluprecnik;
    }
    double DajPovrsinu() const {
        return 4*poluprecnik*poluprecnik*PI;
    }
    double DajZapreminu() const {
        return ((4/3.)*poluprecnik*poluprecnik*poluprecnik)*PI;
    }
    Kugla &PostaviX(double x) {
        this->x=x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        this->y = y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        this->z = z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z) {
        this-> x= x;
        this -> y = y;
        this -> z = z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        this->x = std::get<0>(centar);
        this->y = std::get<1>(centar);
        this->z = std::get<2>(centar);
        return *this;
    }

    Kugla &PostaviPoluprecnik(double r) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        this->poluprecnik = r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{"<<"("<<x<<","<<y<<","<<z<<")"<<","<<poluprecnik<<"}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x += delta_x;
        y += delta_y;
        z += delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;



    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool Kugla::DaLiSadrzi(const Kugla &k) const
{

    double udaljenost = RastojanjeCentara(*this,k);
    double veci_poluprecnik,manji_poluprecnik;
    if(DajPoluprecnik() > k.DajPoluprecnik()) {
        veci_poluprecnik = DajPoluprecnik();
        manji_poluprecnik = k.DajPoluprecnik();
    } else return false;

    if(udaljenost < veci_poluprecnik) {
        if(fabs((veci_poluprecnik - udaljenost)- manji_poluprecnik) < eps || (veci_poluprecnik - udaljenost)>manji_poluprecnik) return true;
    }
    return false;

}


bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    if((fabs(k1.DajX() - k2.DajX()) < eps) && (fabs(k1.DajY() - k2.DajY())< eps) &&
            (fabs(k1.DajZ() - k2.DajZ())< eps) && (fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik()) < eps))
        return true;
    else return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if(fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik()) < eps) return true;
    return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if((fabs(k1.DajX() - k2.DajX()) < eps) && (fabs(k1.DajY() - k2.DajY())< eps) && (fabs(k1.DajZ() - k2.DajZ())< eps)) return true;
    return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    double rastojanje;
    rastojanje = sqrt((k1.DajX() - k2.DajX())*(k1.DajX() - k2.DajX()) + ((k1.DajY() - k2.DajY())*(k1.DajY() - k2.DajY())) +
                      ((k1.DajZ() - k2.DajZ()) * (k1.DajZ() - k2.DajZ())));
    return rastojanje;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    double zbir_poluprecnika = k1.DajPoluprecnik() + k2.DajPoluprecnik();
    double udaljenost = RastojanjeCentara(k1,k2);
    if(fabs(zbir_poluprecnika - udaljenost)< eps) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSuIdenticne(k1,k2)) return false; 
    double zbir_poluprecnika = k1.DajPoluprecnik() + k2.DajPoluprecnik();
    double udaljenost = RastojanjeCentara(k1,k2);
    double veci_poluprecnik,manji_poluprecnik;
    if(k1.DajPoluprecnik() < k2.DajPoluprecnik()) {
        veci_poluprecnik = k2.DajPoluprecnik();
        manji_poluprecnik = k1.DajPoluprecnik();
    } else {
        veci_poluprecnik = k1.DajPoluprecnik();
        manji_poluprecnik = k2.DajPoluprecnik();
    }
    if(udaljenost < veci_poluprecnik) {
        if( fabs((veci_poluprecnik - udaljenost)- manji_poluprecnik) < eps) return true;
    }
    return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    double zbir_poluprecnika = k1.DajPoluprecnik() + k2.DajPoluprecnik();
    double udaljenost = RastojanjeCentara(k1,k2);
    if(zbir_poluprecnika > udaljenost && (!k1.DaLiSadrzi(k2) && !k2.DaLiSadrzi(k1))) return true;
    return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{

    double zbir_poluprecnika = k1.DajPoluprecnik() + k2.DajPoluprecnik();
    double udaljenost = RastojanjeCentara(k1,k2);
    if(zbir_poluprecnika > udaljenost) return true;
    return false;
}

int main ()
{
    int broj_kugla;
    std::vector<std::shared_ptr<Kugla>>kugle;
    double x,y,z,r;
    double delta_x,delta_y,delta_z;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>broj_kugla;
    

    for(int i(0); i < broj_kugla; i++) {
        try {
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
            kugle.push_back(std::make_shared<Kugla>(x,y,z,r));
        }

        catch(std::domain_error e) {
            std::cout<<e.what()<<std::endl;
            i--;
        }
    }

    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin>>delta_x>>delta_y>>delta_z;
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::transform(kugle.begin(),kugle.end(),kugle.begin(), [delta_x,delta_z,delta_y](const std::shared_ptr<Kugla> &pok) { pok->Transliraj(delta_x,delta_y,delta_z); return pok;});
    std::sort(kugle.begin(),kugle.end(),[](const std::shared_ptr<Kugla> &k1, const std::shared_ptr<Kugla> &k2) {
        return k1->DajZapreminu()<k2->DajZapreminu();
    });
    std::for_each(kugle.begin(),kugle.end(), [](const std::shared_ptr<Kugla> &k){
        k->Ispisi(); 
        std::cout<<std::endl;
        
    });
    
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto iter_najveci = std::max_element(kugle.begin(),kugle.end(), [](const std::shared_ptr<Kugla> &pok1, const std::shared_ptr<Kugla> &pok2) {
        return pok1->DajPovrsinu() < pok2->DajPovrsinu();
    });
    (*iter_najveci)->Ispisi();
    std::cout<<std::endl;
    bool presijecaju_se(false);
    int br(0);
    std::for_each(kugle.begin(),kugle.end(),[&kugle,&presijecaju_se,&br](const std::shared_ptr<Kugla> &pok){
        br+=1;
        std::for_each(kugle.begin()+br, kugle.end(), [&presijecaju_se, &pok](const std::shared_ptr<Kugla> &pok2){
            if(!(pok==pok2) && DaLiSeSijeku(*pok,*pok2)){
                std::cout<<"Presjecaju se kugle: ";
                pok->Ispisi();
                std::cout<<std::endl;
                pok2->Ispisi();
                std::cout<<std::endl;
                presijecaju_se=true;
            }
        });
        
    });
    if(!presijecaju_se) {
        std::cout<<"Ne postoje kugle koje se presjecaju!";
    }

    return 0;
}
