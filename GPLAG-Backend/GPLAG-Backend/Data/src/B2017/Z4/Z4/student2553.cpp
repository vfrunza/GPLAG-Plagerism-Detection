/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <tuple>
#include <memory>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <string>


using std::cout;
using std::cin;
using std::endl;



class Datum
{

    int dan,mjesec,godina;
    int BrojDana (int mjesec, int godina);

public:

    Datum(int dan, int mjesec, int godina) {
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(dan,mjesec,godina);
    }
    void Ispisi() const {
        cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};


int Datum::BrojDana(int mjesec, int godina)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( (godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        broj_dana[1]++;
    return broj_dana[mjesec - 1];
}

void Datum::Postavi(int dan, int mjesec, int godina)
{
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12
            || dan > BrojDana(mjesec, godina))
        throw std::domain_error("Neispravan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

//----------------------------------------------------------

class Vrijeme
{

    int sati,minute;

public:

    Vrijeme(int sati, int minute) {
        Postavi(sati,minute);
    }
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj () const {
        return std::make_pair(sati,minute);
    }
    void Ispisi() const {
        cout<<std::setw(2)<<std::setfill('0')<<std::right<<sati<<std::setw(1)<<":"<<std::setw(2)<<std::right<<minute;
    }
};

void Vrijeme::Postavi(int sati, int minute)
{
    if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati=sati;
    Vrijeme::minute=minute;

}

//-------------------------------------------------------------

class Pregled
{

    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    std::string ime_pacijenta;
    int BrojDana(int mjesec, int godina);

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


        int dan,mjesec,godina;
        std::tie(dan,mjesec,godina)=datum_pregleda.Ocitaj();


        dan++;
        if(dan > BrojDana(mjesec, godina)) dan = 1, mjesec++;
        if(mjesec > 12) mjesec = 1, godina++;

        datum_pregleda.Postavi(dan,mjesec,godina);


    }
    void PomjeriDanUnazad() {

        int dan,mjesec,godina;
        std::tie(dan,mjesec,godina)=datum_pregleda.Ocitaj();

        dan--;
        if(dan == 0) mjesec--;
        if(mjesec == 0) mjesec = 12, godina--;
        if(dan == 0) dan=BrojDana(mjesec,godina);

        datum_pregleda.Postavi(dan,mjesec,godina);

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

        std::tuple<int,int,int> datum1(p1.datum_pregleda.Ocitaj());
        std::pair<int,int> vrijeme1(p1.vrijeme_pregleda.Ocitaj());
        std::tuple<int,int,int> datum2(p2.datum_pregleda.Ocitaj());
        std::pair<int, int> vrijeme2(p2.vrijeme_pregleda.Ocitaj());

        int godina1,godina2,mjesec1,mjesec2,dan1,dan2;

        std::tie(dan1,mjesec1,godina1)=datum1;
        std::tie(dan2,mjesec2,godina2)=datum2;

        return { godina1<godina2 || (godina1==godina2 && mjesec1<mjesec2) || (godina1==godina2 && mjesec1==mjesec2 && dan1<dan2) || (datum1==datum2 && vrijeme1<vrijeme2) };

    }


    void Ispisi() const {
        cout<<std::setfill(' ')<<std::setw(30)<<std::left<<ime_pacijenta;
        datum_pregleda.Ispisi();
        cout<<" ";
        vrijeme_pregleda.Ispisi();
        cout<<endl;
    }

};

int Pregled::BrojDana(int mjesec, int godina)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( (godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        broj_dana[1]++;
    return broj_dana[mjesec - 1];
}



Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
                 const Vrijeme &vrijeme_pregleda) : ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {}

Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
                 int godina_pregleda, int sati_pregleda, int minute_pregleda) : ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda),
    vrijeme_pregleda(sati_pregleda,minute_pregleda) {}


//--------------------------------------------------------------------------------------



class Pregledi
{

    
    std::vector<std::shared_ptr<Pregled>> vektor_pam_pok;

public:

