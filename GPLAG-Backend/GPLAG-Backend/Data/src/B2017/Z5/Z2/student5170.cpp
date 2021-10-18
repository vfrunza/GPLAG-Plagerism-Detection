/B2017/2018: Zadaća 5, Zadatak 2
#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>
#include <map>

class Student
{
    int br_indexa;
    std::string godina_studija, imeprezime, adresa, br_telefona;
    bool testindeksa (int broj) {
        if(broj<=0)return false;
        int brojac=0;
        while(broj!=0) {
            broj/=10;
            brojac++;
        }
        if(brojac==5)return true;
        return false;
    }

    bool testgodine (std::string godina) {
        if(godina.size()==0)return false;
        std::string niz[11]= {"1","2","3","1/B","2/B","3/B","1/M","2/M","1/D","2/D","3/D"};
        int i=0;
        for(; i<11; i++) {
            if(godina==niz[i])break;
        }
        if(i!=11)return true;
        return false;
    }

    bool testbroja(std::string broj) {
        if(broj.size()==0) return false;
        int i=0;
        if(broj[i]>='0' && broj[i]<='9') {
            while(i<broj.size() && broj[i]>='0' && broj[i]<='9') {
                i++;
            }
            if(i!=broj.size() && broj[i]=='/') {
                i++;
                while(i<broj.size() && broj[i]>='0' && broj[i]<='9') {
                    i++;
                }
                if(i!=broj.size() && broj[i]=='-') {
                    i++;
                    while(i<broj.size() && broj[i]>='0' && broj[i]<='9') {
                        i++;
                    }
                    if(i!=broj.size())return false;

                } else return false;
            } else return false;
        } else return false;

        return true;
    }
    
    std::string sredi_ime(std::string ime) {
        std::string pomocni=std::string();
       int i=0;
       while(i!=ime.size()) {
       while(i<ime.size() && ime[i]==' '){
           i++;
       } int j=i;
       while(j<ime.size() &&ime[j]!=' ') {
           j++;
       }
       pomocni+=ime.substr(i,j-i);
        if(j!=ime.size()){
            int k=j; while(k<ime.size() && ime[k]==' ' )k++;
            
            if(k!=ime.size())pomocni+=' ';
            
        }
        i=j;
    }
   return pomocni;
}

public:

    Student(int indeks, std::string godina, std::string ime, std::string adresa, std::string broj);
    int DajIndeks() const {return br_indexa;}
    std::string DajImePrezime() const {return imeprezime;}
    std::string DajGodinuStudija() const {
        if(godina_studija=="1")return"1/B";
        if(godina_studija=="2")return"2/B";
        if(godina_studija=="3")return"3/B";
        return godina_studija;}
    std::string DajAdresu() const {return adresa;}
    std::string DajTelefon() const {return br_telefona;}
    void Ispisi () const {
        std::cout<<"Broj indeksa: "<<br_indexa<<std::endl;
        std::cout<<"Godina studija: "<<DajGodinuStudija()<<std::endl;
        std::cout<<"Ime i prezime: "<<imeprezime<<std::endl;
        std::cout<<"Adresa: "<<adresa<<std::endl;
        std::cout<<"Telefon: "<<br_telefona<<std::endl;
    }
    

};

Student::Student(int indeks, std::string godina, std::string ime, std::string adresa1, std::string broj)
{
    if(!testindeksa(indeks) || !testgodine(godina) ||!testbroja(broj)) throw std::domain_error("Neispravni parametri");
    ime =sredi_ime(ime);
     br_indexa=indeks; godina_studija=godina; imeprezime=ime; adresa=adresa1; br_telefona=broj;
}

