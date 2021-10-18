/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>
#include <fstream>


class Spremnik
{
    double tezina;
    std::string Naziv;
public:
    Spremnik(double t, std::string n): tezina(t), Naziv(n){}
    virtual ~Spremnik(){}
    double DajTezinu() const{return tezina;}
    std::string DajNazivSadrzaja() const {return Naziv;}
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual Spremnik* DajKopiju() const = 0;
};

class Sanduk : public Spremnik
{
    std::vector<double> TezinaPredmeta;
public:
    Sanduk(double t, std::string n, std::vector<double>tPredmeta): Spremnik(t, n), 
        TezinaPredmeta(tPredmeta){}
    double DajUkupnuTezinu() const
    {
        int suma(0);
        for(int i(0); i < TezinaPredmeta.size(); i++)
            suma += TezinaPredmeta[i];
        return suma + DajTezinu();
    }
    void Ispisi() const override;
    Spremnik* DajKopiju() const override
    {
        return new Sanduk(*this);
    }
};
void Sanduk::Ispisi() const
{
    std::cout << "Vrsta spremnika: Sanduk" << std::endl;
    std::cout << "Sadrzaj: " << DajNazivSadrzaja() << std::endl;
    std::cout << "Tezine predmeta: ";
    for(int i(0); i < TezinaPredmeta.size(); i++)
        std::cout << TezinaPredmeta[i] << " ";
    std::cout << "(kg)" << std::endl << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}
class Vreca: public Spremnik
{
    double TezinaTereta;
public:
    Vreca(double t, std::string n, double tt): Spremnik(t, n), TezinaTereta(tt){}
    double DajUkupnuTezinu() const{
        return DajTezinu() + TezinaTereta;
    }
    void Ispisi() const override;
    Spremnik* DajKopiju() const override
    {
        return new Vreca(*this);
    }
};
void Vreca::Ispisi() const
{
    std::cout << "Vrsta spremnika: Vreca" << std::endl;
    std::cout << "Sadrzaj: " << DajNazivSadrzaja() << std::endl;
    std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Tezina pohranjene materije: " << TezinaTereta << " (kg)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}
class Bure : public Spremnik
{
    double SpecificnaGustoca;
    double ZapreminaTecnosti;
public:
    Bure(double t, std::string n, double SG, double ZT): Spremnik(t, n), SpecificnaGustoca(SG),
        ZapreminaTecnosti(ZT){}
    double DajUkupnuTezinu() const
    {
        double t = ZapreminaTecnosti/1000;
        double k = SpecificnaGustoca * t;
        return DajTezinu() + k;
    }
    void Ispisi() const override;
    Spremnik* DajKopiju() const override
    {
        return new Bure(*this);
    }
};
void Bure::Ispisi() const
{
    std::cout << "Vrsta spremnika: Bure" << std::endl;
    std::cout << "Sadrzaj: " << DajNazivSadrzaja() << std::endl;
    std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
    std::cout << "Specificna tezina tecnosti: " << SpecificnaGustoca << " (kg/m^3)" << std::endl;
    std::cout << "Zapremina tecnosti: " << ZapreminaTecnosti << " (l)" << std::endl;
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
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
    
    Spremnik* DodajSanduk(double t, std::string n, std::vector<double>tP){
        auto temp = std::make_shared<Sanduk>(t, n, tP);
        v.push_back(temp);
        return temp.get();
    }
    Spremnik* DodajBure(double t, std::string n, double SG, double ZT){
        auto temp = std::make_shared<Bure>(t, n, SG, ZT);
        v.push_back(temp);
        return temp.get();
    }
    Spremnik* DodajVrecu(double t, std::string n, double tP){
        auto temp = std::make_shared<Vreca>(t, n, tP);
        v.push_back(temp);
        return temp.get();
    }
    Spremnik* DodajSpremnik(Spremnik* p, bool CuvamoLiGa);
    void BrisiSpremnik(Spremnik* obrisi);
    Spremnik& DajNajlaksi(){
        if(v.size() == 0)
            throw std::range_error("Skladiste je prazno");
        return *(*std::min_element(v.begin(), v.end(), 
            [](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2){
                return s1->DajTezinu() < s2->DajTezinu();
            }));
    }
    Spremnik& DajNajtezi(){
        if(v.size() == 0)
            throw std::range_error("Skladiste je prazno");
        return *(*std::max_element(v.begin(), v.end(), 
            [](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2){
                return s1->DajTezinu() < s2->DajTezinu();
            }));
    }
    int BrojPreteskih(int t) const{
        return std::count_if(v.begin(), v.end(), [&t](std::shared_ptr<Spremnik> s1){
            return s1->DajUkupnuTezinu() > t;
        });
    }
    int BrojPreteskih(int t) {
        return std::count_if(v.begin(), v.end(), [&t](std::shared_ptr<Spremnik> s1){
            return s1->DajUkupnuTezinu() > t;
        });
    }
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(const char ImeDatoteke[]);
};

