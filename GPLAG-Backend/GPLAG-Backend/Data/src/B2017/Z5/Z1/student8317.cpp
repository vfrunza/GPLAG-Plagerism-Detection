/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

std::string Postavi (const std::string& ime_i_prezime)
{
    std::string novi;
    for(int i=0; i<ime_i_prezime.length(); i++) {

        int j=i;
        while(j<ime_i_prezime.length() && ime_i_prezime[j]==' ') j++;
        if(i!=0 && j!=ime_i_prezime.length()) novi.push_back(ime_i_prezime[i]);
        if(j!=ime_i_prezime.length() && ( i!=j || i==0)) novi.push_back(ime_i_prezime[j]);
        i=j;
    }
    return novi;

}

std::string Studiji[] {"1", "2", "3", "1/B", "2/B", "3/B","1/M", "2/M", "3/M","1/D", "2/D", "3/D"};
class Student
{
    int broj_indeksa;
    std::string godina_studija, ime_i_prezime, adresa,  broj_telefona;

public:

    Student (int broj_indeksa, std::string godina_studija, std::string ime_i_prezime, std::string adresa,
             std::string telefon)   {
        Student::broj_indeksa=broj_indeksa;
        {
            int i(0);
            for( i=0; i<12; i++) {
                if(godina_studija==Studiji[i]) {
                    Student::godina_studija=Studiji[i];
                    break;
                }
            }
            if(i==12) throw std::domain_error("Neispravni parametri");
        }
        Student::ime_i_prezime=Postavi(ime_i_prezime);
        Student::adresa=Postavi(adresa);


        int i=0;

        while(i<telefon.length() && (telefon[i]<='9' && telefon[i]>='0')  ) i++;
        if(i==0 || i==telefon.length() || telefon[i]!='/') {
            throw std::domain_error("Neispravni parametri");
        }
        i++;
        while(i<telefon.length() && telefon[i]<='9' && telefon[i]>='0'  )i++;
        if(i==telefon.length() || telefon[i]!='-')throw std::domain_error("Neispravni parametri");
        i++;
        while(i<telefon.length() && telefon[i]<='9' && telefon[i]>='0'  )i++;
        if(i!=telefon.length())throw std::domain_error("Neispravni parametri");
        broj_telefona=telefon;
    }
    std::string DajImePrezime() const {
        return ime_i_prezime;
    }
    std::string DajAdresu() const {
        return adresa;
    }
    std::string DajTelefon() const {
        return broj_telefona;
    }
    int DajIndeks() const {
        return broj_indeksa;
    }
    std::string DajGodinuStudija() const {

        if(godina_studija.size()==1 && godina_studija[0]-'0'<4) return Studiji[godina_studija[0]-'0'+2];
        return godina_studija;
    }
    void Ispisi() const {
        std::cout<<"Broj indeksa: "<<broj_indeksa<<std::endl
                 <<"Godina studija: "<<DajGodinuStudija()<<std::endl
                 <<"Ime i prezime: "<<ime_i_prezime<<std::endl
                 <<"Adresa: "<<adresa<<std::endl
                 <<"Telefon: "<<broj_telefona<<std::endl;
    }
};

