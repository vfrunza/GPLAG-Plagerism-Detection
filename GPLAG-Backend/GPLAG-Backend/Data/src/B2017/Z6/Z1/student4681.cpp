/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include "string"
#include "vector"
#include "memory"
#include "stdexcept"
#include "algorithm"
#include "fstream"


class Spremnik
{
    protected:
    double kg;
    std::string name;
public:
    Spremnik(double tezina, std::string naziv) {
        if(tezina < 0) throw;
        kg = tezina;
        name = naziv;
    }
    virtual ~Spremnik() {}
    virtual std::shared_ptr<Spremnik> Copy() const = 0;
    double DajTezinu() const { return kg; }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
};

class Sanduk : public Spremnik  //cvrsti predmeti
{
    //double kg; //unsigned
    //std::string name;
    std::vector<double> tezine;
public:
    Sanduk(double tezina, std::string ime, std::vector<double> tezine): Spremnik(tezina, ime) {
        for(double x: tezine)
            if(x < 0) throw;
        this->tezine = tezine;
    } //-
    double DajUkupnuTezinu() const override {
        double suma(kg);
        for(double x : tezine) suma += x;
        return suma;
    }
    
    void Ispisi() const override {
        double suma(kg);
        std::cout << "Vrsta spremnika: Sanduk\n" <<
        "Sadrzaj: " << name << std::endl << "Tezine predmeta: ";
        for(double x : tezine) { std::cout << x << " "; suma += x; }
        std::cout << "(kg)\n" << "Vlastita tezina: " << kg << " (kg)\n" << "Ukupna tezina: " << suma << " (kg)\n";
    }
    std::shared_ptr<Spremnik> Copy() const override { return std::make_shared<Sanduk>(*this); }
};

class Vreca : public Spremnik  //praskasti predmeti
{
   // double kg;
   // std::string name;
    double kgmat; 
public:
    Vreca(double tezina, std::string ime, double kgmat): Spremnik(tezina, ime) {
        if(kgmat < 0) throw;
        this->kgmat = kgmat;
    }
    double DajUkupnuTezinu() const override { return kg + kgmat; }
    
    void Ispisi() const override {
        
        std::cout << "Vrsta spremnika: Vreca\n" <<
        "Sadrzaj: " << name << std::endl;
        std::cout <<"Vlastita tezina: " << kg << " (kg)\n" << "Tezina pohranjene materije: " << kgmat << " (kg)\n" <<
        "Ukupna tezina: " << kg + kgmat << " (kg)\n";
    }
    std::shared_ptr<Spremnik> Copy() const override { return std::make_shared<Vreca>(*this); }
};

class Bure : public Spremnik  //tecnost
{
    //double kg;
   // std::string name;
    double gustoca;
    double zapremina;
public:
    Bure(double tezina, std::string ime, double gustoca, double zapremina): Spremnik(tezina, ime) {
        if(gustoca < 0 || zapremina < 0) throw;
        this->gustoca = gustoca;
        this->zapremina = zapremina;
    }
    double DajUkupnuTezinu() const override { return ((zapremina / 1000.) * gustoca) + kg; }
    
    void Ispisi() const override {
        
        std::cout << "Vrsta spremnika: Bure\n" <<
        "Sadrzaj: " << name << std::endl;
        std::cout << "Vlastita tezina: " << kg << " (kg)\n" << "Specificna tezina tecnosti: " << gustoca << " (kg/m^3)\n" << 
        "Zapremina tecnosti: " << zapremina << " (l)\n" << "Ukupna tezina: " << ((zapremina / 1000.) * gustoca) + kg << " (kg)\n"; 
    }
    std::shared_ptr<Spremnik> Copy() const override { return std::make_shared<Bure>(*this); }
};

