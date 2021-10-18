/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <utility>
#include <memory> 
#include <algorithm>
#include <fstream>

class Spremnik {
    
    protected:
        double tezinaSpremnika;
        std::string nazivSpremnika;
    
    public:
        Spremnik(double tezina, std::string naziv) : tezinaSpremnika(tezina), nazivSpremnika(naziv) {}
        double DajTezinu() const {
            return tezinaSpremnika;
        }
        virtual double DajUkupnuTezinu() const = 0;
        virtual void Ispisi() const = 0;
        virtual Spremnik* DajKopiju() const = 0;
        virtual ~Spremnik() {}
};

class Sanduk : public Spremnik {
    std::vector<double> tezinePredmeta;
    
    public:
        Sanduk(double tezina_p, std::string naziv_p, std::vector<double> tezine_p) : Spremnik(tezina_p, naziv_p), tezinePredmeta(tezine_p) {}
        
        double DajUkupnuTezinu() const override {
            double ukupno = Spremnik::DajTezinu();
            for (double d : tezinePredmeta)
                ukupno += d;
            return ukupno;
        }
        
        void Ispisi() const override {
            std::cout << "Vrsta spremnika: Sanduk\nSadrzaj: " << Spremnik::nazivSpremnika << std::endl;
            std::cout << "Tezine predmeta: ";
            
            for (auto i:tezinePredmeta)
                std::cout << i << " ";
            
            std::cout << "(kg)" << std::endl;
            std::cout << "Vlastita tezina: " << Spremnik::DajTezinu() << " (kg)" << std::endl;
            std::cout << "Ukupna tezina: "<< DajUkupnuTezinu() << " (kg)" << std::endl;
        }
        
        Sanduk* DajKopiju() const {
            return new Sanduk(DajTezinu(), Spremnik::nazivSpremnika, Sanduk::tezinePredmeta);
        } 
        
};

class Vreca : public Spremnik {
    double tezinePraskasteMaterije;
    
    public:
        Vreca(double tezina, std::string naziv, double tezine) : Spremnik(tezina, naziv), tezinePraskasteMaterije(tezine) {}
        
        double DajUkupnuTezinu() const override {
            return DajTezinu() + tezinePraskasteMaterije;
        }
        
        void Ispisi() const override {
            std::cout << "Vrsta spremnika: Vreca" << std::endl;
            std::cout << "Sadrzaj: " << Spremnik::nazivSpremnika << std::endl;
            std::cout << "Vlastita tezina: " << Spremnik::DajTezinu() << " (kg)" << std::endl;
            std::cout << "Tezina pohranjene materije: " << DajUkupnuTezinu() - DajTezinu() << " (kg)" << std::endl;
            std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
            
        }
        
        Vreca* DajKopiju() const {
            return new Vreca(DajTezinu(), nazivSpremnika, tezinePraskasteMaterije);
        }
};

class Bure : public Spremnik {
    double zapremina;
    double specificnaTezina;
    
    public:
        Bure(double tezina_p, std::string naziv_p, double specificnaTezina_p, double zapremina_p) : Spremnik(tezina_p, naziv_p), specificnaTezina(specificnaTezina_p), zapremina(zapremina_p) {}
        
        double DajUkupnuTezinu() const override {
            return zapremina * specificnaTezina * 1e-3 + DajTezinu();
        }
        
        void Ispisi() const override {
            std::cout << "Vrsta spremnika: Bure" << std::endl;
            std::cout << "Sadrzaj: " << Spremnik::nazivSpremnika << std::endl;
            std::cout << "Vlastita tezina: " << Spremnik::DajTezinu() << " (kg)" << std::endl;
            std::cout << "Specificna tezina tecnosti: " << specificnaTezina << " (kg/m^3)" << std::endl;
            std::cout << "Zapremina tecnosti: " << zapremina << " (l)" << std::endl;
            std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
        }
        
        Bure* DajKopiju() const {
            return new Bure(DajTezinu(), Spremnik::nazivSpremnika, specificnaTezina, zapremina);
        }
    
};

class Skladiste {
    std::vector<std::shared_ptr<Spremnik>> spremnici;
    
    public:
        Skladiste() {
            spremnici.clear();
        }
    ~Skladiste() {
        for (int i = 0; i < spremnici.size(); i++)
            spremnici[i] = nullptr;
        
    }
    
    Skladiste(const Skladiste &s) {
        try {
            spremnici.clear();
            
            for (auto i : spremnici) {
             spremnici.push_back(i);
            }
            
        }
        
        catch (...) {
            throw;
        }
        
    }
    
    Skladiste &operator=(const Skladiste &s) {
        spremnici = s.spremnici;
        return *this;
    }
    
    Sanduk* DodajSanduk(double tezina, std::string naziv, std::vector<double> tezine) {
        auto privremeno (std::make_shared<Sanduk> (tezina, naziv, tezine));
        spremnici.push_back(privremeno);
        return privremeno.get();
    }
    
    Vreca* DodajVrecu(double tezina, std::string naziv, double tezine) {
        auto privremeno (std::make_shared<Vreca>(tezina, naziv, tezine));
        spremnici.push_back(privremeno);
        return privremeno.get();
    }
    
    Bure* DodajBure(double tezina, std::string naziv, double specificnaTezina, double zapremina) {
        auto privremeno (std::make_shared<Bure>(tezina, naziv, specificnaTezina, zapremina));
        spremnici.push_back(privremeno);
        return privremeno.get();
    }
    
