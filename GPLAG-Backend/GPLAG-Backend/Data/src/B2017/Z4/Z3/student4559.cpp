/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <iomanip>
#include <algorithm>

#include <tuple>

#include <stdexcept>

class Datum {
    int dan, mjesec, godina;
public:
    static constexpr int brojDana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static bool jeLiPrestupna(int godina) {
        return godina % 400 == 0 || (godina % 4 == 0 && godina % 100 != 0);
    }
    
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
    std::pair<int, int> Ocitaj() const;
    void Ispisi() const;
};

class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
        int sati_pregleda, int minute_pregleda);
        
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

class Pregledi {
    Pregled **pregledi;
    int max_br_pregleda;
    int br_pregleda;
    
    void pobrisiPreglede() {
        for (int i = 0; i < br_pregleda; i++)
            delete pregledi[i];
        br_pregleda = 0;
        
        delete[] pregledi;
        pregledi = nullptr;
    }
public:
    explicit Pregledi(int max_broj_pregleda);
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    
    ~Pregledi();
    
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator=(const Pregledi &pregledi);
    Pregledi &operator=(Pregledi &&pregledi);
    
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int datum_pregleda, int mjesec_pregleda,
        int godina_pregleda, int sati_pregleda, int minute_pregleda);
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
    int max_br_pregleda;
    std::cout << "Unesite maksimalan broj pregleda: ";
    std::cin >> max_br_pregleda;
    
    try {
        Pregledi pregledi(max_br_pregleda);
        
        for (int i = 0; i < max_br_pregleda; i++)
        {
            std::string ime;
            std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::cin >> ime;
            if (ime == "kraj")
                break;
                
            int dan, mjesec, godina;
            std::cout << "Unesite dan mjesec i godinu pregleda: ";
            std::cin >> dan >> mjesec >> godina;
            
            int sati, minute;
            std::cout << "Unesite sate i minute pregleda: ";
            std::cin >> sati >> minute;
            
            pregledi.RegistrirajPregled(ime, dan, mjesec, godina, sati, minute);
        }
        
        std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
        pregledi.IspisiSvePreglede();
        
        for (;;)
        {
            int opcija;
            std::cout << std::endl;
            std::cout << "Odaberite jednu od sljedecih opcija" << std::endl;
            std::cout << "1 - Broj pregleda na datum" << std::endl;
            std::cout << "2 - Najraniji pregled" << std::endl;
            std::cout << "3 - Obrisi pregled pacijenta" << std::endl;
            std::cout << "4 - Obrisi najraniji pregled" << std::endl;
            std::cout << "5 - Ispisi sve pregleda na datum" << std::endl;
            std::cout << "6 - Ispisi sve preglede" << std::endl;
            std::cout << "7 - Kraj programa" << std::endl;
            std::cin >> opcija;
            
            if (opcija == 7)
                break;
                
            if (opcija == 1) {
                int dan, mjesec, godina;
                std::cout << "Unesite dan mjesec i godinu : ";
                std::cin >> dan >> mjesec >> godina;
                
                std::cout << "Broj pregleda na datum " << dan << " " << mjesec << " " << godina << " je: "
                    << pregledi.DajBrojPregledaNaDatum(Datum(dan, mjesec, godina)) << std::endl;
            }
            else if (opcija == 2) {
                std::cout << "Najraniji pregled je:" << std::endl;
                pregledi.DajNajranijiPregled().Ispisi();
            }
            else if (opcija == 3) {
                std::string ime;
                std::cout << "Unesite ime pacijenta: ";
                std::cin >> ime;
                
                int trenutniBroj = pregledi.DajBrojPregleda();
                pregledi.ObrisiPregledePacijenta(ime);
                std::cout << "Uspjesno obrisano " << trenutniBroj - pregledi.DajBrojPregleda() << " pregleda" << std::endl;
            }
            else if (opcija == 4) {
                pregledi.ObrisiNajranijiPregled();
                std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
            }
            else if (opcija == 5) {
                int dan, mjesec, godina;
                std::cout << "Unesite dan mjesec i godinu : ";
                std::cin >> dan >> mjesec >> godina;
                
                std::cout << "Pregledi na datum " << dan << " " << mjesec << " " << godina << " su:" << std::endl;
                pregledi.IspisiPregledeNaDatum(Datum(dan, mjesec, godina));
            }
            else if (opcija == 6) {
                pregledi.IspisiSvePreglede();
            }
        }
    }
    catch(const std::exception &er) {
        std::cout << er.what() << std::endl;
    }
    
	return 0;
}

