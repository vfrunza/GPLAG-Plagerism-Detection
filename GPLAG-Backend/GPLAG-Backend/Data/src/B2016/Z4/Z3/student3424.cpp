/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <new>
#include <algorithm>

class Datum
{
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina)
    {
        if(dan <= 0 || dan > 31 || mjesec <= 0 || mjesec > 12 || godina < 0) throw std::domain_error("Neispravan datum");
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    }
    void Postavi(int dan, int mjesec, int godina)
    {
        if(dan <= 0 || dan > 31 || mjesec <= 0 || mjesec > 12 || godina < 0) throw std::domain_error("Neispravan datum");
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    }
    
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    
    void Ispisi() const { std::cout << dan << "/" << mjesec << "/" << godina; }
};

class Kupac
{
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    static bool Provera(const std::string &s);
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    
    std::string DajImePrezime() const { return ime_i_prezime; }
    Datum DajDatumRodjenja() const { return datum_rodjenja; }
    
    void Ispisi() const 
    {
        std::cout << ime_i_prezime << " ("; datum_rodjenja.Ispisi(); std::cout << ")";
    }
};

bool Kupac::Provera(const std::string &s)
{
    for(int i(0); i < s.length(); i++)
    {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || 
           (s[i] >= '0' && s[i] <= '9') || s[i] == ' ' || s[i] == '-' || s[i] == char(39)) continue;
        else return false;
    }
    return true;
}

Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) 
            : ime_i_prezime(ime_i_prezime), 
              datum_rodjenja(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu())
{
    if(Provera(ime_i_prezime) == false)
      throw std::domain_error("Neispravno ime i prezime");
}

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
{
    if(Provera(ime_i_prezime) == false)
      throw std::domain_error("Neispravno ime i prezime");
    
    try
    {
        Kupac::datum_rodjenja.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
    }
    catch(...)
    {
        throw;
    }
}

class Stan
{
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return broj_soba; }
    bool DajNamjesten() const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    
    void Ispisi() const;
};

Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
          : adresa(adresa), sprat(sprat), broj_soba(broj_soba), namjesten(namjesten), kvadratura(kvadratura)
{
    if(sprat < 0 || broj_soba < 0 || kvadratura < 0)
      throw std::domain_error("Neispravan unos podataka");
}

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{
    if(sprat < 0 || broj_soba < 0 || kvadratura < 0)
      throw std::domain_error("Neispravan unos podataka");
    
    Stan::adresa = adresa;
    Stan::sprat = sprat;
    Stan::broj_soba = broj_soba;
    Stan::namjesten = namjesten;
    Stan::kvadratura = kvadratura;
}

void Stan::Ispisi() const
{
    std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba;
    if(broj_soba < 5) std::cout << " sobe." << std::endl;
    else std::cout << " soba." << std::endl;
    std::cout << "Kvadratura stana je " << kvadratura << " (m^2) i stan ";
    if(namjesten) std::cout << "je namjesten.";
    else std::cout << "nije namjesten.";
}

class Prodaja
{
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
public:
    
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
            std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba,
            bool namjesten_stan, double broj_kvadrata);
    
    void PromijeniKupca(const Kupac &novi_kupac); 
    void PromijeniStan(const Stan &novi_stan);
    void PromijeniDatumKupovine(const Datum &novi_datum);
    void PromijeniCijenuProdaje(const double &nova_cijena);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    
    std::string DajImeAgenta() const { return ime_agenta_prodaje; }
    std::string DajImeKupca() const { return kupac_stana.DajImePrezime(); }
    Datum DajDatumProdaje() const { return datum_prodaje; }
    double DajCijenuStana() const  { return cijena_stana; }
    
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) { return p1.DajCijenuStana() < p2.DajCijenuStana(); }
    
    void Ispisi() const;
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, 
                 const Stan &kupljeni_stan)
: ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana),
  datum_prodaje(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje. DajGodinu()),
  kupac_stana(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja()),
  kupljeni_stan(kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(), 
                kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu()) {}
                                
                                
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
                 std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba,
                 bool namjesten_stan, double broj_kvadrata)
: ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje),
  kupac_stana(ime_kupca, datum_rodjenja_kupca), kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {}
  
void Prodaja::PromijeniKupca(const Kupac &novi_kupac)
{
    try
    {
        kupac_stana.Postavi(novi_kupac.DajImePrezime(), novi_kupac.DajDatumRodjenja());
    }
    catch(...)
    {
        throw;
    }
}

void Prodaja::PromijeniStan(const Stan &novi_stan)
{
    try
    {
        kupljeni_stan.Postavi(novi_stan.DajAdresu(), novi_stan.DajSprat(), novi_stan.DajBrojSoba(), novi_stan.DajNamjesten(), novi_stan.DajKvadraturu());
    }
    catch(...)
    {
        throw;
    }
    
}

