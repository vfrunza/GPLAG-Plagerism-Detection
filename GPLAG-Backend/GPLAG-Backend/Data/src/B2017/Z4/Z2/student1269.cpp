/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <algorithm>
#include <memory>
#include <vector>

// MEĐUSPRENIK OBRISAN NEKAKO
// KOPIRANO IZ CODEBLOCKSA

const double pi = 4*atan(1);
const double eps = 1E-10;

bool DaLiSuIstiDoubleovi (double x, double y){
    return (std::abs(x - y) < eps);
}

class NepreklapajucaKugla {
private:
    double x, y, z;
    double r;

    int brojac{0};

    static NepreklapajucaKugla *posljednji;
    NepreklapajucaKugla *prosli{nullptr};
    
    bool DaLiSeDodirujuIzvana (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
        double udaljenost_centara = std::sqrt( (k1.DajX() - k2.DajX())*(k1.DajX() - k2.DajX()) + (k1.DajY() - k2.DajY())*(k1.DajY() - k2.DajY()) + (k1.DajZ() - k2.DajZ())*(k1.DajZ() - k2.DajZ()) );
        if(DaLiSuIstiDoubleovi(k1.DajPoluprecnik()+k2.DajPoluprecnik(), udaljenost_centara) == true){
            return true;
        }
        return false;
    }
    bool DaLiSuIdenticne (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
        if( (DaLiSuIstiDoubleovi(k1.DajPoluprecnik(), k2.DajPoluprecnik()) == true) && (DaLiSuIstiDoubleovi(k1.DajX(), k2.DajX()) == true) && (DaLiSuIstiDoubleovi(k1.DajY(), k2.DajY()) == true) && (DaLiSuIstiDoubleovi(k1.DajZ(), k2.DajZ()) == true) ){
            return true;
        }
        return false;
    }
    bool DaLiSuKoncentricne (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
        if( (DaLiSuIstiDoubleovi(k1.DajX(), k2.DajX()) == true ) && (DaLiSuIstiDoubleovi(k1.DajY(), k2.DajY()) == true) && (DaLiSuIstiDoubleovi(k1.DajZ(), k2.DajZ()) == true) ){
            return true;
        }
        return false;
    }
    bool DaLiSeSijeku (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
        double udaljenost_centara = RastojanjeCentara(k1, k2);
        if(udaljenost_centara < k1.DajPoluprecnik() + k2.DajPoluprecnik() && udaljenost_centara > std::abs(k1.DajPoluprecnik() - k2.DajPoluprecnik()) ){
            return true;
        }
        return false;
    }
    
