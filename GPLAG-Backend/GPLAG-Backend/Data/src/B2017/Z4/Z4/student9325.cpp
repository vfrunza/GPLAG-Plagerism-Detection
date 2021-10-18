/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <tuple>
#include <utility>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <memory>
#include <vector>
#include <iterator>

class Datum {
    int dan, mjesec, godina;
    static int BrojDana(int mjesec, int godina);
public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan, mjesec, godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(dan, mjesec, godina);
    }
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

int Datum::BrojDana(int mjesec, int godina) {
    int broj_dana_u_mjesecu[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (godina%4==0 && godina%100!=0 || godina%400==0) broj_dana_u_mjesecu[1]=29;
    return broj_dana_u_mjesecu[mjesec-1];
}

void Datum::Postavi(int dan, int mjesec, int godina) {
    if (godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>BrojDana(mjesec, godina)) {
        throw std::domain_error("Neispravan datum");
    }
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}


class Vrijeme {
    int sati, minute;
public:
    Vrijeme(int sati, int minute) {
        Postavi(sati, minute);
    }
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj() const {
        return std::make_pair(sati, minute);
    }
    void Ispisi() const {
        std::cout << std::right << std::setw(2) << std::setfill('0') << sati << ":"
        << std::right << std::setw(2) << std::setfill('0') << minute;
    }
};

void Vrijeme::Postavi(int sati, int minute) {
    if (sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati=sati; Vrijeme::minute=minute;
}


class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    static int BrojDanaUMjesecu(int mjesec, int godina);
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, 
     const Vrijeme &vrijeme_pregleda);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, 
    int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        Pregled::datum_pregleda=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        Pregled::vrijeme_pregleda=novo_vrijeme;
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
    void Ispisi() const;
};

Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : 
ime_pacijenta(ime_pacijenta), 
datum_pregleda(datum_pregleda), 
vrijeme_pregleda(vrijeme_pregleda) {}

Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, 
 int godina_pregleda, int sati_pregleda, int minute_pregleda) : 
ime_pacijenta(ime_pacijenta), 
datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), 
vrijeme_pregleda(sati_pregleda, minute_pregleda) {}

void Pregled::Ispisi() const {
    std::cout << std::left << std::setw(30) << std::setfill(' ') << ime_pacijenta;
    datum_pregleda.Ispisi();
    std::cout << " ";
    vrijeme_pregleda.Ispisi();
    std::cout << std::endl;
}

int Pregled::BrojDanaUMjesecu(int mjesec, int godina) {
    int broj_dana_u_mjesecu[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (godina%4==0 && godina%100!=0 || godina%400==0) broj_dana_u_mjesecu[1]=29;
    return broj_dana_u_mjesecu[mjesec-1];
}

void Pregled::PomjeriDanUnazad() {
    int dan(std::get<0>(datum_pregleda.Ocitaj()));
    int mjesec(std::get<1>(datum_pregleda.Ocitaj()));
    int godina(std::get<2>(datum_pregleda.Ocitaj()));
    dan--;
    if (dan<1) {
        mjesec--;
        if (mjesec<1) {
            mjesec=12;
            godina--;
        }
        dan=BrojDanaUMjesecu(mjesec, godina);
    }
}

void Pregled::PomjeriDanUnaprijed() {
    int dan(std::get<0>(datum_pregleda.Ocitaj()));
    int mjesec(std::get<1>(datum_pregleda.Ocitaj()));
    int godina(std::get<2>(datum_pregleda.Ocitaj()));
    dan++;
    if (dan>BrojDanaUMjesecu(mjesec, godina)) dan=1, mjesec++;
    if (mjesec>12) mjesec=1, godina++;
}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    return std::get<2>(p1.datum_pregleda.Ocitaj())<std::get<2>(p2.datum_pregleda.Ocitaj()) 
    || std::get<2>(p1.datum_pregleda.Ocitaj())==std::get<2>(p2.datum_pregleda.Ocitaj()) 
    && std::get<1>(p1.datum_pregleda.Ocitaj())<std::get<1>(p2.datum_pregleda.Ocitaj()) 
    || std::get<2>(p1.datum_pregleda.Ocitaj())==std::get<2>(p2.datum_pregleda.Ocitaj()) 
    && std::get<1>(p1.datum_pregleda.Ocitaj())==std::get<1>(p2.datum_pregleda.Ocitaj()) 
    && std::get<0>(p1.datum_pregleda.Ocitaj())<std::get<0>(p2.datum_pregleda.Ocitaj()) 
    || std::get<2>(p1.datum_pregleda.Ocitaj())==std::get<2>(p2.datum_pregleda.Ocitaj()) 
    && std::get<1>(p1.datum_pregleda.Ocitaj())==std::get<1>(p2.datum_pregleda.Ocitaj()) 
    && std::get<0>(p1.datum_pregleda.Ocitaj())==std::get<0>(p2.datum_pregleda.Ocitaj()) 
    && p1.vrijeme_pregleda.Ocitaj().first<p2.vrijeme_pregleda.Ocitaj().first 
    || std::get<2>(p1.datum_pregleda.Ocitaj())==std::get<2>(p2.datum_pregleda.Ocitaj()) 
    && std::get<1>(p1.datum_pregleda.Ocitaj())==std::get<1>(p2.datum_pregleda.Ocitaj()) 
    && std::get<0>(p1.datum_pregleda.Ocitaj())==std::get<0>(p2.datum_pregleda.Ocitaj()) 
    && p1.vrijeme_pregleda.Ocitaj().first==p2.vrijeme_pregleda.Ocitaj().first 
    && p1.vrijeme_pregleda.Ocitaj().second<p2.vrijeme_pregleda.Ocitaj().second;
}


