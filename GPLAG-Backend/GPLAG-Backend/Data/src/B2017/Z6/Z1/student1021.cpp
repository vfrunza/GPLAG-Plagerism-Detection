/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <utility>
#include <algorithm>

using std::shared_ptr;
using std::make_shared;
using std::string;
using std::ws;
const double pomocni(1e-3);
const double laksi(1e10);
const double tezi(-1e10);


// Bazna klasa 
class Spremnik {
    protected:
        double tezina;
        string naziv_predmeta;
    public:
        Spremnik() {}
        virtual ~Spremnik() {}
        Spremnik(double tezina_pom, string naziv_pom) {
            Spremnik::tezina=tezina_pom; Spremnik::naziv_predmeta=naziv_pom;
        }
        double DajTezinu() const { return tezina; }
        virtual double DajUkupnuTezinu() const=0;
        virtual void Ispisi() const=0;
        virtual Spremnik* DajKopiju() const=0;
};

class Sanduk : public Spremnik {
    std::vector<double>tezine; // tezine predmeta su u kilogramima
    public:
        Sanduk() {}
        Sanduk(double tezina_pom, string naziv_pom, std::vector<double>tezine_pom) : Spremnik(tezina_pom, naziv_pom) {
            Sanduk::tezine=tezine_pom;
        }
        std::vector<double>DajTezine() const { return tezine; }
        
        double DajUkupnuTezinu() const override {
            double suma(0);
            int i(0);
            while (i<tezine.size()) {
                suma+=tezine.at(i);
                i++;
            }
            suma+=DajTezinu();
            return suma;
        }
        
        void Ispisi() const override {
            std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
            std::cout<<"Sadrzaj: "<<Spremnik::naziv_predmeta<<std::endl;
            std::cout<<"Tezine predmeta: ";
            int i(0);
            while (i<tezine.size()) {
                std::cout<<tezine.at(i)<<" ";
                i++;
            }
            std::cout<<"(kg)"<<std::endl;
            std::cout<<"Vlastita tezina: "<<Spremnik::DajTezinu()<<" (kg)"<<std::endl;
            std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
        }
        
        Sanduk *DajKopiju() const { return new Sanduk(DajTezinu(), naziv_predmeta, DajTezine()); }
};

class Vreca : public Spremnik {
    double tezina_materije;
    public:
        Vreca() {}
        Vreca(double tezina_materije_pom, string naziv_pom, double tezine_pom) : Spremnik(tezina_materije_pom, naziv_pom) {
            Vreca::tezina_materije=tezine_pom;
        }
        
        double DajUkupnuTezinu() const override {
            double povratna_tezina(tezina_materije+DajTezinu());
            return povratna_tezina;
        }
        
        void Ispisi() const override {
            std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
            std::cout<<"Sadrzaj: "<<Spremnik::naziv_predmeta<<std::endl;
            std::cout<<"Vlastita tezina: "<<Spremnik::DajTezinu()<<" (kg)"<<std::endl;
            double pohranjena_memorija(DajUkupnuTezinu()-DajTezinu());
            std::cout<<"Tezina pohranjene materije: "<<pohranjena_memorija<<" (kg)"<<std::endl;
            std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
        }
        
        Vreca *DajKopiju() const { return new Vreca(DajTezinu(), naziv_predmeta, tezina_materije); }
};

class Bure : public Spremnik {
    double specificna_gustina, volumen;
    public:
        Bure() {}
        Bure(double tezina_pom, string naziv_pom, double sprecificna_tezina_pom, double volumen_pom) : Spremnik(tezina_pom, naziv_pom) {
                Bure::specificna_gustina=sprecificna_tezina_pom; Bure::volumen=volumen_pom;
        }
        double DajVolumen() const { return volumen; }
        double DajSpecificnuGustinu() const { return specificna_gustina; }
        double DajUkupnuTezinu() const override {  
            double stvarna_tezina(pomocni*DajVolumen()*DajSpecificnuGustinu()+DajTezinu());
            return stvarna_tezina;
        }
        void Ispisi() const override {
            std::cout<<"Vrsta spremnika: Bure"<<std::endl;
            std::cout<<"Sadrzaj: "<<Spremnik::naziv_predmeta<<std::endl;
            std::cout<<"Vlastita tezina: "<<Spremnik::DajTezinu()<<" (kg)"<<std::endl;
            std::cout<<"Specificna tezina tecnosti: "<<DajSpecificnuGustinu()<<" (kg/m^3)"<<std::endl;
            std::cout<<"Zapremina tecnosti: "<<DajVolumen()<<" (l)"<<std::endl;
            std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
        }
        Bure *DajKopiju() const { return new Bure(DajTezinu(), naziv_predmeta, DajSpecificnuGustinu(), DajVolumen()); }
};

