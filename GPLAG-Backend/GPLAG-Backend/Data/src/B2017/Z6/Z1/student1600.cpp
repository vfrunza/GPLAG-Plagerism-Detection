/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <fstream>
#include <new>
#include <algorithm>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

class Spremnik
{
protected:

    double tezina;
    std::string vrsta;
public:

    Spremnik (double tez, std::string vrs):tezina(tez) {
        vrsta=vrs;
    }

    double DajTezinu() const {
        return tezina;
    }

    virtual double DajUkupnuTezinu() const=0;

    virtual void Ispisi() const=0;

    virtual std::shared_ptr<Spremnik> DajKopiju() const=0;

    virtual ~ Spremnik() {}
};

class Sanduk:public Spremnik
{
private:
    std::vector<double> vektezine;
public:
    Sanduk(double tez, std::string vrs, std::vector<double> vektez):Spremnik(tez,vrs) {
        vektezine=vektez;
    }
    double DajUkupnuTezinu() const override {
        double pom(tezina);
        for(int i=0; i<vektezine.size(); i++)
            pom+=vektezine[i];
        return pom;
    }

    void Ispisi() const override;
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return (std::make_shared<Sanduk>(*this));
    }
};

void Sanduk::Ispisi() const
{
    std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
    std::cout<<"Sadrzaj: "<<vrsta<<std::endl;
    std::cout<<"Tezine predmeta: ";
    for(int i=0; i<vektezine.size(); i++)
        std::cout<<vektezine[i]<<" ";
    std::cout<<"(kg)"<<std::endl;
    std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
    std::cout<<"Ukupna tezina: "<<Sanduk::DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class Vreca:public Spremnik
{
private:
    double tezinamat;
public:
    Vreca(double tez, std::string vrs, double tezmat):Spremnik(tez, vrs), tezinamat(tezmat) {}
    double DajUkupnuTezinu() const override {
        double pom(tezina);
        pom+=tezinamat;
        return pom;
    }

    void Ispisi() const override;
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return (std::make_shared<Vreca>(*this));
    }
};

void Vreca::Ispisi() const
{
    std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
    std::cout<<"Sadrzaj: "<<vrsta<<std::endl;
    std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
    std::cout<<"Tezina pohranjene materije: "<<tezinamat<<" (kg)"<<std::endl;
    std::cout<<"Ukupna tezina: "<<Vreca::DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class Bure:public Spremnik
{
private:
    double gustina;
    double zapremina;
public:
    Bure(double tez, std::string vrs, double gust, double zapr):Spremnik(tez, vrs), gustina(gust), zapremina(zapr) {}
    double DajUkupnuTezinu() const override {
        double pom(tezina);
        pom+=(gustina*0.001*zapremina);
        return pom;
    }
    void Ispisi() const override;
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return (std::make_shared<Bure>(*this));
    }
};

