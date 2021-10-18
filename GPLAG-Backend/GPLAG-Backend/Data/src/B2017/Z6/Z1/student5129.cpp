/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>

class Skladiste;
class Spremnik;
class Sanduk;
class Vreca;
class Bure;

typedef std::shared_ptr<Spremnik> ptrSpremnik;

class Spremnik {
protected:
    double masa;
    std::string materija;
public:
    Spremnik(double masa, const std::string &materija) : masa(masa), materija(materija) {}
    virtual ~Spremnik() {}
    
    virtual Spremnik *DajKopiju() const {
        return new Spremnik(*this);
    }
    
    double DajTezinu() const {
        return masa;
    }
    
    virtual double DajUkupnuTezinu() const {
        return masa;
    }
    virtual void Ispisi() const {}
};

class Sanduk : public Spremnik {
    std::vector<double> masaElemenata;
public:
    Sanduk(double masa, const std::string &materija, const std::vector<double> &masaElemenata) :
        Spremnik(masa, materija), masaElemenata(masaElemenata) {}
    
    Spremnik *DajKopiju() const {
        return new Sanduk(*this);
    }
    
    double DajUkupnuTezinu() const {
        double sumaMasa(0);
        for (auto masaElementa : masaElemenata)
            sumaMasa += masaElementa;
            
        return sumaMasa + masa;
    }
    
    void Ispisi() const {
        std::cout << "Vrsta spremnika: Sanduk" << std::endl;
        std::cout << "Sadrzaj: " << materija << std::endl;
        std::cout << "Tezine predmeta: ";
        for (auto masaElementa : masaElemenata)
            std::cout << masaElementa << " ";
        std::cout << "(kg)" << std::endl;
        std::cout << "Vlastita tezina: " << masa << " (kg)" << std::endl;
        std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
};

class Vreca : public Spremnik {
    double masaMaterije;
public:
    Vreca(double masa, const std::string &materija, double masaMaterije) :
        Spremnik(masa, materija), masaMaterije(masaMaterije) {}
        
    Spremnik *DajKopiju() const {
        return new Vreca(*this);
    }
    
    double DajUkupnuTezinu() const {
        return masa + masaMaterije;
    }
    
    void Ispisi() const {
        std::cout << "Vrsta spremnika: Vreca" << std::endl;
        std::cout << "Sadrzaj: " << materija << std::endl;
        std::cout << "Vlastita tezina: " << masa << " (kg)" << std::endl;
        std::cout << "Tezina pohranjene materije: " << masaMaterije << " (kg)" << std::endl;
        std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
};

class Bure : public Spremnik {
    double gustina;
    double zapremina;
public:
    Bure(double masa, const std::string &materija, double gustina, double zapremina) :
        Spremnik(masa, materija), gustina(gustina), zapremina(zapremina) {}
    
    Spremnik *DajKopiju() const {
        return new Bure(*this);
    }
    
    double DajUkupnuTezinu() const {
        return masa + gustina * zapremina * 0.001;
    }
    
    void Ispisi() const {
        std::cout << "Vrsta spremnika: Bure" << std::endl;
        std::cout << "Sadrzaj: " << materija << std::endl;
        std::cout << "Vlastita tezina: " << masa << " (kg)" << std::endl;
        std::cout << "Specificna tezina tecnosti: " << gustina << " (kg/m^3)" << std::endl;
        std::cout << "Zapremina tecnosti: " << zapremina << " (l)" << std::endl;
        std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
};

class Skladiste {
//public:
    std::vector<ptrSpremnik> roba;
public:
    Skladiste() {}
    
    Skladiste(const Skladiste &s) {
        for (auto el : s.roba)
        // ISTRAZI zasto nece kad je = 0 za virtualne metode Spremnika
            roba.push_back(ptrSpremnik(el->DajKopiju()));
    }
    Skladiste(Skladiste &&s) : roba(std::move(s.roba)) {}
    
    Skladiste &operator=(const Skladiste &s) {
        roba.resize(0);
        for (auto el : s.roba)
        // ISTRAZI zasto nece kad je = 0 za virtualne metode Spremnika
            roba.push_back(ptrSpremnik(el->DajKopiju()));
        return *this;
    }
    
    Skladiste &operator=(Skladiste &&s) {
        roba = std::move(s.roba);
        return *this;
    }
    
    Spremnik *DodajSanduk(double masa, const std::string &materija, const std::vector<double> &masaElemenata) {
        Spremnik *ptr = new Sanduk(masa, materija, masaElemenata);
        return DodajSpremnik(ptr, true);
    }
    
    Spremnik *DodajVrecu(double masa, const std::string &materija, double masaMaterije) {
        Spremnik *ptr = new Vreca(masa, materija, masaMaterije);
        return DodajSpremnik(ptr, true);
    }
    
    Spremnik *DodajBure(double masa, const std::string &materija, double gustina, double zapremina) {
        Spremnik *ptr = new Bure(masa, materija, gustina, zapremina);
        return DodajSpremnik(ptr, true);
    }
    
    Spremnik *DodajSpremnik(Spremnik *sPtr, bool predaje) {
        if (predaje)
            roba.push_back(ptrSpremnik(sPtr));
        else
            roba.push_back(ptrSpremnik(sPtr->DajKopiju()));
        
        auto ret = roba.rbegin()->get();
        
        std::sort(roba.begin(), roba.end(), [](const ptrSpremnik &prvi, const ptrSpremnik &drugi) {
            return prvi->DajUkupnuTezinu() > drugi->DajUkupnuTezinu();
        });
        
        return ret;
    }
    
    void BrisiSpremnik(Spremnik *sPtr) {
        auto found = std::find_if(roba.begin(), roba.end(), [sPtr](const ptrSpremnik &ptr) {
            return ptr.get() == sPtr;
        });
        
        if (found != roba.end())
            roba.erase(found);
    }
    
    Spremnik &DajNajlaksi() {
        if (roba.empty())
            throw std::range_error("Skladiste je prazno");
        
        return **std::min_element(roba.begin(), roba.end(), [](const ptrSpremnik &prvi, const ptrSpremnik &drugi) {
            return prvi->DajTezinu() < drugi->DajTezinu();
        });
    }
    
    Spremnik &DajNajtezi() {
        if (roba.empty())
            throw std::range_error("Skladiste je prazno");
        
        return **std::max_element(roba.begin(), roba.end(), [](const ptrSpremnik &prvi, const ptrSpremnik &drugi) {
            return prvi->DajTezinu() < drugi->DajTezinu();
        });
    }
    
    int BrojPreteskih(int thresh) const {
        return std::count_if(roba.begin(), roba.end(), [thresh](const ptrSpremnik &ptr) {
            return ptr->DajUkupnuTezinu() > thresh;
        });
    }
    
    void IzlistajSkladiste() const {
        for (auto &el : roba)
            el->Ispisi();
    }
};

int main ()
{
    //Sanduk b(1, "tito", {1, 2, 3});
    //std::cout << b.materija << std::endl;
    Skladiste s;
    auto t = s.DodajSanduk(1, "tito", {1, 2, 3});
    auto b = new Vreca(0.2, "brasno", 25);
    std::cout << (dynamic_cast<Sanduk*>(t) != nullptr) << std::endl;
    auto k = s.DodajSpremnik(b, 0);
    std::cout << (dynamic_cast<Sanduk*>(k) != nullptr) << std::endl;
    std::cout << (dynamic_cast<Vreca*>(k) != nullptr) << std::endl;
    std::cout << (dynamic_cast<Bure*>(k) != nullptr) << std::endl;
    Skladiste n(s);
    
	return 0;
}
