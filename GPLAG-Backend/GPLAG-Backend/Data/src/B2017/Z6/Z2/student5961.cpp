/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <memory>
#include <utility>
#include <fstream>
#include <set>

/// IMPLEMENTATION OF BASE CLASS CLASS
class Spremnik {
protected:
    std::string naziv_objekta, ime_sadrzaja;
    double tezina_objekta;
public:
    Spremnik(const std::string& objekat, const std::string& naziv, const double& g) : 
        naziv_objekta(objekat), ime_sadrzaja(naziv), tezina_objekta(g) {}
    double DajTezinu() const { return tezina_objekta; }
    
    virtual ~Spremnik() {}
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const;
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0; // za polimofrizam
};

void Spremnik::Ispisi() const {
    std::cout << "Vrsta spremnika: " << naziv_objekta << std::endl;
    std::cout << "Sadrzaj: " << ime_sadrzaja << std::endl;
}

/// IMPLEMENTATION OF SUROGAT CLASS POLIMORFNISPREMNIK
class PolimorfniSpremnik {
private:
    std::shared_ptr<Spremnik> spremnik;
    void SpremnikExist() const { if(!spremnik) throw std::logic_error("Nespecificiran spremnik"); }
public:
    PolimorfniSpremnik() : spremnik(nullptr) {}
    PolimorfniSpremnik(const PolimorfniSpremnik& s) : spremnik(s.spremnik->DajKopiju()) {}
    PolimorfniSpremnik(PolimorfniSpremnik&& s) : spremnik(s.spremnik) { s.spremnik = nullptr; }
    PolimorfniSpremnik(const Spremnik& s) : spremnik(s.DajKopiju()) {}
    PolimorfniSpremnik(Spremnik&& s) : spremnik(s.DajKopiju()) {}
    PolimorfniSpremnik& operator=(const PolimorfniSpremnik& s) { spremnik = s.spremnik->DajKopiju(); return *this; }
    PolimorfniSpremnik& operator=(PolimorfniSpremnik&& s) { std::swap(spremnik, s.spremnik); return *this; }
    PolimorfniSpremnik& operator=(const Spremnik& s) { spremnik = s.DajKopiju(); return *this; }
    PolimorfniSpremnik& operator=(Spremnik&& s) { spremnik = s.DajKopiju(); return *this; }
    
    double DajTezinu() const { SpremnikExist(); return spremnik->DajTezinu(); }
    double DajUkupnuTezinu() const { SpremnikExist(); return spremnik->DajUkupnuTezinu(); }
    void Ispisi() const { SpremnikExist(); return spremnik->Ispisi(); }
};

/// IMPLEMENTATION OF SANDUK CLASS  
class Sanduk : public Spremnik {
private:
    std::vector<double> tezine_predmeta;
public:
    std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Sanduk>(*this); }
    Sanduk(const double& g_sanduka, const std::string& naziv, const std::vector<double>& tezine) : 
        Spremnik("Sanduk", naziv, g_sanduka), tezine_predmeta(tezine) {}
    
    double DajUkupnuTezinu() const {
        double tezina(0);
        for (auto& val : tezine_predmeta) tezina += val;
        return tezina + Spremnik::tezina_objekta; 
    }
    void Ispisi() const;
};
/// IMPLEMENTATION OF VRECA CLASS
class Vreca : public Spremnik {
private:
    double tezina_predmeta;
public:
    std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Vreca>(*this); }
    Vreca(const double& g_vrece, const std::string& naziv, const double& tezina) : 
        Spremnik("Vreca", naziv, g_vrece), tezina_predmeta(tezina) {}
        
    double DajUkupnuTezinu() const { return DajTezinuPohranjeneMaterije() + Spremnik::tezina_objekta; }
    double DajTezinuPohranjeneMaterije() const { return tezina_predmeta; }
    void Ispisi() const;
};
/// IMPLEMENTATION OF BURE CLASS
class Bure : public Spremnik {
private:
    double  spec_gustoca, // kg/m3 
            zapremina_tecnosti; // l
public:
    std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Bure>(*this); }
    Bure(const double& g_bureta, const std::string& naziv, const double& spec_ro, const double& v) :
        Spremnik("Bure", naziv, g_bureta), spec_gustoca(spec_ro), zapremina_tecnosti(v) {}
    
    double DajUkupnuTezinu() const { return DajTezinuPohranjeneMaterije() + Spremnik::tezina_objekta; }
    double DajTezinuPohranjeneMaterije() const { return (DajSpecTezinu() * DajZapreminu()) / 1000.; }
    double DajSpecTezinu() const { return spec_gustoca; }
    double DajZapreminu() const { return zapremina_tecnosti; }
    void Ispisi() const;
};

