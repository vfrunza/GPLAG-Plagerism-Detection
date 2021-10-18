/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <iomanip>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <cstring>
#include <vector>

class Datum
{
    int dan, mjesec, godina;
    bool Ispravi(int &dan, int &mjesec, int &godina);


public:
    Datum (int dan, int mjesec, int godina) {
        Postavi(dan, mjesec, godina);
    }
    void Postavi (int dan, int mjesec, int godina);

    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(dan,mjesec,godina);
    }
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }

};

class Vrijeme
{
    int sati, minute;
public:
    Vrijeme (int sati, int minute) {
        Postavi(sati, minute);
    }
    void Postavi(int sati, int minute) {
        if(sati < 0 || sati > 23 || minute < 0 || minute > 59) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati = sati;
        Vrijeme::minute = minute;
    }
    std::pair<int, int> Ocitaj() const {
        return std::make_pair(sati, minute);
    }
    void Ispisi() const {
        std::cout << std::setfill('0') << std::setw(2) << std::right << sati << ":"
                  << std::setw(2) << std::right << minute << std::setfill(' ');
    }

};

class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;

    bool Ispravi(int &dan, int &mjesec, int &godina);

public:
    Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): datum_pregleda (datum_pregleda),
        vrijeme_pregleda (vrijeme_pregleda),ime_pacijenta(ime_pacijenta) {
    }

    Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):
        datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda), ime_pacijenta(ime_pacijenta) {
    }

    void PromijeniPacijenta (const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta = ime_pacijenta;
    }

    void PromijeniDatum (const Datum &novi_datum) {
        Pregled::datum_pregleda = novi_datum;
    }
    void PromijeniVrijeme (const Vrijeme &novo_vrijeme) {
        Pregled::vrijeme_pregleda = novo_vrijeme;
    }

    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();

    std::string DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda () const {
        return datum_pregleda;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme_pregleda;
    }

    static bool DolaziPrije (const Pregled &p1, const Pregled &p2);
    void Ispisi() const {
        std::cout << std::left << std::setw(30) << DajImePacijenta();
        DajDatumPregleda().Ispisi();
        std::cout << " ";
        DajVrijemePregleda().Ispisi();
        std::cout << std::endl;
    }
};

class Pregledi
{
    int max_broj_pregleda = 0;
    int broj_evidentiranih = 0;
    Pregled** pregledi;

    void Obrisi(Pregled* za_brisanje);

public:

    explicit Pregledi(int max_broj_pregleda);
    Pregledi (std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi (const Pregledi &pregledi);
    Pregledi (Pregledi &&pregledi);
    Pregledi &operator= (const Pregledi &pregledi);
    Pregledi &operator= (Pregledi && pregledi);

    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
                            int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregledi);

    int DajBrojPregleda() const {
        return broj_evidentiranih;
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;

    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);

    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};


void Datum::Postavi (int dan, int mjesec, int godina)
{
    if(Ispravi(dan, mjesec, godina)) throw std::domain_error("Neispravan datum");

    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

void Pregled::PomjeriDanUnaprijed()
{

    auto info (datum_pregleda.Ocitaj());
    int  dan_pregleda = std::get<0> (info);
    int mjesec_pregleda = std::get<1> (info);
    int godina_pregleda =std::get<2> (info);

    if(Ispravi(++dan_pregleda, mjesec_pregleda, godina_pregleda)) {
        dan_pregleda = 1;
        if(Ispravi(dan_pregleda, ++mjesec_pregleda, godina_pregleda)) {
            mjesec_pregleda = 1;
            Ispravi(dan_pregleda, mjesec_pregleda, ++godina_pregleda);
        }
    }

}

void Pregled::PomjeriDanUnazad()
{
    auto info (datum_pregleda.Ocitaj());
    int  dan_pregleda = std::get<0> (info);
    int mjesec_pregleda = std::get<1> (info);
    int godina_pregleda =std::get<2> (info);

    if(Ispravi(--dan_pregleda, mjesec_pregleda, godina_pregleda)) {
        dan_pregleda = 31;
        if(mjesec_pregleda > 1) {
            mjesec_pregleda--;
            while (Ispravi(dan_pregleda, mjesec_pregleda, godina_pregleda)) dan_pregleda--;
        } else {
            mjesec_pregleda = 12;
            godina_pregleda--;
        }
        while (Ispravi(dan_pregleda, mjesec_pregleda, godina_pregleda)) dan_pregleda--;


    }
    Pregled::datum_pregleda.Postavi(dan_pregleda, mjesec_pregleda, godina_pregleda);

}
bool Pregled::Ispravi(int &dan, int &mjesec, int &godina)
{
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    return (godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1]);

}
bool Datum::Ispravi(int &dan, int &mjesec, int &godina)
{
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    return (godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1]);

}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2)
{

    auto prvi(p1.DajDatumPregleda().Ocitaj());
    auto drugi(p2.DajDatumPregleda().Ocitaj());
    auto vrijeme1(p1.DajVrijemePregleda().Ocitaj());
    auto vrijeme2(p2.DajVrijemePregleda().Ocitaj());

    std::tuple<int, int, int, int, int>  ukupno1 = std::make_tuple(std::get<2>(prvi), std::get<1>(prvi),
            std::get<0>(prvi), std::get<0>(vrijeme1), std::get<1>(vrijeme1));

    std::tuple<int, int, int, int, int>  ukupno2 = std::make_tuple(std::get<2>(drugi),
            std::get<1>(drugi), std::get<0>(drugi),
            std::get<0>(vrijeme2), std::get<1>(vrijeme2));

    return ukupno1 < ukupno2;
}

