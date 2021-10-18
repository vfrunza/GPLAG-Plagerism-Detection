/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>
#include <vector>

//--------------
//--------------
//_____DATUM____
class Datum
{
    
private:
    int dan;
    int mjesec;
    int godina;

    bool validanDatum(int dan, int mjesec, int godina);
        
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const;
    int DajMjesec() const;
    int DajGodinu() const;
    void Ispisi() const;
};

bool Datum::validanDatum(int dan, int mjesec, int godina)
{
    bool prestupna = false;
    
    if (godina % 4 == 0)
        if (godina % 100 == 0)
            if (godina % 400 == 0)
                prestupna = true;
    
    if (dan < 0 || dan > 31)
        return false;
        
    if (mjesec < 0 || mjesec > 12)
        return false;
        
    if (mjesec == 2 && dan > 29)
        return false;
        
    if (mjesec == 2 && dan == 29 && !prestupna)
        return false;
        
    if ((mjesec == 4 || mjesec == 6 || mjesec == 9 || mjesec == 11) && dan > 30)
        return false;
        
    return true;
}

Datum::Datum(int dan, int mjesec, int godina)
{
    if (!validanDatum(dan, mjesec, godina))
        throw std::domain_error("Neispravan datum");
    
    this->dan = dan;
    this->mjesec = mjesec;
    this->godina = godina;
}

void Datum::Postavi(int dan, int mjesec, int godina)
{
    if (!validanDatum(dan, mjesec, godina))
        throw std::domain_error("Neispravan datum");
    
    this->dan = dan;
    this->mjesec = mjesec;
    this->godina = godina;    
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
    std::cout << "(" << DajDan() << "/" << DajMjesec() << "/" << DajGodinu() << ")";
}

//--------------
//--------------
//_____KUPAC____
class Kupac
{
    
private:
    std::string imeIPrezime;
    Datum datumRodjenja;
    
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const;
    Datum DajDatumRodjenja() const;
    void Ispisi() const;
};

Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
    : datumRodjenja(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu())
{
    for (int i = 0; i < ime_i_prezime.size(); i++)
    {
        if (!((ime_i_prezime[i] >= 65 && ime_i_prezime[i] <= 90) || (ime_i_prezime[i] >= 97 && ime_i_prezime[i] <= 122) || (ime_i_prezime[i] >= 48 && ime_i_prezime[i] <= 57) || ime_i_prezime[i] == '-' || ime_i_prezime[i] == ' ' || ime_i_prezime[i] == '\''))
            throw std::domain_error("Neispravno ime i prezime");
    }
    
    imeIPrezime = ime_i_prezime;
}

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
{
    for (int i = 0; i < ime_i_prezime.size(); i++)
    {
        if (!((ime_i_prezime[i] >= 65 && ime_i_prezime[i] <= 90) || (ime_i_prezime[i] >= 97 && ime_i_prezime[i] <= 122) || (ime_i_prezime[i] >= 48 && ime_i_prezime[i] <= 57) || ime_i_prezime[i] == '-' || ime_i_prezime[i] == ' ' || ime_i_prezime[i] == '\''))
            throw std::domain_error("Neispravno ime i prezime");
    }
    
    imeIPrezime = ime_i_prezime;
    datumRodjenja = datum_rodjenja;
}

std::string Kupac::DajImePrezime() const
{
    return imeIPrezime;
}

Datum Kupac::DajDatumRodjenja() const
{
    return datumRodjenja;
}
void Kupac::Ispisi() const
{
    std::cout << imeIPrezime << " ";
    datumRodjenja.Ispisi();
}

