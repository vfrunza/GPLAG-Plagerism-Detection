/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <string> 
#include <utility>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>

int br=0;

class Datum{
    int dan;
    int mjesec;
    int godina;
int BrojDana (int mjesec, int godina){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if (godina%4==0 && godina % 100!=0 || godina % 400==0) broj_dana[1]++;
    return broj_dana[mjesec-1];
}
public:
    Datum(int dan, int mjesec, int godina){Postavi(dan,mjesec,godina);}
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const;
    void Ispisi() const; 
};

class Vrijeme{
    int sati;
    int minute;
public:
    Vrijeme(int sati, int minute){Postavi(sati, minute);}
    void Postavi(int sati, int minute);  
    std::pair<int, int> Ocitaj () const;  
    void Ispisi() const; 
};

class Pregled{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled(const std::string& ime_pacijenta, const Datum& datum_pregleda,  const Vrijeme&  vrijeme_pregleda);  
    Pregled(const std::string& ime_pacijenta, int dan_pregleda, int mjesec_pregleda,  int godina_pregleda, int sati_pregleda, int minute_pregleda);  
    void PromijeniPacijenta(const std::string&  ime_pacijenta);  
    void PromijeniDatum(const Datum&  novi_datum);  
    void PromijeniVrijeme(const Vrijeme&  novo_vrijeme); 
    void PomjeriDanUnaprijed(); 
    void PomjeriDanUnazad();  
    std::string DajImePacijenta() const {return ime_pacijenta;}
    Datum DajDatumPregleda() const {return datum_pregleda;}  
    Vrijeme DajVrijemePregleda() const {return vrijeme_pregleda;}
    static bool DolaziPrije(const Pregled&  p1, const Pregled&  p2);  
    void Ispisi() const; 
};

