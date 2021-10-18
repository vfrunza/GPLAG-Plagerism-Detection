#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <tuple>
#include <utility>
#include <string>
#include <initializer_list>
#include <algorithm>

class Datum {
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina) {
        int br_dana[12] {31, 28, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31};
        if (godina % 400 == 0 || (godina % 100 != 0 && godina % 4 == 0)) br_dana[1]++;
        if (dan < 0 || dan > br_dana[mjesec-1] || mjesec < 0 || mjesec > 12 || godina < 0)
            throw std::domain_error("Neispravan datum");
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    }
    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(dan, mjesec, godina);
    }
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

class Vrijeme {
    int sati, minute;
public:
    Vrijeme(int sati, int minute) { Postavi(sati, minute); }
    void Postavi(int sati, int minute) {
        if (sati < 0 || sati > 23 || minute < 0 || minute > 59)
            throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati = sati; Vrijeme::minute = minute;
    }
    std::pair<int, int> Ocitaj() const {
        return std::make_pair(sati, minute);
    }
    void Ispisi() const {
        std::cout << std::setw(2) << std::setfill('0') << std::right
        << sati << ":" << std::setw(2) << minute;
    }
};

class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    int DaniUMjesecu(int mjesec, int godina) {
        int br_dana[12] {31, 28, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31};
        if (godina % 400 == 0 || (godina % 100 != 0 && godina % 4 == 0)) br_dana[1]++;
        return br_dana[mjesec-1];
    }
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
        const Vrijeme &vrijeme_pregleda) : ime_pacijenta(ime_pacijenta),
        datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) { }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
        int godina_pregleda, int sati_pregleda, int minute_pregleda) :
        ime_pacijenta(ime_pacijenta),
        datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda),
        vrijeme_pregleda(sati_pregleda, minute_pregleda) {}
    void PromjeniPacijenta(const std::string &novi_pacijent) {
        ime_pacijenta = novi_pacijent;
    }
    void PromjeniDatum(const Datum &novi_datum) {
        datum_pregleda = novi_datum;
    }
    void PromjeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme_pregleda = novo_vrijeme;
    }
    void PomjeriDanUnaprijed() {
        auto dat(datum_pregleda.Ocitaj());
        int d(std::get<0>(dat)+1), m(std::get<1>(dat)), g(std::get<2>(dat));
        if (d > DaniUMjesecu(m,g)) { d = 1; m++; }
        if (m > 12) { m = 1; g++; }
        datum_pregleda.Postavi(d,m,g);
    }
    void PomjeriDanUnazad() {
        auto dat(datum_pregleda.Ocitaj());
        int d(std::get<0>(dat)-1), m(std::get<1>(dat)), g(std::get<2>(dat));
        if (d == 0) { m--; d = DaniUMjesecu(m, g); }
        if (m == 0) { m = 12; g--; }
        datum_pregleda.Postavi(d,m,g);
    }
    std::string DajImePacijenta() const { return ime_pacijenta; }
    Datum DajDatumPregleda() const { return datum_pregleda; }
    Vrijeme DajVrijemePregleda() const { return vrijeme_pregleda; }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const {
        std::cout << std::left << std::setw(30) << std::setfill(' ') << ime_pacijenta; 
        datum_pregleda.Ispisi();
        std::cout << " ";
        vrijeme_pregleda.Ispisi() ;
        std::cout << std::endl;
    }
    static bool IstiTermin(const Pregled &p1, const Pregled &p2) {
        return p1.DajDatumPregleda().Ocitaj() == p2.DajDatumPregleda().Ocitaj()
            && p1.DajVrijemePregleda().Ocitaj() == p2.DajVrijemePregleda().Ocitaj();
    }
};

