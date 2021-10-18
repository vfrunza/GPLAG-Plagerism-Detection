/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

bool prestupna(int year){
     return ( (year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0));
}



class Datum{
     int dan,mjesec,godina;
public:
     Datum(int dan=1, int mjesec=1, int godina=1){
          vector<int> dani{31,28,31,30,31,30,31,31,30,31,30,31};
          if(prestupna(godina)) dani[1]++;
          if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > dani[mjesec-1]) throw domain_error("Neispravan datum!");
          Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
     }
     void Postavi(int dan, int mjesec, int godina){
          vector<int> dani{31,28,31,30,31,30,31,31,30,31,30,31};
          if(prestupna(godina)) dani[1]++;
          if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > dani[mjesec-1]) throw domain_error("Neispravan datum!");
          Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
     }
     std::tuple<int, int, int> Ocitaj() const { return make_tuple(dan,mjesec,godina);}
     void Ispisi() const {cout<<dan<<"/"<<mjesec<<"/"<<godina<<" ";}

};

class Vrijeme{
  int sati,minute;
public:
     Vrijeme(int sati=0, int minute=0){
          if(sati>23 || sati<0 || minute>59 || minute<0)throw domain_error("Neispravno vrijeme!");
          Vrijeme::sati=sati; Vrijeme::minute=minute;
     }
     void Postavi(int sati, int minute){
          if(sati>23 || sati<0 || minute>59 || minute<0)throw domain_error("Neispravno vrijeme!");
          Vrijeme::sati=sati; Vrijeme::minute=minute;
     }
     std::pair<int, int> Ocitaj () const{
          return make_pair(sati,minute);
     }
     void Ispisi() const{cout <<setw(2)<<right<<setfill('0')<<sati << ":" <<setfill('0') <<setw(2) << minute ;}
};

class Pregled{
     string ime;
     Datum dat;
     Vrijeme vr;
public:
     Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
           ime=ime_pacijenta; dat=datum_pregleda; vr=vrijeme_pregleda;
      }
     Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, int sati_pregleda, int minute_pregleda){
           ime=ime_pacijenta;
           dat=Datum(dan_pregleda,mjesec_pregleda,godina_pregleda);
           vr=Vrijeme(sati_pregleda,minute_pregleda);
      }
     void PromijeniPacijenta(const std::string &ime_pacijenta){
          ime=ime_pacijenta;
     }
     void PromijeniDatum(const Datum &novi_datum){
          dat=(novi_datum);
     }
     void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
          vr=(novo_vrijeme);
     }
     void PomjeriDanUnaprijed(){
          tuple<int,int,int> t=dat.Ocitaj();
          int dan=get<0>(t), mj=get<1>(t), god=get<2>(t);
          dan++;
          if(dan==32 && (mj==1 || mj==3 || mj==5 || mj==7 || mj==8 || mj==10 || mj==12)){
               dan=1; mj++;
               if(mj==13) { mj=1; god++;}
          }
          else if(dan==31 &&(mj==4 || mj==6 || mj==9 || mj==11)){
               dan=1; mj++; if(mj==13) { mj=1; god++;}
          }
          else if(mj==2 && ((dan==29 && !prestupna(god))||(dan==30 && prestupna(god)))){
               dan=1; mj=3;
          }
          dat=Datum(dan,mj,god);
     }
     void PomjeriDanUnazad(){
          tuple<int,int,int> t=dat.Ocitaj();
          int dan=get<0>(t), mj=get<1>(t), god=get<2>(t);
          dan--;
          if(dan==0){
               mj--;
               if(mj==0) { mj=12; god--;}
               if(mj==1 || mj==3 || mj==5 || mj==7 || mj==8 || mj==10 || mj==12){
                    dan=31;
               }
               else if(mj==4 || mj==6 || mj==9 || mj==11) dan=30;
               else if(mj==2 && prestupna(god)) mj=29;
               else mj=28;
          }
          dat=Datum(dan,mj,god);
     }
     std::string DajImePacijenta() const{ return ime;}
     Datum DajDatumPregleda() const { return dat;}
     Vrijeme DajVrijemePregleda() const { return vr;}
     static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
          vector<int> dani{31,28,31,30,31,30,31,31,30,31,30,31};
          int suma2=get<0>(p2.DajDatumPregleda().Ocitaj()), suma1=get<0>(p1.DajDatumPregleda().Ocitaj());
          int mj1=get<1>(p1.DajDatumPregleda().Ocitaj()), mj2=get<1>(p2.DajDatumPregleda().Ocitaj());
          int god1=get<2>((p1.DajDatumPregleda().Ocitaj())), god2=get<2>((p2.DajDatumPregleda().Ocitaj()));
          int sat1=p1.DajVrijemePregleda().Ocitaj().first, sat2=p2.DajVrijemePregleda().Ocitaj().first;
          int min1=p1.DajVrijemePregleda().Ocitaj().second, min2=p2.DajVrijemePregleda().Ocitaj().second;
          if(god1<god2) return true;
          else if(god1==god2){
               if(mj1<mj2) return true;
               else if(mj1==mj2){
                    if(suma1<suma2) return true;
                    else if(suma1==suma2){
                         if(sat1<sat2) return true;
                         else if(sat1==sat2){
                              if(min1<min2) return true;
                              return false;
                         }
                         else return false;
                    }
                    else return false;
               }
               else return false;
          }
          else return false;
     }
     void Ispisi() const{
        cout<<setw(30)<<left<<setfill(' ')<<ime;
        dat.Ispisi();
        vr.Ispisi();
        cout<<endl;
     }

};

