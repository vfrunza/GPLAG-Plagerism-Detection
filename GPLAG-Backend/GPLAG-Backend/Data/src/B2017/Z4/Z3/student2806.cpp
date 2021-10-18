/B2017/2018: ===TITLE===
#include <iostream>
#include <stdexcept>
#include <utility>
#include <tuple>
#include <string>
#include <algorithm>
#include <iomanip>
#include <initializer_list>
#include <memory>
using namespace std;

typedef tuple<int, int, int> Tuple;
typedef pair<int, int> Pair;

class Datum{
    int d, m, g;
    public:
    Datum (int dan, int mjesec, int godina) {
        Postavi(dan,mjesec,godina);
    }
    void Postavi (int dan, int mjesec, int godina){
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina%4==0 && godina%100!=0 || godina %400==0) broj_dana[1]++;
        if(godina<1 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana[mjesec-1]) throw domain_error ("Neispravan datum");
        d=dan; m=mjesec; g=godina;
    }
    tuple<int, int, int> Ocitaj() const{
        Tuple trojka;
        trojka=make_tuple(d, m, g);
        return trojka;
    }
    void Ispisi() const{
        cout<<d<<"/"<<m<<"/"<<g;
    }
   
    friend class Pregled;
};

class Vrijeme{
    int s, min;
    public:
    Vrijeme(int sati, int minute){
        Postavi(sati, minute);
    }
    void Postavi(int sati, int minute){
        if(sati<0 || sati>23 && minute<0 || minute>59) throw domain_error ("Neispravno vrijeme");
        s=sati; min=minute;
    }
    pair<int, int> Ocitaj() const{
        return Pair (s, min);
    }
    void Ispisi() const{
        if(s>=10) cout<<s<<":";
		else cout<<"0"<<s<<":";
		if(min>=10) cout<<min<<":";
		else cout<<"0"<<min;
    }
    
   friend class Pregled;
};

class Pregled{
    string ime;
    Datum dat_preg;
    Vrijeme vrijeme_preg;
   // int dan_preg, mjesec_preg, godina_preg, sati_preg, minute_preg;
    static void PlusDan(const Datum &d_atum);
    public:
    Pregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):
        ime(ime_pacijenta), dat_preg(datum_pregleda), vrijeme_preg(vrijeme_pregleda){}
      
    Pregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):
    ime(ime_pacijenta), dat_preg(dan_pregleda, mjesec_pregleda, godina_pregleda),  vrijeme_preg(sati_pregleda, minute_pregleda){}
        
    void PromijeniPacijenta(const string &ime_pacijenta) {
        ime=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        dat_preg=novi_datum;
    } 
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme_preg=novo_vrijeme;
    }
    void PomjeriDanUnaprijed() {
        Tuple datum=dat_preg.Ocitaj();
        int dan=get<0>(datum);
        int mjesec=get<1>(datum);
        int godina=get<2>(datum);
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina%4==0 && godina%100!=0 || godina %400==0) { 
            broj_dana[1]++;
            if(dan==broj_dana[mjesec-1]) {
            dan=1;
            if(mjesec==12) {mjesec=1; godina++;}
            else mjesec++;
        }
        else dan++;
        }
        else {
             if(dan==broj_dana[mjesec-1]) {
            dan=1;
            if(mjesec==12) {mjesec=1; godina++;}
            else mjesec++;
        }
        else dan++;
           
        }
    } 
    void PomjeriDanUnazad() {
        Tuple datum=dat_preg.Ocitaj();
        int dan=get<0>(datum);
        int mjesec=get<1>(datum);
        int godina=get<2>(datum);
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina%4==0 && godina%100!=0 || godina %400==0) { 
            broj_dana[1]++;
            if(dan==0) {
            if(mjesec==1) {
            mjesec=12; 
            godina--; }
            else mjesec--;
            dan=broj_dana[mjesec];
            }
            else dan--;
        }
        else{ 
            broj_dana[1]++;
            if(dan==0) {
            if(mjesec==1) {
            mjesec=12; 
            godina--; }
            else mjesec--;
            dan=broj_dana[mjesec];
            }
            else dan--;
        }
    }
    
    string DajImePacijenta() const {
        return ime;
    } 
    Datum DajDatumPregleda() const {
        return dat_preg;
    }  
    Vrijeme DajVrijemePregleda() const {
        return vrijeme_preg;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        Tuple datum1=p1.dat_preg.Ocitaj();
        int dan1=get<0>(datum1);
        int mjesec1=get<1>(datum1);
        int godina1=get<2>(datum1);
        Tuple datum2=p2.dat_preg.Ocitaj();
        int dan2=get<0>(datum2);
        int mjesec2=get<1>(datum2);
        int godina2=get<2>(datum2);
        if(godina1<godina2) return true;
        if(mjesec1<mjesec2) return true;
        if(dan1<=dan2) return true;
        return false;
    } 
    void Ispisi() const {
        cout<<setw(30)<<left<<ime<<" ";
        dat_preg.Ispisi();
        cout<<" ";
        vrijeme_preg.Ispisi();
        cout<<endl;
    }
};

