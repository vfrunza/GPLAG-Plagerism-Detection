/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <algorithm>
#include <iomanip>
#include <string>
class Datum {
    int d, m,g;
    public:
    Datum (int dan, int mjesec, int godina){
        Datum::d=dan;
        Datum::m=mjesec;
        Datum::g=godina;
        
    }
    void Postavi( int dan, int mjesec, int godina){
        Datum::d=dan;
        Datum::m=mjesec;
        Datum::g=godina;
    }
    std::tuple<int, int, int>Ocitaj() const {return std::tie(d,m,g);}
    void Ispisi() const {
        std::cout<<d<<"/"<<m<<"/"<<g;
    }
    
};

class Vrijeme{
    int h, m;
    public:
    Vrijeme ( int sati, int minute){
        Vrijeme::h=sati;
        Vrijeme::m=minute;
    }
    void Postavi( int sati, int minute){
        Vrijeme::h=sati;
        Vrijeme::m=minute;
    }
    std::pair<int, int> Ocitaj() const { return std::make_pair(h, m); }
    void Ispisi() const {
        std::cout<<h<<":"<<m;
    }
    };
    
class Pregled {
    std::string ime_p;
    Datum datum_p;
    Vrijeme vrijeme_p;
    public:
    
    Pregled ( const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): 
    ime_p(ime_pacijenta), datum_p(datum_pregleda), vrijeme_p(vrijeme_pregleda) {}
    
    
    Pregled( const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
    int sati_pregleda, int minute_pregleda): 
    ime_p(ime_pacijenta),
    datum_p(Datum(dan_pregleda, mjesec_pregleda, godina_pregleda)),
    vrijeme_p(Vrijeme(sati_pregleda, minute_pregleda))
        
    {}


    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_p=ime_pacijenta;
    }
    void PromijeniDatum( const Datum &novi_datum) {
        Pregled::datum_p=novi_datum;
    }
    void PromijeniVrijeme( const Vrijeme &novo_vrijeme) {
        Pregled::vrijeme_p=novo_vrijeme;
    }
  void PomjeriDanUnaprijed(){
      int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      std::tuple<int, int, int> datum(this->datum_p.Ocitaj());
      std::get<0>(datum)++;
 
  }
    void PomjeriDanUnazad() {
        std::tuple<int, int , int> datum=datum_p.Ocitaj();
        std::get<0>(datum)++;
    
   }
    std::string DajImePacijenta() const { return ime_p;};
    Datum DajDatumPregleda() const { return datum_p; };
    Vrijeme DajVrijemePregleda() const { return vrijeme_p; };
    

   
   void Ispisi() {
       std::cout<<std::setw(30)<<std::left<<ime_p;
       datum_p.Ispisi();
       std::cout<<" ";
       vrijeme_p.Ispisi();
       std::cout<<std::endl;
   }
    
};
class Pregledi {
    int max_broj_p;
    int broj_pregleda;
    Pregled **pr;
    public:
    
