/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <utility>
#include <stdexcept>
#include <initializer_list>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <new>
#include <memory>
#include <cmath>

class Datum
{
    int dan, mjesec, godina;
    static void ProvjeraDatuma(int dan, int mjesec, int godina) {
        int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
        if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
            broj_dana[1]++;
        if (godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
            throw std::domain_error("Neispravan datum");
    }
public:
    Datum(int dan, int mjesec, int godina) {
        ProvjeraDatuma(dan, mjesec, godina);
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Postavi(int dan, int mjesec, int godina) {
        ProvjeraDatuma(dan, mjesec, godina);
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(dan, mjesec, godina);
    }
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

class Vrijeme
{
    int sati, minute;
    static void ProvjeraVremena(int sati, int minute) {
        if (sati>23 || sati<0 || minute>59 || minute<0)
            throw std::domain_error("Neispravno vrijeme");
    }
public:
    Vrijeme(int sati, int minute) {
        ProvjeraVremena(sati, minute);
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    void Postavi(int sati, int minute) {
        ProvjeraVremena(sati, minute);
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    std::pair<int, int> Ocitaj() const {
        return std::make_pair(sati, minute);
    }
    void Ispisi() const {
        if (sati<10)
            std::cout << "0";
        std::cout << sati << ":";
        if (minute<10)
            std::cout << "0";
        std::cout << minute;
    }
};

class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda) : ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {};
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) :
        ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda) {};
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        auto dat(novi_datum.Ocitaj());
        Pregled::datum_pregleda.Postavi(std::get<0>(dat), std::get<1>(dat), std::get<2>(dat));
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        auto vri(novo_vrijeme.Ocitaj());
        Pregled::vrijeme_pregleda.Postavi(std::get<0>(vri), std::get<1>(vri));
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda() const {
        return datum_pregleda;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme_pregleda;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const {
        std::cout << std::setw(30) << std::left << ime_pacijenta;
        datum_pregleda.Ispisi();
        std::cout << " ";
        vrijeme_pregleda.Ispisi();
        std::cout << std::endl;
    }
};

void Pregled::PomjeriDanUnaprijed()
{
    auto dat(datum_pregleda.Ocitaj());
    int dan(std::get<0>(dat));
    int mjesec(std::get<1>(dat));
    int godina(std::get<2>(dat));
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
    if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        broj_dana[1]++;
    dan++;
    if (dan>broj_dana[mjesec-1]) {
        dan=1;
        mjesec++;
    }
    if (mjesec>12) {
        mjesec=1;
        godina++;
    }
    datum_pregleda.Postavi(dan, mjesec, godina);
}

void Pregled::PomjeriDanUnazad()
{
    auto dat(datum_pregleda.Ocitaj());
    int dan(std::get<0>(dat));
    int mjesec(std::get<1>(dat));
    int godina(std::get<2>(dat));
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
    if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        broj_dana[1]++;
    dan--;
    if (dan<1) {
        mjesec--;
        if (mjesec<1) {
            godina--;
            mjesec=12;
            dan=31;
        } else
            dan=broj_dana[mjesec-1];
    }
    datum_pregleda.Postavi(dan, mjesec, godina);
}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2)
{
    auto dat1(p1.datum_pregleda.Ocitaj());
    int dan1(std::get<0>(dat1));
    int mjesec1(std::get<1>(dat1));
    int godina1(std::get<2>(dat1));
    auto vri1(p1.vrijeme_pregleda.Ocitaj());
    int sat1(std::get<0>(vri1));
    int min1(std::get<1>(vri1));

    auto dat2(p2.datum_pregleda.Ocitaj());
    int dan2(std::get<0>(dat2));
    int mjesec2(std::get<1>(dat2));
    int godina2(std::get<2>(dat2));
    auto vri2(p2.vrijeme_pregleda.Ocitaj());
    int sat2(std::get<0>(vri2));
    int min2(std::get<1>(vri2));

    return ((godina1<godina2) || (godina1==godina2 && mjesec1<mjesec2) || (godina1==godina2 && mjesec1==mjesec2 && dan1<dan2) || (godina1==godina2 && mjesec1==mjesec2 && dan1==dan2 && sat1<sat2) || (godina1==godina2 && mjesec1==mjesec2 && dan1==dan2 && sat1==sat2 && min1<min2));
}

class Pregledi
{
    std::vector<std::shared_ptr<Pregled>> pregledi;
public:
    explicit Pregledi() = default;
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi() = default;
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi) = default;
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi) = default;
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled);
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

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda)
{
    for (auto it(spisak_pregleda.begin()); it != spisak_pregleda.end() ; it++)
        pregledi.emplace_back(std::make_shared<Pregled>(*it));
}

