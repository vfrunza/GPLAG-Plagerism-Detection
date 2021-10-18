/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>

class Spremnik
{
    double tezina;
    std::string naziv_sadrzaja;
public:
    virtual ~Spremnik() {};
    Spremnik(double tezina, std::string naziv_sadrzaja): tezina(tezina), naziv_sadrzaja(naziv_sadrzaja) {}
    virtual double DajTezinu() const {
        return tezina;
    }
    std::string DajNaziv() const {
        return naziv_sadrzaja;
    }

    virtual void Ispisi() const = 0;
    virtual double DajUkupnuTezinu() const = 0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;

};

class Sanduk: public Spremnik
{
    std::vector<double> tezina_predmeta;
public:
    Sanduk(double tezina, std::string naziv_sadrzaja, std::vector<double> tezina_predmeta);
    void Ispisi() const override;
    double DajUkupnuTezinu() const override;
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Sanduk>(*this);
    }

};

class Vreca: public Spremnik
{
    double tezina_materije;
public:
    Vreca (double tezina, std::string naziv_sadrzaja, double tezina_materije):
        Spremnik(tezina, naziv_sadrzaja), tezina_materije(tezina_materije) {}

    void Ispisi() const override;
    double DajUkupnuTezinu() const override;
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Vreca>(*this);
    }

};

class Bure: public Spremnik
{
    double gustina_tecnosti, zapremina_tecnosti;
public:
    Bure(double tezina, std::string naziv_sadrzaja, double gustina_tecnosti, double zapremina_tecnosti);
    void Ispisi() const override;
    double DajUkupnuTezinu() const override;
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Bure> (*this);
    }

};

class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> vektor_pokazivaca;
public:

    Skladiste(): vektor_pokazivaca(0) {}
    Skladiste(const Skladiste &s);
    Skladiste(Skladiste && s) = default;
    Skladiste &operator= (const Skladiste &s);
    Skladiste &operator= (Skladiste &&s);

    Spremnik* DodajSpremnik(Spremnik* pok, bool vlasnistvo);
    Spremnik* DodajSanduk(double tezina, std::string naziv_sadrzaja, std::vector<double> tezina_predmeta);
    Spremnik* DodajBure(double tezina, std::string naziv_sadrzaja, double gustina_tecnosti, double zapremina_tecnosti);
    Spremnik* DodajVrecu(double tezina, std::string naziv_sadrzaja, double tezina_materije);

    void BrisiSpremnik(Spremnik* adresa);
    Spremnik &DajNajlaksi();
    Spremnik &DajNajtezi();
    int BrojPreteskih(int x) const;
    void IzlistajSkladiste() const;

    void UcitajIzDatoteke(std::string ime_datoteke);

};

void Sanduk::Ispisi() const
{
    std::cout << "Vrsta spremnika: Sanduk" << std::endl;
    std::cout << "Sadrzaj: " << DajNaziv() << std::endl;
    std::cout << "Tezine predmeta: ";
    for(auto x : tezina_predmeta) std::cout << x << " ";
    std::cout << "(kg)" << std::endl;
    std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}
double Sanduk::DajUkupnuTezinu() const
{
    double ukupna(0);
    for(auto x: tezina_predmeta) ukupna += x;
    return ukupna + DajTezinu();
}

void Vreca::Ispisi() const
{
    std::cout << "Vrsta spremnika: Vreca" << std::endl;
    std::cout << "Sadrzaj: " << DajNaziv() << std::endl;
    std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Tezina pohranjene materije: " << tezina_materije << " (kg)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}
double Vreca::DajUkupnuTezinu() const
{
    return DajTezinu() + tezina_materije;
}
void Bure::Ispisi() const
{
    std::cout << "Vrsta spremnika: Bure" << std::endl;
    std::cout << "Sadrzaj: "<< DajNaziv() << std::endl;
    std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Specificna tezina tecnosti: " << gustina_tecnosti << " (kg/m^3)" << std::endl;
    std::cout << "Zapremina tecnosti: " << zapremina_tecnosti << " (l)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;

}
double Bure::DajUkupnuTezinu() const
{
    return zapremina_tecnosti * gustina_tecnosti * 0.001 + DajTezinu();
}
Sanduk::Sanduk(double tezina, std::string naziv_sadrzaja, std::vector<double> tezina_predmeta):
    Spremnik(tezina, naziv_sadrzaja)
{
    Sanduk::tezina_predmeta = tezina_predmeta;
}

