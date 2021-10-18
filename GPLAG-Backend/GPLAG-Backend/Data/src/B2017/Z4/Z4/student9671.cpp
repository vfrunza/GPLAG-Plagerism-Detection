/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <cstdlib>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <memory>
#include <vector>
class Datum {

    public:
    int dan,mjesec,godina;
    void Postavi(int dan, int mjesec, int godina){
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if (godina%4==0 || godina%100 !=0 || godina%400==0) broj_dana[1]++;
        if(godina<1 || dan<1 ||mjesec<1|| mjesec>12 ||dan>broj_dana[mjesec-1]) throw std::domain_error ("Neispravan datum");

        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    std::tuple<int, int, int> Ocitaj() const{
        std::tuple<int, int, int> k;
        std::get<0>(k)=Datum::dan;
        std::get<1>(k)=Datum::mjesec;
        std::get<2>(k)=Datum::godina;
        return k;
    }
    void Ispisi() const{

        std::cout<<Datum::dan<<"/"<<Datum::mjesec<<"/"<<Datum::godina;
    }
};

 class Vrijeme {

 public:
int sati,minute;
 void Postavi(int sati, int minute){
     if(sati>23 || sati<0 || minute>59 || minute<0) throw std::domain_error("Neispravno vrijeme");
     Vrijeme::sati=sati;
     Vrijeme::minute=minute;
 }
 std::pair<int, int> Ocitaj () const{
   auto par=std::make_pair(Vrijeme::sati,Vrijeme::minute);
   return par;
 }
 void Ispisi() const{
     std::cout<<std::setprecision(2)<<Vrijeme::sati<<":"<<std::setprecision(2)<<Vrijeme::minute;
 }
 };

 class Pregled{

 std::string ime_pacijenta;
 Datum datum_pregleda;
 Vrijeme vrijeme_pregleda;
 public:
Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
     Pregled::ime_pacijenta=ime_pacijenta;
     Pregled::datum_pregleda.Postavi(dan_pregleda,mjesec_pregleda,godina_pregleda);
     Pregled::vrijeme_pregleda.Postavi(sati_pregleda,minute_pregleda);
 }

