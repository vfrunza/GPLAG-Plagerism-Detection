/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <functional>
#include <vector>

// C9 2 PUTA BRISAO DIJELOVE ZADACA
// KORISTE COPY PASTE ZA FCIJE KOJE SAM IMAO SACUVANE U CODEBLOCKSU
// OSTALE PONOVO NAPISANE

class Berza {
    
    private:
    int max_cijena, min_cijena;
    std::vector<int> REGISTAR;
    
    public:
    // konstruktori
    Berza(int min, int max){
        if(max <= 0 || min <= 0){
            throw std::range_error("Ilegalne granice REGISTAR");
        }
        Berza::min_cijena = min;
        Berza::max_cijena = max;
    };
    explicit Berza(int max){
        if(max <= 0){
            throw std::range_error("Ilegalne granice REGISTAR");
        }
        Berza::min_cijena = 0;
        Berza::max_cijena = max;
    }
    
    // mutatori
    void RegistrirajCijenu(int cijena){
        if(cijena<Berza::min_cijena || cijena>Berza::max_cijena){
            throw std::range_error("Ilegalna cijena");
        }
        REGISTAR.push_back(cijena);
    }
    void BrisiSve(){
        REGISTAR.resize(0);
    }
    
    // inspektori
    int DajBrojRegistriranihCijena() const{
        return REGISTAR.size();
    }
    int DajMinimalnuCijenu(){
        if(REGISTAR.size() == 0){
            throw std::range_error("Nema registriranih cijena");
        }
        return *(std::min_element(REGISTAR.begin(), REGISTAR.end(), std::less<int>()));
    }
    int DajMaksimalnuCijenu(){
        if(REGISTAR.size() == 0){
            throw std::range_error("Nema registriranih cijena");
        }
        return *(std::max_element(REGISTAR.begin(), REGISTAR.end(), std::less<int>()));
    }
    int DajBrojCijenaVecihOd(int cijena) const{
        if(REGISTAR.size() == 0){
            throw std::range_error("Nema registriranih cijena");
        }
        return std::count_if(REGISTAR.begin(), REGISTAR.end(), std::bind(std::greater<int>(), std::placeholders::_1, cijena));
    }
    
    // ispis
    void Ispisi() const {
        if(REGISTAR.size() == 0){
            return;
        }
        std::vector<double> tmp(REGISTAR.size());
        std::transform(REGISTAR.begin(), REGISTAR.end(), tmp.begin(), std::bind(std::divides<double>(), std::placeholders::_1, 100.));
        std::sort(tmp.begin(), tmp.end(), std::greater<double>());
        std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<double>(std::cout << std::setprecision(2) << std::fixed, "\n"));
    }
    
    // operatori
    bool operator !() const{
        if(REGISTAR.size() == 0){
            return true;
        }
        return false;
    }
    bool operator [](int index) const{
        if(index > REGISTAR.size()){
            throw std::range_error("Neispravan indeks");
        }
        return REGISTAR[index-1];
    }
    
    Berza &operator +=(int broj){
        *this = *this + broj;
        return *this;
    }
    Berza &operator -=(int broj);
    Berza &operator -=(const Berza &berza);
    
    friend bool operator ==(const Berza &berza_1, const Berza &berza_2);
    friend bool operator !=(const Berza &berza_1, const Berza &berza_2);
    
    friend Berza operator -(const Berza &berza_1, const Berza &berza_2);
    friend Berza operator -(const Berza &berza, int broj);
    friend Berza operator -(int broj, const Berza &berza);
    friend Berza operator -(const Berza &berza);
    friend Berza operator --(Berza &berza, int);
    friend Berza &operator --(Berza &berza);
    
    friend Berza operator +(const Berza &berza, int broj);
    friend Berza operator +(int broj, const Berza &berza);
    friend Berza operator ++(Berza &berza, int);
    friend Berza &operator ++(Berza &berza);
};

Berza &Berza::operator -=(const Berza &berza){
    Berza tmp = *this;
    if(berza.REGISTAR.size() == REGISTAR.size()){
        std::transform(tmp.REGISTAR.begin(), tmp.REGISTAR.end(), berza.REGISTAR.begin(), tmp.REGISTAR.begin(), std::bind(std::minus<int>(), std::placeholders::_1, std::placeholders::_2));
        int brojac_1 = std::count_if(tmp.REGISTAR.begin(), tmp.REGISTAR.end(), std::bind(std::greater<int>(), std::placeholders::_1, this->max_cijena));
        if(brojac_1 > 0){
            throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        }
        int brojac_2 = std::count_if(tmp.REGISTAR.begin(), tmp.REGISTAR.end(), std::bind(std::less<int>(), std::placeholders::_1, this->min_cijena));
        if(brojac_2 > 0){
            throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        }
        *this = tmp;
    }
    return *this;
}

// Prijateljske fcije
bool operator ==(const Berza &berza_1, const Berza &berza_2){
    if(berza_1.REGISTAR.size() != berza_2.REGISTAR.size()){
        return false;
    }
    bool istina;
    istina = std::equal(berza_1.REGISTAR.begin(), berza_1.REGISTAR.end(), berza_2.REGISTAR.begin(), std::bind(std::equal_to<int>(), std::placeholders::_1, std::placeholders::_2));
    if(istina){
        return true;
    }
    return false;
}
bool operator !=(const Berza &berza_1, const Berza &berza_2){
    if(berza_1 == berza_2){
        return false;
    }
    return true;
}

