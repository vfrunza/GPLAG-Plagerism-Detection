/B2017/2018: Zadaća 4, Zadatak 4

#include <iostream>
#include <stdexcept>
#include <tuple>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <memory>

class Datum {
    int dan,mjesec,godina;
    
    
    void provjeri(int dan, int mjesec, int godina) {
        if(godina<0)throw std::domain_error("Neispravan datum");
      if( (godina%4==0 && godina%100!=0) || godina%400==0  ) 
      if(mjesec==2 && dan>29)throw std::domain_error("Neispravan datum");
      
      if(mjesec<0||mjesec>12) throw std::domain_error("Neispravan datum");
      if(mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11){
      if(dan<0 || dan>30)throw std::domain_error("Neispravan datum");
      } else {
          if(dan<0 || dan>31)throw std::domain_error("Neispravan datum");
      }
   
    }
    
    public:
   
    
  Datum(int dan, int mjesec, int godina) {

     provjeri(dan, mjesec,godina);
     Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
  }
  void Postavi(int dan, int mjesec, int godina) {
      provjeri(dan,mjesec,godina);
      Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
  }
  std::tuple<int,int,int> Ocitaj()const{
      return std::make_tuple(dan,mjesec,godina);
  }
  void Ispisi()const {
      std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
  }

};      
          
    class Vrijeme {
        int sati, minute;
        void provjeri(int sati, int minute) {
            
            if(sati<0 || sati>24||minute<0||minute>59)throw std::domain_error("Neispravno vrijeme"); 
        }
        public:
       
              Vrijeme(int sati, int minute ){
                  provjeri(sati,minute);
                  Vrijeme::sati=sati; Vrijeme::minute=minute; 
              }
              void Postavi(int sati, int minute){
                  provjeri(sati,minute);
                  Vrijeme::sati=sati; Vrijeme::minute=minute;
              }
              std::pair<int,int> Ocitaj () const {
                  return std::make_pair(sati,minute);
              }
              void Ispisi() const {
                  if(sati<10)std::cout<<"0"; std::cout<<sati<<":"; if(minute<10)std::cout<<0;std::cout<<minute;
              }
              
          };
          
   class Pregled
{

    friend class Datum;
    friend class Vrijeme;
    std::string ime_pacijenta;
    Datum datum;
    Vrijeme vrijeme;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):datum(datum_pregleda),vrijeme(vrijeme_pregleda) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }

    Pregled(const std::string &ime_pacijenta,  int dan_pregleda,  int mjesec_pregleda, int godina_pregleda, int
            sat_pregleda, int minute_pregleda):datum(dan_pregleda,mjesec_pregleda,godina_pregleda),vrijeme(sat_pregleda,minute_pregleda) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        Pregled::datum=novi_datum;

    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        Pregled::vrijeme=novo_vrijeme;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();

    std::string DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda()const {
        return datum;
    }
    Vrijeme DajVrijemePregleda()const {
        return vrijeme;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);

    void Ispisi() {
        std::cout<<std::left<<std::setw(30)<<ime_pacijenta;
        datum.Ispisi();
        std::cout<<" ";
        vrijeme.Ispisi();
        std::cout<<std::endl;
    }

};

void Pregled::PomjeriDanUnaprijed()
{
    int a,b,c;
    std::tie(a,b,c)=datum.Ocitaj();
    if(a==28 && b==2) {
        if ( (c%4==0 && c%100!=0) || (c%400==0  ) )
            a=29;
        else {
            b++;
            a=1;
        }
    }

    if(a==30 && (b==1 || b==3 || b==5 || b==7 ||b==8 ||b==10 || b==12) )
        a=31;

    else if(a==30) {
        a=1;
        b++;
    }

    else if(a==31 && b==12) {
        a=1;
        b=1;
        c++;
    } else a++;
    datum.Postavi(a,b,c);
}

