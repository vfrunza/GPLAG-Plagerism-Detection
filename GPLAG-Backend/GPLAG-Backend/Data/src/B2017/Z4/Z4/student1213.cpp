
/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <memory>
#include <initializer_list>

using namespace std;

vector<int> dani{31,28,31,30,31,30,31,31,30,31,30,31};

class Datum{
    int  d,m,g;
public:
    Datum(int dan=1, int mjesec=1, int godina=1){
        if(godina < 1 || dan < 1 || dan > dani[mjesec-1] || mjesec < 1 || mjesec > 12) 
            throw domain_error("Neispravan datum!");
        d=dan; m=mjesec; g=godina;
    }
    void Postavi(int dan, int mjesec, int godina){
        if(godina < 1 || dan < 1 || dan > dani[mjesec-1] || mjesec < 1 || mjesec > 12) 
            throw domain_error("Neispravan datum!");
        d=dan; m=mjesec; g=godina;
    }
    std::tuple<int, int, int> Ocitaj() const{
        tuple<int,int,int> rez(d,m,g);
        return rez;;
    }
    void Ispisi() const{
        cout<<d<<"/"<<m<<"/"<<g<<" ";
    }
};

class Vrijeme{
  int s,m;
public:
    Vrijeme(int sati=0, int minute=0){
        if(sati>23 || sati<0) throw domain_error("Neispravno vrijeme!");
        if( minute>59 || minute<0) throw domain_error("Neispravno vrijeme!");
        s=sati; m=minute;
    }
    void Postavi(int sati, int minute){
        if(sati>23 || sati<0) throw domain_error("Neispravno vrijeme!");
        if( minute>59 || minute<0) throw domain_error("Neispravno vrijeme!");
        s=sati; m=minute;
    }
    std::pair<int, int> Ocitaj () const{
        pair<int,int> p(s,m);
        return p;
    }
    void Ispisi() const{
        cout <<setw(2)<<right<<setfill('0')<<s;
        cout<<":"<<setfill('0') <<setw(2)<<m;
    }
 
};

class Pregled{
  string s; Datum d; Vrijeme v;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
     const Vrijeme &vrijeme_pregleda){
         s=ime_pacijenta;
         d=datum_pregleda;
         v=vrijeme_pregleda;
     }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
     int godina_pregleda, int sati_pregleda, int minute_pregleda){
         s=ime_pacijenta;
         d=Datum(dan_pregleda,mjesec_pregleda,godina_pregleda);
         v=Vrijeme(sati_pregleda,minute_pregleda);
         //d=datum_pregleda;
         //v=vrijeme_pregleda;
     }
    void PromijeniPacijenta(const std::string &ime_pacijenta){
        s=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum){
        d=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
        v=novo_vrijeme;
    }
    void PomjeriDanUnaprijed(){
        
        
    }
    void PomjeriDanUnazad(){
        
    }
    std::string DajImePacijenta() const { return s;}
    Datum DajDatumPregleda() const { return d;}
    Vrijeme DajVrijemePregleda() const { return v;}
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
        Datum dat1=p1.d;
        Datum dat2=p2.d;
        Vrijeme vr1=p1.v;
        Vrijeme vr2=p2.v;
        if(get<2>(dat1.Ocitaj())>get<2>(dat2.Ocitaj()) && get<1>(dat1.Ocitaj())>get<1>(dat2.Ocitaj()) && get<0>(dat1.Ocitaj())>get<0>(dat2.Ocitaj()) && vr1.Ocitaj().first>vr2.Ocitaj().first && vr1.Ocitaj().second>vr2.Ocitaj().second) return false;
        return true;
    }
    void Ispisi() const{
        cout<<setw(30)<<left<<setfill(' ')<<s;
        d.Ispisi();
        v.Ispisi();
        cout<<endl;

    }

};

bool DolaziPrije(const Pregled &p1, const Pregled &p2){
        Datum dat1=p1.DajDatumPregleda();
        Datum dat2=p2.DajDatumPregleda();
        Vrijeme vr1=p1.DajVrijemePregleda();
        Vrijeme vr2=p2.DajVrijemePregleda();
        if(get<2>(dat1.Ocitaj())>get<2>(dat2.Ocitaj())) return false;
        if(get<2>(dat1.Ocitaj())==get<2>(dat2.Ocitaj())&& get<1>(dat1.Ocitaj())>get<1>(dat2.Ocitaj())) return false;
        if(get<2>(dat1.Ocitaj())==get<2>(dat2.Ocitaj()) && get<1>(dat1.Ocitaj())==get<1>(dat2.Ocitaj()) && get<0>(dat1.Ocitaj())>get<0>(dat2.Ocitaj()))return false;
        if(get<2>(dat1.Ocitaj())==get<2>(dat2.Ocitaj()) && get<1>(dat1.Ocitaj())==get<1>(dat2.Ocitaj()) && get<0>(dat1.Ocitaj())==get<0>(dat2.Ocitaj()) && vr1.Ocitaj().first>vr2.Ocitaj().first) return false;
        if(get<2>(dat1.Ocitaj())==get<2>(dat2.Ocitaj()) && get<1>(dat1.Ocitaj())==get<1>(dat2.Ocitaj()) && get<0>(dat1.Ocitaj())==get<0>(dat2.Ocitaj()) && vr1.Ocitaj().first==vr2.Ocitaj().first)
            {
                if(vr1.Ocitaj().second>vr2.Ocitaj().second)
                return false;
            }
        return true;
    }

