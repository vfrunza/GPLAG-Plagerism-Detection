/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <iomanip>
#include <initializer_list>
#include <new>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <string>

class Datum {
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan, mjesec, godina);
    }
    
    void Postavi(int dan, int mjesec, int godina);
    
    std::tuple<int, int, int> Ocitaj() const;
    
    void Ispisi() const {
        std::cout << std::right << dan << "/" << mjesec << "/" << godina;
    }
};

class Vrijeme {
    int sati, minute;
public:

    Vrijeme(int sati, int minute) {
        Postavi(sati, minute);
    }
    
    void Postavi(int sati, int minute) {
        if (sati < 0 || sati > 23 || minute < 0 || minute > 59)
            throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati = sati;
        Vrijeme::minute = minute;
    }
    
    std::pair<int, int> Ocitaj () const {
        std::pair<int, int> tmp;
        tmp = std::make_pair(sati, minute);
        
        return tmp;
    }
    
    void Ispisi() const {
         std::cout << std::setw(2) << std::setfill('0') << sati << ":" <<  std::setw(2) << std::setfill('0') << minute;
    }
};

class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:

    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : ime_pacijenta(ime_pacijenta),
        datum_pregleda(std::get<0>(datum_pregleda.Ocitaj()), std::get<1>(datum_pregleda.Ocitaj()), std::get<2>(datum_pregleda.Ocitaj())), 
        vrijeme_pregleda(vrijeme_pregleda.Ocitaj().first, vrijeme_pregleda.Ocitaj().second) {}
    
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : 
        ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda) , vrijeme_pregleda(sati_pregleda, minute_pregleda) {}
        
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta = ime_pacijenta;
    }
    
    void PromijeniDatum(const Datum &novi_datum) {
        Pregled::datum_pregleda = novi_datum;
    }
    
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        Pregled::vrijeme_pregleda = novo_vrijeme;
    }
    
    void PomjeriDanUnaprijed();
      
    void PomjeriDanUnazad();
    
    std::string DajImePacijenta() const { return ime_pacijenta; }
    
    Datum DajDatumPregleda() const { return datum_pregleda; }
    
    Vrijeme DajVrijemePregleda() const { return vrijeme_pregleda; }
    
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2); 
    
    void Ispisi() const;
    
};

class Pregledi {
    Pregled** niz_pregleda;
    const int max_broj_pregleda;
    int broj_pregleda;
    
public:
    explicit Pregledi(int max_broj) : 
        max_broj_pregleda(max_broj), broj_pregleda(0) , niz_pregleda(new Pregled*[max_broj]{}) {}
        
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    
    ~Pregledi() {
        for (int i = 0 ; i < broj_pregleda ; i++)
            delete niz_pregleda[i];
        delete[] niz_pregleda;
    }
    
    Pregledi(const Pregledi &pregledi);
    
    Pregledi(Pregledi &&pregledi);
    
    Pregledi &operator =(const Pregledi &pregledi);
    
    Pregledi &operator =(Pregledi &&pregledi);
    
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    
    void RegistrirajPregled(Pregled *pregled); 
    
