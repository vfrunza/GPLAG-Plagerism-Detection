/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <initializer_list>

int izbrisani_pregledi;

class Datum
{
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina) {
        int dani[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
            ++dani[1];
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
        if(dan < 0 || mjesec < 0 || godina < 0) throw std::domain_error("Neispravan datum");
        if(mjesec > 12 || dan > dani[mjesec - 1]) throw std::domain_error("Neispravan datum");
    }
    void Postavi(int dan, int mjesec, int godina) {
        int dani[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
            ++dani[1];
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
        if(dan < 0 || mjesec < 0 || godina < 0) throw std::domain_error("Neispravan datum");
        if(mjesec > 12 || dan > dani[mjesec - 1]) throw std::domain_error("Neispravan datum");
    }
    std::tuple<int, int, int> Ocitaj() const {
        auto t = std::make_tuple(dan, mjesec, godina);
        return t;
    }
    void Ispisi() const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
    friend class Pregled;
    friend class Pregledi;
};
class Vrijeme
{
    int sati, minute;
public:
    Vrijeme(int sati, int minute) {
        Vrijeme::sati = sati;
        Vrijeme::minute = minute;
        if(sati < 0 || minute < 0) throw std::domain_error("Neispravno vrijeme");
        if(sati > 60 || minute > 60) throw std::domain_error("Neispravno vrijeme");
    }
    void Postavi(int sati, int minute) {
        Vrijeme::sati = sati;
        Vrijeme::minute = minute;
        if(sati < 0 || minute < 0) throw std::domain_error("Neispravno vrijeme");
        if(sati > 60 || minute > 60) throw std::domain_error("Neispravno vrijeme");
    }
    std::pair<int, int> Ocitaj () const {
        auto p = std::make_pair(sati, minute);
        return p;
    }
    void Ispisi() const {
        if(sati < 10) std::cout<<"0"<<sati<<":";
        else std::cout<<sati<<":";
        if(minute < 10) std::cout<<"0"<<minute;
        else std::cout<<minute;
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
            const Vrijeme &vrijeme_pregleda): ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {}

    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
            int sati_pregleda, int minute_pregleda): ime_pacijenta(ime_pacijenta),datum_pregleda(dan_pregleda,
                        mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda)  {}

    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta = ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        std::tuple<int, int, int> novi_dat = novi_datum.Ocitaj();
        datum_pregleda.Postavi(std::get<0>(novi_dat), std::get<1>(novi_dat), std::get<2>(novi_dat));
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        std::pair<int, int> novo_vri = novo_vrijeme.Ocitaj();
        vrijeme_pregleda.Postavi(novo_vri.first, novo_vri.second);
    }
    void PomjeriDanUnaprijed() {
        int dani[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(datum_pregleda.godina % 4 == 0 && datum_pregleda.godina % 100 != 0 || datum_pregleda.godina % 400 == 0)
            ++dani[1];
        if(datum_pregleda.dan >= dani[datum_pregleda.mjesec - 1]) {
            datum_pregleda.dan = 1;
            if(datum_pregleda.mjesec == 1) {
                datum_pregleda.mjesec = 12;
                --datum_pregleda.godina;
            } else --datum_pregleda.mjesec;
        } else --datum_pregleda.dan;
    }
    void PomjeriDanUnazad() {
        int dani[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(datum_pregleda.godina % 4 == 0 && datum_pregleda.godina % 100 != 0 || datum_pregleda.godina % 400 == 0)
            ++dani[1];
        if(datum_pregleda.dan == 1) {
            datum_pregleda.dan = dani[datum_pregleda.mjesec - 1];
            if(datum_pregleda.mjesec == 12) {
                datum_pregleda.mjesec = 1;
                ++datum_pregleda.godina;
            } else ++datum_pregleda.mjesec;
        } else ++datum_pregleda.dan;
    }
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
            else if(p1.datum_pregleda.mjesec == p2.datum_pregleda.mjesec) return p1.datum_pregleda.dan < p2.datum_pregleda.dan;
        }
    }
    void Ispisi() const {
        std::cout<<std::left<<std::setw(30)<<ime_pacijenta;
        std::cout.fill(' ');
        datum_pregleda.Ispisi();
        std::cout<<" ";
        vrijeme_pregleda.Ispisi();
        std::cout<<std::endl;

    }
    friend class Pregledi;
};

class Pregledi
{
    int broj_pregleda;
    int max_broj_pregleda;
    Pregled **pok;

