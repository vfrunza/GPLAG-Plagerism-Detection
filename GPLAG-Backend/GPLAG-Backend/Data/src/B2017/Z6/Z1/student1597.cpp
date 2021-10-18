/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iterator>
#include <algorithm>
#include <new>
#include <functional>
#include <fstream>

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


class Skladiste {
    std::vector<std::shared_ptr<Spremnik>> vektor_pokazivaca;
public:
    Skladiste()=default;
    Skladiste(Skladiste &&s)=default;
    Skladiste &operator =(Skladiste &&s)=default;
    Skladiste (const Skladiste &s);
    Skladiste &operator =(const Skladiste &s);
    ~Skladiste()=default;
    Spremnik* DodajSanduk(double tezina_sanduka, std::string ime, std::vector<double> vektor_tezina);
    Spremnik* DodajVrecu(double tezina_vrece, std::string ime, double tezina);
    Spremnik* DodajBure(double tezina_bureta, std::string ime, double gustina, double zapremina);
    Spremnik* DodajSpremnik(Spremnik* pok, bool vlasnistvo);
    void BrisiSpremnik(Spremnik* adresa);
    Spremnik &DajNajlaksi();
    Spremnik &DajNajtezi();
    int BrojPreteskih(int zadana) const;
    int BrojPreteskih(int zadana);
    void IzlistajSkladiste();
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(std::string ime_datoteke);
};

void Skladiste::BrisiSpremnik(Spremnik* adresa) {
    auto iter(std::find_if(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [adresa](std::shared_ptr<Spremnik> pok) {
        return pok.get()==adresa;
    }));
    if (iter!=vektor_pokazivaca.end()) vektor_pokazivaca.erase(iter);
}

Spremnik* Skladiste::DodajSpremnik(Spremnik* pok, bool vlasnistvo) {
    if (vlasnistvo) {
        vektor_pokazivaca.push_back(std::shared_ptr<Spremnik>(pok));
        return pok;
    }
    else {
        std::shared_ptr<Spremnik> pametna_kopija(pok->DajKopiju());
        vektor_pokazivaca.push_back(pametna_kopija);
        return pametna_kopija.get();
    }
}

Spremnik* Skladiste::DodajSanduk(double tezina_sanduka, std::string ime, std::vector<double> vektor_tezina) {
    Spremnik* glupi_pokazivac(new Sanduk(tezina_sanduka, ime, vektor_tezina));
    vektor_pokazivaca.push_back(std::shared_ptr<Spremnik>(glupi_pokazivac));
    return glupi_pokazivac;
}

Spremnik* Skladiste::DodajVrecu(double tezina_vrece, std::string ime, double tezina) {
    Spremnik* glupi_pokazivac(new Vreca(tezina_vrece, ime, tezina));
    vektor_pokazivaca.push_back(std::shared_ptr<Spremnik>(glupi_pokazivac));
    return glupi_pokazivac;
}

Spremnik* Skladiste::DodajBure(double tezina_bureta, std::string ime, double gustina, double zapremina) {
    Spremnik* glupi_pokazivac(new Bure(tezina_bureta, ime, gustina, zapremina));
    vektor_pokazivaca.push_back(std::shared_ptr<Spremnik>(glupi_pokazivac));
    return glupi_pokazivac;
}

Skladiste::Skladiste(const Skladiste &s) {
    vektor_pokazivaca.resize(s.vektor_pokazivaca.size());
    for (int i=0; i<vektor_pokazivaca.size(); i++) {
        vektor_pokazivaca[i]=s.vektor_pokazivaca[i]->DajKopiju();
    }
}

Skladiste &Skladiste::operator =(const Skladiste &s) {
    if (&s==this) return *this;
    vektor_pokazivaca.resize(0);
    for (auto iter=s.vektor_pokazivaca.begin(); iter!=s.vektor_pokazivaca.end(); iter++) {
        vektor_pokazivaca.push_back((*iter)->DajKopiju());
    }
    return *this;
}