void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum)
{
    try
    {
        datum_prodaje.Postavi(novi_datum.DajDan(), novi_datum.DajMjesec(), novi_datum.DajGodinu());
    }
    catch(...)
    {
        throw;
    }
}

void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena)
{
    cijena_stana = nova_cijena;
}

void Prodaja::PomjeriDanUnaprijed()
{
    int d(datum_prodaje.DajDan() + 1), m(datum_prodaje.DajMjesec()), g(datum_prodaje.DajGodinu());
    
    if(d > 31)
    {
        d = 1;
        m++;
        
        if(m > 12)
        {
            m = 1;
            g++;
        }
    }
    datum_prodaje.Postavi(d, m, g);
}

void Prodaja::PomjeriDanUnazad()
{
    int d(datum_prodaje.DajDan() - 1), m(datum_prodaje.DajMjesec()), g(datum_prodaje.DajGodinu());
    
    if(d < 1)
    {
        d = 31;
        m--;
        
        if(m < 1)
        {
            m = 12;
            g--;
        }
    }
    datum_prodaje.Postavi(d, m, g);
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.datum_prodaje.DajGodinu() == p2.datum_prodaje.DajGodinu())
    {
        if(p1.datum_prodaje.DajMjesec() == p2.datum_prodaje.DajMjesec())
        {
            return p1.datum_prodaje.DajDan() < p2.datum_prodaje.DajDan();
        }
        return p1.datum_prodaje.DajMjesec() < p2.datum_prodaje.DajMjesec();
    }
    return p1.datum_prodaje.DajGodinu() < p2.datum_prodaje.DajGodinu();
}

void Prodaja::Ispisi() const
{
    std::cout << std::setw(30) << std::left << "Ime agenta:" << ime_agenta_prodaje << std::endl;
    std::cout << std::setw(30) << std::left << "Ime kupca:"; kupac_stana.Ispisi(); std::cout << std::endl;
    std::cout << std::setw(30) << std::left << "Zakazani datum prodaje:"; datum_prodaje.Ispisi(); std::cout << std::endl;
    std::cout << std::setw(30) << std::left << "Cijena stana:" << cijena_stana << std::endl;
    std::cout << "Informacije o stanu:" << std::endl;
    kupljeni_stan.Ispisi();
}

class Prodaje
{
    Prodaja **niz = nullptr;
    int broj_prodaja;
    const int max_broj_prodaja;
    
    void AlocirajNiz(int vel);
    void DealocirajNiz();
    bool Kriterij(Prodaja *p1, Prodaja *p2);
public:
    explicit Prodaje(int max_broj_prodaja) : broj_prodaja(0), max_broj_prodaja(max_broj_prodaja)
    {
        AlocirajNiz(max_broj_prodaja);
    }
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje); 
    
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, 
                            const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, 
                            int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, 
                            const std::string &adresa_stana, int sprat_stana, int broj_soba, 
                            bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    
    int DajBrojProdaja() const { return broj_prodaja; }
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);

    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
};

void Prodaje::AlocirajNiz(int vel)
{
    try
    {
        niz = new Prodaja*[vel]{};
    }
    catch(...)
    {
        throw;
    }
}

void Prodaje::DealocirajNiz()
{
    if(niz == nullptr) return;
    for(int i(0); i < broj_prodaja; i++) delete niz[i];
    delete[] niz;
}

/*Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : broj_prodaja(0), max_broj_prodaja(spisak_prodaja.size()) 
{
    AlocirajNiz(broj_prodaja);
    
    for(const auto &x : spisak_prodaja)
    {
        try
        {
            niz[broj_prodaja++] = new Prodaja(spisak_prodaja.DajImeAgenta(), spisak_prodaja.DajCijenuStana(), spisak_prodaja.)
        }
        catch(...)
        {
            DealocirajNiz();
            throw;
        }
    }
}*/

Prodaje::~Prodaje()
{
    DealocirajNiz();
}

/*Prodaje::Prodaje(const Prodaje &prodaje) : broj_prodaja(prodaje.broj_prodaja), max_broj_prodaja(prodaje.max_broj_prodaja)
{
    AlocirajNiz(broj_prodaja);
    try
    {
        for(int i(0); i < broj_prodaja; i++)
        {
            niz[i] = new Prodaja();
        }
    }
    catch(...)
    {
        DealocirajNiz();
        throw;
    }
}*/

Prodaje::Prodaje(Prodaje &&prodaje) : broj_prodaja(prodaje.broj_prodaja), max_broj_prodaja(prodaje.max_broj_prodaja)
{
    niz = prodaje.niz;
    prodaje.niz = nullptr;
}

