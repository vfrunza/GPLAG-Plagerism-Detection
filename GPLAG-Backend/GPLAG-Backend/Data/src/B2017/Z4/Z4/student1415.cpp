/B2017/2018: Zadaća 4, Zadatak 4
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
#include <memory>

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
    std::vector<std::shared_ptr<Pregled>> pregledi;

    void Obrisi(std::shared_ptr<Pregled> za_brisanje);

public:

    explicit Pregledi() = default;
    Pregledi (std::initializer_list<Pregled> spisak_pregleda);
    Pregledi (const Pregledi &pregledi);
    Pregledi (Pregledi &&pregledi) = default;
    Pregledi &operator= (const Pregledi &pregledi);
    Pregledi &operator= (Pregledi && pregledi) = default;

    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
                            int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr<Pregled> pregledi);

    int DajBrojPregleda() const {
        return pregledi.size();
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

void Pregledi::Obrisi(std::shared_ptr<Pregled> za_brisanje)
{

    pregledi.erase(std::remove_if(pregledi.begin(), pregledi.end(),[za_brisanje](std::shared_ptr<Pregled> pok) {
        return pok == za_brisanje;
    }));

}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda): pregledi(spisak_pregleda.size())
{
    auto it = spisak_pregleda.begin();
    try {
        for(int i = 0; i < spisak_pregleda.size(); i++) {
            pregledi[i] = std::make_shared<Pregled>(*it);
            it++;
        }
    } catch(...) {
        for(int i = 0; i < spisak_pregleda.size(); i++) pregledi[i] = nullptr;
    }

}

Pregledi::Pregledi (const Pregledi &p): pregledi(p.pregledi.size())
{
    for(int i = 0; i < p.pregledi.size(); i++) pregledi[i] = std::make_shared<Pregled>(*p.pregledi[i]);
}

Pregledi &Pregledi:: operator = (const Pregledi &p)
{
    pregledi.resize(p.pregledi.size());
    for(int i = 0; i < p.pregledi.size(); i++)
        pregledi[i] = std::make_shared<Pregled>(*p.pregledi[i]);
    return *this;
}


void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    pregledi.push_back(std::make_shared<Pregled>(Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda )));
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
                                  int sati_pregleda, int minute_pregleda)
{
    pregledi.push_back(std::make_shared<Pregled>(Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda,
                       sati_pregleda, minute_pregleda)));
}

void Pregledi::RegistrirajPregled (std::shared_ptr<Pregled> pregled)
{

    pregledi.push_back(pregled);
}

int Pregledi::DajBrojPregledaNaDatum (const Datum &datum) const
{
    return std::count_if(pregledi.begin(), pregledi.end(), [datum](std::shared_ptr<Pregled> pok) {
        auto prva(datum.Ocitaj());
        auto druga(pok->DajDatumPregleda().Ocitaj());
        return prva == druga;
    });
}

Pregled &Pregledi::DajNajranijiPregled()
{
    if(pregledi.size() == 0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(pregledi.begin(), pregledi.end(), [](std::shared_ptr<Pregled> p1,
    std::shared_ptr<Pregled> p2) {
        return p1->DolaziPrije(*p1, *p2);
    });
}
Pregled Pregledi::DajNajranijiPregled() const
{
    if(pregledi.size() == 0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(pregledi.begin(), pregledi.end(), [](std::shared_ptr<Pregled> p1,
    std::shared_ptr<Pregled> p2) {
        return p1->DolaziPrije(*p1, *p2);
    });
}

void Pregledi::IsprazniKolekciju()

{
    if(pregledi.size() == 0) throw std::range_error("Prazna kolekcija");
    for(int i = 0; i < pregledi.size(); i++) pregledi[i] = nullptr;
}

void Pregledi::ObrisiNajranijiPregled()
{
    if(pregledi.size() == 0) throw std::range_error("Prazna kolekcija");
    auto za_brisanje = std::find_if(pregledi.begin(), pregledi.end(), [this] (std::shared_ptr<Pregled> pok) {
        return pok.get() == &DajNajranijiPregled();
    });
    Obrisi(*za_brisanje);
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    for(;;) {
        auto za_brisanje (std::find_if(pregledi.begin(), pregledi.end(), [ime_pacijenta] (std::shared_ptr<Pregled>pok) {
            return pok -> DajImePacijenta() == ime_pacijenta;
        }));
        if(za_brisanje == pregledi.end()) break;
        Obrisi(*za_brisanje);
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    std::vector<std::shared_ptr<Pregled>> za_sortiranje(pregledi.size());
    std::copy(pregledi.begin(), pregledi.end(), za_sortiranje.begin());
    std::sort(za_sortiranje.begin(), za_sortiranje.end(), [](std::shared_ptr<Pregled> pok1, std::shared_ptr<Pregled> pok2) {
        return pok1->DolaziPrije (*pok1, *pok2);
    });

    std::for_each(za_sortiranje.begin(), za_sortiranje.end(), [datum](std::shared_ptr<Pregled> pok) {
        auto pomocni1(datum.Ocitaj());
        auto pomocni2(pok->DajDatumPregleda().Ocitaj());
        if(pomocni1 == pomocni2) pok->Ispisi();
    });

}

void Pregledi::IspisiSvePreglede() const
{
    std::vector<std::shared_ptr<Pregled>> za_sortiranje(pregledi.size());
    std::copy(pregledi.begin(), pregledi.end(), za_sortiranje.begin());
    std::sort(za_sortiranje.begin(), za_sortiranje.end(), [](std::shared_ptr<Pregled> pok1, std::shared_ptr<Pregled> pok2) {
        return pok1->DolaziPrije(*pok1, *pok2);
    });

    std::for_each(za_sortiranje.begin(), za_sortiranje.end(), [](std::shared_ptr<Pregled> pok) {
        pok->Ispisi();
    });
}
int main ()
{
    Pregledi danasnji;
    for(;;) {

        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";

        std::string temp;
        std::getline(std::cin, temp);
        if(temp == "kraj") break;

        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        int dan, mjesec, godina;
        std::cin >> dan >> mjesec >> godina;

        std::cout << "Unesite sate i minute pregleda: ";
        int sati, minute;
        std::cin  >> sati >> minute;

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
            std::cin >> std::ws;
            std::cout << "Unesite ime pacijenta: ";

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
        std::cin.clear();
        std::cin.ignore(10000, '\n');

    }

    return 0;
}