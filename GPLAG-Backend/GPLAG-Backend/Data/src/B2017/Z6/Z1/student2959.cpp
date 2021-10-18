/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <memory>
#include <stdexcept>

class Spremnik
{
protected:
    std::string naziv;
    double vlastita_tezina;
public:
    Spremnik(double tezina, std::string ime): vlastita_tezina(tezina), naziv(ime) {};
    virtual ~Spremnik() {}
    virtual void Ispisi() const=0;
    double DajTezinu() const {
        return vlastita_tezina;
    }
    virtual double DajUkupnuTezinu() const=0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const =0;
};

class Sanduk: public Spremnik
{
    std::vector<double> tezine_predmeta;
public:
    Sanduk(double tezina, std::string ime, std::vector<double> v): Spremnik(tezina,ime),tezine_predmeta(v) {}
    double DajUkupnuTezinu() const override {
        double suma(vlastita_tezina);
        for(auto x:tezine_predmeta) suma+=x;
        return suma;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl<<
                 "Tezine predmeta: ";
        for(auto x:tezine_predmeta) std::cout<<x<<" ";
        std::cout<<"(kg)"<<std::endl<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl<<
                 "Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Sanduk>(*this);
    }
};

class Vreca: public Spremnik
{
    double tezina_praska;
public:
    Vreca(double tezina, std::string ime, double tezina_materije): Spremnik(tezina,ime), tezina_praska(tezina_materije) {};
    double DajUkupnuTezinu() const override {
        return vlastita_tezina+tezina_praska;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl<<"Sadrzaj: "<<naziv<<
                 std::endl<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<
                 std::endl<<"Tezina pohranjene materije: "<<DajUkupnuTezinu()-DajTezinu()<<" (kg)"<<
                 std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Vreca>(*this);
    }
};

class Bure: public Spremnik
{
    double gustina, zapremina;
public:
    Bure(double tezina, std::string ime, double sp_tezina, double V): Spremnik(tezina,ime), gustina(sp_tezina), zapremina(V) {}
    double DajUkupnuTezinu() const override {
        return vlastita_tezina+gustina*zapremina/1000;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl<<"Sadrzaj: "<<naziv<<
                 std::endl<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<
                 std::endl<<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<
                 std::endl<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<
                 std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Bure>(*this);
    }
};

class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> predmeti;   
public:
    Skladiste()=default;
    ~Skladiste()=default;
    Skladiste(const Skladiste &s) {
        predmeti.resize(s.predmeti.size(), nullptr);
        for(int i=0; i<s.predmeti.size(); i++) {
            predmeti[i]=s.predmeti[i]->DajKopiju();
        }
    }
    Skladiste(Skladiste &&s)=default;
    Skladiste &operator=(Skladiste &&s)=default;
    Skladiste &operator=(const Skladiste &s) {
        predmeti.resize(s.predmeti.size());
        for(int i=0; i<predmeti.size(); i++) {
            predmeti[i]=s.predmeti[i]->DajKopiju();

        }
        return *this;
    }
    Spremnik* DodajSanduk(double tezina, std::string ime, std::vector<double> v) {
        predmeti.push_back(std::shared_ptr<Sanduk>(new Sanduk(tezina,ime,v)));
        return predmeti[predmeti.size()-1].get();
    }
    Spremnik* DodajVrecu(double tezina, std::string ime, double tezina_materije) {
        predmeti.push_back(std::shared_ptr<Vreca>(new Vreca(tezina,ime,tezina_materije)));
        return predmeti[predmeti.size()-1].get();
    }
    Spremnik* DodajBure(double tezina, std::string ime, double sp_tezina, double V) {
        predmeti.push_back(std::shared_ptr<Bure>(new Bure(tezina,ime,sp_tezina,V)));
        return predmeti[predmeti.size()-1].get();
    }
    Spremnik* DodajSpremnik(Spremnik *s, bool vlasnistvo) {
        if(vlasnistvo) {
            predmeti.push_back(std::shared_ptr<Spremnik>(s));
            return s;
        } else {
            predmeti.push_back(s->DajKopiju());
            return predmeti[predmeti.size()-1].get();
        }
    }
    void BrisiSpremnik(Spremnik *s) {
        for(int i=0; i<predmeti.size(); i++) {
            if(predmeti[i].get()==s) {
                predmeti.erase(predmeti.begin()+i);
            }
        }
    }
    Spremnik &DajNajlaksi() {
        if(predmeti.size()==0) throw std::range_error("Skladiste je prazno");
        return **std::min_element(predmeti.begin(),predmeti.end(),[](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2) {
            return s1->DajTezinu()<s2->DajTezinu();
        });
    }
    Spremnik &DajNajtezi() {
        if(predmeti.size()==0) throw std::range_error("Skladiste je prazno");
        return **std::max_element(predmeti.begin(),predmeti.end(),[](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2) {
            return s1->DajTezinu()<s2->DajTezinu();
        });
    }
    int BrojPreteskih(int granica) const {
        return count_if(predmeti.begin(),predmeti.end(),[granica](std::shared_ptr<Spremnik> s) {
            return s->DajUkupnuTezinu()>granica;
        });
    }
    void IzlistajSkladiste() {
        std::sort(predmeti.begin(),predmeti.end(),[](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2) {
            return s1->DajUkupnuTezinu()>s2->DajUkupnuTezinu();
        });
        std::for_each(predmeti.begin(),predmeti.end(),[](std::shared_ptr<Spremnik> s) {
            s->Ispisi();
        });
    }
    void UcitajIzDatoteke(std::string datoteka) {
        std::ifstream ulaz(datoteka);
        if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
        if(predmeti.size()!=0) {
            for(int i=0; i<predmeti.size(); i++) predmeti[i]=nullptr;
            predmeti.resize(0);
        }
        char znak;
        while(ulaz>>znak) {
            ulaz>>std::ws;
            std::string ime;
            std::getline(ulaz,ime);
            if(znak=='S') {
                if(ulaz.peek()=='\n') throw std::logic_error("Datoteka sadrzi besmislene podatke");
                double tezina,broj;
                ulaz>>tezina>>broj;
                if(!ulaz) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                if(broj!=int(broj)) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                std::vector<double> v(broj);
                for(int i=0; i<broj; i++) ulaz>>v.at(i);
                if(!ulaz) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                DodajSanduk(tezina,ime,v);
            } else if(znak=='V') {
                if(ulaz.peek()=='\n') throw std::logic_error("Datoteka sadrzi besmislene podatke");
                double tezina, tezina_materije;
                ulaz>>tezina>>tezina_materije;
                if(!ulaz) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                DodajVrecu(tezina,ime,tezina_materije);
            } else if(znak=='B') {
                if(ulaz.peek()=='\n') throw std::logic_error("Datoteka sadrzi besmislene podatke");
                double tezina,sp_tezina,V;
                ulaz>>tezina>>sp_tezina>>V;
                if(!ulaz) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                DodajBure(tezina,ime,sp_tezina,V);
            } else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        if(!ulaz.eof()) throw std::logic_error("Problemi pri citanju datoteke");
    }
};


int main ()
{
    try {
        Skladiste s;
        s.UcitajIzDatoteke("ROBA.TXT");
        s.IzlistajSkladiste();
    } catch(std::logic_error e) {
        std::cout<<e.what();
    } catch(std::range_error e) {
        std::cout<<e.what();
    }
    return 0;
}