Pregledi::Pregledi(const Pregledi &pregledi)
{
    for (int i = 0; i < pregledi.pregledi.size(); i++)
        Pregledi::pregledi.emplace_back(std::make_shared<Pregled>(*pregledi.pregledi[i]));
}

Pregledi& Pregledi::operator =(const Pregledi &pregledi)
{
    if (Pregledi::pregledi.size()<pregledi.pregledi.size()) {
        for (int i = Pregledi::pregledi.size(); i < pregledi.pregledi.size(); i++)
            Pregledi::pregledi.emplace_back(std::make_shared<Pregled>(*pregledi.pregledi[i]));
    }
    for (int i = 0; i < pregledi.pregledi.size(); i++)
        *Pregledi::pregledi[i]=*pregledi.pregledi[i];
    Pregledi::pregledi.resize(pregledi.pregledi.size());
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    Pregledi::pregledi.emplace_back(std::make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda));
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    Pregledi::pregledi.emplace_back(std::make_shared<Pregled>(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda));
}

void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled)
{
    Pregledi::pregledi.emplace_back(pregled);
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    if (pregledi.size()==0)
        throw std::domain_error("Nema registriranih pregleda");
    auto dat(datum.Ocitaj());
    return std::count_if(pregledi.begin(), pregledi.end(), [&dat] (std::shared_ptr<Pregled> p) {
        auto dat2(p->DajDatumPregleda().Ocitaj());
        return ((std::get<0>(dat)==std::get<0>(dat2))&&(std::get<1>(dat)==std::get<1>(dat2))&&(std::get<2>(dat)==std::get<2>(dat2)));
    });
}

