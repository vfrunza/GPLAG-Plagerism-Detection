/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <stdexcept>

class Datum {
    int dan;
    int mjesec;
    int godina;
public:
    Datum (int dan, int mjesec, int godina){
        if(dan<0 || dan>31 || mjesec<0 || mjesec>12) throw std::domain_error("Neispravan datum")
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Postavi (int dan, int mjesec, int godina){
        if(dan<0 || dan>31 || mjesec<0 || mjesec>12) throw std::domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    std::tuple<int,int,int> Ocitaj() const{
        std::tuple<int,int,int> t(dan,mjesec,godina);
        return t;
    }
    void Ispisi() const{
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};


class Vrijeme {
    int sati;
    int minute;
public:
    Vrijeme (int sati, int minute){
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    void Postavi(int sati, int minute){
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    std::pair<int,int> Ocitaj() const{
        std::pair<int, int> p(sati,minute);
        return p;
    }
    void Ispisi() const{
        std::cout<<sati<<":"<<minute;
    }
};

class Pregled {
    std::string ime_pacijenta;
    Datum datum;
    Vrijeme vrijeme;
    
public:
    Pregled(const std::string &ime_pacijenta const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta (const std::string &ime_pacijenta);
    void PromijeniDatum(const Datum &novi_datum);
    void PromjeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const;
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda() const;
    static bool DolaziPrije (const Pregled &p1, const Pregeld &p2);
    void Ispisi() const;
};


int main ()
{
   
	return 0;
}
