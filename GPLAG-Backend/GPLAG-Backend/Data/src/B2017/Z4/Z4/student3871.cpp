/B2017/2018: Zadaća 4, Zadatak 4
/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <memory>
#include <stdexcept>
#include <map>
#include <algorithm>
#include <tuple>
#include <iomanip>

int broj_izbrisanih_pregleda;

class Datum
{
    int dan, mjesec, godina;

public:
    Datum (int dan, int mjesec, int godina);
    void Postavi(int dan ,int mjesec, int godina);
    std::tuple<int, int,int> Ocitaj() const ;
    void Ispisi() const;
    
    friend class Pregled;
    friend class Pregledi;
};
    Datum::Datum (int dan, int mjesec, int godina) {
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Datum::Postavi(int dan, int mjesec, int godina) {
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
        if (dan < 0 || mjesec < 0 || godina < 0 || mjesec > 12) throw std::domain_error("Neispravan datum");
        if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) {
            if (mjesec == 2) {
                if (dan > 29) throw std::domain_error ("Neispravan datum");
            }
        }
        if (mjesec % 2 != 0) {
            if (dan > 31) throw std::domain_error ("Neispravan datum");
        } else {
            if (mjesec == 2) {
                if (dan > 28) throw std::domain_error ("Neispravan datum");
            } else if(mjesec == 3)  {
                if (dan > 31) throw std::domain_error ("Neispravan datum");
            } else {
                if (dan > 30) throw std::domain_error ("Neispravan datum");
            }
        }

    }
    std::tuple<int, int, int> Datum::Ocitaj() const {
        std::tuple<int, int, int> datum;
        datum = std::make_tuple(Datum::dan, Datum::mjesec, Datum::godina);
        return datum;
    }

    void Datum::Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }


class Vrijeme
{
    int sati, minute;

public:
    
    Vrijeme (int sati, int minute);
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj() const;
    void Ispisi() const;
        
    friend class Pregled;
    friend class Pregledi;

};
    Vrijeme::Vrijeme (int sati, int minute) {
        if (sati < 0 || sati > 23) throw std::domain_error ("Neispravno vrijeme");
        if (minute < 0 || minute > 59) throw std::domain_error ("Neispravno vrijeme");
        Vrijeme::sati = sati;
        Vrijeme::minute = minute;
    }

    void Vrijeme::Postavi (int sati, int minute) {
        if (sati < 0 || sati > 23) throw std::domain_error ("Neispravno vrijeme");
        if (minute < 0 || minute > 59) throw std::domain_error ("Neispravno vrijeme");
        Vrijeme::sati = sati;
        Vrijeme::minute = minute;
    }

    std::pair<int, int> Vrijeme::Ocitaj() const {
        std::pair<int, int> vrijeme;
        vrijeme = std::make_pair(sati, minute);
        return vrijeme;
    }

    void Vrijeme::Ispisi() const {
        std::cout.fill('0');
        std::cout <<std::setw(2)<<std::right<<std::fixed <<sati << ":" <<std::setw(2)<<std::right<<std::fixed << minute;
        std::cout.fill(' ');
    }
   

class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;

public:

    Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta(const std::string &ime_pacijenta);
    void PromijeniDatum(const Datum &novi_datum);
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const;
    Datum DajDatumPacijenta() const;
    Vrijeme DajVrijemePacijenta() const;
    static bool DolaziPrije (const Pregled &p1, const Pregled &p2) {
        if (p1.datum_pregleda.godina < p2.datum_pregleda.godina || p1.datum_pregleda.mjesec < p2.datum_pregleda.mjesec || p1.datum_pregleda.dan < p2.datum_pregleda.dan) return true;
        if (p1.vrijeme_pregleda.sati < p2.vrijeme_pregleda.sati || p1.vrijeme_pregleda.minute < p2.vrijeme_pregleda.minute) return true;
        return false;
    }
    void Ispisi() const;