bool DolaziPrije(const Pregled &p1, const Pregled &p2){
          vector<int> dani{31,28,31,30,31,30,31,31,30,31,30,31};
          //p1.Ispisi(); p2.Ispisi();
          int suma2=get<0>(p2.DajDatumPregleda().Ocitaj()), suma1=get<0>(p1.DajDatumPregleda().Ocitaj());
          int mj1=get<1>(p1.DajDatumPregleda().Ocitaj()), mj2=get<1>(p2.DajDatumPregleda().Ocitaj());
          int god1=get<2>((p1.DajDatumPregleda().Ocitaj())), god2=get<2>((p2.DajDatumPregleda().Ocitaj()));
          int sat1=p1.DajVrijemePregleda().Ocitaj().first, sat2=p2.DajVrijemePregleda().Ocitaj().first;
          int min1=p1.DajVrijemePregleda().Ocitaj().second, min2=p2.DajVrijemePregleda().Ocitaj().second;
          if(god1<god2) return true;
          else if(god1==god2){
               if(mj1<mj2) return true;
               else if(mj1==mj2){
                    if(suma1<suma2) return true;
                    else if(suma1==suma2){
                         if(sat1<sat2) return true;
                         else if(sat1==sat2){
                              if(min1<min2) return true;
                              return false;
                         }
                         else return false;
                    }
                    else return false;
               }
               else return false;
          }
          else return false;
     }