void Pregledi::Obrisi(Pregled* za_brisanje)
{
    for(int i = 0; i < broj_evidentiranih; i++)
        if(pregledi[i] == za_brisanje) {
            if(i == broj_evidentiranih - 1){
                delete pregledi[i];
                break;
            }
            delete pregledi[i];
            for(int j = i + 1; j < broj_evidentiranih; j++)
                pregledi[i] = pregledi[j];
                i--;
        }
    pregledi[broj_evidentiranih - 1] = nullptr;
    broj_evidentiranih--;
}

Pregledi::Pregledi(int max_broj_pregleda): max_broj_pregleda(max_broj_pregleda), broj_evidentiranih(0), pregledi(new Pregled* [max_broj_pregleda] {}) {}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda): max_broj_pregleda(spisak_pregleda.size()), broj_evidentiranih(spisak_pregleda.size()),
    pregledi(new Pregled*[spisak_pregleda.size()] {})
{

    auto pomocni (pregledi);
    int brojac(0);
    for(auto it = spisak_pregleda.begin(); it != spisak_pregleda.end(); it++) {
        pomocni[brojac++] = new Pregled (*it);
    }
}

Pregledi::~Pregledi()
{
    for(int i = 0; i < broj_evidentiranih; i++) delete pregledi[i];
    delete[] pregledi;
}

Pregledi::Pregledi (const Pregledi &p): pregledi(new Pregled* [p.max_broj_pregleda] {}), max_broj_pregleda(p.max_broj_pregleda),
         broj_evidentiranih(p.broj_evidentiranih)
{
    try {
        for(int i = 0; i < p.broj_evidentiranih; i++) pregledi[i] = new Pregled (*p.pregledi[i]);
    } catch(...) {
        for(int i = 0; i < p.broj_evidentiranih; i++) delete pregledi[i];
        delete[] pregledi;
        throw;
    }
}

Pregledi::Pregledi(Pregledi &&p): pregledi(p.pregledi), max_broj_pregleda(p.max_broj_pregleda), broj_evidentiranih(p.broj_evidentiranih)
{
    p.pregledi = nullptr;
    p.broj_evidentiranih = 0;
}

