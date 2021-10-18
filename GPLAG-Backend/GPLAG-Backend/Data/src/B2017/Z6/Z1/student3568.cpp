/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <fstream>

class Spremnik
{
protected:
    double tezina;
    std::string ime_sadrzaja;
public:
    Spremnik (double tezina, std::string ime_sadrzaja) :
        tezina(tezina), ime_sadrzaja(ime_sadrzaja) {}
    double DajTezinu() const {
        return tezina;
    }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const {
        std::cout << "Sadrzaj: " << ime_sadrzaja << std::endl;
    }
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;

};

typedef std::shared_ptr<Spremnik> PokNaSpremnik;

class Sanduk : public Spremnik
{
    std::vector<double> tezina_sadrzaja;
public:
    Sanduk(double tezina, std::string ime_sadrzaja, std::vector<double> tezina_sadrzaja) :
        Spremnik(tezina, ime_sadrzaja), tezina_sadrzaja(tezina_sadrzaja) {}
    double DajUkupnuTezinu() const override {
        double ukupna_tezina(tezina);
        for(auto e : tezina_sadrzaja) ukupna_tezina+=e;
        return ukupna_tezina;
    }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Sanduk" << std::endl;
        Spremnik::Ispisi();
        std::cout << "Tezine predmeta: ";
        for(auto e : tezina_sadrzaja)
            std::cout << e  << " ";
        std::cout << "(kg)" << std::endl;
        std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
        std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    PokNaSpremnik DajKopiju() const {
        return std::make_shared<Sanduk>(*this);
    }
};

class Vreca : public Spremnik
{
    double tezina_sadrzaja;
public:
    Vreca(double tezina, std::string ime_sadrzaja, double tezina_sadrzaja) :
        Spremnik(tezina, ime_sadrzaja), tezina_sadrzaja(tezina_sadrzaja) {}
    double DajUkupnuTezinu() const override {
        return tezina + tezina_sadrzaja;
    }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Vreca" << std::endl;
        Spremnik::Ispisi();
        std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
        std::cout << "Tezina pohranjene materije: " << tezina_sadrzaja << " (kg)" << std::endl;
        std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    PokNaSpremnik DajKopiju() const {
        return std::make_shared<Vreca>(*this);
    }
};

class Bure : public Spremnik
{
    double gustina_sadrzaja, zapremina_sadrzaja;
public:
    Bure(double tezina, std::string ime_sadrzaja, double gustina_sadrzaja, double zapremina_sadrzaja):
        Spremnik(tezina, ime_sadrzaja), gustina_sadrzaja(gustina_sadrzaja), zapremina_sadrzaja(zapremina_sadrzaja) {}
    double DajUkupnuTezinu() const override {
        return tezina + gustina_sadrzaja * zapremina_sadrzaja/1000.;
    }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Bure" << std::endl;
        Spremnik::Ispisi();
        std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
        std::cout << "Specificna tezina tecnosti: " << gustina_sadrzaja << " (kg/m^3)" << std::endl;
        std::cout << "Zapremina tecnosti: " << zapremina_sadrzaja << " (l)" << std::endl;
        std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    PokNaSpremnik DajKopiju() const {
        return std::make_shared<Bure>(*this);
    }
};

class Skladiste
{
    std::vector<PokNaSpremnik> skladiste;
    std::vector<Spremnik*> adrese;
public:
    Skladiste() {}
    Skladiste(const Skladiste &s);
    Skladiste(Skladiste &&s);
    Skladiste& operator = (const Skladiste &s);
    Skladiste& operator = (Skladiste &&s);
    Sanduk* DodajSanduk(double tezina, std::string ime_sadrzaja, std::vector<double> tezina_sadrzaja) {
        std::shared_ptr<Sanduk> s = std::make_shared<Sanduk>(tezina, ime_sadrzaja, tezina_sadrzaja);
        skladiste.push_back(s);
        adrese.push_back(s.get());
        return s.get();
    }
    Vreca* DodajVrecu(double tezina, std::string ime_sadrzaja, double tezina_sadrzaja) {
        std::shared_ptr<Vreca> v = std::make_shared<Vreca>(tezina, ime_sadrzaja, tezina_sadrzaja);
        skladiste.push_back(v);
        adrese.push_back(v.get());
        return v.get();
    }
    Bure* DodajBure(double tezina, std::string ime_sadrzaja, double gustina_sadrzaja, double zapremina_sadrzaja) {
        std::shared_ptr<Bure> b = std::make_shared<Bure>(tezina, ime_sadrzaja, gustina_sadrzaja, zapremina_sadrzaja);
        skladiste.push_back(b);
        adrese.push_back(b.get());
        return b.get();
    }
    Spremnik* DodajSpremnik(Spremnik* s, bool predaje_vlasnistvo) {
        if(!predaje_vlasnistvo) {
            PokNaSpremnik pok = s->DajKopiju();
            skladiste.push_back(pok);
            adrese.push_back(s);
            return pok.get();
        } else {
            skladiste.push_back(std::shared_ptr<Spremnik>(s));
            adrese.push_back(s);
            return s;
        }
    }
    void BrisiSpremnik(Spremnik* s);
    Spremnik& DajNajtezi();
    Spremnik& DajNajlaksi();
    int BrojPreteskih(int n) const;
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(std::string ime_datoteke);

};

