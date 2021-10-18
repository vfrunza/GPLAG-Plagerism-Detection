/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!

#include <iostream>
#include <stdexcept>
#include <cctype>
#include <string>
#include <algorithm>
#include <iomanip>

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
            << " (m^2) i stan " << (_namjesten ? "je" : "nije" ) << " namjesten.\n";
        
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
    std::cout << std::setw(32) << std::left << "Ime agenta: " << _ime_agenta << "\n";
    std::cout << std::setw(32) << std::left << "Ime kupca: " << _kupac.DajImeIPrezime() << " (";
    _kupac.DajDatumRodjenja().Ispisi();
    std::cout << ")\n";
    std::cout << std::setw(32) << std::left << "Zakazani datum prodaje: ";
    _datum.Ispisi();
    std::cout << "\nInforamcije o stanu:\n";
    _stan.Ispisi();
}


class Prodaje
{
    Prodaja** _pr = nullptr;
    int _broj_pr, _max;
    void alociraj_i_kopiraj(const Prodaje& p, bool treba = false);
    void oslobodi_memoriju();
public:
    explicit Prodaje(int max);
    Prodaje(std::initializer_list<Prodaja> sp);
    Prodaje(const Prodaje& p) : _broj_pr(p._broj_pr), _max(p._max)
    {
        alociraj_i_kopiraj(p);
    }
    
    Prodaje(Prodaje&& p) : _pr(p._pr), _broj_pr(p._broj_pr), _max(p._max)
    {
        p._pr = nullptr;
        p._broj_pr = 0;
        p._max = 0;
    }
    
    Prodaje& operator= (const Prodaje& p);
    Prodaje& operator= (Prodaje&& p);
    
    ~Prodaje()
    {
        oslobodi_memoriju();
    }
    
    void RegistrirajProdaju(const std::string ia, double cs, const Datum& d, const Kupac& k, const Stan& s)
    {
        if(_broj_pr == _max)
            throw std::range_error("Dostignut maksimalan broj prodaja");
        _pr[_broj_pr++] = new Prodaja(ia, cs, d, k, s);
    }
    
    void RegistrirajProdaju(const std::string ia, double cs, 
        int d, int m, int g, 
        const std::string ime, const Datum& d_kupca, 
        const std::string& adresa, int ss, int bs, bool n, double k) 
    {
        if(_broj_pr == _max)
            throw std::range_error("Dostignut maksimalan broj prodaja");
        _pr[_broj_pr++] = new Prodaja(ia, cs, {d, m, g}, {ime, d_kupca}, {adresa, ss, bs, n, k});
    }
    
    void RegistrirajProdaju(Prodaja* p)
    {
        if(_broj_pr == _max)
            throw std::range_error("Dostignut maksimalan broj prodaja");
        _pr[_broj_pr++] = p;
    }
    
    int DajBrojProdaja() const
    {
        return _broj_pr;
    }
    
    int DajBrojProdajaNaDatum(const Datum& d) const;
    int DajBrojProdajaOdAgenta(const std::string& s)const
    {
        return std::count_if(_pr, _pr + _broj_pr, [&](Prodaja* p) {
        return s == p->DajImeAgenta();
        });
    }
    
    Prodaja& DajNajranijuProdaju()
    {
        return **std::min_element(_pr, _pr + _broj_pr, [](Prodaja* p1, Prodaja* p2){
            return ProdatPrije(*p1, *p2);
        } );
    }
    
    Prodaja DajNajranijuProdaju() const
    {
        return **std::min_element(_pr, _pr + _broj_pr, [](Prodaja* p1, Prodaja* p2){
            return ProdatPrije(*p1, *p2);
        } );
    }
    
    Prodaja& DajNajSkupljuProdaju()
    {
        return (**std::max_element(_pr, _pr + _broj_pr, [](Prodaja* p1, Prodaja* p2){
            return p1->DajCijenuStana() < p2->DajCijenuStana();
        } ));
    }
    
    Prodaja DajNajSkupljuProdaju() const
    {
        return (**std::max_element(_pr, _pr + _broj_pr, [](Prodaja* p1, Prodaja* p2){
            return p1->DajCijenuStana() < p2->DajCijenuStana();
        } ));
    }
    
    void IsprazniKolekciju();
    void ObrisiNajRanijuProdaju()
    {
        if(_broj_pr == 0)
            throw std::range_error("Prazna kolekcija");
        auto& r = DajNajranijuProdaju();
        std::remove(_pr, _pr + _broj_pr, &r);
        delete &r;
        --_broj_pr;
    }
    
    void ObrisiProdajeAgenta(const std::string& ime);
    void ObrisiProdajeNaDatum(const Datum& d);
    
