/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <iomanip>
#include <string>

class Datum {
    int dan,mjesec,godina;
    public:
    Datum(int dan, int mjesec, int godina){
 int broj dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj dana[1]++;
 if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj dana[m – 1])
 throw std::domain_error("Neispravan datum");
 Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    }
    void Postavi(int dan, int mjesec, int godina) {
 int broj dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj dana[1]++;
 if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj dana[m – 1])
 throw std::domain_error("Neispravan datum");
 Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}

    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(dan,mjesec,godina);
    }
    void Ispisi() const{
        std::cout << std::set() << std::fill('0') << dan << "/" << mjesec << "/" << godina; //provjeri za ovaj iomanip
    }
};

class Vrijeme {
    int sati,minute;
    public:
 Vrijeme(int sati, int minute){
     if (!(sati>=0 && sati<=23 && minute >=0 && minute<=59)) throw std::domain_error("Neispravno vrijeme");
     Vrijeme::sati=sati; Vrijeme::minute=minute; 
 }
void Postavi(int sati, int minute){
    if (!(sati>=0 && sati<=23 && minute >=0 && minute<=59)) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati=sati; Vrijeme::minute=minute; 
}
std::pair<int, int> Ocitaj () const {
    return std::make_pair(sati, minute);
}
void Ispisi() const{
    std::cout <<  sati << ":" << minute;
}  
};

class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    public:
    
Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
     Pregled::ime_pacijenta=ime_pacijenta;
     Pregled::datum_pregleda=datum_pregleda;
     Pregled::vrijeme_pregleda=vrijeme_pregleda;
 }
Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
     Pregled::ime_pacijenta=ime_pacijenta;
     Pregled::datum_pregleda(Datum(dan_pregleda,mjesec_pregleda,godina_pregleda));
     Pregled::vrijeme_pregleda(Vrijeme(sati_pregleda,minute_pregleda));
 }
void PromijeniPacijenta(const std::string &ime_pacijenta){ Pregled::ime_pacijenta=ime_pacijenta; }
void PromijeniDatum(const Datum &novi_datum){ Pregled::datum_pregleda=novi_datum; }
void PromijeniVrijeme(const Vrijeme &novo_vrijeme){ Pregled::vrijeme_pregleda=novo_vrijeme; }
void PomjeriDanUnaprijed(){ Datum::dan++; }                                                             //dodaj uslove za krajnje datume
void PomjeriDanUnazad(){ Datum::dan--; } 
std::string DajImePacijenta() const { return ime_pacijenta; }
Datum DajDatumPregleda() const { return datum_pregleda; }
Vrijeme DajVrijemePregleda() const{ return vrijeme_pregleda; }
static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
    if ((get<2>p1.Ocitaj() < get<2>p2.Ocitaj())|| (get<1>p1.Ocitaj() < get<1>p2.Ocitaj()) ||
    (get<0>p1.Ocitaj() < get<0>p2.Ocitaj()) || (p1.vrijeme_pregleda.first<p2.vrijeme_pregleda.first) || 
    (p1.vrijeme_pregleda.second<p2.vrijeme_pregleda.second)) return 1;
    return 0;
}
void Ispisi() const;
// ime pacijenta,
//poravnato ulijevo u polju širine 30 znakova,  a zatim datum i vrijeme pregleda razdvojeni jednim
//razmakom (na kraju se prelazi u novi red)
};

class Pregledi {
explicit Pregledi(int max_broj_pregleda);
Pregledi(std::initializer_list<Pregled> spisak_pregleda);
~Pregledi();
Pregledi(const Pregledi &pregledi);
Pregledi(Pregledi &&pregledi);
Pregledi &operator =(const Pregledi &pregledi);
Pregledi &operator =(Pregledi &&pregledi);
void RegistrirajPregled(const std::string &ime_pacijenta,
 const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
 int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
 int minute_pregleda);
void RegistrirajPregled(Pregled *pregled);
int DajBrojPregleda() const;
int DajBrojPregledaNaDatum(const Datum &datum) const;
Pregled &DajNajranijiPregled();
Pregled DajNajranijiPregled() const;
void IsprazniKolekciju();
void ObrisiNajranijiPregled();
void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
void IspisiPregledeNaDatum(const Datum &datum) const;
void IspisiSvePreglede() const;

};

int main ()
{
	return 0;
}