 void PromijeniPacijenta(const std::string &ime_pacijenta){
     Pregled::ime_pacijenta=ime_pacijenta;
 }
 void PromijeniDatum(const Datum &novi_datum){
      Pregled::datum_pregleda=novi_datum;
 }
 void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
     Pregled::vrijeme_pregleda=novo_vrijeme;
 }
 void PomjeriDanUnaprijed(){
  std::tuple<int,int,int> k(this->DajDatumPregleda().Ocitaj());
     if (!((std::get<2>(k)%4==0) || (std::get<2>(k)%100 !=0) || (std::get<2>(k)%400==0))) {

     if(std::get<1>(k)<12) {
     if(std::get<1>(k)!=4 && std::get<1>(k)!=6 && std::get<1>(k)!=9 &&std::get<1>(k)!=11 &&std::get<1>(k)!=2 && std::get<0>(k)<31){
         std::get<0>(k)=std::get<0>(k)+1;

     }
     else if (std::get<1>(k)!=4 && std::get<1>(k)!=6 && std::get<1>(k)!=9 &&std::get<1>(k)!=11 &&std::get<1>(k)!=2 && std::get<0>(k)==31){
          std::get<1>(k)=std::get<1>(k)+1;
          std::get<0>(k)=1;
     }
     else if(std::get<1>(k)==4 && std::get<1>(k)==6 && std::get<1>(k)==9 &&std::get<1>(k)==11 && std::get<0>(k)<30){
         std::get<0>(k)=std::get<0>(k)+1;
     }
     else if(std::get<1>(k)==4 && std::get<1>(k)==6 && std::get<1>(k)==9 &&std::get<1>(k)==11 && std::get<0>(k)==30){
         std::get<1>(k)=std::get<1>(k)+1;
         std::get<0>(k)=1;
     }
     else if(std::get<1>(k)==2 && std::get<0>(k)<28){
         std::get<0>(k)=std::get<0>(k)+1;
     }
     else if(std::get<1>(k)==2 && std::get<0>(k)==28){
         std::get<1>(k)=std::get<1>(k)+1;
         std::get<0>(k)=1;

          }

        }


     if(std::get<1>(k)==12) {
     if(std::get<1>(k)!=4 && std::get<1>(k)!=6 && std::get<1>(k)!=9 &&std::get<1>(k)!=11 &&std::get<1>(k)!=2 && std::get<0>(k)<31){
         std::get<0>(k)=std::get<0>(k)+1;

     }
     else if (std::get<1>(k)!=4 && std::get<1>(k)!=6 && std::get<1>(k)!=9 &&std::get<1>(k)!=11 &&std::get<1>(k)!=2 && std::get<0>(k)==31){
          std::get<2>(k)=std::get<2>(k)+1;
          std::get<1>(k)=1;
     }
     else if(std::get<1>(k)==4 && std::get<1>(k)==6 && std::get<1>(k)==9 &&std::get<1>(k)==11 && std::get<0>(k)<30){
         std::get<0>(k)=std::get<0>(k)+1;
     }
     else if(std::get<1>(k)==4 && std::get<1>(k)==6 && std::get<1>(k)==9 &&std::get<1>(k)==11 && std::get<0>(k)==30){
         std::get<2>(k)=std::get<2>(k)+1;
         std::get<1>(k)=1;
     }
     else if(std::get<1>(k)==2 && std::get<0>(k)<28){
         std::get<0>(k)=std::get<0>(k)+1;
     }
     else if(std::get<1>(k)==2 && std::get<0>(k)==28){
         std::get<2>(k)=std::get<2>(k)+1;
         std::get<1>(k)=1;

          }
     }

     }

     if ((std::get<2>(k)%4==0) || (std::get<2>(k)%100 !=0) || (std::get<2>(k)%400==0)) {

     if(std::get<1>(k)<12) {
     if(std::get<1>(k)!=4 && std::get<1>(k)!=6 && std::get<1>(k)!=9 &&std::get<1>(k)!=11 &&std::get<1>(k)!=2 && std::get<0>(k)<31){
         std::get<0>(k)=std::get<0>(k)+1;

     }
     else if (std::get<1>(k)!=4 && std::get<1>(k)!=6 && std::get<1>(k)!=9 &&std::get<1>(k)!=11 &&std::get<1>(k)!=2 && std::get<0>(k)==31){
          std::get<1>(k)=std::get<1>(k)+1;
          std::get<0>(k)=1;
     }
     else if(std::get<1>(k)==4 && std::get<1>(k)==6 && std::get<1>(k)==9 &&std::get<1>(k)==11 && std::get<0>(k)<30){
         std::get<0>(k)=std::get<0>(k)+1;
     }
     else if(std::get<1>(k)==4 && std::get<1>(k)==6 && std::get<1>(k)==9 &&std::get<1>(k)==11 && std::get<0>(k)==30){
         std::get<1>(k)=std::get<1>(k)+1;
         std::get<0>(k)=1;
     }
     else if(std::get<1>(k)==2 && std::get<0>(k)<29){
         std::get<0>(k)=std::get<0>(k)+1;
     }
     else if(std::get<1>(k)==2 && std::get<0>(k)==29){
         std::get<1>(k)=std::get<1>(k)+1;
         std::get<0>(k)=1;

          }

     }

     if(std::get<1>(k)==12) {
     if(std::get<1>(k)!=4 && std::get<1>(k)!=6 && std::get<1>(k)!=9 &&std::get<1>(k)!=11 &&std::get<1>(k)!=2 && std::get<0>(k)<31){
         std::get<0>(k)=std::get<0>(k)+1;

     }
     else if (std::get<1>(k)!=4 && std::get<1>(k)!=6 && std::get<1>(k)!=9 &&std::get<1>(k)!=11 &&std::get<1>(k)!=2 && std::get<0>(k)==31){
          std::get<2>(k)=std::get<2>(k)+1;
          std::get<1>(k)=1;
     }
     else if(std::get<1>(k)==4 && std::get<1>(k)==6 && std::get<1>(k)==9 &&std::get<1>(k)==11 && std::get<0>(k)<30){
         std::get<0>(k)=std::get<0>(k)+1;
     }
     else if(std::get<1>(k)==4 && std::get<1>(k)==6 && std::get<1>(k)==9 &&std::get<1>(k)==11 && std::get<0>(k)==30){
         std::get<2>(k)=std::get<2>(k)+1;
         std::get<1>(k)=1;
     }
     else if(std::get<1>(k)==2 && std::get<0>(k)<28){
         std::get<0>(k)=std::get<0>(k)+1;
     }
     else if(std::get<1>(k)==2 && std::get<0>(k)==28){
         std::get<2>(k)=std::get<2>(k)+1;
         std::get<1>(k)=1;

          }
     }
     }
     }
 void PomjeriDanUnazad(){
     std::tuple<int,int,int> k(this->DajDatumPregleda().Ocitaj());
     if (!((std::get<2>(k)%4==0) || (std::get<2>(k)%100 !=0) || (std::get<2>(k)%400==0))) {
     if(std::get<0>(k)>1)  std::get<0>(k)=std::get<0>(k)-1;
     if(std::get<0>(k)==1) {
         if(std::get<1>(k) !=1)  std::get<1>(k)=std::get<1>(k)-1;
         else if(std::get<1>(k)==1) std::get<1>(k)= 12;

         if(std::get<1>(k)==4 && std::get<1>(k)==6 && std::get<1>(k)==9 &&std::get<1>(k)==11)
         std::get<0>(k)=std::get<1>(k)+29;
         else if(std::get<1>(k)==2)  std::get<0>(k)=std::get<1>(k)+27;
         else  std::get<0>(k)=std::get<1>(k)+30;
        }
     }
     else  {
     if(std::get<0>(k)>1)  std::get<0>(k)=std::get<0>(k)-1;
     if(std::get<0>(k)==1) {
         if(std::get<1>(k) !=1)  std::get<1>(k)=std::get<1>(k)-1;
         else if(std::get<1>(k)==1) std::get<1>(k)= 12;

         if(std::get<1>(k)==4 && std::get<1>(k)==6 && std::get<1>(k)==9 &&std::get<1>(k)==11)
         std::get<0>(k)=std::get<1>(k)+29;
         else if(std::get<1>(k)==2)  std::get<0>(k)=std::get<1>(k)+28;
         else  std::get<0>(k)=std::get<1>(k)+30;
        }
     }
 }


 std::string DajImePacijenta() const{
     return ime_pacijenta;
 }
 Datum DajDatumPregleda() const{
     return datum_pregleda;
 }
 Vrijeme DajVrijemePregleda() const{
     return vrijeme_pregleda;
 }
 static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
  std::tuple <int,int,int> t1(p1.DajDatumPregleda().Ocitaj()), t2(p2.DajDatumPregleda().Ocitaj());
  std::pair<int,int> s1(p1.DajVrijemePregleda().Ocitaj()) ,s2(p2.DajVrijemePregleda().Ocitaj());

      if(std::get<2>(t1)<std::get<2>(t2))  return true ;
     if(std::get<2>(t1)==std::get<2>(t2)) {
         if(std::get<1>(t1)<std::get<1>(t2)) return true;
         if(std::get<1>(t1)==std::get<1>(t2)){

         if(std::get<0>(t1)<std::get<0>(t2)) return true;

         }
         if(std::get<0>(t1)==std::get<0>(t2)) {

         if(s1.first<s2.first) return true;
         }
         if(s1.first==s2.first) {
             if(s1.second<s2.second) return true ;
         }
         }

     return false ;
 }
 void Ispisi() const{
 //Konačno, funkcija “Ispisi” ispisuje podatke o pregledu na način da se prvo ispiše ime pacijenta,
 //poravnato ulijevo u polju širine 30 znakova, a zatim datum i vrijeme pregleda razdvojeni jednim razmakom (na kraju se prelazi u novi red).
std::cout<<std::left<<std::setw(30);
std::cout<<this->DajImePacijenta();
std::cout<<std::get<0>((this->DajDatumPregleda()).Ocitaj())<<"/"<<std::get<1>((this->DajDatumPregleda()).Ocitaj())<<"/"<<std::get<2>((this->DajDatumPregleda()).Ocitaj());
std::cout<<" ";
if(((this->DajVrijemePregleda()).Ocitaj()).first <10) std::cout<<"0";
std::cout<<std::setprecision(2)<<((this->DajVrijemePregleda()).Ocitaj()).first<<":";
if(((this->DajVrijemePregleda()).Ocitaj()).second <10) std::cout<<"0";
std::cout<<((this->DajVrijemePregleda()).Ocitaj()).second;
std::cout<<std::endl;
 }
 };



 class Pregledi {

     std::vector<std::shared_ptr<Pregled>> pok;
     
     
     public:
     explicit Pregledi() {};

     Pregledi(std::initializer_list<Pregled> spisak_pregleda)  {
        pok.resize(spisak_pregleda.size());
         auto iter(spisak_pregleda.begin());
         for(int i{0};i<spisak_pregleda.size();i++)  {
             std::tuple<int,int,int> datum((iter->DajDatumPregleda()).Ocitaj());
             std::pair<int,int> vrijeme((iter->DajVrijemePregleda()).Ocitaj());
             pok[i]=std::make_shared <Pregled>(iter->DajImePacijenta(),std::get<0>(datum),std::get<1>(datum),std::get<2>(datum),
             vrijeme.first,vrijeme.second);
             iter++;
         };


     };
     
     Pregledi(const Pregledi &pregledi){

         pok.resize(pregledi.DajBrojPregleda());
          for(int i{0};i<pok.size();i++)  {
             std::tuple<int,int,int> datum((pregledi.pok[i]->DajDatumPregleda()).Ocitaj());
             std::pair<int,int> vrijeme((pregledi.pok[i]->DajVrijemePregleda()).Ocitaj());
             pok[i]=std::make_shared <Pregled>(pregledi.pok[i]->DajImePacijenta(),std::get<0>(datum),std::get<1>(datum),std::get<2>(datum),
             vrijeme.first,vrijeme.second);
         }


     };
     Pregledi(Pregledi &&pregledi):pok(std::move(pregledi.pok)){};
     
     Pregledi &operator = (const Pregledi &pregledi){
         pok.resize(pregledi.pok.size());

         for(int i{0};i<pok.size();i++)  {
             std::tuple<int,int,int> datum((pregledi.pok[i]->DajDatumPregleda()).Ocitaj());
             std::pair<int,int> vrijeme((pregledi.pok[i]->DajVrijemePregleda()).Ocitaj());
             pok[i]=std::make_shared <Pregled>(pregledi.pok[i]->DajImePacijenta(),std::get<0>(datum),std::get<1>(datum),std::get<2>(datum),
             vrijeme.first,vrijeme.second);

         }

         return *this;
     };
     Pregledi &operator =(Pregledi &&pregledi) {
         pok=std::move(pregledi.pok);
         return *this;
     };
     
     void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
         std::tuple<int,int,int> datumpregleda(datum_pregleda.Ocitaj());
         std::pair<int,int> vrijemepregleda(vrijeme_pregleda.Ocitaj());

         std::shared_ptr<Pregled> novipregled = std::make_shared<Pregled>(ime_pacijenta,std::get<0>(datumpregleda),
         std::get<1>(datumpregleda),std::get<2>(datumpregleda),vrijemepregleda.first,vrijemepregleda.second);

         pok.push_back(novipregled);
     };
     void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){


         Datum datum;
         datum.Postavi(dan_pregleda,mjesec_pregleda,godina_pregleda);

         Vrijeme vrijeme;
         vrijeme.Postavi(sati_pregleda,minute_pregleda);

         RegistrirajPregled(ime_pacijenta,datum,vrijeme);
     };
     void RegistrirajPregled(std::shared_ptr<Pregled> pregled){


        pok.push_back(pregled);
     };
     int DajBrojPregleda() const{
         return pok.size();
     };
     int DajBrojPregledaNaDatum(const Datum &datum) const{
         return std::count_if(pok.begin(),pok.end() ,[datum](std::shared_ptr<Pregled>p) {return (datum.Ocitaj()==(p->DajDatumPregleda()).Ocitaj());});
     }
     Pregled &DajNajranijiPregled() {
        if(pok.size()==0) throw std::domain_error("Nema registriranih pregleda");
        auto najranijipacijent= std::min_element(pok.begin(),pok.end() ,[](std::shared_ptr<Pregled>p1,std::shared_ptr<Pregled> p2) {  return Pregled::DolaziPrije(*p1,*p2);});
        return **najranijipacijent ;
     };
     Pregled DajNajranijiPregled() const {
       if(pok.size()==0) throw std::domain_error("Nema registriranih pregleda");
        auto najranijipacijent= std::min_element(pok.begin(),pok.end() ,[](std::shared_ptr<Pregled>p1,std::shared_ptr<Pregled> p2) {  return Pregled::DolaziPrije(*p1,*p2);});
        return **najranijipacijent ;
     
     };
     void IsprazniKolekciju(){
        
     pok.resize(0);
     };
     void ObrisiNajranijiPregled(){
         if(pok.size()==0) throw std::range_error("Prazna kolekcija");
        auto s= std::min_element(pok.begin(),pok.end() ,[](std::shared_ptr<Pregled>p1,std::shared_ptr<Pregled> p2) {  return Pregled::DolaziPrije(*p1,*p2);});
        
         for(auto it(s),it1(s+1);it1!=pok.end();it++,it1++) *it=*it1;
        pok.resize(pok.size()-1);
         std::cout<<"Najraniji pregled uspjesno obrisan";
     };
     void ObrisiPregledePacijenta(const std::string &ime_pacijenta){
      int br(0);
       while(1) {
      auto s=std::find_if(pok.begin(),pok.end(),[ime_pacijenta] (std::shared_ptr<Pregled>p) {return (p->DajImePacijenta()==ime_pacijenta);});
      if(s==pok.end()) break;
      

         for(auto it(s),it1(s+1);it1!=pok.end();it++,it1++) *it=*it1;
         pok.resize(pok.size()-1);

          br++;


   }
   std::cout<<"Uspjesno obrisano "<< br <<" pregleda";
     };
     void IspisiPregledeNaDatum(const Datum &datum) const{
    static std::vector<std::shared_ptr<Pregled>> pblb ;
      static int br(0);
      std::for_each (pok.begin(),pok.end(), [datum,pblb] (std::shared_ptr<Pregled> pokazivac) {
       std::tuple<int,int,int> t1(pokazivac->DajDatumPregleda().Ocitaj()) , t2(datum.Ocitaj());

       if(std::get<0>(t1)==std::get<0>(t2) && std::get<1>(t1)==std::get<1>(t2) && std::get<2>(t1)==std::get<2>(t2)) 
       {pblb.resize(pblb.size() + 1); pblb[br++] = pokazivac; }});
      std::sort(pblb.begin(),pblb.end(), [] (std::shared_ptr<Pregled>  p1,std::shared_ptr<Pregled> p2) { return Pregled::DolaziPrije(*p1,*p2); });
      std::for_each(pblb.begin(),pblb.end(),[](std::shared_ptr<Pregled> pacijent ){ pacijent->Ispisi() ;});
      
     };
     void IspisiSvePreglede() const {
       
      std::vector<std::shared_ptr<Pregled>> p ;
      //for(int i{0};i<pok.size();i++) {
       p=pok; 
       //static int br{0};
       std::sort(p.begin(),p.end(), [] (std::shared_ptr<Pregled> p1,std::shared_ptr<Pregled> p2) { return Pregled::DolaziPrije(*p1,*p2); });
      std::for_each(p.begin(),p.end(),[](std::shared_ptr<Pregled> pacijent ){ pacijent->Ispisi() ;});
      

     };
 };
