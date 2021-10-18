/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <stdexcept>

using namespace std;
class Datum{
    public:
    int nizz[12]{31,28,31,30,31,30,31,31,30,31,30,31};
  int dan, mjesec, godina;

    Datum(int dan=1, int mjesec=1, int godina=2000) {
        if(dan>31 || dan<=0 || mjesec>12 || mjesec<=0 || godina<0) throw domain_error("Neispravan datum");
        if(dan>nizz[mjesec-1]) throw domain_error("Neispravan datum");
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    };
    void Postavi(int dan, int mjesec, int godina){
        if(dan>31 || dan<=0 || mjesec>12 || mjesec<=0 || godina<0) throw domain_error("Neispravan datum");
        if(dan>nizz[mjesec-1]) throw domain_error("Neispravan datum");
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    }
    tuple<int, int, int> Ocitaj() const{
        return tuple<int, int, int>(dan, mjesec, godina);
    }
   
    void Ispisi() const{
        cout << dan << "/" << mjesec << "/" << godina;
    }
   
};

class Vrijeme{
public:
    int sati, minute;
    Vrijeme(int sati=1, int minute=0){
        if(sati>23 || sati<0 || minute>59 || minute<0) throw domain_error("Neispravno vrijeme");
        Vrijeme::sati = sati; Vrijeme::minute = minute;
    }
        
    void Postavi(int sati, int minute){
        if(sati>23 || sati<0 || minute>59 || minute<0) throw domain_error("Neispravno vrijeme");
        Vrijeme::sati = sati; Vrijeme::minute = minute;
    }
    pair<int, int> Ocitaj() const{
        return pair<int, int>(sati, minute);
    }
    int DajSate() const{ return sati; }
    int DajMinute() const{ return minute; }
    void Ispisi() const{
        if(sati <10){
        cout <<"0"<< sati << ":";
        if(minute<10) cout << "0"<<minute;
        else cout << minute;
        } else if(minute <10){
            cout << sati << ":0" <<minute; 
        } else cout << sati <<":"<<minute;
    }
    friend class Pregled;
};

