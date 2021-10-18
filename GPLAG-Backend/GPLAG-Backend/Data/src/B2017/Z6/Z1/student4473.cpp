#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm> 
#include <stdexcept>
#include <fstream> 
class Spremnik {
    std::string naziv;
    double tezina;
public:
    
    Spremnik(double _tezina, std::string _naziv) {
        tezina = _tezina;
        naziv = _naziv;
    }
    
    double DajTezinu() const { return tezina; }
    std::string DajNaziv() const { return naziv; }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;
};

class Sanduk : public Spremnik {
    std::vector<double> tezinaPredmeta;
public: 
    Sanduk(double _tezina, std::string _naziv, std::vector<double> _tezinaPredmeta) : Spremnik(_tezina, _naziv) {
        tezinaPredmeta = _tezinaPredmeta;
    }
    double DajUkupnuTezinu() const override {
        double suma = 0;
        for (auto x : tezinaPredmeta) suma += x;
        return suma + Spremnik::DajTezinu();
    }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Sanduk\nSadrzaj: " << Spremnik::DajNaziv() <<"\nTezine predmeta: ";
        for (auto x : tezinaPredmeta) std::cout << x << " "; 
        std::cout << "(kg)\n";
        std::cout << "Vlastita tezina: " << Spremnik::DajTezinu() << " (kg)\nUkupna tezina: " << DajUkupnuTezinu() << " (kg)\n"; 
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Sanduk> (*this);
    }
};

class Vreca : public Spremnik {
    double tezinaPredmeta;
public: 
    Vreca(double _tezina, std::string _naziv, double _tezinaPredmeta) : Spremnik(_tezina, _naziv) {
        tezinaPredmeta = _tezinaPredmeta;
    }
    double DajUkupnuTezinu() const override {
        return tezinaPredmeta + Spremnik::DajTezinu();
    }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Vreca\nSadrzaj: " << Spremnik::DajNaziv() <<"\n";
        std::cout << "Vlastita tezina: " << Spremnik::DajTezinu() << " (kg)\nTezina pohranjene materije: " << tezinaPredmeta << " (kg)\nUkupna tezina: " << DajUkupnuTezinu() << " (kg)\n"; 
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Vreca> (*this);
    }
};

class Bure : public Spremnik {
    double gustinaTecnosti;
    double zapreminaTecnosti;
public: 
    Bure(double _tezina, std::string _naziv, double _gustinaTecnosti, double _zapreminaTecnosti) : Spremnik(_tezina, _naziv) {
        gustinaTecnosti = _gustinaTecnosti;
        zapreminaTecnosti = _zapreminaTecnosti;
    }
    double DajUkupnuTezinu() const override {
        return gustinaTecnosti / 1000. * zapreminaTecnosti + Spremnik::DajTezinu();
    }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Bure\nSadrzaj: " << Spremnik::DajNaziv() <<"\n";
        std::cout << "Vlastita tezina: " << Spremnik::DajTezinu() << " (kg)\nSpecificna tezina tecnosti: " << gustinaTecnosti << " (kg/m^3)\n";
        std::cout << "Zapremina tecnosti: " << zapreminaTecnosti << " (l)\nUkupna tezina: " << DajUkupnuTezinu() << " (kg)\n"; 
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Bure> (*this);
    }
};

class Skladiste {
    std::vector<std::shared_ptr<Spremnik> > vect;
public: 
    Skladiste(const Skladiste &a) {
        vect.clear();
        for (int i = 0; i < a.vect.size(); i++)
            vect.push_back(a.vect[i] -> DajKopiju());
    }
    Skladiste(Skladiste &&a) {
        vect = a.vect;
        for (int i = 0; i < a.vect.size(); i++) a.vect[i] = 0;
        a.vect.clear();
    }
    Skladiste() {};
    Skladiste &operator = (Skladiste a) {
        std::swap(vect, a.vect);
        return *this;
    }
    Skladiste &operator = (Skladiste &&a) {
        std::swap(vect, a.vect);
        return *this;
    }
    
    Spremnik *DodajSanduk(double _tezina, std::string _naziv, std::vector<double> _tezinaPredmeta) {
        std::shared_ptr<Spremnik> A = std::make_shared<Sanduk> (Sanduk(_tezina, _naziv, _tezinaPredmeta));
        vect.push_back(A);
        return A.get();
    }
    Spremnik *DodajVrecu(double _tezina, std::string _naziv, double _tezinaPredmeta) {
        std::shared_ptr<Spremnik> A = std::make_shared<Vreca> (Vreca(_tezina, _naziv, _tezinaPredmeta));
        vect.push_back(A);
        return A.get();
    }
    Spremnik *DodajBure(double _tezina, std::string _naziv, double _gustina, double _zapremina) {
        std::shared_ptr<Spremnik> A = std::make_shared<Bure> (Bure(_tezina, _naziv, _gustina, _zapremina));
        vect.push_back(A);
        return A.get();
    }
    Spremnik *DodajSpremnik(Spremnik *a, bool value) {
        if (value) 
            vect.push_back(std::shared_ptr<Spremnik> (a));
        else {
            std::shared_ptr<Spremnik> y = a -> DajKopiju();
            vect.push_back(y);
        }
        return vect[vect.size() - 1].get();
    }
    Spremnik &DajNajlaksi() const {
        if (vect.size() == 0) throw std::range_error("Skladiste je prazno");
        int idx = 0;
        for (int i = 0; i < vect.size(); i++)
            if (vect[i] -> Spremnik::DajTezinu() < vect[idx] -> Spremnik::DajTezinu()) idx = i;
        return (*vect[idx]);
    }
    Spremnik &DajNajtezi() const {
        if (vect.size() == 0) throw std::range_error("Skladiste je prazno");
        int idx = 0;
        for (int i = 0; i < vect.size(); i++)
            if (vect[i] -> Spremnik::DajTezinu() > vect[idx] -> Spremnik::DajTezinu()) idx = i;
        return (*vect[idx]);
    }
    int BrojPreteskih(double tezina) const {
        int ret = 0;
        for (int i = 0; i < vect.size(); i++)
            if (vect[i] -> DajUkupnuTezinu() > tezina) ret++;
        return ret;
    }
    void BrisiSpremnik(Spremnik *spremnik) {
        for (int i = 0; i < vect.size(); i++)
            if (spremnik == vect[i].get()) {
                vect[i] = nullptr;
                vect.erase(vect.begin() + i);
                break;
            }
    }
    void IzlistajSkladiste() const {
        auto kopija = vect;
        std::sort(kopija.begin(), kopija.end(), [](std::shared_ptr<Spremnik> A, std::shared_ptr<Spremnik> B) {
            return A -> DajUkupnuTezinu() > B -> DajUkupnuTezinu();
        });
        for (int i = 0; i < kopija.size(); i++)
            kopija[i] -> Ispisi();
    }
    void UcitajIzDatoteke(std::string ime) {
        vect.clear();
        std::ifstream in(ime);
        if (!in) throw std::logic_error("Trazena datoteka ne postoji");
    }
};
int main() {
    
	return 0;
}
