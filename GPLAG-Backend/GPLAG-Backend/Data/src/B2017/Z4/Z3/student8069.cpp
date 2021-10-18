/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Datum {
    int dan, mjesec, godina;
    int DajDane(Datum d) { return d.dan; }
    int DajMjesec(Datum d) {return d.mjesec; }
    int DajGodinu(Datum d) {return d.godina; }
        
    //}
    public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const;
    void Ispisi() const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
    Datum()=default;
    friend class Pregled;
    friend class Vrijeme;
    friend class Pregledi;
};


void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1  || mjesec>12 || dan>broj_dana[mjesec-1])
    throw std::domain_error("Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}

std::tuple<int, int, int> Datum::Ocitaj() const {
    return std::make_tuple(dan, mjesec, godina);
}

class Vrijeme {
    int sati, minute;
  int DajSate(Vrijeme v) { return v.sati; }
    int DajMinute(Vrijeme v) { return v.minute; }
    public:
    Vrijeme(int sati, int minute) { Postavi(sati, minute); }
    Vrijeme()=default;
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj () const;
    void Ispisi() const {
        if(sati<10) std::cout<<"0";
        std::cout <<sati<<":";
        if(minute<10) std::cout<<"0";
        std::cout<<minute;
    }
    friend class Datum;
    friend class Pregled;
    friend class Pregledi;
};

void Vrijeme::Postavi(int sati, int minute) {
    if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati=sati;
    Vrijeme::minute=minute;
}

std::pair<int, int> Vrijeme::Ocitaj () const {
    return std::make_pair(sati, minute);
}

class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    Pregled()=default;
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
    const Vrijeme &vrijeme_pregleda);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
    int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta(const std::string &ime_pacijenta);
    void PromijeniDatum(const Datum &novi_datum);
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const; // { return ime_pacijenta; }
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda() const;
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
    friend class Vrijeme;
    friend class Pregledi;
    friend class Datum;
};

Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
    const Vrijeme &vrijeme_pregleda) {
        this->ime_pacijenta=ime_pacijenta;
        this->datum_pregleda.Postavi(datum_pregleda.dan, datum_pregleda.mjesec, datum_pregleda.godina);
        this->vrijeme_pregleda.Postavi(vrijeme_pregleda.sati, vrijeme_pregleda.minute);
}

Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
    int godina_pregleda, int sati_pregleda, int minute_pregleda) {
        Pregled::ime_pacijenta=ime_pacijenta;
        this->datum_pregleda.Postavi(dan_pregleda, mjesec_pregleda, godina_pregleda);
        this->vrijeme_pregleda.Postavi(sati_pregleda, minute_pregleda);
}

void Pregled::PromijeniPacijenta(const std::string &ime_pacijenta) {
    this->ime_pacijenta=ime_pacijenta;
}

void Pregled::PromijeniDatum(const Datum &novi_datum) {
   this->datum_pregleda. Postavi(novi_datum.dan, novi_datum.mjesec, novi_datum.godina);
}

void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
     int sati(novo_vrijeme.sati), minute(novo_vrijeme.minute);
     this->vrijeme_pregleda.Postavi(sati, minute);
 }
 
void Pregled::PomjeriDanUnaprijed() {
    this->datum_pregleda.dan++;
    this->datum_pregleda.Postavi(this->datum_pregleda.dan, this->datum_pregleda.mjesec, this->datum_pregleda.godina);
}

void Pregled::PomjeriDanUnazad() {
    this->datum_pregleda.dan--;
    this->datum_pregleda.Postavi(this->datum_pregleda.dan, this->datum_pregleda.mjesec, this->datum_pregleda.godina);
    
}

std::string Pregled::DajImePacijenta() const {
    return this->ime_pacijenta;
}

Datum Pregled::DajDatumPregleda() const {
    return datum_pregleda;
}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    int dan1(p1.datum_pregleda.dan);
    //int dan1(DajDane(p1.datum_pregleda));
    int mjesec1(p1.datum_pregleda.mjesec), godina1(p1.datum_pregleda.godina);
    int dan2(p2.datum_pregleda.dan), mjesec2(p2.datum_pregleda.mjesec), godina2(p2.datum_pregleda.godina);
    if(dan1<dan2 && mjesec1<mjesec2 && godina1<godina2) return true;
    else if(godina1<godina2) {
        if(mjesec1<mjesec2) {
            return(dan1<dan2);
        }
        else if(mjesec1==mjesec2) return(dan1<dan2);
    }
    else if(godina1==godina2) {
        if(mjesec1==mjesec2) return(dan1<dan2);
        else if(mjesec1<mjesec2) return true;
    }
    else if(dan1==dan2 && mjesec1==mjesec2 && godina1==godina2) {
        int sati1(p1.vrijeme_pregleda.sati), minute1(p1.vrijeme_pregleda.minute);
        int sati2(p2.vrijeme_pregleda.sati), minute2(p2.vrijeme_pregleda.minute);
        if(sati1!=sati2) return sati1<sati2;
        else if(sati1==sati2) return minute1<minute2;
    }
    else return false;
}

