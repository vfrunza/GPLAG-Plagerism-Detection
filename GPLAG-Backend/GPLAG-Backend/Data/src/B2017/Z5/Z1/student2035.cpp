/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <stdexcept>

class Student {
      int broj_indexa; 
      std::string godina_studija, ime_prezime, adresa, broj_telefona; 
      void ProvjeraPodataka(int broj_indexa, std::string &godina_studija, std::string &ime_prezime, std::string &adresa, std::string &broj_telefona); 
      void PojediRazmake(std::string &rijec); 
      bool ProvjeraBrojaTelefona(std::string broj);
      friend class Administracija; 
      public: 
      Student(int broj_indexa, std::string godina_studija, std::string ime_prezime, std::string adresa, std::string broj_telefona) {
            ProvjeraPodataka(broj_indexa, godina_studija, ime_prezime, adresa, broj_telefona); //provjeri jel ispravnim redosljedom saljes parametre
            this->broj_indexa=broj_indexa;
            if(godina_studija=="1") this->godina_studija="1/B"; //razmisli ovdje da li se cuva uvijek ovo ili sam ispisuje pa popravi
            else if(godina_studija=="2") this->godina_studija="2/B"; 
            else if(godina_studija=="3")  this->godina_studija="3/B"; 
            else this->godina_studija=godina_studija;
            this->ime_prezime=ime_prezime; this->adresa=adresa; this->broj_telefona=broj_telefona; 
      }
      
      //za sve navedene funkcije provjeri da li se dobro zovu jer se na greskama trebas uciti
      
      int DajIndeks() { return broj_indexa; }
      std::string DajGodinuStudija() { return godina_studija; }
      std::string DajImePrezime()  { return ime_prezime; }
      std::string DajAdresu() { return adresa; }
      std::string DajTelefon() { return broj_telefona; }
      //tesitiraj ispisi
      void Ispisi(); 
      
      
}; 

void Student::Ispisi() {
      std::cout << "Broj indeksa: " << broj_indexa << std::endl << "Godina studija: " << godina_studija << std::endl << "Ime i prezime: " << ime_prezime << std::endl << "Adresa: " << adresa << std::endl << "Telefon: " << broj_telefona << std::endl; 
}