    explicit Pregledi( int max_broj_pregleda): max_broj_p(max_broj_pregleda),broj_pregleda(0),pr(nullptr){
        try{
        pr=new Pregled*[max_broj_pregleda];
        for( int i=0; i<max_broj_pregleda; i++){
            pr[i]=nullptr;
        }
        }catch(...){
            for( int i=0; i<max_broj_pregleda; i++){
                delete pr[i];
            }
            delete [] pr;
            throw;
        }
        
    }
    Pregledi( std::initializer_list<Pregled> spisak_pregleda): max_broj_p(spisak_pregleda.size()), pr(nullptr),
    broj_pregleda(spisak_pregleda.size()){
        pr=new Pregled*[broj_pregleda];
        for( int i=0; i<broj_pregleda; i++){
            pr[i]=nullptr;
        }
        int p(0);
        for( auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++){
            pr[p]= new Pregled(*it);
            p++;
        }
        
    }
    Pregledi( const Pregledi &pregledi): max_broj_p(pregledi.max_broj_p), broj_pregleda(pregledi.broj_pregleda),
    pr(new Pregled*[pregledi.max_broj_p]{}){
    try{
    for( int i=0; i<pregledi.broj_pregleda; i++){
        pr[i]=nullptr;
        pr[i]=new Pregled(*pregledi.pr[i]);
    }
    
}catch(...){
    for( int i=0; i<pregledi.broj_pregleda; i++){
        delete pr[i];
    }
    delete[] pr;
    throw;
}
    
}
   Pregledi(Pregledi &&pregledi): max_broj_p(pregledi.max_broj_p), broj_pregleda(pregledi.broj_pregleda){
        std::swap(broj_pregleda,pregledi.broj_pregleda);
        std::swap(pr, pregledi.pr);
    }
    
    
    Pregledi &operator= ( const Pregledi &pregledi) {
        broj_pregleda=pregledi.broj_pregleda;
        for( int i=0; i<broj_pregleda; i++){
            *pr[i]=*pregledi.pr[i];
        }
        return *this;
        
    }
    Pregledi &operator =( Pregledi &&pregledi){ 
        broj_pregleda=pregledi.broj_pregleda;
        std::swap(broj_pregleda, pregledi.broj_pregleda);
        std::swap(pr,pregledi.pr);
        return *this;
    }
    void RegistrirajPregled( const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        if(broj_pregleda>=max_broj_p) throw std::range_error("Dostignut maksimalan broj pregleda");
        try {
            pr[broj_pregleda]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
            broj_pregleda++;
    }catch(...){
        for( int i=0; i<broj_pregleda+1; i++){
            delete pr[i];
        }
        delete[] pr;
    }
        
    }
    ~Pregledi(){
        for( int i=0; i<broj_pregleda+1; i++){
            delete pr[i];
        }
        delete[] pr;
    }
    void RegistrirajPregled( const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
        Datum datum_p(dan_pregleda, mjesec_pregleda,godina_pregleda);
        Vrijeme vrijeme_p(sati_pregleda, minute_pregleda);
        
        try{
            pr[broj_pregleda]=new Pregled(ime_pacijenta, datum_p, vrijeme_p);
             broj_pregleda++;
        }
        catch(...){
            for( int i=0; i<broj_pregleda; i++){
                delete[] pr[i];
                
            }
            delete[] pr;
        }
    }
    void RagistrirajPregled( Pregled *pregled){
        try{
            *pr[broj_pregleda]=*pregled;
            broj_pregleda++;
        }
        catch(...){
            for( int i=0; i<broj_pregleda; i++){
                delete[] pr[i];
            }
            delete[] pr;
        }
    }
    int DajBrojPregleda() const { return broj_pregleda;}
    int DajBrojPregledaNaDatum( Datum &datum) const {
        int broj_pr_d(0);
        std::tuple<int, int, int> dat_p(datum.Ocitaj());
        std::count_if (pr, pr+broj_pregleda, [&dat_p]( Pregled *p )->bool{ 
            std::tuple<int,int,int> dat(p->DajDatumPregleda().Ocitaj());
            return (std::get<0>(dat)==std::get<0>(dat_p) && std::get<1>(dat)==std::get<1>(dat_p) && std::get<2>(dat)==std::get<2>(dat_p)); 
            
    });
    }
    Pregled &DajNajranijiPregled() {
        std::sort(pr , pr+broj_pregleda, []( Pregled *p1, Pregled *p2 ){
         std::tuple<int, int, int>d1(p1->DajDatumPregleda().Ocitaj());
           std::tuple<int, int, int>d2(p2->DajDatumPregleda().Ocitaj());
           
           std::pair<int,int>v1((p1->DajVrijemePregleda()).Ocitaj());
           std::pair<int, int>v2((p2->DajVrijemePregleda()).Ocitaj());
           if(std::get<2>(d1)==std::get<2>(d2)){
               if(std::get<1>(d1)==std::get<1>(d2)){
                   if(std::get<0>(d1)!=std::get<0>(d1)){
                       return std::get<0>(d1)<std::get<0>(d2);
                       
                   }
                       else { 
                           if(v1.first==v2.first){
                               if(v1.second!=v2.second) return v1.second<v2.second;
                           }
                           else return v1.first<v2.first;
                   }
               }
                 
                   else if(std::get<1>(d1)!=std::get<1>(d2)) return std::get<1>(d1)<std::get<1>(d2);
           }
               else return std::get<2>(d1)<std::get<2>(d2);
          } );
    }
    
   void IsprazniKolekciju() {
       for( int i=0; i<broj_pregleda; i++){
           pr[i]=nullptr;
       }
   }
   void ObrisiNajranijiPregled() {
      Pregled *naj(*std::min_element(pr, pr+broj_pregleda, [](Pregled *p1, Pregled *p2){
         std::tuple<int, int, int>d1(p1->DajDatumPregleda().Ocitaj());
           std::tuple<int, int, int>d2(p2->DajDatumPregleda().Ocitaj());
           
           std::pair<int,int>v1((p1->DajVrijemePregleda()).Ocitaj());
           std::pair<int, int>v2((p2->DajVrijemePregleda()).Ocitaj());
           if(std::get<2>(d1)==std::get<2>(d2)){
               if(std::get<1>(d1)==std::get<1>(d2)){
                   if(std::get<0>(d1)!=std::get<0>(d1)){
                       return std::get<0>(d1)<std::get<0>(d2);
                       
                   }
                       else { 
                           if(v1.first==v2.first){
                               if(v1.second!=v2.second) return v1.second<v2.second;
                           }
                           else return v1.first<v2.first;
                   }
               }
                 
                   else return std::get<1>(d1)<std::get<1>(d2);
           }
               else return std::get<2>(d1)<std::get<2>(d2);
          } ));
       
   std::pair<int, int>naj_p(naj->DajVrijemePregleda().Ocitaj());
   for( int i=0; i<broj_pregleda; i++){
       std::pair<int, int>p_v(pr[i]->DajVrijemePregleda().Ocitaj());
       if(naj_p.first==p_v.first && naj_p.second==p_v.second){
           std::swap(pr[i],pr[broj_pregleda-1]);
           broj_pregleda--;
       }
   }
    
}
           
           
           
           
       
   
   void ObrisiSvePregledePacijenta(const std::string ime_pacijenta) {
       for( int i=0; i<broj_pregleda; i++){
          if( (pr[i]->DajImePacijenta())==ime_pacijenta){
              std::swap(pr[i], pr[broj_pregleda-1]);
              broj_pregleda--;
           }
               
       }
       
       
   }
   
   
   void IspisiSvePreglede() const {
       std::sort(pr , pr+broj_pregleda, []( Pregled *p1, Pregled *p2 ){
           
           std::tuple<int, int, int>d1(p1->DajDatumPregleda().Ocitaj());
           std::tuple<int, int, int>d2(p2->DajDatumPregleda().Ocitaj());
           
           std::pair<int,int>v1((p1->DajVrijemePregleda()).Ocitaj());
           std::pair<int, int>v2((p2->DajVrijemePregleda()).Ocitaj());
           if(std::get<2>(d1)==std::get<2>(d2)){
               if(std::get<1>(d1)==std::get<1>(d2)){
                   if(std::get<0>(d1)!=std::get<0>(d1)){
                       return std::get<0>(d1)<std::get<0>(d2);
                       
                   }
                       else { 
                           if(v1.first==v2.first){
                               if(v1.second!=v2.second) return v1.second<v2.second;
                           }
                           else return v1.first<v2.first;
                   }
               }
                 
                   else if(std::get<1>(d1)!=std::get<1>(d2)) return std::get<1>(d1)<std::get<1>(d2);
           }
               else return std::get<2>(d1)<std::get<2>(d2);
          } );
           for( int i=0; i<broj_pregleda; i++){
               pr[i]->Ispisi();
           }
           
       }
};  

