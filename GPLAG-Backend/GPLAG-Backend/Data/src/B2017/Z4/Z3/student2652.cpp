/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility> 
#include <vector>
class Datum {
    int dan, mjesec, godina; 
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const;
    void Ispisi() const;
};
class Vrijeme {
int sati, minute;
public:
Vrijeme(int sati, int minute);
void Postavi(int sati, int minute);
std::pair<int, int> Ocitaj () const;
void Ispisi() const;    
    
};
Datum::Datum (int dan, int mjesec, int godina) {
    Postavi(dan, mjesec, godina);
}

Vrijeme::Vrijeme (int sati, int minute) {
    Postavi(sati, minute); 
}


void Datum::Postavi (int dan, int mjesec, int godina) {
    if (dan<=0 || dan>31 || mjesec<=0 || mjesec>12 || godina<=0 ) 
        throw std::domain_error ("Neispravan datum");
    
    Datum::dan = dan; 
    Datum::mjesec = mjesec;
    Datum::godina = godina; 
} 

void Vrijeme::Postavi (int sati, int minute) {
    if (sati<0 || sati>23 || minute<0 || minute>59) 
        throw std::domain_error ("Neispravno vrijeme");
    
    Vrijeme::sati= sati;
    Vrijeme::minute = minute ;
} 

std::tuple<int, int, int> Datum::Ocitaj() const{
    return  std::make_tuple (dan, mjesec, godina);
}
std::pair<int, int> Vrijeme::Ocitaj () const {
    return std::make_pair (sati, minute); 
}

void Datum::Ispisi () const{
    std::cout<<dan<<"/"<<mjesec<<"/"<<godina; 
}
void Vrijeme::Ispisi () const {
    if (sati/10==0) std::cout<<"0"; std::cout<<sati<<":"; 
    if (minute/10==0) std::cout<<"0"; std::cout<<minute; 
}
class Pregled{
    std::string ime_pacijenta; 
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled(const std::string & ime_pacijenta, const Datum &datum_pregleda,
    const Vrijeme & vrijeme_pregleda);
    Pregled(const std::string & ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
    int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta(const std::string & ime_pacijenta);
    void PromijeniDatum(const Datum & novi_datum);
    void PromijeniVrijeme(const Vrijeme & novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const;
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda() const;
    static bool DolaziPrije(const Pregled & p1, const Pregled & p2);
    void Ispisi() const;
};
Pregled::Pregled(const std::string & ime_pacijenta, const Datum &datum_pregleda,
    const Vrijeme & vrijeme_pregleda) : ime_pacijenta (ime_pacijenta), datum_pregleda(datum_pregleda),
    vrijeme_pregleda(vrijeme_pregleda)  { }

Pregled::Pregled(const std::string & ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
    int godina_pregleda, int sati_pregleda, int minute_pregleda) : ime_pacijenta (ime_pacijenta),
    datum_pregleda (dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda (sati_pregleda, minute_pregleda)
    { }
void Pregled::PromijeniPacijenta(const std::string & ime_pacijenta) {
    Pregled::ime_pacijenta = ime_pacijenta; 
}
void Pregled::PromijeniDatum(const Datum & novi_datum) {
    datum_pregleda=novi_datum;   
}
void Pregled::PromijeniVrijeme(const Vrijeme & novo_vrijeme) {
    vrijeme_pregleda=novo_vrijeme;
}
void Pregled::PomjeriDanUnaprijed() {
    
}
int main ()
{
  
	return 0;
}