int main ()
{

Pregledi ppp;

 Datum d;
 Vrijeme v;
 

 do {

 std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
 
 int day,month,year,hour,minutes ;
 std::string ime ;
 
  std::cin>>ime;
 if(ime == "kraj") break;
  //std::cin.clear();
  //std::cin.ignore(10000,'\n');
 
 std::cout<<"Unesite dan mjesec i godinu pregleda: ";
 
 std::cin>>day;
 std::cin>>month;
 std::cin>>year ;
 try {
 
  d.Postavi(day,month,year);
 }
 catch (std::domain_error d) {
  std::cout<<d.what();
 }
  std::cout<<"Unesite sate i minute pregleda: " ;
  std::cin>>hour;
  std::cin>>minutes;

  try {
  v.Postavi(hour,minutes);
  }
  catch(std::domain_error d) {
  std::cout<< d.what();
  }
  ppp.RegistrirajPregled(ime,d,v);
  
 } while(1);
 
 std::cout<<"Trenutno su registrovani sljedeci pregledi\n" ;
 ppp.IspisiSvePreglede();
  while(1) {
 std::cout<<"\nOdaberite jednu od sljedecih opcija";
 std::cout<< "\n1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa\n";
 int i;
 std::cin>>i;

  
 switch(i) {
  
    case 1: {
          std::cout<<"Unesite dan mjesec i godinu : ";
          int x,y,z;
          std::cin>>x>>y>>z;
          d.Postavi(x, y, z);
          std::cout<<"Broj pregleda na datum ";
          std::cout<<std::get<0>(d.Ocitaj())<<" "<<std::get<1>(d.Ocitaj())<<" "<<std::get<2>(d.Ocitaj());
          std::cout<<" je: ";
          std::cout<<ppp.DajBrojPregledaNaDatum(d);
          std::cout<<std::endl ;
          } break ;
  
  case 2: std::cout<<"Najraniji pregled je:\n"; 
  try {
   ppp.DajNajranijiPregled().Ispisi();
   }
   catch (std::domain_error d)
   { std::cout<<d.what(); }
    break ; std::cout<<std::endl ;
  
  case 3: {
          std::cout<<"Unesite ime pacijenta: ";
          std::string ime;
          std::cin>>ime;
          ppp.ObrisiPregledePacijenta(ime); 
          std::cout<<std::endl ;
 
                   }break;
  
  case 4: 
  try {
   ppp.ObrisiNajranijiPregled();
   }
   catch(std::domain_error d) {
    std::cout<<d.what();
    } break; std::cout<<std::endl ;
  
  case 5: {
          std::cout<<"Unesite dan mjesec i godinu : ";
          int x,y,z;
          std::cin>>x;
          std::cin>>y;
          std::cin>>z;
          d.Postavi(x, y, z);
          std::cout<<"Pregledi na datum "<<x<<" "<<y<<" "<<z<<" su:\n"; ppp.IspisiPregledeNaDatum(d); 
          std::cout<<std::endl ;
          }break ;
  
  case 6: ppp.IspisiSvePreglede();break ;std::cout<<std::endl ;
  
  case 7: ppp.IsprazniKolekciju(); break ;std::cout<<std::endl ;
   }
   if(i == 7) break;
 }
	return 0;
}