class Laptop
{
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    Student* kod_koga_je;
public:
    Laptop(int ev_broj, std::string naziv, std::string karakteristike):  naziv(naziv),
        karakteristike(karakteristike) {
        if(ev_broj<0) throw std::domain_error("Neispravni parametri");
        Laptop::ev_broj=ev_broj;
        kod_koga_je=nullptr;
    }
    int DajEvidencijskiBroj() const {
        return ev_broj;
    }
    std::string DajNaziv() const {
        return naziv;
    }
    std::string DajKarakteristike() const {
        return karakteristike;
    }
    void Zaduzi(Student& a) {
        if(kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen");
        kod_koga_je=&a;
    }
    void Razduzi() {
        if(kod_koga_je!=nullptr) kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen() const {
        return kod_koga_je!=nullptr;
    }
    Student& DajKodKogaJe() const {
        if(kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen");
        return *kod_koga_je;
    }
    Student* DajPokKodKogaJe() const {
        return kod_koga_je;
    }
    void Ispisi() const {
        std::cout<<"Evidencijski broj: "<<ev_broj<<std::endl
                 <<"Naziv: "<<naziv<<std::endl
                 <<"Karakteristike: "<<karakteristike<<std::endl;

        //provjeriti je l treba novi red
    }
};

class Administracija
{
    std::map<int, Student*> studenti;
    std::map<int, Laptop*>laptopi;
public:
    Administracija()=default; // provjeriti je li dafult
    Administracija(const Administracija& v) {
        try {

            for(auto it=v.studenti.begin(); it!=v.studenti.end(); it++) {
                studenti.emplace(std::make_pair((it->first), new Student(*(it->second))));}
            }
            catch(std::bad_alloc) {

                for(auto it=studenti.begin(); it!=studenti.end(); it++) {
                    delete it->second;
                }
                studenti.clear();
                throw;
            }
            try {

                for(auto it=v.laptopi.begin(); it!=v.laptopi.end(); it++) {
                    laptopi.emplace(it->first, new Laptop(*(it->second)));
                }}
                catch(std::bad_alloc) {

                    for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
                        delete it->second;
                    }
                    laptopi.clear();
                    throw;
                }
            }
Administracija(Administracija&& v){
    if(&v!=this){
    studenti=v.studenti; laptopi=v.laptopi;
   for( auto it=v.laptopi.begin(); it!=v.laptopi.end(); it++) it->second=nullptr;
 for(auto it=v.studenti.begin(); it!=v.studenti.end(); it++) it->second=nullptr;
    } 
}
Administracija& operator =( Administracija v){
     std::swap(studenti, v.studenti); std::swap(laptopi, v.laptopi);
    return *this;   
        
    }
Administracija&operator=(Administracija&& v){
    if(&v!=this){
    studenti=v.studenti; laptopi=v.laptopi;
     for( auto it=v.laptopi.begin(); it!=v.laptopi.end(); it++) it->second=nullptr;
 for(auto it=v.studenti.begin(); it!=v.studenti.end(); it++) it->second=nullptr;}
 return *this;
}
void RegistrirajNovogStudenta(int broj_indeksa, std::string godina_studija, std::string ime_i_prezime, std::string adresa,
             std::string telefon){
                 if(studenti.count(broj_indeksa)) throw std::domain_error("Student s tim indeksom vec postoji");
                 studenti.emplace(broj_indeksa, new Student(broj_indeksa, godina_studija, ime_i_prezime, adresa, telefon));
             }
void RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike){
    if(laptopi.count(ev_broj)) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    laptopi.emplace(ev_broj, new Laptop(ev_broj, naziv, karakteristike));
}
Student & NadjiStudenta(int broj_indeksa){
    if(!studenti.count(broj_indeksa)) throw std::domain_error("Student nije nadjen");
    return *(studenti[broj_indeksa]);
}
Student  NadjiStudenta( int broj_indeksa) const {
    if(!studenti.count(broj_indeksa)) throw std::domain_error("Student nije nadjen");
    auto it=studenti.find(broj_indeksa);
    return *(it->second);
}
Laptop & NadjiLaptop(int ev_broj){
    if(!laptopi.count(ev_broj)) throw std::domain_error("Laptop nije nadjen");
    return *(laptopi[ev_broj]);
}
Laptop  NadjiLaptop( int ev_broj) const {
    if(!laptopi.count(ev_broj)) throw std::domain_error("Laptop nije nadjen");
    auto it=laptopi.find(ev_broj);
    return *(it->second);
}
void IzlistajStudente() const {
    for(auto it=studenti.begin(); it!=studenti.end(); it++){
       (*(it->second)).Ispisi(); std::cout<<std::endl<<std::endl;
    }
}
void IzlistajLaptope() const {
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++){
       (*(it->second)).Ispisi();
        if((*(it->second)).DaLiJeZaduzen()){
            std::cout<<std::endl<<"Zaduzio(la): "<<(((it->second)->DajKodKogaJe())).DajImePrezime()<<" ("<<
            (((it->second)->DajKodKogaJe())).DajIndeks()<<")";
        }
        std::cout<<std::endl<<std::endl;
    }
}

void ZaduziLaptop(int broj_indeksa, int ev_broj){
    if(!studenti.count(broj_indeksa)) throw std::domain_error("Student nije nadjen");
      if(!laptopi.count(ev_broj)) throw std::domain_error("Laptop nije nadjen");
      if(laptopi[ev_broj]->DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
      for( auto it=laptopi.begin(); it!=laptopi.end(); it++) if(((it->second)->DaLiJeZaduzen()) &&
      ((it->second)->DajKodKogaJe()).DajIndeks()==broj_indeksa)
      throw std::domain_error("Student je vec zaduzio laptop");
      NadjiLaptop(ev_broj).Zaduzi(NadjiStudenta(broj_indeksa));
    
}
int NadjiSlobodanLaptop(){
       bool nadjen(false); int broj;
     for( auto it=laptopi.begin(); it!=laptopi.end(); it++) {
  if(!((it->second)->DaLiJeZaduzen())) {nadjen=true; broj=it->first; break;}}
     if(!nadjen) throw std::domain_error("Nema slobodnih laptopa");
    return broj;
}
void RazduziLaptop(int ev_broj){
    if(!laptopi.count(ev_broj)) throw std::domain_error("Laptop nije nadjen");
    if(!(laptopi[ev_broj]->DaLiJeZaduzen())) throw std::domain_error("Laptop nije zaduzen");
    laptopi[ev_broj]->Razduzi();
}

void PrikaziZaduzenja() const {
    bool zaduzeni(false);
for( auto it=laptopi.begin(); it!=laptopi.end(); it++) {
    
  if(((it->second)->DaLiJeZaduzen())){
      std::cout<<"Student "<<(((it->second)->DajKodKogaJe())).DajImePrezime()<<" ("<<
            (((it->second)->DajKodKogaJe())).DajIndeks()<<") zaduzio/la laptop broj "<<it->first<<std::endl;
            //provjeriti novi red
            zaduzeni=true;
  }}
  if(!zaduzeni) std::cout<<"Nema zaduzenja";
}
~Administracija(){
    for( auto it=laptopi.begin(); it!=laptopi.end(); it++) { delete it->second; it->second=nullptr;}
    for( auto it=studenti.begin(); it!=studenti.end(); it++) { delete it->second; it->second=nullptr;}
    
}
        };

//Laptop::kod_koga_je=nullptr;


