#include <iostream>
#include <type_traits>
#include <iterator>
#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <type_traits>
#include <memory>
#include <stdexcept>
#include <string>
#include <new>
#include <utility>
#include <cstdlib>



/*static std::size_t brAlokacija(0);
static std::size_t maksimalanBrojAlokacijaPregleda(2000);
static std::size_t ukupanBrojAlociranihPregleda(0);

static bool ukljuciProvjeruAlokacijePregleda(false);
static bool ukljuciZabranuAlokacija(false);

void *operator new(std::size_t velicina){
    if(ukljuciProvjeruAlokacijePregleda && ++ukupanBrojAlociranihPregleda > maksimalanBrojAlokacijaPregleda )
        throw std::bad_alloc();
    if(ukljuciZabranuAlokacija)
        throw "Nije dozvoljna dodatna alokacija!";
    brAlokacija++;
    return std::malloc(velicina);
}

void *operator new[](std::size_t velicina){
    if(ukljuciZabranuAlokacija)
        throw "Nije dozvoljna dodatna alokacija!";
    ++brAlokacija;
    return std::malloc(velicina);

}


void operator delete(void *adresa) noexcept {
    --brAlokacija;
    std::free(adresa);
}

void operator delete[](void *adresa) noexcept {
    --brAlokacija;
    std::free(adresa);
}

void OgraniciBrojAlokacija(size_t maksAlokacija){
    ukljuciProvjeruAlokacijePregleda = (maksAlokacija != 0);
    maksimalanBrojAlokacijaPregleda = maksAlokacija;
}

void ZabraniAlokaciju(bool zabrana){
    ukljuciZabranuAlokacija = zabrana;
}

void ProvjeriCurenje(){
    if(brAlokacija == 0)
        std::cout << "\nNema curenja!";
    else
        std::cout << "\nCurenje memorije, broj neobrisanih alokacija: "<< brAlokacija << std::endl;
}*/

class Datum {
    int dan, mjesec, godina;
    std::vector<int> VektorDana(int godina){
        std::vector<int> v{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina % 4 == 0 && godina % 100 != 0) || ( godina % 400 == 0))
            v[1]++;
        return v;
    }
public:
    Datum(int dan, int mjesec, int godina){
        Postavi(dan, mjesec, godina);
    }
    void Postavi(int dan, int mjesec, int godina){
        auto v(VektorDana(godina));
        if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > v[mjesec-1])
        {
            throw std::domain_error("Neispravan datum");
        }
        this->dan = dan; this->mjesec = mjesec; this->godina = godina;
    }
    std::tuple<int, int, int> Ocitaj() const{
        return std::make_tuple(dan, mjesec, godina);
    };
    void Ispisi() const{
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

class Vrijeme {
    int sati, minute;
public:
    Vrijeme(int sati, int minute){
        Postavi(sati, minute);
    }
    void Postavi(int sati, int minute){
        if(sati < 0 ||  sati > 23 || minute < 0 || minute > 59)
            throw std::domain_error("Neispravno vrijeme");
        this->sati = sati; this->minute = minute;
    }
    std::pair<int, int> Ocitaj() const{
        std::make_pair(sati, minute);
    };

    void Ispisi() const{
        if(sati < 10) std::cout << "0";
        std::cout << sati;
        std::cout << ":";
        if(minute < 10) std::cout << "0";
        std::cout << minute;
    }
};
class Pregled {
    std::string imePacijenta;
    Datum datumPregleda;
    Vrijeme vrijemePregleda;
    std::vector<int> VektorDana(int godina){
        std::vector<int> v{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina % 4 == 0 && godina % 100 != 0) || ( godina % 400 == 0))
            v[1]++;
        return v;
    }
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
            : datumPregleda(datum_pregleda), vrijemePregleda(vrijeme_pregleda), imePacijenta(ime_pacijenta) {}

    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
            int sati_pregleda, int minute_pregleda) : datumPregleda(dan_pregleda, mjesec_pregleda, godina_pregleda),
                                                      vrijemePregleda(sati_pregleda, minute_pregleda),
                                                      imePacijenta(ime_pacijenta){}


    void PromijeniPacijenta(const std::string &ime_pacijenta) {imePacijenta = ime_pacijenta; }

    void PromijeniDatum(const Datum &novi_datum) { datumPregleda = novi_datum; }

    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {vrijemePregleda = novo_vrijeme;}

    void PomjeriDanUnaprijed(){
        int d, m, g;
        auto datum(datumPregleda.Ocitaj());
        std::tie(d, m, g) = datum;
        auto v(VektorDana(g));
        d++;
        if(d > v[m-1])
            d = 1, m++;
        if(m > 12)
            m = 1, g++;
        datumPregleda.Postavi(d, m, g);
    }

    void PomjeriDanUnazad(){
        int d, m, g;
        auto datum(datumPregleda.Ocitaj());
        std::tie(d, m, g) = datum;
        auto v(VektorDana(g));
        d--;
        if(d == 0) {
            m--;
            if (m == 0) {
                g--;
                m = 12;
                d = 31;
            } else {
                d = v[m - 1];
            }
        }
        datumPregleda.Postavi(d, m, g);
    }

    std::string DajImePacijenta() const { return imePacijenta;}

    Datum DajDatumPregleda() const { return datumPregleda; }

    Vrijeme DajVrijemePregleda() const {return vrijemePregleda;}

    static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
        int d1, m1, g1, sat1, min1, d2, m2, g2, sat2, min2;
        std::tie(d1, m1, g1) = p1.datumPregleda.Ocitaj();
        std::tie(d2, m2, g2) = p2.datumPregleda.Ocitaj();
        sat1 = p1.DajVrijemePregleda().Ocitaj().first;
        min1 = p1.DajVrijemePregleda().Ocitaj().second;
        sat2 = p2.DajVrijemePregleda().Ocitaj().first;
        min2 = p2.DajVrijemePregleda().Ocitaj().second;
        if(g1 != g2)
            return g1 < g2;
        if(m1 != m2)
            return m1 < m2;
        if(d1 != d2)
            return d1 < d2;
        if(sat1 != sat2)
            return sat1 < sat2;
        return min1 < min2;

    }

    void Ispisi() const{
        std::cout << std::left << std::setw(30) << imePacijenta;
        datumPregleda.Ispisi();
        std::cout << " ";
        vrijemePregleda.Ispisi();
        std::cout << std::endl;
    }
};




