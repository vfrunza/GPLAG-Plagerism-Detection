/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <initializer_list>
#include <new>


class Datum
{
    int dan, mjesec, godina;

public:

    Datum(int dan=0, int mjesec=0, int godina=0) {
        Postavi(dan, mjesec, godina);
    }
    void Postavi(int d, int m, int g);

    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(dan, mjesec, godina);
    }
    void Ispisi() const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};

void Datum::Postavi(int d, int m, int g)
{
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4 == 0 && g%100 != 0 || g%400 == 0) broj_dana[1]++;
    if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1]) throw std::domain_error("Neispravan datum");
    dan=d;
    mjesec=m;
    godina=g;
}

class Vrijeme
{
    int sati, minute;
public:
    Vrijeme(int sati=0, int minute=0) {
        Postavi(sati, minute);
    }
    void Postavi(int s, int m);
    std::pair<int, int> Ocitaj() const {
        return std::make_pair(sati, minute);
    }
    void Ispisi() const {
        std::cout<<std::right<<std::setw(2)<<std::setfill('0')<<sati<<":"<<std::right<<std::setw(2)<<std::setfill('0')<<minute;
    }
};

void Vrijeme::Postavi(int sati, int minute)
{
    if (sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati=sati;
    Vrijeme::minute=minute;
}

class Pregled
{
    std::string ime_p;
    Datum datum_p;
    Vrijeme vrijeme_p;


public:
    Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):
        ime_p(ime_pacijenta), datum_p(datum_pregleda), vrijeme_p(vrijeme_pregleda) {}

    Pregled (const std::string &ime_pacijenta, int d, int m, int g,
             int sati, int minute) : ime_p(ime_pacijenta), datum_p(Datum(d,m,g)), vrijeme_p(Vrijeme(sati,minute)) {}

    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        ime_p=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        datum_p=novi_datum;

    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme_p=novo_vrijeme;
    }
    void PomjeriDanUnaprijed() {

        int d=std::get<0>(datum_p.Ocitaj());
        int m=std::get<1>(datum_p.Ocitaj());
        int g=std::get<2>(datum_p.Ocitaj());
        d+=1;
        int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(g%4 == 0 && g%100 != 0 || g%400 == 0) broj_dana[1]++;

        if(d>broj_dana[m-1]) {
            d=1;
            m++;

            if(m>12) {
                m=1;
                g++;
            }
        }
        datum_p.Postavi(d,m,g);
    }

    void PomjeriDanUnazad() {
        int d=std::get<0>(datum_p.Ocitaj());
        int m=std::get<1>(datum_p.Ocitaj());
        int g=std::get<2>(datum_p.Ocitaj());
        d-=1;
        int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(g%4 == 0 && g%100 != 0 || g%400 == 0) broj_dana[1]++;

        if(d==0) {
            m--;
            if(m==0) {
                m=12;
                g--;
            }
            d=broj_dana[m-1];
        }
        datum_p.Postavi(d,m,g);
    }


    std::string DajImePacijenta() const {
        return ime_p;
    }
    Datum DajDatumPacijenta() const {
        return datum_p;
    }
    Vrijeme DajVrijemePacijenta() const {
        return vrijeme_p;
    }

    static bool DolaziPrije (const Pregled &p1, const Pregled &p2) {
        if (std::get<2>(p1.datum_p.Ocitaj()) == std::get<2>(p2.datum_p.Ocitaj())) {
            if(std::get<1>(p1.datum_p.Ocitaj()) == std::get<1>(p2.datum_p.Ocitaj())) {
                if (std::get<0>(p1.datum_p.Ocitaj()) == std::get<0>(p2.datum_p.Ocitaj())) {
                    if(p1.vrijeme_p.Ocitaj().first == p2.vrijeme_p.Ocitaj().first ) {
                        if(p1.vrijeme_p.Ocitaj().second < p2.vrijeme_p.Ocitaj().second ) return true;
                        else return false;
                    }
                    return p1.vrijeme_p.Ocitaj().first < p2.vrijeme_p.Ocitaj().first;
                }
                return std::get<0>(p1.datum_p.Ocitaj()) < std::get<0>(p2.datum_p.Ocitaj());
            }
            return std::get<1>(p1.datum_p.Ocitaj()) < std::get<1>(p2.datum_p.Ocitaj());

        }
        return std::get<2>(p1.datum_p.Ocitaj()) < std::get<2>(p2.datum_p.Ocitaj());
    }


    void Ispisi() const {
        std::cout<< std::left << std::setw(30) <<std::setfill(' ') <<DajImePacijenta();
        DajDatumPacijenta().Ispisi();
        std::cout<<" ";
        DajVrijemePacijenta().Ispisi();
        std::cout<<std::endl;
    }

};

class Pregledi
{

    int max_broj_pregleda;
    int broj_pregleda;
    Pregled **pregledi;