        int main () {
            try {
Administracija a;
int opcija; do{
              std::cout<<"Unesite neku od zeljenih opcija: "<<std::endl
              <<"1: Registriraj Novi Laptop"<<std::endl
              <<"2: Registriraj Novog Studenta"<<std::endl
              <<"3: Izlistaj Laptope"<<std::endl
              <<"4: IzlistajStudente"<<std::endl
              <<"5: Zaduzi Laptop"<<std::endl
              <<"6: PrikaziZaduzenja"<<std::endl
              <<"7: Nadji slobodan laptop"<<std::endl
              <<"8: Zavrsi"<<std::endl;
              std::cin>>opcija;
              switch(opcija){
                  case 8: 
                  break;
                  case 1:
                  std::cout<<"Unesite evidencijski broj, naziv i karakteristike: ";
                  try{
                      
                  
                  int broj;
                  std::string m,b;
                  std::cin>>broj;
                  std::cin.clear();
                  std::cin.ignore(1000,'\n');
                  std::getline(std::cin, m);
                  std::getline(std::cin, b);
                   a.RegistrirajNoviLaptop(broj, m, b);
                  } catch(...){}
                  break;
                  case 2: 
                  std::cout<<"Unesite  broj indeksa, godinu studija ime i prezime, adresu i telefon: ";
                  try{
                      
                  
                  int broj1;
                  std::string naz0, kar0,naz1,naz3;
                  std::cin>>broj1;
                  std::cin.clear();
                  std::cin.ignore(1000,'\n');
                  std::getline(std::cin, naz0);
                  std::getline(std::cin, kar0);
                   std::getline(std::cin, naz1);
                    std::getline(std::cin, naz3);
                    a.RegistrirajNovogStudenta(broj1,naz0,kar0,naz1,naz3);
                  
              } catch(std::domain_error iz ){
                  std::cout<<iz.what();
              }
              break;
              case 3:
              a.IzlistajLaptope();
              break;
              case 4:
              a.IzlistajStudente();
              case 5:
              try{
                  std::cout<<"Unesire evidencijski broj laptopa i broj indeksa studenta";
                  int indeks, ev;
                  std::cin>>ev>>indeks;
                  a.ZaduziLaptop(indeks,ev);
              }
              catch(std::domain_error iz ){
                  std::cout<<iz.what();
              }
              break;
              case 6:
              a.PrikaziZaduzenja();
              case 7:
              try{ int brojz=a.NadjiSlobodanLaptop();
                  std::cout<<"Slobodan laptop ima broj: "<<brojz;
              }
              catch(std::domain_error iz ){
                  std::cout<<iz.what();
              }
              break;
              
              
   } } while(opcija!=8);
            }
   catch(std::domain_error iz) {
                std::cout<<iz.what();
            }
            return 0;
        }
