/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class Spremnik {
protected:
    double tezina;
    std::string naziv_sadrzaja;
public:
    Spremnik(double tezina, std::string naziv) : tezina(tezina), naziv_sadrzaja(naziv) {}
    virtual ~Spremnik() {}
    virtual double DajTezinu() const = 0;
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const =  0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;
};

class Sanduk : public Spremnik {
    std::vector<double> tezina_predmeta;
public:
    Sanduk(double tezina, std::string naziv_predmeta, std::vector<double> vektor_tezina) : Spremnik(tezina, naziv_predmeta), tezina_predmeta(vektor_tezina){}
    double DajTezinu() const override {
        return tezina;
    }
    double DajUkupnuTezinu() const override {
        double suma(0);
        for(int i = 0; i < tezina_predmeta.size(); i++)
            suma +=  tezina_predmeta.at(i);
        return tezina + suma;
    }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Sanduk" << std::endl << "Sadrzaj: " 
            << naziv_sadrzaja << std::endl << "Tezine predmeta: ";
        for(double i: tezina_predmeta) std::cout << i << " ";
        std::cout << "(kg)" << std::endl << "Vlastita tezina: " << DajTezinu() << " (kg)" 
            << std::endl << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Sanduk>(*this);
    }
};

class Vreca : public Spremnik {
    double tezina_materije;
public:
    Vreca(double tezina, std::string naziv_materije, double tezina_materije) : Spremnik(tezina, naziv_materije), tezina_materije(tezina_materije) {}
    double DajTezinu() const override {
        return tezina;
    }
    double DajUkupnuTezinu() const override {
        return tezina + tezina_materije;
    }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Vreca" << std::endl << "Sadrzaj: "
            << naziv_sadrzaja << std::endl << "Vlastita tezina: " << DajTezinu() << " (kg)"
            << std::endl << "Tezina pohranjene materije: " << tezina_materije << " (kg)" 
            << std::endl << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Vreca>(*this);
    }

};

class Bure : public Spremnik {
    double gustina_tecnosti, zapremina;
public:
    Bure(double tezina, std::string naziv_tecnosti, double gustina, double zapremina) : Spremnik(tezina, naziv_tecnosti), gustina_tecnosti(gustina), zapremina(zapremina) {}
    double DajTezinu() const override {
        return tezina;
    }
    double DajUkupnuTezinu() const override {
        return (zapremina / 1000 * gustina_tecnosti) + tezina;
    }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Bure" << std::endl << "Sadrzaj: " << naziv_sadrzaja
        << std::endl << "Vlastita tezina: " << DajTezinu() << " (kg)"
        << std::endl << "Specificna tezina tecnosti: " << gustina_tecnosti << " (kg/m^3)"
        << std::endl << "Zapremina tecnosti: " << zapremina << " (l)"
        << std::endl << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Bure>(*this);
    }
};

class Skladiste {
    std::vector<std::shared_ptr<Spremnik>> roba;
public:
    explicit Skladiste() {}
    Skladiste(const Skladiste &s);
    Skladiste(Skladiste &&s);
    Skladiste &operator =(Skladiste s);
    Skladiste &operator =(Skladiste &&s);
    Spremnik DodajSpremnik(Spremnik *s, bool lv) {
        if(lv) {
            roba.push_back(s->DajKopiju());
        }
        return *roba.at(roba.size()-1);
    }
    
};
Skladiste::Skladiste(const Skladiste &s) {
    roba.resize(0);
    for(int i = 0; i < s.roba.size(); i++) {
        roba.push_back(s.roba.at(i)->DajKopiju());
    }
}
Skladiste::Skladiste(Skladiste &&s) {
    std::swap(roba, s.roba);
    s.roba.resize(0);
}
Skladiste &Skladiste::operator =(Skladiste s) {
    std::swap(roba, s.roba);
    return *this;
}
Skladiste &Skladiste::operator =(Skladiste &&s) {
    std::swap(roba, s.roba);
    return *this;
}

int main ()
{
    std::vector<double> v{2,3,1,2,2,4,3,1,3};
    Sanduk s(10, "Trofazni kataklingeri za auspuhe", v);
    s.Ispisi();
    std::cout << std::endl;
    Vreca v1(0.2, "Praskaste cincozne za glajfanje", 5);
    v1.Ispisi();
    std::cout << std::endl;
    Bure b(5, "Rafinirana kalamuta iz Katange", 1300, 150);
    b.Ispisi();
	return 0;
}
