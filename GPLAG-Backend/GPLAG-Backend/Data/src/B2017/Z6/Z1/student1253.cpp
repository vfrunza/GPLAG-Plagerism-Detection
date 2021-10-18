/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <fstream>

class Spremnik
{
protected:
    double tezina;
    std::string naziv;
public:
    virtual ~Spremnik() {} //treba i kad su pametni pokazivaci
    Spremnik(double tezina, std::string naziv) : tezina(tezina), naziv(naziv) {}
    double DajTezinu() const {
        return tezina;
    }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;
};

class Sanduk : public Spremnik
{
    std::vector<double> tezina_predmeta;
public:
    Sanduk(double t, std::string ime, std::vector<double> tp) : Spremnik(t, ime), tezina_predmeta(tp) {}
    double DajUkupnuTezinu() const override {
        double povratna(tezina);
        for(int i=0; i<tezina_predmeta.size(); i++) {
            povratna += tezina_predmeta[i];
        }
        return povratna;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Sanduk\n";
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Tezine predmeta: ";
        for(int i=0; i<tezina_predmeta.size(); i++) {
            std::cout<<tezina_predmeta[i]<<" ";
        }
        std::cout<<"(kg)\n";
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)\n";
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)\n";
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Sanduk>(*this);
    }
};

class Vreca : public Spremnik
{
    double tezina_praska;
public:
    Vreca(double t, std::string ime, double tp) : Spremnik(t, ime), tezina_praska(tp) {}
    double DajUkupnuTezinu() const override {
        return tezina + tezina_praska;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Vreca\n";
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)\n";
        std::cout<<"Tezina pohranjene materije: "<<tezina_praska<<" (kg)\n";
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)\n";
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Vreca>(*this);
    }
};

class Bure : public Spremnik
{
    double R;
    double V;
public:
    Bure(double t, std::string ime, double R, double V) : Spremnik(t, ime), R(R), V(V) {}
    double DajUkupnuTezinu() const override {
        return tezina + R*V*0.001;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Bure\n";
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)\n";
        std::cout<<"Specificna tezina tecnosti: "<<R<<" (kg/m^3)\n";
        std::cout<<"Zapremina tecnosti: "<<V<<" (l)\n";
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)\n";
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Bure>(*this);
    }
};



