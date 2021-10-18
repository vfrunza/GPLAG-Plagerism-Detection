/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::string;
using std::shared_ptr;

class Spremnik
{
    protected:
    double tezina;
    string naziv;
    public:
    Spremnik(double tezina, string naziv) : tezina(tezina), naziv(naziv) {};
    virtual double DajTezinu() { return tezina; }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual ~Spremnik(){}
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;
};


class Sanduk : public Spremnik
{
    vector<double> predmeti;
    public:
    Sanduk(double kilaza, string ime, vector<double> v) : Spremnik(kilaza, ime)
    {
        for(int i=0; i<v.size(); i++)
            predmeti.push_back(v[i]);
    }
    double DajUkupnuTezinu() const override
    {
        double suma(0);
        for(int i=0; i<predmeti.size(); i++)
            suma+=predmeti[i];
        return suma + tezina;    
    }
    void Ispisi() const override
    {
        cout<<"Vrsta spremnika: Sanduk\n";
        cout<<"Sadrzaj: "<<naziv<<"\n";
        cout<<"Tezine predmeta: ";
        for(int i=0; i<predmeti.size(); i++)
            cout<<predmeti[i]<<" ";
        cout<<"(kg)\n";
        cout<<"Vlastita tezina: "<<tezina<<" (kg)\n";
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)\n";
    }
    std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Sanduk>(*this); }
};

class Vreca : public Spremnik
{
    double prah;
    public:
    Vreca(double kilaza, string ime, double prah) : Spremnik(kilaza, ime), prah(prah){}
    double DajUkupnuTezinu() const override { return tezina + prah; }
    void Ispisi() const override
    {
        cout<<"Vrsta spremnika: Vreca\n";
        cout<<"Sadrzaj: "<<naziv<<"\n";
        cout<<"Vlastita tezina: "<<tezina<<" (kg)\n";
        cout<<"Tezina pohranjene materije: "<<prah<<" (kg)\n";
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)\n";
    }
    std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Vreca>(*this); }
};

class Bure : public Spremnik
{
    double specificna, zapremina;
    public:
    Bure(double kilaza, string ime, double specificna, double zapremina) : Spremnik(kilaza, ime), specificna(specificna), zapremina(zapremina){}
    double DajUkupnuTezinu() const override //PROVJERITI FORMULU
    {
        double m;
        m = specificna * zapremina;
        return m/1000 + tezina;
    }
    void Ispisi() const override
    {
        cout<<"Vrsta spremnika: Bure\n";
        cout<<"Sadrzaj: "<<naziv<<"\n";
        cout<<"Vlastita tezina: "<<tezina<<" (kg)\n";
        cout<<"Specificna tezina tecnosti: "<<specificna<<" (kg/m^3)\n";
        cout<<"Zapremina tecnosti: "<<zapremina<<" (l)\n";
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)\n";
    }
    std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Bure>(*this); }
    
};

class Skladiste
{
    vector<shared_ptr<Spremnik>> vektor;
    public:
    Skladiste() {}
    ~Skladiste(){}
    Skladiste(const Skladiste &s);
    Skladiste(Skladiste &&s);
    Skladiste &operator = (const Skladiste &s);
    Skladiste &operator = ( Skladiste &&s);
    Spremnik* DodajVrecu(double kilaza, string ime, double prah)
    {
        vektor.push_back(Vreca(kilaza,ime,prah).DajKopiju());
        return vektor[vektor.size()-1].get();
    }
    Spremnik* DodajBure(double kilaza, string ime, double specificna, double zapremina)
    {
        vektor.push_back(Bure(kilaza,ime,specificna,zapremina).DajKopiju());
        return vektor[vektor.size()-1].get();
    }
    Spremnik* DodajSanduk(double kilaza, string ime, vector<double> v)
    {
        vektor.push_back(Sanduk(kilaza,ime,v).DajKopiju());
        return vektor[vektor.size()-1].get();
    }
    Spremnik* DodajSpremnik(Spremnik* p, bool a)
    {
        if (a)
        {
            vektor.push_back(shared_ptr<Spremnik>(p));
            return p;
        }
        else
        {
            vektor.push_back(p->DajKopiju());
            return vektor[vektor.size()-1].get();
        }
    }
    void BrisiSpremnik(Spremnik *pok)
    {
        for(auto it=vektor.begin(); it!=vektor.end(); it++)
        {
            if (it->get() == pok)
            {
                vektor.erase(it);
                return;
            }
        }
    }
    Spremnik &DajNajlaksi();
    Spremnik &DajNajtezi();
    
    int BrojPreteskih(double c)
    {
        return std::count_if(vektor.begin(), vektor.end(), [c] (shared_ptr<Spremnik> pok)
        {
            return pok->DajUkupnuTezinu() > c;
        });
    }
    void IzlistajSkladiste()
    {
        std::sort(vektor.begin(), vektor.end(), [] (shared_ptr<Spremnik> pok1, shared_ptr<Spremnik> pok2)
        {
            return pok1->DajUkupnuTezinu() > pok2->DajUkupnuTezinu();
        });
        std::for_each(vektor.begin(), vektor.end(), [](shared_ptr<Spremnik> pok)
        {
            pok->Ispisi();
        });
    }
};

Skladiste::Skladiste(const Skladiste &s)
{
    try
    {
        for(int i=0; i<s.vektor.size(); i++)
            vektor.push_back(s.vektor[i]->DajKopiju());
    }
    catch(...)
    {
        throw;
    }
}

Skladiste::Skladiste(Skladiste &&s): vektor(s.vektor)
{}

Skladiste & Skladiste::operator=(const Skladiste &s)
{
    if(&s!=this)
    {
        vektor.resize(0);
        try
        {
            for(int i=0; i<s.vektor.size(); i++)
                vektor.push_back(s.vektor[i]->DajKopiju());
        }
        catch(...)
        {
            throw;
        }
    }
    return *this;
}

Skladiste & Skladiste::operator=(Skladiste &&s)
{
    vektor=s.vektor;
}

Spremnik &Skladiste::DajNajlaksi()
{
    if (vektor.size() == 0)
        throw std::range_error("Skladiste je prazno");
    auto tr=vektor[0];
    for(int i=0; i<vektor.size(); i++)
    {
        if(vektor[i]->DajTezinu()<tr->DajTezinu())
            tr=vektor[i];
    }
    return *tr;
}
Spremnik &Skladiste::DajNajtezi()
{
    if (vektor.size() == 0)
        throw std::range_error("Skladiste je prazno");
    auto tr=vektor[0];
    for(int i=0; i<vektor.size(); i++)
    {
        if(vektor[i]->DajTezinu()>tr->DajTezinu())
            tr=vektor[i];
    }
    return *tr;
}
int main ()
{
    try
    {
        Skladiste Amko;
        Amko.DodajSanduk(50, "kutija", {1,2,3});
        Bure *b = new Bure(15, "Voda", 1000, 200);
        Amko.DodajSpremnik(b, false);
        delete b;
        Amko.IzlistajSkladiste();
    }
    catch(std::range_error izuzetak)
    {
        cout<<izuzetak.what();
    }
	return 0;
}