    Pregledi(){};
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi() {
        
            for(int i=0; i<vektor_pam_pok.size(); i++) vektor_pam_pok[i]=nullptr;
        vektor_pam_pok.resize(0);
    }
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);


    void RegistrirajPregled(const std::string &ime_pacijenta,
                            const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
                            int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
                            int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled);

    int DajBrojPregleda() const {
        if(vektor_pam_pok.size()==0) throw std::domain_error("Nema registriranih pregleda");
        return vektor_pam_pok.size();
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const {

        if(vektor_pam_pok.size()==0) throw std::domain_error("Nema registriranih pregleda");
        return std::count_if( vektor_pam_pok.begin(), vektor_pam_pok.end(), [datum] (std::shared_ptr<Pregled> pok) {
            Datum datum_pregleda ( pok->DajDatumPregleda() );
            std::tuple<int,int,int> ocitani_datum_pregleda (datum_pregleda.Ocitaj() );
            std::tuple<int,int,int> ocitani_datum (datum.Ocitaj());

            return ocitani_datum_pregleda==ocitani_datum;

        } );
    }

    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;

};


Pregled &Pregledi::DajNajranijiPregled()
{

    if(vektor_pam_pok.size()==0) throw std::domain_error("Nema registriranih pregleda");

    auto min_pregled (std::min_element(vektor_pam_pok.begin(), vektor_pam_pok.end(), [] (std::shared_ptr<Pregled> pok1, std::shared_ptr<Pregled> pok2) {
        return Pregled::DolaziPrije(*pok1,*pok2);
    } ) );
    if(min_pregled!=vektor_pam_pok.end())
        return **min_pregled;
    else return *vektor_pam_pok.at(0);

}

Pregled Pregledi::DajNajranijiPregled() const
{

    if(vektor_pam_pok.size()==0) throw std::domain_error("Nema registriranih pregleda");

    auto min_pregled (std::min_element(vektor_pam_pok.begin(), vektor_pam_pok.end(), [] (std::shared_ptr<Pregled> pok1, std::shared_ptr<Pregled> pok2) {
        return Pregled::DolaziPrije(*pok1,*pok2);
    } ) );
    if(min_pregled!=vektor_pam_pok.end())
        return **min_pregled;
    else return *vektor_pam_pok.at(0);

}

void Pregledi::IsprazniKolekciju()
{

    if(vektor_pam_pok.size()!=0) {
        for(int i=0; i<vektor_pam_pok.size(); i++) 
            vektor_pam_pok[i]=nullptr;
            
    }
    
    vektor_pam_pok.resize(0);
}


void Pregledi::ObrisiNajranijiPregled()
{

    if(vektor_pam_pok.size()==0) throw std::range_error ("Prazna kolekcija");

    auto pok_na_pok_najraniji_pregled ( std::min_element(vektor_pam_pok.begin(), vektor_pam_pok.end(), [] (std::shared_ptr<Pregled> pok1, std::shared_ptr<Pregled> pok2) {
        return Pregled::DolaziPrije(*pok1,*pok2);
    }) );

    if(pok_na_pok_najraniji_pregled!=vektor_pam_pok.end()) {
        for(int i=0; i<vektor_pam_pok.size(); i++) {
            if(vektor_pam_pok[i]==*pok_na_pok_najraniji_pregled) {

                vektor_pam_pok[i]=nullptr;

                for(int j=i; j<vektor_pam_pok.size()-1; j++)
                    vektor_pam_pok[j]=vektor_pam_pok[j+1];                //Da li ovo radi???

                vektor_pam_pok[vektor_pam_pok.size()-1]=nullptr;
                vektor_pam_pok.resize(vektor_pam_pok.size()-1);
                break;
            }

        }
    }

    else {

         vektor_pam_pok.at(0)=nullptr;
        for(int i=0; i<vektor_pam_pok.size()-1; i++)
            vektor_pam_pok[i]=vektor_pam_pok[i+1];

        vektor_pam_pok[vektor_pam_pok.size()-1]=nullptr;

    }

}


void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{

    for(int i=0; i<vektor_pam_pok.size(); i++) {

        if(vektor_pam_pok[i]->DajImePacijenta()==ime_pacijenta) {

            vektor_pam_pok[i]=nullptr;

            for(int j=i; j<vektor_pam_pok.size()-1; j++)
                vektor_pam_pok[j]=vektor_pam_pok[j+1];

            vektor_pam_pok[vektor_pam_pok.size()-1]=nullptr;
            vektor_pam_pok.resize(vektor_pam_pok.size()-1);
            i--;

        }

    }

}


