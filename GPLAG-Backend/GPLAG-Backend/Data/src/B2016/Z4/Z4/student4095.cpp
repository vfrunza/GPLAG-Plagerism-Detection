/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!

#include <iostream>
#include <stdexcept>
#include <cctype>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <memory>

class Datum
{
    int _d, _m, _g;
public:
    Datum(int d, int m, int g)
    {
        Postavi(d, m, g);
    }
    int DajDan()const
    {
        return _d;
    }
    int DajMjesec()const
    {
        return _m;
    }
    int DajGodinu()const
    {
        return _g;
    }
    void Ispisi()const
    {
        std::cout << _d << '/' << _m << '/' << _g;
    }
    void Postavi(int d, int m, int g);
    
};

void Datum::Postavi(int d, int m, int g)
{
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0)
        ++broj_dana[1];
    if(d < 1 || m < 1 || g < 1 || m > 12 || d > broj_dana[m - 1])
        throw std::domain_error("Neispravan datum");
    _m = m;
    _d = d;
    _g = g;
}

class Kupac
{
    std::string _ime;
    Datum _datum;
    static void provjeri_ime(const std::string& ime);
public:
    Kupac(const std::string& ime, const Datum& datum) : _ime(ime), _datum(datum)
    {
        provjeri_ime(ime);
    }
    void Postavi(const std::string& ime, const Datum& datum);
    
    std::string DajImeIPrezime()const
    {
        return _ime;
    }
    
    Datum DajDatumRodjenja()const
    {
        return _datum;
    }
    void Ispisi()const
    {
        std::cout << _ime << " (";
        _datum.Ispisi();
        std::cout << ")\n";
    }
};

void Kupac::provjeri_ime(const std::string& ime)
{
    for(const auto& z : ime)
        if( !std::islower(std::tolower(z)) && z != ' ' && z != '-' && z != 39 )
            throw std::domain_error("Neispravno ime i prezime");
}

void Kupac::Postavi(const std::string& ime, const Datum& datum)
{
    provjeri_ime(ime);
    _ime = ime;
    _datum = datum;
}

class Stan
{
    std::string _adresa;
    int _sprat, _broj_soba;
    bool _namjesten;
    double _kvadratura;
public:
    Stan(const std::string& adresa, int s, int bs, bool n, double k)
    {
        Postavi(adresa, s, bs, n, k);
    }
    void Postavi(const std::string& adresa, int s, int bs, bool n, double k);
    
    std::string DajAdresu()const
    {
        return _adresa;
    }
    
    int DajSprat() const
    {
        return _sprat;
    }
    
    bool DajNamjesten() const
    {
        return _namjesten;
    }
    
    double DajKvadraturu() const
    {
        return _kvadratura;
    }
    
    int DajBrojSoba()const
    {
        return _broj_soba;
    }
    
    void Ispisi()const
    {
        std::cout << "Stan se nalazi na adresi " << _adresa << " na " << _sprat
            << " i ima " << _broj_soba;
       if(_broj_soba >= 2 && _broj_soba <= 4 || _broj_soba > 20 && _broj_soba % 10 >= 2 && _broj_soba % 10 <= 4)
            std::cout << " sobe. ";
        else
            std::cout << " soba. ";
        std::cout << "Kvadratura stana je " << _kvadratura
            << " (m^2) i stan " << (_namjesten ? "je" : "nije" ) << " namjesten.";
        
    }
};


void Stan::Postavi(const std::string& adresa, int s, int bs, bool n, double k)
{
    if(s < 0 || bs < 0 || k < 0 )
        throw std::domain_error("Neispravan unos podataka");
    _adresa = adresa;
    _sprat = s;
    _broj_soba = bs;
    _namjesten = n;
    _kvadratura = k;
}

class Prodaje;

class Prodaja
{
    std::string _ime_agenta;
    double _cijena;
    Datum _datum;
    Kupac _kupac;
    Stan _stan;
    friend Prodaje;
public:
    Prodaja(const std::string ia, double cs, const Datum& d, const Kupac& k, const Stan& s) 
        : _ime_agenta(ia), _cijena(cs), _datum(d), _kupac(k), _stan(s) {}
    
    Prodaja(const std::string ia, double cs, 
        int d, int m, int g, 
        const std::string ime, const Datum& d_kupca, 
        const std::string& adresa, int ss, int bs, bool n, double k) 
            : _ime_agenta(ia), _cijena(cs), _datum(d, m, g), 
              _kupac(ime, d_kupca), _stan(adresa, ss, bs, n, k) {}
    
    void PromijeniStan(const Stan& s)
    {
        _stan = s;
    }
    
    void PrimijeniDatumKupovine(const Datum& d)
    {
        _datum = d;
    }
    