class Skladiste {
    std::vector<shared_ptr<Spremnik>>pametni;
    public:
        Skladiste() { pametni.clear(); }
        
        ~Skladiste() {
            for (int i=0; i<pametni.size(); i++) {
                pametni[i]=nullptr;
                pametni.clear();
            }
        }
        
        Skladiste(const Skladiste &skladiste) {
            try {
                pametni.clear();
                int i(0);
                while (i<skladiste.pametni.size()) {
                    pametni.push_back(skladiste.pametni.at(i));
                    i++;
                }
            } catch(...) { throw; }
        }
        
        Skladiste &operator =(const Skladiste &skladiste) { pametni=skladiste.pametni; return *this; }
        
        Sanduk *DodajSanduk(double tezina_pom, string naziv_pom, std::vector<double>tezine_pom) {
            shared_ptr<Sanduk>povratni;
            povratni=make_shared<Sanduk>(tezina_pom, naziv_pom, tezine_pom);
            pametni.push_back(povratni);
            return povratni.get();
        }
        
        Vreca *DodajVrecu(double tezina_pom, string naziv_pom, double tezine_pom) {
            shared_ptr<Vreca>povratni;
            povratni=make_shared<Vreca>(tezina_pom, naziv_pom, tezine_pom);
            pametni.push_back(povratni);
            return povratni.get();
        }
        
        Bure *DodajBure(double tezina_pom, string naziv_pom, double specificna_gustina_pom, double volumen_pom) {
            shared_ptr<Bure>povratni;
            povratni=make_shared<Bure>(tezina_pom, naziv_pom, specificna_gustina_pom, volumen_pom);
            pametni.push_back(povratni);
            return povratni.get();
        }
        
        Spremnik *DodajSpremnik(Spremnik *predmet, bool logic) {
            if (logic==true) {
                shared_ptr<Spremnik>povratni(predmet);
                pametni.push_back(povratni);
                return povratni.get();
            }
            if (logic==false) {
                shared_ptr<Spremnik>povratni(predmet->DajKopiju());
                pametni.push_back(povratni);
                return povratni.get();
            }
            else {
                shared_ptr<Spremnik>povratni(predmet->DajKopiju());
                pametni.push_back(povratni);
                return povratni.get();
            }
        }
        
        Spremnik *BrisiSpremnik(Spremnik *spremnik) {
            if (pametni.size()==0) throw std::range_error("Skladiste je prazno");
            int i(0);
            while (i<pametni.size()) {
                if (pametni.at(i).get()==spremnik) {
                    pametni.erase(std::begin(pametni)+i);
                    return spremnik;
                }
                i++;
            }
        }
        
        Spremnik &DajNajlaksi() const {
            if (pametni.size()==0) {
                throw std::range_error("Skladiste je prazno");
            }
            double povratna(laksi);
            int i(0), index(0);
            while (i<pametni.size()) {
                if (pametni.at(i)==nullptr) continue;
                if (pametni.at(i)->DajTezinu()<povratna) {
                    index=i;
                    povratna=pametni.at(i)->DajTezinu();
                }
                i++;
            }
            return (*pametni.at(index).get());
        }
        
        Spremnik &DajNajtezi() const {
            if (pametni.size()==0) {
                throw std::range_error("Skladiste je prazno");
            }
            double povratna(tezi);
            int i(0), index(0);
            while (i<pametni.size()) {
                if (pametni.at(i)==nullptr) continue;
                if (pametni.at(i)->DajTezinu()>povratna) {
                    index=i;
                    povratna=pametni.at(i)->DajTezinu();
                }
                i++;
            }
            return (*pametni.at(index).get());
        }
        