class Pregledi{
     int stanje,kapacitet;
     Pregled **niz;
public:
     explicit Pregledi(int max_broj_pregleda){
          stanje=0;
          kapacitet=max_broj_pregleda;
          niz=new Pregled*[kapacitet];
     }
     Pregledi(std::initializer_list<Pregled> spisak_pregleda){
          niz=new Pregled*[spisak_pregleda.size()];
          stanje=spisak_pregleda.size();
          int i=0;
          for(auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++)
               niz[i++]=new Pregled(*it);     }
     ~Pregledi(){
          for(int i=0; i<stanje; i++) delete niz[i];
          delete[]niz;
          stanje=0;
     }
     Pregledi(const Pregledi &pregledi){
          kapacitet=pregledi.kapacitet;
          stanje=pregledi.stanje;
          niz=new Pregled*[kapacitet];
          for(int i=0; i<stanje; i++) niz[i]=new Pregled(*pregledi.niz[i]);
     }
     Pregledi(Pregledi &&pregledi){
          kapacitet=pregledi.kapacitet;
          stanje=pregledi.stanje;
          niz=new Pregled*[kapacitet];
          for(int i=0; i<stanje; i++) niz[i]=pregledi.niz[i];
          for(int i=0; i<pregledi.kapacitet; i++) pregledi.niz[i]=nullptr;
          pregledi.niz=nullptr;
          pregledi.kapacitet=0;
          pregledi.stanje=0;
     }
     Pregledi &operator =(const Pregledi &pregledi){
          if(this==&pregledi) return *this;
          for(int i=0; i<kapacitet; i++)
               delete niz[i];
          delete[] niz;
          kapacitet = pregledi.kapacitet;
          stanje = pregledi.stanje;
          niz = new Pregled*[kapacitet];
          for(int i=0; i<stanje; i++)
          niz[i] = new Pregled(*pregledi.niz[i]);
          return *this;
     }
     Pregledi &operator =(Pregledi &&pregledi){
           if(this==&pregledi) return *this;
          for(int i=0; i<kapacitet; i++)
               delete niz[i];
          delete[] niz;

          kapacitet = pregledi.kapacitet;
          stanje = pregledi.stanje;
          niz = new Pregled*[kapacitet];

          for(int i=0; i<stanje; i++)
               niz[i] = pregledi.niz[i];
          for(int i=0; i<kapacitet; i++)
               pregledi.niz[i] = nullptr;
          pregledi.niz = nullptr;

          pregledi.kapacitet = 0;
          pregledi.stanje = 0;

          return *this;
    
     }
     void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
          if(stanje==kapacitet) throw range_error("Dostignut maksimalni broj pregleda");
          niz[stanje++]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
     }
     void RegistrirajPregled(const std::string &ime_pacijenta, const int &dan_pregleda,const int &mjesec_pregleda, const int &godina_pregleda,const int & sati_pregleda,const int & minute_pregleda){
          if(stanje==kapacitet) throw range_error("Dostignut maksimalni broj pregleda");
          niz[stanje++] = new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
      }
     void RegistrirajPregled(Pregled *pregled){
          if(stanje==kapacitet) throw range_error("Dostignut maksimalni broj pregleda");
          niz[stanje++]=pregled;
     }
     int DajBrojPregleda() const { return stanje;}
     int DajBrojPregledaNaDatum(const Datum &datum) const{
          try{
          return count_if(niz, niz+stanje, [datum](Pregled *p){
               auto t1=datum.Ocitaj();
               auto t2=p->DajDatumPregleda().Ocitaj();
               return (get<0>(t1)==get<0>(t2) && get<1>(t1)==get<1>(t2) && get<2>(t1)==get<2>(t2));
          });
          } catch(...) {throw domain_error("Nema registriranih pregleda");}
     }
     Pregled &DajNajranijiPregled(){
          if (stanje==0) throw domain_error("Nema registriranih pregleda");
          return *(*(min_element(niz, niz+stanje, [](Pregled *p1, Pregled *p2){return(DolaziPrije(*p1,*p2));})));
     }
     Pregled DajNajranijiPregled() const{
          if (stanje==0) throw domain_error("Nema registriranih pregleda");
          return *(*(min_element(niz, niz+stanje, [](Pregled *p1, Pregled *p2){return(DolaziPrije(*p1,*p2));})));
     }
     void IsprazniKolekciju(){
          if(stanje==0) throw domain_error("Nema registriranih pregleda");
          for(int i=0; i<stanje; i++) delete niz[i];
          stanje=0; kapacitet=0;
     }
     void ObrisiNajranijiPregled(){
          if(stanje==0) throw range_error("Prazna kolekcija");
          Pregled *pom=niz[0];
          int ind=0;
          for(int i=0; i<stanje; i++)
          {
               if(DolaziPrije(*niz[i],*pom)){pom = niz[i]; ind = i;}
          }
          delete niz[ind];
          for(int i = ind; i<stanje-1; i++)
                    niz[i] = niz[i+1];
           
          stanje--;
          //niz[stanje-1]->Ispisi();
     }
     void ObrisiPregledePacijenta(const std::string &ime_pacijenta){
          
          int br=0;
          for(int i=0; i<stanje; i++)
               if(niz[i]->DajImePacijenta()==ime_pacijenta){
                    br++;
                    delete niz[i]; 
                    for(int j=i; j<stanje-1; j++) niz[j]=niz[j+1];
                    stanje--;
                    i--;
               }
          if(br!=0) cout<<"Uspjesno obrisano "<<br<<" pregleda"<<endl;
     }
     void IspisiPregledeNaDatum(const Datum &datum) const{
          Pregled **pom=new Pregled*[DajBrojPregledaNaDatum(datum)];
          int j=0;
          auto t1=datum.Ocitaj();
          for(int i=0; i<stanje; i++)
          {
               auto t2=niz[i]->DajDatumPregleda().Ocitaj();
                    if(get<0>(t1)==get<0>(t2) && get<1>(t1)==get<1>(t2) && get<2>(t1)==get<2>(t2))
                         {
                              pom[j] = new Pregled(*niz[i]);
                              j++;
                         }
          }

          for(int i=0; i<DajBrojPregledaNaDatum(datum);i++)
               for(int j=i; j<DajBrojPregledaNaDatum(datum);j++)
                   {
                    if(DolaziPrije(*pom[j], *pom[i]))
                     {
                         Pregled* pom1 = pom[i];
                         pom[i] = pom[j];
                         pom[j] = pom1;
                    }
               }

            for(int i=0; i<DajBrojPregledaNaDatum(datum); i++)
                pom[i]->Ispisi();

          for(int i=0; i<DajBrojPregledaNaDatum(datum); i++)
               delete  pom[i];
          delete[] pom;
     }
     void IspisiSvePreglede() const{
          //cout<<endl<<stanje<<endl;
          Pregled **pom = new Pregled*[stanje];
          //niz[0]->Ispisi();
          for(int i=0; i<stanje; i++)
               pom[i] = niz[i];

          for(int i=0; i<stanje; i++)
               for(int j=i; j<stanje; j++)
               {
                  //  pom[j]->Ispisi(); pom[i]->Ispisi();
                    if(DolaziPrije(*pom[j], *pom[i]))
                    {
                         Pregled* pom1 = pom[i];
                         pom[i] = pom[j];
                         pom[j] = pom1;
                    }
               }
          //cout<<endl<<"ASdaDSASDSD"<<endl;
          for(int i=0; i<stanje; i++)
            pom[i]->Ispisi();

          delete[] pom;
     }

};