    void PromijeniCijenuProdaje(const double& nova_cijena)
    {
        _cijena = nova_cijena;
    }
    
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    
    std::string DajImeAgenta() const
    {
        return _ime_agenta;
    }
    
    std::string DajImeKupca() const
    {
        return _kupac.DajImeIPrezime();
    }
    
    Datum DajDatumProdaje() const
    {
        return _datum;
    }
    
    double DajCijenuStana() const
    {
        return _cijena;
    }
    
    friend bool ProdatPrije(const Prodaja& s1, const Prodaja& s2);
    friend bool SkupljiStan(const Prodaja& s1, const Prodaja& s2)
    {
        return s1.DajCijenuStana() < s2.DajCijenuStana();
    }
    
    void Ispisi() const;
};

bool ProdatPrije(const Prodaja& s1, const Prodaja& s2)
{
    if(s1._datum.DajGodinu() == s2._datum.DajGodinu())
    {
        if(s1._datum.DajMjesec() == s2._datum.DajMjesec())    
            return s1._datum.DajDan() < s2._datum.DajDan();
        return s1._datum.DajMjesec() < s2._datum.DajMjesec();
    }
    return s1._datum.DajGodinu() < s2._datum.DajGodinu();
}

void Prodaja::PomjeriDanUnaprijed()
{
    int g = _datum.DajGodinu();
    int m = _datum.DajMjesec();
    int d = _datum.DajDan();
    
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0)
        ++broj_dana[1];
        
    if(d == broj_dana[m - 1])
    {
        d = 1;
        if(m == 12)
        {
            ++g;
            m = 1;
        }
        else
         ++m;
    }
    else
        ++d;
    _datum.Postavi(d, m, g);
    
}
void Prodaja::PomjeriDanUnazad()
{
    int g = _datum.DajGodinu();
    int m = _datum.DajMjesec();
    int d = _datum.DajDan();
    
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0)
        ++broj_dana[1];
        
    if(d == 1)
    {
      if(m == 1)
      {
          --g;
          m = 12;
          d = 31;
      }
      else
      {
          --m;
          d = broj_dana[m - 1];
      }
    }
    else
        --d;
    _datum.Postavi(d, m, g);
}

void Prodaja::Ispisi() const
{
    std::cout << std::setw(32) << std::left<< "Ime agenta: " << _ime_agenta << "\n";
    std::cout << std::setw(32) << std::left<< "Ime kupca: " << _kupac.DajImeIPrezime() << " (";
    _kupac.DajDatumRodjenja().Ispisi();
    std::cout << ")\n";
    std::cout << std::setw(32) << std::left<< "Zakazani datum prodaje: ";
    _datum.Ispisi();
    std::cout << "\nInforamcije o stanu:\n";
    _stan.Ispisi();
}


class Prodaje
{
    std::vector<std::shared_ptr<Prodaja>> _pr;
public:
    Prodaje() {}
    Prodaje(std::initializer_list<Prodaja> sp);
    
    Prodaje(const Prodaje& p)
    {
        _pr.reserve(p._pr.size());
        for(const auto& elem : p._pr)
            _pr.emplace_back(std::make_shared<Prodaja>(*elem) );
    }
    
    Prodaje(Prodaje&& p) : _pr(std::move(p._pr))
    {
        p._pr.resize(0);
    }
    
    Prodaje& operator= (const Prodaje& p);
    Prodaje& operator= (Prodaje&& p);
    
    void RegistrirajProdaju(const std::string ia, double cs, const Datum& d, const Kupac& k, const Stan& s)
    {
        _pr.emplace_back(std::make_shared<Prodaja>(ia, cs, d, k, s));
    }
    
    void RegistrirajProdaju(const std::string ia, double cs, 
        int d, int m, int g, 
        const std::string ime, const Datum& d_kupca, 
        const std::string& adresa, int ss, int bs, bool n, double k) 
    {
        _pr.emplace_back(std::make_shared<Prodaja>
            (ia, cs, Datum{d, m, g}, Kupac{ime, d_kupca}, Stan{adresa, ss, bs, n, k}));
    }
    
    void RegistrirajProdaju(std::shared_ptr<Prodaja> p)
    {
        _pr.push_back(p);
    }
    
    int DajBrojProdaja() const
    {
        return _pr.size();
    }
    
    int DajBrojProdajaNaDatum(const Datum& d) const;
    int DajBrojProdajaOdAgenta(const std::string& s)const
    {
        return std::count_if(_pr.end(), _pr.end(), [&](const std::shared_ptr<Prodaja>& p) {
        return s == p->DajImeAgenta();
        });
    }
    
    Prodaja& DajNajranijuProdaju()
    {
        return **std::min_element(_pr.begin(), _pr.end(), 
            [](const std::shared_ptr<Prodaja>& p1, const std::shared_ptr<Prodaja>& p2){
                return ProdatPrije(*p1, *p2);
        } );
    }
    
