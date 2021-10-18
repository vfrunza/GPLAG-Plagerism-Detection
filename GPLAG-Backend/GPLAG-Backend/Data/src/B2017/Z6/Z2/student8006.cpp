#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <fstream>

class Spremnik {
    double vl_tezina;
    std::string naziv;
public:
    Spremnik(double m, std::string n) : vl_tezina(m), naziv(n) {}
    virtual ~Spremnik() {}
    double DajTezinu() const { return vl_tezina; }
    std::string DajNaziv() const { return naziv; }
    virtual void Ispisi() const { std::cout << std::endl; }
    virtual double DajUkupnuTezinu() const { return 0; }
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0; 
};

typedef std::shared_ptr<Spremnik> PS;

class Sanduk : public Spremnik {
    std::vector<double> tezine;
public:
    Sanduk(double m, std::string n, std::vector<double> vm) : Spremnik(m,n),
        tezine(vm) {}
    double DajUkupnuTezinu() const {
        double s(0);
        for (int i = 0; i < tezine.size(); i++) s += tezine[i];
        return s + DajTezinu();
    }
    void Ispisi() const {
        std::cout << "Vrsta spremnika: Sanduk" << std::endl
                  << "Sadrzaj: " << DajNaziv() << std::endl
                  << "Tezine predmeta: ";
        for (int i = 0; i < tezine.size(); i++) std::cout << tezine[i] << " ";
        std::cout << "(kg)" << std::endl
                  << "Vlastita tezina: " << DajTezinu()<< " (kg)" << std::endl
                  << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    PS DajKopiju() const { return std::make_shared<Sanduk>(*this); }
};

class Vreca : public Spremnik {
    double tezina;
public:
    Vreca(double vm, std::string n, double m) : Spremnik(vm,n), tezina(m) {}
    double DajUkupnuTezinu() const { return tezina + DajTezinu(); }
    void Ispisi() const {
        std::cout << "Vrsta spremnika: Vreca" << std::endl
                  << "Sadrzaj: " << DajNaziv() << std::endl
                  << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl
                  << "Tezina pohranjene materije: " << tezina << " (kg)" << std::endl
                  << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    PS DajKopiju() const { return std::make_shared<Vreca>(*this); }
};

class Bure : public Spremnik {
    double q, v;
public :
    Bure(double m, std::string n, double q, double v) : Spremnik(m,n), q(q), v(v) {}
    double DajUkupnuTezinu() const { return q*v/1000 + DajTezinu(); } 
    void Ispisi() const {
        std::cout << "Vrsta spremnika: Bure" << std::endl
                  << "Sadrzaj: " << DajNaziv() << std::endl
                  << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl
                  << "Specificna tezina tecnosti: " << q << " (kg/m^3)" << std::endl
                  << "Zapremina tecnosti: " << v << " (l)" << std::endl
                  << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    PS DajKopiju() const { return std::make_shared<Bure>(*this); }
};

class Skladiste {
    std::vector<PS> spremnik;
public:
    Skladiste() = default;
    Skladiste(const Skladiste &s) {
        try {
            for (int i = 0; i < s.spremnik.size(); i++)
                spremnik.push_back(s.spremnik[i]->DajKopiju());
        }
        catch(...) { 
            for (int i = 0; i < spremnik.size(); i++) spremnik[i] = nullptr;
            spremnik.resize(0); throw;
        }
    }
    Skladiste(Skladiste &&s) : spremnik(s.spremnik) {
        s.spremnik.resize(0);
    }
    Skladiste &operator = (const Skladiste &s) {
        std::vector<PS> pomocni;
        for (int i = 0; i < s.spremnik.size(); i++)
            pomocni.push_back(s.spremnik[i]->DajKopiju());
        spremnik = pomocni;
        return *this;
    }
    Skladiste &operator = (Skladiste &&s) {
        std::swap(spremnik, s.spremnik);
        s.spremnik.resize(0);
        return *this;
    }
    Spremnik *DodajSanduk(double m, std::string n, std::vector<double> vm) {
        spremnik.push_back(Sanduk(m,n,vm).DajKopiju());
        return spremnik[spremnik.size()-1].get();
    }
    Spremnik *DodajVrecu(double vm, std::string n, double m) {
        spremnik.push_back(Vreca(vm,n,m).DajKopiju());
        return spremnik[spremnik.size()-1].get();
    }
    Spremnik *DodajBure(double m, std::string n, double q, double v) {
        spremnik.push_back(Bure(m,n,q,v).DajKopiju());
        return spremnik[spremnik.size()-1].get();
    }
    void BrisiSpremnik(Spremnik *s) {
        auto it(spremnik.begin());
        for (; it != spremnik.end(); it++)
            if (it->get() == s) break;
        if (it != spremnik.end()) spremnik.erase(it);
    }
    Spremnik *DodajSpremnik(Spremnik *s, bool vlasnistvo) {
        if (vlasnistvo) {
            std::shared_ptr<Spremnik> p(s);
            spremnik.push_back(p);
        }
        else spremnik.push_back(s->DajKopiju());
        return spremnik[spremnik.size()-1].get();
    }
    Spremnik &DajNajlaksi() {
        if (!spremnik.size()) throw std::range_error("Skladiste je prazno");
        return **(std::min_element(spremnik.begin(), spremnik.end(), [](PS a, PS b) {
            return a->DajTezinu() < b->DajTezinu();
        }));
    }
    Spremnik &DajNajtezi() {
        if (!spremnik.size()) throw std::range_error("Skladiste je prazno");
        return **(std::max_element(spremnik.begin(), spremnik.end(), [](PS a, PS b) {
            return a->DajTezinu() < b->DajTezinu();
        }));
    }
    int BrojPreteskih(int m) const {
        int n(0);
        for (int i = 0; i < spremnik.size(); i++)
            if (spremnik[i]->DajUkupnuTezinu() > m) n++;
        return n;
    }
    void IzlistajSkladiste() const {
        auto v(spremnik);
        std::sort(v.begin(), v.end(), [](PS a, PS b) {
            return a->DajUkupnuTezinu() > b->DajUkupnuTezinu();
        });
        for (auto p : v) p->Ispisi();
    }
    void UcitajIzDatoteke(const char ime[]);
};

class PolimorfniSpremnik {
    PS spremnik;
    void Test() const { if (!spremnik) throw std::logic_error("Nespecificiran spremnik"); }
public:
    PolimorfniSpremnik() = default;
    PolimorfniSpremnik(const PolimorfniSpremnik &ps) : spremnik(ps.spremnik->DajKopiju()) {}
    PolimorfniSpremnik(const Spremnik &s) : spremnik(s.DajKopiju()) {}
    PolimorfniSpremnik &operator = (const PolimorfniSpremnik &ps) {
        spremnik = ps.spremnik->DajKopiju(); return *this;
    }
    PolimorfniSpremnik &operator = (PolimorfniSpremnik &&ps) {
        std::swap(spremnik, ps.spremnik); return *this;
    }
    PolimorfniSpremnik &operator = (const Spremnik &s) {
        spremnik = s.DajKopiju(); return *this;
    }
    double DajTezinu() const { Test(); return spremnik->DajTezinu(); }
    double DajUkupnuTezinu() const { Test(); return spremnik->DajUkupnuTezinu(); }
    std::string DajNaziv() const { Test(); return spremnik->DajNaziv(); }
    void Ispisi() const { Test(); spremnik->Ispisi(); }
    
};

void Skladiste::UcitajIzDatoteke(const char ime[]) {
    std::ifstream dat(ime);
    if (!dat) throw std::logic_error("Trazena datoteka ne postoji");
    char tip; std::string naziv;
    std::vector<PS> novi;
    while (dat >> tip) {
        if (dat.get() != ' ') throw std::logic_error("Datoteka sadrzi besmislene podatke");
        std::getline(dat, naziv);
        if (tip == 'S') {
            double x, z; int y; std::vector<double> v;
            if (!(dat >> x >> y)) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            while (dat.peek() != '\n' && dat.peek() != EOF && dat >> z) v.push_back(z);
            if ((!dat && !dat.eof()) || v.size() != y) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            novi.push_back(Sanduk(x, naziv, v).DajKopiju());
        }
        else if (tip == 'V') {
            double x, y;
            if (!(dat >> x >> y) || (dat.peek() != '\n' && !dat.eof()))
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            novi.push_back(Vreca(x,naziv,y).DajKopiju());
        }
        else if(tip == 'B') {
            double x, y, z;
            if (!(dat >> x >> y >> z) || (dat.peek() != '\n' && !dat.eof()))
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            novi.push_back(Bure(x,naziv,y,z).DajKopiju());
        }
        else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        dat.ignore(1000, '\n');
    }
    if (!dat.eof()) throw std::logic_error("Problemi pri citanju datoteke");
    spremnik = novi;
}

int main ()
{
    Skladiste s;
    s.DodajBure(22,"Nema sta nema", 4,5);
    PolimorfniSpremnik p(Sanduk(12,"Sve i svasta", {3,5,7}));
    Bure b(21, "Pa da", 7,9);
    PolimorfniSpremnik p1;
 //   p1.DajTezinu();
    p1 = std::move(b);
    p1.Ispisi();
    //Skladiste s1(s);
	return 0;
}