    static bool JednakiDatumi(Datum d1, Datum d2) {
        if(std::get<0>(d1.Ocitaj())==std::get<0>(d2.Ocitaj()) && std::get<1>(d1.Ocitaj())==std::get<1>(d2.Ocitaj()) &&
                std::get<2>(d1.Ocitaj())==std::get<2>(d2.Ocitaj())) return true;
        return false;
    }
    static bool JednakaVremena(Vrijeme v1, Vrijeme v2) {
        if(v1.Ocitaj().first == v2.Ocitaj().first && v1.Ocitaj().second == v2.Ocitaj().second) return true;
        return false;
    }

public:
    explicit Pregledi (int max_broj_p) :  max_broj_pregleda(max_broj_p), broj_pregleda(0), pregledi(new Pregled *[max_broj_p] {}) {}

    Pregledi (std::initializer_list<Pregled> spisak_pregleda) : max_broj_pregleda(spisak_pregleda.size()),
        broj_pregleda(spisak_pregleda.size()), pregledi(new Pregled *[spisak_pregleda.size()] {}) {
        try {
            int i(0);
            for(auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++) {
                pregledi[i]=new Pregled(*it);
                i++;
            }
        } catch(...) {
            for(int i=0; i<broj_pregleda; i++) delete pregledi[i];
            delete[] pregledi;
            pregledi=nullptr;
            throw;
        }
    }

    ~Pregledi() {
        for(int i=0; i<broj_pregleda; i++) delete pregledi[i];
        delete[] pregledi;
        pregledi = nullptr;
    }

    Pregledi(const Pregledi &p) : pregledi(new Pregled *[p.max_broj_pregleda] {}), max_broj_pregleda(p.max_broj_pregleda),
    broj_pregleda(p.broj_pregleda) {
        try {
            for(int i=0; i<p.broj_pregleda; i++)
                pregledi[i]=new Pregled(*p.pregledi[i]);
        } catch(...) {
            for(int i=0; i<p.broj_pregleda; i++) delete pregledi[i];
            delete[] pregledi;
            pregledi=nullptr;
            throw;
        }
    }

    Pregledi(Pregledi &&p) : pregledi(p.pregledi), max_broj_pregleda(p.max_broj_pregleda), broj_pregleda(p.broj_pregleda) {
        p.pregledi=nullptr;
        p.broj_pregleda=0;
    }

    Pregledi &operator=(const Pregledi &p) {
        if(p.broj_pregleda>=broj_pregleda) {
            try {
                for(int i=broj_pregleda; i<p.broj_pregleda; i++)
                    pregledi[i]=new Pregled(*p.pregledi[i]);
            } catch(...) {
                for(int i=broj_pregleda; i<p.broj_pregleda; i++) {
                    delete pregledi[i];
                    pregledi[i]=nullptr;
                }
                throw;
            }
        } else {
            for(int i=p.broj_pregleda; i<broj_pregleda; i++) {
                delete pregledi[i];
                pregledi[i]=nullptr;
            }
        }
        broj_pregleda=p.broj_pregleda;
        for(int i=0; i<broj_pregleda; i++) *pregledi[i]=*p.pregledi[i];
        return *this;
    }

    Pregledi &operator = (Pregledi &&p) {
        std::swap(broj_pregleda, p.broj_pregleda);
        std::swap(pregledi, p.pregledi);
        p.pregledi=nullptr;
        p.broj_pregleda=0;
        return *this;
    }

    void RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        if(broj_pregleda>=max_broj_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
        pregledi[broj_pregleda++] = new Pregled(Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda));

