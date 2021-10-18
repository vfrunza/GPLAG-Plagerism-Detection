/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <memory>
#include <utility>
#include <tuple>
#include <iomanip>
#include <algorithm>

using namespace std;

class Datum{
    int dan, mjesec, godina ;
    bool ProvjeriDatum(int d, int m, int g){
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(g % 4 == 0  && g % 100 != 0 || g % 400 == 0)
            broj_dana[1]++;
        if(g < 1 || m < 1 || m > 12 || d < 1 || d > broj_dana[m - 1])
            return false;
        return true;
    }
public:
    Datum(int dan, int mjesec, int godina){
        if(!ProvjeriDatum(dan, mjesec, godina))  throw domain_error("Neispravan datum");
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    }
    Datum(){}
    void Postavi(int dan, int mjesec, int godina){
        if(!ProvjeriDatum(dan, mjesec, godina))  throw domain_error("Neispravan datum");
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    }
    tuple<int, int, int> Ocitaj() const{ return make_tuple(dan,mjesec,godina); }
    void Ispisi() const{
        cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};

class Vrijeme{
    int sati, minute;
    bool ProvjeriVrijeme(int sati, int minute){
        if((sati < 0 || sati > 23) || (minute < 0 || minute >59)) return false;
        return true;
    }
public:
    Vrijeme(int sati, int minute){
        if(!ProvjeriVrijeme(sati,minute)) throw domain_error("Neispravno vrijeme");
        Vrijeme::sati = sati; Vrijeme::minute = minute;
    }
    Vrijeme(){}
    void Postavi(int sati, int minute){
        if(!ProvjeriVrijeme(sati, minute)) throw domain_error("Neispravno vrijeme");
        Vrijeme::sati = sati; Vrijeme::minute = minute;
    }
    pair<int, int> Ocitaj () const{ return make_pair(sati, minute); }
    void Ispisi() const { 
        if(sati < 10) cout<<"0";
        cout<<sati<<":";
        if(minute < 10) cout<<"0";
        cout<<minute;
    }
};

class Pregled{
    string ime;
    Datum datum;
    Vrijeme vrijeme;
public:
    Pregled(const string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda){
        ime = ime_pacijenta; 
        tuple<int, int, int> d(datum_pregleda.Ocitaj());
        datum.Postavi(get<0>(d), get<1>(d), get<2>(d));
        pair<int, int> v(vrijeme.Ocitaj());
        vrijeme.Postavi(v.first, v.second);
    }
    Pregled(){}
    Pregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
    int godina_pregleda, int sati_pregleda, int minute_pregleda){
        ime = ime_pacijenta;
        datum.Postavi(dan_pregleda, mjesec_pregleda, godina_pregleda);
        vrijeme.Postavi(sati_pregleda, minute_pregleda);
    }
    void PromijeniPacijenta(const string &ime_pacijenta){ ime = ime_pacijenta; }
    void PromijeniDatum(const Datum &novi_datum){
        tuple<int, int, int> d(novi_datum.Ocitaj());
        datum.Postavi(get<0>(d), get<1>(d), get<2>(d));
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
        pair<int,int> v(novo_vrijeme.Ocitaj());
        vrijeme.Postavi(v.first, v.second);
    }
    void PomjeriDanUnaprijed() {
        tuple<int, int, int> d(datum.Ocitaj());
        get<0>(d)++;
        try{
            datum.Postavi(get<0>(d), get<1>(d), get<2>(d));
        }
        catch(...){
            get<0>(d) = 1;
            get<1>(d)++;
            try{
                datum.Postavi(get<0>(d), get<1>(d), get<2>(d));
            }
            catch(...){
                get<1>(d) = 1;
                get<2>(d)++;
            }
        }
    }
    void PomjeriDanUnazad(){
        auto d(datum.Ocitaj());
        get<0>(d)--;
        try{
            datum.Postavi(get<0>(d), get<1>(d), get<2>(d));
        }
        catch(...){
            get<1>(d)--;
            int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            get<0>(d) = broj_dana[get<1>(d) - 1];
        
            try{
                datum.Postavi(get<0>(d), get<1>(d), get<2>(d));
            }
            catch(...){
                get<1>(d) = 12;
                get<2>(d)--;
            }
        }
    }
    string DajImePacijenta() const{ return ime; }
    Datum DajDatumPregleda() const { return datum; }
    Vrijeme DajVrijemePregleda() const { return vrijeme; }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const{
       cout<<setw(30)<<left<<ime; datum.Ispisi(); cout<<" "; vrijeme.Ispisi(); cout<<endl; 
    }  
};
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2){
    auto d1(p1.datum.Ocitaj()), d2(p2.datum.Ocitaj());
    auto v1(p1.vrijeme.Ocitaj()), v2(p2.vrijeme.Ocitaj());
    if(get<2>(d2) > get<2>(d1)) return true;
    else if(get<1>(d2) > get<1>(d1)) return true;
    else if(get<0>(d2) > get<0>(d1)) return true;
    else if(v2.first > v1.first) return true;
    else if(v2.second > v1.second) return true;
    return false;
}
class Pregledi{
    int broj_obrisanih = 0;
     int max_broj_pregleda;
    int broj_registrovanih ;
    Pregled **elementi;
  
public:
    explicit Pregledi(int max_broj_pregleda):max_broj_pregleda(max_broj_pregleda), elementi(new Pregled *[max_broj_pregleda] {} ), broj_registrovanih(0) { }
    
