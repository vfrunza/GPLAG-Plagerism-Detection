/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <stdexcept>
#include <memory>
#include <map>
#include <utility>
#include <algorithm>

class Student{
  public:
  int br_indeksa;
  std::string god_studija, ime_prezime, adresa, br_telefona;
  Student(int br_indeksa, std::string god_studija, std::string ime_prezime, std::string adresa, std::string br_telefona);
  int DajIndeks() const { return br_indeksa; };
  std::string DajGodinuStudija() const;
  std::string DajImePrezime() const { return ime_prezime; };
  std::string DajAdresu() const { return adresa; };
  std::string DajTelefon() const { return br_telefona; };
  void Ispisi() const;
};

class Laptop{
  public:
  int ev_broj;
  std::string naziv, karakteristike;
  Student* kod_koga_je;
  Laptop(int ev_br, std::string naz, std::string kar);
  int DajEvidencijskiBroj() const { return ev_broj; };
  std::string DajNaziv() const { return naziv; };
  std::string DajKarakteristike() const { return karakteristike; };
  void Zaduzi(Student& zaduzuje){
    if(kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen");
    kod_koga_je = &zaduzuje;
  };
  void Razduzi(){
    if(kod_koga_je==nullptr) return;
    kod_koga_je=nullptr;
  };
  bool DaLiJeZaduzen() const { return (!(kod_koga_je==nullptr)); };
  Student& DajKodKogaJe() const {
    if(kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen");
    return (*kod_koga_je);
  };
  Student* DajPokKodKogaJe() const { return kod_koga_je; };
  void Ispisi() const;
};

class Administracija : public Student, public Laptop{
  std::map<int, Student*> studenti;
  std::map<int, Laptop*> laptopi;
  public:
  Administracija();
  Administracija(const Administracija &adm);
  Administracija(const Administracija &&adm);
  Administracija &operator=(Administracija adm);
  void RegistrirajNovogStudenta(int br_indeksa, std::string god_studija, std::string ime_prezime, std::string adresa, std::string br_telefona);
  void RegistrirajNoviLaptop(int ev_br, std::string naz, std::string kar);
  Student& NadjiStudenta(int br_indeksa);
  Laptop& NadjiLaptop(int ev_broj);
  void IzlistajStudente() const;
  void IzlistajLaptope() const;
  void ZaduziLaptop(int br_indeksa, int ev_broj);
  int NadjiSlobodniLaptop();
  void RazduziLaptop(int ev_broj);
  void PrikaziZaduzenja();
};

void Administracija::PrikaziZaduzenja(){
  int i(0);
  for(auto it(laptopi.begin()); it!=laptopi.end(); it++){
    if(it->second->kod_koga_je!=nullptr){
      i++;
      auto stud(it->second->kod_koga_je);
      std::cout<<"Student "<<stud->ime_prezime<<"("<<stud->br_indeksa<<")"<<" zaduzio/la laptop broj "<<it->first<<std::endl;
    }
  }
  if(i==0) std::cout<<"Nema zaduzenja";
}

void Administracija::RazduziLaptop(int ev_broj){
  if(!laptopi.count(ev_broj)) throw std::domain_error("Laptop nije nadjen");
  auto it(laptopi.find(ev_broj));
  if(it->second->kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen");
  it->second->kod_koga_je=nullptr;
}

void Administracija::ZaduziLaptop(int br_indeksa, int ev_broj){
  if(!studenti.count(br_indeksa)) throw std::domain_error("Student nije nadjen");
  if(!laptopi.count(ev_broj)) throw std::domain_error("Laptop nije nadjen");
  auto it2(laptopi.find(ev_broj));
  auto it1(studenti.find(br_indeksa));
  if(it2->second->kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen");
  for(auto it(laptopi.begin()); it != laptopi.end(); it++){
    if(it->second->kod_koga_je == it1->second) throw std::domain_error("Student je vec zaduzio laptop");
  }
  it2->second->kod_koga_je=it1->second;
}

int Administracija::NadjiSlobodniLaptop(){
  for(auto it(laptopi.begin()); it!=laptopi.end(); it++){
    if(it->second->kod_koga_je==nullptr) return it->first;
  }
  throw std::domain_error("Nema slobodnih laptopa");
}

void Administracija::IzlistajStudente() const{
   for(auto its=studenti.begin(); its != studenti.end(); its++){
     std::cout<<"Broj indeksa: "<<its->first<<std::endl;
     std::cout<<"Godina studija: "<<its->second->DajGodinuStudija()<<std::endl;
     std::cout<<"Ime i prezime: "<<its->second->ime_prezime<<std::endl;
     std::cout<<"Adresa: "<<its->second->adresa<<std::endl;
     std::cout<<"Telefon: "<<its->second->br_telefona<<std::endl;
     its++;
     std::cout<<std::endl;
     std::cout<<"Broj indeksa: "<<its->first<<std::endl;
     std::cout<<"Godina studija: "<<its->second->DajGodinuStudija()<<std::endl;
     std::cout<<"Ime i prezime: "<<its->second->ime_prezime<<std::endl;
     std::cout<<"Adresa: "<<its->second->adresa<<std::endl;
     std::cout<<"Telefon: "<<its->second->br_telefona<<std::endl;
     std::cout<<std::endl;
   }
}

void Administracija::IzlistajLaptope() const{
   for(auto it=laptopi.begin(); it != laptopi.end(); it++){
     std::cout<<it->first<<" "<<it->second->ev_broj<<" "<<it->second->naziv<<it->second->karakteristike<<std::endl;
     if(it->second->kod_koga_je != nullptr) std::cout<<"Zaduzio(la): "<<it->second->kod_koga_je->ime_prezime<<"("<<it->second->kod_koga_je->br_indeksa<<")"<<std::endl;
     it++;
     std::cout<<it->first<<" "<<it->second->ev_broj<<" "<<it->second->naziv<<it->second->karakteristike<<std::endl;
     if(it->second->kod_koga_je != nullptr) std::cout<<"Zaduzio(la): "<<it->second->kod_koga_je->ime_prezime<<"("<<it->second->kod_koga_je->br_indeksa<<")"<<std::endl;
     std::cout<<std::endl;
   }
 }

Laptop& Administracija::NadjiLaptop(int ev_broj){
  auto it(laptopi.find(br_indeksa));
  if(it==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
  auto iter(it->second);
  return *iter;
}

Student& Administracija::NadjiStudenta(int br_indeksa){
  auto it(studenti.find(br_indeksa));
  if(it==studenti.end()) throw std::domain_error("Student nije nadjen");
  auto iter(it->second);
  return *iter;
}

void Administracija::RegistrirajNovogStudenta(int br_indeksa, std::string god_studija, std::string ime_prezime, std::string adresa, std::string br_telefona){
  if(studenti.count(br_indeksa)) throw std::domain_error("Student s tim indeksom vec postoji");
  try{
  studenti.insert(std::make_pair(br_indeksa, new Student(br_indeksa, god_studija, ime_prezime, adresa, br_telefona)));
  }
  catch(...){
    auto it(studenti.find(br_indeksa));
    delete it->second;
    throw;
  }
}
void Administracija::RegistrirajNoviLaptop(int ev_br, std::string naz, std::string kar){
  if(laptopi.count(ev_br)) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
  try{
  laptopi.insert(std::make_pair(ev_broj, new Laptop(ev_br, naz, kar)));
  }
  catch(...){
    auto it(laptopi.find(ev_broj));
    delete it->second;
    throw;
  }
}
Administracija &Administracija::operator=(Administracija adm){
  std::swap(studenti, adm.studenti);
  std::swap(laptopi, adm.laptopi);
  return *this;
}


Administracija::Administracija(): Student(11111, "1", "", "", "1/1-1"), Laptop(0, "", ""){
  auto it1(studenti.begin());
  it1->second=nullptr;
  auto it2(laptopi.begin());
  it2->second=nullptr;
}

Administracija::Administracija(const Administracija &adm) : Student(br_indeksa, god_studija, ime_prezime, adresa, br_telefona), Laptop(ev_broj, naziv, karakteristike) {
  
  try{
  for(auto its=adm.studenti.begin(); its != adm.studenti.end(); its++){
    studenti.insert(std::make_pair(its->first, new Student(its->second->br_indeksa, its->second->god_studija, its->second->ime_prezime, its->second->adresa, its->second->br_telefona)));
  }
  
  
  for(auto ls(adm.laptopi.begin()); ls != adm.laptopi.end(); ls++){
    laptopi.insert(std::make_pair(ls->first, new Laptop(ls->second->ev_broj, ls->second->naziv, ls->second->karakteristike)));
  }
  }
    catch(...){
    for(auto itn2(studenti.begin()); itn2!=studenti.end(); itn2++) delete itn2->second;
    for(auto ln2(laptopi.begin()); ln2!=laptopi.end(); ln2++) delete ln2->second;
    throw;
  }
}

void Laptop::Ispisi() const{
  std::cout<<"Evidencijski broj: "<<ev_broj<<std::endl;
  std::cout <<"Naziv: "<<naziv<< std::endl;
  std::cout <<"Karakteristike: "<<karakteristike<< std::endl;
}

Laptop::Laptop(int ev_br, std::string naz, std::string kar):naziv(naz), karakteristike(kar), kod_koga_je(nullptr){
  if(ev_br<0) throw std::domain_error("Nesipravni parametri");
  ev_broj=ev_br;
}

Student::Student(int indeks, std::string god_st, std::string i_p, std::string adress, std::string br_tel){
  int tmp=indeks;
  int brojac(0);
  while(tmp){
    brojac++;
    tmp/=10;
  }
  if(brojac!=5) throw std::domain_error("Nesipravni parametri");
  
  std::vector<std::string> godine{"1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "1/D", "2/D", "3/D"};
  int br(0);
  for(int i=0; i<11; i++){
    if(god_st==godine.at(i)){
      br++;
      break;
    }
  }
  if(br==0) throw std::domain_error("Nesipravni parametri");
  char temp('a');
  br=0;
  for(int i(0); i<i_p.length(); i++){
    if(br==1){i--; br=0;};
    if(isspace(i_p.at(i)) && (isspace(temp)|| i==0 || i==i_p.length()-1)){
      i_p.erase(i,1);
      if(i!=0) i--;
      if(i==0) br=1;
      if(i==i_p.length()-1) i--;
    }
    temp=i_p.at(i);
  }
  
  char tp='a';
  br=0;
  for(int i(0); i<br_tel.length(); i++){
    if(std::isdigit(br_tel.at(i)) || (br_tel.at(i)=='-' && br==1 && isdigit(tp))) {
      tp=br_tel.at(i);
      continue;
    }
    if(br_tel.at(i)=='/' && isdigit(tp)){
      br++;
      tp=br_tel.at(i);
      continue;
    }
    else throw std::domain_error("Nesipravni parametri");
  }
  ime_prezime=i_p; br_indeksa=indeks; god_studija=god_st; adresa=adress; br_telefona=br_tel;
}

std::string Student::DajGodinuStudija() const{
  std::string temp;
  if(god_studija=="1") {temp="1/B"; return temp;}
  if(god_studija=="2") {temp="2/B"; return temp;}
  if(god_studija=="3") {temp="3/B"; return temp;}
  else return god_studija;
}

void Student::Ispisi() const{
  std::cout<<"Broj indeksa: "<<br_indeksa<<std::endl;
  std::cout<<"Godina studija: "<<DajGodinuStudija()<< std::endl;
  std::cout<<"Ime i prezime: "<<ime_prezime<< std::endl;
  std::cout<<"Adresa: "<<adresa<< std::endl;
  std::cout<<"Telefon: "<<br_telefona<< std::endl;
}


int main ()
{
  Administracija admin;
    std::cout << "OK";
	return 0;
}
