/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <memory>

class Spremnik {                                                                //apstraktna bazna klasa
    protected:
    double tezina;
    std::string sadrzaj;
    public:
    Spremnik (double tezina, std::string sadrzaj) : tezina(tezina),             //kontruktor
        sadrzaj(sadrzaj) {}
    virtual ~Spremnik() {}                                                      //destruktor
    virtual double DajTezinu() const = 0;                                       //apstraktna metoda
    virtual double DajUkupnuTezinu () const = 0;
    virtual void Ispisi() const = 0;
    virtual Spremnik* DajKopiju() const = 0;
};

class Sanduk : public Spremnik {                                                //za cvrste predmete
    std::vector<double> tezina_predmeta;
    public:
    Sanduk (double tezina,std::string sadrzaj, std::vector<double> tezina_predmeta) :
        Spremnik(tezina, sadrzaj), tezina_predmeta(tezina_predmeta) {}
    double DajTezinu() const override { return tezina; }
    double DajUkupnuTezinu() const override;  
    void Ispisi () const override;
    Spremnik *DajKopiju () const override { return new Sanduk(*this); }
};

double Sanduk::DajUkupnuTezinu() const {
    double rez(0);
    for(auto x: tezina_predmeta) rez+=x;
    return tezina+rez;
}

void Sanduk::Ispisi () const {
    std::cout<<"Vrsta spremnika: Sanduk"<<std::endl
        <<"Sadrzaj: "<<sadrzaj<<std::endl
        <<"Tezine predmeta: ";
    for(auto x: tezina_predmeta) std::cout<<x<<" ";
    std::cout<<"(kg)"<<std::endl
        <<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl
        <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class Bure : public Spremnik {                                                  //za tecnosti
    double gustina, zapremnina;
    public:
    Bure(double tezina,std::string sadrzaj, double gustina, double zapremnina) :
        Spremnik(tezina, sadrzaj), gustina(gustina), zapremnina(zapremnina) {}
    double DajTezinu() const override { return tezina; }
    double DajUkupnuTezinu() const override { return tezina+gustina*zapremnina/1000.; }
    void Ispisi () const override;
    Spremnik *DajKopiju() const override {
        return new Bure(*this);
    }
};

void Bure::Ispisi() const {
    std::cout<<"Vrsta spremnika: Bure"<<std::endl
        <<"Sadrzaj: "<<sadrzaj<<std::endl
        <<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl
        <<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<std::endl
        <<"Zapremina tecnosti: "<<zapremnina<<" (l)"<<std::endl
        <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class Vreca : public Spremnik {                                                 //za praskaste materije
    double tezina_materije;
    public:
    Vreca (double tezina, std::string sadrzaj, double tezina_materije) :
        Spremnik(tezina, sadrzaj), tezina_materije(tezina_materije) {}
    double DajTezinu () const override { return tezina; }
    void Ispisi () const override;
    Spremnik *DajKopiju() const override { return new Vreca(*this); }
    double DajUkupnuTezinu() const override { return tezina+tezina_materije; }
};

void Vreca::Ispisi() const {
    std::cout<<"Vrsta spremnika: Vreca"<<std::endl
        <<"Sadrzaj: "<<sadrzaj<<std::endl
        <<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl
        <<"Tezina pohranjene materije: "<<tezina_materije<<" (kg)"<<std::endl
        <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class Skladiste {                                                               //kontejnerska klasa
    std::vector<std::shared_ptr<Spremnik>> roba;
    public:
    Skladiste () = default;
    ~Skladiste ();
    Skladiste (const Skladiste &s);
    Skladiste (Skladiste &&s);
    Skladiste &operator =(Skladiste s); 
    Spremnik *DodajSanduk (double tezina,std::string sadrzaj, std::vector<double> tezina_predmeta);
    Spremnik *DodajVrecu (double tezina, std::string sadrzaj, double tezina_materije);
    Spremnik *DodajBure (double tezina,std::string sadrzaj, double gustina, double zapremnina);
    Spremnik *DodajSpremnik (Spremnik *objekat, bool istina);
    void BrisiSpremnik (Spremnik *objekat);
    void IzlistajSkladiste() const;
    Spremnik &DajNajlaksi () const;
    Spremnik &DajNajtezi () const;
    int BrojPreteskih (int t) const;
    void UcitajIzDatoteke (std::string ime_datoteke);
};

void Skladiste::UcitajIzDatoteke (std::string ime_datoteke) {
    std::ifstream ulazni_tok(ime_datoteke);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    roba.erase(roba.begin(), roba.end());
    for(;;) {
        if(!ulazni_tok) break;
        std::string ime, sadrzaj;
        ime=ulazni_tok.get();
        ulazni_tok>>std::ws;
        std::getline(ulazni_tok, sadrzaj);
        if(ime=="S") {
            int broj_predmeta;
            double tezina_predmeta, tezina;
            ulazni_tok>>tezina>>broj_predmeta;
            std::vector<double> predmeti(broj_predmeta);
            for(int i=0; i<broj_predmeta; i++) { ulazni_tok>>tezina_predmeta;
            predmeti[i]=tezina_predmeta; }
            if(ulazni_tok.peek()!='\n') throw std::logic_error("Datoteka sadrzi besmislene podatke");
            DodajSanduk(tezina, sadrzaj, predmeti);
        } else if(ime=="B") {
            double tezina, gustina, zapremnina;
            ulazni_tok>>tezina>>gustina>>zapremnina;
            DodajBure(tezina, sadrzaj, gustina, zapremnina);
        } else if(ime=="V") {
            double tezina, tezina_materije;
            ulazni_tok>>tezina>>tezina_materije;
            DodajVrecu(tezina, sadrzaj, tezina_materije);
        } 
        ulazni_tok.ignore(10000, '\n');
    }
    if(ulazni_tok.eof()) return;
    else if(ulazni_tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
    else throw std::logic_error("Datoteka sadrzi besmislene podatke");
}

Skladiste &Skladiste::operator =(Skladiste s) { 
    std::swap(roba, s.roba);
    return *this;
}

int Skladiste::BrojPreteskih (int t) const {
    int brojac(0);
    for(auto x: roba) 
        if(x->DajUkupnuTezinu()>t) brojac++;
    return brojac;
}

Spremnik &Skladiste::DajNajtezi () const {
    if(roba.size()==0)
        throw std::range_error("Skladiste je prazno");
    int indeks(0);
    for(int i=1; i<roba.size(); i++)
        if(roba[i]->DajTezinu()>roba[indeks]->DajTezinu()) indeks=i;
    return *roba[indeks];
}

Spremnik &Skladiste::DajNajlaksi() const {
    if(roba.size()==0)
        throw std::range_error("Skladiste je prazno");
    int indeks(0);
    for(int i=1; i<roba.size(); i++)
        if(roba[i]->DajTezinu()<roba[indeks]->DajTezinu()) indeks=i;
    return *roba[indeks];
}

void Skladiste::IzlistajSkladiste() const {
    if(roba.size()==0)
        throw std::range_error("Skladiste je prazno");
    std::vector<std::shared_ptr<Spremnik>> kopija;
    for(int i=0; i<roba.size(); i++)
        if(roba[i]!=nullptr) kopija.push_back(roba[i]);
    std::sort(kopija.begin(), kopija.end(), []
        (std::shared_ptr<Spremnik> pok1, std::shared_ptr<Spremnik> pok2) {
            return pok1->DajUkupnuTezinu()>pok2->DajUkupnuTezinu();
        });
    for(auto x: kopija) x->Ispisi();
}

void Skladiste::BrisiSpremnik (Spremnik *objekat) {
   for(int i=0; i<roba.size(); i++) {
       if(roba[i].get()==objekat) {
           roba[i]=nullptr;
           roba.erase(roba.begin()+i);
       }
   } 
}

Spremnik *Skladiste::DodajSpremnik (Spremnik *objekat, bool istina) { //PROFVJERITI
    if(istina) {
        roba.push_back(std::shared_ptr<Spremnik>(objekat));
        return objekat;
    } else {
        Spremnik *pok=objekat->DajKopiju();
        roba.push_back(std::shared_ptr<Spremnik>(pok));
        return pok;
    }
}

Spremnik *Skladiste::DodajBure (double tezina,std::string sadrzaj, double gustina, double zapremnina) {
    Spremnik *pok=new Bure(tezina, sadrzaj, gustina, zapremnina);
    roba.push_back(std::shared_ptr<Spremnik>(pok));
    return pok;
}

Spremnik *Skladiste::DodajVrecu (double tezina, std::string sadrzaj, double tezina_materije) {
    Vreca v(tezina, sadrzaj, tezina_materije);
    Spremnik *pok=new Vreca(v);
    roba.push_back(std::shared_ptr<Spremnik>(pok));
    return pok;
}

Spremnik *Skladiste::DodajSanduk (double tezina,std::string sadrzaj, std::vector<double> tezina_predmeta) {
    Spremnik *pok=new Sanduk (tezina, sadrzaj, tezina_predmeta);
    roba.push_back(std::shared_ptr<Spremnik>(pok));
    return pok;
}

Skladiste::Skladiste (Skladiste &&s) {
    roba=std::move(s.roba);
}

Skladiste::Skladiste (const Skladiste &s) {
    try {
        for(auto x: s.roba) 
            roba.push_back(std::shared_ptr<Spremnik>(x->DajKopiju()));
    } catch (...) {
        for(int i=0; i<roba.size(); i++) roba[i]=nullptr;
        roba.resize(0);
        throw;
    }
}

Skladiste::~Skladiste () {
    for(int i=0; i<roba.size(); i++) roba[i]=nullptr;
    roba.resize(0);
}

int main ()
{
    /*try {
    std::ofstream izlaz("TEST.TXT");
    izlaz<<"S Tepsije\n9 5 2 3 1 2 2 4 3 1 3\n";
    izlaz.flush();
    izlaz.close();
    Skladiste s;
    s.UcitajIzDatoteke("TEST.TXT");
    s.IzlistajSkladiste();
     } 
    catch (std::logic_error e) {
        std::cout<<e.what();
    }*/
    
    /*try {
        std::ofstream f("ROBA.TXT");
        f<<"S Tepsije"<<std::endl
            <<"10 9 2 3 1 2 2 4 3 1 3"<<std::endl
            <<"V Brasno"<<std::endl
            <<"0.2 5"<<std::endl
            <<"B Suncokretovo ulje"<<std::endl
            <<"5 1300 150";
        f.close();
    } catch (std::logic_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    } catch (std::range_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }*/
    Skladiste skladiste;
    try {
        skladiste.UcitajIzDatoteke("ROBA.TXT");
        skladiste.IzlistajSkladiste();
    } catch (std::logic_error e) {
        std::cout<<e.what()<<std::endl;
    } catch (std::range_error e) {
        std::cout<<e.what()<<std::endl;
    }
	return 0;
}