class Pregled{
    string ime_prezime;
    Datum d;
    Vrijeme v;
public:
    Pregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): ime_prezime(ime_pacijenta), d(datum_pregleda),
    v(vrijeme_pregleda){
      //  ime_prezime = ime_pacijenta; d.dan = datum_pregleda.dan; d.mjesec = datum_pregleda.mjesec; d.godina = datum_pregleda.godina;
      //  v.sati = vrijeme_pregleda.sati;  v.minute = vrijeme_pregleda.minute;
    }
    Pregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
    int sati_pregleda, int minute_pregleda): ime_prezime(ime_pacijenta), d(dan_pregleda, mjesec_pregleda, godina_pregleda), v(sati_pregleda, minute_pregleda) {
      //  ime_prezime = ime_pacijenta; Pregled::d=Datum(dan_pregleda, mjesec_pregleda, godina_pregleda);
     //   Pregled::v=Vrijeme(sati_pregleda, minute_pregleda);
    }
    void PromijeniPacijenta(const string &ime_pacijenta){
        Pregled::ime_prezime = ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum){
        Pregled::d.dan = novi_datum.dan; Pregled::d.mjesec = novi_datum.mjesec; Pregled::d.godina = novi_datum.godina;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
        Pregled::v.sati = novo_vrijeme.sati; Pregled::v.minute = novo_vrijeme.minute;
    }
    void PomjeriDanUnaprijed(){
        
        if(d.godina % 4 == 0 && d.godina%100 != 0 || d.godina%400 == 0 && d.mjesec==2){
            if(d.dan==28) d.dan++;
            if(d.dan==29) {
                d.dan = 1; d.mjesec = 3;
            }
            
        } else if(d.mjesec == 2 && d.dan == 28){
            d.dan = 1; d.mjesec = 3;
        } else if(d.mjesec == 12 && d.dan == 31){
            d.dan = 1; d.mjesec = 1; d.godina++;
        } else if(d.dan == d.nizz[d.mjesec-1]){
            d.dan == 1; d.mjesec++;
        } else 
        if(d.dan<31 && d.dan>0)
        d.dan++;
    }
    void PomjeriDanUnazad(){
        if((d.godina % 4 == 0 && d.godina%100 != 0 || d.godina%400 == 0) && d.mjesec == 3){
            d.dan = 29;
            d.mjesec--;
        } else if(d.mjesec == 3){
            d.dan = 28;
            d.mjesec--;
        }else
        if(d.dan == 1 && d.mjesec != 1){
            d.dan == d.nizz[d.mjesec-2];
            d.mjesec--;
        } else if(d.dan == 1 && d.mjesec ==1){
            d.dan = 31;
            d.mjesec = 12;
            d.godina--;
        } else
        if(d.dan<=31 && d.dan>1)
        d.dan--;
    }
    string DajImePacijenta() const {
        return ime_prezime;
    }
    Datum DajDatumPregleda() const{
        return d;
    }
    Vrijeme DajVrijemePregleda() const{
        return v;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
        if(p1.DajDatumPregleda().godina < p2.DajDatumPregleda().godina) return true; else
        if(p1.DajDatumPregleda().godina > p2.DajDatumPregleda().godina) return false; else    
            if(p1.DajDatumPregleda().godina ==  p2.DajDatumPregleda().godina && p1.DajDatumPregleda().mjesec < p2.DajDatumPregleda().mjesec) return true; else
            if(p1.DajDatumPregleda().mjesec > p2.DajDatumPregleda().mjesec) return false; else
                if(p1.DajDatumPregleda().mjesec == p2.DajDatumPregleda().mjesec && p1.DajDatumPregleda().dan < p2.DajDatumPregleda().dan) return true; else
                if(p1.DajDatumPregleda().dan > p2.DajDatumPregleda().dan) return false; else
                    if(p1.DajDatumPregleda().dan == p2.DajDatumPregleda().dan && p1.DajVrijemePregleda().sati < p2.DajVrijemePregleda().sati) return true; else
                    if(p1.DajVrijemePregleda().sati > p2.DajVrijemePregleda().sati) return false; else
                        if(p1.v.sati == p2.v.sati &&p1.v.minute < p2.v.minute) return true;
                        return false;
                            
    }
    void Ispisi() const{
        cout << left << setw(30) << ime_prezime;
        d.Ispisi(); cout << " " ;
        v.Ispisi(); cout << endl; 
    }
    friend class Pregledi;
    
};

