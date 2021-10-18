/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <algorithm>


class Spremnik {
    protected:
    double tezina;
    std::string ime;
    public:
    Spremnik(double tez, std::string naziv) {
        ime=naziv;
        tezina=tez;
    }
    virtual ~Spremnik() {}
    double DajTezinu() const { return tezina;}
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const=0;
};



class Sanduk: public Spremnik {
    std::vector<double> sanduk;
    public:
    Sanduk(double tez, std::string naziv, std::vector<double> v): Spremnik(tez,naziv) {
        sanduk=v;
    }
    ~Sanduk() {}
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Sanduk>(*this);
    }
    double DajUkupnuTezinu() const override {
        double s=0;
        for (int i=0; i<sanduk.size(); i++) {
            s+=sanduk[i];
        }
        return s+tezina;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        std::cout<<"Sadrzaj: "<<ime<<std::endl;
        std::cout<<"Tezine predmeta: ";
        for (int i=0; i<sanduk.size(); i++) {
            std::cout<<sanduk[i]<<" ";
            if (i==sanduk.size()-1) std::cout<<"(kg)"<<std::endl;
        }
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};  


class Vreca: public Spremnik {
    double vreca;
    public:
    Vreca(double tez, std::string naziv, double v): Spremnik(tez,naziv) {
        vreca=v;
    }
    ~Vreca() {}
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Vreca>(*this);
    }
    double DajUkupnuTezinu() const override { return vreca+tezina;}
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
        std::cout<<"Sadrzaj: "<<ime<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Tezina pohranjene materije: "<<vreca<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
}; 

class Bure: public Spremnik {
    double ro, v;
    public:
    Bure(double tez, std::string naziv, double gustina, double zapremina): Spremnik(tez,naziv) {
        ro=gustina;
        v=zapremina;
    }
    ~Bure() {}
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Bure>(*this);
    }
    double DajUkupnuTezinu() const override {
        return tezina+ro*v*0.001; 
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl;
        std::cout<<"Sadrzaj: "<<ime<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Specificna tezina tecnosti: "<<ro<<" (kg/m^3)"<<std::endl;
        std::cout<<"Zapremina tecnosti: "<<v<<" (l)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
}; 

class Skladiste {
    std::vector<std::shared_ptr<Spremnik>> skladiste;
    public: 
    Skladiste() {}
    Skladiste(Skladiste &&s) {
        skladiste=s.skladiste;
        s.skladiste.resize(0);
    }
    Skladiste(const Skladiste &s) {
        skladiste.resize(s.skladiste.size());
        for (int i=0; i<s.skladiste.size(); i++) {
            std::shared_ptr<Spremnik>pok(s.skladiste[i]->DajKopiju());
            skladiste[i]=pok;
        }
    }
    ~Skladiste() {}
    Skladiste &operator =(const Skladiste &s) {
        if (&s!=this) {
            skladiste.resize(s.skladiste.size());
            for (int i=0; i<s.skladiste.size(); i++) {
            std::shared_ptr<Spremnik>pok(s.skladiste[i]->DajKopiju());
            skladiste[i]=pok;
            }
        }
        return *this;
    }
    Skladiste &operator =(Skladiste &&s) {
        if (&s!=this) {
            skladiste=s.skladiste;
            s.skladiste.resize(0);
        }
        return *this;
    }
    Spremnik &DajNajlaksi() { 
        if (skladiste.size()==0) throw std::range_error("Skladiste je prazno");
        int trazeni(0);
        double najlaksi(skladiste[0]->DajTezinu());
        for (int i=1; i<skladiste.size(); i++) {
            if (skladiste[i]->DajTezinu()<najlaksi) {
                najlaksi=skladiste[i]->DajTezinu();
                trazeni=i;
            }
        }
        return *skladiste[trazeni];
    }
    
    Spremnik &DajNajtezi() { 
        if (skladiste.size()==0) throw std::range_error("Skladiste je prazno");
        int trazeni(0);
        double najtezi(skladiste[0]->DajTezinu());
        for (int i=1; i<skladiste.size(); i++) {
            if (skladiste[i]->DajTezinu()>najtezi) {
                najtezi=skladiste[i]->DajTezinu();
                trazeni=i;
            }
        }
        return *skladiste[trazeni];
    }
    
    int BrojPreteskih (double teski) {
        int broj_preteskih(0);
        for (int i=0; i<skladiste.size(); i++) {
            if (skladiste[i]->DajUkupnuTezinu()>teski) broj_preteskih++;
        }
        return broj_preteskih;
    }
    
    int BrojPreteskih (double teski) const {
        int broj_preteskih(0);
        for (int i=0; i<skladiste.size(); i++) {
            if (skladiste[i]->DajUkupnuTezinu()>teski) broj_preteskih++;
        }
        return broj_preteskih;
    }
    
    void IzlistajSkladiste() {
        sort(skladiste.begin(), skladiste.end(), [](std::shared_ptr<Spremnik> p1, std::shared_ptr<Spremnik> p2) {
            return (p1->DajUkupnuTezinu() > p2->DajUkupnuTezinu());
        });
        for (auto p:skladiste) p->Ispisi();
    }
    
    void IzlistajSkladiste() const {
        std::vector<std::shared_ptr<Spremnik>> novo_skladiste;
        novo_skladiste.resize(skladiste.size());
        for (int i=0; i<skladiste.size(); i++) {
            novo_skladiste[i]=skladiste[i];
        }
        sort(novo_skladiste.begin(), novo_skladiste.end(), [](std::shared_ptr<Spremnik> p1, std::shared_ptr<Spremnik> p2) {
            return (p1->DajUkupnuTezinu() > p2->DajUkupnuTezinu());
        });
        for (auto p:novo_skladiste) p->Ispisi();
    }
    
    void BrisiSpremnik (Spremnik *spremnik) {
        for (int i=0; i<skladiste.size(); i++) {
            if (skladiste[i].get()==spremnik) {
                for (int j=i; j<skladiste.size()-1; j++) {
                    skladiste[j]=skladiste[j+1];
                }
                skladiste.resize(skladiste.size()-1);
            }
        }
    }
    
    Spremnik *DodajSanduk(double tez, std::string naziv, std::vector<double> s) {
        auto p=std::make_shared<Sanduk>(tez, naziv, s);
        skladiste.push_back(p);
        return skladiste[skladiste.size()-1].get();
    } 
    Spremnik *DodajVrecu(double tez, std::string naziv, double s) {
        auto p=std::make_shared<Vreca>(tez, naziv, s);
        skladiste.push_back(p);
        return skladiste[skladiste.size()-1].get();
    }
    Spremnik *DodajBure(double tez, std::string naziv, double g, double v) {
        auto p=std::make_shared<Bure>(tez, naziv, g, v);
        skladiste.push_back(p);
        return skladiste[skladiste.size()-1].get();
    }
    
    Spremnik *DodajSpremnik(Spremnik *s, bool jeste) {
        if (jeste) {
            skladiste.push_back(std::shared_ptr<Spremnik>(s));
        }
        else {
            auto p=s->DajKopiju();
            skladiste.push_back(p);
        }
        return skladiste[skladiste.size()-1].get();
    } 
    void UcitajIzDatoteke (std::string &ime) {
        std::ifstream input(ime);
        if (!input) throw std::logic_error("Trazena datoteka ne postoji");
    }
}; 



int main ()
{
    Skladiste s;
    try {
        s.IzlistajSkladiste();
    }
    catch (std::range_error a) {
        std::cout<<a.what();
    }
	return 0;
}







 