/**
 * 
 * DATUM
 * 
 **/

constexpr int Datum::brojDana[];

Datum::Datum(int dan, int mjesec, int godina)
{
    Postavi(dan, mjesec, godina);
}

void Datum::Postavi(int dan, int mjesec, int godina)
{
    if (mjesec < 1 || mjesec > 12 || dan < 1 ||
        dan > Datum::brojDana[mjesec - 1] + (mjesec == 2 && jeLiPrestupna(godina)))
            throw std::domain_error("Neispravan datum");
        
    this->dan = dan;
    this->mjesec = mjesec;
    this->godina = godina;
}

std::tuple<int, int, int> Datum::Ocitaj() const
{
    return std::make_tuple(dan, mjesec, godina);
}

void Datum::Ispisi() const
{
    std::cout << dan << "/" << mjesec << "/" << godina/* << std::endl*/;
}

/**
 * 
 * END DATUM
 * 
 **/
 
/**
 * 
 * VRIJEME
 * 
 **/

Vrijeme::Vrijeme(int sati, int minute) 
{
    Postavi(sati, minute);
}

void Vrijeme::Postavi(int sati, int minute)
{
    if (minute < 0 || minute > 59 || sati < 0 || sati > 23)
        throw std::domain_error("Neispravno vrijeme");
        
    this->sati = sati;
    this->minute = minute;
}

std::pair<int, int> Vrijeme::Ocitaj() const
{
    return { sati, minute };
}

void Vrijeme::Ispisi() const
{
    std::cout.fill('0');
    std::cout << std::setw(2) << sati << ":"
        << std::setw(2) << minute/* << std::endl*/;
    std::cout.fill(' ');
}

/**
 * 
 * END VRIJEME
 * 
 **/
 
/**
 * 
 * PREGLED
 * 
 **/

Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) :
    datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda)
{
    this->ime_pacijenta = ime_pacijenta;
}

Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
    int godina_pregleda, int sati_pregleda, int minute_pregleda) :
    datum_pregleda(Datum(dan_pregleda, mjesec_pregleda, godina_pregleda)),
    vrijeme_pregleda(Vrijeme(sati_pregleda, minute_pregleda))
{
    this->ime_pacijenta = ime_pacijenta;
}
    
void Pregled::PromijeniPacijenta(const std::string &ime_pacijenta)
{
    this->ime_pacijenta = ime_pacijenta;
}

void Pregled::PromijeniDatum(const Datum &novi_datum)
{
    this->datum_pregleda = novi_datum;
}

void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme)
{
    this->vrijeme_pregleda = novo_vrijeme;
}

void Pregled::PomjeriDanUnaprijed()
{
    int dan_pregleda, mjesec_pregleda, godina_pregleda;
    std::tie(dan_pregleda, mjesec_pregleda, godina_pregleda) = datum_pregleda.Ocitaj();
    
    dan_pregleda++;
    if (dan_pregleda > Datum::brojDana[mjesec_pregleda - 1] + (mjesec_pregleda == 2 && Datum::jeLiPrestupna(godina_pregleda)))
    {
        dan_pregleda = 1;
        mjesec_pregleda++;
        
        if (mjesec_pregleda > 12)
        {
            mjesec_pregleda = 1;
            godina_pregleda++;
        }
    }
    
    datum_pregleda = Datum(dan_pregleda, mjesec_pregleda, godina_pregleda);
}