class Laptop {
  int ev_broj; std::string naziv, karakteristike;
  std::shared_ptr<Student> kod_koga_je;
  public: 
  Laptop(int broj,std::string ime, std::string karakteristike):naziv(ime),karakteristike(karakteristike),kod_koga_je(nullptr) {
      if(broj<0)throw std::domain_error("Neispravni parametri");
      ev_broj=broj;
  }
  int DajEvidencijskiBroj()const {return ev_broj;}
  std::string DajNaziv() const {return naziv;}
  std::string DajKarakteristike() const {return karakteristike;}
  void Zaduzi (Student & student) {
      if(kod_koga_je!=nullptr)throw std::domain_error("Laptop vec zaduzen");
      kod_koga_je=std::shared_ptr<Student>(&student);
  }
  void Razduzi() {if(kod_koga_je!=nullptr)kod_koga_je=nullptr;}
  bool DaLiJeZaduzen() {if(kod_koga_je!=nullptr)return true; return false;}
  Student & DajKodKogaJe() {
      if(kod_koga_je==nullptr)throw std::domain_error("Laptop nije zaduzen");
      return *kod_koga_je;
  }
    std::shared_ptr<Student> DajPokKodKogaJe() {return kod_koga_je;}
    void Ispisi() const {
    std::cout<<"Evidencijski broj: "<<ev_broj<<std::endl;
    std::cout<<"Naziv: "<<naziv<<std::endl;
    std::cout<<"Karakteristike: "<<karakteristike<<std::endl;
}    
};


class Administracija {
  std::map<int, std::shared_ptr<Student>> mapa_studenti;
  std::map<int, std::shared_ptr<Laptop>> mapa_laptopi;
  public :
  Administracija()=default;
  Administracija (const Administracija& admin);
  Administracija(Administracija && admin);
  Administracija& operator=(const Administracija& admin);
  Administracija &operator=(Administracija &&admin);    
  void RegistrirajNovogStudenta(int indeks, std::string godina, std::string ime, std::string adresa, std::string broj);
  void RegistrirajNoviLaptop(int broj,std::string ime, std::string karakteristike);
  Student& NadjiStudenta(int broj) {
      auto it=mapa_studenti.find(broj); if(it==mapa_studenti.end()) throw std::domain_error("Student nije nadjen"); else return *it->second;
  }
  Student NadjiStudenta(int broj) const{
      auto it=mapa_studenti.find(broj); if(it==mapa_studenti.end()) throw std::domain_error("Student nije nadjen"); else return *it->second;
  }
  Laptop& NadjiLaptop(int broj) {
      auto it=mapa_laptopi.find(broj); if(it==mapa_laptopi.end()) throw std::domain_error("Laptop nije nadjen"); else return *it->second;
  }
  Laptop NadjiLaptop(int broj) const{
      auto it=mapa_laptopi.find(broj); if(it==mapa_laptopi.end()) throw std::domain_error("Laptop nije nadjen"); else return *it->second;
  }
  void IzlistajStudente();
  void IzlistajLaptope();
  void ZaduziLaptop(int indeks, int evid);
  int NadjiSlobodniLaptop ();
  void RazduziLaptop(int evid);
  void PrikaziZaduzenja();
 
  
};

Administracija::Administracija(const Administracija& admin) {
    auto it=admin.mapa_studenti.begin();
    try {
    while(it!=admin.mapa_studenti.end()) {
        mapa_studenti.insert(std::make_pair(it->first,std::make_shared<Student>(*it->second)));
        
        it++;
    }}
    catch(...) {
        throw;
    }
    
}

Administracija::Administracija(Administracija &&admin) {
    mapa_studenti=admin.mapa_studenti;
    mapa_laptopi=admin.mapa_laptopi;
    for(auto it=admin.mapa_studenti.begin();it!=admin.mapa_studenti.end();it++) {
        it->second=nullptr;
    }
    for(auto it=admin.mapa_laptopi.begin();it!=admin.mapa_laptopi.end();it++) {
        it->second=nullptr;
    }
}

