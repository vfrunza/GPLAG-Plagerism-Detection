/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <iomanip>
#include <string>
#include <new>


class Datum {
    int D, M, G;
    friend class Pregled;
public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const { return std::make_tuple (D, M, G); }
    void Ispisi() const { std::cout << D << "/" << M << "/" << G; }
};

void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0)
        broj_dana[1]++;
    if (godina<1 || dan<1 || mjesec <1 || mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error("Neispravan datum");
    D=dan; M=mjesec; G=godina;
}


class Vrijeme {
    int H, M;
    friend class Pregled;
public:
    Vrijeme(int sati, int minute) { if (sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme"); H=sati; M=minute; }
    void Postavi(int sati, int minute) { if (sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme"); H=sati; M=minute; }
    std::pair<int, int> Ocitaj () const { return std::make_pair (H, M); }
    void Ispisi() const { std::cout << std::setw(2) << std::setfill('0') << H << ":" << std::setw(2) << std::setfill('0') << M; }
};


class Pregled {
    std::string ime;
    Datum datum;
    Vrijeme vrijeme;
public:
// pokusati iskoristiti konstruktore za inicijalzicaju vremena i datuma na kraju!!!!!!!!!!!
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : ime(ime_pacijenta), datum(datum_pregleda.D, datum_pregleda.M, datum_pregleda.G), vrijeme(vrijeme_pregleda.H, vrijeme_pregleda.M) {}
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) :
        ime(ime_pacijenta), datum(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme(sati_pregleda, minute_pregleda) {}
    void PromijeniPacijenta(const std::string &ime_pacijenta) { ime=ime_pacijenta; }
    void PromijeniDatum(const Datum &novi_datum) { datum=novi_datum; }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { vrijeme=novo_vrijeme; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const {return ime; }
    Datum DajDatumPregleda() const { return datum; }
    Vrijeme DajVrijemePregleda() const { return vrijeme; }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const { std::cout << std::left << std::setw(30) << ime << " "; datum.Ispisi(); std::cout << " "; vrijeme.Ispisi(); std::cout << std::endl; }
};


void Pregled::PomjeriDanUnaprijed() {
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((datum.G%4==0 && datum.G%100!=0) || datum.G%400==0)
        broj_dana[1]++;
    datum.D++;
    if (datum.D>broj_dana[datum.M-1]) datum.D=1, datum.M++;
    if (datum.M>12) datum.M=1, datum.G++;
}

// provjeriti na kraju za svaki slucaj
void Pregled::PomjeriDanUnazad() {
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((datum.G%4==0 && datum.G%100!=0) || datum.G%400==0)
        broj_dana[1]++;
    datum.D--;
    if (datum.D<1 && datum.M-1==0) datum.D=broj_dana[11], datum.M=12, datum.G--;
    else if (datum.D<1) datum.D=broj_dana[datum.M-2], datum.M--;
}


bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    if (p1.datum.G < p2.datum.G) return true;
    if ((p1.datum.G == p2.datum.G) && (p1.datum.M < p2.datum.M)) return true;
    if ((p1.datum.G == p2.datum.G) && (p1.datum.M == p2.datum.M) && (p1.datum.D < p2.datum.D)) return true;
    return false;
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
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
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
