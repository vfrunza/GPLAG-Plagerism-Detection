/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>
class Datum
{
    int d,m,g;
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina) ;
    std::tuple<int, int, int> Ocitaj() const {

        return std::make_tuple(d,m,g);

    }
    void Ispisi() const;
};
Datum::Datum(int dan, int mjesec, int godina)
{
    if(dan<=0 || dan>31 || mjesec<=0 || mjesec>12 || godina<=0) throw std::domain_error("Neispravan datum");
    d=dan;
    m=mjesec;
    g=godina;
}
void Datum::Postavi(int dan, int mjesec, int godina)
{
    if(dan<=0 || dan>31 || mjesec<=0 || mjesec>12 || godina<=0) throw std::domain_error("Neispravan datum");
    d=dan;
    m=mjesec;
    g=godina;
}
void Datum::Ispisi() const
{
    std::cout<<d<<"/"<<m<<"/"<<g;
}
class Vrijeme
{
    int s,m;
public:
    Vrijeme(int sati, int minute) ;
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj () const {
        return std::make_pair(s,m);
    }
    void Ispisi() const;
};
Vrijeme::Vrijeme(int sati, int minute)
{
    if(sati<0|| sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
    s=sati;
    m=minute;
}
void Vrijeme::Postavi(int sati, int minute)
{
    s=sati;
    m=minute;
}

void Vrijeme::Ispisi() const
{
    if(s<10 && m>=10) std::cout<<" 0"<<s<<":"<<m;
    else if(s<10 && m<10)std::cout<<" 0"<<s<<":0"<<m;
    else if(s>=10 && m<10) std::cout<<" "<<s<<":0"<<m;
    else std::cout<<" "<<s<<":"<<m;
}
class Pregled
{
    std::string ime;
    Datum datum;
    Vrijeme v;

public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):ime(ime_pacijenta),datum(datum_pregleda),v(vrijeme_pregleda) {}
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):ime(ime_pacijenta), datum(dan_pregleda, mjesec_pregleda, godina_pregleda), v(sati_pregleda, minute_pregleda) {}
    void PromijeniPacijenta(const std::string &ime_pacijenta);
    void PromijeniDatum(const Datum &novi_datum);
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const {
        return ime;
    }
    Datum DajDatumPregleda() const {
        return datum;
    }
    Vrijeme DajVrijemePregleda() const {
        return v;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        Datum pomoc1 = p1.DajDatumPregleda();
        Datum pomoc2 = p2.DajDatumPregleda();
        if(std::get<2>(pomoc1.Ocitaj())==std::get<2>(pomoc2.Ocitaj())) {
            if(std::get<1>(pomoc1.Ocitaj())==std::get<1>(pomoc2.Ocitaj())) {
                return std::get<0>(pomoc1.Ocitaj())<std::get<0>(pomoc2.Ocitaj());
            } else return std::get<1>(pomoc1.Ocitaj())<std::get<1>(pomoc2.Ocitaj());
        } else  return std::get<2>(pomoc1.Ocitaj())<std::get<2>(pomoc2.Ocitaj());
    }
    void Ispisi() const;
};
void Pregled::PromijeniPacijenta(const std::string &ime_pacijenta)
{
    ime=ime_pacijenta;
}
void Pregled::PromijeniDatum(const Datum &novi_datum)
{
    datum.Postavi(std::get<0>(novi_datum.Ocitaj()),std::get<1>(novi_datum.Ocitaj()),std::get<2>(novi_datum.Ocitaj()));
}
void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme)
{
    v.Postavi((novo_vrijeme.Ocitaj()).first,(novo_vrijeme.Ocitaj()).second);
}
void Pregled::PomjeriDanUnaprijed()
{
    int dani[]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int god=std::get<2>(datum.Ocitaj());
    int daa;
    int mj=std::get<1>(datum.Ocitaj());
    if((god%4==0 && god%100!=0) || god%400==0) dani[1]++;
    if(std::get<0>(datum.Ocitaj())+1>dani[std::get<1>(datum.Ocitaj())-1]) {
        daa=1;
        mj=std::get<1>(datum.Ocitaj())+1;
        if(mj>12) god++;
    } else daa=std::get<0>(datum.Ocitaj())+1;
    datum=Datum(daa,mj,god);
}
void Pregled::PomjeriDanUnazad()
{
    int dani[]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int god=std::get<2>(datum.Ocitaj());
    int daa=std::get<0>(datum.Ocitaj())-1;
    int mj=std::get<1>(datum.Ocitaj());
    if((god%4==0 && god%100!=0) || god%400==0) dani[1]++;
    if(daa==0) {
        daa=dani[mj-2];
        mj--;
        if(-mj==0) god--;
    }
    datum=Datum(daa,mj,god);
}
void Pregled::Ispisi() const
{
    std::cout<<std::setw(30)<<std::left<<ime;
    datum.Ispisi();

    v.Ispisi();

}


