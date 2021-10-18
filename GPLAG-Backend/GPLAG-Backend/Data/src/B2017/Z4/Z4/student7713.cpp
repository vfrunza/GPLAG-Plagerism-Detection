/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <tuple>
#include <new>
#include <memory>
#include <vector>
#include <utility>
#include <string>
#include <initializer_list>

class Datum
{
    int dan,mjesec,godina;
public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina) {
        int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina % 4) == 0 && (godina % 100) != 0 || (godina % 400) == 0) broj_dana[1]++;
        int parametar(mjesec-1);
        if((godina<1) || (mjesec<1) || (mjesec>12) || (dan<1) || (dan>broj_dana[parametar])) throw std::domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    std::tuple<int, int, int> Ocitaj() const {
        return (std::make_tuple(dan,mjesec,godina));
    }
    void Ispisi() const {
        std::cout<<std::get<0> (Ocitaj())<<"/"<<std::get<1>(Ocitaj())<<"/"<<std::get<2>(Ocitaj());
    }
};

class Vrijeme
{
    int sati, minute;
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
        std::pair<int,int> p {sati,minute};
        return p;
    }
    void Ispisi() const {
        if(sati<10) {
            std::cout<<"0"<<Ocitaj().first<<":";
        } else {
            std::cout<<Ocitaj().first<<":";
        }
        if(minute<10) {
            std::cout<<"0"<<Ocitaj().second;
        } else {
            std::cout<<Ocitaj().second;
        }
    }
};


class Pregled
{
    std::string ime;
    Datum datum;
    Vrijeme vrijeme;
public:
    Pregled(const std::string &ime_pacijenta,const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda) : datum(datum_pregleda) , vrijeme(vrijeme_pregleda) {
        Pregled::ime=ime_pacijenta;
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, int sati_pregleda, int minute_pregleda) : datum(dan_pregleda,mjesec_pregleda,godina_pregleda), vrijeme(sati_pregleda,minute_pregleda) {
        Pregled::ime=ime_pacijenta;
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        Pregled::datum=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        Pregled::vrijeme=novo_vrijeme;
    }
    void PomjeriDanUnaprijed() {
        std::tuple<int,int,int> neki_datum (datum.Ocitaj());
        int dan(std::get<0>(neki_datum));
        int mjesec(std::get<1>(neki_datum));
        int godina(std::get<2>(neki_datum));
        dan++;
        int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina % 4) == 0 && (godina % 100) != 0 || (godina % 400) == 0) broj_dana[1]++;
        int parametar(mjesec-1);
        if(dan>broj_dana[parametar]) {
            dan=1;
            mjesec++;
        }
        if(mjesec>12) {
            mjesec=1;
            godina++;
        }
        datum.Postavi(dan,mjesec,godina);
    }
    void PomjeriDanUnazad() {
        std::tuple<int,int,int> neki_datum (datum.Ocitaj());
        int dan(std::get<0>(neki_datum));
        int mjesec(std::get<1>(neki_datum));
        int godina(std::get<2>(neki_datum));
        dan--;
        int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina % 4) == 0 && (godina % 100) != 0 || (godina % 400) == 0) broj_dana[1]++;
        int parametar(mjesec-1);
        if(dan==0) mjesec--;
        if(mjesec!=0) {
            parametar=mjesec-1;
            dan=broj_dana[parametar];
        } else if(mjesec==0) {
            mjesec=12;
            godina--;
            dan=31;
        };
        datum.Postavi(dan,mjesec,godina);
    }
    std::string DajImePacijenta() const {
        return ime;
    }
    Datum DajDatumPregleda() const {
        return datum;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        if(std::get<2>(p1.datum.Ocitaj())<std::get<2>(p2.datum.Ocitaj())) return true;
        else if(std::get<2>(p1.datum.Ocitaj())>std::get<2>(p2.datum.Ocitaj())) return false;
        else if(std::get<2>(p1.datum.Ocitaj())==std::get<2>(p2.datum.Ocitaj())) {
            if(std::get<1>(p1.datum.Ocitaj())<std::get<1>(p2.datum.Ocitaj())) return true;
            else if(std::get<1>(p1.datum.Ocitaj())>std::get<1>(p2.datum.Ocitaj())) return false;
            else if(std::get<1>(p1.datum.Ocitaj())==std::get<1>(p2.datum.Ocitaj())) {
                if(std::get<0>(p1.datum.Ocitaj())<std::get<0>(p2.datum.Ocitaj())) return true;
                else if(std::get<0>(p1.datum.Ocitaj())>std::get<0>(p2.datum.Ocitaj())) return false;
                else if(std::get<0>(p1.datum.Ocitaj())==std::get<0>(p2.datum.Ocitaj())) {
                    if(p1.vrijeme.Ocitaj().first<p2.vrijeme.Ocitaj().first) return true;
                    else if(p1.vrijeme.Ocitaj().first>p2.vrijeme.Ocitaj().first) return false;
                    else if(p1.vrijeme.Ocitaj().first==p2.vrijeme.Ocitaj().first) {
                        if(p1.vrijeme.Ocitaj().second<p2.vrijeme.Ocitaj().second) return true;
                        return false;
                    }
                }
            }
        }

    }
    void Ispisi() const {
        std::cout<<std::setw(30)<<std::left<<ime;
        datum.Ispisi();
        std::cout<<" ";
        vrijeme.Ispisi();
        std::cout<<std::endl;
    }
};