void Bure::Ispisi() const
{
    std::cout<<"Vrsta spremnika: Bure"<<std::endl;
    std::cout<<"Sadrzaj: "<<vrsta<<std::endl;
    std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
    std::cout<<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<std::endl;
    std::cout<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl;
    std::cout<<"Ukupna tezina: "<<Bure::DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class Skladiste
{
private:
    std::vector<std::shared_ptr<Spremnik>> vekskladista;
public:
    Skladiste() {}
    ~Skladiste() {
        vekskladista.resize(0);
    };
    Spremnik* DodajSanduk(double rez, std::string vrs, std::vector<double> vektez);
    Spremnik* DodajVrecu(double tez, std::string vrs, double tezmat);
    Spremnik* DodajBure(double tez, std::string vrs, double gust, double zapr);
    Spremnik* DodajSpremnik(Spremnik *spremnik, bool brisati);
    void BrisiSpremnik(Spremnik* spremnik) {
        for(int i=0; i<vekskladista.size(); i++) {
            if(spremnik==(&(*vekskladista[i])))
                vekskladista.erase(vekskladista.begin()+i);
        }
    }

    Spremnik &DajNajlaksi();
    Spremnik &DajNajlaksi() const=delete;
    Spremnik &DajNajtezi();
    Spremnik &DajNajtezi() const=delete;
    int BrojPreteskih(int tezina);
    int BrojPreteskih(int tezina) const;
    void IzlistajSkladiste() const;
    Skladiste(const Skladiste &sklad);
    Skladiste(Skladiste &&sklad);
    Skladiste &operator=(const Skladiste &sklad);
    Skladiste &operator=(Skladiste &&sklad);
    void UcitajIzDatoteke (std::string imedat);
};

Spremnik * Skladiste::DodajSanduk (double tez, std::string vrs, std::vector<double> vektez)
{
    auto pok=std::make_shared<Sanduk>(tez, vrs, vektez);
    vekskladista.push_back(pok);
    return (&(*pok));
}

Spremnik* Skladiste::DodajVrecu(double tez, std::string vrs, double tezmat)
{
    auto pok=std::make_shared<Vreca>(tez, vrs, tezmat);
    vekskladista.push_back(pok);
    return (&(*pok));
}

Spremnik* Skladiste::DodajBure(double tez, std::string vrs, double gust, double zapr)
{
    auto pok=std::make_shared<Bure>(tez, vrs, gust, zapr);
    vekskladista.push_back(pok);
    return(&(*pok));
}

Spremnik* Skladiste::DodajSpremnik(Spremnik* spremnik, bool brisati)
{

    if(brisati) {
        auto pok=spremnik->DajKopiju();
        delete spremnik;
        vekskladista.push_back(pok);
        return (&(*pok));
    }
    auto pok=spremnik->DajKopiju();
    vekskladista.push_back(pok);
    return (&(*pok));
}

Spremnik &Skladiste::DajNajlaksi()
{
    if(vekskladista.size()==0)
        throw std::range_error("Skladiste je prazno");
    Spremnik *najlaksi=&(*vekskladista[0]);
    int pom=0;
    for(int i=0; i<vekskladista.size(); i++) {
        if((*vekskladista[i]).DajTezinu()<(najlaksi->DajTezinu())) {
            pom=i;
            najlaksi=&(*vekskladista[i]);
        }
    }
    return (*(vekskladista[pom]));
}

Spremnik &Skladiste::DajNajtezi()
{
    if(vekskladista.size()==0)
        throw std::range_error("Skladiste je prazno");
    Spremnik *najtezi=&(*vekskladista[0]);
    int pom=0;
    for(int i=0; i<vekskladista.size(); i++) {
        if((*vekskladista[i]).DajTezinu()>(najtezi->DajTezinu())) {
            pom=i;
            najtezi=&(*vekskladista[i]);
        }
    }
    return (*(vekskladista[pom]));
}

int Skladiste::BrojPreteskih(int tezina)
{
    int pom(0);
    for(int i=0; i<vekskladista.size(); i++) {
        if((*vekskladista[i]).DajUkupnuTezinu()>tezina)
            pom++;
    }
    return pom;
}

int Skladiste::BrojPreteskih(int tezina) const
{
    int pom=0;
    for(int i=0; i<vekskladista.size(); i++) {
        if((*vekskladista[i]).DajUkupnuTezinu()>tezina)
            pom++;
    }
    return pom;
}

void Skladiste::IzlistajSkladiste() const
{
    std::vector<std::shared_ptr<Spremnik>> pomvek(vekskladista);
    std::sort(pomvek.begin(), pomvek.end(), [](const std::shared_ptr<Spremnik> pok1, const std::shared_ptr<Spremnik> pok2) {
        return (*pok1).DajUkupnuTezinu()>(*pok2).DajUkupnuTezinu();
    });

    for(int i=0; i<pomvek.size(); i++) {
        (*pomvek[i]).Ispisi();
    }
}

Skladiste::Skladiste(const Skladiste &sklad):vekskladista(sklad.vekskladista.size())
{
    for(int i=0; i<sklad.vekskladista.size(); i++) {
        vekskladista[i]=(*(sklad.vekskladista[i])).DajKopiju();
    }
}

Skladiste::Skladiste(Skladiste &&sklad):vekskladista(std::move(sklad.vekskladista)) {}

Skladiste &Skladiste::operator=(const Skladiste &sklad)
{
    vekskladista.resize(sklad.vekskladista.size());
    for(int i=0; i<sklad.vekskladista.size(); i++) {
        vekskladista[i]=(*(sklad.vekskladista[i])).DajKopiju();
    }
    return *this;
}

Skladiste &Skladiste::operator =(Skladiste &&sklad)
{
    vekskladista=std::move(sklad.vekskladista);
    return *this;
}

void Skladiste::UcitajIzDatoteke(std::string imedat)
{
    std::ifstream ulazni_tok(imedat, std::ios::in);
    if(!ulazni_tok) throw std::logic_error ("Trazena datoteka ne postoji");
    char znak;
    std::string materija;
    while(ulazni_tok>>znak) {
        if(ulazni_tok.bad() && !ulazni_tok.eof()) {
            ulazni_tok.clear();
            throw std::logic_error("Problemi pri citanju datoteke");
        }
        if(ulazni_tok.eof()) {
            ulazni_tok.clear();
            break;
        }
        std::getline(ulazni_tok, materija);
        if(ulazni_tok.bad() && !ulazni_tok.eof()) {
            ulazni_tok.clear();
            throw std::logic_error("Problemi pri citanju datoteke");
        }
        if(ulazni_tok.eof()) {
            ulazni_tok.clear();
            break;
        }
        if(znak!='S' && znak!='V' && znak!='B')
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
        if(materija.size()==0) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        else
            materija.erase(materija.begin());
        double tezina1(0), tezina2(0);
        int broj(0);
        double spec(0), zapr(0);
        std::vector<double> vek;
        if(znak=='V') {
            ulazni_tok>>tezina1>>tezina2;
            if(ulazni_tok.bad() && !ulazni_tok.eof()) {
                ulazni_tok.clear();
                throw std::logic_error("Problemi pri citanju datoteke");
            }
        }
        if(znak=='B') {
            ulazni_tok>>tezina1>>spec>>zapr;
            if(ulazni_tok.bad() && !ulazni_tok.eof()) {
                ulazni_tok.clear();
                throw std::logic_error("Problemi pri citanju datoteke");
            }
        }
        if(znak=='S') {
            ulazni_tok>>tezina1>>broj;
            if(ulazni_tok.bad() && !ulazni_tok.eof()) {
                ulazni_tok.clear();
                throw std::logic_error("Problemi pri citanju datoteke");
            }
            for(int i=0; i<broj; i++) {
                double pom=0;
                if(ulazni_tok.eof()) {
                    ulazni_tok.clear();
                    break;
                }
                ulazni_tok>>pom;
                if(ulazni_tok.bad() && !ulazni_tok.eof()) {
                    ulazni_tok.clear();
                    throw std::logic_error("Problemi pri citanju datoteke");
                }
                vek.push_back(pom);
            }
            if(vek.size()!=broj)
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        if(tezina1<0 || tezina2<0 || broj<0)
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
        if(znak=='S')
            auto k=DodajSanduk(tezina1, materija, vek);
        if(znak=='V')
            auto k=DodajVrecu(tezina1, materija, tezina2);
        if(znak=='B')
            auto k=DodajBure(tezina1, materija, spec, zapr);
        if(ulazni_tok.eof()) {
            ulazni_tok.clear();
            break;
        }
    }
}

int main ()
{
    Skladiste sklad;
    Vreca vreca(1,"Nesto->vreca", 2);
    std::vector<double> vektor {1,3,5,7,11};
    Sanduk *sanduk=new Sanduk(4, "Nesto->sanduk", vektor);
    auto pom=sklad.DodajVrecu(10,"Mrkva i kupus", 13);
    auto pom2=sklad.DodajBure(15,"Ulje",1100,20);
    auto pom3=sklad.DodajSpremnik(new Vreca(11,"Pijesak", 50), true);
    auto pom4=sklad.DodajSpremnik(&vreca, false);
    auto pom5=sklad.DodajSpremnik(sanduk, true);
    sklad.IzlistajSkladiste();

    std::cout<<"Broj preteskih: "<<sklad.BrojPreteskih(24);
    sklad.BrisiSpremnik(pom);
    sklad.BrisiSpremnik(pom2);
    sklad.BrisiSpremnik(pom3);
    sklad.BrisiSpremnik(pom4);
    sklad.BrisiSpremnik(pom5);

    std::cout<<std::endl<<"Nakon brisanja: "<<std::endl;

    try {
        sklad.DajNajtezi().Ispisi();
        sklad.IzlistajSkladiste();
    } catch(...) {
        std::cout<<"izuzetak"<<std::endl;
    }

    try {
        Skladiste ETF;
        Spremnik *s=ETF.DodajSpremnik(new Vreca(0.5, "Secer", 40), true);
        ETF.BrisiSpremnik(s);
        ETF.DajNajtezi().Ispisi();
    } catch(std::range_error re) {
        std::cerr<<re.what();
    }
    return 0;
}
