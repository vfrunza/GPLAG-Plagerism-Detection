/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <initializer_list>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>

class Datum
{
private:
    int dan, mjesec, godina;
public:
    Datum (int d, int m, int g) {
        int br_dana[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
        if((g%4==0 && g%100!=0) || g%400==0) br_dana[1]++;
        if(g<1 || m<1 || d<1 || m>12 || d>br_dana[m-1]) throw std::domain_error("Neispravan datum");
        dan=d;
        mjesec=m;
        godina=g;
    }
    void Postavi(int d, int m, int g) {
        int br_dana[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
        if((g%4==0 && g%100!=0) || g%400==0) br_dana[1]++;
        if(g<1 || m<1 || d<1 || m>12 || d>br_dana[m-1]) throw std::domain_error("Neispravan datum");
        dan=d;
        mjesec=m;
        godina=g;
    }
    std::tuple<int,int,int> Ocitaj() const {
        return std::make_tuple(dan,mjesec,godina);
    }
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

class Vrijeme
{
private:
    int sati, minute;
public:
    Vrijeme(int h, int min) {
        if(h<0 || h>23 || min<0 || min>59) throw std::domain_error("Neispravno vrijeme");
        sati=h;
        minute=min;
    }
    void Postavi(int h, int min) {
        if(h<0 || h>23 || min<0 || min>59) throw std::domain_error("Neispravno vrijeme");
        sati=h;
        minute=min;
    }
    std::pair<int, int> Ocitaj() const {
        return std::make_pair(sati,minute);
    }
    void Ispisi() const {
        std::cout << std::setw(2) << std::setfill('0') << std::right << sati << ":" << std::setw(2) << std::setfill('0') << std::right <<  minute;
    }
};

class Pregled
{
private:
    std::string ime_pacijenta;
    Datum datum_pregleda {1,1,2000};
    Vrijeme vrijeme_pregleda {0,0};
    int PomjeranjeDana(int mj, int god);
public:
    Pregled(const std::string &ime_pac, const Datum &datum_pregl, const Vrijeme &vrijeme_pregl) {
        ime_pacijenta=ime_pac;
        datum_pregleda=datum_pregl;
        vrijeme_pregleda=vrijeme_pregl;
    }
    Pregled(const std::string &ime_pac, int dan_pregl, int mjesec_pregl,
            int god_pregl, int sat_pregl, int min_pregl):datum_pregleda(dan_pregl,mjesec_pregl,god_pregl), vrijeme_pregleda(sat_pregl,min_pregl) {
        ime_pacijenta=ime_pac;
    }
    void PromijeniPacijenta(const std::string &ime_pac) {
        ime_pacijenta=ime_pac;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        datum_pregleda=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme_pregleda=novo_vrijeme;
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

    static bool DolaziPrije(const Pregled &P1, const Pregled &P2) {
        if(std::get<2>(P1.DajDatumPregleda().Ocitaj())<std::get<2>(P2.DajDatumPregleda().Ocitaj())) return true;

        if(std::get<2>(P1.DajDatumPregleda().Ocitaj())==std::get<2>(P2.DajDatumPregleda().Ocitaj()) &&
                (std::get<1>(P1.DajDatumPregleda().Ocitaj())<std::get<1>(P2.DajDatumPregleda().Ocitaj()))) return true;

        if(std::get<2>(P1.DajDatumPregleda().Ocitaj())==std::get<2>(P2.DajDatumPregleda().Ocitaj()) &&
                std::get<1>(P1.DajDatumPregleda().Ocitaj())==std::get<1>(P2.DajDatumPregleda().Ocitaj()) &&
                std::get<0>(P1.DajDatumPregleda().Ocitaj())<std::get<0>(P2.DajDatumPregleda().Ocitaj())) return true;

        if(std::get<2>(P1.DajDatumPregleda().Ocitaj())==std::get<2>(P2.DajDatumPregleda().Ocitaj()) &&
                std::get<1>(P1.DajDatumPregleda().Ocitaj())==std::get<1>(P2.DajDatumPregleda().Ocitaj()) &&
                std::get<0>(P1.DajDatumPregleda().Ocitaj())==std::get<0>(P2.DajDatumPregleda().Ocitaj()) &&
                std::get<0>(P1.DajVrijemePregleda().Ocitaj())<std::get<0>(P2.DajVrijemePregleda().Ocitaj())) return true;

        if(std::get<2>(P1.DajDatumPregleda().Ocitaj())==std::get<2>(P2.DajDatumPregleda().Ocitaj()) &&
                std::get<1>(P1.DajDatumPregleda().Ocitaj())==std::get<1>(P2.DajDatumPregleda().Ocitaj()) &&
                std::get<0>(P1.DajDatumPregleda().Ocitaj())==std::get<0>(P2.DajDatumPregleda().Ocitaj()) &&
                std::get<0>(P1.DajVrijemePregleda().Ocitaj())==std::get<0>(P2.DajVrijemePregleda().Ocitaj()) &&
                std::get<1>(P1.DajVrijemePregleda().Ocitaj())<std::get<1>(P2.DajVrijemePregleda().Ocitaj())) return true;
        return false;
    }

    void Ispisi() const {
        std::cout << std::setw(30) << std::setfill(' ') << std::left << ime_pacijenta;
        datum_pregleda.Ispisi();
        std::cout << " ";
        vrijeme_pregleda.Ispisi();
        std::cout << std::endl;
    }
};

int Pregled::PomjeranjeDana(int mj, int god)
{
    int br_dana[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if((god%4==0 && god%100!=0) || god%400==0) br_dana[1]++;
    return br_dana[mj-1];
}

void Pregled::PomjeriDanUnaprijed()
{
    int Dan=std::get<0>(DajDatumPregleda().Ocitaj());
    int Mjesec=std::get<1>(DajDatumPregleda().Ocitaj());
    int Godina=std::get<2>(DajDatumPregleda().Ocitaj());
    Dan++;
    if(Dan>PomjeranjeDana(Mjesec,Godina)) {
        Dan=1;
        Mjesec++;
    }
    if(Mjesec>12) {
        Mjesec=1;
        Godina++;
    }
    datum_pregleda.Postavi(Dan,Mjesec,Godina);
}

void Pregled::PomjeriDanUnazad()
{
    int Dan=std::get<0>(DajDatumPregleda().Ocitaj());
    int Mjesec=std::get<1>(DajDatumPregleda().Ocitaj());
    int Godina=std::get<2>(DajDatumPregleda().Ocitaj());
    Dan--;
    if(Dan<1) {
        Mjesec--;
        if(Mjesec<1) {
            Mjesec=12;
            Godina--;
        }
        Dan=PomjeranjeDana(Mjesec,Godina);
    }
    datum_pregleda.Postavi(Dan,Mjesec,Godina);
}

class Pregledi
{
private:
    Pregled **pok=nullptr;
    const int max_broj_pregleda;
    int broj_pregleda;

public:
    explicit Pregledi(int max_broj_pregl): max_broj_pregleda(max_broj_pregl), broj_pregleda(0), pok(new Pregled*[max_broj_pregl] {}) {}

    Pregledi(std::initializer_list<Pregled> spisak_pregleda): max_broj_pregleda(spisak_pregleda.size()), broj_pregleda(spisak_pregleda.size()),
        pok(new Pregled*[spisak_pregleda.size()] {}) {
        try {
            auto it(spisak_pregleda.begin());
            for(auto i=0; i<max_broj_pregleda; i++) {
                pok[i]=new Pregled(*it);
                it++;
            }
        } catch(...) {
            for(int i=0; i<broj_pregleda; i++) {
                delete pok[i];
            }
            delete[] pok;
            throw;
        }
    }

    ~Pregledi() {
        for(int i=0; i<broj_pregleda; i++) {
            delete pok[i];
        }
        delete[] pok;
    }

    Pregledi (const Pregledi &pregledi): max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.max_broj_pregleda),
        pok(new Pregled*[pregledi.max_broj_pregleda] {}) {
        try {
            for(int i=0; i<pregledi.max_broj_pregleda; i++) {
                pok[i]=new Pregled(*pregledi.pok[i]);
            }
        } catch(...) {
            for(int i=0; i<broj_pregleda; i++) {
                delete pok[i];
            }
            delete[] pok;
            throw;
        }
    }

    Pregledi(Pregledi &&pregledi): max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda),
        pok(pregledi.pok) {
        pregledi.broj_pregleda=0;
        pregledi.pok=nullptr;
    }

    Pregledi &operator = (const Pregledi &pregledi) {
        if(broj_pregleda>pregledi.broj_pregleda) {
            for(int i=pregledi.broj_pregleda; i<broj_pregleda; i++) {
                delete pok[i];
                pok[i]=nullptr;
            }
        } else {
            try {
                Pregled **pok1(new Pregled*[pregledi.broj_pregleda]);
                for(int i=0; i<broj_pregleda; i++) {
                    delete pok[i];
                }
                delete[] pok;
                pok=pok1;
            } catch(...) {

                throw;
            }
        }
        broj_pregleda=pregledi.broj_pregleda;

        for(int i=0; i<pregledi.broj_pregleda; i++) {
            *(pok[i])=*(pregledi.pok[i]);
        }
        return *this;
    }

    Pregledi &operator = (Pregledi && pregledi) {
        std::swap(broj_pregleda,pregledi.broj_pregleda);
        std::swap(pok,pregledi.pok);
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        pok[broj_pregleda]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
        broj_pregleda++;
    }

    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
                            int sati_pregleda, int minute_pregleda) {
        if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        pok[broj_pregleda]=new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
        broj_pregleda++;
    }

    void RegistrirajPregled(Pregled *pregled) {
        if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregled");
        pok[broj_pregleda]=pregled;
        broj_pregleda++;
    }

    int DajBrojPregleda() const {
        return broj_pregleda;
    }

    int DajBrojPregledaNaDatum(const Datum &datum) const;

    Pregled &DajNajranijiPregled();

    Pregled DajNajranijiPregled() const {
        if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
        return **std::min_element(pok,pok+broj_pregleda,[](Pregled *p1,Pregled *p2) {
            return Pregled::DolaziPrije(*p1,*p2);
        });
    }

    void IsprazniKolekciju() {
        for(int i=0; i<broj_pregleda; i++) {
            delete pok[i];
            pok[i]=nullptr;
        }
        broj_pregleda=0;
    }

    void ObrisiNajranijiPregled() {
        if(broj_pregleda==0) throw std::range_error("Prazna kolekcija");
        for(int i=0; i<broj_pregleda; i++) {
            if(pok[i]==&DajNajranijiPregled()) {
                delete pok[i];
                pok[i]=nullptr;
                break;
            }
        }
        Pregled **pok1=new Pregled*[broj_pregleda];
        int k(0);
        for(int i=0; i<broj_pregleda; i++) {
            if(pok[i]!=nullptr) {
                pok1[k]=new Pregled(*pok[i]);
                k++;
            }
        }
        std::swap(pok,pok1);
        for(int i=0; i<broj_pregleda; i++) {
            delete pok1[i];
        }
        delete[] pok1;
        broj_pregleda=k;
    }

    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    int broj_istih_datuma=std::count_if(pok,pok+broj_pregleda,[datum](Pregled *pok) {
        if (std::get<0>(pok->DajDatumPregleda().Ocitaj())==std::get<0>(datum.Ocitaj()) &&
                std::get<1>(pok->DajDatumPregleda().Ocitaj())==std::get<1>(datum.Ocitaj()) &&
                std::get<2>(pok->DajDatumPregleda().Ocitaj())==std::get<2>(datum.Ocitaj())) return true;
        return false;
    });
    return broj_istih_datuma;
}

Pregled &Pregledi::DajNajranijiPregled()
{
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(pok,pok+broj_pregleda,[](Pregled *p1,Pregled *p2) {
        if(Pregled::DolaziPrije(*p1,*p2)) return true;
        return false;
    });
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    int k(0);
    for(int i=0; i<broj_pregleda; i++) {
        if(pok[i]->DajImePacijenta()==ime_pacijenta) {
            delete pok[i];
            pok[i]=nullptr;
        }
    }
    Pregled **pok1=new Pregled*[broj_pregleda];
    for(int i=0; i<broj_pregleda; i++) {
        if(pok[i]!=nullptr) {
            pok1[k]=new Pregled(*pok[i]);
            k++;
        }
    }
    std::swap(pok,pok1);
    for(int i=0; i<broj_pregleda; i++) {
        delete pok1[i];
    }
    delete[] pok1;
    broj_pregleda=k;
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    for(int i=0; i<broj_pregleda; i++) {
        if(std::get<0>(pok[i]->DajDatumPregleda().Ocitaj())==std::get<0>(datum.Ocitaj()) &&
                std::get<1>(pok[i]->DajDatumPregleda().Ocitaj())==std::get<1>(datum.Ocitaj()) &&
                std::get<2>(pok[i]->DajDatumPregleda().Ocitaj())==std::get<2>(datum.Ocitaj())) {
            pok[i]->Ispisi();
        }
    }
}

void Pregledi::IspisiSvePreglede() const
{
    std::vector<Pregled *> ZaIspis;
    for(int i=0; i<broj_pregleda; i++){
        ZaIspis.push_back(pok[i]);
    }
    std::sort(ZaIspis.begin(),ZaIspis.end(),[](Pregled *p1,Pregled *p2){
        return Pregled::DolaziPrije(*p1,*p2);
    });
    for(int i=0; i<broj_pregleda; i++){
        ZaIspis[i]->Ispisi();
    }
}

int main ()
{
    try {
        int max_broj_pregleda, dan, mjesec, godina, sat, minuta;
        std::string ime;
        Pregledi skup(20);
        std::vector<Pregled *> Osoba;
        std::cout << "Unesite maksimalan broj pregleda: ";
        std::cin >> max_broj_pregleda;
        if(max_broj_pregleda<1) return 0;
        int broj_pregleda(0);
        for(;;) {
            std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::cin.ignore(1000, '\n');
            std::getline(std::cin,ime);
            if(ime=="kraj") break;
            std::cout << "Unesite dan mjesec i godinu pregleda: ";
            std::cin >> dan >> mjesec >> godina;
            try {
                Datum d=Datum(dan,mjesec,godina);
            } catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
                return 0;
            }
            std::cout << "Unesite sate i minute pregleda: ";
            std::cin >> sat >> minuta;
            try {
                Vrijeme v=Vrijeme(sat,minuta);
            } catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
                return 0;
            }
            Osoba.push_back(new Pregled(ime,dan,mjesec,godina,sat,minuta));
            try {
                skup.RegistrirajPregled(ime,dan,mjesec,godina,sat,minuta);
            } catch(std::range_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
                return 0;
            }
            broj_pregleda++;
            if(broj_pregleda==max_broj_pregleda) break;
        }
        std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
        std::sort(Osoba.begin(),Osoba.end(),[](Pregled* o1,Pregled* o2) {
            return Pregled::DolaziPrije(*o1,*o2);
        });
        for(int i=0; i<Osoba.size(); i++) {
            Osoba[i]->Ispisi();
        }
        for(int i=0; i<Osoba.size(); i++) {
            delete Osoba[i];
        }
        int U;
        for(;;) {
            std::cout << std::endl << "Odaberite jednu od sljedecih opcija" << std::endl;
            std::cout << "1 - Broj pregleda na datum" << std::endl << "2 - Najraniji pregled" << std::endl <<
                      "3 - Obrisi pregled pacijenta" << std::endl << "4 - Obrisi najraniji pregled" << std::endl <<
                      "5 - Ispisi sve pregleda na datum" << std::endl << "6 - Ispisi sve preglede" << std::endl << "7 - Kraj programa" << std::endl;
            std::cin >> U;
            if(U==1) {
                try {
                    std::cout << "Unesite dan mjesec i godinu : ";
                    std::cin >> dan >> mjesec >> godina;
                    try {
                        Datum d=Datum(dan,mjesec,godina);
                    } catch(std::domain_error izuzetak) {
                        std::cout << izuzetak.what() << std::endl;
                        return 0;
                    }
                    std::cout << "Broj pregleda na datum " << dan << " " << mjesec << " " << godina << " je: " << skup.DajBrojPregledaNaDatum(Datum(dan,mjesec,godina));
                    std::cout << std::endl;
                } catch(std::domain_error izuzetak) {
                    std::cout << izuzetak.what() << std::endl;
                    return 0;
                }
            } else if(U==2) {
                try {
                    skup.DajNajranijiPregled();
                    std::cout << "Najraniji pregled je:" << std::endl;
                    skup.DajNajranijiPregled().Ispisi();
                    std::cout << std::endl;
                } catch(std::domain_error izuzetak) {
                    std::cout << izuzetak.what() << std::endl;
                    return 0;
                }
            } else if(U==3) {
                std::cout << "Unesite ime pacijenta: ";
                std::string ime_za_brisati;
                std::cin.ignore(1000, '\n');
                std::getline(std::cin,ime_za_brisati);
                int br_preg1=skup.DajBrojPregleda();
                skup.ObrisiPregledePacijenta(ime_za_brisati);
                int br_preg2=skup.DajBrojPregleda();
                std::cout << "Uspjesno obrisano " << br_preg1-br_preg2 << " pregleda" << std::endl;
            } else if(U==4) {
                try {
                    skup.ObrisiNajranijiPregled();
                    std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
                } catch(std::range_error izuzetak) {
                    std::cout << izuzetak.what() << std::endl;
                    return 0;
                }
            } else if(U==5) {
                std::cout << "Unesite dan mjesec i godinu : ";
                std::cin >> dan >> mjesec >> godina;
                std::cout << "Pregledi na datum " << dan << " " << mjesec << " " << godina << " su:" << std::endl;
                skup.IspisiPregledeNaDatum(Datum(dan,mjesec,godina));
            } else if(U==6) {
                skup.IspisiSvePreglede();
            }
            if(U==7) {
                return 0;
            }
        }
    } catch(...) {
    }
    return 0;
}
