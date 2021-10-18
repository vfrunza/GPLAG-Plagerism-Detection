/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <string>

using std::vector;
using std::string;
using std::shared_ptr;
using std::cout;
using std::range_error;
using std::logic_error;
using std::sort;
using std::istringstream;
using std::getline;
using std::ifstream;

class Spremnik {
protected:
    float tezina;
    string naziv_predmeta;
public:
    Spremnik(float tezina, string naziv) : tezina(tezina), naziv_predmeta(naziv) {}
    virtual ~Spremnik() {}
    virtual float DajTezinu() const { return tezina; }
    virtual string DajIme() const { return naziv_predmeta; }
    virtual float DajUkupnuTezinu() const = 0;
    virtual shared_ptr<Spremnik> DajKopiju() const = 0;
    virtual void Ispisi() const = 0;
};

class Sanduk : public Spremnik {
    vector<float> tezine_predmeta;
public:
    Sanduk(float tezina, string naziv, vector<float> tezine_predmeta) : Spremnik(tezina, naziv),
        tezine_predmeta(tezine_predmeta) {}
    float DajTezinu() const override { return tezina; }
    float DajUkupnuTezinu() const override;
    shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Sanduk>(*this); }
    void Ispisi() const override;
};

float Sanduk::DajUkupnuTezinu() const {
    float ukupna_tezina_predmeta = 0;
    for(float tezina : tezine_predmeta) 
        ukupna_tezina_predmeta += tezina;
    return ukupna_tezina_predmeta + tezina; 
}

void Sanduk::Ispisi() const {
    cout << "Vrsta spremnika: Sanduk\n";
    cout << "Sadrzaj: " << naziv_predmeta << "\n";
    cout << "Tezine predmeta: ";
    for(float tezina : tezine_predmeta)
        cout << tezina << " ";
    cout << "(kg)\n";
    cout << "Vlastita tezina: " << tezina << " (kg)\n";
    cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)\n";
}

class Vreca : public Spremnik {
    float tezina_materije;
public:
    Vreca(float tezina, string naziv, float tezina_materije) : Spremnik(tezina, naziv),
        tezina_materije(tezina_materije) {}
    float DajTezinu() const override { return tezina; }
    float DajUkupnuTezinu() const override { return tezina_materije + tezina; }
    shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Vreca>(*this); }
    void Ispisi() const override;    
};

void Vreca::Ispisi() const {
    cout << "Vrsta spremnika: Vreca\n";
    cout << "Sadrzaj: " << naziv_predmeta << "\n";
    cout << "Vlastita tezina: " << tezina << " (kg)\n";
    cout << "Tezina pohranjene materije: " << tezina_materije << " (kg)\n";
    cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)\n";
}

class Bure : public Spremnik {
    float gustina;
    float zapremina;
public:
    Bure(float tezina, string naziv, float gustina, float zapremina) : Spremnik(tezina, naziv),
        gustina(gustina), zapremina(zapremina) {}
    float DajTezinu() const override { return tezina; }
    float DajUkupnuTezinu() const override { return tezina + gustina * zapremina * 0.001; }
    shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Bure>(*this); }
    void Ispisi() const override;
};

void Bure::Ispisi() const {
    cout << "Vrsta spremnika: Bure\n";
    cout << "Sadrzaj: " << naziv_predmeta << "\n";
    cout << "Vlastita tezina: " << tezina << " (kg)\n";
    cout << "Specificna tezina tecnosti: " << gustina << " (kg/m^3)\n";
    cout << "Zapremina tecnosti: " << zapremina << " (l)\n";
    cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)\n";
}

class Skladiste {
    vector<shared_ptr<Spremnik>> roba;
    
    const string greska_prazno_skladiste = "Skladiste je prazno";
    const string datoteka_ne_postoji = "Trazena datoteka ne postoji";
    const string problem_citanje_datoteke = "Problem pri citanju datoteke";
    const string datoteka_besmisleni_podaci = "Datoteka sadrzi besmislene podatke";
public:
    Skladiste() {}
    Skladiste(const Skladiste&);
    Skladiste& operator =(const Skladiste&);
    Spremnik* DodajSanduk(float, string, vector<float>);
    Spremnik* DodajVrecu(float, string, float);
    Spremnik* DodajBure(float, string, float, float);
    Spremnik* DodajSpremnik(Spremnik*, bool);
    void BrisiSpremnik(Spremnik*);
    Spremnik& DajNajlaksi();
    Spremnik& DajNajlaksi() const;
    Spremnik& DajNajtezi();
    Spremnik& DajNajtezi() const;
    int BrojPreteskih(int) const;
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(string);
};

Skladiste::Skladiste(const Skladiste& skladiste) {
    for(auto spremnik : skladiste.roba)
        roba.emplace_back(spremnik -> DajKopiju());
}

Skladiste& Skladiste::operator =(const Skladiste& skladiste) {
    if(&skladiste == this)
        return *this;
    roba.clear();
    for(auto spremnik : skladiste.roba)
        roba.emplace_back(spremnik -> DajKopiju());
    return *this;
}

Spremnik* Skladiste::DodajSanduk(float tezina, string naziv, vector<float> tezine_predmeta) {
    Sanduk* sanduk = new Sanduk(tezina, naziv, tezine_predmeta);
    return DodajSpremnik(sanduk, true);
}

Spremnik* Skladiste::DodajVrecu(float tezina, string naziv, float tezina_materije) {
    Vreca* vreca = new Vreca(tezina, naziv, tezina_materije);
    return DodajSpremnik(vreca, true);
}

Spremnik* Skladiste::DodajBure(float tezina, string naziv, float gustina, float zapremina) {
    Bure* bure = new Bure(tezina, naziv, gustina, zapremina);
    return DodajSpremnik(bure, true);
}

