#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>


const double PI = 4*atan(1);
const double E = pow(10, -10);
class Kugla {
    private:
    double x, y, z, r;
    
    public:
    explicit Kugla (double r = 0){
        if (r < 0)throw std::domain_error("Ilegalan poluprecnik");
        x = 0; y = 0; z = 0; this ->r = r;
    }
    Kugla (double x, double y, double z, double r = 0){
        if(r < 0)throw std::domain_error("Ilegalan poluprecnik");
        this -> x = x; this -> y = y; this -> z = z; this -> r = r;
    }
    explicit Kugla (const std::tuple<double, double, double> &centar, double r = 0){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        x = std::get<0>(centar); y = std::get<1>(centar); z = std::get<2>(centar);
        this -> r = r;
    }
    double DajX()const{return x;}
    double DajY()const{return y;}
    double DajZ()const{return z;}
    std::tuple<double, double, double> DajCentar()const{
        std::tuple<double, double, double> centar; centar = std::make_tuple(x,y,z); return centar;
        
    }
    double DajPoluprecnik()const{return r;}
    double DajPovrsinu() const{return 4 * PI * r * r;}
    double DajZapreminu()const{return 4./3 * PI * r * r * r;}
    Kugla &PostaviX(double x){this -> x = x; return *this;}
    Kugla &PostaviY(double y){this -> y = y; return *this;}
    Kugla &PostaviZ(double z){this -> z = z; return *this;}
    Kugla &PostaviCentar (double x, double y, double z){
        this -> x = x; this -> y = y; this ->z =z;
        return *this;
    }
    Kugla &PostaviCentar (std::tuple<double, double, double> &centar){
        this -> x = std::get<0>(centar); this -> y = std::get<1>(centar); this -> z = std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r){ 
        if(r < 0)throw std::domain_error("Ilegalan poluprecnik");
        this -> r = r;
        return *this;
    }
    void Ispisi()const{
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() <<"}" << std::endl;
    }
    void Transliraj (double delta_x, double delta_y, double delta_z){
        x = x + delta_x; y = y + delta_y; z = z +delta_z;
    }
    friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi (const Kugla &k)const;
    friend double RastojanjeCentra(const Kugla &k1, const Kugla &k2);
};
bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2){
    if(k1.DajPoluprecnik() == k2.DajPoluprecnik() && k1.DajX() == k2.DajX() && k1.DajY() == k2.DajY() && k1.DajZ() == k1.DajZ())return true;
    else return false;
}
bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2){
    if(k1.DajPoluprecnik() == k2.DajPoluprecnik())return true;
    else return false;
}
bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2){
    if(k1.DajX() == k2.DajX() && k1.DajY() == k2.DajY() && k1.DajZ() == k2.DajZ())return true;
    else return false;
}
bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2){
    double udaljenost = sqrt(pow(k1.DajX() - k2.DajX(), 2) + pow(k1.DajY() - k2.DajY(), 2) + pow(k1.DajZ() - k2.DajZ(), 2));
    double zbir_poluprecnika = k1.DajPoluprecnik() + k2.DajPoluprecnik();
    if(abs(udaljenost - zbir_poluprecnika) < E*(abs(udaljenost) + abs(zbir_poluprecnika)))return true;
    else return false;
}
bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2){
    double udaljenost = sqrt(pow(k1.DajX() - k2.DajX(), 2) + pow(k1.DajY() - k2.DajY(), 2) + pow(k1.DajZ() - k2.DajZ(), 2));
    double razlika_poluprecnika;
    if(k1.DajPoluprecnik() > k2.DajPoluprecnik()){
        razlika_poluprecnika = k1.DajPoluprecnik() - k2.DajPoluprecnik();
    }
    else{
        razlika_poluprecnika = k2.DajPoluprecnik() - k1.DajPoluprecnik();
    }
    if(abs(udaljenost - razlika_poluprecnika) < E*(abs(udaljenost) + abs(razlika_poluprecnika)))return true;
    else return false;
}
bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2){
    double udaljenost = sqrt(pow(k1.DajX() - k2.DajX(), 2) + pow(k1.DajY() - k2.DajY(), 2) + pow(k1.DajZ() - k2.DajZ(), 2));
    double razlika_poluprecnika;
   // double zbir_poluprecnika = k1.DajPoluprecnik() + k2.DajPoluprecnik();
    if(k1.DajPoluprecnik() > k2.DajPoluprecnik()){
        razlika_poluprecnika = k1.DajPoluprecnik() - k2.DajPoluprecnik();
    }
    else{
        razlika_poluprecnika = k2.DajPoluprecnik() - k1.DajPoluprecnik();
    }
    if( udaljenost < razlika_poluprecnika)return true;
    else return false;
}
bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2){
    double udaljenost = sqrt(pow(k1.DajX() - k2.DajX(), 2) + pow(k1.DajY() - k2.DajY(), 2) + pow(k1.DajZ() - k2.DajZ(), 2));
    double razlika_poluprecnika;
    double zbir_poluprecnika = k1.DajPoluprecnik() + k2.DajPoluprecnik();
    if(k1.DajPoluprecnik() > k2.DajPoluprecnik()){
        razlika_poluprecnika = k1.DajPoluprecnik() - k2.DajPoluprecnik();
    }
    else{
        razlika_poluprecnika = k2.DajPoluprecnik() - k1.DajPoluprecnik();
    }
    if( razlika_poluprecnika < udaljenost && udaljenost < zbir_poluprecnika)return true;
    else return false;
}
bool Kugla::DaLiSadrzi (const Kugla &k) const{
    double udaljenost = sqrt(pow(this -> x - k.DajX(), 2) + pow(this -> y - k.DajY(), 2) + pow(this -> z - k.DajZ(), 2));
    double razlika_poluprecnika = this -> r - k.DajPoluprecnik();
    if(udaljenost < razlika_poluprecnika)return true;
    else return false;
}
double RastojanjeCentra(const Kugla &k1, const Kugla &k2){
    double udaljenost = sqrt(pow(k1.DajX() - k2.DajX(), 2) + pow(k1.DajY() - k2.DajY(), 2) + pow(k1.DajZ() - k2.DajZ(), 2));
    return udaljenost;
}

