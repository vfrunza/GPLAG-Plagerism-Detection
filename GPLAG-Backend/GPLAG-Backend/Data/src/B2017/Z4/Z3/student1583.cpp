/B2017/2018: Zadaća 4, Zadatak 3
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



class Datum{
    
    int dan,mjesec,godina;
    int BrojDana (int mjesec, int godina);
    
public:

Datum(int dan, int mjesec, int godina){ Postavi(dan,mjesec,godina); }
void Postavi(int dan, int mjesec, int godina); 
std::tuple<int, int, int> Ocitaj() const{ return std::make_tuple(dan,mjesec,godina); }
void Ispisi() const{ cout<<dan<<"/"<<mjesec<<"/"<<godina; }
};


 int Datum::BrojDana(int mjesec, int godina) {
 int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 if( (godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
 broj_dana[1]++;
 return broj_dana[mjesec - 1];
}

void Datum::Postavi(int dan, int mjesec, int godina) {
 if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12
 || dan > BrojDana(mjesec, godina))
 throw std::domain_error("Neispravan datum");
 Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}

//----------------------------------------------------------

class Vrijeme{
    
    int sati,minute;
    
public:

Vrijeme(int sati, int minute){ Postavi(sati,minute); }
void Postavi(int sati, int minute);
std::pair<int, int> Ocitaj () const { return std::make_pair(sati,minute); }
void Ispisi() const{ cout<<std::setw(2)<<std::setfill('0')<<std::right<<sati<<std::setw(1)<<":"<<std::setw(2)<<std::right<<minute; }
};

void Vrijeme::Postavi(int sati, int minute) { 
    if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme"); 
    Vrijeme::sati=sati; Vrijeme::minute=minute; 
    
}

//-------------------------------------------------------------

class Pregled{
    
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    std::string ime_pacijenta;
    int BrojDana(int mjesec, int godina);
    
    public:
    
Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
 const Vrijeme &vrijeme_pregleda);
 
Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
 int godina_pregleda, int sati_pregleda, int minute_pregleda);
 
void PromijeniPacijenta(const std::string &ime_pacijenta){ Pregled::ime_pacijenta=ime_pacijenta; }
void PromijeniDatum(const Datum &novi_datum){ datum_pregleda=novi_datum; }
void PromijeniVrijeme(const Vrijeme &novo_vrijeme){ vrijeme_pregleda=novo_vrijeme; }

void PomjeriDanUnaprijed(){
    
    
    int dan,mjesec,godina;
    std::tie(dan,mjesec,godina)=datum_pregleda.Ocitaj();
    
    
 dan++;
 if(dan > BrojDana(mjesec, godina)) dan = 1, mjesec++;
 if(mjesec > 12) mjesec = 1, godina++;
 
 datum_pregleda.Postavi(dan,mjesec,godina);
 
    
}
void PomjeriDanUnazad(){
 
    int dan,mjesec,godina;
    std::tie(dan,mjesec,godina)=datum_pregleda.Ocitaj();

  dan--;
 if(dan == 0) mjesec--;
 if(mjesec == 0) mjesec = 12, godina--;
 if(dan == 0) dan=BrojDana(mjesec,godina);
 
 datum_pregleda.Postavi(dan,mjesec,godina);
    
}
std::string DajImePacijenta() const{ return ime_pacijenta; }
Datum DajDatumPregleda() const{ return datum_pregleda; }
Vrijeme DajVrijemePregleda() const{ return vrijeme_pregleda; }