void Pregled::PomjeriDanUnazad()
{
    int dan_pregleda, mjesec_pregleda, godina_pregleda;
    std::tie(dan_pregleda, mjesec_pregleda, godina_pregleda) = datum_pregleda.Ocitaj();
    
    dan_pregleda--;
    if (dan_pregleda < 1)
    {
        mjesec_pregleda--;
        if (mjesec_pregleda < 1)
        {
            mjesec_pregleda = 12;
            godina_pregleda--;
        }
        
        dan_pregleda = Datum::brojDana[mjesec_pregleda - 1] + (mjesec_pregleda == 2 && Datum::jeLiPrestupna(godina_pregleda));
    }
    
    datum_pregleda = Datum(dan_pregleda, mjesec_pregleda, godina_pregleda);
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
    int v1_min, v1_sat, v2_min, v2_sat;
    int d1_dan, d1_mon, d1_god, d2_dan, d2_mon, d2_god;
    
    std::tie(v1_sat, v1_min) = p1.vrijeme_pregleda.Ocitaj();
    std::tie(v2_sat, v2_min) = p2.vrijeme_pregleda.Ocitaj();
    
    std::tie(d1_dan, d1_mon, d1_god) = p1.datum_pregleda.Ocitaj();
    std::tie(d2_dan, d2_mon, d2_god) = p2.datum_pregleda.Ocitaj();
    
    if (d1_god < d2_god)
        return true;
    else if (d1_god > d2_god)
        return false;
        
    if (d1_mon < d2_mon)
        return true;
    else if (d1_mon > d2_mon)
        return false;
        
    if (d1_dan < d2_dan)
        return true;
    else if (d1_dan > d2_dan)
        return false;
        
    
    if (v1_sat < v2_sat)
        return true;
    else if (v1_sat > v2_sat)
        return false;
    
    if (v1_min < v2_min)
        return true;
    else if (v1_min > v2_min)
        return false;
        
    return false;
}

void Pregled::Ispisi() const
{
    std::cout << std::setw(30) << std::left << ime_pacijenta;
    std::cout << std::right;
    datum_pregleda.Ispisi();
    std::cout << " ";
    vrijeme_pregleda.Ispisi();
    std::cout << std::endl;
}

/**
 * 
 * END PREGLED
 * 
 **/
 
/**
 * 
 * PREGLEDI
 * 
 **/

