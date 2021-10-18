/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <fstream>
#include <algorithm>

class Spremnik {
  protected:
    double tezina;
    std::string naziv;
  public:
    Spremnik(double tezina, std::string ime) : tezina(tezina), naziv(ime) {}
    virtual ~Spremnik() {} 
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0; 
    double DajTezinu() const { return tezina; }
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
};


class Sanduk : public Spremnik {
    std::vector<double> v;
  public:
    Sanduk (double t, std::string ime, std::vector<double> vek) : Spremnik(t, ime), v(vek) {}
    
    double DajUkupnuTezinu() const override {
        double n(0);
        for (double x: v) n+=x;
        return tezina+n;
    }
    
    std::shared_ptr<Spremnik> DajKopiju() const override {
		return std::make_shared<Sanduk>(*this);
	}
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Sanduk" << std::endl;
        std::cout << "Sadrzaj: " << naziv << std::endl;
        std::cout << "Tezine predmeta: ";
            for (double x: v) std::cout << x << " ";
        std::cout << "(kg)" << std::endl;
        std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
        std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    
};


class Vreca : public Spremnik {
    double tezina_materije;
  public:
    Vreca (double t, std::string ime, double tm) : Spremnik(t, ime), tezina_materije(tm) {}
    
    std::shared_ptr<Spremnik> DajKopiju() const override {
		return std::make_shared<Vreca>(*this);
	}
    double DajUkupnuTezinu() const override { return tezina+tezina_materije; }
    
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Vreca" << std::endl;
        std::cout << "Sadrzaj: " << naziv << std::endl;
        std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
        std::cout << "Tezina pohranjene materije: " << tezina_materije << " (kg)" << std::endl;
        std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    
    
};

class Bure : public Spremnik {
    double gustina;
    double zapremina;
  public:
    Bure(double t, std::string ime, double g, double z) : Spremnik(t, ime), gustina(g), zapremina(z) {}
    double DajUkupnuTezinu() const override { return tezina+gustina*zapremina*0.001; } 
    
    std::shared_ptr<Spremnik> DajKopiju() const override {
		return std::make_shared<Bure>(*this);
	}
	
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Bure" << std::endl;
        std::cout << "Sadrzaj: " << naziv << std::endl;
        std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
        std::cout << "Specificna tezina tecnosti: " << gustina << " (kg/m^3)" << std::endl;
        std::cout << "Zapremina tecnosti: " << zapremina << " (l)" << std::endl;
        std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
};


class Skladiste {
    std::vector<std::shared_ptr<Spremnik>> v;
  public:
    Skladiste() {}
    ~Skladiste() {}
    
    
    Skladiste(const Skladiste &s) {
        for (int i=0; i<s.v.size(); i++) {
            v.push_back(s.v.at(i)->DajKopiju());
        }
    }
    
    Skladiste(Skladiste &&s) {
        std::swap(v, s.v);
    }
    
    Skladiste &operator =(const Skladiste &s) {
        if (this!=&s) {
            v.resize(0);
            for (int i=0; i<s.v.size(); i++) {
                v.push_back(s.v.at(i)->DajKopiju());
            }
        }
        return *this;
    }
    
    Skladiste &operator =(Skladiste &&s) {
        if (this!=&s) {
            std::swap(v, s.v);
        }
        return *this;
    }
    
    
    Spremnik* DodajSanduk(double tezina, std::string ime, std::vector<double> vek) {
        std::shared_ptr<Spremnik> p;
        p=std::make_shared<Sanduk>(tezina, ime, vek);
        v.push_back(p);
        return p.get();
    }
    
    Spremnik* DodajVrecu(double tezina, std::string ime, double tm) {
        std::shared_ptr<Spremnik> p;
        p=std::make_shared<Vreca>(tezina, ime, tm);
        v.push_back(p);
        return p.get();
    }
    
    Spremnik* DodajBure(double tezina, std::string ime, double g, double z) {
        std::shared_ptr<Spremnik> p;
        p=std::make_shared<Bure>(tezina, ime, g, z);
        v.push_back(p);
        return p.get();
    }
    