Pregled& Pregledi::DajNajranijiPregled()
{
    if (pregledi.size()==0)
        throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(pregledi.begin(), pregledi.end(), [] (const std::shared_ptr<Pregled> p1, const std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
}

Pregled Pregledi::DajNajranijiPregled() const
{
    if (pregledi.size()==0)
        throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(pregledi.begin(), pregledi.end(), [] (const std::shared_ptr<Pregled> p1, const std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
}

void Pregledi::IsprazniKolekciju()
{
    for (int i = 0; i < pregledi.size(); i++)
        pregledi[i]=nullptr;
}

void Pregledi::ObrisiNajranijiPregled()
{
    if (pregledi.size()==0)
        throw std::range_error("Prazna kolekcija");
    auto poz(std::min_element(pregledi.begin(), pregledi.end(), [] (const std::shared_ptr<Pregled> p1, const std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    }));
    int indeks(0);
    for (int i = 0; i < pregledi.size(); i++) {
        if (*poz==pregledi[i]) {
            indeks=i;
            break;
        }
    }
    for (int i = indeks; i < pregledi.size()-1; i++)
        std::swap(pregledi[i],pregledi[i+1]);
    pregledi[pregledi.size()-1]=nullptr;
    pregledi.resize(pregledi.size()-1);
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    for (int i = 0; i < pregledi.size(); i++) {
        if (pregledi[i]->DajImePacijenta()==ime_pacijenta) {
            for (int j = i; j < pregledi.size()-1; j++)
                std::swap(pregledi[j], pregledi[j+1]);
            pregledi[pregledi.size()-1]=nullptr;
            pregledi.resize(pregledi.size()-1);
            i--;
        }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    auto dat(datum.Ocitaj());
    std::vector<int> indeksi;
    for (int i = 0; i < pregledi.size(); i++) {
        auto dat2(this->pregledi[i]->DajDatumPregleda().Ocitaj());
        if ((std::get<0>(dat)==std::get<0>(dat2))&&(std::get<1>(dat)==std::get<1>(dat2))&&(std::get<2>(dat)==std::get<2>(dat2)))
            indeksi.push_back(i);
    }
    std::sort(indeksi.begin(), indeksi.end(), [this] (const int n1, const int n2) {
        return Pregled::DolaziPrije(*(this->pregledi[n1]),*(this->pregledi[n2]));
    });
    for (int i = 0; i < indeksi.size(); i++)
        this->pregledi[indeksi[i]]->Ispisi();
}

void Pregledi::IspisiSvePreglede() const
{
    std::vector<int> indeksi;
    for (int i = 0; i < pregledi.size(); i++)
        indeksi.push_back(i);
    std::sort(indeksi.begin(), indeksi.end(), [this] (const int n1, const int n2) {
        return Pregled::DolaziPrije(*(this->pregledi[n1]),*(this->pregledi[n2]));
    });
    for (int i = 0; i < indeksi.size(); i++)
        this->pregledi[indeksi[i]]->Ispisi();
}

int main ()
{
    Pregledi p;
    do {
        int dan, mjesec, godina, sati, minute;
        std::string unos;
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::getline(std::cin, unos);
        if (unos=="kraj")
            break;
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        std::cin >> dan >> mjesec >> godina;
        std::cout << "Unesite sate i minute pregleda: ";
        std::cin >> sati >> minute;
        try {
            p.RegistrirajPregled(unos, dan, mjesec, godina, sati, minute);
        } catch (const std::exception &greska) {
            std::cout << greska.what() << std::endl;
            return 0;
        }
        std::cin.clear();
        std::cin.ignore(10000,'\n');
    } while (true);
    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
    p.IspisiSvePreglede();
    do {
        int unos;
        std::cout << "\nOdaberite jednu od sljedecih opcija" << std::endl;
        std::cout << "1 - Broj pregleda na datum" << std::endl;
        std::cout << "2 - Najraniji pregled" << std::endl;
        std::cout << "3 - Obrisi pregled pacijenta" << std::endl;
        std::cout << "4 - Obrisi najraniji pregled" << std::endl;
        std::cout << "5 - Ispisi sve pregleda na datum" << std::endl;
        std::cout << "6 - Ispisi sve preglede" << std::endl;
        std::cout << "7 - Kraj programa" << std::endl;
        std::cin >> unos;
        if (unos==7)
            break;
        int dan, mjesec, godina;
        std::string ime;
        int br_prije(p.DajBrojPregleda());
        switch (unos) {
        case 1:
            std::cout << "Unesite dan mjesec i godinu : ";
            std::cin >> dan >> mjesec >> godina;
            try {
                std::cout << "Broj pregleda na datum " << dan << " " << mjesec << " " << godina << " je: " << p.DajBrojPregledaNaDatum({dan, mjesec, godina}) << std::endl;
            } catch (const std::exception &greska) {
                std::cout << greska.what() << std::endl;
                return 0;
            }
            break;
        case 2:
            std::cout << "Najraniji pregled je:" << std::endl;
            try {
                p.DajNajranijiPregled().Ispisi();
            } catch (const std::exception &greska) {
                std::cout << greska.what() << std::endl;
                return 0;
            }
            std::cout << std::endl;
            break;
        case 3:
            std::cout << "Unesite ime pacijenta: ";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::getline(std::cin, ime);
            try {
                p.ObrisiPregledePacijenta(ime);
            } catch (const std::exception &greska) {
                std::cout << greska.what() << std::endl;
                return 0;
            }
            std::cout << "Uspjesno obrisano " << br_prije - p.DajBrojPregleda() << " pregleda" << std::endl;
            break;
        case 4:
            try {
                p.ObrisiNajranijiPregled();
            } catch (const std::exception &greska) {
                std::cout << greska.what() << std::endl;
                return 0;
            }
            std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
            break;
        case 5:
            std::cout << "Unesite dan mjesec i godinu : ";
            std::cin >> dan >> mjesec >> godina;
            std::cout << "Pregledi na datum " << dan << " " << mjesec << " " << godina << " su:" << std::endl;
            try {
                p.IspisiPregledeNaDatum({dan, mjesec, godina});
            } catch (const std::exception &greska) {
                std::cout << greska.what() << std::endl;
                return 0;
            }
            break;
        case 6:
            p.IspisiSvePreglede();
            break;
        }
    } while (true);
    return 0;
}