class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> items;
public:
    explicit Skladiste() {}
    Skladiste(const Skladiste& s) /*copy*/ {
        for(std::shared_ptr<Spremnik> x: s.items) items.push_back((*x).Copy());
    }
    
    Skladiste(Skladiste&& s) /*move*/ {
        std::swap(items, s.items);
    }
    
    Spremnik*/*?*/ DodajSanduk(double tezina, std::string ime, std::vector<double> tezine) {
        items.push_back(Sanduk(tezina, ime, tezine).Copy());
        return items.at(items.size()-1).get();
    }
    Spremnik* DodajVrecu(double tezina, std::string ime, double kgmat) {
        items.push_back(Vreca(tezina, ime, kgmat).Copy());
        return items.at(items.size()-1).get();
    }
    Spremnik* DodajBure(double tezina, std::string ime, double gustoca, double zapremina) {
        items.push_back(Bure(tezina, ime, gustoca, zapremina).Copy());
        return items.at(items.size()-1).get();
    }
    Spremnik* DodajSpremnik(Spremnik* s, bool predaja) {
        //true->deep
        if(predaja) {
            items.push_back((*s).Copy());
            delete s;
        } else {
            items.push_back(std::shared_ptr<Spremnik>(s));
            //return s;
        }
        return items.at(items.size()-1).get();
    }
    
    void BrisiSpremnik(Spremnik* s) {
        for(int i = 0; i < items.size(); i++) {
            std::shared_ptr<Spremnik> &x(items.at(i));
            if(x.get() == s) { x = nullptr; items.erase(items.begin() + i); }
        }
    }
    
    Spremnik &DajNajlaksi() {
        if(items.empty()) throw std::range_error("Skladiste je prazno");
        std::shared_ptr<Spremnik> najlaksi(items.at(0));
        for(std::shared_ptr<Spremnik> &x : items)
            if(x == nullptr) continue;
            else if(najlaksi->DajTezinu() > x->DajTezinu())
                    najlaksi = x;
        return *najlaksi;
    }
    
    Spremnik &DajNajtezi() {
        if(items.empty()) throw std::range_error("Skladiste je prazno");
        std::shared_ptr<Spremnik> najtezi(items.at(0));
        for(std::shared_ptr<Spremnik> &x : items)
            if(x == nullptr) continue;
            else if(najtezi->DajTezinu() > x->DajTezinu())
                    najtezi = x;
        return *najtezi;
    }
    
    int BrojPreteskih(int limit) const {
        int total(0);
        for(auto x : items)
            if(x == nullptr) continue;
            else if(x->DajUkupnuTezinu() > limit)
                total++;
        return total;
    }
    
    void IzlistajSkladiste() const {
        std::vector<std::shared_ptr<Spremnik>> copy;
        for(std::shared_ptr<Spremnik> x : items) {
            if(x == nullptr) continue;
            //if(!dynamic_cast<Sanduk*>(x) && !dynamic_cast<Vreca*>(x) && !dynamic_cast<Bure*>(x)) continue;
            else copy.push_back(x);
        }
        std::sort(copy.begin(), copy.end(), [](std::shared_ptr<Spremnik> one, std::shared_ptr<Spremnik> two)->bool { return two->DajUkupnuTezinu() < one->DajUkupnuTezinu(); });
        for(auto it = copy.begin(); it != copy.end(); it++) {
            (*it)->Ispisi();

        }
        copy.clear();
    }
    
    void UcitajIzDatoteke(std::string ime) {
        std::ifstream dat(ime);
        if(!dat.is_open()) throw std::logic_error("Trazena datoteka ne postoji");
        //Skladiste(std::move(*this)); //swap data or use for loop -> nullptr
        if((*this).items.size() != 0)
            for(int i = 0; i < items.size(); i++)
                items.at(i) = nullptr;
        std::string line, name;
        while(!dat.eof()) {
        std::getline(dat, line);
        name = line.substr(2);
        char type = line.at(0);
        //std::getline(dat, line);
        if(dat.bad()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        double mass, tezina, zapremina;
        std::vector<double> masses;
        dat.read((char*)&mass, sizeof(double));
        if(type == 'S') {
            int limit;
            double throww;
            while(dat.peek() == ' ');
            dat.read((char*)&limit, sizeof(int));
            for(int current = 0; current < limit; current++)
                if(dat.peek() != ' ') { dat.read((char*)&throww, sizeof(double)); masses.push_back(throww); }
            if(dat.bad()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            this->items.push_back(std::shared_ptr<Spremnik>(new Sanduk(mass, name, masses)));
        } else if(type == 'V') {
            while(dat.peek() == ' ');
            dat.read((char*)&tezina, sizeof(double));
            if(dat.bad()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            this->items.push_back(std::shared_ptr<Spremnik>(new Vreca(mass, name, tezina)));
        } else if(type == 'B') {
            while(dat.peek() == ' ');
            dat.read((char*)&tezina, sizeof(double));
            while(dat.peek() == ' ');
            dat.read((char*)&zapremina, sizeof(double));
            if(dat.bad()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            this->items.push_back(std::shared_ptr<Spremnik>(new Bure(mass, name, tezina, zapremina)));
        } else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
    }
};

int main ()
{

    return 0;
}