//--------------
//--------------
//_____STAN____
class Stan
{
    
private:
    std::string adresaStana;
    int spratStana;
    int brojSoba;
    bool namjestenStan;
    double kvadraturaStana;

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

Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{
    if (sprat < 0 || broj_soba < 0 || kvadratura < 0)
        throw std::domain_error("Neispravan unos podataka");
    
    adresaStana = adresa;
    spratStana = sprat;
    brojSoba = broj_soba;
    namjestenStan = namjesten;
    kvadraturaStana = kvadratura;
}

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{
    if (sprat < 0 || broj_soba < 0 || kvadratura < 0)
        throw std::domain_error("Neispravan unos podataka");
    
    adresaStana = adresa;
    spratStana = sprat;
    brojSoba = broj_soba;
    namjestenStan = namjesten;
    kvadraturaStana = kvadratura;
}

std::string Stan::DajAdresu() const
{
    return adresaStana;
}

int Stan::DajSprat() const
{
    return spratStana;
}

int Stan::DajBrojSoba() const
{
    return brojSoba;
}

bool Stan::DajNamjesten() const
{
    return namjestenStan;
}

double Stan::DajKvadraturu() const
{
    return kvadraturaStana;
}

void Stan::Ispisi() const
{
    std::string pomocni("soba");
    
    if (brojSoba == 1)
        pomocni = "sobu";
    else if (brojSoba == 2 || brojSoba == 3 || brojSoba == 4)
        pomocni = "sobe";
    
    std::cout << "Stan se nalazi na adresi " << adresaStana << " na " << spratStana << " i ima " << brojSoba << " " << pomocni << ". Kvadratura stana je ";
    std::cout << kvadraturaStana << " i stan ";
    
    if (namjestenStan)
        std::cout << "je";
    else
        std::cout << "nije";
        
    std::cout << " namjesten";
}


//--------------
//--------------
//_____Prodaja____
class Prodaja
{

private:
    std::string imeAgenta;
    double cijenaStana;
    Datum datumProdaje;
    Kupac kupacStana;
    Stan kupljeniStan;
    
    bool validanDatum(int dan, int mjesec, int godina);
    
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, 
        const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac);
    void PromijeniStan(const Stan &novi_stan);
    void PromijeniDatumKupovine(const Datum &novi_datum);
    void PromijeniCijenuProdaje(const double &nova_cijena);
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

bool Prodaja::validanDatum(int dan, int mjesec, int godina)
{
    bool prestupna = false;
    
    if (godina % 4 == 0)
        if (godina % 100 == 0)
            if (godina % 400 == 0)
                prestupna = true;
    
    if (dan < 0 || dan > 31)
        return false;
        
    if (mjesec < 0 || mjesec > 12)
        return false;
        
    if (mjesec == 2 && dan > 29)
        return false;
        
    if (mjesec == 2 && dan == 29 && !prestupna)
        return false;
        
    if ((mjesec == 4 || mjesec == 6 || mjesec == 9 || mjesec == 11) && dan > 30)
        return false;
        
    return true;
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan)
    : datumProdaje(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu()), kupacStana(kupac_stana), kupljeniStan(kupljeni_stan)
{
    imeAgenta = ime_agenta_prodaje;
    cijenaStana = cijena_stana;
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, 
        const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
            : datumProdaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupacStana(ime_kupca, datum_rodjenja_kupca), kupljeniStan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)
        {
            imeAgenta = ime_agenta_prodaje;
            cijenaStana = cijena_stana;
        }

void Prodaja::PromijeniKupca(const Kupac &novi_kupac)
{
    kupacStana = novi_kupac;    
}

void Prodaja::PromijeniStan(const Stan &novi_stan)
{
    kupljeniStan = novi_stan;
}

void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum)
{
    datumProdaje = novi_datum;
}

void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena)
{
    cijenaStana = nova_cijena;
}

void Prodaja::PomjeriDanUnaprijed()
{
    if (validanDatum(datumProdaje.DajDan() + 1, datumProdaje.DajMjesec(), datumProdaje.DajGodinu()))
        datumProdaje.Postavi(datumProdaje.DajDan() + 1, datumProdaje.DajMjesec(), datumProdaje.DajGodinu());
    else if (validanDatum(1, datumProdaje.DajMjesec() + 1, datumProdaje.DajGodinu()))
        datumProdaje.Postavi(1, datumProdaje.DajMjesec() + 1, datumProdaje.DajGodinu());
    else
            datumProdaje.Postavi(1, 1, datumProdaje.DajGodinu() + 1);
        
}

void Prodaja::PomjeriDanUnazad()
{
    if (validanDatum(datumProdaje.DajDan() - 1, datumProdaje.DajMjesec(), datumProdaje.DajGodinu()))
        datumProdaje.Postavi(datumProdaje.DajDan() - 1, datumProdaje.DajMjesec(), datumProdaje.DajGodinu());
    else if (validanDatum(31, datumProdaje.DajMjesec() - 1, datumProdaje.DajGodinu()))
        datumProdaje.Postavi(31, datumProdaje.DajMjesec() - 1, datumProdaje.DajGodinu());
    else if (validanDatum(30, datumProdaje.DajMjesec() - 1, datumProdaje.DajGodinu()))
        datumProdaje.Postavi(30, datumProdaje.DajMjesec() - 1, datumProdaje.DajGodinu());
    else if (validanDatum(29, datumProdaje.DajMjesec() - 1, datumProdaje.DajGodinu()))
        datumProdaje.Postavi(29, datumProdaje.DajMjesec() - 1, datumProdaje.DajGodinu());
    else if (validanDatum(28, datumProdaje.DajMjesec() - 1, datumProdaje.DajGodinu()))
        datumProdaje.Postavi(28, datumProdaje.DajMjesec() - 1, datumProdaje.DajGodinu());
    else
            datumProdaje.Postavi(31, 12, datumProdaje.DajGodinu() - 1);    
}

