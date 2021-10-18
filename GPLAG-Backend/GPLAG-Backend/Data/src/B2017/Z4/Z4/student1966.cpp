/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <iomanip>
#include <algorithm>

#include <vector>
#include <memory>

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
    std::vector<std::shared_ptr<Pregled>> pregledi;
    
    void pobrisiPreglede() {
        for (int i = 0; i < pregledi.size(); i++)
            pregledi[i] = nullptr;
        
        pregledi.resize(0);
    }
public:
    explicit Pregledi();
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    
    ~Pregledi() {
        pobrisiPreglede();
    }
    
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator=(const Pregledi &pregledi);
    Pregledi &operator=(Pregledi &&pregledi);
    
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int datum_pregleda, int mjesec_pregleda,
        int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled);
    
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
    try {
        Pregledi pregledi;
        
        for (;;)
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

Pregledi::Pregledi(){}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda)
{
    try {
        for (auto pregled : spisak_pregleda)
            pregledi.push_back(std::make_shared<Pregled>(pregled));
    }
    catch (...) {
        pobrisiPreglede();
        throw;
    }
}

Pregledi::Pregledi(const Pregledi &pregledi)
{   try {
        for (int i = 0; i < pregledi.pregledi.size(); i++)
            this->pregledi.push_back(std::make_shared<Pregled>(*pregledi.pregledi[i]));
    }
    catch (...) {
        pobrisiPreglede();
        throw;
    }
}

Pregledi::Pregledi(Pregledi &&pregledi)
{
    this->pregledi = pregledi.pregledi;
    
    pregledi.pregledi.resize(0);
}

Pregledi &Pregledi::operator=(const Pregledi &pregledi)
{
    for (int i = 0; i < this->pregledi.size(); i++)
            *(this->pregledi[i]) = *pregledi.pregledi[i];
    
    try {    
        for (int i = this->pregledi.size(); i < pregledi.pregledi.size(); i++)
            this->pregledi.push_back(std::make_shared<Pregled>(*pregledi.pregledi[i]));
    }
    catch(...) {
        pobrisiPreglede();
        throw;
    }
    
    return *this;
}

Pregledi &Pregledi::operator=(Pregledi &&pregledi)
{
    this->pregledi = pregledi.pregledi;
    
    pregledi.pregledi.resize(0);
    
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    auto tmp = std::make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    
    RegistrirajPregled(tmp);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
    int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    RegistrirajPregled(ime_pacijenta, Datum(dan_pregleda, mjesec_pregleda, godina_pregleda), Vrijeme(sati_pregleda, minute_pregleda));
}

void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled)
{
    pregledi.push_back(pregled);
}

int Pregledi::DajBrojPregleda() const
{
    return pregledi.size();
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    return std::count_if(pregledi.begin(), pregledi.end(), [datum](const std::shared_ptr<Pregled> p) {
        return p->DajDatumPregleda().Ocitaj() == datum.Ocitaj();
    });
}

Pregled &Pregledi::DajNajranijiPregled()
{
    if (pregledi.size() == 0)
        throw std::domain_error("Nema registriranih pregleda");
    
    return **std::min_element(pregledi.begin(), pregledi.end(), [](const std::shared_ptr<Pregled> p1, const std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
}

Pregled Pregledi::DajNajranijiPregled() const
{
    if (pregledi.size() == 0)
        throw std::domain_error("Nema registriranih pregleda");
        
    return **std::min_element(pregledi.begin(), pregledi.end(), [](const std::shared_ptr<Pregled> p1, const std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
}

void Pregledi::IsprazniKolekciju()
{
    pobrisiPreglede();
}

void Pregledi::ObrisiNajranijiPregled()
{
    if (pregledi.size() == 0)
        throw std::range_error("Prazna kolekcija");
    
    auto poz = std::min_element(pregledi.begin(), pregledi.end(), [](const std::shared_ptr<Pregled> p1, const std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    pregledi.erase(poz);
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    std::vector<std::shared_ptr<Pregled>>::iterator found;
    while ((found = std::find_if(pregledi.begin(), pregledi.end(), [ime_pacijenta](const std::shared_ptr<Pregled> p) {
        return p->DajImePacijenta() == ime_pacijenta;
    })) != pregledi.end()) {
        pregledi.erase(found);
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    Pregledi tmp(*this);
    std::sort(tmp.pregledi.begin(), tmp.pregledi.end(), [](const std::shared_ptr<Pregled> p1, const std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    for (int i = 0; i < pregledi.size(); i++)
        if (tmp.pregledi[i]->DajDatumPregleda().Ocitaj() == datum.Ocitaj())
            tmp.pregledi[i]->Ispisi();
            
}
void Pregledi::IspisiSvePreglede() const
{
    Pregledi tmp(*this);
    std::sort(tmp.pregledi.begin(), tmp.pregledi.end(), [](const std::shared_ptr<Pregled> p1, const std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    for (int i = 0; i < pregledi.size(); i++)
        tmp.pregledi[i]->Ispisi();
}