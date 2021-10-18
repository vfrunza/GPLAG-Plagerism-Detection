/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <vector>

class Datum
{
    int dan, mjesec, godina;
public:
    Datum(int d, int m, int g){ Postavi(d,m,g); }
    void Postavi(int d, int m, int g);
    std::tuple<int,int,int> Ocitaj() const;
    void Ispisi() const{ std::cout << dan << "/" << mjesec << "/" << godina; }
};
class Vrijeme
{
    int sati, minute;
public:
    Vrijeme(int s, int m){ Postavi(s,m); }
    void Postavi(int s, int m);
    std::pair<int,int> Ocitaj() const;
    void Ispisi() const{ 
        if(sati<10) std::cout << "0"; std::cout << sati; std::cout << ":";
        if(minute<10) std::cout << "0"; std::cout << minute; }
};

void Datum::Postavi(int d, int m, int g){
    int br_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && g%100!=0 && g%400==0) br_dana[1]++;
    if(g<1 || d<1 || m<1 || m>12 || d>br_dana[m-1]) throw std::domain_error("Neispravan datum");
    dan=d; mjesec=m; godina=g;
}
std::tuple<int,int,int> Datum::Ocitaj() const{
    std::tuple<int, int, int> t(dan, mjesec, godina);
    return t;
}

void Vrijeme::Postavi(int s, int m){
    if(s<0 || s>23 || m<0 || m>59) throw std::domain_error("Neispravno vrijeme");
    sati=s; minute=m;
}
std::pair<int,int> Vrijeme::Ocitaj() const{
    std::pair<int,int> par(sati,minute);
    return par;
}
class Pregled{
    std::string ime_pacijenta;
    Datum dat_pregleda;
    Vrijeme v_pregleda;
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): 
        ime_pacijenta(ime_pacijenta), dat_pregleda(datum_pregleda), v_pregleda(vrijeme_pregleda){}
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):
        ime_pacijenta(ime_pacijenta), dat_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda), v_pregleda(sati_pregleda, minute_pregleda){}
    
    void PromijeniPacijenta(const std::string &ime_pacijenta){
        this->ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum);
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const { return ime_pacijenta; }
    Datum DajDatumPregleda() const { return dat_pregleda; }
    Vrijeme DajVrijemePregleda() const { return v_pregleda; }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const { std::cout << std::left << std::setw(30) << ime_pacijenta; 
    dat_pregleda.Datum::Ispisi(); std::cout <<" "; v_pregleda.Vrijeme::Ispisi(); std::cout << std::endl;
    }
};

void Pregled::PromijeniDatum(const Datum &novi_datum){
      std::tuple<int,int,int> dat;
      dat=novi_datum.Datum::Ocitaj();
      int d,m,g; std::tie(d,m,g)=dat;
      dat_pregleda.Datum::Postavi(d,m,g);
}
void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme){
    std::pair<int, int> v;
    v=novo_vrijeme.Vrijeme::Ocitaj();
    v_pregleda.Postavi(v.first, v.second);
}
void Pregled::PomjeriDanUnaprijed(){
    int br_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    std::tuple<int,int,int> dat;
    dat=dat_pregleda.Datum::Ocitaj();
    int d,m,g; std::tie(d,m,g)=dat;
    if(g%4==0 && g%100!=0 && g%400==0) br_dana[1]++;
    d++; if(d>br_dana[m-1]) d=1, m++;
    if(m>12) m=1, g++;
    dat_pregleda.Datum::Postavi(d,m,g);
}
void Pregled::PomjeriDanUnazad(){
    int br_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    std::tuple<int,int,int> dat;
    dat=dat_pregleda.Datum::Ocitaj();
    int d,m,g; std::tie(d,m,g)=dat;
    if(g%4==0 && g%100!=0 && g%400==0) br_dana[1]++;
    d--; if(d<1) d=br_dana[m-2], m--;
    if(m>12) m=1, g++;
    if(m<1) m=12, g--;
    dat_pregleda.Datum::Postavi(d,m,g);
}
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2){
    std::tuple<int,int,int> dat; dat=p1.dat_pregleda.Datum::Ocitaj(); int dan1,mj1,god1; std::tie(dan1,mj1,god1)=dat;
    std::pair<int, int> v;  v=p1.v_pregleda.Vrijeme::Ocitaj(); int sat1(v.first), min1(v.second);
    dat=p2.dat_pregleda.Datum::Ocitaj(); int dan2,mj2,god2; std::tie(dan2,mj2,god2)=dat;
    v=p2.v_pregleda.Vrijeme::Ocitaj(); int sat2(v.first), min2(v.second);
    if(god1==god2){
        if(mj1==mj2){
            if(dan1==dan2){
                if(sat1==sat2) return min1<min2;
                return sat1<sat2;
            }
            return dan1<dan2;
        }
        return mj1<mj2;
    }
    return god1<god2;
}

