#include <iostream>
#include <fstream>
#include <stdexcept>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class Spremnik {
    protected:
      double tezina;
      std::string naziv_sadrzaja;
    public:
    Spremnik(double tez, std::string naziv_sadrzaja) : tezina(tez), naziv_sadrzaja(naziv_sadrzaja) {}
    double DajTezinu() const {return tezina;}
    virtual double DajUkupnuTezinu() const {return 0.;}
    virtual void Ispisi() const {}
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;
    virtual ~Spremnik() {}
};

class Bure : public Spremnik {
    double gustina_tecnosti, zapremina_tecnosti;
  public:
    Bure(double tez, std::string naziv, double gus_tecnosti, double zap_tecnosti) : Spremnik(tez, naziv), gustina_tecnosti(gus_tecnosti), zapremina_tecnosti(zap_tecnosti) {}
    double DajUkupnuTezinu() const override { return tezina + gustina_tecnosti*(zapremina_tecnosti/1000); }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Bure\n" << "Sadrzaj: " << naziv_sadrzaja << std::endl << "Vlastita tezina: " << tezina << " (kg)" << std::endl 
        << "Specificna tezina tecnosti: " << gustina_tecnosti << " (kg/m^3)" << std::endl 
        << "Zapremina tecnosti: " << zapremina_tecnosti << " (l)" << std::endl << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)\n";
    }
    std::shared_ptr<Spremnik> DajKopiju()  const override { return std::make_shared<Bure>(*this); }
};

class Sanduk : public Spremnik  {
    std::vector<double> tezine;
  public:
    Sanduk(double tez, std::string naziv, std::vector<double> tezine_predmeta) : Spremnik(tez, naziv), tezine(tezine_predmeta) {}
    double DajUkupnuTezinu() const override {
        double suma(0);
        for(double x : tezine) suma+=x;
        return tezina + suma; 
        
    }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Sanduk\n" << "Sadrzaj: " << naziv_sadrzaja << std::endl;
        std::cout << "Tezine predmeta: "; for(auto x : tezine) std::cout << x << " ";
        std::cout << "(kg)" << std::endl;
        std::cout << "Vlastita tezina: " << tezina << " (kg)"  << std::endl << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)\n";
    }
    std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Sanduk>(*this); }
    
};

class Vreca : public Spremnik {
    double tezina_materijala;
  public:
    Vreca(double tez, std::string naziv, double tez_materijala) : Spremnik(tez, naziv), tezina_materijala(tez_materijala) {}
    double DajUkupnuTezinu() const  override { return tezina + tezina_materijala; }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Vreca\n" << "Sadrzaj: " << naziv_sadrzaja << std::endl << "Vlastita tezina: " << tezina << " (kg)" << std::endl 
        << "Tezina pohranjene materije: " << tezina_materijala << " (kg)" << std::endl << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)\n";
    }
    std::shared_ptr<Spremnik> DajKopiju()  const override { return std::make_shared<Vreca> (*this); }
};

class Skladiste {
    std::vector<std::shared_ptr<Spremnik>> skladiste;
    std::vector<Spremnik*> adrese;
  public:
    Skladiste() {}
    Skladiste(const Skladiste &s);
    Skladiste(Skladiste &&s);
    Skladiste& operator=(const Skladiste &s);
    Skladiste& operator=(Skladiste &&s);
    Spremnik* DodajBure(double tez, std::string naziv, double gus_tecnosti, double zap_tecnosti);
    Spremnik* DodajVrecu(double tez, std::string naziv, double tez_materijala);
    Spremnik* DodajSanduk(double tez, std::string naziv, std::vector<double> tezine_predmeta);
    Spremnik* DodajSpremnik(Spremnik * pok, bool odgovornost);
    void BrisiSpremnik(Spremnik *pok);
    Spremnik& DajNajlaksi();
    Spremnik& DajNajtezi();
    int BrojPreteskih(double n) const;
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(const std::string &ime_datoteke);
};

