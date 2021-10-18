/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

class Spremnik
{
    double Tezina;
protected:
    string Naziv;
public:
    Spremnik(double tezina, string naziv) : Tezina(tezina), Naziv(naziv) {}
    virtual ~Spremnik() {}
    double DajTezinu() const { return Tezina; }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual Spremnik *DajKopiju() const = 0;
};

class Sanduk : public Spremnik
{
    vector<double> Tezine;
public:
    Sanduk(double tezina, string naziv, vector<double> tezine) : Spremnik(tezina, naziv), Tezine(tezine) {}
    double DajUkupnuTezinu() const override 
    {
        double suma = 0;
        for(auto t: Tezine) suma += t;
        return suma + DajTezinu();
    }
    void Ispisi() const override
    {
        cout << "Vrsta spremnika: Sanduk" << endl;
        cout << "Sadrzaj: " << Naziv << endl;
        cout << "Tezine predmeta: ";
        for(auto t: Tezine) cout << t << " ";
        cout << "(kg)" << endl;
        cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << endl;
        cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << endl;
    }
    Sanduk *DajKopiju() const override { return new Sanduk(*this); }
};

class Vreca : public Spremnik
{
    double TezinaM;
public:
    Vreca(double tezina, string naziv, double tezinaM) : Spremnik(tezina, naziv), TezinaM(tezinaM) {}
    double DajUkupnuTezinu() const override { return DajTezinu() + TezinaM; }
    void Ispisi() const override
    {
        cout << "Vrsta spremnika: Vreca" << endl;
        cout << "Sadrzaj: " << Naziv << endl;
        cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << endl;
        cout << "Tezina pohranjene materije: " << TezinaM << " (kg)" << endl;
        cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << endl;
    }
    Vreca *DajKopiju() const override { return new Vreca(*this); }
};

class Bure : public Spremnik
{
    double Gustina;
    double Zapremina;
public:
    Bure(double tezina, string naziv, double gustina, double zapremina) : Spremnik(tezina, naziv), Gustina(gustina), Zapremina(zapremina) {}
    double DajUkupnuTezinu() const override { return (Gustina * Zapremina) / 1000. + DajTezinu(); }
    void Ispisi() const override
    {
        cout << "Vrsta spremnika: Bure" << endl;
        cout << "Sadrzaj: " << Naziv << endl;
        cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << endl;
        cout << "Specificna tezina tecnosti: " << Gustina << " (kg/m^3)" << endl;
        cout << "Zapremina tecnosti: " << Zapremina << " (l)" << endl;
        cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << endl;
    }
    Bure *DajKopiju() const override { return new Bure(*this); }
};

class Skladiste
{
    vector<shared_ptr<Spremnik>> spremnik;
public:
    Skladiste() {}
    Skladiste(const Skladiste &s)
    {
        spremnik.resize(s.spremnik.size());
        for(int i = 0; i < s.spremnik.size(); i++)
        {
            shared_ptr<Spremnik> temp(s.spremnik[i]->DajKopiju());
            spremnik[i] = temp;
        }
    }
    Skladiste &operator =(const Skladiste &s)
    {
        if(&s != this)
        {
            for(int i = 0; i < spremnik.size(); i++) spremnik[i] = nullptr;
            spremnik.resize(s.spremnik.size());
            for(int i = 0; i < s.spremnik.size(); i++)
            {
                shared_ptr<Spremnik> temp(s.spremnik[i]->DajKopiju());
                spremnik[i] = temp;
            }
        }
        return *this;
    }
    Skladiste(Skladiste &&s) : spremnik(move(s.spremnik)) {}
    Skladiste &operator =(Skladiste &&s)
    {
        if(&s != this) spremnik = move(s.spremnik);
        return *this;
    }
    Spremnik* DodajSanduk(double tezina, string naziv, vector<double> tezine);
    Spremnik* DodajVrecu(double tezina, string naziv, double tezinaM);
    Spremnik* DodajBure(double tezina, string naziv, double gustina, double zapremina);
    Spremnik* DodajSpremnik(Spremnik* s, bool preuzeti);
    void IzlistajSkladiste() const;
    Spremnik& DajNajlaksi();
    Spremnik& DajNajtezi();
    int BrojPreteskih(int t) const;
    void BrisiSpremnik(Spremnik *s);
    void UcitajIzDatoteke(const char c1[]);
};



