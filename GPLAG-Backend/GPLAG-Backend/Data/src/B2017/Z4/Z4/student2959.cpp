/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <tuple>
#include <memory>


class Datum
{
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int,int,int> Ocitaj() const {
        return std::make_tuple(dan,mjesec,godina);
    }
    void Ispisi() const;
};

class Vrijeme
{
    int sati,minute;
public:
    Vrijeme(int sati, int minute) {
        Postavi(sati,minute);
    }
    void Postavi(int sati, int minute);
    std::pair<int,int>Ocitaj() const {
        return std::make_pair(sati,minute);
    };
    void Ispisi() const;
};

class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):
        datum_pregleda(datum_pregleda),vrijeme_pregleda(vrijeme_pregleda) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
            int sati_pregleda, int minute_pregleda): datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda),
        vrijeme_pregleda(sati_pregleda,minute_pregleda) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum( const Datum &novi_datum) {
        datum_pregleda=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme_pregleda=novo_vrijeme;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda() const {
        return datum_pregleda;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme_pregleda;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};

class Pregledi
{
    std::vector<std::shared_ptr<Pregled>>svi_pregledi;
public:
    explicit Pregledi()=default;
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi()=default;
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi)=default;
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi)=default;
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
                            int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled);
    int DajBrojPregleda() const {
        return svi_pregledi.size();
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

void Datum::Postavi(int dan, int mjesec, int godina)
{
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && godina%100!=0 && godina%400==0) broj_dana[1]++;
    if(godina<1 || mjesec<1 || dan<1 || mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error("Neispravan datum");
    Datum::dan=dan;
    Datum::mjesec=mjesec;
    Datum::godina=godina;
}
void Datum::Ispisi() const
{
    std::cout<<std::get<0>(Ocitaj())<<"/"<<std::get<1>(Ocitaj())<<"/"<<std::get<2>(Ocitaj());
}

void Vrijeme::Postavi(int sati, int minute)
{
    if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati=sati;
    Vrijeme::minute=minute;
}
void Vrijeme::Ispisi() const
{
    std::cout<<std::right<<std::setw(2)<<std::setfill('0')<<Ocitaj().first<<":"<<
             std::setw(2)<<std::setfill('0')<<Ocitaj().second<<std::setfill(' ');
}

void Pregled::PomjeriDanUnaprijed()
{
    int d,m,g;
    std::tie(d,m,g)=DajDatumPregleda().Ocitaj();
    d++;
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && g%100!=0 && g%400==0) broj_dana[1]++;
    if(d>broj_dana[m-1]) {
        d=1;
        m++;
    }
    if(m>12) {
        m=1;
        g++;
    }
    PromijeniDatum({d,m,g});
}
void Pregled::PomjeriDanUnazad()
{
    int d,m,g;
    std::tie(d,m,g)=DajDatumPregleda().Ocitaj();
    d--;
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && g%100!=0 && g%400==0) broj_dana[1]++;
    if(d==0) {
        m--;
        if(m<1) {
            m=12;
            g--;
        }
        d=broj_dana[m-1];
    }
    PromijeniDatum({d,m,g});
}
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2)
{
    int d1,d2,m1,m2,g1,g2;
    std::tie(d1,m1,g1)=p1.DajDatumPregleda().Ocitaj();
    std::tie(d2,m2,g2)=p2.DajDatumPregleda().Ocitaj();
    if(g1<g2) return true;
    if(g1==g2 && m1<m2) return true;
    if(g1==g2 && m1==m2 && d1<d2) return true;
    if(g1==g2 && m1==m2 && d1==d2) {
        int s1,s2,min1,min2;
        std::tie(s1,min1)=p1.DajVrijemePregleda().Ocitaj();
        std::tie(s2,min2)=p2.DajVrijemePregleda().Ocitaj();
        if(s1<s2) return true;
        if(s1==s2 && min1<min2) return true;
    }
    return false;
}
void Pregled::Ispisi() const
{
    std::cout<<std::left<<std::setw(30)<<DajImePacijenta();
    DajDatumPregleda().Ispisi();
    std::cout<<" ";
    DajVrijemePregleda().Ispisi();
    std::cout<<std::endl;
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda)
{
    auto it=spisak_pregleda.begin();
    for(int i=0; i<spisak_pregleda.size(); i++) {
        svi_pregledi.push_back(std::make_shared<Pregled>(*it++));
    }
}