class Pregledi{
    int max_broj_pregleda, broj_pregleda;
    Pregled **pregledi;
    void ObrisiSvePreglede() {
        for (int i = 0; i < broj_pregleda; i++) delete pregledi[i];
        delete [] pregledi;
    }
    int DajSljedeci(int trenutni) const {
        int sljedeci(-1);
        for (int i = 0; i < broj_pregleda; i++) {
            if (i == trenutni || Pregled::DolaziPrije(*pregledi[i], *pregledi[trenutni]) ||
                Pregled::IstiTermin(*pregledi[i], *pregledi[trenutni]) && i < trenutni) continue;
            if (sljedeci == -1) sljedeci = i;
            else if ((Pregled::DolaziPrije(*pregledi[trenutni], *pregledi[i])
                || Pregled::IstiTermin(*pregledi[trenutni], *pregledi[i]))
                && Pregled::DolaziPrije(*pregledi[i], *pregledi[sljedeci]))
                sljedeci = i;
        }
        return sljedeci;
    }
public:
    explicit Pregledi(int max_broj_pregleda) : max_broj_pregleda(max_broj_pregleda),
        broj_pregleda(0), pregledi(new Pregled*[max_broj_pregleda]{}) {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi() { ObrisiSvePreglede(); }
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&p) : max_broj_pregleda(p.max_broj_pregleda),
        broj_pregleda(p.broj_pregleda), pregledi(p.pregledi) {
        p.pregledi = nullptr; p.broj_pregleda = 0;
    }
    Pregledi &operator = (const Pregledi &pregledi);
    Pregledi &operator = (Pregledi &&pregledi) {
        std::swap(max_broj_pregleda, pregledi.max_broj_pregleda);
        std::swap(broj_pregleda, pregledi.broj_pregleda);
        std::swap(this->pregledi, pregledi.pregledi);
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &dat, 
        const Vrijeme &vrijeme) {
            if (broj_pregleda == max_broj_pregleda)
                throw std::range_error("Dostignut maksimalni broj pregleda");
            pregledi[broj_pregleda] = new Pregled(ime_pacijenta, dat, vrijeme);
            broj_pregleda++;
        }
    void RegistrirajPregled(const std::string &ime_pacijenta, int d, int m, 
        int g, int h, int min) {
            if (broj_pregleda == max_broj_pregleda)
                throw std::range_error("Dostignut maksimalni broj pregleda");
            pregledi[broj_pregleda] = new Pregled(ime_pacijenta, d, m, g, h, min);
            broj_pregleda++;
        }
    void RegistrirajPregled(Pregled *pregled) {
        if (broj_pregleda == max_broj_pregleda)
            throw std::range_error("Dostignut maksimalni broj pregleda");
        pregledi[broj_pregleda++] = pregled;
        pregled = nullptr;
    }
    int DajBrojPregleda() const { return broj_pregleda; }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju() {
        for (int i = 0; i < broj_pregleda; i++) delete pregledi[i];
        broj_pregleda = 0;
    }
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
    
};

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    auto dat1(p1.DajDatumPregleda().Ocitaj());
    auto dat2(p2.DajDatumPregleda().Ocitaj());
        if (std::get<2>(dat1) == std::get<2>(dat2)) {
            if (std::get<1>(dat1) == std::get<1>(dat2)) {
                if (std::get<0>(dat1) == std::get<0>(dat2)) {
                    auto v1(p1.DajVrijemePregleda().Ocitaj());
                    auto v2(p2.DajVrijemePregleda().Ocitaj());
                    if (v1.first == v2.first) 
                        return v1.second < v2.second;
                    return v1.first < v2.first;
                }
                return std::get<0>(dat1) < std::get<0>(dat2);
            }
            return std::get<1>(dat1) < std::get<1>(dat2);
        }
        return std::get<2>(dat1) < std::get<2>(dat2);
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) :
    max_broj_pregleda(spisak_pregleda.size()), broj_pregleda(max_broj_pregleda),
    pregledi(new Pregled*[broj_pregleda]{}) {
        try {
            int i(0);
            for (auto it = spisak_pregleda.begin(); it != spisak_pregleda.end(); it++) {
            pregledi[i] = new Pregled(*it); i++;
            }
        }
        catch (...) {
            ObrisiSvePreglede(); throw;
        }
}
Pregledi::Pregledi(const Pregledi &p) : max_broj_pregleda(p.max_broj_pregleda),   
    broj_pregleda(p.broj_pregleda), pregledi(new Pregled*[max_broj_pregleda]{}) {
        try {
            for (int i = 0; i < broj_pregleda; i++)
                pregledi[i] = new Pregled(*p.pregledi[i]);
        }
        catch(...) {
            ObrisiSvePreglede(); throw;
        }
    }
    
Pregledi &Pregledi::operator = (const Pregledi &p) {
    if (max_broj_pregleda != p.max_broj_pregleda) {
        auto novi_pregledi(new Pregled*[p.max_broj_pregleda]{});
        try {
            for (int i = 0; i < p.broj_pregleda; i++) novi_pregledi[i] = new Pregled(*p.pregledi[i]);
            broj_pregleda = p.broj_pregleda; max_broj_pregleda = p.max_broj_pregleda;
        }
        catch(...) {
            for (int i = 0; i < p.broj_pregleda; i++) delete novi_pregledi[i];
            delete [] novi_pregledi; throw;
        }
        ObrisiSvePreglede(); pregledi = novi_pregledi; return *this;
    }
    for (int i = 0; i < broj_pregleda; i++)
        *pregledi[i] = *p.pregledi[i];
    return *this;
}
    
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    return std::count_if(pregledi, pregledi + broj_pregleda, 
        [datum](Pregled *p) { 
            return p->DajDatumPregleda().Ocitaj() == datum.Ocitaj(); 
        });
}
Pregled &Pregledi::DajNajranijiPregled() {
    if (broj_pregleda == 0) throw std::domain_error("Nema registriranih pregleda");
    return **(std::min_element(pregledi, pregledi + broj_pregleda,
        [](Pregled *p1, Pregled *p2) { return Pregled::DolaziPrije(*p1,*p2); }));
}
Pregled Pregledi::DajNajranijiPregled() const {
    if (broj_pregleda == 0) throw std::domain_error("Nema registriranih pregleda");
    return **(std::min_element(pregledi, pregledi + broj_pregleda,
        [](Pregled *p1, Pregled *p2) { return Pregled::DolaziPrije(*p1,*p2); }));
}