class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> v;
public:
    Skladiste() = default;
    Skladiste(const Skladiste &s) : v(s.v.size()) {
        for(int i=0; i<s.v.size(); i++) {
            v[i] = s.v[i]->DajKopiju();
        }
    }
    Skladiste(Skladiste &&s) : v(std::move(s.v)) {
        s.v.resize(0);
    }
    Skladiste &operator =(const Skladiste &s) {
        v.resize(s.v.size());
        for(int i=0; i<s.v.size(); i++) {
            v[i] = s.v[i]->DajKopiju();
        }
        return *this;
    }
    Skladiste &operator =(Skladiste &&s) {
        v = std::move(s.v);
        return *this;
    }
    Spremnik *DodajSanduk(double t, std::string ime, std::vector<double> tp) {
        std::shared_ptr<Spremnik> novi;
        novi = std::make_shared<Sanduk>(t, ime, tp);
        v.push_back(novi);
        return novi.get();
    }
    Spremnik *DodajVrecu(double t, std::string ime, double tp) {
        std::shared_ptr<Spremnik> novi;
        novi = std::make_shared<Vreca>(t, ime, tp);
        v.push_back(novi);
        return novi.get();
    }
    Spremnik *DodajBure(double t, std::string ime, double R, double V) {
        std::shared_ptr<Spremnik> novi;
        novi = std::make_shared<Bure>(t, ime, R, V);
        v.push_back(novi);
        return novi.get();
    }
    Spremnik *DodajSpremnik(Spremnik *s, bool vlasnistvo) {
        std::shared_ptr<Spremnik> novi;
        novi = s->DajKopiju();
        v.push_back(novi);
        if(vlasnistvo) {
            delete s;
            s = nullptr;
        }
        return novi.get();
    }
    void BrisiSpremnik(Spremnik *s) {
        for(int i=0; i<v.size(); i++) {
            if(v[i].get() == s) {
                v[i] = nullptr;
                v.erase(v.begin() + i);
                break;
            }
        }
    }

    Skladiste DajNajlaksi() const = delete;
    Spremnik &DajNajlaksi() {
        if(v.size()==0) throw std::range_error("Skladiste je prazno\n");
        int indeks(0);
        double min(v[0]->DajTezinu());
        for(int i=0; i<v.size(); i++) {
            if(v[i]->DajTezinu() < min) {
                min = v[i]->DajTezinu();
                indeks = i;
            }
        }
        return *v[indeks];
    }
    Skladiste DajNajtezi() const = delete;
    Spremnik &DajNajtezi() {
        if(v.size()==0) throw std::range_error("Skladiste je prazno\n");
        int indeks(0);
        double max(v[0]->DajTezinu());
        for(int i=0; i<v.size(); i++) {
            if(v[i]->DajTezinu() > max) {
                max = v[i]->DajTezinu();
                indeks = i;
            }
        }
        return *v[indeks];
    }
    int BrojPreteskih(int granica) {
        int broj(0);
        for(int i=0; i<v.size(); i++) {
            if(v[i]->DajUkupnuTezinu() > granica)  broj++;
        }
        return broj;
    }
    int BrojPreteskih(int granica) const {
        int broj(0);
        for(int i=0; i<v.size(); i++) {
            if(v[i]->DajUkupnuTezinu() > granica)  broj++;
        }
        return broj;
    }

    void IzlistajSkladiste() const {
        Skladiste novo(*this);
        std::sort(novo.v.begin(), novo.v.end(), [](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2) {
            if(s1->DajUkupnuTezinu() > s2->DajUkupnuTezinu()) return true;
            return false;
        });
        std::for_each(novo.v.begin(), novo.v.end(), [](std::shared_ptr<Spremnik> s1) {
            s1->Ispisi();
        });
    }
    void IzlistajSkladiste() {
        Skladiste novo(*this);
        std::sort(novo.v.begin(), novo.v.end(), [](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2) {
            if(s1->DajUkupnuTezinu() > s2->DajUkupnuTezinu()) return true;
            return false;
        });
        std::for_each(novo.v.begin(), novo.v.end(), [](std::shared_ptr<Spremnik> s1) {
            s1->Ispisi();
        });
    }
    void UcitajIzDatoteke(std::string ime_datoteke) {
        std::ifstream tok(ime_datoteke.c_str());
        if(!tok) throw std::logic_error("Trazena datoteka ne postoji\n");
        else {
            v.resize(0);
            char znak;
            while( (znak=tok.get()) != EOF && znak != '\n' ) {
                if(znak=='S') {

                    std::string ime;
                    znak = tok.get(); //da ucitamo razmak
                    std::getline(tok, ime);
                    double t, velicina;
                    tok>>t>>velicina;
                    std::vector<double> tp(velicina);
                    for(int i=0; i<velicina; i++) {
                        tok>>tp[i];
                    }

                    v.push_back(std::make_shared<Sanduk>(t, ime, tp));

                } else if(znak == 'V') {

                    std::string ime;
                    znak = tok.get(); //da ucitamo razmak
                    std::getline(tok, ime);
                    double t, tp;
                    tok>>t>>tp;

                    v.push_back(std::make_shared<Vreca>(t, ime, tp));

                } else if(znak == 'B') {

                    std::string ime;
                    znak = tok.get(); //da ucitamo razmak
                    std::getline(tok, ime);
                    double t, R, V;
                    tok>>t>>R>>V;

                    v.push_back(std::make_shared<Bure>(t, ime,  R, V));

                } else if(znak == '\n') {

                } else break;
            }
            if(tok.eof()) {

            } else if(tok.bad()) {
                throw std::logic_error("Problemi pri citanju datoteke\n");
            } else if(!tok.good()) {
                throw std::logic_error("Datoteka sadrzi besmislene podatke\n");
            }
        }
    }
};

int main ()
{
    try {
        std::ofstream izlaz("TEST.TXT");
        izlaz << "S Tepsije\n9 10 2 3 1 2 2 4 3 1 3\n";
        izlaz << "V Brasno\n0.9 100\n";
        izlaz << "B Suncokretovo ulje\n5 1300 150";
        izlaz.flush();
        izlaz.close();

        Skladiste ETF;
        ETF.UcitajIzDatoteke("TEST.TXT");
        ETF.IzlistajSkladiste();
    } catch(std::logic_error le) {
        std::cout << le.what();
    }


    return 0;
}
