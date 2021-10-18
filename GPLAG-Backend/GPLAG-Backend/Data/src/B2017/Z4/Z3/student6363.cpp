#include <iostream>
#include <stdexcept>
#include <exception>
#include <tuple>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Datum
{
    int dan,mjesec,godina;
    static int BrojDana (int mjesec, int godina) {
        int BrojDana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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
        if(dan1>Datum::BrojDana(mjesec1,godina1)) {dan1=1; mjesec1=1;}
        if (mjesec1>12) { mjesec1=1; godina1++; }
        datum_pregleda=Datum(dan1, mjesec1, godina1);
    }

    void PomjeriDanUnazad() {
        int dan1(datum_pregleda.dan), mjesec1(datum_pregleda.mjesec), godina1(datum_pregleda.godina);
        dan1--;
        if (dan1<1) { mjesec1--; 
            if (mjesec1>0) dan1=Datum::BrojDana(mjesec1, godina1);
        }
        if(mjesec1<1) { mjesec1=12; godina1--; if(godina1<1) throw std::domain_error("Neispravan datum"); dan1=Datum::BrojDana(mjesec1,godina1); }
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
    Pregled **pregledi {};
    int broj_pregleda {};
    int max_broj_pregleda;
public:
    explicit Pregledi(int max_broj_pregleda) : pregledi(new Pregled*[max_broj_pregleda] {}), max_broj_pregleda(max_broj_pregleda) {}
    
    Pregledi(std::initializer_list<Pregled> spisak_pregleda) {
        auto it = spisak_pregleda.begin();
        try {
            broj_pregleda=max_broj_pregleda=spisak_pregleda.size();
            pregledi=new Pregled*[spisak_pregleda.size()] {};
            for(int i=0; i<spisak_pregleda.size(); i++,it++,broj_pregleda++)
                pregledi[i]=new Pregled(*it);
        } catch(...) {
            for(int i=0; i<spisak_pregleda.size(); i++) delete pregledi[i];
            delete[] pregledi;
            Pregledi::pregledi=nullptr;
            throw;
        }
    }
    
    ~Pregledi() {
        for(int i=0; i<broj_pregleda; i++) delete pregledi[i];
        delete [] pregledi;
        Pregledi::pregledi=nullptr;
    }
    
    Pregledi(const Pregledi &pregledi) : broj_pregleda(pregledi.broj_pregleda), max_broj_pregleda(pregledi.max_broj_pregleda) {
        try {
            Pregledi::pregledi=new Pregled*[broj_pregleda] {};
            for(int i=0; i<broj_pregleda; i++)
                Pregledi::pregledi[i]=new Pregled(*pregledi.pregledi[i]);
        } catch(...) {
            for(int i=0; i<broj_pregleda; i++) delete Pregledi::pregledi[i];
            delete[] Pregledi::pregledi;
            Pregledi::pregledi=nullptr;
            throw;
        }
    }
    
    Pregledi(Pregledi &&pregledi) {
        std::swap(Pregledi::max_broj_pregleda,pregledi.max_broj_pregleda);
        std::swap(Pregledi::broj_pregleda,pregledi.broj_pregleda);
        std::swap(Pregledi::pregledi,pregledi.pregledi);
    }
    
    Pregledi &operator =(const Pregledi &pregledi) {
        Pregled**temp {};
        try
        {temp=new Pregled*[pregledi.broj_pregleda] {};
        for(int i=0; i<pregledi.broj_pregleda; i++)
            temp[i]=new Pregled(*pregledi.pregledi[i]);
        }
        catch(...){
            for(int i=0; i<pregledi.broj_pregleda; i++) delete temp[i];
            delete[] temp;
            temp=nullptr;
            throw;
        }
        for(int i=0; i<max_broj_pregleda; i++) delete Pregledi::pregledi[i];
        delete [] Pregledi::pregledi;
        Pregledi::pregledi=temp;
        broj_pregleda=pregledi.broj_pregleda;
        max_broj_pregleda=pregledi.max_broj_pregleda;
        return *this;
    }
    
    Pregledi &operator =(Pregledi &&pregledi) {
        std::swap(Pregledi::max_broj_pregleda,pregledi.max_broj_pregleda);
        std::swap(Pregledi::broj_pregleda,pregledi.broj_pregleda);
        std::swap(Pregledi::pregledi,pregledi.pregledi);
        return *this;
    }
    
    void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        if(broj_pregleda+1>max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        pregledi[broj_pregleda]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
        broj_pregleda++;
    }
    
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, int godina_pregleda,
                            int sati_pregleda,int minute_pregleda) {
        if(broj_pregleda+1>max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        pregledi[broj_pregleda]=new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
        broj_pregleda++;
    }

    void RegistrirajPregled(Pregled *pregled) {
        if(broj_pregleda+1>max_broj_pregleda){ throw std::range_error("Dostignut maksimalni broj pregleda"); delete pregled;}
        pregledi[broj_pregleda]=pregled;
        broj_pregleda++;
    }

    int DajBrojPregleda() const {
        return broj_pregleda;
    }

    int DajBrojPregledaNaDatum(const Datum &datum) const {
        int brojac = std::count_if(pregledi,pregledi+broj_pregleda,
        [datum](Pregled*p) {
            return (p->datum_pregleda.dan==datum.dan && p->datum_pregleda.mjesec==datum.mjesec &&
                    p->datum_pregleda.godina==datum.godina);
        });
        return brojac;
    }
    
    Pregled &DajNajranijiPregled() {
        if(broj_pregleda==0 || pregledi==nullptr) throw std::domain_error("Nema registriranih pregleda");
        return **std::min_element(pregledi,pregledi+broj_pregleda,
                                  [](Pregled*p1,Pregled*p2)->bool {return Pregled::DolaziPrije(*p1,*p2);});
    }
    
    Pregled DajNajranijiPregled() const {
        if(broj_pregleda==0 || pregledi==nullptr) throw std::domain_error("Nema registriranih pregleda");
        return **std::min_element(pregledi,pregledi+broj_pregleda,
                                  [](Pregled*p1,Pregled*p2)->bool {return Pregled::DolaziPrije(*p1,*p2);});
    }
    
    void IsprazniKolekciju() {
        for(int i=0; i<max_broj_pregleda; i++) {
            delete pregledi[i];
            pregledi[i]=nullptr;
        }
        broj_pregleda=0;
    }
    
    void ObrisiNajranijiPregled() {
        if(broj_pregleda==0 || pregledi==nullptr) throw std::range_error("Prazna kolekcija");
        Pregled &del=DajNajranijiPregled();
        for(int i=0; i<broj_pregleda; i++)
            if(&del==pregledi[i]) {
                delete pregledi[i];
                for(int j=i; j+1<broj_pregleda; j++) pregledi[j]=pregledi[j+1];
                broj_pregleda--;
            }
    }
    
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
        for(int i=0; i<broj_pregleda; i++) {
            if(pregledi[i]->ime_pacijenta==ime_pacijenta) {
                delete pregledi[i];
                for(int j=i; j+1<broj_pregleda; j++) pregledi[j]=pregledi[j+1];
                broj_pregleda--;
                i--;
            }
        }
    }
    
    void IspisiPregledeNaDatum(const Datum &datum) const {
        vector<const Pregled*> vp;
        for(int i=0; i<broj_pregleda; i++)
            if(pregledi[i]->datum_pregleda.dan==datum.dan && pregledi[i]->datum_pregleda.mjesec==datum.mjesec &&
                    pregledi[i]->datum_pregleda.godina==datum.godina) vp.push_back(pregledi[i]);
        std::sort(vp.begin(),vp.end(),[](const Pregled *p1,const Pregled *p2) {
            return Pregled::DolaziPrije(*p1,*p2);
        });
        for(int i=0; i<vp.size(); i++) vp.at(i)->Ispisi();
    }
    
    void IspisiSvePreglede() const {
        vector<const Pregled*> vp;
        for(int i=0; i<broj_pregleda; i++) vp.push_back(pregledi[i]);
        std::sort(vp.begin(),vp.end(),[](const Pregled *p1,const Pregled *p2) {
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
     {//AT20 (skriveni) Klasa Pregleedi, RegistrirajPregled, prva verzija izuzetak
        Pregledi p(20);
        try {
            for (int i = 0, d=1; i < 25; i++, d++) {
                p.RegistrirajPregled("Dalila", {d, d%12+1, 2001}, {1, 1});
            }
            p.IspisiSvePreglede();
        }
        catch(std::range_error &ex){
            std::cout << "OK " << ex.what() << std::endl;
        }
        p.IspisiSvePreglede();
    }
    return 0;
}