Pregledi::Pregledi(int max_broj_pregleda) : max_br_pregleda(max_broj_pregleda)
{
    br_pregleda = 0;
    pregledi = new Pregled*[max_br_pregleda]{};
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : max_br_pregleda(spisak_pregleda.size())
{
    br_pregleda = max_br_pregleda;
    pregledi = new Pregled*[max_br_pregleda]{};
    
    try {
        auto &it = pregledi;
        for (auto pregled : spisak_pregleda)
        {
            *it = new Pregled(pregled);
            it++;
        }
    }
    catch (...) {
        pobrisiPreglede();
        throw;
    }
}

Pregledi::~Pregledi()
{
    pobrisiPreglede();
}

Pregledi::Pregledi(const Pregledi &pregledi) : max_br_pregleda(pregledi.max_br_pregleda)
{
    br_pregleda = pregledi.br_pregleda;
    this->pregledi = new Pregled*[max_br_pregleda]{};
    
    try {
        for (int i = 0; i < br_pregleda; i++)
            this->pregledi[i] = new Pregled(*pregledi.pregledi[i]);
    }
    catch (...) {
        pobrisiPreglede();
        throw;
    }
}

Pregledi::Pregledi(Pregledi &&pregledi) : max_br_pregleda(pregledi.max_br_pregleda)
{
    br_pregleda = pregledi.br_pregleda;
    this->pregledi = pregledi.pregledi;
    
    pregledi.br_pregleda = 0;
    pregledi.pregledi = nullptr;
}

Pregledi &Pregledi::operator=(const Pregledi &pregledi)
{
    if (pregledi.max_br_pregleda != max_br_pregleda)
        throw;
        
    for (int i = 0; i < br_pregleda; i++)
        if (i >= pregledi.br_pregleda)
            delete this->pregledi[i];
        else
            *(this->pregledi[i]) = *pregledi.pregledi[i];
    
    try {    
        for (int i = br_pregleda; i < pregledi.br_pregleda; i++)
            this->pregledi[i] = new Pregled(*pregledi.pregledi[i]);
    }
    catch(...) {
        pobrisiPreglede();
        throw;
    }
    
    br_pregleda = pregledi.br_pregleda;
    return *this;
}

Pregledi &Pregledi::operator=(Pregledi &&pregledi)
{
    if (pregledi.max_br_pregleda != max_br_pregleda)
        throw;
    
    pobrisiPreglede();
    
    br_pregleda = pregledi.br_pregleda;
    this->pregledi = pregledi.pregledi;
    
    pregledi.br_pregleda = 0;
    pregledi.pregledi = nullptr;
    
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    if (br_pregleda >= max_br_pregleda)
        throw std::range_error("Dostignut maksimalni broj pregleda");
    
    Pregled *tmp = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    
    RegistrirajPregled(tmp);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
    int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    RegistrirajPregled(ime_pacijenta, Datum(dan_pregleda, mjesec_pregleda, godina_pregleda), Vrijeme(sati_pregleda, minute_pregleda));
}

void Pregledi::RegistrirajPregled(Pregled *pregled)
{
    if (br_pregleda >= max_br_pregleda)
        throw std::range_error("Dostignut maksimalni broj pregleda");
    
    pregledi[br_pregleda] = pregled;
    pregled = nullptr;
    
    br_pregleda++;
}

int Pregledi::DajBrojPregleda() const
{
    return br_pregleda;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    return std::count_if(pregledi, pregledi + br_pregleda, [datum](const Pregled *p) {
        return p->DajDatumPregleda().Ocitaj() == datum.Ocitaj();
    });
}

Pregled &Pregledi::DajNajranijiPregled()
{
    if (br_pregleda == 0)
        throw std::domain_error("Nema registriranih pregleda");
    
    return **std::min_element(pregledi, pregledi + br_pregleda, [](const Pregled *p1, const Pregled *p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
}

Pregled Pregledi::DajNajranijiPregled() const
{
    if (br_pregleda == 0)
        throw std::domain_error("Nema registriranih pregleda");
        
    return **std::min_element(pregledi, pregledi + br_pregleda, [](const Pregled *p1, const Pregled *p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
}

void Pregledi::IsprazniKolekciju()
{
    pobrisiPreglede();
}

void Pregledi::ObrisiNajranijiPregled()
{
    if (br_pregleda == 0)
        throw std::range_error("Prazna kolekcija");
    
    auto poz = std::min_element(pregledi, pregledi + br_pregleda, [](const Pregled *p1, const Pregled *p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    auto tbd = *poz;
    while (poz + 1 != pregledi + br_pregleda) {
        *poz = *(poz + 1);
        poz++;
    }
    
    br_pregleda--;
    pregledi[br_pregleda] = nullptr;
    delete tbd;
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    Pregled **found;
    while ((found = std::find_if(pregledi, pregledi + br_pregleda, [ime_pacijenta](const Pregled *p) {
        return p->DajImePacijenta() == ime_pacijenta;
    })) != pregledi + br_pregleda) {
        auto tbd = *found;
        while (found + 1 != pregledi + br_pregleda) {
            *found = *(found + 1);
            found++;
        }
        
        br_pregleda--;
        pregledi[br_pregleda] = nullptr;
        delete tbd;
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    Pregledi tmp(*this);
    std::sort(tmp.pregledi, tmp.pregledi + br_pregleda, [](const Pregled *p1, const Pregled *p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    for (int i = 0; i < br_pregleda; i++)
        if (tmp.pregledi[i]->DajDatumPregleda().Ocitaj() == datum.Ocitaj())
            tmp.pregledi[i]->Ispisi();
            
}
void Pregledi::IspisiSvePreglede() const
{
    Pregledi tmp(*this);
    std::sort(tmp.pregledi, tmp.pregledi + br_pregleda, [](const Pregled *p1, const Pregled *p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    for (int i = 0; i < br_pregleda; i++)
        tmp.pregledi[i]->Ispisi();
}