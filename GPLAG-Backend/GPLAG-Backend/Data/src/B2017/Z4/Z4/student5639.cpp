/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <tuple>
#include <utility>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <memory>


class Datum
{
    int dan, mjesec, godina;
    void TestDatuma (int d, int m, int g) {
        int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(g % 4 == 0 && (g % 100 != 0 || g % 400 == 0)) broj_dana[1]++;
        if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m-1])
            throw std::domain_error("Neispravan datum");
    }
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const;
    void Ispisi() const;
};

Datum::Datum(int dan, int mjesec, int godina)
{
    TestDatuma(dan, mjesec, godina);
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

void Datum::Postavi(int dan, int mjesec, int godina)
{
    TestDatuma(dan, mjesec, godina);
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

std::tuple<int, int, int> Datum::Ocitaj () const
{
    return std::make_tuple(dan, mjesec, godina);
}

void Datum::Ispisi() const
{
    std::cout << dan << "/" << mjesec << "/" << godina;
}

class Vrijeme
{
    int sati, minute;
    void TestVremena(int h, int m) {
        if(h < 0 || h > 23 || m < 0 || m > 59)
            throw std::domain_error("Neispravno vrijeme");
    }
public:
    Vrijeme(int sati, int minute);
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj() const;
    void Ispisi() const;
};

Vrijeme::Vrijeme(int sati, int minute)
{
    TestVremena(sati, minute);
    Vrijeme::sati = sati;
    Vrijeme::minute = minute;
}

void Vrijeme::Postavi(int sati, int minute)
{
    TestVremena(sati, minute);
    Vrijeme::sati = sati;
    Vrijeme::minute = minute;
}

std::pair<int, int> Vrijeme::Ocitaj() const
{
    return std::make_pair(sati, minute);
}

void Vrijeme::Ispisi() const
{
    if(sati >= 0 && sati < 10 && minute > 9) std::cout << "0" << sati << ":" << minute;
    else if (sati > 9 && minute >= 0 && minute < 10) std::cout << sati << ":" << "0" << minute;
    else if (sati >= 0 && sati < 10 && minute >= 0 && minute < 10) std::cout << "0" << sati << ":" <<  "0" << minute;
    else std::cout << sati << ":" << minute;
}

class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta(const std::string &ime_pacijenta);
    void PromijeniDatum(const Datum &novi_datum);
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const;
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda() const;
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};

Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda)
{
    //  Pregled::ime_pacijenta = ime_pacijenta;
}

Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda)
{
    //  Pregled::ime_pacijenta = ime_pacijenta;
}

void Pregled::PromijeniPacijenta(const std::string &ime_pacijenta)
{
    Pregled::ime_pacijenta = ime_pacijenta;
}

void Pregled::PromijeniDatum(const Datum &novi_datum)
{
    datum_pregleda = novi_datum;
}

void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme)
{
    vrijeme_pregleda = novo_vrijeme;
}

void Pregled::PomjeriDanUnaprijed()
{
    auto t(datum_pregleda.Ocitaj());
    int dan, mjesec, godina;
    dan = std::get<0>(t) + 1;
    mjesec = std::get<1>(t);
    godina = std::get<2>(t);
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0)) broj_dana[1]++;
    if(dan > broj_dana[mjesec-1]) {
        dan = 1;
        mjesec++;
    }
    if(mjesec > 12) {
        mjesec = 1;
        godina++;
    }
    Datum novi_datum(dan, mjesec, godina);
    PromijeniDatum(novi_datum);
}
void Pregled::PomjeriDanUnazad()
{
    auto t(datum_pregleda.Ocitaj());
    int dan, mjesec, godina;
    dan = std::get<0>(t) - 1;
    mjesec = std::get<1>(t);
    godina = std::get<2>(t);
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0)) broj_dana[1]++;
    if(dan <= 0) {
        dan = broj_dana[mjesec-2];
        mjesec--;
    }
    if(mjesec <= 0) {
        mjesec = 12;
        godina --;
        dan = 31;
    }
    Datum novi_datum(dan, mjesec, godina);
    PromijeniDatum(novi_datum);
}
std::string Pregled::DajImePacijenta() const
{
    return ime_pacijenta;
}
Datum Pregled::DajDatumPregleda() const
{
    return datum_pregleda;
}
Vrijeme Pregled::DajVrijemePregleda() const
{
    return vrijeme_pregleda;
}
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2)
{
    auto t(p1.datum_pregleda.Ocitaj());
    auto p(p1.vrijeme_pregleda.Ocitaj());
    auto t1(p2.datum_pregleda.Ocitaj());
    auto par(p2.vrijeme_pregleda.Ocitaj());
    if(std::get<2>(t) != std::get<2>(t1)) return std::get<2>(t) < std::get<2>(t1);
    else if(std::get<2>(t) == std::get<2>(t1) && std::get<1>(t) != std::get<1>(t1)) return std::get<1>(t) < std::get<1>(t1);
    else if(std::get<2>(t) == std::get<2>(t1) && std::get<1>(t) == std::get<1>(t1) && std::get<0>(t) != std::get<0>(t1)) return std::get<0>(t) < std::get<0>(t1);
    else if(std::get<2>(t) == std::get<2>(t1) && std::get<1>(t) == std::get<1>(t1) && std::get<0>(t) == std::get<0>(t1) && p.first != par.first) return p.first < par.first;
    else return p.second < par.second;
}
void Pregled::Ispisi() const
{
    std::cout << std::setw(30) << std::left << ime_pacijenta;
    datum_pregleda.Ispisi();
    std::cout << " ";
    vrijeme_pregleda.Ispisi();
    std::cout << std::endl;
}