void Pregled::Ispisi() const {
    std::cout<<std::setw(30)<<std::left<<DajImePacijenta();
    this->datum_pregleda.Ispisi();
    std::cout<<" "; this->vrijeme_pregleda.Ispisi(); std::cout<<std::endl;
}

class Pregledi {
    int max_broj_pregleda;
    int broj_pregleda;
    Pregled** pregledi;
    public:
    explicit Pregledi(int max_broj_pregleda) : broj_pregleda(0), max_broj_pregleda(max_broj_pregleda), pregledi(new Pregled*[max_broj_pregleda]{}) {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi()=default;
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta,
    const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
    int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
    int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
    friend class Datum;
    friend class Pregled;
}; 

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : max_broj_pregleda(spisak_pregleda.size()), broj_pregleda(spisak_pregleda.size()), pregledi(nullptr) {
    try {
        pregledi=new Pregled*[max_broj_pregleda];
        auto it(spisak_pregleda.begin());
        for(int i=0; i<broj_pregleda; i++) {
            pregledi[i]=new Pregled(*it++);
        }
    }
    catch(...) {
        for(int i=0; i<broj_pregleda; i++) {
            delete pregledi[i];
        }
        pregledi=nullptr;
    }
}

Pregledi::~Pregledi() {
    for(int i=0; i<broj_pregleda; i++) delete pregledi[i];
    delete[] pregledi;
}
   
Pregledi::Pregledi(const Pregledi &pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda), pregledi(nullptr) {
    try {
        Pregledi::pregledi=new Pregled*[pregledi.max_broj_pregleda];
        for(int i=0; i<max_broj_pregleda; i++) {
            Pregledi::pregledi[i]=new Pregled(*pregledi.pregledi[i]);
        }
    }
    catch(...) {
        for(int i=0; i<pregledi.broj_pregleda; i++) delete Pregledi::pregledi[i];
        delete[] Pregledi::pregledi;
        throw;
    }
}

Pregledi::Pregledi(Pregledi &&pregledi) : broj_pregleda(pregledi.broj_pregleda), max_broj_pregleda(pregledi.max_broj_pregleda), pregledi(pregledi.pregledi) { 
    pregledi.pregledi=nullptr;
    pregledi.broj_pregleda=0;
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi) {
    if(&pregledi!=this) {
    if(max_broj_pregleda<pregledi.max_broj_pregleda) {
        try {
            for(int i=max_broj_pregleda; i<pregledi.max_broj_pregleda; i++) 
                Pregledi::pregledi[i]=new Pregled(*pregledi.pregledi[i]);
        }
        catch(...) {
            for(int i=max_broj_pregleda; i<pregledi.max_broj_pregleda; i++) delete pregledi.pregledi[i];
            throw;
        }
    }
    else {
        for(int i=0; i<pregledi.max_broj_pregleda; i++) *Pregledi::pregledi[i]=*pregledi.pregledi[i];
    }
    broj_pregleda=pregledi.broj_pregleda;
    max_broj_pregleda=pregledi.max_broj_pregleda;
    }
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi) {
    if(&pregledi!=this) {
        if(max_broj_pregleda<pregledi.max_broj_pregleda) {
            try{
            for(int i=max_broj_pregleda; i<pregledi.max_broj_pregleda; i++) Pregledi::pregledi[i]=new Pregled {};
            }
            catch(...) {
                for(int i=max_broj_pregleda; i<pregledi.max_broj_pregleda; i++) delete Pregledi::pregledi[i];
                throw;
            }
        }
    broj_pregleda=pregledi.broj_pregleda;
        std::swap(broj_pregleda, Pregledi::broj_pregleda);
        std::swap(Pregledi::pregledi, pregledi.pregledi);
    }
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledi[broj_pregleda]=new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    broj_pregleda++;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda) {
    Datum datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda);
    Vrijeme vrijeme_pregleda(sati_pregleda, minute_pregleda);
    RegistrirajPregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    broj_pregleda++;
}

void Pregledi::RegistrirajPregled(Pregled *pregled) {
    if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledi[broj_pregleda]=new Pregled(*pregled);
    broj_pregleda++;
}

