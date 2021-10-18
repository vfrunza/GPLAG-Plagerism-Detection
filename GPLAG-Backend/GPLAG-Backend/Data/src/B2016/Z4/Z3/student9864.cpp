#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector>


/*Interface klasa */

class Datum
{
    int dan;
    int mjesec;
    int godina;
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const;
    int DajMjesec() const;
    int DajGodinu() const;
    void Ispisi() const;

};

class Kupac
{
    Datum datum_rodjenja;
    std::string ime_i_prezime;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const;
    Datum DajDatumRodjenja() const;
    void Ispisi() const;
};

class Stan
{
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const;
    int DajSprat() const;
    int DajBrojSoba() const;
    bool DajNamjesten() const;
    double DajKvadraturu() const;
    void Ispisi() const;
};

class Prodaja
{
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
            const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
            std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana,
            int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac);
    void PromijeniStan(const Stan &novi_stan);
    void PromijeniDatumKupovine(const Datum &novi_datum);
    void PromijeniCijenuProdaje(const double &nova_cijena);
    void PromijeniAgenta (const std::string &ime_agenta_prodaje);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const;
    std::string DajImeKupca() const;
    Datum DajDatumProdaje() const;
    double DajCijenuStana() const;
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

class Prodaje
{
    Prodaja** niz;
    int max_broj_prodaja;
    int broj_prodanih;
public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, 
        const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, 
        int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, 
        int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const;
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    Prodaja &DajProdaju (int redni_broj);
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
};


/* Implementacija metoda za klasu Datum */

Datum::Datum(int dan, int mjesec, int godina)
{
    Postavi(dan,mjesec,godina);
}

void Datum::Postavi(int dan, int mjesec, int godina)
{
    int mjeseci[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
        mjeseci[1]++;
    
    if (godina < 1)
        throw std::domain_error ("Neispravan datum");
        
    if (mjesec<1 || mjesec>12)
        throw std::domain_error ("Neispravan datum");
        
    if (dan<1 || dan>mjeseci[mjesec-1])
        throw std::domain_error ("Neispravan datum");
        
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

int Datum::DajDan() const
{
    return dan;
}

int Datum::DajMjesec() const
{
    return mjesec;
}

int Datum::DajGodinu() const
{
    return godina;
}

void Datum::Ispisi() const
{
    std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
}


/*Implementacija metoda za klasu Kupac */

Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) :
    datum_rodjenja(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu())
{
    Postavi(ime_i_prezime,datum_rodjenja);
}

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
{
    for (int i{};i<ime_i_prezime.length();i++)
        {
            bool test = false;
            if (ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z')
                test = true;
            
            if (ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z')
                test = true;
                
            if (ime_i_prezime[i] == ' ')
                test = true;
                
            if (test == false)
                throw std::domain_error ("Neispravno ime i prezime");
        }
        
    Kupac::ime_i_prezime = ime_i_prezime;
    Kupac::datum_rodjenja.Postavi(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());
}

std::string Kupac::DajImePrezime() const
{
    return ime_i_prezime;
}

Datum Kupac::DajDatumRodjenja() const
{
    return datum_rodjenja;
}

void Kupac::Ispisi() const
{
    std::cout<<ime_i_prezime<<" (";
    datum_rodjenja.Ispisi();
    std::cout<<")";
}

/* Implementacije metoda za klasu Stan */

Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{
    Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
}

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{
    if (sprat < 0 || broj_soba < 0 || kvadratura < 0)
        throw std::domain_error ("Neispravan unos podataka");
        
    Stan::adresa = adresa;
    Stan::sprat = sprat;
    Stan::broj_soba = broj_soba;
    Stan::namjesten = namjesten;
    Stan::kvadratura = kvadratura;
}

std::string Stan::DajAdresu() const
{
    return adresa;
}

int Stan::DajSprat() const
{
    return sprat;
}

int Stan::DajBrojSoba() const
{
    return broj_soba;
}

bool Stan::DajNamjesten() const
{
    return namjesten;
}

double Stan::DajKvadraturu() const
{
    return kvadratura;
}

void Stan::Ispisi() const
{
    std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" ";
    if (broj_soba == 2 || broj_soba == 3 || broj_soba == 4)
        std::cout<<"sobe.";
    else
        std::cout<<"soba.";
        
    std::cout<<" Kvadratura stana je "<<kvadratura<<" (m^2) i stan ";
    if (namjesten == true)
        std::cout<<"je namjesten.";
    else
        std::cout<<"nije namjesten.";
}

/*Implementacije metoda za klasu Prodaja */

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
            const Stan &kupljeni_stan) : datum_prodaje(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()),
            kupac_stana(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja()),
            kupljeni_stan(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),
            kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu())
{
    for (int i{};i<ime_agenta_prodaje.length();i++)
        {
            bool test = false;
            if (ime_agenta_prodaje[i]>='A' && ime_agenta_prodaje[i]<='Z')
                test = true;
            
            if (ime_agenta_prodaje[i]>='a' && ime_agenta_prodaje[i]<='z')
                test = true;
                
            if (ime_agenta_prodaje[i] == ' ')
                test = true;
                
            if (test == false)
                throw std::domain_error ("Neispravno ime i prezime");
        }
        
    if (cijena_stana < 0)
        throw std::domain_error ("Neispravan unos podataka");
        
    Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
    Prodaja::cijena_stana = cijena_stana;
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje,
            int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
            int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) : datum_prodaje(dan_prodaje,mjesec_prodaje,
            godina_prodaje), kupac_stana(ime_kupca,datum_rodjenja_kupca), kupljeni_stan(adresa_stana,sprat_stana,broj_soba,
            namjesten_stan,broj_kvadrata)
{
    for (int i{};i<ime_agenta_prodaje.length();i++)
        {
            bool test = false;
            if (ime_agenta_prodaje[i]>='A' && ime_agenta_prodaje[i]<='Z')
                test = true;
            
            if (ime_agenta_prodaje[i]>='a' && ime_agenta_prodaje[i]<='z')
                test = true;
                
            if (ime_agenta_prodaje[i] == ' ')
                test = true;
                
            if (test == false)
                throw std::domain_error ("Neispravno ime i prezime");
        }
        
    if (cijena_stana < 0)
        throw std::domain_error ("Neispravan unos podataka");
        
    Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
    Prodaja::cijena_stana = cijena_stana;
}

void Prodaja::PromijeniKupca(const Kupac &novi_kupac)
{
    kupac_stana.Postavi(novi_kupac.DajImePrezime(),novi_kupac.DajDatumRodjenja());
}

void Prodaja::PromijeniStan(const Stan &novi_stan)
{
    kupljeni_stan.Postavi(novi_stan.DajAdresu(),novi_stan.DajSprat(),novi_stan.DajBrojSoba(),novi_stan.DajNamjesten(),
                        novi_stan.DajKvadraturu());
}

void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum)
{
    datum_prodaje.Postavi(novi_datum.DajDan(),novi_datum.DajMjesec(),novi_datum.DajGodinu());
}

void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena)
{
    if (nova_cijena < 0)
        throw std::domain_error ("Neispravan unos podataka");
        
    cijena_stana = nova_cijena;
}

void Prodaja::PromijeniAgenta (const std::string &ime_agenta_prodaje)
{
    for (int i{};i<ime_agenta_prodaje.length();i++)
        {
            bool test = false;
            if (ime_agenta_prodaje[i]>='A' && ime_agenta_prodaje[i]<='Z')
                test = true;
            
            if (ime_agenta_prodaje[i]>='a' && ime_agenta_prodaje[i]<='z')
                test = true;
                
            if (ime_agenta_prodaje[i] == ' ')
                test = true;
                
            if (test == false)
                throw std::domain_error ("Neispravno ime i prezime");
        }
        
    Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
}

