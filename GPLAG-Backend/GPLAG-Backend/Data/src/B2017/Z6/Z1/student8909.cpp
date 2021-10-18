/B2017/2018: Zadaća 6, Zadatak 1
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


class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> v;
    std::vector<Spremnik*> adrese;
    Spremnik& DajNajlaksi() const;
    Spremnik& DajNajtezi() const;
    
    public:
    
    Skladiste() = default;
    Skladiste(const Skladiste &s);
    Skladiste(Skladiste &&s);
    Skladiste& operator =(const Skladiste &s);
    Skladiste& operator =(Skladiste &&s);
    
    Spremnik* DodajSanduk(double tezina, std::string naziv, std::vector<double> tpredmeta)
    {
        auto s = std::make_shared<Sanduk>(tezina, naziv, tpredmeta);
        v.push_back(s);
        
        return s.get();
    }
    
    Spremnik* DodajVrecu(double tezina, std::string naziv, double tt)
    {
        auto s = std::make_shared<Vreca>(tezina, naziv, tt);
        v.push_back(s);
        
        return s.get();
    }
    
    Spremnik* DodajBure(double tezina, std::string naziv, double SG, double ZT)
    {
        auto s = std::make_shared<Bure>(tezina, naziv, SG, ZT);
        v.push_back(s);
        
        return s.get();
    }
    
    Spremnik*DodajSpremnik(Spremnik* p, bool CuvamoLiGa);
    void BrisiSpremnik(Spremnik* obrisi);
    
    Spremnik& DajNajlaksi()
    {
        if(v.size() == 0) throw std::range_error("Skladiste je prazno");
        
        return *(*std::min_element(v.begin(), v.end(), [](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2)
        {
            return s1->DajTezinu() < s2->DajTezinu();
        }));
    }
    
    Spremnik& DajNajtezi()
    {
        if(v.size() == 0) throw std::range_error("Skladiste je prazno");
        
        return *(*std::max_element(v.begin(), v.end(), [](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2)
        {
            return s1->DajTezinu() < s2->DajTezinu();
        }));
    }
    
    int BrojPreteskih(int x) const
    {
        return std::count_if(v.begin(), v.end(), [&x](std::shared_ptr<Spremnik> s1)
        {
            return s1->DajUkupnuTezinu() > x;
        });
    }
    
    int BrojPreteskih(int x)
    {
        return std::count_if(v.begin(), v.end(), [&x](std::shared_ptr<Spremnik> s1)
        {
            return s1->DajUkupnuTezinu() > x;
        });
    }
    
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(const char ImeDatoteke[]);
};

Skladiste::Skladiste(const Skladiste &s)
{
    try
    {
        for(int i=0; i<s.v.size(); i++) v.push_back(std::shared_ptr<Spremnik>(s.v[i] -> DajKopiju()));
    }
    catch(std::bad_alloc)
    {
        v.resize(0);
        throw;
    }
}

Skladiste::Skladiste(Skladiste &&s)
{
    v = s.v;
    s.v.resize(0);
}

Skladiste& Skladiste::operator =(const Skladiste &s)
{
    if(&s == this) return *this;
    
    v.resize(0);
    
    try
    {
        for(int i=0; i<s.v.size(); i++) v.push_back(std::shared_ptr<Spremnik> (s.v[i] -> DajKopiju()));
    }
    catch(std::bad_alloc)
    {
        v.resize(0);
        throw;
    }
    return *this;
}

Skladiste& Skladiste::operator =(Skladiste &&s)
{
    if(&s == this) return *this;
    v.resize(0);
    v = s.v;
    s.v.resize(0);
    return *this;
}

Spremnik* Skladiste::DodajSpremnik(Spremnik* p, bool CuvamoLiGa)
{
    if(CuvamoLiGa == true)
    {
        v.push_back(std::shared_ptr<Spremnik> (p));
        return p;
    }
    else
    {
        std::shared_ptr<Spremnik> s(p->DajKopiju());
        v.push_back(s);
        return s.get();
    }
}

void Skladiste::IzlistajSkladiste() const
{
    auto temp(v);
    std::sort(temp.begin(), temp.end(), [](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2)
    {
        return s1 -> DajUkupnuTezinu() > s2 -> DajUkupnuTezinu();
    });
    
    std::for_each(temp.begin(), temp.end(), [](std::shared_ptr<Spremnik> s1)
    {
        s1 -> Ispisi();   
    });
}

void Skladiste::BrisiSpremnik(Spremnik* obrisi)
{
    for(int i=0; i<v.size(); i++)
    {
        if(&(*v[i]) == &(*obrisi))
        {
            v.erase(v.begin() + i);
            break;
        }
    }
}

void Skladiste::UcitajIzDatoteke(const char ImeDatoteke[])
{
    v.resize(0);
    std::ifstream Utok(ImeDatoteke);
    if(!Utok) throw std::logic_error("Trazena datoteka ne postoji");
    else
    {
        char znak;
        std::string naziv;
        while(Utok >> znak)
        {
            if(Utok.peek() == ' ') Utok >> naziv;
        
        else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        
        if(znak == 'S')
        {
            double tSanduka, bPredmeta;
            if(Utok >> tSanduka >> bPredmeta)
            {
                if(bPredmeta < 0) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                std::vector<double> tPredmeta(bPredmeta);
                for(int i=0; i<bPredmeta; i++)
                {
                    double t;
                    if(Utok >> t) tPredmeta[i] = t;
                    else throw std::logic_error("Datoteka sadrzi besmislene podatke");
                }
                DodajSanduk(tSanduka, naziv, tPredmeta);
            }
            else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        else if(znak == 'V')
        {
            double tVrece, tMaterije;
            if(Utok >> tVrece >> tMaterije) DodajVrecu(tVrece, naziv, tMaterije);
            else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        else if(znak == 'B')
        {
            double tBureta, sTezina, zTecnosti;
            if(Utok >> tBureta >> sTezina >> zTecnosti) DodajBure(tBureta, naziv, sTezina, zTecnosti);
            else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        else throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }
    if(Utok.eof());
    else throw std::logic_error("Problemi pri citanju datoteke");
    }
}

int main ()
{
    std::cout << "Radi";
	return 0;
}