    int DajBrojPregleda() const { return broj_pregleda; }
    
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
    std::cout << "Unesite maksimalan broj pregleda: ";
    int max_broj;
    std::cin >> max_broj;
    Pregledi pregledi(max_broj);
    for (int i = 0; i < max_broj; i++) {
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string ime;
        std::cin >> ime;
        std::cin.ignore(10000, '\n');
        if (ime == "kraj") break;
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        int dan, mjesec, godina;
        std::cin >> dan >> mjesec >> godina;
        std::cout << "Unesite sate i minute pregleda: ";
        int sati, minute;
        std::cin >> sati >> minute;
        pregledi.RegistrirajPregled(ime, dan, mjesec, godina, sati, minute);
    }
    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
    pregledi.IspisiSvePreglede();
    std::cout << std::endl << "Odaberite jednu od sljedecih opcija" << std::endl << "1 - Broj pregleda na datum" << std::endl << "2 - Najraniji pregled" << std::endl <<
                     "3 - Obrisi pregled pacijenta" << std::endl << "4 - Obrisi najraniji pregled" << std::endl << "5 - Ispisi sve pregleda na datum" << std::endl <<
                     "6 - Ispisi sve preglede" << std::endl << "7 - Kraj programa" << std::endl;
    int unos;
    std::cin >> unos;
    while (unos != 7) {
        if (unos == 1) {
            std::cout << "Unesite dan mjesec i godinu : ";
            int dan, mjesec, godina;
            std::cin >> dan >> mjesec >> godina;
            try {
                Datum datum(dan, mjesec, godina);
                int broj_pregleda_na_datum = pregledi.DajBrojPregledaNaDatum(datum);
                std::cout << "Broj pregleda na datum " << dan << " " << mjesec << " " << godina << " je: " << broj_pregleda_na_datum <<std::endl;
            } catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what();
            }
        }
        else if (unos == 2) {
            try {
                std::cout << "Najraniji pregled je: " << std::endl;
                Pregled najraniji = pregledi.DajNajranijiPregled();
                najraniji.Ispisi();
            } catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
            }
            
        }
        else if (unos == 3) {
            std::cout << "Unesite ime pacijenta: ";
            std::string ime;
            std::cin >> ime;
            int trenutni_br_pr = pregledi.DajBrojPregleda();
            pregledi.ObrisiPregledePacijenta(ime);
            int br_pr_nakon_brisanja = pregledi.DajBrojPregleda();
            std::cout << "Uspjesno obrisano " << trenutni_br_pr - br_pr_nakon_brisanja << " pregleda";
        }
        else if (unos == 4) {
            pregledi.ObrisiNajranijiPregled();
            std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
        }
        else if (unos == 5) {
            std::cout << "Unesite dan mjesec i godinu : ";
            int dan, mjesec, godina;
            std::cin >> dan >> mjesec >> godina;
            try {
                Datum datum(dan, mjesec, godina);
                std::cout << "Pregledi na datum " << dan << " " << mjesec << " " << godina << " su:" << std::endl;
                pregledi.IspisiPregledeNaDatum(datum);
            } catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what();
            }
        }
        else if (unos == 6) {
            pregledi.IspisiSvePreglede();
        }
        std::cin.ignore(10000, '\n');
        /*char temp;
        temp = std::cin.get();*/
        
        std::cout << std::endl << "Odaberite jednu od sljedecih opcija" << std::endl << "1 - Broj pregleda na datum" << std::endl << "2 - Najraniji pregled" << std::endl <<
                     "3 - Obrisi pregled pacijenta" << std::endl << "4 - Obrisi najraniji pregled" << std::endl << "5 - Ispisi sve pregleda na datum" << std::endl <<
                     "6 - Ispisi sve preglede" << std::endl << "7 - Kraj programa" << std::endl;
        std::cin >> unos;
    }
    
	return 0;
}

void Datum::Postavi(int dan, int mjesec, int godina) {
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((godina % 400 == 0 || godina % 100 != 0) && godina % 4 == 0)
            broj_dana[1]++;
        if (godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1])
            throw std::domain_error("Neispravan datum");
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
    }
    
    std::tuple<int, int, int> Datum::Ocitaj() const {
        std::tuple<int, int, int> tmp;
        tmp = std::make_tuple(dan, mjesec, godina);
        
        return tmp;
    }
    
void Pregled::PomjeriDanUnaprijed() {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Datum datum = this->DajDatumPregleda();
    std::tuple<int, int, int> ocitani_datum = datum.Ocitaj();
    ++std::get<0>(ocitani_datum);
    if (std::get<0>(ocitani_datum) > broj_dana[std::get<1>(ocitani_datum) - 1]) { //ako je broj dana veci od broja dana u mjesecu
        std::get<0>(ocitani_datum) = 1; //dan postavi na jedan
        ++std::get<1>(ocitani_datum); //uvecaj mjesec
        if (std::get<1>(ocitani_datum) > 12) { //ako je broj mjeseci veci od 12
            std::get<1>(ocitani_datum) = 1; //mjesec postavi na 1
            ++std::get<2>(ocitani_datum); //uvecaj godinu
        }
    }
        
    (*this).datum_pregleda.Postavi(std::get<0>(ocitani_datum), std::get<1>(ocitani_datum), std::get<2>(ocitani_datum));
}
    