class Pregledi{
    Pregled **niz;
    int max_br;
    int broj_pregleda;
    
public:
int brojacizb=0;
   explicit Pregledi(int max_broj_pregleda): broj_pregleda(0), max_br(max_broj_pregleda), niz(new Pregled*[max_broj_pregleda]{}){ };
   Pregledi(initializer_list<Pregled> spisak_pregleda): broj_pregleda(spisak_pregleda.size()), max_br(spisak_pregleda.size()), niz(new Pregled*[spisak_pregleda.size()]{}){
       try{
       for(auto iterator = spisak_pregleda.begin(); iterator != spisak_pregleda.end(); ++iterator){
           niz[broj_pregleda] = new Pregled(iterator->DajImePacijenta(), iterator->DajDatumPregleda(), iterator->DajVrijemePregleda());
           broj_pregleda++;
       
       }}
       catch(...){
           for(int i=0; i<broj_pregleda; i++){
               delete niz[i]; 
           } delete[] niz; broj_pregleda=0;    throw;  }
   }
   ~Pregledi(){
       for(int i=0; i<broj_pregleda; i++)
           delete niz[i]; delete[]niz;
           broj_pregleda = 0;
   }
   Pregledi(const Pregledi &pregledi): broj_pregleda(pregledi.broj_pregleda), niz(new Pregled*[pregledi.max_br]{}){
       try{for(int i=0; i< pregledi.broj_pregleda; i++)
           niz[i] = new Pregled(*(pregledi.niz[i])); } catch(...){ throw;}
       }
    Pregledi(Pregledi &&pregledi){
       try{ for(int i=0; i<pregledi.broj_pregleda; i++){
            niz[i] = new Pregled(*(pregledi.niz[i]));} }
         catch(...){ throw; }
            for(int i=0; i<pregledi.broj_pregleda; i++){
                delete pregledi.niz[i];
            }
         delete[] pregledi.niz;
        broj_pregleda = pregledi.broj_pregleda;
    }
    Pregledi &operator =(const Pregledi &pregledi){
        if(max_br < pregledi.broj_pregleda) throw logic_error("Neispravno");
        else { try{
            for(int i=0; i<broj_pregleda; i++) delete niz[i];
            delete[] niz;
            niz = new Pregled*[pregledi.broj_pregleda];
            for(int i=0; i<pregledi.broj_pregleda; i++)
            niz[i] = new Pregled(*(pregledi.niz[i])); 
            broj_pregleda = pregledi.broj_pregleda; } catch(...){ 
                for(int i=0; i<pregledi.broj_pregleda; i++){
                    delete niz[i];
                } delete[] niz;
                throw; }
        }
        return *this;
    }
    Pregledi &operator =(Pregledi &&pregledi){
        if(max_br < pregledi.broj_pregleda) throw logic_error("Neispravno");
        else{ try{
            for(int i=0; i<broj_pregleda; i++) delete niz[i];
            delete[] niz;
            niz = new Pregled*[pregledi.broj_pregleda];
            for(int i=0; i<pregledi.broj_pregleda; i++)
                niz[i] = new Pregled(*(pregledi.niz[i]));
                broj_pregleda = pregledi.broj_pregleda;
           }  catch(...){ 
                for(int i=0; i<pregledi.broj_pregleda; i++){
                    delete niz[i];
                } delete[] niz;
                throw; }}
           for(int i=0; i<pregledi.broj_pregleda; i++)
           delete pregledi.niz[i]; delete[] pregledi.niz;
        return *this;
    } 
    void RegistrirajPregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        broj_pregleda++;
        if(broj_pregleda>max_br){
            broj_pregleda--;
            throw range_error("Dostignut maksimalni broj pregleda");
        }
        try{
        niz[broj_pregleda-1] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);  
        } catch(...){broj_pregleda--; throw; }
         
    }
    void RegistrirajPregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
    int sati_pregleda, int minute_pregleda){
       try{
        if(broj_pregleda >= max_br){
          
            throw range_error("Dostignut maksimalni broj pregleda");
        }
        
        niz[broj_pregleda] = new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda); 
        }
        catch(...){  delete niz[broj_pregleda]; throw; }
        broj_pregleda++;
          }
    void RegistrirajPregled(Pregled *pregled){
        broj_pregleda++;
        if(broj_pregleda > max_br){
            broj_pregleda--;
            throw range_error("Dostignut maksimalni broj pregleda");
        }
        try{
        niz[broj_pregleda-1] = new Pregled(pregled->DajImePacijenta(), pregled->DajDatumPregleda(), pregled->DajVrijemePregleda());
        } catch(...){ broj_pregleda--; delete pregled; throw; }
        delete pregled;
        
    }
    int DajBrojPregleda() const{ return broj_pregleda; }
    int DajBrojPregledaNaDatum(const Datum &datum){
        return count_if(niz,niz+broj_pregleda,[&datum](Pregled *p) {
            if (datum.dan == p->DajDatumPregleda().dan && datum.mjesec == p->DajDatumPregleda().mjesec && datum.godina == p->DajDatumPregleda().godina) return true; return false;
        });
    }
    Pregled &DajNajranijiPregled(){
       return  **min_element(niz, niz+broj_pregleda, [](Pregled *p1, Pregled *p2){
                if(p1->DajDatumPregleda().godina < p2->DajDatumPregleda().godina) return true; else 
                if(p1->DajDatumPregleda().godina > p2->DajDatumPregleda().godina) return false; else
                if(p1->DajDatumPregleda().godina ==  p2->DajDatumPregleda().godina && p1->DajDatumPregleda().mjesec < p2->DajDatumPregleda().mjesec) return true; else 
                if( p1->DajDatumPregleda().mjesec > p2->DajDatumPregleda().mjesec) return false; else
                if(p1->DajDatumPregleda().mjesec ==  p2->DajDatumPregleda().mjesec && p1->DajDatumPregleda().dan < p2->DajDatumPregleda().dan) return true; else
                if(p1->DajDatumPregleda().dan > p2->DajDatumPregleda().dan) return false; else
                if(p1->DajDatumPregleda().dan == p2->DajDatumPregleda().dan && p1->DajVrijemePregleda().sati < p2->DajVrijemePregleda().sati) return true; else
                if(p1->DajVrijemePregleda().sati > p2->DajVrijemePregleda().sati) return false;
                if(p1->DajVrijemePregleda().sati == p2->DajVrijemePregleda().sati && p1->DajVrijemePregleda().minute < p2->DajVrijemePregleda().minute) return true; else
                if(p1->DajVrijemePregleda().minute > p2->DajVrijemePregleda().minute) return false; else
                if(p1->DajVrijemePregleda().minute == p2->DajVrijemePregleda().minute) return true;
            }) ; 
    }
    void IsprazniKolekciju(){
        for(int i=0; i<broj_pregleda; i++){
        delete niz[i];    
        }delete[] niz; //niz = nullptr;    
        broj_pregleda = 0;
    }
    void ObrisiNajranijiPregled(){
        Pregled *p = &DajNajranijiPregled();
        for(int i=0; i<broj_pregleda; i++){
            if(niz[i]->DajDatumPregleda().godina == p->DajDatumPregleda().godina &&
            niz[i]->DajDatumPregleda().mjesec == p->DajDatumPregleda().mjesec &&
            niz[i]->DajDatumPregleda().dan == p->DajDatumPregleda().dan)
            
            niz[i] = nullptr;
           
        }
        delete p;
        remove(niz, niz+broj_pregleda, nullptr);
        broj_pregleda--;
    }
    void ObrisiPregledePacijenta(const string &ime_pacijenta){
        int brojac(0);
        for(int i=0; i<broj_pregleda; i++){
            if(niz[i]->DajImePacijenta() == ime_pacijenta){
                delete niz[i];
                niz[i] = nullptr;
                brojac++;
                brojacizb++;
            }
        }
        remove(niz, niz+broj_pregleda, nullptr);
        
        broj_pregleda -= brojac;
        
    }
    void IspisiPregledeNaDatum(const Datum &d){
        Pregled **p(new Pregled*[broj_pregleda]);
        int brojac=0;
       for(int i=0; i<broj_pregleda; i++){
           if(d.dan == niz[i]->DajDatumPregleda().dan && d.mjesec == niz[i]->DajDatumPregleda().mjesec && d.godina == niz[i]->DajDatumPregleda().godina)
           {                
            p[brojac] = new Pregled(niz[i]->DajImePacijenta(), niz[i]->DajDatumPregleda(), niz[i]->DajVrijemePregleda());
            brojac++;
           }
       }
       for(int i=brojac; i<broj_pregleda; i++){
           p[i] = nullptr;
       }
       sort(p, p+brojac, [](Pregled *p1, Pregled *p2){
          if(p1->DajVrijemePregleda().sati < p2->DajVrijemePregleda().sati) return true; else
          if(p1->DajVrijemePregleda().sati > p2->DajVrijemePregleda().sati) return false; else
          if(p1->DajVrijemePregleda().sati == p2->DajVrijemePregleda().sati && p1->DajVrijemePregleda().minute < p2->DajVrijemePregleda().minute) return true; else
          if(p1->DajVrijemePregleda().minute == p2->DajVrijemePregleda().minute) return true; return false;
       });
      // cout << "Trenutno su registrovani sljedeci pregledi \n";
       for(int i=0; i<brojac; i++){ 
           p[i]->Ispisi();
       }
       for(int i=0; i<brojac; i++){
           delete p[i]; 
       } delete[] p; 
    }
    void IspisiSvePreglede(){
        sort(niz, niz+broj_pregleda, [](Pregled *p1, Pregled *p2){
            if(p1->DajDatumPregleda().godina < p2->DajDatumPregleda().godina) return true; else
            if(p1->DajDatumPregleda().godina > p2->DajDatumPregleda().godina) return false; else 
            if(p1->DajDatumPregleda().godina == p2->DajDatumPregleda().godina && p1->DajDatumPregleda().mjesec < p2->DajDatumPregleda().mjesec) return true; else
            if(p1->DajDatumPregleda().mjesec > p2->DajDatumPregleda().mjesec ) return false; else
            if(p1->DajDatumPregleda().mjesec == p2->DajDatumPregleda().mjesec && p1->DajDatumPregleda().dan < p2->DajDatumPregleda().dan) return true; else
            if(p1->DajDatumPregleda().dan > p2->DajDatumPregleda().dan) return false; else
            if(p1->DajDatumPregleda().dan == p2->DajDatumPregleda().dan && p1->DajVrijemePregleda().sati < p2->DajVrijemePregleda().sati) return true; else
            if(p1->DajVrijemePregleda().sati > p2->DajVrijemePregleda().sati) return false; else
            if(p1->DajVrijemePregleda().sati == p2->DajVrijemePregleda().sati && p1->DajVrijemePregleda().minute < p2->DajVrijemePregleda().minute) return true; else
            if(p1->DajVrijemePregleda().minute > p2->DajVrijemePregleda().minute) return false; return false;
            
        });
      //  cout << "Trenutno su registrovani sljedeci pregledi \n";
        for(int i=0;i<broj_pregleda; i++){
            niz[i]->Ispisi();
        }
    }
    void Dealociraj(){
        for(int i=broj_pregleda+1; i<max_br; i++){
            niz[i] = nullptr;
        }
    }
};