friend class Datum;
    friend class Vrijeme;
    friend class Pregledi;

};
    Pregled::Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):ime_pacijenta(ime_pacijenta),datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {}
    Pregled::Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda) {}
    void Pregled::PromijeniPacijenta (const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void Pregled::PromijeniDatum (const Datum &novi_datum) {
        Pregled::datum_pregleda = novi_datum;
    }
    void Pregled::PromijeniVrijeme (const Vrijeme &novo_vrijeme) {
        Pregled::vrijeme_pregleda = novo_vrijeme;
    }
    void Pregled::PomjeriDanUnaprijed() {
        int dani[12] {31,28,31,30,31,30,31,31,30,31,30,31};
        if ((datum_pregleda.godina % 4 == 0 && datum_pregleda.godina % 100 != 0) || datum_pregleda.godina % 400 == 0) ++dani[1];
        ++datum_pregleda.dan;
        if (datum_pregleda.dan > dani[datum_pregleda.mjesec-1]) {
            datum_pregleda.dan = 1;
            ++datum_pregleda.mjesec;
        }
        if (datum_pregleda.mjesec > 12) {
            ++datum_pregleda.godina;
            datum_pregleda.mjesec = 1;
        }
    }
    void Pregled::PomjeriDanUnazad() {
        int dani[12] {31,28,31,30,31,30,31,31,30,31,30,31};
        if ((datum_pregleda.godina % 4 == 0 && datum_pregleda.godina % 100 != 0) || datum_pregleda.godina % 400 == 0) ++dani[1];
        --datum_pregleda.dan;
        if(datum_pregleda.dan < 1) {
            --datum_pregleda.mjesec;
            datum_pregleda.dan = dani[datum_pregleda.mjesec-1];
        }
        if (datum_pregleda.mjesec < 1) {
            --datum_pregleda.godina;
            datum_pregleda.mjesec = 12;
        }
    }

    std::string Pregled::DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum Pregled::DajDatumPacijenta() const {
        return datum_pregleda;
    }
    Vrijeme Pregled::DajVrijemePacijenta() const {
        return vrijeme_pregleda;
    }

    

    void Pregled::Ispisi() const {
        std::cout << std::setw(30) << std::left << ime_pacijenta;
        std::cout.fill(' ');
        datum_pregleda.Ispisi();
        std::cout << " ";
        vrijeme_pregleda.Ispisi();
        std::cout << std::endl;
    }
    

class Pregledi
{
    /*int max_broj_pregleda;
    int broj_pregleda;
    Pregled **niz;*/
    
    std::vector<std::shared_ptr<Pregled>> niz; 

    void FunkcijaSortiranja () {
        std::sort(niz.begin(), niz.end(), [] (std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {

            if(p1->datum_pregleda.godina < p2->datum_pregleda.godina) return true;
            else if(p1->datum_pregleda.godina == p2->datum_pregleda.godina) {
                if(p1->datum_pregleda.mjesec < p2->datum_pregleda.mjesec) return true;
                else if (p1->datum_pregleda.mjesec == p2->datum_pregleda.mjesec) {
                    if (p1->datum_pregleda.dan < p2->datum_pregleda.dan) return true;
                    else if (p1->datum_pregleda.dan == p2->datum_pregleda.dan) {
                        if (p1->vrijeme_pregleda.sati < p2->vrijeme_pregleda.sati) return true;
                        else if (p1->vrijeme_pregleda.sati == p2->vrijeme_pregleda.sati) {
                            if (p1->vrijeme_pregleda.minute < p2->vrijeme_pregleda.minute) return true;
                        }
                    }

                }
            }
            return false;

        });
    }

public:

    explicit Pregledi() = default;
    /*{
        //niz = std::make_shared<Pregled>;
    }*/

    Pregledi(std::initializer_list<Pregled> spisak_pregleda);

    ~Pregledi() = default;/*{
        for (int i(0); i<max_broj_pregleda; ++i) {
            delete niz[i];
        }
        delete[] niz;
    }*/
    Pregledi &operator = (const Pregledi &pregledi) {
        /*for (int i(0); i<broj_pregleda; ++i) delete niz[i];
        delete[] niz;
        broj_pregleda = pregledi.broj_pregleda;
        niz = new Pregled* [pregledi.broj_pregleda];
        for (int i(0); i<broj_pregleda; ++i) niz[i] = new Pregled(*pregledi.niz[i]);
        return *this;*/
        niz.resize(pregledi.niz.size());
        for (int i(0); i<pregledi.niz.size(); ++i) {
            auto p = std::make_shared<Pregled> (*pregledi.niz[i]);
            niz[i]=p;
        }
        //return *this;
    }

    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);

    Pregledi &operator = (Pregledi &&pregledi) = default;


    int DajBrojPregleda() const ;
    void RegistrirajPregled(const std::string &ime_pacijenta,  const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() {
        this->Pregledi::FunkcijaSortiranja();
        for (int l(0); l<niz.size(); ++l)
            niz[l]->Ispisi();
    }

    friend class Pregled;
    friend class Datum;
    friend class Vrijeme;

};



Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda)
{
/*    niz = new Pregled* [max_broj_pregleda];
    int i = 0;
    for (auto it(std::begin(spisak_pregleda)); it != std::end(spisak_pregleda); it++) {
        niz[i] = new Pregled (*it);
        ++i;
    }*/
    
    for (auto it(std::begin(spisak_pregleda)); it!=std::end(spisak_pregleda); ++it) {
        auto p = std::make_shared<Pregled> (*it);
        niz.push_back(p);
    }
}

Pregledi::Pregledi (const Pregledi &pregledi)
{
    /*niz = new Pregled* [pregledi.broj_pregleda] {};
    for ( int i(0); i<pregledi.broj_pregleda; ++i) niz[i] = new Pregled(*pregledi.niz[i]);
    */
    for (int i(0); i<pregledi.niz.size(); ++i) {
        auto p = std::make_shared<Pregled> (*pregledi.niz[i]);
        niz.push_back(p);
    }
}
Pregledi::Pregledi (Pregledi &&pregledi) = default;//: broj_pregleda(pregledi.broj_pregleda), max_broj_pregleda(pregledi.max_broj_pregleda)
/*{
    std::swap(niz, pregledi.niz);
    pregledi.niz = nullptr;
}*/

void Pregledi::RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{//int broj_pregleda = niz.size();
    //if (broj_pregleda >= max_broj_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
    auto pacijent = std::make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    niz.push_back(pacijent);
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
{//int broj_pregleda = niz.size();
    //if (broj_pregleda >= max_broj_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
    auto pacijent = std::make_shared<Pregled>(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    niz.push_back(pacijent);
}
void Pregledi::RegistrirajPregled(Pregled *pregled)
{
    //if (broj_pregleda >= max_broj_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
    *niz[niz.size()] = (*pregled);
    niz.resize(niz.size()+1);
}


int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{//int broj_pregleda = niz.size();
    int daj_broj_pregleda_na_datum = std::count_if(niz.begin(), niz.end(), [datum] (std::shared_ptr<Pregled> p) {
        if(p->datum_pregleda.godina == datum.godina && p->datum_pregleda.mjesec == datum.mjesec && p->datum_pregleda.dan == datum.dan) return true;
        return false;
    });
    return daj_broj_pregleda_na_datum;
}

Pregled &Pregledi::DajNajranijiPregled()
{int broj_pregleda = niz.size();
    if (broj_pregleda == 0) throw std::domain_error ("Nema registriranih pregleda");
    auto vrijednost = std::min_element(niz.begin(), niz.end(),[](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
        if(p1->datum_pregleda.godina < p2->datum_pregleda.godina) return true;
        else if(p1->datum_pregleda.godina == p2->datum_pregleda.godina) {
            if(p1->datum_pregleda.mjesec < p2->datum_pregleda.mjesec) return true;
            else if (p1->datum_pregleda.mjesec == p2->datum_pregleda.mjesec) {
                if (p1->datum_pregleda.dan < p2->datum_pregleda.dan) return true;
                else if (p1->datum_pregleda.dan == p2->datum_pregleda.dan) {
                    if (p1->vrijeme_pregleda.sati < p2->vrijeme_pregleda.sati) return true;
                    else if (p1->vrijeme_pregleda.sati == p2->vrijeme_pregleda.sati) {
                        if (p1->vrijeme_pregleda.minute < p2->vrijeme_pregleda.minute) return true;
                    }
                }
            }
        }
        return false;
    });
    return **vrijednost;
}
void Pregledi::IsprazniKolekciju()
{   
    int broj_pregleda = niz.size();
    for (int j(0); j<broj_pregleda; ++j) {
        niz[j] = nullptr;
    }
    broj_pregleda = 0;
}
int Pregledi::DajBrojPregleda() const
{   
    int broj_pregleda = niz.size();
    return broj_pregleda;
}
Pregled Pregledi::DajNajranijiPregled() const
{//int broj_pregleda = niz.size();
    if (niz.size() == 0) throw std::domain_error ("Nema registriranih pregleda");
    auto vrijednost = std::min_element (niz.begin(), niz.end(), [](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
        if (p1->datum_pregleda.godina < p2->datum_pregleda.godina) return true;
        else if(p1->datum_pregleda.godina == p2->datum_pregleda.godina) {
            if (p1->datum_pregleda.mjesec < p2->datum_pregleda.mjesec) return true;
            else if (p1->datum_pregleda.mjesec == p2->datum_pregleda.mjesec) {
                if (p1->datum_pregleda.dan < p1->datum_pregleda.dan) return true;
                else if(p1->datum_pregleda.dan == p2->datum_pregleda.dan) {
                    if (p1->vrijeme_pregleda.sati < p2->vrijeme_pregleda.sati) return true;
                    else if (p1->vrijeme_pregleda.sati == p2->vrijeme_pregleda.sati) {
                        if (p1->vrijeme_pregleda.minute < p2->vrijeme_pregleda.minute) return true;
                    }
                }
            }
        }
        return false;
    });
    return **vrijednost;
}


void Pregledi::ObrisiNajranijiPregled()
{   
    int broj_pregleda = niz.size();
    if(broj_pregleda == 0) throw std::range_error ("Prazna kolekcija");
    std::swap(niz[0], niz[broj_pregleda-1]);
    niz.resize(broj_pregleda-1);
    FunkcijaSortiranja();
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{   
    int broj_pregleda = niz.size();
    int temp = niz.size();
    for (int j(0); j<niz.size(); ++j) {
        if(niz[j]->ime_pacijenta == ime_pacijenta) {
            std::swap(niz[j], niz[broj_pregleda-1]);
            niz.resize(niz.size()-1);
            FunkcijaSortiranja();
           -- broj_pregleda;
        }
    }
    broj_izbrisanih_pregleda = temp - broj_pregleda;
}
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    std::vector<std::shared_ptr<Pregled>> pomocna;
    for (int i(0); i<niz.size(); ++i) {
        if(niz[i]->datum_pregleda.dan ==datum.dan && niz[i]->datum_pregleda.mjesec ==datum.mjesec && niz[i]->datum_pregleda.godina ==datum.godina) {
            pomocna.push_back(niz[i]);
        }
    }
    std::sort(pomocna.begin(), pomocna.end(),[](std::shared_ptr<Pregled> pregled1, std::shared_ptr<Pregled> pregled2) {
        if (pregled1->vrijeme_pregleda.sati > pregled2 ->vrijeme_pregleda.sati) return false;
        else if (pregled1 -> vrijeme_pregleda.sati < pregled2 ->vrijeme_pregleda.sati) return true;
        else if (pregled1->vrijeme_pregleda.sati == pregled2->vrijeme_pregleda.sati) {
            if (pregled1->vrijeme_pregleda.minute < pregled2->vrijeme_pregleda.minute) return true;
        }
        return false;
    });
    for (int j(0); j<pomocna.size(); ++j) {
        pomocna[j]->Ispisi();
    }
}


int main ()
{
    //int broj;
    //std::vector<std::shared_ptr<Pregled>> pregledi(broj);
    //std::cout<<"Unesite maksimalan broj pregleda: ";
    //std::cin >> broj;
    Pregledi pregledi;
    while (1){
        std::string vrijednost_koju_unosimo;
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::cin>>vrijednost_koju_unosimo;
        if (vrijednost_koju_unosimo == "kraj") break;
        int dan, mjesec, godina, sat, minuta;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        std::cin>>dan>>mjesec>>godina;
        std::cout<<"Unesite sate i minute pregleda: ";
        std::cin>>sat>>minuta;
        pregledi.RegistrirajPregled(vrijednost_koju_unosimo,dan, mjesec, godina, sat, minuta);
    }

    std::cout<<"Trenutno su registrovani sljedeci pregledi\n";
    pregledi.IspisiSvePreglede();

    int opcija;
    for (;;) {
        std::cout << std::endl;
        std::cout << "Odaberite jednu od sljedecih opcija\n1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa"<<std::endl;
        std::cin >> opcija;

        if (opcija == 1) {
            std::cout<<"Unesite dan mjesec i godinu : ";
            int d, m, g;
            std::cin >> d >> m >> g;
            Datum datum_na_koji_trazimo(d, m, g);
            int broj_pregleda_na_datum = pregledi.DajBrojPregledaNaDatum(datum_na_koji_trazimo);
            std::cout << "Broj pregleda na datum " << d <<" "<<m<< " "<<g<<" je: " << broj_pregleda_na_datum<<std::endl;

        }

        if (opcija==2) {
            auto najraniji_pregled = pregledi.DajNajranijiPregled();
            std::cout << "Najraniji pregled je:\n";
            najraniji_pregled.Ispisi();
        }

        if (opcija == 3) {
            std::cout << "Unesite ime pacijenta: ";
            std::string ime_pacijeta_za_izbrisati;
            std::cin>>ime_pacijeta_za_izbrisati;
            pregledi.ObrisiPregledePacijenta(ime_pacijeta_za_izbrisati);
            std::cout<<"Uspjesno obrisano "<<broj_izbrisanih_pregleda<<" pregleda\n";
        }

        if (opcija == 4) {
            pregledi.ObrisiNajranijiPregled();
            std::cout<<"Najraniji pregled uspjesno obrisan\n";
        }

        if (opcija == 5) {
            std::cout << "Unesite dan mjesec i godinu : ";
            int d, m, g;
            std::cin >> d >> m >> g;
            Datum nizna_datum (d, m, g);
            std::cout << "Pregledi na datum " << d <<" " << m <<" " << g <<" su:\n";
            pregledi.IspisiPregledeNaDatum(nizna_datum);
            std::cout << std::endl;
        }

        if (opcija == 6) {
            pregledi.IspisiSvePreglede();
        }
        if (opcija == 7) return 0;
    }


    return 0;
}