class Pregledi{

vector<shared_ptr<Pregled>> lista;
public:
    explicit Pregledi(){
        
    }
    Pregledi(std::initializer_list<Pregled> spisak_pregleda){
        lista.resize(spisak_pregleda.size());
      
        int br=0;
        for(auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++){
            lista[br]=make_shared<Pregled>(*it);
            br++;
        }
    }
    ~Pregledi(){
        for(int i=0; i<lista.size(); i++) 
           lista[i]=nullptr;
    }
    Pregledi &operator =(const Pregledi &pregledi){
        if(this==&pregledi) return *this;
          for(int i=0; i<lista.size(); i++)
               lista[i]=nullptr;
            lista.resize(pregledi.lista.size());
          for(int i=0; i<lista.size(); i++)
          lista[i] = make_shared<Pregled>(*pregledi.lista[i]);
          return *this;

    }
    Pregledi &operator =(Pregledi &&pregledi){
        if(this==&pregledi) return *this;
          for(int i=0; i<lista.size(); i++)
              lista[i]=nullptr;
            lista.resize(pregledi.lista.size());

          for(int i=0; i<lista.size(); i++)
               lista[i] = pregledi.lista[i];
          for(int i=0; i<pregledi.lista.size(); i++)
               pregledi.lista[i] = nullptr;
          return *this;

    }
    Pregledi(const Pregledi &pregledi){
        
        lista.resize(pregledi.lista.size());
        for(int i=0; i<lista.size(); i++) lista[i]=make_shared<Pregled>(*pregledi.lista[i]);
    }
    void RegistrirajPregled(const std::string &ime_pacijenta,
     const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
          lista.push_back(make_shared<Pregled>(ime_pacijenta,datum_pregleda,vrijeme_pregleda));

     }
    Pregledi(Pregledi &&pregledi){
        lista.resize(pregledi.lista.size());
        for(int i=0; i<lista.size(); i++) lista[i]=pregledi.lista[i];
        for(int i=0; i<pregledi.lista.size(); i++) pregledi.lista[i]=nullptr;
        

    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
     int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
     int minute_pregleda){
    
          lista.push_back(make_shared<Pregled>(ime_pacijenta,dan_pregleda,mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda));

     }
    void RegistrirajPregled(shared_ptr<Pregled>pregled){
          lista.push_back(pregled);

    }
    
    int DajBrojPregledaNaDatum(const Datum &datum) const{
        try{
          return count_if(lista.begin(), lista.end(), [datum](shared_ptr<Pregled>p){
               auto t1=datum.Ocitaj();
               auto t2=p->DajDatumPregleda().Ocitaj();
               return (get<0>(t1)==get<0>(t2) && get<1>(t1)==get<1>(t2) && get<2>(t1)==get<2>(t2));
          });
          } catch(...) {throw domain_error("Nema registriranih pregleda");}

    }
    Pregled &DajNajranijiPregled(){
        if (lista.size()==0) throw domain_error("Nema registriranih pregleda");
          return *(*(min_element(lista.begin(), lista.end(), [](shared_ptr<Pregled>p1, shared_ptr<Pregled>p2){return(DolaziPrije(*p1,*p2));})));

    }
    int DajBrojPregleda() const { return lista.size();}
    Pregled DajNajranijiPregled() const{
        if (lista.size()==0) throw domain_error("Nema registriranih pregleda");
          return *(*(min_element(lista.begin(), lista.end(), [](shared_ptr<Pregled>p1, shared_ptr<Pregled>p2){return(DolaziPrije(*p1,*p2));})));

    }
    
