/B2017/2018: Zadaća 4, Zadatak 3

#include <iostream>
#include <memory>
#include <tuple>
#include <utility>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <stdexcept>
#include <vector>

class Datum {
    int dan, mjesec, godina;
public:
    Datum (int dan, int mjesec, int godina);
    void Postavi (int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const;
    void Ispisi() const;
};

class Vrijeme {
    int sati, minute;
public:
    Vrijeme (int sati, int minute);
    void Postavi (int sati, int minute);
    std::pair<int, int> Ocitaj () const;
    void Ispisi () const;
};

class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    std::vector<int>brojdanaumjesecu = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::vector<int>brojdanaumjesecuPrestupna = {31, 29, 31, 30, 31, 31, 30, 31, 30, 31};
    bool DaLiJePrestupna (int godina) {
        return (godina % 4 == 0 && godina % 100 != 0 && godina % 400 == 0);
    }
    void PopraviDatum (Datum &datum) {
        int dan = std::get<0>(datum.Ocitaj());
        int mjesec = std::get<1>(datum.Ocitaj());
        int godina = std::get<2>(datum.Ocitaj());
        if (DaLiJePrestupna(godina)) {
            if (dan > brojdanaumjesecuPrestupna[mjesec-1]) {
                dan = 1;
                mjesec++;
                if (mjesec > 12) {
                    mjesec = 1;
                    godina++;
                } 
            } else if (dan < 1) {
                mjesec--;
                if (mjesec < 1) {
                    mjesec = 12;
                    godina--;
                }
                dan = brojdanaumjesecuPrestupna[mjesec-1];
            }
            datum.Postavi (dan, mjesec, godina);
        } else {
            if (dan > brojdanaumjesecu[mjesec-1]) {
                dan = 1;
                mjesec++;
                if (mjesec > 12) {
                    mjesec = 1;
                    godina++;
                }
            } else if (dan < 1) {
                mjesec--;
                if (mjesec < 1) {
                    mjesec = 12;
                    godina--;
                }
                dan = brojdanaumjesecu[mjesec-1];
            }
            datum.Postavi(dan, mjesec, godina);
        }
    }
public:
    Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta (const std::string &ime_pacijenta);
    void PromijeniDatum (const Datum &novi_datum);
    void PromijeniVrijeme (const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed ();
    void PomjeriDanUnazad ();
    std::string DajImePacijenta () const;
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda() const;
    static bool DolaziPrije (const Pregled &p1, const Pregled &p2);
    void Ispisi () const;
};

class Pregledi {
    Pregled** spisak_pregleda;
    int broj_pregleda;
    int max_broj_pregleda;
public:
    explicit Pregledi (int max_broj_pregleda);
    Pregledi (std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi (const Pregledi &pregledi);
    Pregledi (Pregledi &&pregledi);
    Pregledi &operator = (const Pregledi &pregledi);
    Pregledi &operator = (Pregledi &&pregledi);
    void RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda,
        const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda,
        int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled (Pregled *pregled);
    int DajBrojPregleda () const;
    int DajBrojPregledaNaDatum (const Datum &datum) const;
    Pregled &DajNajranijiPregled ();
    Pregled DajNajranijiPregled () const;
    void IsprazniKolekciju ();
    void ObrisiNajranijiPregled ();
    void ObrisiPregledePacijenta (const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum (const Datum &datum) const;
    void IspisiSvePreglede () const;
};

Datum::Datum (int dan, int mjesec, int godina) {
    if (dan < 1 || dan > 31 || mjesec < 1 || mjesec > 12) throw std::domain_error ("Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
void Datum::Postavi (int dan, int mjesec, int godina) {
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
std::tuple<int, int, int> Datum::Ocitaj () const {
    std::tuple<int, int, int> t {dan, mjesec, godina};
    return t;
}
void Datum::Ispisi () const {
    std::cout << dan << "/" << mjesec << "/" << godina << std::endl;
}

Vrijeme::Vrijeme (int sati, int minute) {
    if (sati < 0 || sati > 23 || minute < 0 || minute > 59) throw std::domain_error ("Neispravno vrijeme");
    Vrijeme::sati = sati; Vrijeme::minute = minute;
}
void Vrijeme::Postavi (int sati, int minute) {
    Vrijeme::sati = sati; Vrijeme::minute = minute;
}
std::pair<int, int> Vrijeme::Ocitaj () const {
    std::pair<int, int> p {sati, minute};
    return p;
}
void Vrijeme::Ispisi () const {
    std::cout << std::setw (2) << std::setfill ('0') << sati << ":" << minute << std::endl;
}

Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : datum_pregleda(Datum(datum_pregleda)), vrijeme_pregleda(Vrijeme(vrijeme_pregleda)) {
    Pregled::ime_pacijenta = ime_pacijenta;
}

Pregled::Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : 
    datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda) {
    Pregled::ime_pacijenta = ime_pacijenta;
}
void Pregled::PromijeniPacijenta (const std::string &ime_pacijenta) {
    Pregled::ime_pacijenta = ime_pacijenta;
}
void Pregled::PromijeniDatum (const Datum &novi_datum) {
    datum_pregleda = novi_datum;
}
void Pregled::PromijeniVrijeme (const Vrijeme &novo_vrijeme) {
    vrijeme_pregleda = novo_vrijeme;
}
void Pregled::PomjeriDanUnaprijed () {
    int dan = std::get<0>(datum_pregleda.Ocitaj());
    int mjesec = std::get<1>(datum_pregleda.Ocitaj());
    int godina = std::get<2>(datum_pregleda.Ocitaj());
    datum_pregleda.Postavi(dan+1, mjesec, godina);
    PopraviDatum (datum_pregleda);
}
void Pregled::PomjeriDanUnazad () {
    int dan = std::get<0>(datum_pregleda.Ocitaj());
    int mjesec = std::get<1>(datum_pregleda.Ocitaj());
    int godina = std::get<2>(datum_pregleda.Ocitaj());
    datum_pregleda.Postavi(dan-1, mjesec, godina);
    PopraviDatum (datum_pregleda);
}
std::string Pregled::DajImePacijenta () const {
    return ime_pacijenta;
}
Datum Pregled::DajDatumPregleda () const {
    return datum_pregleda;
}
Vrijeme Pregled::DajVrijemePregleda () const {
    return vrijeme_pregleda;
}
bool Pregled::DolaziPrije (const Pregled &p1, const Pregled &p2) {
    return std::get<2>(p1.datum_pregleda.Ocitaj()) < std::get<2>(p2.datum_pregleda.Ocitaj()) && std::get<1>(p1.datum_pregleda.Ocitaj()) < std::get<1>(p2.datum_pregleda.Ocitaj())
        && std::get<0>(p1.datum_pregleda.Ocitaj()) < std::get<0>(p2.datum_pregleda.Ocitaj()) && std::get<0>(p1.vrijeme_pregleda.Ocitaj()) < std::get<0>(p2.vrijeme_pregleda.Ocitaj())
        && std::get<1>(p1.vrijeme_pregleda.Ocitaj()) < std::get<1>(p2.vrijeme_pregleda.Ocitaj());
}
void Pregled::Ispisi () const {
    std::cout << std::left << std::setw(30) << ime_pacijenta << " " << std::right
    << std::get<0>(datum_pregleda.Ocitaj()) << "/" << std::get<1>(datum_pregleda.Ocitaj()) << "/" << std::get<2>(datum_pregleda.Ocitaj()) 
    << " " << std::get<0>(vrijeme_pregleda.Ocitaj()) << ":" << std::get<1>(vrijeme_pregleda.Ocitaj()) << std::endl;
}

Pregledi::Pregledi (int max_broj_pregleda) : spisak_pregleda (new Pregled*[max_broj_pregleda]{}), broj_pregleda(0), max_broj_pregleda (max_broj_pregleda) {}
Pregledi::Pregledi (std::initializer_list<Pregled> spisak_pregleda) : spisak_pregleda (nullptr), max_broj_pregleda(spisak_pregleda.size()) {
    Pregledi::spisak_pregleda = new Pregled*[spisak_pregleda.size()] {}; 
    int i = 0;
    for (Pregled pregled : spisak_pregleda) {
        try {
            Pregledi::spisak_pregleda[i] = new Pregled (pregled);
            i++;
        } catch (...) {
            for (int j = 0; j < i; j++) delete Pregledi::spisak_pregleda[j];
            delete[] Pregledi::spisak_pregleda;
            throw;
        }
    }
    broj_pregleda = spisak_pregleda.size();
}
Pregledi::~Pregledi () {
    for (int i = 0; i < broj_pregleda; i++) {
        delete spisak_pregleda[i];
    }
    delete[] spisak_pregleda;
}
Pregledi::Pregledi (const Pregledi &pregledi) {
    broj_pregleda = pregledi.broj_pregleda;
    max_broj_pregleda = pregledi.max_broj_pregleda;
    spisak_pregleda = new Pregled* [pregledi.max_broj_pregleda] {};
    try {
        for (int i = 0; i < pregledi.max_broj_pregleda; i++) {
            if (pregledi.spisak_pregleda[i] != nullptr) {
                spisak_pregleda[i] = new Pregled (*pregledi.spisak_pregleda[i]);
            }
        }
    } catch (...) {
        for (int i = 0; i < max_broj_pregleda; i++) {
            delete spisak_pregleda[i];
        }
        delete[] spisak_pregleda;
        throw;
    }
}
Pregledi::Pregledi (Pregledi &&pregledi) {
    broj_pregleda = pregledi.broj_pregleda;
    max_broj_pregleda = pregledi.max_broj_pregleda;
    spisak_pregleda = pregledi.spisak_pregleda;
    pregledi.spisak_pregleda = nullptr;
    pregledi.broj_pregleda = 0;
    pregledi.max_broj_pregleda = 0;
}

Pregledi& Pregledi::operator = (const Pregledi &pregledi) {
    if (this != &pregledi) {
        for (int i = 0; i < max_broj_pregleda; i++) {
            delete spisak_pregleda[i];
        }
        delete[] spisak_pregleda;
        broj_pregleda = pregledi.broj_pregleda;
        max_broj_pregleda = pregledi.max_broj_pregleda;
        spisak_pregleda = new Pregled* [pregledi.max_broj_pregleda] {};
        try {
            for (int i = 0; i < pregledi.max_broj_pregleda; i++) {
                if (pregledi.spisak_pregleda[i] != nullptr) {
                    spisak_pregleda[i] = new Pregled (*pregledi.spisak_pregleda[i]);
                }
            }
        } catch (...) {
            for (int i = 0; i < max_broj_pregleda; i++) {
                delete spisak_pregleda[i];
            }
            delete[] spisak_pregleda;
            throw;
        }
    }
    return *this;
}

Pregledi& Pregledi::operator = (Pregledi &&pregledi) {
    if (this != &pregledi) {
        for (int i = 0; i < max_broj_pregleda; i++) {
            delete spisak_pregleda[i];
        }
        delete[] spisak_pregleda;
        max_broj_pregleda = pregledi.max_broj_pregleda;
        broj_pregleda = pregledi.broj_pregleda;
        spisak_pregleda = pregledi.spisak_pregleda;
        pregledi.spisak_pregleda = nullptr;
        pregledi.broj_pregleda = 0;
        pregledi.max_broj_pregleda = 0;
    }
    return *this;
}
void Pregledi::RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda,
    const Vrijeme &vrijeme_pregleda) {
        if (broj_pregleda == max_broj_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
        for (int i = 0; i < max_broj_pregleda; i++) {
            if (spisak_pregleda[i] != nullptr) {
                spisak_pregleda[i] = new Pregled (ime_pacijenta, datum_pregleda, vrijeme_pregleda);
                broj_pregleda ++;
            }
        }
    }
void Pregledi::RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda,
    int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
        if (broj_pregleda == max_broj_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
        for (int i = 0; i < max_broj_pregleda; i++) {
           if (spisak_pregleda[i] != nullptr) {
               spisak_pregleda[i] = new Pregled (ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
               broj_pregleda++;
           }
        }   
    }
void Pregledi::RegistrirajPregled (Pregled *pregled) {
    if (broj_pregleda == max_broj_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
    for (int i = 0; i < max_broj_pregleda; i++) {
        if (spisak_pregleda[i] != nullptr) {
            spisak_pregleda[i] = pregled;
            broj_pregleda++;
        }
    }
}
int Pregledi::DajBrojPregleda () const {
    return broj_pregleda;
}
int Pregledi::DajBrojPregledaNaDatum (const Datum &datum) const {
    return std::count_if (spisak_pregleda, spisak_pregleda + max_broj_pregleda, [datum] (Pregled *p) {
        if (p != nullptr) {
            auto prvi (p->DajDatumPregleda().Ocitaj()), drugi (datum.Ocitaj());
            if (std::get<0>(prvi) == std::get<0>(drugi) && std::get<1>(prvi) == std::get<1>(drugi) && std::get<2>(prvi) == std::get<2>(drugi)) return true;
        }
        return false;
    });
}
Pregled& Pregledi::DajNajranijiPregled () {
    auto it = std::min_element (spisak_pregleda, spisak_pregleda + max_broj_pregleda, [] (Pregled *prvi, Pregled *drugi) {
        if (prvi != nullptr && drugi != nullptr) {
            if (Pregled::DolaziPrije(*prvi, *drugi)) return true;
            return false;
        }
        else if (prvi != nullptr && drugi ==nullptr) return true;
        else return false;
    });
    return **it;
}
Pregled Pregledi::DajNajranijiPregled() const {
    auto it = std::min_element (spisak_pregleda, spisak_pregleda + max_broj_pregleda, [] (Pregled *prvi, Pregled *drugi) {
       if (prvi != nullptr && drugi != nullptr) {
           if (Pregled::DolaziPrije(*prvi, *drugi)) return true;
           return false;
       } 
       else if (prvi != nullptr && drugi == nullptr) return true;
       else return false;
    });
    return **it;
}
void Pregledi::IsprazniKolekciju () {
    for (int i = 0; i < max_broj_pregleda; i++) {
        delete spisak_pregleda[i];
        spisak_pregleda[i] = nullptr;
    }
    broj_pregleda = 0;
}
void Pregledi::ObrisiNajranijiPregled () {
    if (broj_pregleda == 0) throw std::range_error ("Prazna kolekcija");
    Pregled p = DajNajranijiPregled();
    auto najraniji_dat = p.DajDatumPregleda().Ocitaj();
    auto najranije_vrijeme = p.DajVrijemePregleda().Ocitaj();
    for (int i = 0; i < max_broj_pregleda; i++) {
        auto dat = spisak_pregleda[i]->DajDatumPregleda().Ocitaj();
        auto vrijeme = spisak_pregleda[i]->DajDatumPregleda().Ocitaj();
        if (spisak_pregleda[i] != nullptr && spisak_pregleda[i]->DajImePacijenta() == p.DajImePacijenta()
        && std::get<0>(dat) == std::get<0>(najraniji_dat) && std::get<1>(dat) == std::get<1>(najraniji_dat) && std::get<2>(dat) == std::get<2>(najraniji_dat)
        && std::get<0>(vrijeme) == std::get<0>(najranije_vrijeme) && std::get<1>(vrijeme) == std::get<1>(najranije_vrijeme)) {
            delete spisak_pregleda[i];
            spisak_pregleda[i] = nullptr;
        }
    }
}
void Pregledi::ObrisiPregledePacijenta (const std::string &ime_pacijenta) {
    for (int i = 0; i < max_broj_pregleda; i++) {
        if (spisak_pregleda[i] != nullptr && spisak_pregleda[i]->DajImePacijenta() == ime_pacijenta) {
            delete spisak_pregleda[i];
            spisak_pregleda[i] = nullptr;
        }
    }
}
void Pregledi::IspisiPregledeNaDatum (const Datum &datum) const {
    auto datump = datum.Ocitaj();
    std::vector<Pregled> pregledi_na_datum;
    for (int i = 0; i < max_broj_pregleda; i++) {
        if (spisak_pregleda[i] != nullptr) {
            auto datumo = spisak_pregleda[i]->DajDatumPregleda().Ocitaj();
            if (std::get<0>(datump) == std::get<0>(datumo) && std::get<1>(datump) == std::get<1>(datumo) 
                && std::get<2>(datump) == std::get<2>(datumo)) {
                pregledi_na_datum.push_back (*(spisak_pregleda[i]));
            }
        }
    }
    std::sort (pregledi_na_datum.begin(), pregledi_na_datum.end(), [] (Pregled p1, Pregled p2) {
        auto vrijeme1 = p1.DajVrijemePregleda().Ocitaj();
        auto vrijeme2 = p2.DajVrijemePregleda().Ocitaj();
        return std::get<0>(vrijeme1) < std::get<0>(vrijeme2) && std::get<1>(vrijeme1) < std::get<1>(vrijeme2);
    });
    for (Pregled p : pregledi_na_datum) p.Ispisi();
}
void Pregledi::IspisiSvePreglede () const {
    std::vector<Pregled>pregledi;
    for (int i = 0; i < max_broj_pregleda; i++) {
        if (spisak_pregleda[i] != nullptr) 
            pregledi.push_back (*(spisak_pregleda[i]));
    }
    std::sort (pregledi.begin(), pregledi.end(), [] (Pregled p1, Pregled p2) {
        auto vrijeme1 = p1.DajVrijemePregleda().Ocitaj();
        auto vrijeme2 = p2.DajVrijemePregleda().Ocitaj();
        return std::get<0>(vrijeme1) < std::get<0>(vrijeme2) && std::get<1>(vrijeme1) < std::get<1>(vrijeme2);
    });
    for (Pregled p : pregledi) p.Ispisi();
}

int main ()
{
    std::cout << "Unesite maksimalan broj pregleda: ";
    int max_broj_pregleda;
    std::cin >> max_broj_pregleda;
   
    Pregledi pregledi (max_broj_pregleda);
   
    
    std::string ime;
    int dan, mjesec, godina, sati, minute;
    
    do {
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::cin >> ime;
        std::cin.clear();
        std::cin.ignore (10000, '\n');
        if (ime != "kraj") {
            std::cout << "Unesite dan mjesec i godinu pregleda: ";
            std::cin >> dan >> mjesec >> godina;
            std::cout << "Unesite sate i minute pregleda: ";
            std::cin >> sati >> minute;
            pregledi.RegistrirajPregled (ime, dan, mjesec, godina, sati, minute);
        }
    } while (ime != "kraj");
    pregledi.IspisiSvePreglede();
    
    int opcija;
    do {
        std::cout << std::endl << "Odaberite jednu od sljedecih opcija" << std::endl;
        std::cout << "1 - Broj pregleda na datum" << std::endl 
                << "2 - Najraniji pregled" << std::endl
                << "3 - Obrisi pregled pacijenta" << std::endl
                << "4 - Obrisi najraniji pregled" << std::endl
                << "5 - Ispisi sve preglede na datum" << std::endl
                << "6 - Ispisi sve preglede" << std::endl
                << "7 - Kraj programa";
        std::cin >> opcija;
        if (opcija == 1) {
            std::cout << "Unesite dan mjesec i godinu : ";
            std::cin >> dan >> mjesec >> godina;
            std::cout << "Broj pregleda na datum " << dan << " " << mjesec << " " << godina << " je: ";
            Datum datum (dan, mjesec, godina);
            pregledi.DajBrojPregledaNaDatum (datum);
        } else if (opcija == 2) {
            std::cout << "Najraniji pregled je:" << std::endl;
            pregledi.DajNajranijiPregled ().Ispisi();
        } else if (opcija == 3) {
            std::cout << "Unesite ime pacijenta: ";
            std::cin >> ime;
            std::cin.clear();
            std::cin.ignore (10000, '\n');
            int prije = pregledi.DajBrojPregleda();
            pregledi.ObrisiPregledePacijenta(ime);
            int poslije = pregledi.DajBrojPregleda();
            int n = poslije - prije;
            std::cout << "Uspjesno obrisano " << n << " pregleda";
        } else if (opcija == 4) {
            pregledi.ObrisiNajranijiPregled();
            std::cout << "Najraniji pregled uspjesno obrisan";
        } else if (opcija == 5) {
            std::cout << "Unesite dan mjesec i godinu : Pregledi na datum ";
            std::cin >> dan >> mjesec >> godina;
            std::cout << dan << " " << mjesec << " " << godina << " su:";
            Datum datum (dan, mjesec, godina);
            pregledi.IspisiPregledeNaDatum(datum);
        } else if (opcija == 6) {
            pregledi.IspisiSvePreglede();
        } 
    } while (opcija != 7);
    
	return 0;
}
