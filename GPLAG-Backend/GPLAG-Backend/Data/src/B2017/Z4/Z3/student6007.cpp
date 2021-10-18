#include <iostream>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <string>
#include <memory>
#include <vector>

//KLASA "Datum":
class Datum
{
    int dan, mjesec, godina;
public:

    Datum(int dan, int mjesec, int godina) {
        Postavi(dan,mjesec,godina);
    }

    void Postavi(int dan, int mjesec, int godina) {
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0)) broj_dana[1]++;
        if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec-1])
            throw std::domain_error("Naispravan datum");

        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
    }

    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(dan,mjesec,godina);
    }

    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

//KLASA "Vrijeme":
class Vrijeme
{
    int sati, minute;
public:

    Vrijeme(int sati, int minute) {
        Postavi(sati,minute);
    }

    void Postavi(int sati, int minute) {
        if(sati < 0 || sati > 23 || minute < 0 || minute > 59) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati = sati;
        Vrijeme::minute = minute;
    }

    std::pair<int, int> Ocitaj() const {
        return std::make_pair(sati,minute);
    }
    void Ispisi() const {
        std::cout << std::setw(2) << std::right <<std::setfill('0') << sati << ":" << std::setw(2)
                  << std::right << std::setfill('0') << minute;
    }
};
//KLASA Pregled
class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda {1,1,2000};
    Vrijeme vrijeme_pregleda {0,0};
public:

    //Deklaracija i implementacija konstruktora
    Pregled(const std::string &Ime_pacijenta, const Datum &Datum_pregleda, const Vrijeme &Vrijeme_pregleda) {

        datum_pregleda = Datum_pregleda;
        vrijeme_pregleda = Vrijeme_pregleda;
        ime_pacijenta = Ime_pacijenta;
    }

    //Deklaracija i implementacija konstruktora
    Pregled(const std::string &Ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
            int sati_pregleda, int minute_pregleda):

        datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda),
        vrijeme_pregleda(sati_pregleda,minute_pregleda) {
        ime_pacijenta = Ime_pacijenta;
    }

    //Deklaracija metode PromijeniPacijenta
    void PromijeniPacijenta(const std::string &ime_pacijenta);

    //Deklaracija metode PromijeniDatum
    void PromijeniDatum(const Datum &novi_datum);

    //Deklaracija metode PromijeniVrijeme
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);

    //Deklaracija metode PomjeriDanUnaprijed
    void PomjeriDanUnaprijed();

    //Deklaracija metode PomjeriDanUnazad
    void PomjeriDanUnazad();

    //Deklaracija metode DajImePacijenta
    std::string DajImePacijenta() const;

    //Deklaracija metode DajDatumPregleda
    Datum DajDatumPregleda() const;

    //Deklaracija metode DajVrijemePregleda
    Vrijeme DajVrijemePregleda() const;

    //Deklaracija i implementacija metode DolaziPrije
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        if(std::get<2>(p1.DajDatumPregleda().Ocitaj()) < std::get<2>(p2.DajDatumPregleda().Ocitaj())) return true;
        else if(std::get<2>(p1.DajDatumPregleda().Ocitaj()) > std::get<2>(p2.DajDatumPregleda().Ocitaj())) return false;
        else {
            if(std::get<1>(p1.DajDatumPregleda().Ocitaj()) < std::get<1>(p2.DajDatumPregleda().Ocitaj())) return true;
            else if(std::get<1>(p1.DajDatumPregleda().Ocitaj()) > std::get<1>(p2.DajDatumPregleda().Ocitaj())) return false;
            else {
                if(std::get<0>(p1.DajDatumPregleda().Ocitaj()) < std::get<0>(p2.DajDatumPregleda().Ocitaj())) return true;
                else if(std::get<0>(p1.DajDatumPregleda().Ocitaj()) > std::get<0>(p2.DajDatumPregleda().Ocitaj())) return false;
                else {
                    if(std::get<0>(p1.DajVrijemePregleda().Ocitaj()) < std::get<0>(p2.DajVrijemePregleda().Ocitaj())) return true;
                    else if(std::get<0>(p1.DajVrijemePregleda().Ocitaj()) > std::get<0>(p2.DajVrijemePregleda().Ocitaj())) return false;
                    else {
                        if(std::get<1>(p1.DajVrijemePregleda().Ocitaj()) < std::get<1>(p2.DajVrijemePregleda().Ocitaj())) return true;
                    }
                }
            }
        }
        return false;
    }
    //Deklaracija metode Ispisi
    void Ispisi() const;
};
//Implementacija metode PromijeniPacijenta
void Pregled::PromijeniPacijenta(const std::string &ime_pacijenta)
{
    Pregled::ime_pacijenta = ime_pacijenta;
}
//Implementacija metode PromijeniDatum
void Pregled::PromijeniDatum(const Datum &novi_datum)
{
    Pregled::datum_pregleda = novi_datum;
}
//Implementacija metode PromijeniVrijeme
void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme)
{
    Pregled::vrijeme_pregleda = novo_vrijeme;
}
//Implementacija metode PomjeriDanUnaprijed
void Pregled::PomjeriDanUnaprijed()
{
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    int d, m, g;
    std::tie(d, m, g) = datum_pregleda.Ocitaj();
    if(g % 4 == 0 && (g % 100 != 0 || g % 400 == 0)) broj_dana[1]++;
    d++;
    if(d > broj_dana[m-1]) {
        m++;
        d = 1;
    }

    if(m > 12) {
        m = 1;
        g++;
    }
}
//Implementacija metode PomjeriDanUnazad
void Pregled::PomjeriDanUnazad()
{
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    int d, m, g;
    std::tie(d, m, g) = datum_pregleda.Ocitaj();
    if(g % 4 == 0 && (g % 100 != 0 || g % 400 == 0)) broj_dana[1]++;
    d--;
    if(d <= 0) {
        m--;
        d = broj_dana[m-1];
    }
    if(m < 1) {
        m = 12;
        g--;
    }
}
//Implementacija metode DajImePacijenta
std::string Pregled::DajImePacijenta() const
{
    return ime_pacijenta;
}
//Implementacija metode DajDatumPregleda
Datum Pregled::DajDatumPregleda() const
{
    return datum_pregleda;
}
//Implementacija metode DajVrijemePregleda
Vrijeme Pregled::DajVrijemePregleda() const
{
    return vrijeme_pregleda;
}
//Implementacija metode Ispisi
void Pregled::Ispisi() const
{
    std::cout << std::setw(30) << std::left << std::setfill(' ') << ime_pacijenta;
    datum_pregleda.Ispisi();
    std::cout << " ";
    vrijeme_pregleda.Ispisi();
    std::cout << std::endl;
}