class Pregledi {
    std::vector<std::shared_ptr<Pregled>> p_pregledi;
public:
    explicit Pregledi()=default;
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi()=default;
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi)=default;
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi)=default;
    void RegistrirajPregled(const std::string &ime_pacijenta, 
     const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, 
     int mjesec_pregleda, int godina_pregleda, int sati_pregleda, 
     int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled);
    int DajBrojPregleda() const {
        return p_pregledi.size();
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

void Pregledi::IsprazniKolekciju() {
    p_pregledi.resize(0);
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) {
    for (std::initializer_list<Pregled>::iterator iter=spisak_pregleda.begin(); iter!=spisak_pregleda.end(); iter++) {
        p_pregledi.push_back(std::make_shared<Pregled>(*iter));
    }
}

Pregledi::Pregledi(const Pregledi &pregledi) {
    for (auto iter=pregledi.p_pregledi.begin(); iter!=pregledi.p_pregledi.end(); iter++) {
        p_pregledi.push_back(std::make_shared<Pregled>(**iter));
    }
}

Pregled &Pregledi::DajNajranijiPregled() {
    if (p_pregledi.size()==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(p_pregledi.begin(), p_pregledi.end(), [](std::shared_ptr<Pregled> prvi, std::shared_ptr<Pregled> drugi) {
        return Pregled::DolaziPrije(*prvi, *drugi);
    });
}

Pregled Pregledi::DajNajranijiPregled() const {
    if (p_pregledi.size()==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(p_pregledi.begin(), p_pregledi.end(), [](std::shared_ptr<Pregled> prvi, std::shared_ptr<Pregled> drugi) {
        return Pregled::DolaziPrije(*prvi, *drugi);
    });
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi) {
    p_pregledi.resize(0);
    for (auto iter=pregledi.p_pregledi.begin(); iter!=pregledi.p_pregledi.end(); iter++) {
        p_pregledi.push_back(std::make_shared<Pregled>(**iter));
    }
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, 
const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    p_pregledi.push_back(std::make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda));
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, 
int dan_pregleda, int mjesec_pregleda, int godina_pregleda, 
int sati_pregleda, int minute_pregleda) {
    p_pregledi.push_back(std::make_shared<Pregled>(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, 
     sati_pregleda, minute_pregleda));
}

void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled) {
    p_pregledi.push_back(pregled);
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    return std::count_if(p_pregledi.begin(), p_pregledi.end(), [datum](std::shared_ptr<Pregled> pregled) {
        return (pregled->DajDatumPregleda()).Ocitaj()==datum.Ocitaj();
    });
}

void Pregledi::ObrisiNajranijiPregled() {
    if (p_pregledi.size()==0) throw std::range_error("Prazna kolekcija");
    std::tuple<int, int, int> datum_najranijeg((DajNajranijiPregled().DajDatumPregleda()).Ocitaj());
    std::pair<int, int> vrijeme_najranijeg((DajNajranijiPregled().DajVrijemePregleda()).Ocitaj());
    for (auto iter=p_pregledi.begin(); iter!=p_pregledi.end(); iter++) {
        if (((*iter)->DajDatumPregleda()).Ocitaj()==datum_najranijeg && 
        ((*iter)->DajVrijemePregleda()).Ocitaj()==vrijeme_najranijeg) {
            p_pregledi.erase(iter);
            break;
        }
    }
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    for (auto iter=p_pregledi.begin(); iter!=p_pregledi.end(); iter++) {
        if ((*iter)->DajImePacijenta()==ime_pacijenta) {
            iter=p_pregledi.erase(iter);
            iter--;
        }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
    std::vector<std::shared_ptr<Pregled>> vektor_pokazivaca;
    for (auto iter=p_pregledi.begin(); iter!=p_pregledi.end(); iter++) {
        if (((*iter)->DajDatumPregleda()).Ocitaj()==datum.Ocitaj()) vektor_pokazivaca.push_back(*iter);
    }
    std::sort(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [](std::shared_ptr<Pregled> prvi, std::shared_ptr<Pregled> drugi) {
        return Pregled::DolaziPrije(*prvi, *drugi);
    });
    for (auto iter=vektor_pokazivaca.begin(); iter!=vektor_pokazivaca.end(); iter++) {
        (*iter)->Ispisi();
    }
}

void Pregledi::IspisiSvePreglede() const {
    std::vector<std::shared_ptr<Pregled>> vektor_pokazivaca;
    for (auto iter=p_pregledi.begin(); iter!=p_pregledi.end(); iter++) {
        vektor_pokazivaca.push_back(*iter);
    }
    std::sort(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [](std::shared_ptr<Pregled> prvi, std::shared_ptr<Pregled> drugi) {
        return Pregled::DolaziPrije(*prvi, *drugi);
    });
    for (auto iter=vektor_pokazivaca.begin(); iter!=vektor_pokazivaca.end(); iter++) {
        (*iter)->Ispisi();
    }
}


int main ()
{
    Pregledi pregledi;
    while (1) {
        try {
            std::string ime_pacijenta;
            std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::getline(std::cin, ime_pacijenta);
            if (ime_pacijenta=="kraj") break;
            std::cout << "Unesite dan mjesec i godinu pregleda: ";
            int dan(0), mjesec(0), godina(0);
            std::cin >> dan >> mjesec >> godina;
            int sati(0), minute(0);
            std::cout << "Unesite sate i minute pregleda: ";
            std::cin >> sati >> minute;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            pregledi.RegistrirajPregled(ime_pacijenta, dan, mjesec, godina, sati, minute);
        }
        catch(std::domain_error domain_greska) {
            std::cout << domain_greska.what() << std::endl;
        }
        catch(std::range_error range_greska) {
            std::cout << range_greska.what() << std::endl;
        }
    }
    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
    pregledi.IspisiSvePreglede();
    int opcija(0);
    while (opcija!=7) {
        try {
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
            if (opcija==7) break;
            else if (opcija==1) {
                int uneseni_dan(0), uneseni_mjesec(0), unesena_godina(0);
                std::cout << "Unesite dan mjesec i godinu : ";
                std::cin >> uneseni_dan >> uneseni_mjesec >> unesena_godina;
                std::cout << "Broj pregleda na datum " << uneseni_dan << " " 
                << uneseni_mjesec << " " << unesena_godina 
                << " je: " << pregledi.DajBrojPregledaNaDatum(Datum(uneseni_dan, uneseni_mjesec, unesena_godina));
                std::cout << std::endl;
            }
            else if (opcija==2) {
                std::cout << "Najraniji pregled je:" << std::endl;
                pregledi.DajNajranijiPregled().Ispisi();
            }
            else if (opcija==3) {
                std::string ime_p;
                std::cout << "Unesite ime pacijenta: ";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::getline(std::cin, ime_p);
                int broj_trenutnih(pregledi.DajBrojPregleda());
                pregledi.ObrisiPregledePacijenta(ime_p);
                int broj_novih(pregledi.DajBrojPregleda());
                int broj_obrisanih(broj_trenutnih-broj_novih);
                std::cout << "Uspjesno obrisano " << broj_obrisanih << " pregleda" << std::endl;
            }
            else if (opcija==4) {
                pregledi.ObrisiNajranijiPregled();
                std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
            }
            else if (opcija==5) {
                int uneseni_dan(0), uneseni_mjesec(0), unesena_godina(0);
                std::cout << "Unesite dan mjesec i godinu : ";
                std::cin >> uneseni_dan >> uneseni_mjesec >> unesena_godina;
                std::cout << "Pregledi na datum " << uneseni_dan << " " 
                << uneseni_mjesec << " " << unesena_godina << " su:" << std::endl;
                pregledi.IspisiPregledeNaDatum(Datum(uneseni_dan, uneseni_mjesec, unesena_godina));
            }
            else if (opcija==6) {
                pregledi.IspisiSvePreglede();
            }
        }
        catch(std::domain_error domain_greska) {
            std::cout << domain_greska.what() << std::endl;
        }
        catch(std::range_error range_greska) {
            std::cout << range_greska.what() << std::endl;
        }
    }
	return 0;
}
