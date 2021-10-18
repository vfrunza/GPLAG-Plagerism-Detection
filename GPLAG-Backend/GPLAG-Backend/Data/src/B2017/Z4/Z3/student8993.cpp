/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <initializer_list>

class Datum {
    int dan, mjesec, godina;
    public:
        Datum(int dan, int mjesec, int godina) { 
            if () throw std::domain_error ("");
            Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina; 
        }
        void Postavi(int dan, int mjesec, int godina) { Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina; }
        std::tuple<int, int, int> Ocitaj() const {
            std::tuple<int, int, int>pomocna;
            std::get<0>(pomocna)=dan; std:get<1>(pomocna)=mjesec; std::get<2>(pomocna)=godina;
            return pomocna;
        }
        void Ispisi() const;
}

class Vrijeme {
    int sati, minute;
    public:
        Vrijeme(int sati, int minute) { Vrijeme::sati=sati; Vrijeme ::minute=minute; }
        void Postavi(int sati, int minute) { Vrijeme::sati=sati; Vrijeme::minute=minute; }
        std::pair<int, int> Ocitaj () const;
        void Ispisi() const;
}

class Pregled {
    
    public:
        Pregled(const std::string &ime_pacijenta, const Datum &datum_rodjenja, const Vrijeme &vrijeme_pregleda);
        Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
        void PromijeniPacijenta(const std::string &ime_pacijenta);
        void PromijeniDatum(const Datum &novi_datum);
        void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
        void PomjeriDanUnaprijed();
        void PomjeriDanUnazad();
        std::string DajImePacijanata();
        Datum DajDatumPregleda() const;
        Vrijeme DajVrijemePregleda() const;
        static bool DolaziPrije (const Pregled &p1, const Pregled &p2);
        void Ispisi() const;
}

class Pregledi {
    
    public:
        explicit Pregledi(int max_broj_pregleda);
        Pregledi(std::initializer_list<Pregled> spisak_pregleda);
        ~Pregledi();
        Pregledi(const Pregledi &pregledi);
        Pregledi(Pregledi &&pregledi);
        Pregledi &operator =(const Pregledi &pregledi);
        Pregledi &operator =(Pregledi &&pregledi);
        void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
        void RegistrirajPregled(Pregled *pregled);
        int DajBrojPregleda() const;
        int DajBrojPregledaNaDatum(const Datum &datum) const;
        Pregled &DajNajranijiPregled() const;
        Pregled DajNajranijiPregled() const;
        void IsprazniKolekciju();
        void ObrisiNajranijiPregled();
        void ObrisiPregledPacijenta(const std::string &ime_pacijenta);
        void IspisiPregledNaDatum(const Datum &datum) const;
        void IspisiSvePreglede() const;
}

int main () {
    
	return 0;
}