Pregledi::Pregledi(const Pregledi &pregledi): svi_pregledi(pregledi.svi_pregledi.size())
{
   for(int i=0;i<pregledi.svi_pregledi.size();i++){
       svi_pregledi[i]=std::make_shared<Pregled>(*pregledi.svi_pregledi[i]);
   }
}
Pregledi &Pregledi::operator =(const Pregledi &pregledi)
{
    svi_pregledi.resize(pregledi.svi_pregledi.size());
    for(int i=0;i<pregledi.svi_pregledi.size();i++){
        svi_pregledi[i]=std::make_shared<Pregled>(*pregledi.svi_pregledi[i]);
    }
    return *this;
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    svi_pregledi.push_back(std::make_shared<Pregled>(Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda)));
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
                                  int sati_pregleda, int minute_pregleda)
{
    svi_pregledi.push_back(std::make_shared<Pregled>((Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda))));
}
void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled)
{
    svi_pregledi.push_back(pregled);
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    return std::count_if(svi_pregledi.begin(),svi_pregledi.end(),[datum](std::shared_ptr<Pregled> p) {
        return (p->DajDatumPregleda().Ocitaj()==datum.Ocitaj());
    });
}
Pregled &Pregledi::DajNajranijiPregled()
{
    if(svi_pregledi.size()==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(svi_pregledi.begin(),svi_pregledi.end(),[](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1,*p2);
    });
}
Pregled Pregledi::DajNajranijiPregled() const
{
    if(svi_pregledi.size()==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(svi_pregledi.begin(),svi_pregledi.end(),[](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1,*p2);
    });
}
void Pregledi::IsprazniKolekciju()
{
    svi_pregledi.resize(0);
}
void Pregledi::ObrisiNajranijiPregled()
{
    if(svi_pregledi.size()==0) throw std::range_error("Prazna kolekcija");
    auto izbaci=std::find_if(svi_pregledi.begin(),svi_pregledi.end(),[this](std::shared_ptr<Pregled> p) {
        Pregled najraniji=DajNajranijiPregled();
        return (p->DajImePacijenta()==najraniji.DajImePacijenta() &&
                p->DajDatumPregleda().Ocitaj()==najraniji.DajDatumPregleda().Ocitaj() &&
                p->DajVrijemePregleda().Ocitaj()==najraniji.DajVrijemePregleda().Ocitaj());
    });
    svi_pregledi.erase(izbaci);
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    for(;;) {
        auto izbaci=std::find_if(svi_pregledi.begin(),svi_pregledi.end(),[ime_pacijenta](std::shared_ptr<Pregled> p) {
            return (p->DajImePacijenta()==ime_pacijenta);
        });
        if(izbaci==svi_pregledi.end()) return;
        svi_pregledi.erase(izbaci);
    }
}
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    std::vector<std::shared_ptr<Pregled>> novo_mjesto;
    novo_mjesto=svi_pregledi;
    std::sort(novo_mjesto.begin(),novo_mjesto.end(),[](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1,*p2);
    });
    std::for_each(novo_mjesto.begin(),novo_mjesto.end(),[datum](std::shared_ptr<Pregled> p1) {
        if(datum.Ocitaj()==p1->DajDatumPregleda().Ocitaj()) p1->Ispisi();
    });
}
void Pregledi::IspisiSvePreglede() const
{
    std::vector<std::shared_ptr<Pregled>> novo_mjesto;
    novo_mjesto=svi_pregledi;
    std::sort(novo_mjesto.begin(),novo_mjesto.end(),[](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
        return Pregled::DolaziPrije(*p1,*p2);
    });
    std::for_each(novo_mjesto.begin(),novo_mjesto.end(),[](std::shared_ptr<Pregled> p1) {
        p1->Ispisi();
    });
}


int main(){
    Pregledi pregledi;
    for(;;) {
        std::string ime_pacijenta;
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::getline(std::cin,ime_pacijenta);
        if(ime_pacijenta=="kraj") break;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        int d,m,g;
        std::cin>>d>>m>>g;
        std::cout<<"Unesite sate i minute pregleda: ";
        int s,min;
        std::cin>>s>>min;
        pregledi.RegistrirajPregled(ime_pacijenta,d,m,g,s,min);
        std::cin.ignore(1000,'\n');
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
    pregledi.IspisiSvePreglede();
    for(;;) {
        std::cout<<std::endl<<"Odaberite jednu od sljedecih opcija"<<std::endl
                 <<"1 - Broj pregleda na datum"<<std::endl
                 <<"2 - Najraniji pregled"<<std::endl
                 <<"3 - Obrisi pregled pacijenta"<<std::endl
                 <<"4 - Obrisi najraniji pregled"<<std::endl
                 <<"5 - Ispisi sve pregleda na datum"<<std::endl
                 <<"6 - Ispisi sve preglede"<<std::endl
                 <<"7 - Kraj programa"<<std::endl;
        int opcija;
        std::cin>>opcija;
        int d,m,g,prije,poslije;
        std::string ime_pacijenta;
        switch(opcija) {
        case 1:
            std::cout<<"Unesite dan mjesec i godinu : ";
            std::cin>>d>>m>>g;
            std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<pregledi.DajBrojPregledaNaDatum(Datum(d,m,g))<<std::endl;
            break;
        case 2:
            std::cout<<"Najraniji pregled je:"<<std::endl;
            pregledi.DajNajranijiPregled().Ispisi();
            break;
        case 3:
            std::cout<<"Unesite ime pacijenta: ";
            std::cin.ignore(1000,'\n');
            std::getline(std::cin,ime_pacijenta);
            prije=pregledi.DajBrojPregleda();
            pregledi.ObrisiPregledePacijenta(ime_pacijenta);
            poslije=pregledi.DajBrojPregleda();
            std::cout<<"Uspjesno obrisano "<<prije-poslije<<" pregleda"<<std::endl;
            break;
        case 4:
            pregledi.ObrisiNajranijiPregled();
            std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
            break;
        case 5:
            std::cout<<"Unesite dan mjesec i godinu : ";
            std::cin>>d>>m>>g;
            std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su: "<<std::endl;
            pregledi.IspisiPregledeNaDatum(Datum(d,m,g));
            break;
        case 6:
            pregledi.IspisiSvePreglede();
            break;
        case 7:
            return 0;
        }
    }
    return 0;
}