    Pregledi(initializer_list<Pregled> spisak_pregleda):max_broj_pregleda(spisak_pregleda.size()), elementi(new Pregled *[spisak_pregleda.size()] {} ){
        int br(0);
        for(auto p = spisak_pregleda.begin(); p != spisak_pregleda.end(); p++){
            elementi[br] = new Pregled(*p);
            br++;
        }
        broj_registrovanih = spisak_pregleda.size();
    }
    ~Pregledi(){
        if(elementi!=0){
        for(int i = 0; i < max_broj_pregleda - broj_obrisanih; i++) delete elementi[i];
        delete [] elementi;
        }
     }
    Pregledi(const Pregledi &pregledi){
        elementi=new Pregled*[pregledi.max_broj_pregleda]{};
        for(int i=0;i<pregledi.broj_registrovanih;i++) elementi[i]=new Pregled(*(pregledi.elementi[i]));
        max_broj_pregleda=pregledi.max_broj_pregleda; broj_registrovanih=pregledi.broj_registrovanih;
    }
    Pregledi(Pregledi &&pregledi){
        elementi=pregledi.elementi; max_broj_pregleda=pregledi.max_broj_pregleda;
        broj_registrovanih=pregledi.broj_registrovanih;
        for(int i=0;i<broj_registrovanih;i++) pregledi.elementi[i]=0;
        pregledi.elementi=0; 
    }
    Pregledi &operator =(const Pregledi &pregledi){ // Pregledi pregledi
        if(elementi!=0){
        for(int i = 0; i < max_broj_pregleda; i++) delete  elementi[i];
        delete [] elementi;
        }
        elementi=new Pregled*[pregledi.max_broj_pregleda]{};
        for(int i=0;i<pregledi.broj_registrovanih;i++) elementi[i]=new Pregled(*(pregledi.elementi[i]));
        max_broj_pregleda=pregledi.max_broj_pregleda; broj_registrovanih=pregledi.broj_registrovanih;
        return *this;
    }
    Pregledi &operator =(Pregledi &&pregledi){
        if(this!=&pregledi){
             elementi=pregledi.elementi; max_broj_pregleda=pregledi.max_broj_pregleda;
        broj_registrovanih=pregledi.broj_registrovanih;
        for(int i=0;i<broj_registrovanih;i++) pregledi.elementi[i]=0;
        pregledi.elementi=0; 
        }
        return *this;
    }
    void RegistrirajPregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        if(broj_registrovanih >= max_broj_pregleda) throw range_error("Dostignut maksimalni broj pregleda");
        elementi[broj_registrovanih++] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    }
    void RegistrirajPregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
    int godina_pregleda, int sati_pregleda, int minute_pregleda){
        if(broj_registrovanih >= max_broj_pregleda) throw range_error("Dostignut maksimalni broj pregleda");
        elementi[broj_registrovanih++] = new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
    }
    void RegistrirajPregled(Pregled *pregled){
        if(broj_registrovanih >= max_broj_pregleda) throw range_error("Dostignut maksimalni broj pregleda");
        elementi[broj_registrovanih++] = pregled;
    }
    int DajBrojPregleda() const { return broj_registrovanih; }
    int DajBrojPregledaNaDatum(const Datum &datum) const{
        return count_if(elementi, elementi + broj_registrovanih,[datum](Pregled *p){
            int a1, a2, b1, b2, c1, c2;
            tie(a1,b1,c1) = datum.Ocitaj();
            tie(a2,b2,c2) = p->DajDatumPregleda().Ocitaj();
           if(a1 == a2 && b1 == b2 && c1 == c2) return true; 
           return false;
        });
    }
    Pregled &DajNajranijiPregled(){
        if(broj_registrovanih == 0) throw domain_error ("Nema registriranih pregleda");
        return **min_element(elementi, elementi + broj_registrovanih, [](Pregled *p1,Pregled *p2){
            return Pregled::DolaziPrije(*p1,*p2);
        });
    }
    Pregled DajNajranijiPregled() const{
        if(broj_registrovanih == 0) throw domain_error ("Nema registriranih pregleda");
        return **min_element(elementi, elementi + broj_registrovanih, [](Pregled *p1, Pregled *p2){
           return Pregled::DolaziPrije(*p1,*p2);
       });
    }
    void IsprazniKolekciju(){ 
        for(int i = 0; i < max_broj_pregleda; i++) delete elementi[i];
        delete [] elementi; 
    }
    void ObrisiNajranijiPregled(){
        auto p = *min_element(elementi, elementi + broj_registrovanih, [](Pregled *p1,Pregled *p2){
        return Pregled::DolaziPrije(*p1,*p2);
    });
    delete p;
    broj_obrisanih++,
        broj_registrovanih--;
    }
    void ObrisiPregledePacijenta(const string &ime_pacijenta){
        int br(0);
        for(int i = 0; i < broj_registrovanih; i++)
            if(elementi[i]->DajImePacijenta() == ime_pacijenta) { br++; delete  elementi[i];  elementi[i] = nullptr; }
        broj_registrovanih -= br;
    }
    void IspisiPregledeNaDatum(const Datum &datum) const{
        
        for(int i = 0; i < broj_registrovanih; i++ ){
            auto d1((elementi[i]->DajDatumPregleda()).Ocitaj()), d2(datum.Ocitaj());
            if(get<0>(d1) == get<0>(d2) && get<1>(d1) == get<1>(d2) && get<2>(d1) == get<2>(d2)) elementi[i]->Ispisi();
        }
    }
    void IspisiSvePreglede() const{
        
        auto elementi(*this);
        sort(elementi.elementi, elementi.elementi + broj_registrovanih, [] (Pregled *pr1, Pregled *pr2){
            if(Pregled::DolaziPrije(*pr1, *pr2)) return true;
            return false;
        }); 
        for(int i = 0; i < broj_registrovanih; i++)
            (elementi.elementi[i])->Ispisi();
    }
};
int main ()
{

try{
    cout<<"Unesite maksimalan broj pregleda: ";
    int max;
    cin>>max;
    
    Pregledi pregledi(max);
    while(pregledi.DajBrojPregleda() != max){
        string ime;
        cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        cin.clear();
        cin.ignore(1000,'\n');
        getline(cin, ime);
        if(ime == "kraj") break;
        int d,m,g;
        int h,min;
        cout<<"Unesite dan mjesec i godinu pregleda: ";
        cin>>d>>m>>g;
        Datum dat(d,m,g);
        cout<<"Unesite sate i minute pregleda: ";
        cin>>h>>min;
        Vrijeme v(h, min);
        
        pregledi.RegistrirajPregled(ime, d,m,g,h,min);
    }
    pregledi.DajNajranijiPregled().Ispisi();
    
   cout<<"Trenutno su registrovani sljedeci pregledi: "<<endl;
    
    cout<<endl;
    
    while(1){
        
        cout<<"Odaberite jednu od sljedecih opcija"<<endl
        <<"1 - Broj pregleda na datum"<<endl
        <<"2 - Najraniji pregled"<<endl
        <<"3 - Obrisi pregled pacijenta"<<endl
        <<"4 - Obrisi najraniji pregled"<<endl
        <<"5 - Ispisi sve pregleda na datum"<<endl
        <<"6 - Ispisi sve preglede"<<endl
        <<"7 - Kraj programa"<<endl;
    
        int unos;
        cin>>unos;
        if(unos == 7) break;
        
        if(unos == 1){
            cout<<"Unesite dan mjesec i godinu : ";
            int d,m,g;
            cin>>d>>m>>g;
            Datum dat(d, m ,g);
            auto t (dat.Ocitaj());
            cout<<"Broj pregleda na datum "<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" je: ";
            cout<<pregledi.DajBrojPregledaNaDatum(dat);
            cout<<endl;
        }
        else if(unos == 2){
            cout<<"Najraniji pregled je:"<<endl;
            pregledi.DajNajranijiPregled().Ispisi();
            cout<<endl;
        }
        else if(unos == 3){
            cout<<"Unesite ime pacijenta: ";
                string s;
                cin.clear();
                cin.ignore(1000,'\n');
                getline(cin, s);
                int br1 = pregledi.DajBrojPregleda();
                pregledi.ObrisiPregledePacijenta(s);
                int br2 = pregledi.DajBrojPregleda();
                cout<<"Uspjesno obrisano "<<br1 - br2<<" pregleda"<<endl;
        }
        else if(unos == 4){
            if(pregledi.DajBrojPregleda() != 0){
                pregledi.ObrisiNajranijiPregled();
                cout<<"Najraniji pregled uspjesno obrisan";
            }
            else cout<<"Nema registriranih pregleda";
            cout<<endl;
        }
        else if(unos == 5){
            cout<<"Unesite dan mjesec i godinu : ";
            int d,m,g;
            cin>>d>>m>>g;
            Datum dat(d, m ,g);
            auto t (dat.Ocitaj());
            cout<<"Pregledi na datum "<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" su: "<<endl;
            pregledi.IspisiPregledeNaDatum(dat);
            cout<<endl;
        }
        else if(unos == 6){
            pregledi.IspisiSvePreglede();
        }
        cout<<endl;
    }
}
catch(range_error e){
    cout<<e.what()<<endl;
}
catch(domain_error e){
    cout<<e.what()<<endl;
}
	return 0;
}









