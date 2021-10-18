/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <memory>
#include <vector>

class Spremnik
{
    double tezina;
    std::string naziv;
public:
    Spremnik (double tezina, std::string naziv): tezina(tezina),naziv(naziv) {}
    virtual ~Spremnik () {}
    virtual std::shared_ptr<Spremnik> DajKopiju () const = 0;
    double DajTezinu() const {return tezina;}
    std::string DajNaziv () const {return naziv;}
    virtual double DajUkupnuTezinu () const = 0;
    virtual void Ispisi () const = 0;
};

class Sanduk: public Spremnik
{
    std::vector<double> tez;
public:
    Sanduk (double tezina, std::string naziv, const std::vector<double> &tez): Spremnik(tezina,naziv),tez(tez) {}
    double DajUkupnuTezinu() const override;
    void Ispisi () const override;
    std::shared_ptr<Spremnik> DajKopiju() const override {return std::make_shared<Sanduk> (*this);}
};

double Sanduk::DajUkupnuTezinu() const
{
    double suma(DajTezinu());
    for (double x: tez) suma+=x;
    return suma;
}

void Sanduk::Ispisi() const
{
    std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
    std::cout<<"Sadrzaj: "<<DajNaziv()<<std::endl;
    std::cout<<"Tezine predmeta: ";
    for(double x: tez) std::cout<<x<<" ";
    std::cout<<"(kg)"<<std::endl;
    std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
    std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class Vreca: public Spremnik
{
    double tez_materije;
public:
    Vreca (double tezina, std::string naziv, double tez_materije):Spremnik(tezina,naziv),tez_materije(tez_materije) {}
    double DajUkupnuTezinu() const override {return DajTezinu()+tez_materije;}
    void Ispisi() const override;
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
    double DajUkupnuTezinu() const override {return DajTezinu()+zapremina*spec_tezina/1000;}
    void Ispisi() const override;
    std::shared_ptr<Spremnik> DajKopiju() const override {return std::make_shared<Bure> (*this);}
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

class PolimorfniSpremnik
{
    std::shared_ptr<Spremnik> pok;
    void Test () const {if (!pok) throw std::logic_error ("Nespecificiran spremnik");}
public:
    PolimorfniSpremnik ():pok(nullptr) {}
    ~PolimorfniSpremnik() = default;
    PolimorfniSpremnik(const PolimorfniSpremnik &ps);
    PolimorfniSpremnik(const Spremnik &s):pok(s.DajKopiju()) {}
    PolimorfniSpremnik(PolimorfniSpremnik &&ps):pok(ps.pok) {ps.pok=nullptr;}
    PolimorfniSpremnik &operator= (const PolimorfniSpremnik &ps);
    PolimorfniSpremnik &operator= (const Spremnik &s);
    PolimorfniSpremnik &operator= (PolimorfniSpremnik &&ps);
    double DajTezinu() const {Test(); return pok->DajTezinu();}
    std::string DajNaziv() const {Test(); return pok->DajNaziv();}
    double DajUkupnuTezinu() const {Test(); return pok->DajUkupnuTezinu();}
    void Ispisi() const {Test(); pok->Ispisi();}
};

PolimorfniSpremnik &PolimorfniSpremnik::operator= (const Spremnik &s)
{
    pok=s.DajKopiju();
    return *this;
}

PolimorfniSpremnik &PolimorfniSpremnik::operator= (const PolimorfniSpremnik &ps)
{
    std::shared_ptr<Spremnik> novi;
    if (!ps.pok) novi=nullptr;
    else novi=ps.pok->DajKopiju();
    pok=novi;
    return *this;
}

PolimorfniSpremnik &PolimorfniSpremnik::operator= (PolimorfniSpremnik &&ps)
{
    std::swap(pok,ps.pok);
    return *this;
}

PolimorfniSpremnik::PolimorfniSpremnik (const PolimorfniSpremnik &ps)
{
    if (!ps.pok) pok=nullptr;
    else pok=ps.pok->DajKopiju();
}


int main ()
{
    PolimorfniSpremnik ps1(Vreca(12.4,"Vreca ok",1.32));
    try
    {
        PolimorfniSpremnik ps2;
        ps2=ps1;
        ps1=Bure(13.2,"Bure 123",1300,1200);
        ps1.Ispisi();
        ps2.Ispisi();
        PolimorfniSpremnik ps3;
        ps3=Vreca(1,"Vreca ok2",1.1);
        PolimorfniSpremnik ps4(ps3);
        ps4=Sanduk(12,"Sanduk 321",{1,2,3,4});
        std::cout<<ps3.DajUkupnuTezinu()<<" "<<ps4.DajUkupnuTezinu()<<"\n";
        ps3.Ispisi();
        std::cout<<ps4.DajNaziv()<<std::endl;
    }
    catch(std::logic_error e)
    {
        std::cout<<e.what()<<std::endl;
    }
	return 0;
}
