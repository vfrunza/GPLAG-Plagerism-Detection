/B2017/2018: Zadaća 6, Zadatak 2
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




class PolimorfniSpremnik {
    std::shared_ptr<Spremnik> p;
  public:
    
    PolimorfniSpremnik() : p(nullptr) {}
    
    ~PolimorfniSpremnik() {}
    PolimorfniSpremnik(const Spremnik &s) {
        p=s.DajKopiju();
    }
    PolimorfniSpremnik(const PolimorfniSpremnik &p1) {
        if (!p1.p) p=nullptr;
        else p=p1.p->DajKopiju();
    }
    
    PolimorfniSpremnik(PolimorfniSpremnik &&p1) {
        p=p1.p; p1.p=nullptr;
    }
    
    PolimorfniSpremnik &operator = (const PolimorfniSpremnik &p1) {
        std::shared_ptr<Spremnik> s(nullptr);
        if (p1.p) s=p1.p->DajKopiju();
        p=nullptr;
        p=s;
        return *this;
    }
    
    PolimorfniSpremnik &operator =(PolimorfniSpremnik &&p1) {
        std::swap(p, p1.p);
        return *this;
    }
    
    double DajTezinu() const {
        if (p==nullptr) throw std::logic_error("Nespecificiran spremnik");
        return p->DajTezinu(); 
    }
    
    double DajUkupnuTezinu() const {
        if (p==nullptr) throw std::logic_error("Nespecificiran spremnik");
        return p->DajUkupnuTezinu();
    }
    
    void Ispisi() const {
        if (p==nullptr) throw std::logic_error("Nespecificiran spremnik");
        p->Ispisi();
    }
    
};


int main ()
{
    try {
        PolimorfniSpremnik s1(Bure(5,"sok", 930, 70));
        PolimorfniSpremnik s2, s3, s4; 
        s2=s3; 
        s2 = Sanduk(3, "voce", {0.5, 0.8, 0.6, 0.5});
        s3 = Vreca(0.4, "brasno", 30);
        s1=s1;
        s1=std::move(s1);
        std::cout << s1.DajTezinu() << std::endl;
        std::cout << s1.DajUkupnuTezinu() << std::endl;
        s1 = std::move(s2); 
        s1.Ispisi();
        
        
        try {
            s4.DajTezinu();
        }
        catch(std::logic_error &izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
        try {
            s4.DajUkupnuTezinu();
        }
        catch(std::logic_error &izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
        
        try {
            s4.Ispisi();
        }
        catch(std::logic_error &izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
    }
    catch(std::exception &iz) {
        std::cout << iz.what();
    }
	return 0;
}