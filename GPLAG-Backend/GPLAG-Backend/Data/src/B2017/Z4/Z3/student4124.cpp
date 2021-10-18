/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstring>

using namespace std;

class Datum
{
    int dan;
    int mjesec;
    int godina;

public:

    Datum (int dan, int mjesec, int godina);
    void Postavi (int dan, int mjesec, int godina);
    int DajDan() const;
    int DajMjesec() const;
    int DajGodinu() const;
    void Ispisi() const;
};

class Vrijeme
{
    int sati;
    int minute;

public:

    Vrijeme (int sati, int minute);
    void Postavi (int sati, int minute);
    int DajSate() const;
    int DajMinute() const;
    void Ispisi() const;
};

class Pregled
{
    string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;

public:

    Pregled (const char ime_pacijenta[], const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    Pregled (const char ime_pacijenta[], int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta (const char ime_pacijenta[]);
    void PromijeniDatum (const Datum &novi_datum);
    void PromijeniVrijeme (const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    string DajImePacijenta() const;
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda() const;
    friend bool DolaziPrije (const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};

class Pregledi
{

public:

    explicit Pregledi (int max_broj_pregleda);
    Pregledi (std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi (const Pregledi &pregledi);
    Pregledi (Pregledi &&pregledi);
    Pregledi &operator=(const Pregledi &pregledi);
    Pregledi &operator=(Pregledi &&pregledi);
    void RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled (Pregled *pregled);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum (const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled() const;
    void ObrisiPregledePacijenta (const std::string &ime_pacijenta);
    void IspisiSvePreglede() const;
};

Datum::Datum (int dan, int mjesec, int godina) : dan(dan), mjesec(mjesec), godina(godina) {};

void Datum::Postavi (int dan, int mjesec, int godina)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31};
    if (godina%4==0 && godina%100!=0 || godina%400==0)
        broj_dana[1]++;
    if (godina<1 || dan<1 ||mjesec<1 || mjesec>12 ||dan>broj_dana[mjesec-1])
        throw std::domain_error ("Neispravan datum");
    Datum::dan=dan;
    Datum::mjesec=mjesec;
    Datum::godina=godina;
}

int Datum::DajDan () const {
    return dan;
}

int Datum::DajMjesec () const {
    return mjesec;
}

int Datum::DajGodinu () const {
    return godina;
}

void Datum::Ispisi() const
{
    std::cout<< dan<< "/"<< mjesec<< "/"<< godina;
}

Vrijeme::Vrijeme (int sati, int minute): sati(sati), minute (minute) {};

void Vrijeme::Postavi (int sati, int minute)
{
    while (sati>23)
        sati=sati-24;
    while (minute>59)
        minute=minute-60;
    throw std::domain_error ("Neispravno vrijeme");
    Vrijeme::sati=sati;
    Vrijeme::minute=minute;
}

void Vrijeme::Ispisi() const
{
    cout<< sati<< ":"<< minute;
}


Pregled::Pregled (const char ime_pacijenta[], const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): datum_pregleda (datum_pregleda), vrijeme_pregleda (vrijeme_pregleda)
{
    Pregled::ime_pacijenta.resize (std::strlen (ime_pacijenta));
    std::copy (ime_pacijenta, ime_pacijenta+std::strlen(ime_pacijenta), Pregled::ime_pacijenta.begin());
}

Pregled::Pregled (const char ime_pacijenta[], int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda): datum_pregleda (dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda (sati_pregleda, minute_pregleda)
{
    Pregled::ime_pacijenta.resize (std::strlen(ime_pacijenta));
    std::copy (ime_pacijenta, ime_pacijenta+std::strlen (ime_pacijenta), Pregled::ime_pacijenta.begin());
}

void Pregled::PromijeniPacijenta (const char ime_pacijenta[])
{
    Pregled::ime_pacijenta.resize(0);
    Pregled::ime_pacijenta.resize (std::strlen (ime_pacijenta));
    std::copy (ime_pacijenta, ime_pacijenta+std::strlen (ime_pacijenta), Pregled::ime_pacijenta.begin());
}

void Pregled::PromijeniDatum (const Datum &novi_datum)
{
    datum_pregleda=novi_datum;
}

void Pregled::PromijeniVrijeme (const Vrijeme &novo_vrijeme)
{
    vrijeme_pregleda=novo_vrijeme;
}

void Pregled::PomjeriDanUnaprijed()
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (datum_pregleda.DajGodinu()%4==0 && Datum::datum_pregleda::godina%100!=0 || Datum::datum_pregleda::godina%400==0)
        broj_dana[1]++;
    if (Datum::datum_pregleda::godina<1 || Datum::datum_pregleda::dan<1 || mjesec<1 || Datum::datum_pregleda::mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error ("Neispravan datum!");
    for (int i; i<broj_dana+1; i++)
        int pomocna (broj_dana [Datum::datum_pregleda::mjesec-1])
        if (Datum::datum_pregleda::dan<pomocna)
            Datum::datum_pregleda::dan++;
        else {
            Datum::datum_pregleda::dan=1;
            if (Datum::datum_pregleda::mjesec<12)
                Datum::datum_pregleda::mjesec++
                else
                    Datum::datum_pregleda::mjesec=1;
            Datum::datum_pregleda::godina++;
        }

    void PomjeriDanUnazad();
    {
        int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (Datum::datum_pregleda::godina%4==0 && Datum::datum_pregleda::godina%100!=0 || Datum::datum_pregleda::godina%400==0)
            broj_dana[1]++;
        if (Datum::datum_pregleda::godina<1 || Datum::datum_pregleda::dan<1 || mjesec<1 || Datum::datum_pregleda::mjesec>12 || dan>broj_dana[mjesec-1])
            throw std::domain_error ("Neispravan datum!");
        for (int i; i<broj_dana+1; i++)
            int pomocna (broj_dana [Datum::datum_pregleda::mjesec-1])
            if (Datum::datum_pregleda::dan==(pomocna-pomocna+1))
                Datum::datum_pregleda::dan=31;
        Datum::datum_pregleda::mjesec--;
        else {
            Datum::datum_pregleda::dan--;
            if (Datum::datum_pregleda::mjesec==1)
                Datum::datum_pregleda::mjesec==12
                Datum::datum_pregleda::godina--;
        }
    }

    DajImePacijenta() const {
        return ime_pacijenta;
    }

    Datum DajDatumPregleda() const {
        return datum_pregleda;
    }

    Vrijeme DajVrijemePregleda() const {
        return vrijeme_pregleda;
    }

    bool Pregled::DolaziPrije (const Pregled &p1. const Pregled &p2) {
        if (p1::Datum::datum_pregleda::godina==p2::Datum::datum_pregleda::godina)
            if (p1::Datum::datum_pregleda::dan<p2::Datum::datum_pregleda::dan)
                return true;
        return false;
    }

    void Ispisi() const;
}