void Pregled::PomjeriDanUnazad()
{
    int a,b,c;
    std::tie(a,b,c)=datum.Ocitaj();
    if(a==1 && b==3) {
        if( (c%4==0 && c%100!=0) || (c%400==0)  )
            b=2;
        a=29;
    }
    if(a==1 && (b==2 || b==4 || b==6 || b==8 || b==9 || b==11 || b==1)   ) {
        a=31;
        if(b==1) {
            b=12;
            c--;
        }
    } else if(a==1 && ( b==5 || b==7 || b==10 || b==12) ) {
        a=30;
        b--;
    } else a--;
    datum.Postavi(a,b,c);
}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2)
{
    auto  t1= p1.DajDatumPregleda().Ocitaj();
    auto t2=p2.DajDatumPregleda().Ocitaj();
    if (std::get<2>(t1)<std::get<2>(t2))
        return true;
    if(std::get<2>(t1)>std::get<2>(t2))
        return false;
    if(std::get<1>(t1)<std::get<1>(t2))return true;
    if(std::get<1>(t1)>std::get<1>(t2))return false;
    if(std::get<0>(t1)<std::get<0>(t2))return true;
    if(std::get<0>(t1)>std::get<0>(t2))return false;

    auto p1_vrijeme=p1.vrijeme.Ocitaj();
    auto p2_vrijeme=p2.vrijeme.Ocitaj();


    if(p1_vrijeme.first<p2_vrijeme.first) return true;
    if(std::get<0>(p1_vrijeme)>std::get<0>(p2_vrijeme))return false;
    if(std::get<1>(p1_vrijeme)<std::get<1>(p2_vrijeme))return true;
    if(std::get<1>(p1_vrijeme)>std::get<1>(p2_vrijeme))return false;

    return false;
}

    
    class Pregledi {
     std::vector<std::shared_ptr<Pregled>>vektor_pregleda;
      public:
      explicit Pregledi() {}
      
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    Pregledi (const Pregledi &pregledi);
    Pregledi(Pregledi && pregledi):vektor_pregleda(std::move(pregledi.vektor_pregleda)) {}
    Pregledi &operator=(const Pregledi &p);
    Pregledi &operator=(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda);
    
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled) {
       vektor_pregleda.push_back(pregled);
    }
    
    int DajBrojPregledaNaDatum(const Datum& datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
     
    void IsprazniKolekciju() {
        if (vektor_pregleda.size()==0)throw std::range_error("Prazna kolekcija");
        vektor_pregleda.clear();
    }
    
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;  
    void IspisiSvePreglede() const;
    
    int DajBrojPregleda()const {
         return vektor_pregleda.size();
     }   
        
    };
          
         Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) {
           auto it=spisak_pregleda.begin();
            for(int i=0;i<spisak_pregleda.size();i++) {
               vektor_pregleda.push_back(std::make_shared<Pregled>(*it));
            }
        }
        
    Pregledi::Pregledi (const Pregledi &pregledi) {
       
      for(int i=0;i<pregledi.vektor_pregleda.size();i++) {
          vektor_pregleda.push_back(std::make_shared<Pregled>(*pregledi.vektor_pregleda[i]));
      }
        
    }  
          
     Pregledi& Pregledi::operator=(const Pregledi &p){
        vektor_pregleda.resize(p.vektor_pregleda.size());
        for(int i=0;i<p.vektor_pregleda.size();i++)
        vektor_pregleda[i]=std::make_shared<Pregled>(*p.vektor_pregleda[i]);
        return *this;
    }
    
    Pregledi& Pregledi::operator=(Pregledi &&pregledi) {
        vektor_pregleda=std::move(pregledi.vektor_pregleda);
        return *this;
    }
    
    void Pregledi::RegistrirajPregled(const std::string ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        try {
            vektor_pregleda.push_back(std::make_shared<Pregled>( Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda)) );
        }
        catch(...){
            throw ;
        }
    }
    
    void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
    int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
     int minute_pregleda) {
        
         try { vektor_pregleda.push_back(std::make_shared<Pregled>(Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda))) ;}
         catch(...){
             throw ;
         }
         
     }
     
     
    int Pregledi::DajBrojPregledaNaDatum(const Datum& datum) const {
      return  std::count_if(vektor_pregleda.begin(),vektor_pregleda.end(), [&datum]  (std::shared_ptr<Pregled> novi_pok) {
       
             if(novi_pok->DajDatumPregleda().Ocitaj()==datum.Ocitaj() )return true;
          return false;
      }     );
        
    }
    
    Pregled& Pregledi::DajNajranijiPregled() {
        if(vektor_pregleda.size()==0)throw std::domain_error("Nema registriranih pregleda");
        
        auto it=std::min_element(vektor_pregleda.begin(),vektor_pregleda.end(),[] (std::shared_ptr<Pregled> pregled1,std::shared_ptr<Pregled> pregled2) {
            auto tuple1=pregled1->DajDatumPregleda().Ocitaj();
            auto tuple2=pregled2->DajDatumPregleda().Ocitaj();
            
            if(std::get<2>(tuple1)<std::get<2>(tuple2) )return true;
            else if(std::get<2>(tuple1)>std::get<2>(tuple2))return false;
            else {
                if(std::get<1>(tuple1)<std::get<1>(tuple2))return true;
                else if(std::get<1>(tuple1)>std::get<1>(tuple2))return false;
                else {
                    if(std::get<0>(tuple1)<std::get<0>(tuple2))return true;
                else if(std::get<0>(tuple1)>std::get<0>(tuple2))return false;
                    else {
                        auto vrijeme1=pregled1->DajVrijemePregleda().Ocitaj();
                        auto vrijeme2=pregled2->DajVrijemePregleda().Ocitaj();
                        if(std::get<0>(vrijeme1)<std::get<0>(vrijeme2))return true;
                        else if(std::get<0>(vrijeme1)>std::get<0>(vrijeme2))return false;
                        else {
                            if(std::get<1>(vrijeme1)<std::get<1>(vrijeme2))return true;
                            else if(std::get<1>(vrijeme1)>std::get<1>(vrijeme2))return false;
                        }
                        
                    }
                }
            }
         return false;   
        }   );
        return **it;
    }
    
     Pregled Pregledi::DajNajranijiPregled() const {
        if(vektor_pregleda.size()==0)throw std::domain_error("Nema registriranih pregleda");
        
        auto it=std::min_element(vektor_pregleda.begin(),vektor_pregleda.end(),[] (std::shared_ptr<Pregled> pregled1,std::shared_ptr<Pregled> pregled2) {
            
            if(pregled1->DajDatumPregleda().Ocitaj()<pregled2->DajDatumPregleda().Ocitaj() ) return true; return false;
        }   );
        return **it;
    }
          
           void Pregledi::ObrisiNajranijiPregled() {
        if(vektor_pregleda.size()==0)throw std::range_error("Prazna kolekcija");
        
       Pregled p(DajNajranijiPregled());    
    for(int i=0;i<vektor_pregleda.size();i++) {
        if(vektor_pregleda[i]->DajImePacijenta()==p.DajImePacijenta() && vektor_pregleda[i]->DajDatumPregleda().Ocitaj()==p.DajDatumPregleda().Ocitaj() && vektor_pregleda[i]->DajVrijemePregleda().Ocitaj()==p.DajVrijemePregleda().Ocitaj() ){
             vektor_pregleda[i]=nullptr;
            vektor_pregleda.erase(vektor_pregleda.begin()+i);
            break;
        }
    }
    
    }
    
    void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
        for(int i=0;i<vektor_pregleda.size();i++) {
           
           if(vektor_pregleda[i]->DajImePacijenta()==ime_pacijenta ) {
                vektor_pregleda[i]=nullptr; 
              vektor_pregleda.erase(vektor_pregleda.begin()+i);i--;
           }    
        }
        
    }
    
   void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
        
        std::vector<Pregled> vektor;
        for(int i=0;i<vektor_pregleda.size();i++) {
        
        if(vektor_pregleda[i]->DajDatumPregleda().Ocitaj()==datum.Ocitaj()) {
            vektor.push_back(*vektor_pregleda[i]);
        }
            
        }
        
        std::sort(vektor.begin(),vektor.end(),[](const Pregled &p1, const Pregled &p2) {
           if(p1.DolaziPrije(p1,p2) )return true; return false;});
            
   
        for(auto a:vektor)a.Ispisi();
        
    }  
    
    void Pregledi::IspisiSvePreglede() const {
       
       std::vector<Pregled> vektor;
       for(int i=0;i<vektor_pregleda.size();i++) {
           vektor.push_back(*vektor_pregleda[i]);
       }
        
        std::sort(vektor.begin(),vektor.end(),[](const Pregled &p1, const Pregled &p2) {
           if(p1.DolaziPrije(p1,p2) )return true; return false;});
            
   
        for(auto a:vektor)a.Ispisi();
        
    }
          
          
          
