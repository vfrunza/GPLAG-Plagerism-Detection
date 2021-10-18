/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <iomanip>
#include <string>

class Datum {
    int dan,mjesec,godina;
    int BrojDana(int mjesec, int godina);
    public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(dan,mjesec,godina);
    }
    void Ispisi() const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
    friend class Pregled;
};

int Datum::BrojDana(int mjesec, int godina) {
    int brojdana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( (godina%4==0 && godina%100!=0) || godina%400==0 ) brojdana[1]++;
    return brojdana[mjesec-1];
}

void Datum::Postavi(int dan, int mjesec, int godina) {
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>BrojDana(mjesec, godina) ) 
        throw std::domain_error ("Neispravan datum");
    Datum::dan=dan;
    Datum::mjesec=mjesec;
    Datum::godina=godina;
}

class Vrijeme {
    int sati, minute;
    public:
    Vrijeme(int sati, int minute) { Postavi(sati,minute); }
    void Postavi(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59)
            throw std::domain_error ("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    std::pair<int, int> Ocitaj() const { return {sati, minute}; }
    void Ispisi() const {
        std::cout<<std::setfill('0')<<std::setw(2)<<sati<<":"
                 <<std::setfill('0')<<std::setw(2)<<minute;
        std::cout<<std::setfill(' ');
    }
    friend class Pregled;
};

class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
            const Vrijeme &vrijeme_pregleda);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, 
            int godina_pregleda, int sati_pregleda, int minute_pregleda);
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
        datum_pregleda.dan++;
        datum_pregleda=Datum(datum_pregleda.dan,datum_pregleda.mjesec,datum_pregleda.godina);
    }
    void PomjeriDanUnazad() { 
        datum_pregleda.dan--;
        datum_pregleda=Datum(datum_pregleda.dan,datum_pregleda.mjesec,datum_pregleda.godina);
    }
    std::string DajImePacijenta() const { return ime_pacijenta; }
    Datum DajDatumPregleda() const { return datum_pregleda; }
    Vrijeme DajVrijemePregleda() const { return vrijeme_pregleda; }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const {
        std::cout<<std::left<<std::setw(30)<<DajImePacijenta()<<std::right;
        datum_pregleda.Ispisi();
        std::cout<<" ";
        vrijeme_pregleda.Ispisi();
        std::cout<<std::endl;
    }
};

Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
        const Vrijeme &vrijeme_pregleda) : ime_pacijenta(ime_pacijenta),
            datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) { }
            
Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, 
        int godina_pregleda, int sati_pregleda, int minute_pregleda) :
            ime_pacijenta(ime_pacijenta),
            datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda),
            vrijeme_pregleda(sati_pregleda,minute_pregleda) { }
        
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    if(p1.datum_pregleda.godina<p2.datum_pregleda.godina) return true;
    else if(p1.datum_pregleda.godina>p2.datum_pregleda.godina) return false;
    if(p1.datum_pregleda.mjesec<p2.datum_pregleda.mjesec) return true;
    else if(p1.datum_pregleda.mjesec>p2.datum_pregleda.mjesec) return false;
    if(p1.datum_pregleda.dan<p2.datum_pregleda.dan) return true;
    else if(p1.datum_pregleda.dan>p2.datum_pregleda.dan) return false;
    if(p1.vrijeme_pregleda.sati<p2.vrijeme_pregleda.sati) return true;
    else if(p1.vrijeme_pregleda.sati>p2.vrijeme_pregleda.sati) return false;
    if(p1.vrijeme_pregleda.minute<p2.vrijeme_pregleda.minute) return true;
    else if(p1.vrijeme_pregleda.minute>p2.vrijeme_pregleda.minute) return false;
    throw std::domain_error ("Isti termini");
}

class Pregledi {
    const int max_broj_pregleda;
    Pregled **niz;
    public:
    explicit Pregledi(int max_broj_pregleda) : max_broj_pregleda(max_broj_pregleda) {
        niz=new Pregled*[max_broj_pregleda];
    }
    
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator=(const Pregledi &pregledi);
    Pregledi &operator=(Pregledi &&pregledi);
    
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
                            const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, 
                            int mjesec_pregleda, int godina_pregleda, 
                            int sati_pregleda, int minute_pregleda);
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
};

int main ()
{
    std::cout<<"Unesite maksimalan broj pregleda: ";
    int max_pregledi;
    std::cin>>max_pregledi;
    Pregledi pacijenti(max_pregledi);
    int i(0);
    for( ; ; ){
        std::cin.ignore(10000, '\n');
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string ime;
        std::getline(std::cin, ime);
        if(ime=="kraj") break;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        int dan,mj,god;
        std::cin>>dan>>mj>>god;
        std::cout<<"Unesite sate i minute pregleda: ";
        int h,m;
        std::cin>>h>>m;
        pacijenti[i]={ime, dan, mj, god, h, m};
        i++;
        if(i==max_pregledi) break;
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi: \n";
    pacijenti.IspisiSvePreglede();
    
    while(1){
        std::cout<<"Odaberite jednu od sljedecih opcija\n"
                 <<"1 - Broj pregleda na datum\n"
                 <<"2 - Najraniji pregled\n"
                 <<"3 - Obrisi pregled pacijenta\n"
                 <<"4 - Obrisi najraniji pregled\n"
                 <<"5 - Ispisi sve pregleda na datum\n"
                 <<"6 - Ispisi sve preglede\n"
                 <<"7 - Kraj programa\n";
        int br;
        std::cin>>br;
        if(br==7) break;
        else if(br==6) pacijenti.IspisiSvePreglede();
        else if(br==5) pacijenti.IspisiPregledeNaDatum();
        else if(br==4) pacijenti.ObrisiNajranijiPregled();
        else if(br==3) pacijenti.ObrisiPregledePacijenta();
        else if(br==2) DajNajranijiPregled;
        else if(br==1) {
            std::cout<<"Unesite dan mjesec i godinu : ";
            int dan,mj,god;
            std::cin>>dan>>mj>>god;
            Datum d(dan,mj,god);
            std::cout<<"Broj pregleda na datum "<<dan<<" "<<mj<<" "<<god
                     <<" je: "<<DajBrojPregledaNaDatum(d);
        }
    }
             
	return 0;
}