class Pregledi
{
    int br_pregleda;
    int max;
    Pregled**pr;
public:
    explicit Pregledi(int max_broj_pregleda):max(max_broj_pregleda),br_pregleda(0),pr(new Pregled*[max_broj_pregleda] {}) {
    }
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi() {
        for(int i=0; i<max; i++) {
            delete pr[i];
        }
        delete []pr;
    }
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) ;
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda,
                            int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const {
        return br_pregleda;
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

    Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda):max(spisak_pregleda.size()) {
        pr=new Pregled *[spisak_pregleda.size()];
        int brojac=0;
        for(auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++) {
            pr[brojac]=new Pregled(*it);
            brojac++;
        }
    }
    
    Pregledi::Pregledi(const Pregledi &pregledi):br_pregleda(pregledi.br_pregleda),max(pregledi.max) {
        pr=new Pregled*[pregledi.max] {};
        for (int i=0; i<max; i++) {
            pr[i]=new Pregled(*(pregledi.pr[i]));
        }
    }
    
    Pregledi::Pregledi(Pregledi &&pregledi):br_pregleda(pregledi.br_pregleda),max(pregledi.max) {
        pr=new Pregled*[pregledi.max] {};
        for (int i=0; i<max; i++) {
            pr[i]=pregledi.pr[i];
            pregledi.pr[i]=nullptr;
        }
        pregledi.pr=nullptr;
    }
    Pregledi & Pregledi::operator =(const Pregledi &pregledi) {
        pr=new Pregled*[pregledi.max] {};
        for(int i=0; i<max; i++) {
            pr[i]=new Pregled(*pregledi.pr[i]);
        }
        return *this;
    }
    Pregledi &Pregledi::operator =(Pregledi &&pregledi) {
        std::swap(pr,pregledi.pr);
        std::swap(br_pregleda,pregledi.br_pregleda);
        std::swap(max,pregledi.max);
        return *this;
    }
    void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        if(br_pregleda==max) throw std::range_error("Dostignut maksimalni broj pregleda");
        pr[br_pregleda]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
        br_pregleda++;
    }
    void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda,
                            int godina_pregleda, int sati_pregleda, int minute_pregleda) {

        if(br_pregleda==max) throw std::range_error("Dostignut maksimalni broj pregleda");
        Datum d(dan_pregleda, mjesec_pregleda, godina_pregleda);
        Vrijeme v(sati_pregleda, minute_pregleda);
        pr[br_pregleda]=new Pregled(ime_pacijenta, d, v);
        br_pregleda++;

    }
    void Pregledi::RegistrirajPregled(Pregled *pregled) {
        if(br_pregleda==max) throw std::range_error("Dostignut maksimalni broj pregleda");
        pr[br_pregleda]=pregled;
        br_pregleda++;
    }
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    return std::count_if(pr,pr+br_pregleda,[datum](Pregled *p) {
        Datum pomoc = p -> DajDatumPregleda();
        if(std::get<0>(pomoc.Ocitaj())==std::get<0>(datum.Ocitaj()) &&
                std::get<1>(pomoc.Ocitaj())==std::get<1>(datum.Ocitaj()) &&
                std::get<2>(pomoc.Ocitaj())==std::get<2>(datum.Ocitaj()))
            return true;
        else return false;
    });
}


