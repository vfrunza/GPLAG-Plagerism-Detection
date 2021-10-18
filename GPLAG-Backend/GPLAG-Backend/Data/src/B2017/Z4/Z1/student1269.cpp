/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <algorithm>
#include <memory>
#include <vector>

// AKO NISU BROJEVI PREPRAVITI !

const double pi = 4*atan(1);
const double eps = 1E-10;

bool DaLiSuIstiDoubleovi (double x, double y){
    return std::abs(x - y) < eps;
}

class Kugla {
private:
   double x, y, z;
    double r;
public:
    // Konstruktori
    explicit Kugla (double r = 0){
        if(r < 0){
            throw std::domain_error("Ilegalan poluprecnik");
        }
        Kugla::r = r;
        Kugla::x = 0;
        Kugla::y = 0;
        Kugla::z = 0;
    }
    Kugla (double x, double y, double z, double r = 0){
        if(r < 0){
            throw std::domain_error("Ilegalan poluprecnik");
        }
        Kugla::r = r;
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
    }
    explicit Kugla (const std::tuple<double, double, double> &centar, double r = 0){
        if(r < 0){
            throw std::domain_error("Ilegalan poluprecnik");
        }
        Kugla::r = r;
        Kugla::x = std::get<0>(centar);
        Kugla::y = std::get<1>(centar);
        Kugla::z = std::get<2>(centar);
    }
    
    // Inspektori
    double DajX() const{
        return Kugla::x;
    }
    double DajY() const{
        return Kugla::y;
    }
    double DajZ() const{
        return Kugla::z;
    }
    
    std::tuple<double, double, double> DajCentar() const{
        auto tmp = std::make_tuple(Kugla::x, Kugla::y, Kugla::z);
        return tmp;
    }
    double DajPoluprecnik() const{
        return Kugla::r;
    }
    double DajPovrsinu() const{
        return (4 * Kugla::r*Kugla::r * pi);
    }
    double DajZapreminu() const{
        return ((4/3) * (Kugla::r*Kugla::r*Kugla::r) * pi);
    }
    
    // Mutatori - POSTAVLJANJE ATRIBUTA
    Kugla &PostaviX (double x){
        Kugla::x = x;
        return *this;
    }
    Kugla &PostaviY (double y){
        Kugla::y = y;
        return *this;
    }
    Kugla &PostaviZ (double z){
        Kugla::z = z;
        return *this;
    }
    
    Kugla &PostaviCentar (double x, double y, double z){
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
        return *this;
    }
    Kugla &PostaviCentar (const std::tuple<double, double, double> &centar){
        Kugla::x = std::get<0>(centar);
        Kugla::y = std::get<1>(centar);
        Kugla::z = std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik (double r){
        if(r < 0){
            throw std::domain_error("Ilegalan poluprecnik");
        }
        Kugla::r = r;
        return *this;
    }
    
    // Mutatori - MIJENJANJE I ISPIS ATRIBUTA
    void Ispisi() const{
        std::cout << "{(" << Kugla::x << "," << Kugla::y << "," << Kugla::z << ")," << Kugla::r << "}";
    }
    void Transliraj (double delta_x, double delta_y, double delta_z){
        Kugla::x = Kugla::x + delta_x;
        Kugla::y = Kugla::y + delta_y;
        Kugla::z = Kugla::z + delta_z;
    }
    bool DaLiSadrzi (const Kugla &k) const{
        // ne moze sadrzati ako je manja
        if(Kugla::r < k.DajPoluprecnik()){
            return false;
        }
        
        // Udaljenost
        // Centra kugle objekta klase
        // Centra kugle objekta k + poluprecnik kugle k
        // Ako je udaljenost veca od r objekta klase onda ne pripada
        if(DaLiSuIstiDoubleovi(Kugla::x,k.DajX()) == true && DaLiSuIstiDoubleovi(Kugla::y,k.DajY()) == true && DaLiSuIstiDoubleovi(Kugla::z, k.DajZ()) == true){
            return true;
        }
        
        double udaljenost_centara = std::sqrt( (Kugla::x - k.DajX())*(Kugla::x - k.DajX()) + (Kugla::y - k.DajY())*(Kugla::y - k.DajY()) + (Kugla::z - k.DajZ())*(Kugla::z - k.DajZ()) );
        double udaljenost = udaljenost_centara + k.DajPoluprecnik();
        
        if(Kugla::r >= udaljenost){
            return true;
        }
        return false;
    }
    
    // Prijateljske Fcije
    friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2);
    friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2);
};