class Pregledi
{
    std::vector<std::shared_ptr<Pregled>> pregledi;
    mutable int broj_registriranih = 0, broj_kreiranih = 0;
public:
    explicit Pregledi() {};
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi(const Pregledi &pregledi1);
    Pregledi(Pregledi &&p);
    Pregledi &operator =(const Pregledi &pregledi1);
    Pregledi &operator =(Pregledi &&pregledi1);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) ;
    void IspisiSvePreglede() ;
};

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda)
{
    pregledi.resize(spisak_pregleda.size());
    int i = 0;
    for(auto x: spisak_pregleda) {
        pregledi.at(i) = std::make_shared<Pregled> (x);
        i++;
        broj_kreiranih++;
    }
}
Pregledi::~Pregledi()
{
    for(int i = 0; i < pregledi.size(); i++)
        pregledi.at(i) = nullptr;
}
Pregledi::Pregledi(const Pregledi &pregledi1)
{
    pregledi.resize(pregledi1.pregledi.size());
    for(int i = 0; i < pregledi.size(); i++)
        pregledi.at(i) = std::make_shared<Pregled>(*(pregledi1.pregledi.at(i)));
}
Pregledi::Pregledi(Pregledi &&pregledi1)
{
    std::swap(pregledi, pregledi1.pregledi);
    pregledi1.pregledi.resize(0);
}
Pregledi &Pregledi::operator =(const Pregledi &pregledi1)
{
    if(&pregledi1 != this) {
        if(pregledi.size() < pregledi1.pregledi.size())
            for(int i = pregledi.size(); i < pregledi1.pregledi.size(); i++)
                pregledi.push_back(std::make_shared<Pregled>("", 1, 1, 1, 1, 1));
        pregledi.resize(pregledi1.pregledi.size());
        for(int i = 0; i < pregledi1.pregledi.size(); i++)
            *pregledi.at(i) = *pregledi1.pregledi.at(i);
    }
    return *this;
}
Pregledi &Pregledi::operator =(Pregledi &&p)
{
    pregledi = p.pregledi;
    p.pregledi.resize(0);
    return *this;
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    pregledi.push_back(std::make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda));
    broj_registriranih++;
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    Datum dat(dan_pregleda, mjesec_pregleda, godina_pregleda);
    Vrijeme v(sati_pregleda, minute_pregleda);
    pregledi.push_back(std::make_shared<Pregled>(ime_pacijenta, dat, v));
    broj_registriranih++;
}
void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled)
{
    pregledi.push_back(pregled);
    broj_registriranih++;
}
int Pregledi::DajBrojPregleda() const
{
    return pregledi.size();
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    auto t(datum.Ocitaj());
    int dan = std::get<0>(t);
    int mjesec = std::get<1>(t);
    int godina = std::get<2>(t);
    int broj_pregleda = std::count_if(pregledi.begin(), pregledi.end(), [dan, mjesec, godina] (std::shared_ptr<Pregled> p) {
        auto t1(p->DajDatumPregleda().Ocitaj());
        int dan1 = std::get<0>(t1);
        int mjesec1 = std::get<1>(t1);
        int godina1 = std::get<2>(t1);
        return  (dan == dan1 && mjesec == mjesec1 && godina == godina1);
    });
    return broj_pregleda;
}
Pregled &Pregledi::DajNajranijiPregled()
{
    if(broj_registriranih == 0) throw std::domain_error("Nema registriranih pregleda");
    auto it = std::min_element(pregledi.begin(), pregledi.end(), [] (std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
    return **it;
}
Pregled Pregledi::DajNajranijiPregled() const
{
    if(broj_registriranih == 0) throw std::domain_error("Nema registriranih pregleda");
    auto it = std::min_element(pregledi.begin(), pregledi.end(), [] (std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
    return **it;
}
void Pregledi::IsprazniKolekciju()
{
    for(int i = broj_kreiranih; i < broj_kreiranih + broj_registriranih; i++)
        pregledi[i] = nullptr;
}
void Pregledi::ObrisiNajranijiPregled()
{
    if(pregledi.size() == 0) throw std::range_error("Prazna kolekcija");
    auto t(DajNajranijiPregled().DajDatumPregleda().Ocitaj());
    int dan = std::get<0>(t);
    int mjesec = std::get<1>(t);
    int godina = std::get<2>(t);

    for(int i = 0; i < pregledi.size(); i++) {
        auto t1(pregledi[i]->DajDatumPregleda().Ocitaj());
        int dan1 = std::get<0>(t1);
        int mjesec1 = std::get<1>(t1);
        int godina1 = std::get<2>(t1);
        if(dan == dan1 && mjesec == mjesec1 && godina == godina1) pregledi.erase(pregledi.begin()+i);
    }
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    for(int i = 0; i < pregledi.size(); i++)
        if(pregledi.at(i)->DajImePacijenta() == ime_pacijenta) pregledi.erase(pregledi.begin()+i);
}
void Pregledi::IspisiPregledeNaDatum(const Datum &datum)
{
    std::sort(pregledi.begin(), pregledi.end(), [] (std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
    auto t(datum.Ocitaj());
    int dan, mjesec, godina, dan1, mjesec1, godina1;
    dan1 = std::get<0>(t);
    mjesec1 = std::get<1>(t);
    godina1 = std::get<2>(t);
    for(int i = 0; i < pregledi.size(); i++) {
        auto t1(pregledi.at(i)->DajDatumPregleda().Ocitaj());
        dan = std::get<0>(t1);
        mjesec = std::get<1>(t1);
        godina = std::get<2>(t1);
        if(dan1 == dan && mjesec1 == mjesec && godina1 == godina)
            pregledi.at(i)->Ispisi();
    }
}

void Pregledi::IspisiSvePreglede()
{
    std::sort(pregledi.begin(), pregledi.end(), [] (std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
    for(int i = 0; i < pregledi.size(); i++)
        pregledi.at(i)->Ispisi();
}

int main ()
{
    int d, m, g, h, min, opcija;
    std::string ime;
    Pregledi pregledi;
    do {
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::getline(std::cin, ime);
        if(ime == "kraj") break;

        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        std::cin >> d >> m >> g;
        std::cout << "Unesite sate i minute pregleda: ";
        std::cin >> h >> min;
        pregledi.RegistrirajPregled(ime, d, m, g, h, min);
        std::cin.ignore(10000, '\n');
    } while(ime != "kraj");

    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
    pregledi.IspisiSvePreglede();

    do {
        std:: cout << "Odaberite jednu od sljedecih opcija" << std::endl <<
                   "1 - Broj pregleda na datum" << std::endl << "2 - Najraniji pregled" << std::endl <<
                   "3 - Obrisi pregled pacijenta" << std::endl << "4 - Obrisi najraniji pregled" << std::endl <<
                   "5 - Ispisi sve pregleda na datum" << std::endl << "6 - Ispisi sve preglede" << std::endl <<
                   "7 - Kraj programa" << std::endl;
        std::cin >> opcija;
        if(opcija == 1) {
            std::cout << "Unesite dan mjesec i godinu : ";
            std::cin >> d >> m >> g;
            Datum dat(d, m, g);
            std::cout << "Broj pregleda na datum " << d << " " << m << " " << g<< " je: " << pregledi.DajBrojPregledaNaDatum(dat) << std::endl;
        } else if(opcija == 2) {
            std::cout << "Najraniji pregled je: " << std::endl;
            pregledi.DajNajranijiPregled().Ispisi();
        } else if(opcija == 3) {
            std::cout << "Unesite ime pacijenta: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, ime);
            int stari_brpregleda = pregledi.DajBrojPregleda();
            pregledi.ObrisiPregledePacijenta(ime);
            std::cout << "Uspjesno obrisano " << stari_brpregleda - pregledi.DajBrojPregleda() << " pregleda" << std::endl;
        } else if(opcija == 4) {
            int stari_brpregleda = pregledi.DajBrojPregleda();
            pregledi.ObrisiNajranijiPregled();
            if(stari_brpregleda - pregledi.DajBrojPregleda() == 1)
                std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
        } else if(opcija == 5) {
            std::cout << "Unesite dan mjesec i godinu : ";
            std::cin >> d >> m >> g;
            std::cout << "Pregledi na datum " << d << " " << m << " " << g << " su:" << std::endl;
            Datum dat(d, m, g);
            pregledi.IspisiPregledeNaDatum(dat);
            std::cout << std::endl;
        } else if(opcija == 6) {
            pregledi.IspisiSvePreglede();
        } else if(opcija == 7) break;

    } while(opcija != 7);
    return 0;
}