    Spremnik* DodajSpremnik (Spremnik* p1, bool predaje) {
        std::shared_ptr<Spremnik> p;
        if (!predaje) {
            p=p1->DajKopiju();
            v.push_back(p);
        }
        else {
            v.push_back(static_cast<std::shared_ptr<Spremnik>>(p1));
            return p1;
        }
        return p.get();
    }
    
    void BrisiSpremnik (Spremnik* p) {
        for (auto it=v.begin(); it!=v.end(); it++) {
            if ((*it).get()==p) { v.erase(it); return; }
        }
        return;
    }
    
    Spremnik &DajNajlaksi() {
        if (!v.size()) throw std::range_error("Skladiste je prazno");
        return **min_element(v.begin(), v.end(), [](std::shared_ptr<Spremnik> p1, std::shared_ptr<Spremnik> p2) { return (*p1).DajTezinu()<(*p2).DajTezinu(); } );
    }
    
    Spremnik &DajNajtezi() {
        if (!v.size()) throw std::range_error("Skladiste je prazno");
        return **max_element(v.begin(), v.end(), [](std::shared_ptr<Spremnik> p1, std::shared_ptr<Spremnik> p2) { return (*p1).DajTezinu()<(*p2).DajTezinu(); } );
    }
    
    int BrojPreteskih (int x) const {
        return std::count_if(v.begin(), v.end(), [x](std::shared_ptr<Spremnik> p1) { return (*p1).DajUkupnuTezinu()>x;  } );
    }
    
    void IzlistajSkladiste() const {
        if (v.size()==0) return;
        
        std::vector<std::shared_ptr<Spremnik>> pomocni;
        
        pomocni.resize(v.size());
        
        for (int i=0; i<v.size(); i++) pomocni.at(i)=v.at(i);
        
        std::sort(pomocni.begin(), pomocni.end(), [](std::shared_ptr<Spremnik> p1, std::shared_ptr<Spremnik> p2) { return (*p1).DajUkupnuTezinu()>(*p2).DajUkupnuTezinu(); } );
        
        std::for_each(pomocni.begin(), pomocni.end(), [] (std::shared_ptr<Spremnik> p1) { (*p1).Ispisi(); });
        
        for (int i=0; i<pomocni.size(); i++) pomocni.at(i)=nullptr;
        pomocni.resize(0);
    }
    
    void UcitajIzDatoteke (std::string ime) {
        
        v.resize(0);
        
        std::ifstream ulazni(ime);
        if (!ulazni) throw std::logic_error("Trazena datoteka ne postoji");
        
        char slovo, znak;
        while (ulazni >> slovo) {
            
            if (slovo=='S') {
                znak=ulazni.get();
                if (znak!=' ') throw std::logic_error("Datoteka sadrzi besmislene podatke");
                
                char ime[100];
                ulazni.getline(ime, sizeof ime);
                
                double t;
                int br_predmeta;
                std::vector<double> vek;
                
                ulazni >> t >> br_predmeta;
                if (!ulazni) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                
                double broj;
                
                for (int i=0; i<br_predmeta; i++) {
                    ulazni >> broj;
                    if (!ulazni) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                    vek.push_back(broj);
                }
                
                
                DodajSanduk(t, ime, vek);
            }
            else if (slovo=='B') {
                znak=ulazni.get();
                if (znak!=' ') throw std::logic_error("Datoteka sadrzi besmislene podatke");
                
                char ime[100];
                ulazni.getline(ime, sizeof ime);
                
                double broj1, broj2, broj3;
                ulazni >> broj1 >> broj2 >> broj3;
                if (!ulazni) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                
                
                DodajBure(broj1, ime, broj2, broj3);
            }
            else if (slovo=='V') {
                znak=ulazni.get();
                if (znak!=' ') throw std::logic_error("Datoteka sadrzi besmislene podatke");
                
                std::string s;
                std::getline(ulazni, s);
                
                double broj1, broj2;
                ulazni >> broj1 >> broj2;
                if (!ulazni) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                
                DodajVrecu(broj1, s, broj2);
            }
            else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
            
        if (ulazni.bad()) throw std::logic_error("Problemi pri citanju datoteke");
    }
};


int main () {
    
    try {
        Skladiste s;
        s.UcitajIzDatoteke("ROBA.TXT");
        s.IzlistajSkladiste();
    }
    catch(std::exception &re) {
        std::cout << re.what();
    }
    
    
    
	return 0;
}