    Spremnik* DodajSpremnik(Spremnik *objekat, bool predatiVlasnistvo) {
        
        if (!predatiVlasnistvo) {
            std::shared_ptr<Spremnik>privremeno(objekat->DajKopiju());
            spremnici.push_back(privremeno);
            return privremeno.get();
        }
        
        std::shared_ptr<Spremnik>p(objekat);
        spremnici.push_back(p);
        return p.get();
        
    }
    
    Spremnik* BrisiSpremnik(Spremnik *s) {
        if (spremnici.size() == 0)
            throw std::range_error("Skladiste je prazno\n");
        
        for (int i = 0; i < spremnici.size(); i++) {
            if (spremnici[i].get() == s) {
                spremnici.erase(spremnici.begin() + i);
                return s;
            }
        }
    }
    
    Spremnik& DajNajlaksi() const {
        if (spremnici.size() == 0)
            throw std::range_error("Skladiste je prazno\n");
            
        double najlaksi(spremnici[0]->DajTezinu());
        int p(0);
        
        for (int i = 1; i < spremnici.size(); i++) {
            if (spremnici[i] == nullptr)
                continue;
            if (spremnici[i] -> DajTezinu() < najlaksi) {
                najlaksi = spremnici[i] -> DajTezinu();
                p = i;
            }
        }
        return *spremnici[p].get();
    }
    
    Spremnik& DajNajtezi() const {
        if (spremnici.size() == 0) 
            throw std::range_error("Skladiste je prazno\n");
            
        double najtezi(spremnici[0]->DajTezinu());
        int p(0);
        
        for (int i = 1; i < spremnici.size(); i++ ) {
            if (spremnici[i] == nullptr)
                continue;
            
            if (spremnici[i] -> DajTezinu() > najtezi) {
                najtezi = spremnici[i]->DajTezinu();
                p = i;
            }
        }
        return *spremnici[p].get();
    }
    
    int BrojPreteskih(double tezina) const {
        int ukupno(0);
        
        for(int i=0; i < spremnici.size(); i++) {
            if (spremnici[i] -> DajUkupnuTezinu() > tezina) 
                ukupno++;
        }
        return ukupno;
    }
    
    int BrojPreteskih(const double &tezina) {
        int ukupno(0);
        for (int i = 0; i < spremnici.size(); i++) {
            if (spremnici[i] -> DajUkupnuTezinu() > tezina)
                ukupno++;
        }
        
        return ukupno;
    }
    
    void IzlistajSkladiste() {
        std::shared_ptr <Spremnik> pomocna (nullptr);
        for (int i = 0; i < spremnici.size() - 1; i++) {
            for (int j = i+1; j < spremnici.size(); j++) {
                if (spremnici[i] -> DajUkupnuTezinu() < spremnici[j]-> DajUkupnuTezinu()) {
                    pomocna = spremnici[i];
                    spremnici[i] = spremnici[j];
                    spremnici[j] = pomocna;
                }
            }
        }
        
        for (int i = 0; i < spremnici.size(); i++) {
            if (spremnici[i] != nullptr)
                spremnici[i]-> Ispisi();
            
        }
    }
    
    void UcitajIzDatoteke(const char datoteka[]) {
        std::ifstream ulaz(datoteka);
        char tip(0);
        
        if (!ulaz)
            throw std::logic_error("Trazena datoteka ne postoji");
            
        ulaz >> std::ws;
        
        while (ulaz >> tip) {
            bool jeLiB = tip == 'B';
            bool jeLiS = tip == 'S';
            bool jeLiV = tip == 'V';
            
            if (!jeLiB && !jeLiV && !jeLiS)
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
                
            char ime[30];
            
            if (jeLiB) {
                ulaz.getline(ime, 30);
                double zapremina(0);
                double tezina(0);
                double specTezina(0);
                
                ulaz >> tezina >> specTezina >> zapremina;
                
                if (!ulaz)
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                DodajBure(tezina, &ime[1], specTezina, zapremina);
            }
            
            else if (jeLiS) {
                ulaz.getline(ime,30);
                double tezina(0.0);
                double t(0.0);
                int b(0);
                std::vector<double> tezine;
                
                ulaz >> tezina >> b;
                
                if (!ulaz)
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                    
                    for (int i = 0; i < b; i++) {
                        ulaz >> t;
                        if (!ulaz)
                            throw std::logic_error("Datoteka sadrzi besmislene podatke");
                        tezine.push_back(t);
                    }
                    DodajSanduk(tezina, &ime[1], tezine);
            }
            
            else if (jeLiV) {
                ulaz.getline(ime, 30);
                double tezina(0.0);
                double tezinaP(0.0);
                ulaz >> tezina;
                if(!ulaz) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                ulaz >> tezinaP;
                DodajVrecu(tezina, &ime[1], tezinaP);
            }
            
            if(ulaz.bad()) 
                throw std::logic_error("Problemi pri citanju datoteke");
            
        }
        ulaz.close();
    }
};

int main() {
    try {
        
        Skladiste s;
        s.UcitajIzDatoteke("ROBA.TXT");
        s.IzlistajSkladiste();
        
      /*  Skladiste ETF;
        ETF.DodajSanduk(50,"Voce",{1,3,5,6});
        ETF.DodajVrecu(0.1, "Brasno", 25.5);
        ETF.DodajBure(5, "Krv", 1300,150);
        ETF.DodajSpremnik(new Vreca(0.5, "Secer",40), true);
        Bure *b = new Bure(15, "Voda", 1000, 200);
        ETF.DodajSpremnik(b,false);
        delete b;
        ETF.IzlistajSkladiste();*/
    }
    
    catch (std::logic_error l) {
        std::cout << l.what() << std::endl;
    }
    catch (std::range_error r) {
        std::cout << r.what() << std::endl;
    }
    
    return 0;
}