Bure::Bure(double tezina, std::string naziv_sadrzaja, double gustina_tecnosti, double zapremina_tecnosti):
    Spremnik(tezina, naziv_sadrzaja), gustina_tecnosti(gustina_tecnosti),
    zapremina_tecnosti(zapremina_tecnosti) {}

Skladiste::Skladiste(const Skladiste &s)
{
    vektor_pokazivaca.resize(s.vektor_pokazivaca.size());
    for(int i = 0; i < vektor_pokazivaca.size(); i++)
        vektor_pokazivaca[i] = s.vektor_pokazivaca[i] ->DajKopiju();

}

Skladiste &Skladiste::operator= (const Skladiste &s)
{

    if(&s != this) {
        vektor_pokazivaca.resize(s.vektor_pokazivaca.size());
        for(int i = 0; i < vektor_pokazivaca.size(); i++)
            vektor_pokazivaca[i] = s.vektor_pokazivaca[i] -> DajKopiju();
    }

    return *this;
}
Skladiste &Skladiste::operator= (Skladiste &&s)
{
    std::swap(s.vektor_pokazivaca, vektor_pokazivaca);
    return *this;
}
Spremnik*Skladiste::DodajSanduk(double tezina, std::string naziv_sadrzaja, std::vector<double> tezina_predmeta)
{
    vektor_pokazivaca.emplace_back(std::make_shared<Sanduk>(tezina, naziv_sadrzaja,
                                   tezina_predmeta));
    return (vektor_pokazivaca.end() - 1)->get();
}
Spremnik* Skladiste::DodajBure(double tezina, std::string naziv_sadrzaja, double gustina_tecnosti, double zapremina_tecnosti)
{
    vektor_pokazivaca.emplace_back(std::make_shared<Bure>(tezina, naziv_sadrzaja,
                                   gustina_tecnosti, zapremina_tecnosti));

    return (vektor_pokazivaca.end() - 1)->get();
}
Spremnik* Skladiste::DodajVrecu(double tezina, std::string naziv_sadrzaja, double tezina_materije)
{
    vektor_pokazivaca.emplace_back(std::make_shared<Vreca>(tezina,
                                   naziv_sadrzaja, tezina_materije));
    return (vektor_pokazivaca.end() - 1)->get();
}
Spremnik* Skladiste::DodajSpremnik(Spremnik* pok, bool vlasnistvo)
{
    if(vlasnistvo) {

        vektor_pokazivaca.emplace_back(std::move(pok));
        return (vektor_pokazivaca.end() - 1)->get();
    } else {

        vektor_pokazivaca.emplace_back(pok->DajKopiju());
        return (vektor_pokazivaca.end() - 1)->get();
    }
}