void Skladiste::BrisiSpremnik(Spremnik *s)
{
    shared_ptr<Spremnik> brisi(s);
    auto it = spremnik.begin();
    while(it != spremnik.end())
    {
        if(*it == brisi) it = spremnik.erase(it);
        else ++it;
    }
}

int Skladiste::BrojPreteskih(int t) const
{
    int brojac = 0;
    for(auto s: spremnik)
    {
        if(s->DajUkupnuTezinu() > t) brojac++;
    }
    
    return brojac;
}

Spremnik& Skladiste::DajNajlaksi()
{
    if(spremnik.size() == 0)
        throw range_error("Skladiste je prazno");
        
    return **min_element(spremnik.begin(), spremnik.end(), [](shared_ptr<Spremnik> s1, shared_ptr<Spremnik> s2) { return s1->DajTezinu() < s2->DajTezinu(); });
}

Spremnik& Skladiste::DajNajtezi()
{
    if(spremnik.size() == 0)
        throw range_error("Skladiste je prazno");
    
    return **min_element(spremnik.begin(), spremnik.end(), [](shared_ptr<Spremnik> s1, shared_ptr<Spremnik> s2) { return s1->DajTezinu() > s2->DajTezinu(); });
}

void Skladiste::IzlistajSkladiste() const
{
    vector<shared_ptr<Spremnik>> temp(spremnik);
    sort(temp.begin(), temp.end(), [](shared_ptr<Spremnik> s1, shared_ptr<Spremnik> s2)->bool { return s1->DajUkupnuTezinu() > s2->DajUkupnuTezinu(); });
    for(auto s: temp) s->Ispisi();
}

Spremnik* Skladiste::DodajSanduk(double tezina, string naziv, vector<double> tezine)
{
    Sanduk *s = new Sanduk(tezina, naziv, tezine);
    spremnik.push_back(shared_ptr<Sanduk>(s));
    return s;
}

Spremnik* Skladiste::DodajVrecu(double tezina, string naziv, double tezinaM)
{
    Vreca *v = new Vreca(tezina, naziv, tezinaM);
    spremnik.push_back(shared_ptr<Vreca>(v));
    return v;
}

Spremnik* Skladiste::DodajBure(double tezina, string naziv, double gustina, double zapremina)
{
    Bure *b = new Bure(tezina, naziv, gustina, zapremina);
    spremnik.push_back(shared_ptr<Bure>(b));
    return b;
}

Spremnik* Skladiste::DodajSpremnik(Spremnik* s, bool preuzeti)
{
    if(preuzeti)
    {
        shared_ptr<Spremnik> novi(s);
        spremnik.push_back(novi);
        return s;   
    }
    else
    {
        Spremnik* novi = s->DajKopiju();
        shared_ptr<Spremnik> n(novi);
        spremnik.push_back(n);
        return novi;
    }
}

int main ()
{
    try
    {
        Skladiste skladiste;
        Spremnik *s = skladiste.DodajSpremnik(new Vreca(0.2, "Prasak", 35), true);
        skladiste.DodajSanduk(25, "Tvrdo", {3,1,6,5});
        skladiste.DodajVrecu(1, "Pijesak", 52.2);
        skladiste.DodajBure(6, "Voda", 1000, 200);
        
        skladiste.BrisiSpremnik(s);
        skladiste.IzlistajSkladiste();
    }
    catch(range_error e)
    {
        cout << e.what();
    }
	
	return 0;
}
