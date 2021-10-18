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
        std::tuple<int,int,int> t {dan,mjesec,godina};
        return t;
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
    int max;
    int broj_pregleda;
    Pregled **v;
public:
    explicit Pregledi(int max_broj_pregleda) : broj_pregleda(0), max(max_broj_pregleda),
        v(new Pregled*[max_broj_pregleda] {}) {
    }
    Pregledi(std::initializer_list<Pregled> spisak_pregleda): broj_pregleda(spisak_pregleda.size()),max(spisak_pregleda.size()), v(new Pregled*[spisak_pregleda.size()] {}) {
        std::initializer_list<Pregled>::iterator it (spisak_pregleda.begin());
        for(int i(0); i<broj_pregleda; i++) {
            Pregled nn(*it);
            Pregled *neki_pregled(&nn);
            v[i]=neki_pregled;
            it++;
        }

    }
    ~Pregledi() {
        if(v!=nullptr) {
            for(int i(0); i<max; i++) delete v[i];
            delete v;
        }
    }
    Pregledi(const Pregledi &pregledi)
        : broj_pregleda(pregledi.broj_pregleda),max(pregledi.max),
        v(new Pregled*[pregledi.max] {}) {
        for(int i(0); i<pregledi.broj_pregleda; i++) {
            v[i]=pregledi.v[i];
        }
    }
    Pregledi(Pregledi &&pregledi) : broj_pregleda(pregledi.broj_pregleda), v(new Pregled*[pregledi.max] {}),max(pregledi.max) {
        for(int i(0); i<pregledi.broj_pregleda; i++) {
            v[i]=pregledi.v[i];
        }
    }
    Pregledi &operator =(const Pregledi &pregledi) {
        Pregled **novi_prostor(new Pregled*[pregledi.max] {});
        for(int i(0); i<pregledi.broj_pregleda; i++) {
            novi_prostor[i]=pregledi.v[i];
        }
        if(v!=nullptr) {
            for(int i(0); i<broj_pregleda; i++) delete v[i];
            delete v;
        }
        max=pregledi.max;
        broj_pregleda = pregledi.broj_pregleda;
        v=novi_prostor;
        return *this;
    }
    Pregledi &operator =(Pregledi &&pregledi) {
        if(&pregledi!=this) {
            if(v!=nullptr) {
                for(int i(0); i<max; i++) delete v[i];
                delete v;
            }
            for(int i(0); i<pregledi.broj_pregleda; i++) {
                v[i]=pregledi.v[i];
                broj_pregleda=pregledi.broj_pregleda;
                for(int i(0); i<pregledi.max; i++) delete pregledi.v[i];
                delete pregledi.v;
            }
        }
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        if(broj_pregleda<max) {
            Pregled *p (new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda));
            v[broj_pregleda++]=p;
        } else throw std::range_error("Dostignut maksimalni broj pregleda");
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
        if(broj_pregleda<max) {
            Pregled *p (new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda));
            v[broj_pregleda++]=p;
        } else throw std::range_error("Dostignut maksimalni broj pregleda");
    }
    void RegistrirajPregled(Pregled *pregled) {
        if(broj_pregleda<max) {
            v[broj_pregleda++]=pregled;
        } else throw std::range_error("Dostignut maksimalni broj pregleda");
    }
    int DajBrojPregleda() const {
        return broj_pregleda;
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const {

        int brojac(std::count_if(v,v+broj_pregleda,[&datum] (Pregled *p) {
            return(std::get<0>(p->DajDatumPregleda().Ocitaj())==std::get<0> (datum.Ocitaj()) &&
                   std::get<1>(p->DajDatumPregleda().Ocitaj())==std::get<1> (datum.Ocitaj()) &&
                   std::get<2>(p->DajDatumPregleda().Ocitaj())==std::get<2> (datum.Ocitaj()));
        }));
        if(brojac!=0) return brojac;
        else throw std::domain_error("Nema registriranih pregleda");
    }
    Pregled &DajNajranijiPregled() {
        int b(**(std::min_element(v,v+broj_pregleda, [] (Pregled *p1, Pregled *p2) {
            return(Pregled::DolaziPrije(*p1,*p2));
        })));
        if(b!=0) return b;
        else throw std::domain_error("Nema registriranih pregleda");
    }
    Pregled DajNajranijiPregled() const {
        int b(**(std::min_element(v,v+broj_pregleda, [] (Pregled *p1, Pregled *p2) {
            return(Pregled::DolaziPrije(*p1,*p2));
        })));
        if(b!=0) return b;
        else throw std::domain_error("Nema registriranih pregleda");

    }
    void IsprazniKolekciju() {
        for(int i(0); i<max; i++) delete v[i];
        delete v;
        v=new Pregled*[max] {};
        broj_pregleda=0;
    }
    void ObrisiNajranijiPregled() {
        if(broj_pregleda!=0)  {
            Pregled **novi(v);
            std::sort(novi,novi+broj_pregleda, [] ( Pregled *p1,Pregled *p2) {
                return(Pregled::DolaziPrije(*p1,*p2));
            });
            for(int i(0); i<broj_pregleda; i++) delete v[i];
            delete v;
            v=new Pregled*[max] {};
            int j(0);
            for(int i(1); i<broj_pregleda-1; i++) {
                v[j]=novi[i];
                j++;
            }
            for(int i(0); i<max; i++) delete novi[i];
            delete novi;
            broj_pregleda--;
        }

        else throw std::range_error("Prazna kolekcija");
    }
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
        int i(0);
        std::vector<int> b (0);
        Pregled **novi(v);
        std::for_each(novi,novi+broj_pregleda, [ime_pacijenta,&i,&b] (Pregled *p) {
            if(p->DajImePacijenta()==ime_pacijenta)  b.push_back(i);
            i++;
        } );
        for(int i(0); i<max; i++) delete v[i];
        delete v;
        v=new Pregled*[max] {};
        int j(0);
        bool T(false);
        for(int i(1); i<broj_pregleda; i++) {
            T=false;
            for(int k(0); k<b.size(); k++) {
                if(b[k]==i) T=true;
            }
            if(T) continue;
            v[j]=novi[i];
            j++;
        }
        for(int i(0); i<broj_pregleda; i++) delete novi[i];
        delete novi;
        broj_pregleda-=b.size();
    }
    void IspisiPregledeNaDatum(const Datum &datum) const {
        Pregled **novi(v);
        std::sort(novi,novi+broj_pregleda, [] ( Pregled *p1,Pregled *p2) {
            return(Pregled::DolaziPrije(*p1,*p2));
        });
        std::for_each(novi,novi+broj_pregleda, [datum] (Pregled *p) {
            if(std::get<0>(p->DajDatumPregleda().Ocitaj())==std::get<0> (datum.Ocitaj()) &&
                    std::get<1>(p->DajDatumPregleda().Ocitaj())==std::get<1> (datum.Ocitaj()) &&
                    std::get<2>(p->DajDatumPregleda().Ocitaj())==std::get<2> (datum.Ocitaj()))
                p->Ispisi();
        });
    }
    void IspisiSvePreglede() const {
        Pregled **novi(v);
        std::sort(novi,novi+broj_pregleda, [] ( Pregled *p1,Pregled *p2) {
            return(Pregled::DolaziPrije(*p1,*p2));
        });
        std::for_each(novi,novi+broj_pregleda, [] (Pregled *p) {
            p->Ispisi();
        });
    }
};