void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{

    std::vector<int> vektor_indeksa(vektor_pam_pok.size());

    for(int i=0; i<vektor_pam_pok.size(); i++) vektor_indeksa.at(i)=i;

    for(int i=0; i<vektor_pam_pok.size(); i++) {
        for(int j=i+1; j<vektor_pam_pok.size(); j++) {
            if(Pregled::DolaziPrije(*vektor_pam_pok[vektor_indeksa.at(j)],*vektor_pam_pok[vektor_indeksa.at(i)])) {
                int n(vektor_indeksa.at(i));
                vektor_indeksa.at(i)=vektor_indeksa.at(j);
                vektor_indeksa.at(j)=n;
            }
        }
    }

    for(int i=0; i<vektor_pam_pok.size(); i++) {

        auto datum_pregleda(vektor_pam_pok[vektor_indeksa.at(i)]->DajDatumPregleda());
        auto ocitani_datum_pregleda(datum_pregleda.Ocitaj());
        auto ocitani_datum(datum.Ocitaj());
        if(ocitani_datum_pregleda==ocitani_datum)
            vektor_pam_pok[vektor_indeksa.at(i)]->Ispisi();

    }

}


void Pregledi::IspisiSvePreglede() const
{

    std::vector<int> vektor_indeksa(vektor_pam_pok.size());

    for(int i=0; i<vektor_pam_pok.size(); i++) vektor_indeksa.at(i)=i;


    for(int i=0; i<vektor_pam_pok.size(); i++) {
        for(int j=i+1; j<vektor_pam_pok.size(); j++) {
            if(Pregled::DolaziPrije(*vektor_pam_pok[vektor_indeksa.at(j)],*vektor_pam_pok[vektor_indeksa.at(i)])) {
                int n(vektor_indeksa.at(i));
                vektor_indeksa.at(i)=vektor_indeksa.at(j);
                vektor_indeksa.at(j)=n;
            }
        }


    }

    for(int i=0; i<vektor_pam_pok.size(); i++)
        vektor_pam_pok[vektor_indeksa.at(i)]->Ispisi();


}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,
                                  const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{

    
    try{
    vektor_pam_pok.resize(vektor_pam_pok.size()+1);
    vektor_pam_pok[vektor_pam_pok.size()-1]=std::make_shared<Pregled>(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
    }
    
    catch(...){
        for(int i=0;i<vektor_pam_pok.size();i++) vektor_pam_pok.at(i)=nullptr;
        vektor_pam_pok.resize(0);
        throw;
    }
}


void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
                                  int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
                                  int minute_pregleda)
{


    try{
    vektor_pam_pok.resize(vektor_pam_pok.size()+1);
    vektor_pam_pok[vektor_pam_pok.size()-1]=std::make_shared<Pregled>(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
    }
    
     catch(...){
        for(int i=0;i<vektor_pam_pok.size();i++) vektor_pam_pok.at(i)=nullptr;
        vektor_pam_pok.resize(0);
        throw;
    }
    
    
}



void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled)
{

    try{
    
    vektor_pam_pok.resize(vektor_pam_pok.size()+1);    
    vektor_pam_pok[vektor_pam_pok.size()-1]=pregled;
    }
    
    catch(...){
        for(int i=0;i<vektor_pam_pok.size();i++) vektor_pam_pok.at(i)=nullptr;
        vektor_pam_pok.resize(0);
        throw;
    }

}

//-------------------------------


Pregledi &Pregledi::operator =(const Pregledi &pregledi)   // kopirajuci operator dodjele
{

    

    if(&pregledi!=this) {

        try {

            vektor_pam_pok.resize(pregledi.vektor_pam_pok.size());
            for(int i=0;i<vektor_pam_pok.size();i++) vektor_pam_pok.at(i)=std::make_shared<Pregled>(*pregledi.vektor_pam_pok.at(i));
           

        } catch(...) {
            for(int i=0; i<vektor_pam_pok.size(); i++) 
                vektor_pam_pok[i]=nullptr;
            
            vektor_pam_pok.resize(0);
            throw;
        }


    }

    return *this;


}


Pregledi &Pregledi:: operator =(Pregledi &&pregledi)  // pomjerajuci operator dodjele
{
    

    if(&pregledi!=this){ 
        vektor_pam_pok.resize(0);
        vektor_pam_pok=std::move(pregledi.vektor_pam_pok);
        pregledi.vektor_pam_pok.resize(0);
    

    return *this;
}

}


Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda)  //sekvencijalni konstruktor
{

    try {
        
        vektor_pam_pok.resize(spisak_pregleda.size());
        auto it(spisak_pregleda.begin());

        for(int i=0; i<vektor_pam_pok.size(); i++)
            vektor_pam_pok[i]=std::make_shared<Pregled>(*it++);
    }

    catch(std::bad_alloc ) {
        for(int i=0; i<vektor_pam_pok.size(); i++) 
            vektor_pam_pok[i]=nullptr;
        
        vektor_pam_pok.resize(0);
        throw;
    }


}