    void ObrisiNajranijiPregled(){
        auto p=DajNajranijiPregled();
        Datum d=p.DajDatumPregleda();
        Vrijeme v=p.DajVrijemePregleda();
        for(int i=0; i<lista.size(); i++){
            Datum d1=lista[i]->DajDatumPregleda();
            Vrijeme v1=lista[i]->DajVrijemePregleda();
            if(p.DajImePacijenta()==lista[i]->DajImePacijenta())
            if(get<2>(d.Ocitaj())==get<2>(d1.Ocitaj()) && get<1>(d.Ocitaj())==get<1>(d1.Ocitaj()) && get<0>(d.Ocitaj())==get<0>(d1.Ocitaj()) && v.Ocitaj().first==v1.Ocitaj().first && v.Ocitaj().second==v1.Ocitaj().second) 
            {
                lista[i]=nullptr;
                for(int j=i; j<lista.size()-1; j++) lista[j]=lista[j+1];
                lista.resize(lista.size()-1);
                break;
            }
            
        }
    }
    void IsprazniKolekciju(){
        if(lista.size()==0) throw domain_error("Nema registriranih pregleda");
          for(int i=0; i<lista.size(); i++) lista[i]=nullptr;


    }
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta){
        int br=0;
          for(int i=0; i<lista.size(); i++)
               if(lista[i]->DajImePacijenta()==ime_pacijenta){
                    br++;
                    lista[i]=nullptr;
                    for(int j=i; j<lista.size()-1; j++) lista[j]=lista[j+1];
                    lista.resize(lista.size()-1);
                    i--;
               }
          if(br!=0) cout<<"Uspjesno obrisano "<<br<<" pregleda";
          cout<<endl;

    }
    void IspisiPregledeNaDatum(const Datum &datum) const{
        vector<shared_ptr<Pregled>>drugi;
          
          auto t1=datum.Ocitaj();
          for(int i=0; i<lista.size(); i++)
          {
               auto t2=lista[i]->DajDatumPregleda().Ocitaj();
                if(get<0>(t1)==get<0>(t2) && get<1>(t1)==get<1>(t2) && get<2>(t1)==get<2>(t2))
                 {
                    drugi.push_back(make_shared<Pregled>(*lista[i]));
                    
                 }
          }
          for(int i=0; i<DajBrojPregledaNaDatum(datum);i++)
               for(int j=i; j<DajBrojPregledaNaDatum(datum);j++)
                   {
                    if(!DolaziPrije( *drugi[i],*drugi[j]))
                     {
                         auto pom1 = drugi[i];
                         drugi[i] = drugi[j];
                         drugi[j] = pom1;
                    }
               }

            for(int i=0; i<DajBrojPregledaNaDatum(datum); i++)
                drugi[i]->Ispisi();

          for(int i=0; i<DajBrojPregledaNaDatum(datum); i++)
              drugi[i]=nullptr;

    }
    void IspisiSvePreglede() const{
          vector<shared_ptr<Pregled>>drugi; drugi.resize(lista.size());
          for(int i=0; i<lista.size(); i++) drugi[i]=lista[i];
          for(int i=0; i<lista.size(); i++)
               for(int j=i; j<lista.size(); j++)
               {
                    if(!DolaziPrije(*drugi[i],*drugi[j]))
                    {
                         auto pom1 = drugi[i];
                         drugi[i] = drugi[j];
                         drugi[j] = pom1;
                    }
               }
          for(int i=0; i<lista.size(); i++)
            drugi[i]->Ispisi();

       for(int i=0; i<lista.size(); i++) drugi[i]=nullptr;

    }

    
};

void petlja(Pregledi &p){
    int n;
    try{
     for(;;){
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
          switch(n) {
          case 1: {
               cout<<"Unesite dan mjesec i godinu : "; int d,m,g; cin>>d>>m>>g;
               Datum dat=Datum(d,m,g);
               cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<p.DajBrojPregledaNaDatum(dat)<<endl;
               break;
          }
          case 2:{
               cout<<"Najraniji pregled je: "<<endl;
               p.DajNajranijiPregled().Ispisi(); break;
          }
          case 3: {
               string drugi;
               cout<<"Unesite ime pacijenta: ";
               cin>>drugi;
               p.ObrisiPregledePacijenta(drugi);
               break;
          }
          case 4:
               p.ObrisiNajranijiPregled(); cout<<"Najraniji pregled uspjesno obrisan"<<endl; break;
    
          case 5: {
               cout<<"Unesite dan mjesec i godinu : ";
               int d,m,g; cin>>d>>m>>g; Datum dat=Datum(d,m,g);
               cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su: "<<endl;
               p.IspisiPregledeNaDatum(dat); break;
          }
          case 6: {
               p.IspisiSvePreglede(); break;
          }
          case 7: {
               return;
          }
          }
     }
     } catch(domain_error d) { throw d;}
     catch(range_error r) { throw r; } 
}

void pac(Pregledi &p){
    for(;;){
          cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
          string s; 
          cin>>s;
          if(s=="kraj") break;
          cout<<"Unesite dan mjesec i godinu pregleda: ";
          int d,m,god; 
          cin>>d>>m>>god;
          cout<<"Unesite sate i minute pregleda: ";
          int sek,min; 
          cin>>sek>>min;
          p.RegistrirajPregled(s,d,m,god,sek,min);
          //cout<<"ADSdADSD"<<endl;
     }
}

int main ()
{
 
     Pregledi p;
     pac(p);
     cout<<"Trenutno su registrovani sljedeci pregledi"<<endl;
     p.IspisiSvePreglede();
     try{
         petlja(p);
     }catch(domain_error d) { cout<<d.what();}
     catch(range_error r) { cout<<r.what(); } 
  

	return 0;
}
