/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <tuple>
#include <utility>
#include <string>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector> 
#include <memory>

class Datum
{
    int dan, mjesec, godina;
    bool IspravanDatum() const;
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const;
    void Ispisi() const;
};

class Vrijeme
{
    int sati, minute;
    bool IspravnoVrijeme() const;
public:
    Vrijeme(int sati, int minute);
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj() const;
    void Ispisi() const;

};

class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    static bool Prije(const Vrijeme &v1, const Vrijeme &v2);
    static bool Prije(const Datum &d1, const Datum &d2);
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
            const Vrijeme &vrijeme_pregleda);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
            int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta (const std::string &ime_pacijenta);
    void PromijeniDatum (const Datum &novi_datum);
    void PromijeniVrijeme (const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const;
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda() const;
    static bool DolaziPrije (const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};

typedef std::shared_ptr<Pregled> PokNaPregled;

class Pregledi
{
    int br_pregleda=0;
    std::vector<PokNaPregled> pregledi;
public:
    explicit Pregledi();
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    Pregledi(const Pregledi &p);
    Pregledi(Pregledi &&p);
    Pregledi &operator = (const Pregledi &p);
    Pregledi &operator = (Pregledi &&p);
    void RegistrirajPregled(const std::string &ime_pacijenta,
                            const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
                            int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
                            int minute_pregleda);
    void RegistrirajPregled(PokNaPregled pregled);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum (const Datum &d) const;
    void IspisiSvePreglede() const;
};

void Meni(bool &zavrsi, Pregledi &p)
{
    std::cout << "Odaberite jednu od sljedecih opcija\n" <<
              "1 - Broj pregleda na datum\n"<<
              "2 - Najraniji pregled\n" <<
              "3 - Obrisi pregled pacijenta\n" <<
              "4 - Obrisi najraniji pregled\n" <<
              "5 - Ispisi sve pregleda na datum\n" <<
              "6 - Ispisi sve preglede\n" <<
              "7 - Kraj programa\n";
    int unos(0);
    std::cin >> unos;
    if(unos == 1) {
        std::cout << "Unesite dan mjesec i godinu : ";
        int d,m,g;
        std::cin >> d>>m>>g;
        std::cout << "Broj pregleda na datum " << d << " " << m << " " << g << " je: ";
        std::cout << p.DajBrojPregledaNaDatum(Datum(d,m,g))<< std::endl;
    }
    if(unos == 2) {
        std::cout << "Najraniji pregled je:" << std::endl;
        p.DajNajranijiPregled().Ispisi();
    }
    if(unos == 3) {
        int prije(p.DajBrojPregleda());
        std::cout << "Unesite ime pacijenta: ";
        std::string ime;
        std::cin >> ime;
        p.ObrisiPregledePacijenta(ime);
        std::cout << "Uspjesno obrisano " << prije - p.DajBrojPregleda() << " pregleda" << std::endl;
    }
    if(unos == 4) {
        p.ObrisiNajranijiPregled();
        std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
    }
    if(unos == 5) {
        std::cout << "Unesite dan mjesec i godinu : ";
        int d,m,g;
        std::cin >> d >> m >> g;
        std::cout << "Pregledi na datum " << d << " " << m << " " << g <<" su:" << std::endl;
        p.IspisiPregledeNaDatum(Datum(d,m,g));
    }
    if(unos == 6) {
        p.IspisiSvePreglede();
    }
    if(unos == 7) {
        zavrsi=true;
    }

}


int main ()
{
    
        Pregledi p;
        for(;;) {
            std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::string unos;
            std::cin >> unos; 
            if(unos == "kraj") break;
            std::cout << "Unesite dan mjesec i godinu pregleda: ";
            int d,m,g;
            std::cin >> d >> m >> g;
            std::cout << "Unesite sate i minute pregleda: ";
            int s, min;
            std::cin >> s >> min;
            p.RegistrirajPregled(unos, d,m,g,s,min);
        }
        std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
        p.IspisiSvePreglede();
        std::cout << std::endl;
        for(;;) {
            bool zavrsi(false);
            Meni(zavrsi, p);
            std::cout << std::endl;
            if(zavrsi) break;
        }
    return 0;
}

//Implementacija interfejsa klase Datum
Datum::Datum(int dan, int mjesec, int godina)
{
    Postavi(dan, mjesec, godina);
}
void Datum::Postavi(int dan, int mjesec, int godina)
{
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
    if(!IspravanDatum()) throw std::domain_error ("Neispravan datum");
}
std::tuple<int, int, int> Datum::Ocitaj() const
{
    return std::tie(dan, mjesec, godina);
}
void Datum::Ispisi() const
{
    std::cout << dan << "/" << mjesec << "/" << godina;
}

bool Datum::IspravanDatum() const
{
    int broj_dana[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        broj_dana[1]++;
    if(mjesec <=0 || mjesec > 12) return false;
    if(dan < 0 || dan > broj_dana[mjesec-1]) return false;
    if(godina < 0) return false;
    return true;
}


//Implementacija interfejsa klase Vrijeme
Vrijeme::Vrijeme(int sati, int minute)
{
    Postavi(sati, minute);
}
void Vrijeme::Postavi(int sati, int minute)
{
    Vrijeme::sati = sati;
    Vrijeme::minute = minute;
    if(!IspravnoVrijeme()) throw std::domain_error ("Neispravno vrijeme");
}
std::pair<int, int> Vrijeme::Ocitaj() const
{
    return std::make_pair(sati, minute);
}
void Vrijeme::Ispisi() const
{
    if(sati < 10) std::cout << "0";
    std::cout << sati << ":";
    if(minute < 10) std::cout << "0";
    std::cout << minute;
}

bool Vrijeme::IspravnoVrijeme() const
{
    return (sati > 0 && sati <= 23 && minute > 0 && minute < 59);
}

//Implementacija interfejsa klase Pregled
Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
                 const Vrijeme &vrijeme_pregleda) : ime_pacijenta(ime_pacijenta),
    datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {}
Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
                 int godina_pregleda, int sati_pregleda, int minute_pregleda) : ime_pacijenta(ime_pacijenta),
    datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda),
    vrijeme_pregleda(sati_pregleda, minute_pregleda) {}