        int BrojPreteskih(const double &vrijednost) {
            int i(0), brojac(0);
            while (i<pametni.size()) {
                if (pametni.at(i)->DajUkupnuTezinu()>vrijednost) {
                    brojac++;
                }
                i++;
            }
            return brojac;
        }
        
        int BrojPreteskih(double vrijednost) const {
            int i(0), brojac(0);
            while (i<pametni.size()) {
                if (pametni.at(i)->DajUkupnuTezinu()>vrijednost) {
                    brojac++;
                }
                i++;
            }
            return brojac;
        }
             
        void IzlistajSkladiste() {
            int i(0);
            while (i<pametni.size()-1) {
                int j(i+1);
                while (j<pametni.size()) {
                    if (pametni.at(i)->DajUkupnuTezinu()<pametni.at(j)->DajUkupnuTezinu()) {
                        pametni.at(i).swap(pametni.at(j));
                    }
                    j++;
                }
                i++;
            }
            
            int k(0);
            while (k<pametni.size()) {
                if (pametni.at(k)!=nullptr) {
                    pametni.at(k)->Ispisi();
                }
                k++;
            }
            
        } 
        
        void UcitajIzDatoteke(const char datoteka[]) {
            std::ifstream ulazni_tok(datoteka);
            char unos(0);
            if (ulazni_tok.fail()) {
                throw std::logic_error ("Trazena datoteka ne postoji");
            }
            ulazni_tok>>ws;
            while (ulazni_tok>>unos) {
                if (unos!='B' && unos!='S' && unos!='V') {
                    throw std::logic_error ("Datoteka sadrzi besmislene podatke");
                }
                char ime_pom[30];
                
                if (unos=='S') {
                    ulazni_tok.getline(ime_pom, sizeof ime_pom);
                    int broj(0), i(0);
                    double tezina, tezina_pom;
                    std::vector<double>pomocni;
                    ulazni_tok>>tezina>>broj;
                    if (ulazni_tok.fail()) {
                        throw std::logic_error ("Datoteka sadrzi besmislene podatke");
                    }
                    while (i<broj) {
                        ulazni_tok>>tezina_pom;
                        if (ulazni_tok.fail()) {
                            throw std::logic_error ("Datoteka sadrzi besmislene podatke");
                        }
                        pomocni.push_back(tezina_pom);
                        i++;
                    }
                    DodajSanduk(tezina, &ime_pom[1], pomocni);
                }
                
                else if (unos=='V') {
                    ulazni_tok.getline(ime_pom, sizeof ime_pom);
                    double tezina, tezina_pom;
                    ulazni_tok>>tezina;
                    if (ulazni_tok.fail()) {
                        throw std::logic_error ("Datoteka sadrzi besmislene podatke");
                    }
                    ulazni_tok>>tezina_pom;
                    DodajVrecu(tezina, &ime_pom[1], tezina_pom);
                }
                
                else if (unos=='B') {
                    ulazni_tok.getline(ime_pom, sizeof ime_pom);
                    double tezina_pom, specificna_gustina_pom, volumen_pom;
                    ulazni_tok>>tezina_pom>>specificna_gustina_pom>>volumen_pom;
                    if (ulazni_tok.fail()) {
                        throw std::logic_error("Datoteka sadrzi besmislene podatke");
                    }
                    DodajBure(tezina_pom, &ime_pom[1], specificna_gustina_pom, volumen_pom);
                }
                
                if (ulazni_tok.bad()) {
                    throw std::logic_error("Problemi pri citanju datoteke");
                }
            }
        }
};

int main () {
    
    try {
        Skladiste ETF;
        ETF.DodajSanduk(50, "Voce", {1,3,5,6});
        ETF.DodajVrecu(0.1, "Brasno", 25.5);
        ETF.DodajBure(5, "Krv", 1300, 150);
        ETF.DodajSpremnik(new Vreca(0.5, "Secer", 40), true);
        Bure *b = new Bure(15, "Voda", 1000, 200);
        ETF.DodajSpremnik(b, false);
        delete b;
        ETF.DajNajlaksi().Ispisi();
        std::cout<<ETF.BrojPreteskih(40)<<std::endl;
        ETF.DajNajtezi().Ispisi();
    }
    catch (std::range_error re) {
        std::cout<<re.what();
    }
    
	return 0;
}