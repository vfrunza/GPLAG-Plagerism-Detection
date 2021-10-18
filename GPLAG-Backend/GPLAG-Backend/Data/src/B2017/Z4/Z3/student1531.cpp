/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <utility>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>


class Datum
{
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const {
        std::tuple<int, int, int> t {dan, mjesec, godina};
        return t;
    }
    void Ispisi() const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
    friend class Pregled;
    friend class Pregledi;
};
Datum::Datum(int dan, int mjesec, int godina)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0) && (godina % 100 != 0 || godina % 400 == 0)) broj_dana[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1]) {
        throw std::domain_error("Neispravan datum!");
    }
    this->dan = dan;
    this->mjesec = mjesec;
    this->godina = godina;
}
void Datum::Postavi(int dan, int mjesec, int godina)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0) && (godina % 100 != 0 || godina % 400 == 0)) broj_dana[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1]) {
        throw std::domain_error("Neispravan datum!");
    }
    this->dan = dan;
    this->mjesec = mjesec;
    this->godina = godina;
}


class Vrijeme
{
    int sati, minute;
public:
    Vrijeme(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        this->sati = sati;
        this->minute = minute;
    }
    void Postavi(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        this->sati = sati;
        this->minute = minute;
    }
    std::pair<int, int> Ocitaj () const {
        std::pair<int, int> p;
        p.first = sati;
        p.second = minute;
        return p;
    }
    void Ispisi() const {
        std::cout<<std::right<<std::setfill('0')<<std::setw(2)<<sati<<":"<<std::setfill('0')<<std::setw(2)<<minute;
        std::cout<<std::setfill(' ');
    }
    friend class Pregled;
    friend class Pregledi;
};


class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;

public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
            const Vrijeme &vrijeme_pregleda) : ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {};
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
            int minute_pregleda) : ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda),
        vrijeme_pregleda(sati_pregleda, minute_pregleda) {};
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        this->ime_pacijenta = ime_pacijenta;
    };
    void PromijeniDatum(const Datum &novi_datum) {
        this->datum_pregleda = novi_datum;
    };
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        this->vrijeme_pregleda = novo_vrijeme;
    };
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
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        if(p1.datum_pregleda.godina < p2.datum_pregleda.godina) return true;
        else if(p1.datum_pregleda.godina == p2.datum_pregleda.godina) {
            if(p1.datum_pregleda.mjesec < p2.datum_pregleda.mjesec) return true;
            else if(p1.datum_pregleda.mjesec == p2.datum_pregleda.mjesec) {
                if(p1.datum_pregleda.dan < p2.datum_pregleda.dan) return true;
                else if(p1.datum_pregleda.dan == p2.datum_pregleda.dan) {
                    if(p1.vrijeme_pregleda.sati < p2.vrijeme_pregleda.sati) return true;
                    else if(p1.vrijeme_pregleda.sati == p2.vrijeme_pregleda.sati) {
                        if(p1.vrijeme_pregleda.minute < p2.vrijeme_pregleda.minute) return true;
                    } else return false;
                } else return false;
            } else return false;
        } else return false;
        return false;
    }
    void Ispisi() const;
    friend class Pregledi;
};


void Pregled::PomjeriDanUnaprijed()
{
    datum_pregleda.dan++;
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((datum_pregleda.godina % 4 == 0) && (datum_pregleda.godina % 100 != 0 || datum_pregleda.godina % 400 == 0)) broj_dana[1]++;
    if(datum_pregleda.dan > broj_dana[datum_pregleda.mjesec - 1]) {
        datum_pregleda.dan = 1;
        datum_pregleda.mjesec++;
        if(datum_pregleda.mjesec > 12) {
            datum_pregleda.mjesec = 1;
            datum_pregleda.godina++;
        }
    }
}
void Pregled::PomjeriDanUnazad()
{
    datum_pregleda.dan--;
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((datum_pregleda.godina % 4 == 0) && (datum_pregleda.godina % 100 != 0 || datum_pregleda.godina % 400 == 0)) broj_dana[1]++;
    if(datum_pregleda.dan < 0) {
        int prethodni_mjesec(datum_pregleda.mjesec-1);
        if(prethodni_mjesec<=0) {
            prethodni_mjesec = 12;
            datum_pregleda.godina--;
        }
        datum_pregleda.dan = broj_dana[prethodni_mjesec-1];
        datum_pregleda.mjesec--;
    }
}


