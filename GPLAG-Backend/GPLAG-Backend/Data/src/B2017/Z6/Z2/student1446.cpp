/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iterator>
#include <algorithm>

class Spremnik {
protected:
    double tezina_spremnika;
    std::string ime_materije;
public:
    Spremnik(double tezina, std::string ime) : 
    tezina_spremnika(tezina) {
        ime_materije=ime;
    }
    virtual ~Spremnik() {}
    double DajTezinu() const {
        return tezina_spremnika;
    }
    virtual void Ispisi() const=0;
    virtual double DajUkupnuTezinu() const=0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const=0;
};


class Sanduk : public Spremnik {
    std::vector<double> vektor_tezina_predmeta;
public:
    Sanduk(double tezina_sanduka, std::string ime, std::vector<double> vektor_tezina) : 
    Spremnik(tezina_sanduka, ime) {
        vektor_tezina_predmeta=vektor_tezina;
    }
    void Ispisi() const override;
    double DajUkupnuTezinu() const override;
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Sanduk>(*this);
    }
};

void Sanduk::Ispisi() const {
    std::cout << "Vrsta spremnika: Sanduk" << std::endl;
    std::cout << "Sadrzaj: " << ime_materije << std::endl;
    std::cout << "Tezine predmeta: ";
    for (auto iter=vektor_tezina_predmeta.begin(); iter!=vektor_tezina_predmeta.end(); iter++) {
        std::cout << (*iter) << " ";
    }
    std::cout << "(kg)" << std::endl;
    std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}

double Sanduk::DajUkupnuTezinu() const {
    double suma(0);
    for (auto iter=vektor_tezina_predmeta.begin(); iter!=vektor_tezina_predmeta.end(); iter++) {
        suma+=(*iter);
    }
    return tezina_spremnika+suma;
}


class Vreca : public Spremnik {
    double tezina_materije;
public:
    Vreca(double tezina_vrece, std::string ime, double tezina) : 
    Spremnik(tezina_vrece, ime), tezina_materije(tezina) {}
    void Ispisi() const override;
    double DajUkupnuTezinu() const override {
        return tezina_materije+tezina_spremnika;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Vreca>(*this);
    }
};

void Vreca::Ispisi() const {
    std::cout << "Vrsta spremnika: Vreca" << std::endl;
    std::cout << "Sadrzaj: " << ime_materije << std::endl;
    std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Tezina pohranjene materije: " << tezina_materije << " (kg)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}


class Bure : public Spremnik {
    double gustina_tecnosti;
    double zapremina_tecnosti;
public:
    Bure(double tezina_bureta, std::string ime, double gustina, double zapremina) : 
    Spremnik(tezina_bureta, ime), gustina_tecnosti(gustina), zapremina_tecnosti(zapremina) {}
    void Ispisi() const override;
    double DajUkupnuTezinu() const override {
        return tezina_spremnika+gustina_tecnosti*(zapremina_tecnosti/1000.);
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Bure>(*this);
    }
};

void Bure::Ispisi() const {
    std::cout << "Vrsta spremnika: Bure" << std::endl;
    std::cout << "Sadrzaj: " << ime_materije << std::endl;
    std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Specificna tezina tecnosti: " << gustina_tecnosti << " (kg/m^3)" << std::endl;
    std::cout << "Zapremina tecnosti: " << zapremina_tecnosti << " (l)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}


class PolimorfniSpremnik {
    std::shared_ptr<Spremnik> pok_na_spremnik;
public:
    PolimorfniSpremnik() : pok_na_spremnik(nullptr) {}
    ~PolimorfniSpremnik()=default;
    PolimorfniSpremnik(const Spremnik &spr) : 
    pok_na_spremnik(spr.DajKopiju()) {}
    PolimorfniSpremnik(const PolimorfniSpremnik &pol) {
        if (!pol.pok_na_spremnik) pok_na_spremnik=nullptr;
        else pok_na_spremnik=pol.pok_na_spremnik->DajKopiju();
    }
    PolimorfniSpremnik(PolimorfniSpremnik &&pol)=default;
    PolimorfniSpremnik &operator =(const PolimorfniSpremnik &pol) {
        if (&pol==this) return *this;
        if (!pol.pok_na_spremnik) pok_na_spremnik=nullptr;
        else {
            std::shared_ptr<Spremnik> novi_pok(pol.pok_na_spremnik->DajKopiju());
            pok_na_spremnik=novi_pok;
        }
        return *this;
    }
    PolimorfniSpremnik &operator =(PolimorfniSpremnik &&pol)=default;
    double DajTezinu() const {
        if (!pok_na_spremnik) throw std::logic_error("Nespecificiran spremnik");
        return pok_na_spremnik->DajTezinu();
    }
    void Ispisi() const {
        if (!pok_na_spremnik) throw std::logic_error("Nespecificiran spremnik");
        pok_na_spremnik->Ispisi();
    }
    double DajUkupnuTezinu() const {
        if (!pok_na_spremnik) throw std::logic_error("Nespecificiran spremnik");
        return pok_na_spremnik->DajUkupnuTezinu();
    }
};


int main ()
{
	return 0;
}
