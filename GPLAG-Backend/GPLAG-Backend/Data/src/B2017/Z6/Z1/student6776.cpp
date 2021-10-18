/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>

using std::endl;


class Spremnik {
    double vlastita_tezina;
    std::string sadrzaj;
    std::string vrsta_spremnika;
    public:
    Spremnik(double tezina,std::string predmet,std::string vrsta):
    vlastita_tezina(tezina), sadrzaj(predmet), vrsta_spremnika(vrsta) {}
    virtual ~Spremnik() = default;
    double DajTezinu() const { return vlastita_tezina; }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    std::string DajSadrzaj() const { return sadrzaj; }
    std::string DajVrstuSpremnika() const { return vrsta_spremnika; }
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;
};


class Sanduk: public Spremnik{
    std::vector<double> tezine_predmeta;
    public:
    Sanduk(double tezina,std::string predmet,std::vector<double> vektor_tezina):
    Spremnik(tezina,predmet,"Sanduk"), tezine_predmeta(vektor_tezina) {}
    ~Sanduk() = default;
    void IspisiTezine() const { for(auto x:tezine_predmeta) std::cout << x << " "; }
    double SumaTezina() const { double suma(0); for(auto &x:tezine_predmeta) suma+=x; return suma; }
    double DajUkupnuTezinu() const override { return this->DajTezinu()+this->SumaTezina(); }
    void Ispisi() const override;
    std::shared_ptr<Spremnik> DajKopiju() const override { return std::shared_ptr<Spremnik>(new Sanduk(*this)); }
};


void Sanduk::Ispisi() const {
    std::cout << "Vrsta spremnika: " << Spremnik::DajVrstuSpremnika() << endl;
    std::cout << "Sadrzaj: " << Spremnik::DajSadrzaj() << endl;
    std::cout << "Tezine predmeta: ";
    IspisiTezine(); 
    std::cout << "(kg)" << endl;
    std::cout << "Vlastita tezina: " << Spremnik::DajTezinu() << " (kg)" << endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << endl;
}

class Vreca: public Spremnik{
    double tezina_materije;
    public:
    Vreca(double tezina_vrece,std::string naziv,double tezina_materije):
    Spremnik(tezina_vrece,naziv,"Vreca"), tezina_materije(tezina_materije) {}
    ~Vreca() = default;
    double DajTezinuMaterije() const { return tezina_materije; }
    double DajUkupnuTezinu() const override { return this->DajTezinu()+tezina_materije; }
    void Ispisi() const override;
    std::shared_ptr<Spremnik> DajKopiju() const override { return std::shared_ptr<Spremnik>(new Vreca(*this)); }
};

void Vreca::Ispisi() const {
    std::cout << "Vrsta spremnika: " << Spremnik::DajVrstuSpremnika() << endl;
    std::cout << "Sadrzaj: " << Spremnik::DajSadrzaj() << endl;
    std::cout << "Vlastita tezina: " << Spremnik::DajTezinu() << " (kg)" << endl;
    std::cout << "Tezina pohranjene materije: " << DajTezinuMaterije() << " (kg)" << endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << endl;
}

class Bure: public Spremnik{
    double specificna_tezina;
    double zapremina;
    public:
    Bure(double tezina_bureta, std::string naziv,double rho,double volumen):
    Spremnik(tezina_bureta,naziv,"Bure"), specificna_tezina(rho), zapremina(volumen) {}
    ~Bure() = default;
    double DajSpecificnuTezinu() const { return specificna_tezina; }
    double DajZapreminu() const { return zapremina; }
    double DajUkupnuTezinu() const override { return this->DajTezinu()+specificna_tezina*zapremina/1000; }
    void Ispisi() const override;
    std::shared_ptr<Spremnik> DajKopiju() const override { return std::shared_ptr<Spremnik>(new Bure(*this)); }
};


void Bure::Ispisi() const {
    std::cout << "Vrsta spremnika: " << Spremnik::DajVrstuSpremnika() << endl;
    std::cout << "Sadrzaj: " << Spremnik::DajSadrzaj() << endl;
    std::cout << "Vlastita tezina: " << Spremnik::DajTezinu() << " (kg)" << endl;
    std::cout << "Specificna tezina tecnosti: " << DajSpecificnuTezinu() << " (kg/m^3)" << endl;
    std::cout << "Zapremina tecnosti: " << DajZapreminu() << " (l)" << endl; 
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << endl;
}