void Skladiste::UcitajIzDatoteke(std::string ime_datoteke) {
    std::ifstream ulazni_tok(ime_datoteke);
    if (!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    if (vektor_pokazivaca.size()!=0) vektor_pokazivaca.resize(0);
    while (1) {
        if (ulazni_tok.peek()==EOF) break;
        char znak;
        if (ulazni_tok.peek()=='B') {
            znak=ulazni_tok.get();
            if (ulazni_tok.get()!=' ') throw std::logic_error("Datoteka sadrzi besmislene podatke");
            std::string ime;
            std::getline(ulazni_tok, ime);
            double tezina_bureta, gustina, zapremina;
            ulazni_tok >> tezina_bureta >> gustina >> zapremina;
            if (!ulazni_tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            if (ulazni_tok.peek()!=EOF && ulazni_tok.peek()!='\n')
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            DodajBure(tezina_bureta, ime, gustina, zapremina);
            if (ulazni_tok.peek()==EOF) break;
            ulazni_tok.ignore(10000, '\n');
            continue;
        }
        else if (ulazni_tok.peek()=='S') {
            znak=ulazni_tok.get();
            if (ulazni_tok.get()!=' ') throw std::logic_error("Datoteka sadrzi besmislene podatke");
            std::string ime;
            std::getline(ulazni_tok, ime);
            double tezina_sanduka;
            int broj_predmeta;
            std::vector<double> vektor_tezina_predmeta;
            ulazni_tok >> tezina_sanduka >> broj_predmeta;
            if (!ulazni_tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            while (ulazni_tok.peek()!=EOF && ulazni_tok.peek()!='\n') {
                double tezina_jednog_predmeta;
                ulazni_tok >> tezina_jednog_predmeta;
                if (!ulazni_tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                vektor_tezina_predmeta.push_back(tezina_jednog_predmeta);
            }
            if (vektor_tezina_predmeta.size()!=broj_predmeta) {
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
            DodajSanduk(tezina_sanduka, ime, vektor_tezina_predmeta);
            if (ulazni_tok.peek()==EOF) break;
            ulazni_tok.ignore(10000, '\n');
            continue;
        }
        else if (ulazni_tok.peek()=='V') {
            znak=ulazni_tok.get();
            if (ulazni_tok.get()!=' ') throw std::logic_error("Datoteka sadrzi besmislene podatke");
            std::string ime;
            std::getline(ulazni_tok, ime);
            double tezina_vrece, tezina_materije;
            ulazni_tok >> tezina_vrece >> tezina_materije;
            if (!ulazni_tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            if (ulazni_tok.peek()!=EOF && ulazni_tok.peek()!='\n')
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            DodajVrecu(tezina_vrece, ime, tezina_materije);
            if (ulazni_tok.peek()==EOF) break;
            ulazni_tok.ignore(10000, '\n');
            continue;
        }
        else if (ulazni_tok.peek()!=EOF) {
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
    }
}

void Skladiste::IzlistajSkladiste() {
    std::vector<std::shared_ptr<Spremnik>> vektor;
    vektor=vektor_pokazivaca;
    std::sort(vektor.begin(), vektor.end(), [](std::shared_ptr<Spremnik> prvi, std::shared_ptr<Spremnik> drugi) {
        return (prvi->DajUkupnuTezinu())>(drugi->DajUkupnuTezinu());
    });
    std::for_each(vektor.begin(), vektor.end(), [](std::shared_ptr<Spremnik> pok) {
        pok->Ispisi();
        pok=nullptr;
    });
}

void Skladiste::IzlistajSkladiste() const {
    std::vector<std::shared_ptr<Spremnik>> vektor;
    vektor=vektor_pokazivaca;
    std::sort(vektor.begin(), vektor.end(), [](std::shared_ptr<Spremnik> prvi, std::shared_ptr<Spremnik> drugi) {
        return (prvi->DajUkupnuTezinu())>(drugi->DajUkupnuTezinu());
    });
    std::for_each(vektor.begin(), vektor.end(), [](std::shared_ptr<Spremnik> pok) {
        pok->Ispisi();
        pok=nullptr;
    });
}

Spremnik &Skladiste::DajNajlaksi() {
    if (vektor_pokazivaca.size()==0) throw std::range_error("Skladiste je prazno");
    return **std::min_element(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), 
    [](std::shared_ptr<Spremnik> prvi, std::shared_ptr<Spremnik> drugi) {
        return (prvi->DajTezinu())<(drugi->DajTezinu());
    });
}

Spremnik &Skladiste::DajNajtezi() {
    if (vektor_pokazivaca.size()==0) throw std::range_error("Skladiste je prazno");
    return **std::max_element(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), 
    [](std::shared_ptr<Spremnik> prvi, std::shared_ptr<Spremnik> drugi) {
        return (prvi->DajTezinu())<(drugi->DajTezinu());
    });
}

int Skladiste::BrojPreteskih(int zadana) const {
    return std::count_if(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [zadana](std::shared_ptr<Spremnik> pok) {
        return (pok->DajUkupnuTezinu())>zadana;
    });
}

int Skladiste::BrojPreteskih(int zadana) {
    return std::count_if(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [zadana](std::shared_ptr<Spremnik> pok) {
        return (pok->DajUkupnuTezinu())>zadana;
    });
}


int main ()
{
    try {
        Skladiste novo_skl;
        novo_skl.UcitajIzDatoteke("ROBA.TXT");
        novo_skl.IzlistajSkladiste();
    }
    catch(std::logic_error logicka) {
        std::cout << logicka.what();
    }
    catch(std::range_error rangovska) {
        std::cout << rangovska.what();
    }
	return 0;
}
