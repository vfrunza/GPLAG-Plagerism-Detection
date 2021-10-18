/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <memory>
#include <vector>
class Spremnik {
protected:
    double kilogrami;    
    std::string naziv;
public:
    Spremnik(double kilogrami, std::string naziv): kilogrami(kilogrami),naziv(naziv) {}
    double DajTezinu() const { return kilogrami; }
    double DajUkupnuTezinu() const { return 0; }
    std::string DajNaziv() const { return naziv; }
    void Ispisi() const {}
};
class Sanduk : Spremnik{
    std::vector<double> tezinePredmeta;
public:
    Sanduk(double kilogrami, std::string nazivPredmeta, std::vector<double> tezinePredmeta): Spremnik(kilogrami, naziv) , tezinePredmeta(tezinePredmeta){}
    double DajUkupnuTezinu() const { 
        double ukupnaTezina(0);
        for(int i = 0; i < tezinePredmeta.size(); i++) {
            ukupnaTezina += tezinePredmeta.at(i);
        }
        return ukupnaTezina + this->DajTezinu();
    }
    void Ispisi() const {
        std::cout << "Vrsta spremnika: Sanduk" << std::endl;
        std::cout << "Sadrzaj: " << this->DajNaziv() << std::endl;
        std::cout << "Tezine predmeta: ";
        for(int i = 0; i < tezinePredmeta.size(); i++) {
            std::cout << tezinePredmeta.at(i) << " ";
        }
        std::cout<< "(kg)" << std::endl;
        std::cout << "Vlastita tezina: " << this->DajTezinu() << " (kg)" << std::endl;
        std::cout << "Ukupna tezina: " << this->DajUkupnuTezinu() << " (kg)" << std::endl;

    } 
};

class Vreca : Spremnik{
    double tezinaPohranjeneMaterije;
public:
    Vreca(double kilogrami, std::string nazivPredmeta, double tezinaPohranjeneMaterije): Spremnik(kilogrami, naziv) , tezinaPohranjeneMaterije(tezinaPohranjeneMaterije){}
    double DajUkupnuTezinu() const {
        return this->DajTezinu() + this->tezinaPohranjeneMaterije;
    }
    void Ispisi() const {
        std::cout << "Vrsta spremnika: Vreca" << std::endl;
        std::cout << "Sadrzaj: " << this->DajNaziv() << std::endl;
        std::cout << "Vlastita tezina: " << this->DajTezinu() << " (kg)" << std::endl;
        std::cout<< "Tezina pohranjene materije: " << this->tezinaPohranjeneMaterije << " (kg)" << std::endl;
        std::cout << "Ukupna tezina: " << this->DajUkupnuTezinu() << " (kg)" << std::endl;
    } 
};

class Bure : Spremnik{
    double gustina;
    double zapremina;
public:
    Bure(double kilogrami, std::string nazivPredmeta, double gustina, double zapremina): Spremnik(kilogrami, naziv) , gustina(gustina), zapremina(zapremina){}
     double DajUkupnuTezinu() const {
        return this->DajTezinu() + this->gustina * this->zapremina*0.001;
     }
    void Ispisi() const {
        std::cout << "Vrsta spremnika: Bure" << std::endl;
        std::cout << "Sadrzaj: " << this->DajNaziv() << std::endl;
        std::cout << "Vlastita tezina: " << this->DajTezinu() << " (kg)" << std::endl;
        std::cout << "Specificna tezina tecnosti: " << this->gustina << " (kg/m^3)" << std::endl;
        std::cout << "Zapremina tecnosti: " << this->zapremina << " (l)" << std::endl;
        std::cout << "Ukupna tezina: " << this->DajUkupnuTezinu() << " (kg)" << std::endl;
    }
};

class Skladiste {
    std::shared_ptr<Spremnik> roba;
public:
    explicit Skladiste() 
};

int main ()
{
	return 0;
}