Skladiste::Skladiste(const Skladiste &s)
{
    try{
        for(int i(0); i < s.v.size(); i++)
            v.push_back(std::shared_ptr<Spremnik>(s.v[i]->DajKopiju()));
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
    try{
        for(int i(0); i < s.v.size(); i++)
            v.push_back(std::shared_ptr<Spremnik>(s.v[i]->DajKopiju()));
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
    if(CuvamoLiGa == true){
        v.push_back(std::shared_ptr<Spremnik>(p));
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
    std::sort(temp.begin(), temp.end(), [](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2){
        return s1->DajUkupnuTezinu() > s2->DajUkupnuTezinu();
    });
    std::for_each(temp.begin(), temp.end(), [](std::shared_ptr<Spremnik> s1){
        s1->Ispisi();
    });
}
void Skladiste:: BrisiSpremnik(Spremnik* obrisi)
{
    for(int i(0); i < v.size(); i++)
    {
        if(&(*v[i]) == &(*obrisi)){
            v.erase(v.begin() + i);
            break;
        }
    }
}
void Skladiste::UcitajIzDatoteke(const char* dat)
{
    v.resize(0);
    std::ifstream ulaz (dat);
    if(!ulaz)
        throw std::logic_error("Trazena datoteka ne postoji");
    while (true) {
        char oznaka;
        std::string ime;
        ulaz >> oznaka;
        std::getline(ulaz >> std::ws, ime);
        
        if(oznaka == 'S')
        {
            double tezina_s;
            int br_premeta;
            ulaz >> tezina_s >> br_premeta;
            if(tezina_s < 0 || br_premeta  < 0)
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            std::vector<double> v(br_premeta);
            for(int i = 0; i < br_premeta; i++)
            {
                double t; ulaz >> t;
                if( t < 0)
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                v[i] = t;
            }
            if(ulaz.eof())
            {
                DodajSanduk(tezina_s, ime, v);
                break;
            }
            if(!ulaz.good())
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            DodajSanduk(tezina_s, ime, v);   
        }
        else if(oznaka == 'V')
        {
            double tezina_v, tezina_pm;
            
            ulaz >> tezina_v >> tezina_pm;
            
            if( tezina_pm < 0 || tezina_v < 0)
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            
            if(ulaz.eof())
            {
                DodajVrecu(tezina_v, ime, tezina_pm);    
                break;
            }
            if(!ulaz.good())
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            DodajVrecu(tezina_v, ime, tezina_pm);   
            
        }
        else if(oznaka == 'B')
        {
            double tb, st, z;
            ulaz >> tb >> st >> z;
            if(tb < 0 || st < 0 || z < 0)
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            if(ulaz.eof())
            {
                DodajBure(tb, ime, st, z);
                break;
            }
            if(!ulaz.good())
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            DodajBure(tb, ime, st, z);
        }
        else
        {
            if(ulaz.eof())
                break;
            if(!ulaz.good())
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
    }
}
int main ()

{
    try{
        Skladiste s;
        s.UcitajIzDatoteke("ROBA.TXT");
        s.IzlistajSkladiste();
    }
    catch(std::range_error e)
    {
        std::cout << e.what();
    }
    catch(std::logic_error e)
    {
        std::cout << e.what();
    }
    catch(std::bad_alloc)
    {
        std::cout << "Nestalo memorije!";
    }
	return 0;
}