class Pregledi{
    std::vector<std::shared_ptr<Pregled>> vektorPregleda;
    bool JednakiDatumi(Datum dat1, Datum dat2) const{
        double d1, d2, m1, m2, g1, g2;
        std::tie(d1, m1, g1) = dat1.Ocitaj();
        std::tie(d2, m2, g2) = dat2.Ocitaj();
        return d1 == d2 && m1 == m2 && g1 == g2;
    }
public:
    explicit Pregledi() {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda)
    {
        for(auto pregled: spisak_pregleda)
            vektorPregleda.push_back(std::make_shared<Pregled>(pregled));
    }
    //destruktor ne treba

    Pregledi(const Pregledi &pregledi)
    {
        for(auto pregled : pregledi.vektorPregleda)
            vektorPregleda.push_back(std::make_shared<Pregled>(*pregled));

    }
    Pregledi(Pregledi &&pregledi) : vektorPregleda(std::move(pregledi.vektorPregleda)) {}

    Pregledi &operator=(const Pregledi &pregledi){
        if(&pregledi != this){//ovdje dodati autotest, moguce je da nece biti memorije za novi vektor
            //ne smiju uništiti izvorni
            std::vector<std::shared_ptr<Pregled>> pomocniVektor(pregledi.vektorPregleda.size());
            for(int i = 0; i < pomocniVektor.size(); i++){
                pomocniVektor[i] = std::make_shared<Pregled>(*pregledi.vektorPregleda[i]);
            }
            this->vektorPregleda = pomocniVektor;
        }
        return *this;
    }
    Pregledi &operator=(Pregledi && pregledi){//destruktivna samo dodjela ???
        if(&pregledi != this){
            vektorPregleda = std::move(pregledi.vektorPregleda);
        }
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        vektorPregleda.push_back(std::make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda));
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
                            int sati_pregleda, int minute_pregleda)
    {
        vektorPregleda.push_back(std::make_shared<Pregled>(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda));
    }
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled){
        vektorPregleda.push_back(pregled);
    }
    int DajBrojPregleda() const{
        return vektorPregleda.size();
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const{
        int broj =  std::count_if(vektorPregleda.begin(), vektorPregleda.end(), [&datum, this](std::shared_ptr<Pregled> p){
            return JednakiDatumi(datum, p->DajDatumPregleda());
        });
        if(broj == 0) throw std::domain_error("Nema registriranih pregleda");
        return broj;

    }
    Pregled &DajNajranijiPregled(){
        if(vektorPregleda.size() == 0)
            throw std::domain_error("Nema registriranih pregleda");
        return **std::min_element(vektorPregleda.begin(), vektorPregleda.end(), [](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2){
            return p1->DolaziPrije(*p1, *p2);
        });
    }
    Pregled DajNajranijiPregled() const{
        if(vektorPregleda.size() == 0)
            throw std::domain_error("Nema registriranih pregleda");
        return **std::min_element(vektorPregleda.begin(), vektorPregleda.end(), [](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2){
            return p1->DolaziPrije(*p1, *p2);
        });
    }
    void IsprazniKolekciju(){
        vektorPregleda.clear();
    }
    void ObrisiNajranijiPregled(){//pva funkcija ne bi smjela da alocita
        if(vektorPregleda.size() == 0)
            throw std::range_error("Prazna kolekcija");
        auto najraniji = std::min_element(vektorPregleda.begin(), vektorPregleda.end(),
                [](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) -> bool { return  p1->DolaziPrije(*p1, *p2); });
        vektorPregleda.erase(najraniji);
    }
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta){//ni ovdje ne bi smjelo biti dodatne alokacije, provjeriti da li pada kad se brise sve
        for(int i = 0; i< vektorPregleda.size(); i++)
        {
            if(vektorPregleda[i]->DajImePacijenta() == ime_pacijenta){
               vektorPregleda.erase(vektorPregleda.begin() + i);
               i--;
            }

        }
    }
    void IspisiPregledeNaDatum(const Datum &datum) const{

        std::vector<std::shared_ptr<Pregled>> pomocniVektor(vektorPregleda);
        std::sort(pomocniVektor.begin(), pomocniVektor.end(), [](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2){
            return p1->DolaziPrije(*p1, *p2);
        });

        for(auto pregled : pomocniVektor){
            if(JednakiDatumi(datum, pregled->DajDatumPregleda())){
                pregled->Ispisi();
            }
        }
    }
    void IspisiSvePreglede() const{
        std::vector<std::shared_ptr<Pregled>> pomocniVektor(vektorPregleda);
        std::sort(pomocniVektor.begin(), pomocniVektor.end(), [](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2){
            return p1->DolaziPrije(*p1, *p2);
        });

        for(auto pregled : pomocniVektor){
                pregled->Ispisi();
            }
        }



};