// ako je sve isto
bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2){
    if( (DaLiSuIstiDoubleovi(k1.DajPoluprecnik(), k2.DajPoluprecnik()) == true) && (DaLiSuIstiDoubleovi(k1.DajX(), k2.DajX()) == true) && (DaLiSuIstiDoubleovi(k1.DajY(), k2.DajY()) == true) && (DaLiSuIstiDoubleovi(k1.DajZ(), k2.DajZ()) == true) ){
        return true;
    }
    return false;
}
// ako su poluprecnici isti
bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2){
    if(DaLiSuIstiDoubleovi(k1.DajPoluprecnik(), k2.DajPoluprecnik()) == true){
        return true;
    }
    return false;
}
// ako je centar isti
bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2){
    if( (DaLiSuIstiDoubleovi(k1.DajX(), k2.DajX()) == true ) && (DaLiSuIstiDoubleovi(k1.DajY(), k2.DajY()) == true) && (DaLiSuIstiDoubleovi(k1.DajZ(), k2.DajZ()) == true) ){
        return true;
    }
    return false;
}
bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2){
    double udaljenost_centara = std::sqrt( (k1.DajX() - k2.DajX())*(k1.DajX() - k2.DajX()) + (k1.DajY() - k2.DajY())*(k1.DajY() - k2.DajY()) + (k1.DajZ() - k2.DajZ())*(k1.DajZ() - k2.DajZ()) );
    double poluprecnici = k1.DajPoluprecnik() + k2.DajPoluprecnik();
    if(DaLiSuIstiDoubleovi(poluprecnici, udaljenost_centara) == true){
        return true;
    }
    return false;
}
bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2){
    double udaljenost_centara = std::sqrt( (k1.DajX() - k2.DajX())*(k1.DajX() - k2.DajX()) + (k1.DajY() - k2.DajY())*(k1.DajY() - k2.DajY()) + (k1.DajZ() - k2.DajZ())*(k1.DajZ() - k2.DajZ()) );
    if(DaLiSuIstiDoubleovi(udaljenost_centara+k1.DajPoluprecnik(), k2.DajPoluprecnik()) == true){
        return true;
    }
    if(DaLiSuIstiDoubleovi(udaljenost_centara+k2.DajPoluprecnik(), k1.DajPoluprecnik()) == true){
        return true;
    }
    return false;
}
bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2){
    if(DaLiSeDodirujuIzvana(k1, k2) == true){
        return true;
    }
    if(DaLiSeSijeku(k1, k2) == true){
        return true;
    }
    if(DaLiSuKoncentricne(k1, k2) == true){
        return true;
    }
    if(DaLiSuIdenticne(k1, k2) == true){
        return true;
    }
    if(k1.DaLiSadrzi(k2)==true || k2.DaLiSadrzi(k1)==true){
        return true;
    }
    return false;
}
bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2){
    double udaljenost_centara = RastojanjeCentara(k1, k2);
    if(udaljenost_centara < k1.DajPoluprecnik() + k2.DajPoluprecnik() && udaljenost_centara > std::abs(k1.DajPoluprecnik() - k2.DajPoluprecnik()) ){
        return true;
    }
    return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    double udaljenost_centara = std::sqrt( (k1.DajX() - k2.DajX())*(k1.DajX() - k2.DajX()) + (k1.DajY() - k2.DajY())*(k1.DajY() - k2.DajY()) + (k1.DajZ() - k2.DajZ())*(k1.DajZ() - k2.DajZ()) );
    return udaljenost_centara;
}