int main ()
{
     cout<<"Unesite maksimalan broj pregleda: ";
     int n; cin>>n; 
     Pregledi p(n);
     for(int i=0; i<n; i++){
          cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
          string ime; cin>>ime;
          if(ime=="kraj") break;
          cout<<"Unesite dan mjesec i godinu pregleda: ";
          int d,m,g; cin>>d>>m>>g;
          cout<<"Unesite sate i minute pregleda: ";
          int s,min; cin>>s>>min;
          p.RegistrirajPregled(ime,d,m,g,s,min);
     }
     cout<<"Trenutno su registrovani sljedeci pregledi"<<endl;
     p.IspisiSvePreglede();
     try{
     while(1){
          cout<<endl;
          cout<<"Odaberite jednu od sljedecih opcija"<<endl;
          cout<<"1 - Broj pregleda na datum"<<endl;
          cout<<"2 - Najraniji pregled"<<endl;
          cout<<"3 - Obrisi pregled pacijenta"<<endl;
          cout<<"4 - Obrisi najraniji pregled"<<endl;
          cout<<"5 - Ispisi sve pregleda na datum"<<endl;
          cout<<"6 - Ispisi sve preglede"<<endl;
          cout<<"7 - Kraj programa"<<endl;
          cin>>n;
          if(n==1){
               cout<<"Unesite dan mjesec i godinu : "; int d,m,g; cin>>d>>m>>g;
               Datum dat=Datum(d,m,g);
               cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<p.DajBrojPregledaNaDatum(dat)<<endl;
               
          }
          else if(n==2){
               cout<<"Najraniji pregled je: "<<endl;
               p.DajNajranijiPregled().Ispisi();
          }
          else if(n==3){
               string pom;
               cout<<"Unesite ime pacijenta: ";
               cin>>pom;
               p.ObrisiPregledePacijenta(pom);
               
          }
          else if(n==4){
               p.ObrisiNajranijiPregled(); cout<<"Najraniji pregled uspjesno obrisan"<<endl;
          }
          else if(n==5){
               cout<<"Unesite dan mjesec i godinu : ";
               int d,m,g; cin>>d>>m>>g; Datum dat=Datum(d,m,g);
               cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su: "<<endl;
               p.IspisiPregledeNaDatum(dat);
          }
          else if(n==6){
               p.IspisiSvePreglede();
          }
          else if(n==7){
               break;
          }
     }
     } catch(domain_error d) { cout<<d.what();}
     catch(range_error r) { cout<<r.what(); } 
     return 0;
}