int main ()
{   
    int i = 0;
    
    
    cout << "Unesite maksimalan broj pregleda: ";
    int br_pregleda;
    cin >> br_pregleda;
    try{
    Pregledi pregledi(br_pregleda);
    string ime_pacijenta;

    while(i != br_pregleda){
    cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
    
    cin >> ime_pacijenta;
    if(ime_pacijenta == "kraj") {
    cin.clear();
    cin.ignore(10000,'\n');
    break;}
    
    cout << "Unesite dan mjesec i godinu pregleda: ";
    int dan, mjesec, godina;
    cin >> dan >> mjesec >> godina;
    
    cout << "Unesite sate i minute pregleda: ";
    int sati, minute;
    cin >> sati >> minute;

 //   Pregled p1(ime_pacijenta, dan, mjesec, godina, sati, minute); 
    pregledi.RegistrirajPregled(ime_pacijenta, dan, mjesec, godina, sati, minute);
    i++;
    }
    cout << "Trenutno su registrovani sljedeci pregledi\n";
    pregledi.IspisiSvePreglede();
   

    
    for(;;){
    cout << "\nOdaberite jednu od sljedecih opcija\n";
    cout << "1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n";
    cout << "4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa\n";
    
    int n; 
    cin >> n;
    if(n==1){
        cout << "Unesite dan mjesec i godinu : ";
        int a,b,c;
        cin >> a >> b >> c;
        
        cout << "Broj pregleda na datum " << a << " " <<b<< " "<<c << " je: " << pregledi.DajBrojPregledaNaDatum(Datum(a,b,c)) << endl;
       
        
    }
    else if(n==2){
        cout << "Najraniji pregled je:\n";
        pregledi.DajNajranijiPregled().Ispisi();
    }
    else if(n==3){
        cout << "Unesite ime pacijenta: ";
        string ime_pac;
        cin >> ime_pac;
        pregledi.ObrisiPregledePacijenta(ime_pac);
        cout << "Uspjesno obrisano " << pregledi.brojacizb << " pregleda";
        
        
    }
    else if(n==4){
        pregledi.ObrisiNajranijiPregled();
        cout << "Najraniji pregled uspjesno obrisan\n";
    
       
    }
    else if(n==5){
        cout << "Unesite dan mjesec i godinu : ";
        int a,b,c;
        cin >> a >> b >> c;
        cout << "Pregledi na datum "<<a<<" " <<b<<" "<<c << " su:\n";
        pregledi.IspisiPregledeNaDatum(Datum(a,b,c));
        cout << endl;
    }
    else if(n==6){
        
        pregledi.IspisiSvePreglede();
        cout << endl;
    }
    else if(n==7){ pregledi.Dealociraj();
        break;
    }
           
    }
    }
    catch(range_error izuzetak){
        cout << izuzetak.what();
    }
    catch(domain_error izuzetak){
        cout << izuzetak.what();
    }
    catch(...){  }
	return 0;
}