/// ISPISI FUNKCIJE
void Sanduk::Ispisi() const {
    Spremnik::Ispisi();
    std::cout << "Tezine predmeta: "; for(auto x : tezine_predmeta) std::cout << x << " ";
    std::cout << "(kg)" << std::endl;
    std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}
void Bure::Ispisi() const {
    Spremnik::Ispisi();
    std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Specificna tezina tecnosti: " << DajSpecTezinu() << " (kg/m^3)" << std::endl;
    std::cout << "Zapremina tecnosti: " << DajZapreminu() << " (l)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;   
}
void Vreca::Ispisi() const {
    Spremnik::Ispisi();
    std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Tezina pohranjene materije: " << DajTezinuPohranjeneMaterije() << " (kg)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;     
}

///////// IMPLEMENTATION OF SKLADISTE
class Skladiste {
private:
    std::vector<std::shared_ptr<Spremnik>> spremnici;
public:
    /// NIJE IMPLEMENTIRANO
    Skladiste() {}
    ~Skladiste() = default;
    Skladiste(const Skladiste& s);
    Skladiste(Skladiste&& s);
    
    Skladiste& operator=(const Skladiste& s);
    Skladiste& operator=(Skladiste&& s);
    
    /// IMPLEMENTIRANO
    Spremnik* DodajSanduk(const double& g_sanduka, const std::string& naziv, const std::vector<double>& tezine);
    Spremnik* DodajVrecu(const double& g_vrece, const std::string& naziv, const double& tezina);
    Spremnik* DodajBure(const double& g_bureta, const std::string& naziv, const double& spec_ro, const double& v);
    
    Spremnik* DodajSpremnik(Spremnik* spremnik, bool vlasnistvo);
    void BrisiSpremnik(Spremnik* spremnik);
    
    Spremnik& DajNajlaksi();
    Spremnik& DajNajtezi();
    
    int BrojPreteskih(const double& value) const;
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(const std::string& datoteka);
};
/// ctors and operators=
Skladiste::Skladiste(const Skladiste& s) {
    for(auto& x : s.spremnici)
        spremnici.push_back(x->DajKopiju());
}
Skladiste::Skladiste(Skladiste&& s) {
    spremnici.clear();
    std::swap(spremnici, s.spremnici);
}

Skladiste& Skladiste::operator=(const Skladiste& s) {
    spremnici.clear();
    for(auto& x : s.spremnici)
        spremnici.push_back(x->DajKopiju());
    return *this;
}
Skladiste& Skladiste::operator=(Skladiste&& s) {
    spremnici.clear();
    std::swap(spremnici, s.spremnici);
    return *this;
}

/// add to skladiste data
Spremnik* Skladiste::DodajSanduk(const double& g_sanduka, const std::string& naziv, const std::vector<double>& tezine) {
    return DodajSpremnik(new Sanduk(g_sanduka, naziv, tezine), true);
}
Spremnik* Skladiste::DodajVrecu(const double& g_vrece, const std::string& naziv, const double& tezina) {
    return DodajSpremnik(new Vreca(g_vrece, naziv, tezina), true);
}
Spremnik* Skladiste::DodajBure(const double& g_bureta, const std::string& naziv, const double& spec_ro, const double& v) {
    return DodajSpremnik(new Bure(g_bureta, naziv, spec_ro, v), true);
}
/// mutatori i inspektori
Spremnik& Skladiste::DajNajlaksi() {
    if(spremnici.empty())
        throw std::range_error("Skladiste je prazno");
        
    return **std::min_element(spremnici.begin(), spremnici.end(), 
        [](const std::shared_ptr<Spremnik>& lhs, const std::shared_ptr<Spremnik>& rhs) { 
            return lhs->DajTezinu() < rhs->DajTezinu(); 
    });
}
Spremnik& Skladiste::DajNajtezi() {
    if(spremnici.empty())
        throw std::range_error("Skladiste je prazno");
    return **std::min_element(spremnici.begin(), spremnici.end(), 
        [](const std::shared_ptr<Spremnik>& lhs, const std::shared_ptr<Spremnik>& rhs) { 
            return lhs->DajTezinu() > rhs->DajTezinu(); 
    });
}
int Skladiste::BrojPreteskih(const double& value) const {
    return std::count_if(spremnici.begin(), spremnici.end(), [&value](const std::shared_ptr<Spremnik>& lhs) { return lhs->DajUkupnuTezinu() > value; });
}

