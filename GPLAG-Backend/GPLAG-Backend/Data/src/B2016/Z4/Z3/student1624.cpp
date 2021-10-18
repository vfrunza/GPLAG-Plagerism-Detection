#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace::std;

class Datum
{
    int d,m,g;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const
    {
        return d;
    }
    int DajMjesec() const
    {
        return m;
    }
    int DajGodinu() const
    {
        return g;
    }
    void Ispisi() const;
};

Datum::Datum(int dan, int mjesec, int godina)
{
    Postavi(dan,mjesec,godina);
}
void Datum::Postavi(int dan, int mjesec, int godina)
{
    if(mjesec < 1 || mjesec >12)
        throw domain_error("Meispravan datum");
    vector<int> duzina{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(dan < 1 || dan > duzina[mjesec])
        throw domain_error("Neispravan datum");
    d = dan;
    m = mjesec;
    g = godina;
}
void Datum::Ispisi() const
{
        cout << DajDan() << "/" << DajMjesec() << "/" << DajGodinu();
}

class Kupac
{
    string ime;
    Datum dat;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const
    {
        return ime;
    }
    Datum DajDatumRodjenja() const
    {
        return dat;
    }
    void Ispisi() const;
};

Kupac::Kupac(const string &ime_i_prezime,const Datum &datum_rodjenja) : dat(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu())
{
    string smije_imati = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890- ";
    string::iterator it1 = smije_imati.begin();
    string::iterator it2 = smije_imati.end();
    for(int i = 0;i < ime_i_prezime.length();i++)
    {
        if(find(it1,it2,ime_i_prezime[i]) == it2)
            throw domain_error("Neispravno ime i prezime");
    }
    ime = ime_i_prezime;
}
void Kupac::Postavi(const string &ime_i_prezime, const Datum &datum_rodjenja)
{
    string smije_imati = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890- ";
    string::iterator it1 = smije_imati.begin();
    string::iterator it2 = smije_imati.end();
    for(int i = 0;i < ime_i_prezime.length();i++)
    {
        if(find(it1,it2,ime_i_prezime[i]) == it2)
            throw domain_error("Neispravno ime i prezime");
    }
    ime = ime_i_prezime;
    dat.Postavi(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());
}

void Kupac::Ispisi() const
{
    cout << ime << " (";
    dat.Ispisi();
    cout << ")";
}

class Stan
{
   string adresa;
   int sprat,broj_soba;
   bool namjesten;
   double kvadratura;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,
    double kvadratura);
    void Postavi(const std::string &adresa, int sprat, int broj_soba,
    bool namjesten, double kvadratura);
    std::string DajAdresu() const
    {
        return adresa;
    }
    int DajSprat() const
    {
        return sprat;
    }
    int DajBrojSoba() const
    {
        return broj_soba;
    }
    bool DajNamjesten() const
    {
        return namjesten;
    }
    double DajKvadraturu() const
    {
        return kvadratura;
    }
    void Ispisi() const;
};

Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura)
{
    Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
}

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura)
{
    if(sprat < 0 || broj_soba < 0 || kvadratura < 0)
        throw domain_error("Neispravan unos podataka");
    Stan::adresa = adresa;
    Stan::sprat = sprat;
    Stan::broj_soba = broj_soba;
    Stan::namjesten = namjesten;
    Stan::kvadratura = kvadratura;
}

void Stan::Ispisi() const
{
    cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba;
    if(broj_soba %10 == 1)
    {
        cout << " sobu.";
    }
    else if(broj_soba %10 == 2 || broj_soba %10 == 3 || broj_soba %10 == 4)
    {
        cout << " sobe.";
    }
    else
    {
        cout << " soba.";
    }
    cout << endl << "Kvadratura stana je " << kvadratura;
    if(namjesten)
    {
        cout << " i stan je namjesten.";
    }
    else
        cout << "i stan nije namjesten.";
}

