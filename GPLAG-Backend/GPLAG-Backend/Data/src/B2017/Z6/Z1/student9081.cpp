/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <fstream>

class Spremnik
{
    double tezina;
    std::string naziv;
public:
    Spremnik (double tezina, std::string naziv): tezina(tezina),naziv(naziv) {}
    virtual ~Spremnik () {}
    virtual std::shared_ptr<Spremnik> DajKopiju () const = 0;
    double DajTezinu () const {return tezina;}
    std::string DajNaziv () const {return naziv;}
    virtual double DajUkupnuTezinu () const = 0;
    virtual void Ispisi () const = 0;
};

class Sanduk: public Spremnik
{
    std::vector<double> tez;
public:
    Sanduk (double tezina, std::string naziv, std::vector<double> tezine): Spremnik(tezina,naziv),tez(tezine) {}
    double DajUkupnuTezinu() const override;
    void Ispisi () const override;
    std::shared_ptr<Spremnik> DajKopiju () const override {return std::make_shared<Sanduk> (*this);}
};

double Sanduk::DajUkupnuTezinu () const
{
    double suma(DajTezinu());
    for (double x: tez) suma+=x;
    return suma;
}

void Sanduk::Ispisi () const
{
    std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
    std::cout<<"Sadrzaj: "<<DajNaziv()<<std::endl;
    std::cout<<"Tezine predmeta: ";
    for (double x: tez) std::cout<<x<<" ";
    std::cout<<"(kg)"<<std::endl;
    std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
    std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class Vreca: public Spremnik
{
    double tez_materije;
public:
    Vreca (double tezina, std::string naziv, double tez_materije): Spremnik(tezina,naziv), tez_materije(tez_materije) {}
    double DajUkupnuTezinu() const override {return DajTezinu()+tez_materije;}
    void Ispisi () const override;
    std::shared_ptr<Spremnik> DajKopiju() const override {return std::make_shared<Vreca> (*this);}
};

void Vreca::Ispisi() const
{
    std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
    std::cout<<"Sadrzaj: "<<DajNaziv()<<std::endl;
    std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
    std::cout<<"Tezina pohranjene materije: "<<tez_materije<<" (kg)"<<std::endl;
    std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class Bure: public Spremnik
{
    double spec_tezina,zapremina;
public:
    Bure (double tezina, std::string naziv, double spec_tezina, double zapremina): Spremnik(tezina,naziv),spec_tezina(spec_tezina),zapremina(zapremina) {}
    std::shared_ptr<Spremnik> DajKopiju() const override {return std::make_shared<Bure> (*this);}
    double DajUkupnuTezinu() const override {return DajTezinu()+zapremina*spec_tezina/1000;}
    void Ispisi () const override;
};

void Bure::Ispisi() const
{
    std::cout<<"Vrsta spremnika: Bure"<<std::endl;
    std::cout<<"Sadrzaj: "<<DajNaziv()<<std::endl;
    std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
    std::cout<<"Specificna tezina tecnosti: "<<spec_tezina<<" (kg/m^3)"<<std::endl;
    std::cout<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl;
    std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> spremnik;
    void Test (const Skladiste &s);
public:
    Skladiste () = default;
    Skladiste (const Skladiste &s);
    Skladiste (Skladiste &&s);
    Skladiste &operator= (const Skladiste &s);
    Skladiste &operator= (Skladiste &&s);
    ~Skladiste () = default;
    Spremnik *DodajBure (double tezina, std::string naziv, double spec_tezina, double zapremina);
    Spremnik *DodajVrecu (double tezina, std::string naziv, double tez_materije);
    Spremnik *DodajSanduk (double tezina, std::string naziv, std::vector<double> tezine);
    Spremnik *DodajSpremnik (Spremnik *sp, bool vlasnistvo);
    void BrisiSpremnik (Spremnik *sp);
    Spremnik &DajNajlaksi ();
    Spremnik &DajNajtezi ();
    int BrojPreteskih (int n) const;
    void IzlistajSkladiste () const;
    void UcitajIzDatoteke (const char ime_datoteke[]);
};

void Skladiste::Test(const Skladiste &s)
{
    *this=s;
    throw std::logic_error ("Datoteka sadrzi besmislene podatke");
}

void Skladiste::UcitajIzDatoteke (const char ime_datoteke[])
{
    std::ifstream iz_tok (ime_datoteke);
    if (!iz_tok) throw std::logic_error ("Trazena datoteka ne postoji");
    auto temp(*this);
    spremnik.resize(0);
    char znak;
    std::string ime;
    while (iz_tok>>znak)
    {
        if (iz_tok.fail()) Test(temp);
        iz_tok>>std::ws;
        std::getline(iz_tok,ime);
        if (iz_tok.fail()) Test(temp);
        if (znak=='S')
        {
            double tezina;
            int velicina;
            iz_tok>>tezina>>velicina;
            std::vector<double> tezine;
            if (iz_tok.fail() || tezina<0 || velicina<0) Test(temp);
            for (int i=0;i<velicina;i++)
            {
                double t;
                iz_tok>>t;
                tezine.push_back(t);
                if (iz_tok.fail() || t<0) Test(temp);
            }
            spremnik.push_back(std::make_shared<Sanduk> (tezina,ime,tezine));
        }
        else if (znak=='V')
        {
            double tezina,tez_materije;
            iz_tok>>tezina>>tez_materije;
            if (iz_tok.fail() || tezina<0 || tez_materije<0) Test(temp);
            spremnik.push_back(std::make_shared<Vreca> (tezina,ime,tez_materije));
        }
        else if (znak=='B')
        {
            double tezina,spec_gustina,zapremina;
            iz_tok>>tezina>>spec_gustina>>zapremina;
            if (iz_tok.fail() || tezina<0 || spec_gustina<0 || zapremina<0) Test(temp);
            spremnik.push_back(std::make_shared<Bure> (tezina,ime,spec_gustina,zapremina));
        }
        else Test(temp);
    }
    if (iz_tok.eof()) return;
    else if (iz_tok.bad()) std::logic_error ("Problemi pri citanju datoteke");
    else Test(temp);
}

void Skladiste::IzlistajSkladiste () const
{
    std::vector<bool> vec(spremnik.size(),false);
    for (int i=0;i<spremnik.size();i++)
    {
        int maxi(0);
        while (vec[maxi]==true) maxi++;
        for (int j=0;j<spremnik.size();j++)
        {
            if (spremnik[j]->DajUkupnuTezinu()>spremnik[maxi]->DajUkupnuTezinu() && vec[j]==false)
            maxi=j;
        }
        vec[maxi]=true;
        spremnik[maxi]->Ispisi();
    }
}

int Skladiste::BrojPreteskih (int n) const
{
    return std::count_if(spremnik.begin(),spremnik.end(),[n] (std::shared_ptr<Spremnik> s) {return s->DajUkupnuTezinu()>n;});
}

Spremnik &Skladiste::DajNajlaksi ()
{
    if (spremnik.size()==0) throw std::range_error ("Skladiste je prazno");
    return **std::min_element(spremnik.begin(),spremnik.end(),[] (std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2) {return s1->DajTezinu()<s2->DajTezinu();});
}

Spremnik &Skladiste::DajNajtezi ()
{
    if (spremnik.size()==0) throw std::range_error ("Skladiste je prazno");
    return **std::max_element(spremnik.begin(),spremnik.end(),[] (std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2) {return s1->DajTezinu()<s2->DajTezinu();});
}

void Skladiste::BrisiSpremnik (Spremnik *p)
{
    for (int i=0;i<spremnik.size();i++)
    {
        if (p==spremnik[i].get())
        spremnik.erase(spremnik.begin()+i);
    }
}

Spremnik *Skladiste::DodajSpremnik (Spremnik *sp, bool vlasnistvo)
{
    if (vlasnistvo)
    {
        spremnik.push_back(std::shared_ptr<Spremnik> (sp));
        return sp;
    }
    auto pok(sp->DajKopiju());
    spremnik.push_back(pok);
    return pok.get();
}

Spremnik *Skladiste::DodajSanduk (double tezina, std::string naziv, std::vector<double> tezine)
{
    auto pok(std::make_shared<Sanduk> (tezina,naziv,tezine));
    spremnik.push_back(pok);
    return pok.get();
}

Spremnik *Skladiste::DodajVrecu (double tezina, std::string naziv, double tez_materije)
{
    auto pok(std::make_shared<Vreca>(tezina,naziv,tez_materije));
    spremnik.push_back(pok);
    return pok.get();
}

Spremnik *Skladiste::DodajBure (double tezina, std::string naziv, double spec_tezina, double zapremina)
{
    auto pok(std::make_shared<Bure> (tezina,naziv,spec_tezina,zapremina));
    spremnik.push_back(pok);
    return pok.get();
}

Skladiste::Skladiste (const Skladiste &s)
{
    for (int i=0;i<s.spremnik.size();i++)
        spremnik.push_back(s.spremnik[i]->DajKopiju());
}

Skladiste::Skladiste (Skladiste &&s):spremnik(s.spremnik) {}

Skladiste &Skladiste::operator= (const Skladiste &s)
{
    std::vector<std::shared_ptr<Spremnik>> novi;
    for (int i=0;i<s.spremnik.size();i++)
        novi.push_back(s.spremnik[i]->DajKopiju());
    spremnik=novi;
    return *this;
}

Skladiste &Skladiste::operator= (Skladiste &&s)
{
    std::swap(spremnik,s.spremnik);
    return *this;
}

int main ()
{
    Skladiste s1;
    try
    {
        s1.UcitajIzDatoteke("ROBA.TXT");
        s1.IzlistajSkladiste();
    }
    catch(std::logic_error e)
    {
        std::cout<<e.what()<<std::endl;
    }
	return 0;
}
