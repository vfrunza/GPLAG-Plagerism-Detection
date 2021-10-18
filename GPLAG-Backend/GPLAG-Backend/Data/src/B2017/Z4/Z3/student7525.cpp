/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <utility>
#include <stdexcept>
#include <iomanip>

class Datum
{
    friend class Pregled;
    int dan, mjesec, godina;
    public:
    Datum (int dan, int mjesec, int godina)
    {
        if (dan > 31 || dan < 1 || mjesec > 12 || mjesec < 1) throw std::domain_error ("Neispravan datum");
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
    }
    void Postavi (int dan, int mjesec, int godina)
    {
        if (dan > 31 || dan < 1 || mjesec > 12 || mjesec < 1) throw std::domain_error ("Neispravan datum");
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
    }
    std::tuple<int, int, int> Ocitaj() const { return std::make_tuple(dan, mjesec, godina); }
    
    void Ispisi() const
    {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

class Vrijeme
{
    friend class Pregled;
    int sati, minute;
    public:
    Vrijeme (int sati, int minute)
    {
        if (sati > 23 || sati < 0 || minute > 59 || minute < 0) throw std::domain_error ("Neispravno vrijeme");
        Vrijeme::sati = sati;
        Vrijeme::minute = minute;
    }
    void Postavi (int sati, int minute)
    {
        if (sati > 23 || sati < 0 || minute > 59 || minute < 0) throw std::domain_error ("Neispravno vrijeme");
        Vrijeme::sati = sati; 
        Vrijeme::minute = minute;
    }
    std::pair<int, int> Ocitaj() const { return std::make_pair(sati, minute); }
    void Ispisi() const
    {
        std::cout << std::setprecision(2) << std::fixed << sati << ":" << std::setprecision(2) << std::fixed << minute;
    }
};

class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    public:
    
    Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
    {
        ime_pacijenta = ime_pacijenta;
        datum_pregleda = datum_pregleda;
        vrijeme_pregleda = vrijeme_pregleda;
    }
    
    Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int minute_pregleda, int sati_pregleda)
    {
        Pregled::ime_pacijenta = ime_pacijenta;
        datum_pregleda.dan = dan_pregleda;
        datum_pregleda.mjesec = mjesec_pregleda;
        datum_pregleda.godina = godina_pregleda;
        vrijeme_pregleda.minute = minute_pregleda;
        vrijeme_pregleda.sati = sati_pregleda;
    }
    
    void PromijeniPacijenta (const std::string &ime_pacijenta);
    void PromjeniDatum (const Datum &novi_datum);
    void PromjeniVrijeme (const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed() 
    {
        datum_pregleda.dan = datum_pregleda.dan + 1;
    }
    void PomjeriDanUnazad()
    {
        datum_pregleda.dan = datum_pregleda.dan - 1;
    }
    
    std::string DajImePacijenta() const { return ime_pacijenta; }
    Datum DajDatumPregleda() const { return datum_pregleda; }
    Vrijeme DajVrijemePregleda() const { return vrijeme_pregleda; }
    
    static bool DolaziPrije (const Pregled &p1, const Pregled &p2)
    {
        if (p1.datum_pregleda.dan > p2.datum_pregleda.dan) return true;
        return false;
    }
            
};

int main ()
{
    
	return 0;
}
