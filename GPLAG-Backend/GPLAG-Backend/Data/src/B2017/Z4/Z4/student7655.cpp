#include <vector>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <tuple>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <memory>
bool Provjeri_datum(int d,int m,int g)
{
    int broj_dana[]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && g%10!=0 || g%400==0)
        broj_dana[1]++;
    if(g<1||m<1||m>12||d<1||d>broj_dana[m-1]) return false;
    return true;
}
int BrojDana(int m,int g)
{
    int broj_dana[]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && g%100!=0 || g%400==0)
        broj_dana[1]++;
    return broj_dana[m-1];
}
bool Provjeri_sat(int h, int m)
{
    if(h<0||h>23||m<0||m>59) return false;
    return true;
}
class Datum
{
public:
    int dan,mjesec,godina;
    Datum(int dan, int mjesec, int godina) {
        if(Provjeri_datum(dan,mjesec,godina)) Datum::dan=dan, Datum::mjesec=mjesec, Datum::godina=godina;
        else throw std::domain_error("Neispravan datum");
    }
    void Postavi(int dan,int mjesec, int godina) {
        if(Provjeri_datum(dan,mjesec,godina))  Datum::dan=dan, Datum::mjesec=mjesec, Datum::godina=godina;
        else throw std::domain_error("Neispravan datum");
    }
    std::tuple<int,int,int> Ocitaj() const {
        std::tuple<int,int,int>d_m_g;
        d_m_g=std::make_tuple(dan,mjesec,godina);
        return d_m_g;
    }
    void Ispisi() const {
        std::cout << dan<<"/"<<mjesec<<"/"<<godina ;
    }
    friend class Pregled;
};
class Vrijeme
{
public:
    int sati,minute;
    Vrijeme(int sati, int minute) {
        if(Provjeri_sat(sati,minute)) Vrijeme::sati=sati, Vrijeme::minute=minute;
        else throw std::domain_error("Neispravno vrijeme");
    }
    void Postavi(int sati,int minute) {
        if(Provjeri_sat(sati,minute)) Vrijeme::sati=sati, Vrijeme::minute=minute;
        else throw std::domain_error("Neispravno vrijeme");
    }
    std::pair<int,int> Ocitaj() const {
        std::pair<int,int>h_m;
        h_m.first=sati;
        h_m.second=minute;
        return h_m;
    }
    void Ispisi() const {
        std::string h_0,m_0;
        if(sati<10) h_0="0";
        if(minute<10) m_0="0";
        std::cout <<h_0<<sati<<":"<<m_0<<minute;
    }
    friend class Pregled;
};
class Pregled
{
public:
    std::string ime_pacijenta;
    Datum datum_pregleda {1,1,1};
    Vrijeme vrijeme_pregleda {0,0};
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        this->ime_pacijenta=ime_pacijenta;
        this->datum_pregleda.Postavi(datum_pregleda.dan,datum_pregleda.mjesec,datum_pregleda.godina);
        this->vrijeme_pregleda.Postavi(vrijeme_pregleda.sati,vrijeme_pregleda.minute);
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda,
            int sati_pregleda,int minute_pregleda) {
        this->ime_pacijenta=ime_pacijenta;
        datum_pregleda.Postavi(dan_pregleda,mjesec_pregleda,godina_pregleda);
        vrijeme_pregleda.Postavi(sati_pregleda,minute_pregleda);
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        this->ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum (const Datum &novi_datum) {
        datum_pregleda.Postavi(novi_datum.dan,novi_datum.mjesec,novi_datum.godina);
    }
    void PromijeniVrijeme (const Vrijeme &novo_vrijeme) {
        vrijeme_pregleda.Postavi(novo_vrijeme.sati,novo_vrijeme.minute);
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda() const {
        return this->datum_pregleda;
    }
    Vrijeme DajVrijemePregleda() const {
        return this->vrijeme_pregleda;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const {
        std::cout << std::left<<std::setw(30)<<ime_pacijenta ;
        (this->datum_pregleda).Ispisi() ;
        std::cout<< " ";
        (this->vrijeme_pregleda).Ispisi() ;
        std::cout<< std::endl;
    }
};

void Pregled::PomjeriDanUnaprijed()
{
    datum_pregleda.dan++;
    if(datum_pregleda.dan>BrojDana(datum_pregleda.mjesec,datum_pregleda.godina)) datum_pregleda.dan=1, datum_pregleda.mjesec++;
    if(datum_pregleda.mjesec>12) datum_pregleda.mjesec=1,datum_pregleda.godina++;
}
void Pregled::PomjeriDanUnazad()
{
    datum_pregleda.dan--;
    if(datum_pregleda.dan<1) {
        int b(BrojDana(datum_pregleda.mjesec-1,datum_pregleda.godina));
        if(datum_pregleda.mjesec==1) b=31;
        datum_pregleda.dan=b;
        datum_pregleda.mjesec--;
    }
    if(datum_pregleda.mjesec<1) datum_pregleda.mjesec=12, datum_pregleda.godina--;
}
bool DolaziPrije(const Pregled *p1, const Pregled *p2)
{
    if(p1->datum_pregleda.godina<p2->datum_pregleda.godina) return true;
    if(p1->datum_pregleda.godina==p2->datum_pregleda.godina) {
        if(p1->datum_pregleda.mjesec<p2->datum_pregleda.mjesec) return true;
        if(p1->datum_pregleda.mjesec==p2->datum_pregleda.mjesec) {
            if(p1->datum_pregleda.dan<p2->datum_pregleda.dan) return true;
            if(p1->datum_pregleda.dan>p2->datum_pregleda.dan) return false;
        }
    }
    return false;
}
class Pregledi
{
public:
    std::vector<std::shared_ptr<Pregled>>pregledi {};
    explicit Pregledi()  { };

    /* Pregledi(std::initializer_list<Pregled> spisak_pregleda) : kapacitet(spisak_pregleda.size()), broj_evidentiranih(0) {
         pregledi=new Pregled *[spisak_pregleda.size()] {};
         int i(0);
         for(auto x : spisak_pregleda) {
             pregledi[i]=new Pregled(x);
             i++;
         }
     } */
    ~Pregledi() {
        for(int i(0); i<pregledi.size(); i++) pregledi[i]=nullptr;
    }
    Pregledi (const Pregledi &pregledi);
    Pregledi (Pregledi &&pregledi);
    Pregledi &operator = (const Pregledi &pregledi);
    Pregledi &operator = (Pregledi &&pregledi); 
    void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, int sati_pregleda,int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr<Pregled>pregled);
    int DajBrojPregleda() {
        return pregledi.size();
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledPacijenata(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede()  {
        std::sort(&pregledi[0], &pregledi[pregledi.size()], [] (std::shared_ptr<Pregled>p1,std::shared_ptr<Pregled>p2) {
            if(p1->datum_pregleda.godina<p2->datum_pregleda.godina) return true;
            if(p1->datum_pregleda.godina==p2->datum_pregleda.godina) {
                if(p1->datum_pregleda.mjesec<p2->datum_pregleda.mjesec) return true;
                if(p1->datum_pregleda.mjesec==p2->datum_pregleda.mjesec) {
                    if(p1->datum_pregleda.dan<p2->datum_pregleda.dan) return true;
                    if(p1->datum_pregleda.dan>p2->datum_pregleda.dan) return false;
                }
            }
            return false; 
        }); 
        for(int i(0); i<pregledi.size(); i++)  pregledi[i]->Ispisi();
    }
    friend class Pregled;
};
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    auto p(std::make_shared<Pregled>(ime_pacijenta,datum_pregleda,vrijeme_pregleda));
    pregledi.push_back(p);
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda,int sati_pregleda,int minute_pregleda)
{
    auto p(std::make_shared<Pregled>(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda));
    pregledi.push_back(p);
}
void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled>pregled)
{
    pregledi.push_back(pregled);
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    int brojac(0);
    int dan(datum.dan),mjesec(datum.mjesec),godina(datum.godina);
    Datum dat(dan,mjesec,godina);
    brojac=std::count_if(pregledi.begin(),pregledi.end(),[dat] (std::shared_ptr<Pregled>p) {
        Datum d(p->DajDatumPregleda());
        if (d.dan==dat.dan&&d.mjesec==dat.mjesec&&d.godina==dat.godina) return true;
        return false;
    } );
    return brojac;
}
Pregled &Pregledi::DajNajranijiPregled()
{
    return *pregledi[0];
}
Pregled Pregledi::DajNajranijiPregled() const
{
    return *pregledi[0];
}

/*void Pregledi::IsprazniKolekciju()
{
    pregledi.resize(0):
} */
void Pregledi::ObrisiNajranijiPregled()
{
    if(pregledi.size()==0) throw std::range_error("Prazna kolelkcija");
    pregledi.erase(pregledi.begin());
}
void Pregledi::ObrisiPregledPacijenata(const std::string &ime_pacijenta)
{
    if(pregledi.size()==0) throw std::range_error("Prazna kolelkcija");
    for(int i(0); i<pregledi.size(); i++) {
        if(pregledi[i]->ime_pacijenta==ime_pacijenta)
            pregledi.erase(pregledi.begin()+i);
    }
}
/*
Pregledi::Pregledi(const Pregledi &pre)
{
    pregledi=pre.pregledi;
}
Pregledi::Pregledi(Pregledi &&pre)
{
    pregledi=pre.pregledi;
}
Pregledi Pregledi::operator = (const Pregledi &pre)
{
    Pregledi p;
    p.pregledi=pre.pregledi;
    return p;
}
Pregledi &Pregledi::operator =(Pregledi &&pre)
{

} */
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    int dan(datum.dan),mjesec(datum.mjesec),godina(datum.godina),brojac(0);
    Datum dat(1,1,1);
    std::cout << "Pregledi na datum "<<dan<<" "<<mjesec<<" "<<godina<<" su:" << std::endl;
    for(int i(0); i<pregledi.size(); i++) {
        dat=pregledi[i]->DajDatumPregleda();
        if(dat.dan==dan&&dat.mjesec==mjesec&&dat.godina==godina) {
            brojac++;
            pregledi[i]->Ispisi();
        }
    }
}
int main ()
{

    Pregledi p;
    for(;;) {
        std::string ime_pacijenta,kraj("kraj");
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::getline(std::cin,ime_pacijenta);
        if(ime_pacijenta==kraj) break;
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        int dan,mjesec,godina;
        std::cin >> dan>>mjesec>>godina;
        Datum datum(dan,mjesec,godina);
        std::cout << "Unesite sate i minute pregleda: ";
        int sati,minute;
        std::cin >> sati>>minute;
        Vrijeme vrijeme(sati,minute);
        p.RegistrirajPregled(ime_pacijenta,dan,mjesec,godina,sati,minute);
        std::cin.ignore(1000,'\n');
    }
    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;

    p.IspisiSvePreglede();
    int izbor(0);
    do {
        std::cout << "\nOdaberite jednu od sljedecih opcija" << std::endl;
        std::cout << "1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n4 - Obrisi najraniji pregled"<<std::endl;
        std::cout << "5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa" << std::endl;
        std::cin >> izbor;
        if(izbor==1) {
            std::cout << "Unesite dan mjesec i godinu : ";
            int d,m,g;
            std::cin >> d>>m>>g;
            Datum dat(d,m,g);
            std::cout <<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<p.DajBrojPregledaNaDatum(dat)<< std::endl;

        }
        if(izbor==2) {
            std::cout << "Najraniji pregled je:" << std::endl;
            auto pregled=p.DajNajranijiPregled();
            pregled.Ispisi();
        }
        if(izbor==3) {
            std::cout << "Unesite ime pacijenta: ";
            std::string s;
            int brojac(0);
            std::cin.ignore(1000,'\n');
            std::getline(std::cin,s);
            for(int i(0); i<p.pregledi.size(); i++) {
                if(p.pregledi[i]->ime_pacijenta==s) brojac++;
            }
            p.ObrisiPregledPacijenata(s);
            std::cout << "Uspjesno obrisano "<<brojac<<" pregleda" << std::endl;
        }
        if(izbor==4) {
            p.ObrisiNajranijiPregled();
            std::cout << "Najraniji pregled uspjesno obrisan"<<std::endl;
        }
        if(izbor==5) {
            std::cout << "Unesite dan mjesec i godinu : ";
            int d,m,g;
            std::cin >> d>>m>>g;
            Datum dat(d,m,g);
            p.IspisiPregledeNaDatum(dat);
        }
        if(izbor==6) p.IspisiSvePreglede();
    } while (izbor!=7);
    return 0;
}