    Prodaja& DajProdaju(int i)
    {
        if( i < 0 &&  i > _broj_pr)
            throw std::domain_error("Pogresan parametar"); 
        return *_pr[i];
    }
    
    
    void IspisiProdajuNaDatum(const Datum& d) const;
    
    void IspisiSveProdaje() const;
    
};

void Prodaje::IspisiSveProdaje() const
{
    std::for_each(_pr, _pr + _broj_pr, [] (Prodaja* p){
       p->Ispisi();
       std::cout << '\n';
    });
}

void Prodaje::IspisiProdajuNaDatum(const Datum& d) const
{
    std::for_each(_pr, _pr + _broj_pr, [&] (Prodaja* p){
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
    int brojac = 0;
    std::remove_if(_pr, _pr + _broj_pr, [&] (Prodaja* p){
       const auto& da = p->DajDatumProdaje();
       if(da.DajDan() == d.DajDan() && da.DajMjesec() == d.DajMjesec() 
            && da.DajGodinu() == d.DajGodinu())
       {
           ++brojac;
           delete p;
           return true;
       }
       return false;
    });
    _broj_pr -= brojac;
}

void Prodaje::ObrisiProdajeAgenta(const std::string& ime)
{
    int brojac = 0;
    std::remove_if(_pr, _pr + _broj_pr, [&] (Prodaja* p){
       if(p->DajImeAgenta() == ime){
           ++brojac;
           delete p;
           return true;
       }
       return false;
    });
    _broj_pr -= brojac;
}

void Prodaje::IsprazniKolekciju()
{
    for(int i = 0; i < _broj_pr; ++i)
        delete _pr[i];
    std::fill(_pr, _pr + _broj_pr, nullptr);
    _broj_pr = 0;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum& d) const
{
    return std::count_if(_pr, _pr + _broj_pr, [&](Prodaja* p) {
        return d.DajDan() == p->DajDatumProdaje().DajDan() && d.DajMjesec() == p->DajDatumProdaje().DajMjesec() &&
            d.DajGodinu() == p->DajDatumProdaje().DajGodinu();
    });
}

Prodaje& Prodaje::operator= (Prodaje&& p)
{
    if(&p == this)
        return *this;
    oslobodi_memoriju();
    _pr = p._pr;
    p._pr = nullptr;
    _broj_pr = p._broj_pr;
    p._broj_pr = 0;
    _max = p._max;
    p._max = 0;
    return *this;
}

Prodaje& Prodaje::operator= (const Prodaje& p)
{
    if(&p == this)
        return *this;
    try {
        oslobodi_memoriju();
        alociraj_i_kopiraj(p);
    }
    catch (...) {
        oslobodi_memoriju();
    }
    return *this;
}

void Prodaje::oslobodi_memoriju()
{
    if(_pr == nullptr)
        return;
    for(int i = 0; i < _broj_pr; ++i)
        delete _pr[i];
    delete [] _pr;
    _pr = nullptr;
}

void Prodaje::alociraj_i_kopiraj(const Prodaje& p, bool treba)
{
    try
    {
        if(!treba)
            _pr = new Prodaja*[p._max];
        for(int i = 0; i < p._broj_pr; ++i)
            _pr[i] = new Prodaja (*p._pr[i]);
        _max = p._max;
        _broj_pr = p._broj_pr;
    }catch(std::bad_alloc)
    {
        oslobodi_memoriju();
        throw;
    }
}

Prodaje::Prodaje(int max) : _broj_pr(0), _max(max)
{
    if(max < 0)
        throw std::range_error("MEMEME");
    _pr = new Prodaja* [max];
}

Prodaje::Prodaje(std::initializer_list<Prodaja> sp) : _broj_pr(sp.size()), _max(_broj_pr)
{
    try
    {
        _pr = new Prodaja* [_max]{};
        auto it = sp.begin();
        for(int i = 0; i < _max; ++i, ++it)
            _pr[i] = new Prodaja(*it);
    }catch(...)
    {
        oslobodi_memoriju();
        throw;
    }
}


int uredjivanje_stana(std::vector<Stan>& vs)
{
    for(;;)
    {
        std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - dodavanje stana\n 2 - uredjivanje stanova";
        std::cout << "\n 3 - ispisi svih stanova\n 4 - kraj\n";    
        int opcija;
        std::cin >> opcija;
        if( opcija == 0 )
            return 0;
        if(opcija == 4)
            return 4;
        if(opcija == 1)
        {
            UNOS_STANA:
            std::string adresa;
            std::cout << "Unesite adresu: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, adresa);
            std::cin.ignore(10000, '\n');
            std::cout << "Unesite sprat: ";
            int s;
            std::cin >> s;
            std::cout << "Unesite broj soba: ";
            int bs;
            std::cin >> bs;
            std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
            int n;
            std::cin >> n;
            if(n != 1 && n != 0)
            {
                std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n";
                continue;
            }
            std::cout << "Unesite kvadraturu: ";
            double kv;
            std::cin >> kv;
            try{
                vs.emplace_back(adresa, s, bs, n, kv);
                std::cout << "Stan je uspjesno dodan!\n";
            }catch(std::bad_alloc){
                throw;
            }
            catch(...){
                std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n";
                goto UNOS_STANA;
            }
        }
        if(opcija == 3)
        {
            int i = 0;
            for(const auto& s : vs)
            {
                std::cout << i << ". ";
                s.Ispisi();
                ++i;
            }
            continue;
        }
        if(opcija == 2)
        {
            std::cout << "Odaberite stan. Dostupni stanovi su:\n";
            int i = 0;
            for(const auto& s : vs)
            {
                std::cout << ' ' << i << " - ";
                s.Ispisi();
                ++i;
            }
            int br_stana;
            std::cin >> br_stana;
            std::cout << "Odaberite polje koje zelite izmijeniti:\n";
            std::cout << " 0 - nazad\n 1 - adresa\n 2 - sprat\n 3 - broj soba\n";
            std::cout << " 4 - da li je stan namjesten\n 5 - kvadratura\n - 6 sve\n";
            auto &st = vs[br_stana - 1];
            int opcija_stana;
            std::cin >> opcija_stana;
            if(opcija_stana == 1)
            {
                UNOS_ADRESE:
                std::string adresa;
                std::cout << "Unesite adresu: ";
                std::cin.ignore(10000, '\n');
                std::getline(std::cin, adresa);
                std::cin.ignore(10000, '\n');
                auto &st = vs[br_stana - 1];
                try {
                    st = Stan(adresa, st.DajSprat(), st.DajBrojSoba(), st.DajNamjesten(), st.DajKvadraturu()); 
                    std::cout << "Stan je uspjesno izmijenjen!\n";
                }
                catch(std::bad_alloc)
                {
                    throw;
                }
                catch (...) {
                    std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n";
                    goto UNOS_ADRESE;
                }
            }
            
            if(opcija_stana == 2)
            {
                UNOS_SPRATA:
                std::cout << "Unesite sprat: ";
                int sprat;
                std::cin >> sprat;
                try {
                    st = Stan(st.DajAdresu(), sprat, st.DajBrojSoba(), st.DajNamjesten(), st.DajKvadraturu());
                    std::cout << "Stan je uspjesno izmijenjen!\n";
                }
                catch(std::bad_alloc)
                {
                    throw;
                }
                catch (...) {
                    std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n";
                    goto UNOS_SPRATA;
                }
            }
            
            if(opcija_stana == 3)
            {
                UNOS_SOBA:
                std::cout << "Unesite broj soba: ";
                int bs;
                std::cin >> bs;
                try {
                    st = Stan(st.DajAdresu(), st.DajSprat(), bs, st.DajNamjesten(), st.DajKvadraturu());
                    std::cout << "Stan je uspjesno izmijenjen!\n";
                }
                catch(std::bad_alloc)
                {
                    throw;
                }
                catch (...) {
                    std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n";
                    goto UNOS_SOBA;
                }
            }
            
            if(opcija_stana == 4)
            {
                UNOS_NAMJESTEN:
                std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                int n;
                std::cin >> n;
                if(n != 1 && n != 0)
                {
                    std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n";
                    goto UNOS_NAMJESTEN;
                }
                try {
                    st = Stan(st.DajAdresu(), st.DajSprat(), st.DajBrojSoba(), n, st.DajKvadraturu());
                    std::cout << "Stan je uspjesno izmijenjen!\n";
                }
                catch(std::bad_alloc)
                {
                    throw;
                }
                catch (...) {
                    std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n";
                    goto UNOS_SPRATA;
                }
            }
            
            if(opcija_stana == 5)
            {
                UNOS_KVADRATURE:
                std::cout << "Unesite kvadraturu: ";
                double kv;
                std::cin >> kv;
                try {
                    st = Stan(st.DajAdresu(), st.DajSprat(), st.DajBrojSoba(), st.DajNamjesten(), kv);
                    std::cout << "Stan je uspjesno izmijenjen!\n";
                }
                catch(std::bad_alloc)
                {
                    throw;
                }
                catch (...) {
                    std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n";
                    goto UNOS_KVADRATURE;
                }
            }
            if(opcija_stana == 6)
            {
                UNOS_STANA_P:
                std::string adresa;
                std::cout << "Unesite adresu: ";
                std::cin.ignore(10000, '\n');
                std::getline(std::cin, adresa);
                std::cin.ignore(10000, '\n');
                std::cout << "Unesite sprat: ";
                int s;
                std::cin >> s;
                std::cout << "Unesite broj soba: ";
                int bs;
                std::cin >> bs;
                std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                int n;
                std::cin >> n;
                if(n != 1 && n != 0)
                {
                    std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n";
                    continue;
                }
                std::cout << "Unesite kvadraturu: ";
                double kv;
                std::cin >> kv;
                
                try {
                    st = Stan(adresa, s, bs, n, kv);
                    std::cout << "Stan je uspjesno izmijenjen!\n";
                }
                catch(std::bad_alloc)
                {
                    throw;
                }
                catch (...) {
                    std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n";
                    goto UNOS_STANA_P;
                }
            }
                
        }
    } // kraj beskonacne petlje
}

int uredjivanje_kupaca(std::vector<Kupac>& vk)
{
    for(;;)
    {
        std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - dodavanje kupca\n";
        std::cout << " 2 - uredjivanje kupaca\n 3 - ispisi svih kupaca\n - 4 kraj\n";
        int opcija;
        std::cin >> opcija;
        if( opcija == 0 )
            return 0;
        if(opcija == 4)
            return 4;
        if(opcija == 1)
        {
            UNSO_KUPCA:
            std::cout << "Unesite ime i prezime kupca: ";
            std::cin.ignore(10000, '\n');
            std::string ime;
            std::cin.ignore(10000, '\n');
            std::cout << "Unesite datum rodjenja (formata d/m/g): ";
            char znak;
            int d, m, g;
            std::cin >> d >> znak >> m >> znak >> g;
            try {
                vk.push_back(Kupac(ime, Datum{d, m, g}));
                std::cout << "Kupac je uspjesno dodan!";
            }
            catch (std::domain_error e) {
                std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.";
                goto UNSO_KUPCA;
            }
        }
        if(opcija == 3)
        {
            for(const auto& k : vk)
            {
                k.Ispisi();
                std::cout << "\n";
            }
        }
        
        if(opcija == 2)
        {
            std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:";
            int i = 0;
            for(const auto& k : vk)
            {
                std::cout << " " << i << " - ";
                k.Ispisi();
                std::cout << "\n";
                ++i;
            }
            int br_kupca;
            std::cin >> br_kupca;
            UNSO_KUPCA_l:
            std::cout << "Unesite ime i prezime kupca: ";
            std::cin.ignore(10000, '\n');
            std::string ime;
            std::cin.ignore(10000, '\n');
            std::cout << "Unesite datum rodjenja (formata d/m/g): ";
            char znak;
            int d, m, g;
            std::cin >> d >> znak >> m >> znak >> g;
            try {
                vk[br_kupca - 1] = Kupac(ime, Datum{d, m, g});
                std::cout << "Kupac je uspjesno izmijenjen!";
            }
            catch (std::domain_error e) {
                std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.";
                goto UNSO_KUPCA_l;
            }
        }
    }
}

int uredjivanje_prodaje(Prodaja& p)
{
    Izaberite opciju:
 0 - nazad
 1 - dodavanje prodaje
 2 - uredjivanje prodaje
 3 - ispis prodaja
 4 - brisanje prodaja
 5 - kraj

    for(;;)
    {
        
    }

}

int main ()
{
    try{
        std::cout << "Dobrodosli!\n\n";
        std::vector<Stan> vs;
        std::vector<Kupac> vk;
        Prodaje p(20);
        for(;;)
        {
            std::cout << "Izaberite opciju:\n 0 - kraj\n 1 - uredjivanje stanova\n 2 - uredjivanje kupaca";
            std::cout << "\n 3 - uredjivanje prodaja\n";
            int opcija;
            std::cin >> opcija;
            if(opcija == 0)
                return 0;
            if(opcija == 1)
            {
                auto a = uredjivanje_stana(vs);
                if(a == 4)
                    return 0;
                if(a == 0)
                    continue;
            }
            if(opcija == 2)
            {
                auto a = uredjivanje_kupaca(vk);
                if(a == 4)
                    return 0;
                if(a == 0)
                    continue;
            }
            if(opcija == 3)
            {
                auto a = uredjivanje_prodaje(vk);
                if(a == 4)
                    return 0;
                if(a == 0)
                    continue;
            }
        }    
    }catch(...)
    {
        
    }
    
 	return 0;
}