int main ()
{
    int m_br;
    std::cout<<"Unesite maksimalan broj pregleda: ";
    std::cin>>m_br;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
    Pregledi pacijenti(m_br);
    while(true) {
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string ime;
        std::getline(std::cin,ime);
        if(ime=="kraj") {
            std::cin.ignore(1000,'\n');
            std::cin.clear();
            break;
        }
        int dan,mjesec,godina,sati,minute;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        std::cin>>dan;
        std::cin>>mjesec;
        std::cin>>godina;
        std::cout<<"Unesite sate i minute pregleda: ";
        std::cin>>sati;
        std::cin>>minute;
        pacijenti.RegistrirajPregled(ime,dan,mjesec,godina,sati,minute);
        std::cin.clear();
        std::cin.ignore(1000,'\n');
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
    pacijenti.IspisiSvePreglede();
    std::cout<<std::endl;
    while(true) {
        std::cout<<"Odaberite jednu od sljedecih opcija"<<std::endl;
        std::cout<<"1 - Broj pregleda na datum"<<std::endl;
        std::cout<<"2 - Najraniji pregled"<<std::endl;
        std::cout<<"3 - Obrisi pregled pacijenta"<<std::endl;
        std::cout<<"4 - Obrisi najraniji pregled"<<std::endl;
        std::cout<<"5 - Ispisi sve pregleda na datum"<<std::endl;
        std::cout<<"6 - Ispisi sve preglede"<<std::endl;
        std::cout<<"7 - Kraj programa"<<std::endl;
        int opcija;
        std::cin>>opcija;
        if(opcija==1) {
            std::cout<<"Unesite dan mjesec i godinu : ";
            int d,m,g;
            std::cin>>d>>m>>g;
            Datum const dat(d,m,g);
            std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<pacijenti.DajBrojPregledaNaDatum(dat)<<std::endl;
        } else if(opcija==2) {
            std::cout<<"Najraniji pregled je :"<<std::endl;
            pacijenti.DajNajranijiPregled().Ispisi();
        } else if(opcija==3) {
            int brojac(pacijenti.DajBrojPregleda());
            std::string n;
            std::cin.ignore(1000,'\n');
            std::cin.clear();
            std::getline(std::cin,n);
            pacijenti.ObrisiPregledePacijenta(n);
            brojac-=pacijenti.DajBrojPregleda();
            std::cout<<"Uspjesno obrisano "<<brojac<<" pacijenata";
        } else if(opcija==4) {
            if(pacijenti.DajBrojPregleda()>0) {
                pacijenti.ObrisiNajranijiPregled();
                std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
            }
        } else if(opcija==5) {
            std::cout<<"Unesite dan mjesec i godinu : ";
            int dan,mjesec,godina;
            std::cin>>dan;
            std::cin>>mjesec;
            std::cin>>godina;
            Datum dat(dan,mjesec,godina);
            std::cout<<"Pregledi na datum "<<dan<<" "<<mjesec<<" "<<godina<<" su:"<<std::endl;
            pacijenti.IspisiPregledeNaDatum(dat);
        } else if(opcija==6) {
            pacijenti.IspisiSvePreglede();
        } else if(opcija==7) break;
        std::cout<<std::endl;
        std::cin.clear();
        std::cin.ignore(1000,'\n');
    }
    return 0;
}