int main() {/*
    std::cout << "\n-----------\nAutotest 1\n-----------\n";

    {//AT1 (skriveni) Test klase Datum, Vrijeme i Pregled
        Datum d1(28,5,2017), d2(2,2,2018);
        Vrijeme v1(10,10), v2(12,12);
        Pregled p1("Lamija", d1, v1);
        Pregled p2("Amina", d2, v2);
        p1.Ispisi();
        p2.Ispisi();
        if(p1.DolaziPrije(p1, p2)){
            std::cout << "Lamija dolazi prije Amine\n";
        }
        else{
            std::cout << "Amina dolazi prije Lamije\n";
        }
    }
    std::cout << "\n-----------\nAutotest 2\n-----------\n";

    {//AT2 (skriveni) Test klase Datum neispravni parametri
        try {Datum d1(31, 1, 2017);} catch(std::domain_error &ex){std::cout << " NOT OK "; }
        try {Datum d1(32, 1, 2017);} catch(std::domain_error &ex){std::cout << " OK1 " << ex.what(); }
        try {Datum d1(29, 2, 2016);} catch(std::domain_error &ex){std::cout << " NOT OK "; }
        try {Datum d1(29, 2, 2015);} catch(std::domain_error &ex){std::cout << " OK2 " << ex.what(); }
        try {Datum d1(31, 12, 2016);} catch(std::domain_error &ex){std::cout << " NOT OK "; }
        try {Datum d1(31, 13, 2015);} catch(std::domain_error &ex){std::cout << " OK3 " << ex.what(); }
        try {Datum d1(30, 0, 2015);} catch(std::domain_error &ex){std::cout << " OK4 " << ex.what(); }
        std::cout << "\nEND";
    }

    std::cout << "\n-----------\nAutotest 3\n-----------\n";

    {//AT3 (skriveni) Test klase Datum, metode Postavi i Ispisi
        Datum d1(31,3,2016);
        try {d1.Postavi(32, 3, 2017);} catch(std::domain_error &ex){std::cout << "OK1 " << ex.what() << std::endl; }
        d1.Ispisi();

        d1.Postavi(31, 12, 2017);
        try {d1.Postavi(32, 12, 2017);} catch(std::domain_error &ex){std::cout << "\nOK2 " << ex.what() << std::endl; }
        d1.Ispisi();

        d1.Postavi(30, 11, 2018);
        try {d1.Postavi(31, 13, 2017);} catch(std::domain_error &ex){std::cout << "\nOK3 " << ex.what() << std::endl; }
        d1.Ispisi();

        std::cout << "\nEND";
    }

    std::cout << "\n-----------\nAutotest 4\n-----------\n";


    {//AT4 (skriveni) Test klase Datum i Vrijeme, metoda ocitaj
        Datum d1(30,8,2016);
        Vrijeme v1(1,1);
        std::tuple<int, int, int> d1Vrijednosti(d1.Ocitaj());
        std::pair<int, int> v1Vrijednosti(v1.Ocitaj());
        std::cout << std::get<0>(d1Vrijednosti) << " " << std::get<1>(d1Vrijednosti) << " " << std::get<2>(d1Vrijednosti)
                  << " " << v1Vrijednosti.first << " " << v1Vrijednosti.second;
        std::cout << "\nEND";
    }

    std::cout << "\n-----------\nAutotest 5\n-----------\n";


    {//AT5 (skriveni) Test klase Vrijeme neispravne vrijednosti
        try {Vrijeme v1(12,12);} catch(std::domain_error &ex){std::cout << " NOT OK "; }
        try {Vrijeme v1(24, 12);} catch(std::domain_error &ex){std::cout << " OK1 " << ex.what(); }
        try {Vrijeme v1(-1,12);} catch(std::domain_error &ex){std::cout << " OK2 " << ex.what(); }
        try {Vrijeme v1(12, -1);} catch(std::domain_error &ex){std::cout << " OK3 " << ex.what(); }
        try {Vrijeme v1(12,60);} catch(std::domain_error &ex){std::cout << " OK4 " << ex.what(); }

        std::cout << "\nEND";
    }

    std::cout << "\n-----------\nAutotest 6\n-----------\n";


    {//AT6 (skriveni) Test klase Vrijeme, metoda postavi i ispisi
        Vrijeme v1(2,2);
        try {v1.Postavi(-1,12);} catch(std::domain_error &ex){std::cout << "OK1 " << ex.what() << std::endl; }
        v1.Ispisi();
        try {v1.Postavi(24,12);} catch(std::domain_error &ex){std::cout << "\nOK2 " << ex.what() << std::endl; }
        v1.Ispisi();
        try {v1.Postavi(0,-1);} catch(std::domain_error &ex){std::cout << "\nOK3 " << ex.what() << std::endl; }
        v1.Ispisi();
        try {v1.Postavi(0,60);} catch(std::domain_error &ex){std::cout << "\nOK4 " << ex.what() << std::endl; }
        v1.Ispisi();
    }

    std::cout << "\n-----------\nAutotest 7\n-----------\n";


    {//AT7 (skriveni) Test klase Pregled, konstruktori, ispisi
        Pregled p1("Dalila", Datum(17,2,2018), Vrijeme(10,10));
        try {Pregled p1("Dalila", Datum(29,2,2018), Vrijeme(10,10) );} catch(std::domain_error &ex){std::cout << "OK1 " << ex.what() << std::endl; }
        try {Pregled p1("Dalila", Datum(29,2,2018), Vrijeme(10,60) );} catch(std::domain_error &ex){std::cout << "OK2 " << ex.what() << std::endl; }
        Pregled p2("Emina", 31,5,2014,12,12);
        try {Pregled p2("Emina", 32,5,2014,12,12);} catch(std::domain_error &ex){std::cout << "OK3 " << ex.what() << std::endl; }
        try {Pregled p2("Emina", 31,5,2014,27,12);} catch(std::domain_error &ex){std::cout << "OK4 " << ex.what() << std::endl; }

        p1.Ispisi();
        p2.Ispisi();
    }

    std::cout << "\n-----------\nAutotest 8\n-----------\n";

    {//AT8 (skriveni) Test klase pregled getteri setteri, const
        Pregled p1("Dalila", Datum(17,2,2018), Vrijeme(10,10));
        try {p1.PromijeniDatum({32,1,2018});} catch(std::domain_error &ex){std::cout << "OK1 " << ex.what() << std::endl; }
        try {p1.PromijeniVrijeme({-1,-1});} catch(std::domain_error &ex){std::cout << "OK2 " << ex.what() << std::endl; }
        p1.PromijeniDatum({18,2,2018});
        p1.PromijeniVrijeme({11,11});
        p1.Ispisi();
    }

    std::cout << "\n-----------\nAutotest 9\n-----------\n";


    {//AT9 (skriveni) Test klase pregled dolaziPrije, pomjeriDanUnaprijed, PomjeriDanUnazad
        Pregled p1("Lamija", {25,10,2018}, {16,20});
        Pregled p2("Selma", {31,7,2018}, {20,12});
        Pregled p3("Lejla", {31,7,2018}, {20,12});
        Pregled p4("Emina", {20,8,2016}, {20,12});
        std::cout << std::boolalpha << p1.DolaziPrije(p1, p2) << " " << p1.DolaziPrije(p2, p1)
                  << " " << p1.DolaziPrije(p2,p3) << " " << p1.DolaziPrije(p3, p2)
                  << " " << p1.DolaziPrije(p1, p4)<< " " << p1.DolaziPrije(p2, p4) << " "
                  << p1.DolaziPrije(p4, p1) << std::endl;

        p1.PomjeriDanUnaprijed();
        p2.PomjeriDanUnaprijed();
        p3.PomjeriDanUnazad();
        p4.PomjeriDanUnazad();
        p1.Ispisi();
        p2.Ispisi();
        p3.Ispisi();
        p4.Ispisi();
    }

    std::cout << "\n-----------\nAutotest 10\n-----------\n";


    {//AT10 (skriveni) Test klase pregled dolaziPrije, granicni slucajevi
        Pregled p1("Lamija", {25,10,2018}, {16,20});
        Pregled p2("Selma", {20,10,2018}, {16,19});
        Pregled p3("Dalila", {20,10,2018}, {16,21});
        Pregled p4("Lejla", {20,10,2018}, {17,20});
        Pregled p5("Emina", {20,10,2018}, {15,20});
        std::cout << std::boolalpha << p1.DolaziPrije(p1, p2) << " " << p1.DolaziPrije(p2, p1)
                  << " " << p1.DolaziPrije(p1,p3) << " " << p1.DolaziPrije(p3, p1)
                  << " " << p1.DolaziPrije(p1, p4)<< " " << p1.DolaziPrije(p4, p1) << " "
                  << p1.DolaziPrije(p1, p5) << " " << p1.DolaziPrije(p5, p1) << std::endl;

        Pregled p6("Selma", {19,10,2018}, {16,20});
        Pregled p7("Dalila", {21 ,10,2018}, {16,20});
        Pregled p8("Lejla", {20,9,2018}, {16,20});
        Pregled p9("Emina", {20,11,2018}, {16,20});
        Pregled p10("Lejla", {20,10,2016}, {16,20});
        Pregled p11("Emina", {20,10,2017}, {16,20});

        std::cout << std::boolalpha << p1.DolaziPrije(p1, p6) << " " << p1.DolaziPrije(p6, p1)
                  << " " << p1.DolaziPrije(p1,p7) << " " << p1.DolaziPrije(p7, p1)
                  << " " << p1.DolaziPrije(p1, p8)<< " " << p1.DolaziPrije(p8, p1) << " "
                  << p1.DolaziPrije(p1, p9)<< " " << p1.DolaziPrije(p9, p1) << " "
                  << p1.DolaziPrije(p1, p10)<< " " << p1.DolaziPrije(p10, p1) << " "
                  << p1.DolaziPrije(p1, p11)<< " " << p1.DolaziPrije(p11, p1) << " ";

    }

    std::cout << "\n-----------\nAutotest 11\n-----------\n";

    {//AT11 (skriveni) Test klase pregled pomjeriUnaprijed, granicni slucajevi
        Pregled p("Dalila", {31,12,2018}, {10,10});
        p.PomjeriDanUnaprijed();
        p.Ispisi();

        p.PromijeniDatum({31,1,2018});
        p.PomjeriDanUnaprijed();
        p.Ispisi();

        p.PromijeniDatum({31,3,2018});
        p.PomjeriDanUnaprijed();
        p.Ispisi();

        p.PromijeniDatum({30,4,2018});
        p.PomjeriDanUnaprijed();
        p.Ispisi();

        p.PromijeniDatum({31,5,2018});
        p.PomjeriDanUnaprijed();
        p.Ispisi();

        p.PromijeniDatum({30,6,2018});
        p.PomjeriDanUnaprijed();
        p.Ispisi();

        p.PromijeniDatum({31,7,2018});
        p.PomjeriDanUnaprijed();
        p.Ispisi();

        p.PromijeniDatum({31,8,2018});
        p.PomjeriDanUnaprijed();
        p.Ispisi();

        p.PromijeniDatum({30,9,2018});
        p.PomjeriDanUnaprijed();
        p.Ispisi();

        p.PromijeniDatum({31,10,2018});
        p.PomjeriDanUnaprijed();
        p.Ispisi();

        p.PromijeniDatum({30,11,2018});
        p.PomjeriDanUnaprijed();
        p.Ispisi();

    }

    std::cout << "\n-----------\nAutotest 12\n-----------\n";

    {//AT12 (skriveni) Test klase pregled pomjeriUnazad, granicni slucajevi
        Pregled p("Dalila", {1,12,2018}, {10,10});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,1,2018});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,3,2018});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,4,2018});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,5,2018});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,6,2018});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,7,2018});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,8,2018});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,9,2018});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,10,2018});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,11,2018});
        p.PomjeriDanUnazad();
        p.Ispisi();
    }

    std::cout << "\n-----------\nAutotest 13\n-----------\n";

    {//AT13 (neaktivni) Test klase pregled pomjeriUnazad, februar
        Pregled p("Dalila", {1,3,2018}, {10,10});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,3,2017});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,3,2006});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,3,1998});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,3,2004});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,3,2000});
        p.PomjeriDanUnazad();
        p.Ispisi();

        p.PromijeniDatum({1,3,2008});
        p.PomjeriDanUnazad();
        p.Ispisi();

    }
    std::cout << "\n-----------\nAutotest 14\n-----------\n";


    {//AT14 (skriveni) Test klase pregled getteri
        Pregled p1("Dalila", Datum(17,2,2018), Vrijeme(10,10));
        std::cout << p1.DajImePacijenta() << " ";
        p1.DajDatumPregleda().Ispisi(); std::cout << " ";
        p1.DajVrijemePregleda().Ispisi(); std::cout << std::endl;
        Pregled p2("Emina", {8,1,2018}, {18,18});
        std::cout << p2.DajImePacijenta() << " ";
        p2.DajDatumPregleda().Ispisi(); std::cout << " ";
        p2.DajVrijemePregleda().Ispisi(); std::cout << std::endl;
    }
    std::cout << "\n-----------\nAutotest 15\n-----------\n";

    {//AT15 (skriveni) Test klase pregled getteri, const
        const Pregled p1("Dalila", Datum(17,2,2018), Vrijeme(10,10));
        std::cout << p1.DajImePacijenta() << " ";
        p1.DajDatumPregleda().Ispisi(); std::cout << " ";
        p1.DajVrijemePregleda().Ispisi(); std::cout << std::endl;
        const Pregled p2("Emina", {8,1,2018}, {18,18});
        std::cout << p2.DajImePacijenta() << " ";
        p2.DajDatumPregleda().Ispisi(); std::cout << " ";
        p2.DajVrijemePregleda().Ispisi(); std::cout << std::endl;
    }
    std::cout << "\n-----------\nAutotest 16\n-----------\n";

    {//AT16 (skriveni) Klasa Pregleedi, konstrukotr bez parametara
        std::cout << std::boolalpha << std::is_convertible<Pregledi, int>::value;
        Pregledi p;
        p.IspisiSvePreglede();
        std::cout << " " << p.DajBrojPregleda();

    }
    std::cout << "\n-----------\nAutotest 17\n-----------\n";

    {//AT17 (skriveni) Klasa Pregleedi, RegistrirajPregled, prva verzija
        Pregledi p;
        int d(1);
        for(int i = 0; i < 20; i++,d++){
            p.RegistrirajPregled("Dalila", {d,d%12+1,2000+d},{1,1});
        }
        p.IspisiSvePreglede();
    }
    std::cout << "\n-----------\nAutotest 18\n-----------\n";

    {//AT18 (skriveni) Klasa Pregleedi, RegistrirajPregled, druga verzija
        Pregledi p;
        int d(1);
        for(int i = 0; i < 20; i++,d++){
            p.RegistrirajPregled("Dalila", d,d%12+1,2000+d,1,1);
        }
        p.IspisiSvePreglede();
    }
    std::cout << "\n-----------\nAutotest 19\n-----------\n";

    {//AT19 (skriveni) Klasa Pregleedi, RegistrirajPregled, treca verzija
        Pregledi p;
        int d(1);
        for(int i = 0; i < 20; i++,d++){
            p.RegistrirajPregled(std::make_shared<Pregled>(Pregled("Dalila", {d,d%12+1,2000+d}, {1,1})));
        }
        p.IspisiSvePreglede();
    }


    std::cout << "\n-----------\nAutotest 23\n-----------\n";


    {//AT23 (skriveni) Klasa Pregledi, dajBrojPregleda trivijalni, const provjera
        Pregledi p;
        for(int i = 0; i < 10; i++)
            p.RegistrirajPregled("Dino", {1,1,2001}, {10,10});
        std::cout << p.DajBrojPregleda() << std::endl;
        p.RegistrirajPregled("Emir", {1,1,2001}, {1,1});
        std::cout << p.DajBrojPregleda() << std::endl;
        const Pregledi p1;
        std::cout << p1.DajBrojPregleda() << std::endl;
    }
    std::cout << "\n-----------\nAutotest 24\n-----------\n";


    {//AT24 (skriveni) Klasa Pregledi, dajBrojPregledaNaDatum trivijalni, const provjera
        Pregledi p;
        for(int i = 0, d=1; i < 999; i++,d++)
            p.RegistrirajPregled("Dino", {d%30+1,d%12+1,2000 + d%3}, {10,10});

        std::cout << p.DajBrojPregledaNaDatum({2,2,2001}) << std::endl;
        std::cout << p.DajBrojPregledaNaDatum({1,1,2000}) << std::endl;
        std::cout << p.DajBrojPregledaNaDatum({30,6,2002}) << std::endl;

        p.RegistrirajPregled("Emir", {30,6,2002}, {1,1});
        std::cout << p.DajBrojPregledaNaDatum({30,6,2002}) << std::endl;
        const Pregledi p1;
        try {
            std::cout << p1.DajBrojPregledaNaDatum({10, 10, 2010}) << std::endl;
        }
        catch(std::domain_error ex){
            std::cout << ex.what();
        }
    }

    std::cout << "\n-----------\nAutotest 25\n-----------\n";

    {//AT25 (skriveni) Klasa Pregledi, DajNajranijiPregled, obrisiNajranijiPregled
        Pregledi p;
        p.RegistrirajPregled("Dino", {31,5,2018}, {1,1});
        p.RegistrirajPregled("Enis", {30,6,2016}, {10,12});
        p.RegistrirajPregled("Rijad", {31,7,2015}, {18,11});
        p.RegistrirajPregled("Salko", {30,8,2017}, {17,13});
        p.RegistrirajPregled("Samir", {20,5,2019}, {19,16});

        std::cout << "Najraniji pregled: \n";
        p.DajNajranijiPregled().Ispisi();
        p.ObrisiNajranijiPregled();
        std::cout << "Nakon brisanja ostaju pregledi: \n";
        p.IspisiSvePreglede();
    }

    std::cout << "\n-----------\nAutotest 26\n-----------\n";

    {//AT26 (skriveni) Klasa Pregledi DajNajranijiPreglede, non const verzija

        Pregledi p;
        p.RegistrirajPregled("Dino", {31,5,2018}, {1,1});
        p.RegistrirajPregled("Enis", {30,6,2016}, {10,12});
        p.RegistrirajPregled("Rijad", {31,7,2015}, {18,11});
        p.RegistrirajPregled("Salko", {30,8,2017}, {17,13});
        p.RegistrirajPregled("Samir", {20,5,2019}, {19,16});
        p.DajNajranijiPregled().PromijeniPacijenta("Novi pacijent ");
        p.IspisiSvePreglede();
    }
    std::cout << "\n-----------\nAutotest 27\n-----------\n";


    {//AT27 (skriveni) Klasa Pregledi DajNajranijiPreglede, const verzija

        Pregled p1("Dino", {31,5,2018}, {1,1});
        Pregled p2("Enis", {30,6,2016}, {10,12});
        Pregled p3("Rijad", {31,7,2015}, {18,11});
        Pregled p4("Salko", {30,8,2017}, {17,13});
        Pregled p5("Samir", {20,5,2019}, {19,16});
        const Pregledi p{p1, p2, p3, p4, p5};
        p.DajNajranijiPregled().PromijeniPacijenta("Novi pacijent ");
        p.IspisiSvePreglede();
    }
    std::cout << "\n-----------\nAutotest 28\n-----------\n";

    {//AT28 (skriveni) Klasa Pregledi DajNajranijiPreglede izuzetak

        try {
            const Pregledi p;
            Pregledi p1;
            try{p.DajBrojPregledaNaDatum({1,1,2001});}catch(std::domain_error &ex) {std::cout << ex.what() << std::endl;}
            try{p1.DajBrojPregledaNaDatum({1,1,2001});}catch(std::domain_error &ex) {std::cout << ex.what() << std::endl;}
        }
        catch(...){
            std::cout << "IZUZETAK!";
        }
    }
    std::cout << "\n-----------\nAutotest 29\n-----------\n";

    {//AT29 (skriveni) DajBrojPregleda i DajBrojPregledaNaDatum netrivijalni
        Pregledi p;
        for(int i = 0; i < 100; i++)
            p.RegistrirajPregled("Lamija", {i%30+1, 1,2001},{10,10});

        std::cout << p.DajBrojPregleda() << " " << p.DajBrojPregledaNaDatum({1,1,2001}) << std::endl;
        for(int i = 0; i < 4; i++)
            p.ObrisiNajranijiPregled();

        std::cout << p.DajBrojPregleda() << std::endl;
        try{std::cout << p.DajBrojPregledaNaDatum({1,1,2001});}catch(std::domain_error &ex) {std::cout << ex.what() << std::endl;}
    }
    std::cout << "\n-----------\nAutotest 30\n-----------\n";

    {//AT30 (skriveni) DajBrojPregleda i DajBrojPregledaNaDatum ObrisiNajranijiPregled netrivijalni
        Pregledi p;
        for(int i = 0; i < 100; i++)
            p.RegistrirajPregled("Lamija", {i%30+1, 1,2001},{10,10});

        std::cout << p.DajBrojPregleda() << " " << p.DajBrojPregledaNaDatum({1,1,2001}) << std::endl;
        for(int i = 0; i < 4; i++)
            p.ObrisiNajranijiPregled();

        std::cout << p.DajBrojPregleda() << std::endl;
        try{std::cout << p.DajBrojPregledaNaDatum({1,1,2001});}catch(std::domain_error &ex) {std::cout << ex.what() << std::endl;}
    }

    std::cout << "\n-----------\nAutotest 31\n-----------\n";

    {//AT31 (skriveni) Klasa Pregledi ObrisiPregledePacijenta IspisiPregledeNaDatum
        Pregledi p;
        p.RegistrirajPregled("Amina", 1,1,2001,1,1);
        p.RegistrirajPregled("Emina", 1,1,2002,1,1);
        p.RegistrirajPregled("Aida", 1,1,2001,1,1);
        p.RegistrirajPregled("Fatima", 1,1,2002,1,1);
        p.RegistrirajPregled("Lejla", 1,1,2001,1,1);
        p.RegistrirajPregled("Farah", 1,1,2001,1,1);
        p.RegistrirajPregled("Aida", 1,1,2001,1,1);

        p.ObrisiPregledePacijenta("Amina");
        p.ObrisiPregledePacijenta("Aida");
        std::cout << "Pregledi na datum: \n";
        p.IspisiPregledeNaDatum({1,1,2001});
        std::cout << "Svi pregledi: \n";
        p.IspisiSvePreglede();
    }
//
    std::cout << "\n-----------\nAutotest 32\n-----------\n";

    {//AT32 (skriveni) Klasa Pregledi IsprazniKolekciju
        Pregledi p;
        for(int i = 0; i < 1000; i++){
            p.RegistrirajPregled("Lamija", 1,1,2001,1,1);
        }
        std::cout << p.DajBrojPregleda() << std::endl;
        p.IsprazniKolekciju();
        std::cout << p.DajBrojPregleda();
        p.IspisiSvePreglede();
    }
    std::cout << "\n-----------\nAutotest 33\n-----------\n";

    {//AT33 (skriveni) Klasa Pregledi sekvencijski  konstruktor
        Pregled p1("Dino", {31, 5, 2018}, {1, 1});
        Pregled p2("Enis", {30, 6, 2016}, {10, 12});
        Pregled p3("Rijad", {31, 7, 2015}, {18, 11});
        Pregled p4("Salko", {30, 8, 2017}, {17, 13});
        Pregled p5("Samir", {20, 5, 2019}, {19, 16});
        Pregledi p{p1, p2, p3, p4, p5};
        std::cout << p.DajBrojPregleda() << " " << p.DajBrojPregledaNaDatum({31, 5, 2018}) << std::endl;
        p.IspisiSvePreglede();

    }

    {//AT34 (neaktivni) Klasa Pregledni sekvencijski  konstruktor, nedovoljno memorije
        //nakon neuspjesne alokacije treba da pocisti za sobom
        try {
            Pregled p1("Dino", {31, 5, 2018}, {1, 1});
            Pregled p2("Enis", {30, 6, 2016}, {10, 12});
            Pregled p3("Rijad", {31, 7, 2015}, {18, 11});
            Pregled p4("Salko", {30, 8, 2017}, {17, 13});
            Pregled p5("Samir", {20, 5, 2019}, {19, 16});
            Pregled p6("Damir", {20, 5, 2019}, {19, 16});
            Pregled p7("Amir", {20, 5, 2019}, {19, 16});

            OgraniciBrojAlokacija(6);
            Pregledi p{p1, p2, p3, p4, p5, p6, p7};
            std::cout << p.DajBrojPregleda() << " " << p.DajBrojPregledaNaDatum({31, 5, 2018}) << std::endl;
            p.IspisiSvePreglede();
        }
        catch (std::bad_alloc) {
            std::cout << "Neuspjela alokacija!";
        }
    }
    ProvjeriCurenje();
    OgraniciBrojAlokacija(0);

    std::cout << "\n-----------\nAutotest 35\n-----------\n";


    {//AT35 (neaktivni) Provjera da li se u obrisiPregledePacijenta  i obrisiPregledeNaDatum vrši nova alokacija
        //ova metoda treba samo da obrise element ne smije se vrsiti alokaciju novih pregleda, niti novog niza pregleda

        try{
            Pregledi p;
            for(int i = 0; i < 1000; i++){
                p.RegistrirajPregled(std::to_string(i), 1,1,1,1,1);
            }
            ZabraniAlokaciju(true);
            try {
                for (int i = 20; i < 200; i++) {
                    p.ObrisiPregledePacijenta(std::to_string(i));
                }
                std::cout << "Broj pregleda: " << p.DajBrojPregleda() << std::endl
                          << "Najraniji pregled je\n";
                p.DajNajranijiPregled().Ispisi();
                p.ObrisiNajranijiPregled();
                std::cout << "Nakon obrisanog najranijeg pregleda broj pregleda je: ";
                std::cout << p.DajBrojPregleda() << "\nI novi najraniji pregled je\n";
                p.DajNajranijiPregled().Ispisi();
            }
            catch(const char ex[]){
                std::cout << ex;
            }
        }
        catch(const char c[]){
            std::cout << c;
        }
    }

    ZabraniAlokaciju(false);


    std::cout << "\n-----------\nAutotest 36\n-----------\n";


    {//AT36 (neaktivni) Test kopirajuceg konstrukotra kada mu ponestane memorije
        try {
            Pregledi p;
            for (int i = 0; i < 100; i++) {
                p.RegistrirajPregled(std::to_string(i), 1, 1, 1, 1, 1);
            }
            //prije provjere curenja provjeravamo da li je uopce dobro implementiran
            Pregledi p2(p);
            p2.ObrisiPregledePacijenta("1");
            std::cout << "Broj pregleda p "<< p.DajBrojPregleda() << ", broj pregleda p2 " << p2.DajBrojPregleda() << std::endl;
            OgraniciBrojAlokacija(80);
            Pregledi p1(p);
            p1.IspisiSvePreglede();
        }
        catch(std::bad_alloc){
            std::cout << "Nema dovoljno memorije!";
        }
    }
    ProvjeriCurenje();


    OgraniciBrojAlokacija(0);
//
    std::cout << "\n-----------\nAutotest 37\n-----------\n";


    {//AT37 (neaktivni) Test pomjerajućeg konstruktora kopije, u njemu se ne smije vršiti dodatna alokacija
        //pomjerajuci konstruktor treba da ukrade elemente, a ne da ih kopira
        try {
            Pregledi p;
            for (int i = 0; i < 10; i++) {
                p.RegistrirajPregled(std::to_string(i), 1, 1, 1, 1, 1);
            }
            ZabraniAlokaciju(true);
            try {
                Pregledi p1(std::move(p));
                p.ObrisiPregledePacijenta("1");
                std::cout << "Broj pregleda p: " << p.DajBrojPregleda() << ", broj pregleda p1 " << p1.DajBrojPregleda()
                          << "\nSvi pregledi: \n";
                ZabraniAlokaciju(false);
                p1.IspisiSvePreglede();
            }
            catch(const char ex[]){
                std::cout << ex;
            }
            ZabraniAlokaciju(false);
        }
        catch(const char *ex){
            std::cout << ex;
        }
        catch(...){
            std::cout << "Izuzetak";
        }
    }

    std::cout << "\n-----------\nAutotest 38\n-----------\n";


    {//AT38 (skriveni) Test kopirajuceg konstrukotra

        Pregledi p;
        p.RegistrirajPregled("Dalila", 1,1,2001,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);

        Pregledi p1(p);
        //provjera plitke kopije
        p.IsprazniKolekciju();
        p.IspisiSvePreglede();
        std::cout << "Trenutni pregledi: \n";
        p1.IspisiSvePreglede();
        p1.ObrisiPregledePacijenta("Dalila");
        std::cout << "Broj pregleda nakon brisanja je " << p1.DajBrojPregleda() << std::endl;
        //provjera da li maksimalni kapacitet isti kao kod orginalnog
        try {
            for (int i = 0; i < 1000; i++) {
                p1.RegistrirajPregled(std::to_string(i), 1, 1, 1, 1, 1);
            }
        }
        catch(...){
            std::cout << "NOT OK\n";
        }
        try { p1.RegistrirajPregled(std::to_string(1001), 1, 1, 1, 1, 1); }
        catch (std::range_error &ex) { std::cout << ex.what(); }
        std::cout << "\nBroj pregleda nakon dodavanja je  " << p1.DajBrojPregleda();
    }

    std::cout << "\n-----------\nAutotest 39\n-----------\n";


    {//AT39 (skriveni) Test operatora dodjele
        Pregledi p;
        p.RegistrirajPregled("Dalila", 1,1,2001,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);

        Pregledi p1;
        for(int i = 0; i < 1000; i++){
            p1.RegistrirajPregled(std::make_shared<Pregled>("Dino",1,1,1,1,1));
        }
        p1.RegistrirajPregled(std::make_shared<Pregled>("Edin",1,1,1,1,1));

        //destruktivna samododjela
        p1 = p1;
        //regularna dodjela
        p = p1;
        //provjera plitke kopije
        p1.IsprazniKolekciju();
        p1.IspisiSvePreglede();
        p.RegistrirajPregled("Dalila",1,1,1,1,1);
        p.ObrisiPregledePacijenta("Dino");
        //pregledi nakon brisanja trebaju biti samo Dalila i Edin
        p.IspisiSvePreglede();
    }

    std::cout << "\n-----------\nAutotest 40\n-----------\n";

    {//AT40 (neaktivni) Operator dodjele, nedostatak memorije, ne smije se uništiti izvorni ukoliko nema memorije da se
        //izvrši dodjela, ne smije curiti
        Pregledi p;
        p.RegistrirajPregled("Dalila", 1, 1, 2001, 1, 1);
        p.RegistrirajPregled("Dalila", 1, 1, 2002, 1, 1);
        p.RegistrirajPregled("Dalila", 1, 1, 2002, 1, 1);
        p.RegistrirajPregled("Dalila", 1, 1, 2002, 1, 1);
        p.RegistrirajPregled("Dalila", 1, 1, 2002, 1, 1);
        p.RegistrirajPregled("Dalila", 1, 1, 2002, 1, 1);
        p.RegistrirajPregled("Dalila", 1, 1, 2002, 1, 1);

        Pregledi p1;
        for (int i = 0; i < 100; i++) {
            p1.RegistrirajPregled(std::make_shared<Pregled>("Dino", 1, 1, 1, 1, 1));
        }
        OgraniciBrojAlokacija(80);
        try {
            p = p1;
        }
        catch (std::bad_alloc ex) {
            std::cout << "Nedovoljno memorije\n";
        }

        //ovim dozvoljavamo opet alokaciju
        OgraniciBrojAlokacija(0);
        //objekat ne smije biti u neispravnom stanju nakon neuspjele dodjele
        p.IspisiSvePreglede();
        std::cout << "Broj pregleda: " << p.DajBrojPregleda();
    }
    ProvjeriCurenje();

    std::cout << "\n-----------\nAutotest 41\n-----------\n";


    {//AT41 (neaktivni) Pomjerajuci operator dodjele
        // dodatno alociranje nije dozvoljeno, odredišna klasa treba da ukrade elemente
        Pregledi p;
        p.RegistrirajPregled("Dalila", 1,1,2001,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);
        p.RegistrirajPregled("Dalila", 1,1,2002,1,1);

        Pregledi p1;
        for(int i = 0; i < 1000; i++){
            p1.RegistrirajPregled(std::make_shared<Pregled>("Dino",1,1,1,1,1));
        }
        ZabraniAlokaciju(true);
        try {
            //destruktivna samododjela
            p1 = std::move(p1);
            //regularna dodjela
            p = std::move(p1);
        }
        catch(const char ex[]){
            std::cout << ex;
        }
        ZabraniAlokaciju(false);

        //provjera da li smo ispravno "ukrali" elemente
        p1.IsprazniKolekciju();
        p1.IspisiSvePreglede();

        p.ObrisiPregledePacijenta("Dino");
        p.RegistrirajPregled("Dalila", 10,1,2002,1,1);
        p.IspisiSvePreglede();
        std::cout << "Broj pregleda: " << p.DajBrojPregleda();
    }
    ProvjeriCurenje();*/

    //Studentski main

        //Studentski main
    Pregledi p;
    std::string ime;
    int i(0);
    for(;;){
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        if(i!= 0) std::cin.ignore(1000,'\n');
        std::getline(std::cin, ime);
        if(ime == "kraj")
            break;
        int d, m, g, sati, minute;
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        std::cin >> d >> m >> g;
        std::cout << "Unesite sate i minute pregleda: ";
        std::cin >> sati >> minute;
        p.RegistrirajPregled(ime, d, m ,g, sati, minute);
        i++;
    }
    std::cout << "Trenutno su registrovani sljedeci pregledi\n";
    p.IspisiSvePreglede();

    bool vrsiUnos = true;
    while(vrsiUnos){
        int opcija(-1);
        std::cout << "\nOdaberite jednu od sljedecih opcija\n1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n"
                     << "4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa\n";
        std::cin >> opcija;
        int d, m, g;
        switch(opcija) {
            case 1:
                std::cout << "Unesite dan mjesec i godinu : ";
                std::cin >> d >> m >> g;
                std::cout << "Broj pregleda na datum " << d << " " << m << " " << g << " je: "
                        <<   p.DajBrojPregledaNaDatum({d, m, g}) << std::endl;
                break;
            case 2:
                std::cout << "Najraniji pregled je:\n";
                          p.DajNajranijiPregled().Ispisi();
                break;
            case 3: {
                int brojPregleda1 = p.DajBrojPregleda();
                std::cin.ignore(1000, '\n');
                std::string ime;
                std::cout << "Unesite ime pacijenta: ";
                std::getline(std::cin, ime);
                p.ObrisiPregledePacijenta(ime);
                int noviBrojPregleda = p.DajBrojPregleda();
                std::cout << "Uspjesno obrisano " << brojPregleda1 - noviBrojPregleda << " pregleda\n";
                }
                break;
            case 4:
                try {
                    p.ObrisiNajranijiPregled();
                }
                catch(std::domain_error &ex){
                    ex.what();
                }
                std::cout << "Najraniji pregled uspjesno obrisan\n";
                break;
            case 5:
                std::cout << "Unesite dan mjesec i godinu : ";
                std::cin >> d >> m >> g;
                std::cout << "Pregledi na datum " << d << " " << m << " " << g << " su:\n";
                          p.IspisiPregledeNaDatum({d,m,g});
                break;
            case 6:
                p.IspisiSvePreglede();
            break;
            case 7:
                vrsiUnos = false;
                break;
            default:
                std::cout << "Nije unesena ispravna opcija";
        }
    }

}