class Pregledi{
    Pregled** pregledi;
    int broj_pregleda;
    int max_broj_pregleda;
    void Brisi ();
public:
    explicit Pregledi(int max_broj_pregleda);
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const { return broj_pregleda; }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

void Datum::Postavi(int dan, int mjesec, int godina){
    if (godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>BrojDana(mjesec,godina)) throw std::domain_error("Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}

std::tuple<int,int,int> Datum::Ocitaj () const{
    std::tuple<int, int, int> datum (dan, mjesec, godina);
    return datum;
}

void Datum::Ispisi() const{
    std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
}

void Vrijeme::Postavi(int sati, int minute){
    if (sati>=0 && sati<=23 && minute>=0 && minute<=59){
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }else throw std::domain_error ("Neispravno vrijeme");
}

std::pair<int, int> Vrijeme::Ocitaj () const {
    return std::make_pair (sati, minute);
}

void Vrijeme::Ispisi() const {
    std::cout<<std::setfill('0')<<std::setw(2)<<sati<<":"<<std::setw(2)<<minute;
    std::cout<<std::setfill(' ');
}

Pregled::Pregled(const std::string&  ime_pacijenta, const Datum&  datum_pregleda, const Vrijeme&  vrijeme_pregleda) : datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {
    PromijeniPacijenta(ime_pacijenta);
    
}    
/*kad imas atribut u klasi klasa moras u inic*/
Pregled::Pregled(const std::string& ime_pacijenta, int dan_pregleda, int mjesec_pregleda,  int godina_pregleda, int sati_pregleda, int minute_pregleda) : datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda){
    PromijeniPacijenta(ime_pacijenta);
}
void Pregled::PromijeniPacijenta(const std::string& ime_pacijenta){
    Pregled::ime_pacijenta=ime_pacijenta;
}

void Pregled::PromijeniDatum(const Datum& novi_datum){
    datum_pregleda=novi_datum;
}

void Pregled::PromijeniVrijeme(const Vrijeme& novo_vrijeme){
    vrijeme_pregleda=novo_vrijeme;
}

void Pregled::PomjeriDanUnaprijed () {
    std::tuple <int, int, int> datum;
    datum=(*this).datum_pregleda.Ocitaj();
    std::get<0>(datum)++;
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if (std::get<2>(datum)%100!=0 && std::get<2>(datum)%4==0 || std::get<2>(datum)%400==0) broj_dana[1]++;
    if (std::get<0>(datum)>broj_dana[std::get<1>(datum)-1]){ 
        std::get<0>(datum)=1;
        std::get<1>(datum)++;
    }
    if (std::get<1>(datum)>12) {
        std::get<1>(datum)=1;
        std::get<2>(datum)++;
    }
    Datum pomocni(std::get<0>(datum), std::get<1>(datum), std::get<2>(datum));
    (*this).datum_pregleda=pomocni;
}

void Pregled::PomjeriDanUnazad () {
    std::tuple <int, int, int> datum;
    datum=(*this).datum_pregleda.Ocitaj();
    std::get<0>(datum)--;
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if (std::get<2>(datum)%100!=0 && std::get<2>(datum)%4==0 || std::get<2>(datum)%400==0) broj_dana[1]++;
    if (std::get<0>(datum)==0 && std::get<1>(datum)==1){
        std::get<0>(datum)=31;
        std::get<2>(datum)--;
        std::get<1>(datum)=12;
    }
    if (std::get<0>(datum)<=0){ 
        std::get<0>(datum)=broj_dana[std::get<1>(datum)-2];
        std::get<1>(datum)--;
    }
    Datum pomocni(std::get<0>(datum), std::get<1>(datum), std::get<2>(datum));
    (*this).datum_pregleda=pomocni;
}

bool Pregled::DolaziPrije(const Pregled& p1, const Pregled& p2){ /*MORAJ DAJ, samo s funkcijama*/
    std::tuple <int, int, int> d1, d2;
    std::pair <int, int> v1, v2;
    d1=p1.DajDatumPregleda().Ocitaj();
    d2=p2.DajDatumPregleda().Ocitaj();
    v1=p1.DajVrijemePregleda().Ocitaj();
    v2=p2.DajVrijemePregleda().Ocitaj();
    if (std::get<2>(d1)!=std::get<2>(d2)) return std::get<2>(d1)<std::get<2>(d2);
    else if (std::get<1>(d1)!=std::get<1>(d2)) return std::get<1>(d1)<std::get<1>(d2);
    else if (std::get<0>(d1)!=std::get<0>(d2)) return std::get<0>(d1)<std::get<0>(d2);
    else if (v1.first!=v2.first) return v1.first<v2.first;
    else return v1.second<v2.second;
}

void Pregled::Ispisi() const{
    std::cout<<std::left<<std::setw(30)<<DajImePacijenta()<<std::right;
    DajDatumPregleda().Ispisi(); /*fja ne moze u tok*/
    std::cout<<" ";
    DajVrijemePregleda().Ispisi();
}

Pregledi::Pregledi(int max_broj_pregleda) : max_broj_pregleda(max_broj_pregleda), pregledi(new Pregled*[max_broj_pregleda]{}), broj_pregleda(0){}
void Pregledi::Brisi () {
    for (int i=0; i<broj_pregleda; i++) {
        delete pregledi[i];
    }
    delete[] pregledi;
    pregledi=nullptr;
}
    Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : max_broj_pregleda(spisak_pregleda.size()), broj_pregleda(spisak_pregleda.size()), pregledi(new Pregled*[spisak_pregleda.size()]{}){
    int i(0);
    try{
    for (auto pregled : spisak_pregleda) {
        pregledi[i] = new Pregled (pregled);
        i++;
    }} catch (...) {
        Brisi();
    }  
}


    Pregledi::~Pregledi(){
    Brisi();
}

    Pregledi::Pregledi(const Pregledi &pregledi) : broj_pregleda(pregledi.broj_pregleda), max_broj_pregleda(pregledi.max_broj_pregleda), pregledi(new Pregled*[pregledi.max_broj_pregleda]{}) {
    try{
        for (int i=0; i<broj_pregleda; i++){
            Pregledi::pregledi[i] = new Pregled (*pregledi.pregledi[i]);
        }
    }catch (...){
        Brisi();
    }
}
    Pregledi::Pregledi(Pregledi &&pregledi) : broj_pregleda(pregledi.broj_pregleda), max_broj_pregleda(pregledi.max_broj_pregleda) {
    Pregledi::pregledi=pregledi.pregledi;
    pregledi.pregledi=nullptr;
    pregledi.broj_pregleda=0;
}

Pregledi& Pregledi::operator =(const Pregledi &pregledi){
    if (this==&pregledi) return *this;
    Brisi();
    max_broj_pregleda=pregledi.max_broj_pregleda;
    broj_pregleda=pregledi.broj_pregleda;
    Pregledi::pregledi = new Pregled* [max_broj_pregleda];
    try{
        for (int i=0; i<broj_pregleda; i++){
            Pregledi::pregledi[i] = new Pregled (*pregledi.pregledi[i]);
        }
    }catch (...){
        Brisi();
    }
    return *this;
}


Pregledi& Pregledi::operator =(Pregledi &&pregledi){
    if (this==&pregledi) return *this;
    Brisi();
    max_broj_pregleda = pregledi.max_broj_pregleda;
    broj_pregleda = pregledi.broj_pregleda;
    Pregledi::pregledi = pregledi.pregledi;
    pregledi.pregledi=nullptr;
    pregledi.broj_pregleda=0;
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    if (broj_pregleda == max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledi[broj_pregleda] =  new Pregled (ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    broj_pregleda++;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
    if (broj_pregleda == max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledi[broj_pregleda] =  new Pregled (ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    broj_pregleda++;
}

void Pregledi::RegistrirajPregled(Pregled *pregled){
    if (broj_pregleda == max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledi[broj_pregleda] =  pregled;
    broj_pregleda++;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const{
    int broj_pregleda_na_datum(0);
    std::tuple<int, int, int> datum2;
    datum2=datum.Ocitaj();
    broj_pregleda_na_datum = std::count_if(pregledi, pregledi+broj_pregleda, [datum2] (Pregled* pregled) -> bool {
      std::tuple<int, int, int> datum1;
        datum1=(*pregled).DajDatumPregleda().Ocitaj();
        return std::get<0>(datum1)==std::get<0>(datum2) && std::get<1>(datum1)==std::get<1>(datum2) && std::get<2>(datum1)==std::get<2>(datum2);});
    return broj_pregleda_na_datum; 
}

Pregled& Pregledi::DajNajranijiPregled(){
    if (broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(pregledi, pregledi+broj_pregleda, [] (Pregled* pok1, Pregled* pok2){
        return Pregled::DolaziPrije(*pok1, *pok2);
    });
}
Pregled Pregledi::DajNajranijiPregled() const{ /*Unutar const ne smijes pozivat nekonstantne fje*/
        if (broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(pregledi, pregledi+broj_pregleda, [] (Pregled* pok1, Pregled* pok2){
        return Pregled::DolaziPrije(*pok1, *pok2);
    }); 
}

void Pregledi::IsprazniKolekciju(){
    Brisi();
    pregledi = new Pregled* [max_broj_pregleda]{}; 
}

void Pregledi::ObrisiNajranijiPregled(){
    if (broj_pregleda==0) throw std::range_error ("Prazna kolekcija");
    Pregled** min(std::min_element(pregledi, pregledi+broj_pregleda, [] (Pregled* pok1, Pregled* pok2){
        return Pregled::DolaziPrije(*pok1, *pok2);
    })); 
    int indeks (min-&pregledi[0]);
    /*std::cout<<indeks<<" "<<std::endl;
    (**min).Ispisi();*/
    delete pregledi[indeks]; 
    pregledi[indeks]=nullptr;
    for (int i=indeks;i<broj_pregleda-1;i++){
        pregledi[i]=pregledi[i+1];
    }
    pregledi[broj_pregleda-1]=nullptr;
    broj_pregleda--;
}
    
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta){
    br=0;
    for (int i=0;i<broj_pregleda;i++){
         if ((*pregledi[i]).DajImePacijenta()==ime_pacijenta){
                delete pregledi[i];
                for (int j=i;j<broj_pregleda-1;j++){
                    pregledi[j]=pregledi[j+1];
                }
                pregledi[broj_pregleda-1]=nullptr;
                broj_pregleda--;
                i--;
                br++;
            }
        }
    }
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
    std::vector<Pregled> pomocni;
    std::tuple<int, int, int> d;
    d=datum.Ocitaj();
    for (int i=0;i<broj_pregleda;i++){
        std::tuple<int,int,int> p;
        p=(*pregledi[i]).DajDatumPregleda().Ocitaj();
        if (std::get<0>(p)==std::get<0>(d) && std::get<1>(p)==std::get<1>(d) && std::get<2>(p)==std::get<2>(d)) pomocni.push_back(*pregledi[i]);
        else;
    }
    
    std::sort(pomocni.begin(), pomocni.end(), [] (Pregled p1, Pregled p2) { 
        std::pair<int, int> v1, v2;
        v1=p1.DajVrijemePregleda().Ocitaj();
        v2=p2.DajVrijemePregleda().Ocitaj();
        if(v1.first!=v2.first)
            return v1.first<v2.first;
        else
            return v1.second<v2.second;
    });
    
    for(int i=0;i<pomocni.size();i++)
        pomocni.at(i).Ispisi();
}
void Pregledi::IspisiSvePreglede() const{
    std::sort(pregledi, pregledi+broj_pregleda, [] (Pregled *pok1, Pregled *pok2){
        return Pregled::DolaziPrije(*pok1,*pok2);
    });
   for (int i=0;i<broj_pregleda;i++){
        pregledi[i]->Ispisi();
        std::cout<<std::endl;
    }
}
    
int main()
{
    try{
    std::cout<<"Unesite maksimalan broj pregleda: ";
    int max_broj_pregleda(0);
    std::cin>>max_broj_pregleda;
    Pregledi svi_pregledi(max_broj_pregleda);
    std::string s;
    int brojac(0);
    while (s!="kraj"){
    brojac++;
        if (brojac==max_broj_pregleda+1) break;
        else;
    std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
    std::cin.ignore(1000,'\n');
    std::getline(std::cin, s); // cin.ignore treba prije getline
    if (s=="kraj") break;
    std::cout<<"Unesite dan mjesec i godinu pregleda: ";
    int d,m,g;
    std::cin>>d>>m>>g;
    std::cout<<"Unesite sate i minute pregleda: ";
    int h,min;
    std::cin>>h>>min;
    svi_pregledi.RegistrirajPregled(s,d,m,g,h,min);
    };
    std::cout<<"Trenutno su registrovani sljedeci pregledi "<<std::endl;
    svi_pregledi.IspisiSvePreglede();
    int n(0);
    while (n!=7){
    std::cout<<"Odaberite jednu od sljedecih opcija"<<std::endl<<"1 - Broj pregleda na datum"<<std::endl<<
    "2 - Najraniji pregled"<<std::endl<<"3 - Obrisi pregled pacijenta"<<std::endl<<
    "4 - Obrisi najraniji pregled"<<std::endl<<"5 - Ispisi sve pregleda na datum"<<std::endl<<
    "6 - Ispisi sve preglede"<<std::endl<<"7 - Kraj programa"<<std::endl<<std::endl;
    std::cin>>n;
    if (n==1) {
        std::cout<<std::endl<<"Unesite dan mjesec i godinu : ";
        int dan, mjesec, godina;
        std::cin>>dan>>mjesec>>godina;
        Datum datum(dan, mjesec, godina);
        std::cout<<"Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina<<" je: "<<svi_pregledi.DajBrojPregledaNaDatum(datum)<<std::endl<<std::endl;
    } else if (n==2){
        std::cout<<"Najraniji pregled je:"<<std::endl;
        svi_pregledi.DajNajranijiPregled().Ispisi();
        std::cout<<std::endl<<std::endl;
    } else if (n==3){
        std::cout<<"Unesite ime pacijenta: ";
        std::string ime;
        std::cin>>ime;
        svi_pregledi.ObrisiPregledePacijenta(ime);
        std::cout<<"Uspjesno obrisano "<<br<<" pregleda"<<std::endl<<std::endl;
        
    } else if (n==4){
        svi_pregledi.ObrisiNajranijiPregled();
        std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl<<std::endl;
    } else if (n==5){
        int day, month, year;
        std::cout<<"Unesite dan mjesec i godinu : ";
        std::cin>>day>>month>>year;
        Datum date (day,month,year);
        std::cout<<"Pregledi na datum "<<day<<" "<<month<<" "<<year<<" su:"<<std::endl;
        svi_pregledi.IspisiPregledeNaDatum(date);
        std::cout<<std::endl;
    } else if (n==6){
        svi_pregledi.IspisiSvePreglede();
        std::cout<<std::endl<<std::endl;
    }
    else break;
}
    } catch(std::domain_error e){
        std::cout<<e.what();
    } catch (std::range_error e){
        std::cout<<e.what();
    } catch (...){
        
    }
	return 0;
}



















