Berza operator - (const Berza &berza, int broj) {
    Berza tmp = berza;
    int brojac_1 = std::count_if(berza.REGISTAR.begin(), berza.REGISTAR.end(), std::bind(std::greater<int>(), std::bind(std::minus<int>(), std::placeholders::_1 , broj), berza.max_cijena));
    if(brojac_1>0){
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    int brojac_2 = std::count_if(berza.REGISTAR.begin(), berza.REGISTAR.end(), std::bind(std::less<int>(), std::bind(std::minus<int>(), std::placeholders::_1 , broj), berza.min_cijena));
    if(brojac_2 > 0){
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    std::transform(tmp.REGISTAR.begin(), tmp.REGISTAR.end(), tmp.REGISTAR.begin(), std::bind(std::minus<int>(), std::placeholders::_1, broj));
    return tmp;

}
Berza operator - (const Berza &berza) {
    Berza tmp = berza;
    std::transform(tmp.REGISTAR.begin(), tmp.REGISTAR.end(), tmp.REGISTAR.begin(), std::bind(std::minus<int>(), tmp.max_cijena + tmp.min_cijena, std::placeholders::_1));
    return tmp;
}
Berza operator - (int broj, const Berza &berza) {
    Berza tmp = berza;
    int brojac_1 = std::count_if(berza.REGISTAR.begin(), berza.REGISTAR.end(), std::bind(std::greater<int>(), std::bind(std::minus<int>(), broj, std::placeholders::_1), berza.max_cijena));
    if(brojac_1 > 0){
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    int brojac_2 = std::count_if(berza.REGISTAR.begin(), berza.REGISTAR.end(), std::bind(std::less<int>(), std::bind(std::minus<int>(), broj, std::placeholders::_1), berza.min_cijena));
    if(brojac_2 > 0){
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    std::transform(tmp.REGISTAR.begin(), tmp.REGISTAR.end(), tmp.REGISTAR.begin(), std::bind(std::minus<int>(), broj, std::placeholders::_1));
    return tmp;
}
Berza operator - (const Berza &berza_1, const Berza &berza_2) {
    if (berza_1.REGISTAR.size() == berza_2.REGISTAR.size() || berza_1.max_cijena == berza_2.max_cijena || berza_1.min_cijena == berza_2.min_cijena){
        throw std::domain_error("Nesaglasni operandi");
    }
        auto tmp = berza_1;
        tmp -= berza_2;
        return tmp;
}
Berza operator --(Berza &berza, int){
    Berza tmp = berza;
    --berza;
    return tmp;
}
Berza &operator --(Berza &berza){
    try{
        berza = berza - 100.;
        return berza;
    } catch(std::domain_error){
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
}


Berza operator + (const Berza &berza, int broj) {
    Berza tmp = berza;
    int brojac_1 = std::count_if(berza.REGISTAR.begin(), berza.REGISTAR.end(), std::bind(std::greater<int>(), std::bind(std::plus<int>(), std::placeholders::_1 , broj), berza.max_cijena));
    if(brojac_1 > 0){
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    int brojac_2 = std::count_if(berza.REGISTAR.begin(), berza.REGISTAR.end(), std::bind(std::less<int>(), std::bind(std::plus<int>(), std::placeholders::_1 , broj), berza.min_cijena));
    if(brojac_2 > 0){
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    std::transform(tmp.REGISTAR.begin(), tmp.REGISTAR.end(), tmp.REGISTAR.begin(), std::bind(std::plus<int>(), std::placeholders::_1, broj));
    return tmp;
}
Berza operator + (int x, const Berza &y) {
    return y + x;
}
Berza operator ++(Berza &berza, int){
    Berza tmp = berza;
    ++berza;
    return tmp;
}
Berza &operator ++(Berza &berza){
    try{
        berza = berza + 100.;
        return berza;
    } catch(std::domain_error){
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
}


int main (){
    // TEST KOMPAJLIRANJA
    // std::cout << "Kompajlira se!";
    
    // TESTIRANJE KLASE
    // Berza b1 (0, 100); -> baca izuzetak, tacno
    Berza b1 (1, 100);
    Berza b2 (200);
    
    b1.RegistrirajCijenu(10);
    b1.RegistrirajCijenu(30);
    b1.RegistrirajCijenu(50);
    
    b2.RegistrirajCijenu(10);
    b2.RegistrirajCijenu(150);
    b2.RegistrirajCijenu(200);
        
    std::cout << "Berza 1: " << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "Max: " << b1.DajMaksimalnuCijenu() << std::endl;
    std::cout << "Min: " << b1.DajMinimalnuCijenu() << std::endl;
    std::cout << "Br reg: " << b1.DajBrojRegistriranihCijena() << std::endl;
    std::cout << "Veci od 90: " << b1.DajBrojCijenaVecihOd(90);
    
    std::cout << std::endl << std::endl;
    
    std::cout << "Berza 2: " << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "Max: " << b2.DajMaksimalnuCijenu() << std::endl;
    std::cout << "Min: " << b2.DajMinimalnuCijenu() << std::endl;
    std::cout << "Br reg: " << b2.DajBrojRegistriranihCijena() << std::endl;
    std::cout << "Veci od 90: " << b2.DajBrojCijenaVecihOd(90);
    
    b1.BrisiSve();
    b2.BrisiSve();
    b1.Ispisi();
    b2.Ispisi();
    
    // std::cout << b2[0];
    
        
    Berza c = b1-b2;
    std::cout << "Berza 1: " << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "Max: " << c.DajMaksimalnuCijenu() << std::endl;
    std::cout << "Min: " << c.DajMinimalnuCijenu() << std::endl;
    std::cout << "Br reg: " << c.DajBrojRegistriranihCijena() << std::endl;
    std::cout << "Veci od 90: " << c.DajBrojCijenaVecihOd(90);

	return 0;
}