class Pregledi
{
    int broj_pregleda;
    std::vector<std::shared_ptr<Pregled>>v;
public:

    explicit Pregledi() : broj_pregleda(0) {
    }
    Pregledi(std::initializer_list<Pregled> spisak_pregleda): broj_pregleda(spisak_pregleda.size())  {
        std::initializer_list<Pregled>::iterator it (spisak_pregleda.begin());
        for(int i(0); i<spisak_pregleda.size(); i++) {
            v.push_back(std::make_shared<Pregled>(*it));
            it++;
        }
    }

    Pregledi(const Pregledi &pregledi)
        : broj_pregleda(pregledi.broj_pregleda) {
        for(int i(0); i<broj_pregleda; i++)
            v.push_back(pregledi.v.at(i));
    }
    Pregledi(Pregledi &&pregledi) : broj_pregleda(pregledi.broj_pregleda), v(pregledi.v) { }
    Pregledi &operator =(const Pregledi &pregledi) {
        v.resize(pregledi.broj_pregleda);
        for(int i(0); i<pregledi.broj_pregleda; i++) {
            Pregledi::v[i]=pregledi.v[i];
        }
        Pregledi::broj_pregleda=pregledi.broj_pregleda;
        return *this;
    }
    Pregledi &operator =(Pregledi &&pregledi) {
        if(&pregledi!=this) {
            v.resize(pregledi.broj_pregleda);
            Pregledi::broj_pregleda=pregledi.broj_pregleda;
            for(int i(0); i<pregledi.broj_pregleda; i++) {
                Pregledi::v[i]=pregledi.v[i];
            }
            for(int i(0); i<pregledi.broj_pregleda; i++) {
                pregledi.v[i]=nullptr;
            }
        }
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        broj_pregleda++;
        std::shared_ptr<Pregled> p (std::make_shared<Pregled>(ime_pacijenta,datum_pregleda,vrijeme_pregleda));
        v.push_back(p);
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
        broj_pregleda++;
        Pregled pr(ime_pacijenta,dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
        std::shared_ptr<Pregled> p (std::make_shared<Pregled>(pr));
        v.push_back(p);
    }
    void RegistrirajPregled(Pregled *pregled) {
        broj_pregleda++;
        std::shared_ptr<Pregled> p (std::make_shared<Pregled>(*pregled));
        v.push_back(p);
    }
    int DajBrojPregleda() const {
        return broj_pregleda;
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const {

        int brojac(std::count_if(v.begin(),v.end(),[&datum] (std::shared_ptr<Pregled> p) {
            return(std::get<0>(p->DajDatumPregleda().Ocitaj())==std::get<0> (datum.Ocitaj()) &&
                   std::get<1>(p->DajDatumPregleda().Ocitaj())==std::get<1> (datum.Ocitaj()) &&
                   std::get<2>(p->DajDatumPregleda().Ocitaj())==std::get<2> (datum.Ocitaj()));
        }));
        if(brojac!=0) return brojac;
        else throw std::domain_error("Nema registriranih pregleda");
    }
    Pregled &DajNajranijiPregled() {
        Pregled &najraniji(*(v[0]));
        for(int i(1); i<v.size(); i++) {
            if(Pregled::DolaziPrije(*(v[i]),najraniji)) najraniji=*(v[i]);
        }

        return najraniji;
    }
    Pregled DajNajranijiPregled() const {
        Pregled najraniji(*(v[0]));
        for(int i(1); i<v.size(); i++) {
            if(Pregled::DolaziPrije(*(v[i]),najraniji)) najraniji=*(v[i]);
        }
        return najraniji;
    }
    void IsprazniKolekciju() {
        int n(v.size());
        n--;
        for(int i(n); i>=0; i--)
            v.erase(v.begin()+i);
        broj_pregleda=0;
    }
    void ObrisiNajranijiPregled() {
        Pregled najraniji(DajNajranijiPregled());
        int n(v.size());
        for(int i(0); i<n; i++) {
            if(v[i]->DajImePacijenta()==DajNajranijiPregled().DajImePacijenta()
                    && std::get<0>(v[i]->DajDatumPregleda().Ocitaj())==std::get<0>(DajNajranijiPregled().DajDatumPregleda().Ocitaj())
                    && std::get<1>(v[i]->DajDatumPregleda().Ocitaj())==std::get<1>(DajNajranijiPregled().DajDatumPregleda().Ocitaj())
                    && std::get<2>(v[i]->DajDatumPregleda().Ocitaj())==std::get<2>(DajNajranijiPregled().DajDatumPregleda().Ocitaj())
                    && v[i]->DajVrijemePregleda().Ocitaj().first==DajNajranijiPregled().DajVrijemePregleda().Ocitaj().first
                    && v[i]->DajVrijemePregleda().Ocitaj().second==DajNajranijiPregled().DajVrijemePregleda().Ocitaj().second) {
                v.erase(v.begin()+i);
                break;
            }
        }
        broj_pregleda--;
    }
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
        int n(v.size());
        for(int i(0); i<n; i++) {
            if(v[i]->DajImePacijenta()==ime_pacijenta) {
                v.erase(v.begin()+i);
                n--;
                i--;
                broj_pregleda--;
            }
        }
    }
    void IspisiPregledeNaDatum(const Datum &datum) const {
        std::vector<std::shared_ptr<Pregled>> ve;
        ve=v;
        std::sort(ve.begin(),ve.end(), [] ( std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
            Pregled  &pr1(*(p1)),&pr2(*(p2));
            return(Pregled::DolaziPrije(pr1,pr2));
        });
        for(int i(0); i<v.size(); i++) {
            if(std::get<0>(ve[i]->DajDatumPregleda().Ocitaj())==std::get<0>(datum.Ocitaj()) && std::get<1>(ve[i]->DajDatumPregleda().Ocitaj())==std::get<1>(datum.Ocitaj()) && std::get<2>(ve[i]->DajDatumPregleda().Ocitaj())==std::get<2>(datum.Ocitaj())) ve[i]->Ispisi();
        }
    }
    void IspisiSvePreglede() const {
        std::vector<std::shared_ptr<Pregled>> ve;
        ve=v;
        std::sort(ve.begin(),ve.end(), [] ( std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
            Pregled  &pr1(*(p1)),&pr2(*(p2));
            return(Pregled::DolaziPrije(pr1,pr2));
        });
        std::for_each(ve.begin(),ve.end(), [] (std::shared_ptr<Pregled> p) {
            p->Ispisi();
        });
    }
};


int main ()
{
       Pregledi p;
        int d(1);
        for(int i = 0; i < 20; i++,d++){
            p.RegistrirajPregled(std::make_shared<Pregled>(Pregled("Dalila", {d,d%12+1,2000+d}, {1,1})));
        }
        p.IspisiSvePreglede();
    return 0;
}