        std::sort (pregledi, pregledi+broj_pregleda, [](Pregled *p1, Pregled *p2) {
            return Pregled::DolaziPrije(*p1, *p2);
        });
    }

    void RegistrirajPregled (const std::string &ime_pacijenta, int d, int m, int g, int sati, int minute) {
        if(broj_pregleda>=max_broj_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
        pregledi[broj_pregleda++] =new Pregled(Pregled(ime_pacijenta, Datum(d,m,g), Vrijeme(sati,minute)));

        std::sort (pregledi, pregledi+broj_pregleda, [](Pregled *p1, Pregled *p2) {
            return Pregled::DolaziPrije(*p1, *p2);
        });
    }

    void RegistrirajPregled(Pregled *p) {
        if(broj_pregleda>=max_broj_pregleda) {
            delete p;
            throw std::range_error ("Dostignut maksimalni broj pregleda");
        }
        pregledi[broj_pregleda++] = p;

        std::sort (pregledi, pregledi+broj_pregleda, [](Pregled *p1, Pregled *p2) {
            return Pregled::DolaziPrije(*p1, *p2);
        });
    }

    int DajBrojPregleda() const {
        return broj_pregleda;
    }
    int DajBrojPregledaNaDatum(const Datum &d) const {
        return std::count_if(pregledi, pregledi+broj_pregleda, [d](Pregled *pok) {
            if(JednakiDatumi(pok->DajDatumPacijenta(), d)) return true;
            return false;
        });
    }

    Pregled &DajNajranijiPregled() {
        if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
        auto pregled = std::min_element(pregledi, pregledi+broj_pregleda, [](Pregled *p1, Pregled *p2) {
            return Pregled::DolaziPrije(*p1, *p2);
        });
        return **pregled;
    }

    Pregled DajNajranijiPregled() const {
        if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
        auto pregled= std::min_element(pregledi, pregledi+broj_pregleda, [](Pregled *p1, Pregled *p2) {
            return Pregled::DolaziPrije(*p1, *p2);
        });
        return **pregled;

    }

    void IsprazniKolekciju() {
        for(int i=0; i<broj_pregleda; i++) {
            delete pregledi[i];
            pregledi[i]=nullptr;
        }
        broj_pregleda=0;
    }

    void ObrisiNajranijiPregled() {
        if(broj_pregleda==0) throw std::range_error("Prazna kolekcija");
        for(int i=0; i<broj_pregleda; i++) {
            if(JednakiDatumi(pregledi[i]->DajDatumPacijenta(),DajNajranijiPregled().DajDatumPacijenta()) &&
                    JednakaVremena(pregledi[i]->DajVrijemePacijenta(), DajNajranijiPregled().DajVrijemePacijenta())) {
                delete pregledi[i];
                pregledi[i]=nullptr;
                for(int j=i; j<broj_pregleda-1; j++) pregledi[j]=pregledi[j+1];
                broj_pregleda--;

            }
        }
        std::sort (pregledi, pregledi+broj_pregleda, [](Pregled *p1, Pregled *p2) {
            return Pregled::DolaziPrije(*p1, *p2);
        });
    }


    void ObrisiPregledePacijenata(const std::string &ime_pacijenta) {
        for(int i=0; i<broj_pregleda; i++) {
            if(pregledi[i]->DajImePacijenta() == ime_pacijenta) {
                delete pregledi[i];
                pregledi[i]=nullptr;
                for(int j=i; j<broj_pregleda-1; j++) pregledi[j]=pregledi[j+1];
                broj_pregleda--;
            }
        }
        std::sort (pregledi, pregledi+broj_pregleda, [](Pregled *p1, Pregled *p2) {
            return Pregled::DolaziPrije(*p1, *p2);
        });
    }


    void IspisiPregledeNaDatum(const Datum &d) const {

        for (int i=0; i<broj_pregleda; i++) {
            if(JednakiDatumi(pregledi[i]->DajDatumPacijenta(), d)) pregledi[i]->Ispisi();
        }
    }

    void IspisiSvePreglede() const {

        for (int i=0; i<broj_pregleda; i++) {
            pregledi[i]->Ispisi();
        }
    }

};



int main()
{
    
    int broj_pregleda;
    std::cout<<"Unesite maksimalan broj pregleda: ";
    std::cin>>broj_pregleda;
    Pregledi p(broj_pregleda);
    for(int i=0; i<broj_pregleda; i++) {
        std::string ime_pacijenta;
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, ime_pacijenta);
        if(ime_pacijenta=="kraj") break;
        int dan, mjesec, godina, sati, minute;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        std::cin>>dan >>mjesec>> godina;
        std::cout<<"Unesite sate i minute pregleda: ";
        std::cin>>sati>>minute;
        p.RegistrirajPregled(ime_pacijenta, dan, mjesec, godina, sati, minute);
    }

    std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
    p.IspisiSvePreglede();
    std::cout<<std::endl;

    do {
        int opcija;
        std::cout<<"Odaberite jednu od sljedecih opcija"<<std::endl<<
                 "1 - Broj pregleda na datum"<<std::endl<<"2 - Najraniji pregled"<<std::endl<<"3 - Obrisi pregled pacijenta"<<std::endl<<"4 - Obrisi najraniji pregled"<<std::endl<<"5 - Ispisi sve pregleda na datum"<<std::endl<<"6 - Ispisi sve preglede"<<std::endl<<"7 - Kraj programa"<<std::endl;
        std::cin>>opcija;
        if(opcija==1) {
            int d, m, g;
            std::cout<<"Unesite dan mjesec i godinu : ";
            std::cin>>d>>m>>g;
            std::cout<<"Broj pregleda na datum "<< d <<" "<<m<<" "<<g<<" je: "<< p.DajBrojPregledaNaDatum(Datum(d,m,g))<<std::endl;
        } else if(opcija==2) {
            std::cout<<"Najraniji pregled je:"<<std::endl;
            p.DajNajranijiPregled().Ispisi();
        } else if(opcija==3) {
            std::string ime;
            std::cout<<"Unesite ime pacijenta: ";
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, ime);
            int brojpregleda(p.DajBrojPregleda());
            p.ObrisiPregledePacijenata(ime);
            std::cout<<"Uspjesno obrisano "<<brojpregleda - p.DajBrojPregleda()<<" pregleda" << std::endl;
        } else if (opcija==4) {
            p.ObrisiNajranijiPregled();
            std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
        } else if(opcija==5) {
            int d, m, g;
            std::cout<<"Unesite dan mjesec i godinu : ";
            std::cin>>d>>m>>g;
            std::cout<<"Pregledi na datum "<< d <<" "<<m<<" "<<g<<" su:"<<std::endl;
            p.IspisiPregledeNaDatum(Datum(d,m,g));

        } else if(opcija==6) p.IspisiSvePreglede();
        else if(opcija == 7) break;
        std::cout<<std::endl;
    } while(1);



    return 0;
}