/// IO CONTROL
void Skladiste::IzlistajSkladiste() const {
    auto compare = [](const std::shared_ptr<Spremnik>& lhs, const std::shared_ptr<Spremnik>& rhs) -> bool {
        return lhs->DajUkupnuTezinu() > rhs->DajUkupnuTezinu(); 
    };
    std::set<std::shared_ptr<Spremnik>, decltype(compare)> _set (compare);
    for(auto data : spremnici) _set.insert(data);
    std::for_each(_set.begin(), _set.end(), [](const std::shared_ptr<Spremnik>& s) { s->Ispisi(); });
}
void Skladiste::UcitajIzDatoteke(const std::string& datoteka) {
    std::vector<std::shared_ptr<Spremnik>> novi_spremnici;
    std::ifstream ulazni_tok(datoteka, std::ios::in);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    
    std::string naziv_predmeta;
    char tip, delim;
    for(;;) {
        ulazni_tok >> tip;
        delim = ulazni_tok.get();
        std::getline(ulazni_tok, naziv_predmeta);
        if(tip == 'B') {
            double tez_bureta, spec_tezina, zapremina;
            
            ulazni_tok >> tez_bureta >> spec_tezina >> zapremina;
            if(!ulazni_tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            
            novi_spremnici.push_back(std::shared_ptr<Spremnik>(new Bure(tez_bureta, naziv_predmeta, spec_tezina, zapremina)));
        }
        else if(tip == 'S') {
            int broj_stvari, i;
            double tez_sanduka, tezina_trenutnog;
            std::vector<double> podaci_tezina;
            
            ulazni_tok >> tez_sanduka >> broj_stvari;
            for(i = 0; i < broj_stvari && (!ulazni_tok.eof() && ulazni_tok.peek() != '\n'); ++i) {
                ulazni_tok >> tezina_trenutnog;
                podaci_tezina.push_back(tezina_trenutnog);
            }
            if(!ulazni_tok || i != broj_stvari) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            
            novi_spremnici.push_back(std::shared_ptr<Spremnik>(new Sanduk(tez_sanduka, naziv_predmeta, podaci_tezina)));
        }
        else if(tip == 'V') {
            double tez_vrece, tez_stvari;
            
            ulazni_tok >> tez_vrece >> tez_stvari;
            if(!ulazni_tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            
            novi_spremnici.push_back(std::shared_ptr<Spremnik>(new Vreca(tez_vrece, naziv_predmeta, tez_stvari)));
        }
        else if(!ulazni_tok.eof() || delim != ' ')
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
        
        if(ulazni_tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
        if(ulazni_tok.eof()) break;
    }
    spremnici.clear();
    spremnici = novi_spremnici;
}
Spremnik* Skladiste::DodajSpremnik(Spremnik* spremnik, bool vlasnistvo) {
    std::shared_ptr<Spremnik> novi_spremnik (nullptr);
    if(!vlasnistvo) novi_spremnik = spremnik->DajKopiju();
    else novi_spremnik = std::shared_ptr<Spremnik>(spremnik);
    spremnici.push_back(novi_spremnik);
    return novi_spremnik.get();
}
void Skladiste::BrisiSpremnik(Spremnik* spremnik) {
    auto it = std::find_if(spremnici.begin(), spremnici.end(), [&spremnik](const std::shared_ptr<Spremnik>& lhs) {
        return lhs.get() == spremnik;
    });
    
    if(it != spremnici.end()) 
        spremnici.erase(it);
}


int main () {
    try {
        Skladiste s;
        s.UcitajIzDatoteke("ROBA.TXT");
        s.IzlistajSkladiste();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
	return 0;
}
