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


class NepreklapajucaKugla
{
    
    static NepreklapajucaKugla *posljednjaKreirana;
    NepreklapajucaKugla* prethodna;
    double x,y,z,poluprecnik;
    
    void DaLiSePreklapaju(){
        for(NepreklapajucaKugla *pok=posljednjaKreirana; pok!=nullptr; pok=pok->prethodna){
            if(this->DaLiSePreklapaju(*pok)){
                throw std::logic_error("Nedozvoljeno preklapanje");
            }
        }
    }
    
    bool DaLiSePreklapaju(const NepreklapajucaKugla &k){
        double zbir_poluprecnika = DajPoluprecnik() + k.DajPoluprecnik();
        double udaljenost = RastojanjeCentara(*this,k);
        if(zbir_poluprecnika > udaljenost) return true;
        return false;
    }

    
    

public:

    ~NepreklapajucaKugla(){
        
        if(this==posljednjaKreirana){
            posljednjaKreirana=posljednjaKreirana->prethodna;
        }
        else{
            NepreklapajucaKugla *prije_prethodne = posljednjaKreirana;
            for(auto pok=posljednjaKreirana->prethodna; pok!=nullptr; pok=pok->prethodna){
                if(this==pok){
                    prije_prethodne->prethodna=this->prethodna;
                    break;
                }
                prije_prethodne=pok;
            }
        }
    }

    explicit NepreklapajucaKugla(double r = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        poluprecnik=r;
        x = 0;
        y = 0;
        z = 0;
        //postavljamo prethodnu na zadnju DO SADA kreiranu
        prethodna=posljednjaKreirana;
        
        //Testiramo da li se ova preklapa i sa jednom drugom
        this->DaLiSePreklapaju();
        
        //Ako se ne preklapa onda azuriramo posljenjuKreiranu
        posljednjaKreirana=this;
        
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0) {
        
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        poluprecnik=r;
        this->x = x;
        this->y = y;
        this->z = z;
        //postavljamo prethodnu na zadnju DO SADA kreiranu
        prethodna=posljednjaKreirana;
        
        //Testiramo da li se ova preklapa i sa jednom drugom
        this->DaLiSePreklapaju();
        
        //Ako se ne preklapa onda azuriramo posljenjuKreiranu
        posljednjaKreirana=this;
        

    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        poluprecnik=r;
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
        
        //postavljamo prethodnu na zadnju DO SADA kreiranu
        prethodna=posljednjaKreirana;
        
        //Testiramo da li se ova preklapa i sa jednom drugom
        this->DaLiSePreklapaju();
        
        //Ako se ne preklapa onda azuriramo posljenjuKreiranu
        posljednjaKreirana=this;
        

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
    
    
    NepreklapajucaKugla &PostaviX(double x) {
        this->x=x;
        this->DaLiSePreklapaju();
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        this->y = y;
        this->DaLiSePreklapaju();
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        this->z = z;
        this->DaLiSePreklapaju();
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        this-> x= x;
        this -> y = y;
        this -> z = z;
        this->DaLiSePreklapaju();
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        this->x = std::get<0>(centar);
        this->y = std::get<1>(centar);
        this->z = std::get<2>(centar);
        this->DaLiSePreklapaju();
        return *this;
    }

    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        this->poluprecnik = r;
        this->DaLiSePreklapaju();
        return *this;
    }
    
    
    void Ispisi() const {
        std::cout<<"{"<<"("<<x<<","<<y<<","<<z<<")"<<","<<poluprecnik<<"}";
    }
    
    
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x += delta_x;
        y += delta_y;
        z += delta_z;
        this->DaLiSePreklapaju();
        
    }
    

    bool DaLiSadrzi(const NepreklapajucaKugla &k) const;

    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};


NepreklapajucaKugla* NepreklapajucaKugla::posljednjaKreirana=nullptr;



bool NepreklapajucaKugla::DaLiSadrzi(const NepreklapajucaKugla &k) const
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


double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    double rastojanje;
    rastojanje = sqrt((k1.DajX() - k2.DajX())*(k1.DajX() - k2.DajX()) + ((k1.DajY() - k2.DajY())*(k1.DajY() - k2.DajY())) +
                      ((k1.DajZ() - k2.DajZ()) * (k1.DajZ() - k2.DajZ())));
    return rastojanje;
}



int main ()
{
    int n;
    std::vector<std::shared_ptr<NepreklapajucaKugla>> v;
    std::cout<<"Unesite broj kugli: ";
    std::cin>>n;
    double x,y,z,r;
    for(int i(0); i < n; i++){
        try {
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
            auto dijeljeni = std::make_shared<NepreklapajucaKugla>(x,y,z,r);
            v.push_back(dijeljeni);
        }

        catch(std::domain_error e) {
            std::cout<<e.what()<<std::endl;
            i--;
        }
        catch(std::logic_error e){
            std::cout<<e.what()<<std::endl;
            i--;
        }
    }

    return 0;
}
