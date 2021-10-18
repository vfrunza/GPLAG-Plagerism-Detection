/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <initializer_list>
#include <string>
#include <memory>
#include <vector>

//uraditi pregled dolazi prije

class Datum
{
    int dan, mjesec, godina;
public:
    Datum (int dan, int mjesec, int godina) {
        Postavi(dan, mjesec, godina);
    };
    void Postavi (int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const {
        int a(dan), b(mjesec), c(godina);
        return std::tie<int, int, int> (a,b,c);
    };
    void Ispisi() const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};

void Datum::Postavi (int dan, int mjesec, int godina)
{
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0)
        broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error("Neispravan datum"); //pr ispis
    Datum::dan=dan;
    Datum::mjesec=mjesec;
    Datum::godina=godina;
}

class Vrijeme
{
    int sati, minute;
public:
    Vrijeme (int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59)
            throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    void Postavi (int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59)
            throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    std::pair<int, int> Ocitaj () const;
    void Ispisi() const;
};

std::pair<int, int> Vrijeme::Ocitaj() const
{
    return std::make_pair (sati, minute);
}

void Vrijeme::Ispisi() const
{
    if(sati<10) std::cout<<"0";
    std::cout<<sati<<":";
    if(minute<10) std::cout<<"0";
    std::cout<<minute;
}

class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda,
             const Vrijeme &vrijeme_pregleda) : ime_pacijenta(ime_pacijenta),
        datum_pregleda (datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {}
    Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
             int godina_pregleda, int sati_pregleda, int minute_pregleda) :
        ime_pacijenta(ime_pacijenta), datum_pregleda(Datum(dan_pregleda, mjesec_pregleda, godina_pregleda)),
        vrijeme_pregleda(Vrijeme(sati_pregleda, minute_pregleda)) {}
    void PromijeniPacijenta (const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta=ime_pacijenta;
    };
    void PromijeniDatum (const Datum &novi_datum) {
        auto pomocni(novi_datum.Ocitaj());
        datum_pregleda.Postavi(std::get<0> (pomocni), std::get<1> (pomocni),
                               std::get<2> (pomocni));
    };
    void PromijeniVrijeme (const Vrijeme &novo_vrijeme) {
        auto pomocni(novo_vrijeme.Ocitaj());
        vrijeme_pregleda.Postavi(pomocni.first, pomocni.second);
    };
    void PomjeriDanUnaprijed ();
    void PomjeriDanUnazad ();
    std::string DajImePacijenta () const {
        return ime_pacijenta;
    };
    Datum DajDatumPregleda () const {
        return datum_pregleda;
    };
    Vrijeme DajVrijemePregleda () const {
        return vrijeme_pregleda;
    };
    static bool DolaziPrije (const Pregled &p1, const Pregled &p2);
    void Ispisi () const;
};

bool Pregled::DolaziPrije (const Pregled &p1, const Pregled &p2)         //true ako je prvi pregled zakazan prije drugog
{
    auto pom(p1.DajDatumPregleda());
    auto pom1(pom.Ocitaj());
    int d1=std::get<0> (pom1);
    int mj1=std::get<1> (pom1);
    int g1=std::get<2> (pom1);
    auto pom2(p1.DajVrijemePregleda());
    auto pom3(pom2.Ocitaj());
    int h1=pom3.first;
    int m1=pom3.second;
    pom=p2.DajDatumPregleda();
    pom1=pom.Ocitaj();
    int d2=std::get<0> (pom1);
    int mj2=std::get<1> (pom1);
    int g2=std::get<2> (pom1);
    pom2=p2.DajVrijemePregleda();
    pom3=pom2.Ocitaj();
    int h2=pom3.first;
    int m2=pom3.second;
    if(g1!=g2) return g1<g2;
    else if(g1==g2 && mj1!=mj2) return mj1<mj2;
    else if(g1==g2 && mj1==mj2 && d1!=d2) return d1<d2;
    else if(g1==g2 && mj1==mj2 && d1==d2 && h1!=h2) return h1<h2;
    else return m1<m2;
}