class Skladiste{
    std::vector<std::shared_ptr<Spremnik>> roba;
    //void Sortiraj();
    public:
    Skladiste() {}
    ~Skladiste() = default;
    Skladiste(const Skladiste &s) { for(auto x:s.roba) roba.push_back(x->DajKopiju());}
    Skladiste(Skladiste &&s) { for(auto x:s.roba) roba.push_back(x->DajKopiju());}
    Skladiste& operator =(const Skladiste &s)
    { roba.resize(0); for(auto x:s.roba) roba.push_back(x->DajKopiju()); return *this; }
    Skladiste operator =(Skladiste &&s);
    Spremnik* DodajSanduk(double tezina,std::string predmet,std::vector<double> vektor_tezina);
    Spremnik* DodajVrecu(double tezina_vrece,std::string naziv,double tezina_materije);
    Spremnik* DodajBure(double tezina_bureta, std::string naziv,double rho,double volumen);
    Spremnik* DodajSpremnik(Spremnik *objekat,bool logicka);
    void BrisiSpremnik(Spremnik *adresa){ for(auto &x:roba) if(&*x==adresa) x=nullptr; }
    Spremnik& DajNajtezi() const;
    Spremnik& DajNajlaksi() const;
    int BrojPreteskih(int x) { double granica(x); return std::count_if(roba.begin(),roba.end(),[&granica](std::shared_ptr<Spremnik> p){ return p->DajUkupnuTezinu()>granica;});} 
    int BrojPreteskih(int x) const { double granica(x); return std::count_if(roba.begin(),roba.end(),[&granica](std::shared_ptr<Spremnik> p){ return p->DajUkupnuTezinu()>granica;});}
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(const char ime_datoteke[]);
};

/*
void Skladiste::UcitajIzDatoteke(const char ime_datoteke[]){
    std::ifstream ulazni_tok(ime_datoteke);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    else{
        char oznaka;
        std::string sadrzaj;
        while(ulazni_tok >> oznaka){
            ulazni_tok.ignore(1,' ');
        }
    }
}*/

Skladiste Skladiste::operator =(Skladiste &&s){
    roba.resize(s.roba.size());
    for(int i(0);i<roba.size();i++) std::swap(roba[i],s.roba[i]);
    return *this;
}



void Skladiste::IzlistajSkladiste() const {
    std::vector<std::shared_ptr<Spremnik>> pomocni(roba);
    int broj_ispisanih(0);
    int nenulti(0);
    for(auto &x:pomocni) if(x!=nullptr) nenulti++;
    while(broj_ispisanih<nenulti){
        int indeks(0);
        double najvece(0);
        for(int i(0);i<roba.size();i++){
            if(pomocni[i]==nullptr) continue;
            if(pomocni[i]->DajUkupnuTezinu()>najvece){
                indeks=i;
                najvece=pomocni[i]->DajUkupnuTezinu();
            }
        }
    broj_ispisanih++;
    pomocni[indeks]->Ispisi();
    pomocni[indeks]=nullptr;
    }
}



Spremnik& Skladiste::DajNajtezi()const{
    int nenulti(0);
    for(auto &x:roba) if(x!=nullptr) nenulti++;
    if(!roba.size() || nenulti==0) throw std::range_error("Skladiste je prazno");
    double najteze(roba[0]->DajTezinu());
    int indeks(0);
    for(int i(0); i<roba.size(); i++){
        if(roba[i]==nullptr) continue;
        if(roba[i]->DajTezinu()>najteze) { indeks=i; najteze=roba[i]->DajTezinu(); }
    }
    return *roba[indeks];
}

Spremnik& Skladiste::DajNajlaksi() const{
    int nenulti(0);
    for(auto &x:roba) if(x!=nullptr) nenulti++;
    if(!roba.size() || nenulti==0) throw std::range_error("Skladiste je prazno");
    double najlakse(roba[0]->DajTezinu());
    int indeks(0);
    for(int i(0); i<roba.size(); i++){
        if(roba[i]==nullptr) continue;
        if(roba[i]->DajTezinu()<najlakse) { indeks=i; najlakse=roba[i]->DajTezinu(); }
    }
    return *roba[indeks];
}


Spremnik* Skladiste::DodajSpremnik(Spremnik *objekat,bool logicka){
    if(logicka){
        roba.push_back(std::shared_ptr<Spremnik>(objekat));
    }
    else{
        roba.push_back(objekat->DajKopiju());
    }
    Spremnik* p(&*roba[roba.size()-1]);
    return p;
}

Spremnik* Skladiste::DodajSanduk(double tezina,std::string predmet,std::vector<double> vektor_tezina){
    roba.push_back(std::shared_ptr<Spremnik>(new Sanduk(tezina,predmet,vektor_tezina)));
    Spremnik *p(&*roba[roba.size()-1]);
    return p;
}

Spremnik* Skladiste::DodajVrecu(double tezina_vrece,std::string naziv,double tezina_materije){
    roba.push_back(std::shared_ptr<Spremnik>(new Vreca(tezina_vrece,naziv,tezina_materije)));
    Spremnik *p(&*roba[roba.size()-1]);
    return p;
}

Spremnik* Skladiste::DodajBure(double tezina_bureta, std::string naziv,double rho,double volumen){
    roba.push_back(std::shared_ptr<Spremnik>(new Bure(tezina_bureta,naziv,rho,volumen)));
    Spremnik *p(&*roba[roba.size()-1]);
    return p;
}



int main ()
{
    
    try
    {

        Skladiste ETF;
        Spremnik *s = ETF.DodajSpremnik(new Vreca(0.5, "Secer", 40), true);
        ETF.BrisiSpremnik(s);
        ETF.DajNajtezi().Ispisi();
    }
    catch(std::range_error re)
    {
        std::cout << re.what();
    }
	return 0;
}