static bool DolaziPrije(const Pregled &p1, const Pregled &p2){ 
 
             std::tuple<int,int,int> datum1(p1.datum_pregleda.Ocitaj());
             std::pair<int,int> vrijeme1(p1.vrijeme_pregleda.Ocitaj());
             std::tuple<int,int,int> datum2(p2.datum_pregleda.Ocitaj());
             std::pair<int, int> vrijeme2(p2.vrijeme_pregleda.Ocitaj());
             
             int godina1,godina2,mjesec1,mjesec2,dan1,dan2;
             
             std::tie(dan1,mjesec1,godina1)=datum1;
             std::tie(dan2,mjesec2,godina2)=datum2;
             
    return { godina1<godina2 || (godina1==godina2 && mjesec1<mjesec2) || (godina1==godina2 && mjesec1==mjesec2 && dan1<dan2) || (datum1==datum2 && vrijeme1<vrijeme2) };
             
}
           
         
void Ispisi() const{ 
    cout<<std::setfill(' ')<<std::setw(30)<<std::left<<ime_pacijenta;
    datum_pregleda.Ispisi();
    cout<<" ";
    vrijeme_pregleda.Ispisi();
    cout<<endl;
}

};

 int Pregled::BrojDana(int mjesec, int godina) {
 int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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

class Pregledi{
    
    int max_broj_pregleda;
    int broj_pregleda;
    Pregled **niz_pok_na_preglede;

public:
explicit Pregledi(int max_broj_pregleda);
Pregledi(std::initializer_list<Pregled> spisak_pregleda);
~Pregledi(){ if(niz_pok_na_preglede!=nullptr){ for(int i=0;i<broj_pregleda;i++) delete niz_pok_na_preglede[i]; } delete[] niz_pok_na_preglede;  }
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

int DajBrojPregleda() const{ if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda"); return broj_pregleda; }
int DajBrojPregledaNaDatum(const Datum &datum) const{ 
    
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    return std::count_if( niz_pok_na_preglede, niz_pok_na_preglede+broj_pregleda, [datum] (Pregled *pok){ 
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


Pregled &Pregledi::DajNajranijiPregled(){
    
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    
    auto min_pregled ( std::min_element( niz_pok_na_preglede, niz_pok_na_preglede+broj_pregleda, [] (Pregled *pok1, Pregled *pok2) {return Pregled::DolaziPrije(*pok1,*pok2);} ) );
    if(min_pregled!=niz_pok_na_preglede+broj_pregleda)
    return **min_pregled;
    else return **niz_pok_na_preglede;
    
}

Pregled Pregledi::DajNajranijiPregled() const{
    
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    
    auto min_pregled (std::min_element(niz_pok_na_preglede, niz_pok_na_preglede+broj_pregleda, [] (Pregled *pok1, Pregled *pok2) {return Pregled::DolaziPrije(*pok1,*pok2);} ) );
    if(min_pregled!=niz_pok_na_preglede+broj_pregleda)
    return **min_pregled;
    else return **niz_pok_na_preglede;
    
}

void Pregledi::IsprazniKolekciju(){
    
    if(niz_pok_na_preglede!=nullptr){
    for(int i=0;i<broj_pregleda;i++) { delete niz_pok_na_preglede[i]; niz_pok_na_preglede[i]=nullptr; }
    }
    broj_pregleda=0;
}


void Pregledi::ObrisiNajranijiPregled(){
    
    if(broj_pregleda==0) throw std::range_error ("Prazna kolekcija");
    
    auto pok_na_pok_najraniji_pregled ( std::min_element(niz_pok_na_preglede, niz_pok_na_preglede+broj_pregleda, [] (Pregled *pok1, Pregled *pok2) {return Pregled::DolaziPrije(*pok1,*pok2);}) );
    
    if(pok_na_pok_najraniji_pregled!=niz_pok_na_preglede+broj_pregleda){
    for(int i=0;i<broj_pregleda;i++){
        if(niz_pok_na_preglede[i]==*pok_na_pok_najraniji_pregled){
            
        delete niz_pok_na_preglede[i];
        
        for(int j=i;j<broj_pregleda-1;j++)
            niz_pok_na_preglede[j]=niz_pok_na_preglede[j+1];                //Da li ovo radi???
            
         niz_pok_na_preglede[broj_pregleda-1]=nullptr;
        broj_pregleda--;
        break;
        }
        
    }
    }
    
    else{
        
        delete *niz_pok_na_preglede;
        for(int i=0;i<broj_pregleda-1;i++)
        niz_pok_na_preglede[i]=niz_pok_na_preglede[i+1];
        
        niz_pok_na_preglede[broj_pregleda-1]=nullptr;
        
    }
    
}


void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta){
    
    for(int i=0;i<broj_pregleda;i++){
        
        if(niz_pok_na_preglede[i]->DajImePacijenta()==ime_pacijenta){
            
            delete niz_pok_na_preglede[i];
        
        for(int j=i;j<broj_pregleda-1;j++)
            niz_pok_na_preglede[j]=niz_pok_na_preglede[j+1];              
            
         niz_pok_na_preglede[broj_pregleda-1]=nullptr;
        broj_pregleda--;
        i--;
            
        }
        
    }
    
}
 

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
    
    std::vector<int> vektor_indeksa(broj_pregleda); 
    
    for(int i=0;i<broj_pregleda;i++) vektor_indeksa.at(i)=i;
    
    for(int i=0;i<broj_pregleda;i++){
            for(int j=i+1;j<broj_pregleda;j++){
                if(Pregled::DolaziPrije(*niz_pok_na_preglede[vektor_indeksa.at(j)],*niz_pok_na_preglede[vektor_indeksa.at(i)])){
                    int n(vektor_indeksa.at(i)); 
                    vektor_indeksa.at(i)=vektor_indeksa.at(j); 
                    vektor_indeksa.at(j)=n;
                }
        }
    }
    
    for(int i=0;i<broj_pregleda;i++){
        
    auto datum_pregleda(niz_pok_na_preglede[vektor_indeksa.at(i)]->DajDatumPregleda());
    auto ocitani_datum_pregleda(datum_pregleda.Ocitaj());
    auto ocitani_datum(datum.Ocitaj());
        if(ocitani_datum_pregleda==ocitani_datum)
        niz_pok_na_preglede[vektor_indeksa.at(i)]->Ispisi();
     
             
    
    }
    
}


void Pregledi::IspisiSvePreglede() const{
    
    std::vector<int> vektor_indeksa(broj_pregleda); 
    
    for(int i=0;i<broj_pregleda;i++) vektor_indeksa.at(i)=i;
    
    
    
    for(int i=0;i<broj_pregleda;i++){
            for(int j=i+1;j<broj_pregleda;j++){
                if(Pregled::DolaziPrije(*niz_pok_na_preglede[vektor_indeksa.at(j)],*niz_pok_na_preglede[vektor_indeksa.at(i)])){
                    int n(vektor_indeksa.at(i));
                    vektor_indeksa.at(i)=vektor_indeksa.at(j);
                    vektor_indeksa.at(j)=n;
                }
        }
        
 
    }

    for(int i=0;i<broj_pregleda;i++)
        niz_pok_na_preglede[vektor_indeksa.at(i)]->Ispisi();

    
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,
 const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
     
     if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
     
         niz_pok_na_preglede[broj_pregleda]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
         broj_pregleda++;
 }
 
 
 void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
 int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
 int minute_pregleda){
     
     if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
     
     niz_pok_na_preglede[broj_pregleda]=new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
     broj_pregleda++;
 }
 


void Pregledi::RegistrirajPregled(Pregled *pregled){
 
 if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
 
 niz_pok_na_preglede[broj_pregleda]=pregled;
 broj_pregleda++;
    
}

//-------------------------------


Pregledi &Pregledi::operator =(const Pregledi &pregledi) { // kopirajuci operator dodjele

    broj_pregleda=pregledi.broj_pregleda;
    max_broj_pregleda=pregledi.max_broj_pregleda;
	
	if(&pregledi!=this){
		
		try{
	
	
		Pregled **novi_pregledi(new Pregled *[broj_pregleda]{}); //Realokacija...
		for(int i=0;i<broj_pregleda;i++) delete niz_pok_na_preglede[i];
		delete[] niz_pok_na_preglede;
		niz_pok_na_preglede = novi_pregledi;
	
	
		for(int i=0;i<broj_pregleda;i++)
		niz_pok_na_preglede[i]=new Pregled(*pregledi.niz_pok_na_preglede[i]);
	
		}
		catch(...){
			for(int i=0;i<broj_pregleda;i++) { delete niz_pok_na_preglede[i]; niz_pok_na_preglede[i]=nullptr; }
			delete[] niz_pok_na_preglede; niz_pok_na_preglede=nullptr;
		}
		
		
	}
		
		return *this;
	
		
}


Pregledi &Pregledi:: operator =(Pregledi &&pregledi){ // pomjerajuci operator dodjele
	

	max_broj_pregleda=pregledi.max_broj_pregleda;
	broj_pregleda=pregledi.max_broj_pregleda;
	
	if(&pregledi!=this){
		for(int i=0;i<broj_pregleda;i++) delete niz_pok_na_preglede[i];
		delete[] niz_pok_na_preglede;
		niz_pok_na_preglede=pregledi.niz_pok_na_preglede; // uzimamo pokazivač
		pregledi.niz_pok_na_preglede=nullptr; // stari pokazivač nije više bitan
	}
	
	return *this;
}


Pregledi::Pregledi(int max_broj_pregleda) : max_broj_pregleda(max_broj_pregleda), broj_pregleda(0), niz_pok_na_preglede(new Pregled*[max_broj_pregleda]{}) {} // konstruktor sa jednim parametrom
	

	Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : max_broj_pregleda(spisak_pregleda.size()), broj_pregleda(spisak_pregleda.size()),niz_pok_na_preglede(new Pregled *[broj_pregleda]{})  { //sekvencijalni konstruktor

	try{ 
		
		auto it(spisak_pregleda.begin());
	
		for(int i=0;i<broj_pregleda;i++) 
			niz_pok_na_preglede[i]=new Pregled(*it++);
		}
		
	catch(std::bad_alloc ){
	for(int i=0;i<broj_pregleda;i++) { delete niz_pok_na_preglede[i]; niz_pok_na_preglede[i]=nullptr; }
	delete[] niz_pok_na_preglede;
	niz_pok_na_preglede=nullptr;
		throw;
	}
		

	}
	
	

	Pregledi::Pregledi (const Pregledi &pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda) { //kopirajuci konstruktor
		
		niz_pok_na_preglede=nullptr;
		try{
			
			niz_pok_na_preglede=new Pregled*[broj_pregleda]{};
			
			for(int i=0;i<broj_pregleda;i++)
			niz_pok_na_preglede[i]=new Pregled(*(pregledi.niz_pok_na_preglede[i]));
		
		}
		
		catch(std::bad_alloc ){
		for(int i=0;i<broj_pregleda;i++) { delete niz_pok_na_preglede[i]; niz_pok_na_preglede[i]=nullptr; }
		delete[] niz_pok_na_preglede; niz_pok_na_preglede=nullptr;
		throw;
	}
		
		
	}
	
	Pregledi::Pregledi (Pregledi &&pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda), niz_pok_na_preglede(pregledi.niz_pok_na_preglede){ pregledi.niz_pok_na_preglede=nullptr; } //pomjerajuci konstruktor

int main ()
{
    
   
    /*cout<<"Unesite maksimalan broj pregleda: ";
    int max_br_pregleda;
    cin>>max_br_pregleda;
    
    std::cin.ignore(10000,'\n');
    
    Pregledi pregledi_pacijenata(max_br_pregleda);
    
    for(int i=0;i<max_br_pregleda;i++){
    
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
    
    while(opcija!=7){ 
    
    cout<<endl<<"Odaberite jednu od sljedecih opcija"<<endl;
    cout<<"1 - Broj pregleda na datum"<<endl<<"2 - Najraniji pregled"<<endl<<"3 - Obrisi pregled pacijenta"<<endl<<"4 - Obrisi najraniji pregled"<<endl;
    cout<<"5 - Ispisi sve pregleda na datum"<<endl<<"6 - Ispisi sve preglede"<<endl<<"7 - Kraj programa"<<endl;
    cin>>opcija;
    
    switch (opcija){

        
        case 1: {
            cout<<"Unesite dan mjesec i godinu : ";
            int d,m,g;
            cin>>d>>m>>g;
            Datum datum_pregleda(d,m,g);
            cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<pregledi_pacijenata.DajBrojPregledaNaDatum(datum_pregleda)<<endl;
            break;
        }
        
        case 2 : {cout<<"Najraniji pregled je:"<<endl; pregledi_pacijenata.IspisiPregledeNaDatum(pregledi_pacijenata.DajNajranijiPregled().DajDatumPregleda()); break;}
        
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
        
        case 5 : { cout<<"Unesite dan mjesec i godinu : "; int dan,mjesec,godina;
        cin>>dan>>mjesec>>godina;
        cout<<"Pregledi na datum "<<dan<<" "<<mjesec<<" "<<godina<<" su:"<<endl;
        const Datum datum_pregleda(dan,mjesec,godina);
        pregledi_pacijenata.IspisiPregledeNaDatum(datum_pregleda);
        break;
            
        }
        
        case 6 : { pregledi_pacijenata.IspisiSvePreglede(); break; }
        
        case 7 : break;
        
    }
    }*/
    
    Pregled p("a",31,12,2000,0,0);
    p.Ispisi();
    p.PomjeriDanUnaprijed();
    p.Ispisi();
    
	return 0;
}