void Pregledi::ObrisiNajranijiPregled() {
    if (broj_pregleda == 0) throw std::range_error("Prazna kolekcija");
    auto pok(&DajNajranijiPregled());
    int i(0);
    for (; i < broj_pregleda; i++) if (pregledi[i] == pok) break;
    delete pregledi[i]; broj_pregleda--;
    for (; i < broj_pregleda; i++) pregledi[i] = pregledi[i+1];
    pregledi[i] = nullptr;
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    for (int i = 0; i < broj_pregleda; i++) {
        if (pregledi[i]->DajImePacijenta() == ime_pacijenta) {
            delete pregledi[i]; 
            for (int j = i; j < broj_pregleda-1; j++) pregledi[j] = pregledi[j+1];
            pregledi[--broj_pregleda] = nullptr;
            i--;
        }
    }
}

void Pregledi::IspisiSvePreglede() const {
    Pregled p(DajNajranijiPregled());
    int x(0);
    while (!Pregled::IstiTermin(*pregledi[x], p) || !(pregledi[x]->DajImePacijenta() == p.DajImePacijenta())) x++;
    for (int i = 0; i < broj_pregleda; i++) {
        pregledi[x]->Ispisi();
        int a(DajSljedeci(x));
        if (a != -1) x = a;
    }
}
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
    Pregled p(DajNajranijiPregled());
    int x(0);
    while (!Pregled::IstiTermin(*pregledi[x], p) || !(pregledi[x]->DajImePacijenta() == p.DajImePacijenta())) x++;
    for (int i = 0; i < broj_pregleda; i++) {
        if (pregledi[x]->DajDatumPregleda().Ocitaj() == datum.Ocitaj()) pregledi[x]->Ispisi();
        int a(DajSljedeci(x));
        if (a != -1) x = a;
    }
}


int main() {
    int max(0);
    std::cout << "Unesite maksimalan broj pregleda: ";
    std::cin >> max;
    try {
        Pregledi pregledi(max);
        for (int i = 0; i < max; i++) {
            std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::string ime;
            if (std::cin >> ime, ime == "kraj") break;
            std::cout << "Unesite dan mjesec i godinu pregleda: ";
            int d, m, g, s, min;
            std::cin >> d >> m >> g;
            std::cout << "Unesite sate i minute pregleda: ";
            std::cin >> s >> min;
            pregledi.RegistrirajPregled(ime, d, m, g, s, min);
        }
        std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
        pregledi.IspisiSvePreglede();
        for (;;) {
            std::cout << std::endl;
            std::cout << "Odaberite jednu od sljedecih opcija" << std::endl
            << "1 - Broj pregleda na datum" << std::endl
            << "2 - Najraniji pregled" << std::endl
            << "3 - Obrisi pregled pacijenta" << std::endl
            << "4 - Obrisi najraniji pregled" << std::endl
            << "5 - Ispisi sve pregleda na datum" << std::endl
            << "6 - Ispisi sve preglede" << std::endl
            << "7 - Kraj programa" << std::endl;
            int n; std::cin >> n;
            switch(n) {
                case 1: {
                    int d,m,g;
                    std::cout << "Unesite dan mjesec i godinu : ";
                    std::cin >> d >> m >> g;
                    Datum dat(d,m,g);
                    std::cout << "Broj pregleda na datum " << d << " " << m 
                    << " " << g << " je: " << pregledi.DajBrojPregledaNaDatum(dat)
                    << std::endl;
                    break;
                }
                case 2: {
                    std::cout << "Najraniji pregled je:" << std::endl;
                    pregledi.DajNajranijiPregled().Ispisi();
                    break;
                }
                case 3: {
                    std::string ime;
                    std::cout << "Unesite ime pacijenta: ";
                    std::cin >> ime;
                    int br(pregledi.DajBrojPregleda());
                    pregledi.ObrisiPregledePacijenta(ime);
                    std::cout << "Uspjesno obrisano " 
                    << br - pregledi.DajBrojPregleda() 
                    << " pregleda" << std::endl;
                    break;
                }
                case 4: {
                    pregledi.ObrisiNajranijiPregled();
                    std::cout << "Najraniji pregled uspjesno obrisan" 
                    << std::endl;
                    break;
                }
                case 5: {
                    int d,m,g;
                    std::cout << "Unesite dan mjesec i godinu : ";
                    std::cin >> d >> m >> g;
                    Datum dat(d,m,g);
                    std::cout << "Pregledi na datum " << d << " " << m 
                    << " " << g << " su:" << std::endl;
                    pregledi.IspisiPregledeNaDatum(dat);
                    break;
                }
                case 6: {
                    pregledi.IspisiSvePreglede();
                    break;
                }
                case 7: return 0;
            }
        }
    }
    catch (std::range_error e) {
        std::cout << e.what();
    }
    catch (std::domain_error e) {
        std::cout << e.what();
    }
    catch (std::bad_alloc) {
        std::cout << "Problemi sa memorijom";
    }
    return 0;
}