class Pregledi{
  int kapacitet;
  int registrovano;
  Pregled **elementi;
  public: 
  explicit Pregledi(int max_broj_pregleda): kapacitet(max_broj_pregleda), registrovano(0), elementi(new Pregled*[max_broj_pregleda]{}){}
  Pregledi(std::initializer_list<Pregled> spisak_pregleda);
  ~Pregledi(){ for(int i=0;i<registrovano;i++) delete elementi[i]; delete[] elementi; }
  Pregledi (const Pregledi &pregledi);
  Pregledi (Pregledi &&pregledi);
  Pregledi &operator= (const Pregledi &pregledi);
  Pregledi &operator= (Pregledi &&pregledi);
  void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
  void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
  void RegistrirajPregled(Pregled *pregled);
  int DajBrojPregleda() const{return registrovano;};
  int DajBrojPregledaNaDatum(const Datum &datum) const;
  Pregled &DajNajranijiPregled();
  Pregled DajNajranijiPregled() const;
  void IsprazniKolekciju();
  void ObrisiNajranijiPregled();
  void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
  void IspisiPregledeNaDatum(const Datum &datum) const;
  void IspisiSvePreglede() const;
};
  Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda): 
  kapacitet(spisak_pregleda.size()), registrovano(spisak_pregleda.size()), elementi(new Pregled*[spisak_pregleda.size()]{}){
      auto it(spisak_pregleda.begin());
    try{ 
         for(int i=0;i<spisak_pregleda.size();i++){
          elementi[i]=new Pregled(*it);
          it++;
      }
    }catch(...){
        for(int i=0;i<spisak_pregleda.size();i++) delete elementi[i];
        delete[] elementi; throw;
    }
  }

  Pregledi::Pregledi (const Pregledi &pregledi): 
  kapacitet(pregledi.kapacitet), registrovano(pregledi.registrovano), elementi(new Pregled*[pregledi.kapacitet]{}){
    try{
        for(int i=0;i<registrovano;i++) elementi[i]=new Pregled(*pregledi.elementi[i]);
    } catch(...){
        for(int i=0;i<registrovano;i++) delete elementi[i]; 
        delete[] elementi; throw;
    }
  }
 
  Pregledi::Pregledi (Pregledi &&pregledi): 
  kapacitet(pregledi.kapacitet), registrovano(pregledi.registrovano), elementi(pregledi.elementi){
      pregledi.elementi=nullptr; pregledi.registrovano=0;
  }
  
  Pregledi &Pregledi::operator= (const Pregledi &pregledi){
      if(&pregledi==this) return *this;
     // if(kapacitet!=pregledi.kapacitet){
          Pregled **novi_prostor(nullptr);
          try{
              novi_prostor=new Pregled*[pregledi.kapacitet]{};
              for(int i(0);i<pregledi.registrovano;i++) novi_prostor[i]=new Pregled(*pregledi.elementi[i]);
              for(int i(0);i<registrovano;i++) delete elementi[i]; delete[] elementi;
                elementi=novi_prostor;
                kapacitet=pregledi.kapacitet;
              }catch(...){
                  for(int i(0);i<pregledi.registrovano;i++) delete novi_prostor[i]; delete[] novi_prostor;
                    throw;
              }
        /*}
          else{
              std::copy(pregledi.elementi, pregledi.elementi+registrovano, elementi);
          }*/
          registrovano=pregledi.registrovano;
          return *this;
  }
  
  Pregledi &Pregledi::operator= (Pregledi &&pregledi){
      if(&pregledi==this) return *this;
      std::swap(kapacitet, pregledi.kapacitet);
      std::swap(registrovano, pregledi.registrovano);
      std::swap(elementi, pregledi.elementi);
      return *this;
  }
  
  void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        if(registrovano>=kapacitet) throw std::range_error("Dostignut maksimalni broj pregleda");
        Pregled* novi(nullptr);
        try{
        novi=new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
        elementi[registrovano++]=novi;
        }catch(...){ delete novi; throw;}
    }
    
  void Pregledi::RegistrirajPregled
  (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
      if(registrovano>=kapacitet) throw std::range_error("Dostignut maksimalni broj pregleda");
      Pregled* novi(nullptr);
     try{
      novi=new Pregled(ime_pacijenta, dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
      elementi[registrovano++]=novi;
     }catch(...){delete novi; throw;}
  }
  
  void Pregledi::RegistrirajPregled(Pregled *pregled){
      if(registrovano>=kapacitet) throw std::range_error("Dostignut maksimalni broj pregleda");
        elementi[registrovano++]=pregled;
  }
  
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const{
        int br;
        std::tuple<int,int,int> datum2(datum.Ocitaj());
        int d2, m2, g2;
        std::tie(d2,m2,g2)=datum2;
        br=std::count_if(elementi, elementi+registrovano, [d2,m2,g2](Pregled* p){
            std::tuple <int,int,int> datum1((p->DajDatumPregleda()).Ocitaj());
         int d1, m1, g1;
         std::tie(d1,m1,g1)=datum1;
         return (d1==d2 && m1==m2 && g1==g2);});
        return br;
    }
    
  Pregled &Pregledi::DajNajranijiPregled(){
   Pregled **najmanji=std::min_element(elementi, elementi+registrovano,[](Pregled* p1, Pregled* p2){
       return Pregled::DolaziPrije(*p1,*p2); });
    return **najmanji;
  }
  
  Pregled Pregledi::DajNajranijiPregled() const{
      if(registrovano==0) throw std::range_error("Nema registriranih pregleda");
    Pregled **najmanji=std::min_element(elementi, elementi+registrovano,[](Pregled* p1, Pregled* p2){
       return Pregled::DolaziPrije(*p1,*p2); });
    return **najmanji;
  }
  
  void Pregledi::IsprazniKolekciju(){
      for(int i(0); i<registrovano; i++){
          delete elementi[i];
          elementi[i]=nullptr;
      }
  }
  
 void Pregledi::ObrisiNajranijiPregled(){
     Pregled **najmanji=std::min_element(elementi, elementi+registrovano,[](Pregled* p1, Pregled* p2){
       return Pregled::DolaziPrije(*p1,*p2); });
       Pregled* pok_na_min(*najmanji);
       for(int i(0);i<registrovano;i++){
           if(elementi[i]==pok_na_min){
              delete pok_na_min; pok_na_min=nullptr;
              for(int j=i;j<registrovano-1;j++){
                 elementi[j]=elementi[j+1];
              }
          elementi[registrovano-1]=nullptr;
       registrovano--;}}
       
 }
 
  void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta){
          for(int i(0); i<registrovano; i++){
              if(elementi[i]->DajImePacijenta()==ime_pacijenta){
              delete elementi[i]; elementi[i]=nullptr;
            for(int k(i);k<registrovano-1;k++)   elementi[k]=elementi[k+1];
          elementi[registrovano-1]=nullptr;
                registrovano--;
                i--;
              }
          }
  }
  void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
      std::vector<Pregled*> v(registrovano, nullptr);
      for(int i(0);i<registrovano;i++) v[i]=elementi[i];
      std::sort(v.begin(), v.end(), [](Pregled* p1, Pregled* p2){return Pregled::DolaziPrije(*p1,*p2);});
      std::tuple<int,int,int> datum2(datum.Ocitaj());
      for(int i(0);i<registrovano;i++){
           std::tuple <int,int,int> datum1((v[i]->DajDatumPregleda()).Ocitaj());
         if (datum1==datum2) v[i]->Pregled::Ispisi();
      }
  }
  void Pregledi::IspisiSvePreglede() const{
      std::vector<Pregled*> v(registrovano, nullptr);
      for(int i(0);i<registrovano;i++) v[i]=elementi[i];
      std::sort(v.begin(), v.end(), [](Pregled* p1, Pregled* p2){return Pregled::DolaziPrije(*p1,*p2);});
      for(int i(0);i<registrovano;i++) v[i]->Pregled::Ispisi();
  }