class Pregledi{
    Pregled **pregledi;
    const int max_br_preg;
    int trenutni_br_preg; 
    public:
    explicit Pregledi(int max_broj_pregleda): max_br_preg(max_broj_pregleda), trenutni_br_preg(0), pregledi(new Pregled*[max_broj_pregleda]{}) {} 
    
    Pregledi (initializer_list<Pregled> spisak_pregleda);
    
    ~Pregledi();
    
    Pregledi(const Pregledi &pregledi1): pregledi(pregledi1.pregledi), max_br_preg(pregledi1.max_br_preg), trenutni_br_preg(pregledi1.trenutni_br_preg) {}
    
    
    Pregledi(Pregledi &&pregledi2): pregledi(pregledi2.pregledi), max_br_preg(pregledi2.max_br_preg), trenutni_br_preg(pregledi2.trenutni_br_preg) {
        pregledi2.pregledi=nullptr;
        pregledi2.trenutni_br_preg=0;
    }
    
    Pregledi &operator =(const Pregledi &pregledi3){
        swap(trenutni_br_preg, pregledi.trenutni_br_preg);
        swap(pregledi, pregledi3.pregledi);
        return *this;
    }
    
    Pregledi &operator =(Pregledi &&pregledi);
    
    void RegistrirajPregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        Pregled *novi=new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
        pregledi[trenutni_br_preg]=novi;
        trenutni_br_preg++;
    }
    void RegistrirajPregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
        Pregled *novi = new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
        pregledi[trenutni_br_preg]=novi;
        trenutni_br_preg++;
    }
    void RegistrirajPregled(Pregled *pregled) {
        pregledi[trenutni_br_preg]=pregled;
        trenutni_br_preg++;
    }
    int DajBrojPregleda() const {return trenutni_br_preg;}
    
    int DajBrojPregledaNaDatum (const Datum &datum) const {
        count_if() //nemam blage
    }
    
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const {
    
    }
    
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledPacijenta(const string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi (initializer_list<Pregled> spisak_pregleda): max_br_preg(spisak_pregleda.size()) {
        initializer_list<Pregled>::iterator it{spisak_pregleda.begin()};
        for (int i=0; i<spisak_pregleda.size(); i++){
            pregledi[i]=make_shared<Pregled>(*it);
            it++;
        }
    }
    
int Pregledi::DajBrojPregledaNaDatum (const Datum &datum) const {
        Tuple dat1=datum.Ocitaj();
        int pom=0;
        for(int i=0; i<pregledi.size(); i++) {
            for(int j=0; j<pregledi[i].size(); j++){
                Tuple dat=pregledi[i][j].DajDatumPregleda().Ocitaj();
                if(dat==dat1) pom++;
            }
        }
        return pom;
    }




int main ()
{
    //Pregled *novi= new Pregled("Azra Ridjic", 1,11,2017,3,3);
    //novi->Ispisi();
    int max_br_preg, dan, mjesec, godina, sat, minuta;
    string ime;
    Pregledi skup(20);
    vector<Pregled*> Osoba;
    cout<<"Unesite maksimalan broj pregleda: ";
    cin>>max_br_preg;
    if(max_br_preg<1) return 0;
    int br_preg(0);
    for(;;){
        cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        cin.ignore(10000, '\n');
        getline(cin, ime);
        if(ime=="kraj") break;
        cout<<"Unesite dan mjesec i godinu pregleda: ";
        cin>>dan>>mjesec>>godina;
        try{
            Datum d=Datum(dan, mjesec, godina);
        }
        catch (domain_error izuzetak){
            cout<<izuzetak.what()<<endl;
            return 0;
        }
        cout<<"Unesite sate i minute pregleda: ";
        cin>>sat>>minuta;
        try{
            Vrijeme v=Vrijeme(sat. minuta);
        }
        catch(domain_error izuzetak){
            cout<<izuzetak.what();<<endl;
            return 0;
        }
        Osoba.push_back(new Pregled(ime, dan, mjesec, godina, sat,minuta));
        try{
            skup.RegistrirajPregled(ime, dan, mjesec, godina, sat,minuta);
        }
        catch(range_error izuzetak){
            cout<<izuzetak.what()<<endl;
            return 0;
        }
        br_preg++;
        if(br_preg==max_br_preg) break;
    }
    cout<<"Trenutno su registrovani sljedeci pregledi: " <<endl;
    sort(Osoba.begin(), Osoba.end(), [](Pregled *o1, Pregled *o2) {
        return Pregled::DolaziPrije(*o1, *o2);
    });
    for (int i=0; i<Osoba.size(); i++){
        Osoba[i]->Ispisi();
    }
    for (int i=0; i<Osoba.size(); i++){
        delete Osoba[i];
    }
    int U;
    for(;;){
        cout<<endl<<"Odaberite jednu od sljedecih opcija"<<endl;
        cout<<"1 - Broj pregleda na datum"<<endl<<"2 - Najraniji pregled"<<endl<<"3 - Obrisi pregled pacijenta"<<endl<<"4 - Obrisi najraniji pregled"<<endl<<"5 - Ispisi sve preglede na datum"<<endl<<"6 - Ispisi sve preglede"<<endl<<"7 - Kraj pregleda";
        cin>>U;
        if(U==1){
            try{
                cout<<"Unesite dan mjesec i godinu : ";
                cin>>dan>>mjesec>>godina;
                try{
                    Datum d=Datum(dan, mjesec, godina);
                }
                catch(domain_error izuzetak){
                    cout<<izuzetak.what()<<endl;
                    return 0;
                }
                cout<<"Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina<<" je : "<<skup.DajBrojPregledaNaDatum();
                cout<<endl;
            }
            catch(domain_error izuzetak){
                cout<<izuzetak.what()<<endl;
                return 0;
            }
        }
        if(U==2){
            try{
            skup.DajNajranijiPregled();
            cout<<"Najraniji pregled je: "<<endl;
            skup.DajNajranijiPregled().Ispisi();
            cout<<endl;
            }
            catch(domain_error izuzetak){
                cout<<izuzetak.what()<<endl;
                return 0;
            }
        }
        else if(U==3){
            cout<<"Unesite ime pacijenta: ";
            string ime_b;
            cin.ignore(10000, '\n');
            getline(cin, ime_b);
            int br_preg1=skup.DajBrojPregleda();
            skup.ObrisiPregledPacijenta(ime_b);
            int br_preg2=skup.DajBrojPregleda();
            cout<<"Uspjesno obrisano "<<br_preg1-br_preg2<<" pregleda"<<endl;
        }
        else if(U==4){
            try{
                skup.ObrisiNajranijiPregled();
                cout<<"Najraniji pregled uspjesno obrisan"<<endl;
            }
            catch(domain_error izuzetak){
                cout<<izuzetak.what();
                return 0;
            }
        }
        else if(U==5){
            cout<<"Unesite dan mjesec i godinu: ";
            cin>>dan>>mjesec>>godina;
            cout<<"Pregledi na datum "<<dan<<" "<<mjesec<<" "<<godina<<" su:"<<endl;
            skup.IspisiPregledeNaDatum(Datum(dan, mjesec, godina));
        }
        else if(U==6){
            skup.IspisiSvePreglede();
        }
        if(U==7){
            return 0;
        }
    }
	return 0;
}
