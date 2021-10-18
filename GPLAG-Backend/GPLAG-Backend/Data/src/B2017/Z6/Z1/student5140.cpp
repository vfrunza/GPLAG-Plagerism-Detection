/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <cmath>
class Spremnik
{
protected:
    double masa_samo_masa;
    std::string naziv;
public:
    virtual ~Spremnik(){};
    friend class Skladiste;
    /*Spremnik(double m, std::string ime): masa_samo_masa(m), naziv(ime) {}*/
    double DajTezinu() const {
        return masa_samo_masa;
    }
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;
};

class Bure: public Spremnik
{
    double gustina, zapremina;
public:
    Bure(double mass, std::string tecnost, double ro, double V){
        masa_samo_masa=mass;
        naziv=tecnost;
        gustina=ro;
        zapremina=V;
    }
    double DajUkupnuTezinu() const override {
        return DajTezinu()+gustina*zapremina/1000;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<Spremnik::DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<std::endl;
        std::cout<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Bure>(masa_samo_masa, naziv, gustina, zapremina);
    }
};
class Vreca: public Spremnik
{
    double masa_materije;
public:
    Vreca(double mass, std::string materija, double masa_m){
        masa_samo_masa=mass;
        naziv=materija;
        masa_materije=masa_m;
    }
    double DajUkupnuTezinu() const override {
        return DajTezinu()+masa_materije;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Tezina pohranjene materije: "<<masa_materije<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Vreca>(masa_samo_masa, naziv, masa_materije);
    }
};
class Sanduk: public Spremnik
{
    std::vector<double> mase_predmeta;
public:
    Sanduk(double m, std::string predmet, std::vector<double> mase) {
        masa_samo_masa=m;
        naziv=predmet;
        mase_predmeta=mase;
    }
    double DajUkupnuTezinu() const override {
        double mase(0);
        for(int i=0; i<mase_predmeta.size(); i++) mase+=mase_predmeta.at(i);
        return DajTezinu()+mase;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Tezine predmeta: ";
        for(int i=0;i<mase_predmeta.size();i++){
            std::cout << mase_predmeta[i]<<" ";
        }
        std::cout<<"(kg)"<<std::endl;
        std::cout<<"Vlastita tezina: "<<masa_samo_masa<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Sanduk>(masa_samo_masa, naziv, mase_predmeta);
    }
};
class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> roba;
public:
    explicit Skladiste() = default;
    Skladiste(const Skladiste &s) {
        roba.resize(0);
        for(int i=0;i<s.roba.size();i++) roba.push_back(s.roba[i]->DajKopiju());
    }
    Skladiste &operator=(const Skladiste &s) {
        if(&s != this) {
            roba.resize(0);
            for(int i=0; i<roba.size(); i++) roba.push_back(s.roba[i]->DajKopiju());
        }
        return *this;
    }
    Spremnik* DodajBure(double m, std::string tecnost, double ro, double V) {
        auto p=std::make_shared<Bure>(m, tecnost, ro, V);
        roba.push_back(p);
        return p.get();
    }
    Spremnik* DodajVrecu(double m, std::string materija, double masa_m) {
        auto p=std::make_shared<Vreca>(m, materija, masa_m);
        roba.push_back(p);
        return p.get();
    }
    Spremnik *DodajSanduk(double m, std::string predmet, std::vector<double> mase) {
        auto p=std::make_shared<Sanduk>(m, predmet, mase);
        roba.push_back(p);
        return p.get();
    }
    Spremnik *DodajSpremnik(Spremnik *pok, bool dodati){
        if(dodati){
            auto p=pok->DajKopiju();
            roba.push_back(p);
            delete pok;
            return p.get();
        }
        else{
            auto p=pok->DajKopiju();
            roba.push_back(p);
            return p.get();
        }
    }
    void BrisiSpremnik(Spremnik *s) {
        for(int i=0;i<roba.size();i++) {
            if(s==roba[i].get()) roba.erase(roba.begin()+i);
        }
    }
    Spremnik &DajNajlaksi() {
        if(roba.begin() == roba.end()) throw std::range_error("Skladiste je prazno");
        /*std::shared_ptr<Spremnik> najlaksi(std::min_element(roba.begin(), roba.end(), 
            [](std::shared_ptr<Spremnik> a, std::shared_ptr<Spremnik> b)
            {return (*a).DajTezinu() < (*b).DajTezinu();}));
        return *najlaksi;*/
        int min(0);
        for(int i=0;i<roba.size();i++) {
            if(roba[min]->DajTezinu() > roba[i]->DajTezinu()) min = i;
        }
        return *(roba[min]);
    }
    Spremnik &DajNajtezi() {
        if(roba.begin() == roba.end()) throw std::range_error("Skladiste je prazno");
        /*std::shared_ptr<Spremnik> najtezi(std::max_element(roba.begin(), roba.end(), [](std::shared_ptr<Spremnik> a, std::shared_ptr<Spremnik> b){
            return a->DajTezinu() < b->DajTezinu();
        }));
        return *najtezi;*/
        int max(0);
        for(int i=0;i<roba.size();i++) {
            if(roba[max]->DajTezinu() < roba[i]->DajTezinu()) max = i;
        }
        return *(roba[max]);
    }
    int BrojPreteskih(int a) {
        int brojac=0;
        for(int i=0;i<roba.size();i++) {
            if(roba[i]->DajUkupnuTezinu() > a) brojac++;
        }
        return brojac;
    }
    void IzlistajSkladiste() {
        Skladiste s=*this;
        for(int i=0;i<s.roba.size();) {
            int min(0);
            for(int j=0;j<s.roba.size();j++) {
                if(s.roba[min]->DajUkupnuTezinu() < s.roba[j]->DajUkupnuTezinu()) min = j;
            }
            s.roba[min]->Ispisi();
            s.roba.erase(s.roba.begin() + min);
        }
    }
    void UcitajIzDatoteke() {
        std::ifstream ulaz("ROBA.TXT");
        if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
        char c;
        roba.resize(0);
        while(ulaz>>c) {
            char sss;
            sss=ulaz.get();
            std::string s;
            if(c=='B') {
                std::getline(ulaz, s);
                double a,b,c;
                ulaz>>a>>b>>c;
                roba.push_back(std::make_shared<Bure>(a,s,b,c));
                continue;
            }
            else if(c =='V') {
                std::getline(ulaz, s);
                double a,b;
                ulaz>>a>>b;
                roba.push_back(std::make_shared<Vreca>(a,s,b));
                continue;
            }
            else if(c=='S') {
                std::getline(ulaz,s);
                double a,b;
                std::vector<double> c;
                ulaz>>a>>b;
                for(int i=0;i<b;i++) {
                    double t;
                    ulaz>>t;
                    c.push_back(t);
                }
                roba.push_back(std::make_shared<Sanduk>(a,s,c));
                continue;
            }
            break;
        }
        if(ulaz.eof()) ;
        else if(ulaz.bad()) throw std::logic_error ("Problemi pri citanju datoteke");
        else throw std::logic_error("Datoteka ne sadrzi smislene podatke");
    }
};
int main ()
{
    return 0;
}