Administracija& Administracija:: operator=(const Administracija &admin) {
 
  for(auto it=mapa_studenti.begin();it!=mapa_studenti.end();it++) {
     
      it=mapa_studenti.erase(it);
  }
  for(auto it=mapa_laptopi.begin();it!=mapa_laptopi.end();it++){
     
      it=mapa_laptopi.erase(it);
  }
  try {
  for(auto it=admin.mapa_studenti.begin();it!=admin.mapa_studenti.end();it++) {
     mapa_studenti.insert(std::make_pair(it->first, std::make_shared<Student>(*it->second)));
  }}
  catch(...) {
      
      throw;
  }
  
  try {
  for(auto it=admin.mapa_laptopi.begin();it!=admin.mapa_laptopi.end();it++) {
     mapa_laptopi.insert(std::make_pair(it->first, std::make_shared <Laptop>(*it->second)));
  }}
  catch(...) {
    
      throw;
  }
   return *this;
}

Administracija& Administracija::operator=( Administracija&& admin) {
    
    mapa_laptopi=std::move(admin.mapa_laptopi);
    mapa_studenti=std::move(admin.mapa_studenti);
    
    return *this;
}

void Administracija::RegistrirajNovogStudenta(int indeks, std::string godina, std::string ime, std::string adresa, std::string broj) {
    auto it=mapa_studenti.find(indeks);
    if(it!=mapa_studenti.end())throw std::domain_error ("Student s tim indeksom vec postoji");
    mapa_studenti.insert(std::make_pair(indeks, std::make_shared<Student>( indeks,godina, ime, adresa,  broj) ) ) ;
}

void Administracija::RegistrirajNoviLaptop(int broj,std::string ime, std::string karakteristike) {
    auto it=mapa_laptopi.find(broj);
    if(it!=mapa_laptopi.end())throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    mapa_laptopi.insert(std::make_pair(broj,std::make_shared<Laptop>(broj,ime,karakteristike)));
}

void Administracija::IzlistajStudente() {
    for(auto it=mapa_studenti.begin();it!=mapa_studenti.end();it++) {
        it->second->Ispisi(); std::cout<<std::endl;
    }
}

void Administracija::IzlistajLaptope() {
    for(auto it=mapa_laptopi.begin();it!=mapa_laptopi.end();it++) {
        it->second->Ispisi();
        if(it->second->DaLiJeZaduzen()) {
            auto pok2=it->second->DajPokKodKogaJe();
            std::cout<<std::endl;std::cout<<"Zaduzio(la): "<<pok2->DajImePrezime()<<" ("<<pok2->DajIndeks()<<")"<<std::endl;
        }
    }
}

void Administracija::ZaduziLaptop(int indeks, int evid) {
    auto it=mapa_studenti.find(indeks);
    if(it==mapa_studenti.end())throw std::domain_error("Student nije nadjen");
    auto it2=mapa_laptopi.find(evid);
    if(it2==mapa_laptopi.end())throw std::domain_error("Laptop nije nadjen");
    if(it2->second->DaLiJeZaduzen())throw std::domain_error("Laptop vec zaduzen");
    for(auto it2=mapa_laptopi.begin();it2!=mapa_laptopi.end();it2++) {
        auto pok2=it2->second->DajPokKodKogaJe();
        if(pok2!=nullptr){
        if(pok2->DajAdresu()==it->second->DajAdresu() && 
        pok2->DajIndeks()==it->second->DajIndeks() && 
        pok2->DajGodinuStudija()==it->second->DajGodinuStudija() &&
        pok2->DajImePrezime()==it->second->DajImePrezime() && 
        pok2->DajTelefon()==it->second->DajTelefon()) throw std::domain_error("Student je vec zaduzio laptop");
        }
    }
    it2->second->Zaduzi(*it->second);
}

int Administracija::NadjiSlobodniLaptop() {
    auto it=mapa_laptopi.begin();
    for(;it!=mapa_laptopi.end();it++){
        if(!it->second->DaLiJeZaduzen())break;
    }
    if(it==mapa_laptopi.end())throw std::domain_error("Nema slobodnih laptopa");
    
    return it->second->DajEvidencijskiBroj();
}