void Prodaja::PomjeriDanUnaprijed()
{
    int dan = datum_prodaje.DajDan();
    int mjesec = datum_prodaje.DajMjesec();
    int godina = datum_prodaje.DajGodinu();
    
    int mjeseci[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
        mjeseci[1]++;
        
    dan++;
    if (dan > mjeseci[mjesec-1])
        {
            dan = 1;
            mjesec++;
        }
    
    if (mjesec == 13)
        {
            mjesec = 1;
            godina++;
        }
        
    datum_prodaje.Postavi(dan,mjesec,godina);
}

void Prodaja::PomjeriDanUnazad()
{
    int dan = datum_prodaje.DajDan();
    int mjesec = datum_prodaje.DajMjesec();
    int godina = datum_prodaje.DajGodinu();
    
    int mjeseci[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
        mjeseci[1]++;
        
    dan--;
    
    if (dan == 0)
        {
            if (mjesec == 1)
                dan = 31;
            else
                dan = mjeseci[mjesec-2];
                
            mjesec--;
        }
        
    if (mjesec == 0)
        {
            mjesec = 12;
            godina--;
        }
        
    datum_prodaje.Postavi(dan,mjesec,godina);
}

std::string Prodaja::DajImeAgenta() const
{
    return ime_agenta_prodaje;
}

std::string Prodaja::DajImeKupca() const
{
    return kupac_stana.DajImePrezime();
}

Datum Prodaja::DajDatumProdaje() const
{
    return datum_prodaje;
}

double Prodaja::DajCijenuStana() const
{
    return cijena_stana;
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    Datum prvi = p1.DajDatumProdaje();
    Datum drugi = p2.DajDatumProdaje();
    
    if (prvi.DajGodinu() < drugi.DajGodinu())
        return true;
    else if (prvi.DajGodinu() == drugi.DajGodinu())
        {
            if (prvi.DajMjesec() < drugi.DajMjesec())
                return true;
            else if (prvi.DajMjesec() == drugi.DajMjesec())
                {
                    if (prvi.DajDan() < drugi.DajDan())
                        return true;
                }
        }
        
    return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    if (p1.DajCijenuStana() > p2.DajCijenuStana())
        return true;
    
    return false;
}

void Prodaja::Ispisi() const
{
    int razmak = 30;
    
    std::cout<<std::left<<std::setw(razmak)<<"Ime agenta:"<<ime_agenta_prodaje<<std::endl;
    std::cout<<std::left<<std::setw(razmak)<<"Ime kupca:";
    kupac_stana.Ispisi();
    std::cout<<std::endl;
    std::cout<<std::left<<std::setw(razmak)<<"Zakazani datum prodaje:";
    datum_prodaje.Ispisi();
    std::cout<<std::endl;
    std::cout<<std::left<<std::setw(razmak)<<"Cijena stana:"<<cijena_stana<<std::endl;
    std::cout<<"Informacije o stanu:"<<std::endl;
    kupljeni_stan.Ispisi();
}


/* Implementacije metoda za klasu Prodaje */

Prodaje::Prodaje(int max_broj_prodaja) : max_broj_prodaja(max_broj_prodaja), broj_prodanih(0), niz(nullptr)
{
    try
    {
        niz = new Prodaja* [max_broj_prodaja];
        for (int i{};i<max_broj_prodaja;i++)
            niz[i] = nullptr;
    }
    catch (...)
    {
        delete [] niz;
        niz = nullptr;
        std::bad_alloc e;
        throw e;
    }
}

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : max_broj_prodaja(spisak_prodaja.size()),
                broj_prodanih(spisak_prodaja.size()), niz(nullptr)
{
    try
    {
        niz = new Prodaja* [max_broj_prodaja];
        for (int i{};i<max_broj_prodaja;i++)
            niz[i] = nullptr;
    }
    catch (...)
    {
        delete [] niz;
        niz = nullptr;
        std::bad_alloc e;
        throw e;
    }
    
    auto it = spisak_prodaja.begin();
    int i = 0;
    while(it != spisak_prodaja.end())
        {
            try
            {
                niz[i] = new Prodaja (*it);
                i++;
            }
            catch (...)
            {
                for (int i{};i<max_broj_prodaja;i++)
                    delete niz[i];
                delete [] niz;
                niz = nullptr;
                std::bad_alloc e;
                throw e;
            }
            
            
            it++;
        }
    
}

Prodaje::~Prodaje()
{
    for (int i{};i<max_broj_prodaja;i++)
        delete niz[i];
    delete [] niz;
    niz = nullptr;
}

Prodaje::Prodaje(const Prodaje &prodaje) : max_broj_prodaja(prodaje.max_broj_prodaja), broj_prodanih(prodaje.broj_prodanih),
                niz(nullptr)
{
    try
    {
        niz = new Prodaja* [max_broj_prodaja];
        for (int i{};i<max_broj_prodaja;i++)
            niz[i] = nullptr;
    }
    catch (...)
    {
        delete [] niz;
        niz = nullptr;
        std::bad_alloc e;
        throw e;
    }
    
    try
    {
        for (int i{};i<broj_prodanih;i++)
            {
                Prodaja* pomocni = prodaje.niz[i];
                niz[i] = new Prodaja (*pomocni);
            }
    }
    catch(...)
    {
        for (int i{};i<max_broj_prodaja;i++)
            delete niz[i];
        delete [] niz;
        niz = nullptr;
        std::bad_alloc e;
        throw e;
    }
}

Prodaje::Prodaje(Prodaje &&prodaje) : max_broj_prodaja(max_broj_prodaja), broj_prodanih(broj_prodanih), niz(nullptr)
{
    niz = prodaje.niz;
    prodaje.niz = nullptr;
    prodaje.broj_prodanih = 0;
    prodaje.max_broj_prodaja = 0;
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje)
{
    if (&prodaje == this)
        return *this;
        
    for (int i{};i<max_broj_prodaja;i++)
        delete niz[i];
    delete [] niz;
    niz = nullptr;
    
    max_broj_prodaja = prodaje.max_broj_prodaja;
    broj_prodanih = prodaje.broj_prodanih;
    
    try
    {
        niz = new Prodaja* [max_broj_prodaja];
        for (int i{};i<max_broj_prodaja;i++)
            niz[i] = nullptr;
    }
    catch (...)
    {
        delete [] niz;
        niz = nullptr;
        std::bad_alloc e;
        throw e;
    }
    
    try
    {
        for (int i{};i<broj_prodanih;i++)
            {
                Prodaja* pomocni = prodaje.niz[i];
                niz[i] = new Prodaja (*pomocni);
            }
    }
    catch(...)
    {
        for (int i{};i<max_broj_prodaja;i++)
            delete niz[i];
        delete [] niz;
        niz = nullptr;
        std::bad_alloc e;
        throw e;
    }
    
    return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&prodaje)
{
    if (&prodaje == this)
        return *this;
        
    for (int i{};i<max_broj_prodaja;i++)
        delete niz[i];
    delete [] niz;
    niz = nullptr;
    
    broj_prodanih = prodaje.broj_prodanih;
    max_broj_prodaja = prodaje.max_broj_prodaja;
    niz = prodaje.niz;
    
    prodaje.niz = nullptr;
    prodaje.broj_prodanih = 0;
    prodaje.max_broj_prodaja = 0;
    
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, 
        const Kupac &kupac_stana, const Stan &kupljeni_stan)
{
    if (broj_prodanih == max_broj_prodaja)
        throw std::range_error ("Dostignut maksimalni broj prodaja");
        
    try
    {
        niz[broj_prodanih] = new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
        broj_prodanih++;
    }
    catch (...)
    {
        for (int i{};i<max_broj_prodaja;i++)
            delete niz[i];
        delete [] niz;
        niz = nullptr;
        std::bad_alloc e;
        throw e;
    }
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, 
        int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, 
        int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
{
    if (broj_prodanih == max_broj_prodaja)
        throw std::range_error ("Dostignut maksimalni broj prodaja");
        
    try
    {
        niz[broj_prodanih] = new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,
                                        ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,
                                        broj_kvadrata);
        broj_prodanih++;
    }
    catch (...)
    {
        for (int i{};i<max_broj_prodaja;i++)
            delete niz[i];
        delete [] niz;
        niz = nullptr;
        std::bad_alloc e;
        throw e;
    }    
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja)
{
    if (broj_prodanih == max_broj_prodaja)
        throw std::range_error ("Dostignut maksimalni broj prodaja");
        
    try
    {
        niz[broj_prodanih] = new Prodaja(*prodaja);
        broj_prodanih++;
    }
    catch (...)
    {
        for (int i{};i<max_broj_prodaja;i++)
            delete niz[i];
        delete [] niz;
        niz = nullptr;
        std::bad_alloc e;
        throw e;
    }  
}

int Prodaje::DajBrojProdaja() const
{
    return broj_prodanih;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const
{
    int rezultat = std::count_if(niz,niz+broj_prodanih, [datum] (Prodaja* pok)
    {
        Datum pomocni = pok->DajDatumProdaje();
        
        int brojac = 0;
        
        if (pomocni.DajDan() == datum.DajDan())
            brojac++;
        
        if (pomocni.DajMjesec() == datum.DajMjesec())
            brojac++;
            
        if (pomocni.DajGodinu() == datum.DajGodinu())
            brojac++;
            
        if (brojac == 3)
            return true;
            
        return false;
    });
    
    return rezultat;
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const
{
    int rezultat = std::count_if(niz,niz+broj_prodanih, [ime_agenta] (Prodaja *pok)
    {
        if (pok->DajImeAgenta() == ime_agenta)
            return true;
        
        return false;
    });
    
    return rezultat;
}

Prodaja &Prodaje::DajNajranijuProdaju()
{
    if (broj_prodanih == 0)
        throw std::domain_error ("Nema registriranih prodaja");
        
    Prodaja *rezultat = *std::min_element(niz,niz+broj_prodanih, [] (Prodaja *p1, Prodaja *p2)
    {
        return ProdatPrije(*p1,*p2);
    });
    
    return *rezultat;
}

Prodaja Prodaje::DajNajranijuProdaju() const
{
    if (broj_prodanih == 0)
        throw std::domain_error ("Nema registriranih prodaja");
        
    Prodaja *rezultat = *std::min_element(niz,niz+broj_prodanih, [] (Prodaja* p1, Prodaja* p2)
    {
        return ProdatPrije(*p1,*p2);
    });
    
    return *rezultat;
}

Prodaja &Prodaje::DajNajskupljuProdaju()
{
    if (broj_prodanih == 0)
        throw std::domain_error ("Nema registriranih prodaja");
        
    Prodaja* rezultat = *std::max_element(niz,niz+broj_prodanih, [] (Prodaja* p1, Prodaja* p2)
    {
        if (SkupljiStan(*p1,*p2) == true)
            return false;
        
        return true;
    });
    
    return *rezultat;
    
}

Prodaja Prodaje::DajNajskupljuProdaju() const
{
    if (broj_prodanih == 0)
        throw std::domain_error ("Nema registriranih prodaja");
        
    Prodaja* rezultat = *std::max_element(niz,niz+broj_prodanih, [] (Prodaja* p1, Prodaja* p2)
    {
        if (SkupljiStan(*p1,*p2) == true)
            return false;
        
        return true;
    });
    
    return *rezultat;
}

Prodaja &Prodaje::DajProdaju (int redni_broj)
{
    if (redni_broj<1 || redni_broj>max_broj_prodaja)
        throw std::range_error ("Neispravan redni broj");
        
    return *niz[redni_broj-1];
}

void Prodaje::IsprazniKolekciju()
{
    for (int i{};i<max_broj_prodaja;i++)
        delete niz[i];
    
    for (int i{};i<max_broj_prodaja;i++)
        niz[i] = nullptr;
        
    broj_prodanih = 0;
}

void Prodaje::ObrisiNajranijuProdaju()
{
    if (broj_prodanih == 0)
        throw std::range_error ("Prazna kolekcija");
        
    Prodaja* brisanje = &DajNajranijuProdaju();
    
    for (int i{};i<broj_prodanih;i++)
        {
            if (niz[i] == brisanje)
                {
                    delete niz[i];
                    niz[i] = nullptr;
                }
        }
        
    Prodaja** pomocna = nullptr;
    try
    {
        pomocna = new Prodaja* [max_broj_prodaja];
        for (int i{};i<max_broj_prodaja;i++)
            pomocna[i] = nullptr;
    }
    catch (...)
    {
        delete [] pomocna;
        pomocna = nullptr;
        std::bad_alloc e;
        throw e;
    }
    
    try
    {
        int k = 0;
        for (int i{};i<broj_prodanih;i++)
            {
                if (niz[i] != nullptr)
                    pomocna[k++] = new Prodaja (*niz[i]);
            }
    }
    catch (...)
    {
        for (int i{};i<max_broj_prodaja;i++)
            {
                delete pomocna[i];
                delete niz[i];
            }
        delete [] pomocna;
        delete [] niz;
        pomocna = nullptr;
        niz = nullptr;
        std::bad_alloc e;
        throw e;
    }
    
    for (int i{};i<max_broj_prodaja;i++)
        delete niz[i];
    delete [] niz;
    niz = pomocna;
    pomocna = nullptr;
    
    broj_prodanih--;
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta)
{
    if (broj_prodanih == 0)
        throw std::range_error ("Prazna kolekcija");
    
    int obrisani = 0;
    
    for (int i{};i<broj_prodanih;i++)
        {
            if (niz[i]->DajImeAgenta() == ime_agenta)
                {
                    delete niz[i];
                    niz[i] = nullptr;
                    obrisani++;
                }
        }
        
    Prodaja** pomocna = nullptr;
    try
    {
        pomocna = new Prodaja* [max_broj_prodaja];
        for (int i{};i<max_broj_prodaja;i++)
            pomocna[i] = nullptr;
    }
    catch (...)
    {
        delete [] pomocna;
        pomocna = nullptr;
        std::bad_alloc e;
        throw e;
    }
    
    try
    {
        int k = 0;
        for (int i{};i<broj_prodanih;i++)
            {
                if (niz[i] != nullptr)
                    pomocna[k++] = new Prodaja (*niz[i]);
            }
    }
    catch (...)
    {
        for (int i{};i<max_broj_prodaja;i++)
            {
                delete pomocna[i];
                delete niz[i];
            }
        delete [] pomocna;
        delete [] niz;
        pomocna = nullptr;
        niz = nullptr;
        std::bad_alloc e;
        throw e;
    }
    
    for (int i{};i<max_broj_prodaja;i++)
        delete niz[i];
    delete [] niz;
    niz = pomocna;
    pomocna = nullptr;
    
    broj_prodanih -= obrisani;
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum)
{
    if (broj_prodanih == 0)
        throw std::range_error ("Prazna kolekcija");
    
    int obrisani = 0;
    
    for (int i{};i<broj_prodanih;i++)
        {
            Datum pomocni = niz[i]->DajDatumProdaje();
            if (pomocni.DajDan() == datum.DajDan() && pomocni.DajMjesec() == datum.DajMjesec() &&
                pomocni.DajGodinu() == datum.DajGodinu())
                {
                    delete niz[i];
                    niz[i] = nullptr;
                    obrisani++;
                }
        }
        
    Prodaja** pomocna = nullptr;
    try
    {
        pomocna = new Prodaja* [max_broj_prodaja];
        for (int i{};i<max_broj_prodaja;i++)
            pomocna[i] = nullptr;
    }
    catch (...)
    {
        delete [] pomocna;
        pomocna = nullptr;
        std::bad_alloc e;
        throw e;
    }
    
    try
    {
        int k = 0;
        for (int i{};i<broj_prodanih;i++)
            {
                if (niz[i] != nullptr)
                    pomocna[k++] = new Prodaja (*niz[i]);
            }
    }
    catch (...)
    {
        for (int i{};i<max_broj_prodaja;i++)
            {
                delete pomocna[i];
                delete niz[i];
            }
        delete [] pomocna;
        delete [] niz;
        pomocna = nullptr;
        niz = nullptr;
        std::bad_alloc e;
        throw e;
    }
    
    for (int i{};i<max_broj_prodaja;i++)
        delete niz[i];
    delete [] niz;
    niz = pomocna;
    pomocna = nullptr;
    
    broj_prodanih -= obrisani;
    
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const
{
    Prodaje ispis(*this);
    
    std::sort(ispis.niz,ispis.niz+broj_prodanih, [] (Prodaja* p1, Prodaja *p2)
     {
        return p1->DajImeKupca() < p2->DajImeKupca(); 
     });
     
     for (int i{};i<broj_prodanih;i++)
        {
            Datum pomocni = ispis.niz[i]->DajDatumProdaje();
            if (pomocni.DajDan() == datum.DajDan() && pomocni.DajMjesec() == datum.DajMjesec() &&
                pomocni.DajGodinu() == datum.DajGodinu())
                {
                    ispis.niz[i]->Ispisi();
                    std::cout<<std::endl<<std::endl;
                }
            
        }
}

void Prodaje::IspisiSveProdaje() const
{
    Prodaje ispis (*this);
    
    std::sort(ispis.niz,ispis.niz+broj_prodanih, [] (Prodaja* p1, Prodaja* p2)
    {
       Datum pomocni = p1->DajDatumProdaje();
       Datum datum = p2->DajDatumProdaje();
       
       if (ProdatPrije(*p1,*p2) == true)
            return true;
            
       else if (pomocni.DajDan() == datum.DajDan() && pomocni.DajMjesec() == datum.DajMjesec() &&
                pomocni.DajGodinu() == datum.DajGodinu())
                return p1->DajImeKupca() < p2->DajImeKupca();
                
        return false;
    });
    
    for (int i{};i<broj_prodanih;i++)
        {
            ispis.niz[i]->Ispisi();
            std::cout<<std::endl<<std::endl;
        }
}
            
            
            
            
int main ()
{
    Prodaje P(20);
    std::vector<Stan> stanovi;
    std::vector<Kupac> kupci;
    
    std::cout<<"Dobrodosli!"<<std::endl<<std::endl;
    while(true)
        {
            std::cout<<"Izaberite opciju:"<<std::endl;
            std::cout<<" 0 - kraj"<<std::endl;
            std::cout<<" 1 - uredjivanje stanova"<<std::endl;
            std::cout<<" 2 - uredjivanje kupaca"<<std::endl;
            std::cout<<" 3 - uredjivanje prodaja"<<std::endl;
            int odabir;
            std::cin>>odabir;
            std::cin.ignore(10000, '\n');
            
            if (odabir == 0)
                break;
               
            bool izlaz = false; 
            if (odabir == 1)
                {
                    while(true)
                    {
                        std::cout<<"Izaberite opciju:"<<std::endl;
                        std::cout<<" 0 - nazad"<<std::endl;
                        std::cout<<" 1 - dodavanje stana"<<std::endl;
                        std::cout<<" 2 - uredjivanje stanova"<<std::endl;
                        std::cout<<" 3 - ispis svih stanova"<<std::endl;
                        std::cout<<" 4 - kraj"<<std::endl;
                    
                        int odabir_1;
                        std::cin>>odabir_1;
                        std::cin.ignore(10000, '\n');
                        
                        if (odabir_1 == 0)
                            break;
                            
                        if (odabir_1 == 4)
                            {
                                izlaz = true;
                                break;
                            }
                            
                        if (odabir_1 == 1)
                            {
                                while(true)
                                {
                                    std::cout<<"Unesite adresu: ";
                                    std::string adresa;
                                    std::getline(std::cin,adresa);
                                    std::cout<<"Unesite sprat: ";
                                    int sprat;
                                    std::cin>>sprat;
                                    std::cin.ignore(10000, '\n');
                                    std::cout<<"Unesite broj soba: ";
                                    int broj_soba;
                                    std::cin>>broj_soba;
                                    std::cin.ignore(10000, '\n');
                                    std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                                    int namjesten;
                                    std::cin>>namjesten;
                                    std::cin.ignore(10000, '\n');
                                    std::cout<<"Unesite kvadraturu: ";
                                    double kvadratura;
                                    std::cin>>kvadratura;
                                    std::cin.ignore(10000, '\n');
                                    try
                                    {
                                        bool uslov;
                                        if (namjesten == 1)
                                            uslov = true;
                                        else if (namjesten == 0)
                                            uslov = false;
                                        else
                                            throw std::domain_error ("Neispravan unos podataka");
                                        
                                        Stan upis (adresa,sprat,broj_soba,uslov,kvadratura);
                                        stanovi.push_back(upis);
                                        std::cout<<"Stan je uspjesno dodan!"<<std::endl<<std::endl;
                                        break;
                                    }
                                    catch (std::domain_error e)
                                    {
                                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl<<std::endl;
                                    }
                                }
                            }
                            
                            if (odabir_1 == 3)
                                {
                                    for (int i{};i<stanovi.size();i++)
                                        {
                                            std::cout<<i+1<<". ";
                                            stanovi[i].Ispisi();
                                            std::cout<<std::endl;
                                        }
                                        
                                    std::cout<<std::endl;
                                }
                                
                            if (odabir_1 == 2)
                                {
                                    while(true)
                                    {
                                        std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
                                        for (int i{};i<stanovi.size();i++)
                                            {
                                                std::cout<<" "<<i+1<<" - ";
                                                stanovi[i].Ispisi();
                                                std::cout<<std::endl;
                                            }
                                        
                                        int odabir_1_stan;
                                        std::cin>>odabir_1_stan;
                                        std::cin.ignore(10000, '\n');
                                    
                                        std::cout<<"Odaberite polje koji zelite urediti:"<<std::endl;
                                        std::cout<<" 0 - nazad"<<std::endl;
                                        std::cout<<" 1 - adresa"<<std::endl;
                                        std::cout<<" 2 - sprat"<<std::endl;
                                        std::cout<<" 3 - broj soba"<<std::endl;
                                        std::cout<<" 4 - da li je stan namjesten"<<std::endl;
                                        std::cout<<" 5 - kvadratura"<<std::endl;
                                        std::cout<<" 6 - sve"<<std::endl;
                                        
                                        int odabir_1_stan_opcija;
                                        std::cin>>odabir_1_stan_opcija;
                                        std::cin.ignore(10000, '\n');
                                        
                                        if (odabir_1_stan_opcija == 0)
                                            break;
                                            
                                        if (odabir_1_stan_opcija == 5)
                                            {
                                                while(true)
                                                    {
                                                        std::cout<<"Unesite kvadraturu: ";
                                                        double kvadratura;
                                                        std::cin>>kvadratura;
                                                        std::cin.ignore(10000, '\n');
                                                        try
                                                        {
                                                            Stan kopija = stanovi[odabir_1_stan-1];
                                                            stanovi[odabir_1_stan-1].Postavi(kopija.DajAdresu(),kopija.DajSprat(),kopija.DajBrojSoba(),kopija.DajNamjesten(),kvadratura);
                                                            std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<std::endl;
                                                            break;
                                                        }
                                                        catch(std::domain_error e)
                                                        {
                                                            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                                        }
                                                    }
                                                break;    
                                            }
                                            
                                        if (odabir_1_stan_opcija == 6)
                                            {
                                                while(true)
                                                {
                                                std::cout<<"Unesite adresu: ";
                                                std::string adresa;
                                                std::getline(std::cin,adresa);
                                                std::cout<<"Unesite sprat: ";
                                                int sprat;
                                                std::cin>>sprat;
                                                std::cin.ignore(10000, '\n');
                                                std::cout<<"Unesite broj soba: ";
                                                int broj_soba;
                                                std::cin>>broj_soba;
                                                std::cin.ignore(10000, '\n');
                                                std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                                                int namjesten;
                                                std::cin>>namjesten;
                                                std::cin.ignore(10000, '\n');
                                                std::cout<<"Unesite kvadraturu: ";
                                                double kvadratura;
                                                std::cin>>kvadratura;
                                                std::cin.ignore(10000, '\n');
                                                try
                                                {
                                                    bool uslov;
                                                    if (namjesten == 1)
                                                        uslov = true;
                                                    else if (namjesten == 0)
                                                        uslov = false;
                                                    else
                                                        throw std::domain_error ("Neispravan unos podataka");
                                        
                                                    
                                                    stanovi[odabir_1_stan-1].Postavi(adresa,sprat,broj_soba,uslov,kvadratura);
                                                    std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<std::endl;
                                                    break;
                                                }
                                                catch (std::domain_error e)
                                                {
                                                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl<<std::endl;
                                                }
                                                }
                                                break;
                                            }
                                        
                                        if (odabir_1_stan_opcija == 1)
                                            {
                                                while (true)
                                                {
                                                    std::cout<<"Unesite adresu: ";
                                                    std::string adresa;
                                                    std::getline(std::cin,adresa);
                                                    try
                                                    {
                                                        Stan kopija = stanovi[odabir_1_stan-1];
                                                        stanovi[odabir_1_stan-1].Postavi(adresa,kopija.DajSprat(),kopija.DajBrojSoba(),kopija.DajNamjesten(),kopija.DajKvadraturu());
                                                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<std::endl;
                                                        break;
                                                    }
                                                    catch(std::domain_error e)
                                                    {
                                                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                                    }
                                                }
                                                break;
                                            }
                                            
                                        if (odabir_1_stan_opcija == 2)
                                            {
                                                while (true)
                                                {
                                                    std::cout<<"Unesite sprat: ";
                                                    int sprat;
                                                    std::cin>>sprat;
                                                    std::cin.ignore(10000, '\n');
                                                    try
                                                    {
                                                        Stan kopija = stanovi[odabir_1_stan-1];
                                                        stanovi[odabir_1_stan-1].Postavi(kopija.DajAdresu(),sprat,kopija.DajBrojSoba(),kopija.DajNamjesten(),kopija.DajKvadraturu());
                                                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<std::endl;
                                                        break;
                                                    }
                                                    catch(std::domain_error e)
                                                    {
                                                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                                    }
                                                }
                                                break;
                                            }
                                            
                                        if (odabir_1_stan_opcija == 3)
                                            {
                                                while (true)
                                                {
                                                    std::cout<<"Unesite broj soba: ";
                                                    int broj_soba;
                                                    std::cin>>broj_soba;
                                                    std::cin.ignore(10000, '\n');
                                                    try
                                                    {
                                                        Stan kopija = stanovi[odabir_1_stan-1];
                                                        stanovi[odabir_1_stan-1].Postavi(kopija.DajAdresu(),kopija.DajSprat(),broj_soba,kopija.DajNamjesten(),kopija.DajKvadraturu());
                                                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<std::endl;
                                                        break;
                                                    }
                                                    catch(std::domain_error e)
                                                    {
                                                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                                    }
                                                }
                                                break;
                                                
                                            }
                                            
                                        if (odabir_1_stan_opcija == 4)
                                            {
                                                while (true)
                                                {
                                                    std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                                                    int namjesten;
                                                    std::cin>>namjesten;
                                                    std::cin.ignore(10000, '\n');
                                                
                                                    try
                                                    {
                                                        bool uslov;
                                                        if (namjesten == 1)
                                                            uslov = true;
                                                        else if (namjesten == 0)
                                                            uslov = false;
                                                        else
                                                            throw std::domain_error ("Neispravan unos podataka");
                                        
                                                    
                                                        Stan kopija = stanovi[odabir_1_stan-1];
                                                        stanovi[odabir_1_stan-1].Postavi(kopija.DajAdresu(),kopija.DajSprat(),kopija.DajBrojSoba(),uslov,kopija.DajKvadraturu());
                                                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<std::endl;
                                                        break;
                                                    }
                                                    catch (std::domain_error e)
                                                    {
                                                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl<<std::endl;
                                                    }
                                                }
                                                break;
                                            }
                                    }
                                }
                    }
                    
                }
                
            if (odabir == 2)
                {
                    while (true)
                        {
                            std::cout<<"Izaberite opciju:"<<std::endl;
                            std::cout<<" 0 - nazad"<<std::endl;
                            std::cout<<" 1 - dodavanje kupca"<<std::endl;
                            std::cout<<" 2 - uredjivanje kupaca"<<std::endl;
                            std::cout<<" 3 - ispis svih kupaca"<<std::endl;
                            std::cout<<" 4 - kraj"<<std::endl;
                            
                            int odabir_2;
                            std::cin>>odabir_2;
                            std::cin.ignore(10000, '\n');
                            
                            if (odabir_2 == 0)
                                break;
                                
                            if (odabir_2 == 4)
                                {
                                    izlaz = true;
                                    break;
                                }
                                
                            if (odabir_2 == 1)
                                {
                                    while (true)
                                        {
                                            std::cout<<"Unesite ime i prezime kupca: ";
                                            std::string ime_kupca;
                                            std::getline(std::cin,ime_kupca);
                                            std::cout<<"Unesite datum rodjenja (formata dan/mjesec/godina): ";
                                            int dan, mjesec, godina;
                                            char znak;
                                            std::cin>>dan>>znak>>mjesec>>znak>>godina;
                                            std::cin.ignore(10000, '\n');
                                            
                                            try
                                            {
                                                Datum datum(dan,mjesec,godina);
                                                Kupac upis(ime_kupca,datum);
                                                kupci.push_back(upis);
                                                std::cout<<"Kupac je uspjesno dodan!"<<std::endl<<std::endl;
                                                break;
                                            }
                                            catch (std::domain_error e)
                                            {
                                                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                            }
                                        }
                                }
                                
                            if (odabir_2 == 3)
                                {
                                    for (int i{};i<kupci.size();i++)
                                        {
                                            kupci[i].Ispisi();
                                            std::cout<<std::endl;
                                        }
                                    std::cout<<std::endl;
                                }
                                
                            if (odabir_2 == 2)
                                {
                                    std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:"<<std::endl;
                                    for (int i{};i<kupci.size();i++)
                                        {
                                            std::cout<<" "<<i+1<<" - ";
                                            kupci[i].Ispisi();
                                            std::cout<<std::endl;
                                        }
                                        
                                    int odabir_2_kupac;
                                    std::cin>>odabir_2_kupac;
                                    std::cin.ignore(10000, '\n');
                                    
                                    while (true)
                                        {
                                            std::cout<<"Unesite ime i prezime kupca: ";
                                            std::string ime_kupca;
                                            std::getline(std::cin,ime_kupca);
                                            std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                                            int dan, mjesec, godina;
                                            char znak;
                                            std::cin>>dan>>znak>>mjesec>>znak>>godina;
                                            std::cin.ignore(10000, '\n');
                                            
                                            try
                                            {
                                                Datum datum(dan,mjesec,godina);
                                                kupci[odabir_2_kupac-1].Postavi(ime_kupca,datum);
                                                std::cout<<"Kupac je uspjesno izmijenjen!"<<std::endl<<std::endl;
                                                break;
                                            }
                                            catch (std::domain_error e)
                                            {
                                                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                            }
                                        }
                                }
                        }
                }
                
            if (odabir == 3)
                {
                    while(true)
                    {
                        std::cout<<"Izaberite opciju:"<<std::endl;
                        std::cout<<" 0 - nazad"<<std::endl;
                        std::cout<<" 1 - dodavanje prodaje"<<std::endl;
                        std::cout<<" 2 - uredjivanje prodaje"<<std::endl;
                        std::cout<<" 3 - ispis prodaja"<<std::endl;
                        std::cout<<" 4 - brisanje prodaja"<<std::endl;
                        std::cout<<" 5 - kraj"<<std::endl;
                    
                        int odabir_3;
                        std::cin>>odabir_3;
                        std::cin.ignore(10000, '\n');
                    
                        if (odabir_3 == 0)
                            break;
                        
                        if (odabir_3 == 5)
                            {
                                izlaz = true;
                                break;
                            }
                            
                        if (odabir_3 == 1)
                            {
                                while(true)
                                {
                                std::cout<<"Izaberite opciju:"<<std::endl;
                                std::cout<<" 0 - nazad"<<std::endl;
                                std::cout<<" 1 - dodavanje potpuno nove prodaje"<<std::endl;
                                std::cout<<" 2 - dodavanje nove prodaje na osnovu arhive"<<std::endl;
                                std::cout<<" 3 - kraj"<<std::endl;
                                
                                int odabir_3_nova_prodaja;
                                std::cin>>odabir_3_nova_prodaja;
                                std::cin.ignore(10000, '\n');
                                
                                if (odabir_3_nova_prodaja == 0)
                                    break;
                                    
                                if (odabir_3_nova_prodaja == 3)
                                    {
                                        izlaz = true;
                                        break;
                                    }
                                    
                                if (odabir_3_nova_prodaja == 1)
                                    {
                                        while(true)
                                            {
                                                std::cout<<"Unesite ime i prezime agenta prodaje: ";
                                                std::string ime_agenta;
                                                std::getline(std::cin,ime_agenta);
                                                std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                                                int dan_p, mjesec_p, godina_p;
                                                char znak;
                                                std::cin>>dan_p>>znak>>mjesec_p>>znak>>godina_p;
                                                std::cin.ignore(10000, '\n');
                                                std::cout<<"Unesite cijenu stana: ";
                                                double cijena_stana;
                                                std::cin>>cijena_stana;
                                                std::cin.ignore(10000, '\n');
                                                std::cout<<"Unesite ime kupca: ";
                                                std::string ime_kupca;
                                                std::getline(std::cin,ime_kupca);
                                                std::cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
                                                int dan, mjesec, godina;
                                                std::cin>>dan>>znak>>mjesec>>znak>>godina;
                                                std::cin.ignore(10000, '\n');
                                                std::cout<<"Unesite adresu: ";
                                                std::string adresa;
                                                std::getline(std::cin,adresa);
                                                std::cout<<"Unesite sprat: ";
                                                int sprat;
                                                std::cin>>sprat;
                                                std::cin.ignore(10000, '\n');
                                                std::cout<<"Unesite broj soba: ";
                                                int broj_soba;
                                                std::cin>>broj_soba;
                                                std::cin.ignore(10000, '\n');
                                                std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                                                int namjesten;
                                                std::cin>>namjesten;
                                                std::cin.ignore(10000, '\n');
                                                std::cout<<"Unesite kvadraturu: ";
                                                double kvadratura;
                                                std::cin>>kvadratura;
                                                std::cin.ignore(10000, '\n');
                                                try
                                                {
                                                    bool uslov;
                                                    if (namjesten == 1)
                                                        uslov = true;
                                                    else if (namjesten == 0)
                                                        uslov = false;
                                                    else
                                                        throw std::domain_error ("Neispravan unos podataka");
                                                    
                                                    Datum datum_prodaje(dan_p,mjesec_p,godina_p);
                                                    Datum datum_rodjenja_kupca (dan,mjesec,godina);
                                                    Kupac upis_kupca (ime_kupca,datum_rodjenja_kupca);
                                                    kupci.push_back(upis_kupca);
                                                    Stan upis_stana (adresa,sprat,broj_soba,uslov,kvadratura);
                                                    stanovi.push_back(upis_stana);
                                                    Prodaja upis(ime_agenta,cijena_stana,datum_prodaje,upis_kupca,upis_stana);
                                                    P.RegistrirajProdaju(&upis);
                                                    std::cout<<"Prodaja uspjesno dodana!"<<std::endl<<std::endl;
                                                    break;
                                                }
                                                catch (std::domain_error e)
                                                {
                                                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl<<std::endl;
                                                }
                                                catch (std::range_error e)
                                                    {
                                                        std::cout<<"Izuzetak: "<<e.what()<<"."<<std::endl;
                                                    }
                                                
                            
                                            }
                                    }
                                    
                                if (odabir_3_nova_prodaja == 2)
                                    {
                                        while(true)
                                            {
                                                std::cout<<"Unesite ime i prezime agenta prodaje: ";
                                                std::string ime_agenta;
                                                std::getline(std::cin,ime_agenta);
                                                std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                                                int dan_p, mjesec_p, godina_p;
                                                char znak;
                                                std::cin>>dan_p>>znak>>mjesec_p>>znak>>godina_p;
                                                std::cin.ignore(10000, '\n');
                                                std::cout<<"Unesite cijenu stana: ";
                                                double cijena_stana;
                                                std::cin>>cijena_stana;
                                                std::cin.ignore(10000, '\n');
                                                std::cout<<"Odaberite kupca. Dostupni kupci su:"<<std::endl;
                                                for (int i{};i<kupci.size();i++)
                                                    {
                                                        std::cout<<" "<<i+1<<" - ";
                                                        kupci[i].Ispisi();
                                                        std::cout<<std::endl;
                                                    }
                                                    
                                                int odabir_3_nova_prodaja_kupac;
                                                std::cin>>odabir_3_nova_prodaja_kupac;
                                                std::cin.ignore(10000, '\n');
                                                
                                                std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
                                                for (int i{};i<stanovi.size();i++)
                                                    {
                                                        std::cout<<" "<<i+1<<" - ";
                                                        stanovi[i].Ispisi();
                                                        std::cout<<std::endl;
                                                    }
                                                
                                                int odabir_3_nova_prodaja_stan;
                                                std::cin>>odabir_3_nova_prodaja_stan;
                                                std::cin.ignore(10000, '\n');
                                                
                                                try
                                                {
                                                    Datum datum_prodaje(dan_p,mjesec_p,godina_p);
                                                    Kupac upis_kupca = kupci[odabir_3_nova_prodaja_kupac-1];
                                                    Stan upis_stana = stanovi[odabir_3_nova_prodaja_stan-1];
                                                    Prodaja upis(ime_agenta,cijena_stana,datum_prodaje,upis_kupca,upis_stana);
                                                    P.RegistrirajProdaju(&upis);
                                                    std::cout<<"Prodaja uspjesno dodana!"<<std::endl<<std::endl;
                                                    break;
                                                }
                                                catch (std::domain_error e)
                                                {
                                                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl<<std::endl;
                                                }
                                                catch (std::range_error e)
                                                    {
                                                        std::cout<<"Izuzetak: "<<e.what()<<"."<<std::endl;
                                                    }
                                                    
                                            }
                                    }
                            }
                            }
                        
                        if (odabir_3 == 2)
                            {
                                std::cout<<"Odaberite prodaju koju zelite urediti. Dostupne prodaje su:"<<std::endl;
                                for (int i{};i<P.DajBrojProdaja();i++)
                                    {
                                        Prodaja ispis = P.DajProdaju(i+1);
                                        std::cout<<i+1<<"."<<std::endl;
                                        ispis.Ispisi();
                                        std::cout<<std::endl<<std::endl;
                                    }
                                
                                int odabir_3_uredjivanje;
                                std::cin>>odabir_3_uredjivanje;
                                std::cin.ignore(10000, '\n');
                                
                                std::cout<<"Izaberite opciju:"<<std::endl;
                                std::cout<<" 0 - nazad"<<std::endl;
                                std::cout<<" 1 - izmjena agenta"<<std::endl;
                                std::cout<<" 2 - izmjena datuma prodaje"<<std::endl;
                                std::cout<<" 3 - izmjena kupca"<<std::endl;
                                std::cout<<" 4 - izmjena stana"<<std::endl;
                                std::cout<<" 5 - izmjena cijene stana"<<std::endl;
                                
                                int odabir_3_uredjivanje_opcija;
                                std::cin>>odabir_3_uredjivanje_opcija;
                                std::cin.ignore(10000, '\n');
                                
                                if (odabir_3_uredjivanje_opcija == 0)
                                    break;
                                    
                                if (odabir_3_uredjivanje_opcija == 1)
                                    {
                                        while(true)
                                        {
                                        std::cout<<"Unesite ime i prezime agenta prodaje: ";
                                        std::string ime_agenta;
                                        std::getline(std::cin,ime_agenta);
                                        
                                        try
                                        {
                                            Prodaja *promjena = &P.DajProdaju(odabir_3_uredjivanje);
                                            promjena->PromijeniAgenta(ime_agenta);
                                            std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                                            break;
                                            
                                        }
                                        catch (std::domain_error e)
                                        {
                                            std::cout<<"Izuzetak: "<<e.what()<<". "<<"Molimo unesite opet."<<std::endl;
                                        }
                                        }
                                    }
                                    
                                if (odabir_3_uredjivanje_opcija == 2)
                                {
                                   while (true)
                                        {
                                            std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                                            int dan_p, mjesec_p, godina_p;
                                            char znak;
                                            std::cin>>dan_p>>znak>>mjesec_p>>znak>>godina_p;
                                            std::cin.ignore(10000, '\n');
                                            
                                            try
                                            {
                                            Datum d(dan_p,mjesec_p,godina_p);    
                                            Prodaja *promjena = &P.DajProdaju(odabir_3_uredjivanje);
                                            promjena->PromijeniDatumKupovine(d);
                                            std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                                            break;
                                            
                                            }
                                            catch (std::domain_error e)
                                            {
                                            std::cout<<"Izuzetak: "<<e.what()<<". "<<"Molimo unesite opet."<<std::endl;
                                            }
                                        }
                                }
                                
                                if (odabir_3_uredjivanje_opcija == 3)
                                    {
                                        while(true)
                                            {
                                                std::cout<<"Izaberite opciju:"<<std::endl;
                                                std::cout<<" 0 - nazad"<<std::endl;
                                                std::cout<<" 1 - odabir postojeceg kupca"<<std::endl;
                                                std::cout<<" 2 - dodavanje novog kupca"<<std::endl;
                                                
                                                int odabir_3_uredjivanje_opcija_kupac;
                                                std::cin>>odabir_3_uredjivanje_opcija_kupac;
                                                std::cin.ignore(10000, '\n');
                                                
                                                if (odabir_3_uredjivanje_opcija_kupac == 0)
                                                    break;
                                                    
                                                if (odabir_3_uredjivanje_opcija_kupac == 1)
                                                    {
                                                        std::cout<<"Odaberite kupca. Dostupni kupci su:"<<std::endl;
                                                        for (int i{};i<kupci.size();i++)
                                                            {
                                                                std::cout<<" "<<i+1<<" - ";
                                                                kupci[i].Ispisi();
                                                                std::cout<<std::endl;
                                                            }
                                                    
                                                        int odabir_3_nova_prodaja_kupac;
                                                        std::cin>>odabir_3_nova_prodaja_kupac;
                                                        std::cin.ignore(10000, '\n');
                                                        
                                                        try
                                                        {
                                                            Prodaja *promjena = &P.DajProdaju(odabir_3_uredjivanje);
                                                            promjena->PromijeniKupca(kupci[odabir_3_nova_prodaja_kupac-1]);
                                                            std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                                                            break;
                                            
                                                        }
                                                        catch (std::domain_error e)
                                                        {
                                                            std::cout<<"Izuzetak: "<<e.what()<<". "<<"Molimo unesite opet."<<std::endl;
                                                        }
                                                    
                                                    }
                                                
                                                    
                                                if (odabir_3_uredjivanje_opcija_kupac == 2)
                                                    {
                                                        while (true)
                                                            {
                                                                std::cout<<"Unesite ime i prezime kupca: ";
                                                                std::string ime_kupca;
                                                                std::getline(std::cin,ime_kupca);
                                                                std::cout<<"Unesite datum rodjenja (formata dan/mjesec/godina): ";
                                                                int dan, mjesec, godina;
                                                                char znak;
                                                                std::cin>>dan>>znak>>mjesec>>znak>>godina;
                                                                std::cin.ignore(10000, '\n');
                                            
                                                                try
                                                                {
                                                                    Datum datum(dan,mjesec,godina);
                                                                    Kupac upis(ime_kupca,datum);
                                                                    kupci.push_back(upis);
                                                                    Prodaja *promjena = &P.DajProdaju(odabir_3_uredjivanje);
                                                                    promjena->PromijeniKupca(upis);
                                                                    std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                                                                    break;
                                                                }
                                                                catch (std::domain_error e)
                                                                {
                                                                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                                                }
                                                            
                                                            }
                                                        
                                                        
                                                    }
                                                break;
                                            }
                                    }
                                    
                                if (odabir_3_uredjivanje_opcija == 4)
                                    {
                                        std::cout<<"Izaberite opciju:"<<std::endl;
                                        std::cout<<" 0 - nazad"<<std::endl;
                                        std::cout<<" 1 - odabir postojeceg stana"<<std::endl;
                                        std::cout<<" 2 - dodavanje novog stana"<<std::endl;
                                        
                                        int odabir_3_uredjivanje_opcija_stan;
                                        std::cin>>odabir_3_uredjivanje_opcija_stan;
                                        std::cin.ignore(10000, '\n');
                                        
                                        if (odabir_3_uredjivanje_opcija_stan == 0)
                                            break;
                                            
                                        if (odabir_3_uredjivanje_opcija_stan == 1)
                                            {
                                                std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
                                                for (int i{};i<stanovi.size();i++)
                                                    {
                                                        std::cout<<" "<<i+1<<" - ";
                                                        stanovi[i].Ispisi();
                                                        std::cout<<std::endl;
                                                    }
                                                    
                                                int n;
                                                std::cin>>n;
                                                std::cin.ignore(10000, '\n');
                                                
                                                try
                                                    {
                                                        Stan upis = stanovi[n-1];
                                                        Prodaja *promjena = &P.DajProdaju(odabir_3_uredjivanje);
                                                        promjena->PromijeniStan(upis);
                                                        std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                                                    
                                                    }
                                                catch (std::domain_error e)
                                                    {
                                                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                                    }
                                                
                                            }
                                            
                                        if (odabir_3_uredjivanje_opcija_stan == 2)
                                            {
                                                while(true)
                                                {
                                                std::cout<<"Unesite adresu: ";
                                                std::string adresa;
                                                std::getline(std::cin,adresa);
                                                std::cout<<"Unesite sprat: ";
                                                int sprat;
                                                std::cin>>sprat;
                                                std::cin.ignore(10000, '\n');
                                                std::cout<<"Unesite broj soba: ";
                                                int broj_soba;
                                                std::cin>>broj_soba;
                                                std::cin.ignore(10000, '\n');
                                                std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                                                int namjesten;
                                                std::cin>>namjesten;
                                                std::cin.ignore(10000, '\n');
                                                std::cout<<"Unesite kvadraturu: ";
                                                double kvadratura;
                                                std::cin>>kvadratura;
                                                std::cin.ignore(10000, '\n');
                                                try
                                                {
                                                    bool uslov;
                                                    if (namjesten == 1)
                                                        uslov = true;
                                                    else if (namjesten == 0)
                                                        uslov = false;
                                                    else
                                                        throw std::domain_error ("Neispravan unos podataka");
                                        
                                                    Stan upis (adresa,sprat,broj_soba,uslov,kvadratura);
                                                    stanovi.push_back(upis);
                                                    Prodaja *promjena = &P.DajProdaju(odabir_3_uredjivanje);
                                                    promjena->PromijeniStan(upis);
                                                    std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                                                    break;
                                                }
                                                catch (std::domain_error e)
                                                {
                                                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl<<std::endl;
                                                }
                                                }
                                                
                                            }
                                        
                                    }
                                    
                                if (odabir_3_uredjivanje_opcija == 5)
                                    {
                                        while (true)
                                            {
                                                std::cout<<"Unesite cijenu stana: ";
                                                double cijena_stana;
                                                std::cin>>cijena_stana;
                                                std::cin.ignore(10000, '\n');
                                                
                                                try
                                                    {
                                                        Prodaja *promjena = &P.DajProdaju(odabir_3_uredjivanje);
                                                        promjena->PromijeniCijenuProdaje(cijena_stana);
                                                        std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                                                        break;
                                                    }
                                                catch (std::domain_error e)
                                                    {
                                                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                                    }
                                            }
                                    }
                            }
                            
                        if (odabir_3 == 3)
                            {
                                while (true)
                                    {
                                        std::cout<<"Izaberite opciju:"<<std::endl;
                                        std::cout<<" 0 - nazad"<<std::endl;
                                        std::cout<<" 1 - ispis svih prodaja"<<std::endl;
                                        std::cout<<" 2 - ispis prodaja na datum"<<std::endl;
                                        std::cout<<" 3 - ispis najranije prodaje"<<std::endl;
                                        std::cout<<" 4 - ispis najskuplje prodaje"<<std::endl;
                                        std::cout<<" 5 - ispis broja prodaja"<<std::endl;
                                        std::cout<<" 6 - ispis broja prodaja po datumu"<<std::endl;
                                        std::cout<<" 7 - ispis broja prodaja po agentu"<<std::endl;
                                        std::cout<<" 8 - kraj"<<std::endl;
                                        
                                        int odabir_3_ispis;
                                        std::cin>>odabir_3_ispis;
                                        std::cin.ignore(10000 ,'\n');
                                        
                                        if (odabir_3_ispis == 0)
                                            break;
                                        
                                        if (odabir_3_ispis == 8)
                                            {
                                                izlaz = true;
                                                break;
                                            }
                                            
                                        if (odabir_3_ispis == 2)
                                            {
                                                while (true)
                                                {
                                                std::cout<<"Unesite datum (d/m/g): ";
                                                int dan, mjesec, godina;
                                                char znak;
                                                std::cin>>dan>>znak>>mjesec>>znak>>godina;
                                                std::cin.ignore(10000, '\n');
                                                
                                                try
                                                {
                                                    Datum datum (dan,mjesec,godina);
                                                    std::cout<<"Prodaje na datum "<<dan<<"/"<<mjesec<<"/"<<godina<<" su:"<<std::endl;
                                                    P.IspisiProdajeNaDatum(datum);
                                                    break;
                                                }
                                                catch (std::domain_error e)
                                                    {
                                                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                                    }
                                                }
                                            }
                                            
                                        if (odabir_3_ispis == 1)
                                            P.IspisiSveProdaje();
                                            
                                        if (odabir_3_ispis == 3)
                                            {
                                                Prodaja ispis = P.DajNajranijuProdaju();
                                                ispis.Ispisi();
                                                std::cout<<std::endl<<std::endl;
                                            }
                                            
                                        if (odabir_3_ispis == 4)
                                            {
                                                Prodaja ispis = P.DajNajskupljuProdaju();
                                                ispis.Ispisi();
                                                std::cout<<std::endl<<std::endl;
                                            }
                                            
                                        if (odabir_3_ispis == 5)
                                            {
                                                std::cout<<"Broj prodaja: "<<P.DajBrojProdaja()<<std::endl<<std::endl;
                                            }
                                            
                                        if (odabir_3_ispis == 6)
                                            {
                                                while (true)
                                                {
                                                std::cout<<"Unesite datum (d/m/g): ";
                                                int dan, mjesec, godina;
                                                char znak;
                                                std::cin>>dan>>znak>>mjesec>>znak>>godina;
                                                std::cin.ignore(10000, '\n');
                                                
                                                try
                                                {
                                                    Datum datum (dan,mjesec,godina);
                                                    std::cout<<"Broj prodaja na uneseni datum: "<<P.DajBrojProdajaNaDatum(datum)<<std::endl<<std::endl;
                                                   
                                                    break;
                                                }
                                                catch (std::domain_error e)
                                                    {
                                                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                                    }
                                                }
                                            }
                                            
                                        if (odabir_3_ispis == 7)
                                            {
                                                while (true)
                                                {
                                                std::cout<<"Unesite ime agenta: ";
                                                std::string ime_agenta;
                                                std::getline(std::cin,ime_agenta);
                                                
                                                
                                                try
                                                {
                                                    std::cout<<"Broj prodaja: "<<P.DajBrojProdajaOdAgenta(ime_agenta)<<std::endl<<std::endl;
                                                    break;
                                                }
                                                catch (std::domain_error e)
                                                    {
                                                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                                    }
                                                }
                                                
                                            }
                                            
                                    }
                            }
                            
                            if (odabir_3 == 4)
                                {
                                    while (true)
                                        {
                                            std::cout<<"Izaberite opciju:"<<std::endl;
                                            std::cout<<" 0 - nazad"<<std::endl;
                                            std::cout<<" 1 - brisanje najranije prodaje"<<std::endl;
                                            std::cout<<" 2 - brisanje prodaja agenta"<<std::endl;
                                            std::cout<<" 3 - brisanje prodaja po datumu"<<std::endl;
                                            std::cout<<" 4 - brisanje svih prodaja"<<std::endl;
                    
                                            int odabir_3_brisanje;
                                            std::cin>>odabir_3_brisanje;
                                            std::cin.ignore(10000, '\n');
                    
                                            if (odabir_3_brisanje == 0)
                                                break;
                                                
                                            if (odabir_3_brisanje == 1)
                                                {
                                                    try
                                                    {
                                                        P.ObrisiNajranijuProdaju();
                                                        std::cout<<"Najranija prodaja je obrisana!"<<std::endl;
                                                    }
                                                    catch (std::range_error e)
                                                        {
                                                            std::cout<<"Izuzetak: "<<e.what()<<"."<<std::endl;
                                                        }
                                                }
                                                
                                            if (odabir_3_brisanje == 2)
                                                {
                                                    while (true)
                                                        {
                                                            std::cout<<"Unesite ime agenta: ";
                                                            std::string ime_agenta;
                                                            std::getline(std::cin,ime_agenta);
                                                
                                                
                                                            try
                                                                {
                                                                    P.ObrisiProdajeAgenta(ime_agenta);
                                                                    std::cout<<"Sve prodaje tog agenta su obrisane."<<std::endl;
                                                                    break;
                                                                }
                                                            catch (std::domain_error e)
                                                                {
                                                                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                                                }
                                                            catch (std::range_error e)
                                                                {
                                                                    std::cout<<"Izuzetak: "<<e.what()<<"."<<std::endl;
                                                                    break;
                                                                }
                                                        }
                                                    
                                                }
                                                
                                            if (odabir_3_brisanje == 3)
                                                {
                                                    while (true)
                                                        {
                                                            std::cout<<"Unesite datum: ";
                                                            int dan, mjesec, godina;
                                                            char znak;
                                                            std::cin>>dan>>znak>>mjesec>>znak>>godina;
                                                            std::cin.ignore(10000 ,'\n');
                                                
                                                            try
                                                                {
                                                                    Datum datum (dan,mjesec,godina);
                                                                    P.ObrisiProdajeNaDatum(datum);
                                                                    std::cout<<"Sve prodaje na taj datum su obrisane."<<std::endl;
                                                                    break;
                                                                }
                                                            catch (std::domain_error e)
                                                                {
                                                                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                                                }
                                                            catch (std::range_error e)
                                                                {
                                                                    std::cout<<"Izuzetak: "<<e.what()<<"."<<std::endl;
                                                                    break;
                                                                }
                                                        }
                                                    
                                                }
                                            
                                            if (odabir_3_brisanje == 4)
                                                {
                                                    try
                                                    {
                                                        P.IsprazniKolekciju();
                                                        std::cout<<"Sve prodaje su obrisane."<<std::endl;
                                                    }
                                                    catch (std::range_error e)
                                                    {
                                                        std::cout<<"Izuzetak: "<<e.what()<<"."<<std::endl;
                                                    }
                                                }
                                        }
                    
                                }
                            
                            
                        if (izlaz == true)
                            break;
                            
                    }
                }
                
            
                
            if (izlaz == true)
                break;
        }
    
    std::cout<<std::endl<<"Dovidjenja!";
	return 0;
}