/B2017/2018: Zadaća 6, Zadatak 2.
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

class PolimorfniSpremnik {
    std::shared_ptr<Spremnik> spremnik;
    public:
    PolimorfniSpremnik() : spremnik(nullptr) {}
    PolimorfniSpremnik(const Spremnik &spr) : spremnik(spr.DajKopiju()) {}
    PolimorfniSpremnik(const PolimorfniSpremnik &p_spr) {
        if(!p_spr.spremnik) spremnik = nullptr;
        else spremnik = p_spr.spremnik->DajKopiju();
    }
    PolimorfniSpremnik(PolimorfniSpremnik && p_spr) {
        spremnik = p_spr.spremnik; p_spr.spremnik = nullptr;
    }
    PolimorfniSpremnik& operator=(const PolimorfniSpremnik &p_spr) {
        if(p_spr.spremnik != nullptr) spremnik = p_spr.spremnik;
        return *this;
    }
    PolimorfniSpremnik& operator=(PolimorfniSpremnik &&p_spr) {
        spremnik = p_spr.spremnik;
        return *this;
    }
    double DajTezinu() const { if(!spremnik) throw std::logic_error("Nespecificiran spremnik"); return spremnik->DajTezinu(); }
    double DajUkupnuTezinu() const { if(!spremnik) throw std::logic_error("Nespecificiran spremnik"); return spremnik->DajUkupnuTezinu(); }
    void Ispisi() const { if(!spremnik) throw std::logic_error("Nespecificiran spremnik"); spremnik->Ispisi(); }
};



int main() {
   PolimorfniSpremnik s1(Bure(5,"Benzin", 930, 70)); // s1 je bure
    PolimorfniSpremnik s2, s3; // s2 i s3 su nespecificirani
    s2 = Sanduk(3, "Tepsije", {0.5, 0.8, 0.6, 0.5}); // s2 je sada sanduk
    s3 = Vreca(0.4, "Brasno", 30); // a s3 vreca
    std::cout << s1.DajTezinu() << std::endl;
    std::cout << s2.DajUkupnuTezinu() << std::endl;
    s3.Ispisi();
    s1 = s2; // sad je i s1 sanduk...
    s1.Ispisi();

    
    return 0;
}