void Skladiste::BrisiSpremnik(Spremnik* s)
{
    auto it(std::find_if(adrese.begin(), adrese.end(), [s](Spremnik* s1) {
        return s1==s;
    }));
    int pozicija(it-adrese.begin());
    adrese.erase(it);
    auto itt=skladiste.begin();
    itt+=pozicija;
    skladiste.erase(itt);
}

Spremnik& Skladiste::DajNajtezi()
{
    if(skladiste.size()==0)
        throw std::range_error("Skladiste je prazno");
    auto it(std::max_element(skladiste.begin(), skladiste.end(), [](PokNaSpremnik s1, PokNaSpremnik s2) {
        return s1->DajTezinu() < s2->DajTezinu();
    }));
    return **it;
}
Spremnik& Skladiste::DajNajlaksi()
{
    if(skladiste.size()==0)
        throw std::range_error("Skladiste je prazno");
    auto it(std::min_element(skladiste.begin(), skladiste.end(), [](PokNaSpremnik s1, PokNaSpremnik s2) {
        return s1->DajTezinu() < s2->DajTezinu();
    }));
    return **it;
}

int Skladiste::BrojPreteskih(int n) const
{
    int broj_preteskih(std::count_if(skladiste.begin(), skladiste.end(), [n](PokNaSpremnik s) {
        return s->DajUkupnuTezinu() > n;
    }));
    return broj_preteskih;
}

void Skladiste::IzlistajSkladiste() const
{
    std::vector<PokNaSpremnik> tmp(skladiste);
    std::sort(tmp.begin(), tmp.end(), [](PokNaSpremnik s1, PokNaSpremnik s2) {
        return s1->DajUkupnuTezinu() > s2->DajUkupnuTezinu();
    });
    for(int i=0; i<tmp.size(); i++)
        tmp[i]->Ispisi();
}

void Skladiste::UcitajIzDatoteke(std::string ime_datoteke)
{
    std::ifstream ulazni_tok(ime_datoteke);
    if(!ulazni_tok)
        throw std::logic_error("Trazena datoteka ne postoji");
    Skladiste tmp(*this);
    skladiste.resize(0);
    adrese.resize(0);
    char slovo;
    std::string naziv;
    double tezina, tezina1;
    bool besmisleno(false);
    while (ulazni_tok >> slovo) {
        ulazni_tok.ignore(1000, ' ');
        std::getline(ulazni_tok, naziv);
        if(!ulazni_tok) {
            besmisleno = true;
            break;
        }
        if(slovo == 'S') {
            int broj_predmeta;
            std::vector<double> tezine;
            ulazni_tok >> tezina >> broj_predmeta;
            if(!ulazni_tok) {
                besmisleno = true;
                break;
            }
            double b;
            for(int i=0; i<broj_predmeta; i++) {
                ulazni_tok >> b;
                tezine.push_back(b);
                if(!ulazni_tok) {
                    besmisleno = true;
                    break;
                }
            }
            if(besmisleno) break;
            if(ulazni_tok.peek() != '\n'){
                besmisleno = true;
                break; 
            }
            DodajSanduk(tezina, naziv, tezine);
        }
        if(slovo == 'B') {
            double zapremina;
            ulazni_tok >> tezina >> tezina1 >> zapremina;
            if(!ulazni_tok) {
                besmisleno = true;
                break;
            }
            DodajBure(tezina, naziv, tezina1, zapremina);
        }
        if(slovo == 'V') {
            ulazni_tok >> tezina >> tezina1;
            if(!ulazni_tok) {
                besmisleno = true;
                break;
            }
            DodajVrecu(tezina, naziv, tezina1);
        }
    }
    if(besmisleno){
        *this = tmp;
        throw std::logic_error ("Datoteka sadrzi besmislene podatke");
    }
    if(!ulazni_tok && !ulazni_tok.eof()){
        *this = tmp;
        throw std::logic_error ("Problemi pri citanju datoteke");
    }
}

Skladiste::Skladiste(const Skladiste &s){
    adrese = s.adrese;
    for(int i=0; i<s.skladiste.size(); i++)
        skladiste.push_back(s.skladiste[i]->DajKopiju());
    
}
Skladiste::Skladiste(Skladiste &&s){
    adrese = s.adrese;
    skladiste = std::move(s.skladiste);
    for(auto &e : s.skladiste) e = nullptr;
}
Skladiste& Skladiste::operator = (const Skladiste &s){
    std::vector<PokNaSpremnik> tmp;
    try {
        for(int i=0; i<s.skladiste.size(); i++)
            tmp.push_back(s.skladiste[i]->DajKopiju());
    }
    catch (...) {
        throw;
    }
    
    adrese = s.adrese;
    skladiste=std::move(tmp);
    for(auto &e : tmp) e = nullptr;
    return *this;
}
Skladiste& Skladiste::operator = (Skladiste &&s){
    adrese = s.adrese;
    skladiste = std::move(s.skladiste);
    for(auto &e : s.skladiste) e = nullptr;
    return *this;
}

int main ()
{

    Skladiste ETF;
    std::string s = "ROBA.TXT";
    try {
        ETF.UcitajIzDatoteke(s);
        ETF.IzlistajSkladiste();
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