int main ()
{
    int max_br_pregleda(0);
    int dan(1), mjesec(1), godina(1), sati(0), minute(0);
    std::string unos;
    try{
    std::cout<<"Unesite maksimalan broj pregleda: ";
    std::cin>>max_br_pregleda;
    
    
    Pregledi pr(max_br_pregleda);
    for( int i=0; i<max_br_pregleda; i++){
        std::cin.ignore(1000, '\n');
        std::cin.clear();
    std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
    std::getline(std::cin, unos);
    if(unos=="kraj") break;
    std::cout<<"Unesite dan mjesec i godinu pregleda: ";
    std::cin>>dan>>mjesec>>godina;
    Datum datum(dan,mjesec,godina);
    std::cout<<"Unesite sate i minute pregleda: ";
    std::cin>>sati>>minute;
    Vrijeme vrijeme(sati, minute);
    pr.RegistrirajPregled(unos, datum, vrijeme);
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi "<<std::endl;
    pr.IspisiSvePreglede(); 
    std::cout<<std::endl;
    int opcija(0);
    while(opcija!=7){
    std::cout<<"Odaberite jednu od sljedecih opcija"<<std::endl;
    std::cout<<"1 - Broj pregleda na datum"<<std::endl;
    std::cout<<"2 - Najraniji pregled"<<std::endl;
    std::cout<<"3 - Obrisi pregled pacijenta"<<std::endl;
    std::cout<<"4 - Obrisi najraniji pregled"<<std::endl;
    std::cout<<"5 - Ispisi sve pregleda na datum"<<std::endl;
    std::cout<<"6 - Ispisi sve preglede"<<std::endl;
    std::cout<<"7 - Kraj programa"<<std::endl;
    std::cin>>opcija;
    if(opcija==1){
        std::cout<<"Unesite dan mjesec i godinu : ";
        std::cin>>dan>>mjesec>>godina;
        Datum d(Datum(dan, mjesec, godina));
        int broj_pregleda(pr.DajBrojPregledaNaDatum(d));
        std::cout<<"Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina<<" je: "<<broj_pregleda<<std::endl<<std::endl;
    }  else if(opcija==2){
        std::cout<<"Najraniji pregled je: "<<std::endl;
        (pr.DajNajranijiPregled()).Ispisi();
    } else if(opcija==4){
       pr.ObrisiNajranijiPregled();
        std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl<<std::endl;
    }else if(opcija==3){
        std::cin.ignore(10000, '\n');
        std::cin.clear();
        std::cout<<"Unesite ime pacijenta: ";
        std::string ime_pacijenta;
        std::getline(std::cin, ime_pacijenta);
       pr.ObrisiSvePregledePacijenta(ime_pacijenta);
        std::cout<<"Uspjesno obrisano 1 pregleda"<<std::endl<<std::endl;
        
    }else if(opcija==5){
        std::cout<<"Unesite dan mjesec i godinu: ";
        std::cin>>dan>>mjesec>>godina;
        Datum d(Datum(dan, mjesec, godina));
        std::cout<<"Pregledi na datum "<<dan<<" "<<mjesec<<" "<<godina<<" su: "<<std::endl;
     //   pr.IspisiPregledeNaDatum(d);
    } else if(opcija==6){
        pr.IspisiSvePreglede();
        std::cout<<std::endl;
    }else if( opcija==7) break;
        
    }
        
    }catch(std::range_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
        
	return 0;
}