int Pregledi::DajBrojPregleda() const {
   return broj_pregleda; 
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    auto pom(pregledi+broj_pregleda);
    return (std::count_if(pregledi, pom, [&datum]  (Pregled *p1) {
      if(datum.dan==p1->datum_pregleda.dan && datum.mjesec==p1->datum_pregleda.mjesec && datum.godina==p1->datum_pregleda.godina) return true;
        return false;
    }
    ));
}

Pregled &Pregledi::DajNajranijiPregled() {
  std::sort(pregledi, pregledi+broj_pregleda, [] (Pregled *p1, Pregled *p2) {
      return Pregled::DolaziPrije(*p1,*p2);
  });
  return **pregledi;
}

Pregled Pregledi::DajNajranijiPregled() const {
    std::sort(pregledi, pregledi+broj_pregleda, [] (Pregled *p1, Pregled *p2) {
      return Pregled::DolaziPrije(*p1,*p2);
  });
  return **pregledi;
}

void Pregledi::ObrisiNajranijiPregled() {
    std::sort(pregledi, pregledi+broj_pregleda, [] (Pregled *p1, Pregled *p2) {
      return Pregled::DolaziPrije(*p1,*p2);
  });
  delete pregledi[0];
  broj_pregleda--;
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    for(int i=0; i<broj_pregleda; i++) {
        if(pregledi[i]->DajImePacijenta()==ime_pacijenta) {
            delete pregledi[i];
            pregledi[i]=nullptr;
            broj_pregleda--;
        }
    }
}
    

void Pregledi::IsprazniKolekciju() {
    for(int i=0; i<broj_pregleda; i++) { delete this->pregledi[i];
    pregledi[i]= nullptr;
    }
    delete[] this->pregledi;
    this->broj_pregleda=0;
    this->max_broj_pregleda=0;
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
    for(int i=0; i<broj_pregleda; i++) {
        if(pregledi[i]->DajDatumPregleda().dan==datum.dan && pregledi[i]->DajDatumPregleda().mjesec==datum.mjesec
        && pregledi[i]->DajDatumPregleda().godina==datum.godina) 
            pregledi[i]->Ispisi();
        }
}

void Pregledi::IspisiSvePreglede() const {
    for(int i=0; i<broj_pregleda; i++) 
        pregledi[i]->Ispisi();
}

int main() {
    cout<<"Unesite maksimalan broj pregleda: ";
    int n;
    cin>>n;
    int broj(0);
    Pregledi p(n);
   // p.max_broj_pregleda(n);
    for(;;) {
    std::string ime;
       // cin>>std::ws;
    cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
    cin>>ime;
    if(ime=="kraj") break;
    cout<<"Unesite dan mjesec i godinu pregleda: ";
    int dan, mjesec, godina;
    cin>>dan>>mjesec>>godina;
    cout<<"Unesite sate i minute pregleda: ";
    int sati,minute;
    cin>>sati>>minute;
    try {
    p.RegistrirajPregled(ime, dan, mjesec, godina, sati, minute);
    }
    catch(std::exception &e) {
        cout<<e.what();
    }
    broj++;
    if(broj==n) break;
    }
    cout<<"Trenutno su registrovai sljedeci pregledi\n";
    p.IspisiSvePreglede();
    int opcija;
    while(1) {
    cout<<"\nOdaberite jednu od sljedecih opcija\n1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n";
    cout<<"4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa";
    cin>>opcija;
    if(opcija==1) {
        int d,m,g;
        cout<<"Unesite dan mjesec i godinu : ";
        cin>>d>>m>>g;
        cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je "<<p.DajBrojPregledaNaDatum(Datum(d,m,g));
    }
    else if(opcija==2) {
        cout<<"Najraniji pregled je:"<<std::endl;
        p.DajNajranijiPregled().Ispisi();
        
    }
    else if(opcija==3) {
        cout<<"Unesite ime pacijenta: ";
        std::string s;
        cin>>s;
        p.ObrisiPregledePacijenta(s);
        cout<<"Uspjesno obrisano 1 pregleda";
    }
    else if(opcija==4) {
        p.ObrisiNajranijiPregled();
        cout<<"Najraniji pregled uspjesno obrisan";
    }
    else if(opcija==5) {
        int d,m,g;
        cout<<"Unesite dan mjesec i godinu: ";
        cin>>d>>m>>g;
        cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su:";
        p.IspisiPregledeNaDatum(Datum(d,m,g));
    }
    else if(opcija==6) {
        p.IspisiSvePreglede();
    }
    else break;
    }
    return 0;
}
