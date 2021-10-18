/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
#include <memory>
#include <vector>

class Spremnik
{
    double Tezina;
    std::string NazivSadrzaja;
    
    public:
    
    Spremnik(double tezina, std::string naziv) : Tezina(tezina), NazivSadrzaja(naziv) {}
    virtual ~Spremnik(){}
    double DajTezinu() const 
    {
        return Tezina;
    }
    std::string DajNazivSadrzaja() const
    {
        return NazivSadrzaja;
    }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual Spremnik* DajKopiju() const = 0;
};

class Sanduk : public Spremnik
{
    std::vector<double> Tezina_Predmeta;
    
    public:
    
    Sanduk(double tezina, std::string naziv, std::vector<double>tpredmeta) : Spremnik(tezina, naziv), Tezina_Predmeta(tpredmeta) {}
    double DajUkupnuTezinu() const override;
    void Ispisi() const override;
    Spremnik* DajKopiju() const override
    {
        return new Sanduk (*this);
    }
};

void Sanduk::Ispisi () const
{
    std::cout << "Vrsta spremnika: Sanduk" << std::endl;
    std::cout << "Sadrzaj: " << DajNazivSadrzaja() << std::endl << "Tezine predmeta: ";
    for(int i=0; i < Tezina_Predmeta.size(); i++)
    {
        std::cout << Tezina_Predmeta[i] << " ";
    }
    std::cout << "(kg)" << std::endl << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}

double Sanduk::DajUkupnuTezinu() const
{
    double suma = 0;
    for(int i=0; i < Tezina_Predmeta.size(); i++)
    {
        suma = suma + Tezina_Predmeta[i];
    }
    return (suma + DajTezinu());
}

class Bure : public Spremnik
{
    double SpecGustoca;
    double ZapreminaTecnosti;
    
    public:
    
    Bure(double tezina, std::string naziv, double SG, double ZT) : Spremnik(tezina, naziv), SpecGustoca(SG), ZapreminaTecnosti(ZT) {}
    double DajUkupnuTezinu() const override;
    void Ispisi() const override;
    Spremnik* DajKopiju() const override
    {
        return new Bure(*this);
    }
};

void Bure::Ispisi() const
{
    std::cout << "Vrsta spremnika: Bure" << std::endl << "Sadrzaj: " << DajNazivSadrzaja() << std::endl
              << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl
              << "Specificna tezina tecnosti: " << SpecGustoca << " (kg/m^3)" << std::endl
              << "Zapremina tecnosti: " << ZapreminaTecnosti << " (l)" << std::endl
              << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}

double Bure::DajUkupnuTezinu() const
{
    double temp = ZapreminaTecnosti / 1000.;
    double kol = SpecGustoca * temp;
    return DajTezinu() + kol;
}

class Vreca : public Spremnik
{
    double Tezina_Tereta;
    
    public:
    
    Vreca(double tezina, std::string naziv, double tt) : Spremnik(tezina, naziv), Tezina_Tereta(tt) {}
    double DajUkupnuTezinu() const 
    {
        return DajTezinu() + Tezina_Tereta;
    }
    void Ispisi() const override;
    Spremnik* DajKopiju() const override
    {
        return new Vreca(*this);
    }
};

void Vreca::Ispisi() const
{
    std::cout << "Vrsta spremnika: Vreca" << std::endl << "Sadrzaj: " << DajNazivSadrzaja() << std::endl
              << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl
              << "Tezina pohranjene materije: " << Tezina_Tereta << " (kg)" << std::endl
              << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}

class PolimorfniSpremnik
{
    Spremnik* p_spremnik;
    void Test() const
    {
        if(!p_spremnik) throw std::logic_error("Nespecificiran spremnik");
    }
    
    public:
    
    PolimorfniSpremnik() : p_spremnik(nullptr) {}
    ~PolimorfniSpremnik() 
    {
        delete p_spremnik;
    }
    double DajTezinu() const
    {
        Test();
        return p_spremnik->DajTezinu();
    }
    double DajUkupnuTezinu() const
    {
        Test();
        return p_spremnik->DajUkupnuTezinu();
    }
    void Ispisi() const
    {
        Test();
        return p_spremnik->Ispisi();
    }
    PolimorfniSpremnik(const Spremnik &s) : p_spremnik(s.DajKopiju()) {}
    PolimorfniSpremnik(const PolimorfniSpremnik &s);
    PolimorfniSpremnik(PolimorfniSpremnik &&s);
    PolimorfniSpremnik& operator =(const PolimorfniSpremnik &s);
    PolimorfniSpremnik& operator =(PolimorfniSpremnik &&s);
};

PolimorfniSpremnik& PolimorfniSpremnik::operator =(const PolimorfniSpremnik &s)
{
    if(&s == this) 
        return *this;
    delete p_spremnik;
    if(!s.p_spremnik) 
        p_spremnik = nullptr;
    else p_spremnik = s.p_spremnik->DajKopiju();
    
    return *this;
}

PolimorfniSpremnik& PolimorfniSpremnik::operator =(PolimorfniSpremnik &&s)
{
    if(&s == this)
        return *this;
    delete p_spremnik;
    p_spremnik = s.p_spremnik;
    s.p_spremnik = nullptr;
    
    return *this;
}

PolimorfniSpremnik::PolimorfniSpremnik(PolimorfniSpremnik &&s)
{
    p_spremnik = s.p_spremnik;
    s.p_spremnik = nullptr;
}

PolimorfniSpremnik::PolimorfniSpremnik(const PolimorfniSpremnik &s)
{
    if(!s.p_spremnik) p_spremnik = nullptr;
    else p_spremnik = s.p_spremnik->DajKopiju();
}

int main ()
{
    try
    {
        PolimorfniSpremnik s = Bure(10, "Sok", 930, 70);
        PolimorfniSpremnik s1, s2;
        s.Ispisi();
        s1 = Sanduk(5, "Kutije", {2, 4, 2.5, 9, 15});
        s2 = Vreca(0.1, "Brasno", 20);
        
        s1.Ispisi();
        s2.Ispisi();
        
        s = s1;
        s.Ispisi();
        
        PolimorfniSpremnik N(s2);
        N.Ispisi();
    }
    catch(std::logic_error greska)
    {
        std::cout << greska.what();
    }
	return 0;
}