void Pregled::PromijeniPacijenta (const std::string &ime_pacijenta)
{
    Pregled::ime_pacijenta = ime_pacijenta;
}
void Pregled::PromijeniDatum (const Datum &novi_datum)
{
    Pregled::datum_pregleda = novi_datum;
}
void Pregled::PromijeniVrijeme (const Vrijeme &novo_vrijeme)
{
    Pregled::vrijeme_pregleda = novo_vrijeme;
}
void Pregled::PomjeriDanUnaprijed()
{
    int d,g,m;
    std::tie(d,m,g) = datum_pregleda.Ocitaj();
    int broj_dana[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0)
        broj_dana[1]++;
    d++;
    if(d > broj_dana[m-1]) {
        d = 1;
        m++;
        if(m > 12) {
            m = 1;
            g++;
        }
    }
    datum_pregleda.Postavi(d,m,g);
}
void Pregled::PomjeriDanUnazad()
{
    int d,g,m;
    std::tie(d,m,g) = datum_pregleda.Ocitaj();
    int broj_dana[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0)
        broj_dana[1]++;
    d--;
    if(d == 0) {
        if(m == 1) d = broj_dana[11];
        else d = broj_dana[m-2];
        m--;
        if(m == 0) {
            m = 12;
            g--;
        }
    }
    datum_pregleda.Postavi(d,m,g);
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
bool Pregled::DolaziPrije (const Pregled &p1, const Pregled &p2)
{
    if(Pregled::Prije(p1.datum_pregleda, p2.datum_pregleda)) return true;
    if(Pregled::Prije(p2.datum_pregleda, p1.datum_pregleda)) return false;
    return Pregled::Prije(p1.vrijeme_pregleda, p2.vrijeme_pregleda);
}
void Pregled::Ispisi() const
{
    std::cout << std::left << std::setw(30) << ime_pacijenta;
    datum_pregleda.Ispisi();
    std::cout << " ";
    vrijeme_pregleda.Ispisi();
    std::cout << std::endl;
}

bool Pregled::Prije(const Datum &d1, const Datum &d2)
{
    int dan1, dan2, mjesec1, mjesec2, godina1, godina2;
    std::tie(dan1, mjesec1, godina1) = d1.Ocitaj();
    std::tie(dan2, mjesec2, godina2) = d2.Ocitaj();
    if(godina1 < godina2) return true;
    if(godina1 == godina2 && mjesec1 < mjesec2) return true;
    if(godina1 == godina2 && mjesec1 == mjesec2 && dan1 < dan2) return true;
    return false;
}

bool Pregled::Prije(const Vrijeme &v1, const Vrijeme &v2)
{
    int sati1, minute1, sati2, minute2;
    std::tie(sati1, minute1) = v1.Ocitaj();
    std::tie(sati2, minute2) = v2.Ocitaj();
    return sati1*3600 + minute1*60 < sati2*3600 + minute2*60;
}

//Implementacija interfejsa klase Pregledi
Pregledi::Pregledi() {}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda)
{
    br_pregleda = spisak_pregleda.size();
    pregledi.resize(br_pregleda);
    auto it(spisak_pregleda.begin());
    for(int i=0; i<br_pregleda; i++) {
        pregledi[i] = std::make_shared<Pregled>(*it);
        it++;
    }

}
Pregledi::Pregledi(const Pregledi &p)
{

    pregledi.resize(p.pregledi.size());
    for(int i=0; i<pregledi.size(); i++)
        pregledi[i] = std::make_shared<Pregled>(*p.pregledi[i]);

    br_pregleda = p.br_pregleda;

}
Pregledi::Pregledi(Pregledi &&p)
{
    br_pregleda = p.br_pregleda;
    pregledi.resize(p.pregledi.size());
    for(int i=0; i<pregledi.size(); i++) {
        pregledi[i] = p.pregledi[i];
        p.pregledi[i] = nullptr;
    }
}
Pregledi& Pregledi::operator = (const Pregledi &p)
{
    if(this == &p) return *this;

    pregledi.resize(p.pregledi.size());
    for(int i=0; i<pregledi.size(); i++)
        pregledi[i] = std::make_shared<Pregled>(*p.pregledi[i]);

    br_pregleda = p.br_pregleda;
    return *this;


}