//KLASA "Pregledi":
class Pregledi
{
    const int max_broj_pregleda;
    Pregled **p;
    int broj_pregleda;
public:

    //Implementacija konstruktora sa jednim parametrom
    explicit Pregledi(int max_broj_pregleda): max_broj_pregleda(max_broj_pregleda),
        p(new Pregled*[max_broj_pregleda]), broj_pregleda(0) {}

    //Deklaracija sekvencijskog konstruktora
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);

    //Deklaracija destruktora
    ~Pregledi();

    //Deklaracija kopirajuceg konstruktora
    Pregledi(const Pregledi &pregledi);

    //Deklaracija pomjerajuceg konstruktora
    Pregledi(Pregledi &&pregledi);

    //Deklaracija kopirajuceg operatora dodjele
    Pregledi &operator = (const Pregledi &pregledi);

    //Deklaracija pomjerajuceg operatora dodjele
    Pregledi &operator =(Pregledi &&pregledi);

    //Deklaracija metode RegistrirajPregled
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);

    //Deklaracija metode RegistrirajPregled
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda ,
                            int sati_pregleda, int minute_pregleda);

    //Deklaracija metode RegistrirajPregled
    void RegistrirajPregled(Pregled *pregled);

    //Deklaracija metode DajBrojPregleda
    int DajBrojPregleda() const;

    //Deklaracija metode DajBrojPregledaNaDatum
    int DajBrojPregledaNaDatum(const Datum &datum) const;

    //Deklaracija metode DajNajranijiPregled
    Pregled &DajNajranijiPregled();

    //Deklaracija metode DajNajranijiPregled
    Pregled DajNajranijiPregled() const;

    //Deklaracija metode IsprazniKolekciju
    void IsprazniKolekciju();

    //Deklaracija metode ObrisiNajranijiPregled
    void ObrisiNajranijiPregled();

    //Deklaracija metode ObrisiPregledePacijenata
    void ObrisiPregledePacijenata(const std::string &ime_pacijenta);

    //Deklaracija metode IspisiPregledeNaDatum
    void IspisiPregledeNaDatum(const Datum &datum) const;

    //Deklaracija metode IspisiSvePreglede
    void IspisiSvePreglede() const;
};

