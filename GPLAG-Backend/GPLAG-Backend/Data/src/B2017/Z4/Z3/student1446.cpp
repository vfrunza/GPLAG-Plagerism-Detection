/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <utility>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <new>
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
    int max_broj_pregleda;
    int broj_pregleda;
    Pregled** p_pregledi;
public:
    explicit Pregledi(int max_broj_pregleda) : 
     max_broj_pregleda(max_broj_pregleda), broj_pregleda(0), 
     p_pregledi(new Pregled*[max_broj_pregleda]{}) {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, 
     const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, 
     int mjesec_pregleda, int godina_pregleda, int sati_pregleda, 
     int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const {
        return broj_pregleda;
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
    for (int i=0; i<broj_pregleda; i++) {
        delete p_pregledi[i];
        p_pregledi[i]=nullptr;
    }
    broj_pregleda=0;
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : 
max_broj_pregleda(spisak_pregleda.size()), broj_pregleda(spisak_pregleda.size()), 
p_pregledi(new Pregled*[spisak_pregleda.size()]{}) {
    std::initializer_list<Pregled>::iterator iter=spisak_pregleda.begin();
    try {
        for (int i=0; i<spisak_pregleda.size(); i++) {
            p_pregledi[i]=new Pregled(*iter);
            iter++;
        }
    }
    catch (...) {
        for (int i=0; i<spisak_pregleda.size(); i++) delete p_pregledi[i];
        delete[] p_pregledi;
        throw;
    }
}

Pregledi::~Pregledi() {
    for (int i=0; i<broj_pregleda; i++) delete p_pregledi[i];
    delete[] p_pregledi;
}

Pregledi::Pregledi(const Pregledi &pregledi) : 
max_broj_pregleda(pregledi.max_broj_pregleda), 
broj_pregleda(pregledi.broj_pregleda), 
p_pregledi(new Pregled*[pregledi.max_broj_pregleda]{}) {
    try {
        for (int i=0; i<pregledi.broj_pregleda; i++) {
            p_pregledi[i]=new Pregled(*pregledi.p_pregledi[i]);
        }
    }
    catch(...) {
        for (int i=0; i<pregledi.broj_pregleda; i++) delete p_pregledi[i];
        delete[] p_pregledi;
        throw;
    }
}

Pregled &Pregledi::DajNajranijiPregled() {
    if (broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(p_pregledi, p_pregledi+broj_pregleda, [](Pregled* prvi, Pregled* drugi) {
        return Pregled::DolaziPrije(*prvi, *drugi);
    });
}

Pregled Pregledi::DajNajranijiPregled() const {
    if (broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(p_pregledi, p_pregledi+broj_pregleda, [](Pregled* prvi, Pregled* drugi) {
        return Pregled::DolaziPrije(*prvi, *drugi);
    });
}

Pregledi::Pregledi(Pregledi &&pregledi) : 
max_broj_pregleda(pregledi.max_broj_pregleda), 
broj_pregleda(pregledi.broj_pregleda), 
p_pregledi(pregledi.p_pregledi) {
    pregledi.broj_pregleda=0;
    pregledi.p_pregledi=nullptr;
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi) {
    if (&pregledi!=this) {
        for (int i=0; i<broj_pregleda; i++) {
            delete p_pregledi[i];
            p_pregledi[i]=nullptr;
        }
        delete[] p_pregledi;
        p_pregledi=nullptr;
        max_broj_pregleda=pregledi.max_broj_pregleda;
        broj_pregleda=pregledi.broj_pregleda;
        p_pregledi=new Pregled*[max_broj_pregleda]{};
        for (int i=0; i<broj_pregleda; i++) p_pregledi[i]=new Pregled(*pregledi.p_pregledi[i]);
    }
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi) {
    std::swap(max_broj_pregleda, pregledi.max_broj_pregleda);
    std::swap(broj_pregleda, pregledi.broj_pregleda);
    std::swap(p_pregledi, pregledi.p_pregledi);
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, 
const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    if (broj_pregleda>=max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    p_pregledi[broj_pregleda++]=new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, 
int dan_pregleda, int mjesec_pregleda, int godina_pregleda, 
int sati_pregleda, int minute_pregleda) {
    if (broj_pregleda>=max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    p_pregledi[broj_pregleda++]=new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, 
     sati_pregleda, minute_pregleda);
}

void Pregledi::RegistrirajPregled(Pregled *pregled) {
    if (broj_pregleda>=max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    p_pregledi[broj_pregleda++]=pregled;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    return std::count_if(p_pregledi, p_pregledi+broj_pregleda, [datum](Pregled* pregled) {
        return (pregled->DajDatumPregleda()).Ocitaj()==datum.Ocitaj();
    });
}

void Pregledi::ObrisiNajranijiPregled() {
    if (broj_pregleda==0) throw std::range_error("Prazna kolekcija");
    std::tuple<int, int, int> datum_najranijeg((DajNajranijiPregled().DajDatumPregleda()).Ocitaj());
    std::pair<int, int> vrijeme_najranijeg((DajNajranijiPregled().DajVrijemePregleda()).Ocitaj());
    for (int i=0; i<broj_pregleda; i++) {
        if ((p_pregledi[i]->DajDatumPregleda()).Ocitaj()==datum_najranijeg && 
        (p_pregledi[i]->DajVrijemePregleda()).Ocitaj()==vrijeme_najranijeg) {
            delete p_pregledi[i];
            for (int j=i; j<broj_pregleda-1; j++) p_pregledi[j]=p_pregledi[j+1];
            p_pregledi[broj_pregleda-1]=nullptr;
            broj_pregleda--;
            break;
        }
    }
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    for (int i=0; i<broj_pregleda; i++) {
        if (p_pregledi[i]->DajImePacijenta()==ime_pacijenta) {
            delete p_pregledi[i];
            for (int j=i; j<broj_pregleda-1; j++) p_pregledi[j]=p_pregledi[j+1];
            p_pregledi[broj_pregleda-1]=nullptr;
            broj_pregleda--;
            i--;
        }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
    int broj_na_datum(DajBrojPregledaNaDatum(datum));
    Pregled** niz_pokazivaca(new Pregled*[broj_na_datum]{});
    int brojac(0);
    for (int i=0; i<broj_pregleda; i++) {
        if (p_pregledi[i]->DajDatumPregleda().Ocitaj()==datum.Ocitaj()) {
            niz_pokazivaca[brojac++]=p_pregledi[i];
        }
    }
    std::sort(niz_pokazivaca, niz_pokazivaca+brojac, [](Pregled* prvi, Pregled* drugi) {
        return Pregled::DolaziPrije(*prvi, *drugi);
    });
    for (int i=0; i<brojac; i++) {
        niz_pokazivaca[i]->Ispisi();
        niz_pokazivaca[i]=nullptr;
    }
    delete[] niz_pokazivaca;
    niz_pokazivaca=nullptr;
}

void Pregledi::IspisiSvePreglede() const {
    Pregled** niz_pokazivaca(new Pregled*[broj_pregleda]{});
    int brojac(0);
    for (int i=0; i<broj_pregleda; i++) niz_pokazivaca[brojac++]=p_pregledi[i];
    std::sort(niz_pokazivaca, niz_pokazivaca+brojac, [](Pregled* prvi, Pregled* drugi) {
        return Pregled::DolaziPrije(*prvi, *drugi);
    });
    for (int i=0; i<brojac; i++) {
        niz_pokazivaca[i]->Ispisi();
        niz_pokazivaca[i]=nullptr;
    }
    delete[] niz_pokazivaca;
    niz_pokazivaca=nullptr;
}


int main ()
{
    int max_broj_pregleda(0);
    std::cout << "Unesite maksimalan broj pregleda: ";
    std::cin >> max_broj_pregleda;
    Pregledi pregledi(max_broj_pregleda);
    for (int i=0; i<max_broj_pregleda; i++) {
        try {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
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
            pregledi.RegistrirajPregled(ime_pacijenta, dan, mjesec, godina, sati, minute);
        }
        catch(std::domain_error domain_greska) {
            std::cout << domain_greska.what() << std::endl;
            i--;
        }
        catch(std::range_error range_greska) {
            std::cout << range_greska.what() << std::endl;
            i--;
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