int main ()
{
    std::cout << "Unesite maksimalan broj pregleda: ";
    int max(0);
    std::cin >> max;
        Pregledi pregledi(max);
        for(int i(0);i<max;i++){
            std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::string ime;
            std::cin >> ime;
            if(ime=="kraj")     break;
            std::cout << "Unesite dan mjesec i godinu pregleda: " ;
            int d,m,g;
            std::cin >> d >> m >> g;
            std::cout << "Unesite sate i minute pregleda: ";
            int h, min;
            std::cin >> h >> min;
            pregledi.RegistrirajPregled(ime,d,m,g,h,min);
           
        }
    
    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
    pregledi.IspisiSvePreglede();
    
    for(;;){
        std::cout << std::endl;
        std::cout << "Odaberite jednu od sljedecih opcija" << std::endl;
        std::cout << "1 - Broj pregleda na datum" << std::endl;
        std::cout << "2 - Najraniji pregled" << std::endl;
        std::cout << "3 - Obrisi pregled pacijenta" << std::endl;
        std::cout << "4 - Obrisi najraniji pregled" << std::endl;
        std::cout << "5 - Ispisi sve pregleda na datum" << std::endl;
        std::cout << "6 - Ispisi sve preglede"<< std::endl;
        std::cout << "7 - Kraj programa" << std::endl;
            int izbor(0);
            std::cin >> izbor;
            if(izbor==7) break;
            if(izbor==1){
                std::cout << "Unesite dan mjesec i godinu : " ;
                int d,m,g; std::cin >> d >> m >>g;
                Datum trazeni(d,m,g);
                std::cout << "Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: ";
                int broj(pregledi.DajBrojPregledaNaDatum(trazeni));
                std::cout << broj;
            }
            if(izbor==2){
                std::cout << "Najraniji pregled je:" << std::endl;
                Pregled najraniji(pregledi.DajNajranijiPregled());
                najraniji.Pregled::Ispisi();
            }
            if(izbor==3){
                std::cout << "Unesite ime pacijenta: " ;
                std::string ime;
                std::cin >> ime;
                int br(pregledi.DajBrojPregleda());
                pregledi.ObrisiPregledePacijenta(ime);
                br-=pregledi.DajBrojPregleda();
                std::cout << "Uspjesno obrisano "<<br<<" pregleda" << std::endl;
            }
            if(izbor==4){
                pregledi.ObrisiNajranijiPregled();
                std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
            }
            if(izbor==5){
              std::cout << "Unesite dan mjesec i godinu : " ;
                int d,m,g; std::cin >> d >> m >>g;
                Datum trazeni(d,m,g);
                std::cout << "Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su:" << std::endl;
                pregledi.IspisiPregledeNaDatum(trazeni);
            }
            if(izbor==6){
                pregledi.IspisiSvePreglede();
            }
    }
    return 0;
}
