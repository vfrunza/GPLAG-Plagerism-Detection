/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>
#include <fstream>

class Spremnik
{
    double Tezina;
    std::string NazivSadrzaja;
public:
    Spremnik(double tezina, std::string naziv): Tezina(tezina), NazivSadrzaja(naziv){}
    virtual ~Spremnik(){}
    double DajTezinu() const {return Tezina;}
    std::string DajNazivSadrzaja() const {return NazivSadrzaja;}
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual Spremnik* DajKopiju() const = 0;
};
class Sanduk : public Spremnik
{
    std::vector<double> Tezina_Predmeta;
public:
    Sanduk(double tezina, std::string naziv, std::vector<double>tpredmeta): Spremnik(tezina, naziv),
        Tezina_Predmeta(tpredmeta){}
    double DajUkupnuTezinu() const override;
    void Ispisi() const override;
    Spremnik* DajKopiju() const override
    {
        return new Sanduk(*this);
    }
};
double Sanduk::DajUkupnuTezinu() const
{
    double suma(0);
    for(int i(0); i < Tezina_Predmeta.size(); i++)
        suma += Tezina_Predmeta[i];
    return (suma + DajTezinu());
}
void Sanduk::Ispisi() const
{
    std::cout << "Vrsta spremnika: Sanduk" << std::endl;
    std::cout << "Sadrzaj: " << DajNazivSadrzaja() << std::endl << "Tezine predmeta: ";
    for(int i(0); i < Tezina_Predmeta.size(); i++)
        std::cout << Tezina_Predmeta[i] << " ";
    std::cout << "(kg)" << std::endl << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}
class Vreca : public Spremnik
{
    double Tezina_Tereta;
public:
    Vreca(double tezina, std::string naziv, double tt): Spremnik(tezina, naziv), Tezina_Tereta(tt){}
    double DajUkupnuTezinu() const{
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
    std::cout << "Vrsta spremnika: Vreca" << std::endl << "Sadrzaj: " << DajNazivSadrzaja() << std::endl;
    std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Tezina pohranjene materije: " << Tezina_Tereta << " (kg)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}
class Bure : public Spremnik
{
    double SpecGustoca;
    double ZapreminaTecnosti;
public:
    Bure(double tezina, std::string naziv, double SG, double ZT): Spremnik(tezina, naziv), SpecGustoca(SG),
        ZapreminaTecnosti(ZT){}
    double DajUkupnuTezinu() const override;
    void Ispisi() const override;
    Spremnik* DajKopiju() const override
    {
        return new Bure(*this);
    }
};
double Bure::DajUkupnuTezinu() const
{
    double temp = ZapreminaTecnosti / 1000.;
    double kol = SpecGustoca * temp;
    return DajTezinu() + kol;
}
void Bure::Ispisi() const
{
    std::cout << "Vrsta spremnika: Bure" << std::endl << "Sadrzaj: " << DajNazivSadrzaja() << std::endl;
    std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Specificna tezina tecnosti: " << SpecGustoca << " (kg/m^3)" << std::endl;
    std::cout << "Zapremina tecnosti: " << ZapreminaTecnosti << " (l)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}

class PolimorfniSpremnik
{
    Spremnik *p_spremnik;
    void Test() const{
        if(!p_spremnik) throw std::logic_error("Nespecificiran spremnik");
    }
public:
    PolimorfniSpremnik() : p_spremnik(nullptr){}
    ~PolimorfniSpremnik() {delete p_spremnik;}
    double DajTezinu() const{
        Test(); return p_spremnik->DajTezinu();
    }
    double DajUkupnuTezinu() const{
        Test(); return p_spremnik->DajUkupnuTezinu();
    }
    void Ispisi() const{
        Test(); return p_spremnik->Ispisi();
    }
    PolimorfniSpremnik(const Spremnik &s): p_spremnik(s.DajKopiju()){}
    PolimorfniSpremnik(const PolimorfniSpremnik &s);
    PolimorfniSpremnik(PolimorfniSpremnik &&s);
    PolimorfniSpremnik& operator= (const PolimorfniSpremnik &s);
    PolimorfniSpremnik& operator= (PolimorfniSpremnik &&s);
};
PolimorfniSpremnik::PolimorfniSpremnik(const PolimorfniSpremnik &s)
{
    if(!s.p_spremnik) p_spremnik = nullptr;
    else p_spremnik = s.p_spremnik->DajKopiju();
}
PolimorfniSpremnik::PolimorfniSpremnik(PolimorfniSpremnik &&s)
{
    p_spremnik = s.p_spremnik;
    s.p_spremnik = nullptr;
}
PolimorfniSpremnik& PolimorfniSpremnik::operator =(const PolimorfniSpremnik &s)
{
    if(&s == this) return* this;
    delete p_spremnik;
    if(!s.p_spremnik) p_spremnik = nullptr;
    else p_spremnik = s.p_spremnik->DajKopiju();
    return *this;
}
PolimorfniSpremnik& PolimorfniSpremnik::operator =(PolimorfniSpremnik &&s)
{
    if(&s == this) return* this;
    delete p_spremnik;
    p_spremnik = s.p_spremnik;
    s.p_spremnik = nullptr;
    return *this;
}

int main ()
{
    try{
        PolimorfniSpremnik s = Bure(150, "Benzin", 100, 60);
        PolimorfniSpremnik s1, s2;
        s.Ispisi();
        s1 = Sanduk(50, "kafa", {3, 45, 5, 1, 3});
        s2 = Vreca(10, "secer", 40);
        s1.Ispisi();
        s2.Ispisi();
        s = s1;
        s.Ispisi();
        PolimorfniSpremnik novi(s2);
        novi.Ispisi();
        s = std::move(novi);
        s.Ispisi();
        PolimorfniSpremnik temp;
        temp.Ispisi();
        
    }
catch(std::logic_error e)
{
    std::cout << e.what();
}
	return 0;
}