Pregledi::Pregledi (const Pregledi &pregledi)    //kopirajuci konstruktor
{

    
    try {
        
        vektor_pam_pok.resize(pregledi.vektor_pam_pok.size());
        

        for(int i=0; i<vektor_pam_pok.size(); i++)
            vektor_pam_pok[i]=std::make_shared<Pregled>(*(pregledi.vektor_pam_pok[i]));

    }

    catch(std::bad_alloc ) {
        for(int i=0; i<vektor_pam_pok.size(); i++) {
            
            vektor_pam_pok[i]=nullptr;
        }
        
        vektor_pam_pok.resize(0);
        throw;
    }


}

Pregledi::Pregledi (Pregledi &&pregledi) // pomjerajuci konstruktor
{
    vektor_pam_pok=std::move(pregledi.vektor_pam_pok);
    vektor_pam_pok.resize(0);    
}

int main ()
{



    Pregledi pregledi_pacijenata;

    while(true){

        cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";

        std::string ime_pacijenta;
        std::getline(cin,ime_pacijenta);
        if(ime_pacijenta=="kraj") break;

        cout<<"Unesite dan mjesec i godinu pregleda: ";
        int dan,mjesec,godina;
        cin>>dan>>mjesec>>godina;
        cout<<"Unesite sate i minute pregleda: ";
        int sati,minute;
        cin>>sati>>minute;

        std::cin.ignore(10000,'\n');
        

        pregledi_pacijenata.RegistrirajPregled(ime_pacijenta,dan,mjesec,godina,sati,minute);

    }

    cout<<"Trenutno su registrovani sljedeci pregledi"<<endl;

    pregledi_pacijenata.IspisiSvePreglede();



    int opcija(0);

    while(opcija!=7) {

        cout<<endl<<"Odaberite jednu od sljedecih opcija"<<endl;
        cout<<"1 - Broj pregleda na datum"<<endl<<"2 - Najraniji pregled"<<endl<<"3 - Obrisi pregled pacijenta"<<endl<<"4 - Obrisi najraniji pregled"<<endl;
        cout<<"5 - Ispisi sve pregleda na datum"<<endl<<"6 - Ispisi sve preglede"<<endl<<"7 - Kraj programa"<<endl;
        cin>>opcija;

        switch (opcija) {


        case 1: {
            cout<<"Unesite dan mjesec i godinu : ";
            int d,m,g;
            cin>>d>>m>>g;
            Datum datum_pregleda(d,m,g);
            cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<pregledi_pacijenata.DajBrojPregledaNaDatum(datum_pregleda)<<endl;
            break;
        }

        case 2 : {
            cout<<"Najraniji pregled je:"<<endl;
            pregledi_pacijenata.IspisiPregledeNaDatum(pregledi_pacijenata.DajNajranijiPregled().DajDatumPregleda());
            break;
        }

        case 3 : {
            int broj_pregleda1(pregledi_pacijenata.DajBrojPregleda());

            cout<<"Unesite ime pacijenta: ";
            std::cin.ignore(10000,'\n');
            std::string ime_pacijenta;
            std::getline(cin,ime_pacijenta);
            pregledi_pacijenata.ObrisiPregledePacijenta(ime_pacijenta);

            int broj_pregleda2(pregledi_pacijenata.DajBrojPregleda());

            cout<<"Uspjesno obrisano "<<broj_pregleda1-broj_pregleda2<<" pregleda"<<endl;
            break;
        }

        case 4 : {
            pregledi_pacijenata.ObrisiNajranijiPregled();
            cout<<"Najraniji pregled uspjesno obrisan"<<endl;
            break;
        }

        case 5 : {
            cout<<"Unesite dan mjesec i godinu : ";
            int dan,mjesec,godina;
            cin>>dan>>mjesec>>godina;
            cout<<"Pregledi na datum "<<dan<<" "<<mjesec<<" "<<godina<<" su:"<<endl;
            const Datum datum_pregleda(dan,mjesec,godina);
            pregledi_pacijenata.IspisiPregledeNaDatum(datum_pregleda);
            break;

        }

        case 6 : {
            pregledi_pacijenata.IspisiSvePreglede();
            break;
        }

        case 7 :
            break;

        }
    }

    return 0;
}
      