/*Prodaje &Prodaje::operator =(const Prodaje &prodaje)
{
    if(broj_prodaja < prodaje.broj_prodaja)
    {
        this->DealocirajNiz();
        Alocira
    }
}*/

Prodaje &Prodaje::operator =(Prodaje &&prodaje)
{
    if(&prodaje == this) return *this;
    
    niz = prodaje.niz;
    broj_prodaja = prodaje.broj_prodaja;
    prodaje.niz = nullptr;
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, 
                                 const Kupac &kupac_stana, const Stan &kupljeni_stan)
{
    if(broj_prodaja == max_broj_prodaja)
      throw std::range_error("Dostignut maksimalni broj prodaja");
    
    try
    {
        niz[broj_prodaja++] = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
    }
    catch(...)
    {
        throw;
    }
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, 
                                 int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, 
                                 const std::string &adresa_stana, int sprat_stana, int broj_soba, 
                                 bool namjesten_stan, double broj_kvadrata)
{
    if(broj_prodaja == max_broj_prodaja)
      throw std::range_error("Dostignut maksimalni broj prodaja");
    
    try
    {
        niz[broj_prodaja++] = new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje,
                                          ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten, broj_kvadrata);
    }
    catch(...)
    {
        throw;
    }
}

/*void Prodaje::RegistrirajProdaju(Prodaja *p)
{
    if(broj_prodaja == max_broj_prodaja)
      throw std::range_error("Dostignut maksimalni broj prodaja");
    
    try
    {
        niz[broj_prodaja++] = new Prodaja(p->DajImeAgenta(), p->DajCijenuStana(), p->DajDatumProdaje(), p->Daj, p->kupljeni_stan);
    }
    catch(...)
    {
        throw;
    }
}*/

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const
{
    return std::count_if(niz, niz + broj_prodaja, [datum](Prodaja *p)
                                                  {
                                                     return (datum.DajDan() == p->DajDatumProdaje().DajDan() &&
                                                             datum.DajMjesec() == p->DajDatumProdaje().DajMjesec() &&
                                                             datum.DajGodinu() == p->DajDatumProdaje().DajGodinu()); 
                                                   });
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const
{
    return std::count_if(niz, niz + broj_prodaja, [ime_agenta](Prodaja *p){return ime_agenta == p->DajImeAgenta();});
}

Prodaja &Prodaje::DajNajranijuProdaju()
{
    if(broj_prodaja == 0)
      throw std::domain_error("Nema registriranih prodaja");
    
    Prodaja *p(std::min_element(*niz, *niz + broj_prodaja, [](Prodaja *p1, Prodaja *p2)
                                                     {
                                                         int d1(p1->DajDatumProdaje().DajDan()), m1(p1->DajDatumProdaje().DajMjesec()), g1(p1->DajDatumProdaje().DajGodinu());
                                                         int d2(p2->DajDatumProdaje().DajDan()), m2(p2->DajDatumProdaje().DajMjesec()), g2(p2->DajDatumProdaje().DajGodinu());
                                                         if(g1 == g2)
                                                         {
                                                             if(m1 == m2)
                                                             {
                                                                 return d1 < d2;
                                                             }
                                                             return m1 < m2;
                                                         }
                                                         return g1 < g2;
                                                     }));
    return *p;
}

Prodaja Prodaje::DajNajranijuProdaju() const
{
    if(broj_prodaja == 0)
      throw std::domain_error("Nema registriranih prodaja");
    
    return *(std::min_element(*niz, *niz + broj_prodaja, [](Prodaja *p1, Prodaja *p2)
                                                     {
                                                         int d1(p1->DajDatumProdaje().DajDan()), m1(p1->DajDatumProdaje().DajMjesec()), g1(p1->DajDatumProdaje().DajGodinu());
                                                         int d2(p2->DajDatumProdaje().DajDan()), m2(p2->DajDatumProdaje().DajMjesec()), g2(p2->DajDatumProdaje().DajGodinu());
                                                         if(g1 == g2)
                                                         {
                                                             if(m1 == m2)
                                                             {
                                                                 return d1 < d2;
                                                             }
                                                             return m1 < m2;
                                                         }
                                                         return g1 < g2;
                                                     }));
}

Prodaja &Prodaje::DajNajskupljuProdaju()
{
    if(broj_prodaja == 0)
      throw std::domain_error("Nema registriranih prodaja");
    
    Prodaja *p(std::max_element(*niz, *niz + broj_prodaja, [](Prodaja *p1, Prodaja *p2)
                                                     {
                                                         int d1(p1->DajDatumProdaje().DajDan()), m1(p1->DajDatumProdaje().DajMjesec()), g1(p1->DajDatumProdaje().DajGodinu());
                                                         int d2(p2->DajDatumProdaje().DajDan()), m2(p2->DajDatumProdaje().DajMjesec()), g2(p2->DajDatumProdaje().DajGodinu());
                                                         if(g1 == g2)
                                                         {
                                                             if(m1 == m2)
                                                             {
                                                                 return d1 > d2;
                                                             }
                                                             return m1 > m2;
                                                         }
                                                         return g1 > g2;
                                                     }));
    return *p;
}

Prodaja Prodaje::DajNajskupljuProdaju() const
{ 
    if(broj_prodaja == 0)
      throw std::domain_error("Nema registriranih prodaja");
    
    return *std::max_element(*niz, *niz + broj_prodaja, [](Prodaja *p1, Prodaja *p2)
                                                     {
                                                         int d1(p1->DajDatumProdaje().DajDan()), m1(p1->DajDatumProdaje().DajMjesec()), g1(p1->DajDatumProdaje().DajGodinu());
                                                         int d2(p2->DajDatumProdaje().DajDan()), m2(p2->DajDatumProdaje().DajMjesec()), g2(p2->DajDatumProdaje().DajGodinu());
                                                         if(g1 == g2)
                                                         {
                                                             if(m1 == m2)
                                                             {
                                                                 return d1 > d2;
                                                             }
                                                             return m1 > m2;
                                                         }
                                                         return g1 > g2;
                                                     });
}    

void Prodaje::IsprazniKolekciju()
{
    for(int i(0); i < broj_prodaja; i++)
    {
        delete niz[i];
        niz[i] = nullptr;
    }
}

void Prodaje::ObrisiNajranijuProdaju()
{
    if(broj_prodaja == 0)
      throw std::range_error("Prazna kolekcija");
    
    *Prodaj x(DajNajranijuProdaju());
    delete x;
    x = nullptr;
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta)
{
    for(int i(0); i < broj_prodaja; i++)
    {
        if(niz[i]->DajImeAgenta() == ime_agenta)
        {
            delete niz[i];
            niz[i] = nullptr;
        }
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum)
{
    for(int i(0); i < broj_prodaja; i++)
    {
        if(datum.DajDan() == niz[i]->DajDatumProdaje().DajDan() && datum.DajMjesec() == niz[i]->DajDatumProdaje().DajMjesec() &&
           datum.DajGodinu() == niz[i]->DajDatumProdaje().DajGodinu())
        {
            delete niz[i];
            niz[i] = nullptr;
        }
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const
{
    
}

void Prodaje::IspisiSveProdaje() const
{

}


int main ()
{
    /*Prodaje prodaje(20);
    std::cout << "Dobrodosli!" << std::endl;
    
    for(;;)
    {
        int opcija;
        std::cout << "Izaberite opciju:" << std::endl
                  << " 0 - kraj\n" 
                  << " 1 - uredjivanje stanova\n"
                  << " 2 - uredjivanje kupaca\n"
                  << " 3 - uredjivanje prodaja" << std::endl;
        
        std::cin >> opcija;
        
        if(opcija == 0) break;
        
        else if(opcija == 1)
        {
            for(;;)
            {
                std::cout << "Izaberite opciju:" << std::endl
                  << " 0 - nazad\n" 
                  << " 1 - dodavanje stana\n"
                  << " 2 - uredjivanje stanova\n"
                  << " 3 - ispis svih stanova\n"
                  << " 4 - kraj" << std::endl;
            
                std::cin >> opcija;
                
                if(opcija == 0) break;
                else if(opcija == 1)
                {
                    for(int i(0); i < 1; i++)
                    {
                        try
                        {
                            std::cin.ignore(10000, '\n');
                            
                            std::string adresa;
                            std::cout << "Unesite adresu: ";
                            std::getline(std::cin, adresa);
                            
                            int sprat;
                            std::cout << "Unesite sprat: ";
                            std::cin >> sprat;
                            
                            int broj_soba;
                            std::cout << "Unesite broj soba: ";
                            std::cin >> broj_soba;
                            
                            bool namjesten;
                            std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                            std::cin >> namjesten;
                            
                            double kvadratura;
                            std::cout << "Unesite kvadraturu: ";
                            std::cin >> kvadratura;
                            
                            //prodaje.
                        }
                        catch(const std::exception &e)
                        {
                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.";
                            i--;
                        }
                        std::cout << "Stan je uspjesno dodan!" << std::endl;
                    }
                }
                else if(opcija == 2)
                {
                    std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                    //ispis svihh stanova po rednim broju
                    std::cin >> opcija;
                    
                    std::cout << "Odaberite polje koje zelite urediti:" << std::endl
                              << " 0 - ";
                }
                else if(opcija == 3)
                {
                    //ispis svih stanova
                }
                else if(opcija == 4) return 0;
            }
            
            
        }
        else if(opcija == 2) {}
        else if(opcija == 3) {}
    }*/
	return 0;
}