int main(){
    try{
        std::vector<std::shared_ptr<Kugla>> v;
        
        int broj_kugli;
        std::cout << "Unesite broj kugla: ";
        while(1){
            std::cin >> broj_kugli;
            if(std::cin.fail()){
                std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            } else if(broj_kugli <= 0){
                std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
                continue;
            } else {
                break;
            }
        }
        
        for(int i=0; i<broj_kugli; i++){
            double x, y, z, r(0);
            std::cout << "Unesite centar " << i+1 << ". kugle: ";
            std::cin >> x;
            // Nije precizirana poruka za unos koji nije broj !!!!
            if(std::cin.fail()){
                std::cout << "Neispravan centar" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                i--;
                continue;
            } // ilegalan unos - NIJE BROJ
            std::cin >> y;
            if(std::cin.fail()){
                std::cout << "Neispravan centar" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                i--;
                continue;
            } // ilegalan unos - NIJE BROJ
            std::cin >> z;
            if(std::cin.fail()){
                std::cout << "Neispravan centar" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                i--;
                continue;
            } // ilegalan unos - NIJE BROJ
            std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
            std::cin >> r;
            if(std::cin.fail()){
                std::cout << "Ilegalan poluprecnik" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                i--;
                continue;
            } else if(r<0){
                std::cout << "Ilegalan poluprecnik" << std::endl;
                i--;
                continue;
            }
            // provjeta unosa
            v.push_back(std::make_shared<Kugla>(x,y,z,r));
        }
        
        std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        double delta_x, delta_y, delta_z;
        while(1){
            std::cin >> delta_x;
            if(std::cin.fail()){
                std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            std::cin >> delta_y;
            if(std::cin.fail()){
                std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            std::cin >> delta_z;
            if(std::cin.fail()){
                std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            break;
        }
        
        // transformacija
        std::transform(v.begin(), v.end(), v.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> x){
            (*x).Transliraj(delta_x, delta_y, delta_z); 
            return x;
        });
        
        // sortiranje po volumenu
        std::sort(v.begin(), v.end(), [](std::shared_ptr<Kugla> x, std::shared_ptr<Kugla> y){
            return (*x).DajZapreminu() < (*y).DajZapreminu();
        });
        
        std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
        
        // ispis sa for each
        std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> x){
            (*x).Ispisi();
            std::cout << std::endl;
        });
        
        // kugla sa najvecom povrsinom
        std::shared_ptr<Kugla> najveca_povrsina;
        najveca_povrsina = *(std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> x, std::shared_ptr<Kugla> y){
            return ((*x).DajPovrsinu() < (*y).DajPovrsinu());}
        ));
        std::cout << "Kugla sa najvecom povrsinom je: ";
        (*najveca_povrsina).Ispisi();
        
        std::cout << std::endl;
        bool presjecaju_se(false);
        for_each(v.begin(), v.end() - 1, [v, &presjecaju_se](std::shared_ptr<Kugla> x){
            int brojac=0;
            for_each(v.begin() + brojac + 1, v.end(), [x, brojac, &presjecaju_se](std::shared_ptr<Kugla> y){
                if(DaLiSeSijeku(*x, *y) == true){
                    presjecaju_se = true;
                    std::cout << "Presjecaju se kugle: ";
                    (*x).Ispisi();
                    std::cout << std::endl;
                    (*y).Ispisi();
                    std::cout << std::endl;
                }
            });
            std::cout << std::endl;
            brojac++;
        });
        if(presjecaju_se == false){
            std::cout << "Ne postoje kugle koje se presjecaju!";
        }
        
    } catch(std::domain_error greska){
        std::cout << greska.what() << std::endl;
    }
    
    return 0;
}