void Pregled::PomjeriDanUnazad() {
    Datum datum = this->DajDatumPregleda();
    std::tuple<int, int, int> ocitani_datum = datum.Ocitaj();
    --std::get<0>(ocitani_datum);
    //ako je dan manji od nula funkcija Postavi ce baciti izuzetak
    (*this).datum_pregleda.Postavi(std::get<0>(ocitani_datum), std::get<1>(ocitani_datum), std::get<2>(ocitani_datum)); 
}
    
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    int broj_dana1[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int broj_dana2[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::tuple<int, int, int> ocitano_p1 = p1.datum_pregleda.Ocitaj(); 
    std::tuple<int, int, int> ocitano_p2 = p2.datum_pregleda.Ocitaj();
    int godina = std::get<2>(ocitano_p1);
    if ((godina % 400 == 0 || godina % 100 != 0) && godina % 4 == 0)
        broj_dana1[1]++;
    godina = std::get<2>(ocitano_p2);
    if ((godina % 400 == 0 || godina % 100 != 0) && godina % 4 == 0)
        broj_dana2[1]++;
    
    if (std::get<2>(ocitano_p1) < std::get<2>(ocitano_p2))
        return true;
    else if (std::get<2>(ocitano_p1) == std::get<2>(ocitano_p2)) {
        int br_dana_p1 = std::get<0>(ocitano_p1);
        for (int i = 0 ; i < std::get<1>(ocitano_p1) - 1 ; i++)
            br_dana_p1 += broj_dana1[i];
        int br_dana_p2 = std::get<0>(ocitano_p2);
        for (int i = 0 ; i < std::get<1>(ocitano_p2) - 1 ; i++)
            br_dana_p2 += broj_dana2[i];
            
        return br_dana_p1 < br_dana_p2;
    }
    return false;
}
    
void Pregled::Ispisi() const {
    std::string ime = Pregled::DajImePacijenta();
    Datum dat_pregleda = Pregled::DajDatumPregleda();
    Vrijeme vr_pregleda = Pregled::DajVrijemePregleda();
    std::cout << std::setfill(' ') << std::left << std::setw(30) << ime;
    dat_pregleda.Ispisi();
    std::cout << " ";
    vr_pregleda.Ispisi();
    std::cout << std::endl;
    std::cout.unsetf(std::ios::floatfield);
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) :
    max_broj_pregleda(spisak_pregleda.size()), broj_pregleda(spisak_pregleda.size()), niz_pregleda(new Pregled* [spisak_pregleda.size()]{}) {
        int i(0);
        for (auto it = spisak_pregleda.begin() ; it != spisak_pregleda.end() ; it++, i++)
            niz_pregleda[i] = new Pregled(it->DajImePacijenta(), it->DajDatumPregleda(), it->DajVrijemePregleda()); 
}

Pregledi::Pregledi(const Pregledi &pregledi) :
    niz_pregleda(new Pregled* [pregledi.max_broj_pregleda] {}), max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda) {
        try {
            for (int i = 0 ; i < pregledi.broj_pregleda ; i++)
                niz_pregleda[i] = new Pregled(*pregledi.niz_pregleda[i]);
        } catch(std::bad_alloc) {
            for (int i = 0 ; i < pregledi.broj_pregleda ; i++)
                delete niz_pregleda[i];
            delete[] niz_pregleda;
        }
}

Pregledi::Pregledi(Pregledi &&pregledi) :
    max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda), niz_pregleda(pregledi.niz_pregleda) {
        pregledi.niz_pregleda = nullptr;
        pregledi.broj_pregleda = 0;
}

Pregledi& Pregledi::operator =(const Pregledi &pregledi) {
    if(max_broj_pregleda != pregledi.max_broj_pregleda)
        throw std::logic_error("Neka poruka");
    if (pregledi.broj_pregleda > broj_pregleda) {
        try {
            for (int i = broj_pregleda ; i < pregledi.broj_pregleda ; i++)
                niz_pregleda[i] = new Pregled(*pregledi.niz_pregleda[i]);
                
        } catch (std::bad_alloc) {
            for (int i = broj_pregleda ; i < pregledi.broj_pregleda ; i++) {
                delete niz_pregleda[i];
                niz_pregleda[i] = nullptr;
            }
            throw;
        }
    }
    else {
        for (int i = pregledi.broj_pregleda ; i < broj_pregleda ; i++) {
            delete niz_pregleda[i];
            niz_pregleda[i] = nullptr;
        }
    }
    broj_pregleda = pregledi.broj_pregleda;
    for (int i = 0 ; i < broj_pregleda ; i++)
        *niz_pregleda[i] = *pregledi.niz_pregleda[i];
        
    return *this;
}