    Prodaja DajNajranijuProdaju() const
    {
        return **std::min_element(_pr.begin(), _pr.end() , 
            [](const std::shared_ptr<Prodaja>& p1, const std::shared_ptr<Prodaja>& p2){
                return ProdatPrije(*p1, *p2);
        } );
    }
    
    Prodaja& DajNajSkupljuProdaju()
    {
        return (**std::max_element(_pr.begin(), _pr.end(), 
            [](const std::shared_ptr<Prodaja>& p1, const std::shared_ptr<Prodaja>& p2){
                return p1->DajCijenuStana() < p2->DajCijenuStana();
        } ));
    }
    
    Prodaja DajNajSkupljuProdaju() const
    {
        return (**std::max_element(_pr.begin(), _pr.end(), 
            [](const std::shared_ptr<Prodaja>& p1, const std::shared_ptr<Prodaja>& p2){
                return p1->DajCijenuStana() < p2->DajCijenuStana();
        } ));
    }
    
    void IsprazniKolekciju();
    void ObrisiNajRanijuProdaju()
    {
        if(_pr.size() == 0)
            throw std::range_error("Prazna kolekcija");
        auto& r = DajNajranijuProdaju();
        std::remove_if(_pr.begin(), _pr.end(), [&](const std::shared_ptr<Prodaja>& p){
            return p.get() == &r;
        } );
    }
    
    void ObrisiProdajeAgenta(const std::string& ime);
    void ObrisiProdajeNaDatum(const Datum& d);
    
    Prodaja& DajProdaju(int i)
    {
        if( i < 0 &&  i > _pr.size())
            throw std::domain_error("Pogresan parametar"); 
        return *_pr[i];
    }
    
    
    void IspisiProdajuNaDatum(const Datum& d) const;
    
    void IspisiSveProdaje() const;
    
};

void Prodaje::IspisiSveProdaje() const
{
    std::for_each(_pr.begin(), _pr.end(), [] (const std::shared_ptr<Prodaja>& p){
       p->Ispisi();
       std::cout << '\n';
    });
}

void Prodaje::IspisiProdajuNaDatum(const Datum& d) const
{
    std::for_each(_pr.begin(), _pr.end(), [&] (const std::shared_ptr<Prodaja>& p){
       const auto& da = p->DajDatumProdaje();
       if(da.DajDan() == d.DajDan() && da.DajMjesec() == d.DajMjesec() 
            && da.DajGodinu() == d.DajGodinu())
       {
           p->Ispisi();
           std::cout << '\n';
       }
    });
}

void Prodaje::ObrisiProdajeNaDatum(const Datum& d)
{
    auto it = std::remove_if(_pr.begin(), _pr.end(), [&] (const std::shared_ptr<Prodaja>& p){
       const auto& da = p->DajDatumProdaje();
       if(da.DajDan() == d.DajDan() && da.DajMjesec() == d.DajMjesec() 
            && da.DajGodinu() == d.DajGodinu())
           return true;
       return false;
    });
    _pr.resize(it - _pr.begin());
}

void Prodaje::ObrisiProdajeAgenta(const std::string& ime)
{
    auto it = std::remove_if(_pr.begin(), _pr.end(), [&] (const std::shared_ptr<Prodaja>& p){
       return p->DajImeAgenta() == ime;
    });
    _pr.resize(it - _pr.begin());
}

void Prodaje::IsprazniKolekciju()
{
    _pr.clear();
}

int Prodaje::DajBrojProdajaNaDatum(const Datum& d) const
{
    return std::count_if(_pr.begin(), _pr.end(), [&](const std::shared_ptr<Prodaja>& p) {
        return d.DajDan() == p->DajDatumProdaje().DajDan() && d.DajMjesec() == p->DajDatumProdaje().DajMjesec() &&
            d.DajGodinu() == p->DajDatumProdaje().DajGodinu();
    });
}

Prodaje& Prodaje::operator= (Prodaje&& p)
{
    if(&p == this)
        return *this;
    
    _pr = std::move(p._pr);
    
    p._pr.resize(0);

    return *this;
}

Prodaje& Prodaje::operator= (const Prodaje& p)
{
    if(&p == this)
        return *this;
        
    _pr.resize(0);
    _pr.reserve(p._pr.size());
    for(const auto& elem : p._pr)
        _pr.emplace_back(std::make_shared<Prodaja>(*elem) );
            
    return *this;
}



Prodaje::Prodaje(std::initializer_list<Prodaja> p)
{
    _pr.reserve(p.size());
    for(const auto& elem : p)
        _pr.emplace_back(std::make_shared<Prodaja>(elem) );
}

int main ()
{
 	return 0;
}