    void Sort() const {
        std::sort(pok, pok + broj_pregleda, [](const Pregled *p1, const Pregled *p2) {
            if(p1->datum_pregleda.godina > p2->datum_pregleda.godina) return false;
            else if(p1->datum_pregleda.godina == p2->datum_pregleda.godina) {
                if(p1->datum_pregleda.mjesec > p2->datum_pregleda.mjesec) return false;
                else if(p1->datum_pregleda.mjesec == p2->datum_pregleda.mjesec) {
                    if(p1->datum_pregleda.dan > p2->datum_pregleda.dan) return false;
                    else if(p1->datum_pregleda.dan == p2->datum_pregleda.dan) {
                        if(p1->vrijeme_pregleda.sati > p2->vrijeme_pregleda.sati) return false;
                        else if(p1->vrijeme_pregleda.sati == p2->vrijeme_pregleda.sati) {
                            if(p1->vrijeme_pregleda.minute > p2->vrijeme_pregleda.minute) return false;
                        }
                    }
                }
            }
            return true;
        });
    }
public:
    explicit Pregledi(int max_broj_pregleda) {
        Pregledi::max_broj_pregleda = max_broj_pregleda;
        try {
            pok = new Pregled*[max_broj_pregleda] {};
        } catch(std::bad_alloc) {
            delete[] pok;
        }
        broj_pregleda = 0;
    }
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi) = default;
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const ;
    void IspisiSvePreglede() const;
};


Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda)
{
    broj_pregleda = spisak_pregleda.size();
    max_broj_pregleda = spisak_pregleda.size();
    pok = new Pregled*[spisak_pregleda.size()];
    int i(0);
    for(auto it(spisak_pregleda.begin()); it != spisak_pregleda.end(); ++it) {
        pok[i] = new Pregled(*it);
        ++i;
    }
}
Pregledi::~Pregledi()
{
    for(int i(0); i<max_broj_pregleda; ++i) delete pok[i];
    delete[] pok;
}
Pregledi::Pregledi(const Pregledi &pregledi): max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda)
{
    pok = new Pregled*[max_broj_pregleda];
    for(int i(0); i<broj_pregleda; ++i) {
        pok[i] = new Pregled(*pregledi.pok[i]);
    }
}
Pregledi::Pregledi(Pregledi &&pregledi): max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda)
{
    std::swap(pok, pregledi.pok);
    pregledi.pok = nullptr;
}
Pregledi& Pregledi::operator =(const Pregledi &pregledi)
{

    for(int i(0); i<max_broj_pregleda; ++i) delete pok[i];
    delete[] pok;

    max_broj_pregleda = pregledi.max_broj_pregleda;
    broj_pregleda = pregledi.broj_pregleda;
    pok = new Pregled*[max_broj_pregleda];
    for(int i(0); i<max_broj_pregleda; ++i) new Pregled(*pregledi.pok[i]);
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    if(broj_pregleda >= max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    Pregled novi(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    pok[broj_pregleda++] = new Pregled(novi);
    Sort();
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    if(broj_pregleda >= max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    Pregled novi(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    pok[broj_pregleda++] = new Pregled(novi);
    Sort();
}
void Pregledi::RegistrirajPregled(Pregled *pregled)
{
    if(broj_pregleda >= max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    pok[broj_pregleda++] = new Pregled(*pregled);
    Sort();
}
int Pregledi::DajBrojPregleda() const
{
    return broj_pregleda;
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    return std::count_if(pok, pok+broj_pregleda, [datum](const Pregled *p1) -> bool {
        if(p1->datum_pregleda.godina == datum.godina && p1->datum_pregleda.mjesec == datum.mjesec && p1->datum_pregleda.dan == datum.dan) return true;
        return false;
    });
}
Pregled& Pregledi::DajNajranijiPregled()
{
    auto p = std::min_element(pok, pok+broj_pregleda, [](const Pregled *p1, const Pregled *p2) -> bool {
        if(p1->datum_pregleda.godina > p2->datum_pregleda.godina) return false;
        else if(p1->datum_pregleda.godina == p2->datum_pregleda.godina) {
            if(p1->datum_pregleda.mjesec > p2->datum_pregleda.mjesec) return false;
            else if(p1->datum_pregleda.mjesec == p2->datum_pregleda.mjesec) {
                if(p1->datum_pregleda.dan > p2->datum_pregleda.dan) return false;
                else if(p1->datum_pregleda.dan == p2->datum_pregleda.dan) {
                    if(p1->vrijeme_pregleda.sati > p2->vrijeme_pregleda.sati) return false;
                    else if(p1->vrijeme_pregleda.sati == p2->vrijeme_pregleda.sati) {
                        if(p1->vrijeme_pregleda.minute > p2->vrijeme_pregleda.minute) return false;
                    }
                }
            }
        }
        return true;
    });
    return **p;
}
Pregled Pregledi::DajNajranijiPregled() const
{
    auto p = std::min_element(pok, pok+broj_pregleda, [](const Pregled *p1, const Pregled *p2) -> bool {
        if(p1->datum_pregleda.godina > p2->datum_pregleda.godina) return false;
        else if(p1->datum_pregleda.godina == p2->datum_pregleda.godina) {
            if(p1->datum_pregleda.mjesec > p2->datum_pregleda.mjesec) return false;
            else if(p1->datum_pregleda.mjesec == p2->datum_pregleda.mjesec) {
                if(p1->datum_pregleda.dan > p2->datum_pregleda.dan) return false;
                else if(p1->datum_pregleda.dan == p2->datum_pregleda.dan) {
                    if(p1->vrijeme_pregleda.sati > p2->vrijeme_pregleda.sati) return false;
                    else if(p1->vrijeme_pregleda.sati == p2->vrijeme_pregleda.sati) {
                        if(p1->vrijeme_pregleda.minute > p2->vrijeme_pregleda.minute) return false;
                    }
                }
            }
        }
        return true;
    });
    return **p;
}
void Pregledi::IsprazniKolekciju()
{
    for(int i(0); i<broj_pregleda; ++i)
        delete pok[i];
    broj_pregleda = 0;
}
void Pregledi::ObrisiNajranijiPregled()
{
    if(broj_pregleda == 0) throw std::range_error("Prazna kolekcija");
    //delete pok[0];
    for(int i(0); i<broj_pregleda - 1; ++i) {
        std::swap(pok[i], pok[i+1]);
    }
    --broj_pregleda;
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    izbrisani_pregledi = broj_pregleda;
    for(int i(0); i<broj_pregleda; ++i) {
        if(pok[i]->ime_pacijenta == ime_pacijenta) {
            //delete pok[i];
            for(int x(i); x < broj_pregleda - 1; ++x) std::swap(pok[x], pok[x + 1]);
            --broj_pregleda;
        }
    }
    izbrisani_pregledi -= broj_pregleda;
}
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    std::vector<Pregled*> p;
    for(int i(0); i<broj_pregleda; ++i) {
        if(pok[i]->datum_pregleda.dan == datum.dan && pok[i]->datum_pregleda.mjesec == datum.mjesec && pok[i]->datum_pregleda.godina == datum.godina) {
            p.emplace_back(pok[i]);
        }
    }
    std::sort(p.begin(), p.end(), [](Pregled *p1, Pregled *p2) -> bool {
        if(p1->vrijeme_pregleda.sati < p2->vrijeme_pregleda.sati) return true;
        else return p1->vrijeme_pregleda.minute < p2->vrijeme_pregleda.minute;
    });
    for(int i(0); i<p.size(); ++i) {
        p[i]->Ispisi();
    }
}
void Pregledi::IspisiSvePreglede() const
{
    for(int i(0); i<broj_pregleda; ++i) pok[i]->Ispisi();
}


int main ()
{
    try {
        std::cout<<"Unesite maksimalan broj pregleda: ";
        int max_br;
        std::cin>>max_br;

        Pregledi pregledi(max_br);
        std::string unos;
        for(int i(0); i<max_br; ++i) {
            std::cin.ignore(10000, '\n');
            std::cin.clear();
            std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            getline(std::cin, unos);
            if(unos == "kraj") break;
            int d, m, g, h, min;
            std::cout<<"Unesite dan mjesec i godinu pregleda: ";
            std::cin>>d>>m>>g;
            std::cout<<"Unesite sate i minute pregleda: ";
            std::cin>>h>>min;
            pregledi.RegistrirajPregled(unos, d, m, g, h, min);
        }
        std::cout<<"Trenutno su registrovani sljedeci pregledi\n";
        pregledi.IspisiSvePreglede();

        int odabir(7);
        for(;;) {
            std::cout<<"\nOdaberite jednu od sljedecih opcija\n"
                     <<"1 - Broj pregleda na datum\n"
                     <<"2 - Najraniji pregled\n"
                     <<"3 - Obrisi pregled pacijenta\n"
                     <<"4 - Obrisi najraniji pregled\n"
                     <<"5 - Ispisi sve pregleda na datum\n"
                     <<"6 - Ispisi sve preglede\n"
                     <<"7 - Kraj programa\n";

            std::cin>>odabir;
            if(odabir == 1) {
                std::cout<<"Unesite dan mjesec i godinu : ";
                int d,m,g;
                std::cin>>d>>m>>g;
                Datum datum(d, m, g);
                std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<pregledi.DajBrojPregledaNaDatum(datum)<<std::endl;
            }
            if(odabir == 2) {
                std::cout<<"Najraniji pregled je:\n";
                pregledi.DajNajranijiPregled().Ispisi();
            }
            if(odabir == 3) {
                std::cout<<"Unesite ime pacijenta: ";
                std::string ime;
                std::cin.ignore(10000, '\n');
                std::cin.clear();
                getline(std::cin, ime);
                pregledi.ObrisiPregledePacijenta(ime);
                std::cout<<"Uspjesno obrisano "<<izbrisani_pregledi<<" pregleda\n";
            }
            if(odabir == 4) {
                pregledi.ObrisiNajranijiPregled();
                std::cout<<"Najraniji pregled uspjesno obrisan\n";
            }
            if(odabir == 5) {
                std::cout<<"Unesite dan mjesec i godinu : ";
                int d,m,g;
                std::cin>>d>>m>>g;
                Datum datum(d, m, g);
                std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su:\n";
                pregledi.IspisiPregledeNaDatum(datum);
                std::cout<<std::endl;
            }
            if(odabir == 6) pregledi.IspisiSvePreglede();
            if(odabir == 7) break;
        }
    } catch(std::bad_alloc e) {
        std::cout<<e.what();
    } catch(std::domain_error e) {
        std::cout<<e.what();
    } catch(std::range_error e) {
        std::cout<<e.what();
    } catch(std::logic_error e) {
        std::cout<<e.what();
    }

    return 0;
}