void Pregled::Ispisi() const
{
    std::cout<<std::left<<std::setw(30)<<ime_pacijenta;
    datum_pregleda.Ispisi();
    std::cout<<" ";
    vrijeme_pregleda.Ispisi();
    std::cout<<std::endl;
}

class Pregledi
{
    const int max_broj_pregleda;
    int broj_pregleda;
    Pregled **p;

public:
    explicit Pregledi(int max_broj_pregleda) : max_broj_pregleda(max_broj_pregleda), broj_pregleda(0), p(new Pregled*[max_broj_pregleda] {}) {}
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

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : max_broj_pregleda(spisak_pregleda.size()), broj_pregleda(spisak_pregleda.size()),
        p(new Pregled*[spisak_pregleda.size()] {})
{
    try {
        auto it(spisak_pregleda.begin());
        for(int i=0; i<broj_pregleda && it!=spisak_pregleda.end(); i++) {
            p[i] = new Pregled(*it);
            it++;
        }
    } catch(...) {
        for(int i=0; i<broj_pregleda; i++) delete p[i];
        delete[] p;
        broj_pregleda = 0;
        throw;
    }
}

Pregledi::~Pregledi()
{
    for(int i=0; i<broj_pregleda; i++) delete p[i];
    delete[] p;
}
Pregledi::Pregledi(const Pregledi &pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda), 
        p(new Pregled*[pregledi.max_broj_pregleda] {})
{
    try {
        for(int i=0; i<broj_pregleda; i++) {
            p[i] = new Pregled(*pregledi.p[i]);
        }
    } catch(...) {
        for(int i=0; i<broj_pregleda; i++) delete p[i];
        delete[] p;
        broj_pregleda = 0;
        throw;
    }
}
Pregledi::Pregledi(Pregledi &&pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda), p(pregledi.p)
{
    pregledi.p = nullptr;
    pregledi.broj_pregleda = 0;
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi)
{
    if(max_broj_pregleda != pregledi.max_broj_pregleda) throw std::logic_error("Nesagalsni kapaciteti pregleda");
    if(broj_pregleda < pregledi.broj_pregleda) {
        try {
            for(int i=broj_pregleda; i<pregledi.broj_pregleda; i++) {
                p[i] = new Pregled(*pregledi.p[i]);
            }
        } catch(...) {
            for(int i=broj_pregleda; i<pregledi.broj_pregleda; i++)  {
                delete p[i];
                p[i] = nullptr;
            }
            throw;
        }
    } else {
        for(int i=pregledi.broj_pregleda; i<broj_pregleda; i++) {
            delete p[i];
            p[i] = nullptr;
        }
    }
    broj_pregleda = pregledi.broj_pregleda;
    for(int i=0; i<broj_pregleda; i++) *p[i] = *pregledi.p[i];
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi)
{
    if(max_broj_pregleda != pregledi.max_broj_pregleda) throw std::logic_error("Nesagalsni kapaciteti pregleda");
    std::swap(broj_pregleda, pregledi.broj_pregleda);
    std::swap(p, pregledi.p);
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    Pregled *novi(nullptr);
    try {
        novi = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
        p[broj_pregleda] = novi;
        novi = nullptr;
        broj_pregleda++;
    } catch(...) {
        delete novi;
        throw;
    }
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
                                  int sati_pregleda, int minute_pregleda)
{
    if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    Pregled *novi(nullptr);
    try {
        novi = new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
        p[broj_pregleda] = novi;
        novi =nullptr;
        broj_pregleda++;
    } catch(...) {
        delete novi;
        throw;
    }
}
void Pregledi::RegistrirajPregled(Pregled *pregled)
{
    if(broj_pregleda==max_broj_pregleda) {
        delete p;
        throw std::range_error("Dostignut maksimalni broj pregleda");
    }
    Pregled *novi(nullptr);
    try {
        novi = new Pregled(*pregled);
        p[broj_pregleda] = novi;
        broj_pregleda++;
    } catch(...) {
        delete novi;
        throw;
    }
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    int brojac(0);
    brojac = std::count_if(p, p+broj_pregleda, [datum](const Pregled *p1) {
        if(p1->datum_pregleda.godina != datum.godina) return false;
        if(p1->datum_pregleda.mjesec != datum.mjesec) return false;
        if(p1->datum_pregleda.dan != datum.dan) return false;
        return true;
    });
    return brojac;
}

Pregled &Pregledi::DajNajranijiPregled()
{
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    auto it (std::min_element(p, p+broj_pregleda, [](const Pregled *p1, const Pregled *p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    }) );
    return **it;
}
Pregled Pregledi::DajNajranijiPregled() const
{
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    auto it (std::min_element(p, p+broj_pregleda, [](const Pregled *p1, const Pregled *p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    }) );
    return **it;
}

void Pregledi::IsprazniKolekciju()
{
    for(int i=0; i<broj_pregleda; i++) {
        delete p[i];
        p[i] = nullptr;
    }
    broj_pregleda = 0;
}

void Pregledi::ObrisiNajranijiPregled()
{
    if(broj_pregleda==0) throw std::range_error("Prazna kolekcija");
    Pregled *pok(&(this->DajNajranijiPregled()));

    for(int i=0; i<broj_pregleda; i++) {
        if(p[i] == pok) {
            delete p[i];
            for(int j=i; j<broj_pregleda-1; j++) {
                p[j] = p[j+1];
            }
            p[broj_pregleda-1] = nullptr;
            broj_pregleda--;
            break;
        }
    }
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    for(int i=0; i<broj_pregleda; i++) {
        if(p[i]->DajImePacijenta() == ime_pacijenta) {
            delete p[i];
            for(int j=i; j<broj_pregleda-1; j++) {
                p[j] = p[j+1];
            }
            p[broj_pregleda-1] = nullptr;
            i--;
            broj_pregleda--;
        }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    
    std::vector<bool> ispisani(broj_pregleda, false);
    bool temp(true);
    int min(0);
    for(int i=0; i<broj_pregleda && !ispisani.at(i); i++) {
        min = i;
        temp = true;
        for(int j=0; j<broj_pregleda && !ispisani.at(j); j++) {
            if(j!=i) {
                if(!Pregled::DolaziPrije(*p[i], *p[j])) {
                    temp = false;
                    if(Pregled::DolaziPrije(*p[j], *p[min])) min =j;
                }
            }
        }
        if(temp && !ispisani.at(i)) {
            if(p[i]->datum_pregleda.godina == datum.godina) {
                if(p[i]->datum_pregleda.mjesec == datum.mjesec) {
                    if(p[i]->datum_pregleda.dan == datum.dan) {
                        p[i]->Ispisi();
                    }
                }
            }
            ispisani.at(i) = true;
        } else if(!temp) {
            if(p[min]->datum_pregleda.godina == datum.godina) {
                if(p[min]->datum_pregleda.mjesec == datum.mjesec) {
                    if(p[min]->datum_pregleda.dan == datum.dan) {
                        p[min]->Ispisi();
                    }
                }
            }
            ispisani.at(i) = true;
        }
    }
    
}

void Pregledi::IspisiSvePreglede() const
{
    std::vector<bool> ispisani(broj_pregleda, false);
    bool temp(true);
    int min(0);
    for(int i=0; i<broj_pregleda && !ispisani.at(i); i++) {
        min = i;
        temp = true;
        for(int j=0; j<broj_pregleda && !ispisani.at(j); j++) {
            if(j!=i) {
                if(!Pregled::DolaziPrije(*p[i], *p[j])) {
                    temp = false;
                    if(Pregled::DolaziPrije(*p[j], *p[min])) min =j;
                }
            }
        }
        if(temp && !ispisani.at(i)) {
            p[i]->Ispisi();
            ispisani.at(i) = true;
        } else if(!temp) {
            p[min]->Ispisi();
            ispisani.at(min) = true;
        }
    }
}

int main ()
{ 
    try {
        std::cout<<"Unesite maksimalan broj pregleda: ";
        int max;
        for(;;) {
            std::cin>>max;
            if(std::cin && max>0) break;
            else {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout<<"Neispravan broj pregleda, unesite ponovo!\n";
            }
        }
        Pregledi pregledi(max);
        std::cin.ignore(10000, '\n');
        for(int i=0; i<max; i++) {
            std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::string ime;
            std::getline(std::cin, ime);
            if(std::cin && ime!=std::string("kraj")) {
                std::cout<<"Unesite dan mjesec i godinu pregleda: ";
                int dan, mjesec, godina;
                std::cin>>dan>>mjesec>>godina;
                if(std::cin) {
                    std::cout<<"Unesite sate i minute pregleda: ";
                    int h,m;
                    std::cin>>h>>m;
                    if(std::cin) {
                        Pregled *p(nullptr);
                        try {
                            p = new Pregled(ime, dan, mjesec, godina, h, m);
                        } catch(std::domain_error izuzetak) {
                            delete p;
                            p = nullptr;
                            std::cout<<izuzetak.what()<<std::endl;
                            i--;
                        } catch(...) {
                            delete p;
                            p = nullptr;
                            throw;
                        }
                        pregledi.RegistrirajPregled(p);
                    } else {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout<<"Neispravno vrijeme!"<<std::endl;
                    }
                } else {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout<<"Neispravan datum!"<<std::endl;
                    i--;
                }

            } else if(ime==std::string("kraj")) break;
            else {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout<<"Neispravni podaci"<<std::endl;
                i--;
            }
            std::cin.ignore(10000, '\n');
        }
        std::cout<<"Trenutno su registrovani sljedeci pregledi:\n";
        //std::cout<<" "<<pregledi.DajBrojPregleda();
        pregledi.IspisiSvePreglede();
        bool kraj(false);
        while(!kraj) {
            std::cout<<"\nOdaberite jednu od sljedecih opcija\n";
            std::cout<<"1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n4 - Obrisi najraniji pregled"<<std::endl;
            std::cout<<"5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa"<<std::endl;
            int opcija;
            std::cin>>opcija;
            switch(opcija) {
            case 1: {
                std::cout<<"Unesite dan mjesec i godinu : ";
                int d, m, g;
                std::cin>>d>>m>>g;
                if(std::cin) {
                    int broj(pregledi.DajBrojPregledaNaDatum(Datum(d, m, g)));
                    std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<broj<<std::endl;
                } else {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout<<"Neispravan datum!"<<std::endl;
                }
            }
            break;
            case 2: {
                std::cout<<"Najraniji pregled je:\n";
                Pregled x(pregledi.DajNajranijiPregled());
                x.Ispisi();
            }
            break;
            case 3: {
                std::cin.ignore(10000, '\n');
                std::cout<<"Unesite ime pacijenta: ";
                std::string ime;
                std::getline(std::cin, ime);
                int prije(pregledi.DajBrojPregleda());
                pregledi.ObrisiPregledePacijenta(ime);
                int poslije(pregledi.DajBrojPregleda());
                int obrisano(prije-poslije);
                std::cout<<"Uspjesno obrisano "<<obrisano<<" pregleda"<<std::endl;
            }
            break;
            case 4: {
                pregledi.ObrisiNajranijiPregled();
                std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
            }
            break;
            case 5: {
                std::cout<<"Unesite dan mjesec i godinu : ";
                int d, m, g;
                std::cin>>d>>m>>g;
                if(std::cin) {
                    std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su:"<<std::endl;
                    pregledi.IspisiPregledeNaDatum(Datum(d, m, g));
                } else {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout<<"Neispravan datum!"<<std::endl;
                }
            }
            break;
            case 6: {
                pregledi.IspisiSvePreglede();
            }
            break;
            case 7: {
                kraj = true;
            }
            break;
            default: {
                kraj = true;
            }
            }
        }
    } catch(...) {
        std::cout<<"Doslo je do greske!"<<std::endl;
    }
    
    return 0;
}
