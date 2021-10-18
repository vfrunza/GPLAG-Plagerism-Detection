/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <tuple>

using namespace std;

class Datum
{
    int dan,mjesec,godina;

public:
    
    Datum( int dan, int mjesec, int godina)
    {
        Postavi(dan,mjesec,godina);
    }
    
    void Postavi(int dan, int mjesec, int godina) {
        if((dan<0 && dan>31) || (mjesec<0 && mjesec>12) || (godina<0 && godina>99999999)) throw("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }

   
    tuple<int, int, int> Ocitaj() const
    {
        tuple<int,int,int> d=make_tuple(dan,mjesec,godina);
        return d;
    }

    void Ispisi() const {
        cout<<dan<<"/"<<mjesec<<"/"<<godina<<endl;
    }
};

class Vrijeme
{
    int sati,minute;

public:

    Vrijeme(int sati,int minute)
    {
        Postavi(sati,minute);
    }
    void Postavi(int sati,int minute) {
        if((sati<0 && sati>23) || (minute<0 && minute>59)) throw("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }


    pair<int,int>Ocitaj() const
    {
        pair<int,int> v=make_pair(sati,minute);
        return v;
    }

    void Ispisi() const {
        cout<<sati<<":"<<minute<<endl;
    }

};


class Pregled
{

    string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;

//int dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda;

public:

    Pregled(const string &ime_pacijenta,const Datum &dan_pregleda,const Vrijeme &vrijeme_pregleda):ime_pacijenta(ime_pacijenta),datum_pregleda(dan_pregleda),vrijeme_pregleda(vrijeme_pregleda){};
    Pregled(const string &ime_pacijenta,const  int dan_pregleda,const  int mjesec_pregleda,const  int godina_pregleda,const  int sati_pregleda,const  int minute_pregleda):
    ime_pacijenta(ime_pacijenta),datum_pregleda(Datum(dan_pregleda,mjesec_pregleda,godina_pregleda)),vrijeme_pregleda(Vrijeme(sati_pregleda,minute_pregleda)){};


    void PromjeniPacijenta(const string &ime_pacijenta) {
            Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromjeniDatum(const Datum &nov_datum) {
        datum_pregleda.Postavi(get<0>(nov_datum.Ocitaj()),get<1>(nov_datum.Ocitaj()),get<2>(nov_datum.Ocitaj()));
    }

    void PromjeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme_pregleda.Postavi(novo_vrijeme.Ocitaj().first,novo_vrijeme.Ocitaj().second );
    }
    void PomjeriDanUnaprijed() {
         datum_pregleda.Postavi(get<0>(datum_pregleda.Ocitaj())+1,get<1>(datum_pregleda.Ocitaj()),get<2>(datum_pregleda.Ocitaj()));
    
    }
    void PomjeriDanUnazad() {
        datum_pregleda.Postavi(get<0>(datum_pregleda.Ocitaj())-1,get<1>(datum_pregleda.Ocitaj()),get<2>(datum_pregleda.Ocitaj()));
    
    }

    string DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda() const {
        return datum_pregleda;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme_pregleda;
    }

    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {

        //if((p1.godina_pregleda<p2.godina_pregleda) && (p1.mjesec_pregleda<p2.mjesec_pregleda) && (p1.dan_pregleda<p2.dan_pregleda))
            return true;
        return false;
    }

    void Ispisi() const {
        cout<<fixed<<left<<setprecision(30)<<ime_pacijenta<<endl;
        datum_pregleda.Ispisi();
        vrijeme_pregleda.Ispisi();

    }

};

class Pregledi
{
    int stanje,kapacitet;
    Pregled **niz;

public:

    explicit Pregledi(int max_broj_pregleda)
    {
        stanje=0;
        kapacitet=max_broj_pregleda;
        niz=new Pregled*[kapacitet];
    }
    
    Pregledi(initializer_list<Pregled> spisak_pregleda)
    {
        stanje=0;
        
        for(auto it=spisak_pregleda.begin();it!=spisak_pregleda.end();it++)
                 niz[stanje++]=new Pregled(*it);
                 
        kapacitet=spisak_pregleda.size();
    }
    
    ~Pregledi()
    {
        for(int i=0;i<stanje;i++)
               delete niz[i];
        delete[] niz;
    }
    Pregledi(const Pregledi &pregledi)
    {
        stanje=pregledi.stanje;
        kapacitet=pregledi.kapacitet;
        
        niz=new Pregled*[kapacitet];
        for(int i=0;i<stanje;i++)
               niz[i]=new Pregled(*pregledi.niz[i]);
        
        
    }
    Pregledi(Pregledi &&pregledi)
    {
        stanje=pregledi.stanje;
        kapacitet=pregledi.kapacitet;
        
        niz=new Pregled*[kapacitet];
        for(int i=0;i<stanje;i++)
               niz[i]=new Pregled(*pregledi.niz[i]);
        
        
        for(int i=0;i<stanje;i++)
            pregledi.niz[i]=nullptr;
        delete[] pregledi.niz;
        
    }
    Pregledi &operator = (const Pregledi &pregledi)
    {
        if(this==&pregledi) return *this;
        
        for(int i=0;i<stanje;i++)
            delete niz[i];
        delete[] niz;
        
        stanje=pregledi.stanje;
        kapacitet=pregledi.kapacitet;
        
        niz=new Pregled*[kapacitet];
        for(int i=0;i<stanje;i++)
               niz[i]=new Pregled(*pregledi.niz[i]);
        
        return *this;    
    }
    Pregledi &operator =(Pregledi &&pregledi)
    {
        if(this==&pregledi) return *this;
        
        for(int i=0;i<stanje;i++)
            delete niz[i];
        delete[] niz;
        
        stanje=pregledi.stanje;
        kapacitet=pregledi.kapacitet;
        
        niz=new Pregled*[kapacitet];
        for(int i=0;i<stanje;i++)
               niz[i]=new Pregled(*pregledi.niz[i]);
        
        
        for(int i=0;i<stanje;i++)
            pregledi.niz[i]=nullptr;
        delete[] pregledi.niz;
        
        return *this;
    }
    
    void RegistrirajPregled(const string &ime_pacijenta, const Datum &dan_pregleda, const Vrijeme &vrijeme_pregleda)
    {
        niz[stanje++]=new Pregled(ime_pacijenta,dan_pregleda,vrijeme_pregleda);
    }
    void RegistrirajPregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
    {
        niz[stanje++]=new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
    }

    void RegistrirajPregled(Pregled *pregled)
    {
        niz[stanje++]=new Pregled(*pregled);
    }

    int DajBrojPregleda() const
    {   
        
        return stanje;
        
    }
    
    int DajBrojPregledaNaDatum(const Datum &datum) const;

    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
        
    void IsprazniKolekciju()
    {
        for(int i=0;i<stanje;i++)
            niz[i]=nullptr;
        stanje=0;
    }
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenata(const string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const
    {
        
        for(int i=0;i<stanje;i++)
           niz[i]->Ispisi();
    }

};


int main ()
{   
    
    string ime_pacijenta;
    int brojPregleda;
    int dan,mjesec,godina,sati,minute;
    int opcija;


    cout<<"Unesite maksimalan broj pregleda: ";
    cin>>brojPregleda;
    Pregledi p(brojPregleda);
    
    while(opcija!=7) {
    cout<<"Unesite ime novog pacijenta ili kraj za zavrsetak unosa: ";
    cin>>ime_pacijenta;
    
    cout<<"Unesite dan mjesec i godinu pregleda: ";
    cin>>dan>>mjesec>>godina;
    
    cout<<"Uneiste sate i minute pregleda: ";
    cin>>sati>> minute;
    
    cout<<"Odaberite jednu od sljedecih opcija"<<endl;
    cout<<"1 - Broj pregleda na datum"<<endl;
    cout<<"2 - Najraniji pregled"<<endl;
    cout<<"3 - Obrisi pregled pacijenta"<<endl;
    cout<<"4 - Obrisi najraniji pregled"<<endl;
    cout<<"5 - Ispisi sve pregleda na datum"<<endl;
    cout<<"6 - Ispisi sve preglede"<<endl;
    cout<<"7 - Kraj programa"<<endl;
    
    
    cin>>opcija;
    switch(opcija) {
        
        case 1:
        
        case 2:
        
        case 3:
        
        case 4:
    
        case 5:
        
        case 6:
        
            p.IspisiSvePreglede();    
        
        case 7: 

            return 0;
        
        default:
        
        return 0;
    }
    
}
    cout<<"OK";
    return 0;
}
