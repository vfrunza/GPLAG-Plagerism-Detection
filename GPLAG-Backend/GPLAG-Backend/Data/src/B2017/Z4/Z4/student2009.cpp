#include <iostream>
#include <stdexcept>
#include <exception>
#include <tuple>
#include <vector>
#include <string>
#include <iomanip>
#include <memory>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::shared_ptr;
using std::make_shared;
class Datum
{
    int dan,mjesec,godina;
    static int BrojDana (int mjesec, int godina) {
        int BrojDana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((godina%4==0 && godina%100!=0) || godina%400==0) BrojDana[1]++;
        return BrojDana[mjesec-1];
    }
public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina) {
        if(godina<1 || mjesec<1 || mjesec>12 || dan<1 || dan>BrojDana(mjesec,godina)) throw std::domain_error("Neispravan datum");
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
    }

    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(dan,mjesec,godina);
    }
    void Ispisi() const {
        cout << dan << "/" << mjesec << "/" << godina;
    }

    friend class Pregled;
    friend class Pregledi;
};

class Vrijeme
{
    int sati,minute;
public:
    Vrijeme(int sati, int minute) {
        Postavi(sati,minute);
    }

    void Postavi(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }

    std::pair<int, int> Ocitaj () const {
        return std::make_pair(sati,minute);
    }

    void Ispisi() const {
        std::cout << std::setfill('0') << std::setw(2) << sati << ":" << std::setw(2) << minute << std::setfill(' ');
    }

    friend class Pregled;
    friend class Pregledi;
};

class Pregled
{
    string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;

public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda):
        ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {}

    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, int sati_pregleda, int minute_pregleda) :
        ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda), vrijeme_pregleda(sati_pregleda,minute_pregleda) {}

    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }

    void PromijeniDatum(const Datum &novi_datum) {
        datum_pregleda=novi_datum;
    }

    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme_pregleda=novo_vrijeme;
    }

    void PomjeriDanUnaprijed() {
        int dan1(datum_pregleda.dan), mjesec1(datum_pregleda.mjesec), godina1(datum_pregleda.godina);
        dan1++;
        if(dan1>Datum::BrojDana(mjesec1,godina1)) {
            dan1=1;
            mjesec1=1;
        }
        if (mjesec1>12) {
            mjesec1=1;
            godina1++;
        }
        datum_pregleda=Datum(dan1, mjesec1, godina1);
    }

    void PomjeriDanUnazad() {
        int dan1(datum_pregleda.dan), mjesec1(datum_pregleda.mjesec), godina1(datum_pregleda.godina);
        dan1--;
        if (dan1<1) {
            mjesec1--;
            if (mjesec1>0) dan1=Datum::BrojDana(mjesec1, godina1);
        }
        if(mjesec1<1) {
            mjesec1=12;
            godina1--;
            if(godina1<1) throw std::domain_error("Neispravan datum");
            dan1=Datum::BrojDana(mjesec1,godina1);
        }
        datum_pregleda=Datum(dan1, mjesec1, godina1);
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
        return ( p1.datum_pregleda.godina<p2.datum_pregleda.godina ||
                 (p1.datum_pregleda.godina==p2.datum_pregleda.godina && p1.datum_pregleda.mjesec<p2.datum_pregleda.mjesec) ||
                 (p1.datum_pregleda.godina==p2.datum_pregleda.godina && p1.datum_pregleda.mjesec==p2.datum_pregleda.mjesec &&
                  p1.datum_pregleda.dan<p2.datum_pregleda.dan) || (p1.datum_pregleda.godina==p2.datum_pregleda.godina &&
                          p1.datum_pregleda.mjesec==p2.datum_pregleda.mjesec && p1.datum_pregleda.dan==p2.datum_pregleda.dan && p1.vrijeme_pregleda.sati<p2.vrijeme_pregleda.sati)
                 || (p1.datum_pregleda.godina==p2.datum_pregleda.godina && p1.datum_pregleda.mjesec==p2.datum_pregleda.mjesec &&
                     p1.datum_pregleda.dan==p2.datum_pregleda.dan && p1.vrijeme_pregleda.sati==p2.vrijeme_pregleda.sati
                     && p1.vrijeme_pregleda.minute<p2.vrijeme_pregleda.minute));
    }

    void Ispisi() const {
        cout << std::left << std::setw(30) << ime_pacijenta << std::right;
        datum_pregleda.Ispisi();
        cout << " ";
        vrijeme_pregleda.Ispisi();
        cout << endl;
    }

    friend class Vrijeme;
    friend class Datum;
    friend class Pregledi;
};

class Pregledi
{
    vector<shared_ptr<Pregled>> pregledi;
public:
    explicit Pregledi() {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda) {
        auto it = spisak_pregleda.begin();
        for(int i=0; i<spisak_pregleda.size(); i++,it++)
            pregledi.push_back(make_shared<Pregled>(*it));
    }

    ~Pregledi() {
        for(int i=0; i<pregledi.size(); i++) pregledi.at(i)=nullptr;
    }

    Pregledi(const Pregledi &pregledi) {
        for(int i=0; i<pregledi.pregledi.size(); i++)
            Pregledi::pregledi.push_back(make_shared<Pregled>(*(pregledi.pregledi.at(i))));
    }

