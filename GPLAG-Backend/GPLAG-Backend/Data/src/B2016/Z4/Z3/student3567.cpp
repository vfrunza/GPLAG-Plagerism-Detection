/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

class Datum
{
    int Dan, Mjesec, Godina;
public:
    Datum(int dan, int mjesec, int godina)
    {
        Postavi(dan, mjesec, godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const
    {
        return Dan;
    }
    int DajMjesec() const
    {
        return Mjesec;
    }
    int DajGodinu() const
    {
        return Godina;
    }
    void Ispisi() const
    {
        cout << Dan << "/" << Mjesec << "/" << Godina;
    }
};

void Datum::Postavi(int dan, int mjesec, int godina)
{
    int brojDana[12]
    {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) brojDana[1]++;
    if (godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > brojDana[mjesec - 1])
        throw domain_error("Neispravan datum");
    Dan = dan;
    Mjesec = mjesec;
    Godina = godina;
}

class Kupac
{
    string imePrezime;
    Datum datumRodjenja;
public:
    Kupac(const std::string & ime_i_prezime,
          const Datum & datum_rodjenja): datumRodjenja(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu())
    {
        bool validan = true;
        for (int i = 0; i < ime_i_prezime.length(); i++)
        {
            if (!(ime_i_prezime[i] >= 'a' && ime_i_prezime[i] <= 'z' || ime_i_prezime[i] >= 'A' && ime_i_prezime[i] <= 'Z' || ime_i_prezime[i] >= '0' && ime_i_prezime[i] <= '9' ||
                    ime_i_prezime[i] == '-' || ime_i_prezime[i] == '\'' || ime_i_prezime[i] == ' '))
            {
                validan = false;
                break;
            }
        }

        if (!validan)
            throw domain_error("Neispravno ime i prezime");

        imePrezime = ime_i_prezime;
    }
    void Postavi(const std::string & ime_i_prezime,
                 const Datum & datum_rodjenja);
    std::string DajImePrezime() const
    {
        return imePrezime;
    }
    Datum DajDatumRodjenja() const
    {
        return datumRodjenja;
    }
    void Ispisi() const
    {
        cout << imePrezime << " (";
        datumRodjenja.Ispisi();
        cout << ")";
    }
};

void Kupac::Postavi(const std::string & ime_i_prezime,
                    const Datum & datum_rodjenja)
{
    bool validan = true;
    for (int i = 0; i < ime_i_prezime.length(); i++)
    {
        if (!(ime_i_prezime[i] >= 'a' && ime_i_prezime[i] <= 'z' || ime_i_prezime[i] >= 'A' && ime_i_prezime[i] <= 'Z' || ime_i_prezime[i] >= '0' && ime_i_prezime[i] <= '9' ||
                ime_i_prezime[i] == '-' || ime_i_prezime[i] == '\'' || ime_i_prezime[i] == ' '))
        {
            validan = false;
            break;
        }
    }

    if (!validan)
        throw domain_error("Neispravno ime i prezime");

    move(ime_i_prezime.begin(), ime_i_prezime.end(), imePrezime.begin());
    datumRodjenja.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
}

class Stan
{
    string Adresa;
    int Sprat;
    int brojSoba;
    bool Namjesten;
    double Kvadratura;
public:
    Stan(const std::string & adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
    {
        Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
    }
    void Postavi(const std::string & adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const
    {
        return Adresa;
    }
    int DajSprat() const
    {
        return Sprat;
    }
    int DajBrojSoba() const
    {
        return brojSoba;
    }
    bool DajNamjesten() const
    {
        return Namjesten;
    }
    double DajKvadraturu() const
    {
        return Kvadratura;
    }
    void Ispisi() const;
};

void Stan::Postavi(const std::string & adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{
    if (sprat < 0 || broj_soba < 0 || kvadratura < 0)
        throw domain_error("Neispravan unos podataka");
    Adresa = adresa;
    Sprat = sprat;
    brojSoba = broj_soba;
    Namjesten = namjesten;
    Kvadratura = kvadratura;
}

void Stan::Ispisi() const
{
    string n, s;

    if (Namjesten) n = "je namjesten";
    else n = "nije namjesten";

    if (brojSoba % 10 == 1) s = "sobu";
    else if (brojSoba % 10 == 2 || brojSoba % 10 == 3 || brojSoba % 10 == 4) s = "sobe";
    else s = "soba";

    cout << "Stan se nalazi na adresi " << Adresa << " na " << Sprat << ". spratu i ima " << brojSoba << " " << s << ". Kvadratura stana je " << Kvadratura << " (m^2) i stan " << n << "." << endl;
}

class Prodaja
{
    string imeAgentaProdaje;
    double cijenaStana;
    Datum datumProdaje;
    Kupac kupacStana;
    Stan kupljeniStan;
public:
    Prodaja(const std::string & ime_agenta_prodaje, double cijena_stana,
            const Datum & datum_prodaje,
            const Kupac & kupac_stana,
            const Stan & kupljeni_stan): imeAgentaProdaje(ime_agenta_prodaje),
        cijenaStana(cijena_stana), datumProdaje(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu()), kupacStana(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja()),
        kupljeniStan(kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(), kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu()) {}
    Prodaja(const std::string & ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string & ime_kupca,
            const Datum & datum_rodjenja_kupca,
            const std::string & adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata):
        imeAgentaProdaje(ime_agenta_prodaje), cijenaStana(cijena_stana), datumProdaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupacStana(ime_kupca, datum_rodjenja_kupca), kupljeniStan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {}
    void PromijeniKupca(const Kupac & novi_kupac)
    {
        kupacStana = novi_kupac;
        //kupacStana.Postavi(novi_kupac.DajImePrezime(), novi_kupac.DajDatumRodjenja());
    }
    void PromijeniStan(const Stan & novi_stan)
    {
        kupljeniStan = novi_stan;
    }
    void PromijeniDatumKupovine(const Datum & novi_datum)
    {
        datumProdaje = novi_datum;
    }
    void PromijeniCijenuProdaje(const double & nova_cijena)
    {
        cijenaStana = nova_cijena;
    }
    void PromijeniAgentaProdaje(string noviAgent)
    {
        imeAgentaProdaje = noviAgent;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const
    {
        return imeAgentaProdaje;
    }
    std::string DajImeKupca() const
    {
        return kupacStana.DajImePrezime();
    }
    Datum DajDatumProdaje() const
    {
        return datumProdaje;
    }
    double DajCijenuStana() const
    {
        return cijenaStana;
    }
    friend bool ProdatPrije(const Prodaja & p1,
                            const Prodaja & p2);
    friend bool SkupljiStan(const Prodaja & p1,
                            const Prodaja & p2);
    void Ispisi() const;
};

bool ProdatPrije(const Prodaja & p1,
                 const Prodaja & p2)
{
    int d1, m1, g1, d2, m2, g2;
    bool prodatPrije = false;

    d1 = p1.DajDatumProdaje().DajDan();
    m1 = p1.DajDatumProdaje().DajMjesec();
    g1 = p1.DajDatumProdaje().DajGodinu();
    d2 = p2.DajDatumProdaje().DajDan();
    m2 = p2.DajDatumProdaje().DajMjesec();
    g2 = p2.DajDatumProdaje().DajGodinu();

    if (g1 < g2) prodatPrije = true;
    else if (g1 == g2)
    {
        if (m1 < m2) prodatPrije = true;
        else if (m1 == m2)
        {
            if (d1 < d2) prodatPrije = true;
        }
    }

    return prodatPrije;
}

bool SkupljiStan(const Prodaja & p1,
                 const Prodaja & p2)
{
    return (p1.DajCijenuStana() < p2.DajCijenuStana());
}

void Prodaja::PomjeriDanUnaprijed()
{
    int dan, mjesec, godina;

    dan = datumProdaje.DajDan();
    mjesec = datumProdaje.DajMjesec();
    godina = datumProdaje.DajGodinu();

    int brojDana[12]
    {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) brojDana[1]++;
    dan++;
    if (dan == brojDana[mjesec - 1] + 1)
    {
        dan = 1;
        mjesec++;
    }
    if (mjesec == 13)
    {
        mjesec = 1;
        godina++;
    }

    datumProdaje.Postavi(dan, mjesec, godina);
}

void Prodaja::PomjeriDanUnazad()
{
    int dan, mjesec, godina;

    dan = datumProdaje.DajDan();
    mjesec = datumProdaje.DajMjesec();
    godina = datumProdaje.DajGodinu();

    int brojDana[12]
    {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) brojDana[1]++;
    dan--;
    if (dan == 0)
    {
        if (mjesec == 1)
        {
            mjesec = 12;
            godina--;
        }
        else mjesec--;
        dan = brojDana[mjesec - 1];
    }

    datumProdaje.Postavi(dan, mjesec, godina);
}

void Prodaja::Ispisi() const
{
    cout << setw(32) << setfill(' ') << left << "Ime agenta: " << imeAgentaProdaje << endl;
    cout << setw(32) << setfill(' ') << left << "Ime kupca: ";
    kupacStana.Ispisi();
    cout << endl;
    cout << setw(32) << setfill(' ') << left << "Zakazani datum prodaje:";
    datumProdaje.Ispisi();
    cout << endl;
    cout << setw(32) << setfill(' ') << left << "Cijena stana: " << cijenaStana << endl;
    cout << setw(32) << setfill(' ') << left << "Informacije o stanu:" << endl;
    kupljeniStan.Ispisi();
    cout << endl;
}

class Prodaje
{
    int brojProdaja, maxProdaja;
    Prodaja ** sveProdaje;
public:
    explicit Prodaje(int max_broj_prodaja): brojProdaja(0), maxProdaja(max_broj_prodaja), sveProdaje(new Prodaja * [max_broj_prodaja]) {}
    Prodaje(std::initializer_list < Prodaja > spisak_prodaja): brojProdaja(spisak_prodaja.size()), maxProdaja(spisak_prodaja.size()), sveProdaje(new Prodaja * [spisak_prodaja.size()])
    {
        auto it = spisak_prodaja.begin();
        for (int i = 0; i < spisak_prodaja.size(); i++)
        {
            sveProdaje[i] = new Prodaja( * it);
            it++;
        }
    }~Prodaje()
    {
        for (int i = 0; i < brojProdaja; i++) delete sveProdaje[i];
        delete[] sveProdaje;
    }
    Prodaje(const Prodaje & prodaje): sveProdaje(new Prodaja * [prodaje.maxProdaja]), maxProdaja(prodaje.maxProdaja), brojProdaja(prodaje.brojProdaja)
    {
        for (int i = 0; i < prodaje.brojProdaja; i++) sveProdaje[i] = new Prodaja( * prodaje.sveProdaje[i]);
    }
    Prodaje(Prodaje && prodaje): sveProdaje(prodaje.sveProdaje), maxProdaja(prodaje.maxProdaja), brojProdaja(prodaje.brojProdaja)
    {
        prodaje.sveProdaje = nullptr;
        prodaje.brojProdaja = 0;
    }
    Prodaje & operator = (const Prodaje & prodaje)
    {
        if ( & prodaje == this) return *this;

        for (int i = 0; i < brojProdaja; i++) delete sveProdaje[i];
        delete[] sveProdaje;
        maxProdaja = prodaje.maxProdaja;
        brojProdaja = prodaje.brojProdaja;
        sveProdaje = new Prodaja * [prodaje.maxProdaja];
        for (int i = 0; i < brojProdaja; i++) sveProdaje[i] = new Prodaja( * (prodaje.sveProdaje[i]));

        return *this;
    }
    Prodaje & operator = (Prodaje && prodaje)
    {
        if ( & prodaje == this) return *this;

        for (int i = 0; i < brojProdaja; i++) delete sveProdaje[i];
        delete[] sveProdaje;
        sveProdaje = prodaje.sveProdaje;
        brojProdaja = prodaje.brojProdaja;
        maxProdaja = prodaje.maxProdaja;
        prodaje.sveProdaje = nullptr;
        prodaje.brojProdaja = 0;

        return *this;
    }
    void RegistrirajProdaju(const std::string & ime_agenta_prodaje, double cijena_stana,
                            const Datum & datum_prodaje,
                            const Kupac & kupac_stana,
                            const Stan & kupljeni_stan);
    void RegistrirajProdaju(const std::string & ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string & ime_kupca,
                            const Datum & datum_rodjenja_kupca,
                            const std::string & adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja * prodaja);
    int DajBrojProdaja() const
    {
        return brojProdaja;
    }
    int DajBrojProdajaNaDatum(const Datum & datum) const;
    int DajBrojProdajaOdAgenta(const std::string & ime_agenta) const;
    Prodaja & DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja & DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    Prodaja & DajProdaju(int indeks)
    {
        if (indeks < 0 || indeks > brojProdaja)
            throw range_error("Nije ispravan");
        return *sveProdaje[indeks - 1];
    }
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string & ime_agenta);
    void ObrisiProdajeNaDatum(const Datum & datum); //
    void IspisiProdajeNaDatum(const Datum & datum) const;
    void IspisiSveProdaje() const;
};

void Prodaje::RegistrirajProdaju(const std::string & ime_agenta_prodaje, double cijena_stana,
                                 const Datum & datum_prodaje,
                                 const Kupac & kupac_stana,
                                 const Stan & kupljeni_stan)
{
    if (brojProdaja == maxProdaja)
        throw range_error("Dostignut maksimalni broj prodaja");

    Prodaja * prodaja = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
    sveProdaje[brojProdaja] = prodaja;
    brojProdaja++;
}

void Prodaje::RegistrirajProdaju(const std::string & ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string & ime_kupca,
                                 const Datum & datum_rodjenja_kupca,
                                 const std::string & adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
{
    if (brojProdaja == maxProdaja)
        throw range_error("Dostignut maksimalni broj prodaja");

    Prodaja * prodaja = new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
    sveProdaje[brojProdaja] = prodaja;
    brojProdaja++;
}

void Prodaje::RegistrirajProdaju(Prodaja * prodaja)
{
    if (brojProdaja == maxProdaja)
        throw range_error("Dostignut maksimalni broj prodaja");

    sveProdaje[brojProdaja] = prodaja;
    brojProdaja++;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum & datum) const
{
    int brojac = count_if(sveProdaje, sveProdaje + brojProdaja, [ & ](Prodaja * p)
    {
        return (p-> DajDatumProdaje().DajDan() == datum.DajDan() && p-> DajDatumProdaje().DajMjesec() == datum.DajMjesec() &&
                p-> DajDatumProdaje().DajGodinu() == datum.DajGodinu());
    });

    return brojac;
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string & ime_agenta) const
{
    int brojac = count_if(sveProdaje, sveProdaje + brojProdaja, [ & ](Prodaja * p)
    {
        return (p->DajImeAgenta() == ime_agenta);
    });

    return brojac;
}

Prodaja & Prodaje::DajNajranijuProdaju()
{
    if (brojProdaja == 0)
        throw domain_error("Nema registriranih prodaja");

    Prodaja * najranija = * min_element(sveProdaje, sveProdaje + brojProdaja, [](Prodaja * p1, Prodaja * p2)
    {
        return ProdatPrije( * p1, * p2);
    });
    return *najranija;
}

Prodaja Prodaje::DajNajranijuProdaju() const
{
    if (brojProdaja == 0)
        throw domain_error("Nema registriranih prodaja");

    Prodaja * najranija = * min_element(sveProdaje, sveProdaje + brojProdaja, [](Prodaja * p1, Prodaja * p2)
    {
        return ProdatPrije( * p1, * p2);
    });

    return *najranija;
}

Prodaja & Prodaje::DajNajskupljuProdaju()
{
    if (brojProdaja == 0)
        throw domain_error("Nema registriranih prodaja");

    Prodaja * najskuplja = * max_element(sveProdaje, sveProdaje + brojProdaja, [](Prodaja * p1, Prodaja * p2)
    {
        return SkupljiStan( * p1, * p2);
    });

    return *najskuplja;
}

Prodaja Prodaje::DajNajskupljuProdaju() const
{
    if (brojProdaja == 0)
        throw domain_error("Nema registriranih prodaja");

    Prodaja * najskuplja = * max_element(sveProdaje, sveProdaje + brojProdaja, [](Prodaja * p1, Prodaja * p2)
    {
        return SkupljiStan( * p1, * p2);
    });

    return *najskuplja;
}

void Prodaje::IsprazniKolekciju()
{
    for_each(sveProdaje, sveProdaje + brojProdaja, [](Prodaja * p)->void
    {
        delete p;
    });
    brojProdaja = 0;
}

void Prodaje::ObrisiNajranijuProdaju()
{
    if (brojProdaja == 0)
        throw range_error("Prazna kolekcija");

    Prodaja najranija = DajNajranijuProdaju();

    for (int i = 0; i < brojProdaja; i++)
    {
        if (sveProdaje[i]->DajDatumProdaje().DajDan() == najranija.DajDatumProdaje().DajDan() &&
                sveProdaje[i]->DajDatumProdaje().DajMjesec() == najranija.DajDatumProdaje().DajMjesec() &&
                sveProdaje[i]->DajDatumProdaje().DajGodinu() == najranija.DajDatumProdaje().DajGodinu())
        {
            delete sveProdaje[i];
            sveProdaje[i] = nullptr;
            for (int j = i; j < brojProdaja - 1; j++) * sveProdaje[j] = * sveProdaje[j + 1];
            brojProdaja--;
            i--;
        }
    }
}

void Prodaje::ObrisiProdajeAgenta(const std::string & ime_agenta)
{
    for (int i = 0; i < brojProdaja; i++)
    {
        if (ime_agenta == sveProdaje[i]->DajImeAgenta())
        {
            delete sveProdaje[i];
            sveProdaje[i] = nullptr;
            for (int j = i; j < brojProdaja - 1; j++) sveProdaje[j] = sveProdaje[j + 1];
            brojProdaja--;
            i--;
        }
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum & datum)
{
    for (int i = 0; i < brojProdaja; i++)
    {
        if (datum.DajDan() == sveProdaje[i]->DajDatumProdaje().DajDan() &&
                datum.DajMjesec() == sveProdaje[i]->DajDatumProdaje().DajMjesec() &&
                datum.DajGodinu() == sveProdaje[i]->DajDatumProdaje().DajGodinu())
        {
            delete sveProdaje[i];
            sveProdaje[i] = nullptr;
            for (int j = i; j < brojProdaja - 1; j++) sveProdaje[j] = sveProdaje[j + 1];
            brojProdaja--;
            i--;
        }
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum & datum) const
{
    sort(sveProdaje, sveProdaje + brojProdaja, [](Prodaja * p1, Prodaja * p2)
    {
        int a = p1->DajImeKupca().compare(p2->DajImeKupca());
        if (a < 0) return true;
        else return false;
    });

    for (int i = 0; i < brojProdaja; i++)
    {
        if (datum.DajDan() == sveProdaje[i]->DajDatumProdaje().DajDan() &&
                datum.DajMjesec() == sveProdaje[i]->DajDatumProdaje().DajMjesec() &&
                datum.DajGodinu() == sveProdaje[i]->DajDatumProdaje().DajGodinu())
            sveProdaje[i]->Ispisi();
    }
}
void Prodaje::IspisiSveProdaje() const
{
    sort(sveProdaje, sveProdaje + brojProdaja, [](Prodaja * p1, Prodaja * p2)
    {
        int a = p1->DajImeKupca().compare(p2->DajImeKupca());
        if (a < 0) return true;
        else return false;
    });
    
    sort(sveProdaje, sveProdaje + brojProdaja, [](Prodaja * p1, Prodaja * p2)
    {
        return ProdatPrije( * p1, * p2);
    });

    for (int i = 0; i < brojProdaja; i++)
        sveProdaje[i]->Ispisi();
}

int main()
{
    int izbor, podIzbor, podPodIzbor, sprat, brojSoba, namjesten, izborStana, danRodjenja, mjesecRodjenja, godinaRodjenja, izborKupca, danProdaje, mjesecProdaje, godinaProdaje, izborProdaje, podPodPodIzbor;
    double kvadratura, cijenaStana;
    char znak;
    bool Namjesten = false;
    string adresa, imeKupca, imeAgenta;
    vector<Stan> stanovi;
    vector<Kupac> kupci;
    Prodaje prodaje(20);


    cout << "Dobrodosli!" << endl << endl;
    for (;;)
    {
        cout << "Izaberite opciju:" << endl << " 0 - kraj" << endl << " 1 - uredjivanje stanova" << endl << " 2 - uredjivanje kupaca" << endl << " 3 - uredjivanje prodaja" << endl;
        cin >> izbor;

        Namjesten = false;

        if (izbor == 0) break;
        else if (izbor == 1)
        {
            cin.ignore(10000, '\n');
            for (;;)
            {
                Namjesten = false;
                cout << "Izaberite opciju:" << endl << " 0 - nazad" << endl << " 1 - dodavanje stana" << endl << " 2 - uredjivanje stanova" << endl << " 3 - ispis svih stanova" << endl << " 4 - kraj" << endl;
                cin >> podIzbor;

                if (podIzbor == 0)
                    break;
                else if (podIzbor == 1)
                {
                    //cin.ignore(10000, '\n');
                    for (;;)
                    {
                        cin.ignore(10000, '\n');
                        cout << "Unesite adresu: ";
                        getline(cin, adresa);
                        //cin.ignore(10000, '\n');
                        cout << "Unesite sprat: ";
                        cin >> sprat;
                        cout << "Unesite broj soba: ";
                        cin >> brojSoba;
                        cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                        cin >> namjesten;
                        cout << "Unesite kvadraturu: ";
                        cin >> kvadratura;

                        if (namjesten != 0 && namjesten != 1)
                            cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << endl;
                        else
                        {
                            try
                            {
                                if (namjesten == 1) Namjesten = true;
                                Stan novi(adresa, sprat, brojSoba, Namjesten, kvadratura);
                                cout << "Stan je uspjesno dodan!" << endl;
                                stanovi.push_back(novi);
                                break;
                            }
                            catch (domain_error e)
                            {
                                cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << endl;
                            }
                        }
                    }
                }
                else if (podIzbor == 2)
                {
                    cin.ignore(10000, '\n');
                    cout << "Odaberite stan. Dostupni stanovi su: " << endl;
                    for (int i = 0; i < stanovi.size(); i++)
                    {
                        cout << " " << i + 1 << " - ";
                        stanovi[i].Ispisi();
                    }
                    cin >> izborStana;

                    cout << "Odaberite polje koje zelite urediti: " << endl << " 0 - nazad" << endl << " 1 - adresa" << endl << " 2 - sprat" << endl << " 3 - broj soba" << endl << " 4 - da li je stan namjesten" << endl << " 5 - kvadratura" << endl << " 6 - sve" << endl;
                    cin >> podPodIzbor;

                    if (podPodIzbor == 0)
                        break;
                    else if (podPodIzbor == 1)
                    {
                        cin.ignore(10000, '\n');
                        for (;;)
                        {
                            cout << "Unesite adresu: ";
                            getline(cin, adresa);
                            //cin.ignore(10000, '\n');
                            sprat = stanovi[izborStana - 1].DajSprat();
                            brojSoba = stanovi[izborStana - 1].DajBrojSoba();
                            Namjesten = stanovi[izborStana - 1].DajNamjesten();
                            kvadratura = stanovi[izborStana - 1].DajKvadraturu();
                            try
                            {
                                stanovi[izborStana - 1].Postavi(adresa, sprat, brojSoba, Namjesten, kvadratura);
                                cout << "Stan je uspjesno izmijenjen!" << endl;
                                break;
                            }
                            catch (domain_error e)
                            {
                                cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << endl;
                            }
                        }
                    }
                    else if (podPodIzbor == 2)
                    {
                        for(;;)
                        {
                            cout << "Unesite sprat: ";
                            cin >> sprat;
                            adresa = stanovi[izborStana - 1].DajAdresu();
                            brojSoba = stanovi[izborStana - 1].DajBrojSoba();
                            Namjesten = stanovi[izborStana - 1].DajNamjesten();
                            kvadratura = stanovi[izborStana - 1].DajKvadraturu();
                            try
                            {
                                stanovi[izborStana - 1].Postavi(adresa, sprat, brojSoba, Namjesten, kvadratura);
                                cout << "Stan je uspjesno izmijenjen!" << endl;
                                break;
                            }
                            catch (domain_error e)
                            {
                                cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << endl;
                            }
                        }
                    }
                    else if (podPodIzbor == 3)
                    {
                        for(;;)
                        {
                            cout << "Unesite broj soba: ";
                            cin >> brojSoba;
                            adresa = stanovi[izborStana - 1].DajAdresu();
                            sprat = stanovi[izborStana - 1].DajSprat();
                            Namjesten = stanovi[izborStana - 1].DajNamjesten();
                            kvadratura = stanovi[izborStana - 1].DajKvadraturu();
                            try
                            {
                                stanovi[izborStana - 1].Postavi(adresa, sprat, brojSoba, Namjesten, kvadratura);
                                cout << "Stan je uspjesno izmijenjen!" << endl;
                                break;
                            }
                            catch (domain_error e)
                            {
                                cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << endl;
                            }
                        }
                    }
                    else if (podPodIzbor == 4)
                    {
                        for(;;)
                        {
                            cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                            cin >> namjesten;
                            adresa = stanovi[izborStana - 1].DajAdresu();
                            sprat = stanovi[izborStana - 1].DajSprat();
                            brojSoba = stanovi[izborStana - 1].DajBrojSoba();
                            kvadratura = stanovi[izborStana - 1].DajKvadraturu();

                            if (namjesten != 0 && namjesten != 1)
                                cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << endl;
                            else
                            {
                                try
                                {
                                    if (namjesten == 1) Namjesten = true;
                                    stanovi[izborStana - 1].Postavi(adresa, sprat, brojSoba, Namjesten, kvadratura);
                                    cout << "Stan je uspjesno izmijenjen!" << endl;
                                    break;
                                }
                                catch (domain_error e)
                                {
                                    cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << endl;
                                }
                            }
                        }
                    }
                    else if (podPodIzbor == 5)
                    {
                        for(;;)
                        {
                            cout << "Unesite kvadraturu: ";
                            cin >> kvadratura;
                            adresa = stanovi[izborStana - 1].DajAdresu();
                            sprat = stanovi[izborStana - 1].DajSprat();
                            Namjesten = stanovi[izborStana - 1].DajNamjesten();
                            brojSoba = stanovi[izborStana - 1].DajBrojSoba();
                            try
                            {
                                stanovi[izborStana - 1].Postavi(adresa, sprat, brojSoba, Namjesten, kvadratura);
                                cout << "Stan je uspjesno izmijenjen!" << endl;
                                break;
                            }
                            catch (domain_error e)
                            {
                                cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << endl;
                            }
                        }
                    }
                    else if (podPodIzbor == 6)
                    {
                        for(;;)
                        {
                            cin.ignore(10000, '\n');
                            cout << "Unesite adresu: ";
                            getline(cin, adresa);
                            //cin.ignore(10000, '\n');
                            cout << "Unesite sprat: ";
                            cin >> sprat;
                            cout << "Unesite broj soba: ";
                            cin >> brojSoba;
                            cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                            cin >> namjesten;
                            cout << "Unesite kvadraturu: ";
                            cin >> kvadratura;

                            if (namjesten != 0 && namjesten != 1)
                                cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << endl;
                            else
                            {
                                try
                                {
                                    if (namjesten == 1) Namjesten = true;
                                    stanovi[izborStana - 1].Postavi(adresa, sprat, brojSoba, Namjesten, kvadratura);
                                    cout << "Stan je uspjesno izmijenjen!" << endl;
                                    break;
                                }
                                catch (domain_error e)
                                {
                                    cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << endl;
                                }
                            }
                        }
                    }
                }
                else if (podIzbor == 3)
                {
                    for (int i = 0; i < stanovi.size(); i++)
                    {
                        cout << i + 1 << ". ";
                        stanovi[i].Ispisi();
                    }
                }
                else if(podIzbor == 4) break;

            }
        }
        else if (izbor == 2)
        {
            cin.ignore(10000, '\n');
            for (;;)
            {
                cout << "Izaberite opciju:" << endl << " 0 - nazad" << endl << " 1 - dodavanje kupca" << endl << " 2 - uredjivanje kupaca" << endl << " 3 - ispis svih kupaca" << endl << " 4 - kraj" << endl;
                cin >> podIzbor;

                if (podIzbor == 0) break;
                else if (podIzbor == 1)
                {
                    cin.ignore(1000, '\n');
                    for (;;)
                    {
                        cout << "Unesite ime i prezime kupca: ";
                        getline(cin, imeKupca);
                        //cin.ignore(10000, '\n');
                        cout << "Unesite datum rodjenja (formata d/m/g): ";
                        cin >> danRodjenja >> znak >> mjesecRodjenja >> znak >> godinaRodjenja;
                        try
                        {
                            Datum d(danRodjenja, mjesecRodjenja, godinaRodjenja);
                            Kupac noviKupac(imeKupca, d);
                            cout << "Kupac je uspjesno dodan!" << endl;
                            kupci.push_back(noviKupac);
                            break;
                        }
                        catch (domain_error e)
                        {
                            cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << endl;
                            cin.ignore(1000, '\n');
                        }
                    }
                }
                else if(podIzbor == 2)
                {
                    cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:" << endl;
                    for(int i = 0; i < kupci.size(); i++)
                    {
                        cout << " " << i + 1 << " - ";
                        kupci[i].Ispisi();
                        cout << endl;
                    }
                    cin >> izborKupca;
                    for(;;)
                    {
                        cin.ignore(1000, '\n');
                        cout << "Unesite ime i prezime kupca: ";
                        getline(cin, imeKupca);
                        //cin.ignore(10000, '\n');
                        cout << "Unesite datum rodjenja (formata d/m/g): ";
                        cin >> danRodjenja >> znak >> mjesecRodjenja >> znak >> godinaRodjenja;


                        try
                        {
                            Datum d(danRodjenja, mjesecRodjenja, godinaRodjenja);
                            kupci[izborKupca - 1].Postavi(imeKupca, d);
                            cout << "Kupac je uspjesno izmijenjen!" << endl;
                            break;
                        }
                        catch (domain_error e)
                        {
                            cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << endl;
                            cin.ignore(10000, '\n');
                        }
                    }
                }
                else if(podIzbor == 3)
                {
                    for(int i = 0; i < kupci.size(); i++)
                    {
                        kupci[i].Ispisi();
                        cout << endl;
                    }
                }
                else if(podIzbor == 4) break;
            }
        }
        else if(izbor == 3)
        {
            cin.ignore(10000, '\n');
            for(;;)
            {
                cout << "Izaberite opciju:" << endl << " 0 - nazad" << endl << " 1 - dodavanje prodaje" << endl << " 2 - uredjivanje prodaje" << endl << " 3 - ispis prodaja" << endl << " 4 - brisanje prodaja" << endl << " 5 - kraj" << endl;
                cin >> podIzbor;

                if(podIzbor == 0)
                    break;
                else if(podIzbor == 1)
                {
                    for(;;)
                    {
                        cin.ignore(10000, '\n');
                        cout << "Izaberite opciju:" << endl << " 0 - nazad" << endl << " 1 - dodavanje potpuno nove prodaje" << endl << " 2 - dodavanje nove prodaje na osnovu arhive" << endl << " 3 - kraj" << endl;
                        cin >> podPodIzbor;

                        if(podPodIzbor == 0)
                            break;
                        else if(podPodIzbor == 1)
                        {
                            for(;;)
                            {
                                Namjesten = false;
                                cin.ignore(10000, '\n');
                                cout << "Unesite ime i prezime agenta prodaje: ";
                                getline(cin, imeAgenta);
                                cout << "Unesite datum prodaje (formata d/m/g): ";
                                cin >> danProdaje >> znak >> mjesecProdaje >> znak >> godinaProdaje;
                                cout << "Unesite cijenu stana: ";
                                cin >> cijenaStana;
                                cin.ignore(10000, '\n');
                                cout << "Unesite ime kupca: ";
                                getline(cin, imeKupca);
                                //cin.ignore(10000, '\n');
                                cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
                                cin >> danRodjenja >> znak >> mjesecRodjenja >> znak >> godinaRodjenja;
                                cin.ignore(10000, '\n');
                                cout << "Unesite adresu: ";
                                getline(cin, adresa);
                                //cin.ignore(10000, '\n');
                                cout << "Unesite sprat: ";
                                cin >> sprat;
                                cout << "Unesite broj soba: ";
                                cin >> brojSoba;
                                cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                cin >> namjesten;
                                cout << "Unesite kvadraturu: ";
                                cin >> kvadratura;

                                if (namjesten != 0 && namjesten != 1)
                                    cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << endl;
                                else
                                {
                                    try
                                    {
                                        if (namjesten == 1) Namjesten = true;
                                        Datum dr(danRodjenja, mjesecRodjenja, godinaRodjenja), dp(danProdaje, mjesecProdaje, godinaProdaje);
                                        Stan novi(adresa, sprat, brojSoba, Namjesten, kvadratura);
                                        stanovi.push_back(novi);
                                        Kupac noviKupac(imeKupca, dr);
                                        kupci.push_back(noviKupac);
                                        prodaje.RegistrirajProdaju(imeAgenta, cijenaStana, dp, noviKupac, novi);
                                        cout << "Prodaja uspjesno dodana!" << endl;
                                        break;
                                    }
                                    catch (domain_error e)
                                    {
                                        cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << endl;
                                    }
                                }
                            }
                        }
                        else if(podPodIzbor == 2)
                        {
                            cin.ignore(10000, '\n');
                            for(;;)
                            {
                                cout << "Unesite ime i prezime agenta prodaje: ";
                                getline(cin, imeAgenta);
                                cout << "Unesite datum prodaje (formata d/m/g): ";
                                cin >> danProdaje >> znak >> mjesecProdaje >> znak >> godinaProdaje;
                                cout << "Unesite cijenu stana: ";
                                cin >> cijenaStana;
                                cout << "Odaberite kupca. Dostupni kupci su:" << endl;
                                for(int i = 0; i < kupci.size(); i++)
                                {
                                    cout << " " << i + 1 << " - ";
                                    kupci[i].Ispisi();
                                    cout << endl;
                                }
                                cin >> izborKupca;

                                cout << "Odaberite stan. Dostupni stanovi su: " << endl;
                                for (int i = 0; i < stanovi.size(); i++)
                                {
                                    cout << " " << i + 1 << " - ";
                                    stanovi[i].Ispisi();
                                }
                                cin >> izborStana;

                                try
                                {
                                    Datum dp(danProdaje, mjesecProdaje, godinaProdaje);
                                    Stan stan = stanovi[izborStana - 1];
                                    Kupac kupac = kupci[izborKupca - 1];
                                    prodaje.RegistrirajProdaju(imeAgenta, cijenaStana, dp, kupac, stan);
                                    cout << "Prodaja uspjesno dodana!" << endl;
                                    break;
                                }
                                catch (domain_error e)
                                {
                                    cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << endl;
                                }
                            }
                        }
                        else if(podPodIzbor == 3)
                            break;
                    }

                }
                else if(podIzbor == 2)
                {
                    cout << "Odaberite prodaju koju želite urediti. Dostupne prodaje su:" << endl;
                    for(int i = 1; i <= prodaje.DajBrojProdaja(); i++)
                    {
                        cout << i  << "." << endl;
                        prodaje.DajProdaju(i).Ispisi();
                    }
                    cin >> izborProdaje;


                    cout << "Izaberite opciju:" << endl << " 0 - nazad" << endl << " 1 - izmjena agenta" << endl << " 2 - izmjena datuma prodaje" << endl << " 3 - izmjena kupca" << endl <<" 4 - izmjena stana" << endl << " 5 - izmjena cijene stana" << endl;
                    cin >> podPodIzbor;


                    if(podPodIzbor == 0)
                        break;
                    else if(podPodIzbor == 1) // popravit
                    {
                        cin.ignore(1000, '\n');
                        cout << "Unesite ime i prezime agenta prodaje: ";
                        getline(cin, imeAgenta);
                        //cin.ignore(10000, '\n');
                        prodaje.DajProdaju(izborProdaje).PromijeniAgentaProdaje(imeAgenta);
                        cout << "Prodaja je uspjesno izmijenjena!" << endl;
                    }
                    else if(podPodIzbor == 2)
                    {
                        for(;;)
                        {
                            cout << "Unesite datum prodaje (formata d/m/g): ";
                            cin >> danProdaje >> znak >> mjesecProdaje >> znak >> godinaProdaje;
                            try
                            {
                                Datum dp(danProdaje, mjesecProdaje, godinaProdaje);
                                prodaje.DajProdaju(izborProdaje).PromijeniDatumKupovine(dp);
                                cout << "Prodaja je uspjesno izmijenjena!" << endl;
                                break;
                            }
                            catch(domain_error e)
                            {
                                cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << endl;
                            }
                        }
                    }
                    else if(podPodIzbor == 3)
                    {


                        cout << "Izaberite opciju:" << endl << " 0 - nazad" << endl << " 1 - odabir postojeceg kupca" << endl << " 2 - dodavanje novog kupca" << endl;
                        cin >> podPodPodIzbor;

                        if(podPodPodIzbor == 0)
                            break;
                        else if(podPodPodIzbor == 1)
                        {
                            cout << "Odaberite kupca. Dostupni kupci su:" << endl;
                            for(int i = 0; i < kupci.size(); i++)
                            {
                                cout << " " << i + 1 << " - ";
                                kupci[i].Ispisi();
                                cout << endl;
                            }
                            cin >> izborKupca;
                            prodaje.DajProdaju(izborProdaje).PromijeniKupca(kupci[izborKupca - 1]);
                            cout << "Prodaja je uspjesno izmijenjena!" << endl;
                        }
                        else if(podPodPodIzbor == 2)
                        {
                            for(;;)
                            {
                                cin.ignore(10000, '\n');
                                cout << "Unesite ime i prezime kupca: ";
                                getline(cin, imeKupca);
                                //cin.ignore(10000, '\n');
                                cout << "Unesite datum rodjenja (formata d/m/g): ";
                                cin >> danRodjenja >> znak >> mjesecRodjenja >> znak >> godinaRodjenja;
                                try
                                {
                                    Datum dr(danRodjenja, mjesecRodjenja, godinaRodjenja);
                                    Kupac novi(imeKupca, dr);
                                    prodaje.DajProdaju(izborProdaje).PromijeniKupca(novi);
                                    cout << "Prodaja je uspjesno izmijenjena!" << endl;
                                    break;
                                }
                                catch(domain_error e)
                                {
                                    cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << endl;
                                }
                            }
                        }

                    }
                    else if(podPodIzbor == 4)
                    {

                        cout << "Izaberite opciju: " << endl << " 0 - nazad" << endl << " 1 - odabir postojeceg stana" << endl << " 2 - dodavanje novog stana" << endl;
                        cin >> podPodPodIzbor;

                        if(podPodPodIzbor == 0)
                            break;
                        else if(podPodPodIzbor == 1)
                        {
                            cout << "Odaberite stan. Dostupni stanovi su: " << endl;
                            for (int i = 0; i < stanovi.size(); i++)
                            {
                                cout << " " << i + 1 << " - ";
                                stanovi[i].Ispisi();
                            }
                            cin >> izborStana;
                            prodaje.DajProdaju(izborProdaje).PromijeniStan(stanovi[izborStana - 1]);
                            cout << "Prodaja je uspjesno izmijenjena!" << endl;
                        }
                        else if(podPodPodIzbor == 2)
                        {
                            for(;;)
                            {
                                Namjesten = false;
                                cin.ignore(10000, '\n');
                                cout << "Unesite adresu: ";
                                getline(cin, adresa);
                                //cin.ignore(10000, '\n');
                                cout << "Unesite sprat: ";
                                cin >> sprat;
                                cout << "Unesite broj soba: ";
                                cin >> brojSoba;
                                cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                cin >> namjesten;
                                cout << "Unesite kvadraturu: ";
                                cin >> kvadratura;

                                if (namjesten != 0 && namjesten != 1)
                                    cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << endl;
                                else
                                {
                                    try
                                    {
                                        if (namjesten == 1) Namjesten = true;
                                        Stan novi(adresa, sprat, brojSoba, Namjesten, kvadratura);
                                        prodaje.DajProdaju(izborProdaje).PromijeniStan(novi);
                                        cout << "Prodaja je uspjesno izmijenjena!" << endl;
                                        break;
                                    }
                                    catch (domain_error e)
                                    {
                                        cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << endl;
                                    }
                                }
                            }
                        }

                    }
                    else if(podPodIzbor == 5)
                    {
                        cout << "Unesite cijenu stana: ";
                        cin >> cijenaStana;
                        prodaje.DajProdaju(izborProdaje).PromijeniCijenuProdaje(cijenaStana);
                        cout << "Prodaja je uspjesno izmijenjena!" << endl;
                        break;
                    }
                }
                else if(podIzbor == 3)
                {
                    for(;;)
                    {
                        cout << "Izaberite opciju:" << endl << " 0 - nazad" << endl << " 1 - ispis svih prodaja" << endl <<  " 2 - ispis prodaja na datum" << endl << " 3 - ispis najranije prodaje" << endl << " 4 - ispis najskuplje prodaje" << endl << " 5 - ispis broja prodaja" << endl <<" 6 - ispis broja prodaja po datumu" << endl << " 7 - ispis broja prodaja po agentu"<< endl << " 8 - kraj" << endl;
                        cin >> podPodIzbor;

                        if(podPodIzbor == 0)
                            break;
                        else if(podPodIzbor == 1)
                        {
                            prodaje.IspisiSveProdaje();
                        }
                        else if(podPodIzbor == 2)
                        {
                            cout << "Unesite datum (d/m/g): ";
                            cin >> danProdaje >> znak >> mjesecProdaje >> znak >> godinaProdaje;
                            Datum dp(danProdaje, mjesecProdaje, godinaProdaje);
                            cout << "Prodaje na datum " << danProdaje << "/" << mjesecProdaje << "/" << godinaProdaje << " su:" << endl;
                            prodaje.IspisiProdajeNaDatum(dp);
                        }
                        else if(podPodIzbor == 3)
                        {
                            try
                            {
                                prodaje.DajNajranijuProdaju().Ispisi();
                            }
                            catch(domain_error e)
                            {
                                cout << "Izuzetak: " << e.what() << "." << endl;
                            }
                        }
                        else if(podPodIzbor == 4)
                        {
                            try
                            {
                                prodaje.DajNajskupljuProdaju().Ispisi();
                            }
                            catch(domain_error e)
                            {
                                cout << "Izuzetak: " << e.what() << "." << endl;
                            }
                        }
                        else if(podPodIzbor == 5)
                        {
                            cout << "Broj prodaja: " << prodaje.DajBrojProdaja() << endl;
                        }
                        else if(podPodIzbor == 6)
                        {
                            cout << "Unesite datum (d/m/g): ";
                            cin >> danProdaje >> znak >> mjesecProdaje >> znak >> godinaProdaje;
                            Datum dp(danProdaje, mjesecProdaje, godinaProdaje);
                            cout << "Broj ponuda na uneseni datum: " << prodaje.DajBrojProdajaNaDatum(dp) << endl;
                        }
                        else if(podPodIzbor == 7)
                        {
                            cin.ignore(10000, '\n');
                            cout << "Unesite ime agenta: ";
                            getline(cin, imeAgenta);
                            cout << "Broj prodaja: " << prodaje.DajBrojProdajaOdAgenta(imeAgenta) << endl;
                        }
                        else if(podPodIzbor == 8)
                            break;
                    }
                }
                else if(podIzbor == 4)
                {
                    for(;;)
                    {
                        cout << "Izaberite opciju:" << endl <<" 0 - nazad" << " 1 - brisanje najranije prodaje" << endl << " 2 - brisanje prodaja agenta" << endl << " 3 - brisanje prodaja po datumu" << endl << " 4 - brisanje svih prodaja" << endl;
                        cin >> podPodIzbor;

                        if(podPodIzbor == 0)
                            break;
                        else if(podPodIzbor == 1)
                        {
                            try
                            {
                                prodaje.ObrisiNajranijuProdaju();
                                cout << "Najranija prodaja je obrisana!" << endl;
                            }
                            catch(range_error e)
                            {
                                cout << "Izuzetak: " << e.what() << "." << endl;
                            }
                        }
                        else if(podPodIzbor == 2)
                        {
                            cin.ignore(10000, '\n');
                            cout << "Unesite ime agenta: ";
                            getline(cin, imeAgenta);
                            prodaje.ObrisiProdajeAgenta(imeAgenta);
                            cout << "Sve prodaje tog agenta su obrisane." << endl;
                        }
                        else if(podPodIzbor == 3)
                        {
                            cout << "Unesite datum (d/m/g): ";
                            cin >> danProdaje >> znak >> mjesecProdaje >> znak >> godinaProdaje;
                            Datum dp(danProdaje, mjesecProdaje, godinaProdaje);
                            prodaje.ObrisiProdajeNaDatum(dp);
                            cout << "Sve prodaje na taj datum su obrisane." << endl;
                        }
                        else if(podPodIzbor == 4)
                        {
                            prodaje.IsprazniKolekciju();
                            cout << "Sve prodaje su obrisane." << endl;
                        }
                    }
                }
            }
        }

        if(podIzbor == 4 || podIzbor == 5) break; // provjerit
    }

    cout << endl << endl << "Dovidjenja!";


    return 0;
}