//Implementacija sekvencijskog konstruktora
Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda):
    broj_pregleda(spisak_pregleda.size()), p(new Pregled*[spisak_pregleda.size()]),
    max_broj_pregleda(spisak_pregleda.size())
{
    try {
        for(int i = 0; i < spisak_pregleda.size(); i++) {
            p[i] = new Pregled(spisak_pregleda.begin()[i]);
        }
    } catch(...) {
        for(int i = 0; i < spisak_pregleda.size(); i++) delete p[i];
        delete[] p;
        throw;
    }
}

//Implementacija destruktora
Pregledi::~Pregledi()
{
    for(int i = 0; i < broj_pregleda; i++) delete p[i];
    delete [] p;
}

//Implementacija kopirajuceg konstruktora
Pregledi::Pregledi(const Pregledi &pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda),
    p(new Pregled*[pregledi.broj_pregleda]), broj_pregleda(pregledi.broj_pregleda)
{
    try {
        for(int i = 0; i < pregledi.broj_pregleda; i++) {
            p[i] = new Pregled(*pregledi.p[i]);
        }
    } catch(...) {
        for(int i = 0; i < pregledi.broj_pregleda; i++) delete p[i];
        delete p;
        throw;
    }
}
//Implementacija pomjerajuceg konstruktora
Pregledi::Pregledi(Pregledi &&pregledi): max_broj_pregleda(pregledi.max_broj_pregleda),
    p(pregledi.p),broj_pregleda(pregledi.broj_pregleda)
{
    for(int i = 0; i < pregledi.broj_pregleda; i++) {
        pregledi.p[i] = nullptr;
    }
}
//Implementacija kopirajuceg operatora dodjele
Pregledi &Pregledi::operator = (const Pregledi &pregledi)
{
    if(broj_pregleda < pregledi.broj_pregleda) {
        Pregled **novi_prostor(new Pregled*[pregledi.broj_pregleda]);
        for(int i = 0; i < pregledi.broj_pregleda; i++) {
            novi_prostor[i] = pregledi.p[i];
        }

        for(int i = 0; i < broj_pregleda; i++) delete p[i];
        delete[] p;
        p = novi_prostor;
    }
    broj_pregleda = pregledi.broj_pregleda;
    for(int i = 0; i < broj_pregleda; i++) {
        pregledi.p[i] = p[i];
    }
    return *this;
}
//Implementacija pomjerajuceg operatora dodjele
Pregledi &Pregledi::operator =(Pregledi &&pregledi)
{
    std::swap(broj_pregleda, pregledi.broj_pregleda);
    std::swap(p,pregledi.p);

    return *this;
}
//Implementacija metode RegistrirajPregled
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    if(broj_pregleda >= max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    p[broj_pregleda++] = new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
}
//Implementacija metode RegistrirajPregled
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
                                  int godina_pregleda, int sati_pregleda, int minute_pregleda)
{

    if(broj_pregleda >= max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    p[broj_pregleda++] = new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,
                                     godina_pregleda, sati_pregleda,minute_pregleda);

}
//Implementacija metode RegistrirajPregled
void Pregledi::RegistrirajPregled(Pregled *pregled)
{
    if(broj_pregleda >= max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    p[broj_pregleda++] = pregled;
}
//Implementacija metode DajBrojPregleda
int Pregledi::DajBrojPregleda() const
{
    return broj_pregleda;
}

//Implementacija metode DajBrojPregledaNaDatum
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    int broj =  std::count_if(p,p + broj_pregleda,[datum](Pregled *pok) {
        return (std::get<0>(datum.Ocitaj()) == std::get<0>(pok->DajDatumPregleda().Ocitaj())
                && std::get<1>(datum.Ocitaj()) == std::get<1>(pok->DajDatumPregleda().Ocitaj())
                && std::get<2>(datum.Ocitaj()) == std::get<2>(pok->DajDatumPregleda().Ocitaj()));
    });
    return broj;
}