void Student::ProvjeraPodataka(int broj_indexa, std::string &godina_studija, std::string &ime_prezime, std::string &adresa, std::string &broj_telefona) {
      if(!(broj_indexa>=10000 && broj_indexa<=99999)) throw std::domain_error("Neispravni parametri"); 
      std::vector<std::string> lista{"1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "3/M", "1/D", "2/D", "3/D"}; 
      //pojedi razmake kod godine studija
      bool legalana_godina_studija(false); 
      for(int i=0; i<12; i++) {
            if(lista[i]==godina_studija) {legalana_godina_studija=true; break; }
      }
      if(!legalana_godina_studija) throw std::domain_error("Neispravni parametri"); 
      PojediRazmake(ime_prezime); //vidi jel definisano sta ako su prazan string ime_prezime
      PojediRazmake(adresa); //vidi jel definisano sta ako je adresa prazan string
      PojediRazmake(broj_telefona); 
      if(!ProvjeraBrojaTelefona(broj_telefona)) throw std::domain_error("Neispravni parametri"); 
} 

void Student::PojediRazmake(std::string &rijec) {
      bool bilo_slovo=false; 
      for(int i=0; i<rijec.size(); i++) {
            if(rijec[i]!=' ') bilo_slovo=true; 
            else {
                  if(bilo_slovo) {bilo_slovo=false; continue; }
                  else rijec.erase(rijec.begin()+i); 
                  bilo_slovo=false;
                  i--;
            } 
      }
      if(rijec.size()!=0) {if(rijec[rijec.size()-1]==' ') rijec.erase(rijec.begin()+rijec.size()-1); }
      
}

bool Student::ProvjeraBrojaTelefona(std::string rijec) {
      bool bila_cifra(false); 
      bool bila_crtica(false); 
      bool bio_slash(false); 
      //ako je manje od 5 da vrati false 
      if(rijec.size()<5) return false; 
      if(rijec[0]>'9' || rijec[0]<'0') { return false; }
      for(int i=0; i<rijec.size(); i++) {
            if((rijec[i]>'9' || rijec[i]<'0') && (rijec[i]!='-' && rijec[i]!='/')) {return false; }
            else if(rijec[i]<='9' && rijec[i]>='0') bila_cifra=true; 
            else if(rijec[i]=='/') {
                  if(bio_slash)  {return false; }
                  if(bila_crtica) {return false; }
                  if(!bila_cifra) return false; 
                  bio_slash=true; 
                  bila_cifra=false;
            }
            else if(rijec[i]=='-') {
                  if(!bio_slash) return false; 
                  if(!bila_cifra) return false; 
                  if(bila_crtica) return false; 
                  bila_crtica=true; 
                  bila_cifra=false; 
            }
            if(i==rijec.size()-1) { if(rijec[i]<'0' || rijec[i]>'9') return false; }
            }
            return true;
}


class Laptop{
      int ev_broj; 
      std::string naziv, karakteristike;
      Student* kod_koga_je; 
      void ProvjeraPodatakaZaLaptop(int ev_broj, std::string naziv, std::string karakteristike); 
      friend class Administracija;
      public: 
      Laptop(int ev_broj, std::string naziv, std::string karakteristike) : kod_koga_je(nullptr) {
       this->ev_broj=ev_broj; this->naziv=naziv; this->karakteristike=karakteristike;      
      }
      int DajEvidencijskiBroj() { return ev_broj; }
      std::string DajNaziv() { return naziv; }
      std::string DajKarakteristike() { return karakteristike; }
      void Zaduzi(Student &onaj_koji_zaduzuje) { if(kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen"); kod_koga_je=&onaj_koji_zaduzuje; }
      void Razduzi() { kod_koga_je=nullptr; }
      bool DaLiJeZaduzen() { if(kod_koga_je==nullptr) return false; return true; }      
      Student DajKodKogaJe() { if(kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen"); return *kod_koga_je; }
      Student* DajPokKodKogaJe() { return kod_koga_je; } 
      //testiraj ispisi
      void Ispisi(); 
      
}; 

void Laptop::Ispisi() {
      std::cout << "Evidencijski broj: " << ev_broj << std::endl << "Naziv: " << naziv << std::endl << "Karakteristike: " << karakteristike; 
}


void Laptop::ProvjeraPodatakaZaLaptop(int ev_broj, std::string naziv, std::string karakteristike) {
      if(ev_broj<0) throw std::domain_error("Neispravni parametri"); 
}

class Administracija{
      std::map<int, Student* > mapa_studenata; 
      std::map<int, Laptop* > mapa_laptopa; 
      public: 
      Administracija() {/*navnodno je prazan ali da li je to fkt tako*/}
      Administracija(const Administracija &admin);
      Administracija(Administracija &&admin);
      Administracija &operator = (const Administracija &admin); 
  //    Administracija &operator = (const Administracija &&admin);
      ~Administracija();  
      void RegistrirajNovogStudenta(/*parametri kao u konstruktoru za studenta */); //kreira studenta i upisuje u evidenciju NOTE: 
                                                                              //ako postoji student s istim brojem indexa baca
                                                                              //domain_error("Student s tim indexom vec postoji")
      void RegistrirajNoviLaptop(); //analogno onoj za studente "Laptop s tim evidencijskim brojem vec postoji"
      Student &NadjiStudenta(int broj_indexa); //ili referencu na tog studenta ili domain_Error "Student nije nadjen"
      Student NadjiStudenta(const Administracija &admin); //vratiti kopiju studenta umjesto reference tj novi objekat tipa student istovjetan
                                                            //nadjenom
      Laptop &NadjiLaptop(int evidencijski_broj); //izuzetak "Laptop nije nadjen"
      Laptop NadjiLaptop(const Administracija &admin); //analogno prethodnom
      void IzlistajStudente(); //poglredaj format u zadatku
      void IzlistajLaptope(); //pogledaj format u zadatku
      void ZaduziLaptop(int broj_indexa, int ev_broj); //domain_error"Student nije nadjen/Laptop nije nadjen";, prvo testiras studenta pa laptop
                                                      //ako je laptop vvec zaduzen domainerror("Laptop vec zaduzen")    
                                                      //analogno za studenta ("Student vec zaduzio laptop")
      int NadjiSlobodanLaptop(); //vraca evidencijski broj prvog slobodnog laptopa ili domainerror ("Nema slobodnih laptopa")
      void RazduziLaptop(int evidencijski_broj); //domain error("Laptop nije nadjen")/"Laptop nije zaduzen"
      void PrikaziZaduzenja(); //pogledaj format 
}; 

Administracija::Administracija (const Administracija &admin) { //ja mislim da je ok ali provjeri jos jednom ako bude bilo sudbine
      auto it_studenata=admin.mapa_studenata.begin(); 
      auto it_laptopa=admin.mapa_laptopa.begin();
      while(it_studenata!=admin.mapa_studenata.end()) {
            mapa_studenata[it_studenata->first]=new Student(it_studenata->second->broj_indexa, it_studenata->second->godina_studija, it_studenata->second->ime_prezime, it_studenata->second->adresa, it_studenata->second->broj_telefona);
            it_studenata++;
      }
      while(it_laptopa!=admin.mapa_laptopa.end()) {
            mapa_laptopa[it_laptopa->first]=new Laptop(it_laptopa->second->ev_broj, it_laptopa->second->naziv, it_laptopa->second->karakteristike);
            mapa_laptopa[it_laptopa->first]->kod_koga_je=it_laptopa->second->kod_koga_je;
            it_laptopa++;
      }
}

Administracija::Administracija(Administracija &&admin) { //EADEM 
      auto it_studenata=admin.mapa_studenata.begin();
      auto it_laptopa=admin.mapa_laptopa.begin();
      while(it_studenata!=admin.mapa_studenata.end()) {
            mapa_studenata[it_studenata->first]=it_studenata->second; 
           it_studenata->second=nullptr;
            it_studenata++;
      }
      while(it_laptopa!=admin.mapa_laptopa.end()) {
            it_laptopa++;
      }
}



int main ()
{
     std::string s("  6553/-12           "); 
 //     PojediRazmake(s); 
   //   std::cout << s << " "<< std::boolalpha << ProvjeraBrojaTelefona(s);  
	return 0;
}