Pregledi& Pregledi::operator =(Pregledi &&pregledi) {
    if (max_broj_pregleda != pregledi.max_broj_pregleda)
        throw std::logic_error("Neka poruka");
    std::swap(broj_pregleda, pregledi.broj_pregleda);
    std::swap(niz_pregleda, pregledi.niz_pregleda);
    
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    Pregled* pok = *niz_pregleda;
    int brojac(0);
    while(pok != nullptr) {
        brojac++;
        pok++;
    }
    if (brojac == max_broj_pregleda)
        throw std::range_error ("Dostignut maksimalni broj pregleda");
    niz_pregleda[brojac] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    broj_pregleda++;    
    
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    niz_pregleda[broj_pregleda] = new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    broj_pregleda++;
    
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    return std::count_if(niz_pregleda, niz_pregleda + broj_pregleda, [datum] (Pregled* pok_na_pregled) {
        Datum dat = pok_na_pregled->DajDatumPregleda();
        std::tuple<int, int, int> dat_pregleda1 = dat.Ocitaj();
        std::tuple<int, int, int> dat_pregleda2 = datum.Ocitaj();
         return std::get<0>(dat_pregleda1) == std::get<0>(dat_pregleda2) && std::get<1>(dat_pregleda1) == std::get<1>(dat_pregleda2) &&
                std::get<2>(dat_pregleda1) == std::get<2>(dat_pregleda2);
    });
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    for (int i = 0 ; i < broj_pregleda ; i++) {
        if (niz_pregleda[i]->DajImePacijenta() == ime_pacijenta) {
            delete niz_pregleda[i];
            for (int j = i ; j < broj_pregleda - 1 ; j++)
                niz_pregleda[j] = niz_pregleda[j + 1];
                
            niz_pregleda[broj_pregleda - 1] = nullptr;
            broj_pregleda--;
        }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
    std::tuple<int, int, int> ocitani_datum = datum.Ocitaj();
    std::vector<Pregled*> vekt_pregleda;
    for (int i = 0 ; i < broj_pregleda ; i++) {
        Datum pomocni = niz_pregleda[i]->DajDatumPregleda();
        std::tuple<int, int, int> jedan_datum = pomocni.Ocitaj();
        if (std::get<0>(jedan_datum) == std::get<0>(ocitani_datum) && std::get<1>(jedan_datum) == std::get<1>(ocitani_datum) && std::get<2>(jedan_datum) == std::get<2>(ocitani_datum))
            vekt_pregleda.push_back(niz_pregleda[i]);
    }
    std::sort(vekt_pregleda.begin(), vekt_pregleda.end(), [](Pregled* pregled1, Pregled* pregled2) {
        return pregled1->DolaziPrije(*pregled2, *pregled1); 
    });
    for (int i = 0 ; i < vekt_pregleda.size() ; i++)
        vekt_pregleda[i]->Ispisi();
    
}

void Pregledi::IspisiSvePreglede() const {
    std::sort(niz_pregleda, niz_pregleda + broj_pregleda , [](Pregled* pregled1, Pregled* pregled2) {
        return pregled1->DolaziPrije(*pregled1, *pregled2);
    });
    for (int i = 0 ; i < broj_pregleda ; i++)
        niz_pregleda[i]->Ispisi();
}

Pregled &Pregledi::DajNajranijiPregled() {
    if (broj_pregleda == 0)
        throw std::domain_error("Nema registriranih pregleda");
        
    auto najraniji_pregled = std::min_element(niz_pregleda, niz_pregleda + broj_pregleda, [](Pregled* pregled1, Pregled* pregled2) {
        return Pregled::DolaziPrije(*pregled1, *pregled2);
    });
    
    return *(*najraniji_pregled);
}

Pregled Pregledi::DajNajranijiPregled() const {
    if (broj_pregleda == 0)
        throw std::domain_error("Nema registriranih pregleda");
        
    auto najraniji_pregled = std::min_element(niz_pregleda, niz_pregleda + broj_pregleda, [](Pregled* pregled1, Pregled* pregled2) {
        return Pregled::DolaziPrije(*pregled1, *pregled2);
    });
   
   return *(*najraniji_pregled);
}

void Pregledi::ObrisiNajranijiPregled() {
    try {
        Pregled najraniji_pregled = this->DajNajranijiPregled();
        Datum datum_najranijeg = najraniji_pregled.DajDatumPregleda();
      
        for (int i = 0 ; i < broj_pregleda ; i++) {
            std::tuple<int, int, int> datum = niz_pregleda[i]->DajDatumPregleda().Ocitaj();
            std::pair<int, int> vrijeme = niz_pregleda[i]->DajVrijemePregleda().Ocitaj();
            
            if (niz_pregleda[i]->DajImePacijenta() == najraniji_pregled.DajImePacijenta() &&
                std::get<0>(datum) == std::get<0>(datum_najranijeg.Ocitaj()) && 
                std::get<1>(datum) == std::get<1>(datum_najranijeg.Ocitaj()) && 
                std::get<2>(datum) == std::get<2>(datum_najranijeg.Ocitaj()) &&
                vrijeme.first == najraniji_pregled.DajVrijemePregleda().Ocitaj().first && 
                vrijeme.second == najraniji_pregled.DajVrijemePregleda().Ocitaj().second) {
                delete niz_pregleda[i];
                for(int j = i; j < broj_pregleda - 1; j++)
                    niz_pregleda[j] = niz_pregleda[j + 1];
                
                niz_pregleda[broj_pregleda - 1] = nullptr;
                broj_pregleda--;
                //pretpostavka je da nema vise istih
            }
        }
    } catch(std::domain_error) {
        throw;
    }
}

void Pregledi::RegistrirajPregled(Pregled *pregled) {
    niz_pregleda[broj_pregleda] = pregled;
}

void Pregledi::IsprazniKolekciju() {
    for (int i = 0 ; i < broj_pregleda ; i++) {
        delete niz_pregleda[i];
        niz_pregleda[i] = nullptr;
    }
    broj_pregleda = 0;
}
    
   