class Prodaja
{
    string agent;
    double cijena;
    Datum dat;
    Kupac kupac;
    Stan stan;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac)
    {
        kupac = novi_kupac;
    }
    void PromijeniStan(const Stan &novi_stan)
    {
        stan = novi_stan;
    }
    void PromijeniDatumKupovine(const Datum &novi_datum)
    {
        dat = novi_datum;
    }
    void PromijeniCijenuProdaje(const double &nova_cijena)
    {
        cijena = nova_cijena;
    }
    void PomjeriDanUnaprijed()
    {
        dat.Postavi(dat.DajDan()+1,dat.DajMjesec(),dat.DajGodinu());
    }
    void PomjeriDanUnazad()
    {
        dat.Postavi(dat.DajDan()-1,dat.DajMjesec(),dat.DajGodinu());
    }
    std::string DajImeAgenta() const
    {
        return agent;
    }
    std::string DajImeKupca() const
    {
        return kupac.DajImePrezime();
    }
    Datum DajDatumProdaje() const
    {
        return dat;
    }
    double DajCijenuStana() const
    {
        return cijena;
    }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
    {
        int dan1 = p1.DajDatumProdaje().DajDan();
        int mj1 = p1.DajDatumProdaje().DajMjesec();
        int g1 = p1.DajDatumProdaje().DajGodinu();
        int dan2 = p2.DajDatumProdaje().DajDan();
        int mj2 = p2.DajDatumProdaje().DajMjesec();
        int g2 = p2.DajDatumProdaje().DajGodinu();
        if(g1 > g2)
            return true;
        if(g1 == g2)
        {
            if(mj1 > mj2)
            return true;
            else if(mj1 == mj2)
            {
                if(dan1 > dan2)
                    return true;
            }
        }
        return false;
    }
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
    {
    if(p1.DajCijenuStana() > p2.DajCijenuStana())
        return true;
    return false;
    }
    void Ispisi() const;
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan) :
    dat(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()),
    kupac(kupac_stana),
    stan(kupljeni_stan)
{
    agent = ime_agenta_prodaje;
    cijena = cijena_stana;
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata) : 
    dat(dan_prodaje,mjesec_prodaje,godina_prodaje),
    kupac(ime_kupca,datum_rodjenja_kupca),
    stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata)
    {
        agent = ime_agenta_prodaje;
        cijena = cijena_stana;
    }
void Prodaja::Ispisi() const
{
    cout << "Ime agenta: " << agent << endl;
    cout << "Ime kupca: ";
    kupac.Ispisi();
    cout << endl;
    cout << "Zakazani datum prodaje: ";
    dat.Ispisi();
    cout << endl;
    cout << "Cijena stana: " << cijena << endl;
    cout << "Informacije o stanu:" << endl;
    stan.Ispisi();
}

class Prodaje
{
    int max,dimenzija;
    Prodaja **p;
public:
explicit Prodaje(int max_broj_prodaja)
{
    max = max_broj_prodaja;
    dimenzija = 0;
    p = new Prodaja*[max_broj_prodaja];
}
Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
~Prodaje()
{
    for(int i = 0;i<dimenzija;i++)
    {
        delete p[i];
        p[i] = nullptr;
    }
    delete[] p;
}
Prodaje(const Prodaje &prodaje)
{
    dimenzija = prodaje.DajBrojProdaja();
    p = new Prodaja*[dimenzija];
    copy(prodaje.p,prodaje.p+max,p);
}
Prodaje(Prodaje &&prodaje)
{
    dimenzija = prodaje.DajBrojProdaja();
    p = new Prodaja*[dimenzija];
    copy(prodaje.p,prodaje.p+max,p);
}
Prodaje &operator =(const Prodaje &prodaje);
Prodaje &operator =(Prodaje &&prodaje);
void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
const Stan &kupljeni_stan);
void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena, int dan_prodaje,
int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
void RegistrirajProdaju(Prodaja *prodaja);
int DajBrojProdaja() const
{
    return dimenzija;
}
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

Prodaje::Prodaje(initializer_list<Prodaja> spisak_prodaja)
{
    dimenzija = spisak_prodaja.size();
    auto it = spisak_prodaja.begin();
    for(int i = 0;i < max;i++)
    {
        p[i] = new Prodaja(*it);
        it++;
    }
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,
double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
const Stan &kupljeni_stan)
{
    if(dimenzija >= max)
        throw range_error("Dostignut maksimalni broj prodaja");
    dimenzija++;
    p[dimenzija] = new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena,int dan_prodaje,
int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
{
    if(dimenzija >= max)
        throw range_error("Dostignut maksimalni broj prodaja");
    dimenzija++;
    Datum d(dan_prodaje,mjesec_prodaje,godina_prodaje);
    Stan s(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
    Kupac k(ime_kupca,datum_rodjenja_kupca);
    p[dimenzija] = new Prodaja(ime_agenta_prodaje,cijena,d,k,s);
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja)
{
    if(dimenzija >= max)
        throw range_error("Dostignut maksimalni broj prodaja");
    dimenzija++;
    p[dimenzija] = prodaja;
}
int main()
{
    return 0;
}