void Pregledi::IsprazniKolekciju()
{
    for(int i=0; i<max; i++) {
        delete pr[i];
        pr[i]=nullptr;
    }
}
Pregled &Pregledi::DajNajranijiPregled()
{
    if(br_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    auto it=std::min_element(pr,pr+br_pregleda,[](Pregled *p1,Pregled *p2) {
        return Pregled::DolaziPrije(*p1,*p2);
    });
    return **it;
}
Pregled Pregledi::DajNajranijiPregled() const
{

    if(br_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    auto it=std::min_element(pr,pr+br_pregleda,[](Pregled *p1,Pregled *p2) {
        return Pregled::DolaziPrije(*p1,*p2);
    });
    return **it;
}
void Pregledi::ObrisiNajranijiPregled()
{    
     /*auto it=std::min_element(pr,pr+br_pregleda,[](Pregled *p1,Pregled *p2) {
        return Pregled::DolaziPrije(*p1,*p2);
    });
    delete *it;
    it=nullptr;
    br_pregleda--;*/
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{

    for (int i=0; i<max; i++) {
        if(pr[i] != nullptr)
            if(pr[i]->DajImePacijenta()==ime_pacijenta) {
                delete pr[i];
                pr[i]=nullptr;
                br_pregleda--;
            }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{

    for(int i=0; i<max; i++) {
        if(std::get<0>((pr[i]->DajDatumPregleda()).Ocitaj())==std::get<0>(datum.Ocitaj()) &&
                std::get<1>((pr[i]->DajDatumPregleda()).Ocitaj())==std::get<1>(datum.Ocitaj()) &&
                std::get<2>((pr[i]->DajDatumPregleda()).Ocitaj())==std::get<2>(datum.Ocitaj()))
            pr[i]->Ispisi();
    }
}
void Pregledi::IspisiSvePreglede() const{
   
    for(int i=0; i<max; i++) {
        if(pr[i] != nullptr) {
            pr[i]->Ispisi();
            std::cout<<std::endl;
        }
    }
}
int main ()
{
    std::cout<<"Unesite maksimalan broj pregleda: ";
    int n;

    std::vector<Pregled> p;
    std::cin>>n;
    Pregledi p1= Pregledi(n);
    int ima=0;
    for(;;) {
        if(n==0 )break;
        std::string ime;
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::cin>>ime;

        if(ime=="kraj" ) break;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";

        int d,m,g;
        std::cin>>d>>m>>g;
        try {
            Datum dat=Datum(d,m,g);

            std::cout<<"Unesite sate i minute pregleda: ";
            int s,mi;
            std::cin>>s>>mi;

            Vrijeme vr=Vrijeme(s,mi);
            p.push_back(Pregled(ime,dat,vr));
            p1.RegistrirajPregled(ime, dat, vr);
        } catch(std::domain_error izuzetak) {
            std::cout<<izuzetak.what();
        }
        ima++;
        n--;

    }
    std::sort(p.begin(),p.end(),[](Pregled p1,Pregled p2) {
        if(std::get<2>(p1.DajDatumPregleda().Ocitaj())==std::get<2>(p2.DajDatumPregleda().Ocitaj())) {
            if(std::get<1>(p1.DajDatumPregleda().Ocitaj())==std::get<1>(p2.DajDatumPregleda().Ocitaj())) {
                return std::get<0>(p1.DajDatumPregleda().Ocitaj())<std::get<0>(p2.DajDatumPregleda().Ocitaj());
            } else return std::get<1>(p1.DajDatumPregleda().Ocitaj())<std::get<1>(p2.DajDatumPregleda().Ocitaj());
        } else  return std::get<2>(p1.DajDatumPregleda().Ocitaj())<std::get<2>(p2.DajDatumPregleda().Ocitaj());
    });
    std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
    for(int i=0; i<p.size(); i++) {
        p[i].Ispisi();
        std::cout<<std::endl;
    }
    int br;
    std::cout<<std::endl<<"Odaberite jednu od sljedecih opcija"<<std::endl<<"1 - Broj pregleda na datum"<<std::endl<<
             "2 - Najraniji pregled"<<std::endl<<"3 - Obrisi pregled pacijenta"<<std::endl<<
             "4 - Obrisi najraniji pregled"<<std::endl<<"5 - Ispisi sve pregleda na datum"<<std::endl<<
             "6 - Ispisi sve preglede"<<std::endl<<"7 - Kraj programa"<<std::endl;
    std::cin>>br;
    int duzina=0;
    for(;;) {

        if(br==7) break;
        else if(br==1) {
            std::cout<<"Unesite dan mjesec i godinu : ";
            int m,s,t;
            std::cin>>m>>t>>s;
            Datum d(m,t,s);
            int br=p1.DajBrojPregledaNaDatum(d);
            std::cout<<"Broj pregleda na datum "<<m<<" "<<t<<" "<<s<<" je: "<<br<<std::endl;
        } else if(br==2) {
            std::cout<<"Najraniji pregled je: "<<std::endl;
            p1.DajNajranijiPregled().Ispisi();
            std::cout<<std::endl;
        } else if(br==3) {
            std::cout<<"Unesite ime pacijenta: ";
            std::string novo;
            std::cin>>novo;
            int brk=0;
            p1.ObrisiPregledePacijenta(novo);
            duzina=ima;
            for (int i=0; i<ima; i++) {
                if(p[i].DajImePacijenta()==novo) {
                    brk++;
                    duzina--;
                }

            }

            std::cout<<"Uspjesno obrisano "<<brk<<" pregleda"<<std::endl;
            
        } else if(br==4) {
            p1.ObrisiNajranijiPregled();
            std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
        } else if(br==5) {
            std::cout<<"Unesite dan mjesec i godinu : ";
            int m,s,t;
            std::cin>>m>>t>>s;
            Datum d(m,t,s);
            std::cout<<"Pregledi na datum "<<m<<" "<<t<<" "<<s<<" su: "<<std::endl;

            p1.IspisiPregledeNaDatum(d);
        } else if(br==6) {
            p1.IspisiSvePreglede();
        }

        std::cout<<std::endl<<"Odaberite jednu od sljedecih opcija"<<std::endl<<"1 - Broj pregleda na datum"<<std::endl<<
                 "2 - Najraniji pregled"<<std::endl<<"3 - Obrisi pregled pacijenta"<<std::endl<<
                 "4 - Obrisi najraniji pregled"<<std::endl<<"5 - Ispisi sve pregleda na datum"<<std::endl<<
                 "6 - Ispisi sve preglede"<<std::endl<<"7 - Kraj programa"<<std::endl;
        std::cin>>br;
    }
    return 0;
}
