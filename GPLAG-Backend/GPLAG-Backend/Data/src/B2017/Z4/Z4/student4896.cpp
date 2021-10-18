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
    std::vector<std::shared_ptr<Pregled>> vec_pregleda;
    int broj_pregleda;
public:

    explicit Pregledi(): broj_pregleda(0) {}

    Pregledi(std::initializer_list<Pregled> spisak_pregleda): broj_pregleda(spisak_pregleda.size()) {
        vec_pregleda.resize(spisak_pregleda.size());
        try {
            for(int i=0; i<spisak_pregleda.size(); i++) {
                vec_pregleda[i]=std::shared_ptr<Pregled> ();
            }
        } catch(...) {
            throw;
        }
    }

    Pregledi(const Pregledi &pregledi):broj_pregleda(pregledi.broj_pregleda) {
        try {
            vec_pregleda.resize(pregledi.broj_pregleda);
            try {
                for(int i=0; i<pregledi.broj_pregleda; i++) {
                    vec_pregleda[i]=std::shared_ptr<Pregled> (pregledi.vec_pregleda[i]);
                }
            } catch(...) {
                throw;
            }
        } catch(...) {
            throw;
        }
    }

    Pregledi(Pregledi &&pregledi):broj_pregleda(pregledi.broj_pregleda), vec_pregleda(pregledi.vec_pregleda) {
        pregledi.broj_pregleda=0;
        pregledi.vec_pregleda.resize(0);
    }

    Pregledi &operator = (const Pregledi &pregledi) {
        if(broj_pregleda>pregledi.broj_pregleda) {
            for(int i=pregledi.broj_pregleda; i<broj_pregleda; i++) {
                vec_pregleda[i]=nullptr;
            }
        } else {
            try {
                std::vector<std::shared_ptr<Pregled>> vec_pregleda_novi(pregledi.broj_pregleda);
                for(int i=0; i<broj_pregleda; i++) {
                    vec_pregleda[i]=nullptr;
                }
                vec_pregleda=vec_pregleda_novi;
            } catch(...) {
                throw;
            }
        }

        broj_pregleda=pregledi.broj_pregleda;
        for(int i=0; i<broj_pregleda; i++) {
            *(vec_pregleda[i])=*(pregledi.vec_pregleda[i]);
        }
        return *this;
    }

    Pregledi &operator =(Pregledi &&pregledi) {
        std::swap(broj_pregleda,pregledi.broj_pregleda);
        std::swap(vec_pregleda,pregledi.vec_pregleda);
        return *this;
    }

    void RegistrirajPregled(const std::string &ime_pac, const Datum &datum_pregl, const Vrijeme &vrijeme_pregl) {
        vec_pregleda.resize(vec_pregleda.size()+1);
        vec_pregleda[broj_pregleda]=std::make_shared<Pregled>(ime_pac,datum_pregl,vrijeme_pregl);
        broj_pregleda++;
    }

    void RegistrirajPregled(const std::string &ime_pac, int dan, int mjesec, int godina, int sat, int min) {
        vec_pregleda.resize(vec_pregleda.size()+1);
        vec_pregleda[broj_pregleda]=std::make_shared<Pregled>(ime_pac,dan,mjesec,godina,sat,min);
        broj_pregleda++;
    }

    void RegistrirajPregled(std::shared_ptr<Pregled> pregled) {
        vec_pregleda.resize(vec_pregleda.size()+1);
        vec_pregleda[broj_pregleda]=pregled;
        broj_pregleda++;
    }

    int DajBrojPregleda() const {
        return broj_pregleda;
    }

    int DajBrojPregledaNaDatum(const Datum &datum) const {
        int broj_istih=std::count_if(vec_pregleda.begin(),vec_pregleda.end(),[datum](std::shared_ptr<Pregled> P) {
            return (std::get<0>(P->DajDatumPregleda().Ocitaj())==std::get<0>(datum.Ocitaj()) &&
                    std::get<1>(P->DajDatumPregleda().Ocitaj())==std::get<1>(datum.Ocitaj()) &&
                    std::get<2>(P->DajDatumPregleda().Ocitaj())==std::get<2>(datum.Ocitaj()));
        });
        return broj_istih;
    }

    Pregled &DajNajranijiPregled() {
        if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");

        return **std::min_element(vec_pregleda.begin(),vec_pregleda.end(),[](std::shared_ptr<Pregled> P1, std::shared_ptr<Pregled> P2) {
            return Pregled::DolaziPrije(*P1,*P2);
        });
    }

    Pregled DajNajranijiPregled() const {
        if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");

        return **std::min_element(vec_pregleda.begin(),vec_pregleda.end(),[](std::shared_ptr<Pregled> P1, std::shared_ptr<Pregled> P2) {
            return Pregled::DolaziPrije(*P1,*P2);
        });
    }

    void IsprazniKolekciju() {
        for(int i=0; i<broj_pregleda; i++) {
            vec_pregleda[i]=nullptr;
        }
        vec_pregleda.resize(0);
        broj_pregleda=0;
    }

    void IspisiPregledeNaDatum(const Datum &datum) {
        int broj_pregleda_na_datum=DajBrojPregledaNaDatum(datum);
        std::vector<std::shared_ptr<Pregled>> novi_vec(broj_pregleda_na_datum);
        int br(0);
        for(int i=0; i<broj_pregleda; i++) {
            if(std::get<0>(vec_pregleda[i]->DajDatumPregleda().Ocitaj())==std::get<0>(datum.Ocitaj()) &&
                    std::get<1>(vec_pregleda[i]->DajDatumPregleda().Ocitaj())==std::get<1>(datum.Ocitaj()) &&
                    std::get<2>(vec_pregleda[i]->DajDatumPregleda().Ocitaj())==std::get<2>(datum.Ocitaj())) {
                novi_vec[br]=vec_pregleda[i];
                br++;
            }
        }
        std::sort(novi_vec.begin(),novi_vec.end(),[](std::shared_ptr<Pregled> P1, std::shared_ptr<Pregled> P2) {
            return Pregled::DolaziPrije(*P1,*P2);
        });

        for(int i=0; i<br; i++) {
            novi_vec[i]->Ispisi();
        }
    }

    void IspisiSvePreglede() const {
        std::vector<std::shared_ptr<Pregled>> vec_novi(broj_pregleda);
        for(int i=0; i<broj_pregleda; i++) {
            vec_novi[i]=vec_pregleda[i];
        }
        std::sort(vec_novi.begin(),vec_novi.end(),[](std::shared_ptr<Pregled> P1, std::shared_ptr<Pregled> P2) {
            return Pregled::DolaziPrije(*P1,*P2);
        });
        for(int i=0; i<broj_pregleda; i++) {
            vec_novi[i]->Ispisi();
        }
    }

    void ObrisiNajranijiPregled() {
        if(broj_pregleda==0) throw std::range_error("Prazna kolekcija");
        for(int i=0; i<broj_pregleda; i++) {
            if(vec_pregleda[i]==*std::min_element(vec_pregleda.begin(),vec_pregleda.end(),[](std::shared_ptr<Pregled> &P1, std::shared_ptr<Pregled> &P2) {
            return Pregled::DolaziPrije(*P1,*P2);
            })) {
                vec_pregleda.erase(vec_pregleda.begin()+i);
                break;
            }
        }
        broj_pregleda--;
    }

    void ObrisiPregledePacijenta(const std::string &ime_pac) {
        for(int i=0; i<broj_pregleda; i++) {
            if(vec_pregleda[i]->DajImePacijenta()==ime_pac) {
                vec_pregleda.erase(vec_pregleda.begin()+i);
                broj_pregleda--;
                i--;
            }
        }
    }
};

int main()
{

    try {
        int dan, mjesec, godina, sat, minuta;
        std::string ime;
        Pregledi skup;
        std::vector<std::shared_ptr<Pregled>> Osoba;
        int broj_pregleda(0);
        for(;;) {
            std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
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
            try {
                Osoba.push_back(std::make_shared<Pregled>(ime,Datum(dan,mjesec,godina),Vrijeme(sat,minuta)));
            } catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
                return 0;
            }
            std::cin.ignore(1000, '\n');
            broj_pregleda++;
            try {
                skup.RegistrirajPregled(ime,dan,mjesec,godina,sat,minuta);
            } catch(std::range_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
                return 0;
            }
        }
        std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
        std::sort(Osoba.begin(),Osoba.end(),[](const std::shared_ptr<Pregled> &o1,const std::shared_ptr<Pregled> &o2) {
            return Pregled::DolaziPrije(*o1,*o2);
        });
        for(int i=0; i<Osoba.size(); i++) {
            Osoba[i]->Ispisi();
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