void Skladiste::BrisiSpremnik(Spremnik* adresa)
{
    auto it(std::find_if(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [adresa](std::shared_ptr<Spremnik> pok) {
        return pok.get() == adresa;
    }));

    if(it != vektor_pokazivaca.end()) vektor_pokazivaca.erase(it);

}
Spremnik &Skladiste::DajNajlaksi()
{
    if(vektor_pokazivaca.size() == 0) throw std::range_error("Skladiste je prazno");
    return **std::min_element(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [] (std::shared_ptr<Spremnik> prvi,
    std::shared_ptr<Spremnik> drugi) {
        return prvi->DajTezinu() < drugi->DajTezinu();
    });
}
Spremnik &Skladiste::DajNajtezi()
{
    if(vektor_pokazivaca.size() == 0) throw std::range_error("Skladiste je prazno");
    return **std::max_element(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [](std::shared_ptr<Spremnik> prvi,
    std::shared_ptr<Spremnik> drugi) {
        return prvi->DajTezinu() < drugi -> DajTezinu();
    });
}
int Skladiste::BrojPreteskih(int x) const
{
    return std::count_if(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [x](std::shared_ptr<Spremnik> pok) {
        return pok->DajUkupnuTezinu() > x;
    });
}
void Skladiste::IzlistajSkladiste() const
{
    std::vector<std::shared_ptr<Spremnik>> novi (vektor_pokazivaca);
    std::sort(novi.begin(), novi.end(), [](std::shared_ptr<Spremnik> prvi, std::shared_ptr<Spremnik> drugi) {
        return prvi->DajUkupnuTezinu() > drugi->DajUkupnuTezinu();
    });

    std::for_each(novi.begin(), novi.end(), [](std::shared_ptr<Spremnik> pok) {
        pok -> Ispisi();
    });
}
void Skladiste::UcitajIzDatoteke(std::string ime_datoteke)
{
    std::ifstream ulazni_tok(ime_datoteke);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");

    vektor_pokazivaca.resize(0);

    char znak;
    std::string red;

    while (ulazni_tok >> znak) {
        ulazni_tok >> std::ws;
        std::getline(ulazni_tok, red);

        double tezina, tezina_materije, gustina_tecnosti, zapremina_tecnosti;

        if(znak == 'B') {
            ulazni_tok  >> tezina >>  gustina_tecnosti >> zapremina_tecnosti;
            if(!ulazni_tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            DodajBure(tezina, red.c_str(), gustina_tecnosti, zapremina_tecnosti);
        } else if (znak == 'S') {

            int broj_predmeta(0);
            ulazni_tok >> tezina >> broj_predmeta;
            std::vector<double> tezine;

            for(int i = 0; i < broj_predmeta; i++) {
                double trenutni;
                ulazni_tok >> trenutni;
                if (!ulazni_tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                tezine.emplace_back(trenutni);
            }

            DodajSanduk(tezina, red.c_str(), tezine);

        } else if(znak == 'V') {
            ulazni_tok >>  tezina >> tezina_materije;
            if(!ulazni_tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            DodajVrecu(tezina, red.c_str(), tezina_materije);

        } else
            throw std::logic_error("Datoteka sadrzi besmislene podatke");

    }
    ulazni_tok >> znak;

    if(!ulazni_tok && znak != '\n' && !ulazni_tok.eof()) throw std::logic_error("Problemi pri citanju datoteke");

}
class PolimorfniSpremnik
{
    std::shared_ptr<Spremnik> pok;
    void Prazan() const;
public:
    PolimorfniSpremnik(): pok(nullptr) {}
    PolimorfniSpremnik(const Spremnik &s): pok(s.DajKopiju()) {}
    PolimorfniSpremnik(const PolimorfniSpremnik &s);
    PolimorfniSpremnik (PolimorfniSpremnik &&s);
    PolimorfniSpremnik &operator = (const PolimorfniSpremnik &s);
    PolimorfniSpremnik &operator =(PolimorfniSpremnik && s) = default;


    void Ispisi() const;
    double DajTezinu() const;
    double DajUkupnuTezinu() const;

};

void PolimorfniSpremnik::Prazan() const
{
    if(!pok) throw std::logic_error("Nespecificiran spremnik");
}
PolimorfniSpremnik::PolimorfniSpremnik(const PolimorfniSpremnik &s)
{
    if(!s.pok) pok = std::move(nullptr);
    else pok = std::move(s.pok->DajKopiju());
}
PolimorfniSpremnik::PolimorfniSpremnik (PolimorfniSpremnik &&s)
{
    pok = std::move(s.pok);
    s.pok = std::move(nullptr);
}
PolimorfniSpremnik &PolimorfniSpremnik::operator = (const PolimorfniSpremnik &s)
{
    std::shared_ptr<Spremnik> novi;
    if(s.pok != nullptr) novi = std::move(s.pok->DajKopiju());

    pok = std::move(novi);
    return *this;
}

void PolimorfniSpremnik::Ispisi() const
{
    Prazan();
    pok -> Ispisi();
}
double PolimorfniSpremnik::DajTezinu() const
{
    Prazan();
    return pok -> DajTezinu();
}
double PolimorfniSpremnik::DajUkupnuTezinu() const
{
    Prazan();
    return pok -> DajUkupnuTezinu();
}



int main ()
{
    try{
        PolimorfniSpremnik s;
        s.DajTezinu();
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }


    PolimorfniSpremnik s1(Bure(5, "Benzin", 930, 70));
    PolimorfniSpremnik s2, s3;
    s2 = Sanduk(3, "Tepsije", {0.5, 0.8, 0.6, 0.5});
    s3 = Vreca(0.4, "Brasno", 30);

    std::cout << s1.DajTezinu() << std::endl;
    std::cout << s2.DajUkupnuTezinu() << std::endl;

    s3.Ispisi();
    s1 = s2;
    s1.Ispisi();
    return 0;
}