Pregledi &Pregledi:: operator = (const Pregledi &p)
{
    for(int i = 0; i < broj_evidentiranih; i++) delete pregledi[i];
    delete[] pregledi;

    max_broj_pregleda = p.max_broj_pregleda;
    broj_evidentiranih = p.broj_evidentiranih;
    pregledi = new Pregled*[p.max_broj_pregleda] {};

    std::copy(p.pregledi, p.pregledi + p.broj_evidentiranih, pregledi);
    return *this;
}
Pregledi &Pregledi:: operator =(Pregledi && p)
{

    std::swap(broj_evidentiranih, p.broj_evidentiranih);
    std::swap(max_broj_pregleda, p.max_broj_pregleda);
    std::swap(pregledi, p.pregledi);

    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    if(broj_evidentiranih >= max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledi[broj_evidentiranih++] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
                                  int sati_pregleda, int minute_pregleda)
{
    if(broj_evidentiranih >= max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");

    pregledi[broj_evidentiranih++] = new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda,
            sati_pregleda, minute_pregleda);
}

void Pregledi::RegistrirajPregled (Pregled* pregled)
{
    if(broj_evidentiranih >= max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledi[broj_evidentiranih++] = pregled;
}

int Pregledi::DajBrojPregledaNaDatum (const Datum &datum) const
{
    return std::count_if(pregledi, pregledi + broj_evidentiranih, [datum](Pregled* pok) {
        auto prva(datum.Ocitaj());
        auto druga(pok->DajDatumPregleda().Ocitaj());
        return prva == druga;
    });
}

Pregled &Pregledi::DajNajranijiPregled()
{
    if(broj_evidentiranih == 0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(pregledi, pregledi + broj_evidentiranih, [](const Pregled* p1, const Pregled* p2) {
        return p1->DolaziPrije(*p1, *p2);
    });
}
Pregled Pregledi::DajNajranijiPregled() const
{
    if(broj_evidentiranih == 0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(pregledi, pregledi + broj_evidentiranih, [](const Pregled* p1, const Pregled* p2) {
        return p1->DolaziPrije(*p1, *p2);
    });
}

void Pregledi::IsprazniKolekciju()
{
    if(broj_evidentiranih == 0) throw std::range_error("Prazna kolekcija");
    for(int i = 0; i < broj_evidentiranih; i++) delete pregledi[i];
    delete[] pregledi;
    broj_evidentiranih = 0;
}

void Pregledi::ObrisiNajranijiPregled()
{
    if(broj_evidentiranih == 0) throw std::range_error("Prazna kolekcija");
    auto za_brisanje = std::find_if(pregledi, pregledi + broj_evidentiranih, [this] (Pregled* pok) {
        return pok == &DajNajranijiPregled();
    });
    Obrisi(*za_brisanje);
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    for(;;) {
        auto za_brisanje (std::find_if(pregledi, pregledi + broj_evidentiranih, [ime_pacijenta] (Pregled *pok) {
            return pok -> DajImePacijenta() == ime_pacijenta;
        }));
        if(za_brisanje == pregledi + broj_evidentiranih) break;
        Obrisi(*za_brisanje);
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    std::vector<Pregled*> za_sortiranje(broj_evidentiranih);
    std::copy(pregledi, pregledi + broj_evidentiranih, za_sortiranje.begin());
    std::sort(za_sortiranje.begin(), za_sortiranje.end(), [](Pregled *pok1, Pregled* pok2) {
        return pok1->DolaziPrije (*pok1, *pok2);
    });

    std::for_each(za_sortiranje.begin(), za_sortiranje.end(), [datum](Pregled* pok) {
        auto pomocni1(datum.Ocitaj());
        auto pomocni2(pok->DajDatumPregleda().Ocitaj());
        if(pomocni1 == pomocni2) pok->Ispisi();
    });

}

void Pregledi::IspisiSvePreglede() const
{
    std::vector<Pregled*> za_sortiranje(broj_evidentiranih);
    std::copy(pregledi, pregledi + broj_evidentiranih, za_sortiranje.begin());
    std::sort(za_sortiranje.begin(), za_sortiranje.end(), [](Pregled* pok1, Pregled* pok2) {
        return pok1->DolaziPrije(*pok1, *pok2);
    });

    std::for_each(za_sortiranje.begin(), za_sortiranje.end(), [](Pregled* pok) {
        pok->Ispisi();
    });
}
int main ()
{
    std::cout << "Unesite maksimalan broj pregleda: ";
    int broj_pregleda;
    std::cin >> broj_pregleda;

    Pregledi danasnji (broj_pregleda);
    std::cin.ignore(10000, '\n');


    for(int i = 0; i < broj_pregleda; i++) {

        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";

        std::string temp;
        std::getline(std::cin, temp);
        if(temp == "kraj") break;

        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        int dan, mjesec, godina;
        std::cin >> dan >> mjesec >> godina;

        std::cout << "Unesite sate i minute pregleda: ";
        int sati, minute;
        std::cin >> sati >> minute;

        danasnji.RegistrirajPregled(temp, dan, mjesec, godina, sati, minute);
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
    danasnji.IspisiSvePreglede();

    for(;;) {

        std::cout << std::endl;
        std::cout << "Odaberite jednu od sljedecih opcija" << std::endl;
        std::cout << "1 - Broj pregleda na datum" << std::endl;
        std::cout << "2 - Najraniji pregled" << std::endl;
        std::cout << "3 - Obrisi pregled pacijenta" << std::endl;
        std::cout << "4 - Obrisi najraniji pregled" << std::endl;
        std::cout << "5 - Ispisi sve pregleda na datum" << std::endl;
        std::cout << "6 - Ispisi sve preglede" << std::endl;
        std::cout << "7 - Kraj programa" << std::endl;

        int x;
        std::cin >> x;
        std::string pomocni;
        int dan, mjesec, godina;
        int prije;

        switch(x) {
        case 1:
            std::cout << "Unesite dan mjesec i godinu : ";

            std::cin >> dan >> mjesec >> godina;
            std::cout << "Broj pregleda na datum " << dan << " " << mjesec << " " << godina << " je: "<<
                      danasnji.DajBrojPregledaNaDatum(Datum(dan,mjesec,godina)) << std::endl;
            continue;
        case 2:
            std::cout <<"Najraniji pregled je: " << std::endl;
            danasnji.DajNajranijiPregled().Ispisi();
            continue;
        case 3:
            std::cout << "Unesite ime pacijenta: ";
            std::cin >> std::ws;
            std::getline(std::cin, pomocni);

            prije = danasnji.DajBrojPregleda();
            danasnji.ObrisiPregledePacijenta(pomocni);
            std::cout << "Uspjesno obrisano " << prije - danasnji.DajBrojPregleda() << " pregleda" << std::endl;
            continue;
        case 4:
            danasnji.ObrisiNajranijiPregled();
            std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
            continue;
        case 5:
            std::cout << "Unesite dan mjesec i godinu : ";

            std::cin >> dan>> mjesec >> godina;

            std::cout  << "Pregledi na datum "<< dan << " " << mjesec << " " << godina <<" su:" << std::endl;
            danasnji.IspisiPregledeNaDatum(Datum(dan, mjesec, godina));
            continue;
        case 6:
            danasnji.IspisiSvePreglede();
            continue;
        case 7:
            return 0;
        }

        std::cin.ignore(10000, '\n');
    }

    return 0;
}