void Skladiste::UcitajIzDatoteke(const std::string &ime_datoteke)
{
    skladiste.resize(0);
    adrese.resize(0);
    std::ifstream tok(ime_datoteke);
    if(!tok) throw std::logic_error("Trazena datoteka ne postoji");
    char znak,znak1;
    std::string s;
    while(tok >> znak && tok.get(znak1) && std::getline(tok,s)) {
        if(znak == 'S') {
            double tezina_sanduka;
            int broj_predmeta;
            std::vector<double> tez_predmeta;
            tok >> tezina_sanduka >> broj_predmeta;
            tez_predmeta.resize(broj_predmeta);
            for(int i = 0; i < broj_predmeta; i ++) {
                tok >> tez_predmeta[i];
            }
            if(tok) {
                *this->DodajSanduk(tezina_sanduka, s, tez_predmeta);
            }
            
        } else if(znak == 'V') {
            double tezina_vrece, tezina_u_vreci;
            tok >> tezina_vrece >> tezina_u_vreci;
            if(tok) {
                *this->DodajVrecu(tezina_vrece, s, tezina_u_vreci);
            }
            
        } else if(znak == 'B')  {
            double tezina, gustina, zapremina;
            tok >> tezina >> gustina >> zapremina;
            if(tok) {
                *this->DodajBure(tezina, s, gustina, zapremina);
            }
            
        } else {
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
    }
    if(tok.eof());
    else if(tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
    else throw std::logic_error("Datoteka sadrzi besmislene podatke");
}

void Skladiste::BrisiSpremnik(Spremnik *pok)
{
     for(int i = 0; i < adrese.size(); i++) {
         if(adrese[i] == pok) {
             skladiste.erase(skladiste.begin() + i);
             adrese.erase(adrese.begin() + i);
             break;
         }
     }
}

void Skladiste::IzlistajSkladiste() const 
{
    Skladiste tmp(*this);
    std::sort(tmp.skladiste.begin(), tmp.skladiste.end(), [](std::shared_ptr<Spremnik> pok1, std::shared_ptr<Spremnik> pok2){
       return pok1->DajUkupnuTezinu() > pok2->DajUkupnuTezinu(); 
    });
    std::for_each(tmp.skladiste.begin(), tmp.skladiste.end(), [](std::shared_ptr<Spremnik> pok1){
        pok1->Ispisi();
    });
}

int Skladiste::BrojPreteskih(double n) const
{
    return std::count_if(skladiste.begin(), skladiste.end(), [n](std::shared_ptr<Spremnik> pok1) {
         return pok1->DajUkupnuTezinu() > n;
        });
}

Spremnik& Skladiste::DajNajtezi() 
{
    if(!skladiste.size()) throw std::range_error("Skladiste je prazno");
    return **std::max_element(skladiste.begin(), skladiste.end(), [](std::shared_ptr<Spremnik> pok1, std::shared_ptr<Spremnik> pok2) {
            return pok1->DajTezinu() < pok2->DajTezinu();
        });
}

Spremnik& Skladiste::Skladiste::DajNajlaksi()
{
    if(!skladiste.size()) throw std::range_error("Skladiste je prazno");
    return **std::min_element(skladiste.begin(), skladiste.end(), [](std::shared_ptr<Spremnik> pok1, std::shared_ptr<Spremnik> pok2) {
            return pok1->DajTezinu() < pok2->DajTezinu();
        });
}

Spremnik* Skladiste::DodajSpremnik(Spremnik * pok, bool odgovornost)
{
    if(odgovornost) {
        std::shared_ptr<Spremnik> tmp(pok);
        skladiste.push_back(tmp);
        pok = nullptr;
        adrese.push_back(skladiste[skladiste.size() - 1].get());
        return skladiste[skladiste.size() - 1].get();
    } else {
        skladiste.push_back(pok->DajKopiju());
        adrese.push_back(skladiste[skladiste.size() - 1].get());
        return skladiste[skladiste.size() - 1].get();
    }
    
}

Spremnik* Skladiste::DodajBure(double tez, std::string naziv, double gus_tecnosti, double zap_tecnosti)
{
   Bure bure(tez, naziv, gus_tecnosti, zap_tecnosti);
   skladiste.push_back(bure.DajKopiju());
   adrese.push_back(bure.DajKopiju().get());
   return bure.DajKopiju().get();
}

Spremnik* Skladiste::DodajSanduk(double tez, std::string naziv, std::vector<double> tezine_predmeta)
{ 
   Sanduk sanduk(tez, naziv, tezine_predmeta);
   skladiste.push_back(sanduk.DajKopiju());
   adrese.push_back(sanduk.DajKopiju().get());
   return sanduk.DajKopiju().get();
}

Spremnik* Skladiste::DodajVrecu(double tez, std::string naziv, double tez_materijala)
{
   Vreca vreca(tez, naziv, tez_materijala);
   skladiste.push_back(vreca.DajKopiju());
   adrese.push_back(vreca.DajKopiju().get());
   return vreca.DajKopiju().get();
}

Skladiste::Skladiste(const Skladiste &s)
{
    try {
        skladiste.resize(s.skladiste.size());
        for(int i = 0; i < skladiste.size(); i++) {
            skladiste[i] = s.skladiste[i]->DajKopiju();
        }
    } catch (...) {
        skladiste.resize(0);
    }
}

Skladiste& Skladiste::operator=(const Skladiste &s)
{
    try {
        skladiste.resize(s.skladiste.size());
        for(int i = 0; i < skladiste.size(); i++) {
            skladiste[i] = s.skladiste[i]->DajKopiju();
        }
    } catch (...) {
        skladiste.resize(0);
    }
    return *this;
}

Skladiste::Skladiste(Skladiste &&s)
{
    skladiste.resize(s.skladiste.size());
    std::swap_ranges(s.skladiste.begin(), s.skladiste.end(), skladiste.begin());
}

Skladiste& Skladiste::operator=(Skladiste &&s)
{
    skladiste.resize(s.skladiste.size());
    std::swap_ranges(s.skladiste.begin(), s.skladiste.end(), skladiste.begin());
    return *this;
}

int main() {
    try {
        Skladiste s;
        s.UcitajIzDatoteke("ROBA.TXT");
        s.IzlistajSkladiste();
    } catch(std::logic_error izuzetak) {
        std::cout << izuzetak.what();
    } catch(std::range_error izuzetak) {
        std::cout << izuzetak.what();
    }
    return 0;
}

