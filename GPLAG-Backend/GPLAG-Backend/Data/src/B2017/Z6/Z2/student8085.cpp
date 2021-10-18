/B2017/2018: Zadaća 6, Zadatak 2
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

class PolimorfniSpremnik
{
    Spremnik *spremnik;
public:
    PolimorfniSpremnik() { spremnik = nullptr; }
    ~PolimorfniSpremnik() { delete spremnik; }
    PolimorfniSpremnik(const Spremnik &s) { spremnik = s.DajKopiju(); }
    PolimorfniSpremnik &operator =(const Spremnik &s)
    {
        delete spremnik;
        spremnik = s.DajKopiju();
        return *this;
    }
    PolimorfniSpremnik(const PolimorfniSpremnik &ps)
    {
        if(!ps.spremnik) spremnik = nullptr;
        else spremnik = ps.spremnik->DajKopiju();
    }
    PolimorfniSpremnik &operator =(const PolimorfniSpremnik &ps)
    {
        if(&ps != this)
        {
            if(!ps.spremnik) spremnik = nullptr;
            else
            {
                delete spremnik;
                spremnik = ps.spremnik->DajKopiju();
            }
        }
        return *this;
    }
    PolimorfniSpremnik &operator =(PolimorfniSpremnik &&ps)
    {
        if(&ps != this)
        {
            delete spremnik;
            spremnik = ps.spremnik;
            ps.spremnik = nullptr;
        }
        return *this;
    }
    double DajTezinu() const 
    { 
        if(spremnik == nullptr)
            throw logic_error("Nespecificiran spremnik");
        return spremnik->DajTezinu(); 
    }
    double DajUkupnuTezinu() const 
    { 
        if(spremnik == nullptr)
            throw logic_error("Nespecificiran spremnik");
        return spremnik->DajUkupnuTezinu(); 
    }
    void Ispisi() const 
    { 
        if(spremnik == nullptr)
            throw logic_error("Nespecificiran spremnik");
        spremnik->Ispisi(); 
    }
    PolimorfniSpremnik *DajKopiju() const { return new PolimorfniSpremnik(*this); }
};

int main ()
{
    try
    {

        PolimorfniSpremnik ps1(Bure(2,"Tecnost", 325, 20));
        PolimorfniSpremnik ps2, ps3;
        ps2 = Sanduk(1, "Tvrdo", {5, 8, 5, 6});
        ps3 = Vreca(0.5, "Pijesak", 12);
        cout << ps1.DajTezinu() << endl;
        cout << ps2.DajUkupnuTezinu() << endl;
        ps3.Ispisi();
        ps1 = ps2;
        ps1.Ispisi();
    }
    catch(logic_error e)
    {
        cout << e.what();
    }

	return 0;
}