Spremnik* Skladiste::DodajSpremnik(Spremnik* spremnik, bool vlasnistvo) {
    if(vlasnistvo)
        roba.emplace_back((shared_ptr<Spremnik>) spremnik);
    else
        roba.emplace_back(spremnik -> DajKopiju());
    return &(*roba[roba.size() - 1]);
}

void Skladiste::BrisiSpremnik(Spremnik* spremnik) {
    for(int i = 0; i < roba.size(); i++) {
        if(roba[i].get() == spremnik) {
            roba.erase(roba.begin() + i);
            return;
        }
    }
}

Spremnik& Skladiste::DajNajlaksi() const {
    if(roba.empty())
        throw range_error(greska_prazno_skladiste);
    int indeks_najlakseg = 0;
    for(int i = 1; i < roba.size(); i++)
        if(roba[i] -> DajTezinu() < roba[indeks_najlakseg] -> DajTezinu())
            indeks_najlakseg = i;
    return *roba[indeks_najlakseg];
}

Spremnik& Skladiste::DajNajlaksi() {
    if(roba.empty())
        throw range_error(greska_prazno_skladiste);
    int indeks_najlakseg = 0;
    for(int i = 1; i < roba.size(); i++)
        if(roba[i] -> DajTezinu() < roba[indeks_najlakseg] -> DajTezinu())
            indeks_najlakseg = i;
    return *roba[indeks_najlakseg];
}

Spremnik& Skladiste::DajNajtezi() const {
    if(roba.empty())
        throw range_error(greska_prazno_skladiste);
    int indeks_najtezeg = 0;
    for(int i = 1; i < roba.size(); i++)
        if(roba[i] -> DajTezinu() > roba[indeks_najtezeg] -> DajTezinu())
            indeks_najtezeg = i;
    return *roba[indeks_najtezeg];
}

Spremnik& Skladiste::DajNajtezi() {
    if(roba.empty())
        throw range_error(greska_prazno_skladiste);
    int indeks_najtezeg = 0;
    for(int i = 1; i < roba.size(); i++)
        if(roba[i] -> DajTezinu() > roba[indeks_najtezeg] -> DajTezinu())
            indeks_najtezeg = i;
    return *roba[indeks_najtezeg];
}

int Skladiste::BrojPreteskih(int tezina) const {
    int broj_preteskih = 0;
    for(auto spremnik : roba)
        if(spremnik -> DajUkupnuTezinu() > tezina)
            broj_preteskih++;
    return broj_preteskih;
}

void Skladiste::IzlistajSkladiste() const {
    vector<shared_ptr<Spremnik>> roba_ispis;
    for(auto spremnik : roba)
        roba_ispis.emplace_back(spremnik -> DajKopiju());
    sort(roba_ispis.begin(), roba_ispis.end(),
        [](const shared_ptr<Spremnik>& x, const shared_ptr<Spremnik>& y)
            { return x -> DajUkupnuTezinu() > y -> DajUkupnuTezinu(); });
    for(auto spremnik : roba_ispis)
        spremnik -> Ispisi();
}

void Skladiste::UcitajIzDatoteke(string ime_datoteke) {
    ifstream datoteka(ime_datoteke);
    if(!datoteka)
        throw logic_error(datoteka_ne_postoji);
    roba.clear();
    while(!(datoteka.eof() || datoteka.bad())) {
        string spremnik_info;
        getline(datoteka, spremnik_info);
        
        string tezine;
        getline(datoteka, tezine);
        istringstream tezine_cifre(tezine);
        
        char pocetno_slovo = spremnik_info[0];
        spremnik_info.erase(spremnik_info.begin(), spremnik_info.begin() + 2);
        
        float tezina_spremnika;
        tezine_cifre >> tezina_spremnika;
        
        if(pocetno_slovo == 'S') {
            int ukupno_predmeta;
            if(tezine_cifre) 
                tezine_cifre >> ukupno_predmeta;
            else
                throw logic_error(datoteka_besmisleni_podaci);
            vector<float> tezine_predmeta;
            float t;
            while(tezine_cifre >> t) 
                tezine_predmeta.push_back(t);
            if(tezine_predmeta.size() != ukupno_predmeta)
                throw logic_error(datoteka_besmisleni_podaci);
            DodajSanduk(tezina_spremnika, spremnik_info, tezine_predmeta);
        }
        else if(pocetno_slovo == 'V') {
            float tezina_materije;
            if(tezine_cifre)
                tezine_cifre >> tezina_materije;
            else
                throw logic_error(datoteka_besmisleni_podaci);
            if(tezine_cifre.eof()) 
                DodajVrecu(tezina_spremnika, spremnik_info, tezina_materije);
            else
                throw logic_error(datoteka_besmisleni_podaci);
        }
        else if(pocetno_slovo == 'B') {
            float gustina, zapremina;
            if(tezine_cifre)
                tezine_cifre >> gustina;
            else
                throw logic_error(datoteka_besmisleni_podaci);
            if(tezine_cifre)
                tezine_cifre >> zapremina;
            else
                throw logic_error(datoteka_besmisleni_podaci);
            if(tezine_cifre.eof())
                DodajBure(tezina_spremnika, spremnik_info, gustina, zapremina);
            else
                throw logic_error(datoteka_besmisleni_podaci);
        }
    }
    if(datoteka.eof())
        return;
    if(datoteka.bad())
        throw logic_error(problem_citanje_datoteke);
}

int main () {
    try {
        Skladiste s;
        s.UcitajIzDatoteke("ROBA.TXT");
        s.IzlistajSkladiste();
    }
    catch(range_error e) {
        cout << e.what();
    }
    catch(logic_error e) {
        cout << e.what();
    }
	return 0;
}