    bool DaLiSePreklapaju (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
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

    bool ImaLiIsti(NepreklapajucaKugla *elementi_trazi) {
        auto tmp1 = prosli, tmp2 = posljednji;
        if (elementi_trazi != posljednji) {
            while (tmp2 != nullptr) {
                if(DaLiSePreklapaju(*elementi_trazi, *tmp2)) {
                    return true;
                }
                if (tmp2->prosli == elementi_trazi){
                    tmp2 = tmp2->prosli->prosli;
                } else { 
                    tmp2 = tmp2->prosli;
                }
            }
        } else if (elementi_trazi == posljednji){
            while (tmp1 != nullptr){
                if(DaLiSePreklapaju(*elementi_trazi, *tmp1)){
                    return true;
                }
                tmp1 = tmp1->prosli;
            }
        }
        return false;
    }

    void Postavi(double tacka_1, double tacka_2, double tacka_3, double poluprecnik=0) {
        int brojac_tmp = brojac;
        if (posljednji == nullptr) {
            x = tacka_1;
            y = tacka_2;
            z = tacka_3;
            r = poluprecnik;
            prosli = nullptr;
            posljednji = this;
            brojac = 1;
            return;
        }
        else {
            x = tacka_1;
            y = tacka_2;
            z = tacka_3;
            r = poluprecnik;
            if (brojac == 0 && this->prosli == nullptr) {
                this->prosli = posljednji;
                posljednji = this;
                auto pom = this;
                while(pom != nullptr) {
                    brojac++;
                    pom = pom->prosli;
                }
            }
        }
        
        if (this != posljednji && ImaLiIsti(this) == true) {
            brojac = brojac_tmp;
            throw std::logic_error("Nedozvoljeno preklapanje");
        } else if(posljednji == this && ImaLiIsti(this) == true){
            brojac = brojac_tmp;
            posljednji = this->prosli;
            prosli = prosli->prosli;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
    }
    
    public:
    // Konstruktori
    explicit NepreklapajucaKugla (double r = 0){
        if(r < 0){
            throw std::domain_error("Ilegalan poluprecnik");
        }
        Postavi(0,0,0,r);
    }
    NepreklapajucaKugla (double x, double y, double z, double r = 0){
        if(r < 0){
            throw std::domain_error("Ilegalan poluprecnik");
        }
        Postavi(x,y,z,r);
    }
    explicit NepreklapajucaKugla (const std::tuple<double, double, double> &centar, double r = 0){
        if(r < 0){
            throw std::domain_error("Ilegalan poluprecnik");
        }
        double poluprecnik = r;
        double tacka_1 = std::get<0>(centar);
        double tacka_2 = std::get<1>(centar);
        double tacka_3 = std::get<2>(centar);
        Postavi(tacka_1, tacka_2, tacka_3, poluprecnik);
    }
    
    // Inspektori
    double DajX() const{
        return NepreklapajucaKugla::x;
    }
    double DajY() const{
        return NepreklapajucaKugla::y;
    }
    double DajZ() const{
        return NepreklapajucaKugla::z;
    }
    
    std::tuple<double, double, double> DajCentar() const{
        auto tmp = std::make_tuple(NepreklapajucaKugla::x, NepreklapajucaKugla::y, NepreklapajucaKugla::z);
        return tmp;
    }
    double DajPoluprecnik() const{
        return NepreklapajucaKugla::r;
    }
    double DajPovrsinu() const{
        return (4 * NepreklapajucaKugla::r*NepreklapajucaKugla::r * pi);
    }
    double DajZapreminu() const{
        return ((4/3) * (NepreklapajucaKugla::r*NepreklapajucaKugla::r*NepreklapajucaKugla::r) * pi);
    }
    
    // Mutatori - POSTAVLJANJE ATRIBUTA
    NepreklapajucaKugla &PostaviX (double x){
        NepreklapajucaKugla::x = x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY (double y){
        NepreklapajucaKugla::y = y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ (double z){
        NepreklapajucaKugla::z = z;
        return *this;
    }
    
    NepreklapajucaKugla &PostaviCentar (double x, double y, double z){
        NepreklapajucaKugla::x = x;
        NepreklapajucaKugla::y = y;
        NepreklapajucaKugla::z = z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar (const std::tuple<double, double, double> &centar){
        NepreklapajucaKugla::x = std::get<0>(centar);
        NepreklapajucaKugla::y = std::get<1>(centar);
        NepreklapajucaKugla::z = std::get<2>(centar);
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik (double r){
        if(r < 0){
            throw std::domain_error("Ilegalan poluprecnik");
        }
        NepreklapajucaKugla::r = r;
        return *this;
    }
    
    // Mutatori - MIJENJANJE I ISPIS ATRIBUTA
    void Ispisi() const{
        std::cout << "{(" << NepreklapajucaKugla::x << "," << NepreklapajucaKugla::y << "," << NepreklapajucaKugla::z << ")," << NepreklapajucaKugla::r << "}";
    }
    void Transliraj (double delta_x, double delta_y, double delta_z){
        NepreklapajucaKugla::x = NepreklapajucaKugla::x + delta_x;
        NepreklapajucaKugla::y = NepreklapajucaKugla::y + delta_y;
        NepreklapajucaKugla::z = NepreklapajucaKugla::z + delta_z;
    }
    bool DaLiSadrzi (const NepreklapajucaKugla &k) const{
        // ne moze sadrzati ako je manja
        if(NepreklapajucaKugla::r < k.DajPoluprecnik()){
            return false;
        }
        
        // Udaljenost
        // Centra kugle objekta klase
        // Centra kugle objekta k + poluprecnik kugle k
        // Ako je udaljenost veca od r objekta klase onda ne pripada
        if(DaLiSuIstiDoubleovi(NepreklapajucaKugla::x,k.DajX()) == true && DaLiSuIstiDoubleovi(NepreklapajucaKugla::y,k.DajY()) == true && DaLiSuIstiDoubleovi(NepreklapajucaKugla::z, k.DajZ()) == true){
            return true;
        }
        
        double udaljenost_centara = std::sqrt( (NepreklapajucaKugla::x - k.DajX())*(NepreklapajucaKugla::x - k.DajX()) + (NepreklapajucaKugla::y - k.DajY())*(NepreklapajucaKugla::y - k.DajY()) + (NepreklapajucaKugla::z - k.DajZ())*(NepreklapajucaKugla::z - k.DajZ()) );
        double udaljenost = udaljenost_centara + k.DajPoluprecnik();
        
        if(NepreklapajucaKugla::r >= udaljenost){
            return true;
        }
        return false;
    }
    
    // Prijateljske Fcije

    ~NepreklapajucaKugla(){
        if (posljednji == nullptr) return;
        else if (prosli == nullptr) posljednji = nullptr;
        else if (prosli->prosli == nullptr) {
            posljednji = prosli;
            prosli = nullptr;
        }
        else {
            posljednji = prosli;
            prosli = prosli->prosli;
        }
    }

    friend double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

NepreklapajucaKugla *NepreklapajucaKugla::posljednji(nullptr);


double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    double udaljenost_centara = std::sqrt( (k1.DajX() - k2.DajX())*(k1.DajX() - k2.DajX()) + (k1.DajY() - k2.DajY())*(k1.DajY() - k2.DajY()) + (k1.DajZ() - k2.DajZ())*(k1.DajZ() - k2.DajZ()) );
    return udaljenost_centara;
}

int main(){
    try{
        std::vector<std::shared_ptr<NepreklapajucaKugla>> v;
        
        int broj_kugli;
        std::cout << "Unesite broj kugli: ";
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
            std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
            ponovi:std::cin >> x;
            // Nije precizirana poruka za unos koji nije broj !!!!
            if(std::cin.fail()){
                std::cout << "Neispravan centar, unesite ponovo:" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                goto ponovi;
            } // ilegalan unos - NIJE BROJ
            std::cin >> y;
            if(std::cin.fail()){
                std::cout << "Neispravan centar, unesite ponovo:" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                goto ponovi;
            } // ilegalan unos - NIJE BROJ
            std::cin >> z;
            if(std::cin.fail()){
                std::cout << "Neispravan centar, unesite ponovo:" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                goto ponovi;
            } // ilegalan unos - NIJE BROJ
            
            std::cout << "Unesite poluprecnik: ";
            vrati:std::cin >> r;
            if(std::cin.fail()){
                std::cout << "Neispravan poluprecnik, unesite ponovo:" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                goto vrati;
            } else if(r<0){
                std::cout << "Neispravan poluprecnik, unesite ponovo:" << std::endl;
                goto vrati;
            }
            // provjeta unosa
            try{
                std::shared_ptr<NepreklapajucaKugla> pom = nullptr;
                pom = std::make_shared<NepreklapajucaKugla>(x,y,z,r);
                v.push_back(pom);
            } catch(std::logic_error izuzetak){
                std::cout << izuzetak.what() << std::endl;
                i--;
                continue;
            }
        }
        
        // sortiranje po volumenu
        std::sort(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> x, std::shared_ptr<NepreklapajucaKugla> y){
            return (*x).DajZapreminu() < (*y).DajZapreminu();
        });

        std::cout << std::endl << "Kugle nakon obavljenog sortiranja: " << std::endl;
        
        // ispis sa for each
        std::for_each(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> x){
            (*x).Ispisi();
            std::cout << std::endl;
        });
    } catch(std::domain_error greska){
        std::cout << greska.what() << std::endl;
    }
    
    return 0;
}