std::string Prodaja::DajImeAgenta() const
{
    return imeAgenta;
}

std::string Prodaja::DajImeKupca() const
{
    return kupacStana.DajImePrezime();
}

Datum Prodaja::DajDatumProdaje() const
{
    return datumProdaje;    
}

double Prodaja::DajCijenuStana() const
{
    return cijenaStana;    
}
   
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    if (p2.datumProdaje.DajGodinu() < p1.datumProdaje.DajGodinu())
        return false;
    else if (p2.datumProdaje.DajGodinu() == p1.datumProdaje.DajGodinu() && p2.datumProdaje.DajMjesec() < p1.datumProdaje.DajMjesec())
        return false;
    else if (p2.datumProdaje.DajGodinu() == p1.datumProdaje.DajGodinu() && p2.datumProdaje.DajMjesec() == p1.datumProdaje.DajMjesec() && p2.datumProdaje.DajDan() < p1.datumProdaje.DajDan())
        return false;
        
    return true;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    if (p2.cijenaStana > p1.cijenaStana)
        return false;
        
    return true;
}

void Prodaja::Ispisi() const
{
    std::cout << "Ime agenta: " << imeAgenta << std::endl;
    std::cout << "Ime kupca: " << kupacStana.DajImePrezime() << " ";
    kupacStana.DajDatumRodjenja().Ispisi();
    std::cout << std::endl;
    std::cout << "Zakazani datum prodaje: " << datumProdaje.DajDan() << "/" << datumProdaje.DajMjesec() << "/" << datumProdaje.DajGodinu() << std::endl;
    std::cout << "Cijena stana: " << cijenaStana << std::endl;
    
    std::cout << "Informacije o stanu: " << std::endl;
    kupljeniStan.Ispisi();
}

//--------------
//--------------
//_____Prodaje____
class Prodaje
{

private:
    Prodaja **prodajee;
    int duzinaKolekcije;
    
public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, 
        const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const;
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

 Prodaje::Prodaje(int max_broj_prodaja)
{
    prodajee = new Prodaja*[max_broj_prodaja];
    duzinaKolekcije = max_broj_prodaja;
    
    for (int i = 0; i < duzinaKolekcije; i++)
        prodajee[i] = nullptr;
}

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja)
{
    std::vector<Prodaja> vProdaje(spisak_prodaja);   
    
    int duzina = spisak_prodaja.size();
    duzinaKolekcije = duzina;
    
    prodajee = new Prodaja*[duzina];
    
    for (int i = 0; i < duzinaKolekcije; i++)
        prodajee[i] = new Prodaja(vProdaje[i]);
}


Prodaje::~Prodaje() 
{
    for (int i = 0; i < duzinaKolekcije; i++)
        delete prodajee[i];
        
    delete[] prodajee;
}

//const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan
Prodaje::Prodaje(const Prodaje &prodaje) : duzinaKolekcije(prodaje.duzinaKolekcije) 
{
    prodajee = new Prodaja*[duzinaKolekcije];
    
    for (int i = 0; i < duzinaKolekcije; i++)
    {
        prodajee[i] = new Prodaja(prodaje.prodajee[i]->DajImeAgenta(), prodaje.prodajee[i]->DajCijenuStana(), prodaje.prodajee[i]->DajDatumProdaje(), prodaje.prodajee[i]->DajImeKupca(), prodaje.prodajee[i]->);
    }
}

Prodaje(Prodaje &&prodaje);
Prodaje &operator =(const Prodaje &prodaje);
Prodaje &operator =(Prodaje &&prodaje);
void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, 
const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
void RegistrirajProdaju(Prodaja *prodaja);
int DajBrojProdaja() const;
int DajBrojProdajaNaDatum(const Datum &datum) const;
int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
Prodaja &DajNajranijuProdaju();
Prodaja DajNajranijuProdaju() const;
Prodaja &DajNajskupljuProdaju() const;
Prodaja DajNajskupljuProdaju() const;
void IsprazniKolekciju();
void ObrisiNajranijuProdaju();
void ObrisiProdajeAgenta(const std::string &ime_agenta);
void ObrisiProdajeNaDatum(const Datum &datum);
void IspisiProdajeNaDatum(const Datum &datum) const;
void IspisiSveProdaje() const;










int main ()
{
    
	return 0;
}