//Implementacija metode DajNajranijiPregled
Pregled &Pregledi::DajNajranijiPregled()
{
    if(broj_pregleda == 0) throw std::domain_error("Nema registriranih pregleda");
    return (**(std::min_element(p,p + broj_pregleda, [](Pregled *p1, Pregled *p2) {
        return (Pregled::DolaziPrije(*p1,*p2));

    })));
}

//Implementacija metode DajNajranijiPregled
Pregled Pregledi::DajNajranijiPregled() const
{
    if(broj_pregleda == 0) throw std::domain_error("Nema registriranih pregleda");
    return (**(std::min_element(p,p + broj_pregleda, [](Pregled *p1, Pregled *p2) {
        return (Pregled::DolaziPrije(*p1,*p2));
    })));
}
//Implementacija metode IsprazniKolekciju
void Pregledi::IsprazniKolekciju()
{
    for(int i = 0; i < broj_pregleda; i++) delete p[i];
    delete[] p;
    broj_pregleda = 0;
}
//Implementacija metode ObrisiNajranijiPregled
void Pregledi::ObrisiNajranijiPregled()
{
    if(broj_pregleda == 0) throw std::range_error("Prazna kolekcija");
    for(int i = 0; i < broj_pregleda; i++) {
        if (std::get<0>(p[i]->DajDatumPregleda().Ocitaj()) == std::get<0>(DajNajranijiPregled().DajDatumPregleda().Ocitaj()) &&
                std::get<1>(p[i]->DajDatumPregleda().Ocitaj()) == std::get<1>(DajNajranijiPregled().DajDatumPregleda().Ocitaj()) &&
                std::get<2>(p[i]->DajDatumPregleda().Ocitaj()) == std::get<2>(DajNajranijiPregled().DajDatumPregleda().Ocitaj())) {
            delete p[i];
            p[i] = nullptr;
            std::swap(p[i],p[broj_pregleda-1]);
            broj_pregleda--;
            break;
        }

    }
}
//Implementacija metode ObrisiPregledePacijenata
void Pregledi::ObrisiPregledePacijenata(const std::string &ime_pacijenta)
{
    for(int i = 0; i < broj_pregleda; i++) {
        if(p[i]->DajImePacijenta() == ime_pacijenta) {
            delete p[i];
            p[i] = nullptr;
            std::swap(p[i],p[broj_pregleda-1]);
            broj_pregleda--;
        }
    }
}
//Implementacija metode IspisiPregledeNaDatum
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{

    for(int i = 0; i < broj_pregleda; i++) {
        if(std::get<0>(p[i]->DajDatumPregleda().Ocitaj()) == std::get<0>(datum.Ocitaj()) &&
                std::get<1>(p[i]->DajDatumPregleda().Ocitaj()) == std::get<1>(datum.Ocitaj()) &&
                std::get<2>(p[i]->DajDatumPregleda().Ocitaj()) == std::get<2>(datum.Ocitaj()))
            p[i]->Ispisi();
    }
}
//Implementacija metode IspisiSvePreglede
void Pregledi::IspisiSvePreglede() const
{
    if(broj_pregleda == 0) return;
    std::vector<int> Pozicije(broj_pregleda);
    int j(0);
    while(j < broj_pregleda) {
        int index(0);
        int i(0);
        while(i < broj_pregleda) {
            if(i == j) {
                i++;
                continue;
            }
            if(Pregled::DolaziPrije(*p[j],*p[i]) == false) index++;
            i++;
        }
        Pozicije[index] = j;
        j++;
    }
    int k(0);
    while(k < broj_pregleda) {
        p[Pozicije[k]]->Ispisi();
        k++;
    }
}
int main ()
{
    std::cout << "Unesite maksimalan broj pregleda: ";
    int maksimalan_broj_pregleda;
    int broj_pregleda(0);
    std::cin >> maksimalan_broj_pregleda;
    std::string name;
    std::string kraj("kraj");
    std::vector<Pregled*> V;
    Pregledi P(maksimalan_broj_pregleda);
    while(1) {
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::cin.ignore(10000,'\n');
        std::getline(std::cin,name);
        if(name == kraj) break;
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        int dan, mjesec, godina;
        std::cin >> dan >> mjesec >> godina;
        try {
            Datum d(dan,mjesec,godina);
        } catch(std::domain_error e6) {
            std::cout << e6.what() << std::endl;
            return 0;
        }
        std::cout << "Unesite sate i minute pregleda: ";
        int sati, minute;
        std::cin >> sati >> minute;
        try {
            Vrijeme v(sati,minute);
        } catch(std::domain_error e7) {
            std::cout << e7.what() << std::endl;
            return 0;
        }
        try {
            V.push_back(new Pregled(name, {dan,mjesec,godina}, {sati,minute}));
        } catch(std::bad_alloc) {
            for(int i = 0; i < V.size(); i++) delete V[i];
            std::cout << "Problemi s memorijom" << std::endl;
            return 0;
        }
        broj_pregleda++;
        try {
            P.RegistrirajPregled(name,dan,mjesec,godina,sati,minute);
        } catch(std::range_error e2) {
            std::cout << e2.what() << std::endl;
            return 0;
        }
        if(broj_pregleda == maksimalan_broj_pregleda) break;
    }
    std::cout << "Trenutno su registrovani sljedeci pregledi\n";
    P.IspisiSvePreglede();
    int n(0);
    while(n != 7) {
        std::cout << "Odaberite jednu od sljedecih opcija\n";
        std::cout << "1 - Broj pregleda na datum\n";
        std::cout << "2 - Najraniji pregled\n";
        std::cout << "3 - Obrisi pregled pacijenta\n";
        std::cout << "4 - Obrisi najraniji pregled\n";
        std::cout << "5 - Ispisi sve pregleda na datum\n";
        std::cout << "6 - Ispisi sve preglede\n";
        std::cout << "7 - Kraj programa\n";
        std::cin >> n;
        if(n == 7) break;
        switch(n) {
        case 1: {
            std::cout << "Unesite dan mjesec i godinu : ";
            int dan,mjesec,godina;
            std::cin >> dan >> mjesec >> godina;
            try {
                P.DajBrojPregledaNaDatum(Datum(dan,mjesec,godina));
            } catch(std::domain_error e5) {
                std::cout << e5.what() << std::endl;
                return 0;
            }
            std::cout << "Broj pregleda na datum " << dan << " " << mjesec << " " << godina << " je: ";
            std::cout << P.DajBrojPregledaNaDatum(Datum(dan,mjesec,godina)) << std::endl;

            break;
        }
        case 2: {
            try {
                P.DajNajranijiPregled();
            } catch(std::domain_error e3) {
                std::cout << e3.what() << std::endl;
                return 0;
            }
            std::cout << "Najraniji pregled je:\n";
            P.DajNajranijiPregled().Ispisi();
            std::cout << std::endl;
            break;
        }
        case 3: {
            std::cout << "Unesite ime pacijenta: ";
            std::string ime1;
            std::cin.ignore(10000,'\n');
            std::getline(std::cin,ime1);
            int br_pr(P.DajBrojPregleda());
            P.ObrisiPregledePacijenata(ime1);
            std::cout << "Uspjesno obrisano " << br_pr - P.DajBrojPregleda() << " pregleda\n";
            break;
        }
        case 4: {
            try {
                P.ObrisiNajranijiPregled();
            } catch(std::range_error e4) {
                std::cout << e4.what() << std::endl;
                return 0;
            }
            std::cout << "Najraniji pregled uspjesno obrisan\n";
            break;
        }
        case 5: {
            std::cout << "Unesite dan mjesec i godinu : ";
            int dan, mjesec, godina;
            std::cin >> dan >> mjesec >> godina;
            std::cout << "Pregledi na datum " << dan << " " << mjesec << " " << godina << " su:\n";
            P.IspisiPregledeNaDatum(Datum(dan,mjesec,godina));
            break;
        }
        case 6: {
            P.IspisiSvePreglede();
            break;
        }
        }
    }
    for(int i = 0; i < V.size(); i++) delete V[i];
    return 0;
}