Pregledi& Pregledi::operator = (Pregledi &&p)
{

    br_pregleda=p.br_pregleda;
    pregledi.resize(p.pregledi.size());
    for(int i=0; i<pregledi.size(); i++) {
        pregledi[i] = p.pregledi[i];
        p.pregledi[i] = nullptr;
    }
    return *this;
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,
                                  const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    pregledi.push_back(std::make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda));
    br_pregleda++;

}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
                                  int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
                                  int minute_pregleda)
{
    pregledi.push_back(std::make_shared<Pregled>(ime_pacijenta, dan_pregleda, mjesec_pregleda,
                           godina_pregleda, sati_pregleda, minute_pregleda));
    br_pregleda++;
}
void Pregledi::RegistrirajPregled(PokNaPregled pregled)
{
    pregledi.push_back(pregled);
    br_pregleda++;
}
int Pregledi::DajBrojPregleda() const
{
    return br_pregleda;
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    int brojac(std::count_if(pregledi.begin(), pregledi.end(), [&datum](PokNaPregled p1) {
        return datum.Ocitaj() == p1->DajDatumPregleda().Ocitaj();
    }));
    return brojac;
}
Pregled& Pregledi::DajNajranijiPregled()
{
    if(br_pregleda == 0) throw std::domain_error ("Nema registriranih pregleda");
    auto it(std::min_element(pregledi.begin(), pregledi.end(), [](PokNaPregled p1, PokNaPregled p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    }));
    return **it;
}
Pregled Pregledi::DajNajranijiPregled() const
{
    if(br_pregleda == 0) throw std::domain_error ("Nema registriranih pregleda");
    auto it(std::min_element(pregledi.begin(), pregledi.end(), [](PokNaPregled p1, PokNaPregled p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    }));
    return **it;
}
void Pregledi::IsprazniKolekciju()
{
    pregledi.resize(0);
    br_pregleda=0;
}
void Pregledi::ObrisiNajranijiPregled()
{
    if(br_pregleda == 0) throw std::range_error ("Prazna kolekcija");
    Pregled najraniji_pregled(DajNajranijiPregled());
    auto it(std::find_if(pregledi.begin(), pregledi.end(), [&najraniji_pregled](PokNaPregled p) {
        return p->DajImePacijenta() == najraniji_pregled.DajImePacijenta() &&
               p->DajDatumPregleda().Ocitaj() == najraniji_pregled.DajDatumPregleda().Ocitaj() &&
               p->DajVrijemePregleda().Ocitaj() == najraniji_pregled.DajVrijemePregleda().Ocitaj();
    }));
    auto poz(it - pregledi.begin());
    pregledi[poz] = nullptr;
    std::stable_sort(pregledi.begin(), pregledi.end(), [](PokNaPregled p1, PokNaPregled p2) {
        return (p1 != nullptr && p2 == nullptr) || (p1 != nullptr && p2 != nullptr);
    });
    pregledi.resize(pregledi.size()-1);
    br_pregleda--;

}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    int brojac(0);
    auto it(std::for_each(pregledi.begin(), pregledi.end(), [&ime_pacijenta, &brojac, this](PokNaPregled &p) {
        if(p->DajImePacijenta() == ime_pacijenta) {
            p=nullptr;
            brojac++;
        }
    }));
    br_pregleda-=brojac;
    std::stable_sort(pregledi.begin(), pregledi.end(), [](PokNaPregled p1, PokNaPregled p2) {
        return (p1 != nullptr && p2 == nullptr) || (p1 != nullptr && p2 != nullptr);
    });
    pregledi.resize(pregledi.size()-brojac);
}
void Pregledi::IspisiPregledeNaDatum (const Datum &d) const 
{
    std::vector<PokNaPregled> tmp(pregledi.size());
    std::copy(pregledi.begin(), pregledi.end(), tmp.begin());
    std::sort(tmp.begin(), tmp.end(), [this](PokNaPregled p1, PokNaPregled  p2) {
        return Pregled::DolaziPrije(*p1,*p2);
    });
    std::for_each(tmp.begin(), tmp.end(), [this, &d](PokNaPregled p) {
        if(p->DajDatumPregleda().Ocitaj() == d.Ocitaj())
            p->Ispisi(); 
    });
}
void Pregledi::IspisiSvePreglede() const
{
    std::vector<PokNaPregled> tmp(pregledi.size());
    std::copy(pregledi.begin(), pregledi.end(), tmp.begin());
    std::sort(tmp.begin(), tmp.end(), [this](PokNaPregled p1, PokNaPregled  p2) {
        return Pregled::DolaziPrije(*p1,*p2);
    });
    std::for_each(tmp.begin(), tmp.end(), [this](PokNaPregled p) {
        p->Ispisi();
    });
}