int main(){
    try{
       
        int broj_kugla;
        std::cout << "Unesite broj kugla: ";
        do{
            std::cin >> broj_kugla;
            
            if(broj_kugla <= 0 || !std::cin){
                std::cout << "Neispravan broj kugli, unesite ponovo!"<< std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
           
            }
            else if(broj_kugla > 0)break;

        }while(broj_kugla <= 0 || !std::cin);
            
        std::vector<std::shared_ptr<Kugla>> kugle(broj_kugla);
        
        for(int i = 0; i < kugle.size(); i++){
            
            std::cout << "Unesite centar "<< i + 1<< ". kugle: ";
             double x, y, z;
            std::cin >> x >> y >> z;
        if(!std::cin) {std::cout << "Neispravan centar"<< std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            i--;
           
            continue;
            }
           
            std::cout << "Unesite poluprecnik "<< i + 1<< ". kugle: ";
            double poluprecnik;
            std::cin >> poluprecnik;
            
        if(!std::cin || poluprecnik < 0){
            std::cout << "Ilegalan poluprecnik" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            i--;
            continue;
        }
        kugle[i] = std::make_shared<Kugla>(x, y, z, poluprecnik);

        }

       std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): "; // translacija
        double delta_x, delta_y, delta_z;
        for(;;){
            std::cin >> delta_x >> delta_y >> delta_z;
            if(!std::cin){
                std::cout << "Neispravni parametri translacije, unesite ponovo!"<<std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            else break;
        }
        std::transform(kugle.begin(), kugle.end(),kugle.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> pomocni){ pomocni -> Transliraj(delta_x, delta_y, delta_z); return pomocni;});
        std::sort(kugle.begin(), kugle.end(),[](std::shared_ptr<Kugla> prvi, std::shared_ptr<Kugla> drugi){ return prvi -> DajZapreminu() < drugi -> DajZapreminu();});
        
        std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl; // ispisivanje nakon sortiranja po zapreminama
        std::for_each(kugle.begin(), kugle.end(), [](std::shared_ptr<Kugla> pomocni){pomocni -> Ispisi();});
        
        std::cout << "Kugla sa najvecom povrsinom je: "; // trazenje maximuma po kriteriju
        auto povrsina = *std::max_element(kugle.begin(), kugle.end(), [](std::shared_ptr<Kugla> prvi, std::shared_ptr<Kugla> drugi){return prvi -> DajPovrsinu() < drugi -> DajPovrsinu();});
        povrsina -> Ispisi();
        
        int brojac(0), broj_ispisanih(0);
        std::for_each(kugle.begin(), kugle.end(), [kugle,&brojac, &broj_ispisanih](std::shared_ptr<Kugla> pomocni){
        
            std::for_each(kugle.begin() + brojac, kugle.end(),[pomocni, &broj_ispisanih]( std::shared_ptr<Kugla> drugi){
                if(DaLiSeSijeku(*pomocni, *drugi)){
                    std::cout<< "Presjecaju se kugle: ";
                    pomocni -> Ispisi(); drugi -> Ispisi();
                    broj_ispisanih ++;
                }
            });
               brojac++;
        }); 
        if(broj_ispisanih == 0)std::cout <<"Ne postoje kugle koje se presjecaju!";
    }
    catch(std::domain_error izuzetak){
        std::cout << izuzetak.what() << std::endl;
    }
    
    return 0;
}