void Administracija::RazduziLaptop(int evid){
    auto it=mapa_laptopi.begin(); 
    for(;it!=mapa_laptopi.end();it++) {
        if(it->second->DajEvidencijskiBroj()==evid)break;
    }
  if(it==mapa_laptopi.end())throw std::domain_error("Laptop nije nadjen");
  if(!it->second->DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen");
  it->second->Razduzi();
  
}

void Administracija::PrikaziZaduzenja() {
    auto it=mapa_laptopi.begin(); int brojac=0;
    for(;it!=mapa_laptopi.end();it++) {
        auto pok=it->second->DajPokKodKogaJe();
        if(pok!=nullptr) {
            std::cout<<"Student "<<pok->DajImePrezime()<<" ("<<pok->DajIndeks()<<") zaduzio/la laptop broj "<<it->second->DajEvidencijskiBroj()<<std::endl;
        }
        if(pok==nullptr)brojac++;
    }
    if( brojac==mapa_laptopi.size() )std::cout<<"Nema zaduzenja"<<std::endl;
}


int main ()
{
    Administracija admin; int opcija=11;
    do{
    std::cout<<"Izaberite opciju ili 0 za kraj: "<<std::endl;
    std::cout<<"1. Registriraj studenta"<<std::endl;
    std::cout<<"2. Registriraj laptop"<<std::endl;
    std::cout<<"3. Nadji studenta"<<std::endl;
    std::cout<<"4. Nadji laptop"<<std::endl;
    std::cout<<"5. Izlistaj studente"<<std::endl;
    std::cout<<"6. Izlistaj laptope"<<std::endl;
    std::cout<<"7. Zaduzi laptop"<<std::endl;
    std::cout<<"8. Nadji slobodni laptop"<<std::endl;
    std::cout<<"9. Razduzi laptop"<<std::endl;
    std::cout<<"10. Prikazi zaduzenja"<<std::endl;
     std::cin>>opcija; 
     std::cin.ignore(10000,'\n');
     if(opcija==1) {
         std::cout<<"Unesite ime i prezime: "; std::string imeiprezime; std::getline(std::cin,imeiprezime); 
          std::cout<<"Unesite broj telefona: "; std::string telefon; std::getline(std::cin,telefon);
         std::cout<<"Unesite adresu: "; std::string adresa; std::getline(std::cin, adresa); 
          std::cout<<"Unesite godinu studija: "; std::string godina; std::getline(std::cin,godina);
         std::cout<<"Unesite broj indeksa: "; int broj; std::cin>>broj;
         admin.RegistrirajNovogStudenta(broj, godina, imeiprezime, adresa, telefon);
     }
     if(opcija==2) {
         std::cout<<"Unesite broj: "; int broj; std::cin>>broj; std::cin.ignore(10000,'\n');
         std::cout<<"Unesite ime: "; std::string ime; std::getline(std::cin, ime);
         std::cout<<"Unesite karakteritike: "; std::string karakt; std::getline(std::cin, karakt);
         admin.RegistrirajNoviLaptop(broj, ime, karakt);
     }
     if(opcija==3) {
         std::cout<<"Unesite broj indeksa: "; int broj; std::cin>>broj;
         Student s=admin.NadjiStudenta(broj);
         s.Ispisi();
     }
     if(opcija==4) {
         std::cout<<"Unesite evidencijski broj: "; int broj; std::cin>>broj;
         Laptop p=admin.NadjiLaptop(broj);
         p.Ispisi();
     }
     if(opcija ==5) {
         admin.IzlistajStudente();
     }
     if(opcija==6){
         admin.IzlistajLaptope();
     }
     if(opcija==7){
         std::cout<<"Unesite broj indeksa studenta: "; int br1; std::cin>>br1;
         std::cout<<"Unesite broj laptopa: "; int br2; std::cin>>br2;
         admin.ZaduziLaptop(br1,br2);
     }
     if(opcija==8){
         int broj=admin.NadjiSlobodniLaptop();
         Laptop p=admin.NadjiLaptop(broj);
         std::cout<<"Prvi slobodni je "; p.Ispisi();
     }
     if(opcija==9) {
         std::cout<<"Unesite evidencijski broj: "; int broj; std::cin>>broj;
         admin.RazduziLaptop(broj);
     }
     
     if(opcija==10) {
         admin.PrikaziZaduzenja();
     }
     
    }while(opcija!=0);
    
    
    
    
    
    return 0;
}