int main ()
{
  
    Pregledi pregledi;
    std::string ime; 
   
    do{
     
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
     
        std::getline(std::cin,ime);
        if(ime!="kraj") {
            
            std::cout<<"Unesite dan mjesec i godinu pregleda: ";
            int dan,mjesec,godina; 
            
            std::cin>>dan>>mjesec>>godina;
            
            
            
            Datum datum(dan,mjesec,godina);
            std::cout<<"Unesite sate i minute pregleda: "; 
            int sati,minute;
           
               
            std::cin>>sati>>minute;
            Vrijeme vrijeme(sati,minute);
               
            
            auto pok=std::make_shared<Pregled> (Pregled(ime,datum,vrijeme));
               pregledi.RegistrirajPregled(pok); 
            std::cin.ignore(10000,'\n');
        }
        
    } while(ime!="kraj");
    
    std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
    pregledi.IspisiSvePreglede();
    
  
    while(1){
       
        std::cout<<std::endl;
         
    std::cout<<"Odaberite jednu od sljedecih opcija"<<std::endl;
    std::cout<<"1 - Broj pregleda na datum"<<std::endl;
    std::cout<<"2 - Najraniji pregled"<<std::endl;
    std::cout<<"3 - Obrisi pregled pacijenta"<<std::endl;
    std::cout<<"4 - Obrisi najraniji pregled"<<std::endl;
    std::cout<<"5 - Ispisi sve pregleda na datum"<<std::endl;
    std::cout<<"6 - Ispisi sve preglede"<<std::endl;
    std::cout<<"7 - Kraj programa"<<std::endl;
        
         int opcija; std::cin>>opcija; 
        std::cin.ignore(10000,'\n');
        
        switch(opcija) {
    
         case 1:{
         std::cout<<"Unesite dan mjesec i godinu : "; int d,m,g;
         std::cin>>d>>m>>g; 
         std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<pregledi.DajBrojPregledaNaDatum(Datum(d,m,g));
         std::cout<<std::endl;
         break;}
         
         case 2:{
         std::cout<<"Najraniji pregled je: "<<std::endl; 
         pregledi.DajNajranijiPregled().Ispisi();
         std::cout<<std::endl;
         break;}
         
         case 3: {
         std::cout<<"Unesite ime pacijenta: "; std::string imepacijenta;
         std::getline(std::cin, imepacijenta); int prije=pregledi.DajBrojPregleda();
         pregledi.ObrisiPregledePacijenta(imepacijenta); 
         std::cout<<"Uspjesno obrisano "<<prije-pregledi.DajBrojPregleda()<<" pregleda"<<std::endl;break; }
         
        
        case 4:{
        try{pregledi.ObrisiNajranijiPregled();
        std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
        }
         catch(std::range_error izuzetak){std::cout<<izuzetak.what();break;} break; }
         
        case 5:{
        std::cout<<"Unesite dan mjesec i godinu : "; int d1,m1,g1; std::cin>>d1>>m1>>g1;
        std::cout<<"Pregledi na datum "<<d1<<" "<<m1<<" "<<g1<<" su:"; std::cout<<std::endl; pregledi.IspisiPregledeNaDatum(Datum(d1,m1,g1));
        std::cout<<std::endl;
        break;}
        
        case 6:
       { pregledi.IspisiSvePreglede(); break;}
        
        case 7:return 0;
            
        }
    }
    
    
	return 0;
}