void Pregled::PomjeriDanUnaprijed()
{
    auto pomocni(datum_pregleda.Ocitaj());
    int d=std::get<0> (pomocni)+1;
    int m=std::get<1> (pomocni);
    int g=std::get<2> (pomocni);
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(d>broj_dana[m-1]) {
        d-=broj_dana[m-1];
        m++;
    }
    if(m>12) {
        m-=12;
        g++;
    }
    datum_pregleda.Postavi(d,m,g);
}

void Pregled::PomjeriDanUnazad()
{
    auto pomocni(datum_pregleda.Ocitaj());
    int d=std::get<0> (pomocni)-1;
    int m=std::get<1> (pomocni);
    int g=std::get<2> (pomocni);
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(d<1) {
        m--;
        d=broj_dana[m-1];
    }
    if(m<1) {
        m=12;
        d=broj_dana[m-1];
        g--;
    }
    datum_pregleda.Postavi(d, m, g);
}

void Pregled::Ispisi() const
{
    std::cout<<std::left<<std::setw(30)<<ime_pacijenta;
    datum_pregleda.Ispisi();
    std::cout<<" ";
    vrijeme_pregleda.Ispisi();
    std::cout<<std::endl;
}

//dinamicki alocirani niz pokazivaca na objekte tipa Pregled
class Pregledi
{
    int max_broj_pregleda;
    Pregled **pregledi_n;                                                       //din alociran niz pokazivaca na objekte tipa Pregled
    void PostaviMax() {
        max_broj_pregleda--;
    }
public:
    explicit Pregledi (int max_broj_pregleda) :  max_broj_pregleda(max_broj_pregleda),
        pregledi_n(new Pregled *[max_broj_pregleda] {}) {};
    Pregledi (std::initializer_list<Pregled> spisak_pregleda);
    Pregledi (std::vector<Pregled> spisak_pregleda);
    ~Pregledi() {
        for(int i=0; i<max_broj_pregleda; i++) delete pregledi_n[i];
        delete[] pregledi_n;
    };
    Pregledi (const Pregledi &pregledi);
    Pregledi (Pregledi &&pregledi);
    Pregledi &operator = (const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled (const std::string &ime_pacijenta,
                             const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda,
                             int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregledi);
    int DajBrojPregleda () const;
    int DajBrojPregledaNaDatum (const Datum &datum) const;
    Pregled &DajNajranijiPregled ();
    //Pregled DajNajranijiPregled () const;
    void IsprazniKolekciju ();
    void ObrisiNajranijiPregled ();
    void ObrisiPregledePacijenta (const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum (const Datum &datum) const;
    void IspisiSvePreglede () const;
};

void Pregledi::ObrisiPregledePacijenta (const std::string &ime_pacijenta) {
    for(int i=0; i<this->DajBrojPregleda(); i++) {
        if(pregledi_n[i]->DajImePacijenta()==ime_pacijenta) {
            delete pregledi_n[i];
            this->PostaviMax();
        }
    }
}

void Pregledi::ObrisiNajranijiPregled () {
    auto min_pregled(this->DajNajranijiPregled()); //ovdje dobijem pregled
    auto min(min_pregled.DajDatumPregleda());
    auto pomocna2(min.Ocitaj());
    int d2=std::get<0> (pomocna2); 
    int m2=std::get<1> (pomocna2);
    int g2=std::get<2> (pomocna2);
    for(int i=0; i<this->DajBrojPregleda(); i++) {
        auto x=pregledi_n[i];
        auto datum_iz_niza(x->DajDatumPregleda());
        auto pomocna1(datum_iz_niza.Ocitaj());
        int d1=std::get<0> (pomocna1);
        int m1=std::get<1> (pomocna1);
        int g1=std::get<2> (pomocna1);
        if(d1==d2 && m1==m2 && g1==g2) {
            delete pregledi_n[i];
            
        }
    }
}

Pregled &Pregledi::DajNajranijiPregled() {
    return *(*std::min_element(pregledi_n, pregledi_n+this->DajBrojPregleda(), [] (Pregled *pok1, Pregled *pok2) {
        return (*pok1).DolaziPrije(*pok1, *pok2);
    }));
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    auto pomocna2(datum.Ocitaj());
    int d1=std::get<0> (pomocna2);
    int m1=std::get<1> (pomocna2);
    int g1=std::get<2> (pomocna2);
    int brojac(0);
    for(int i=0; i<this->DajBrojPregleda(); i++) {
        auto x=pregledi_n[i];
        auto datum_iz_niza(x->DajDatumPregleda());
        auto pomocna1(datum_iz_niza.Ocitaj());
        int d2=std::get<0> (pomocna1);
        int m2=std::get<1> (pomocna1);
        int g2=std::get<2> (pomocna1);
        if(d1==d2 && m1==m2 && g1==g2) brojac++;
    }
    return brojac;
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum ) const {
    auto pomocna2(datum.Ocitaj());
    int d1=std::get<0> (pomocna2);
    int m1=std::get<1> (pomocna2);
    int g1=std::get<2> (pomocna2);
    for(int i=0; i<this->DajBrojPregleda(); i++) {
        auto x=pregledi_n[i];
        auto datum_iz_niza(x->DajDatumPregleda());
        auto pomocna1(datum_iz_niza.Ocitaj());
        int d2=std::get<0> (pomocna1);
        int m2=std::get<1> (pomocna1);
        int g2=std::get<2> (pomocna1);
        if(d1==d2 && m1==m2 && g1==g2) pregledi_n[i]->Ispisi();
    }
}

void Pregledi::IspisiSvePreglede () const {
    for(int i=0; i<this->DajBrojPregleda(); i++)
        pregledi_n[i]->Ispisi();
}

int Pregledi::DajBrojPregleda() const {
    int brojac(0);
    for(int i=0; i<max_broj_pregleda; i++)
        if(pregledi_n[i]!=nullptr) brojac++;
      
        
    return brojac;
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi) {
    //error
    if((*this).DajBrojPregleda()<pregledi.DajBrojPregleda()) {
        try {
            for(int i=(*this).DajBrojPregleda(); i<pregledi.DajBrojPregleda(); i++)
                pregledi_n[i]=new Pregled(*pregledi.pregledi_n[i]);
        } catch (...) {
            for(int i=(*this).DajBrojPregleda(); i<pregledi.DajBrojPregleda();i++) {
                delete pregledi_n[i];
                delete[] pregledi_n;
            }
            throw;
        }
    } else {
        for(int i=(*this).DajBrojPregleda(); i<pregledi.DajBrojPregleda(); i++)
            delete pregledi_n[i];
    }
    max_broj_pregleda=pregledi.max_broj_pregleda;
    for(int i=0; i<pregledi.DajBrojPregleda(); i++)
        *pregledi_n[i]=*pregledi.pregledi_n[i];
    return *this;
}

Pregledi::Pregledi (Pregledi &&pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda) ,
    pregledi_n(pregledi.pregledi_n) {
        pregledi.pregledi_n=nullptr;
        pregledi.max_broj_pregleda=0;
}

Pregledi::Pregledi(const Pregledi &pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda), 
    pregledi_n(new Pregled *[pregledi.max_broj_pregleda] {}){
        try {
            for(int i=0; i<pregledi.max_broj_pregleda; i++)
                pregledi_n[i]=new Pregled(*pregledi.pregledi_n[i]);
        } catch (...) {
            for(int i=0; i<max_broj_pregleda; i++)
                delete pregledi_n[i];
                delete[] pregledi_n;
                throw;
        }
}

Pregledi::Pregledi (std::vector<Pregled> spisak_pregleda) :
    max_broj_pregleda(spisak_pregleda.size()), pregledi_n(new Pregled *[spisak_pregleda.size()] {}) {
    int brojac(0);
    for(auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++) {
        try {
            pregledi_n[brojac]=new Pregled(*it);
            brojac++;
        } catch (...) {
            for(int i=0; i<spisak_pregleda.size(); i++) {
                delete pregledi_n[i];
                pregledi_n[i]=nullptr;
            }
            throw;
        }
    }
}


Pregledi::Pregledi (std::initializer_list<Pregled> spisak_pregleda) :
    max_broj_pregleda(spisak_pregleda.size()), pregledi_n(new Pregled *[spisak_pregleda.size()] {})
{
    int brojac(0);
    for(auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++) {
        try {
            pregledi_n[brojac]=new Pregled(*it);
            brojac++;
        } catch (...) {
            for(int i=0; i<spisak_pregleda.size(); i++) {
                delete pregledi_n[i];
                pregledi_n[i]=nullptr;
            }
            throw;
        }
    }
}

int main ()
{
    std::cout<<"Unesite maksimalan broj pregleda: ";
    int broj_pregleda;
    std::cin>>broj_pregleda;
    std::vector<Pregled> spisak_pregleda;
    //Pregledi evidencija_pacijenata;
   
    for(int i=0; i<broj_pregleda; i++) {
        std::cin.ignore(10000, '\n');
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string ime;
        std::cin>>ime;
        std::string kraj({'k', 'r', 'a', 'j'});
        if(ime==kraj)  
            break;
        std::cin.ignore(10000, '\n');
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        int d, m, g;
        std::cin>>d>>m>>g;
        std::cout<<"Unesite sate i minute pregleda: ";
        int h, min;
        std::cin>>h>>min;
        spisak_pregleda.push_back(Pregled(ime, d, m, g, h, min));

    }
    
    Pregledi evidencija_pacijenata(spisak_pregleda);
    std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
    evidencija_pacijenata.IspisiSvePreglede();
    std::cout<<std::endl;
    for(;;) {
        
    std::cout<<"Odaberite jednu od sljedecih opcija"<<std::endl
        <<"1 - Broj pregleda na datum"<<std::endl
        <<"2 - Najraniji pregled"<<std::endl
        <<"3 - Obrisi pregled pacijenta"<<std::endl
        <<"4 - Obrisi najraniji pregled"<<std::endl
        <<"5 - Ispisi sve pregleda na datum"<<std::endl
        <<"6 - Ispisi sve preglede"<<std::endl
        <<"7 - Kraj programa"<<std::endl;
    int opcija(0);
    
    std::cin>>opcija;
    if(opcija==1) {
        std::cout<<"Unesite dan mjesec i godinu : ";
        int dan, mjesec, godina;
        std::cin>>dan>>mjesec>>godina;
        std::cout<<"Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina
        <<" je : "<<evidencija_pacijenata.DajBrojPregledaNaDatum(Datum(dan, mjesec, godina));
       
    }
    else if(opcija==2) {
        std::cout<<"Najraniji pregled je: ";
        evidencija_pacijenata.DajNajranijiPregled().Ispisi();
        std::cout<<std::endl;
    }
    else if(opcija==3) {
        std::cout<<"Unesite ime pacijenta:";
        std::string ime;
        std::cin>>ime;
        
        evidencija_pacijenata.ObrisiPregledePacijenta(ime);
        std::cout<<std::endl;
        
    }
    else if(opcija==4) {
        evidencija_pacijenata.ObrisiNajranijiPregled();
        std::cout<<"Najraniji pregled uspjesno obrisan";
        std::cout<<std::endl;
    }
    else if(opcija==5) {
        std::cout<<"Unesite dan mjesec i godinu : ";
        int d, m, g;
        std::cin>>d>>m>>g;
        std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su:"<<std::endl;
        evidencija_pacijenata.IspisiPregledeNaDatum(Datum(d, m, g));
        std::cout<<std::endl;
    }
    else if(opcija==6) { //ok
        evidencija_pacijenata.IspisiSvePreglede();
        std::cout<<std::endl;
    }
    else break;
    std::cout<<std::endl;
    }
    /*Pregled p1("Elmira D", 1, 2, 2017, 6, 7);
    Pregled p2("Adisa", 1, 1, 2017, 6, 7);
    Pregledi spisak1({p1, p2});
    //Pregledi spisak2(10);
    //spisak2=spisak1;
    std::cout<<spisak1.DajBrojPregledaNaDatum(Datum(1,2,2017));*/
    

    return 0;
}