    Pregledi(Pregledi &&pregledi) {
        Pregledi::pregledi=std::move(pregledi.pregledi);
    }

    Pregledi &operator =(const Pregledi &pregledi) {
        if(&pregledi!=this) { // samododjela?
            Pregledi::pregledi.resize(0);
            for(int i=0; i<pregledi.pregledi.size(); i++)
                Pregledi::pregledi.push_back(make_shared<Pregled>(*(pregledi.pregledi.at(i))));
        }
        return *this;
    }

    Pregledi &operator =(Pregledi &&pregledi) {
        if(&pregledi!=this) Pregledi::pregledi=std::move(pregledi.pregledi);
        return *this;
    }

    void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        pregledi.push_back(make_shared<Pregled>(ime_pacijenta,datum_pregleda,vrijeme_pregleda));
    }

    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, int godina_pregleda,
                            int sati_pregleda,int minute_pregleda) {
        pregledi.push_back(make_shared<Pregled>(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda));
    }

    void RegistrirajPregled(shared_ptr<Pregled> pregled) {
        pregledi.push_back(pregled);
    }

    int DajBrojPregleda() const {
        return pregledi.size();
    }

    int DajBrojPregledaNaDatum(const Datum &datum) const {
        int brojac = std::count_if(pregledi.begin(),pregledi.end(),
        [datum](shared_ptr<Pregled>p) {
            return (p->datum_pregleda.dan==datum.dan && p->datum_pregleda.mjesec==datum.mjesec &&
                    p->datum_pregleda.godina==datum.godina);
        });
        return brojac;
    }

    Pregled &DajNajranijiPregled() {
        if(pregledi.size()==0) throw std::domain_error("Nema registriranih pregleda");
        return **(std::min_element(pregledi.begin(),pregledi.end(),
                                   [](shared_ptr<Pregled>p1,shared_ptr
                                      <Pregled>p2)->bool {return Pregled::DolaziPrije(*p1,*p2);}));
    }

    Pregled DajNajranijiPregled() const {
        if(pregledi.size()==0) throw std::domain_error("Nema registriranih pregleda");
        return **std::min_element(pregledi.begin(),pregledi.end(),
                                  [](shared_ptr<Pregled>p1,shared_ptr
                                     <Pregled>p2)->bool {return Pregled::DolaziPrije(*p1,*p2);});
    }

    void IsprazniKolekciju() {
        for(int i=0; i<pregledi.size(); i++) pregledi.at(i)=nullptr;
        pregledi.resize(0);
    }

    void ObrisiNajranijiPregled() {
        if(pregledi.size()==0) throw std::range_error("Prazna kolekcija");
        Pregled &del=DajNajranijiPregled();
        for(int i=0; i<pregledi.size(); i++)
            if(&del==pregledi.at(i).get()) {
                for(int j=i; j+1<pregledi.size(); j++) pregledi.at(j)=pregledi.at(j+1);
                pregledi.resize(pregledi.size()-1);
                break;
            }
    }

    void ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
        for(int i=0; i<pregledi.size(); i++) {
            if(pregledi.at(i)->ime_pacijenta==ime_pacijenta) {
                for(int j=i; j+1<pregledi.size(); j++) pregledi.at(j)=pregledi.at(j+1);
                pregledi.resize(pregledi.size()-1);
                i--;
            }
        }
    }

    void IspisiPregledeNaDatum(const Datum &datum) const {
        vector<shared_ptr<const Pregled>> vp;
        for(int i=0; i<pregledi.size(); i++)
            if(pregledi.at(i)->datum_pregleda.dan==datum.dan && pregledi.at(i)->datum_pregleda.mjesec==datum.mjesec &&
                    pregledi.at(i)->datum_pregleda.godina==datum.godina) vp.push_back(pregledi.at(i));
        std::sort(vp.begin(),vp.end(),[](shared_ptr<const Pregled> p1, shared_ptr<const Pregled>p2) {
            return Pregled::DolaziPrije(*p1,*p2);
        });
        for(int i=0; i<vp.size(); i++) vp.at(i)->Ispisi();
    }

    void IspisiSvePreglede() const {
        vector<shared_ptr<const Pregled>> vp;
        for(int i=0; i<pregledi.size(); i++) vp.push_back(pregledi.at(i));
        std::sort(vp.begin(),vp.end(),[](shared_ptr<const Pregled> p1, shared_ptr<const Pregled>p2) {
            return Pregled::DolaziPrije(*p1,*p2);
        });
        for(int i=0; i<vp.size(); i++) vp.at(i)->Ispisi();
    }

    friend class Datum;
    friend class Vrijeme;
    friend class Pregled;
};


int main ()
{
      {//AT8 (skriveni) Test klase pregled getteri setteri, const
        Pregled p1("Dalila", Datum(17,2,2018), Vrijeme(10,10));
        try {p1.PromijeniDatum({32,1,2018});} catch(std::domain_error &ex){std::cout << "OK1 " << ex.what() << std::endl; }
        try {p1.PromijeniVrijeme({-1,-1});} catch(std::domain_error &ex){std::cout << "OK2 " << ex.what() << std::endl; }
        p1.PromijeniDatum({18,2,2018});
        p1.PromijeniVrijeme({11,11});
        p1.Ispisi();
    }
    return 0;
}
